// CPhysTorque (RTTI CPhysTorque : CPhysForce, vtable 0x10445974), "phys_torque" (0x4a8 bytes): a torque about a
// fixed axis. The 2004 SDK's dlls/phys_controller.cpp class.
#pragma once

#include "CPhysForce.h"

class CPhysTorque : public CPhysForce
{
public:
	// DECLARE_CLASS( CPhysTorque, CPointEntity ): Spawn's BaseClass::Spawn() is CPointEntity's (0x101c0820), not
	// CPhysForce's, and the datamap's baseMap is CBaseEntity's
	typedef CPointEntity BaseClass;

	virtual CBaseEntity *vfunc5(unsigned int flags);	// slot 5: the scalar deleting destructor
	virtual datamap_t *vfunc82();	// slot 82 GetDataDescMap: &m_DataMap
	virtual void vfunc103();	// slot 103 Spawn
	virtual void vfunc241(IPhysicsObject *pPhys, Vector *pLinear, Vector *pAngular);	// slot 241 SetupForces: no linear part; the axis in world space (the object's slot 38 matrix) times the force

	static datamap_t m_DataMap;	// 0x10537098 (DECLARE_DATADESC)

	Vector m_axis;	// 0x49c: m_axis (key "axis"): a point on the axis in the map, the unit axis after Spawn
};
