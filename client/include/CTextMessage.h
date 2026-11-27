// CTextMessage: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "ITextMessage.h"
#include "CTextMessagePanel.h"

class CTextMessage : public ITextMessage
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots CTextMessage adds to its base's vtable: 0-7, vfuncK at slot K
    virtual int vfunc0(int);
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3(int, int, int, int, float);
    virtual void vfunc4(int *, int *, int);
    virtual int vfunc5(int, int);
    class CTextMessagePanel *m_pEnt;	// made by vfunc0 (0x1016a6c0 constructs it)
    virtual void vfunc6();
    virtual void vfunc7();
};
