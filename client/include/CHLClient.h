// CHLClient: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "IBaseClientDLL.h"

class bf_write;
struct kbutton_s;

class CHLClient : public IBaseClientDLL
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots CHLClient adds to its base's vtable: 0-44, vfuncK at slot K
    virtual int vfunc0(void *(*appSystemFactory)(const char *, int *), void *(*physicsFactory)(const char *, int *), class CGlobalVarsBase *pGlobals);
    virtual void vfunc1();
    virtual void vfunc2(int a);
    virtual void vfunc3();
    virtual void vfunc4();
    virtual int vfunc5();
    virtual int vfunc6();
    virtual int vfunc7(int, int);
    virtual int vfunc8(float);
    virtual void vfunc9(int);
    virtual int vfunc10();
    virtual int vfunc11(int, int, int, int);
    virtual void vfunc12(int);
    virtual void IN_ActivateMouse();	// slot 13
    virtual void IN_DeactivateMouse();	// slot 14
    virtual void IN_MouseEvent(int mstate, bool down);	// slot 15
    virtual void IN_Accumulate();	// slot 16
    virtual void IN_ClearStates();	// slot 17
    virtual struct kbutton_s *IN_FindKey(const char *name);	// slot 18
    virtual int IN_KeyEvent(int eventcode, int keynum, const char *pszCurrentBinding);	// slot 19
    virtual void CreateMove(int sequence_number, int totalslots, float tick_frametime, float input_sample_frametime, int active, float packet_loss);	// slot 20
    virtual void WriteUsercmdDeltaToBuffer(bf_write *buf, int from, int to, bool isnewcommand);	// slot 21
    virtual void vfunc22();
    virtual int vfunc23(int, int);
    virtual void vfunc24();
    virtual int vfunc25(int);
    virtual int vfunc26();
    virtual void vfunc27(int, int);
    virtual void vfunc28(int);
    virtual int vfunc29();
    virtual void vfunc30(int, int);
    virtual void vfunc31(const char *pName);
    virtual void vfunc32(int);
    virtual int vfunc33(int);
    virtual void vfunc34(void *pData, int a, int b, int c, int d, int e);
    virtual void vfunc35(void *pData, int a, int b, int c, int d, int e);
    virtual int vfunc36();
    virtual void vfunc37(void *pData);
    virtual void vfunc38(void *pData);
    virtual void vfunc39(void *pData);
    virtual void vfunc40(void *pData, int a);
    virtual int vfunc41(int);
    virtual void vfunc42();
    virtual void vfunc43(int, int, int);
    virtual bool vfunc44();	// forwards input->vfunc18()
};
