// CLoadingDisc: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "ILoadingDisc.h"

class CLoadingDisc : public ILoadingDisc
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots CLoadingDisc adds to its base's vtable: 0-3, vfuncK at slot K
    virtual int vfunc0(int);
    virtual void vfunc1();
    virtual void vfunc2(bool bOn);
    struct LoadingDiscPanel *m_pPanel;
    virtual int vfunc3();
};
