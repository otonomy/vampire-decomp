/* util.c -- file and memory helpers */

#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#define vd_mkdir(p) _mkdir(p)
#else
#define vd_mkdir(p) mkdir((p), 0777)
#endif

#include "vd.h"

void vd_die(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fputc('\n', stderr);
	exit(2);
}

void *vd_xmalloc(size_t n)
{
	void *p = malloc(n ? n : 1);

	if (!p) {
		vd_die("out of memory");
	}
	return p;
}

void *vd_xrealloc(void *p, size_t n)
{
	p = realloc(p, n ? n : 1);
	if (!p) {
		vd_die("out of memory");
	}
	return p;
}

char *vd_xstrdup(const char *s)
{
	return vd_xstrndup(s, strlen(s));
}

char *vd_xstrndup(const char *s, size_t n)
{
	char *p = vd_xmalloc(n + 1);

	memcpy(p, s, n);
	p[n] = 0;
	return p;
}

int vd_read_file(const char *path, vd_buf_t *out)
{
	FILE *f = fopen(path, "rb");
	long  n;

	out->data = NULL;
	out->size = 0;
	if (!f) {
		return -1;
	}
	fseek(f, 0, SEEK_END);
	n = ftell(f);
	fseek(f, 0, SEEK_SET);
	out->data = vd_xmalloc((size_t)n + 1);
	if (n > 0 && fread(out->data, 1, (size_t)n, f) != (size_t)n) {
		fclose(f);
		free(out->data);
		out->data = NULL;
		return -1;
	}
	out->data[n] = 0;
	out->size = (size_t)n;
	fclose(f);
	return 0;
}

int vd_write_file(const char *path, const void *data, size_t size)
{
	FILE *f = fopen(path, "wb");

	if (!f) {
		return -1;
	}
	if (size && fwrite(data, 1, size, f) != size) {
		fclose(f);
		return -1;
	}
	return fclose(f);
}

int vd_mkdirs_for(const char *file_path)
{
	char  *p = vd_xstrdup(file_path);
	size_t i;

	for (i = 1; p[i]; i++) {
		if (p[i] == '/' || p[i] == '\\') {
			char c = p[i];

			p[i] = 0;
			if (vd_mkdir(p) != 0 && errno != EEXIST) {
				/* a drive root such as "E:" fails harmlessly */
			}
			p[i] = c;
		}
	}
	free(p);
	return 0;
}

uint16_t vd_u16(const unsigned char *p)
{
	return (uint16_t)(p[0] | (p[1] << 8));
}

uint32_t vd_u32(const unsigned char *p)
{
	return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

void vd_strlist_add(vd_strlist_t *l, const char *s)
{
	if (l->count == l->cap) {
		l->cap = l->cap ? l->cap * 2 : 64;
		l->items = vd_xrealloc(l->items, sizeof(char *) * (size_t)l->cap);
	}
	l->items[l->count++] = vd_xstrdup(s);
}

void vd_strlist_free(vd_strlist_t *l)
{
	int i;

	for (i = 0; i < l->count; i++) {
		free(l->items[i]);
	}
	free(l->items);
	l->items = NULL;
	l->count = l->cap = 0;
}
