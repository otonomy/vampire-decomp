// CFireOverlay: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
#pragma once
#include "CGlowOverlay.h"

class CFireOverlay : public CGlowOverlay
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with CFireOverlay's own function
    virtual bool vfunc1();
    void *m_pOwner;	// 0x90
    Vector m_BaseColors[4];	// 0x94
    float m_flScaleLast;	// 0xc4
    int m_nSeed;	// 0xc8
};
