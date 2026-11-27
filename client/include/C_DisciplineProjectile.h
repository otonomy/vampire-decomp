// C_DisciplineProjectile: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_VampireProjectile.h"

class C_DisciplineProjectile : public C_VampireProjectile
{
public:
	C_DisciplineProjectile();
	virtual ~C_DisciplineProjectile();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_DisciplineProjectile's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual void vfunc143();
	char m_pad0014[0x808 - 0x7e8];
};
