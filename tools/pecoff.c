/* pecoff.c -- read the retail PE image and the compiler's COFF objects */

#include <stdlib.h>
#include <string.h>

#include "vd.h"

#define SCN_CNT_CODE        0x00000020
#define SCN_CNT_UNINIT_DATA 0x00000080
#define SCN_LNK_COMDAT      0x00001000

/*
================
vd_pe_load
================
*/
int vd_pe_load(const char *path, vd_pe_t *pe)
{
	const unsigned char *d;
	uint32_t pe_off, opt_off, sec_off, imp_rva;
	uint16_t nsec, opt_size;
	int      i;

	memset(pe, 0, sizeof(*pe));
	if (vd_read_file(path, &pe->file) != 0) {
		return -1;
	}
	d = pe->file.data;
	if (pe->file.size < 0x40 || d[0] != 'M' || d[1] != 'Z') {
		return -1;
	}
	pe_off = vd_u32(d + 0x3c);
	if (pe_off + 24 > pe->file.size || memcmp(d + pe_off, "PE\0\0", 4) != 0) {
		return -1;
	}
	nsec = vd_u16(d + pe_off + 6);
	opt_size = vd_u16(d + pe_off + 20);
	opt_off = pe_off + 24;
	if (vd_u16(d + opt_off) != 0x10b) {
		return -1;      /* PE32 only */
	}
	pe->image_base = vd_u32(d + opt_off + 28);
	pe->image_size = vd_u32(d + opt_off + 56);
	sec_off = opt_off + opt_size;

	pe->nsections = nsec;
	pe->sections = vd_xmalloc(sizeof(vd_pe_section_t) * nsec);
	for (i = 0; i < nsec; i++) {
		const unsigned char *s = d + sec_off + 40 * i;
		vd_pe_section_t     *ps = &pe->sections[i];

		memcpy(ps->name, s, 8);
		ps->name[8] = 0;
		ps->vsize = vd_u32(s + 8);
		ps->va = pe->image_base + vd_u32(s + 12);
		ps->raw_size = vd_u32(s + 16);
		ps->raw_off = vd_u32(s + 20);
		ps->flags = vd_u32(s + 36);
	}

	/* imports: map each IAT slot to the name it imports */
	imp_rva = vd_u32(d + opt_off + 96 + 8);
	if (imp_rva) {
		uint32_t             desc_va = pe->image_base + imp_rva;
		const unsigned char *desc;
		int                  cap = 0;

		for (; (desc = vd_pe_ptr(pe, desc_va, 20)) != NULL && vd_u32(desc + 12); desc_va += 20) {
			uint32_t ilt = vd_u32(desc + 0);
			uint32_t iat = vd_u32(desc + 16);
			const unsigned char *dllname = vd_pe_ptr(pe, pe->image_base + vd_u32(desc + 12), 1);
			uint32_t k;

			if (!ilt) {
				ilt = iat;
			}
			for (k = 0;; k++) {
				const unsigned char *e = vd_pe_ptr(pe, pe->image_base + ilt + 4 * k, 4);
				uint32_t v;
				vd_pe_import_t *imp;

				if (!e || !(v = vd_u32(e))) {
					break;
				}
				if (pe->nimports == cap) {
					cap = cap ? cap * 2 : 256;
					pe->imports = vd_xrealloc(pe->imports, sizeof(vd_pe_import_t) * (size_t)cap);
				}
				imp = &pe->imports[pe->nimports++];
				imp->iat_va = pe->image_base + iat + 4 * k;
				imp->dll = vd_xstrdup(dllname ? (const char *)dllname : "?");
				if (v & 0x80000000u) {
					char ord[32];

					sprintf(ord, "#%u", v & 0xffff);
					imp->name = vd_xstrdup(ord);
				} else {
					const unsigned char *hn = vd_pe_ptr(pe, pe->image_base + v + 2, 1);

					imp->name = vd_xstrdup(hn ? (const char *)hn : "?");
				}
			}
		}
	}
	return 0;
}

/*
================
vd_pe_ptr

Returns the file bytes behind [va, va + len), or NULL when the range is not backed by the file.
================
*/
const unsigned char *vd_pe_ptr(const vd_pe_t *pe, uint32_t va, uint32_t len)
{
	int i;

	/* headers */
	if (va >= pe->image_base && va - pe->image_base + len <= 0x1000 && va - pe->image_base + len <= pe->file.size) {
		return pe->file.data + (va - pe->image_base);
	}
	for (i = 0; i < pe->nsections; i++) {
		const vd_pe_section_t *s = &pe->sections[i];

		if (va >= s->va && va - s->va + len <= s->raw_size) {
			if (s->raw_off + (va - s->va) + len > pe->file.size) {
				return NULL;
			}
			return pe->file.data + s->raw_off + (va - s->va);
		}
	}
	return NULL;
}

