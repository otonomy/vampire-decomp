// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101670d0 size=0x351
#include "CLoadingDiscPanel.h"
#include "vgui2__TextEntry.h"

extern "C" __declspec(dllimport) void Msg(const char *pMsg, ...);

int sub_100cd0f0();
int sub_100cd100();
const char *sub_1018c870(const char *);

struct ISchemeMgrView
{
	virtual void v0();
	virtual int LoadSchemeFromFile(const char *file);
};
ISchemeMgrView *sub_101ac8c0();

struct ISurfaceView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26();
	virtual void DrawSetTextureFile(int id, const char *name, int hardwareFilter);
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void DrawGetTextureSize(int id, int &wide, int &tall);
	virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
	virtual void v37();
	virtual int CreateNewTextureID(int procedural);
};
ISurfaceView *sub_101ac8d0();

struct SColor
{
	int raw;
	SColor() {}
};

struct ISchemeView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual int GetFont(const char *name);
	virtual void v5();
	virtual SColor GetColor(const char *name);
};

struct Color
{
	unsigned char r, g, b, a;
	Color(int _r, int _g, int _b, int _a) { r = _r; g = _g; b = _b; a = _a; }
};

struct PanelSetScheme
{
	void sub_101aa230(int scheme);
};

struct TextEntryCtor
{
	vgui2::TextEntry *sub_101acaa0(vgui2::Panel *parent, const char *name);
};

#define FIELD(off) (*(int *)((char *)this + (off)))

CLoadingDiscPanel::CLoadingDiscPanel(vgui2::Panel *parent)
	: vgui2::Panel(parent, "CLoadingDiscPanel")
{
	int scheme = sub_101ac8c0()->LoadSchemeFromFile("Resource/VampireScheme.res");
	if (!scheme)
		Msg("Error loading '%s'\n", "Resource/VampireScheme.res");
	((PanelSetScheme *)(void *)this)->sub_101aa230(scheme);
	sub_101a99f0(0);
	vfunc54(0);
	Color col(0, 0, 0, 255);
	vfunc51(*(int *)&col);
	vfunc63(0);
	FIELD(0x88) = 0xff;

	FIELD(0x58) = sub_101ac8d0()->CreateNewTextureID(0);
	FIELD(0x64) = sub_101ac8d0()->CreateNewTextureID(0);
	FIELD(0x70) = sub_101ac8d0()->CreateNewTextureID(0);
	FIELD(0x7c) = sub_101ac8d0()->CreateNewTextureID(0);
	sub_101ac8d0()->DrawSetTextureFile(FIELD(0x58), "interface/TipInfoScreen/LoadingBar_Empty", 0);
	sub_101ac8d0()->DrawGetTextureSize(FIELD(0x58), FIELD(0x5c), FIELD(0x60));
	sub_101ac8d0()->DrawSetTextureFile(FIELD(0x64), "interface/TipInfoScreen/LoadingBar_Full", 0);
	sub_101ac8d0()->DrawGetTextureSize(FIELD(0x64), FIELD(0x68), FIELD(0x6c));
	sub_101ac8d0()->DrawSetTextureFile(FIELD(0x70), "interface/TipInfoScreen/Background_Default", 0);
	sub_101ac8d0()->DrawGetTextureSize(FIELD(0x70), FIELD(0x74), FIELD(0x78));
	sub_101ac8d0()->DrawSetTextureFile(FIELD(0x7c), "interface/TipInfoScreen/Overlay_Info", 0);
	sub_101ac8d0()->DrawGetTextureSize(FIELD(0x7c), FIELD(0x80), FIELD(0x84));

	sub_101a98f0(sub_100cd100(), sub_100cd0f0());
	sub_101a9890(0, 0);

	ISchemeView *pScheme = (ISchemeView *)sub_101ac830();
	FIELD(0x98) = pScheme->GetFont(sub_1018c870("PercolatorSmall"));
	FIELD(0x9c) = pScheme->GetFont(sub_1018c870("Dlg_Base"));

	void *mem = vgui2::Panel::operator new(0x128);
	vgui2::TextEntry *pText = mem ? ((TextEntryCtor *)mem)->sub_101acaa0(this, "TxtHelp") : 0;
	*(vgui2::TextEntry **)((char *)this + 0x94) = pText;
	pText->vfunc132(FIELD(0x98));
	pText->vfunc107("");
	pText->vfunc51(pScheme->GetColor("TitleText").raw);
	pText->vfunc50(pScheme->GetColor("GhostControlBG").raw);
	pText->sub_101a9950((int)(217.0 * (sub_100cd100() / 1024.0)),
		(int)(191.0 * (sub_100cd0f0() / 768.0)),
		(int)(595.0 * (sub_100cd100() / 1024.0)),
		(int)(323.0 * (sub_100cd0f0() / 768.0)));
	pText->vfunc138(1);
	pText->vfunc140(0);
	pText->vfunc134(0);
	pText->vfunc62(0);
}
// END FUNCTION

