// C_PointCamera: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
#pragma once
#include "C_BaseEntity.h"

class C_PointCamera : public C_BaseEntity
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	C_PointCamera();
    // the base slots the game's vtable fills with C_PointCamera's own function
    virtual int vfunc15();
    virtual int vfunc16();
    char m_pad0014[0x420 - 0x14];
    bool sub_10006120();	// IsActive
    float sub_10006100();	// GetFOV
};
