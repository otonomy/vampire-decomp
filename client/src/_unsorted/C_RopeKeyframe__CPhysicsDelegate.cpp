// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100be960 size=0x228
#include "engineclient.h"
#include <math.h>
#include <stdlib.h>
#include "C_RopeKeyframe.h"
#include "ConVar.h"


extern ConVar *g_104a3a5c;
extern float g_102b5c84;

extern void sub_100e2fc0(float flTime, Vector &vWind);
extern void sub_10108fd0(const float *start, float scale, const float *dir, float *dest);

static inline Vector RandomVector(float minVal, float maxVal)
{
	Vector random;
	float scale = (maxVal - minVal) * (1.0f / 32767.0f);
	random.x = minVal + (float)rand() * scale;
	random.y = minVal + (float)rand() * scale;
	random.z = minVal + (float)rand() * scale;
	return random;
}

void C_RopeKeyframe::CPhysicsDelegate::vfunc0(CRopeNode *pNodes, int iNode, Vector *pAccel)
{
	pAccel->Init(0.0f, 0.0f, -1500.0f);

	if (!(m_pKeyframe->m_LockedPoints[iNode >> 5] & (1 << (iNode & 31))) && m_pKeyframe->m_bApplyWind)
	{
		Vector vWind;
		sub_100e2fc0(engine->Time(0), vWind);
		if (vWind.LengthSqr() > 0.0f)
		{
			sub_10108fd0(pAccel->Base(), 10.0f, vWind.Base(), pAccel->Base());
		}
		else if (m_pKeyframe->m_flCurWindTime < m_pKeyframe->m_flWindDuration)
		{
			float flScale = 1.0 - cos((m_pKeyframe->m_flCurWindTime / m_pKeyframe->m_flWindDuration) * 3.141592653589793);
			*pAccel += m_pKeyframe->m_vWindDir * flScale;
		}
	}

	if (!g_104a3a5c->vfunc1() && g_104a3a5c->m_nValue)
	{
		*pAccel += RandomVector(-g_102b5c84, g_102b5c84);
	}

	*pAccel += m_pKeyframe->m_vForce * 20.0f;
	m_pKeyframe->m_vForce *= 0.95f;
}
// END FUNCTION
