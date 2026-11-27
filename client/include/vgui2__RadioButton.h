// vgui2::RadioButton: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__ToggleButton.h"

namespace vgui2
{
class RadioButton : public vgui2::ToggleButton
{
public:
	virtual ~RadioButton();
	RadioButton *sub_101c62f0(int direction);
	void sub_101c6220(int code);
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with RadioButton's own function
	virtual int vfunc74(int);
	virtual void vfunc75(int);
	virtual int vfunc76(int);
	virtual int vfunc77();
	virtual void vfunc87(int);
	virtual void vfunc91(int);
	virtual void vfunc92();
	virtual void vfunc94(int);
	virtual void vfunc98();
	virtual void vfunc101();
	virtual int vfunc102();
	virtual void vfunc143(char);
	virtual int vfunc164(int, int, int, int);
	// the slots RadioButton adds to its base's vtable: 166-169, vfuncK at slot K
	virtual int vfunc166();
	virtual int vfunc167(int);
	virtual int vfunc168();
	virtual void vfunc169(int, int);
};
}
