// vgui2::Menu: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Panel.h"

namespace vgui2
{
class MenuItem;
class Menu : public vgui2::Panel
{
public:
	void sub_101c0080(void *pExcept);
	void sub_101c0b10(int);
	void sub_101c0990(int);
	void sub_101bfc60();
	void *sub_101c0050(int);
	void sub_101c09f0(int);
	void sub_101bfd10();
	void sub_101bfe20();
	virtual ~Menu();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with Menu's own function
	virtual int vfunc21(int);
	virtual void vfunc60(void *);
	virtual int vfunc74(int);
	virtual void vfunc78(int);
	virtual void vfunc81();
	virtual void vfunc84(int, int);
	virtual void vfunc90(int);
	virtual void vfunc91(int);
	virtual void vfunc92();
	virtual void vfunc93(int);
	virtual void vfunc98();
	virtual void vfunc101();
	virtual int vfunc102();
	// the slots Menu adds to its base's vtable: 107-137, vfuncK at slot K
	virtual int vfunc107(vgui2::MenuItem *);
	virtual int vfunc108(int, int);
	virtual int vfunc109(int, int, int, int);
	virtual int vfunc110(int, int, int);
	virtual int vfunc111(int, int, int, int);
	virtual int vfunc112(int, int, int);
	virtual int vfunc113(int, int);
	virtual int vfunc114(int, int, int, int);
	virtual int vfunc115(int, int, int);
	virtual int vfunc116(int, int, int, int);
	virtual int vfunc117(int, int, int);
	virtual int vfunc118(int, int, int);
	virtual int vfunc119(int, int, int, int, int);
	virtual int vfunc120(int, int, int, int);
	virtual int vfunc121(int, int, int, int, int);
	virtual int vfunc122(int, int, int, int);
	virtual void vfunc123();
	virtual void vfunc124(const char *, int);
	virtual void vfunc125();
	virtual int vfunc126(int);
	virtual int vfunc127(int);
	virtual void vfunc128(int);
	void sub_101c0120(int);
	virtual int vfunc129();
	virtual int vfunc130(int);
	virtual int vfunc131();
	virtual void vfunc132();
	virtual int vfunc133();
	virtual int vfunc134();
	virtual int vfunc135();
	virtual void vfunc136();
	virtual void vfunc137();
};
}
