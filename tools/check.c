/* check.c -- compare one compiled function with the retail image, references included */

#include <stdlib.h>
#include <string.h>

#include "vd.h"

const char *vd_status_names[] = { "OK", "OK-UNVERIFIED", "REF", "DIFF", "SIZE", "NOSYM", "NOOBJ" };

#define MAX_CANDIDATES 64

/* ------------------------------------------------------------------ names */

/* split "A::B<x::y>::f" on top-level "::" */
static int split_qualified(const char *q, char parts[][256], int max)
{
	int         n = 0, depth = 0;
	const char *start = q, *p;

	for (p = q;; p++) {
		if (*p == '<') {
			depth++;
		} else if (*p == '>') {
			depth--;
		}
		if (!*p || (depth == 0 && p[0] == ':' && p[1] == ':')) {
			size_t len = (size_t)(p - start);

			if (n < max) {
				if (len > 255) {
					len = 255;
				}
				memcpy(parts[n], start, len);
				parts[n][len] = 0;
				n++;
			}
			if (!*p) {
				break;
			}
			p++;
			start = p + 1;
		}
	}
	return n;
}

/*
 * Build the mangled prefix of a plain qualified name: "A::B::f" -> "?f@B@A@@", "A::A" -> "??0A@@",
 * "A::~A" -> "??1A@@", "f" -> "?f@@". Returns 0 for names this cannot spell (templates, operators).
 */
static int mangled_prefix(const char *qualified, char *out, size_t outsize)
{
	char   parts[16][256];
	int    n = split_qualified(qualified, parts, 16), i;
	size_t len = 0;

	if (n <= 0 || strchr(qualified, '<') || strstr(qualified, "operator") || strchr(qualified, ' ')) {
		return 0;
	}
	out[0] = 0;
	if (n >= 2 && strcmp(parts[n - 1], parts[n - 2]) == 0) {
		len += (size_t)snprintf(out + len, outsize - len, "??0");
	} else if (n >= 2 && parts[n - 1][0] == '~' && strcmp(parts[n - 1] + 1, parts[n - 2]) == 0) {
		len += (size_t)snprintf(out + len, outsize - len, "??1");
	} else {
		len += (size_t)snprintf(out + len, outsize - len, "?%s@", parts[n - 1]);
	}
	for (i = n - 2; i >= 0 && len < outsize; i--) {
		len += (size_t)snprintf(out + len, outsize - len, "%s@", parts[i]);
	}
	if (len < outsize) {
		snprintf(out + len, outsize - len, "@");
	}
	return 1;
}

/* loose match for names mangled_prefix cannot spell: every name part appears in the symbol */
static int loose_match(const char *qualified, const char *sym)
{
	char parts[16][256];
	int  n = split_qualified(qualified, parts, 16), i;
	char buf[300];

	if (n <= 0) {
		return 0;
	}
	/* the function's own name comes first */
	snprintf(buf, sizeof(buf), "?%s@", parts[n - 1]);
	if (strncmp(sym, buf, strlen(buf)) != 0) {
		return 0;
	}
	for (i = 0; i < n - 1; i++) {
		char *lt;

		snprintf(buf, sizeof(buf), "%s", parts[i]);
		lt = strchr(buf, '<');
		if (lt) {
			*lt = 0;
		}
		if (!strstr(sym, buf)) {
			return 0;
		}
	}
	return 1;
}

/* the function-name component alone: "sub_10029100" matches "?sub_10029100@AnyClass@@..." */
static int bare_name_matches(const char *qualified, const char *sym)
{
	char        parts[16][256], buf[300];
	int         n = split_qualified(qualified, parts, 16);

	if (n <= 0) {
		return 0;
	}
	snprintf(buf, sizeof(buf), "?%s@", parts[n - 1]);
	return strncmp(sym, buf, strlen(buf)) == 0;
}

static int name_matches(const char *qualified, const char *prefix, const char *sym)
{
	size_t n;

	if (prefix[0]) {
		n = strlen(prefix);
		if (strncmp(sym, prefix, n) == 0) {
			return 1;
		}
	} else if (loose_match(qualified, sym)) {
		return 1;
	}
	/* extern "C" spellings: _f, _f@N, @f@N */
	if (!strstr(qualified, "::")) {
		n = strlen(qualified);
		if ((sym[0] == '_' || sym[0] == '@') && strncmp(sym + 1, qualified, n) == 0 &&
			(sym[1 + n] == 0 || sym[1 + n] == '@')) {
			return 1;
		}
	}
	return 0;
}

