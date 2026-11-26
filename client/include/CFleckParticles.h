// CFleckParticles: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases; nothing else yet
#pragma once
#include "CSimpleEmitter.h"

class CFleckParticles : public CSimpleEmitter
{
	char m_pad0004[0xec - 0x4];
	void vfunc13(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
public:
	virtual bool vfunc3(struct FleckParticle *pParticle, struct ParticleDraw *pDraw, float &sortKey);
};
