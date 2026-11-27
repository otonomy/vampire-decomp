// CExponentialProxy: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
#pragma once
#include "CClampProxy.h"

class CExponentialProxy : public CFunctionProxy
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with CExponentialProxy's own function
    virtual bool vfunc0(void*, void*);
    virtual void vfunc1(int);
    CClampProxy::CInput m_flScale;
    CClampProxy::CInput m_flOffset;
    CClampProxy::CInput m_flMax;
    CClampProxy::CInput m_flMin;
};
