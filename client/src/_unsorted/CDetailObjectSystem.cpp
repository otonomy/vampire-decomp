// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100e04b0 size=0x65
#include "CDetailObjectSystem.h"
void sub_10109910();
CDetailObjectSystem::CDetailObjectSystem()
{
    sub_10109910();
}
// TARGET: ??0CDetailObjectSystem@@QAE@XZ
// END FUNCTION

// FUNCTION: 0x100e0520 size=0x3
// TARGET: sub_100e0520
bool sub_100e0520()
{
	return true;
}
// END FUNCTION

// FUNCTION: 0x100e0530 size=0x1
#include "CDetailObjectSystem.h"

// TARGET: CDetailObjectSystem::vfunc1
void CDetailObjectSystem::vfunc1()
{
}
// END FUNCTION

// FUNCTION: 0x100e0540 size=0x1
#include "CDetailObjectSystem.h"

// TARGET: CDetailObjectSystem::vfunc3
void CDetailObjectSystem::vfunc3()
{
}
// END FUNCTION

// FUNCTION: 0x100e0550 size=0x1
#include "CDetailObjectSystem.h"
// TARGET: CDetailObjectSystem::vfunc6
void CDetailObjectSystem::vfunc6()
{
}
// END FUNCTION

// FUNCTION: 0x100e0560 size=0x3
// TARGET: sub_100e0560
void __stdcall sub_100e0560(int)
{
}
// END FUNCTION

// FUNCTION: 0x100e0570 size=0x21
struct El0570 { int a; int m4; char pad[72]; };
struct V0570 { char pad[0x1c]; El0570 *arr; int *sub_100e0570(unsigned int h); };
int *V0570::sub_100e0570(unsigned int h) { El0570 *e = &arr[h & 0xffff]; return e ? &e->m4 : 0; }
// END FUNCTION

// FUNCTION: 0x100e05a0 size=0x19
#include "CDetailObjectSystem.h"
// TARGET: CDetailObjectSystem::vfunc11
char *CDetailObjectSystem::vfunc11(unsigned int i)
{
	return (char *)m_data.m_unk1c + (i & 0xffff) * 80 + 0x20;
}
// END FUNCTION

// FUNCTION: 0x100e08f0 size=0x1
#include "CDetailObjectSystem.h"
// TARGET: CDetailObjectSystem::vfunc5
void CDetailObjectSystem::vfunc5()
{
}
// END FUNCTION

// FUNCTION: 0x100e0d90 size=0x24e
#include "CDetailObjectSystem.h"
#include "ConVar.h"
#include "Vector.h"
#define V10(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7(); virtual void n##8(); virtual void n##9();
struct IClientModeV { V10(a) virtual bool ShouldDrawDetailObjects(); };
struct IModelInfoV { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual bool ModelHasMaterialProxy(void *); virtual void a9(); virtual void a10(); virtual void RecomputeTranslucency(void *); };
struct ITimerV { virtual double Get(); };
struct StatV { char pad[0xb0]; double m_total; char pad2[0x188 - 0xb8]; double m_start; char pad3[0x308 - 0x190]; ITimerV *m_pTimer; };
struct IViewV { V10(a) virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5(); virtual void b6(); virtual void b7(); virtual int BuildWorldListsNumber(); };
struct ISpatialQueryV { virtual void a0(); virtual void a1(); virtual void a2(); virtual void EnumerateLeavesInSphere(const Vector *, float, ISpatialLeafEnumerator *, int); };
struct IEngineV { V10(a) V10(b) V10(c) V10(d) V10(e) V10(f) V10(g) V10(h) virtual void i0(); virtual void i1(); virtual void i2(); virtual void i3(); virtual void i4(); virtual void i5(); virtual void i6(); virtual ISpatialQueryV *GetBSPTreeQuery(); };
struct EnumContext_t { float m_MaxSqDist; float m_FadeSqDist; float m_FalloffFactor; int m_BuildWorldListNumber; };
extern IClientModeV *g_105f99d8;
extern ConVar g_10619018;
extern IModelInfoV *g_104a57f8;
extern IViewV *g_102d43d8;
extern IEngineV *g_104a57d4;
StatV *sub_100ad7a0();
const Vector *sub_10198d30();
// TARGET: CDetailObjectSystem::vfunc10
void CDetailObjectSystem::vfunc10()
{
	if (!g_105f99d8->ShouldDrawDetailObjects() || g_10619018.GetInt() == 0)
		return;
	for (int i = m_data.m_unk14; --i >= 0; )
	{
		if (g_104a57f8->ModelHasMaterialProxy(((void **)m_data.m_unk8)[i]))
			g_104a57f8->RecomputeTranslucency(((void **)m_data.m_unk8)[i]);
	}
	StatV *stat = sub_100ad7a0();
	if (stat->m_pTimer)
		stat->m_start = stat->m_pTimer->Get();
	static ConVar cl_detaildist("cl_detaildist", "600", 0, "Draw current position at top of screen");
	static ConVar cl_detailfade("cl_detailfade", "300", 0, "Draw current position at top of screen");
	EnumContext_t ctx;
	ctx.m_MaxSqDist = cl_detaildist.GetFloat() * cl_detaildist.GetFloat();
	ctx.m_FadeSqDist = cl_detaildist.GetFloat() - cl_detailfade.GetFloat();
	if (ctx.m_FadeSqDist > 0)
		ctx.m_FadeSqDist *= ctx.m_FadeSqDist;
	else
		ctx.m_FadeSqDist = 0;
	ctx.m_FalloffFactor = 255.0f / (ctx.m_MaxSqDist - ctx.m_FadeSqDist);
	ctx.m_BuildWorldListNumber = g_102d43d8->BuildWorldListsNumber();
	ISpatialQueryV *pQuery = g_104a57d4->GetBSPTreeQuery();
	pQuery->EnumerateLeavesInSphere(sub_10198d30(), cl_detaildist.GetFloat(), this, (int)&ctx);
	stat = sub_100ad7a0();
	if (stat->m_pTimer)
		stat->m_total += stat->m_pTimer->Get() - stat->m_start;
}
// END FUNCTION
