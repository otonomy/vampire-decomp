// CTEParticleRenderer: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor; nothing else yet
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CParticleEffect.h"

class CTEParticleRenderer : public CParticleEffect
{
public:
	virtual ~CTEParticleRenderer();
	bool vfunc3(struct StandardParticle_t *pParticle, struct ParticleDraw *pDraw, float &sortKey);
	struct StandardParticle_t *sub_1003e020();	// AddParticle
	int m_unk70;
	float m_flParticleSize;	// 0x74
	unsigned char m_hMaterial;	// 0x78
	char m_pad0079[0xe8 - 0x79];
};
