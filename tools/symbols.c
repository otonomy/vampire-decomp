/* symbols.c -- symbols.txt: every address with its mangled and readable name */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "vd.h"

static uint32_t hash_str(const char *s)
{
	uint32_t h = 2166136261u;

	while (*s) {
		h = (h ^ (unsigned char)*s++) * 16777619u;
	}
	return h;
}

static const vd_symtab_t *g_sort_st;

static int cmp_by_addr(const void *a, const void *b)
{
	const vd_sym_t *x = &g_sort_st->syms[*(const int *)a];
	const vd_sym_t *y = &g_sort_st->syms[*(const int *)b];

	if (x->addr != y->addr) {
		return x->addr < y->addr ? -1 : 1;
	}
	return *(const int *)a - *(const int *)b;
}

/*
================
vd_symtab_load

Each line is "0xADDR kind mangled pretty...".
================
*/
int vd_symtab_load(const char *path, vd_symtab_t *st)
{
	vd_buf_t buf;
	char    *p, *end;
	int      cap = 0;

	memset(st, 0, sizeof(*st));
	if (vd_read_file(path, &buf) != 0) {
		return -1;
	}
	p = (char *)buf.data;
	end = p + buf.size;
	while (p < end) {
		char *line = p, *nl = memchr(p, '\n', (size_t)(end - p));
		char *tok[3];
		int   n = 0;
		char *q;

		if (!nl) {
			nl = end;
		}
		*nl = 0;
		if (nl > line && nl[-1] == '\r') {
			nl[-1] = 0;
		}
		p = nl + 1;

		q = line;
		while (n < 3) {
			while (*q == ' ' || *q == '\t') {
				q++;
			}
			if (!*q) {
				break;
			}
			tok[n++] = q;
			while (*q && *q != ' ' && *q != '\t') {
				q++;
			}
			if (*q) {
				*q++ = 0;
			}
		}
		if (n < 3 || tok[0][0] != '0') {
			continue;
		}
		while (*q == ' ' || *q == '\t') {
			q++;
		}
		if (st->count == cap) {
			cap = cap ? cap * 2 : 4096;
			st->syms = vd_xrealloc(st->syms, sizeof(vd_sym_t) * (size_t)cap);
		}
		st->syms[st->count].addr = (uint32_t)strtoul(tok[0], NULL, 16);
		st->syms[st->count].kind = vd_xstrdup(tok[1]);
		st->syms[st->count].mangled = vd_xstrdup(tok[2]);
		st->syms[st->count].pretty = vd_xstrdup(*q ? q : tok[2]);
		st->syms[st->count].stub = 0;
		st->count++;
	}
	free(buf.data);
	vd_symtab_index(st);
	return 0;
}

/*
================
vd_symtab_index

(Re)build the name hash and the address order.
================
*/
void vd_symtab_index(vd_symtab_t *st)
{
	int i;

	free(st->hash_head);
	free(st->hash_next);
	free(st->by_addr);
	st->hash_size = 1;
	while (st->hash_size < st->count * 2) {
		st->hash_size <<= 1;
	}
	st->hash_head = vd_xmalloc(sizeof(int) * (size_t)st->hash_size);
	st->hash_next = vd_xmalloc(sizeof(int) * (size_t)(st->count + 1));
	for (i = 0; i < st->hash_size; i++) {
		st->hash_head[i] = -1;
	}
	for (i = st->count - 1; i >= 0; i--) {
		uint32_t h = hash_str(st->syms[i].mangled) & (uint32_t)(st->hash_size - 1);

		st->hash_next[i] = st->hash_head[h];
		st->hash_head[h] = i;
	}

	st->by_addr = vd_xmalloc(sizeof(int) * (size_t)(st->count + 1));
	for (i = 0; i < st->count; i++) {
		st->by_addr[i] = i;
	}
	g_sort_st = st;
	qsort(st->by_addr, (size_t)st->count, sizeof(int), cmp_by_addr);
}

