/* source.c -- read a unit and its function annotations */

#include <stdlib.h>
#include <string.h>

#include "vd.h"

/*
================
vd_unit_load

A block runs from "// FUNCTION: 0xADDR size=0xSIZE" to "// END FUNCTION". A "// TARGET: name" line inside
it names the symbol the block compiles to when that differs from symbols.txt.
================
*/
int vd_unit_load(const char *path, vd_unit_t *u)
{
	char *p, *end;
	int   cap_lines = 0, cap_blocks = 0, i;
	int   open = -1;

	memset(u, 0, sizeof(*u));
	if (vd_read_file(path, &u->text) != 0) {
		return -1;
	}
	u->path = vd_xstrdup(path);
	p = (char *)u->text.data;
	end = p + u->text.size;
	while (p < end) {
		char *nl = memchr(p, '\n', (size_t)(end - p));

		if (!nl) {
			nl = end;
		}
		if (u->nlines == cap_lines) {
			cap_lines = cap_lines ? cap_lines * 2 : 1024;
			u->lines = vd_xrealloc(u->lines, sizeof(char *) * (size_t)cap_lines);
		}
		u->lines[u->nlines++] = p;
		*nl = 0;
		if (nl > p && nl[-1] == '\r') {
			nl[-1] = 0;
		}
		p = nl + 1;
	}

	for (i = 0; i < u->nlines; i++) {
		const char *l = u->lines[i];
		unsigned    addr, size;

		if (strncmp(l, "// FUNCTION: ", 13) == 0 && sscanf(l + 13, "0x%x size=0x%x", &addr, &size) == 2) {
			if (u->nblocks == cap_blocks) {
				cap_blocks = cap_blocks ? cap_blocks * 2 : 64;
				u->blocks = vd_xrealloc(u->blocks, sizeof(vd_block_t) * (size_t)cap_blocks);
			}
			open = u->nblocks++;
			memset(&u->blocks[open], 0, sizeof(vd_block_t));
			u->blocks[open].addr = addr;
			u->blocks[open].size = size;
			u->blocks[open].line_begin = i + 1;
			u->blocks[open].line_end = i + 1;
		} else if (open >= 0 && strncmp(l, "// TARGET: ", 11) == 0) {
			const char *t = l + 11;
			size_t      n = strlen(t);

			while (n && (t[n - 1] == ' ' || t[n - 1] == '\t')) {
				n--;
			}
			u->blocks[open].target = vd_xstrndup(t, n);
		} else if (open >= 0 && strncmp(l, "// END FUNCTION", 15) == 0) {
			u->blocks[open].line_end = i + 1;
			open = -1;
		}
	}
	return 0;
}

void vd_unit_free(vd_unit_t *u)
{
	int i;

	for (i = 0; i < u->nblocks; i++) {
		free(u->blocks[i].target);
	}
	free(u->blocks);
	free(u->lines);
	free(u->text.data);
	free(u->path);
	memset(u, 0, sizeof(*u));
}
