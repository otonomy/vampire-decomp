// CMessageCharsPanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Panel.h"

class CMessageCharsPanel : public vgui2::Panel
{
public:
	CMessageCharsPanel(vgui2::Panel *parent);
	virtual ~CMessageCharsPanel();
	void sub_10168480();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CMessageCharsPanel's own function
	virtual void vfunc2();
	virtual bool vfunc25(int, int);
	virtual int vfunc74(int);
	virtual void vfunc98();
	// the slots CMessageCharsPanel adds to its base's vtable: 107-109, vfuncK at slot K
	virtual int vfunc107(float lifetime, int font, int x, int a4, char r, char g, char b, char a, const char *fmt, int a10, ...);
	int sub_101682b0();
	virtual void vfunc108(int, int *, int *, int);
	virtual bool vfunc109();
};
