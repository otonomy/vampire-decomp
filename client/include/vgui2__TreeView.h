// vgui2::TreeView: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Panel.h"

namespace vgui2
{
class TreeView : public vgui2::Panel
{
public:
	virtual ~TreeView();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with TreeView's own function
	virtual void vfunc11(int, int);
	virtual int vfunc74(int);
	virtual void vfunc90(int);
	virtual void vfunc101();
	virtual int vfunc102();
	// the slots TreeView adds to its base's vtable: 107-122, vfuncK at slot K
	virtual int vfunc107(void *data, int parentItemIndex);	// AddItem
	virtual int vfunc108();
	virtual void vfunc109();
	virtual int vfunc110();
	virtual void vfunc111(int, bool);
	virtual void vfunc112();
	virtual bool vfunc113(int, int);
	virtual void vfunc114(int);
	virtual void vfunc115(int, char);
	virtual void vfunc116(int);
	virtual int vfunc117();
	virtual int vfunc118(int);
	virtual int vfunc119();
	virtual void vfunc120(int, bool);
	virtual void vfunc121(int);
	virtual int vfunc122();
};
}
