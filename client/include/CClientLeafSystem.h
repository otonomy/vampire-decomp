// CClientLeafSystem: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases; nothing else yet (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "IClientLeafSystem.h"
#include "ISpatialLeafEnumerator.h"

class CClientLeafSystem : public IClientLeafSystem, public ISpatialLeafEnumerator
{
public:
public:
    struct Item_t { int m_a0; int m_a4; int m_a8; int m_ac; int m_a10; int m_a14; int m_a18; int m_a1c; int m_a20; int m_a24; int m_a28; int m_a2c; int m_a30; };
    struct Data_t { int m_u0; int m_u4; int m_u8; int m_uc; int m_u10; int m_u14; Item_t m_Items[1]; };
    int m_unk8; int m_unkc; int m_unk10; int m_unk14; int m_unk18; int m_unk1c;
    Data_t *m_pData;
    void *vfunc21(unsigned short);
    unsigned short vfunc17(unsigned short);
    bool vfunc15(char);
    bool vfunc16(char);
    void vfunc22();
    virtual void vfunc2(unsigned short, int, unsigned short *);
    void sub_100d2560(unsigned int, unsigned short);
    void sub_100d2800(unsigned short, float *, float *);
    void vfunc23();
public:
    int vfunc10(int, int, int);
    void vfunc13(void *a1, int leaf, int a3, void *info);
    void vfunc12(int, int *, int *, int);
    void vfunc8(int, int, unsigned int *, unsigned int *);
    void vfunc7(int, unsigned int *, unsigned int *);
    void vfunc6(int, unsigned short, unsigned short);
    virtual bool vfunc5(unsigned short);
    bool vfunc9(int, int);
    void vfunc14(class CUtlVector4 *out);
    void vfunc0(class IClientRenderable *pRenderable, bool bRenderWithViewModels);
    void sub_100d2a40(int handle, int group);
    void sub_100d1b60(class IClientRenderable *pRenderable, int group, int flags);
};
