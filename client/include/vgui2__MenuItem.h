// vgui2::MenuItem: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Button.h"

namespace vgui2
{
class MenuItem : public vgui2::Button
{
public:
	MenuItem(int, int, int, int, char);
	virtual ~MenuItem();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with MenuItem's own function
	virtual int vfunc74(int);
	virtual void vfunc81();
	virtual void vfunc84(int, int);
	virtual void vfunc85();
	virtual void vfunc86();
	virtual void vfunc94(int);
	virtual void vfunc101();
	virtual int vfunc102();
	virtual void vfunc150();
	virtual int vfunc164(int, int, int, int);
	// the slots MenuItem adds to its base's vtable: 166-166, vfuncK at slot K
	virtual void vfunc166();
	void sub_101c7080();
	bool sub_101c74f0();
	void sub_101c7440(void *, vgui2::MenuItem *const &);
	void sub_101c71b0();
};
}
