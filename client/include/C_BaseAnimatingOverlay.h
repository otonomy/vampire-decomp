// C_BaseAnimatingOverlay: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
#pragma once
#include "C_BaseAnimating.h"

class C_BaseAnimatingOverlay : public C_BaseAnimating
{
public:
    C_BaseAnimatingOverlay();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with C_BaseAnimatingOverlay's own function
    virtual int vfunc15();
    virtual int vfunc16();
    virtual int vfunc17();
    virtual int vfunc70();
    virtual void vfunc130(const struct CBitVecWords *boneMask, Vector *pos, Quaternion *q);
};
