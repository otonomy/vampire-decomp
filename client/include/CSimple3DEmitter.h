// CSimple3DEmitter: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases; nothing else yet
#pragma once
#include "CSimpleEmitter.h"
#include "CParticleCollision.h"

class CSimple3DEmitter : public CSimpleEmitter
{
public:
	bool vfunc3(void *pParticle, void *pDraw, float &sortKey);	// SimulateAndRender (particle_simple3d.cpp)
	int m_unk70;
	int m_unk74;
	CParticleCollision m_ParticleCollision;	// 0x78
};
