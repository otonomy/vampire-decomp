// C_SteamJet: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseParticleEntity.h"
#include "IPrototypeAppEffect.h"
#include "Vector.h"
#include "QAngle.h"

class C_SteamJet : public C_BaseParticleEntity, public IPrototypeAppEffect
{
public:
	C_SteamJet();
	virtual ~C_SteamJet();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_SteamJet's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual void OnDataChanged(int updateType);
	void sub_10031d80();	// UpdateLightingRamp
	char m_pad0018[0x470 - 0x18];
	float m_Speed;		// 0x470
	int m_unk474;
	int m_unk478;
	float m_Rate;		// 0x47c
	float m_JetLength;	// 0x480
	int m_unk484;
	int m_nType;		// 0x488
	bool m_bFaceLeft;	// 0x48c
	Vector m_vLastRampUpdatePos;	// 0x490
	QAngle m_vLastRampUpdateAngles;	// 0x49c
	float m_Lifetime;	// 0x4a8
	Vector m_Ramps[5];	// 0x4ac
	char m_pad04e8[0x4f8 - 0x4e8];
};
