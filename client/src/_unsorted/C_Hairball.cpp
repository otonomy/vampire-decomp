// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1002ca90 size=0x6ca
#include "C_Hairball.h"
#include "CGlobalVarsBase.h"
#include "engineclient.h"
#include "Ray_t.h"
#include "CTraceFilterSimple.h"
#include "CGameTrace.h"
#include "VMatrix.h"
#include "QAngle.h"
#include <math.h>

#define M_PI_1002ca90 3.14159265358979323846

extern float (__cdecl *g_101e31a0)(float minVal, float maxVal);	// RandomFloat
extern float g_1027c674;
float sub_10109fa0(float x);
void sub_101659b0(const Vector &start, const Vector &end, int r, int g, int b, bool noDepthTest, float duration);

struct ConVarView_1002ca90
{
	int sub_10005de0();
};
extern ConVarView_1002ca90 g_103edd98;

struct HairEntView_1002ca90
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42();
	virtual const Vector &GetLocalOrigin();	// slot 43
	virtual void SetLocalOrigin(const Vector &origin);	// slot 44
	virtual const QAngle &GetLocalAngles();	// slot 45
	virtual void SetLocalAngles(const QAngle &angles);	// slot 46
};

#define ENT_1002ca90 ((HairEntView_1002ca90 *)(C_BaseEntity *)this)

struct HairNode_1002ca90
{
	Vector m_vPos;
	Vector m_vPrevPos;
	Vector m_vPredicted;
};

static inline void Vector3DMultiplyPosition_1002ca90(const VMatrix &src1, const Vector &src2, Vector &dst)
{
	float y = src1[1][0] * src2[0] + src1[1][2] * src2[2] + src1[1][1] * src2[1] + src1[1][3];
	float z = src1[2][0] * src2[0] + src1[2][2] * src2[2] + src1[2][1] * src2[1] + src1[2][3];
	float x = src1[0][0] * src2[0] + src1[0][2] * src2[2] + src1[0][1] * src2[1] + src1[0][3];
	dst.x = x;
	dst.y = y;
	dst.z = z;
}

void C_Hairball::ClientThink()
{
	m_flSwayTime += gpGlobals->frametime;
	if (m_flSwayTime < m_flSwayPeriod)
	{
		float frac = m_flSwayTime / m_flSwayPeriod;
		QAngle angles = ENT_1002ca90->GetLocalAngles();
		angles.x += sub_10109fa0(frac) * m_flSwayX;
		angles.y += sub_10109fa0(frac) * m_flSwayY;
		ENT_1002ca90->SetLocalAngles(angles);
	}
	else
	{
		if (fabs(m_flSwayX) > 0.01f)
		{
			m_flSwayX = m_flSwayY = 0;
			m_flSwayPeriod = g_101e31a0(1.0f, 2.0f);
		}
		else
		{
			static float s_flSwayY = g_1027c674 * 0.1f;
			m_flSwayX = g_101e31a0(-M_PI_1002ca90 * g_1027c674, M_PI_1002ca90 * g_1027c674);
			m_flSwayY = g_101e31a0(-M_PI_1002ca90 * s_flSwayY, M_PI_1002ca90 * s_flSwayY);
			m_flSwayPeriod = g_101e31a0(1.0f, 4.0f);
		}
		m_flSwayTime = 0;
	}

	if (m_flNextBurst > 0.0f)
	{
		m_flNextBurst -= gpGlobals->frametime;
		if (m_flNextBurst <= 0.0f)
		{
			m_vecBurstVel.Init(1.0f, 0.0f, 0.0f);
			float flBestFrac = 0;
			for (int i = 0; i < 15; i++)
			{
				Vector dir(g_101e31a0(-1.0f, 1.0f), g_101e31a0(-1.0f, 1.0f), g_101e31a0(-1.0f, 1.0f));
				VectorNormalize(dir);

				Vector vecEnd = GetAbsOrigin() + dir * 10000.0f;
				Ray_t ray;
				ray.sub_10005e00(GetAbsOrigin().Base(), vecEnd.Base());
				CTraceFilterSimple filter;
				filter.sub_1004b5c0(0, 0);
				CGameTrace tr;
				enginetrace->vfunc4((int)&ray, 0x200400b, &filter, (int)&tr);
				if (g_103edd98.sub_10005de0())
					sub_101659b0(*(Vector *)tr.m_startpos, *(Vector *)tr.m_endpos, 255, 0, 0, true, -1.0f);

				if (tr.m_fraction != 1.0 && tr.m_fraction > flBestFrac)
				{
					flBestFrac = tr.m_fraction;
					m_vecBurstVel = dir;
				}
			}
			m_vecBurstVel *= 650.0f;
			m_flNextBurst = -1.0f;
		}
	}
	else
	{
		Vector vecEnd = GetAbsOrigin() + m_vecBurstVel * gpGlobals->frametime;
		Ray_t ray;
		ray.sub_10005e00(GetAbsOrigin().Base(), vecEnd.Base());
		CTraceFilterSimple filter;
		filter.sub_1004b5c0(0, 0);
		CGameTrace tr;
		enginetrace->vfunc4((int)&ray, 0x200400b, &filter, (int)&tr);
		if (g_103edd98.sub_10005de0())
			sub_101659b0(*(Vector *)tr.m_startpos, *(Vector *)tr.m_endpos, 255, 0, 0, true, -1.0f);

		if (tr.m_fraction < 1.0f)
		{
			m_flNextBurst = g_101e31a0(1.0f, 3.0f);
		}
		else
		{
			Vector vecNewOrigin = ENT_1002ca90->GetLocalOrigin() + m_vecBurstVel * gpGlobals->frametime;
			ENT_1002ca90->SetLocalOrigin(vecNewOrigin);
		}
	}

	VMatrix mat;
	mat.sub_101a2290(ENT_1002ca90->GetLocalOrigin(), ENT_1002ca90->GetLocalAngles());

	int i;
	for (i = 0; i < m_Vec434.m_Size; i++)
	{
		Vector3DMultiplyPosition_1002ca90(mat, ((Vector *)m_Vec434.m_Memory.m_pMemory)[i], ((Vector *)m_Vec448.m_Memory.m_pMemory)[i]);
	}

	if (m_bResetNodes)
	{
		m_bResetNodes = false;
		for (i = 0; i < m_Vec434.m_Size; i++)
		{
			for (int j = 0; j < m_unk418; j++)
			{
				const Vector &vecPt = ((Vector *)m_Vec448.m_Memory.m_pMemory)[i];
				HairNode_1002ca90 *pNode = &((HairNode_1002ca90 *)m_Vec420.m_pMemory)[m_unk418 * i + j];
				pNode->m_vPos = pNode->m_vPrevPos = pNode->m_vPredicted = vecPt;
			}
		}
	}

	m_Physics.sub_1012c770(m_Vec420.m_pMemory, m_Vec420.m_Size, &m_unk45c, gpGlobals->frametime, 0.98f);
}
// END FUNCTION
