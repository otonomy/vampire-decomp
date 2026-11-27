// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10164b50 size=0xc7
#include "CCenterStringPanel.h"

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

CCenterStringPanel::CCenterStringPanel(vgui2::Panel *parent)
	: vgui2::Panel(parent, "CCenterStringPanel")
{
	sub_101a98f0(sub_100cd100(), sub_100cd0f0());
	sub_101a9890(0, 0);
	((PanelV21 *)(void *)this)->sub_101a99f0(0);
	vfunc54(0);

	Color col(0, 0, 0, 0);
	*(int *)((char *)this + 0x58) = 0;
	vfunc51(*(int *)&col);
	vfunc63(0);

	int vp = *(int *)((char *)this + 4);
	*(char *)((char *)this + 0x5c) = 0;
	*(int *)((char *)this + 0x45c) = 0;
	*(int *)((char *)this + 0x460) = 0;
	*(int *)((char *)this + 0x464) = 0;
	*(int *)((char *)this + 0x468) = 0;
	*(int *)((char *)this + 0x46c) = 0;
	*(int *)((char *)this + 0x478) = 0xff;
	*(int *)((char *)this + 0x474) = 0xff;
	*(int *)((char *)this + 0x470) = 0xff;
	*(int *)((char *)this + 0x47c) = 0xff;

	((IVGui *)(void *)sub_101ac8f0())->AddTickSignal(vp, 100);
}
// END FUNCTION

// FUNCTION: 0x10164c20 size=0x5
#include "CCenterStringPanel.h"
bool CCenterStringPanel::vfunc25(int a0, int a1)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10164c30 size=0x1e
#include "CCenterStringPanel.h"

// VC6 writes CCenterStringPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CCenterStringPanel *pcd_emit_10164c30(const CCenterStringPanel &other) { return new CCenterStringPanel(other); }

