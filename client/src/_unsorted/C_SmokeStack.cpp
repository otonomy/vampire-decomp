// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1002f780 size=0x6
#include "C_SmokeStack.h"
namespace lifted {
extern char g_1027cbe0;
}
int C_SmokeStack::vfunc16()
{
    return (int)&lifted::g_1027cbe0;
}
// END FUNCTION

// FUNCTION: 0x1002f790 size=0x3
#include "C_SmokeStack.h"
int C_SmokeStack::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1002fcf0 size=0x1e
#include "C_SmokeStack.h"

// VC6 writes C_SmokeStack's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_SmokeStack *pcd_emit_1002fcf0(const C_SmokeStack &other) { return new C_SmokeStack(other); }

// TARGET: ??_GC_SmokeStack@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1002fd90 size=0x60
#include "C_SmokeStack.h"

class CParticleMgr;
extern CParticleMgr g_104e0768;	// g_ParticleMgr

struct CPrototypeAppEffect_1002fd90
{
	virtual void v0();
	virtual void Start(CParticleMgr *pParticleMgr, void *pArgs);
};

#define clamp(val, min, max) (((val) > (max)) ? (max) : (((val) < (min)) ? (min) : (val)))

void C_SmokeStack::OnDataChanged(int updateType)
{
	C_BaseEntity::OnDataChanged(updateType);

	int &nType = *(int *)((char *)this + 0x528);
	nType = clamp(nType, 0, 2);

	if (updateType == 0)
	{
		((CPrototypeAppEffect_1002fd90 *)((char *)this + 0x468))->Start(&g_104e0768, 0);
	}

	// Recalculate lifetime in case length or speed changed.
	*(float *)((char *)this + 0x57c) = *(float *)((char *)this + 0x4d4) / *(float *)((char *)this + 0x4e4);
}
// END FUNCTION
