// vgui2::PropertySheet: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Panel.h"

namespace vgui2
{
class PropertySheet : public vgui2::Panel
{
public:
	virtual ~PropertySheet();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with PropertySheet's own function
	virtual int vfunc15(int);
	virtual int vfunc72(int);
	virtual void vfunc101();
	virtual int vfunc102();
	// the slots PropertySheet adds to its base's vtable: 107-129, vfuncK at slot K
	virtual void vfunc107(vgui2::Panel *page, const char *title, int);	// AddPage
	virtual void vfunc108(int);
	virtual int vfunc109(int);
	virtual int vfunc110(int);
	virtual void vfunc111(const char *, int, char);
	virtual int vfunc112();
	virtual void vfunc113();
	virtual void vfunc114();
	virtual void vfunc115();
	virtual void vfunc116();
	virtual void vfunc117();
	virtual void vfunc118();
	virtual int vfunc119();
	virtual int vfunc120();
	virtual void vfunc121();
	virtual void vfunc122();
	virtual int vfunc123();
	virtual int vfunc124(int);
	virtual int vfunc125(int);
	virtual void vfunc126(int);
	virtual void vfunc127(int);
	virtual int vfunc128();
	virtual void vfunc129(const char *, int);
	virtual void vfunc92(int);
};
}
