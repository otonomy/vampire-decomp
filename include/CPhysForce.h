// CPhysForce (RTTI CPhysForce : CPointEntity, vtable 0x10445024, 243 slots): the base of the physics force
// entities, the 2004 SDK's dlls/phys_controller.cpp class. It attaches a constant force controller
// (CConstantForceController, embedded at +0x464) to the physics object of a named entity; the derived classes
// (CPhysThruster "phys_thruster", CPhysTorque "phys_torque") compute the force in slot 241 (SetupForces).
// Member names in comments are the DATADESC field names (the table filled by 0x100260a0).
#pragma once

#include "CPointEntity.h"
#include "CConstantForceController.h"	// CPhysForceVec3 and the motion record's class

class IPhysicsObject;
struct datamap_t;

// Spawnflags of the force entities (m_flags204), the SDK's SF_THRUST_* values
#define SF_THRUST_STARTACTIVE		0x0001
#define SF_THRUST_FORCE				0x0002
#define SF_THRUST_TORQUE			0x0004
#define SF_THRUST_LOCAL_ORIENTATION	0x0008
#define SF_THRUST_MASS_INDEPENDENT	0x0010
#define SF_THRUST_IGNORE_POS		0x0020

// IMotionEvent::simresult_e values the force stores in its controller's m_n4 (m_controlType)
#define SIM_LOCAL_ACCELERATION		1
#define SIM_GLOBAL_ACCELERATION		3

// The controller object whose pointer sits at +0x450 of CPhysForce (IPhysicsMotionController; class not modelled):
// its slot 1 takes the motion record.
class CPhysForceController
{
public:
	virtual void vfunc0();
	virtual void vfunc1(CConstantForceController *pMotion);	// SetEventHandler
	virtual void vfunc2(); virtual void vfunc3(); virtual void vfunc4(); virtual void vfunc5(); virtual void vfunc6();
	virtual void vfunc7();	// slot 7: run after the motion record has been rescaled by the input handler 0x10027b60
};

class CPhysForce : public CPointEntity
{
public:
	typedef CPointEntity BaseClass;	// DECLARE_CLASS( CPhysForce, CPointEntity )

	CPhysForce();	// 0x100264e0: CBaseEntity(0), handle -1 (+0x460), the motion record's vftable (+0x464), own vftable, controller null

	virtual CBaseEntity *vfunc5(unsigned int flags);	// slot 5: the scalar deleting destructor
	virtual datamap_t *vfunc82();	// slot 82 GetDataDescMap: &m_DataMap
	virtual void vfunc103();	// slot 103 Spawn: the controller's simulation type from SF_THRUST_LOCAL_ORIENTATION, ForceOn with SF_THRUST_STARTACTIVE
	virtual void vfunc113();	// slot 113 Activate: base work, finds the attached entity by name (+0x454) when its handle (+0x460) is stale, OnActivate (slot 242), and attaches the force (sub_10027960) when a controller exists
	virtual void vfunc130(int a);	// slot 130 OnRestore: base work, then the controller's slot 1 with the motion record

	// its own slots
	virtual void vfunc241(IPhysicsObject *pPhys, Vector *pLinear, Vector *pAngular) = 0;	// slot 241 SetupForces (_purecall in this vtable)
	virtual void vfunc242();	// slot 242 OnActivate: 0x10027670, empty here

	void sub_10027b60(float flScale);	// input handler body (called by the inputdata_t wrapper 0x10027890 with the float value): attaches the force when there is no controller, scales the motion record (+0x464) by flScale and runs the controller's slot 7
	void sub_10014470();	// the destructor body (stub of sub_100276c0)
	void sub_100276c0();	// 0x100276c0: vtable store, DestroySpring of the controller (env slot 40), then the CBaseEntity destructor body (stub 0x1000cb8a)
	void sub_100a0bc0();	// CBaseEntity::vfunc113 (stub 0x10001226), called directly
	void sub_100278e0();	// ForceOn: without a controller attaches the force (sub_10027960) and, with a non-zero timeout (+0x45c), sets the next think to curtime + timeout and the think function to the stub at 0x10001a9b
	void sub_10027960();	// ActivateForce: attaches the force to the physics object of the attached entity (handle at +0x460): the object's current points are stored in the motion record at +0x464, the environment (global 0x10723940, slot 39) creates the controller for it (+0x450) and the object is added to it

	static datamap_t m_DataMap;	// 0x10536e28 (DECLARE_DATADESC); its baseMap is CBaseEntity's

	void *m_pController;	// 0x450: m_pController, the motion controller (CPhysForceController)
	const char *m_nameAttach;	// 0x454: m_nameAttach (key "attach1"), the name of the entity to attach to
	float m_force;	// 0x458: m_force (key "force")
	float m_flTimeout;	// 0x45c: m_forceTime (key "forcetime")
	EHANDLE m_hAttached;	// 0x460: m_attachedObject
	CConstantForceController m_Motion;	// 0x464: m_integrator
};
