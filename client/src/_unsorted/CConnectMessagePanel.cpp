// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10165170 size=0xc5
#include "engineclient.h"
#include "CConnectMessagePanel.h"

int sub_100cd0f0();
int sub_100cd100();
int sub_101ac8f0();

struct PanelV21
{
	void sub_101a99f0(int);
};


struct IVGui
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17();
	virtual void AddTickSignal(int vpanel, int tick);
};

struct Color
{
	unsigned char r, g, b, a;
	Color(int _r, int _g, int _b, int _a) { r = _r; g = _g; b = _b; a = _a; }
};

CConnectMessagePanel::CConnectMessagePanel(vgui2::Panel *parent)
	: vgui2::Panel(parent, "CConnectMessagePanel")
{
	sub_101a98f0(sub_100cd100(), sub_100cd0f0());
	sub_101a9890(0, 0);
	((PanelV21 *)(void *)this)->sub_101a99f0(0);
	vfunc54(0);

	Color col(0, 0, 0, 0);
	*(int *)((char *)this + 0x58) = 0;
	vfunc51(*(int *)&col);
	vfunc63(0);

	*(int *)((char *)this + 0x5c) = ((int)cvar->FindVar("scr_connectmsg"));
	*(int *)((char *)this + 0x60) = ((int)cvar->FindVar("scr_connectmsg1"));
	*(int *)((char *)this + 0x64) = ((int)cvar->FindVar("scr_connectmsg2"));

	int vp = *(int *)((char *)this + 4);
	((IVGui *)(void *)sub_101ac8f0())->AddTickSignal(vp, 200);
}
// END FUNCTION

// FUNCTION: 0x10165240 size=0x1e
#include "CConnectMessagePanel.h"

// VC6 writes CConnectMessagePanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CConnectMessagePanel *pcd_emit_10165240(const CConnectMessagePanel &other) { return new CConnectMessagePanel(other); }

// TARGET: ??_GCConnectMessagePanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10165270 size=0x22
#include "CConnectMessagePanel.h"
namespace lifted {
extern char g_102cdd40;
struct C101ab490 { int sub_101ab490(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(int); };
}
int CConnectMessagePanel::vfunc74(int a0)
{
    ((lifted::C101ab490 *)this)->sub_101ab490(a0);
    *(int *)((char *)this + 0x58) = ((lifted::V *)a0)->f4((int)&lifted::g_102cdd40);
    return *(int *)((char *)this + 0x58);
}
// END FUNCTION

// FUNCTION: 0x101652a0 size=0x15
#include "CConnectMessagePanel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual int f107(); };
}
void CConnectMessagePanel::vfunc2()
{
    ((lifted::V *)this)->f21(((lifted::V *)this)->f107());
}
// END FUNCTION

// FUNCTION: 0x101652c0 size=0x54
#include "CConnectMessagePanel.h"
#include "ConVar.h"

static __forceinline const char *ConVarString(ConVar *p)
{
	if ( p->m_pParent->vfunc1() )
		return "";
	if ( p->m_nFlags & 0x1000 )
		return "FCVAR_NEVER_AS_STRING";
	p = p->m_pParent;
	if ( p->m_pszString )
		return p->m_pszString;
	return "";
}

// TARGET: CConnectMessagePanel::vfunc107
char CConnectMessagePanel::vfunc107()
{
	ConVar *pA = *(ConVar **)((char *)this + 0x5c);
	void *pB = *(void **)((char *)this + 0x60);
	void *pC = *(void **)((char *)this + 0x64);
	if ( !pA || !pB || !pC )
		return 0;
	return ConVarString(pA)[0] != '0';
}
// END FUNCTION
