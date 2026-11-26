// CUnknown101dff00: a hit group record of the discipline/animation tables (real name not yet known): a name, five
// 0xac byte action records and a duration range, plus an optional trait effect id; sub_101dff00 prints it.
#pragma once

class Range;

#include "string_t.h"
#include "CUnknown101ddc30.h"
#include "CUnknown101dce30.h"

class CUnknown101df000	// one 0xac byte action record
{
public:
	bool m_bInUse;	// 0x00
	int m_n04;	// 0x04: Dmg_Health range (min, max)
	int m_n08;
	int m_n0c;	// 0x0c: Dmg_Health_Src range
	int m_n10;
	int m_n14;	// 0x14: Blood_Suck range
	int m_n18;
	bool m_bClearCopyProp;	// 0x1c
	bool m_bGibOnDeath;	// 0x1d
	bool m_bAddToComfort;	// 0x1e
	int m_n20;	// 0x20: Heal_Blood range
	int m_n24;
	int m_n28;	// 0x28: Health_Buffer range
	int m_n2c;
	int m_nHealthBufferBlockPercent;	// 0x30
	string_t m_iszSchedule;	// 0x34: AI_Schedule
	int m_nPlayerAnim;	// 0x38: Player_Anim activity
	int m_nGestureAnim;	// 0x3c
	float m_flGestureDuration;	// 0x40
	string_t m_iszExpression;	// 0x44
	int m_nFlinch;	// 0x48
	int m_nKnockback;	// 0x4c
	CUnknown101ddc30 m_casting;	// 0x50: Trigger_Casting
	CUnknown101dce30 m_effectInstant;	// 0x5c: Effect_Tgt_Instant
	CUnknown101dce30 m_effectHit;	// 0x78: Effect_Tgt_Hit
	CUnknown101dc5a0 m_sounds;	// 0x94
	int m_na4;
	int m_na8;

	bool sub_10148350(CUnknown101dc5a0Keys *pKV, const char *pszName);	// loads the record ("HitInfo") from the sub key pszName of pKV (the key itself when null or empty); false without a key
	void sub_101485b0(const char *pszLabel);	// stub 0x100102ad: prints the record under that label when it is in use
		// stub 0x1000852b: loads the record from the sub key of that name of pKV (a null name: the key itself)
};

class CTraitEffectTable	// the table behind the global at 0x1074df78
{
public:
	struct Name	// the name holder at +8 of an entry (read through its address)
	{
		const char *m_psz;
		const char *Get() { return m_psz; }
	};
	struct Entry
	{
		char m_pad[8];
		Name m_Name;	// 0x08
	};
	Entry *sub_10157c20(int id);	// stub 0x1000c5d1: the entry of a trait effect id
	int sub_10157b80(const char *pszEffect);	// stub 0x1000ee67: the id of the named trait effect
};

class CUnknown101dff00;

struct CUnknown101dff00List	// the list of hit groups: count at +4, pointer array at +8
{
	int m_n00;
	int m_nCount;	// 0x4
	class CUnknown101dff00 **m_ppGroups;	// 0x8

	void sub_10149310();	// Debug_Display: prints "[[Hit_Group_List]]:" and then every hit group
	CUnknown101dff00 *sub_101492b0(int index);	// the hit group at index, or a lazily created default group when out of range
};

class CUnknown101dff00
{
public:
	CUnknown101dff00(int id);
	~CUnknown101dff00();
	char m_pad0000[4];
	const char *m_pszName;	// 0x04
	char m_pad0008[0x364 - 0x08];	// five 0xac byte CUnknown101df000 records at +0x08, +0xb4, +0x160, +0x20c, +0x2b8
	char m_RangeStorage[8];	// 0x364: a Range (min, max)
	int m_nTraitEffect;	// 0x36c, -1 when none
	char m_bDoPossession;	// 0x370
	char m_bDoFrenzy;	// 0x371

	void sub_10148ed0();	// debug print: "Hit Group: <name>", the trait effect (when set), the duration range and the five action records (Begin, End, Callback, Interrupt, InterruptSchedule)
	bool sub_10148da0(int a, void *pKV, const char *pszName);	// loads the hit group from its key (ret 0xc): the name, "InheritFrom" (another hit group, sub_101df340), the five action records, "Duration", the "TraitEffect" sub key's "Effect" and the "DoPossession" / "DoFrenzy" flags; false without a key or when the inherited group is unknown
	char sub_10148840(int a, const char *pszParent);	// stub 0x10002699: copies the hit group named pszParent
};
