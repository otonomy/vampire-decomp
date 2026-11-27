// C_BasePlayer: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseVCombatCharacter.h"
#include "CBaseHandle.h"
#include "CUserCmd.h"

extern "C" __declspec(dllimport) void Plat_Free(void *);
extern int vt_1022e8dc;	// CPlayerLocalPredictedData::vftable

// the predicted data block at +0x1658 (0x34 bytes): its destructor only stores the vftable back
class CPlayerLocalBlock1658
{
public:
	int m_data[0x34 / 4];
	~CPlayerLocalBlock1658() { *(int **)this = &vt_1022e8dc; }
};

// the container at +0x1a14: memory (pointer, allocation count, grow size), size, element pointer; its destructor purges
class CPlayerUtlVec1a14
{
public:
	int *m_pMemory;
	int m_allocationCount;
	int m_growSize;
	int m_Size;
	int *m_pElements;
	void sub_100aad50();
	~CPlayerUtlVec1a14()
	{
		m_Size = 0;
		sub_100aad50();
		m_pElements = m_pMemory;
		if (m_growSize != -1)
		{
			if (m_pMemory)
			{
				Plat_Free(m_pMemory);
				m_pMemory = 0;
			}
			m_allocationCount = 0;
		}
	}
};

class C_BaseCombatWeapon;
class C_BaseEntity;
class Vector;
class QAngle;
class C_BasePlayer : public C_BaseVCombatCharacter
{
public:
	static C_BasePlayer *GetLocalPlayer();
	bool sub_100a5910();
	float sub_10099ac0(int);
	void sub_100a1ef0(float t, void **ppNext, void **ppPrev);
	float sub_100a7990();
	float sub_100aa6d0();	// GetFOVDistanceAdjustFactor-like
	virtual ~C_BasePlayer();
	virtual void OnDataChanged(int updateType);
	virtual void OnPreDataChanged(int updateType);
	int sub_100a2450();
	int sub_100a93e0();
	int sub_100a96a0(int iStat);
	char *sub_100a9af0(int);
	void sub_100a9c90();
	bool sub_100a54c0(int, int);
	void sub_100aa040();
	int sub_100a6850(int b, int h);
	int sub_100a6780(int b, int h);
	bool sub_100a6b10();
	void sub_1007ede0(C_BaseEntity *pEntity);
	void sub_100a9f40(C_BaseEntity *pEntity);
	void sub_100a9e30(C_BaseEntity *pEntity);
	C_BaseEntity *sub_100a7890();
	void sub_100a5fc0();
	void sub_100a6450();	// sound / stat tick: two convar overrides (else +0x17a0 / +0x179c) for engine sound slots 9 / 8 on a static local player filter, slot 13 with +0x16f0, then eases +0x1648 towards 1 - level(stat list 3) * 0.07
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_BasePlayer's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual int vfunc17();
	virtual void vfunc19();
	virtual void vfunc37();
	virtual int vfunc62();
	virtual bool vfunc73();
	virtual bool vfunc74();
	virtual int vfunc84();
	virtual int vfunc86();
	virtual bool vfunc94();
	virtual int vfunc107(int);
	virtual int vfunc108();
	virtual char * vfunc109();
	virtual void vfunc119(int);
	virtual bool vfunc147(class C_BaseCombatWeapon *pWeapon, int);
	// the slots C_BasePlayer adds to its base's vtable: 149-196, vfuncK at slot K
	virtual void vfunc149(float dt, Vector *pOrigin, QAngle *pAngles);
	virtual Vector vfunc150(const Vector &v);
	virtual void vfunc151(int, int, int, int, int, int, int, int, int, int, int);
	virtual int vfunc152(int, int);
	virtual void vfunc153();
	virtual void vfunc154(int);
	virtual void vfunc155();
	virtual void vfunc156();
	virtual void vfunc157();
	virtual void vfunc158();
	virtual void vfunc159(int slot, int, int);	// ret 0xc: weapon selection by slot (0x100a7c40)
	virtual bool vfunc160(bool);
	void sub_100aa490();
	virtual void vfunc161();
	virtual void vfunc162();
	virtual bool vfunc163();
	virtual C_BaseCombatWeapon *vfunc164(int);	// the weapon of a slot (0x100a7c40 hands it to vfunc168)
	virtual C_BaseCombatWeapon * vfunc165(int, int);
	virtual C_BaseCombatWeapon *vfunc166(int, int, int);
	virtual C_BaseCombatWeapon * vfunc167();
	virtual void vfunc168(int);
	virtual void vfunc169(int);
	virtual void vfunc170();
	virtual int vfunc171();
	virtual void vfunc172(C_BaseCombatWeapon *);
	virtual int vfunc173();
	virtual bool vfunc174();
	virtual int vfunc175(int, int);
	virtual float vfunc176();
	virtual void vfunc177();
	virtual void vfunc178();
	virtual void vfunc179();
	virtual void vfunc180();
	virtual void vfunc181();
	virtual void vfunc182();
	virtual int vfunc183();
	virtual void vfunc184();
	virtual void vfunc185(int);
	virtual void vfunc186();
	virtual void vfunc187(struct CViewSetup *pView);
	virtual void vfunc188(int nRole);
	virtual void vfunc189(int);
	virtual void vfunc190(class C_BaseCombatWeapon *pWeapon);
	virtual void vfunc191();
	virtual C_BaseCombatWeapon *vfunc192();
	virtual C_BaseCombatWeapon *vfunc193();
	virtual C_BaseEntity *vfunc194(const char *pName);
	virtual char * vfunc195();
	virtual int vfunc196(int, int, int);
	char m_pad1438[0x14d0 - 0x1438];
	float m_fl14d0;
	bool m_b14d4;
	char m_c14d5; char m_c14d6; char m_c14d7;
	int m_n14d8;	// 0x14d8: the active discipline ("discipline_%d" icon, 31 = none)
	int m_n14dc;
	int m_n14e0;
	int m_unk14e4;
	CBaseHandle m_h14e8;
	char m_pad14ec[0x162c - 0x14ec];
	int m_unk162c;
	int m_unk1630;
	float m_fl1634;
	char m_pad1638[0x1658 - 0x1638];
	CPlayerLocalBlock1658 m_Local1658;
	char m_pad168c[0x16b0 - 0x168c];
	int m_unk16b0;
	char m_pad16b4[0x19f4 - 0x16b4];
	CBaseHandle m_h19f4;
	char m_pad19f8[0x1a14 - 0x19f8];
	CPlayerUtlVec1a14 m_Vec1a14;
	char m_pad1a28[0x1aac - 0x1a28];
	CUserCmd m_Cmd1aac;
	void sub_100a73a0();
};

// the local player (2004 SDK c_baseplayer.h): read it as C_BasePlayer::GetLocalPlayer()
extern C_BasePlayer *g_pLocalPlayer;

inline C_BasePlayer *C_BasePlayer::GetLocalPlayer()
{
	return g_pLocalPlayer;
}
