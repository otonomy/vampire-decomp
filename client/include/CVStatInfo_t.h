// CVStatInfo_t: per-stat record (0x13c bytes); a table of 8-byte {duration, add} entries (one per level, 1-based) hangs at +0x100.
// Only what decompiled code needs.
#pragma once

#include "CVDmg_t.h"

struct CVStatLevelEntry_t
{
	int m_duration;
	int m_durationAdd;
};

class CVStatActionList_t;
class CVStatInfoList_t;
struct CVStatKV	// the key/value node the stat data is loaded from; slot 13 is GetString(key, default)
{
	virtual void a0(); virtual void a1();
	virtual CVStatKV *vfunc2(const char *pszName);	// slot 2: the sub key of that name, 0 when there is none
	virtual CVStatKV *vfunc3();	// slot 3: the next key of the same level, 0 at the end
	virtual void a4();
	virtual void a5(); virtual void *vfunc6(const char *pszKey); virtual void a7(); virtual void a8(); virtual void a9();
	virtual int vfunc10(const char *pszKey, int nDefault); virtual float vfunc11(const char *pszKey, float flDefault); virtual char vfunc12(const char *pszKey, int nDefault);
	virtual const char *vfunc13(const char *pszKey, const char *pszDefault);
};

class CVStatInfo_t
{
public:
	int m_field0000;	// 0x0000
	int m_field0004;	// 0x0004
	int m_field0008;	// 0x0008, -1 = none
	int m_field000c;	// 0x000c: set by PreCache from the list's dword at +0x2c
	int m_field0010;	// 0x0010: set by PreCache to the record's index
	const char *m_pszTitle;	// 0x0014
	const char *m_pszName;	// 0x0018
	const char *m_apszHelpText[12];	// 0x001c
	char m_pad004c[0x60 - 0x4c];
	CVDmgBlock16_t m_max0060;	// 0x0060: the "Max" value record
	char m_pad0070[0x9c - 0x70];
	CVDmgBlock16_t m_default09c;	// 0x009c: the "Default" value record
	char m_pad00ac[0xd8 - 0xac];
	const char *m_apszGfxHud[2];	// 0x00d8
	const char *m_pszInfoModel;	// 0x00e0
	const char *m_apszSound[6];	// 0x00e4
	int m_nForceOrdering;	// 0x00fc
	CVStatLevelEntry_t *m_pLevels;	// 0x0100
	unsigned int m_flags;	// 0x0104
	char m_bField0108;	// 0x0108
	char m_pad0109[0x118 - 0x109];	// 0x4c..0xb0: five 0x14-byte records starting with -1, 0xb0: a CVStatCost_t, 0x10c: a 12 byte list
	int m_field0118;	// 0x0118: set by PreCache like +0x0c
	int m_field011c;	// 0x011c: set by PreCache like +0x10
	int m_field0120;	// 0x0120
	int m_field0124;	// 0x0124
	char m_pad0128[0x130 - 0x128];
	int m_field0130;	// 0x0130
	int m_field0134;	// 0x0134: number of entries of the action pointer array
	void **m_field0138;	// 0x0138: the action pointer array

	int DefaultValue() { return m_default09c.sub_10161510(); }
	bool sub_1005d6e0();
	bool sub_1015be50();
	const char *sub_1005d750();
	CVStatInfo_t();	// 0x101fdaf0 (called through the stub at 0x1000dfb2): constructs the five records, the cost and the list, then scope trace and the plain fields
	~CVStatInfo_t();	// 0x101fdc30 (called through the stub at 0x1000f0a6): scope trace around the free of the level table, frees the action pointer array (each action's part at +0x18 first), clears the fields, then the list at +0x10c (sub_101fd4c0) and the five records (+0x9c .. +0x4c, last first)
	void *sub_1015c440(unsigned int flags);	// vector deleting destructor
	void sub_1015b420(CVStatKV *pKV);	// "CVStatInfo_t::PreLoad"-like (stub 0x100135fc): loads the record from its "Stat" key
	CVStatInfo_t *sub_1015b050();	// "CVStatInfo_t::CVStatInfo_t": constructs the five records, the cost and the list, then scope trace and the plain fields
	int sub_1015bec0(int level);	// "CVStatInfo_t::Get_Duration_Initial": scope trace, duration of the level (clamped to 5), 0 without a table
	int sub_1015bf50(int level);	// "CVStatInfo_t::Get_Duration_Add": same shape, the second dword of the level entry
	char sub_1015b3b0();	// a flag of the stat record (called through the stub at 0x1000308f), picks the one-name form of the detailed dump
	bool sub_1015bdb0();	// "CVStatInfo_t::IsPassive": scope trace, bit 2 of the flags, false when the global at 0x1074e6b4 is set up for it
	bool sub_1015bcc0();
	bool sub_1015bfe0(int arg);
		// "CVStatInfo_t::IsRenewable": same shape, bit 3 of the flags, global at 0x1074e77c
	int sub_1015c0a0(int arg);
	int sub_1015c0e0(int arg);
	int sub_1015c1d0(int arg);
	int sub_1015c120(int arg);
	int sub_1015c280(int arg);	// "CVStatInfo_t::Default": scope trace, then evaluates the fifth value record (+0x9c) for arg
		// stub 0x10003152: evaluates a value record of the stat for arg (the caller picks the stat record by index)
		// evaluates the stat's value record (stub 0x10003a08), used by MinSell
		// "CVStatInfo_t::MinSell": scope trace (empty entity name), the larger of the third value record (+0x74) and sub_101ff010 for arg (each evaluated again for the result)
		// "CVStatInfo_t::MaxBuy": scope trace (empty entity name), the smaller of the value record at +0x88 and sub_101ff060 for arg (each evaluated again for the result)
	const char *sub_1015b270(int arg);	// "CVStatInfo_t::GetValueName": scope trace (empty entity name), with an id at +8 hands (id, arg) to the global table at 0x1074e968, else calls the function pointer at +0 (when set) with arg; returns the name text
	int sub_1015b300(const char *pszValue);	// "CVStatInfo_t::GetNameValue": scope trace (empty entity name), with an id at +8 looks the id and the string up in the global table at 0x1074e968 (sub_10203190) and evaluates the result, else calls the function pointer at +4 (when set) with the string, else atoi(string); returns the value
		// "CVStatInfo_t::MidLoad": scope trace (empty entity name); Msg when there is no data, else loads the value-name hooks: a "NameMapping" id (+8), else the "NameFunc" picks the function pair at +0 / +4 (ClanNameFunc, CharTemplateNameFunc, StartingEquipFunc, ExcludedEquipFunc), else the default function at +0
		// "CVStatInfo_t::PostLoad": scope trace (empty entity name); Msg when there is no data, else loads the value records +0x4c "Min", +0x60 "Max", +0x74 "MinSell" (a copy of Min when unset), +0x88 "MaxBuy" (a copy of Max when unset), +0x9c "Default", the action list (+0x10c), the "IncPredependency" list (+0x120) and the cost (+0xb0), which is copied from pDefaults+0x30 when the cost is missing
		// "CVStatInfo_t::Debug_Display" (stub 0x1001339a), called by the list's Debug_Display with the list's dword at +0x2c
		// "CVStatInfo_t::PassesIncPreDependencyTest"
};
