// C_WeaponRanged_FlameThrower: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
#pragma once
#include "C_BaseCombatWeapon.h"

class C_WeaponRanged_FlameThrower : public C_BaseCombatWeapon
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	C_WeaponRanged_FlameThrower();
    // the base slots the game's vtable fills with C_WeaponRanged_FlameThrower's own function
    virtual int vfunc15();
    virtual int vfunc16();
    virtual int vfunc17();
    virtual bool vfunc116(int, int);
    virtual void vfunc118(int);
    virtual void vfunc143();
    char m_pad0014[0x978 - 0x14];
    int m_a978[0x2ee];
    int m_i1530;
    int m_i1534;
    char m_pad1538[0x156c - 0x1538];
    int m_i156c;
    int m_i1570;
    int m_i1574;
    char m_pad1578[0x157c - 0x1578];
    float m_f157c;
    char m_pad1580[0x15a0 - 0x1580];
    int m_iList[50];
    int m_i1668;
    int m_i166c;
};
