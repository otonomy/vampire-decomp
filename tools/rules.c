/* rules.c -- vd rules: the decomp-code-rules checker over every annotated function */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "vd.h"

/*
 * [match] findings (block a match):
 *   R1   a block that compiles the function under another class than the binary names (TARGET view);
 *        a local definition of a type a shared header defines; a class/struct keyword mismatch
 *   R2   a file-scope or local extern of a global in a unit (unless relaxed: --r2 advisory);
 *        one global declared with two types
 *   R4   offset casts: (char *)p + N dereferenced, (char *)this + ..., ((T *)this)[n], offset macros
 *   R13  virtuals named pad/dummy (header finding, applied to the class's functions)
 *   R17  volatile without a "// volatile:" note; if (0) / while (0) outside macros; empty if/else bodies;
 *        bare ";" statements; self-assignment; "+ 0" and "* 1"; padding members
 *   R18  inline assembly
 * advisory: R7 placeholder names, R25 local prototypes and externs, R33 missing banners, R37 #if 0
 */

enum {
	F_R1, F_R2, F_R4, F_R13, F_R17, F_R18,
	F_R7, F_R25, F_R33, F_R37,
	F_COUNT
};

static const char *g_rule_names[F_COUNT] = { "R1", "R2", "R4", "R13", "R17", "R18", "R7", "R25", "R33", "R37" };

#define IS_MATCH_RULE(r) ((r) <= F_R18)

typedef struct {
	int  count[F_COUNT];
	char first[F_COUNT][160];
} findings_t;

typedef struct {
	char root[1024];
	char gate_csv[1100];
	char out[1100];
	char dll[1024];
	int  r2_advisory;
} rules_opts_t;

/* --------------------------------------------------------------- tokens */

static int is_ident_char(int c)
{
	return isalnum(c) || c == '_';
}

static int word_at(const char *s, size_t i, const char *w)
{
	size_t n = strlen(w);

	return strncmp(s + i, w, n) == 0 && (i == 0 || !is_ident_char((unsigned char)s[i - 1])) &&
		   !is_ident_char((unsigned char)s[i + n]);
}

static const char *skip_ws(const char *p)
{
	while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') {
		p++;
	}
	return p;
}

/* p at '(': returns the char after the matching ')', or NULL */
static const char *skip_parens(const char *p)
{
	int depth = 0;

	for (; *p; p++) {
		if (*p == '(') {
			depth++;
		} else if (*p == ')') {
			if (--depth == 0) {
				return p + 1;
			}
		}
	}
	return NULL;
}

static int read_ident(const char *p, char *out, size_t outsize)
{
	size_t n = 0;

	if (!isalpha((unsigned char)*p) && *p != '_') {
		return 0;
	}
	while (is_ident_char((unsigned char)p[n]) && n + 1 < outsize) {
		out[n] = p[n];
		n++;
	}
	out[n] = 0;
	return (int)n;
}

static int read_number(const char *p)
{
	int n = 0;

	if (p[0] == '0' && (p[1] == 'x' || p[1] == 'X')) {
		n = 2;
		while (isxdigit((unsigned char)p[n])) {
			n++;
		}
		return n > 2 ? n : 0;
	}
	while (isdigit((unsigned char)p[n])) {
		n++;
	}
	return n;
}

/*
 * Strip comments and string/char literals from a whole unit, keeping newlines so offsets map to lines. Literals
 * become "" or ''.
 */
static char *strip_code(const char *src, size_t n)
{
	char  *out = vd_xmalloc(n + 1);
	size_t i = 0, o = 0;

	while (i < n) {
		if (src[i] == '/' && i + 1 < n && src[i + 1] == '/') {
			while (i < n && src[i] != '\n') {
				i++;
			}
		} else if (src[i] == '/' && i + 1 < n && src[i + 1] == '*') {
			i += 2;
			while (i + 1 < n && !(src[i] == '*' && src[i + 1] == '/')) {
				if (src[i] == '\n') {
					out[o++] = '\n';
				}
				i++;
			}
			i += 2;
			out[o++] = ' ';
		} else if (src[i] == '"' || src[i] == '\'') {
			char q = src[i++];

			out[o++] = q;
			while (i < n && src[i] != q && src[i] != '\n') {
				if (src[i] == '\\') {
					i++;
				}
				i++;
			}
			out[o++] = q;
			i++;
		} else {
			out[o++] = src[i++];
		}
	}
	out[o] = 0;
	return out;
}

static void note(findings_t *f, int rule, int line, const char *what)
{
	if (f->count[rule]++ == 0) {
		snprintf(f->first[rule], sizeof(f->first[rule]), "line %d: %s", line, what);
	}
}

/* ------------------------------------------------------------ type table */

typedef struct {
	char *name;
	int   is_class;      /* 1 class, 0 struct */
	int   in_header;
	char *where;
} typedef_t;

typedef struct {
	typedef_t *items;
	int        count, cap;
} typetab_t;

static typedef_t *type_find(typetab_t *t, const char *name)
{
	int i;

	for (i = 0; i < t->count; i++) {
		if (strcmp(t->items[i].name, name) == 0) {
			return &t->items[i];
		}
	}
	return NULL;
}

/* a small open hash on top of the list: the tables hold tens of thousands of names */
typedef struct {
	int *head, *next, size;
} nameidx_t;

