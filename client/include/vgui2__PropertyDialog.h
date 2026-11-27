// vgui2::PropertyDialog: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Frame.h"

namespace vgui2
{
class PropertyDialog : public vgui2::Frame
{
public:
	PropertyDialog(vgui2::Panel *parent, const char *name);
	virtual ~PropertyDialog();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with PropertyDialog's own function
	virtual void vfunc78(int);
	virtual void vfunc92();
	virtual void vfunc101();
	virtual int vfunc108();
	// the slots PropertyDialog adds to its base's vtable: 145-155, vfuncK at slot K
	virtual int vfunc145();
	virtual int vfunc146(int, int);
	virtual int vfunc147();
	virtual int vfunc148();
	virtual int vfunc149(float);
	virtual int vfunc150(float);
	virtual int vfunc151();
	virtual int vfunc152();
	virtual int vfunc153(int, int, float);
	virtual int vfunc154(int);
	virtual int vfunc155();
};
}
