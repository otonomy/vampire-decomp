// CGUIClientRenderable: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "CDefaultClientRenderable.h"

class CGUIClientRenderable : public CDefaultClientRenderable
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots CGUIClientRenderable adds to its base's vtable: 9-13, vfuncK at slot K
    virtual void vfunc9();
    virtual void vfunc10(class Vector *pos, class Quaternion *q);
    virtual void vfunc11();
    virtual char * vfunc12();
    virtual char * vfunc13();

    int m_unk08;
    int m_nSequence;
    int m_unk10; int m_unk14; int m_unk18; int m_unk1c;
    int m_unk20; int m_unk24; int m_unk28;
    void *m_pModel;
    float m_flCycle;
    int m_unk34; int m_unk38; int m_unk3c;
    int m_unk40; int m_unk44; int m_unk48; int m_unk4c;
    int m_unk50; int m_unk54; int m_unk58; int m_unk5c;
    int m_unk60; int m_unk64;
    void *m_pStudioHdr;
    int m_unk6c;
    int m_unk70; int m_unk74; int m_unk78; int m_unk7c;
    int m_unk80; int m_unk84;
    float m_flPoseParameter[24];
    float m_flPrevPoseParameter[24];
    float m_flPlaybackRate;
    int m_unk14c;
    float m_flLastCycle;

    int m_unk154[(0x190 - 0x154) / 4];
    float m_f190;
    int m_unk194[(0x1ac - 0x194) / 4];
    float m_f1ac;
    ~CGUIClientRenderable();
    float sub_1018a7d0();
    float sub_1018a8c0(float cur, float prev, float curTime, bool b);
    float sub_1018a860(int i, float cur, float prev, float curTime);
    float sub_1018a990(float flCycle, int nSequence, float *poseParameter, float flPlaybackRate, float dt);
    void sub_1018a350(float cycle, float *poseParameter, class Vector *pos, class Quaternion *q);
    void sub_1018a730(float *controllers, float curTime);
};
