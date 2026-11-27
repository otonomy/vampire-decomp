// CHudInfo: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CHudInfo : public CManagedHudElement
{
public:
	virtual ~CHudInfo();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CHudInfo's own function
	virtual void vfunc98();
	virtual bool vfunc107();
	CHudInfo(int a);
	struct IFontLike { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int GetFont(const char *); };
	IFontLike *sub_101ac830();
	int m_unk174; int m_unk178; int m_unk17c; union { int m_n180; float m_flPos; }; int m_unk184; int m_unk188; int m_unk18c; int m_unk190; int m_unk194;
	int m_arr198[0x60];
	int m_unk318; int m_unk31c; int m_nFont;
};
