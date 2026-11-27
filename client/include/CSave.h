// class CSave (RTTI .?AVCSave@@), primary vtable 0x10476fbc, 40 slots.
// Only the slots that decompiled code needs have their signature; the rest are placeholders.
#pragma once

#include "ISave.h"
#include "utlvector.h"
#include "Vector.h"

struct typedescription_t;
struct CSaveEdict;

class CSave : public ISave
{
public:
	virtual int vfunc0();	// current position
	virtual void vfunc1(int pos);	// seek
	virtual void vfunc2(void *pBlock, const char *pszName);	// slot 2: the save hook of a custom block (the physics save block handler hands it its block at +0x98 and an empty name)
	virtual int vfunc3(int a, int b, int c, int d, int e);	// "CSave::WriteFields" (name, base data, root map, fields, field count): stub 0x1000b258, returns 1
	virtual void vfunc4();
	virtual void vfunc5(const void *p);	// pushes the current position on the section stack (vector at +4) after sub_101a05f0(p, 0)
	virtual void vfunc6();	// pops the section stack, writes the section size
	virtual void vfunc7(int a, int b, int count);	// forwards to sub_101a05b0 with the count doubled (shorts to bytes)
	virtual bool vfunc8(const void *pData, int nBytes);	// slot 8: writes nBytes * 2 bytes through sub_1000643d (the physics save block handler writes its flag 1 under the global name at 0x1053c340)
	virtual void vfunc9(const char *pszName, void *pData, int count);	// writes count ints (called by vfunc37 with the entity indices)
	virtual bool vfunc10(const void *pData, int nBytes);	// WriteInt
	virtual int vfunc11(int, int, int);
	virtual void vfunc12(const void *pData, int count);
	virtual void vfunc13(const char *pszName, void *pData, int count);
	virtual bool vfunc14(const void *pData, int nBytes);
	virtual void vfunc15(int a, int b, int c);	// 0x1019fc00: a tail call of sub_101a05b0
	virtual void vfunc16(const void *pData, int nBytes);	// slot 16: writes the float at pData (a 4-byte value), called by vfunc25 with the difference of two floats
	virtual void vfunc17(const char *pszName, void *pData, int count);	// slot used by WriteField for field types 0x10 / 0x11
	virtual void vfunc18(int a, const char *psz);
	virtual void vfunc19(const char **ppStrings, int count);	// writes count strings (a null entry is the empty string at 0x106b8540), each with its length + 1 through sub_1000643d
	virtual void vfunc20(const char *pString);	// WriteString
	virtual void vfunc21(const char *pszName, const void *pData, int count);	// 0x1019fdd0: sub_101a05f0(count, count * 12), then sub_1000643d(pData, count * 12); pszName is unused
	virtual void vfunc22(const char *pszName, const Vector &value);	// slot 22: writes a named vector (called by vfunc30 with the landmark relative position)
	virtual void vfunc23(const void *pData, int count);	// WriteVector
	virtual void vfunc24(const Vector &value);	// WriteVector (one vector)
	virtual void vfunc25(const float *pValues, int count);	// slot 25: for each of the count floats writes the value minus the float at +0x12e8 of the entity block (m_pEntityBlock) through slot 16
	virtual void vfunc26(const char *pszName, void *pData, int count);	// slot used by WriteField for field type 0xf
	virtual void vfunc27(const Vector *pValues, int count);	// WritePositionVector (array): for each vector, the vector minus the landmark offset (see slot 28) written through slot 16 with 12 bytes
	virtual void vfunc28(const Vector &value);	// WritePositionVector: with the landmark flag at +0x12c4 of the entity block set, the vector minus the landmark offset at +0x12dc is written through slot 24; without it the offset is the zero vector (0x1070d1b0)
	virtual void vfunc29(const char *pszName, void *pData, int count);	// slot used by WriteField for field type 0xe
	virtual void vfunc30(const char *pszName, const Vector &value);	// named version of vfunc28: the same landmark relative vector, written through slot 22 under pszName
	virtual void vfunc31(void *pBase, const char *pszName, void *pData, int count);	// slot used by WriteField for field type 0x13
	virtual void vfunc32(const int *pHandles, int count);	// converts count entities to table indices (sub_101a08f0) on the stack, writes them through slot 10
	virtual void vfunc33(const char *pszName, void *pData, int count);	// slot used by WriteField for field type 0xb
	virtual void vfunc34(CSaveEdict *const *pEdicts, int count);	// converts count edicts to table indices (sub_101a0830) on the stack, writes them through slot 10
	virtual void vfunc35(const char *pszName, void *pData, int count);	// slot used by WriteField for field type 0xd
	virtual void vfunc36(const void *pData, int count);	// WriteEHandle
	virtual void vfunc37(const char *pszName, void *pData, int count);	// slot used by WriteField for field type 0xc: converts the entity handles to entity table indices (sub_101a08f0) and writes them through slot 9
	virtual int vfunc38();
	void *vfunc39(unsigned char bFree);

