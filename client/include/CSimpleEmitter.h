// CSimpleEmitter: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor; nothing else yet
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CParticleEffect.h"
#include "CSmokeEmitterAux.h"

struct SimpleParticleAux_t
{
	char m_unk00[0x24];
	float m_fl24;
	char m_unk28[0x38 - 0x28];
	float m_fl38;
};

struct SimpleParticleC_t
{
	int m_unk00; int m_unk04; int m_unk08; int m_unk0c; int m_unk10; int m_unk14; int m_unk18; int m_unk1c; int m_unk20; int m_unk24;
	float m_flDieTime;	// 0x28
	float m_flLifetime;	// 0x2c
	unsigned char m_uchColor[3];
};

class Vector;
class CSimpleEmitter : public CParticleEffect
{
public:
	CSimpleEmitter(const char *name);
	virtual ~CSimpleEmitter();
	float vfunc8(struct SimpleParticle8 *p, int unused);
	float vfunc9(struct XSP *p, int unused);
	virtual float vfunc10(SimpleParticleAux_t *p, float dt);
	Vector vfunc12(const SimpleParticleC_t *p, float unused);
};
