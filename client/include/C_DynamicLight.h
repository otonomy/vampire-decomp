// C_DynamicLight: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
#pragma once
#include "C_BaseEntity.h"

class C_DynamicLight : public C_BaseEntity
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	C_DynamicLight();
    // the base slots the game's vtable fills with C_DynamicLight's own function
    virtual int vfunc15();
    virtual int vfunc16();
    virtual void vfunc77();
	virtual void ClientThink();	// IClientThinkable slot 0 (this = the thinkable at +0x10)
	union {
    char m_pad0014[0x438 - 0x14];
	struct {
		int m_unk14[(0x44 - 0x14) / 4];
		int m_index;	// 0x44 (C_BaseEntity::index)
		int m_unk48;
		int m_unk4c;
		unsigned char m_clrRender[4];	// 0x50 (C_BaseEntity::m_clrRender: r, g, b, a)
		int m_unk54[(0x410 - 0x54) / 4];
		unsigned char m_Flags;	// 0x410
		unsigned char m_LightStyle;	// 0x411
		short m_unk412;
		float m_Radius;		// 0x414
		int m_Exponent;		// 0x418
		float m_InnerAngle;	// 0x41c
		float m_OuterAngle;	// 0x420
		float m_SpotRadius;	// 0x424
		int m_unk428;
		struct dlight_t *m_pDynamicLight;	// 0x42c
		struct dlight_t *m_pSpotlightEnd;	// 0x430
		int m_unk434;
	};
	};
};
