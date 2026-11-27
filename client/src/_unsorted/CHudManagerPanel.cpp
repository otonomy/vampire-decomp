// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100586e0 size=0x1e
#include "CHudManagerPanel.h"

// VC6 writes CHudManagerPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CHudManagerPanel *pcd_emit_100586e0() { return new CHudManagerPanel; }

// TARGET: ??_GCHudManagerPanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100587b0 size=0x602
#include "CHudManagerPanel.h"
#include "CHudManager.h"
#include "engineclient.h"
#include "CSignUI.h"
#include "CHudTimerUI.h"
#include "CHudInfo.h"
#include "CHudInfoBar.h"
#include "CProgBar.h"
#include "CHudDialog.h"
#include "CDiscipline.h"
#include "CBloodBar.h"
#include "CHealthAnkh.h"
#include "CFeedBar.h"
#include "CBossHealthBar.h"
#include "CFrenzyBar.h"
#include "CHudUseIcon.h"
#include "CStealth.h"
#include "CAmmoCounter.h"
#include "CPhysicsHand.h"
#include "CTargeted.h"
#include "CItemInfo.h"
#include "CMoneyBar.h"
#include "CHudAreaIcon.h"
#include "CCredits.h"

struct CUnknown10057710 { int sub_10057710(int); };

typedef int (*HudHook_t)(const char *, int, void *);
int sub_10058090(int, int, int);
int sub_100580b0(int, int, int);
int sub_100580f0(int, int, int);
int sub_100580d0(int, int, int);
int sub_10058290(int, int, int);
int sub_10058110(int, int, int);
int sub_10058130(int, int, int);
int sub_10058150(int, int, int);
int sub_10058170(int, int, int);
int sub_10058190(int, int, int);
int sub_100581b0(int, int, int);
int sub_100581d0(int, int, int);
int sub_100581f0(int, int, int);
int sub_10058210(int, int, int);
int sub_10058230(int, int, int);
int sub_10058250(int, int, int);
int sub_10058270(int, int, int);
int sub_100582b0(int, int, int);
int sub_100582d0(int, int, int);
int sub_100582f0(int, int, int);

#define ADD(x) ((CUnknown10057710 *)m_pChild)->sub_10057710((int)(IManagedHudElement *)(x))

void CHudManagerPanel::vfunc0(vgui2::Panel *parent)
{
	engine->vfunc29("SignUI", (HudHook_t)sub_10058090);
	engine->vfunc29("HUDTimer", (HudHook_t)sub_100580b0);
	engine->vfunc29("InfoCtrl", (HudHook_t)sub_100580f0);
	engine->vfunc29("InfoBarCtrl", (HudHook_t)sub_100580d0);
	engine->vfunc29("ProgBar", (HudHook_t)sub_10058290);
	engine->vfunc29("DialogCtrl", (HudHook_t)sub_10058110);
	engine->vfunc29("DiscCtrl", (HudHook_t)sub_10058130);
	engine->vfunc29("BloodCtrl", (HudHook_t)sub_10058150);
	engine->vfunc29("FaithCtrl", (HudHook_t)sub_10058170);
	engine->vfunc29("Health", (HudHook_t)sub_10058190);
	engine->vfunc29("AgrDmg", (HudHook_t)sub_100581b0);
	engine->vfunc29("Damage", (HudHook_t)sub_100581d0);
	engine->vfunc29("FeedBar", (HudHook_t)sub_100581f0);
	engine->vfunc29("BossHP", (HudHook_t)sub_10058210);
	engine->vfunc29("FrenzyBar", (HudHook_t)sub_10058230);
	engine->vfunc29("TraitFX", (HudHook_t)sub_10058250);
	engine->vfunc29("Discipline", (HudHook_t)sub_10058270);
	engine->vfunc29("RangedAcc", (HudHook_t)sub_100582b0);
	engine->vfunc29("ForceCam", (HudHook_t)sub_100582d0);
	engine->vfunc29("Credits", (HudHook_t)sub_100582f0);

	m_pChild = (HudChild_t *)new CHudManager(parent);
	ADD(new CDiscipline((int)m_pChild));
	ADD(new CBloodBar((int)m_pChild));
	ADD(new CFeedBar((int)m_pChild));
	ADD(new CBossHealthBar((int)m_pChild));
	ADD(new CFrenzyBar((int)m_pChild));
	ADD(new CHudDialog((int)m_pChild));
	ADD(new CHealthAnkh((int)m_pChild));
	ADD(new CHudUseIcon((int)m_pChild));
	ADD(new CHudInfo((int)m_pChild));
	ADD(new CStealth((int)m_pChild));
	ADD(new CProgBar((int)m_pChild));
	ADD(new CAmmoCounter((int)m_pChild));
	ADD(new CPhysicsHand((int)m_pChild));
	ADD(new CTargeted((int)m_pChild));
	ADD(new CItemInfo((int)m_pChild));
	ADD(new CMoneyBar((int)m_pChild));
	ADD(new CHudTimerUI((int)m_pChild));
	ADD(new CHudInfoBar((int)m_pChild));
	ADD(new CSignUI((int)m_pChild));
	ADD(new CHudAreaIcon((int)m_pChild));
	ADD(new CCredits((int)m_pChild));
	m_nCount = 0;
}
// END FUNCTION

