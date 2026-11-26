// C_BaseVCombatCharacter: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor; nothing else yet
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseCombatCharacter.h"
#include "CVStatListManager_t.h"

class CUnknown10157d10
{
public:
	void *sub_10157d10();
};

struct CBaseVCombatUnk10e0
{
	CBaseVCombatUnk10e0() { ((CUnknown10157d10 *)this)->sub_10157d10(); }
	char m_data[0x84];
};

struct VStatBindPair_t
{
	int *pBase;
	int *pMod;
};

class C_BaseVCombatCharacter : public C_BaseCombatCharacter
{
public:
	C_BaseVCombatCharacter();
	virtual ~C_BaseVCombatCharacter();
	char m_pad0014[0xfd0 - 0x14];
	int m_unkfd0;
	char m_pad0fd4[0x10b8 - 0xfd4];
	unsigned int m_unk10b8;
	char m_pad10bc[0x10e0 - 0x10bc];
	CBaseVCombatUnk10e0 m_unk10e0;
	CVStatListManager_t m_StatListManager;
	int m_base0[35];
	int m_mod0[35];
	VStatBindPair_t m_pair0;
	int m_base1[13];
	int m_mod1[13];
	VStatBindPair_t m_pair1;
	int m_base2[17];
	int m_mod2[17];
	VStatBindPair_t m_pair2;
	int m_base3[17];
	int m_mod3[17];
	VStatBindPair_t m_pair3;
	int sub_1008ebb0();
	bool sub_1008eb70();	// a flag of the character's clan record (0x105e74fc table, +0x8c)
	int sub_1014db90(class C_BaseVCombatCharacter *pTarget, int a, int b);
};
