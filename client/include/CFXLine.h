// CFXLine: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CFXStaticLine.h"

class CFXLine : public CFXStaticLine
{
public:
	virtual ~CFXLine();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CFXLine's own function
	virtual void vfunc1(double frametime);
	virtual bool vfunc3();
	virtual void vfunc4();
	virtual void vfunc5(double dt);
};