static uint32_t hash_name(const char *s)
{
	uint32_t h = 2166136261u;

	while (*s) {
		h = (h ^ (unsigned char)*s++) * 16777619u;
	}
	return h;
}

static void typetab_index(typetab_t *t, nameidx_t *ix)
{
	int i;

	ix->size = 1;
	while (ix->size < t->count * 2 + 2) {
		ix->size <<= 1;
	}
	ix->head = vd_xmalloc(sizeof(int) * (size_t)ix->size);
	ix->next = vd_xmalloc(sizeof(int) * (size_t)(t->count + 1));
	for (i = 0; i < ix->size; i++) {
		ix->head[i] = -1;
	}
	for (i = 0; i < t->count; i++) {
		uint32_t h = hash_name(t->items[i].name) & (uint32_t)(ix->size - 1);

		ix->next[i] = ix->head[h];
		ix->head[h] = i;
	}
}

static typedef_t *type_lookup(typetab_t *t, nameidx_t *ix, const char *name)
{
	int i;

	if (!ix->size) {
		return type_find(t, name);
	}
	for (i = ix->head[hash_name(name) & (uint32_t)(ix->size - 1)]; i >= 0; i = ix->next[i]) {
		if (strcmp(t->items[i].name, name) == 0) {
			return &t->items[i];
		}
	}
	return NULL;
}

static void type_add(typetab_t *t, const char *name, int is_class, int in_header, const char *where)
{
	if (t->count == t->cap) {
		t->cap = t->cap ? t->cap * 2 : 1024;
		t->items = vd_xrealloc(t->items, sizeof(typedef_t) * (size_t)t->cap);
	}
	t->items[t->count].name = vd_xstrdup(name);
	t->items[t->count].is_class = is_class;
	t->items[t->count].in_header = in_header;
	t->items[t->count].where = vd_xstrdup(where);
	t->count++;
}

/*
 * Visit every "struct X {", "struct X : B {", "class X {" definition (and, with fwd, "struct X;" declarations)
 * in stripped code. cb(name, is_class, is_definition, offset).
 */
typedef void (*type_cb)(void *ctx, const char *name, int is_class, int is_def, size_t off);

static void scan_types(const char *code, void *ctx, type_cb cb)
{
	size_t i;

	for (i = 0; code[i]; i++) {
		int         is_class;
		const char *p;
		char        name[256];
		int         n;

		if (word_at(code, i, "struct")) {
			is_class = 0;
			p = code + i + 6;
		} else if (word_at(code, i, "class")) {
			is_class = 1;
			p = code + i + 5;
		} else {
			continue;
		}
		p = skip_ws(p);
		/* skip declspecs such as __declspec(novtable) */
		if (strncmp(p, "__declspec", 10) == 0) {
			p = skip_parens(strchr(p, '('));
			if (!p) {
				continue;
			}
			p = skip_ws(p);
		}
		n = read_ident(p, name, sizeof(name));
		if (!n) {
			continue;
		}
		p = skip_ws(p + n);
		if (*p == '{' || (*p == ':' && p[1] != ':')) {
			cb(ctx, name, is_class, 1, i);
		} else if (*p == ';') {
			/* "friend class X;" and template parameters are not forward declarations of interest */
			cb(ctx, name, is_class, 0, i);
		}
	}
}

typedef struct {
	typetab_t  *t;
	const char *where;
} hdr_ctx_t;

static void collect_header_type(void *vctx, const char *name, int is_class, int is_def, size_t off)
{
	hdr_ctx_t *c = vctx;

	(void)off;
	if (is_def && !type_find(c->t, name)) {
		type_add(c->t, name, is_class, 1, c->where);
	}
}

/* ------------------------------------------------------------ the units */

typedef struct {
	char    *name;
	char    *type;
	char    *where;
} extern_t;

typedef struct {
	extern_t *items;
	int       count, cap;
} externs_t;

/* parse "extern TYPE NAME;" / "extern TYPE NAME[...];" (not functions); returns 1 with name/type set */
static int parse_extern(const char *line, char *name, size_t ns, char *type, size_t ts)
{
	const char *p = skip_ws(line);
	const char *semi, *e, *b;
	size_t      n;

	if (!word_at(p, 0, "extern")) {
		return 0;
	}
	p = skip_ws(p + 6);
	if (*p == '"') {
		return 0;    /* extern "C" */
	}
	semi = strchr(p, ';');
	if (!semi) {
		return 0;
	}
	/* a function prototype has "(" that is not a pointer declarator "(*" */
	{
		const char *par = memchr(p, '(', (size_t)(semi - p));

		if (par && skip_ws(par + 1)[0] != '*') {
			return 0;
		}
	}
	e = semi;
	b = memchr(p, '[', (size_t)(semi - p));
	if (b) {
		e = b;
	}
	{
		const char *par = memchr(p, '(', (size_t)(semi - p));

		if (par) {
			/* "(*name)(...)" */
			const char *q = skip_ws(par + 1) + 1;

			q = skip_ws(q);
			n = 0;
			while (is_ident_char((unsigned char)q[n])) {
				n++;
			}
			if (!n || n >= ns) {
				return 0;
			}
			memcpy(name, q, n);
			name[n] = 0;
			snprintf(type, ts, "fnptr:%.*s", (int)(semi - p), p);
			return 1;
		}
	}
	while (e > p && (e[-1] == ' ' || e[-1] == '\t')) {
		e--;
	}
	b = e;
	while (b > p && is_ident_char((unsigned char)b[-1])) {
		b--;
	}
	n = (size_t)(e - b);
	if (!n || n >= ns || b == p) {
		return 0;
	}
	memcpy(name, b, n);
	name[n] = 0;
	/* the type: everything before the name, whitespace-normalised */
	{
		size_t o = 0;
		int    sp = 0;
		const char *q;

		for (q = p; q < b && o + 1 < ts; q++) {
			if (*q == ' ' || *q == '\t') {
				sp = 1;
				continue;
			}
			if (sp && o && o + 2 < ts) {
				type[o++] = ' ';
			}
			sp = 0;
			type[o++] = *q;
		}
		type[o] = 0;
	}
	return 1;
}

