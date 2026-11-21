/* vd.h -- shared declarations for the vd tools (byte gate, rule checker, renamer) */

#ifndef VD_H
#define VD_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/* ---------------------------------------------------------------- util.c */

typedef struct {
	unsigned char *data;
	size_t         size;
} vd_buf_t;

int   vd_read_file(const char *path, vd_buf_t *out);
int   vd_write_file(const char *path, const void *data, size_t size);
void *vd_xmalloc(size_t n);
void *vd_xrealloc(void *p, size_t n);
char *vd_xstrdup(const char *s);
char *vd_xstrndup(const char *s, size_t n);
void  vd_die(const char *fmt, ...);
int   vd_mkdirs_for(const char *file_path);

uint16_t vd_u16(const unsigned char *p);
uint32_t vd_u32(const unsigned char *p);

/* growable string list */
typedef struct {
	char **items;
	int    count;
	int    cap;
} vd_strlist_t;

void vd_strlist_add(vd_strlist_t *l, const char *s);
void vd_strlist_free(vd_strlist_t *l);

/* --------------------------------------------------------------- pecoff.c */

/* the retail image */
typedef struct {
	char     name[9];
	uint32_t va;        /* absolute */
	uint32_t vsize;
	uint32_t raw_off;
	uint32_t raw_size;
	uint32_t flags;
} vd_pe_section_t;

typedef struct {
	uint32_t iat_va;    /* absolute address of the IAT slot */
	char    *name;      /* imported symbol name, as the export names it */
	char    *dll;
} vd_pe_import_t;

typedef struct {
	vd_buf_t         file;
	uint32_t         image_base;
	uint32_t         image_size;
	int              nsections;
	vd_pe_section_t *sections;
	int              nimports;
	vd_pe_import_t  *imports;
} vd_pe_t;

int                  vd_pe_load(const char *path, vd_pe_t *pe);
const unsigned char *vd_pe_ptr(const vd_pe_t *pe, uint32_t va, uint32_t len);
int                  vd_pe_is_code(const vd_pe_t *pe, uint32_t va);
const vd_pe_import_t *vd_pe_import_at(const vd_pe_t *pe, uint32_t va);

/* an object file */
enum {
	VD_REL_DIR32   = 0x0006,
	VD_REL_DIR32NB = 0x0007,
	VD_REL_REL32   = 0x0014
};

typedef struct {
	uint32_t offset;
	uint32_t symbol;
	uint16_t type;
} vd_coff_reloc_t;

typedef struct {
	char             name[9];
	uint32_t         size;
	const unsigned char *data;  /* NULL for uninitialized data */
	uint32_t         flags;
	int              nrelocs;
	vd_coff_reloc_t *relocs;
	int              comdat;    /* nonzero when IMAGE_SCN_LNK_COMDAT */
} vd_coff_section_t;

typedef struct {
	char    *name;
	uint32_t value;
	int16_t  section;   /* 1-based; 0 undefined, negative absolute/debug */
	uint16_t type;
	uint8_t  sclass;
	uint8_t  naux;
} vd_coff_symbol_t;

typedef struct {
	vd_buf_t           file;
	int                nsections;
	vd_coff_section_t *sections;
	uint32_t           nsymbols;   /* raw count, aux records included */
	vd_coff_symbol_t  *symbols;    /* indexed by raw symbol index; aux slots have name NULL */
} vd_coff_t;

int  vd_coff_load(const char *path, vd_coff_t *obj);
void vd_coff_free(vd_coff_t *obj);
int  vd_coff_is_function(const vd_coff_symbol_t *s);

/* -------------------------------------------------------------- symbols.c */

typedef struct {
	uint32_t addr;
	char    *kind;      /* func, data, vtable */
	char    *mangled;
	char    *pretty;
	uint32_t stub;      /* for a body entry made from a jump stub: the stub's address */
} vd_sym_t;

typedef struct {
	int       count;
	vd_sym_t *syms;
	/* hash of mangled -> index chain */
	int      *hash_head;
	int      *hash_next;
	int       hash_size;
	/* sorted by address */
	int      *by_addr;
} vd_symtab_t;

int        vd_symtab_load(const char *path, vd_symtab_t *st);
void       vd_symtab_index(vd_symtab_t *st);
void       vd_symtab_add_bodies(vd_symtab_t *st, const vd_pe_t *pe);
/* every address that symbols.txt gives this mangled name; returns count */
int        vd_symtab_find(const vd_symtab_t *st, const char *mangled, uint32_t *out, int max);
/* first symbol at an address (func preferred), or NULL */
const vd_sym_t *vd_symtab_at(const vd_symtab_t *st, uint32_t addr);
/* every function symbol at an address (folded bodies carry several); returns count */
int        vd_symtab_all_at(const vd_symtab_t *st, uint32_t addr, const vd_sym_t **out, int max);
/* address encoded in a placeholder name (sub_10001234, g_10701234); 0 if none */
uint32_t   vd_name_address(const char *mangled);

/* --------------------------------------------------------------- source.c */

typedef struct {
	uint32_t addr;
	uint32_t size;
	char    *target;      /* TARGET: name, or NULL */
	int      line_begin;  /* line of the FUNCTION marker, 1-based */
	int      line_end;    /* line of the END FUNCTION marker */
} vd_block_t;

typedef struct {
	char       *path;
	vd_buf_t    text;
	int         nlines;
	char      **lines;     /* pointers into a private copy, NUL-terminated */
	int         nblocks;
	vd_block_t *blocks;
} vd_unit_t;

int  vd_unit_load(const char *path, vd_unit_t *u);
void vd_unit_free(vd_unit_t *u);

/* ---------------------------------------------------------------- check.c */

enum {
	VD_OK = 0,          /* bytes identical and every reference verified */
	VD_OK_UNVERIFIED,   /* bytes identical; some references could not be resolved either way */
	VD_REF,             /* bytes identical outside relocations; a reference names the wrong target */
	VD_DIFF,            /* code bytes differ */
	VD_SIZE,            /* compiled length differs from the annotated size */
	VD_NOSYM,           /* the function was not found in the object */
	VD_NOOBJ            /* the unit did not compile */
};

extern const char *vd_status_names[];

typedef struct {
	int      status;
	int      ndiff;          /* differing bytes (DIFF) */
	uint32_t first_diff;     /* offset of the first difference */
	int      nrefs;
	int      nunverified;
	int      nbad;
	char     detail[256];
	char    *objsym;         /* the object symbol that was compared */
} vd_result_t;

typedef struct {
	const vd_pe_t     *pe;
	const vd_symtab_t *st;
} vd_ctx_t;

/* forced: an object symbol index to compare instead of looking the name up, or -1 */
void vd_check_block(const vd_ctx_t *ctx, const vd_coff_t *obj, const vd_block_t *b, long forced, vd_result_t *r);
/* does this block name its function (TARGET, or symbols.txt at its address)? */
int  vd_block_has_name(const vd_ctx_t *ctx, const vd_block_t *b);

#endif /* VD_H */
