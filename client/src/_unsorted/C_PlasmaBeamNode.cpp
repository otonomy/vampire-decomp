// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100057a0 size=0x1e
#include "C_PlasmaBeamNode.h"

// VC6 writes C_PlasmaBeamNode's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_PlasmaBeamNode *pcd_emit_100057a0(const C_PlasmaBeamNode &other) { return new C_PlasmaBeamNode(other); }

// TARGET: ??_GC_PlasmaBeamNode@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10005800 size=0x16
#include "C_PlasmaBeamNode.h"
namespace lifted {
struct C10118080 { int sub_10118080(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual int f9(); };
}
void C_PlasmaBeamNode::vfunc37()
{
    int t0 = *(int *)((char *)this + 0x414);
    ((lifted::C10118080 *)t0)->sub_10118080(((lifted::V *)this)->f9());
}
// END FUNCTION

// FUNCTION: 0x10005820 size=0xbc
#include "C_PlasmaBeamNode.h"
#include "CGlobalVarsBase.h"
#include "engineclient.h"

struct CollSetupView_10005820
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void Setup(const Vector &origin, const Vector *dir, float angularSpread, float minSpeed, float maxSpeed, float gravity, float dampen);
};

void C_PlasmaBeamNode::OnDataChanged(int updateType)
{
	if (updateType == 0) {
		Vector vecDir = m_vecVelocityA8;
		float speed = VectorNormalize(vecDir);
		((CollSetupView_10005820 *)&m_pFirePlasmaSpray->m_collision)->Setup(GetAbsOrigin(), &vecDir, 0.3f, speed - 50.0f, speed + 50.0f, 800.0f, 0.5f);
		vfunc83(engine->Time(0) + 0.01);
	}
	C_BaseEntity::OnDataChanged(updateType);
}
// END FUNCTION

// FUNCTION: 0x100058f0 size=0x307
#include "Vector.h"
#include "C_PlasmaBeamNode.h"
#include "CPlasmaSpray.h"
#include "engineclient.h"
#include "Ray_t.h"
#include "CTraceFilterSimple.h"
#include "CGameTrace.h"
#include "QAngle.h"

void sub_101659b0(const Vector &start, const Vector &end, int r, int g, int b, bool noDepthTest, float duration);

struct ConVarView_100058f0
{
	int sub_10005de0();
};
extern ConVarView_100058f0 g_103edd98;

struct SimpleParticle_100058f0
{
	int m_unk00[6];
	Vector m_vecVelocity;	// 0x18
	int m_unk24;
	float m_flDieTime;	// 0x28
	float m_flLifetime;	// 0x2c
};

inline void UTIL_TraceLine_100058f0(const Vector &vecAbsStart, const Vector &vecAbsEnd, unsigned int mask, const void *ignore, int collisionGroup, CGameTrace *ptr)
{
	Ray_t ray;
	ray.sub_10005e00(vecAbsStart.Base(), vecAbsEnd.Base());
	CTraceFilterSimple traceFilter;
	traceFilter.sub_1004b5c0(ignore, collisionGroup);
	enginetrace->vfunc4((int)&ray, mask, &traceFilter, (int)ptr);
	if (g_103edd98.sub_10005de0())
		sub_101659b0(*(Vector *)ptr->m_startpos, *(Vector *)ptr->m_endpos, 255, 0, 0, true, -1.0f);
}

void C_PlasmaBeamNode::ClientThink()
{
	if (!m_bSprayOn)
		return;

	CGameTrace trace;
	Vector vEndTrace = GetAbsOrigin() + 0.3f * m_vecVelocityA8;
	UTIL_TraceLine_100058f0(GetAbsOrigin(), vEndTrace, 0x46004003, 0, 0, &trace);
	if (trace.m_fraction != 1.0f || trace.m_startsolid)
	{
		m_bSprayOn = false;
		return;
	}

	union { char c; int i; } handle;
	handle.c = (char)(int)m_pFirePlasmaSpray->sub_101180b0("sprites/plasmaember");
	for (int i = 0; i < 12; i++)
	{
		if (enginerandom->RandomInt(0, 2) == 0)
		{
			float ranx = enginerandom->RandomFloat(-28.0f, 28.0f);
			float rany = enginerandom->RandomFloat(-28.0f, 28.0f);
			float ranz = enginerandom->RandomFloat(-28.0f, 28.0f);

			Vector vNewPos = GetAbsOrigin();
			Vector vAdd = Vector(GetAbsAngles().x, GetAbsAngles().y, GetAbsAngles().z) * enginerandom->RandomFloat(-60, 120);
			vNewPos += vAdd;

			SimpleParticle_100058f0 *sParticle = (SimpleParticle_100058f0 *)m_pFirePlasmaSpray->sub_101180c0(0x3c, (void *)handle.i, vNewPos);
			sParticle->m_flLifetime = 0.0f;
			sParticle->m_flDieTime = 0.5f;
			sParticle->m_vecVelocity = m_vecVelocityA8;
			sParticle->m_vecVelocity.x += ranx;
			sParticle->m_vecVelocity.y += rany;
			sParticle->m_vecVelocity.z += ranz;
			C_BaseEntity *pOwner = this;
			unsigned long &h = *(unsigned long *)&m_pFirePlasmaSpray->m_78;
			if (pOwner)
				h = *pOwner->vfunc1();
			else
				h = 0xffffffff;
		}
	}
	vfunc83(engine->Time(0) + 0.05);
}
// END FUNCTION

// FUNCTION: 0x10005c00 size=0x6
#include "C_PlasmaBeamNode.h"
namespace lifted {
extern char g_10271d90;
}
int C_PlasmaBeamNode::vfunc16()
{
    return (int)&lifted::g_10271d90;
}
// END FUNCTION

// FUNCTION: 0x10005c10 size=0x3
#include "C_PlasmaBeamNode.h"
int C_PlasmaBeamNode::vfunc15()
{
    return 0;
}
// END FUNCTION
