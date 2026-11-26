// C_BaseCombatCharacter: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseFlex.h"

class C_BaseCombatCharacter : public C_BaseFlex
{
public:
	C_BaseCombatCharacter();
	virtual ~C_BaseCombatCharacter();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_BaseCombatCharacter's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual int vfunc17();
	virtual void vfunc121();
	virtual void vfunc127(const Vector &origin, const QAngle &angles, int event, const char *options);
	virtual void vfunc130();
	virtual int vfunc143();
	// the slots C_BaseCombatCharacter adds to its base's vtable: 146-148, vfuncK at slot K
	virtual void vfunc146(int a, int b, int c, int d);
	virtual bool vfunc147(class C_BaseCombatWeapon *pWeapon, int);
	virtual void *vfunc148();
};
