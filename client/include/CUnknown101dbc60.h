// CUnknown101dbc60: a sound-range-like record (name provisional): range, source and affects indices into string tables,
// min / max radius, then an embedded CUnknown101da960 filter list at +0x14.
#pragma once

#include "CUnknown101da960.h"

class IKVNodeView;

class CUnknown101db210;

struct CUnknown101dbc60Tail	// the object at +0x24
{
	int m_n00;
	int m_nCount;	// 0x4: number of affects tables
	CUnknown101db210 **m_ppTables;	// 0x8
	void sub_10146e70();	// Debug_Display: prints "[[Affects_Table_List]]:" and then every table
	void sub_10149310();

		// debug display (stub 0x10004b1f)
	void sub_10146cb0(IKVNodeView *pKV, void *pFilter);	// loads the tail from the node (stub 0x1000394a)
};

struct CUnknown101dbc60Filter	// the filter list at +0x14 (a CUnknown101da960 with its bit set)
{
	char sub_101466c0(IKVNodeView *pKV);	// loads the filter from the node's "Affects Filters" child (stub 0x1000eceb)
};

class CUnknown101dbc60
{
public:
	int m_nRange;	// 0x00
	int m_iSource;	// 0x04
	int m_iAffects;	// 0x08
	int m_nMinRadius;	// 0x0c
	int m_nMaxRadius;	// 0x10
	char m_filter[0x10];	// 0x14: a CUnknown101da960 (empty class)
	char m_tail[4];	// 0x24: a CUnknown101dbc60Tail

	void sub_101470d0();	// Debug_Display: prints the range, source, affects, radii, the filter and the tail with Msg
	void sub_10146ed0();	// the constructor body (stub 0x10005e16)
	char sub_10147010(IKVNodeView *pKV);	// loads the record from the "AoE" child
		// 0x101dbc10 (ret 8, stub 0x100065eb; called by CUnknown101e0f00::sub_101e3730 as m_range): when the filter at +0x14 lets pChar through (CUnknown101da960::sub_101daad0(pTarget, pChar), stub 0x10003986) answers the pick of the tail at +0x24 (CUnknown101db210Sub::sub_101db870(pTarget, pChar), stub 0x1000483b: the tail object is the same 8-byte-header view as CUnknown101db210Sub, include CUnknown101db210.h and cast m_tail), else -1
	CUnknown101da960 *Filter() { return (CUnknown101da960 *)m_filter; }
		// loads the record from the "AoE" child of the node: Range, Source, Affects, MinRadius, MaxRadius, the filter and the tail; false for a null node
};
