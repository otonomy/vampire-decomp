// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "vampire.h"

// FUNCTION: 0x10026040 size=0x6
#include "CPhysForce.h"

//-----------------------------------------------------------------------------
// CPhysForce::GetDataDescMap
//-----------------------------------------------------------------------------
datamap_t *CPhysForce::vfunc82()
{
	return &m_DataMap;
}
// END FUNCTION

// FUNCTION: 0x100264e0 size=0x32
#include "CPhysForce.h"

//-----------------------------------------------------------------------------
// CPhysForce::CPhysForce
//-----------------------------------------------------------------------------
CPhysForce::CPhysForce()
{
	m_pController = 0;
}
// END FUNCTION

// FUNCTION: 0x10027670 size=0x1
#include "CPhysForce.h"

//-----------------------------------------------------------------------------
// Purpose: OnActivate: the derived classes set up here before the force is switched on
//-----------------------------------------------------------------------------
void CPhysForce::vfunc242()
{
}
// END FUNCTION

// FUNCTION: 0x10027690 size=0x1e
#include "CPhysForce.h"

void sub_100aa7b0(void *p);

//-----------------------------------------------------------------------------
// CPhysForce scalar deleting destructor
//-----------------------------------------------------------------------------
CBaseEntity *CPhysForce::vfunc5(unsigned int flags)
{
	sub_10014470();
	if (flags & 1)
		sub_100aa7b0(this);
	return this;
}
// END FUNCTION

// FUNCTION: 0x10027700 size=0x2a
#include "CPhysForce.h"

//-----------------------------------------------------------------------------
// Purpose: Spawn
//-----------------------------------------------------------------------------
void CPhysForce::vfunc103()
{
	if (m_flags204 & SF_THRUST_LOCAL_ORIENTATION)
	{
		m_Motion.m_n4 = SIM_LOCAL_ACCELERATION;
	}
	else
	{
		m_Motion.m_n4 = SIM_GLOBAL_ACCELERATION;
	}

	if (m_flags204 & SF_THRUST_STARTACTIVE)
	{
		sub_100278e0();
	}
}
// END FUNCTION

// FUNCTION: 0x10027740 size=0x27
#include "CPhysForce.h"

//-----------------------------------------------------------------------------
// Purpose: OnRestore: hook the restored controller back up to the motion record
//-----------------------------------------------------------------------------
void CPhysForce::vfunc130(int a)
{
	BaseClass::vfunc130(a);
	if (m_pController)
		((CPhysForceController *)m_pController)->vfunc1(&m_Motion);
}
// END FUNCTION

// FUNCTION: 0x10027780 size=0x92
#include "CPhysForce.h"
#include "CGlobalEntityList.h"

extern CGlobalEntityList g_106eb5d8;	// gEntList

//-----------------------------------------------------------------------------
// Purpose: Activate
//-----------------------------------------------------------------------------
void CPhysForce::vfunc113()
{
	BaseClass::vfunc113();

	if (!m_hAttached)
	{
		m_hAttached = g_106eb5d8.sub_100f7770(0, m_nameAttach ? m_nameAttach : "", 0, 0);
	}

	// Let the derived class set up before we throw the switch
	vfunc242();

	if (m_pController)
	{
		sub_10027960();
	}
}
// END FUNCTION
