/* gate.c -- vd gate / vd check: compile units with VC6 and compare every annotated function */

#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "vd.h"

typedef struct {
	char root[1024];       /* project root: holds project.toml, src/, include/, symbols.txt */
	char cl[1024];         /* CL.EXE */
	char dll[1024];        /* the retail binary */
	char out[1024];        /* build directory */
	char flags[512];
	int  jobs;
	int  verbose;
} vd_gate_opts_t;

/* --------------------------------------------------------------- config */

static void toml_string(const char *text, const char *key, char *out, size_t outsize)
{
	const char *p = text;
	size_t      klen = strlen(key);

	while ((p = strstr(p, key)) != NULL) {
		const char *q = p + klen;

		if ((p == text || p[-1] == '\n') && (*q == ' ' || *q == '=')) {
			size_t n = 0;

			while (*q == ' ' || *q == '=') {
				q++;
			}
			if (*q == '"') {
				q++;
				while (*q && *q != '"' && n + 1 < outsize) {
					if (q[0] == '\\' && q[1] == '\\') {
						q++;
					}
					out[n++] = *q++;
				}
				out[n] = 0;
				return;
			}
		}
		p += klen;
	}
}

static void load_config(vd_gate_opts_t *o)
{
	char     path[1100];
	vd_buf_t t;
	const char *e;

	snprintf(path, sizeof(path), "%s/project.toml", o->root);
	if (vd_read_file(path, &t) == 0) {
		if (!o->dll[0]) {
			toml_string((const char *)t.data, "binary", o->dll, sizeof(o->dll));
		}
		if (!o->cl[0]) {
			toml_string((const char *)t.data, "cl", o->cl, sizeof(o->cl));
		}
		free(t.data);
	}
	/* local overrides: the checked-in project.toml holds the owner's paths */
	if ((e = getenv("VD_DLL")) != NULL && *e) {
		snprintf(o->dll, sizeof(o->dll), "%s", e);
	}
	if ((e = getenv("VD_CL")) != NULL && *e) {
		snprintf(o->cl, sizeof(o->cl), "%s", e);
	}
}

void vd_load_paths(const char *root, char *dll, size_t dlls, char *cl, size_t cls)
{
	vd_gate_opts_t o;

	memset(&o, 0, sizeof(o));
	snprintf(o.root, sizeof(o.root), "%s", root);
	load_config(&o);
	snprintf(dll, dlls, "%s", o.dll);
	snprintf(cl, cls, "%s", o.cl);
}

/* ---------------------------------------------------------------- units */

#ifdef _WIN32
static void list_units(const char *dir, vd_strlist_t *out)
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
			list_units(full, out);
		} else {
			size_t n = strlen(fd.cFileName);

			if (n > 4 && _stricmp(fd.cFileName + n - 4, ".cpp") == 0) {
				vd_strlist_add(out, full);
			}
		}
	} while (FindNextFileA(h, &fd));
	FindClose(h);
}
#endif

static int cmp_str(const void *a, const void *b)
{
	return strcmp(*(char *const *)a, *(char *const *)b);
}

/* build/obj/<path under root>.obj */
static void obj_path_for(const vd_gate_opts_t *o, const char *unit, char *out, size_t outsize)
{
	const char *rel = unit;
	size_t      rl = strlen(o->root);
	char       *dot;

	if (strncmp(unit, o->root, rl) == 0 && (unit[rl] == '/' || unit[rl] == '\\')) {
		rel = unit + rl + 1;
	} else if (strchr(unit, ':') || unit[0] == '/' || unit[0] == '\\' || strstr(unit, "..")) {
		/* a unit outside the project: keep only its file name */
		const char *s1 = strrchr(unit, '/'), *s2 = strrchr(unit, '\\');

		rel = s1 > s2 ? s1 + 1 : s2 ? s2 + 1 : unit;
	}
	snprintf(out, outsize, "%s/obj/%s", o->out, rel);
	dot = strrchr(out, '.');
	if (dot) {
		strcpy(dot, ".obj");
	}
}

