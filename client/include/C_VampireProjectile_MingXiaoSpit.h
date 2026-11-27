// C_VampireProjectile_MingXiaoSpit: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
#pragma once
#include "C_VampireProjectile.h"

class C_VampireProjectile_MingXiaoSpit : public C_VampireProjectile
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with C_VampireProjectile_MingXiaoSpit's own function
    virtual int vfunc15();
    virtual int vfunc16();
    char m_pad0014[0x800 - 0x7e8];
};
