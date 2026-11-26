// CHudTimerUI: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

struct CIntM1 { int v; CIntM1() { v = -1; } };

class CHudTimerUI : public CManagedHudElement
{
public:
	virtual ~CHudTimerUI();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CHudTimerUI's own function
	virtual void vfunc98();
	virtual bool vfunc107();
	// the slots CHudTimerUI adds to its base's vtable: 114-114, vfuncK at slot K
	virtual void vfunc114(int, int, int);
	CHudTimerUI(int parent);
	void sub_1005db50();
	int m_unk174; int m_unk178; int m_unk17c; int m_unk180; int m_unk184; float m_unk188; char m_unk18c; char m_unk18d; char m_unk18e; char m_unk18f; float m_unk190; CIntM1 m_unk194; int m_unk198; int m_unk19c;
};
