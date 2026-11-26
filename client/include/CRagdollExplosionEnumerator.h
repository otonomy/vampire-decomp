// CRagdollExplosionEnumerator: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "IPartitionEnumerator.h"
#include "Vector.h"

class CRagdollExplosionEnumerator : public IPartitionEnumerator
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots CRagdollExplosionEnumerator adds to its base's vtable: 0-0, vfuncK at slot K
    virtual int vfunc0(void *pHandleEntity);
	Vector m_vecOrigin;
	float m_flMagnitude;
	float m_flRadius;
	void sub_100367b0(Vector v, float a, float b);
};
