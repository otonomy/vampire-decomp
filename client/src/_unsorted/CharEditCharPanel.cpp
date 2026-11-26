// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101766a0 size=0x1e
#include "CharEditCharPanel.h"

// VC6 writes CharEditCharPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CharEditCharPanel *pcd_emit_101766a0(const CharEditCharPanel &other) { return new CharEditCharPanel(other); }

// TARGET: ??_GCharEditCharPanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10177370 size=0xb7
#include "engineclient.h"
#include "CharEditCharPanel.h"
#include <string.h>

extern void sub_10179840();


struct CCharEditPanel_10177370
{
	char m_pad0[0x274];
	int m_unk274;
	void sub_101733d0(int a);
	void sub_101744c0(int a);
};

struct CHud_10177370
{
	CCharEditPanel_10177370 *sub_100f0ed0(const char *name);
};

struct CCharEditCharPanel_10177370
{
	void sub_10177a20();
};

extern CHud_10177370 g_104cfe38;

// TARGET: ?vfunc78@CharEditCharPanel@@UAEXH@Z
void CharEditCharPanel::vfunc78(int command)
{
	const char *pszCommand = (const char *)command;
	if (!_strcmpi(pszCommand, "refresh"))
	{
		((CCharEditCharPanel_10177370 *)this)->sub_10177a20();
	}
	else if (!_strcmpi(pszCommand, "play"))
	{
		sub_10179840();
		CCharEditPanel_10177370 *pPanel = g_104cfe38.sub_100f0ed0("CharEditPanel");
		pPanel->sub_101733d0(0);
		pPanel->m_unk274 = 0;
		engine->vfunc27("vclan teamchoose done", 1);
	}
	else if (!_strcmpi(pszCommand, "next"))
	{
		CCharEditPanel_10177370 *pPanel = g_104cfe38.sub_100f0ed0("CharEditPanel");
		pPanel->sub_101744c0(1);
	}
	else
	{
		typedef vgui2::Panel BaseClass;
		BaseClass::vfunc78(command);
	}
}
// END FUNCTION

// FUNCTION: 0x10177990 size=0x6
#include "CharEditCharPanel.h"
namespace lifted {
extern char g_102d0928;
}
int CharEditCharPanel::vfunc102()
{
    return (int)&lifted::g_102d0928;
}
// END FUNCTION

// FUNCTION: 0x10177a00 size=0x1
#include "CharEditCharPanel.h"
void CharEditCharPanel::vfunc119()
{
}
// END FUNCTION

// FUNCTION: 0x10177aa0 size=0x21
#include "CharEditCharPanel.h"
int sub_1016a6b0();
void CharEditCharPanel::vfunc123()
{
	int n = sub_1016a6b0();
	vfunc33(n);
	sub_101aa0a0(1000);
}
// END FUNCTION

// FUNCTION: 0x10177ad0 size=0x28
#include "CharEditCharPanel.h"
namespace lifted {
struct C10177ea0 { int sub_10177ea0(); };
struct C10177eb0 { int sub_10177eb0(); };
struct C101a99f0 { int sub_101a99f0(int); };
}
int CharEditCharPanel::vfunc21(int a0)
{
    int t0 = ((lifted::C101a99f0 *)this)->sub_101a99f0(a0);
    if (((char)a0) != 0) {
        return ((lifted::C10177eb0 *)this)->sub_10177eb0();
    }
    return ((lifted::C10177ea0 *)this)->sub_10177ea0();
}
// END FUNCTION

// FUNCTION: 0x10177b00 size=0x10
#include "CharEditCharPanel.h"
namespace lifted {
struct C10176f80 { int sub_10176f80(); };
struct C101ab2f0 { int sub_101ab2f0(); };
}
void CharEditCharPanel::vfunc101()
{
    ((lifted::C101ab2f0 *)this)->sub_101ab2f0();
    ((lifted::C10176f80 *)this)->sub_10176f80();
}
// END FUNCTION

// FUNCTION: 0x10177b20 size=0x37a
#include "CharEditCharPanel.h"
#include "CharEditPanel.h"
#include "vgui2__Label.h"
#include "vgui2__TextEntry.h"
#include "C_BasePlayer.h"
#include "CHud.h"
#include "engineclient.h"
#include "CStatDefault3List.h"
#include "StatOwner2.h"

struct ClanRec1014e6d0 { int m_0; int m_4; const char *m_pszName; const char *m_pszDesc; };
struct CUnknown101f0e50 { ClanRec1014e6d0 *sub_1014e6d0(int id); };
extern CUnknown101f0e50 g_105e8544;
extern CStatDefault3List g_105e74fc;
extern int g_102d0944;

