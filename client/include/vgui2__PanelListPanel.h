// vgui2::PanelListPanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Panel.h"

namespace vgui2
{
class PanelListPanel : public vgui2::Panel
{
public:
	virtual ~PanelListPanel();
	PanelListPanel(vgui2::Panel *parent, const char *name);
	struct CMemberInit
	{
		__forceinline CMemberInit()
		{
			char *p = (char *)this - sizeof(vgui2::Panel);
			*(int *)(p + 0x58) = 0; *(int *)(p + 0x5c) = 0; *(int *)(p + 0x60) = 0;
		}
	} m_memberInit;
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with PanelListPanel's own function
	virtual int vfunc74(int);
	virtual void vfunc97();
	virtual void vfunc101();
	virtual int vfunc102();
	// the slots PanelListPanel adds to its base's vtable: 107-116, vfuncK at slot K
	virtual void vfunc107();
	virtual int vfunc108(vgui2::Panel *a, vgui2::Panel *b);
	virtual int vfunc109();
	virtual void vfunc110();
	virtual void vfunc111();
	virtual void vfunc112();
	virtual int vfunc113(int);
	virtual int vfunc114(int, int);
	virtual int vfunc115(int);
	virtual int vfunc116();
	void sub_101cab80(int itemID);
};
}
