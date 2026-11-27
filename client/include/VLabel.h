// VLabel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
#pragma once
#include "vgui2__Label.h"

class VLabel : public vgui2::Label
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with VLabel's own function
    virtual int vfunc99();
    VLabel(vgui2::Panel *parent, const char *name, const char *text) : vgui2::Label(parent, name, text) { *(int *)((char *)this + 0xb8) = 0; }
    char m_pad0004[0xbc - 0x4];
};
