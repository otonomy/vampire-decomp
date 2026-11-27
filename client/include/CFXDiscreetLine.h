// CFXDiscreetLine: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CClientSideEffect.h"

#include "Vector.h"
struct IMatInst_10044eb0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(int a); };

class CFXDiscreetLine : public CClientSideEffect
{
public:
	CFXDiscreetLine(const char *name, const Vector &start, const Vector &direction, float velocity, float length, float clipLength, float scale, float life, const char *shader);
	virtual ~CFXDiscreetLine();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CFXDiscreetLine's own function
	virtual void vfunc1(double frametime);
	virtual bool vfunc3();
	virtual void vfunc4();
	// the slots CFXDiscreetLine adds to its base's vtable: 5-5, vfuncK at slot K
	virtual void vfunc5(double);
	char m_pad0004[0xc - 0x4];
	IMatInst_10044eb0 *m_pMaterial;
	float m_flUnk10;
	Vector m_vStart;
	Vector m_vDir;
	float m_flVelocity;
	float m_flUnk30;
	float m_flClip;
	float m_flScale;
	float m_flLength;
};
