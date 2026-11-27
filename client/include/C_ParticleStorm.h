// C_ParticleStorm: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseParticleEntity.h"
#include "IPrototypeAppEffect.h"

class C_ParticleStorm : public C_BaseParticleEntity, public IPrototypeAppEffect
{
public:
	C_ParticleStorm();
	virtual ~C_ParticleStorm();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_ParticleStorm's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual void OnDataChanged(int updateType);
	void sub_10004480(const Vector &origin, char flag);
	char m_pad0018[0x560 - 0x18];
};
