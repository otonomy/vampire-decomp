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

// FUNCTION: 0x10114b40 size=0x238
#include "CBaseSimpleCollision.h"
#include "CGameTrace.h"
#include "Ray_t.h"
#include "ConVar.h"
#include "engineclient.h"

struct CUnknown1004b5c0 { int m_a[3]; void sub_1004b5c0(int a, int b); };
extern ConVar *g_103edd9c;
void sub_101659b0(const float *start, const float *end, int r, int g, int b, int noDepthTest, float duration);

// TARGET: CBaseSimpleCollision::vfunc2
void CBaseSimpleCollision::vfunc2(const Vector &start, const Vector &vel, float a, float b)
{
	Vector testpos;
	testpos = start;
	testpos.x = start.x;
	float h = a * 0.25f;
	Vector step;
	step.x = h * vel.x;
	step.y = h * vel.y;
	step.z = h * vel.z;
	float g = b * 0.25f;
	for (int i = 1; i <= 8.0f; i++)
	{
		Vector next;
		next.x = step.x;
		next.y = step.y;
		next.z = step.z;
		next.x += testpos.x;
		next.y += testpos.y;
		next.z += testpos.z;
		float t = i * 0.25f;
		Vector endpos;
		endpos.x = next.x;
		endpos.y = next.y;
		endpos.z = next.z - (t * t * 0.5f) * g;
		Ray_t ray;
		ray.m_Delta[0] = endpos.x - testpos.x;
		ray.m_Delta[1] = endpos.y - testpos.y;
		ray.m_Delta[2] = endpos.z - testpos.z;
		int swept = (ray.m_Delta[0] * ray.m_Delta[0] + ray.m_Delta[1] * ray.m_Delta[1] + ray.m_Delta[2] * ray.m_Delta[2]) != 0;
		*(char *)&ray.m_IsSwept = (char)swept;
		ray.m_StartOffset[0] = ray.m_StartOffset[1] = ray.m_StartOffset[2] = 0.0f;
		ray.m_IsRay = true;
		ray.m_Extents[0] = ray.m_Extents[1] = ray.m_Extents[2] = 0.0f;
		ray.m_Start[0] = testpos.x;
		ray.m_Start[1] = testpos.y;
		ray.m_Start[2] = testpos.z;
		ray.m_b32 = 0;
		ray.m_n34 = 0;
		ray.m_b33 = 0;
		CUnknown1004b5c0 filter;
		filter.sub_1004b5c0(0, 0);
		CGameTrace tr;
		enginetrace->vfunc4((int)&ray, 0x400b, &filter, (int)&tr);
		if (!g_103edd9c->vfunc1() && g_103edd9c->m_nValue)
			sub_101659b0(tr.m_startpos, tr.m_endpos, 0xff, 0, 0, 1, -1.0f);
		if (tr.m_fraction != 1.0f)
		{
			vfunc3(*(VPlane *)tr.m_planeNormal);
			return;
		}
		testpos.x = endpos.x;
		testpos.y = endpos.y;
		testpos.z = endpos.z;
	}
}
// END FUNCTION
