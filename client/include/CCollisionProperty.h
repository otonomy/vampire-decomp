// CCollisionProperty: skeleton from the game's RTTI (2026-11-24)
// declared: its bases (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "ICollideable.h"
#include "vector.h"
#include "QAngle.h"

class CCollisionProperty : public ICollideable
{
public:
    virtual void *vfunc0();
    virtual Vector &vfunc1();
    virtual void *vfunc2();
    virtual void vfunc3(Vector *, Vector *);
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual const Vector &vfunc8();
    virtual const QAngle &vfunc9(int);
    virtual const struct matrix3x4_t &vfunc10();
    virtual void vfunc11x();
    virtual int vfunc12x();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15(Vector &mins, Vector &maxs);	// slot 15: the world-space bounds (C_ServerRagdoll's GetRenderBoundsWorldspace forwards to it)
    virtual void vfunc16();
    virtual void vfunc17();
    Vector m_vecMins;	// +0x4
    int m_unk10; int m_unk14; int m_unk18; int m_unk1c; float m_flBloat; int m_unk24; int m_unk28; int m_unk2c; int m_unk30; int m_unk34; int m_unk38;
    void *m_unk3c;
    int m_unk40;
    unsigned short m_unk44;
    int *sub_100432f0(char a);
    int vfunc11();
    bool sub_100442d0();
    int vfunc12();
    void sub_10043230(int state);
    void sub_100442b0();
    void sub_100433c0(Vector *a, char *b);
    void sub_100432a0(int a);
    void sub_10043860(const Vector &mins, const Vector &maxs, Vector *pWorldMins, Vector *pWorldMaxs);
    float sub_10043b90(const Vector *pPoint);
    float sub_10043c80(const Vector *dir);
    bool sub_10043930(const Vector &pt);
};