// FUNCTION: 0x10167430 size=0x1e
#include "CLoadingDiscPanel.h"

// VC6 writes CLoadingDiscPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CLoadingDiscPanel *pcd_emit_10167430(const CLoadingDiscPanel &other) { return new CLoadingDiscPanel(other); }

// TARGET: ??_GCLoadingDiscPanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10167460 size=0x4c4
#include "CLoadingDiscPanel.h"
#include "engineclient.h"
#include "CGlobalVarsBase.h"
#include "ScopeTrace.h"

struct LDColor
{
	unsigned char m_c[4];
	LDColor() {}
};

#define LDV10(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();

struct LDSurface
{
	LDV10(a)
	virtual void s10();
	virtual void DrawSetColor(int r, int g, int b, int a);
	virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
	virtual void DrawSetTextureFile(int id, const char *filename, int hardwareFilter);
	virtual void s28(); virtual void s29(); virtual void s30();
	virtual void DrawSetTexture(int id);
	virtual void DrawGetTextureSize(int id, int &wide, int &tall);
	virtual void DrawTexturedRect(int x0, int y0, int x1, int y1);
	virtual void s34();
	virtual void DrawTexturedSubRect(int x0, int y0, int x1, int y1, float s0, float t0, float s1, float t1);
};

struct LDLabel
{
	LDV10(a0) LDV10(a1) LDV10(a2) LDV10(a3) LDV10(a4)
	virtual void b50();
	virtual void SetFgColor(LDColor color);
	virtual void b52();
	virtual LDColor GetFgColor();
	virtual void b54(); virtual void b55(); virtual void b56(); virtual void b57(); virtual void b58(); virtual void b59();
	LDV10(a6) LDV10(a7) LDV10(a8) LDV10(a9)
	virtual void c100();
	virtual void SizeToContents();
	virtual void c102(); virtual void c103(); virtual void c104(); virtual void c105(); virtual void c106();
	virtual void SetText(const char *text);
	virtual void c108(); virtual void c109();
	LDV10(d11) LDV10(d12)
	virtual void e130(); virtual void e131();
	virtual void SetFont(int font);
};

struct LDTip
{
	int m_n0; int m_n4;
	int m_nType;	// 0x08
	const char *sub_10151780();
	const char *sub_10151790();
	const char *sub_101517a0();
};

struct LDTipMgr
{
	LDTip *sub_10151b20();
	void sub_10151c60(int a, int b, int c, int d, const char *pszName);
};

extern LDSurface *sub_101ac8d0();
extern int sub_100cd0f0();
extern int sub_100cd100();
extern LDTip *g_105fad04;
extern LDTipMgr g_105e8668;

struct LDPanelSize
{
	void sub_101a9920(int &wide, int &tall);
};

#define m_iProgressTex (*(int *)((char *)this + 0x58))
#define m_iProgressW (*(int *)((char *)this + 0x5c))
#define m_iProgressH (*(int *)((char *)this + 0x60))
#define m_iProgressTex2 (*(int *)((char *)this + 0x64))
#define m_iBgTex (*(int *)((char *)this + 0x70))
#define m_iBgW (*(int *)((char *)this + 0x74))
#define m_iBgH (*(int *)((char *)this + 0x78))
#define m_iOvTex (*(int *)((char *)this + 0x7c))
#define m_iOvW (*(int *)((char *)this + 0x80))
#define m_iOvH (*(int *)((char *)this + 0x84))
#define m_iAlpha (*(int *)((char *)this + 0x88))
#define m_bDone (*(bool *)((char *)this + 0x8c))
#define m_flDoneTime (*(float *)((char *)this + 0x90))
#define m_pTipLabel (*(LDLabel **)((char *)this + 0x94))
#define m_hFont1 (*(int *)((char *)this + 0x98))
#define m_hFont2 (*(int *)((char *)this + 0x9c))

#define LD_XRES(x) ((x) * ((float)sub_100cd100() / 1024.0))
#define LD_YRES(y) ((y) * ((float)sub_100cd0f0() / 768.0))