/* -------------------------------------------------------------- functions */

/* end offset of the function symbol at index si: the next function symbol in its section, or the section end */
static uint32_t function_extent(const vd_coff_t *obj, uint32_t si)
{
	const vd_coff_symbol_t *s = &obj->symbols[si];
	uint32_t                end = obj->sections[s->section].size, k;

	for (k = 0; k < obj->nsymbols; k++) {
		const vd_coff_symbol_t *t = &obj->symbols[k];

		if (k != si && vd_coff_is_function(t) && t->section == s->section && t->value > s->value && t->value < end) {
			end = t->value;
		}
	}
	return end;
}

/* the function symbol whose body holds section offset off, or -1 */
static int64_t function_at(const vd_coff_t *obj, int section, uint32_t off)
{
	int64_t  best = -1;
	uint32_t k;

	for (k = 0; k < obj->nsymbols; k++) {
		const vd_coff_symbol_t *t = &obj->symbols[k];

		if (vd_coff_is_function(t) && t->section == section && t->value <= off &&
			(best < 0 || t->value > obj->symbols[best].value)) {
			best = k;
		}
	}
	return best;
}

static int is_padding(unsigned char c)
{
	return c == 0xcc || c == 0x90;
}

/* follow an incremental-link jump stub */
static uint32_t through_stub(const vd_pe_t *pe, uint32_t va)
{
	const unsigned char *p = vd_pe_ptr(pe, va, 5);

	if (p && p[0] == 0xe9 && vd_pe_is_code(pe, va)) {
		return va + 5 + vd_u32(p + 1);
	}
	return va;
}

/* compare obj section bytes [off, off+len) with retail at va, masking relocation fields */
static int compare_masked(const vd_pe_t *pe, const vd_coff_t *obj, int section, uint32_t off, uint32_t len,
						  uint32_t va)
{
	const vd_coff_section_t *sec = &obj->sections[section];
	const unsigned char     *r = vd_pe_ptr(pe, va, len);
	unsigned char           *mask;
	uint32_t                 i;
	int                      k, same = 1;

	if (!sec->data || !r || off + len > sec->size) {
		return 0;
	}
	mask = vd_xmalloc(len);
	memset(mask, 0, len);
	for (k = 0; k < sec->nrelocs; k++) {
		uint32_t o = sec->relocs[k].offset;

		for (i = 0; i < 4; i++) {
			if (o + i >= off && o + i < off + len) {
				mask[o + i - off] = 1;
			}
		}
	}
	for (i = 0; i < len; i++) {
		if (!mask[i] && sec->data[off + i] != r[i]) {
			same = 0;
			break;
		}
	}
	free(mask);
	return same;
}

/* ------------------------------------------------------------- references */

enum { REF_OK, REF_UNVERIFIED, REF_BAD };

static int addr_in(uint32_t a, const uint32_t *c, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		if (c[i] == a) {
			return 1;
		}
	}
	return 0;
}

/* strip stdcall/fastcall decoration and the C underscore: "_Foo@8" -> "Foo" */
static void undecorate_c(const char *in, char *out, size_t outsize)
{
	const char *p = in;
	size_t      n;
	char       *at;

	if (*p == '_' || *p == '@') {
		p++;
	}
	snprintf(out, outsize, "%s", p);
	if (in[0] != '?' && (at = strchr(out, '@')) != NULL) {
		*at = 0;
	}
	n = strlen(out);
	(void)n;
}

/*
 * Verify that the retail reference at field va (with full target tfull = symbol + addend) names the same thing
 * as the object's relocation.
 */
