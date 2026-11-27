// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1010d6b0 size=0x94
#include "CGaussianNoiseProxy.h"
#include "CClampProxy.h"
bool CGaussianNoiseProxy::vfunc0(void *pMaterial, void *pKeyValues)
{
	if (!CResultProxy::vfunc0(pMaterial, pKeyValues))
		return false;
	if (!m_Mean.sub_100e3140(pMaterial, pKeyValues, "mean", 0.0f))
		return false;
	if (!m_StdDev.sub_100e3140(pMaterial, pKeyValues, "halfwidth", 1.0f))
		return false;
	if (!m_flMinVal.sub_100e3140(pMaterial, pKeyValues, "minVal", -3.402823466e+38f))
		return false;
	if (!m_flMaxVal.sub_100e3140(pMaterial, pKeyValues, "maxVal", 3.402823466e+38f))
		return false;
	return true;
}
// END FUNCTION

// FUNCTION: 0x1010d750 size=0xbb
#include "CGaussianNoiseProxy.h"
#include "CClampProxy.h"
struct CRnd102b8488 { int m_unk; };
extern CRnd102b8488 *g_102b8488;
extern float (CRnd102b8488::*g_101e31e4)(float, float);
void CGaussianNoiseProxy::vfunc1(int)
{
	char *s = (char *)this;
	float mean = ((CClampProxy::CInput *)(s + 0xc))->sub_100e3270();
	float sigma = ((CClampProxy::CInput *)(s + 0x18))->sub_100e3270();
	float v = (g_102b8488->*g_101e31e4)(mean, sigma);
	float hi = ((CClampProxy::CInput *)(s + 0x30))->sub_100e3270();
	float lo = ((CClampProxy::CInput *)(s + 0x24))->sub_100e3270();
	if (lo > hi) { float t = lo; lo = hi; hi = t; }
	if (v < lo) v = lo;
	else if (v > hi) v = hi;
	sub_100e33c0(v);
}
// END FUNCTION

// FUNCTION: 0x1010d870 size=0x1e
#include "CGaussianNoiseProxy.h"

// VC6 writes CGaussianNoiseProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CGaussianNoiseProxy *pcd_emit_1010d870() { return new CGaussianNoiseProxy; }

// TARGET: ??_GCGaussianNoiseProxy@@UAEPAXI@Z
// END FUNCTION
