// vgui2::PropertyPage: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__EditablePanel.h"

namespace vgui2
{
class PropertyPage : public vgui2::EditablePanel
{
public:
	PropertyPage();
	virtual ~PropertyPage();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with PropertyPage's own function
	virtual int vfunc74(int);
	virtual int vfunc99();
	virtual int vfunc102();
	// the slots PropertyPage adds to its base's vtable: 118-122, vfuncK at slot K
	virtual void vfunc118();
	virtual void vfunc119();
	virtual void vfunc120();
	virtual void vfunc121();
	virtual int vfunc122();
};
}
