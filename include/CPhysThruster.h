// CPhysThruster (RTTI CPhysThruster : CPhysForce, vtable 0x104454dc), "phys_thruster" (0x4a8 bytes): a force
// along the entity's forward direction, applied at its position relative to the attached entity. The 2004 SDK's
// dlls/phys_controller.cpp class. Its datamap's baseMap is CBaseEntity's, not CPhysForce's; guess: its
// DECLARE_CLASS named CPointEntity as the base, as CPhysTorque's evidently does (see CPhysTorque.h).
#pragma once

#include "CPhysForce.h"

class CPhysThruster : public CPhysForce
{
public:
	virtual CBaseEntity *vfunc5(unsigned int flags);	// slot 5: the scalar deleting destructor
	virtual datamap_t *vfunc82();	// slot 82 GetDataDescMap: &m_DataMap
	virtual void vfunc241(IPhysicsObject *pPhys, Vector *pLinear, Vector *pAngular);	// slot 241 SetupForces: the force direction (forward vector of slot 221's angles) scaled by the force (+0x458), by the object's mass with SF_THRUST_MASS_INDEPENDENT; rotated into the attached entity's frame; the object's slot 33 turns it into the linear and angular parts, which SF_THRUST_LOCAL_ORIENTATION (back to world space), SF_THRUST_FORCE / SF_THRUST_TORQUE (keep linear / angular) refine
	virtual void vfunc242();	// slot 242 OnActivate: with the attached entity alive, the thruster's offset (+0x49c) is vec3_origin with SF_THRUST_IGNORE_POS, else this entity's absolute origin minus the attached entity's

	static datamap_t m_DataMap;	// 0x10537024 (DECLARE_DATADESC)

	Vector m_localOrigin;	// 0x49c: m_localOrigin, the thrust position relative to the attached entity
};
