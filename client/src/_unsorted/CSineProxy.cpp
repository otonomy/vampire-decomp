// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1010d010 size=0x91
#include "CSineProxy.h"
#include "CClampProxy.h"
bool CSineProxy::vfunc0(void *pMaterial, void *pKeyValues)
{
	if (!CResultProxy::vfunc0(pMaterial, pKeyValues))
		return false;
	if (!m_SinePeriod.sub_100e3140(pMaterial, pKeyValues, "sinePeriod", 1.0f))
		return false;
	if (!m_SineMax.sub_100e3140(pMaterial, pKeyValues, "sineMax", 1.0f))
		return false;
	if (!m_SineMin.sub_100e3140(pMaterial, pKeyValues, "sineMin", 0.0f))
		return false;
	if (!m_SineTimeOffset.sub_100e3140(pMaterial, pKeyValues, "timeOffset", 0.0f))
		return false;
	return true;
}
// END FUNCTION

// FUNCTION: 0x1010d0b0 size=0x9c
#include "engineclient.h"
#include "CSineProxy.h"
#include "CClampProxy.h"
#include "CFunctionProxy.h"

extern "C" double sin(double);
#pragma intrinsic(sin)



struct SineView {
    void *vt;
    int m_unk04;
    int m_unk08;
    CClampProxy::CInput m_SinePeriod;     // 0xc
    CClampProxy::CInput m_SineMax;        // 0x18
    CClampProxy::CInput m_SineMin;        // 0x24
    CClampProxy::CInput m_SineTimeOffset; // 0x30
};

// TARGET: CSineProxy::vfunc1
void CSineProxy::vfunc1(int)
{
    SineView *p = (SineView *)this;
    float flTimeOffset = p->m_SineTimeOffset.sub_100e3270();
    float flMax = p->m_SineMax.sub_100e3270();
    float flMin = p->m_SineMin.sub_100e3270();
    float flPeriod = p->m_SinePeriod.sub_100e3270();
    if (flPeriod == 0.0f)
        flPeriod = 1.0f;
    double flSine = sin((engine->Time(0) - flTimeOffset) * 6.283185307179586 / flPeriod);
    flSine *= 0.5;
    flSine += 0.5;
    float flResult = (flMax - flMin) * flSine + flMin;
    ((CFunctionProxy *)this)->sub_100e33c0(flResult);
}
// END FUNCTION

// FUNCTION: 0x1010d1b0 size=0x1e
#include "CSineProxy.h"

// VC6 writes CSineProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CSineProxy *pcd_emit_1010d1b0() { return new CSineProxy; }

// TARGET: ??_GCSineProxy@@UAEPAXI@Z
// END FUNCTION
