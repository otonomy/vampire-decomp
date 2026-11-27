// CParticleEffectBinding: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases; nothing else yet (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "CDefaultClientRenderable.h"

#include "Vector.h"
struct CPEBList
{
	int m_a; int m_b; int m_c;
	short m_s0c; short m_s0e; short m_s10; short m_s12; unsigned short m_s14; short m_s16;
	int m_x18;
	void sub_10117b60();
	CPEBList() { m_a = 0; m_b = 0; m_c = 0; sub_10117b60(); m_x18 = m_a; }
};
class CParticleEffectBinding;
class CParticleMgr;
class VMatrix;
struct CPEBOwner { void sub_101176b0(CParticleEffectBinding *); };
class CParticleEffectBinding : public CDefaultClientRenderable
{
public:
	CParticleEffectBinding();
	~CParticleEffectBinding();
	int sub_10116710();
	void sub_10116df0(CParticleMgr *, void *);
	void *sub_10117260(const char *name, unsigned short *pIndex);
	void sub_10116e10();
	void sub_10116bb0(VMatrix *, VMatrix *);	// RenderStart
	void sub_10116ca0(VMatrix *, VMatrix *);	// RenderEnd
	void sub_10115fb0(bool bBucketSort, Vector *pMins, Vector *pMaxs);
	void *sub_101165c0(unsigned short iMaterial);	// the material of a list entry (its slot 26: NeedsFrameBufferTexture)
	void sub_10116720(bool bBucketSort, bool bNoRender, void *pMaterial, float flFrameTime, Vector *pMins, Vector *pMaxs, bool *pbWireframe, bool bWireframePass);	// DrawMaterialParticles
	void sub_10116010(bool bBucketSort, bool bWireframe, Vector *pMins, Vector *pMaxs);
	virtual int DrawModel(int flags, int a1);	// IClientRenderable slot 9 (0x10116070)
	void SetDrawn(bool bDrawn) { if (bDrawn) m_unk34 |= 0x20; else m_unk34 &= ~0x20; }	// the flags at +0x34 (FLAGS_DRAWN)
	unsigned short m_unk08; unsigned short m_unk0a;
	Vector m_Min; Vector m_Max;
	unsigned short m_unk24; unsigned short m_unk26; unsigned short m_unk28; unsigned short m_unk2a;
	int m_unk2c; CPEBOwner *m_unk30; int m_unk34;
	CPEBList m_List;
};
