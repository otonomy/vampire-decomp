// CGlowOverlay: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "Vector.h"

class CGlowSprite
{
public:
	Vector m_vColor;
	float m_flHorzSize;
	float m_flVertSize;
	void *m_Material;
};

class CGlowOverlay
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the slots CGlowOverlay adds to its base's vtable: 0-4, vfuncK at slot K
	CGlowOverlay();
	virtual ~CGlowOverlay();
	virtual bool vfunc1();
	virtual void vfunc2(float flDot, CGlowSprite *pSprite, float *pflHorzSize, float *pflVertSize, Vector *pColor);
	virtual void vfunc3();
	virtual void vfunc4();
	void sub_100efd40();
	void sub_100eee60(const Vector &vToGlow);	// UpdateGlowObstruction
	Vector m_vPos;
	bool m_bDirectional;
	Vector m_vDirection;
	bool m_bInSky;
	CGlowSprite m_Sprites[4];
	int m_nSprites;
	float m_flProxyRadius;
	bool m_bActivated;
	unsigned short m_ListIndex;
};
