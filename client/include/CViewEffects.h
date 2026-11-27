// CViewEffects: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "IViewEffects.h"
#include "Vector.h"
#include "QAngle.h"

class CViewEffects : public IViewEffects
{
public:
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    // the screen shake (CalcShake: type 0 random offsets, 1 roll only, other: moved to the wave block at +0x50)
    struct screenshake_t
    {
        int type;
        float time;
        float duration;
        float amplitude;
        float frequency;
        float nextShake;
        float offset[3];
        float angle;
        float appliedOffset[3];
        float appliedAngle;
    };
    union
    {
        screenshake_t m_Shake;
        struct
        {
            int m_unk18;
            int m_unk1c;
            int m_unk20;
            int m_unk24;
            int m_unk28;
            int m_unk2c;
            int m_unk30;
            int m_unk34;
            int m_unk38;
            int m_unk3c;
            int m_unk40;
            int m_unk44;
            int m_unk48;
            int m_unk4c;
        };
    };
    int m_nState;
    // SetWaves (sub_10196d70) stores its int arguments here; CalcShake reads them as floats
    union
    {
        struct
        {
            int m_unk54;
            int m_unk58;
            int m_unk5c;
            int m_unk60;
        };
        struct
        {
            float m_flWaveTime;
            float m_flWaveDuration;
            float m_flWaveAmplitude;
            float m_flWaveFrequency;
        };
    };
    int m_unk64;
    Vector m_vecAppliedOffset;
    float m_flAppliedAngle;
    Vector m_vecShakeOffset;
    float m_flShakeAngle;
    int m_unk88;
    int m_unk8c;
    int m_unk90;
    int m_unk94;
    int m_unk98;
    Vector m_vecHolyLight;
    float m_flHolyLightStrength;
    bool sub_101977a0();
    void sub_10197a20(int);
    int sub_10196d70(int mode, int a, int b, int c, float d);
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots CViewEffects adds to its base's vtable: 0-17, vfuncK at slot K
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2(int, unsigned char *, unsigned char *, unsigned char *, unsigned char *, unsigned char *);
    virtual void vfunc3();
    virtual int vfunc4(int a0, int a1, void *pFade);	// slot 4: called by FadeCalculate with (0, 0, &screenfade message)
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7(Vector &origin, QAngle &angles, float factor);
    virtual void vfunc8(Vector &origin, QAngle &angles, float factor);
    virtual void vfunc9(Vector &origin, QAngle &angles, float factor);
    virtual void vfunc10();
    virtual void vfunc11();
    virtual bool vfunc12();
    virtual void vfunc13();
    virtual void vfunc14(float flStrength);
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
};
