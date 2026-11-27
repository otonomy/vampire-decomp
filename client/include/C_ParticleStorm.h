// C_ParticleStorm: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseParticleEntity.h"
#include "IPrototypeAppEffect.h"
#include "Vector.h"
#include "CParticleSphereRenderer.h"

struct C_BaseEntityPadPS : public C_BaseEntity { char m_padEnt[0x410 - 0x14]; };
class IParticleEffectP { public: virtual void pe0(); virtual void pe1(); virtual void pe2(); virtual void pe3(); virtual void pe4(); virtual void pe5(); virtual void pe6(); virtual void pe7(); };
struct CPSEffectPad : public IParticleEffectP { char m_padBinding[0x468 - 0x414]; };
class C_ParticleStorm : public C_BaseEntityPadPS, public CPSEffectPad, public IPrototypeAppEffect
{
public:
	C_ParticleStorm();
	virtual ~C_ParticleStorm();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_ParticleStorm's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual void OnDataChanged(int updateType);
	void sub_10004480(const Vector &origin, char flag);
	virtual void vfunc1(void *, void *);
	CParticleSphereRenderer m_Renderer;
	int m_unk4cc;
	float m_SpawnRate;
	char m_pad4d4[0x538 - 0x4d4];
	char m_Mat;
	float m_t0;
	float m_t1;
	Vector m_Pos;
	char m_pad550[0x55c - 0x550];
	class CParticleMgr *m_pMgr;
};
