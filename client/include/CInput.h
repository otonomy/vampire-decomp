// CInput: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "IInput.h"

class CInput : public IInput
{
public:
    void sub_10106880(int);
    void sub_10106560(float *, float *, int, int);
    void sub_10106860(int *, int *);
    void sub_10101df0();
    void sub_10102800(struct Vector *);
    void sub_101025f0(float, struct Vector &);
    void sub_101003b0();
    void sub_10101d10(const char *, int);
    void sub_101068a0(int);
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    int m_unk20;
    int m_unk24;
    void *m_unk28;
    int m_unk2c[(0x54 - 0x2c) / 4];
    int sub_10100f10();
    int m_unk54;
    int m_unk58;
    int m_unk5c;
    int m_unk60;
    int m_unk64[(0xdc - 0x64) / 4];
    struct CInputKey { char name[0x20]; int value; CInputKey *next; };
    CInputKey *m_pKeys;
    int m_unke0; int m_unke4; int m_unke8; int m_unkec; int m_unkf0; int m_unkf4; int m_unkf8;
    float m_f0fc;
    float m_f100;
    int m_unk104[(0x138 - 0x104) / 4];
    float m_f138;
    char sub_100ff0a0(struct CUnkPlayer *);
    // vtable-slot layer (2026-11-22), from the game's vtables
    // the slots CInput adds to its base's vtable: 0-56, vfuncK at slot K
    virtual void vfunc0();
    virtual void vfunc1();
    virtual int vfunc2(int bResetState);	// GetButtonBits
    virtual void vfunc3();
    virtual void vfunc4(void *, int, int, int);
    virtual void vfunc5(int, int, int);
    virtual void vfunc6(int, int, int);
    virtual char *vfunc7(int i);
    virtual void vfunc8(int);
    virtual float vfunc9(struct kbutton_t *);
    virtual int vfunc10(int, int, int);
    virtual int vfunc11(const char *name);
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual bool vfunc18();
    virtual void vfunc19();
    virtual float vfunc20();
    virtual void vfunc21(char);
    virtual void vfunc22(int *, int *, int *, int *);
    virtual void vfunc23(int, int);
    virtual bool vfunc24();
    virtual void vfunc25();
    virtual bool vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual int vfunc29();
    virtual float vfunc30();
    virtual void vfunc31(void *cmd);
    virtual int vfunc32(int);
    virtual void vfunc33(void *, void *, void *);
    virtual int vfunc34();
    virtual int vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual int vfunc42();
    virtual void vfunc43();
    virtual int vfunc44();
    virtual int vfunc45();
    virtual int vfunc46(int, int);
    virtual int vfunc47();
    virtual bool vfunc48();
    virtual void vfunc49(float *, float *);
    virtual float vfunc50();
    virtual float vfunc51();
    virtual float vfunc52();
    virtual float vfunc53();
    virtual void vfunc54();
    virtual int vfunc55(int);
    virtual int vfunc56();
};
