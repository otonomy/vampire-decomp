// vgui2::MessageBox: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Frame.h"
#include "vgui2__Label.h"

namespace vgui2
{
class MessageBox : public vgui2::Frame
{
public:
	MessageBox(const char *, const char *, vgui2::Panel *);
	virtual ~MessageBox();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with MessageBox's own function
	virtual void vfunc101();
	virtual int vfunc102();
	virtual int vfunc130();
	// the slots MessageBox adds to its base's vtable: 145-149, vfuncK at slot K
	virtual void vfunc145();
	virtual int vfunc146(int);
	virtual int vfunc147(float);
	virtual int vfunc148(int);
	virtual int vfunc149();
};
}
