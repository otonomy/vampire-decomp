// IClassMap: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once

class IClassMap
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots IClassMap adds to its base's vtable: 0-3, vfuncK at slot K
    virtual void vfunc0(const char *mapname, const char *classname, int size, void *(*factory)(void));	// Add
    virtual const char *vfunc1(const char *classname);	// Lookup
    virtual void vfunc2();
    virtual int vfunc3(const char *classname);
};