// FUNCTION: 0x10058dc0 size=0xf
#include "CHudManagerPanel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual int f20(int); };
}
void CHudManagerPanel::vfunc1()
{
    if ((*(int *)((char *)this + 4)) != 0) {
        ((lifted::V *)(*(int *)((char *)this + 4)))->f20(1);
    }
}
// END FUNCTION

// FUNCTION: 0x10058dd0 size=0x1b
#include "C_BasePlayer.h"
#include "CHudManagerPanel.h"
bool sub_1018c770();
// TARGET: CHudManagerPanel::vfunc2
bool CHudManagerPanel::vfunc2(int)
{
	if (!C_BasePlayer::GetLocalPlayer())
		return true;
	return sub_1018c770() ? true : false;
}
// END FUNCTION

// FUNCTION: 0x10058df0 size=0xb
#include "CHudManagerPanel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual int f113(); };
}
int CHudManagerPanel::vfunc3()
{
    return ((lifted::V *)(*(int *)((char *)this + 4)))->f113();
}
// END FUNCTION

// FUNCTION: 0x10058e00 size=0xb
#include "CHudManagerPanel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual int f114(); };
}
int CHudManagerPanel::vfunc4()
{
    return ((lifted::V *)(*(int *)((char *)this + 4)))->f114();
}
// END FUNCTION

// FUNCTION: 0x10058e10 size=0xb
#include "CHudManagerPanel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual int f115(); };
}
int CHudManagerPanel::vfunc5()
{
    return ((lifted::V *)(*(int *)((char *)this + 4)))->f115();
}
// END FUNCTION

// FUNCTION: 0x10058e20 size=0x1a
#include "CHudManagerPanel.h"
// TARGET: CHudManagerPanel::vfunc6
void CHudManagerPanel::vfunc6()
{
	m_nCount++;
	if (m_pChild)
		m_pChild->v21(m_nCount <= 0);
}
// END FUNCTION

// FUNCTION: 0x10058e40 size=0x1a
#include "CHudManagerPanel.h"
// TARGET: CHudManagerPanel::vfunc7
void CHudManagerPanel::vfunc7()
{
	m_nCount--;
	if (m_pChild)
		m_pChild->v21(m_nCount <= 0);
}
// END FUNCTION

// FUNCTION: 0x10058e60 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057960 { int sub_10057960(); };
}
int CHudManagerPanel::vfunc10()
{
    return ((lifted::C10057960 *)(*(int *)((char *)this + 4)))->sub_10057960();
}
// END FUNCTION

// FUNCTION: 0x10058e70 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C100577f0 { int sub_100577f0(); };
}
int CHudManagerPanel::vfunc9()
{
    return ((lifted::C100577f0 *)(*(int *)((char *)this + 4)))->sub_100577f0();
}
// END FUNCTION

// FUNCTION: 0x10058e80 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057900 { int sub_10057900(); };
}
int CHudManagerPanel::vfunc24()
{
    return ((lifted::C10057900 *)(*(int *)((char *)this + 4)))->sub_10057900();
}
// END FUNCTION

// FUNCTION: 0x10058e90 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057840 { int sub_10057840(); };
}
int CHudManagerPanel::vfunc23()
{
    return ((lifted::C10057840 *)(*(int *)((char *)this + 4)))->sub_10057840();
}
// END FUNCTION

// FUNCTION: 0x10058ea0 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C100578a0 { int sub_100578a0(); };
}
int CHudManagerPanel::vfunc25()
{
    return ((lifted::C100578a0 *)(*(int *)((char *)this + 4)))->sub_100578a0();
}
// END FUNCTION

