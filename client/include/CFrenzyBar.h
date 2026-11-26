// CFrenzyBar: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CFrenzyBarOwned { public: virtual ~CFrenzyBarOwned(); };

class CFrenzyBar : public CManagedHudElement
{
public:
	virtual ~CFrenzyBar();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CFrenzyBar's own function
	virtual void vfunc97();
	virtual void vfunc98();
	virtual bool vfunc107();
	virtual void vfunc112();
	virtual void vfunc113();
	// the slots CFrenzyBar adds to its base's vtable: 114-114, vfuncK at slot K
	virtual void vfunc114();
	CFrenzyBar(int parent);
	void sub_10050af0();
	void sub_101a98c0(int *, int *);
	void sub_10050ba0(int, int);
	void sub_101a9890(int, int);
	void sub_101a98f0(int, int);
	int m_unk174; int m_unk178; int m_unk17c; int m_unk180; int m_unk184; int m_unk188; int m_unk18c; int m_unk190; char m_unk194; char m_unk195; char m_unk196; char m_unk197; int m_unk198; float m_unk19c;
	CFrenzyBarOwned *m_pChild1; CFrenzyBarOwned *m_pChild2;
};
