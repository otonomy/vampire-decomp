// C_World: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseEntity.h"
#include "Vector.h"

class C_World : public C_BaseEntity
{
public:
	C_World();
	virtual ~C_World();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_World's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual void vfunc19();
	virtual void vfunc21();
	virtual int vfunc66();
	char m_pad0014[0x430 - 0x14];
	float m_unk430; int m_unk434; float m_fTarget; float m_fUp; float m_fDown; float m_fCur; float m_fTime; int m_unk44c;
	void sub_100ca750();
};
