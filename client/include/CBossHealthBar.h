// CBossHealthBar: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"
#include "CHUDSprite.h"

class CBossHealthBarOwned { public: virtual ~CBossHealthBarOwned(); };

class CBossHealthBar : public CManagedHudElement
{
public:
	virtual ~CBossHealthBar();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CBossHealthBar's own function
	virtual void vfunc97();
	virtual void vfunc98();
	virtual bool vfunc107();
	virtual void vfunc112();
	virtual void vfunc113();
	// the slots CBossHealthBar adds to its base's vtable: 114-114, vfuncK at slot K
	virtual void vfunc114();
	CBossHealthBar(int a);
	struct IFontLike { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int GetFont(const char *); };
	IFontLike *sub_101ac830();
	void sub_101a9890(int, int);
	void sub_101a98f0(int, int);
	void sub_1004d610();
	void sub_1004d710(int, int, int, int);
	void sub_1004d850();
	void sub_101a98c0(int *, int *);
	int m_unk174; int m_unk178; int m_unk17c; int m_unk180; int m_unk184; int m_unk188; int m_unk18c; int m_unk190; int m_unk194; char m_b198; char m_b199; char m_b19a; char m_b19b; int m_nFont; int m_unk1a0; int m_unk1a4[2]; const char *m_unk1ac[2]; int m_unk1b4; int m_unk1b8; int m_unk1bc;
	CHUDSprite *m_pChild1; CHUDSprite *m_pChild2;
};