	CSave(void *pData);	// stub 0x10009bf6

	// the section stack at +4 (a CUtlVector<int> without its destructor: the game's code tears it down by hand), the
	// buffer and the entity block; initialised by the constructor's initialiser list, before CSave's vptr store
	int *m_pSections;	// +0x04
	int m_nAlloc;	// +0x08
	int m_nGrow;	// +0x0c
	int m_nSections;	// +0x10
	int *m_pElements;	// +0x14
	void *m_pData;	// +0x18
	void *m_pEntityBlock;	// +0x1c: block holding the entity table (count at +0x1318, entries at +0x131c)

	int sub_10129640(int a, int b, struct CSaveDesc *p);	// walks the chain of descriptions (p->m_pParent at +0xc, parents first) and calls slot 3 with the five dwords of each; stub 0x10008d4b
	int sub_1012ab00(int a, int b, struct CSaveDesc *p);
		// the jump stub of sub_101a0320, used by its recursive call

		// ORs flags into the entity table entry (0x30 bytes, flags at +0x20); returns the new flags, 0 when out of range
	int sub_10129a30(void *pEntity);	// index of the entity in the table, or -1
		// "CSave::EntityIndex" (edict): -1 for null, else sub_101a08f0 of the entity of the edict (CBaseEntity::Instance scope trace around slot 4 of the object at edict+0x40)
	void sub_10129830(int a, int bytes, int b);
	void sub_10129860(const void *p, int a);	// called by vfunc5 through the stub at 0x1000950c
	bool sub_101299c0(const void *pData, int nBits);	// as in CUnknown100bde40 (transplant)
	void sub_1012b150(const unsigned short *pToken, void *pData, void *pRootMap, typedescription_t *pField);
	void sub_1012a350(const unsigned short *pToken, void *pData, void *pRootMap, typedescription_t *pField);	// "CSave::WriteBasicField" (stub 0x1001069a): dispatches on the field type (1..10) to the matching write slot (data, field size, token), embedded structs (9) go to WriteAll(data, td), custom fields (10) to the field's save/restore ops, "Bad field type" warning otherwise
	bool sub_1012a060(int a, void *pData, void *pBase, typedescription_t *pField);	// "CSave::WriteField": dispatches on the field type (0xb..0x13) to the matching write slot, "Bad field type" warning otherwise
		// the CSave constructor (the stub at 0x10009bf6)
		// writes the size byte string pData under pszName (stub 0x100139b7)
	bool sub_10129250(void *pData, typedescription_t *pField);	// "CSave::IsFieldNonEmpty"-like (recursive, stub 0x10015aaf): whether the field holds data that has to be saved: embedded structures (type 9) are checked field by field, custom fields (type 10) ask their save/restore ops (slot 2), everything else is tested for all-zero bytes (sub_101a0570)
		// the jump stub of sub_1019fe10, used by its recursive call
	int sub_10129800(const void *pData, int nBytes);	// whether the bytes are all zero (stub 0x100041d8)
	int sub_10129560(const void *pBaseData, typedescription_t *pFields, int nFields);	// the number of fields that have to be saved (stub 0x100143da)
	bool sub_10129350(const unsigned short *pToken, void *pData, void *pRootMap, typedescription_t *pField);	// \"CSave::WriteBasicField\" (stub 0x10015401): the basic types 1..10, called by sub_101a01c0
	bool sub_10129540(const char *pszName, void *pData, void *pRootMap, typedescription_t *pField);	// writes one field (stub 0x1000b0fa); false when it failed
};