typedef struct {
	vd_strlist_t offset_macros;
} unit_state_t;

static int strlist_has(const vd_strlist_t *l, const char *s)
{
	int i;

	for (i = 0; i < l->count; i++) {
		if (strcmp(l->items[i], s) == 0) {
			return 1;
		}
	}
	return 0;
}

/* does code[i..] start an offset cast? reports the identifier being offset */
static int offset_cast_at(const char *code, size_t i, char *base, size_t bs)
{
	const char *p = code + i, *q;
	static const char *bytetypes[] = { "char", "unsigned char", "signed char", "BYTE", "byte", "uint8", "uint8_t",
									   "unsigned __int8", NULL };
	int k, n;

	if (*p != '(') {
		return 0;
	}
	q = skip_ws(p + 1);
	if (strncmp(q, "const ", 6) == 0) {
		q = skip_ws(q + 6);
	}
	for (k = 0; bytetypes[k]; k++) {
		size_t l = strlen(bytetypes[k]);

		if (strncmp(q, bytetypes[k], l) == 0 && !is_ident_char((unsigned char)q[l])) {
			q += l;
			break;
		}
	}
	if (!bytetypes[k]) {
		return 0;
	}
	q = skip_ws(q);
	if (*q != '*') {
		return 0;
	}
	q = skip_ws(q + 1);
	if (*q != ')') {
		return 0;
	}
	q = skip_ws(q + 1);
	if (*q == '(') {
		q = skip_ws(q + 1);
	}
	n = read_ident(q, base, bs);
	if (!n) {
		return 0;
	}
	q = skip_ws(q + n);
	/* member chains: (char *)pEnt->m_x + 4 */
	while ((q[0] == '-' && q[1] == '>') || q[0] == '.') {
		char tmp[256];

		q += q[0] == '.' ? 1 : 2;
		n = read_ident(q, tmp, sizeof(tmp));
		if (!n) {
			return 0;
		}
		q = skip_ws(q + n);
	}
	if (*q == ')') {
		q = skip_ws(q + 1);
	}
	if (*q != '+' && *q != '-') {
		return 0;
	}
	if (q[1] == '+' || q[1] == '-' || q[1] == '=') {
		return 0;
	}
	q = skip_ws(q + 1);
	if (strcmp(base, "this") == 0) {
		return 1;
	}
	if (*q == '(') {
		q = skip_ws(q + 1);
	}
	return read_number(q) > 0;
}

/* byte pointers made from a cast: "char *p = (char *)this;" or "p = (char *)ent;" */
static void collect_byte_locals(const char *code, vd_strlist_t *out)
{
	size_t i;

	for (i = 0; code[i]; i++) {
		const char *p;
		char        name[256];
		int         n;

		if (!word_at(code, i, "char") && !word_at(code, i, "BYTE") && !word_at(code, i, "byte")) {
			continue;
		}
		p = code + i;
		while (is_ident_char((unsigned char)*p)) {
			p++;
		}
		p = skip_ws(p);
		if (*p != '*') {
			continue;
		}
		p = skip_ws(p + 1);
		n = read_ident(p, name, sizeof(name));
		if (!n) {
			continue;
		}
		p = skip_ws(p + n);
		if (*p != '=') {
			continue;
		}
		p = skip_ws(p + 1);
		if (*p == '(' && (strncmp(skip_ws(p + 1), "char", 4) == 0 || strncmp(skip_ws(p + 1), "BYTE", 4) == 0)) {
			if (!strlist_has(out, name)) {
				vd_strlist_add(out, name);
			}
		}
	}
}

static int is_placeholder(const char *id)
{
	size_t n = strlen(id), k, digits = 0, hex = 0;

	if (strncmp(id, "sub_", 4) == 0 || strncmp(id, "vfunc", 5) == 0 || strncmp(id, "FUN_", 4) == 0 ||
		strncmp(id, "DAT_", 4) == 0 || strncmp(id, "unk_", 4) == 0 || strncmp(id, "field_", 6) == 0 ||
		strncmp(id, "param_", 6) == 0 || strncmp(id, "local_", 6) == 0 || strncmp(id, "CUnknown", 8) == 0) {
		return 1;
	}
	/* an address-like run: 6-8 hex digits containing a digit, at the end of the identifier */
	for (k = n; k > 0 && isxdigit((unsigned char)id[k - 1]); k--) {
		hex++;
		if (isdigit((unsigned char)id[k - 1])) {
			digits++;
		}
	}
	if (hex >= 6 && digits && (k == 0 || id[k - 1] == '_' || isalpha((unsigned char)id[k - 1]))) {
		/* the run must start the hex part at a word or underscore boundary: m_n5bb0 is not one */
		if (hex <= 8 && (k == 0 || id[k - 1] == '_' || !isxdigit((unsigned char)id[k - 1]))) {
			return 1;
		}
	}
	return 0;
}

