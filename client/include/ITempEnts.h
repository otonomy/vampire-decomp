// ITempEnts: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
#pragma once

class Vector;
class QAngle;

class ITempEnts
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots ITempEnts adds to its base's vtable: 0-19, vfuncK at slot K
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4(const void *, int, int, int, int, int, float, float);
    virtual void vfunc5();
    virtual int vfunc6(int, int, int, int, char, int, int, int, int);
    virtual void vfunc7();
    virtual void vfunc8(const Vector &mins, const Vector &maxs, float height, int modelIndex, int count, float speed);	// Bubbles
    virtual void vfunc9();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17(int, int, int, int, int, int);
    virtual void vfunc18(class C_LocalTempEntity *pTemp, float damp);	// PlaySound: the bounce sound of a temp entity
    virtual void vfunc19(const Vector &, const QAngle &, const QAngle &, int, const Vector &);
};
