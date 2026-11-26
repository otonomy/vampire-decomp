// C_ServerRagdollAttached: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
#pragma once
#include "C_ServerRagdoll.h"

class C_ServerRagdollAttached : public C_ServerRagdoll
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with C_ServerRagdollAttached's own function
    virtual int vfunc15();
    virtual int vfunc16();
    virtual void vfunc123(const Vector *pos, const Quaternion *q, const matrix3x4_t &cameraTransform, const struct StudioBoneMask *pBoneComputed);	// BuildTransformations
    char m_pad0adc[0xb28 - 0xadc];
};
