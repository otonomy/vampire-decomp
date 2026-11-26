// vgui2::EditablePanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Panel.h"

namespace vgui2
{
class EditablePanel : public vgui2::Panel
{
public:
	EditablePanel(vgui2::Panel *parent, const char *name);
	virtual ~EditablePanel();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with EditablePanel's own function
	virtual void vfunc10(int);
	virtual void vfunc11(int, int);
	virtual void vfunc14();
	virtual int vfunc15(int);
	virtual int vfunc17();
	virtual void vfunc58(int);
	virtual void vfunc59(int);
	virtual int vfunc72(int);
	virtual void vfunc75(int);
	virtual void vfunc80();
	virtual void vfunc97();
	virtual int vfunc102();
	virtual void vfunc105(Panel *);
	// the slots EditablePanel adds to its base's vtable: 107-117, vfuncK at slot K
	virtual void vfunc107();
	void sub_101b4d70(int);
	virtual int vfunc108();
	virtual int vfunc109();
	virtual void vfunc110();
	vgui2::Panel *sub_101b5230(vgui2::Panel *, const char *);
	virtual void vfunc111(int, int);
	virtual void vfunc112(int, int);
	virtual int vfunc113(int, int);
	virtual void vfunc114(const char *, char *, int, const char *);
	virtual int vfunc115(int, int);
	virtual char * vfunc116();
	virtual void vfunc117();
};
}
