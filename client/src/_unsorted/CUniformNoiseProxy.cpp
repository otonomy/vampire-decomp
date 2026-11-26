// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1010d5f0 size=0x3c
#include "engineclient.h"
#include "CUniformNoiseProxy.h"


// TARGET: CUniformNoiseProxy::vfunc1
void CUniformNoiseProxy::vfunc1(int)
{
	sub_100e33c0(enginerandom->RandomFloat(m_InputMin.sub_100e3270(), m_InputMax.sub_100e3270()));
}
// END FUNCTION

// FUNCTION: 0x1010d690 size=0x1e
#include "CUniformNoiseProxy.h"

// VC6 writes CUniformNoiseProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CUniformNoiseProxy *pcd_emit_1010d690() { return new CUniformNoiseProxy; }

// TARGET: ??_GCUniformNoiseProxy@@UAEPAXI@Z
// END FUNCTION
