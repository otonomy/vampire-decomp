// CTargeted: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CTargeted : public CManagedHudElement
{
public:
	virtual ~CTargeted();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CTargeted's own function
	virtual void vfunc97();
	virtual void vfunc98();
	virtual bool vfunc107();
	virtual void vfunc112();
	CTargeted(int a);
	struct IFontLike { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int GetFont(const char *); };
	IFontLike *sub_101ac830();
	void sub_101a9890(int, int);
	void sub_101a98f0(int, int);
	void sub_10063a70();
	void sub_10063d40();
	int m_unk174; int m_n178; int m_n17c; int m_n180; int m_n184;
	int m_n188; int m_n18c; int m_n190; int m_n194; int m_n198; int m_n19c; int m_n1a0; int m_pad1a4;
	int m_nFont1a8; int m_nFont1ac; int m_nFont1b0;
	struct CTgtObj *m_p1b4; struct CTgtObj *m_p1b8; struct CTgtObj *m_p1bc; struct CTgtObj *m_p1c0; struct CTgtObj *m_p1c4; struct CTgtObj *m_p1c8; struct CTgtObj *m_p1cc;
	int m_n1d0; int m_pad1d4; int m_n1d8; int m_n1dc;
	char m_pad01e0[0x220 - 0x1e0];
	struct CTgtObj *m_p220;
};