int vd_pe_is_code(const vd_pe_t *pe, uint32_t va)
{
	int i;

	for (i = 0; i < pe->nsections; i++) {
		const vd_pe_section_t *s = &pe->sections[i];

		if (va >= s->va && va < s->va + s->vsize) {
			return (s->flags & SCN_CNT_CODE) != 0;
		}
	}
	return 0;
}

const vd_pe_import_t *vd_pe_import_at(const vd_pe_t *pe, uint32_t va)
{
	int i;

	for (i = 0; i < pe->nimports; i++) {
		if (pe->imports[i].iat_va == va) {
			return &pe->imports[i];
		}
	}
	return NULL;
}

/*
================
vd_coff_load
================
*/
int vd_coff_load(const char *path, vd_coff_t *obj)
{
	const unsigned char *d;
	uint32_t symoff, strtab_off, i;
	uint16_t nsec, optsize;

	memset(obj, 0, sizeof(*obj));
	if (vd_read_file(path, &obj->file) != 0) {
		return -1;
	}
	d = obj->file.data;
	if (obj->file.size < 20 || vd_u16(d) != 0x14c) {
		return -1;
	}
	nsec = vd_u16(d + 2);
	symoff = vd_u32(d + 8);
	obj->nsymbols = vd_u32(d + 12);
	optsize = vd_u16(d + 16);
	strtab_off = symoff + 18 * obj->nsymbols;
	if (strtab_off > obj->file.size) {
		return -1;
	}

	obj->nsections = nsec;
	obj->sections = vd_xmalloc(sizeof(vd_coff_section_t) * (nsec + 1));
	memset(obj->sections, 0, sizeof(vd_coff_section_t) * (nsec + 1));
	for (i = 0; i < nsec; i++) {
		const unsigned char *s = d + 20 + optsize + 40 * i;
		vd_coff_section_t   *cs = &obj->sections[i + 1];   /* 1-based, as symbols number them */
		uint32_t             nrel, relptr, k;

		memcpy(cs->name, s, 8);
		cs->name[8] = 0;
		cs->size = vd_u32(s + 16);
		cs->flags = vd_u32(s + 36);
		cs->comdat = (cs->flags & SCN_LNK_COMDAT) != 0;
		cs->data = (cs->flags & SCN_CNT_UNINIT_DATA) || !vd_u32(s + 20) ? NULL : d + vd_u32(s + 20);
		relptr = vd_u32(s + 24);
		nrel = vd_u16(s + 32);
		cs->nrelocs = (int)nrel;
		cs->relocs = vd_xmalloc(sizeof(vd_coff_reloc_t) * (nrel + 1));
		for (k = 0; k < nrel; k++) {
			const unsigned char *r = d + relptr + 10 * k;

			cs->relocs[k].offset = vd_u32(r);
			cs->relocs[k].symbol = vd_u32(r + 4);
			cs->relocs[k].type = vd_u16(r + 8);
		}
	}

	obj->symbols = vd_xmalloc(sizeof(vd_coff_symbol_t) * (obj->nsymbols + 1));
	memset(obj->symbols, 0, sizeof(vd_coff_symbol_t) * (obj->nsymbols + 1));
	for (i = 0; i < obj->nsymbols; i++) {
		const unsigned char *s = d + symoff + 18 * i;
		vd_coff_symbol_t    *cs = &obj->symbols[i];
		uint32_t             k;

		if (vd_u32(s) == 0) {
			cs->name = vd_xstrdup((const char *)d + strtab_off + vd_u32(s + 4));
		} else {
			cs->name = vd_xstrndup((const char *)s, strnlen((const char *)s, 8));
		}
		cs->value = vd_u32(s + 8);
		cs->section = (int16_t)vd_u16(s + 12);
		cs->type = vd_u16(s + 14);
		cs->sclass = s[16];
		cs->naux = s[17];
		for (k = 0; k < cs->naux; k++) {
			obj->symbols[i + 1 + k].name = NULL;
		}
		i += cs->naux;
	}
	return 0;
}

void vd_coff_free(vd_coff_t *obj)
{
	int      i;
	uint32_t k;

	for (i = 0; i <= obj->nsections; i++) {
		free(obj->sections[i].relocs);
	}
	free(obj->sections);
	for (k = 0; k < obj->nsymbols; k++) {
		free(obj->symbols[k].name);
	}
	free(obj->symbols);
	free(obj->file.data);
	memset(obj, 0, sizeof(*obj));
}

int vd_coff_is_function(const vd_coff_symbol_t *s)
{
	return s->name && s->section > 0 && (s->type & 0x30) == 0x20 && (s->sclass == 2 || s->sclass == 3);
}
