// CVTraitEffectGroup_t: declared by pcdecomp transplant for 0x101f7350 from CDataObjectAccessSystem (0x1003ca90);
// only what matched code needs, as plain members.
#pragma once

#include "CVTraitEffect_t.h"

class CVModInfo_t;
struct CTraitStatBlock;

class CVTraitEffectGroup_t
{
public:
	CVTraitEffectGroup_t(int nUnk);
	~CVTraitEffectGroup_t();	// constructor (0x101f7310): stores nUnk at +4, vptr, +0xc = -1, +0x10 / +0x14 = 0
	int m_n0004;	// 0x04
	const char *m_pszName;	// 0x08
	int m_nId;	// 0x0c: -1 for an empty group
	int m_nEffects;	// 0x10: the number of "TraitEffect" sub keys
	CVTraitEffect_t *m_pEffects;	// 0x14: m_nEffects effects of 0x44 bytes

	CVTraitEffect_t *sub_10157040(int i);	// the i-th effect, or a shared default effect (guarded static) when out of range
	void sub_10156f70(CVStatKV *pKV);	// counts the "TraitEffect" sub keys of pKV, allocates that many effects and loads each from its key
	void sub_10157170(int a, CVModInfo_t *pInfo, int c);	// hands (a, pInfo, c) to every effect (stub 0x10015609)
	void sub_10157130(CVModInfo_t *pInfo, void *pResult);	// hands (pInfo, pResult) to every effect (stub 0x10001159)
	void sub_101570f0(CVModInfo_t *pInfo);	// Effect_Calc_Clan's per-group step
	void sub_101570b0(CTraitStatBlock *pBlock);	// stores the group's id at +0x40 of the stat block, then applies every effect to it (CUnknown101f6c50::sub_101f6c50)
	void sub_10157280(void *pOut);	// writes the group to an output object (sub_10203df0 / stub 0x100045ed): "[<id text>]\t\t\t{<name>}\t", then the lines of its effects (or "( <ERROR> )") and a newline
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the slots CVTraitEffectGroup_t adds to its base's vtable: 0-0, vfuncK at slot K
	virtual CVTraitEffectGroup_t*vfunc0(unsigned int);
};
