/* rtti.c -- vd rtti: the retail binary's class hierarchy (MSVC RTTI) against the headers' declared bases */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "vd.h"

/*
 * MSVC (VC6, /GR) stores for each vtable, one dword before it, a pointer to the RTTICompleteObjectLocator:
 *   { signature, offset, cdOffset, TypeDescriptor *, ClassHierarchyDescriptor * }
 *   TypeDescriptor            { const void *vftable, void *spare, char name[] }   name: ".?AVClass@@"
 *   ClassHierarchyDescriptor  { signature, attributes, numBaseClasses, BaseClassDescriptor **array }
 *   BaseClassDescriptor       { TypeDescriptor *, numContainedBases, PMD where (3 dwords), attributes }
 * The base array lists the class first, then each direct base followed by that base's own bases.
 */

typedef struct {
	char *name;
	char *bases;        /* direct bases from RTTI, comma-separated */
	char *declared;     /* direct bases the headers declare */
	char *header;
	uint32_t vtable;
} rclass_t;

/* ".?AVCNPC_VBach@@" -> "CNPC_VBach"; ".?AVB@A@@" -> "A::B"; templates keep their mangled argument text */
static void type_name(const char *raw, char *out, size_t outsize)
{
	const char *p = raw;
	char        parts[8][256];
	int         n = 0, i;
	size_t      o = 0;

	if (strncmp(p, ".?AV", 4) == 0 || strncmp(p, ".?AU", 4) == 0) {
		p += 4;
	}
	while (*p && n < 8) {
		size_t l = 0;

		if (p[0] == '@') {
			break;
		}
		if (p[0] == '?' && p[1] == '$') {
			/* a template: take everything up to the matching "@@" of its arguments, roughly */
			const char *e = strstr(p, "@@");

			l = e ? (size_t)(e - p) + 1 : strlen(p);
		} else {
			while (p[l] && p[l] != '@') {
				l++;
			}
		}
		if (l > 255) {
			l = 255;
		}
		memcpy(parts[n], p, l);
		parts[n][l] = 0;
		n++;
		p += l;
		if (*p == '@') {
			p++;
		}
	}
	out[0] = 0;
	for (i = n - 1; i >= 0; i--) {
		o += (size_t)snprintf(out + o, o < outsize ? outsize - o : 0, "%s%s", parts[i], i ? "::" : "");
	}
}

static int read_u32(const vd_pe_t *pe, uint32_t va, uint32_t *out)
{
	const unsigned char *p = vd_pe_ptr(pe, va, 4);

	if (!p) {
		return 0;
	}
	*out = vd_u32(p);
	return 1;
}

static int read_type(const vd_pe_t *pe, uint32_t td, char *out, size_t outsize)
{
	const unsigned char *p = vd_pe_ptr(pe, td + 8, 4);

	if (!p || p[0] != '.' || p[1] != '?') {
		return 0;
	}
	type_name((const char *)p, out, outsize);
	return 1;
}

/* the RTTI direct bases of the class whose vtable is at va */
static int rtti_bases(const vd_pe_t *pe, uint32_t vt, char *self, size_t ss, char *bases, size_t bs)
{
	uint32_t col, td, chd, nbase, arr, i;
	size_t   o = 0;

	if (!read_u32(pe, vt - 4, &col) || !read_u32(pe, col + 12, &td) || !read_u32(pe, col + 16, &chd)) {
		return 0;
	}
	if (!read_type(pe, td, self, ss) || !read_u32(pe, chd + 8, &nbase) || !read_u32(pe, chd + 12, &arr)) {
		return 0;
	}
	if (nbase == 0 || nbase > 256) {
		return 0;
	}
	bases[0] = 0;
	i = 1;
	while (i < nbase) {
		uint32_t bcd, btd, contained;
		char     name[512];

		if (!read_u32(pe, arr + 4 * i, &bcd) || !read_u32(pe, bcd, &btd) || !read_u32(pe, bcd + 4, &contained)) {
			return 0;
		}
		if (!read_type(pe, btd, name, sizeof(name))) {
			return 0;
		}
		o += (size_t)snprintf(bases + o, o < bs ? bs - o : 0, "%s%s", o ? "," : "", name);
		i += 1 + contained;
	}
	return 1;
}

/* ------------------------------------------------------------- headers */

typedef struct {
	char *name;
	char *bases;
	char *header;
} decl_t;

static decl_t *g_decls;
static int     g_ndecls, g_capdecls;

