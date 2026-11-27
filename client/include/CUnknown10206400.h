// CUnknown10206400: one vendor record of the vendor list (vdata\system\vendors.txt, VendorList7::sub_10161fd0
// news 0x24 bytes and builds each with the next id); no vtable, so no RTTI name. Placeholder name from vtmb.
#pragma once

class CUnknown10206400
{
public:
	CUnknown10206400(int nId);	// 0x10161db0
	~CUnknown10206400();	// 0x10161dd0: frees the item pointers
	int m_n0;	// 1
	int m_n4;
	int m_n8;
	int m_nC;
	int m_n10;	// item array: allocated
	int m_n14;	// item count
	void **m_ppItems18;
	int m_nId;	// 0x1c
	const char *m_pszName;	// 0x20
};

// the vendor list object: its records' count at +0x14 and array at +0x18 (0x105f9984 / 0x105f9988)
struct CVendorList105f9970
{
	int m_n0;
	int m_nNextId;
	int m_n8;
	int m_nC;
	int m_n10;
	int m_nCount;
	CUnknown10206400 **m_ppVendors;
};
extern CVendorList105f9970 g_105f9970;
