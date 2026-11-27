// CKeyValuesX: a node of the key/value trees the game loads from its data files (the same objects as CUnknown10248a50);
// only what decompiled code needs.
#pragma once

class CUtlBuffer;

// vtable view of the file system object SaveToFile gets: slot 0 Open, 1 Close, 3 Write.
class IKeyValuesFileView
{
public:
	virtual int Open(const char *pFileName, const char *pOptions, const char *pPathID);
	virtual void Close(int hFile);
	virtual int Read(void *pOutput, int size, int hFile);
	virtual int Write(const void *pInput, int size, int hFile);
};

class CKeyValuesX
{
public:
	int m_iKeyName;	// 0x00: symbol of the key name
	const char *m_sValue;	// 0x04: the string value, null for a node with sub keys
	union {
		int m_nValue;	// 0x08: the int value
		float m_flValue;	// 0x08: the float value (type 2)
	};
	int m_iDataType;	// 0x0c: 0 string, 2 float, else int
	CKeyValuesX *m_pPeer;	// 0x10: the next key of the same level
	CKeyValuesX *m_pSub;	// 0x14: the first sub key
	CKeyValuesX *m_pBase18;	// 0x18: the key searched next when no sub key has the name
	int sub_10127c80();
	int sub_101284c0(const char *pszKey, int nDefault);	// "GetInt": the sub key's value as an int (atoi of the string, ftol of the float), nDefault when there is no such key
	CKeyValuesX *sub_101282e0(const char *pszName, bool bCreate);	// the stub of sub_10248900 (the recursion goes through it)
	CKeyValuesX *sub_10128270(const char *pszName);	// creates a sub key of that name at the end of the list (stub 0x10004eee)

	const char *sub_10128590(const char *pszKey, const char *pszDefault);	// "GetString" (called through the stub 0x1000ed95)
	CKeyValuesX *sub_10128350(const char *pszName, int bCreate);	// stub 0x1001569a: finds the sub key of that name
	CKeyValuesX *sub_101283a0();	// stub 0x10004c8c: the first sub key
	CKeyValuesX *sub_101283b0();	// stub 0x1000fa65: the next key of the same level
	const char *sub_10127c70();	// "GetName" (stub 0x1000fec0): the key's name
	bool sub_10127c90(const char *pszFile, void *pFileSystem, const char *pszPathID, bool bRefresh);	// "LoadFromFile" (stub 0x100108b6, same as CUnknown10248a50::sub_102480f0); the object is made by `new CUnknown10248a50(name)` (ctor stub 0x1000e363)
		// the destructor body (stub 0x100046f1), called before `delete`
	void sub_10128180(CUtlBuffer *pBuf, int nIndent);	// "RecursiveSaveToFile": writes this key and its sub keys as text, one level deeper per sub key
		// the stub of sub_10248730 (the recursion goes through it)
	CKeyValuesX *sub_10128430(const char *pszName);	// "FindKey" without create (stub 0x1000c9fa): the sub key of that name, 0 when there is none
		// "GetNextKey" (stub 0x1000894f): the next key of the same level
	float sub_10128540(const char *pszKey, float flDefault);	// "GetFloat" (stub 0x10009a9d)
	int sub_10128510(const char *pszKey, int nDefault);	// typed int lookup (stub 0x10014b...): the sub key of that name when it has the value type 3 its value at +8, 0 for another type, nDefault when there is no such key
		// the FindKey worker (stub 0x1000b58c): the sub key of that name, created through sub_10248870 when bCreate is set, else 0
		// a jump to sub_10248900 with the same two arguments (stub-like thunk)
	void sub_101288c0(const char *pszName, const char *pszValue);	// "SetString": finds or creates the sub key and stores a copy of the string, type 0
	void sub_10128100(const char *pszFile, IKeyValuesFileView *pFileSystem, const char *pszPathID);	// "SaveToFile": writes the tree as text into the file
};
