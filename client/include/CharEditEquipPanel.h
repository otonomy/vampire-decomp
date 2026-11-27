// CharEditEquipPanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__PropertyPage.h"

class CharEditEquipPanel : public vgui2::PropertyPage
{
public:
	virtual ~CharEditEquipPanel();
	void sub_10179850();
	void sub_10179c40();
	void sub_10178a50();
	void sub_1017a7f0();
	void sub_10179e40();	// "LastArmor"
	void sub_10179fe0();	// "NextArmor"
	void sub_1017a5c0();
	void sub_1017a630();	// "cancel"
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CharEditEquipPanel's own function
	virtual void vfunc3();
	virtual int vfunc21(int);
	virtual void vfunc78(int);
	virtual void vfunc98();
	virtual int vfunc102();
	virtual void vfunc119();
	// the slots CharEditEquipPanel adds to its base's vtable: 123-124, vfuncK at slot K
	virtual void vfunc123();
	virtual void vfunc124(int);
	char m_pad0004[0xec - 0x4];
};
