// CClientModeDialog: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "ClientModeHLNormal.h"

class CClientModeDialog : public ClientModeHLNormal
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with CClientModeDialog's own function
    virtual int vfunc16(int, int, const char *);
    virtual void vfunc22(int, int);
};
