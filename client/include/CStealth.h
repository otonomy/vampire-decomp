// CStealth: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CStealthChild { public: virtual ~CStealthChild(); };

class CStealth : public CManagedHudElement
{
public:
	virtual ~CStealth();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CStealth's own function
	virtual void vfunc97();
	virtual void vfunc98();
	virtual bool vfunc107();
	void sub_10062610();
	void sub_10063210();
	char m_pad0008[0x178 - 0x174];
	int m_n178;
	int m_n17c;
	char m_pad0180[0x1b0 - 0x180];
	CStealthChild *m_p1b0;
	CStealthChild *m_arr1b4[5];
	CStealthChild *m_p1c8;
	int m_unk1cc;
	CStealthChild *m_p1d0;
	CStealthChild *m_p1d4;
	CStealthChild *m_p1d8;
	CStealthChild *m_p1dc;
	CStealthChild *m_p1e0;
	CStealthChild *m_p1e4;
	CStealthChild *m_arr1e8[4];
	int m_unk1f8;
	CStealthChild *m_p1fc;
	CStealthChild *m_p200;
	CStealthChild *m_p204;
};