/* --------------------------------------------------------- one block */

typedef struct {
	const rules_opts_t *o;
	typetab_t          *types;
	nameidx_t          *types_ix;
	externs_t          *externs;
	const vd_symtab_t  *st;
	const char         *unit_rel;
} rules_ctx_t;

typedef struct {
	rules_ctx_t *rc;
	findings_t  *f;
	const char  *code;
	size_t       begin;
	const int   *line_of;   /* offset -> line, for the unit */
} block_types_ctx_t;

static void block_type_cb(void *vctx, const char *name, int is_class, int is_def, size_t off)
{
	block_types_ctx_t *c = vctx;
	typedef_t         *t = type_lookup(c->rc->types, c->rc->types_ix, name);
	char               what[200];
	int                line = c->line_of[c->begin + off];

	if (!t) {
		return;
	}
	if (is_def && t->in_header) {
		snprintf(what, sizeof(what), "local definition of %s, which %s defines", name, t->where);
		note(c->f, F_R1, line, what);
	} else if (!is_def && t->is_class != is_class) {
		snprintf(what, sizeof(what), "%s %s; but %s defines it as %s", is_class ? "class" : "struct", name, t->where,
				 t->is_class ? "class" : "struct");
		note(c->f, F_R1, line, what);
	}
}

static void check_block(rules_ctx_t *rc, unit_state_t *us, const vd_unit_t *u, const char *code,
						const size_t *line_off, const int *line_of, const vd_block_t *b, findings_t *f)
{
	size_t       begin = line_off[b->line_begin - 1];
	size_t       end = b->line_end < u->nlines ? line_off[b->line_end] : strlen(code);
	char        *blk = vd_xstrndup(code + begin, end - begin);
	vd_strlist_t bytelocals = { 0 };
	size_t       i;
	int          ln;
	int          saw_banner = 0;

	memset(f, 0, sizeof(*f));

	/* R1: the function compiles under a class the binary does not name */
	if (b->target) {
		const vd_sym_t *s = vd_symtab_at(rc->st, b->addr);

		if (!s || strcmp(s->pretty, b->target) != 0) {
			char what[300];

			snprintf(what, sizeof(what), "compiled as %s; the binary names it %s", b->target,
					 s ? s->pretty : "(no symbol)");
			note(f, F_R1, b->line_begin, what);
		}
	}

	/* R1: local copies of header types, keyword mismatches */
	{
		block_types_ctx_t c;

		c.rc = rc;
		c.f = f;
		c.code = code;
		c.begin = begin;
		c.line_of = line_of;
		scan_types(blk, &c, block_type_cb);
	}

	collect_byte_locals(blk, &bytelocals);

	/* line-based checks */
	for (ln = b->line_begin; ln <= b->line_end && ln <= u->nlines; ln++) {
		size_t      lb = line_off[ln - 1], le = ln < u->nlines ? line_off[ln] : strlen(code);
		char       *line = vd_xstrndup(code + lb, le - lb);
		const char *raw = u->lines[ln - 1];
		const char *t = skip_ws(line);
		int         is_define = strncmp(t, "#define", 7) == 0 || strncmp(t, "# define", 8) == 0;
		char        name[256], type[512];

		/* banners: any comment line that is not an annotation marker */
		{
			const char *r = skip_ws(raw);

			if ((r[0] == '/' && (r[1] == '/' || r[1] == '*')) && strncmp(r, "// FUNCTION:", 12) != 0 &&
				strncmp(r, "// END FUNCTION", 15) != 0 && strncmp(r, "// TARGET:", 10) != 0 &&
				strncmp(r, "// RULE-EXCEPTION", 17) != 0) {
				saw_banner = 1;
			}
		}

		if (strncmp(t, "#if 0", 5) == 0) {
			note(f, F_R37, ln, "#if 0 block");
		}

		/* R2 / R25: declarations in the unit */
		if (parse_extern(t, name, sizeof(name), type, sizeof(type))) {
			char what[400];

			snprintf(what, sizeof(what), "extern %s in the unit", name);
			note(f, rc->o->r2_advisory ? F_R25 : F_R2, ln, what);
			if (rc->externs->count == rc->externs->cap) {
				rc->externs->cap = rc->externs->cap ? rc->externs->cap * 2 : 4096;
				rc->externs->items = vd_xrealloc(rc->externs->items, sizeof(extern_t) * (size_t)rc->externs->cap);
			}
			rc->externs->items[rc->externs->count].name = vd_xstrdup(name);
			rc->externs->items[rc->externs->count].type = vd_xstrdup(type);
			{
				char where[1200];

				snprintf(where, sizeof(where), "%s:%d:0x%08x", rc->unit_rel, ln, b->addr);
				rc->externs->items[rc->externs->count].where = vd_xstrdup(where);
			}
			rc->externs->count++;
		}

		/* offset macros: a #define whose body offsets a byte pointer */
		if (is_define) {
			const char *m = skip_ws(t + (t[1] == ' ' ? 8 : 7));
			char        mname[256];
			int         n = read_ident(m, mname, sizeof(mname));

			for (i = 0; line[i]; i++) {
				char base[256];

				if (offset_cast_at(line, i, base, sizeof(base))) {
					if (n && !strlist_has(&us->offset_macros, mname)) {
						vd_strlist_add(&us->offset_macros, mname);
					}
					note(f, F_R4, ln, "offset macro");
					break;
				}
			}
		}

		for (i = 0; line[i]; i++) {
			char base[256], id[256];
			int  n;

			/* R4 */
			if (line[i] == '(' && offset_cast_at(line, i, base, sizeof(base))) {
				char what[300];

				snprintf(what, sizeof(what), "offset cast on %s", base);
				note(f, F_R4, ln, what);
			}
			if (line[i] == '(' && i + 1 < strlen(line)) {
				/* ((T *)this)[n] */
				const char *q = skip_ws(line + i + 1);

				if (*q == '(') {
					const char *e = skip_parens(q);

					if (e && word_at(skip_ws(e), 0, "this")) {
						const char *after = skip_ws(skip_ws(e) + 4);

						if (*after == ')' && *skip_ws(after + 1) == '[') {
							note(f, F_R4, ln, "this indexed as an array");
						}
					}
				}
			}

			n = read_ident(line + i, id, sizeof(id));
			if (n && (i == 0 || !is_ident_char((unsigned char)line[i - 1]))) {
				const char *after = skip_ws(line + i + n);

				if (!is_define && strlist_has(&us->offset_macros, id) && *after == '(') {
					char what[300];

					snprintf(what, sizeof(what), "offset macro %s", id);
					note(f, F_R4, ln, what);
				}
				if (strlist_has(&bytelocals, id) && (*after == '+' || *after == '-') && after[1] != '+' &&
					after[1] != '-' && after[1] != '=' && read_number(skip_ws(after + 1)) > 0) {
					char what[300];

					snprintf(what, sizeof(what), "offset arithmetic on byte pointer %s", id);
					note(f, F_R4, ln, what);
				}
				if (strcmp(id, "volatile") == 0 && !strstr(raw, "// volatile:")) {
					note(f, F_R17, ln, "volatile");
				}
				if ((strcmp(id, "__asm") == 0 || strcmp(id, "_asm") == 0 || strcmp(id, "asm") == 0) &&
					(*after == '{' || *after == '\n' || *after == 0 || isalpha((unsigned char)*after))) {
					note(f, F_R18, ln, "inline assembly");
				}
				if (!is_define && (strcmp(id, "if") == 0 || strcmp(id, "while") == 0) && *after == '(') {
					const char *z = skip_ws(after + 1);

					if (*z == '0' && *skip_ws(z + 1) == ')') {
						char what[64];

						snprintf(what, sizeof(what), "%s (0)", id);
						note(f, F_R17, ln, what);
					}
				}
				/* padding members: pad, pad2, _pad, padding[...] */
				if ((strncmp(id, "pad", 3) == 0 || strncmp(id, "_pad", 4) == 0) && *after == '[') {
					note(f, F_R17, ln, "padding member");
				}
				if (is_placeholder(id)) {
					f->count[F_R7]++;
					if (f->count[F_R7] == 1) {
						snprintf(f->first[F_R7], sizeof(f->first[F_R7]), "line %d: %s", ln, id);
					}
				}
				/* self-assignment: x = x; */
				if (!is_define && *after == '=' && after[1] != '=') {
					const char *rhs = skip_ws(after + 1);
					char        id2[256];
					int         n2 = read_ident(rhs, id2, sizeof(id2));

					if (n2 && strcmp(id, id2) == 0 && *skip_ws(rhs + n2) == ';' &&
						(i == 0 || (line[i - 1] != '.' && line[i - 1] != '>'))) {
						note(f, F_R17, ln, "self-assignment");
					}
				}
				i += (size_t)n - 1;
				continue;
			}

			/* "+ 0" and "* 1", token-bounded */
			if ((line[i] == '+' || line[i] == '*') && !is_define) {
				const char *z = line + i + 1;
				char        lit = line[i] == '+' ? '0' : '1';

				if (line[i] == '+' && (line[i + 1] == '+' || line[i + 1] == '=' || (i && line[i - 1] == '+'))) {
					continue;
				}
				if (line[i] == '*' && (line[i + 1] == '=' || line[i + 1] == ')' || line[i + 1] == '*')) {
					continue;
				}
				z = skip_ws(z);
				if (*z == lit && !is_ident_char((unsigned char)z[1]) && z[1] != '.' && z[1] != 'x') {
					/* "* 1" must be multiplication: an operand before it */
					size_t k = i;

					while (k > 0 && (line[k - 1] == ' ' || line[k - 1] == '\t')) {
						k--;
					}
					if (k > 0 && (is_ident_char((unsigned char)line[k - 1]) || line[k - 1] == ')' ||
								  line[k - 1] == ']')) {
						char what[16];

						snprintf(what, sizeof(what), "%c %c", line[i], lit);
						note(f, F_R17, ln, what);
					}
				}
			}
		}

		/* empty if/else bodies on one line */
		for (i = 0; line[i]; i++) {
			if (!is_define && word_at(line, i, "if")) {
				const char *q = skip_ws(line + i + 2);
				const char *e;

				if (*q != '(') {
					continue;
				}
				e = skip_parens(q);
				if (!e) {
					continue;
				}
				e = skip_ws(e);
				if (*e == ';' || (*e == '{' && *skip_ws(e + 1) == '}')) {
					note(f, F_R17, ln, "empty if body");
				}
			}
			if (!is_define && word_at(line, i, "else")) {
				const char *e = skip_ws(line + i + 4);

				if (*e == ';' || (*e == '{' && *skip_ws(e + 1) == '}')) {
					note(f, F_R17, ln, "empty else body");
				}
			}
		}

		/* a bare ";" statement: not an empty loop body */
		if (t[0] == ';' && *skip_ws(t + 1) == 0) {
			int k = ln - 1;

			while (k >= b->line_begin) {
				size_t      pb = line_off[k - 1];
				size_t      pe = line_off[k];
				char       *prev = vd_xstrndup(code + pb, pe - pb);
				const char *pt = skip_ws(prev);
				size_t      pl = strlen(pt);

				while (pl && isspace((unsigned char)pt[pl - 1])) {
					pl--;
				}
				if (pl) {
					char last = pt[pl - 1];

					if (last == ';' || last == '{' || last == '}') {
						note(f, F_R17, ln, "bare ; statement");
					}
					free(prev);
					break;
				}
				free(prev);
				k--;
			}
		}

		free(line);
	}

	/* multi-line empty bodies: "if (...)\n{\n}" */
	for (i = 0; blk[i]; i++) {
		if (word_at(blk, i, "if") || word_at(blk, i, "else")) {
			const char *q = skip_ws(blk + i + (blk[i] == 'i' ? 2 : 4));
			const char *e = q;

			if (blk[i] == 'i') {
				if (*q != '(') {
					continue;
				}
				e = skip_parens(q);
				if (!e) {
					continue;
				}
			}
			e = skip_ws(e);
			if (*e == '{' && *skip_ws(e + 1) == '}' && strchr(blk + i, '\n') && strchr(blk + i, '\n') < e) {
				note(f, F_R17, line_of[begin + i], "empty if/else body");
			}
		}
	}

	/* local function prototypes (advisory R25): "T name(args);" at file scope inside the block */
	for (ln = b->line_begin; ln <= b->line_end && ln <= u->nlines; ln++) {
		const char *raw = skip_ws(u->lines[ln - 1]);
		size_t      l = strlen(raw);

		if (l > 2 && raw[l - 1] == ';' && raw[l - 2] == ')' && raw == u->lines[ln - 1] && strchr(raw, '(') &&
			!strchr(raw, '=') && strncmp(raw, "return", 6) != 0 && isalpha((unsigned char)raw[0]) &&
			strncmp(raw, "extern", 6) != 0) {
			note(f, F_R25, ln, "local prototype");
		}
	}

	if (!saw_banner) {
		note(f, F_R33, b->line_begin, "no header comment");
	}

	vd_strlist_free(&bytelocals);
	free(blk);
}

