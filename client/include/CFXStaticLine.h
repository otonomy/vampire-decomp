// CFXStaticLine: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CClientSideEffect.h"
#include "Vector.h"

class CFXStaticLine : public CClientSideEffect
{
public:
	CFXStaticLine(int a1, const Vector *start, const Vector *end, float width, float f5, const char *material, float f7);
	virtual ~CFXStaticLine();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CFXStaticLine's own function
	virtual void vfunc1(double frametime);
	virtual bool vfunc3();
	virtual void vfunc4();
	// the slots CFXStaticLine adds to its base's vtable: 5-5, vfuncK at slot K
	virtual void vfunc5(double dt);
	char m_pad0004[0x2c - 0x4];
	float m_flUnk2c;
	int m_unk30;
};
