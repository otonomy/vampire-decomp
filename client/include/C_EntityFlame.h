// C_EntityFlame: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseEntity.h"

#include "CSmartPtr.h"
#include "CParticleEffect.h"
class C_EntityFlame : public C_BaseEntity
{
public:
	C_EntityFlame();
	virtual ~C_EntityFlame();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_EntityFlame's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual void vfunc37();
	char m_pad0014[0x410 - 0x14];
	float m_flSize;
	CSmartPtr<CParticleEffect> m_Effect;
	float m_flA;
	int m_nB;
	char m_pad0420[0x428 - 0x420];
};
