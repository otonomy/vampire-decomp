// C_Func_Dust: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseEntity.h"
#include "CParticleEffect.h"

class C_Func_Dust : public C_BaseEntity
{
public:
	C_Func_Dust();
	virtual ~C_Func_Dust();
	virtual void PostDataUpdate(int updateType);
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_Func_Dust's own function
	virtual int vfunc15();
	virtual int vfunc16();
	char m_pad0014[0x410 - 0x14];
	unsigned char m_Color[4];	// 0x410: r, g, b, a
	int m_unk414;
	float m_flSizeMin;	// 0x418
	float m_flSizeMax;	// 0x41c
	int m_SpeedMax;	// 0x420
	int m_LifetimeMin;	// 0x424
	int m_LifetimeMax;	// 0x428
	int m_DistMax;	// 0x42c
	const char *m_pszMaterial;
	int m_DustFlags;	// 0x434: 2 scale motes by distance, 4 frozen
	CParticleEffect m_ParticleEffect;
	int m_unk4a8;
	unsigned char m_hMaterial;	// 0x4ac
	unsigned char m_unk4ad;
	unsigned char m_unk4ae;
	unsigned char m_unk4af;
	float m_flFactor;
	int m_unk4b4;
	void sub_100babb0();	// AttemptSpawnNewParticle (Source 2003 c_func_dust.cpp)
};
