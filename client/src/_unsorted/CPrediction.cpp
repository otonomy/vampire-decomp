// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10120e40 size=0x1e
#include "CPrediction.h"

// VC6 writes CPrediction's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CPrediction *pcd_emit_10120e40() { return new CPrediction; }

// TARGET: ??_GCPrediction@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10120e90 size=0x31
#include "CPrediction.h"
struct CV_10120e90 { virtual void v0(); virtual bool v1(); char pad[0x2c - 4]; void *m_p2c; };
extern CV_10120e90 *g_104e170c;
struct View_10120e90 { char pad[0x34]; bool m_b34; };
void CPrediction::vfunc1()
{
	((View_10120e90 *)this)->m_b34 = (g_104e170c->v1() ? 0 : g_104e170c->m_p2c) != 0;
}
// END FUNCTION

// FUNCTION: 0x10120ed0 size=0x1
#include "CPrediction.h"
void CPrediction::vfunc2()
{
}
// END FUNCTION

// FUNCTION: 0x101225f0 size=0x250
template <class T> __forceinline T pcd_stage(T x) { return x; }
#include "CPrediction.h"
#include "CGameTrace.h"
#include "Ray_t.h"
#include "CTraceFilterSimple.h"
#include "CUnknown1070b254.h"
#include "ConVar.h"
#include "QAngle.h"

extern ConVar *g_103edd9c;
extern ConVar *g_104e1584;
extern int g_104e16f4;
extern float g_104e16f8;
void sub_101090a0(const QAngle &angles, Vector *forward, Vector *right, Vector *up);
void sub_10108fd0(const Vector &start, float scale, const Vector &dir, Vector &dest);
void sub_101659b0(const Vector &start, const Vector &end, int r, int g, int b, bool noDepthTest, float duration);

static inline void UTIL_TraceLine(const Vector &vecAbsStart, const Vector &vecAbsEnd, unsigned int mask, const void *ignore, int collisionGroup, CGameTrace *ptr)
{
	Ray_t ray;
	ray.sub_10005e00(&vecAbsStart.x, &vecAbsEnd.x);
	CTraceFilterSimple traceFilter;
	traceFilter.sub_1004b5c0(ignore, collisionGroup);
	g_104a582c->vfunc4(&ray, mask, (CTraceFilterNoCharacterCollide *)&traceFilter, ptr);
	if ((g_103edd9c->vfunc1() ? 0 : g_103edd9c->m_nValue) != 0)
	{
		sub_101659b0(*(const Vector *)ptr->m_startpos, *(const Vector *)ptr->m_endpos, 255, 0, 0, true, -1.0f);
	}
}

void CPrediction::vfunc19(const Vector &origin, const QAngle &angles, const Vector &viewofs)
{
	if (g_104e16f4 == -1)
		return;

	Vector forward;
	sub_101090a0(angles, &forward, 0, 0);
	forward.z = 0;

	float heights[6];
	int count = 0;
	for (int dist = 36; dist < 108; dist += 12)
	{
		Vector start;
		sub_10108fd0(origin, (float)dist, forward, start);
		start.z = pcd_stage(viewofs.z) + start.z;
		Vector end;
		end.x = start.x;
		end.y = start.y;
		end.z = start.z - 160.0f;

		CGameTrace tr;
		UTIL_TraceLine(start, end, 0x200400b, 0, 6, &tr);
		if (tr.m_allsolid || tr.m_fraction == 1.0f)
			return;
		heights[count++] = start.z + tr.m_fraction * (end.z - start.z);
	}

	int lastStep = 0;
	int nSteps = 0;
	for (int i = 1; i < count; i++)
	{
		int t0 = heights[i] - heights[i - 1]; int step = (int)(t0);
		if (step > -0.1 && step < 0.1)
			continue;
		if (lastStep)
		{
			int diff = step - lastStep;
			if (diff > 0.1 || diff < -0.1)
				return;
		}
		nSteps++;
		lastStep = step;
	}

	if (!lastStep)
	{
		g_104e16f8 = 0;
		return;
	}
	if (nSteps < 2)
		return;
	g_104e16f8 = (g_104e1584->vfunc1() ? 0.0f : g_104e1584->m_fValue) * -lastStep;
}

