// VKeyValues (RTTI .?AVVKeyValues@@): the key/value file object, a class with two virtual bases (IKeyCacheable at +0x28,
// IKeyValues at +0x30). Only the raw view the cache loader needs: the first dword is the vbtable, whose entry [1] is the
// offset of the IKeyCacheable part and entry [2] the offset of the IKeyValues part.
#pragma once

#include "IKeyValues.h"	// the virtual base (IKeyValues : virtual IKeyCacheable)

struct VKeyValuesCacheable	// the IKeyCacheable part: slot 2 is the scalar deleting destructor
{
	virtual void a0();
	virtual void a1();
	virtual void vfunc2(int bDelete);
};

struct VKeyValuesInterface	// the IKeyValues part: slot 0 is the key's name
{
	virtual const char *vfunc0();
	virtual void vfunc1();
	virtual VKeyValuesInterface *vfunc2(const char *pszName);	// slot 2: the sub key of that name (FindKey), 0 when none
	virtual VKeyValuesInterface *vfunc3();	// slot 3: the next key of the same level
	virtual VKeyValuesInterface *vfunc4();	// slot 4: the first sub key
	virtual VKeyValuesInterface *vfunc5();	// slot 5: the next sub key of the same parent
	virtual void vfunc6(); virtual void vfunc7(); virtual void vfunc8(); virtual void vfunc9();
	virtual int vfunc10(const char *pszKey, int nDefault);	// slot 10: GetInt
	virtual float vfunc11(const char *pszKey, float flDefault);
	virtual char vfunc12(const char *pszKey, int nDefault);
	virtual const char *vfunc13(const char *pszKey, const char *pszDefault);	// slot 13: GetString

	char sub_10154370(const char *pszName, int nMax, const char *pszFormat, int **ppValues, int *pnCount);	// stdcall, ret 0x14, this = the IKeyValues part (VKeyValues + 0x30): FindKey(pszName) dynamic_cast to VKeyValues; counts the keys sprintf(pszFormat, i) (\"%s%d\"-style, i = 0..nMax-1) that have a non-empty string, stores the count in *pnCount, allocates int[count] into *ppValues and fills it with GetInt(key, 0); false (and *pnCount = 0) when nothing is found

	char sub_10154230(const char *pszName, int nMax, const char *pszFormat, const char **ppszFirstName, const char ***pppszValues, int *pnCount);	// ret 0x18, this = the IKeyValues part (thunk 0x101f31e0 subtracts the vtordisp): the GetString twin of sub_101f2b00: FindKey(pszName) dynamic_cast to VKeyValues; *ppszFirstName = its GetString("Name", ""), counts the keys sprintf(pszFormat, i) with a non-empty string (i < nMax), *pnCount = the count, *pppszValues = malloc(count * 4) (sub_101f3000) filled with the strings; false (and *pnCount = 0) when nothing is found
	int sub_101541d0(const char *pszName, const char **ppszChoices, int nChoices, int nDefault);	// the index of the choice (case-insensitive) equal to the named sub key's string value, nDefault when none
	float sub_10154150(const char *pszName, float flDefault);	// the float getter: atof of the string, the int as a float, the float, else 0
	void *sub_10154120(const char *pszName, void *pDefault);	// "GetPtr" of the IKeyValues part (this - 0x30 is the VKeyValues; caller thunk 0x101f3200): the named sub key's value (+0x8) when its type (+0x10) is 4, else 0; pDefault when there is no such key
	int sub_101540a0(const char *pszName, int nDefault);	// "GetInt" of the IKeyValues part (this - 0x30 is the VKeyValues): the named sub key's value as an int (atoi of the string, ftol of the float), nDefault when there is none
};

// The real class: the vbptr is at 0x00 (no vftable of its own), a vtordisp before each virtual base (VC6 adds them
// because the class has a user-declared constructor and overrides virtuals of its bases).
class VKeyValues : public virtual IKeyValues
{
public:
	VKeyValues(const char *pszName);
	virtual ~VKeyValues();	// 0x101f20d0: sub_101f2c60()
	virtual void vfunc0();	// IKeyCacheable slot 0
	virtual void vfunc1();	// IKeyCacheable slot 1
	virtual void kv0();	// IKeyValues slot 1
	// IKeyValues' other slots: the game's vtordisp thunks (0x101f3100 .. 0x101f3230) jump to this class's functions,
	// matched under view names; declared only, the standalone link takes the thunks' targets
	virtual void kv1(); virtual IKeyValues *kv2(const char *pszName); virtual IKeyValues *kv3();
	virtual void kv4(); virtual void kv5(); virtual void kv6(); virtual void kv7(); virtual void kv8();
	virtual void kv9(); virtual void kv10(); virtual void kv11(); virtual void kv12();
	virtual const char *kv13(const char *pszName, const char *pszDefault);
	virtual void kv14(); virtual void kv15(); virtual void kv16(); virtual void kv17(); virtual void kv18();
	virtual void kv19(); virtual void kv20();
	VKeyValues *sub_101544e0(const char *pszName);
	void sub_10154480();	// clears the sub keys, the string and the name

	int m_n04;	// 0x04
	int m_nValue08;	// 0x08: the int value (a float for type 3)
	const char *m_pszValue0c;	// 0x0c: the string value (type 1)
	int m_nType10;	// 0x10: 1 string, 3 float, else int
	char *m_pszName14;	// 0x14: malloc'ed copy of the key's name (sub_101f2f70)
	VKeyValues *m_pNext18;	// 0x18: the next key of the same level
	VKeyValues *m_pChild1c;	// 0x1c: the first sub key
	VKeyValues *m_pParent20;	// 0x20: the key searched next when no sub key has the name

	VKeyValues *sub_10154540(const char *pszName);	// finds the sub key of that name (case-insensitive, by the IKeyValues name), then asks +0x20; 0 when none (stub 0x100122c4)
		// the stub of sub_101f2d70 (the recursion goes through it)
	int *VbTable() const { return *(int **)this; }	// the vbptr: [1] = the IKeyCacheable part, [2] = the IKeyValues part
	VKeyValuesInterface *NameOf() { return (VKeyValuesInterface *)((char *)this + VbTable()[2]); }

	void sub_10153ba0(const char *pszName);	// the constructor body (stub 0x10013a8e): the name copy at +0x14, the fields +0xc / +0x10 / +0x18 / +0x1c / +0x20 cleared, the global byte 0x1073aa40 cleared
		// the constructor (stub 0x100056a0)
		// opens and parses the file (stub 0x10001cdf)

	VKeyValuesCacheable *Cacheable() { return (VKeyValuesCacheable *)((char *)this + VbTable()[1]); }
	void *KeyValues() { return (char *)this + VbTable()[2]; }
};

struct VKeyValuesPool	// the allocator object at 0x1073d280
{
		// stub 0x1000bbd6
};
