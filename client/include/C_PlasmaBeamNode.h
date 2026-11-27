// C_PlasmaBeamNode: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseEntity.h"
#include "Vector.h"
#include "CSmartPtr.h"
#include "CPlasmaSpray.h"

class C_PlasmaBeamNode : public C_BaseEntity
{
public:
	C_PlasmaBeamNode();
	virtual ~C_PlasmaBeamNode();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_PlasmaBeamNode's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual void vfunc37();
	virtual void OnDataChanged(int updateType);
	virtual void ClientThink();	// IClientThinkable slot 0 (this = the thinkable part, +0x10)
	char m_pad0014[0xa8 - 0x14];
	Vector m_vecVelocityA8;	// 0xa8: read directly as the SDK's GetAbsVelocity()
	char m_pad00b4[0x410 - 0xb4];
	bool m_bSprayOn;	// 0x410
	char m_c411; char m_c412; char m_c413;
	CSmartPtr<CPlasmaSpray> m_pFirePlasmaSpray;	// 0x414
};
