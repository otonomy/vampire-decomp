// C_VampireProjectile: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseAnimating.h"

class C_VampireProjectile : public C_BaseAnimating
{
public:
	C_VampireProjectile();
	virtual ~C_VampireProjectile();
	char m_pad0014[0x790 - 0x14];
	CBaseHandle m_unk790;
	CBaseHandle m_unk794;
	int m_unk798;
	int m_unk79c; int m_unk7a0; int m_unk7a4; int m_unk7a8; int m_unk7ac; int m_unk7b0; int m_unk7b4; int m_unk7b8; int m_unk7bc; int m_unk7c0; int m_unk7c4; int m_unk7c8; int m_unk7cc; int m_unk7d0; int m_unk7d4; int m_unk7d8; int m_unk7dc; int m_unk7e0;
	int m_unk7e4;
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_VampireProjectile's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual void vfunc19();
	virtual void vfunc21();
	virtual int vfunc86();
	virtual void vfunc95();
	virtual void vfunc96(int, int, int, int);
	virtual bool vfunc113(bool isbeingremoved, C_BaseEntity *predicted);
	// the slots C_VampireProjectile adds to its base's vtable: 143-147, vfuncK at slot K
	virtual void vfunc143();
	virtual bool vfunc144();
	virtual float vfunc145();
	virtual void vfunc146();
	virtual void vfunc147(int);
};