/* ------------------------------------------------------------- gate join */

typedef struct {
	uint32_t addr;
	char     status[24];
} gate_row_t;

static gate_row_t *g_gate;
static int         g_ngate;

static int cmp_gate(const void *a, const void *b)
{
	uint32_t x = ((const gate_row_t *)a)->addr, y = ((const gate_row_t *)b)->addr;

	return x < y ? -1 : x > y;
}

static void load_gate(const char *path)
{
	vd_buf_t buf;
	char    *p, *end;
	int      cap = 0;

	if (vd_read_file(path, &buf) != 0) {
		return;
	}
	p = (char *)buf.data;
	end = p + buf.size;
	p = memchr(p, '\n', (size_t)(end - p));
	while (p && ++p < end) {
		unsigned addr;
		char     st[24];
		char    *nl = memchr(p, '\n', (size_t)(end - p));

		if (sscanf(p, "0x%x,%*[^,],%23[^,]", &addr, st) == 2) {
			if (g_ngate == cap) {
				cap = cap ? cap * 2 : 8192;
				g_gate = vd_xrealloc(g_gate, sizeof(gate_row_t) * (size_t)cap);
			}
			g_gate[g_ngate].addr = addr;
			snprintf(g_gate[g_ngate].status, sizeof(g_gate[g_ngate].status), "%s", st);
			g_ngate++;
		}
		p = nl;
	}
	free(buf.data);
	qsort(g_gate, (size_t)g_ngate, sizeof(gate_row_t), cmp_gate);
}

