// Source's datamap layer (save/restore data descriptions), as the game lays it out.
// typedescription_t is 0x2c bytes; datamap_t is {dataDesc, dataNumFields, dataClassName, baseMap}.
// Field flags: 0x2 FIELD, 0x4 KEY (externalName is the keyvalue name), 0x8 INPUTFUNC, 0x10 OUTPUT, 0x20 FUNCTION.
#pragma once

struct typedescription_t;

struct datamap_t
{
	typedescription_t *dataDesc;
	int dataNumFields;
	const char *dataClassName;
	datamap_t *baseMap;
};

#include "SaveRestoreFieldInfo_t.h"

#include "ISaveRestoreOps.h"

struct typedescription_t
{
	int fieldType;	// +0x00: 1,15 float; 2,16,17 string-like int; 3,14 vector; 4 int; 5 bool; 6 short; 7 char; 8 color; 9 embedded (td); 10 custom ops
	const char *fieldName;	// +0x04
	int fieldOffset[2];	// +0x08
	unsigned short fieldSize;	// +0x10
	short flags;	// +0x12
	const char *externalName;	// +0x14
	ISaveRestoreOps *pSaveRestoreOps;	// +0x18
	void *inputFunc;	// +0x1c
	datamap_t *td;	// +0x20 (embedded fields)
	union { int fieldSizeInBytes; typedescription_t *override_field; };	// +0x24 (prediction copy: the field this one overrides)
	union { int unk; int override_count; };	// +0x28 (prediction copy: the chain count that skips this field)
};
