// C_EnvParticle: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseEntity.h"

class C_EnvParticle : public C_BaseEntity
{
public:
	C_EnvParticle();
	int sub_100aeea0(int, int);
	void sub_100af150();
	bool sub_100af0b0();
	void sub_100b0460();
	void sub_100b02c0();
	void sub_100af810();
	virtual ~C_EnvParticle();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_EnvParticle's own function
	virtual int vfunc15();
	virtual int vfunc16();
	// the slots C_EnvParticle adds to its base's vtable: 120-123, vfuncK at slot K
	virtual void vfunc120();
	virtual void vfunc121();
	virtual void vfunc122(int);
	virtual void vfunc123(int);
	int m_unk0014[(0x4c0 - 0x14) / 4];
};
