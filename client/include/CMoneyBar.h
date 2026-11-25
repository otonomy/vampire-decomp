// CMoneyBar: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CMoneyBar : public CManagedHudElement
{
public:
	virtual ~CMoneyBar();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CMoneyBar's own function
	virtual void vfunc97();
	virtual void vfunc98();
	virtual bool vfunc107();
	virtual void vfunc112();
	int m_n174;
	float m_flCur178;
	float m_flTime17c;
	char m_pad180;
	bool m_b181;
	bool m_b182;
	char m_szText183[0x1a4 - 0x183];
	int m_n1a4;
	void sub_101a98c0(int *a, int *b);
	void sub_1005f590(int a, int b, int *c);
};