void sub_10171400();
void sub_10171390();

#define F(type, off) (*(type *)((char *)this + (off)))
#define LBL (F(vgui2::Label *, 0x80))
#define TXT (F(vgui2::TextEntry *, 0x84))

static inline const char *SafeStr(const char *const &s)
{
	return s ? s : "";
}

void CharEditCharPanel::vfunc3()
{
	if (!engine->IsInGame())
		return;
	C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
	if (!pPlayer)
		return;
	if (*(int *)((char *)pPlayer + 0x14c0) != g_102d0944)
	{
		F(bool, 0xc4) = true;
		g_102d0944 = *(int *)((char *)pPlayer + 0x14c0);
		sub_10171400();
		sub_10171390();
	}
	if (!F(bool, 0xc4))
		return;

	if (!((CharEditPanel *)gHUD.FindElement("CharEditPanel"))->sub_10172ac0())
	{
		switch (F(int, 0xc0))
		{
		case 0:
			LBL->vfunc108(g_105e74fc.sub_1013ffa0(pPlayer->sub_1008ebb0()));
			TXT->vfunc107(SafeStr(g_105e74fc.sub_10140000(pPlayer->sub_1008ebb0())->m_pszDisplayName));
			break;
		case 1:
			LBL->vfunc108(g_105e74fc.sub_1013ffa0(pPlayer->sub_1008ebb0()));
			TXT->vfunc107(SafeStr(g_105e74fc.sub_10140000(pPlayer->sub_1008ebb0())->m_pszDisplayName));
			break;
		case 2:
			if (*(int *)((char *)pPlayer + 0x14c0) != -1)
			{
				LBL->vfunc108(SafeStr(g_105e8544.sub_1014e6d0(*(int *)((char *)pPlayer + 0x14c0))->m_pszName));
				TXT->vfunc107(SafeStr(g_105e8544.sub_1014e6d0(*(int *)((char *)pPlayer + 0x14c0))->m_pszDesc));
			}
			else
			{
				LBL->vfunc108("");
				TXT->vfunc107("");
			}
			break;
		default:
			LBL->vfunc108("");
			TXT->vfunc107("");
			break;
		}
	}
	else
	{
		switch (F(int, 0xc0))
		{
		case 0:
			LBL->vfunc108(g_105f93c0.sub_1015f2f0("KineKindred")->sub_1015ecd0(F(unsigned char, 0xbc)));
			TXT->vfunc107(g_105f93c0.sub_1015f2f0("KineKindredDescriptions")->sub_1015ecd0(F(unsigned char, 0xbc)));
			break;
		case 1:
			LBL->vfunc108(g_105f93c0.sub_1015f2f0("KineKindred")->sub_1015ecd0(F(unsigned char, 0xbc)));
			TXT->vfunc107(g_105f93c0.sub_1015f2f0("KineKindredDescriptions")->sub_1015ecd0(F(unsigned char, 0xbc)));
			break;
		case 2:
			if (*(int *)((char *)pPlayer + 0x14c0) != -1)
			{
				LBL->vfunc108(SafeStr(g_105e8544.sub_1014e6d0(*(int *)((char *)pPlayer + 0x14c0))->m_pszName));
				TXT->vfunc107(SafeStr(g_105e8544.sub_1014e6d0(*(int *)((char *)pPlayer + 0x14c0))->m_pszDesc));
			}
			else
			{
				LBL->vfunc108("");
				TXT->vfunc107("");
			}
			break;
		default:
			LBL->vfunc108("");
			TXT->vfunc107("");
			break;
		}
	}

	TXT->vfunc101();
	int nLines = TXT->sub_101b1c70();
	if (TXT->sub_101b16e0() > nLines)
		TXT->vfunc140(1);
	else
		TXT->vfunc140(0);
	TXT->vfunc101();
	TXT->vfunc49();
	F(bool, 0xc4) = false;
}
// END FUNCTION

// FUNCTION: 0x10177ef0 size=0x16
#define V8(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7();
struct O_10177ef0 {
V8(a) V8(b) V8(c) V8(d) V8(e) V8(f) V8(g) V8(h) V8(i) V8(j)
virtual void E0(); virtual void E1(); virtual void E2(); virtual void E3(); virtual void E4(); virtual void E5(); virtual void E6();
virtual void v87(int); };
O_10177ef0 *sub_10170f70();
struct S_10177ef0 { void sub_10177ef0(int a); };
void S_10177ef0::sub_10177ef0(int a)
{
	O_10177ef0 *p = sub_10170f70();
	if (p)
		p->v87(a);
}
// END FUNCTION
