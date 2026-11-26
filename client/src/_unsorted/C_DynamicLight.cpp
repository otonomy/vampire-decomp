// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100add30 size=0x6
#include "C_DynamicLight.h"
namespace lifted {
extern char g_102b2a04;
}
int C_DynamicLight::vfunc16()
{
    return (int)&lifted::g_102b2a04;
}
// END FUNCTION

// FUNCTION: 0x100add40 size=0x3
#include "C_DynamicLight.h"
int C_DynamicLight::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100ae000 size=0x1e
#include "C_DynamicLight.h"

// VC6 writes C_DynamicLight's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_DynamicLight *pcd_emit_100ae000(const C_DynamicLight &other) { return new C_DynamicLight(other); }

// TARGET: ??_GC_DynamicLight@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100ae070 size=0x49a
#include "C_DynamicLight.h"
#include "engineclient.h"
#include "CGameTrace.h"
#include "Ray_t.h"
#include "CTraceFilterSimple.h"
#include "ConVar.h"
#include "QAngle.h"

struct dlight_t
{
	int flags;		// 0x00
	Vector origin;		// 0x04
	float radius;		// 0x10
	unsigned char color[4];	// 0x14: r, g, b, exponent
	float die;		// 0x18
	float decay;		// 0x1c
	float minlight;		// 0x20
	int key;		// 0x24
	int style;		// 0x28
	Vector m_Direction;	// 0x2c
	float m_InnerAngle;	// 0x38
	float m_OuterAngle;	// 0x3c
};

extern ConVar *g_103edd9c;
void sub_101090a0(const QAngle &angles, Vector *forward, Vector *right, Vector *up);
void sub_10108fd0(const Vector &start, float scale, const Vector &dir, Vector &dest);
void sub_101659b0(const Vector &start, const Vector &end, int r, int g, int b, bool noDepthTest, float duration);

static inline void UTIL_TraceLine_100ae070(const Vector &vecAbsStart, const Vector &vecAbsEnd, unsigned int mask, const void *ignore, int collisionGroup, CGameTrace *ptr)
{
	Ray_t ray;
	ray.Init(vecAbsStart, vecAbsEnd);
	CTraceFilterSimple traceFilter;
	traceFilter.sub_1004b5c0(ignore, collisionGroup);
	enginetrace->vfunc4((int)&ray, mask, &traceFilter, (int)ptr);
	if ((g_103edd9c->vfunc1() ? 0 : g_103edd9c->m_nValue) != 0)
	{
		sub_101659b0(*(const Vector *)ptr->m_startpos, *(const Vector *)ptr->m_endpos, 255, 0, 0, true, -1.0f);
	}
}

void C_DynamicLight::ClientThink()
{
	Vector forward;
	sub_101090a0(GetAbsAngles(), &forward, 0, 0);

	if ((m_Flags & 2) == 0)
	{
		if (!m_pDynamicLight || m_pDynamicLight->key != m_index)
		{
			m_pDynamicLight = (dlight_t *)effects->CL_AllocDlight(m_index);
		}

		m_pDynamicLight->style = m_LightStyle;
		m_pDynamicLight->radius = m_Radius;
		m_pDynamicLight->flags = m_Flags;
		if (m_OuterAngle > 0)
			m_pDynamicLight->flags |= 1;
		m_pDynamicLight->color[0] = m_clrRender[0];
		m_pDynamicLight->color[1] = m_clrRender[1];
		m_pDynamicLight->color[2] = m_clrRender[2];
		m_pDynamicLight->color[3] = m_Exponent;
		m_pDynamicLight->origin = GetAbsOrigin();
		m_pDynamicLight->m_InnerAngle = m_InnerAngle;
		m_pDynamicLight->m_OuterAngle = m_OuterAngle;
		m_pDynamicLight->die = engine->Time(0) + 1e6;
		m_pDynamicLight->m_Direction = forward;
	}
	else
	{
		if (m_pDynamicLight)
		{
			m_pDynamicLight->die = engine->Time(0);
			m_pDynamicLight = 0;
		}
	}

	if ((m_OuterAngle > 0) && ((m_Flags & 1) == 0))
	{
		if (!m_pSpotlightEnd || m_pSpotlightEnd->key != -m_index)
		{
			m_pSpotlightEnd = (dlight_t *)effects->CL_AllocDlight(-m_index);
		}

		Vector end;
		sub_10108fd0(GetAbsOrigin(), m_Radius, forward, end);

		CGameTrace pm;
		UTIL_TraceLine_100ae070(GetAbsOrigin(), end, 0x2000b, 0, 0, &pm);
		m_pSpotlightEnd->origin = *(const Vector *)pm.m_endpos;

		if (pm.m_fraction == 1.0f)
		{
			m_pSpotlightEnd->die = engine->Time(0);
			m_pSpotlightEnd = 0;
		}
		else
		{
			float falloff = 1.0 - pm.m_fraction;
			falloff *= falloff;

			m_pSpotlightEnd->style = m_LightStyle;
			m_pSpotlightEnd->flags = 2;
			m_pSpotlightEnd->radius = m_SpotRadius;
			m_pSpotlightEnd->die = engine->Time(0) + 1e6;
			m_pSpotlightEnd->color[0] = m_clrRender[0] * falloff;
			m_pSpotlightEnd->color[1] = m_clrRender[1] * falloff;
			m_pSpotlightEnd->color[2] = m_clrRender[2] * falloff;
			m_pSpotlightEnd->color[3] = m_Exponent;

			m_pSpotlightEnd->m_Direction = forward;

			render->vfunc2(m_pSpotlightEnd);
		}
	}
	else
	{
		if (m_pSpotlightEnd)
		{
			m_pSpotlightEnd->die = engine->Time(0);
			m_pSpotlightEnd = 0;
		}
	}

	vfunc83(engine->Time(0) + 0.001);
}
// END FUNCTION

// FUNCTION: 0x100ae510 size=0x9a
#include "C_DynamicLight.h"
#include "ehandle.h"
#include "Vector.h"
#include "QAngle.h"

struct DynLightView
{
	char m_pad000[0x188];
	CBaseHandle m_hOwner;
	char m_pad18c[0x428 - 0x18c];
	int m_n428;
};

struct CBaseEntV77
{
	void sub_100a0e30();
};

void C_DynamicLight::vfunc77()
{
	DynLightView *v = (DynLightView *)this;
	if (v->m_n428 > 0)
	{
		C_BaseEntity *pOwner = (C_BaseEntity *)v->m_hOwner.Get();
		if (pOwner)
		{
			Vector origin;
			QAngle angles;
			pOwner->vfunc57(v->m_n428, (int)&origin, (int)&angles);
			vfunc44((int)&origin);
			vfunc46((int)&angles);
			sub_100a2030(&origin);
			sub_100a2100(angles);
			return;
		}
	}
	((CBaseEntV77 *)this)->sub_100a0e30();
}
// END FUNCTION
