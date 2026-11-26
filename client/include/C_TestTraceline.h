// C_TestTraceline: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseEntity.h"

class C_TestTraceline : public C_BaseEntity
{
public:
	C_TestTraceline();
	virtual ~C_TestTraceline();
	void sub_100417c0(Vector &center, unsigned char *pColor);	// DrawCube: a 10 unit cube around center as six polygons of pColor
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_TestTraceline's own function
	virtual int vfunc15();
	virtual int vfunc16();
	char m_pad0014[0x418 - 0x14];
};
