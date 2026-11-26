// C_Func_LOD: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
#pragma once
#include "C_BaseEntity.h"

class C_Func_LOD : public C_BaseEntity
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	C_Func_LOD();
    // the base slots the game's vtable fills with C_Func_LOD's own function
    virtual int vfunc15();
    virtual int vfunc16();
    virtual bool LODTest();	// IClientRenderable slot 14: distance fade with a transition zone
    char m_pad0014[0x410 - 0x14];
    volatile bool m_bLastDrawn;	// 0x410: read back after each store (the game reloads it for the return), so volatile here
    int m_LastRenderState;	// 0x414
    float m_fDisappearDist;	// 0x418
    int m_unk41c;
};
