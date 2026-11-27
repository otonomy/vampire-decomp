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
    union { int m_unk2c[(0x40 - 0x2c) / 4]; struct { int m_joy_avail; int m_unk30; int m_joy_haspov; int m_joy_numbuttons; int m_unk3c; }; };
    int m_nJoystickFlags;	// 0x40
    union { int m_unk44[(0x54 - 0x44) / 4]; struct { unsigned long m_joy_oldbuttonstate; unsigned long m_joy_oldpovstate; int m_unk4c; int m_unk50; }; };
    int sub_10100f10();
    int m_unk54;
    int m_unk58;
    int m_unk5c;
    int m_unk60;
    int m_unk64[(0x7c - 0x64) / 4];
    struct joy_axis_t { int m_unk00; int AxisMap; int ControlMap; unsigned long *pdwRawValue; };
    joy_axis_t m_rgAxes[6];	// 0x7c
    unsigned long *RawValuePointer(int axis);	// 0x10100b40; defined in in_joystick.cpp before its callers (VC6 then keeps edx live across the call)
    void sub_10100f80(float frametime, class CUserCmd *cmd);
    struct CInputKey { char name[0x20]; int value; CInputKey *next; };
    CInputKey *m_pKeys;
    int m_unke0; int m_unke4; int m_unke8; int m_unkec; int m_unkf0; int m_unkf4; int m_unkf8;
    float m_f0fc;
    float m_f100;
    int m_unk104[(0x138 - 0x104) / 4];
    float m_f138;
    int m_unk13c[(0x144 - 0x13c) / 4];
    bool m_b144;
    char m_c145; char m_c146; char m_c147;
    int m_unk148[(0x19c - 0x148) / 4];
    int m_fCameraDistanceMove;	// 0x19c
    int m_nCameraOldX;	// 0x1a0
    int m_nCameraOldY;	// 0x1a4
    int m_nCameraX;	// 0x1a8
    int m_nCameraY;	// 0x1ac
    int m_unk1b0[(0x1bc - 0x1b0) / 4];
    int m_n1bc;	// 0x1bc: the last command's forward move, truncated
    class CUserCmd *m_pCommands;	// 0x1c0
    int m_n1c4;	// 0x1c4: msec adjustment still to apply (CreateMove's last argument)
    class ConVar *m_p1c8;	// 0x1c8: CreateMove clamps its int to 1..255 (30 without it) into CUserCmd +0x47
    class ConVar *m_p1cc;	// 0x1cc: the same into +0x46 (20 without it)
    void sub_101028d0(float frametime);
    void sub_10102a50(class CUserCmd *cmd);
    int sub_10102940();
    void sub_10102d00(class CUserCmd *cmd);
    void sub_10102df0(class CUserCmd *cmd);
    void sub_10102fe0(float frametime, class CUserCmd *cmd);
    void sub_101030c0(class QAngle &viewangles, class CUserCmd *cmd);
    void sub_101063f0(float *mx, float *my);
    void sub_100fc170();	// CAM_Think-like: mouse / key camera angles and distance into cam_idealpitch/yaw/dist
    char sub_100ff0a0(struct CUnkPlayer *);
    void sub_100fc900();
    // vtable-slot layer (2026-11-22), from the game's vtables
    // the slots CInput adds to its base's vtable: 0-56, vfuncK at slot K
    virtual void Init_All();	// slot 0
    virtual void Shutdown_All();	// slot 1
    virtual int GetButtonBits(int bResetState);	// slot 2
    virtual void CreateMove(int sequence_number, int totalslots, float tick_frametime, float input_sample_frametime, int active, float packet_loss);	// slot 3; SDK IInput::CreateMove, CHLClient::CreateMove forwards it
    virtual void WriteUsercmdDeltaToBuffer(void *buf, int from, int to, bool isnewcommand);	// slot 4; SDK IInput::WriteUsercmdDeltaToBuffer
    virtual void EncodeUserCmdToBuffer(int, int, int);	// slot 5
    virtual void DecodeUserCmdFromBuffer(int, int, int);	// slot 6
    virtual char *GetUsercmd(int i);	// slot 7
    virtual void MakeWeaponSelection(int);	// slot 8
    virtual float KeyState(struct kbutton_t *);	// slot 9
    virtual int KeyEvent(int, int, int);	// slot 10
    virtual int FindKey(const char *name);	// slot 11
    virtual void ControllerCommands();	// slot 12
    virtual void Joystick_Advanced();	// slot 13
    virtual void AccumulateMouse();	// slot 14
    virtual void MouseEvent(int mstate, bool down);	// slot 15; SDK IInput::MouseEvent, CHLClient::IN_MouseEvent forwards it
    virtual void ActivateMouse();	// slot 16
    virtual void DeactivateMouse();	// slot 17
    virtual bool vfunc18();
    virtual void ClearStates();	// slot 19
    virtual float GetLookSpring();	// slot 20
    virtual void vfunc21(char);
    virtual void GetFullscreenMousePos(int *, int *, int *, int *);	// slot 22
    virtual void SetFullscreenMousePos(int, int);	// slot 23
    virtual bool vfunc24();
    virtual void vfunc25();
    virtual bool vfunc26();
    virtual float vfunc27();	// CViewRender::sub_10190390 takes fabs() of it
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

// the client's input object (SDK cl_dll/hl2_dll/hl_in_main.cpp: static CHLInput g_Input; IInput *input = &g_Input):
// input->vfuncN(); declared as CInput * since the slots are declared here
extern CInput *input;
