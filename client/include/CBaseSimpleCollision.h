// CBaseSimpleCollision: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once

#include "Vector.h"

struct CGameTrace;

struct VPlane
{
    Vector m_Normal;
    vec_t m_Dist;
};

class CBaseSimpleCollision
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots CBaseSimpleCollision adds to its base's vtable: 0-3, vfuncK at slot K
    virtual void vfunc0(const Vector &start, float a, float b);
    virtual void vfunc1(const Vector &start, const Vector &end, CGameTrace *pTrace, bool coarse = true);
    virtual void vfunc2(const Vector &start, const Vector &vel, float a, float b);
    virtual void vfunc3(const VPlane &plane);

    VPlane m_collisionPlanes[6];
    int m_nActivePlanes;
};
