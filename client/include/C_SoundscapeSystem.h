// C_SoundscapeSystem: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "IGameSystem.h"

struct SSEntry { char pad0[0xc]; float m_time; float m_data[1]; char pad1[0x2c]; };
class C_SoundscapeSystem : public IGameSystem
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with C_SoundscapeSystem's own function
    virtual bool vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7(int a);
    void sub_100c0f30(int a);
    // the slots C_SoundscapeSystem adds to its base's vtable: 9-9, vfuncK at slot K
    virtual void vfunc9();
    void *sub_100c0a90(unsigned int flags);
    void sub_100c1dd0(float t);
    void sub_100c1c80(SSEntry *e);
    int m_unk04; int m_unk08; int m_unk0c; int m_unk10; int m_unk14; int m_unk18; int m_unk1c; int m_unk20;
    int m_unk24; int m_unk28; int m_unk2c; int m_unk30; int m_unk34; int m_unk38; int m_unk3c; int m_unk40;
    int m_unk44; int m_unk48; int m_unk4c; int m_unk50; int m_unk54; int m_unk58; int m_unk5c; int m_unk60;
    int m_unk64; int m_unk68;
    SSEntry *m_entries;
    int m_unk70; int m_unk74;
    int m_count;
    int m_unk7c;
    float m_next;
};
