// CHudAreaIcon: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CHudAreaIconObj { public: virtual ~CHudAreaIconObj(); };
class CHudAreaIcon : public CManagedHudElement
{
public:
	CHudAreaIcon(int a);
	void sub_100527c0();
	int sub_100ca9c0();
	bool sub_10163bf0();
	virtual ~CHudAreaIcon();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CHudAreaIcon's own function
	virtual void vfunc98();
	virtual bool vfunc107();
	// the slots CHudAreaIcon adds to its base's vtable: 114-114, vfuncK at slot K
	virtual void vfunc114();
	int m_unk174;
	CHudAreaIconObj *m_p178;
	int m_unk17c; int m_unk180; int m_unk184; int m_unk188; int m_unk18c;
	bool m_b190; char m_unk191; char m_unk192; char m_unk193; float m_unk194; int m_unk198;
	CHudAreaIconObj *m_p19c;
	CHudAreaIconObj *m_p1a0;
	CHudAreaIconObj *m_p1a4;
	float m_unk1a8; float m_unk1ac; float m_unk1b0;	// floats (CHudAreaIcon::vfunc98 truncates / subtracts them)
	void sub_10051df0();
};
