// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10079410 size=0x24
#include "CAnimatedTextureProxy.h"
// TARGET: ??_GCAnimatedTextureProxy@@UAEPAXI@Z
CAnimatedTextureProxy *pcd_emit_10079410() { return new CAnimatedTextureProxy; }
// END FUNCTION

// FUNCTION: 0x10079440 size=0x2b
#include "engineclient.h"
#include "CAnimatedTextureProxy.h"
bool CAnimatedTextureProxy::vfunc0(void *a, void *b)
{
	*(float *)((char *)this + 0x14) = engine->Time(0);
	return CBaseAnimatedTextureProxy::vfunc0(a, b);
}
// END FUNCTION

// FUNCTION: 0x10079470 size=0x6
#include "CAnimatedTextureProxy.h"
float CAnimatedTextureProxy::vfunc4(int a0)
{
    return *(float *)((char *)this + 0x14);
}
// END FUNCTION
