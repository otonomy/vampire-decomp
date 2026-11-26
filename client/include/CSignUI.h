// CSignUI: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CKeyValuesX;

extern "C" __declspec(dllimport) void __cdecl Plat_Free(void *);
struct SUMem {
	void *m_pMem; int m_nAlloc; int m_nGrow;
	~SUMem() { Purge(); }
	SUMem() { m_pMem = 0; m_nAlloc = 0; m_nGrow = 0; }
	void Purge() { if (m_nGrow != -1) { if (m_pMem) { Plat_Free(m_pMem); m_pMem = 0; } m_nAlloc = 0; } }
};
struct SUVec {
	SUMem m_Memory; int m_Size; void *m_pElements;
	SUVec() { m_Size = 0; m_pElements = 0; }
	~SUVec() { Purge(); }
	void Purge() { m_Size = 0; m_Memory.Purge(); m_pElements = m_Memory.m_pMem; }
};
class CSignUI : public CManagedHudElement
{
public:
	virtual ~CSignUI();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CSignUI's own function
	virtual void vfunc98();
	virtual bool vfunc107();
	// the slots CSignUI adds to its base's vtable: 114-114, vfuncK at slot K
	virtual void vfunc114(int, int, int);
	void sub_10060c30();
	void sub_10061f60(CKeyValuesX *pData);	// one "Text" block: a new CSignLabel (text, font, alignment, position, colours, image) appended to m_vecA
	const char *sub_10061c40(CKeyValuesX *pData);	// the "Font_<screen width>" key of the data, else "Font" (default "Default")
	void sub_100617b0(CKeyValuesX *pData);
	void sub_10061830(CKeyValuesX *pData);	// the "BackgroundImage" block: image name / tiled, position and size scaled from 1024 x 768 (centred when XPos and YPos are 0)
	CSignUI(int a);
	int m_unk174; int m_unk178; int m_unk17c; char m_b180; char m_b181; short m_unk182; int m_unk184; int m_unk188; float m_f18c;
	SUVec m_vecB;
	SUVec m_vecA;
	int m_nXPos;	// 0x1b8: "BackgroundImage" XPos (1024 x 768 units; 0, 0 centres it)
	int m_nYPos;	// 0x1bc
	int m_nWide;	// 0x1c0
	int m_nTall;	// 0x1c4
	char m_bHideHUD;	// 0x1c8
	char m_b1c9;
	char m_pad1ca[0x24c - 0x1ca];
};
