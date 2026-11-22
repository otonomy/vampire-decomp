// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "vampire.h"

// FUNCTION: 0x10028160 size=0x6
#include "CPhysTorque.h"

//-----------------------------------------------------------------------------
// CPhysTorque::GetDataDescMap
//-----------------------------------------------------------------------------
datamap_t *CPhysTorque::vfunc82()
{
	return &m_DataMap;
}
// END FUNCTION

// FUNCTION: 0x10028260 size=0x5f
#include "CPhysTorque.h"

void sub_101cf680(Vector *, float);	// UTIL_SnapDirectionToAxis

//-----------------------------------------------------------------------------
// Purpose: Spawn
//-----------------------------------------------------------------------------
void CPhysTorque::vfunc103()
{
	// force spawnflags to agree with implementation of this class
	m_flags204 = (m_flags204 & ~SF_THRUST_FORCE) | SF_THRUST_TORQUE | SF_THRUST_MASS_INDEPENDENT;

	m_axis -= *(Vector *)vfunc217();	// GetAbsOrigin (CBaseEntity.h types slot 217 as float *)
	VectorNormalize(m_axis);
	sub_101cf680(&m_axis, 0.01f);
	BaseClass::sub_101c0820();	// BaseClass::Spawn
}
// END FUNCTION

// FUNCTION: 0x100282e0 size=0x75
#include "CPhysTorque.h"
#include "IPhysicsObject.h"

void sub_10138460(const Vector *pIn, const float *pMatrix, Vector *pOut);	// VectorRotate

//-----------------------------------------------------------------------------
// Purpose: SetupForces
//-----------------------------------------------------------------------------
void CPhysTorque::vfunc241(IPhysicsObject *pPhys, Vector *pLinear, Vector *pAngular)
{
	pLinear->Init();

	float matrix[12];
	pPhys->vfunc38(matrix);

	Vector axis_ws;
	sub_10138460(&m_axis, matrix, &axis_ws);

	*pAngular = axis_ws * m_force;
}
// END FUNCTION

// FUNCTION: 0x10029b80 size=0x1e
#include "CPhysTorque.h"

void sub_100aa7b0(void *p);

//-----------------------------------------------------------------------------
// CPhysTorque scalar deleting destructor
//-----------------------------------------------------------------------------
CBaseEntity *CPhysTorque::vfunc5(unsigned int flags)
{
	sub_10014470();
	if (flags & 1)
		sub_100aa7b0(this);
	return this;
}
// END FUNCTION
