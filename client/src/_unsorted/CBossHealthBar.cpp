// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1004d4b0 size=0xc6
#include "CBossHealthBar.h"
char *sub_1018c870(const char *);
CBossHealthBar::CBossHealthBar(int a)
    : CManagedHudElement(a, (int)"BossHP")
{
	sub_1004d610();
	vfunc63(0);
	sub_101a9890(m_unk178, m_unk17c);
	sub_101a98f0(m_unk180, m_unk184);
	m_b198 = 0;
	m_b19a = 0;
	m_b199 = 0;
	m_unk194 = 0xff;
	m_pChild2 = 0;
	m_pChild1 = 0;
	sub_1004d710(0, 0, 0, 1);
	IFontLike *p = sub_101ac830();
	m_nFont = p->GetFont(sub_1018c870("Copperplate"));
	sub_1004d850();
}
// END FUNCTION

// FUNCTION: 0x1004d5a0 size=0x1e
#include "CBossHealthBar.h"

// VC6 writes CBossHealthBar's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CBossHealthBar *pcd_emit_1004d5a0(const CBossHealthBar &other) { return new CBossHealthBar(other); }

// TARGET: ??_GCBossHealthBar@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1004d5c0 size=0x42
#include "CBossHealthBar.h"
// TARGET: ??1CBossHealthBar@@UAE@XZ
CBossHealthBar::~CBossHealthBar()
{
	sub_101a9ff0(0);
	delete m_pChild1;
	delete m_pChild2;
}
// END FUNCTION

// FUNCTION: 0x1004d820 size=0x23
#include "CBossHealthBar.h"
bool sub_10163bf0();
struct IUnkG286860 { virtual void v0(); virtual void v1(); virtual bool Check(int); };
extern IUnkG286860 *g_10286860;
bool CBossHealthBar::vfunc107()
{
	return sub_10163bf0() && !g_10286860->Check(0);
}
// END FUNCTION

// FUNCTION: 0x1004d850 size=0x2a
#include "CBossHealthBar.h"
struct CSub170 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(int); };
void CBossHealthBar::vfunc112()
{
	m_unk1bc = 0;
	((CSub170 *)((char *)this + 0x170))->v5(0);
	m_unk1a0 = 0;
}
// END FUNCTION

// FUNCTION: 0x1004d880 size=0x8
#include "CBossHealthBar.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual int f112(); };
}
void CBossHealthBar::vfunc113()
{
    ((lifted::V *)this)->f112();
}
// END FUNCTION

// FUNCTION: 0x1004d890 size=0x33e
#include "CBossHealthBar.h"
#include "CHUDSprite.h"
#include "ConVar.h"
#include "CInput.h"
#include "engineclient.h"

extern ConVar g_105faa30;
int sub_100cd100();

struct BarRect { int left; int right; int top; int bottom; };

#define BAR_MIN(a, b) (((a) > (b)) ? (b) : (a))
#define BAR_MAX(a, b) (((a) >= (b)) ? (a) : (b))

void CBossHealthBar::vfunc98()
{
	static ConVar *s_pHideVGui = cvar->FindVar("v_hidevgui");
	if (s_pHideVGui && s_pHideVGui->GetBool())
		return;
	if (!g_105faa30.GetBool())
		return;
	if (input->vfunc52() > 0.0f)
		return;

	if (!m_pChild1)
	{
		m_pChild2 = new CHUDSprite("hud/BloodBar_Empty", 0, 0, 0x200, 0x40, 0x200, 0x40);
		m_pChild1 = new CHUDSprite("hud/BloodBar_Full", 0, 0, 0x200, 0x40, 0x200, 0x40);
	}

	int x, y;
	sub_101a98c0(&x, &y);

	if (m_b199 && m_unk194 < 255)
		m_unk194 = BAR_MIN(m_unk194 + 5, 255);
	else if (m_b19a && m_unk194 > 0)
		m_unk194 = BAR_MAX(m_unk194 - 5, 0);

	for (int i = 0; i < m_unk1a0; i++)
	{
		int h = 360 - m_unk1a4[i] * 360 / 100;
		{
			BarRect rect;
			rect.left = 0;
			rect.right = 0x200;
			rect.top = 0;
			rect.bottom = 0x40;
			m_pChild2->sub_1005c430(x, m_unk184 * i + y, m_unk180, m_unk184, (int)&rect, m_unk194);
			rect.left = h + 0x4b;
			rect.top = 0;
			rect.right = 0x1b3;
			rect.bottom = 0x40;
			m_pChild1->sub_1005c430(m_unk18c + x, m_unk184 * i + y,
				(int)((m_unk180 - m_unk18c) - rect.left * (sub_100cd100() / 1024.0)),
				m_unk184, (int)&rect, m_unk194);
		}
		if (m_unk1ac[i])
		{
			int w = g_pMatSystemSurface->vfunc15(m_nFont, m_unk1ac[i]);
			int th;
			g_pMatSystemSurface->vfunc14(m_nFont, w, &th, m_unk1ac[i]);
			g_pMatSystemSurface->vfunc12(m_nFont, (m_unk180 - w) / 2, (i + 1) * m_unk184 - th, 0xff, 0xff, 0xff, m_unk194, m_unk1ac[i]);
		}
	}
}
// END FUNCTION

// FUNCTION: 0x1004dbd0 size=0x1
#include "CBossHealthBar.h"
void CBossHealthBar::vfunc97()
{
}
// END FUNCTION
