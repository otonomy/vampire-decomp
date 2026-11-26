// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100d0710 size=0x31
#include "engineclient.h"
#include "CClientEffectPrecacheSystem.h"
struct XEff { virtual void d(int); };
struct XCEP { int u0; XEff **m_pList; char u1[8]; int m_n; };
// TARGET: CClientEffectPrecacheSystem::vfunc2
void CClientEffectPrecacheSystem::vfunc2()
{
	XCEP *p = (XCEP *)this;
	for (int i = 0; i < p->m_n; i++)
		p->m_pList[i]->d(1);
	materials->vfunc41();
}
// END FUNCTION

// FUNCTION: 0x100d0750 size=0x1
#include "CClientEffectPrecacheSystem.h"
void CClientEffectPrecacheSystem::vfunc4()
{
}
// END FUNCTION

// FUNCTION: 0x100d0760 size=0x24
#include "CClientEffectPrecacheSystem.h"
struct E100d0760 { virtual void v0(int); };
void CClientEffectPrecacheSystem::vfunc5()
{
	E100d0760 **p = *(E100d0760 ***)((char *)this + 4);
	for (int i = 0; i < *(int *)((char *)this + 0x10); i++)
		(*(E100d0760 ***)((char *)this + 4))[i]->v0(0);
}
// END FUNCTION

// FUNCTION: 0x100d0790 size=0x41
#include "CClientEffectPrecacheSystem.h"
extern "C" __declspec(dllimport) void Plat_Free(void *);
void CClientEffectPrecacheSystem::vfunc1()
{
    *(int *)((char *)this + 0x10) = 0;
    if ((*(int *)((char *)this + 0xc)) != -1) {
        if ((*(int *)((char *)this + 4)) != 0) {
            Plat_Free((void *)(*(int *)((char *)this + 4)));
            *(int *)((char *)this + 4) = 0;
        }
        *(int *)((char *)this + 8) = 0;
        *(int *)((char *)this + 0x14) = *(int *)((char *)this + 4);
        return;
    }
    *(int *)((char *)this + 0x14) = *(int *)((char *)this + 4);
}
// END FUNCTION

// FUNCTION: 0x100d0890 size=0x3
#include "CClientEffectPrecacheSystem.h"
bool CClientEffectPrecacheSystem::vfunc0()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100d08a0 size=0x1
#include "CClientEffectPrecacheSystem.h"
void CClientEffectPrecacheSystem::vfunc3()
{
}
// END FUNCTION

// FUNCTION: 0x100d08b0 size=0x3
// TARGET: sub_100d08b0
void __stdcall sub_100d08b0(int)
{
}
// END FUNCTION

// FUNCTION: 0x100d08c0 size=0x1
#include "CClientEffectPrecacheSystem.h"
void CClientEffectPrecacheSystem::vfunc6()
{
}
// END FUNCTION

// FUNCTION: 0x100d08d0 size=0x6e
#include "CClientEffectPrecacheSystem.h"

// TARGET: ??_GCClientEffectPrecacheSystem@@UAEPAXI@Z
CClientEffectPrecacheSystem *pcd_emit_100d08d0()
{
	return new CClientEffectPrecacheSystem;
}
// END FUNCTION