void CLoadingDiscPanel::vfunc98()
{
	int wide, tall;
	int alpha = m_iAlpha;
	((LDPanelSize *)this)->sub_101a9920(wide, tall);

	if (!g_105fad04 || g_105fad04 != g_105e8668.sub_10151b20())
	{
		g_105fad04 = g_105e8668.sub_10151b20();
		if (!g_105fad04)
		{
			g_105e8668.sub_10151c60(0, 0, -6, -1, "interface/TipInfoScreen/Background_Default");
			g_105fad04 = g_105e8668.sub_10151b20();
		}
		if (g_105fad04)
		{
			if (g_105fad04->m_nType == 2)
				m_pTipLabel->SetFont(m_hFont1);
			else
				m_pTipLabel->SetFont(m_hFont2);
			m_pTipLabel->SetText(g_105fad04->sub_10151780());
			m_pTipLabel->SizeToContents();
			const char *pszImage = g_105fad04->sub_10151790();
			if (pszImage)
			{
				sub_101ac8d0()->DrawSetTextureFile(m_iBgTex, pszImage, 0);
				sub_101ac8d0()->DrawGetTextureSize(m_iBgTex, m_iBgW, m_iBgH);
			}
			const char *pszOverlay = g_105fad04->sub_101517a0();
			if (pszOverlay)
			{
				sub_101ac8d0()->DrawSetTextureFile(m_iOvTex, pszOverlay, 0);
				sub_101ac8d0()->DrawGetTextureSize(m_iOvTex, m_iOvW, m_iOvH);
			}
		}
		else
		{
			m_pTipLabel->SetText(g_102de300);
			sub_101ac8d0()->DrawSetTextureFile(m_iBgTex, "interface/TipInfoScreen/Background_Default", 0);
			sub_101ac8d0()->DrawGetTextureSize(m_iBgTex, m_iBgW, m_iBgH);
			sub_101ac8d0()->DrawSetTextureFile(m_iOvTex, "interface/TipInfoScreen/Overlay_Info", 0);
			sub_101ac8d0()->DrawGetTextureSize(m_iOvTex, m_iOvW, m_iOvH);
		}
	}

	LDColor col = m_pTipLabel->GetFgColor();
	col.m_c[3] = alpha;
	m_pTipLabel->SetFgColor(col);

	sub_101ac8d0()->DrawSetTexture(m_iBgTex);
	sub_101ac8d0()->DrawSetColor(255, 255, 255, alpha);
	sub_101ac8d0()->DrawTexturedRect(0, 0, wide, tall);
	sub_101ac8d0()->DrawSetTexture(m_iOvTex);
	sub_101ac8d0()->DrawSetColor(255, 255, 255, alpha);
	sub_101ac8d0()->DrawTexturedRect(0, 0, wide, tall);

	int y = (int)LD_YRES(650);
	int x0; x0 = (int)LD_XRES(190);
	float s0 = 190.0f / m_iProgressW;
	int x1 = (int)LD_XRES(830);
	float s1 = 830.0f / m_iProgressW;
	int x2 = (int)LD_XRES(152);
	float s2 = 152.0f / m_iProgressW;
	int x3 = (int)LD_XRES(869);
	float s3 = 869.0f / m_iProgressW;

	int progress;
	if (!m_bDone)
	{
		progress = engine->vfunc59();
		if (!progress)
		{
			float t0 = gpGlobals->curtime; float dt = t0 - m_flDoneTime;
			if (dt < 1.0)
				progress = engine->vfunc59();
		}
	}
	else
		progress = 100;
	if (100 <= progress)
		m_flDoneTime = gpGlobals->curtime;

	float frac = 0.01f * progress;
	if (frac > 1.0f)
		frac = 1.0;

	sub_101ac8d0()->DrawSetTexture(m_iProgressTex);
	sub_101ac8d0()->DrawSetColor(255, 255, 255, alpha);
	sub_101ac8d0()->DrawTexturedSubRect(x2, y, x3, y + m_iProgressH, s2, 0, s3, 1.0f);

	sub_101ac8d0()->DrawSetTexture(m_iProgressTex2);
	sub_101ac8d0()->DrawSetColor(255, 255, 255, alpha);
	sub_101ac8d0()->DrawTexturedSubRect(x0, y, x0 + (int)(frac * (x1 - x0)), y + m_iProgressH, s0, 0, (s1 - s0) * frac + s0, 1.0f);
}
// END FUNCTION
