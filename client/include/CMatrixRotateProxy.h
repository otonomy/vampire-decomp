// CMatrixRotateProxy: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
#pragma once
#include "CResultProxy.h"
#include "CClampProxy.h"

class CMatrixRotateProxy : public CResultProxy
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with CMatrixRotateProxy's own function
    virtual bool vfunc0(void*, void*);
    virtual void vfunc1(int);
    char m_pad0004[0xc - 0x4];
    CClampProxy::CInput m_Angle;
    void *m_pAxisVar;
};