static int verify_ref(const vd_ctx_t *ctx, const vd_coff_t *obj, const vd_coff_reloc_t *rel, uint32_t addend,
					  uint32_t tfull, char *why, size_t whysize)
{
	const vd_coff_symbol_t *sym = &obj->symbols[rel->symbol];
	uint32_t                cand[MAX_CANDIDATES];
	int                     nc = 0;
	uint32_t                s_retail = tfull - addend;
	const char             *name = sym->name ? sym->name : "?";

	/* imports */
	if (strncmp(name, "__imp_", 6) == 0) {
		const vd_pe_import_t *imp = vd_pe_import_at(ctx->pe, s_retail);
		char                  want[512], have[512];

		if (!imp) {
			snprintf(why, whysize, "%s: retail 0x%08x is not an import slot", name, s_retail);
			return REF_BAD;
		}
		if (name[6] == '?') {
			snprintf(want, sizeof(want), "%s", name + 6);
		} else {
			undecorate_c(name + 6, want, sizeof(want));
		}
		snprintf(have, sizeof(have), "%s", imp->name);
		if (strcmp(want, have) == 0 || (name[6] != '?' && strcmp(name + 6, have) == 0)) {
			return REF_OK;
		}
		/* an import library may export a C++ declaration under its undecorated name */
		if (name[6] == '?') {
			const char *at = strchr(name + 7, '@');
			size_t      l = at ? (size_t)(at - (name + 7)) : 0;

			if (l && strlen(have) == l && strncmp(have, name + 7, l) == 0) {
				return REF_OK;
			}
		}
		snprintf(why, whysize, "%s: retail imports %s!%s", name, imp->dll, imp->name);
		return REF_BAD;
	}

	/* names symbols.txt knows, or that carry their address */
	nc = vd_symtab_find(ctx->st, name, cand, MAX_CANDIDATES);
	if (nc < MAX_CANDIDATES) {
		uint32_t a = vd_name_address(name);

		if (a && !addr_in(a, cand, nc)) {
			cand[nc++] = a;
		}
	}
	if (nc > 0) {
		int i;

		if (addr_in(s_retail, cand, nc) || addr_in(through_stub(ctx->pe, s_retail), cand, nc)) {
			return REF_OK;
		}
		for (i = 0; i < nc; i++) {
			if (through_stub(ctx->pe, cand[i]) == s_retail ||
				through_stub(ctx->pe, cand[i]) == through_stub(ctx->pe, s_retail)) {
				return REF_OK;
			}
		}
		if (sym->section <= 0) {
			const vd_sym_t *at = vd_symtab_at(ctx->st, through_stub(ctx->pe, s_retail));

			snprintf(why, whysize, "%s: expected 0x%08x, retail 0x%08x (%s)", name, cand[0], s_retail,
					 at ? at->pretty : "no symbol");
			return REF_BAD;
		}
		/* a definition in this unit: fall through to its contents, the name may be stale */
	}

	if (sym->section > 0) {
		int                      section = sym->section;
		const vd_coff_section_t *sec = &obj->sections[section];
		uint32_t                 toff = sym->value + addend;

		if (sec->flags & 0x20) {
			/* code: a jump table entry, or a call to a function defined here */
			int64_t fi = function_at(obj, section, toff);

			if (fi >= 0) {
				const vd_coff_symbol_t *f = &obj->symbols[fi];
				uint32_t                fcand[MAX_CANDIDATES];
				int                     nf = vd_symtab_find(ctx->st, f->name, fcand, MAX_CANDIDATES);
				uint32_t                fa = vd_name_address(f->name);
				uint32_t                ext = function_extent(obj, (uint32_t)fi);
				uint32_t                len = ext - f->value;
				uint32_t                base = through_stub(ctx->pe, tfull - (toff - f->value));

				if (fa && nf < MAX_CANDIDATES) {
					fcand[nf++] = fa;
				}
				if (nf && (addr_in(tfull - (toff - f->value), fcand, nf) || addr_in(base, fcand, nf))) {
					return REF_OK;
				}
				while (len > 0 && sec->data && is_padding(sec->data[f->value + len - 1])) {
					len--;
				}
				if (toff == f->value && compare_masked(ctx->pe, obj, section, f->value, len, base)) {
					return REF_OK;
				}
				if (toff != f->value && compare_masked(ctx->pe, obj, section, f->value, len, tfull - (toff - f->value))) {
					return REF_OK;
				}
				snprintf(why, whysize, "%s+0x%x: retail 0x%08x holds different code", f->name, toff - f->value, tfull);
				return REF_BAD;
			}
		}
		if (sec->data) {
			/* data defined here: compare its bytes */
			uint32_t end = sec->size, k, len;

			if (!sec->comdat) {
				for (k = 0; k < obj->nsymbols; k++) {
					const vd_coff_symbol_t *t = &obj->symbols[k];

					if (t->name && t->section == section && t->value > toff && t->value < end) {
						end = t->value;
					}
				}
			}
			if (toff >= end) {
				snprintf(why, whysize, "%s: reference past its data", name);
				return REF_UNVERIFIED;
			}
			len = end - toff;
			if (strncmp(name, "$SG", 3) == 0 || strncmp(name, "??_C@", 5) == 0) {
				uint32_t z = 0;

				while (z < len && sec->data[toff + z]) {
					z++;
				}
				len = z < len ? z + 1 : len;
			}
			if (len > 4096) {
				len = 4096;
			}
			if (compare_masked(ctx->pe, obj, section, toff, len, tfull)) {
				return REF_OK;
			}
			snprintf(why, whysize, "%s+0x%x: retail 0x%08x holds different data", name, addend, tfull);
			return REF_BAD;
		}
		if (strncmp(name, "??_C@", 5) == 0 && toff < sec->size) {
			/* an all-zero literal (""), which VC6 places in uninitialized data: retail must hold zeros there */
			uint32_t             len = sec->size - toff, z;
			const unsigned char *rp = vd_pe_ptr(ctx->pe, tfull, len);

			for (z = 0; rp && z < len && !rp[z]; z++) {
			}
			if (!rp || z == len) {
				return REF_OK;   /* past a section's file data the image is zero-filled too */
			}
			snprintf(why, whysize, "%s: retail 0x%08x is not empty", name, tfull);
			return REF_BAD;
		}
	}

	snprintf(why, whysize, "%s: unresolved", name);
	return REF_UNVERIFIED;
}

