// CLabelHeader: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "vgui2__Label.h"

struct VObj5 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void d(int); };
class CLabelHeader : public vgui2::Label
{
public:
	CLabelHeader(vgui2::Panel *p, const char *n, const char *t) : vgui2::Label(p, n, t) {}
	virtual ~CLabelHeader() { VObj5 *o = *(VObj5 **)((char *)this + 0xb8); if (o) o->d(1); }
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with CLabelHeader's own function
    virtual int vfunc51(int);
    virtual int vfunc74(int);
    virtual void vfunc98();
    virtual void vfunc108(const char *);
    virtual int vfunc111(int);
    virtual void vfunc118();
    // the slots CLabelHeader adds to its base's vtable: 138-138, vfuncK at slot K
    virtual void vfunc138(int textBufferLen, const char *text);
};
