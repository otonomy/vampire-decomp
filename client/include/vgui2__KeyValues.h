// vgui2::KeyValues: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once

namespace vgui2
{
class KeyValues
{
public:
    static void *operator new(unsigned int);
    KeyValues(const char *);
    KeyValues(const char *, const char *, int);
    KeyValues(const char *, const char *, const char *);
    ~KeyValues();
    void sub_101b5ac0(char *, int);
    int m_unk4;
    void *m_pName;
    union { int m_unkc; float m_flValue; };
    int m_unk10;
    KeyValues *m_pPeer;
    KeyValues *m_pSub;	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots KeyValues adds to its base's vtable: 0-21, vfuncK at slot K
    virtual int vfunc0();
    virtual int vfunc1();
    virtual bool vfunc2(void *, const char *, const char *);
    virtual void vfunc3();
    virtual KeyValues *vfunc4(const char *keyName, bool bCreate);
    virtual void vfunc5();
    virtual void vfunc6(KeyValues *);
    virtual int vfunc7();
    virtual int vfunc8();
    virtual int vfunc9(const char *keyName, int defaultValue);
    virtual float vfunc10(const char *keyName, float defaultValue);
    virtual const char *vfunc11(const char *keyName, const char *defaultValue);
    virtual int vfunc12(int, int);
    virtual bool vfunc13(int);
    virtual void vfunc14(const char *keyName, const char *value);
    virtual int vfunc15(int, int);
    virtual int vfunc16(int, int);
    virtual int vfunc17(int, int);
    virtual KeyValues *vfunc18();
    virtual void vfunc19();
    virtual int vfunc20(int);
    virtual void vfunc21();
};
}
