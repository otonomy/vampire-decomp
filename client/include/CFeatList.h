// CFeatList: the feats data loader (global 0x105e8120, loaded from vdata\system\feats.txt by 0x1014b870).
// A hand-rolled pointer array of CUnknown1014ada0 records: +0x14 allocated, +0x18 used, +0x1c the array.
#pragma once

class CFeatList
{
public:
	int m_unk00;
	int m_nGrowSize;	// 0x04
	int m_nNextId;	// 0x08: handed to each record's constructor
	const char *m_pszInternalName;	// 0x0c
	const char *m_pszName;	// 0x10
	int m_nAllocated;	// 0x14
	int m_nCount;	// 0x18
	void **m_ppData;	// 0x1c

	void sub_1014b870();	// reload: delete every record, then read vdata\system\feats.txt
};
