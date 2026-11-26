// CAmmoCounter: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CAmmoCounter : public CManagedHudElement
{
public:
	virtual ~CAmmoCounter();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CAmmoCounter's own function
	virtual void vfunc97();
	virtual void vfunc98();
	virtual bool vfunc107();
	virtual void vfunc112();
	CAmmoCounter(int a);
	struct IFontLike { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int GetFont(const char *); };
	IFontLike *sub_101ac830();
	void sub_101a9890(int, int);
	void sub_101a98f0(int, int);
	void sub_1004bc40();
	void sub_1004bdd0();
	void sub_1004bde0();
	int m_unk174; int m_n178; int m_n17c; int m_n180; int m_n184;
	int m_n188; int m_n18c; int m_n190; int m_n194;
	void sub_1004c2f0(const char *pszName);
	union { int m_n198; float m_fl198; }; char m_b19c; char m_b19d; char m_b19e; char m_pad19f;
	int m_nFont;
	struct CAmmoCounterChild { virtual ~CAmmoCounterChild(); } *m_pUnk1a4;
};
