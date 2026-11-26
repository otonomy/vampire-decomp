// FX_Cube: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "CClientSideEffect.h"
#include "Vector.h"

struct FXMatView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void vfunc12(int a);
};

class FX_Cube : public CClientSideEffect
{
public:
	FX_Cube(void *pMat) : CClientSideEffect((int)"FX_Cube")
	{
		m_pMaterial = pMat;
		if (pMat)
			((FXMatView *)pMat)->vfunc12(0);
	}
	virtual void vfunc1(double frametime);	// Draw: the six faces, lit by a fixed light direction; the life (+0x30) counts down
	virtual bool vfunc3();
	void sub_100e3b10(float *v, int i0, int i1, int i2, float a, float b, float c);	// v[i0] = a, v[i1] = b, v[i2] = c
	void sub_100e3b40(int i0, int i1, int i2, float a0, float b0, float a1, float b1, float c, bool bFlip, float flScale);	// DrawFace: one face as a 2-triangle strip; Draw expands the first two inline
	int m_unk4; int m_unk8;
	Vector m_vecMins;	// 0x0c
	Vector m_vecMaxs;	// 0x18
	Vector m_vecColor;	// 0x24
	float m_flUnk30;
	void *m_pMaterial;
};