/* judged with these header patches (not saved):
[
 {
  "path": "include/CPrediction.h",
  "old": "    virtual void vfunc19();",
  "new": "    virtual void vfunc19(const class Vector &origin, const class QAngle &angles, const class Vector &viewofs);"
 }
]
*/
// END FUNCTION

// FUNCTION: 0x101230c0 size=0x4
#include "CPrediction.h"
bool CPrediction::vfunc12()
{
    return *(bool *)((char *)this + 0x24);
}
// END FUNCTION

// FUNCTION: 0x101230d0 size=0x4
#include "CPrediction.h"
int CPrediction::vfunc13()
{
    return *(int *)((char *)this + 0x28);
}
// END FUNCTION

// FUNCTION: 0x101230e0 size=0x4
#include "CPrediction.h"
bool CPrediction::vfunc14()
{
    return *(bool *)((char *)this + 0x2c);
}
// END FUNCTION

// FUNCTION: 0x101230f0 size=0x11
#include "C_BasePlayer.h"
#include "CPrediction.h"
int CPrediction::vfunc7()
{
    if (C_BasePlayer::GetLocalPlayer() == 0) {
        return ((int)C_BasePlayer::GetLocalPlayer());
    }
    return *(int *)((char *)((int)C_BasePlayer::GetLocalPlayer()) + 0x90);
}
// END FUNCTION

// FUNCTION: 0x10123110 size=0x37
#include "C_BasePlayer.h"
#include "CPrediction.h"
#include "C_BasePlayer.h"
#include "Vector.h"
// TARGET: CPrediction::vfunc8
void CPrediction::vfunc8(Vector *v)
{
    if (C_BasePlayer::GetLocalPlayer() == 0) {
        v->x = 0;
        v->y = 0;
        v->z = 0;
    } else {
        *v = C_BasePlayer::GetLocalPlayer()->GetAbsOrigin();
    }
}
// END FUNCTION

// FUNCTION: 0x10123150 size=0x28
#include "C_BasePlayer.h"
#include "CPrediction.h"
namespace lifted {
struct C100a2030 { int sub_100a2030(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual int f44(int); };
}
void CPrediction::vfunc9(int a0)
{
    int t0 = ((int)C_BasePlayer::GetLocalPlayer());
    if (t0 != 0) {
        ((lifted::C100a2030 *)t0)->sub_100a2030(a0);
        ((lifted::V *)t0)->f44(a0);
    }
}
// END FUNCTION

// FUNCTION: 0x10123180 size=0x3a
#include "C_BasePlayer.h"
#include "CPrediction.h"
#include "C_BasePlayer.h"
#include "Vector.h"
// TARGET: CPrediction::vfunc10
void CPrediction::vfunc10(Vector *v)
{
    if (C_BasePlayer::GetLocalPlayer() == 0) {
        v->x = 0;
        v->y = 0;
        v->z = 0;
    } else {
        *v = *(Vector *)C_BasePlayer::GetLocalPlayer()->vfunc195();
    }
}
// END FUNCTION

// FUNCTION: 0x101231c0 size=0x32
#include "C_BasePlayer.h"
#include "CPrediction.h"
#include "Vector.h"
#define V10(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4(); virtual void a##5(); virtual void a##6(); virtual void a##7(); virtual void a##8(); virtual void a##9();
struct PlayerView {
 V10(a0) V10(a1) V10(a2) V10(a3) V10(a4) V10(a5) V10(a6) V10(a7) V10(a8) V10(a9)
 V10(b0) V10(b1) V10(b2) V10(b3) V10(b4) V10(b5) V10(b6)
 virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5();
 virtual void c6(); virtual void c7(); virtual void c8(); virtual void c9(); virtual void d0(); virtual void d1();
 virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
 virtual void d8(); virtual void d9(); virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3();
 virtual void e4(); virtual void e5();
 virtual void vfunc196(Vector v);
};
// TARGET: CPrediction::vfunc11
void CPrediction::vfunc11(const Vector *v)
{
    if (C_BasePlayer::GetLocalPlayer())
        ((PlayerView *)C_BasePlayer::GetLocalPlayer())->vfunc196(*v);
}
// END FUNCTION

// FUNCTION: 0x10123200 size=0x4
#include "CPrediction.h"
int CPrediction::vfunc15()
{
    return *(int *)((char *)this + 0x30);
}
// END FUNCTION
