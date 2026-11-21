// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "vampire.h"

// FUNCTION: 0x10027c20 size=0x6
#include "CPhysThruster.h"

//-----------------------------------------------------------------------------
// CPhysThruster::GetDataDescMap
//-----------------------------------------------------------------------------
datamap_t *CPhysThruster::vfunc82()
{
	return &m_DataMap;
}
// END FUNCTION

// FUNCTION: 0x10027cb0 size=0xe4
#include "CPhysThruster.h"

extern Vector g_1070d1b0;	// vec3_origin

//-----------------------------------------------------------------------------
// Purpose: OnActivate: remember where the thruster sits relative to the attached entity
//-----------------------------------------------------------------------------
void CPhysThruster::vfunc242()
{
	if (m_hAttached != 0)
	{
		if (m_flags204 & SF_THRUST_IGNORE_POS)
		{
			m_localOrigin = g_1070d1b0;
		}
		else
		{
			m_localOrigin = *(Vector *)vfunc217() - *(Vector *)m_hAttached->vfunc217();	// GetAbsOrigin (CBaseEntity.h types slot 217 as float *)
		}
	}
}
// END FUNCTION

// FUNCTION: 0x10027de0 size=0x18c
#include "CPhysThruster.h"
#include "IPhysicsObject.h"
#include "CUnknown101d1460.h"
#include "QAngle.h"

struct CMatrix10027de0 : CUnknown101d1460
{
	void sub_10027fe0(Vector *pOut, const Vector *pIn);
	void sub_10028060(Vector *pOut, const Vector *pIn);
	void sub_100280e0(Vector *pOut, const Vector *pIn);
};

void sub_10139550(const QAngle &angles, Vector *pForward);

//-----------------------------------------------------------------------------
// Purpose: SetupForces
//-----------------------------------------------------------------------------
void CPhysThruster::vfunc241(IPhysicsObject *pPhys, Vector *pLinear, Vector *pAngular)
{
	Vector vecForce;
	sub_10139550(*(const QAngle *)vfunc221(), &vecForce);	// AngleVectors( GetAbsAngles() ) (CBaseEntity.h types slot 221 as float *)
	vecForce = vecForce * m_force;
	if (m_flags204 & SF_THRUST_MASS_INDEPENDENT)
		vecForce = vecForce * pPhys->vfunc12();
	{
		CMatrix10027de0 matAttached;
		matAttached.sub_101d1530(m_hAttached, 0);
		Vector vecOffset;
		matAttached.sub_10027fe0(&vecOffset, &m_localOrigin);
		{
			Vector vecTemp;
			matAttached.sub_10028060(&vecTemp, &vecForce);
			vecForce = vecTemp;
		}
		pPhys->vfunc33(&vecForce, &vecOffset, pLinear, pAngular);
		if (m_flags204 & SF_THRUST_LOCAL_ORIENTATION)
		{
			Vector vecLocal;
			matAttached.sub_100280e0(&vecLocal, pLinear);
			*pLinear = vecLocal;
		}
	}
	if (!(m_flags204 & SF_THRUST_FORCE))
	{
		pLinear->x = 0;
		pLinear->y = 0;
		pLinear->z = 0;
	}
	if (!(m_flags204 & SF_THRUST_TORQUE))
	{
		pAngular->x = 0;
		pAngular->y = 0;
		pAngular->z = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x10029b50 size=0x1e
#include "CPhysThruster.h"

void sub_100aa7b0(void *p);

//-----------------------------------------------------------------------------
// CPhysThruster scalar deleting destructor
//-----------------------------------------------------------------------------
CBaseEntity *CPhysThruster::vfunc5(unsigned int flags)
{
	sub_10014470();
	if (flags & 1)
		sub_100aa7b0(this);
	return this;
}
// END FUNCTION
