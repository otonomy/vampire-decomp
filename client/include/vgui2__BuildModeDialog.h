// vgui2::BuildModeDialog: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Frame.h"

namespace vgui2
{
class KeyValues;
class BuildModeDialog : public vgui2::Frame
{
public:
	BuildModeDialog(void *pBuildGroup);
	void sub_101c3bb0();
	void sub_101c4b30();
	void sub_101c4a20();
	void sub_101c45b0(void *, const char *);
	virtual ~BuildModeDialog();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with BuildModeDialog's own function
	virtual void vfunc78(int);
	virtual void vfunc92(int);
	virtual int vfunc102();
	// the slots BuildModeDialog adds to its base's vtable: 145-148, vfuncK at slot K
	virtual void vfunc145();
	virtual void vfunc146(int);
	virtual int vfunc147();
	virtual KeyValues *vfunc148();
};
}
