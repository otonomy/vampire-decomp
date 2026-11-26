// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100509c0 size=0x9e
#include "CFrenzyBar.h"
// TARGET: ??0CFrenzyBar@@QAE@H@Z
CFrenzyBar::CFrenzyBar(int parent) : CManagedHudElement(parent, (int)"FrenzyBar")
{
	sub_10050af0();
	vfunc63(0);
	sub_101a9890(m_unk178, m_unk17c);
	sub_101a98f0(m_unk188, m_unk18c);
	m_unk194 = 0;
	m_unk196 = 0;
	m_unk195 = 0;
	m_unk190 = 0xff;
	m_pChild2 = 0;
	m_pChild1 = 0;
	sub_10050ba0(11, 0);
	vfunc112();
}
// END FUNCTION

// FUNCTION: 0x10050a80 size=0x1e
#include "CFrenzyBar.h"

// VC6 writes CFrenzyBar's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CFrenzyBar *pcd_emit_10050a80(const CFrenzyBar &other) { return new CFrenzyBar(other); }

// TARGET: ??_GCFrenzyBar@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10050aa0 size=0x42
#include "CFrenzyBar.h"
// TARGET: ??1CFrenzyBar@@UAE@XZ
CFrenzyBar::~CFrenzyBar()
{
	sub_101a9ff0(0);
	delete m_pChild1;
	delete m_pChild2;
}
// END FUNCTION

// FUNCTION: 0x10050c80 size=0x23
#include "CFrenzyBar.h"
bool sub_10163bf0();
struct IUnkG286860 { virtual void v0(); virtual void v1(); virtual bool Check(int); };
extern IUnkG286860 *g_10286860;
bool CFrenzyBar::vfunc107()
{
	return sub_10163bf0() && !g_10286860->Check(0);
}
// END FUNCTION

// FUNCTION: 0x10050cb0 size=0x1a
#include "CFrenzyBar.h"
namespace lifted {
extern int g_103ede98;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual int f5(int); };
}
void CFrenzyBar::vfunc112()
{
    *(int *)((char *)this + 0x19c) = 0;
    lifted::g_103ede98 = 0;
    ((lifted::V *)((int)this + 0x170))->f5(0);
}
// END FUNCTION

// FUNCTION: 0x10050cd0 size=0x8
#include "CFrenzyBar.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual int f112(); };
}
void CFrenzyBar::vfunc113()
{
    ((lifted::V *)this)->f112();
}
// END FUNCTION

// FUNCTION: 0x10050ce0 size=0x22d
#include "CFrenzyBar.h"
#include "CHUDSprite.h"
struct PlayerV5a80 { bool sub_100a5a80(); };
struct PanelV170 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void SetVisible(bool b); };
struct TimeV { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual double GetTime(int a); };
extern TimeV *g_104a57d4;
extern PlayerV5a80 *g_104a0d50;
int sub_100cd100();
struct RectV { int left; int right; int top; int bottom; };
// TARGET: CFrenzyBar::vfunc98
void CFrenzyBar::vfunc98()
{
	double limit = m_unk19c;
	if (g_104a57d4->GetTime(0) >= limit)
	{
		((PanelV170 *)((char *)this + 0x170))->SetVisible(false);
		return;
	}
	if (g_104a0d50 && g_104a0d50->sub_100a5a80())
	{
		m_unk19c = 0.01f;
		((PanelV170 *)((char *)this + 0x170))->SetVisible(false);
		return;
	}
	if (!m_pChild1)
	{
		m_pChild2 = (CFrenzyBarOwned *)new CHUDSprite("hud/FrenzyBar_Empty", 0, 0, 512, 64, 512, 64);
		m_pChild1 = (CFrenzyBarOwned *)new CHUDSprite("hud/FrenzyBar_Full", 0, 0, 512, 64, 512, 64);
	}
	int x, y;
	sub_101a98c0(&x, &y);
	int a;
	if (m_unk195 && m_unk190 < 255)
	{
		a = m_unk190 + 5;
		if (a > 255)
			a = 255;
		goto store;
	}
	if (m_unk196 && m_unk190 > 0)
	{
		a = m_unk190 - 5;
		a = a & ((a < 0) - 1);
store:
		m_unk190 = a;
	}
	int h = m_unk180 - m_unk198 * m_unk180 / 100;
	RectV rc;
	rc.left = 0;
	rc.right = m_unk180;
	rc.top = 0;
	rc.bottom = m_unk184;
	((CHUDSprite *)m_pChild2)->sub_1005c3b0(x, y, m_unk188, m_unk18c, (int)&rc);
	rc.left = h;
	rc.right = m_unk180;
	rc.top = 0;
	rc.bottom = m_unk184;
	((CHUDSprite *)m_pChild1)->sub_1005c3b0(x, y, (int)(m_unk188 - h * (sub_100cd100() * 0.0009765625)), m_unk18c, (int)&rc);
}
// END FUNCTION

// FUNCTION: 0x10050f10 size=0x1
#include "CFrenzyBar.h"
void CFrenzyBar::vfunc97()
{
}
// END FUNCTION
