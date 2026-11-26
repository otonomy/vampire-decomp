// CParticleEffect: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor; nothing else yet
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "IParticleEffect.h"

class CParticleEffect : public IParticleEffect
{
public:
	virtual ~CParticleEffect();
	void sub_10117fd0();
	void sub_10118060(int);
	int sub_10117fc0();
	void vfunc5(int);
	void sub_10117fe0();
	void *sub_101180b0(const char *pMaterialName);	// GetPMaterial
	void *sub_101180c0(int size, void *pMaterial, const class Vector &pos);	// AddParticle
	int m_unk04;
	int m_unk08;
	int m_unk0c;
	int m_unk10;
	int m_unk14;
	int m_unk18;
	int m_unk1c;
	int m_unk20;
	int m_unk24;
	int m_unk28;
	int m_unk2c;
	int m_unk30;
	int m_unk34;
	int m_unk38;
	int m_unk3c;
	int m_unk40;
	int m_unk44;
	int m_unk48;
	int m_unk4c;
	int m_unk50;
	int m_unk54;
	int m_unk58;
	int m_unk5c;
	int m_unk60;
	int m_unk64;
	int m_unk68;
	int m_unk6c;
};
