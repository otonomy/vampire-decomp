// CPrediction: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
#pragma once
#include "IPrediction.h"

class CPrediction : public IPrediction
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with CPrediction's own function
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual int vfunc7();
    virtual void vfunc8(class Vector *);
    virtual void vfunc9(int);
    virtual void vfunc10(class Vector *);
    virtual void vfunc11(const class Vector *v);
    virtual bool vfunc12();
    virtual int vfunc13();
    virtual bool vfunc14();
    virtual int vfunc15();
    // the slots CPrediction adds to its base's vtable: 16-19, vfuncK at slot K
    virtual void vfunc16(class C_BasePlayer *player, struct CUserCmdView *ucmd, void *pHelper, struct CMoveDataView *move);
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19(const class Vector &origin, const class QAngle &angles, const class Vector &viewofs);
	void sub_10120ee0(int commands_acknowledged);
};
