// CUnknown1006c810: a record loaded from a key file by sub_1006c810 (an internal name id at +4, a second text id at +8,
// flags at +0xc, a counted array of floats read from the numbered keys "0", "1", ... and a 16 byte dependency record at
// +0x18); real name not yet known (the key names are "InternalName", "TraitDependency", "Clamping").
#pragma once

struct CVTraitKV	// a KeyValues-like object (slot 10 = GetInt, slot 11 = GetFloat, slot 13 = GetString)
{
	virtual void v0(); virtual void v1(); virtual CVTraitKV *FindKey(const char *pszName); virtual CVTraitKV *GetNextKey(); virtual void v4();
	virtual void v5(); virtual int v6(const char *pszName); virtual void v7(); virtual void v8(); virtual void v9();
	virtual int GetInt(const char *pszKey, int nDefault);
	virtual float GetFloat(const char *pszKey, float flDefault);
	virtual void v12();
	virtual const char *GetString(const char *pszKey, const char *pszDefault);
};

struct CVTraitTextId	// a 4 byte text id returned through a hidden pointer (the type has a copy constructor)
{
	int m_id;

	CVTraitTextId() { }
	CVTraitTextId(const CVTraitTextId &other) : m_id(other.m_id) { }
};

struct CVTraitDependency	// the 16 byte dependency record
{
	int m_a, m_b, m_c, m_d;

		// stub 0x10010573: sets the record to its default
	void sub_101608a0(const char *pszDependency);	// stub 0x100045e3: parses the record from its text
};

class CUnknown1006c810
{
public:
	char m_pad0000[4];
	int m_nInternalName;	// 0x04
	int m_nText;	// 0x08
	unsigned int m_flags;	// 0x0c: bit 0 = clamping
	int m_nValues;	// 0x10: the number of numbered keys
	float *m_pValues;	// 0x14
	CVTraitDependency m_Dependency;	// 0x18

	bool sub_1015ffa0(CVTraitKV *pKV, const CVTraitDependency *pDefaultDependency);	// loads the record from its key: InternalName, the text id, TraitDependency (the text, else a copy of pDefaultDependency, else the default), Clamping and the numbered float keys; always true
};
