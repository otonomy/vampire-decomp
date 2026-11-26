// CUnknown101dc5a0: a list of sound descriptions (CUnknown101dbe30, 0xc bytes each) loaded from a KeyValues-like file;
// real name not yet known. A lazily grown array of item pointers: grow amount at +0, allocation count at +4, count at +8,
// pointer array at +0xc.
#pragma once

#include "CUnknown101dbe30.h"

struct CUnknown101dc5a0Keys	// the KeyValues-like block: slot 2 finds a sub block by name, slot 3 gives the next sibling
{
	virtual void vfunc0();
	virtual void vfunc1();
	virtual CUnknown101dc5a0Keys *vfunc2(const char *pszName);
	virtual CUnknown101dc5a0Keys *vfunc3();
	virtual void vfunc4();
	virtual void vfunc5();
	virtual void vfunc6();
	virtual void vfunc7();
	virtual void vfunc8();
	virtual void vfunc9();
	virtual int vfunc10(const char *pszKey, int nDefault);	// GetInt
	virtual float vfunc11(const char *pszKey, float flDefault);	// GetFloat
	virtual bool vfunc12(const char *pszKey, bool bDefault);	// GetBool
	virtual const char *vfunc13(const char *pszKey, const char *pszDefault);	// GetString
};

class CUnknown101dc5a0
{
public:
	int m_growBy;	// 0x00
	int m_allocationCount;	// 0x04
	int m_count;	// 0x08
	CUnknown101dbe30 **m_pItems;	// 0x0c

	bool sub_101475e0(CUnknown101dc5a0Keys *pKeys);	// parses every "SoundFX" block of pKeys into a new item; false (with a message) when an item cannot be created, true otherwise
};
