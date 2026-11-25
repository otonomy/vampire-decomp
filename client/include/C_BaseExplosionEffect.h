// C_BaseExplosionEffect: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "Vector.h"

class C_BaseExplosionEffect
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots C_BaseExplosionEffect adds to its base's vtable: 0-5, vfuncK at slot K
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    Vector m_vecOrigin;	// 0x04
    Vector m_vecDirection;	// 0x10
    int m_unk1c;
    int m_fFlags;	// 0x20
};