// FUNCTION: 0x10058eb0 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C100579c0 { int sub_100579c0(); };
}
int CHudManagerPanel::vfunc12()
{
    return ((lifted::C100579c0 *)(*(int *)((char *)this + 4)))->sub_100579c0();
}
// END FUNCTION

// FUNCTION: 0x10058ec0 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057a20 { int sub_10057a20(); };
}
int CHudManagerPanel::vfunc11()
{
    return ((lifted::C10057a20 *)(*(int *)((char *)this + 4)))->sub_10057a20();
}
// END FUNCTION

// FUNCTION: 0x10058ed0 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057a50 { int sub_10057a50(); };
}
int CHudManagerPanel::vfunc13()
{
    return ((lifted::C10057a50 *)(*(int *)((char *)this + 4)))->sub_10057a50();
}
// END FUNCTION

// FUNCTION: 0x10058ee0 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057ab0 { int sub_10057ab0(); };
}
int CHudManagerPanel::vfunc14()
{
    return ((lifted::C10057ab0 *)(*(int *)((char *)this + 4)))->sub_10057ab0();
}
// END FUNCTION

// FUNCTION: 0x10058ef0 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057b10 { int sub_10057b10(); };
}
int CHudManagerPanel::vfunc15()
{
    return ((lifted::C10057b10 *)(*(int *)((char *)this + 4)))->sub_10057b10();
}
// END FUNCTION

// FUNCTION: 0x10058f00 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057d40 { int sub_10057d40(); };
}
int CHudManagerPanel::vfunc16()
{
    return ((lifted::C10057d40 *)(*(int *)((char *)this + 4)))->sub_10057d40();
}
// END FUNCTION

// FUNCTION: 0x10058f10 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057b70 { int sub_10057b70(); };
}
int CHudManagerPanel::vfunc17()
{
    return ((lifted::C10057b70 *)(*(int *)((char *)this + 4)))->sub_10057b70();
}
// END FUNCTION

// FUNCTION: 0x10058f20 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057bd0 { int sub_10057bd0(); };
}
int CHudManagerPanel::vfunc18()
{
    return ((lifted::C10057bd0 *)(*(int *)((char *)this + 4)))->sub_10057bd0();
}
// END FUNCTION

// FUNCTION: 0x10058f30 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057ca0 { int sub_10057ca0(); };
}
int CHudManagerPanel::vfunc19()
{
    return ((lifted::C10057ca0 *)(*(int *)((char *)this + 4)))->sub_10057ca0();
}
// END FUNCTION

// FUNCTION: 0x10058f40 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057d00 { int sub_10057d00(); };
}
int CHudManagerPanel::vfunc26()
{
    return ((lifted::C10057d00 *)(*(int *)((char *)this + 4)))->sub_10057d00();
}
// END FUNCTION

// FUNCTION: 0x10058f50 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057d20 { int sub_10057d20(); };
}
int CHudManagerPanel::vfunc27()
{
    return ((lifted::C10057d20 *)(*(int *)((char *)this + 4)))->sub_10057d20();
}
// END FUNCTION

// FUNCTION: 0x10058f60 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057d50 { int sub_10057d50(); };
}
int CHudManagerPanel::vfunc20()
{
    return ((lifted::C10057d50 *)(*(int *)((char *)this + 4)))->sub_10057d50();
}
// END FUNCTION

// FUNCTION: 0x10058f70 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057dc0 { int sub_10057dc0(); };
}
int CHudManagerPanel::vfunc21()
{
    return ((lifted::C10057dc0 *)(*(int *)((char *)this + 4)))->sub_10057dc0();
}
// END FUNCTION

// FUNCTION: 0x10058f80 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057e20 { int sub_10057e20(); };
}
int CHudManagerPanel::vfunc22()
{
    return ((lifted::C10057e20 *)(*(int *)((char *)this + 4)))->sub_10057e20();
}
// END FUNCTION

// FUNCTION: 0x10058f90 size=0x8
#include "CHudManagerPanel.h"
namespace lifted {
struct C10057e70 { int sub_10057e70(); };
}
int CHudManagerPanel::vfunc28()
{
    return ((lifted::C10057e70 *)(*(int *)((char *)this + 4)))->sub_10057e70();
}
// END FUNCTION

