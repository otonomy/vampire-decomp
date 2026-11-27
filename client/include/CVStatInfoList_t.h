// CVStatInfoList_t: list of stat infos (no vtable known). Only the members decompiled code needs.
#pragma once

#include "CVStatInfo_t.h"
#include "CVStatCost_t.h"
#include "CVDmg_t.h"

class CVStatInfoList_t
{
public:
	int m_pad0000;	// set from the constructor's last argument
	int m_nStats;	// +4
	CVStatInfo_t *m_pStats;	// +8, m_nStats records of 0x13c bytes
	char m_szName[0x18];	// +0xc
	const char *m_pszName24;	// +0x24: the stat list's display text (set by PreCache)
	int m_field28;	// +0x28: set by PreCache from "InternalName"
	int m_field2c;	// +0x2c
	CVStatCost_t m_cost;	// +0x30

#ifdef PCD_INITIALIZERS	// only the initializer units: elsewhere a constructor or destructor changes the class
	CVStatInfoList_t(const char *name, int a, int b);	// function 0x101ff300
	~CVStatInfoList_t();	// function 0x101ff3e0
#endif
	CVStatInfoList_t *sub_1015c2f0(const char *name, int a, int b);	// "CVStatInfoList_t::CVStatInfoList_t": scope trace, nulls the cost, stores b at +0, zeroes the list, a at +0x2c and copies name to +0xc
	void sub_1015c3a0();	// "CVStatInfoList_t::~CVStatInfoList_t"-like: scope trace, delete[]s the records and zeroes the count
		// "CVStatInfoList_t::PreCache": scope trace, frees the records, opens "vdata\\system\\stats.txt", finds the block named like the list (+0xc), reads its display text (+0x24) and "InternalName" (+0x28), counts and allocates the records of its "Stat" keys and pre-loads each; DevMsg when the count differs from the one the list was made with (+0)
	void sub_1015c4b0();	// "CVStatInfoList_t::PreCache"
	int sub_1015cde0(const char *name, int index);
	int sub_1015c8f0(const char *name);	// "CVStatInfoList_t::Lookup(char*)": scope trace, index of the stat whose name equals the argument (case-insensitive, null name counts as ""), -1 when none
	int sub_1015c9b0(const char *name);
	CVDmgBlock16_t *sub_1015cf10(const char *name);
		// "CVStatInfoList_t::Lookup( const char *name )": same lookup (name string at +0x18 of each record)
	int sub_1015ca70(const char *name);	// "CVStatInfoList_t::LookupPartial": scope trace, index of the first stat whose lowercased name starts with the lowercased argument, -1 when none
	int sub_1015cb90(const char *name);
		// "CVStatInfoList_t::LookupPartial" (second variant): scope trace, same prefix lookup with 128 byte lower-cased copies
		// "CVStatInfoList_t::LookupNextPart": scope trace, like LookupPartial but starting after startIdx
		// "CVStatInfoList_t::LookupNextPart" (another instance)
	CVStatInfo_t *sub_1015cfe0(int idx);	// element accessor: the record at idx, or a shared default record when idx is out of range
		// "CVStatInfoList_t::LookupDependency": scope trace, a function-local static block set to (the table entry for +0x2c, the index of the stat named name) and returned
		// "CVStatInfoList_t::PostCache": scope trace, opens "vdata\\system\\stats.txt", finds the block named like the list (+0xc) and loads every stat record from its "Stat" keys in two passes (MidLoad with a block made of the table's stat id and the index, then the list's cost, then PostLoad with the list); Msg when the file or the block is missing
		// "CVStatInfoList_t::Debug_Display": scope trace; prints the name (the text at +0x24), the "CostStrings" record's texts of the list's cost (first, then second sub cost) unless it is null, then Debug_Display of every record
};