// TARGET: ??_GCCenterStringPanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10164c60 size=0x22
#include "CCenterStringPanel.h"
namespace lifted {
extern char g_102cdb34;
struct C101ab490 { int sub_101ab490(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(int); };
}
int CCenterStringPanel::vfunc74(int a0)
{
    ((lifted::C101ab490 *)this)->sub_101ab490(a0);
    *(int *)((char *)this + 0x58) = ((lifted::V *)a0)->f4((int)&lifted::g_102cdb34);
    return *(int *)((char *)this + 0x58);
}
// END FUNCTION

// FUNCTION: 0x10164c90 size=0x131
#include "engineclient.h"
#include "CCenterStringPanel.h"
extern "C" __declspec(dllimport) char *Q_strncpy(char *, const char *, int);
int sub_100cd0f0();
int sub_100cd100();
struct V105faacc { virtual void v0(); virtual void v1(); };
extern V105faacc *g_105faacc;
struct IFontTall { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual int v63(int font); };
IFontTall *sub_101ac8d0();
struct CenterView {
	char pad[0x58];
	int m_font;
	char m_text[0x408];
	int m_n464;
	int m_n468;
	int m_n46c;
	int m_r;
	int m_g;
	int m_b;
	int m_a;
};
void CCenterStringPanel::vfunc98()
{
	CenterView *v = (CenterView *)this;
	if (render->vfunc37()) {
		g_105faacc->v1();
		engine->Time(0);
	}
	int n = v->m_n464;
	v->m_n46c = 0;
	char *p = v->m_text;
	int y;
	if (n <= 4)
		y = (int)(sub_100cd0f0() * 0.35);
	else
		y = 0x30;
	for (;;) {
		char line[0x28];
		Q_strncpy(line, p, 0x28);
		int i = 0;
		while (line[i] && line[i] != '\n')
			i++;
		line[i] = 0;
		int w = g_pMatSystemSurface->vfunc15(v->m_font, line);
		int x = (sub_100cd100() - w) / 2;
		g_pMatSystemSurface->vfunc12(v->m_font, x, y, v->m_r, v->m_g, v->m_b, v->m_a, line);
		y += sub_101ac8d0()->v63(v->m_font);
		while (*p && *p != '\n')
			p++;
		if (!*p)
			break;
		p++;
	}
}
// END FUNCTION

// FUNCTION: 0x10164dd0 size=0x2b
#include "CCenterStringPanel.h"
int CCenterStringPanel::vfunc108(int a0, int a1, int a2, int a3)
{
    *(int *)((char *)this + 0x470) = a0;
    *(int *)((char *)this + 0x474) = a1;
    *(int *)((char *)this + 0x478) = a2;
    *(int *)((char *)this + 0x47c) = a3;
    return a2;
}
// END FUNCTION

// FUNCTION: 0x10164e00 size=0xaa
#include "engineclient.h"
#include "CCenterStringPanel.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

struct IA10164e00 { virtual void v0(); virtual bool v1(); char pad[0x28 - 4]; float m_f28; };
extern IA10164e00 *g_105faa84;
extern char *(__cdecl *g_101e3188)(char *, const char *, int);

struct View10164e00
{
	int vt;
	char pad[0x5c - 4];
	char m_szText[0x400];
	float m_f45c;
	float m_f460;
	int m_nLines;
};

void CCenterStringPanel::vfunc109(const char *fmt, ...)
{
	char buf[1024];
	va_list args;
	va_start(args, fmt);
	_vsnprintf(buf, sizeof(buf), fmt, args);
	View10164e00 *v = (View10164e00 *)this;
	g_101e3188(v->m_szText, buf, 1023);
	v->m_f460 = g_105faa84->v1() ? 0.0f : g_105faa84->m_f28;
	v->m_f45c = engine->Time(0);
	v->m_nLines = 1;
	char *p = v->m_szText;
	char c = *p;
	while (c)
	{
		if (c == '\n')
			v->m_nLines++;
		c = *++p;
	}
}
// END FUNCTION

// FUNCTION: 0x10164eb0 size=0x3b
#include "CCenterStringPanel.h"
#include <stdarg.h>
void CCenterStringPanel::vfunc110(int a, int b, int c, int d, const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vfunc108(a, b, c, d);
	vfunc109(fmt, args);
}
// END FUNCTION

// FUNCTION: 0x10164ef0 size=0xc
#include "CCenterStringPanel.h"
int CCenterStringPanel::vfunc111()
{
    *(char *)((char *)this + 0x5c) = 0;
    *(int *)((char *)this + 0x460) = 0;
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10164f00 size=0x15
#include "CCenterStringPanel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual int f107(); };
}
void CCenterStringPanel::vfunc2()
{
    ((lifted::V *)this)->f21(((lifted::V *)this)->f107());
}
// END FUNCTION

// FUNCTION: 0x10164f20 size=0xc3
#include "CCenterStringPanel.h"
#define F(n) virtual void f##n();
#define F10(p) F(p##0) F(p##1) F(p##2) F(p##3) F(p##4) F(p##5) F(p##6) F(p##7) F(p##8) F(p##9)
struct EngA {
	F10(0) F10(1) F10(2) F(30) F(31) F(32) F(33) F(34) F(35) F(36)
	virtual int v37();
	virtual void f38();
	virtual float v39(int a);
	F10(4) F(50) F(51) F(52) F(53) F(54)
	virtual char v55();
	F(56) F(57) F(58)
	virtual int v59();
};
struct RenV {
	F10(0) F10(1) F10(2) F(30) F(31) F(32) F(33) F(34) F(35) F(36)
	virtual int v37();
};
extern EngA *g_104a57d4;
extern RenV *g_104a57e4;
struct CenterView {
	char m_pad[0x45c];
	float m_f45c;
	float m_f460;
	int m_n464;
	int m_n468;
};
char CCenterStringPanel::vfunc107()
{
	CenterView *v = (CenterView *)this;
	if (g_104a57d4->v59())
		return 0;
	if (g_104a57e4->v37() == 1 && g_104a57d4->v55())
		return 0;
	if (v->m_n464 > v->m_n468)
		v->m_n468 = v->m_n464;
	double t = v->m_f460 + v->m_f45c;
	float d = t - g_104a57d4->v39(0);
	if (d <= 0.0f && !g_104a57e4->v37())
		return 0;
	return g_104a57d4->v55() != 0;
}
// END FUNCTION
