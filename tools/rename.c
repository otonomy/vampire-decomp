/* rename.c -- vd rename: apply a name map to src/, include/ and symbols.txt */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "vd.h"

/*
 * The map holds one rename per line: OLD<TAB>NEW, where OLD is a whole identifier. Only identifiers that are
 * unique by construction belong in it (address-named placeholders such as sub_10027370), because the renamer
 * does not know C++ scope: every whole-word occurrence is replaced, in source text and inside mangled names
 * (where identifiers are delimited by '?' and '@').
 */

typedef struct {
	char *from;
	char *to;
	long  hits;
} rename_t;

typedef struct {
	rename_t *items;
	int       count, cap;
	int      *head, *next, size;
} rmap_t;

static uint32_t hash_n(const char *s, size_t n)
{
	uint32_t h = 2166136261u;
	size_t   i;

	for (i = 0; i < n; i++) {
		h = (h ^ (unsigned char)s[i]) * 16777619u;
	}
	return h;
}

static rename_t *rmap_find(rmap_t *m, const char *s, size_t n)
{
	int i;

	for (i = m->head[hash_n(s, n) & (uint32_t)(m->size - 1)]; i >= 0; i = m->next[i]) {
		if (strlen(m->items[i].from) == n && memcmp(m->items[i].from, s, n) == 0) {
			return &m->items[i];
		}
	}
	return NULL;
}

static int is_id(int c)
{
	return isalnum(c) || c == '_';
}

/* rewrite one buffer; returns the new text, or NULL when nothing changed */
static char *apply(rmap_t *m, const char *text, size_t n, size_t *outn, long *changes)
{
	char  *out = NULL;
	size_t o = 0, cap = 0, i = 0, last = 0;

	*changes = 0;
	while (i < n) {
		if ((isalpha((unsigned char)text[i]) || text[i] == '_') && (i == 0 || !is_id((unsigned char)text[i - 1]))) {
			size_t    j = i;
			rename_t *r;

			while (j < n && is_id((unsigned char)text[j])) {
				j++;
			}
			r = rmap_find(m, text + i, j - i);
			if (r) {
				size_t need = o + (i - last) + strlen(r->to) + (n - j) + 1;

				if (need > cap) {
					cap = need * 2;
					out = vd_xrealloc(out, cap);
				}
				memcpy(out + o, text + last, i - last);
				o += i - last;
				memcpy(out + o, r->to, strlen(r->to));
				o += strlen(r->to);
				last = j;
				r->hits++;
				(*changes)++;
			}
			i = j;
			continue;
		}
		i++;
	}
	if (!*changes) {
		free(out);
		return NULL;
	}
	if (o + (n - last) + 1 > cap) {
		cap = o + (n - last) + 1;
		out = vd_xrealloc(out, cap);
	}
	memcpy(out + o, text + last, n - last);
	o += n - last;
	out[o] = 0;
	*outn = o;
	return out;
}

#ifdef _WIN32
static void list_tree(const char *dir, vd_strlist_t *out)
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
		char   full[1200];
		size_t l = strlen(fd.cFileName);

		if (fd.cFileName[0] == '.') {
			continue;
		}
		snprintf(full, sizeof(full), "%s/%s", dir, fd.cFileName);
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			list_tree(full, out);
		} else if ((l > 4 && _stricmp(fd.cFileName + l - 4, ".cpp") == 0) ||
				   (l > 2 && _stricmp(fd.cFileName + l - 2, ".h") == 0) ||
				   (l > 4 && _stricmp(fd.cFileName + l - 4, ".asm") == 0)) {
			vd_strlist_add(out, full);
		}
	} while (FindNextFileA(h, &fd));
	FindClose(h);
}
#endif

/*
================
vd_rename_main

vd rename [--root DIR] [--dry-run] MAP
================
*/
int vd_rename_main(int argc, char **argv)
{
	char         root[1024] = ".", path[1200];
	const char  *mapfile = NULL;
	int          dry = 0, i;
	rmap_t       m;
	vd_buf_t     mb;
	vd_strlist_t files = { 0 };
	long         total = 0, nfiles = 0;

	for (i = 2; i < argc; i++) {
		if (strcmp(argv[i], "--root") == 0 && i + 1 < argc) {
			snprintf(root, sizeof(root), "%s", argv[++i]);
		} else if (strcmp(argv[i], "--dry-run") == 0) {
			dry = 1;
		} else {
			mapfile = argv[i];
		}
	}
	if (!mapfile || vd_read_file(mapfile, &mb) != 0) {
		vd_die("usage: vd rename [--root DIR] [--dry-run] MAP");
	}

	memset(&m, 0, sizeof(m));
	{
		char *p = (char *)mb.data, *end = p + mb.size;

		while (p < end) {
			char *nl = memchr(p, '\n', (size_t)(end - p)), *tab;

			if (!nl) {
				nl = end;
			}
			*nl = 0;
			if (nl > p && nl[-1] == '\r') {
				nl[-1] = 0;
			}
			tab = strchr(p, '\t');
			if (p[0] != '#' && tab) {
				char *to = tab + 1, *e;

				*tab = 0;
				e = strchr(to, '\t');
				if (e) {
					*e = 0;
				}
				if (m.count == m.cap) {
					m.cap = m.cap ? m.cap * 2 : 256;
					m.items = vd_xrealloc(m.items, sizeof(rename_t) * (size_t)m.cap);
				}
				m.items[m.count].from = vd_xstrdup(p);
				m.items[m.count].to = vd_xstrdup(to);
				m.items[m.count].hits = 0;
				m.count++;
			}
			p = nl + 1;
		}
	}
	m.size = 1;
	while (m.size < m.count * 2 + 2) {
		m.size <<= 1;
	}
	m.head = vd_xmalloc(sizeof(int) * (size_t)m.size);
	m.next = vd_xmalloc(sizeof(int) * (size_t)(m.count + 1));
	for (i = 0; i < m.size; i++) {
		m.head[i] = -1;
	}
	for (i = 0; i < m.count; i++) {
		uint32_t h = hash_n(m.items[i].from, strlen(m.items[i].from)) & (uint32_t)(m.size - 1);

		if (rmap_find(&m, m.items[i].from, strlen(m.items[i].from))) {
			vd_die("map renames %s twice", m.items[i].from);
		}
		m.next[i] = m.head[h];
		m.head[h] = i;
	}

#ifdef _WIN32
	snprintf(path, sizeof(path), "%s/src", root);
	list_tree(path, &files);
	snprintf(path, sizeof(path), "%s/include", root);
	list_tree(path, &files);
#endif
	snprintf(path, sizeof(path), "%s/symbols.txt", root);
	vd_strlist_add(&files, path);

	for (i = 0; i < files.count; i++) {
		vd_buf_t b;
		size_t   on;
		long     ch;
		char    *nt;

		if (vd_read_file(files.items[i], &b) != 0) {
			continue;
		}
		nt = apply(&m, (const char *)b.data, b.size, &on, &ch);
		if (nt) {
			nfiles++;
			total += ch;
			if (!dry && vd_write_file(files.items[i], nt, on) != 0) {
				vd_die("cannot write %s", files.items[i]);
			}
			free(nt);
		}
		free(b.data);
	}
	for (i = 0; i < m.count; i++) {
		if (!m.items[i].hits) {
			printf("unused: %s\n", m.items[i].from);
		}
	}
	printf("%s%ld replacements in %ld files, %d names\n", dry ? "(dry run) " : "", total, nfiles, m.count);
	return 0;
}
