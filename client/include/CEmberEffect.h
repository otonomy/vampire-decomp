// CEmberEffect: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases; nothing else yet
#pragma once
#include "CSimpleEmitter.h"

class CEmberEffect : public CSimpleEmitter
{
	char m_pad0004[0x78 - 0x4];
	void sub_10118870(struct EmberParticle_10118870 *pParticle, float timeDelta);
public:
	Vector vfunc12(const SimpleParticleC_t *p, float unused);	// UpdateColor: the color faded by lifetime / dietime
};
