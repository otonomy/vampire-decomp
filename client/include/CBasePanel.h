// CBasePanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Panel.h"

class CBasePanel : public vgui2::Panel
{
public:
	CBasePanel(int a, int b);
	virtual ~CBasePanel();
	void sub_101aa230(void *);
	void sub_10187a90(int);
	void sub_10186970(int);
	void sub_101ab3d0(const char *name);
	void sub_10175da0(const char *name);
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CBasePanel's own function
	virtual void vfunc2();
	virtual void vfunc84(int, int);
	virtual void vfunc87(int);
	virtual void vfunc88(int);
	virtual void vfunc89(int);
	virtual void vfunc90(int);
	virtual void vfunc97();
	// the slots CBasePanel adds to its base's vtable: 107-111, vfuncK at slot K
	virtual bool vfunc107();
	virtual void vfunc108(const char *name, char b);
	virtual void vfunc109(float);
	virtual void vfunc110();
	virtual void vfunc111(int);
};
