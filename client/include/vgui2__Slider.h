// vgui2::Slider: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
#pragma once
#include "vgui2__Panel.h"

namespace vgui2
{
class Slider : public vgui2::Panel
{
public:
	void *sub_101bb6e0(void *parent, const char *name);
	void sub_101bbb20();	// DrawTicks
	void sub_101bbc40();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with Slider's own function
    virtual int vfunc74(int);
    virtual void vfunc75(int);
    virtual void vfunc84(int, int);
    virtual void vfunc87(int);
    virtual void vfunc88(int);
    virtual void vfunc89(int);
    virtual void vfunc97();
    virtual void vfunc98();
    virtual void vfunc101();
    // the slots Slider adds to its base's vtable: 107-121, vfuncK at slot K
    virtual void vfunc107(int);
    virtual int vfunc108();
    virtual void vfunc109(int, int);
    virtual int vfunc110(int, int);
    virtual int vfunc111(int, int);
    virtual int vfunc112(int, int);
    virtual int vfunc113(int);
    virtual void vfunc114(const char *, const char *);
    virtual int vfunc115(int);
    virtual int vfunc116(int);
    virtual void vfunc117(const char *text);
    virtual void vfunc118();
    virtual void vfunc119();
    virtual int vfunc120();
    virtual void vfunc121(int &x, int &y, int &w, int &h);
};
}