/* ------------------------------------------------------------- compiling */

#ifdef _WIN32
static void to_backslashes(char *s)
{
	for (; *s; s++) {
		if (*s == '/') {
			*s = '\\';
		}
	}
}

static void setup_env(const vd_gate_opts_t *o)
{
	char vc[1024], bin[1100], path[8192], inc[4096], *slash;
	const char *old = getenv("PATH");

	snprintf(vc, sizeof(vc), "%s", o->cl);
	to_backslashes(vc);
	slash = strrchr(vc, '\\');           /* ...\VC98\BIN\CL.EXE -> ...\VC98\BIN */
	if (slash) {
		*slash = 0;
	}
	snprintf(bin, sizeof(bin), "%s", vc);
	slash = strrchr(vc, '\\');           /* -> ...\VC98 */
	if (slash) {
		*slash = 0;
	}
	snprintf(path, sizeof(path), "%s;%s\\..\\COMMON\\MSDEV98\\BIN;%s", bin, vc, old ? old : "");
	SetEnvironmentVariableA("PATH", path);
	snprintf(inc, sizeof(inc), "%s\\INCLUDE", vc);
	SetEnvironmentVariableA("INCLUDE", inc);
}

typedef struct {
	HANDLE proc;
	int    index;
} job_t;

/* compile srcs[i] to objs[i] with up to o->jobs compilers at once; ok[i] is set from each exit code */
static int compile_jobs(const vd_gate_opts_t *o, char **srcs, char **objs, int n, int *ok)
{
	job_t *jobs = vd_xmalloc(sizeof(job_t) * (size_t)o->jobs);
	int    running = 0, next = 0, failed = 0, i;

	while (next < n || running > 0) {
		while (running < o->jobs && next < n) {
			char                obj[1200], logp[1300], cmd[8192], src[1200], inc[1200];
			STARTUPINFOA        si;
			PROCESS_INFORMATION pi;
			SECURITY_ATTRIBUTES sa;
			HANDLE              logh;

			snprintf(obj, sizeof(obj), "%s", objs[next]);
			vd_mkdirs_for(obj);
			remove(obj);         /* judge from the compiler's exit code and a fresh file only */
			snprintf(logp, sizeof(logp), "%s.log", obj);
			snprintf(src, sizeof(src), "%s", srcs[next]);
			snprintf(inc, sizeof(inc), "%s/include", o->root);
			to_backslashes(obj);
			to_backslashes(src);
			to_backslashes(inc);
			snprintf(cmd, sizeof(cmd), "\"%s\" /nologo /c %s /I\"%s\" /Fo\"%s\" \"%s\"", o->cl, o->flags, inc, obj,
					 src);

			memset(&sa, 0, sizeof(sa));
			sa.nLength = sizeof(sa);
			sa.bInheritHandle = TRUE;
			logh = CreateFileA(logp, GENERIC_WRITE, FILE_SHARE_READ, &sa, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			memset(&si, 0, sizeof(si));
			si.cb = sizeof(si);
			si.dwFlags = STARTF_USESTDHANDLES;
			si.hStdOutput = logh;
			si.hStdError = logh;
			si.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
			if (!CreateProcessA(NULL, cmd, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
				vd_die("cannot run %s (error %lu)", o->cl, GetLastError());
			}
			CloseHandle(logh);
			CloseHandle(pi.hThread);
			jobs[running].proc = pi.hProcess;
			jobs[running].index = next;
			running++;
			next++;
		}
		{
			HANDLE hs[MAXIMUM_WAIT_OBJECTS];
			DWORD  w, code = 1;

			for (i = 0; i < running; i++) {
				hs[i] = jobs[i].proc;
			}
			w = WaitForMultipleObjects((DWORD)running, hs, FALSE, INFINITE);
			i = (int)(w - WAIT_OBJECT_0);
			if (i < 0 || i >= running) {
				vd_die("wait failed");
			}
			GetExitCodeProcess(jobs[i].proc, &code);
			CloseHandle(jobs[i].proc);
			ok[jobs[i].index] = code == 0;
			if (code != 0) {
				failed++;
				if (o->verbose) {
					fprintf(stderr, "compile failed: %s\n", srcs[jobs[i].index]);
				}
			}
			jobs[i] = jobs[--running];
		}
	}
	free(jobs);
	return failed;
}
#endif

/* ------------------------------------------------------------ one block */

/*
 * A block compiled on its own: the unit's own prelude (the lines before its first block), then the block at its
 * original line numbers.
 */
static void write_block_tu(const vd_unit_t *u, const vd_block_t *b, const char *unit_abs, const char *path)
{
	FILE *f;
	int   first = u->nblocks ? u->blocks[0].line_begin : u->nlines + 1;
	int   ln;
	char  fixed[1200];
	char *c;

	snprintf(fixed, sizeof(fixed), "%s", unit_abs);
	for (c = fixed; *c; c++) {
		if (*c == '\\') {
			*c = '/';
		}
	}
	vd_mkdirs_for(path);
	f = fopen(path, "w");
	if (!f) {
		vd_die("cannot write %s", path);
	}
	for (ln = 1; ln < first; ln++) {
		fprintf(f, "%s\n", u->lines[ln - 1]);
	}
	fprintf(f, "#line %d \"%s\"\n", b->line_begin, fixed);
	for (ln = b->line_begin; ln <= b->line_end; ln++) {
		fprintf(f, "%s\n", u->lines[ln - 1]);
	}
	fclose(f);
}

/* the dynamic initializers a unit registers, in order: the targets of its .CRT$XCU entries */
static int xcu_targets(const vd_coff_t *obj, uint32_t *out, int max)
{
	int s, n = 0;

	for (s = 1; s <= obj->nsections; s++) {
		const vd_coff_section_t *sec = &obj->sections[s];
		int                      k, j;

		if (strncmp(sec->name, ".CRT$XC", 7) != 0 || sec->name[7] == 'A' || sec->name[7] == 'Z') {
			continue;
		}
		/* relocations sorted by offset */
		for (k = 0; k < sec->nrelocs && n < max; k++) {
			uint32_t best = 0xffffffffu;
			int      bi = -1;

			for (j = 0; j < sec->nrelocs; j++) {
				uint32_t off = sec->relocs[j].offset;
				int      used = 0, m;

				for (m = 0; m < n; m++) {
					if (out[m] == sec->relocs[j].symbol) {
						used = 1;
					}
				}
				if (!used && off < best) {
					best = off;
					bi = j;
				}
			}
			if (bi < 0) {
				break;
			}
			out[n++] = sec->relocs[bi].symbol;
		}
	}
	return n;
}

/* ---------------------------------------------------------------- gate */

static void csv_field(FILE *f, const char *s)
{
	fputc('"', f);
	for (; s && *s; s++) {
		if (*s == '"') {
			fputc('"', f);
		}
		fputc(*s, f);
	}
	fputc('"', f);
}

/*
================
vd_gate_main

vd gate [--root DIR] [--out DIR] [--jobs N] [--no-compile] [unit.cpp ...]
================
*/
int vd_gate_main(int argc, char **argv)
{
	vd_gate_opts_t o;
	vd_strlist_t   units = { 0 };
	vd_pe_t        pe;
	vd_symtab_t    st;
	vd_ctx_t       ctx;
	int           *ok, *base, *alone;
	char         **objs, *how;
	vd_unit_t     *uv;
	vd_result_t   *res;
	int            i, compile = 1, per_block = 0, failed = 0, block_failed = 0, units_whole = 0, nblocks = 0;
	long           in_unit = 0;
	long           counts[8] = { 0 };
	long long      bytes[8] = { 0 };
	char           path[1200];
	FILE          *csv;

	memset(&o, 0, sizeof(o));
	strcpy(o.root, ".");
	o.jobs = 16;
	strcpy(o.flags, "/O2 /GR");
	for (i = 2; i < argc; i++) {
		if (strcmp(argv[i], "--root") == 0 && i + 1 < argc) {
			snprintf(o.root, sizeof(o.root), "%s", argv[++i]);
		} else if (strcmp(argv[i], "--out") == 0 && i + 1 < argc) {
			snprintf(o.out, sizeof(o.out), "%s", argv[++i]);
		} else if (strcmp(argv[i], "--jobs") == 0 && i + 1 < argc) {
			o.jobs = atoi(argv[++i]);
		} else if (strcmp(argv[i], "--no-compile") == 0) {
			compile = 0;
		} else if (strcmp(argv[i], "--per-block") == 0) {
			per_block = 1;
		} else if (strcmp(argv[i], "-v") == 0) {
			o.verbose = 1;
		} else {
			vd_strlist_add(&units, argv[i]);
		}
	}
	if (o.jobs < 1) {
		o.jobs = 1;
	}
	if (o.jobs > 60) {
		o.jobs = 60;
	}
	if (!o.out[0]) {
		snprintf(o.out, sizeof(o.out), "%s/build", o.root);
	}
	load_config(&o);
	if (!o.dll[0] || !o.cl[0]) {
		vd_die("set VD_DLL and VD_CL, or binary and cl in project.toml");
	}

	if (vd_pe_load(o.dll, &pe) != 0) {
		vd_die("cannot read %s", o.dll);
	}
	snprintf(path, sizeof(path), "%s/symbols.txt", o.root);
	if (vd_symtab_load(path, &st) != 0) {
		vd_die("cannot read %s", path);
	}
	vd_symtab_add_bodies(&st, &pe);
	ctx.pe = &pe;
	ctx.st = &st;

#ifdef _WIN32
	if (!units.count) {
		snprintf(path, sizeof(path), "%s/src", o.root);
		list_units(path, &units);
	}
#endif
	if (!units.count) {
		vd_die("no units");
	}
	qsort(units.items, (size_t)units.count, sizeof(char *), cmp_str);

	ok = vd_xmalloc(sizeof(int) * (size_t)units.count);
	objs = vd_xmalloc(sizeof(char *) * (size_t)units.count);
	uv = vd_xmalloc(sizeof(vd_unit_t) * (size_t)units.count);
	base = vd_xmalloc(sizeof(int) * (size_t)(units.count + 1));
	for (i = 0; i < units.count; i++) {
		char objp[1200];

		ok[i] = 1;
		obj_path_for(&o, units.items[i], objp, sizeof(objp));
		objs[i] = vd_xstrdup(objp);
		if (vd_unit_load(units.items[i], &uv[i]) != 0) {
			vd_die("cannot read %s", units.items[i]);
		}
		base[i] = nblocks;
		nblocks += uv[i].nblocks;
	}
	base[units.count] = nblocks;
	res = vd_xmalloc(sizeof(vd_result_t) * (size_t)(nblocks + 1));
	how = vd_xmalloc((size_t)(nblocks + 1));
	alone = vd_xmalloc(sizeof(int) * (size_t)(nblocks + 1));
	memset(alone, 0, sizeof(int) * (size_t)(nblocks + 1));

	/* 1. compile each unit whole */
#ifdef _WIN32
	setup_env(&o);
	if (compile && !per_block) {
		failed = compile_jobs(&o, units.items, objs, units.count, ok);
	}
#endif
	for (i = 0; i < units.count; i++) {
		if (per_block) {
			ok[i] = 0;
		} else if (!compile) {
			FILE *f = fopen(objs[i], "rb");

			ok[i] = f != NULL;
			if (f) {
				fclose(f);
			}
		}
	}

	/* 2. check every block against its unit's object */
	for (i = 0; i < units.count; i++) {
		vd_unit_t *u = &uv[i];
		vd_coff_t  obj;
		int        b, nx = 0, xi = 0, have = 0;
		uint32_t   xcu[4096];

		if (ok[i] && vd_coff_load(objs[i], &obj) == 0) {
			have = 1;
			nx = xcu_targets(&obj, xcu, 4096);
			units_whole++;
		}
		for (b = 0; b < u->nblocks; b++) {
			int          k = base[i] + b;
			vd_result_t *r = &res[k];

			if (u->blocks[b].parked) {
				memset(r, 0, sizeof(*r));
				r->status = VD_PARKED;
				snprintf(r->detail, sizeof(r->detail), "parked");
				how[k] = '-';
				continue;
			}
			if (have) {
				long forced = -1;

				if (!vd_block_has_name(&ctx, &u->blocks[b])) {
					forced = xi < nx ? (long)xcu[xi++] : -1;
				}
				vd_check_block(&ctx, &obj, &u->blocks[b], forced, r);
				how[k] = 'u';
			} else {
				memset(r, 0, sizeof(*r));
				r->status = VD_NOOBJ;
				snprintf(r->detail, sizeof(r->detail), "did not compile");
				how[k] = '-';
			}
			if (r->status > VD_OK_UNVERIFIED) {
				alone[k] = 1;
			}
			if (r->objsym) {
				r->objsym = vd_xstrdup(r->objsym);   /* the object is freed below */
			}
		}
		if (have) {
			vd_coff_free(&obj);
		}
	}

	/* 3. compile alone every block that did not match in its unit: the blocks of units that do not compile
	      whole, and functions whose code depends on their neighbours */
	{
		vd_strlist_t bsrc = { 0 }, bobj = { 0 };
		int         *bidx = vd_xmalloc(sizeof(int) * (size_t)(nblocks + 1)), *bok, nb = 0;

		for (i = 0; i < units.count; i++) {
			int b;

			for (b = 0; b < uv[i].nblocks; b++) {
				char tu[1300], ob[1300], *dot, *objdir;

				if (!alone[base[i] + b]) {
					continue;
				}
				snprintf(tu, sizeof(tu), "%s", objs[i]);
				dot = strrchr(tu, '.');
				snprintf(dot, sizeof(tu) - (size_t)(dot - tu), "/%08x.cpp", uv[i].blocks[b].addr);
				objdir = strstr(tu, "/obj/");     /* build/obj/x.obj -> build/blk/x/ADDR.cpp */
				if (objdir) {
					memcpy(objdir, "/blk/", 5);
				}
				snprintf(ob, sizeof(ob), "%s", tu);
				strcpy(strrchr(ob, '.'), ".obj");
				if (compile) {
					write_block_tu(&uv[i], &uv[i].blocks[b], units.items[i], tu);
				}
				vd_strlist_add(&bsrc, tu);
				vd_strlist_add(&bobj, ob);
				bidx[nb++] = base[i] + b;
			}
		}
		bok = vd_xmalloc(sizeof(int) * (size_t)(nb + 1));
		for (i = 0; i < nb; i++) {
			FILE *f = compile ? NULL : fopen(bobj.items[i], "rb");

			bok[i] = compile || f != NULL;
			if (f) {
				fclose(f);
			}
		}
#ifdef _WIN32
		if (compile && nb) {
			block_failed = compile_jobs(&o, bsrc.items, bobj.items, nb, bok);
		}
#endif
		/* 4. check them; keep whichever result is better */
		for (i = 0; i < nb; i++) {
			int         k = bidx[i], ui = 0;
			vd_coff_t   obj;
			vd_result_t r;

			while (ui + 1 <= units.count && base[ui + 1] <= k) {
				ui++;
			}
			if (!bok[i] || vd_coff_load(bobj.items[i], &obj) != 0) {
				continue;
			}
			{
				const vd_block_t *blk = &uv[ui].blocks[k - base[ui]];
				long              forced = -1;

				if (!vd_block_has_name(&ctx, blk)) {
					uint32_t one[4];

					forced = xcu_targets(&obj, one, 4) ? (long)one[0] : -1;
				}
				vd_check_block(&ctx, &obj, blk, forced, &r);
			}
			if (r.objsym) {
				r.objsym = vd_xstrdup(r.objsym);
			}
			if (r.status < res[k].status) {
				res[k] = r;
				how[k] = 'b';
			}
			vd_coff_free(&obj);
		}
		vd_strlist_free(&bsrc);
		vd_strlist_free(&bobj);
		free(bidx);
		free(bok);
	}

	/* 5. results */
	snprintf(path, sizeof(path), "%s/check.csv", o.out);
	vd_mkdirs_for(path);
	csv = fopen(path, "w");
	if (!csv) {
		vd_die("cannot write %s", path);
	}
	fprintf(csv, "addr,size,status,refs,unverified,bad,unit,line,compiled,objsym,detail\n");
	for (i = 0; i < units.count; i++) {
		const char *rel = units.items[i];
		size_t      rl = strlen(o.root);
		int         b;

		if (strncmp(rel, o.root, rl) == 0 && (rel[rl] == '/' || rel[rl] == '\\')) {
			rel += rl + 1;
		}
		for (b = 0; b < uv[i].nblocks; b++) {
			int                k = base[i] + b;
			const vd_result_t *r = &res[k];
			const vd_block_t  *blk = &uv[i].blocks[b];

			counts[r->status]++;
			bytes[r->status] += blk->size;
			if (r->status <= VD_OK_UNVERIFIED && how[k] == 'u') {
				in_unit++;
			}
			fprintf(csv, "0x%08x,0x%x,%s,%d,%d,%d,", blk->addr, blk->size, vd_status_names[r->status], r->nrefs,
					r->nunverified, r->nbad);
			csv_field(csv, rel);
			fprintf(csv, ",%d,%s,", blk->line_begin, how[k] == 'u' ? "unit" : how[k] == 'b' ? "alone" : "none");
			csv_field(csv, r->objsym);
			fputc(',', csv);
			csv_field(csv, r->detail);
			fputc('\n', csv);
			if (o.verbose && r->status > VD_OK_UNVERIFIED) {
				printf("%s 0x%08x %s:%d %s\n", vd_status_names[r->status], blk->addr, rel, blk->line_begin, r->detail);
			}
		}
	}
	fclose(csv);

	{
		long      total = 0, matched;
		long long tb = 0;
		int       s;

		for (s = 0; s <= VD_NOOBJ; s++) {
			total += counts[s];
			tb += bytes[s];
		}
		/* parked functions are counted apart, and in neither number */
		printf("units %d: %d compile whole, %d do not\n", units.count, units_whole, units.count - units_whole);
		for (s = 0; s <= VD_PARKED; s++) {
			printf("  %-14s %6ld functions %9lld bytes\n", vd_status_names[s], counts[s], bytes[s]);
		}
		matched = counts[VD_OK] + counts[VD_OK_UNVERIFIED];
		printf("bytes matched: %ld of %ld annotated functions (%lld of %lld bytes)\n", matched, total,
			   bytes[VD_OK] + bytes[VD_OK_UNVERIFIED], tb);
		printf("  in their own unit: %ld; only when compiled alone: %ld\n", in_unit, matched - in_unit);
		if (block_failed) {
			printf("blocks that did not compile alone: %d\n", block_failed);
		}
		printf("results: %s/check.csv\n", o.out);
		(void)failed;
		return matched == total ? 0 : 1;
	}
}
