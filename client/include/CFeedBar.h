// CFeedBar: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CFeedBarOwned { public: virtual ~CFeedBarOwned(); };

class CFeedBar : public CManagedHudElement
{
public:
	virtual ~CFeedBar();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CFeedBar's own function
	virtual void vfunc97();
	virtual void vfunc98();
	virtual bool vfunc107();
	virtual void vfunc112();
	virtual void vfunc113();
	// the slots CFeedBar adds to its base's vtable: 114-114, vfuncK at slot K
	virtual void vfunc114(int, int);
	CFeedBar(int a);
	void sub_100503d0(int a, int b);
	void sub_10050530();
	void sub_10050270();
	void sub_101a9890(int a, int b);
	void sub_101a98f0(int a, int b);
	void sub_101a98c0(int *, int *);
	int m_unk174; int m_unk178; int m_unk17c; int m_unk180; int m_unk184; int m_unk188; int m_unk18c; int m_unk190; int m_unk194; int m_unk198; int m_unk19c; int m_unk1a0; char m_b1a4; char m_b1a5; char m_b1a6; char m_b1a7; int m_unk1a8; int m_unk1ac; float m_fl1b0; float m_fl1b4;
	CFeedBarOwned *m_pChild1; CFeedBarOwned *m_pChild2;
};