/*
================
vd_symtab_add_bodies

symbols.txt names the incremental-link jump stubs. Give each stub's destination the stub's names too, so a
function body can be looked up by its own address.
================
*/
void vd_symtab_add_bodies(vd_symtab_t *st, const vd_pe_t *pe)
{
	int n = st->count, i;

	for (i = 0; i < n; i++) {
		const unsigned char *p = vd_pe_ptr(pe, st->syms[i].addr, 5);
		uint32_t             dest;

		if (strcmp(st->syms[i].kind, "func") != 0 || !p || p[0] != 0xe9 || !vd_pe_is_code(pe, st->syms[i].addr)) {
			continue;
		}
		dest = st->syms[i].addr + 5 + vd_u32(p + 1);
		st->syms = vd_xrealloc(st->syms, sizeof(vd_sym_t) * (size_t)(st->count + 1));
		st->syms[st->count].addr = dest;
		st->syms[st->count].kind = vd_xstrdup("func");
		st->syms[st->count].mangled = vd_xstrdup(st->syms[i].mangled);
		st->syms[st->count].pretty = vd_xstrdup(st->syms[i].pretty);
		st->syms[st->count].stub = st->syms[i].addr;
		st->count++;
	}
	vd_symtab_index(st);
}

int vd_symtab_find(const vd_symtab_t *st, const char *mangled, uint32_t *out, int max)
{
	int i, n = 0;

	if (!st->hash_size) {
		return 0;
	}
	for (i = st->hash_head[hash_str(mangled) & (uint32_t)(st->hash_size - 1)]; i >= 0; i = st->hash_next[i]) {
		if (strcmp(st->syms[i].mangled, mangled) == 0 && n < max) {
			out[n++] = st->syms[i].addr;
		}
	}
	return n;
}

const vd_sym_t *vd_symtab_at(const vd_symtab_t *st, uint32_t addr)
{
	int lo = 0, hi = st->count - 1, found = -1, k;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (st->syms[st->by_addr[mid]].addr < addr) {
			lo = mid + 1;
		} else {
			if (st->syms[st->by_addr[mid]].addr == addr) {
				found = mid;
			}
			hi = mid - 1;
		}
	}
	if (found < 0) {
		return NULL;
	}
	for (k = found; k < st->count && st->syms[st->by_addr[k]].addr == addr; k++) {
		if (strcmp(st->syms[st->by_addr[k]].kind, "func") == 0) {
			return &st->syms[st->by_addr[k]];
		}
	}
	return &st->syms[st->by_addr[found]];
}

/*
================
vd_name_address

Placeholder names carry their address: ?sub_1001482b@@..., ?g_10924a6c@lifted@@..., _sub_10012345.
Returns that address, or 0.
================
*/
uint32_t vd_name_address(const char *mangled)
{
	const char *p = mangled, *e;
	size_t      n;

	if (p[0] == '?' && p[1] != '?') {
		p++;
	} else if (p[0] == '_') {
		p++;
	} else {
		return 0;
	}
	for (e = p; *e && *e != '@'; e++) {
	}
	n = (size_t)(e - p);
	if (n < 9) {
		return 0;
	}
	if (p[n - 9] != '_') {
		return 0;
	}
	{
		const char *h = p + n - 8;
		int         k;

		for (k = 0; k < 8; k++) {
			if (!isxdigit((unsigned char)h[k]) || isupper((unsigned char)h[k])) {
				return 0;
			}
		}
		if (h[0] != '1') {
			return 0;
		}
		return (uint32_t)strtoul(h, NULL, 16);
	}
}

int vd_symtab_all_at(const vd_symtab_t *st, uint32_t addr, const vd_sym_t **out, int max)
{
	int lo = 0, hi = st->count - 1, first = -1, k, n = 0;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (st->syms[st->by_addr[mid]].addr < addr) {
			lo = mid + 1;
		} else {
			if (st->syms[st->by_addr[mid]].addr == addr) {
				first = mid;
			}
			hi = mid - 1;
		}
	}
	for (k = first; first >= 0 && k < st->count && st->syms[st->by_addr[k]].addr == addr && n < max; k++) {
		if (strcmp(st->syms[st->by_addr[k]].kind, "func") == 0) {
			out[n++] = &st->syms[st->by_addr[k]];
		}
	}
	return n;
}
