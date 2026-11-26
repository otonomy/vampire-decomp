// CProgBar: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CProgBar : public CManagedHudElement
{
public:
	CProgBar(int a);
	virtual ~CProgBar();
	void sub_1005fcb0();
	bool sub_1005fcf0();
	void sub_1005fe40(int a, int b, int c);
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CProgBar's own function
	virtual void vfunc98();
	virtual bool vfunc107();
	virtual void vfunc112();
	int m_unk174;
	union { int m_n178; float m_fl178; };	// 0x178: alpha 0..255
	char m_b17c;
	char m_b17d;
	char m_b17e;
	char m_c17f;
	int m_n180;
	int m_n184;
	int m_n188;
	int m_n18c;
	int m_n190;
	int m_n194;
	int m_n198;
	int m_n19c;
	int m_n1a0;
	int m_n1a4;
	int m_n1a8;
	int m_n1ac;
	int m_n1b0;
	unsigned char m_b1b4;
	char m_c1b5; char m_c1b6; char m_c1b7;
	class CHUDSprite *m_pSprite1b8;
	class CHUDSprite *m_pSprite1bc;
	int m_n1c0;	// font
	const char *sub_1005fea0(int i);	// "UI_Progress_Bar" string i (a member: callers load this into ecx)
};
