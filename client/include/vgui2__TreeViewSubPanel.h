// vgui2::TreeViewSubPanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
#pragma once
#include "vgui2__Panel.h"

namespace vgui2
{
class TreeViewSubPanel : public vgui2::Panel
{
public:
	TreeViewSubPanel(Panel *parent) : Panel(parent) {}
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with TreeViewSubPanel's own function
    virtual int vfunc74(int);
    virtual void vfunc88(int);
    virtual void vfunc90(int);
};
}
