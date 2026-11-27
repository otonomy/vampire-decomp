// CBloodBar: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CBloodBarChild { public: virtual ~CBloodBarChild(); };
class CBloodBar : public CManagedHudElement
{
public:
	CBloodBar(int a);
	virtual ~CBloodBar();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CBloodBar's own function
	virtual void vfunc97();
	virtual void vfunc98();
	virtual bool vfunc107();
	virtual void vfunc112();
	// the slots CBloodBar adds to its base's vtable: 114-115, vfuncK at slot K
	virtual int vfunc114(int);
	virtual int vfunc115(int);
	char m_pad0174[0x178 - 0x174];
	int m_n178;
	int m_n17c;
	int m_n180;
	int m_n184;
	int m_n188;
	int m_n18c;
	char m_pad0190[0x1a4 - 0x190];
	void sub_1004c780();
	CBloodBarChild *m_p1a4;
	int m_unk1a8;
	CBloodBarChild *m_p1ac;
	CBloodBarChild *m_p1b0;
	CBloodBarChild *m_p1b4;
	CBloodBarChild *m_p1b8;
	CBloodBarChild *m_p1bc;
	CBloodBarChild *m_p1c0;
	CBloodBarChild *m_p1c4;
	CBloodBarChild *m_p1c8;
	char m_pad01cc[0x1d4 - 0x1cc];
	float m_flTime1d4;
	char m_pad01d8[0x1dc - 0x1d8];
	void sub_1004d460();
};
