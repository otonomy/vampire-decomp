// CViewRender: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "IViewRender.h"
#include "QAngle.h"
#include "Vector.h"

class CViewRender : public IViewRender
{
public:
    void sub_1019ac50(bool, int, int);
    bool sub_1019f140(int arg);
    void sub_1019e530(int, int, float, float, int, int, int, int);
    void sub_1019af80(bool, int);
    void sub_10190850();
    float sub_101907a0(const QAngle &, const Vector &, float, float);
    void sub_1019c970();
    void sub_1019d8f0(const char *view);
    void sub_1019a950(int, void *, void *, int, int);
	void sub_1019add0(int, int, int);
	void sub_1019ab90(bool, int, int, int);
    void sub_10191710();
    void sub_10190390();
    void sub_1019a560(int unused);	// "CViewRender::DrawObfuscatedEntities": draws the obfuscated model (+0x404) of each entity in the handle list at +0x464 with the local player's blend, then purges the list
    void CopyViewModelInfoToEntities();
    int sub_1018fab0();
    int sub_1018fb10();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with CViewRender's own function
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void *vfunc6(int);
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual int vfunc10(class C_BaseEntity *pEntity);
    virtual char * vfunc11();
    virtual char * vfunc12();
    virtual bool vfunc13();
    virtual void *vfunc14();
    virtual void vfunc15(const class Vector &);
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual int vfunc20();
    virtual int vfunc21();
    virtual int vfunc22();
    virtual int vfunc23();
    virtual int vfunc24();
    virtual int vfunc25();
    virtual int vfunc26();
    virtual int vfunc27();
    virtual int vfunc28();
    virtual int vfunc29();
    virtual int vfunc30();
    virtual int vfunc31();
    virtual int vfunc32();
    virtual int vfunc33();
    virtual int vfunc34();
    virtual int vfunc35();
    virtual int vfunc36();
    virtual int vfunc37();
    virtual int vfunc38();
    virtual void vfunc39();
    virtual bool vfunc40(Vector *pOut1, Vector *pOut2, float *pOut3);
    virtual void vfunc41();
    virtual void vfunc42();
    virtual bool vfunc43();
    // the slots CViewRender adds to its base's vtable: 44-45, vfuncK at slot K
    virtual void vfunc44();
    virtual float vfunc45();
    CViewRender *sub_1018e9b0(unsigned flags);
    CViewRender *sub_10198a90();	// the constructor ("CViewRender::CViewRender" scope trace), written as a plain member
    void sub_1019aed0(bool, int);	// provisional, like sub_1019af80 (transplant)
};
