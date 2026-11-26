// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1010d4c0 size=0x4d
#include "engineclient.h"
#include "CLinearRampProxy.h"
#include "CClampProxy.h"
#include "CFunctionProxy.h"



struct LinRampView {
    void *vt;
    int m_unk04;
    int m_unk08;
    CClampProxy::CInput m_flRate;
    CClampProxy::CInput m_flInitialValue;
};

// TARGET: CLinearRampProxy::vfunc1
void CLinearRampProxy::vfunc1(int)
{
    float flValue = ((LinRampView *)this)->m_flRate.sub_100e3270() * engine->Time(0)
        + ((LinRampView *)this)->m_flInitialValue.sub_100e3270();
    ((CFunctionProxy *)this)->sub_100e33c0(flValue);
}
// END FUNCTION

// FUNCTION: 0x1010d570 size=0x1e
#include "CLinearRampProxy.h"

// VC6 writes CLinearRampProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CLinearRampProxy *pcd_emit_1010d570() { return new CLinearRampProxy; }

// TARGET: ??_GCLinearRampProxy@@UAEPAXI@Z
// END FUNCTION