static void add_decl(const char *name, const char *bases, const char *header)
{
	int i;

	for (i = 0; i < g_ndecls; i++) {
		if (strcmp(g_decls[i].name, name) == 0) {
			return;   /* the first definition wins; duplicates are R1's business */
		}
	}
	if (g_ndecls == g_capdecls) {
		g_capdecls = g_capdecls ? g_capdecls * 2 : 1024;
		g_decls = vd_xrealloc(g_decls, sizeof(decl_t) * (size_t)g_capdecls);
	}
	g_decls[g_ndecls].name = vd_xstrdup(name);
	g_decls[g_ndecls].bases = vd_xstrdup(bases);
	g_decls[g_ndecls].header = vd_xstrdup(header);
	g_ndecls++;
}

static const decl_t *find_decl(const char *name)
{
	int i;

	for (i = 0; i < g_ndecls; i++) {
		if (strcmp(g_decls[i].name, name) == 0) {
			return &g_decls[i];
		}
	}
	return NULL;
}

/* "class X : public A, private virtual B {" -> X with bases "A,B"; "class X {" -> X with no bases */
static void scan_header(const char *text, const char *header)
{
	const char *p = text;

	while ((p = strpbrk(p, "cs")) != NULL) {
		int         is_kw = 0;
		const char *q;
		char        name[256], bases[2048];
		size_t      n = 0, o = 0;

		if ((strncmp(p, "class", 5) == 0 && !isalnum((unsigned char)p[5]) && p[5] != '_') ||
			(strncmp(p, "struct", 6) == 0 && !isalnum((unsigned char)p[6]) && p[6] != '_')) {
			is_kw = p == text || (!isalnum((unsigned char)p[-1]) && p[-1] != '_');
		}
		if (!is_kw) {
			p++;
			continue;
		}
		q = p + (p[0] == 'c' ? 5 : 6);
		while (isspace((unsigned char)*q)) {
			q++;
		}
		while ((isalnum((unsigned char)*q) || *q == '_') && n + 1 < sizeof(name)) {
			name[n++] = *q++;
		}
		name[n] = 0;
		while (isspace((unsigned char)*q)) {
			q++;
		}
		p = q;
		if (!n) {
			continue;
		}
		bases[0] = 0;
		if (*q == ':' && q[1] != ':') {
			q++;
			while (*q && *q != '{' && *q != ';') {
				char word[256];
				size_t w = 0;

				while (isspace((unsigned char)*q) || *q == ',') {
					q++;
				}
				if (*q == '{' || *q == ';' || !*q) {
					break;     /* Allman style: the brace on the next line ends the base list */
				}
				while ((isalnum((unsigned char)*q) || *q == '_' || *q == ':' || *q == '<' || *q == '>' || *q == ' ') &&
					   *q != ',' && *q != '{' && w + 1 < sizeof(word)) {
					word[w++] = *q++;
				}
				word[w] = 0;
				/* drop access specifiers and "virtual" */
				{
					char *t = word, *last = word, *s;

					for (s = strtok(t, " "); s; s = strtok(NULL, " ")) {
						if (strcmp(s, "public") && strcmp(s, "protected") && strcmp(s, "private") && strcmp(s, "virtual")) {
							last = s;
						}
					}
					if (w && strcmp(last, "public") && strcmp(last, "protected") && strcmp(last, "private")) {
						o += (size_t)snprintf(bases + o, o < sizeof(bases) ? sizeof(bases) - o : 0, "%s%s", o ? "," : "",
											  last);
					}
				}
				if (!w) {
					q++;
				}
			}
		} else if (*q != '{') {
			continue;   /* a forward declaration or a use */
		}
		if (*q == '{') {
			add_decl(name, bases, header);
		}
	}
}

#ifdef _WIN32
static void list_headers(const char *dir, vd_strlist_t *out)
{
	char             pat[1200];
	WIN32_FIND_DATAA fd;
	HANDLE           h;

	snprintf(pat, sizeof(pat), "%s/*.h", dir);
	h = FindFirstFileA(pat, &fd);
	if (h == INVALID_HANDLE_VALUE) {
		return;
	}
	do {
		char full[1200];

		snprintf(full, sizeof(full), "%s/%s", dir, fd.cFileName);
		vd_strlist_add(out, full);
	} while (FindNextFileA(h, &fd));
	FindClose(h);
}
#endif

