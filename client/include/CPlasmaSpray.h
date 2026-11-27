// CPlasmaSpray: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases; nothing else yet
#pragma once
#include "CSimpleEmitter.h"
#include "CParticleCollision.h"

class CPlasmaSpray : public CSimpleEmitter
{
public:
	char m_pad0070[0x08];
	int m_78;	// the owner's handle (SDK: m_pFirePlasmaSpray->m_pOwner = this)
	CParticleCollision m_collision;
	CPlasmaSpray(const char *name) : CSimpleEmitter(name), m_78(-1) {}
	void vfunc11(void *pVec, int arg1);
};
