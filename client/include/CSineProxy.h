// CSineProxy: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
#pragma once
#include "CResultProxy.h"
#include "CClampProxy.h"

class CSineProxy : public CResultProxy
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with CSineProxy's own function
    virtual bool vfunc0(void*, void*);
    virtual void vfunc1(int);
    int m_unk4; int m_unk8;
    CClampProxy::CInput m_SinePeriod;
    CClampProxy::CInput m_SineMax;
    CClampProxy::CInput m_SineMin;
    CClampProxy::CInput m_SineTimeOffset;
};
