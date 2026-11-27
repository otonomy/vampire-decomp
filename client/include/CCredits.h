// CCredits: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CCredits : public CManagedHudElement
{
public:
	CCredits(int a);
	virtual ~CCredits();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CCredits's own function
	virtual void vfunc97();
	virtual void vfunc98();
	virtual bool vfunc107();
	virtual void vfunc112();
	virtual void vfunc113();
	// the slots CCredits adds to its base's vtable: 114-115, vfuncK at slot K
	bool sub_1004e220(const char *);
	virtual void vfunc114(const char *);
	virtual void vfunc115();
	int m_unk174; int m_unk178; int m_unk17c; int m_unk180; int m_unk184; int m_unk188; float m_flStartTime;
	void *m_pMem; int m_allocCount; int m_growSize; int m_size; void *m_pElements;
	int m_unk1a4; int m_unk1a8; int m_unk1ac; int m_unk1b0; int m_unk1b4; int m_unk1b8; int m_unk1bc; int m_unk1c0;
};
