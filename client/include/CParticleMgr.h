// CParticleMgr: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once

#include "Vector.h"
#include "CUtlLinkedList8.h"

struct CParticleMgrEntry
{
	Vector m_v;
	float m_t;
};

class CParticleEffectBinding;

class CParticleMgr
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the slots CParticleMgr adds to its base's vtable: 0-0, vfuncK at slot K
	virtual ~CParticleMgr();

	void sub_10117a80();
	void sub_10117980(float flTimeDelta);
	CParticleMgr *sub_101172d0();
	int sub_10117920(Vector *p, float t);

	void sub_101177a0();
	void sub_101177f0();	// IncrementFrameCode
	void sub_10117890();	// SimulateUndrawnEffects
	void sub_101176b0(CParticleEffectBinding *p);
	bool sub_101175b0(CParticleEffectBinding *p, void *pSim);

	int m_unk04;
	CParticleMgrEntry m_entries[20];
	int m_nCount;
	CUtlLinkedList8 m_list;
	void *m_pMaterialSystem;
	int m_unk16c; int m_unk170; int m_unk174; int m_unk178; int m_unk17c; int m_unk180; int m_unk184; int m_unk188;
	int m_unk18c; int m_unk190; int m_unk194; int m_unk198; int m_unk19c; int m_unk1a0; int m_unk1a4; int m_unk1a8;
	struct Pool *m_pPool;
	bool sub_10117400(int nItems, void *pMaterialSystem);
	void sub_10117460();
};
