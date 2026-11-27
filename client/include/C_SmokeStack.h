// C_SmokeStack: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseParticleEntity.h"
#include "IPrototypeAppEffect.h"

class C_SmokeStack : public C_BaseParticleEntity, public IPrototypeAppEffect
{
public:
	C_SmokeStack();
	virtual ~C_SmokeStack();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_SmokeStack's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual void vfunc1(void *pParticleMgr, void *pArgs);	// IPrototypeAppEffect slot 1: Start
	virtual void OnDataChanged(int updateType);	// IClientNetworkable slot 5: clamps +0x528 to 0..2, Start(&g_ParticleMgr, NULL) when created, lifetime +0x57c = +0x4d4 / +0x4e4
	char m_pad0018[0x590 - 0x18];
};
