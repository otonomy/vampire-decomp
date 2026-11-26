// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1002a1e0 size=0x7
#include "CInput.h"
float CInput::vfunc50()
{
    return *(float *)((char *)this + 0x138);
}
// END FUNCTION

// FUNCTION: 0x1002a1f0 size=0x7
#include "CInput.h"
float CInput::vfunc51()
{
    return *(float *)((char *)this + 0xfc);
}
// END FUNCTION

// FUNCTION: 0x1002a200 size=0x7
#include "CInput.h"
float CInput::vfunc52()
{
    return *(float *)((char *)this + 0x100);
}
// END FUNCTION

// FUNCTION: 0x1002a210 size=0x17
#include "CInput.h"
int CInput::vfunc46(int a0, int a1)
{
    *(int *)((char *)this + 0x1b0) = a0;
    *(int *)((char *)this + 0x1b4) = a1;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x100ff7c0 size=0x14
#include "CInput.h"
namespace lifted {
extern char g_104d2700;
struct C100dfa90 { int sub_100dfa90(int); };
}
int CInput::vfunc34()
{
    *(char *)((char *)this + 0xf0) = 1;
    return ((lifted::C100dfa90 *)((int)&lifted::g_104d2700))->sub_100dfa90(0);
}
// END FUNCTION

// FUNCTION: 0x100ff7e0 size=0x14
#include "CInput.h"
namespace lifted {
extern char g_104d2700;
struct C100dfa90 { int sub_100dfa90(int); };
}
int CInput::vfunc35()
{
    *(char *)((char *)this + 0xf0) = 0;
    return ((lifted::C100dfa90 *)((int)&lifted::g_104d2700))->sub_100dfa90(0);
}
// END FUNCTION

// FUNCTION: 0x100ff800 size=0xf2
#include "C_BasePlayer.h"
#include "engineclient.h"
#include "CInput.h"

struct SelfV
{
	char pad0[0xf0];
	char m_f0;		// 0xf0
	char pad1[7];
	char m_f8;		// 0xf8
};

class ConVarV
{
public:
	void sub_100dfa90(int);
};

class PlayerV
{
public:
	void sub_1009c2e0(char b);
	void sub_1009c250();
	int sub_1007b160();
};

class EntV
{
public:
	char pad0[0x24d0];
	int m_x24d0;			// 0x24d0
	char pad1[0x4fe84 - 0x24d4];
	int m_x4fe84;			// 0x4fe84
};

class GameSysV
{
public:
	virtual void d000(); virtual void d001(); virtual void d002(); virtual void d003(); virtual void d004();
	virtual void d005(); virtual void d006(); virtual void d007(); virtual void d008(); virtual void d009();
	virtual void d010(); virtual void d011(); virtual void d012(); virtual void d013(); virtual void d014();
	virtual void d015(); virtual void d016(); virtual void d017(); virtual void d018(); virtual void d019();
	virtual void d020(); virtual void d021(); virtual void d022(); virtual void d023(); virtual void d024();
	virtual void d025(); virtual void d026(); virtual void d027(); virtual void d028(); virtual void d029();
	virtual void d030(); virtual void d031(); virtual void d032(); virtual void d033(); virtual void d034();
	virtual void d035(); virtual void d036(); virtual void d037(); virtual void d038(); virtual void d039();
	virtual void d040(); virtual void d041(); virtual void d042(); virtual void d043(); virtual void d044();
	virtual void d045(); virtual void d046(); virtual void d047(); virtual void d048(); virtual void d049();
	virtual void d050(); virtual void d051(); virtual void d052(); virtual void d053(); virtual void d054();
	virtual void d055(); virtual void d056(); virtual void d057(); virtual void d058(); virtual void d059();
	virtual void d060(); virtual void d061(); virtual void d062(); virtual void d063(); virtual void d064();
	virtual void d065(); virtual void d066(); virtual void d067(); virtual void d068(); virtual void d069();
	virtual void d070(); virtual void d071(); virtual void d072(); virtual void d073(); virtual void d074();
	virtual void d075(); virtual void d076(); virtual void d077(); virtual void d078(); virtual void d079();
	virtual void d080(); virtual void d081(); virtual void d082(); virtual void d083(); virtual void d084();
	virtual void d085(); virtual void d086(); virtual void d087(); virtual void d088(); virtual void d089();
	virtual void d090(); virtual void d091(); virtual void d092(); virtual void d093(); virtual void d094();
	virtual void d095(); virtual void d096(); virtual void d097(); virtual void d098(); virtual void d099();
	virtual void d100(); virtual void d101(); virtual void d102(); virtual void d103(); virtual void d104();
	virtual void d105(); virtual void d106(); virtual void d107(); virtual void d108(); virtual void d109();
	virtual void d110(); virtual void d111(); virtual void d112(); virtual void d113(); virtual void d114();
	virtual void d115(); virtual void d116(); virtual void d117(); virtual void d118(); virtual void d119();
	virtual void d120(); virtual void d121(); virtual void d122(); virtual void d123(); virtual void d124();
	virtual void d125(); virtual void d126(); virtual void d127(); virtual void d128(); virtual void d129();
	virtual void d130(); virtual void d131(); virtual void d132(); virtual void d133(); virtual void d134();
	virtual void d135(); virtual void d136(); virtual void d137(); virtual void d138(); virtual void d139();
	virtual void d140(); virtual void d141(); virtual void d142(); virtual void d143(); virtual void d144();
	virtual void d145(); virtual void d146(); virtual void d147();
	virtual int slot148();
};


extern char g_104d2700[];
int sub_1009b210();

// TARGET: CInput::vfunc36
void CInput::vfunc36()
{
	SelfV *self = (SelfV *)this;
	((ConVarV *)g_104d2700)->sub_100dfa90(0);
	GameSysV *gp = ((GameSysV *)C_BasePlayer::GetLocalPlayer());
	self->m_f0 = (self->m_f0 == 0);
	int p = sub_1009b210();
	if ( p )
	{
		((PlayerV *)p)->sub_1009c2e0(self->m_f0);
		((PlayerV *)p)->sub_1009c250();
		if ( ((PlayerV *)p)->sub_1007b160() )
		{
			if ( ((EntV *)((PlayerV *)p)->sub_1007b160())->m_x4fe84 > 0 )
				engine->vfunc27("force_sniper_third_person", 1);
		}
	}
	else
	{
		self->m_f0 = 0;
	}
	if ( self->m_f8 && gp )
	{
		if ( gp->slot148() )
		{
			if ( ((PlayerV *)gp->slot148())->sub_1007b160() )
			{
				if ( ((EntV *)((PlayerV *)gp->slot148())->sub_1007b160())->m_x24d0 == 0 )
				{
					engine->vfunc27("inven_holster", 1);
					self->m_f0 = 0;
					self->m_f8 = 0;
				}
			}
		}
	}
}
// END FUNCTION

// FUNCTION: 0x100ff900 size=0x8
#include "CInput.h"
void CInput::vfunc37()
{
    *(char *)((char *)this + 0xf8) = 1;
}
// END FUNCTION

// FUNCTION: 0x100ff910 size=0x8
#include "CInput.h"
void CInput::vfunc38()
{
    *(char *)((char *)this + 0xf8) = 0;
}
// END FUNCTION

// FUNCTION: 0x100ff920 size=0x8
#include "CInput.h"
void CInput::vfunc39()
{
    *(char *)((char *)this + 0xf9) = 1;
}
// END FUNCTION

// FUNCTION: 0x100ff930 size=0x8
#include "CInput.h"
void CInput::vfunc40()
{
    *(char *)((char *)this + 0xf9) = 0;
}
// END FUNCTION

// FUNCTION: 0x100ff940 size=0x7
#include "CInput.h"
bool CInput::vfunc48()
{
    return *(bool *)((char *)this + 0x1b8);
}
// END FUNCTION

// FUNCTION: 0x100ff950 size=0x56
#include "CInput.h"

struct InputView
{
    virtual void iv0() = 0;
    virtual bool vfunc1() = 0;
    char m_pad04[0x24];
    float m_fl28;        // +0x28
};

extern InputView *g_104d2134;
extern InputView *g_104d24f4;

void CInput::vfunc49(float *a, float *b)
{
    *a = g_104d2134->vfunc1() ? 0.0f : g_104d2134->m_fl28;
    *b = g_104d24f4->vfunc1() ? 0.0f : g_104d24f4->m_fl28;
}
// END FUNCTION

// FUNCTION: 0x100ff9b0 size=0x1b
#include "CInput.h"
namespace lifted {
extern char g_104d2700;
struct C100dfa90 { int sub_100dfa90(int); };
}
int CInput::vfunc47()
{
    *(char *)((char *)this + 0xf0) = 0;
    *(char *)((char *)this + 0x1b8) = 1;
    return ((lifted::C100dfa90 *)((int)&lifted::g_104d2700))->sub_100dfa90(0);
}
// END FUNCTION

// FUNCTION: 0x100ff9d0 size=0x1
#include "CInput.h"
void CInput::vfunc41()
{
}
// END FUNCTION

// FUNCTION: 0x100ff9e0 size=0xf
#include "CInput.h"
int CInput::vfunc42()
{
    *(int *)((char *)this + 0xf4) = 0;
    *(int *)((char *)this + 0xec) = 0;
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100ff9f0 size=0x1
#include "CInput.h"
void CInput::vfunc43()
{
}
// END FUNCTION

// FUNCTION: 0x100ffa00 size=0x15
#include "CInput.h"
int CInput::vfunc44()
{
    *(int *)((char *)this + 0x19c) = 0;
    *(int *)((char *)this + 0xf4) = 0;
    *(int *)((char *)this + 0xec) = 0;
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100ffa20 size=0x71
#include "CInput.h"

// TARGET: vfunc29
int CInput::vfunc29()
{
	if ( *(char *)((char *)this + 0xf8) != 0
		|| *(char *)((char *)this + 0xf0) != 0
		|| *(float *)((char *)this + 0xfc) > 0.0f
		|| *(float *)((char *)this + 0x108) > 0.0f
		|| *(float *)((char *)this + 0x138) > 0.0f
		|| *(float *)((char *)this + 0x100) > 0.0f )
		return 1;
	return 0;
}
// END FUNCTION

// FUNCTION: 0x100ffaa0 size=0x4b
#include "Vector.h"
#include "CInput.h"
float CInput::vfunc30() {
 if (!vfunc29()) return 0.0f;
 return ((Vector *)((char *)this + 0x164))->Length();
}
// END FUNCTION

// FUNCTION: 0x100ffaf0 size=0x7
#include "CInput.h"
float CInput::vfunc53()
{
    return *(float *)((char *)this + 0x104);
}
// END FUNCTION

// FUNCTION: 0x100ffb00 size=0x5c
#include "CInput.h"
#include "Vector.h"

struct CmdView
{
	char m_pad28[0x28];
	Vector m_vec28;
	char m_pad34[0x38 - 0x34];
	Vector m_vec38;
	char m_pad44[0x50 - 0x44];
	Vector m_vec50;
};

struct CInputView
{
	char m_pad164[0x164];
	Vector m_vec164;
	Vector m_vec170;
};

void CInput::vfunc31(void *pCmd)
{
	CmdView *cmd = (CmdView *)pCmd;
	CInputView *v = (CInputView *)this;
	VectorAdd(cmd->m_vec38, v->m_vec164, cmd->m_vec38);
	cmd->m_vec50 = v->m_vec170;
	vfunc33(&cmd->m_vec38, &cmd->m_vec50, &cmd->m_vec28);
}
// END FUNCTION

// FUNCTION: 0x100ffb60 size=0x21
#include "CInput.h"
int CInput::vfunc32(int a0)
{
    *(int *)((char *)a0) = *(int *)((char *)this + 0x164);
    *(int *)((char *)a0 + 4) = *(int *)((char *)this + 0x168);
    *(int *)((char *)a0 + 8) = *(int *)((char *)this + 0x16c);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x100ffd10 size=0x7
#include "CInput.h"
int CInput::vfunc45()
{
    return *(int *)((char *)this + 0xec);
}
// END FUNCTION

// FUNCTION: 0x10101cd0 size=0x34
#include "CInput.h"
#include <string.h>
// TARGET: CInput::FindKey
int CInput::FindKey(const char *name)
{
	for (CInputKey *p = m_pKeys; p; p = p->next) {
		if (!_strcmpi(name, p->name))
			return p->value;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x10101da0 size=0x7
#include "CInput.h"
int CInput::vfunc56()
{
    return *(int *)((char *)this + 0x1c4);
}
// END FUNCTION

// FUNCTION: 0x10102500 size=0x17
#include "CInput.h"
struct IGlobal_105f99d8 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual int v16(int a, int b, int c);
};
extern IGlobal_105f99d8 *g_105f99d8;
int CInput::KeyEvent(int a, int b, int c)
{
	if (g_105f99d8)
		return g_105f99d8->v16(a, b, c);
	return 1;
}
// END FUNCTION

// FUNCTION: 0x10103310 size=0x3
#include "CInput.h"
void CInput::MakeWeaponSelection(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x10103a60 size=0x97
#include "CInput.h"
#include "CUserCmd.h"
void sub_1013bb00(int, char *, CUserCmd *);
// TARGET: CInput::EncodeUserCmdToBuffer
void CInput::EncodeUserCmdToBuffer(int a, int b, int c)
{
    CUserCmd cmd;
    char *p = GetUsercmd(c);
    sub_1013bb00(a, p, &cmd);
}
// END FUNCTION

// FUNCTION: 0x10103b00 size=0x97
#include "CInput.h"
#include "CUserCmd.h"
void sub_1013c230(int, char *, CUserCmd *);
// TARGET: CInput::DecodeUserCmdFromBuffer
void CInput::DecodeUserCmdFromBuffer(int a, int b, int c)
{
    CUserCmd cmd;
    char *p = GetUsercmd(c);
    sub_1013c230(a, p, &cmd);
}
// END FUNCTION

// FUNCTION: 0x10103ba0 size=0xbc
#include "CInput.h"
#include "CUserCmd.h"
void sub_10103c60(void *buf, CUserCmd *to, CUserCmd *from, bool isnew);

void CInput::WriteUsercmdDeltaToBuffer(void *buf, int from, int to, bool isnew)
{
    CUserCmd nullcmd;
    CUserCmd *f;
    if (from == -1)
        f = &nullcmd;
    else
        f = (CUserCmd *)GetUsercmd(from);
    CUserCmd *t = (CUserCmd *)GetUsercmd(to);
    sub_10103c60(buf, t, f, isnew);
}
// END FUNCTION

// FUNCTION: 0x10104440 size=0x15
#include "CInput.h"
char *CInput::GetUsercmd(int i)
{
	return *(char **)((char *)this + 0x1c0) + i * 96;
}
// END FUNCTION

// FUNCTION: 0x10104460 size=0x287
#include "CInput.h"

struct kbutton_t
{
	int down[2];
	int state;
};

extern int g_104d3e38;	// s_ClearInputState
extern kbutton_t g_104d2e4c;
extern kbutton_t g_104d3234;
extern kbutton_t g_104d38b8;
extern kbutton_t g_104d3590;
extern kbutton_t g_104d3af0;
extern kbutton_t g_104d2fa4;
extern kbutton_t g_104d3714;
extern kbutton_t g_104d3748;
extern kbutton_t g_104d38a0;
extern kbutton_t g_104d39a4;
extern kbutton_t g_104d3584;
extern kbutton_t g_104d3c5c;
extern kbutton_t g_104d3754;
extern kbutton_t g_104d2f3c;
extern kbutton_t g_104d2da0;
extern kbutton_t g_104d2e40;
extern kbutton_t g_104d36e0;
extern kbutton_t g_104d33d0;
extern int g_104d3e40;	// in_cancel
extern int g_104cfe64;
extern unsigned int g_104cfe50;	// gHUD.m_iKeyBits
extern char g_104d3e48;

void sub_101046f0(int *bits, int in_button, int in_ignore, kbutton_t *button, bool reset);
void sub_10105fb0(int *bits, int in_button, int in_button2, int in_ignore, kbutton_t *button, bool reset);
void sub_10105f30(int *bits, int in_button, int in_button2, int in_ignore, kbutton_t *button, bool reset);

char sub_10101b80()
{
	return g_104d3e48;
}

// TARGET: ?vfunc2@CInput@@UAEHH@Z
int CInput::GetButtonBits(int bResetState)
{
	int bits = 0;

	sub_101046f0(&bits, 0x20000, g_104d3e38, &g_104d2e4c, bResetState != 0);
	sub_101046f0(&bits, 4, g_104d3e38, &g_104d3234, bResetState != 0);
	sub_101046f0(&bits, 2, g_104d3e38, &g_104d38b8, bResetState != 0);
	sub_10105fb0(&bits, 8, 0, g_104d3e38, &g_104d3590, bResetState != 0);
	sub_10105fb0(&bits, 0x10, 0, g_104d3e38, &g_104d3af0, bResetState != 0);
	sub_101046f0(&bits, 0x20, g_104d3e38, &g_104d2fa4, bResetState != 0);
	sub_101046f0(&bits, 0x80, g_104d3e38, &g_104d3714, bResetState != 0);
	sub_101046f0(&bits, 0x100, g_104d3e38, &g_104d3748, bResetState != 0);
	sub_101046f0(&bits, 0x200, g_104d3e38, &g_104d38a0, bResetState != 0);
	sub_101046f0(&bits, 0x400, g_104d3e38, &g_104d39a4, bResetState != 0);
	sub_101046f0(&bits, 0x2000, g_104d3e38, &g_104d3584, bResetState != 0);
	sub_101046f0(&bits, 0x4000, g_104d3e38, &g_104d3c5c, bResetState != 0);
	sub_101046f0(&bits, 0x10000, g_104d3e38, &g_104d3754, bResetState != 0);
	sub_10105f30(&bits, 1, 0x800000, g_104d3e38, &g_104d2f3c, bResetState != 0);
	sub_10105f30(&bits, 0x800, 0x1000000, g_104d3e38, &g_104d2da0, bResetState != 0);
	sub_10105f30(&bits, 0x400000, 0, g_104d3e38, &g_104d2e40, bResetState != 0);
	sub_10105f30(&bits, 0x8000000, g_104d3e38, g_104d3e38, &g_104d36e0, bResetState != 0);

	if (g_104d2fa4.state & 4)
	{
		bits |= 0x2000000;
		g_104d2fa4.state &= ~4;
	}
	if (g_104d33d0.state & 3)
		bits |= 0x4000000;
	if (g_104d3e40)
		bits |= 0x40;
	if (sub_10101b80() || g_104cfe64)
		bits |= 0x10000;
	if (g_104cfe50 & 0x80000)
		bits |= 0x80000;
	if (g_104cfe50 & 0x100000)
		bits |= 0x100000;

	bits &= ~g_104d3e38;
	if (bResetState)
		g_104d3e38 = 0;
	return bits;
}
// END FUNCTION

// FUNCTION: 0x10104730 size=0x15
#include "CInput.h"
namespace lifted {
extern int g_104d3e38;
}
int CInput::vfunc55(int a0)
{
    lifted::g_104d3e38 = lifted::g_104d3e38 | a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x10104750 size=0x31
#include "CInput.h"
struct XG2 { virtual void v0(); virtual char v1(); char u[0x2c - 4]; int m_i2c; };
extern XG2 *g_104d31f4;
// TARGET: CInput::GetLookSpring
float CInput::GetLookSpring()
{
	int p;
	if (g_104d31f4->v1())
		p = 0;
	else
		p = g_104d31f4->m_i2c;
	return (float)p;
}
// END FUNCTION

// FUNCTION: 0x10104790 size=0x1d
#include "CInput.h"
struct SubObj_10104790
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual int v8();
};
struct Player_10104790
{
	int m_unk0, m_unk4, m_unk8;
	SubObj_10104790 m_sub;
};
extern Player_10104790 *g_104a0d50;
// TARGET: CInput::vfunc26
bool CInput::vfunc26()
{
	if (g_104a0d50 && g_104a0d50->m_sub.v8() == 9)
		return true;
	return false;
}
// END FUNCTION

// FUNCTION: 0x10105d50 size=0x13e
#include "engineclient.h"
#include "CInput.h"
#include "CUserCmd.h"

extern "C" void *__cdecl memset(void *, int, unsigned int);


struct CInputFields_10105d50
{
	char pad0[0x20];
	int m_fMouseInitialized;       // 0x20
	int m_fRestoreSPI;             // 0x24
	int m_n28;                     // 0x28
	int m_fJoystickAvailable;      // 0x2c
	int m_fJoystickAdvancedInit;   // 0x30
	int m_fJoystickHasPOVControl;  // 0x34
	char pad38[0x5c - 0x38];
	int m_fMouseActive;            // 0x5c
	int m_rgOrigMouseParms[3];     // 0x60
	int m_rgNewMouseParms[3];      // 0x6c
	int m_fMouseParmsValid;        // 0x78
	char pad7c[0xe0 - 0x7c];
	int m_ne0;                     // 0xe0
	bool m_be4;                    // 0xe4
	int m_ne8;                     // 0xe8
	char padec[0x138 - 0xec];
	int m_n138;                    // 0x138
	int m_n13c;                    // 0x13c
	char pad140[0x1bc - 0x140];
	float m_flLastForwardMove;     // 0x1bc
	CUserCmd *m_pCommands;         // 0x1c0
	int m_n1c4;                    // 0x1c4
	void *m_pCmdRate;              // 0x1c8
	void *m_pUpdateRate;           // 0x1cc

	void sub_101062e0();
	void sub_101009f0();
	void sub_10101db0();
	void sub_101003b0();
};

// TARGET: CInput::Init_All
void CInput::Init_All()
{
	CInputFields_10105d50 *f = (CInputFields_10105d50 *)this;
	f->m_pCommands = new CUserCmd[64];

	f->m_fMouseInitialized = 0;
	f->m_fRestoreSPI = 0;
	f->m_fMouseActive = 0;
	f->m_n28 = 0;
	memset(f->m_rgOrigMouseParms, 0, sizeof(f->m_rgOrigMouseParms));
	memset(f->m_rgNewMouseParms, 0, sizeof(f->m_rgNewMouseParms));

	f->m_rgNewMouseParms[2] = 1;

	f->m_fMouseParmsValid = 0;
	f->m_fJoystickAvailable = 0;
	f->m_fJoystickAdvancedInit = 0;
	f->m_fJoystickHasPOVControl = 0;
	f->m_flLastForwardMove = 0.0f;
	f->m_n13c = 0;
	f->m_n138 = 0;
	f->m_be4 = false;
	f->m_ne8 = 0;
	f->m_ne0 = 0;

	f->sub_101062e0();
	f->sub_101009f0();
	f->sub_10101db0();
	f->sub_101003b0();

	f->m_pCmdRate = cvar->FindVar("cl_cmdrate");
	f->m_pUpdateRate = cvar->FindVar("cl_updaterate");
}
// END FUNCTION

// FUNCTION: 0x10105ef0 size=0x2b
#include "CInput.h"
namespace lifted {
struct C10101df0 { int sub_10101df0(); };
struct V { virtual int f0(int); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual int f17(); };
}
void CInput::Shutdown_All()
{
    ((lifted::V *)this)->f17();
    int t0 = ((lifted::C10101df0 *)this)->sub_10101df0();
    if ((*(int *)((char *)this + 0x1c0)) != 0) {
        ((lifted::V *)(*(int *)((char *)this + 0x1c0)))->f0(3);
    }
    *(int *)((char *)this + 0x1c0) = 0;
}
// END FUNCTION

// FUNCTION: 0x10105f20 size=0x8
#include "CInput.h"
void CInput::vfunc54()
{
    *(char *)((char *)this + 0xe4) = 1;
}
// END FUNCTION

// FUNCTION: 0x10106240 size=0x48
#include "CInput.h"
extern int (__stdcall *g_101e30e4)(int, int, void *, int);
// TARGET: ?vfunc16@CInput@@UAEXXZ
void CInput::ActivateMouse()
{
	char *p = (char *)this;
	if (*(int *)(p + 0x28) != 1 && *(int *)(p + 0x20) != 0) {
		if (*(int *)(p + 0x78) != 0)
			*(int *)(p + 0x5c) = g_101e30e4(4, 0, p + 0x6c, 0);
		*(int *)(p + 0x28) = 1;
		vfunc25();
		*(int *)(p + 0x54) = 0;
		*(int *)(p + 0x58) = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x10106290 size=0x3f
#include "CInput.h"
extern void (__stdcall *g_101e30e4)(int, int, void *, int);
void CInput::DeactivateMouse()
{
	if (m_unk28 && m_unk20) {
		if (m_unk5c)
			g_101e30e4(4, 0, &m_unk60, 0);
		m_unk28 = 0;
		m_unk54 = 0;
		m_unk58 = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x101062d0 size=0x9
#include "CInput.h"
bool CInput::vfunc18() { if (m_unk28) return true; return false; }
// END FUNCTION

// FUNCTION: 0x10106310 size=0x2a
#include "CInput.h"
struct IEngA {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
	virtual int v46(int); virtual int v47();
};
extern IEngA *g_104a57d4;
void CInput::vfunc25()
{
	int a = g_104a57d4->v47();
	int b = g_104a57d4->v46(a);
	sub_10106880(b);
}
// END FUNCTION

// FUNCTION: 0x101067d0 size=0x8f
#include "engineclient.h"
#include "CInput.h"
struct Gv_101067d0 {
	virtual void v0();
	virtual bool v1();
	int m_pad[10];
	int m_n2c;
};
extern Gv_101067d0 *g_104d400c;

void CInput::AccumulateMouse()
{
	int x, y;
	if (!g_104d400c->v1() && g_104d400c->m_n2c && !m_unkec && !m_unk24 && m_unk28) {
		sub_10106860(&x, &y);
		m_unk54 += x - engine->vfunc46();
		m_unk58 += y - engine->vfunc47();
		vfunc25();
	}
}
// END FUNCTION

// FUNCTION: 0x101069a0 size=0x11
#include "CInput.h"
// TARGET: CInput::vfunc21
void CInput::vfunc21(char b) { m_unk24 = b != 0; }
// END FUNCTION

// FUNCTION: 0x101069c0 size=0x9
#include "CInput.h"
bool CInput::vfunc24() { if (m_unk24) return true; return false; }
// END FUNCTION

// FUNCTION: 0x101069d0 size=0xe9
#include "engineclient.h"
#include "CInput.h"


extern int sub_100cd100();
extern int sub_100cd0f0();

void CInput::GetFullscreenMousePos(int *a1, int *a2, int *a3, int *a4)
{
	if (!m_unk24)
		return;
	int x, y;
	sub_10106860(&x, &y);
	x -= engine->vfunc46();
	y -= engine->vfunc47();
	x += sub_100cd100() / 2;
	y += sub_100cd0f0() / 2;
	if (a3)
		*a3 = x;
	if (a4)
		*a4 = y;
	x = x < 0 ? 0 : x;
	if (sub_100cd100() < x)
		x = sub_100cd100();
	y = y < 0 ? 0 : y;
	if (sub_100cd0f0() < y)
		y = sub_100cd0f0();
	*a1 = x;
	*a2 = y;
}
// END FUNCTION

// FUNCTION: 0x10106ac0 size=0x52
#include "engineclient.h"
#include "CInput.h"

int sub_100cd0f0();
int sub_100cd100();



struct CInputCallView_10106ac0
{
	int sub_10106880(int x, int y);
};

// TARGET: CInput::SetFullscreenMousePos
void CInput::SetFullscreenMousePos(int a1, int a2)
{
	((CInputCallView_10106ac0 *)this)->sub_10106880(
		a1 - sub_100cd100() / 2 + engine->vfunc46(),
		a2 - sub_100cd0f0() / 2 + engine->vfunc47());
}
// END FUNCTION

// FUNCTION: 0x10106b20 size=0x13
#include "CInput.h"
void CInput::ClearStates()
{
	if ( m_unk28 != 0 )
	{
		m_unk2c[(0x54 - 0x2c) / 4] = 0;
		m_unk2c[(0x58 - 0x2c) / 4] = 0;
		m_unk2c[(0x50 - 0x2c) / 4] = 0;
	}
}
// END FUNCTION
