// C_BaseHLPlayer: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
#pragma once
#include "C_BasePlayer.h"

class C_BaseHLPlayer : public C_BasePlayer
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	C_BaseHLPlayer();
    // the base slots the game's vtable fills with C_BaseHLPlayer's own function
    virtual int vfunc15();
    virtual int vfunc16();
    char m_pad1b0c[0x1b18 - 0x1b0c];
};
