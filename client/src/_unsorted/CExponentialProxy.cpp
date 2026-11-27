// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1010d890 size=0x94
#include "CExponentialProxy.h"
bool CExponentialProxy::vfunc0(void *pMaterial, void *pKeyValues)
{
	if (!CFunctionProxy::vfunc0(pMaterial, pKeyValues))
		return false;
	if (!m_flScale.sub_100e3140(pMaterial, pKeyValues, "scale", 1.0f))
		return false;
	if (!m_flOffset.sub_100e3140(pMaterial, pKeyValues, "offset", 0.0f))
		return false;
	if (!m_flMax.sub_100e3140(pMaterial, pKeyValues, "minVal", -3.402823466e+38f))
		return false;
	if (!m_flMin.sub_100e3140(pMaterial, pKeyValues, "maxVal", 3.402823466e+38f))
		return false;
	return true;
}
// END FUNCTION

// FUNCTION: 0x1010d930 size=0xd0
#include "CExponentialProxy.h"
#include "math.h"
struct ExpVar { virtual void v0(); virtual void v1(); virtual void v2(); virtual float GetFloat(); };
// TARGET: CExponentialProxy::vfunc1
void CExponentialProxy::vfunc1(int)
{
	double e = exp(((ExpVar *)m_unk0c)->GetFloat() + m_flOffset.sub_100e3270());
	float flVal = m_flScale.sub_100e3270() * e;
	float a = m_flMin.sub_100e3270();
	float b = m_flMax.sub_100e3270();
	if (b > a) {
		float t = b; b = a; a = t;
	}
	if (flVal < b)
		flVal = b;
	else if (flVal > a)
		flVal = a;
	sub_100e33c0(flVal);
}
// END FUNCTION

// FUNCTION: 0x1010da60 size=0x1e
#include "CExponentialProxy.h"

// VC6 writes CExponentialProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CExponentialProxy *pcd_emit_1010da60() { return new CExponentialProxy; }

// TARGET: ??_GCExponentialProxy@@UAEPAXI@Z
// END FUNCTION