// FUNCTION: 0x10058fa0 size=0x2a
#include "CHudManagerPanel.h"
namespace lifted {
extern char g_10272378;
extern char g_104cfe38;
bool sub_10052ed0();
struct C100f0ed0 { int sub_100f0ed0(int); };
struct C101a7a60 { int sub_101a7a60(int, int, int); };
}
void CHudManagerPanel::vfunc29()
{
    bool t0 = lifted::sub_10052ed0();
    if (t0 == 0) {
        int t1 = ((lifted::C100f0ed0 *)((int)&lifted::g_104cfe38))->sub_100f0ed0((int)&lifted::g_10272378);
        if (t1 != 0) {
            ((lifted::C101a7a60 *)t1)->sub_101a7a60(0, 0, 1);
        }
    }
}
// END FUNCTION

// FUNCTION: 0x10058fd0 size=0x2a
#include "CHudManagerPanel.h"
namespace lifted {
extern char g_10272378;
extern char g_104cfe38;
bool sub_10052ed0();
struct C100f0ed0 { int sub_100f0ed0(int); };
struct C101a7a60 { int sub_101a7a60(int, int, int); };
}
void CHudManagerPanel::vfunc30()
{
    bool t0 = lifted::sub_10052ed0();
    if (t0 == 0) {
        int t1 = ((lifted::C100f0ed0 *)((int)&lifted::g_104cfe38))->sub_100f0ed0((int)&lifted::g_10272378);
        if (t1 != 0) {
            ((lifted::C101a7a60 *)t1)->sub_101a7a60(1, 0, 1);
        }
    }
}
// END FUNCTION

// FUNCTION: 0x10059000 size=0x2a
#include "CHudManagerPanel.h"
namespace lifted {
extern char g_10272378;
extern char g_104cfe38;
bool sub_10052ed0();
struct C100f0ed0 { int sub_100f0ed0(int); };
struct C101a7a60 { int sub_101a7a60(int, int, int); };
}
void CHudManagerPanel::vfunc31()
{
    bool t0 = lifted::sub_10052ed0();
    if (t0 == 0) {
        int t1 = ((lifted::C100f0ed0 *)((int)&lifted::g_104cfe38))->sub_100f0ed0((int)&lifted::g_10272378);
        if (t1 != 0) {
            ((lifted::C101a7a60 *)t1)->sub_101a7a60(2, 0, 1);
        }
    }
}
// END FUNCTION

// FUNCTION: 0x10059030 size=0x2a
#include "CHudManagerPanel.h"
namespace lifted {
extern char g_10272378;
extern char g_104cfe38;
bool sub_10052ed0();
struct C100f0ed0 { int sub_100f0ed0(int); };
struct C101a7a60 { int sub_101a7a60(int, int, int); };
}
void CHudManagerPanel::vfunc32()
{
    bool t0 = lifted::sub_10052ed0();
    if (t0 == 0) {
        int t1 = ((lifted::C100f0ed0 *)((int)&lifted::g_104cfe38))->sub_100f0ed0((int)&lifted::g_10272378);
        if (t1 != 0) {
            ((lifted::C101a7a60 *)t1)->sub_101a7a60(3, 0, 1);
        }
    }
}
// END FUNCTION

// FUNCTION: 0x10059060 size=0x2a
#include "CHudManagerPanel.h"
namespace lifted {
extern char g_10272378;
extern char g_104cfe38;
bool sub_10052ed0();
struct C100f0ed0 { int sub_100f0ed0(int); };
struct C101a7a60 { int sub_101a7a60(int, int, int); };
}
void CHudManagerPanel::vfunc33()
{
    bool t0 = lifted::sub_10052ed0();
    if (t0 == 0) {
        int t1 = ((lifted::C100f0ed0 *)((int)&lifted::g_104cfe38))->sub_100f0ed0((int)&lifted::g_10272378);
        if (t1 != 0) {
            ((lifted::C101a7a60 *)t1)->sub_101a7a60(4, 0, 1);
        }
    }
}
// END FUNCTION

// FUNCTION: 0x10059090 size=0x1a
#include "CHudManagerPanel.h"
namespace lifted {
extern char g_102869b4;
extern int g_104a57d4;
bool sub_10052ed0();
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual int f28(int); };
}
void CHudManagerPanel::vfunc34()
{
    bool t0 = lifted::sub_10052ed0();
    if (t0 == 0) {
        ((lifted::V *)lifted::g_104a57d4)->f28((int)&lifted::g_102869b4);
    }
}
// END FUNCTION

