// CFXQuad: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CClientSideEffect.h"
#include "Vector.h"

class CFXQuad : public CClientSideEffect
{
public:
	CFXQuad *sub_100e5c70(const int *p);
	virtual ~CFXQuad();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CFXQuad's own function
	virtual void vfunc1(double frametime);	// Draw (overrides CClientSideEffect::vfunc1(double))
	virtual bool vfunc3();
	virtual void vfunc4();
	// the slots CFXQuad adds to its base's vtable: 5-5, vfuncK at slot K
	virtual void vfunc5(double frametime);	// Update
	char m_pad0004[0xc - 0x4];
	unsigned int m_uiFlags;	// 0x0c (1 bias scale, 2 bias alpha)
	void *m_pMaterial;	// 0x10
	Vector m_vecOrigin;	// 0x14
	Vector m_vecNormal;	// 0x20
	float m_flStartScale;	// 0x2c
	float m_flEndScale;	// 0x30
	float m_flA;	// 0x34 die time
	float m_flB;	// 0x38 life time
	float m_flStartAlpha;	// 0x3c
	float m_flEndAlpha;	// 0x40
	Vector m_Color;	// 0x44
	float m_flYaw;	// 0x50
	float m_flDeltaYaw;	// 0x54
	float m_flScaleBias;	// 0x58
	float m_flAlphaBias;	// 0x5c
};
