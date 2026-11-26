// CLoadingDiscPanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Panel.h"

class CLoadingDiscPanel : public vgui2::Panel
{
public:
	CLoadingDiscPanel(vgui2::Panel *parent);
	virtual ~CLoadingDiscPanel();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CLoadingDiscPanel's own function
	virtual void vfunc98();
};
