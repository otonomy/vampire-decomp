// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100ee940 size=0x3d
#include "GlobalWetnessProxy.h"
#include "CClampProxy.h"
bool GlobalWetnessProxy::vfunc0(void *pMaterial, void *pKeyValues)
{
	if (!CResultProxy::vfunc0(pMaterial, pKeyValues))
		return false;
	if (!m_Scale.sub_100e3140(pMaterial, pKeyValues, "scale", 1.0f))
		return false;
	return true;
}
// END FUNCTION

// FUNCTION: 0x100ee980 size=0x79
#include "GlobalWetnessProxy.h"
#include "CClampProxy.h"

struct WetEntView
{
	char pad[0x444];
	float m_fl444;
};

struct WetProxyView
{
	void *vt;
	int m_unk04;
	int m_unk08;
	CClampProxy::CInput m_input;
	void sub_100e33c0(float);
};

int sub_100ca9c0();

// TARGET: GlobalWetnessProxy::vfunc1
void GlobalWetnessProxy::vfunc1(int)
{
	WetEntView *p = (WetEntView *)sub_100ca9c0();
	if (p)
	{
		float f = p->m_fl444;
		f *= ((WetProxyView *)this)->m_input.sub_100e3270();
		if (f > 1.0f)
			f = 1.0f;
		if (f < 0.0f)
			f = 0.0f;
		((WetProxyView *)this)->sub_100e33c0(f);
	}
}
// END FUNCTION

// FUNCTION: 0x100eea60 size=0x1e
#include "GlobalWetnessProxy.h"

// VC6 writes GlobalWetnessProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
GlobalWetnessProxy *pcd_emit_100eea60() { return new GlobalWetnessProxy; }

// TARGET: ??_GGlobalWetnessProxy@@UAEPAXI@Z
// END FUNCTION
