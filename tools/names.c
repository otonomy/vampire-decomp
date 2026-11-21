/* names.c -- vd names: turn symbol-coverage matches into a rename map, under fixed evidence rules */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "vd.h"

/*
 * Input: a symbol-coverage matches.csv (target_addr,size,section,name,name_from,candidate_names,name_choice,...),
 * where each row says that a prototype binary with debug information holds a function with the same normalised
 * code as the target address.
 *
 * A row becomes a rename only when all of these hold:
 *   - its prototype matches --from (default: the Source engine's own 2006 debug build);
 *   - name_choice is "unique": no other prototype function with that code has a different name;
 *   - the function is at least --min-size bytes (default 48): short forwarders and accessors share their code
 *     shape with many unrelated functions, so a unique match of a short body is no evidence;
 *   - the repository names the function with an address placeholder (sub_<addr>), so the rename is exact;
 *   - the class agrees: the same class, or the repository's class is itself a placeholder;
 *   - no other row gives the same qualified name to a different address;
 *   - the new name is a plain identifier (no templates, operators, constructors or destructors).
 * Rows that name a virtual slot (vfuncN) are written to the anchors file instead: a slot rename spans a class
 * hierarchy and needs type information that a text rename does not have.
 */

typedef struct {
	uint32_t addr;
	uint32_t size;
	char    *name;       /* the prototype's qualified name */
	char    *from;       /* prototype@address */
	char    *choice;
	char    *repo;       /* the repository's qualified name */
	int      verdict;
	char     why[96];
} row_t;

enum { V_RENAME, V_ANCHOR, V_REJECT };

static char *csv_next(char **pp)
{
	char *p = *pp, *out = p, *w = p;

	if (*p == '"') {
		p++;
		while (*p) {
			if (p[0] == '"' && p[1] == '"') {
				*w++ = '"';
				p += 2;
			} else if (*p == '"') {
				p++;
				break;
			} else {
				*w++ = *p++;
			}
		}
		while (*p && *p != ',') {
			p++;
		}
	} else {
		while (*p && *p != ',') {
			*w++ = *p++;
		}
	}
	if (*p == ',') {
		p++;
	}
	*w = 0;
	*pp = p;
	return out;
}

/* split "A::B::f" into class "A::B" and member "f"; class empty for free functions */
static void split_member(const char *q, char *cls, size_t cs, char *mem, size_t ms)
{
	const char *last = NULL, *p;
	int         depth = 0;

	for (p = q; *p; p++) {
		if (*p == '<') {
			depth++;
		} else if (*p == '>') {
			depth--;
		} else if (depth == 0 && p[0] == ':' && p[1] == ':') {
			last = p;
		}
	}
	if (last) {
		snprintf(cls, cs, "%.*s", (int)(last - q), q);
		snprintf(mem, ms, "%s", last + 2);
	} else {
		cls[0] = 0;
		snprintf(mem, ms, "%s", q);
	}
}

static int is_plain_ident(const char *s)
{
	if (!*s || !(isalpha((unsigned char)*s) || *s == '_')) {
		return 0;
	}
	for (; *s; s++) {
		if (!isalnum((unsigned char)*s) && *s != '_') {
			return 0;
		}
	}
	return 1;
}

static int is_placeholder_class(const char *cls)
{
	size_t n = strlen(cls), k, hex = 0;

	if (!n) {
		return 0;
	}
	if (strncmp(cls, "CUnknown", 8) == 0 || strncmp(cls, "CFwd", 4) == 0 || strncmp(cls, "CSymTabUnit", 11) == 0) {
		return 1;
	}
	for (k = n; k > 0 && isxdigit((unsigned char)cls[k - 1]); k--) {
		hex++;
	}
	return hex >= 6;
}

static int is_addr_placeholder(const char *mem, uint32_t addr)
{
	char want[32];

	snprintf(want, sizeof(want), "sub_%08x", addr);
	return strcmp(mem, want) == 0;
}

static int cmp_row_name(const void *a, const void *b)
{
	return strcmp(((const row_t *)a)->name, ((const row_t *)b)->name);
}

