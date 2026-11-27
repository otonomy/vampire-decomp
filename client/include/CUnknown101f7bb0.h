// CUnknown101f7bb0: loader of the "TraitEffectInfoList" data file (real name not yet known); same shape as
// CUnknown101f10e0 (name table at 0x1074df78).
#pragma once

struct CUnknown101f7bb0_Item
{
	virtual ~CUnknown101f7bb0_Item() {}
};

class CUnknown101f7bb0
{
public:
	int m_n0000;	// 0x00: cleared by the reset
	int m_nItems;	// 0x04: number of items
	CUnknown101f7bb0_Item **m_ppItems;	// 0x08: the items, deleted by the reset
	int m_iInternalName;	// 0x0c: pooled string id of the General key "InternalName"
	int m_iName;	// 0x10: pooled string id of the General key "Name"
	int m_n0014;	// 0x14: cleared by the reset
	void *m_p0018;	// 0x18: buffer freed by the reset
	int m_aiModifierName[11];	// 0x1c: pooled string ids of the "ModifierNames" entries 0..10
	int m_anModifierNameLen[11];	// 0x48: their lengths

		// parses one trait effect category of the data file: InternalName picks the id (registered on a miss), every TraitEffectGroup key is handed to a fresh item; false (with a Msg) for no data or when no item could be made
		// opens the data file and parses every "TraitEffectCategory" key of it with sub_101f7bb0; false (with a Msg) when the file is missing or a category does not parse
	void sub_10157480();	// resets the loader (stub 0x10009624)
	void sub_10157850();
		// loads the General data (vdata\system\traiteffect.txt: InternalName, Name, the 11 ModifierNames), then every vdata\system\TraitEffects*.txt file with sub_101f7db0; Msg for each file that does not open
};
