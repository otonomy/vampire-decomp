// ClientModeShared: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
#pragma once
#include "IClientMode.h"

class ClientModeShared : public IClientMode
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with ClientModeShared's own function
    virtual void vfunc1();
    virtual void vfunc2();
    virtual int vfunc8(int);
    virtual bool vfunc10();
    virtual bool vfunc11(int);
    virtual bool vfunc12(void *);
    virtual bool vfunc13();
    virtual bool vfunc14();
    virtual void vfunc15(int);
    virtual int vfunc16(int, int, const char *);
    virtual void vfunc17(int);
    virtual void vfunc18();
    virtual bool vfunc19();
    virtual int vfunc20();
    virtual void vfunc21();
    virtual void vfunc23(int);
    virtual void vfunc24(int);
    virtual void vfunc25();
    virtual bool vfunc26();
    virtual void vfunc28(int, int, int, int);
    virtual void vfunc29(int);
    virtual void vfunc30();
    virtual void vfunc31();
    virtual int vfunc33(int);
    virtual int vfunc34();
    virtual void vfunc35();
};
