// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101baa10 size=0x1e
#include "vgui2__CheckButton.h"

// VC6 writes vgui2::CheckButton's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::CheckButton *pcd_emit_101baa10(const vgui2::CheckButton &other) { return new vgui2::CheckButton(other); }

// TARGET: ??_GCheckButton@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101baa60 size=0x122
#include "vgui2__CheckButton.h"

struct ColorLocal
{
	unsigned char _color[4];

	ColorLocal() {}
	ColorLocal(int r, int g, int b, int a)
	{
		_color[0] = (unsigned char)r;
		_color[1] = (unsigned char)g;
		_color[2] = (unsigned char)b;
		_color[3] = (unsigned char)a;
	}
	int Raw() const { return *(const int *)_color; }
};

struct ISchemeLocal
{
	virtual void v0() = 0;
	virtual void v1() = 0;
	virtual void v2() = 0;
	virtual void v3() = 0;
	virtual unsigned long GetFont(const char *fontName) = 0;
	virtual ColorLocal GetColorDef(const char *colorName, ColorLocal defaultColor) = 0;
	virtual ColorLocal GetColor(const char *colorName) = 0;
};

struct CheckImageLocal
{
	char pad0[0x20];
	ColorLocal _borderColor1;
	ColorLocal _borderColor2;
	ColorLocal _checkColor;
	ColorLocal _bgColor;
	unsigned long _font;
};

struct ILabel123
{
	virtual void u00(); virtual void u01(); virtual void u02(); virtual void u03();
	virtual void u04(); virtual void u05(); virtual void u06(); virtual void u07();
	virtual void u08(); virtual void u09(); virtual void u10(); virtual void u11();
	virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15();
	virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
	virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23();
	virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27();
	virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31();
	virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35();
	virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39();
	virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43();
	virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47();
	virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51();
	virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55();
	virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59();
	virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63();
	virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67();
	virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71();
	virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75();
	virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79();
	virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83();
	virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87();
	virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91();
	virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95();
	virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99();
	virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103();
	virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107();
	virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111();
	virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115();
	virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119();
	virtual void u120(); virtual void u121(); virtual void u122();
	virtual int SetImageAtIndex(int index, int image, int offset);
};

// TARGET: vgui2::CheckButton::vfunc74
int vgui2::CheckButton::vfunc74(int a)
{
	ISchemeLocal *pScheme = (ISchemeLocal *)a;
	ToggleButton::vfunc74(a);

	vfunc51(pScheme->GetColor("FgColor").Raw());

	CheckImageLocal *img = *(CheckImageLocal **)((char *)this + 0xf4);
	img->_font = pScheme->GetFont("Marlett");
	img->_bgColor = pScheme->GetColorDef("CheckBgColor", ColorLocal(62, 70, 55, 255));
	img->_borderColor1 = pScheme->GetColorDef("CheckButtonBorder1", ColorLocal(20, 20, 20, 255));
	img->_borderColor2 = pScheme->GetColorDef("CheckButtonBorder2", ColorLocal(90, 90, 90, 255));
	img->_checkColor = pScheme->GetColorDef("CheckButtonCheck", ColorLocal(20, 20, 20, 255));

	vfunc111(3);
	return ((ILabel123 *)this)->SetImageAtIndex(0, *(int *)((char *)this + 0xf4), 0);
}
// END FUNCTION

// FUNCTION: 0x101bab90 size=0x5
#include "vgui2__CheckButton.h"
int vgui2::CheckButton::vfunc164(int a0, int a1, int a2, int a3)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x101baba0 size=0x4c
#include "vgui2__CheckButton.h"
struct CUnknown101b56c0 { CUnknown101b56c0 *sub_101b56c0(const char *a, const char *b, int c); };
void *sub_101b6840(int n);
void vgui2::CheckButton::vfunc143(char state)
{
	CUnknown101b56c0 *kv = (CUnknown101b56c0 *)sub_101b6840(0x1c);
	CUnknown101b56c0 *r = kv ? kv->sub_101b56c0("CheckButtonChecked", "state", (unsigned char)state) : 0;
	this->vfunc43((void *)r);
	Button::vfunc143(state);
}
// END FUNCTION

// FUNCTION: 0x101babf0 size=0x33
#include "vgui2__CheckButton.h"
namespace lifted {
struct C101bc3d0 { int sub_101bc3d0(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual bool f144(); };
}
int vgui2::CheckButton::vfunc156(int a0)
{
    bool t0 = ((lifted::V *)this)->f144();
    if (t0 != 0) {
        *(int *)((char *)a0) = *(int *)((char *)this + 0xf8);
        return a0;
    }
    ((lifted::C101bc3d0 *)this)->sub_101bc3d0(a0);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101bac30 size=0x9c
#include "vgui2__CheckButton.h"
struct ColorX { int c; };
struct ISchemeX {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4();
	virtual ColorX *GetColor(ColorX *out, const char *name, ColorX def);
	virtual ColorX *GetColor2(ColorX *out, const char *name);
};
struct ISchemeMgrX {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual ISchemeX *GetIScheme(int h);
};
struct IKVX {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
	virtual const char *GetStr(const char *name, int def);
};
ISchemeMgrX *sub_101ac8c0();
struct CB { char pad[0xf4]; int m_nf4; ColorX m_cf8; };
void vgui2::CheckButton::vfunc75(int a)
{
	Button::vfunc75(a);
	ISchemeX *pScheme = sub_101ac8c0()->GetIScheme(sub_101aa220());
	ColorX t1, t2;
	CB *p = (CB *)this;
	p->m_cf8 = *pScheme->GetColor(&t2, "BrightControlText", *pScheme->GetColor2(&t1, "ControlText"));
	const char *s = ((IKVX *)a)->GetStr("labelText", 0);
	if (s)
	{
		Label::vfunc108("");
		((Label *)this)->vfunc108(s);
	}
	vfunc123(0, p->m_nf4, 0);
}
// END FUNCTION

// FUNCTION: 0x101bacd0 size=0x47
#include "vgui2__CheckButton.h"
namespace lifted {
extern char g_102d89b8;
int __stdcall sub_101b4100(int);
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual int f14(int, int); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual int f109(int, int); };
struct B256 { int d[64]; };
}
int vgui2::CheckButton::vfunc76(int a0)
{
    lifted::B256 l0;
    lifted::sub_101b4100(a0);
    ((lifted::V *)this)->f109((int)((char *)&l0), 0xff);
    return ((lifted::V *)a0)->f14((int)&lifted::g_102d89b8, (int)((char *)&l0));
}
// END FUNCTION

// FUNCTION: 0x101bad20 size=0x30
#include "vgui2__CheckButton.h"
namespace lifted {
int __stdcall sub_101b23f0(int);
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual int f120(int); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual int f130(int); };
}
int vgui2::CheckButton::vfunc108(int a0)
{
    lifted::sub_101b23f0(a0);
    ((lifted::V *)this)->f120(((lifted::V *)this)->f130(a0));
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101bad50 size=0x3
#include "vgui2__CheckButton.h"
void vgui2::CheckButton::vfunc166(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101badd0 size=0x6
#include "vgui2__CheckButton.h"
namespace lifted {
extern char g_102d9288;
}
int vgui2::CheckButton::vfunc102()
{
    return (int)&lifted::g_102d9288;
}
// END FUNCTION