static int cmp_row_addr(const void *a, const void *b)
{
	uint32_t x = ((const row_t *)a)->addr, y = ((const row_t *)b)->addr;

	return x < y ? -1 : x > y;
}

void vd_load_paths(const char *root, char *dll, size_t dlls, char *cl, size_t cls);

/*
================
vd_names_main

vd names [--root DIR] [--from TEXT] --matches matches.csv --map OUT.tsv --log OUT.csv
================
*/
int vd_names_main(int argc, char **argv)
{
	char        root[1024] = ".", from[256] = "Half-Life Deathmatch - Source", dll[1024], cl[1024], path[1200];
	const char *matches = NULL, *mapout = NULL, *logout = NULL;
	vd_buf_t    mb;
	vd_symtab_t st;
	vd_pe_t     pe;
	row_t      *rows = NULL;
	int         nrows = 0, cap = 0, i, j;
	FILE       *mf, *lf;
	int         counts[3] = { 0 };
	uint32_t    min_size = 48;

	for (i = 2; i < argc; i++) {
		if (strcmp(argv[i], "--root") == 0 && i + 1 < argc) {
			snprintf(root, sizeof(root), "%s", argv[++i]);
		} else if (strcmp(argv[i], "--from") == 0 && i + 1 < argc) {
			snprintf(from, sizeof(from), "%s", argv[++i]);
		} else if (strcmp(argv[i], "--matches") == 0 && i + 1 < argc) {
			matches = argv[++i];
		} else if (strcmp(argv[i], "--map") == 0 && i + 1 < argc) {
			mapout = argv[++i];
		} else if (strcmp(argv[i], "--log") == 0 && i + 1 < argc) {
			logout = argv[++i];
		} else if (strcmp(argv[i], "--min-size") == 0 && i + 1 < argc) {
			min_size = (uint32_t)strtoul(argv[++i], NULL, 0);
		}
	}
	if (!matches || !mapout || !logout) {
		vd_die("usage: vd names [--root DIR] [--from TEXT] [--min-size N] --matches matches.csv --map OUT.tsv --log OUT.csv");
	}
	snprintf(path, sizeof(path), "%s/symbols.txt", root);
	if (vd_symtab_load(path, &st) != 0) {
		vd_die("cannot read %s", path);
	}
	vd_load_paths(root, dll, sizeof(dll), cl, sizeof(cl));
	if (!dll[0] || vd_pe_load(dll, &pe) != 0) {
		vd_die("set VD_DLL: the stub-to-body map needs the retail binary");
	}
	vd_symtab_add_bodies(&st, &pe);

	if (vd_read_file(matches, &mb) != 0) {
		vd_die("cannot read %s", matches);
	}
	{
		char *p = (char *)mb.data, *end = p + mb.size;
		int   header = 1;

		while (p < end) {
			char *nl = memchr(p, '\n', (size_t)(end - p));
			char *f[8], *q;
			int   k;

			if (!nl) {
				nl = end;
			}
			*nl = 0;
			if (nl > p && nl[-1] == '\r') {
				nl[-1] = 0;
			}
			q = p;
			p = nl + 1;
			if (header) {
				header = 0;
				continue;
			}
			for (k = 0; k < 8; k++) {
				f[k] = csv_next(&q);
			}
			/* target_addr,size,section,name,name_from,candidate_names,name_choice,all_names */
			if (!strstr(f[4], from)) {
				continue;
			}
			if (nrows == cap) {
				cap = cap ? cap * 2 : 512;
				rows = vd_xrealloc(rows, sizeof(row_t) * (size_t)cap);
			}
			memset(&rows[nrows], 0, sizeof(row_t));
			rows[nrows].addr = (uint32_t)strtoul(f[0], NULL, 16);
			rows[nrows].size = (uint32_t)strtoul(f[1], NULL, 10);
			rows[nrows].name = vd_xstrdup(f[3]);
			rows[nrows].from = vd_xstrdup(f[4]);
			rows[nrows].choice = vd_xstrdup(f[6]);
			nrows++;
		}
	}

	/* duplicates: one qualified name for two addresses */
	qsort(rows, (size_t)nrows, sizeof(row_t), cmp_row_name);
	for (i = 0; i < nrows; i = j) {
		for (j = i + 1; j < nrows && strcmp(rows[j].name, rows[i].name) == 0; j++) {
		}
		if (j - i > 1) {
			int k;

			for (k = i; k < j; k++) {
				rows[k].verdict = V_REJECT;
				snprintf(rows[k].why, sizeof(rows[k].why), "name given to %d addresses", j - i);
			}
		}
	}
	qsort(rows, (size_t)nrows, sizeof(row_t), cmp_row_addr);

	for (i = 0; i < nrows; i++) {
		row_t          *r = &rows[i];
		const vd_sym_t *s = vd_symtab_at(&st, r->addr);
		char            ncls[512], nmem[256], rcls[512], rmem[256];

		r->repo = vd_xstrdup(s ? s->pretty : "");
		if (r->verdict == V_REJECT) {
			continue;
		}
		r->verdict = V_REJECT;
		if (r->size < min_size) {
			snprintf(r->why, sizeof(r->why), "%u bytes: too short to identify", r->size);
			continue;
		}
		if (strcmp(r->choice, "unique") != 0) {
			snprintf(r->why, sizeof(r->why), "ambiguous match (%s)", r->choice);
			continue;
		}
		if (!s) {
			snprintf(r->why, sizeof(r->why), "no symbol at the address");
			continue;
		}
		split_member(r->name, ncls, sizeof(ncls), nmem, sizeof(nmem));
		split_member(s->pretty, rcls, sizeof(rcls), rmem, sizeof(rmem));
		if (!is_plain_ident(nmem) || strcmp(nmem, ncls) == 0 || nmem[0] == '~' || strchr(ncls, '<')) {
			snprintf(r->why, sizeof(r->why), "not a plain member name");
			continue;
		}
		if (strcmp(rcls, ncls) != 0 && !is_placeholder_class(rcls)) {
			snprintf(r->why, sizeof(r->why), "class differs: repository %s", rcls[0] ? rcls : "(free function)");
			continue;
		}
		if (!rcls[0] && ncls[0]) {
			snprintf(r->why, sizeof(r->why), "repository has a free function");
			continue;
		}
		if (strncmp(rmem, "vfunc", 5) == 0) {
			r->verdict = V_ANCHOR;
			snprintf(r->why, sizeof(r->why), "virtual slot %s", rmem + 5);
			continue;
		}
		if (!is_addr_placeholder(rmem, r->addr)) {
			snprintf(r->why, sizeof(r->why), "repository name is not sub_<addr>");
			continue;
		}
		r->verdict = V_RENAME;
		snprintf(r->why, sizeof(r->why), "%s", strcmp(rcls, ncls) == 0 ? "class agrees" : "class unconfirmed");
	}

	mf = fopen(mapout, "w");
	lf = fopen(logout, "w");
	if (!mf || !lf) {
		vd_die("cannot write the outputs");
	}
	fprintf(mf, "# generated by vd names from %s; one OLD<TAB>NEW per line\n", matches);
	fprintf(lf, "addr,size,verdict,repository_name,evidence_name,evidence,match,note\n");
	for (i = 0; i < nrows; i++) {
		row_t      *r = &rows[i];
		static const char *vn[] = { "rename", "anchor", "reject" };
		char        nmem[256], ncls[512];

		counts[r->verdict]++;
		split_member(r->name, ncls, sizeof(ncls), nmem, sizeof(nmem));
		if (r->verdict == V_RENAME) {
			fprintf(mf, "sub_%08x\t%s\n", r->addr, nmem);
		}
		fprintf(lf, "0x%08x,%u,%s,\"%s\",\"%s\",\"%s\",%s,\"%s\"\n", r->addr, r->size, vn[r->verdict], r->repo, r->name, r->from,
				r->choice, r->why);
	}
	fclose(mf);
	fclose(lf);
	printf("%d rows from \"%s\": %d renames, %d virtual-slot anchors, %d rejected\n", nrows, from,
		   counts[V_RENAME], counts[V_ANCHOR], counts[V_REJECT]);
	return 0;
}