static const char *gate_status(uint32_t addr)
{
	gate_row_t key, *r;

	key.addr = addr;
	r = bsearch(&key, g_gate, (size_t)g_ngate, sizeof(gate_row_t), cmp_gate);
	return r ? r->status : NULL;
}

/* ------------------------------------------------------------------ main */

#ifdef _WIN32
static void list_files(const char *dir, const char *ext, vd_strlist_t *out)
{
	char             pat[1200];
	WIN32_FIND_DATAA fd;
	HANDLE           h;

	snprintf(pat, sizeof(pat), "%s/*", dir);
	h = FindFirstFileA(pat, &fd);
	if (h == INVALID_HANDLE_VALUE) {
		return;
	}
	do {
		char full[1200];

		if (fd.cFileName[0] == '.') {
			continue;
		}
		snprintf(full, sizeof(full), "%s/%s", dir, fd.cFileName);
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			list_files(full, ext, out);
		} else {
			size_t n = strlen(fd.cFileName), e = strlen(ext);

			if (n > e && _stricmp(fd.cFileName + n - e, ext) == 0) {
				vd_strlist_add(out, full);
			}
		}
	} while (FindNextFileA(h, &fd));
	FindClose(h);
}
#endif

static int cmp_strp(const void *a, const void *b)
{
	return strcmp(*(char *const *)a, *(char *const *)b);
}

