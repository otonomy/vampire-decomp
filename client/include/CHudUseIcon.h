// CHudUseIcon: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CHudUseIconOwned { public: virtual ~CHudUseIconOwned(); };

class CHudUseIcon : public CManagedHudElement
{
public:
	virtual ~CHudUseIcon();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CHudUseIcon's own function
	virtual void vfunc98();
	virtual bool vfunc107();
	int m_unk174;
	CHudUseIconOwned *m_pChild1; CHudUseIconOwned *m_pChild2; CHudUseIconOwned *m_pChild3;
	int m_unk184; int m_unk188;
	CHudUseIconOwned *m_pChild4; CHudUseIconOwned *m_pChild5;
	CHudUseIcon(int parent);
	void sub_1005e1a0();
	const char *sub_1005e400(int);
	void sub_1005e4a0(bool);
	void sub_101a9890(int, int);
	void sub_101a98f0(int, int);
	int m_unk194; int m_unk198; int m_unk19c; int m_unk1a0; int m_unk1a4; float m_f1a8; char m_b1ac; char m_b1ad; char m_b1ae; char m_b1af; int m_unk1b0; int m_unk1b4; int m_unk1b8; int m_unk1bc;
	int m_unk1c0; int m_unk1c4; char m_pad1c8; char m_arr1c9[0x40];
	char m_pad209[0x20c - 0x209]; int m_unk20c; int m_unk210; int m_unk214;
};
