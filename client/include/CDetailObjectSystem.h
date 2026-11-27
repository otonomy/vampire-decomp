// CDetailObjectSystem: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "IDetailObjectSystem.h"
#include "ISpatialLeafEnumerator.h"

class CDetailObjectSystem : public IDetailObjectSystem, public ISpatialLeafEnumerator
{
public:
    CDetailObjectSystem();
    void sub_100e0900(struct Buf_100e0900 &buf);
    void sub_100e0bc0(struct Buf_100e0900 &buf);
    void sub_100e0a40(struct Buf_100e0900 &buf);
    bool sub_100e0c90(int a1, void *pInfo);
    struct Data {
        int m_unk8, m_unkc, m_unk10, m_unk14, m_unk18, m_unk1c, m_unk20, m_unk24;
        unsigned short m_w28, m_w2a, m_w2c, m_w2e, m_w30;
        int m_unk34, m_unk38, m_unk3c, m_unk40, m_unk44, m_unk48;
        Data() {
            m_unk8 = 0; m_unkc = 0; m_unk10 = 0; m_unk14 = 0; m_unk18 = 0; m_unk1c = 0; m_unk20 = 0; m_unk24 = 0;
            m_w28 = -1; m_w2a = -1; m_w2c = -1; m_w30 = 0; m_w2e = 0;
            m_unk34 = 0; m_unk38 = 0; m_unk3c = 0; m_unk40 = 0; m_unk44 = 0; m_unk48 = 0;
        }
    } m_data;
public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots CDetailObjectSystem adds to its base's vtable: 9-11, vfuncK at slot K
    virtual void vfunc9();
    virtual void vfunc10();
    virtual char *vfunc11(unsigned int);
};
