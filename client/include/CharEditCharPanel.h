// CharEditCharPanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, its operator delete, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include <stdlib.h>
#include "vgui2__PropertyPage.h"

class CharEditCharPanel : public vgui2::PropertyPage
{
public:
	virtual ~CharEditCharPanel();
	static void operator delete(void *pMem) { free(pMem); }
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CharEditCharPanel's own function
	virtual void vfunc3();
	virtual int vfunc21(int);
	virtual void vfunc78(int);
	virtual void vfunc87(int);
	virtual void vfunc98();
	virtual void vfunc101();
	virtual int vfunc102();
	virtual void vfunc119();
	// the slots CharEditCharPanel adds to its base's vtable: 123-124, vfuncK at slot K
	virtual void vfunc123();
	virtual void vfunc124();
	void sub_10176f80();
	void sub_101744c0(int);
	void sub_10177000();
	void sub_101766e0();
	void sub_10177a20();
	void sub_10177080(struct CharEditCtrl_10177080 *ctrl, int y, const char *title, int count, int first, const char *(*getstr)(int), int (*getdata)(int), bool (*filter)(int), int sel);
};
