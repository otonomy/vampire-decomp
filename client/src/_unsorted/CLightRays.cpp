// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10049030 size=0x10e
#include "CLightRays.h"

extern float (__cdecl *g_101e31a0)(float flMin, float flMax);

// TARGET: CLightRays::CLightRays
CLightRays::CLightRays(int numRays, float a1, float a2, float a3, float a4, float a5, float a6)
{
	m_Rays.EnsureCount(numRays);

	for (int i = 0; i < numRays; i++)
	{
		m_Rays[i].f00 = g_101e31a0(0.0f, 360.0f);
		m_Rays[i].f04 = g_101e31a0(a1, a2);
		m_Rays[i].f08 = g_101e31a0(a3, a4);
		m_Rays[i].f0c = g_101e31a0(a5, a6);
		if (m_Rays[i].f08 > m_Rays[i].f0c)
		{
			float tmp = m_Rays[i].f08;
			m_Rays[i].f08 = m_Rays[i].f0c;
			m_Rays[i].f0c = tmp;
		}
		m_Rays[i].n28 = i;
	}

	m_v18 = Vector(1.0f, 0.0f, 0.0f);
	m_v24 = Vector(0.0f, 1.0f, 0.0f);
}
// END FUNCTION

// FUNCTION: 0x10049140 size=0x1e
#include "CLightRays.h"

// VC6 writes CLightRays's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CLightRays *pcd_emit_10049140() { return new CLightRays; }

// TARGET: ??_GCLightRays@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10049160 size=0x53
#include "CLightRays.h"

// TARGET: CLightRays::~CLightRays
CLightRays::~CLightRays()
{
}
// END FUNCTION

// FUNCTION: 0x100492b0 size=0x241
#include "CLightRays.h"
#include "engineclient.h"
extern "C" double floor(double);

void CLightRays::vfunc1()
{
	if (m_Rays.Count()) {
		float dt = engine->vfunc41(0);
		for (int i = 0; i < m_Rays.Count(); i++)
			m_Rays[i].f00 += dt * m_Rays[i].f04;
		sub_100491c0();
		bool bChanged = false;
		while (m_Rays[0].f00 < 0.0f) {
			LightRay_t t = m_Rays[0];
			t.f00 = t.f00 - floor(t.f00 * 0.0027777778f) * 360.0;
			m_Rays.Remove(0);
			m_Rays.AddToTail(t);
			bChanged = true;
		}
		if (bChanged)
			sub_100491c0();
		bChanged = false;
		while (m_Rays[m_Rays.Count() - 1].f00 >= 360.0f) {
			LightRay_t t = m_Rays[m_Rays.Count() - 1];
			t.f00 = t.f00 - floor(t.f00 * 0.0027777778f) * 360.0;
			m_Rays.Remove(m_Rays.Count() - 1);
			m_Rays.AddToHead(t);
			bChanged = true;
		}
		if (bChanged)
			sub_100491c0();
	}
}
// END FUNCTION