// FUNCTION: 0x100590b0 size=0x1a
#include "CHudManagerPanel.h"
namespace lifted {
extern char g_102869c8;
extern int g_104a57d4;
bool sub_10052ed0();
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual int f28(int); };
}
void CHudManagerPanel::vfunc35()
{
    bool t0 = lifted::sub_10052ed0();
    if (t0 == 0) {
        ((lifted::V *)lifted::g_104a57d4)->f28((int)&lifted::g_102869c8);
    }
}
// END FUNCTION

// FUNCTION: 0x100590d0 size=0x2a
#include "CHudManagerPanel.h"
namespace lifted {
extern char g_10272378;
extern char g_104cfe38;
bool sub_10052ed0();
struct C100f0ed0 { int sub_100f0ed0(int); };
struct C101a7a60 { int sub_101a7a60(int, int, int); };
}
void CHudManagerPanel::vfunc36()
{
    bool t0 = lifted::sub_10052ed0();
    if (t0 == 0) {
        int t1 = ((lifted::C100f0ed0 *)((int)&lifted::g_104cfe38))->sub_100f0ed0((int)&lifted::g_10272378);
        if (t1 != 0) {
            ((lifted::C101a7a60 *)t1)->sub_101a7a60(7, 0, 1);
        }
    }
}
// END FUNCTION

// FUNCTION: 0x10059100 size=0xa9
#include "CHudManagerPanel.h"
#include "C_BasePlayer.h"
#include "CHud.h"
#include "engineclient.h"
#include <stdlib.h>
extern "C" __declspec(dllimport) int __cdecl Q_snprintf(char *, unsigned int, const char *, ...);
struct HudElemX { char m_pad[0x1c]; bool m_bFlag; };
void sub_1004f810();
// TARGET: CHudManagerPanel::vfunc37
void CHudManagerPanel::vfunc37()
{
	C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
	if (pPlayer && engine->vfunc63() == 2)
	{
		bool bChanged;
		char szCmd[0x30];
		int nDiscipline = atoi(engine->Cmd_Argv(1) + 1) - 1;
		int nValue = pPlayer->sub_100a94d0(nDiscipline, &bChanged);
		Q_snprintf(szCmd, 0x30, "vdiscipline_int %d", nValue);
		if (((HudElemX *)gHUD.FindElement("CHudWeaponSelection"))->m_bFlag)
			pPlayer->vfunc160(false);
		if (bChanged)
		{
			sub_1004f810();
			engine->vfunc27(szCmd, 1);
		}
	}
}
// END FUNCTION

// FUNCTION: 0x100591b0 size=0x91
#include "C_BasePlayer.h"
#include "engineclient.h"
#include "CHudManagerPanel.h"
#include "CHud.h"
#include "Tier1.h"
#include <stdlib.h>
struct PV_100591b0 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
	virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
	virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
	virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
	virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
	virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
	virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
	virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
	virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104();
	virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
	virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114();
	virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
	virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124();
	virtual void v125(); virtual void v126(); virtual void v127(); virtual void v128(); virtual void v129();
	virtual void v130(); virtual void v131(); virtual void v132(); virtual void v133(); virtual void v134();
	virtual void v135(); virtual void v136(); virtual void v137(); virtual void v138(); virtual void v139();
	virtual void v140(); virtual void v141(); virtual void v142(); virtual void v143(); virtual void v144();
	virtual void v145(); virtual void v146(); virtual void v147(); virtual void v148(); virtual void v149();
	virtual void v150(); virtual void v151(); virtual void v152(); virtual void v153(); virtual void v154();
	virtual void v155(); virtual void v156(); virtual void v157(); virtual void v158(); virtual void v159();
	virtual void Select(int);
};
struct HE_100591b0 { char m_pad[0x1c]; char m_b; };
extern CHud g_104cfe38;
extern char sub_10052ed0();

void CHudManagerPanel::vfunc38()
{
	PV_100591b0 *p = ((PV_100591b0 *)C_BasePlayer::GetLocalPlayer());
	if (p && !sub_10052ed0()) {
		if (engine->vfunc63() == 2) {
			char buf[0x30];
			g_101e3190(buf, 0x30, "vhotkey_int %d", atoi(engine->Cmd_Argv(1) + 1) - 1);
			if (((HE_100591b0 *)g_104cfe38.sub_100f0ed0("CHudWeaponSelection"))->m_b)
				p->Select(0);
			engine->vfunc27(buf, 1);
		}
	}
}
// END FUNCTION
