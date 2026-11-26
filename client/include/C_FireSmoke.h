// C_FireSmoke: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseEntity.h"
#include "C_Sprite.h"
#include "CParticleEffect.h"
#include "CSmartPtr.h"

class CFireSmokeOwned { public: virtual ~CFireSmokeOwned() {} };

class C_FireSmoke : public C_BaseEntity
{
public:
	C_FireSmoke();
	virtual ~C_FireSmoke();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_FireSmoke's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual void vfunc37();

	void sub_100b55b0();
	void sub_100b5d00();
	void sub_100b56c0();	// "Start": the child flames (render mode, random yaw, model, frame, scale, brightness) and the fire overlay when flag 8 is set
	char m_pad0014[0x410 - 0x14];
	float m_flStartScale;
	float m_flScale;
	float m_flScaleTime;
	int m_nFlags;
	int m_nFlameModelIndex;
	float m_flScaleRegister;
	float m_flScaleStart;
	float m_flScaleEnd;
	float m_flScaleTimeStart;
	float m_flScaleTimeEnd;
	char m_pad438[0x44c - 0x438];
	bool m_bClipTested;
	char m_pad44d[3];
	CSmartPtr<CParticleEffect> m_pEmberEmitter;
	CSmartPtr<CParticleEffect> m_pSmokeEmitter;
	C_Sprite m_entFlames[8];
	float m_flFlameScales[8];	// 0x27d8
	float m_flChildFlameSpread;
	int m_nUnk27fc;
	class CFireSmokeOwned *m_p2800;
	int m_unk2804;
};