static int cmp_extern(const void *a, const void *b)
{
	const extern_t *x = a, *y = b;
	int             c = strcmp(x->name, y->name);

	return c ? c : strcmp(x->type, y->type);
}

void vd_load_paths(const char *root, char *dll, size_t dlls, char *cl, size_t cls);

/*
================
vd_rules_main
================
*/
int vd_rules_main(int argc, char **argv)
{
	rules_opts_t o;
	vd_strlist_t units = { 0 }, headers = { 0 };
	typetab_t    types = { 0 };
	nameidx_t    types_ix = { 0 };
	externs_t    externs = { 0 };
	vd_symtab_t  st;
	vd_pe_t      pe;
	char         path[1200], cl[1024];
	FILE        *out;
	int          i;
	long         n_total = 0, n_bytes_ok = 0, n_rules_ok = 0, n_pending = 0, n_verbatim = 0, n_unmatched = 0;
	long         rule_funcs[F_COUNT] = { 0 };
	long long    b_rules_ok = 0, b_bytes_ok = 0, b_total = 0;
	int          have_pe;

	memset(&o, 0, sizeof(o));
	strcpy(o.root, ".");
	for (i = 2; i < argc; i++) {
		if (strcmp(argv[i], "--root") == 0 && i + 1 < argc) {
			snprintf(o.root, sizeof(o.root), "%s", argv[++i]);
		} else if (strcmp(argv[i], "--gate") == 0 && i + 1 < argc) {
			snprintf(o.gate_csv, sizeof(o.gate_csv), "%s", argv[++i]);
		} else if (strcmp(argv[i], "--out") == 0 && i + 1 < argc) {
			snprintf(o.out, sizeof(o.out), "%s", argv[++i]);
		} else if (strcmp(argv[i], "--r2") == 0 && i + 1 < argc) {
			o.r2_advisory = strcmp(argv[++i], "advisory") == 0;
		} else {
			vd_strlist_add(&units, argv[i]);
		}
	}
	if (!o.gate_csv[0]) {
		snprintf(o.gate_csv, sizeof(o.gate_csv), "%s/build/check.csv", o.root);
	}
	if (!o.out[0]) {
		snprintf(o.out, sizeof(o.out), "%s/build/rules.csv", o.root);
	}

	snprintf(path, sizeof(path), "%s/symbols.txt", o.root);
	if (vd_symtab_load(path, &st) != 0) {
		vd_die("cannot read %s", path);
	}
	vd_load_paths(o.root, o.dll, sizeof(o.dll), cl, sizeof(cl));
	have_pe = o.dll[0] && vd_pe_load(o.dll, &pe) == 0;
	if (have_pe) {
		vd_symtab_add_bodies(&st, &pe);
	} else {
		fprintf(stderr, "warning: no retail binary (VD_DLL); TARGET checks use stub names only\n");
	}
	load_gate(o.gate_csv);

#ifdef _WIN32
	snprintf(path, sizeof(path), "%s/include", o.root);
	list_files(path, ".h", &headers);
	if (!units.count) {
		snprintf(path, sizeof(path), "%s/src", o.root);
		list_files(path, ".cpp", &units);
	}
#endif
	qsort(units.items, (size_t)units.count, sizeof(char *), cmp_strp);

	/* the shared type table */
	for (i = 0; i < headers.count; i++) {
		vd_buf_t  b;
		char     *code;
		hdr_ctx_t c;
		const char *base = strrchr(headers.items[i], '/');

		if (vd_read_file(headers.items[i], &b) != 0) {
			continue;
		}
		code = strip_code((const char *)b.data, b.size);
		c.t = &types;
		c.where = base ? base + 1 : headers.items[i];
		scan_types(code, &c, collect_header_type);
		free(code);
		free(b.data);
	}
	typetab_index(&types, &types_ix);

	vd_mkdirs_for(o.out);
	out = fopen(o.out, "w");
	if (!out) {
		vd_die("cannot write %s", o.out);
	}
	fprintf(out, "addr,size,bytes,rules,status,unit,line,match_findings,R7_placeholders,advisory,first_finding\n");

	for (i = 0; i < units.count; i++) {
		vd_unit_t    u;
		char        *code;
		size_t      *line_off;
		int         *line_of;
		size_t       n, k;
		int          ln, b;
		unit_state_t us = { { 0 } };
		rules_ctx_t  rc;
		const char  *rel = units.items[i];
		size_t       rl = strlen(o.root);

		if (strncmp(rel, o.root, rl) == 0 && (rel[rl] == '/' || rel[rl] == '\\')) {
			rel += rl + 1;
		}
		if (vd_unit_load(units.items[i], &u) != 0) {
			continue;
		}
		/* vd_unit_load split the text in place; rebuild the stripped code from the lines */
		{
			size_t total = 0;
			char  *joined, *w;

			for (ln = 0; ln < u.nlines; ln++) {
				total += strlen(u.lines[ln]) + 1;
			}
			joined = vd_xmalloc(total + 1);
			w = joined;
			for (ln = 0; ln < u.nlines; ln++) {
				size_t l = strlen(u.lines[ln]);

				memcpy(w, u.lines[ln], l);
				w += l;
				*w++ = '\n';
			}
			*w = 0;
			code = strip_code(joined, total);
			free(joined);
		}
		n = strlen(code);
		line_off = vd_xmalloc(sizeof(size_t) * (size_t)(u.nlines + 1));
		line_of = vd_xmalloc(sizeof(int) * (n + 1));
		ln = 0;
		line_off[0] = 0;
		for (k = 0; k < n; k++) {
			line_of[k] = ln + 1;
			if (code[k] == '\n' && ln + 1 <= u.nlines) {
				ln++;
				line_off[ln] = k + 1;
			}
		}
		line_of[n] = ln + 1;
		while (ln < u.nlines) {
			line_off[++ln] = n;
		}

		rc.o = &o;
		rc.types = &types;
		rc.types_ix = &types_ix;
		rc.externs = &externs;
		rc.st = &st;
		rc.unit_rel = rel;

		for (b = 0; b < u.nblocks; b++) {
			findings_t  f;
			const char *gs = gate_status(u.blocks[b].addr);
			int         bytes_ok = gs && (strcmp(gs, "OK") == 0 || strcmp(gs, "OK-UNVERIFIED") == 0);
			int         nmatch = 0, r;
			const char *status;
			char        rules_s[64] = "", adv[128] = "", first[200] = "";

			check_block(&rc, &us, &u, code, line_off, line_of, &u.blocks[b], &f);
			for (r = 0; r < F_COUNT; r++) {
				if (f.count[r]) {
					rule_funcs[r]++;
				}
				if (IS_MATCH_RULE(r) && f.count[r] && r != F_R18) {
					nmatch++;
					if (rules_s[0]) {
						strcat(rules_s, " ");
					}
					strcat(rules_s, g_rule_names[r]);
					if (!first[0]) {
						snprintf(first, sizeof(first), "%s %s", g_rule_names[r], f.first[r]);
					}
				}
			}
			for (r = F_R25; r < F_COUNT; r++) {
				if (f.count[r]) {
					char one[32];

					snprintf(one, sizeof(one), "%s%s:%d", adv[0] ? " " : "", g_rule_names[r], f.count[r]);
					strcat(adv, one);
				}
			}

			n_total++;
			b_total += u.blocks[b].size;
			if (bytes_ok) {
				n_bytes_ok++;
				b_bytes_ok += u.blocks[b].size;
			}
			if (f.count[F_R18]) {
				status = "VERBATIM";
				if (bytes_ok) {
					n_verbatim++;
				}
				snprintf(first, sizeof(first), "R18 %s", f.first[F_R18]);
			} else if (!bytes_ok) {
				status = "UNMATCHED";
				n_unmatched++;
			} else if (nmatch) {
				status = "MATCH-PENDING";
				n_pending++;
			} else {
				status = "MATCHED";
				n_rules_ok++;
				b_rules_ok += u.blocks[b].size;
			}
			fprintf(out, "0x%08x,0x%x,%s,%s,%s,", u.blocks[b].addr, u.blocks[b].size, gs ? gs : "-",
					nmatch ? "fail" : "pass", status);
			fprintf(out, "\"%s\",%d,\"%s\",%d,\"%s\",\"", rel, u.blocks[b].line_begin, rules_s, f.count[F_R7], adv);
			for (k = 0; first[k]; k++) {
				if (first[k] == '"') {
					fputc('"', out);
				}
				fputc(first[k], out);
			}
			fprintf(out, "\"\n");
		}

		vd_strlist_free(&us.offset_macros);
		free(line_off);
		free(line_of);
		free(code);
		vd_unit_free(&u);
	}
	fclose(out);

	/* R2: one global declared with two types */
	if (externs.count) {
		int j, conflicts = 0;

		qsort(externs.items, (size_t)externs.count, sizeof(extern_t), cmp_extern);
		snprintf(path, sizeof(path), "%s.r2-conflicts.txt", o.out);
		out = fopen(path, "w");
		for (i = 0; i < externs.count; i = j) {
			int distinct = 1;

			for (j = i + 1; j < externs.count && strcmp(externs.items[j].name, externs.items[i].name) == 0; j++) {
				if (strcmp(externs.items[j].type, externs.items[j - 1].type) != 0) {
					distinct++;
				}
			}
			if (distinct > 1 && out) {
				int k;

				conflicts++;
				fprintf(out, "%s:\n", externs.items[i].name);
				for (k = i; k < j; k++) {
					fprintf(out, "  %-40s %s\n", externs.items[k].type, externs.items[k].where);
				}
			}
		}
		if (out) {
			fclose(out);
		}
		printf("R2: %d globals declared with more than one type (%s)\n", conflicts, path);
	}

	printf("annotated functions:         %6ld (%lld bytes)\n", n_total, b_total);
	printf("bytes matched:               %6ld (%lld bytes)\n", n_bytes_ok, b_bytes_ok);
	printf("matched under the rules:     %6ld (%lld bytes)\n", n_rules_ok, b_rules_ok);
	printf("MATCH-PENDING:               %6ld\n", n_pending);
	printf("verbatim (inline assembly):  %6ld\n", n_verbatim);
	printf("not byte-matched:            %6ld\n", n_unmatched);
	printf("functions with findings, by rule:\n");
	for (i = 0; i < F_COUNT; i++) {
		printf("  %-4s %s %6ld\n", g_rule_names[i], IS_MATCH_RULE(i) ? "[match]   " : "[advisory]", rule_funcs[i]);
	}
	printf("results: %s\n", o.out);
	return 0;
}
