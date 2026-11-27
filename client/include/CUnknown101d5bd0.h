// CUnknown101d5bd0: vector of pointers to named entries (count at +4, data at +8); real name not yet known.
#pragma once

struct CUnknown101d5bd0Entry
{
	int m_unk0;
	int m_unk4;
	const char *m_p;	// 0x0008

	void sub_10149400();	// the entry's destructor body (called through the stub at 0x10009da4)
};

class CUnknown101d5bd0
{
public:
	int m_unk0;
	int m_count;	// 0x0004
	CUnknown101d5bd0Entry **m_pData;	// 0x0008
	char m_pad000c[0x18 - 0xc];
	char m_bFlag18;	// 0x0018

	int sub_10157b30(const char *name);
	int sub_10157b80(const char *name);
	int sub_1013fdf0(const char *name);
	int sub_10149dc0(const char *name);
	int sub_1013fef0(const char *name, int start);
	int sub_10149ec0(const char *name, int start);
		// same as sub_101d5d20 (another instance)
	char sub_10140c10(const char *pszFile);
	struct CLoaderView *sub_10140910();
	void sub_10140a70();	// purges the list, then loads the "LevelingTemplate" data files (vdata/system) one by one
	void sub_101499f0();
		// provisional, like sub_101d6de0 (transplant)
	void sub_10149980();	// deletes every entry and the pointer array, then clears the count and the first field and sets the flag byte at +0x18
	void sub_10157a20();	// loads the "TraitEffects" data files (vdata/system): counts the TraitEffects_*.txt files with the file system, then loads TraitEffects%03d.txt one by one through sub_101f7e90
	bool sub_101577a0(const char *pszFile);	// loads one trait effect file (called through the stub at 0x100024d7)
};