/* strip comments so commented-out bases are not read */
static char *strip_comments(const char *s, size_t n)
{
	char  *o = vd_xmalloc(n + 1);
	size_t i = 0, k = 0;

	while (i < n) {
		if (s[i] == '/' && i + 1 < n && s[i + 1] == '/') {
			while (i < n && s[i] != '\n') {
				i++;
			}
		} else if (s[i] == '/' && i + 1 < n && s[i + 1] == '*') {
			i += 2;
			while (i + 1 < n && !(s[i] == '*' && s[i + 1] == '/')) {
				i++;
			}
			i += 2;
		} else {
			o[k++] = s[i++];
		}
	}
	o[k] = 0;
	return o;
}

void vd_load_paths(const char *root, char *dll, size_t dlls, char *cl, size_t cls);

/*
================
vd_rtti_main

vd rtti [--root DIR] [--out FILE]
================
*/
int vd_rtti_main(int argc, char **argv)
{
	char         root[1024] = ".", out[1200] = "", dll[1024], cl[1024], path[1200];
	vd_pe_t      pe;
	vd_symtab_t  st;
	vd_strlist_t headers = { 0 };
	FILE        *f;
	int          i, nclasses = 0, nsame = 0, ndiff = 0, nundeclared = 0;

	for (i = 2; i < argc; i++) {
		if (strcmp(argv[i], "--root") == 0 && i + 1 < argc) {
			snprintf(root, sizeof(root), "%s", argv[++i]);
		} else if (strcmp(argv[i], "--out") == 0 && i + 1 < argc) {
			snprintf(out, sizeof(out), "%s", argv[++i]);
		}
	}
	if (!out[0]) {
		snprintf(out, sizeof(out), "%s/build/rtti.csv", root);
	}
	vd_load_paths(root, dll, sizeof(dll), cl, sizeof(cl));
	if (!dll[0] || vd_pe_load(dll, &pe) != 0) {
		vd_die("set VD_DLL to the retail binary");
	}
	snprintf(path, sizeof(path), "%s/symbols.txt", root);
	if (vd_symtab_load(path, &st) != 0) {
		vd_die("cannot read %s", path);
	}
#ifdef _WIN32
	snprintf(path, sizeof(path), "%s/include", root);
	list_headers(path, &headers);
#endif
	for (i = 0; i < headers.count; i++) {
		vd_buf_t    b;
		char       *code;
		const char *base = strrchr(headers.items[i], '/');

		if (vd_read_file(headers.items[i], &b) != 0) {
			continue;
		}
		code = strip_comments((const char *)b.data, b.size);
		scan_header(code, base ? base + 1 : headers.items[i]);
		free(code);
		free(b.data);
	}

	vd_mkdirs_for(out);
	f = fopen(out, "w");
	if (!f) {
		vd_die("cannot write %s", out);
	}
	fprintf(f, "vtable,class,rtti_bases,declared_bases,header,verdict\n");
	{
		/* one row per class: its primary vtable ("??_7X@@6B@") */
		vd_strlist_t seen = { 0 };

		for (i = 0; i < st.count; i++) {
			const vd_sym_t *s = &st.syms[i];
			char            self[512], bases[4096];
			const decl_t   *d;
			const char     *verdict;
			int             k, dup = 0;

			if (strncmp(s->mangled, "??_7", 4) != 0 || !strstr(s->mangled, "@@6B@")) {
				continue;
			}
			if (strcmp(s->mangled + strlen(s->mangled) - 5, "@@6B@") != 0) {
				continue;     /* a secondary vtable ("6BBase@@@") */
			}
			if (!rtti_bases(&pe, s->addr, self, sizeof(self), bases, sizeof(bases))) {
				continue;
			}
			for (k = 0; k < seen.count; k++) {
				if (strcmp(seen.items[k], self) == 0) {
					dup = 1;
				}
			}
			if (dup) {
				continue;
			}
			vd_strlist_add(&seen, self);
			nclasses++;
			d = find_decl(self);
			if (!d) {
				verdict = "not declared";
				nundeclared++;
			} else if (strcmp(d->bases, bases) == 0) {
				verdict = "same";
				nsame++;
			} else {
				verdict = "differs";
				ndiff++;
			}
			fprintf(f, "0x%08x,\"%s\",\"%s\",\"%s\",\"%s\",%s\n", s->addr, self, bases, d ? d->bases : "",
					d ? d->header : "", verdict);
		}
		vd_strlist_free(&seen);
	}
	fclose(f);
	printf("classes with RTTI: %d; declared bases agree: %d, differ: %d, class not declared: %d\n", nclasses, nsame,
		   ndiff, nundeclared);
	printf("results: %s\n", out);
	return ndiff ? 1 : 0;
}
