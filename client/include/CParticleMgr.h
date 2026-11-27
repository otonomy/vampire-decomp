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
};
