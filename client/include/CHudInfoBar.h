// CHudInfoBar: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

struct CZ { int v; CZ() { v = 0; } };
class CHUDSprite;

class CHudInfoBar : public CManagedHudElement
{
public:
	virtual ~CHudInfoBar();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CHudInfoBar's own function
	virtual void vfunc98();
	virtual bool vfunc107();
	virtual void vfunc112();
	virtual void vfunc113();
	// the slots CHudInfoBar adds to its base's vtable: 114-116, vfuncK at slot K
	virtual int vfunc114(int, int, int);
	virtual int vfunc115(int, int);
	virtual int vfunc116(int, int);
	CHudInfoBar(int parent);
	void sub_100565b0();
	CHUDSprite *sub_10056460(int);
	void sub_10056860();
	void sub_10056f30(int);
	void sub_10056fd0(void *, int, int, const char *, int);
	int sub_10056bc0(int, int, const char *);
	int m_unk174; char m_unk178; char m_unk179; char m_unk17a; char m_unk17b; float m_unk17c; float m_unk180; int m_unk184; int m_unk188; int m_unk18c; int m_unk190; int m_unk194; int m_unk198; int m_unk19c; float m_unk1a0; int m_unk1a4; int m_unk1a8; CZ m_unk1ac; CZ m_unk1b0; CZ m_unk1b4; CZ m_unk1b8; CZ m_unk1bc; CZ m_unk1c0; CZ m_unk1c4; CZ m_unk1c8; CZ m_unk1cc; CZ m_unk1d0;
};