/* --------------------------------------------------------------- the check */

/*
================
vd_check_block
================
*/
void vd_check_block(const vd_ctx_t *ctx, const vd_coff_t *obj, const vd_block_t *b, long forced, vd_result_t *r)
{
	const vd_sym_t          *expect = vd_symtab_at(ctx->st, b->addr);
	const char              *qualified = b->target ? b->target : (expect ? expect->pretty : NULL);
	char                     prefix[1024];
	int64_t                  best = -1;
	uint32_t                 best_ext = 0, k;
	const vd_coff_symbol_t  *fs;
	const vd_coff_section_t *sec;
	const unsigned char     *retail;
	uint32_t                 ext, off, i;
	int                      ri;

	memset(r, 0, sizeof(*r));
	prefix[0] = 0;
	if (qualified) {
		mangled_prefix(qualified, prefix, sizeof(prefix));
	}

	/* find the compiled function: an exact mangled name from symbols.txt, then a spelled-out TARGET or symbol
	   name, then the bare function name (a TARGET may give only that) */
	{
		const vd_sym_t *names[32];
		int             nn = vd_symtab_all_at(ctx->st, b->addr, names, 32), q, best_hit = 0;
		int             forced_hit = 0;

		if (forced >= 0 && (uint32_t)forced < obj->nsymbols && vd_coff_is_function(&obj->symbols[forced])) {
			forced_hit = 1;
			best = forced;
			best_ext = function_extent(obj, (uint32_t)forced) - obj->symbols[forced].value;
		}
		for (k = 0; !forced_hit && k < obj->nsymbols; k++) {
			const vd_coff_symbol_t *s = &obj->symbols[k];
			int                     hit = 0;
			uint32_t                e;

			if (!vd_coff_is_function(s)) {
				continue;
			}
			for (q = 0; q < nn && hit < 4; q++) {
				if (strcmp(s->name, names[q]->mangled) == 0) {
					hit = 4;
				}
			}
			if (hit < 3 && qualified && name_matches(qualified, prefix, s->name)) {
				hit = 3;
			}
			for (q = 0; q < nn && hit < 2; q++) {
				char p2[1024];

				if (mangled_prefix(names[q]->pretty, p2, sizeof(p2)) && name_matches(names[q]->pretty, p2, s->name)) {
					hit = 2;
				}
			}
			if (hit < 1 && qualified && bare_name_matches(qualified, s->name)) {
				hit = 1;
			}
			if (!hit) {
				continue;
			}
			e = function_extent(obj, k) - s->value;
			if (best < 0 || hit > best_hit ||
				(hit == best_hit && e >= b->size && (best_ext < b->size || e < best_ext))) {
				best = k;
				best_ext = e;
				best_hit = hit;
			}
		}
	}
	if (best < 0) {
		r->status = VD_NOSYM;
		snprintf(r->detail, sizeof(r->detail), "no symbol for %s", qualified ? qualified : "(unknown)");
		return;
	}
	fs = &obj->symbols[best];
	r->objsym = fs->name;
	sec = &obj->sections[fs->section];
	ext = best_ext;

	/* length */
	if (ext < b->size) {
		r->status = VD_SIZE;
		snprintf(r->detail, sizeof(r->detail), "compiled 0x%x bytes, retail 0x%x", ext, b->size);
		return;
	}
	for (i = b->size; i < ext; i++) {
		if (!is_padding(sec->data[fs->value + i])) {
			r->status = VD_SIZE;
			snprintf(r->detail, sizeof(r->detail), "compiled 0x%x bytes, retail 0x%x", ext, b->size);
			return;
		}
	}

	/* bytes */
	retail = vd_pe_ptr(ctx->pe, b->addr, b->size);
	if (!retail || !sec->data) {
		r->status = VD_DIFF;
		snprintf(r->detail, sizeof(r->detail), "no retail bytes at 0x%08x", b->addr);
		return;
	}
	{
		unsigned char *mask = vd_xmalloc(b->size);

		memset(mask, 0, b->size);
		for (ri = 0; ri < sec->nrelocs; ri++) {
			uint32_t o = sec->relocs[ri].offset;

			if (o >= fs->value && o < fs->value + b->size) {
				for (i = 0; i < 4 && o - fs->value + i < b->size; i++) {
					mask[o - fs->value + i] = 1;
				}
			}
		}
		for (i = 0; i < b->size; i++) {
			if (!mask[i] && sec->data[fs->value + i] != retail[i]) {
				if (!r->ndiff) {
					r->first_diff = i;
				}
				r->ndiff++;
			}
		}
		free(mask);
	}
	if (r->ndiff) {
		r->status = VD_DIFF;
		snprintf(r->detail, sizeof(r->detail), "%d bytes differ, first at +0x%x", r->ndiff, r->first_diff);
		return;
	}

	/* references */
	for (ri = 0; ri < sec->nrelocs; ri++) {
		const vd_coff_reloc_t *rel = &sec->relocs[ri];
		uint32_t               p, v, a, tfull;
		char                   why[256];
		int                    res;

		off = rel->offset;
		if (off < fs->value || off >= fs->value + b->size) {
			continue;
		}
		p = b->addr + (off - fs->value);
		v = vd_u32(retail + (off - fs->value));
		a = vd_u32(sec->data + off);
		if (rel->type == VD_REL_REL32) {
			tfull = p + 4 + v;       /* the linker writes S + A - (P + 4); the object field holds A */
		} else if (rel->type == VD_REL_DIR32) {
			tfull = v;
		} else if (rel->type == VD_REL_DIR32NB) {
			tfull = v + ctx->pe->image_base;
		} else {
			r->nrefs++;
			r->nunverified++;
			continue;
		}
		r->nrefs++;
		why[0] = 0;
		res = verify_ref(ctx, obj, rel, a, tfull, why, sizeof(why));
		if (res == REF_BAD) {
			r->nbad++;
			if (r->nbad == 1) {
				snprintf(r->detail, sizeof(r->detail), "+0x%x %s", off - fs->value, why);
			}
		} else if (res == REF_UNVERIFIED) {
			r->nunverified++;
			if (!r->nbad && r->nunverified == 1) {
				snprintf(r->detail, sizeof(r->detail), "+0x%x %s", off - fs->value, why);
			}
		}
	}
	if (r->nbad) {
		r->status = VD_REF;
	} else if (r->nunverified) {
		r->status = VD_OK_UNVERIFIED;
	} else {
		r->status = VD_OK;
	}
}

int vd_block_has_name(const vd_ctx_t *ctx, const vd_block_t *b)
{
	return b->target != NULL || vd_symtab_at(ctx->st, b->addr) != NULL;
}
