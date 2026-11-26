// CDustEffect: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases; nothing else yet
#pragma once
#include "CParticleEffect.h"

class C_Func_Dust;

class CDustEffect : public CParticleEffect
{
public:
	virtual bool vfunc3(struct CFuncDustParticle *pParticle, struct ParticleDraw *pDraw, float &sortKey);	// SimulateAndRender
	C_Func_Dust *m_pDust;	// 0x70
};
