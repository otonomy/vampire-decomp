// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101148a0 size=0x20f
#include "CBaseSimpleCollision.h"
#include "CGameTrace.h"
#include "Ray_t.h"
#include "ConVar.h"
#include "CUnknown1070b254.h"

struct CUnknown1004b5c0 { int m_a[3]; void sub_1004b5c0(int a, int b); };
extern ConVar *g_103edd9c;
void sub_101659b0(CGameTrace *, float *, int, int, int, int, float);

// TARGET: CBaseSimpleCollision::vfunc1
void CBaseSimpleCollision::vfunc1(const Vector &start, const Vector &end, CGameTrace *pTrace, bool coarse)
{
	for (int i = 0; i < m_nActivePlanes; i++)
	{
		if (m_collisionPlanes[i].m_Dist == -1.0f)
			continue;
		float startDot = (start.x * m_collisionPlanes[i].m_Normal.x) + (start.y * m_collisionPlanes[i].m_Normal.y + start.z * m_collisionPlanes[i].m_Normal.z) - m_collisionPlanes[i].m_Dist;
		float endDot = end.y * m_collisionPlanes[i].m_Normal.y + end.z * m_collisionPlanes[i].m_Normal.z + m_collisionPlanes[i].m_Normal.x * end.x - m_collisionPlanes[i].m_Dist;
		if (startDot < -0.01f)
			continue;
		int startInside = (startDot > 0.01f);
		int endInside = (endDot > 0.01f);
		if (startInside != endInside)
		{
			float t = startDot / (startDot - endDot);
			Vector d;
			d = (end - start) * t;
			Vector *hit = (Vector *)pTrace->m_endpos;
			*hit = start + d;
			pTrace->m_fraction = t - 0.01f;
			*(Vector *)pTrace->m_planeNormal = m_collisionPlanes[i].m_Normal;
			pTrace->m_planeDist = m_collisionPlanes[i].m_Dist;
			if (!coarse && pTrace->m_fraction < 1.0f)
			{
				Ray_t ray;
				ray.sub_10005e00(&start.x, &end.x);
				CUnknown1004b5c0 filter;
				filter.sub_1004b5c0(0, 0);
				g_104a582c->vfunc4(&ray, 0x400b, (CTraceFilterNoCharacterCollide *)&filter, pTrace);
				if (!g_103edd9c->vfunc1() && g_103edd9c->m_nValue)
					sub_101659b0(pTrace, (float *)hit, 0xff, 0, 0, 1, -1.0f);
			}
			return;
		}
	}
	pTrace->m_planeNormal[0] = 0;
	pTrace->m_planeNormal[1] = 0;
	pTrace->m_planeNormal[2] = 0;
	pTrace->m_planeDist = 0;
	pTrace->m_fraction = 1.0f;
}
// END FUNCTION
