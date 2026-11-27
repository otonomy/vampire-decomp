// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101b36f0 size=0x1e
#include "vgui2__Button.h"

// VC6 writes vgui2::Button's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::Button *pcd_emit_101b36f0(const vgui2::Button &other) { return new vgui2::Button(other); }

// TARGET: ??_GButton@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101b3710 size=0x20
#include "vgui2__Button.h"
struct ButtonObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); };
vgui2::Button::~Button()
{
	ButtonObj *p = *(ButtonObj **)((char *)this + 0xc4);
	if (p)
		p->v21();
}
// END FUNCTION

// FUNCTION: 0x101b3730 size=0x23
#include "vgui2__Button.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
void vgui2::Button::vfunc152(char a0)
{
    if (a0 != (*(char *)((char *)this + 0xbc))) {
        *(char *)((char *)this + 0xbc) = a0;
        ((lifted::V *)this)->f57(0, 0);
    }
}
// END FUNCTION

// FUNCTION: 0x101b3760 size=0x31
#include "vgui2__Button.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual int f142(); };
}
void vgui2::Button::vfunc143(char a0)
{
    if ((*(char *)((char *)this + 0xba)) != a0) {
        *(char *)((char *)this + 0xba) = a0;
        ((lifted::V *)this)->f142();
        ((lifted::V *)this)->f57(0, 0);
    }
}
// END FUNCTION

// FUNCTION: 0x101b37a0 size=0x31
#include "vgui2__Button.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual int f142(); };
}
void vgui2::Button::vfunc141(char a0)
{
    if ((*(char *)((char *)this + 0xbb)) != a0) {
        *(char *)((char *)this + 0xbb) = a0;
        ((lifted::V *)this)->f142();
        ((lifted::V *)this)->f57(0, 0);
    }
}
// END FUNCTION

// FUNCTION: 0x101b3840 size=0xd
#include "vgui2__Button.h"
bool vgui2::Button::vfunc145(char a0)
{
    *(char *)((char *)this + 0xbd) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101b3850 size=0x7
#include "vgui2__Button.h"
bool vgui2::Button::vfunc146()
{
    return *(bool *)((char *)this + 0xbd);
}
// END FUNCTION

// FUNCTION: 0x101b3860 size=0x31
#include "vgui2__Button.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual int f142(); };
}
void vgui2::Button::vfunc138(char a0)
{
    if ((*(char *)((char *)this + 0xb8)) != a0) {
        *(char *)((char *)this + 0xb8) = a0;
        ((lifted::V *)this)->f142();
        ((lifted::V *)this)->f57(0, 0);
    }
}
// END FUNCTION

// FUNCTION: 0x101b38a0 size=0x7
#include "vgui2__Button.h"
bool vgui2::Button::vfunc139()
{
    return *(bool *)((char *)this + 0xb8);
}
// END FUNCTION

// FUNCTION: 0x101b38b0 size=0x25
#include "vgui2__Button.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual int f143(int); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual int f150(); };
}
int vgui2::Button::vfunc147()
{
    ((lifted::V *)this)->f143(1);
    ((lifted::V *)this)->f150();
    return ((lifted::V *)this)->f143(0);
}
// END FUNCTION

// FUNCTION: 0x101b38e0 size=0x7
#include "vgui2__Button.h"
bool vgui2::Button::vfunc144()
{
    return *(bool *)((char *)this + 0xba);
}
// END FUNCTION

// FUNCTION: 0x101b38f0 size=0x7
#include "vgui2__Button.h"
bool vgui2::Button::vfunc140()
{
    return *(bool *)((char *)this + 0xb9);
}
// END FUNCTION

// FUNCTION: 0x101b3900 size=0xd2
#include "vgui2__Button.h"

struct SurfV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
	virtual void v36(); virtual void v37(); virtual void v38();
	virtual void v39(int *, int *);
};

SurfV *sub_101ac8d0();

void vgui2::Button::vfunc98()
{
	sub_101b2610();
	if (!vfunc56())
		return;
	if (!vfunc47())
		return;
	if (!m_b0ed)
		return;
	int w, h;
	sub_101ac8d0()->v39(&w, &h);
	int x, y;
	sub_101a9920(&x, &y);
	double sh = h * (1.0 / 768.0);
	double sw = w * (1.0 / 1024.0);
	vfunc163((int)(3.0 * sw), (int)(3.0 * sh), (int)(x - 4.0 * sw), (int)(y - 2.0 * sh));
}
// END FUNCTION

// FUNCTION: 0x101b39e0 size=0x73
#include "vgui2__Button.h"
#include "vgui2__Panel.h"

class BtnView_101b39e0 : public vgui2::Panel
{
public:
	virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110();
	virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114();
	virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118();
	virtual void v119(); virtual void v120(); virtual void v121(); virtual void v122();
	virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126();
	virtual void v127(); virtual void v128(); virtual void v129(); virtual void v130();
	virtual void v131(); virtual void v132(); virtual void v133(); virtual void v134();
	virtual void v135(); virtual void v136(); virtual void v137(); virtual void v138();
	virtual void v139(); virtual void v140(); virtual void v141(); virtual void v142();
	virtual void v143(); virtual void v144(); virtual void v145(); virtual void v146();
	virtual void v147(); virtual void v148(); virtual void v149(); virtual void v150();
	virtual void v151(); virtual void v152(); virtual void v153(); virtual void v154();
	virtual void v155();
	virtual int v156(int);
	virtual int v157(int);
	virtual void v158(); virtual void v159(); virtual void v160(); virtual void v161();
	virtual void v162(); virtual void v163();
	virtual int v164(bool a, bool b, bool c, bool d);
};

// TARGET: vgui2::Button::vfunc101
void vgui2::Button::vfunc101()
{
	BtnView_101b39e0 *v = (BtnView_101b39e0 *)this;
	int clr;
	v->vfunc60((void *)v->v164(*(bool *)((char *)this + 0xb9), *(bool *)((char *)this + 0xb8), *(bool *)((char *)this + 0xba), v->vfunc56()));
	v->vfunc51(*(int *)v->v156((int)&clr));
	v->vfunc50(*(int *)v->v157((int)&clr));
	Label::vfunc101();
}
// END FUNCTION

// FUNCTION: 0x101b3a60 size=0x41
#include "vgui2__Button.h"
int vgui2::Button::vfunc156(int a0)
{
    if ((*(char *)((char *)this + 0xb9)) != 0) {
        *(int *)((char *)a0) = *(int *)((char *)this + 0xe4);
        return a0;
    }
    if ((*(char *)((char *)this + 0xb8)) != 0) {
        *(int *)((char *)a0) = *(int *)((char *)this + 0xdc);
        return a0;
    }
    *(int *)((char *)a0) = *(int *)((char *)this + 0xd4);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101b3ab0 size=0x41
#include "vgui2__Button.h"
int vgui2::Button::vfunc157(int a0)
{
    if ((*(char *)((char *)this + 0xb9)) != 0) {
        *(int *)((char *)a0) = *(int *)((char *)this + 0xe8);
        return a0;
    }
    if ((*(char *)((char *)this + 0xb8)) != 0) {
        *(int *)((char *)a0) = *(int *)((char *)this + 0xe0);
        return a0;
    }
    *(int *)((char *)a0) = *(int *)((char *)this + 0xd8);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101b3b00 size=0x17
#include "vgui2__Button.h"
namespace lifted {
struct C101ab3e0 { int sub_101ab3e0(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
void vgui2::Button::vfunc80()
{
    ((lifted::V *)this)->f57(0, 0);
    ((lifted::C101ab3e0 *)this)->sub_101ab3e0();
}
// END FUNCTION

// FUNCTION: 0x101b3b20 size=0x17
#include "vgui2__Button.h"
namespace lifted {
struct C101ab3f0 { int sub_101ab3f0(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
void vgui2::Button::vfunc81()
{
    ((lifted::V *)this)->f57(0, 0);
    ((lifted::C101ab3f0 *)this)->sub_101ab3f0();
}
// END FUNCTION

// FUNCTION: 0x101b3c40 size=0x7e
#include "vgui2__Button.h"
struct BtnColor {
	unsigned char r, g, b, a;
};
struct BtnView {
	char pad[0xd4];
	BtnColor m_c1;
	BtnColor m_c2;
};
#pragma warning(disable:4716)
// TARGET: ?vfunc153@Button@vgui2@@UAEHII@Z
int vgui2::Button::vfunc153(unsigned int c1, unsigned int c2)
{
	BtnView *v = (BtnView *)this;
	BtnColor *p1 = (BtnColor *)&c1;
	BtnColor *p2 = (BtnColor *)&c2;
	if (!(v->m_c1.r == p1->r && v->m_c1.g == p1->g && v->m_c1.b == p1->b && v->m_c1.a == p1->a
		&& v->m_c2.r == p2->r && v->m_c2.g == p2->g && v->m_c2.b == p2->b && v->m_c2.a == p2->a))
	{
		*(unsigned int *)&v->m_c1 = c1;
		*(unsigned int *)&v->m_c2 = c2;
		return vfunc57(0, 0);
	}
}
// END FUNCTION

// FUNCTION: 0x101b3cc0 size=0x7e
#include "vgui2__Button.h"
void vgui2::Button::vfunc154(unsigned int a, unsigned int b)
{
	unsigned char *pa = (unsigned char *)&a;
	unsigned char *pb = (unsigned char *)&b;
	unsigned char *fg = (unsigned char *)&m_nFgColor;
	unsigned char *bg = (unsigned char *)&m_nBgColor;
	if (!(fg[0] == pa[0] && fg[1] == pa[1] && fg[2] == pa[2] && fg[3] == pa[3] &&
		bg[0] == pb[0] && bg[1] == pb[1] && bg[2] == pb[2] && bg[3] == pb[3])) {
		m_nBgColor = b;
		m_nFgColor = a;
		vfunc57(0, 0);
	}
}
// END FUNCTION

// FUNCTION: 0x101b3d40 size=0x7e
#include "vgui2__Button.h"
struct Color4 { unsigned char r, g, b, a; };
void vgui2::Button::vfunc155(unsigned int a, unsigned int b)
{
	Color4 &ca = *(Color4 *)&a;
	Color4 &cb = *(Color4 *)&b;
	Color4 &c1 = *(Color4 *)((char *)this + 0xe4);
	Color4 &c2 = *(Color4 *)((char *)this + 0xe8);
	if (c1.r == ca.r && c1.g == ca.g && c1.b == ca.b && c1.a == ca.a &&
	    c2.r == cb.r && c2.g == cb.g && c2.b == cb.b && c2.a == cb.a)
		return;
	*(unsigned int *)((char *)this + 0xe4) = a;
	*(unsigned int *)((char *)this + 0xe8) = b;
	vfunc57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101b3dc0 size=0x19
#include "vgui2__Button.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int vgui2::Button::vfunc158(int a0)
{
    *(int *)((char *)this + 0xc8) = a0;
    return ((lifted::V *)this)->f57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101b3de0 size=0x19
#include "vgui2__Button.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int vgui2::Button::vfunc159(int a0)
{
    *(int *)((char *)this + 0xcc) = a0;
    return ((lifted::V *)this)->f57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101b3e00 size=0x19
#include "vgui2__Button.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int vgui2::Button::vfunc160(int a0)
{
    *(int *)((char *)this + 0xd0) = a0;
    return ((lifted::V *)this)->f57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101b3e20 size=0x6f
#include "vgui2__Button.h"

// TARGET: vfunc164
int vgui2::Button::vfunc164(int a0, int a1, int a2, int a3)
{
	if ( *(bool *)((char *)this + 0xbc) )
	{
		if ( *(char *)&a0 )
			return *(int *)((char *)this + 0xcc);
		if ( *(char *)&a3 )
			return *(int *)((char *)this + 0xd0);
		if ( vfunc47() )
		{
			if ( *(bool *)((char *)this + 0xec) )
				return *(int *)((char *)this + 0xd0);
		}
	}
	else
	{
		if ( *(char *)&a0 )
			return *(int *)((char *)this + 0xcc);
		if ( *(char *)&a1 )
			return *(int *)((char *)this + 0xc8);
	}
	return *(int *)((char *)this + 0xc8);
}
// END FUNCTION

// FUNCTION: 0x101b3e90 size=0xa7
#include "vgui2__Button.h"

extern void *sub_101b6840(unsigned int size);

struct KV_101b3e90 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16();
	virtual void v17(const char *key, void *value);
	KV_101b3e90 *sub_101b5670(const char *name);
};

struct IVGui_101b3e90 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void PostMessage(int target, void *params, int from, float delaySeconds);
};
extern IVGui_101b3e90 *sub_101ac8f0();

struct PanelLike_101b3e90 {
	virtual int GetVPanel();
};

void vgui2::Button::vfunc151(int state)
{
	bool *pFlag = (bool *)&m_c0ec;
	bool b = state != 0;
	if (*pFlag != b)
	{
		*pFlag = b;
		if (state && vfunc31())
		{
			KV_101b3e90 *msg = (KV_101b3e90 *)sub_101b6840(0x1c);
			if (msg)
				msg = msg->sub_101b5670("DefaultButtonSet");
			else
				msg = 0;
			msg->v17("panel", this);
			PanelLike_101b3e90 *parent = (PanelLike_101b3e90 *)vfunc31();
			sub_101ac8f0()->PostMessage(parent->GetVPanel(), msg, vfunc0(), 0.0f);
		}
		vfunc57(0, 0);
		vfunc6();
	}
}
// END FUNCTION

// FUNCTION: 0x101b3f40 size=0x35
#include "vgui2__Button.h"
// TARGET: vgui2::Button::vfunc148
void vgui2::Button::vfunc148(int bit, bool on)
{
	unsigned int *flags = (unsigned int *)((char *)this + 0xc0);
	if (on)
		*flags |= 1 << (bit + 1);
	else
		*flags &= ~(1 << (bit + 1));
}
// END FUNCTION

// FUNCTION: 0x101b3f80 size=0x1a
#include "vgui2__Button.h"
bool vgui2::Button::vfunc149(int n) { return (*(int *)((char *)this + 0xc0) & (1 << (n + 1))) ? true : false; }
// END FUNCTION

// FUNCTION: 0x101b3fa0 size=0x47
#include "vgui2__Button.h"
struct KV101b5690 { KV101b5690 *sub_101b5690(const char *, const char *, int); };
void *sub_101b6840(int);
// TARGET: ?vfunc162@Button@vgui2@@UAEXH@Z
void vgui2::Button::vfunc162(int a)
{
	KV101b5690 *kv = (KV101b5690 *)sub_101b6840(0x1c);
	vfunc161(kv ? (int)kv->sub_101b5690("Command", "command", a) : 0);
}
// END FUNCTION

// FUNCTION: 0x101b3ff0 size=0x2e
#include "vgui2__Button.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(); };
}
void vgui2::Button::vfunc161(int a0)
{
    if ((*(int *)((char *)this + 0xc4)) != 0) {
        int t0 = ((lifted::V *)(*(int *)((char *)this + 0xc4)))->f21();
        *(int *)((char *)this + 0xc4) = a0;
        return;
    }
    *(int *)((char *)this + 0xc4) = a0;
}
// END FUNCTION

// FUNCTION: 0x101b4020 size=0x21
#include "vgui2__Button.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual int f18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual int f43(int); };
}
void vgui2::Button::vfunc150()
{
    if ((*(int *)((char *)this + 0xc4)) != 0) {
        ((lifted::V *)this)->f43(((lifted::V *)(*(int *)((char *)this + 0xc4)))->f18());
    }
}
// END FUNCTION

// FUNCTION: 0x101b4050 size=0xae
#include "vgui2__Button.h"
extern "C" int __cdecl strcmp(const char *, const char *);
struct BtnKVView
{
	virtual const char *GetName();
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
	virtual void v11(); virtual void v12(); virtual void v13();
	virtual void SetString(const char *name, const char *value);
	virtual void SetInt(const char *name, int value);
};
struct BtnTargetView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
	virtual const char *GetString(const char *name, const char *def);
};
// TARGET: vgui2::Button::vfunc14
bool vgui2::Button::vfunc14(vgui2::KeyValues *data)
{
	BtnKVView *kv = (BtnKVView *)data;
	if (!strcmp(kv->GetName(), "GetState")) {
		kv->SetInt("state", vfunc144());
		return true;
	}
	if (!strcmp(kv->GetName(), "GetCommand")) {
		BtnTargetView *t = *(BtnTargetView **)((char *)this + 0xc4);
		if (t)
			kv->SetString("command", t->GetString("command", ""));
		else
			kv->SetString("command", "");
		return true;
	}
	return this->Label::vfunc14(data);
}
// END FUNCTION

// FUNCTION: 0x101b4150 size=0x52
#include "vgui2__Button.h"
namespace lifted {
extern char g_102c19a0;
extern char g_102d0be0;
extern char g_102de300;
int __stdcall sub_101b3090(int);
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual int f9(int, int); virtual void u10(); virtual int f11(int, int); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual int f151(int); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual int f162(int); };
}
void vgui2::Button::vfunc75(int a0)
{
    lifted::sub_101b3090(a0);
    int t0 = ((lifted::V *)a0)->f11((int)&lifted::g_102d0be0, (int)&lifted::g_102de300);
    if ((*(char *)((char *)t0)) != 0) {
        ((lifted::V *)this)->f162(t0);
    }
    int t1 = ((lifted::V *)a0)->f9((int)&lifted::g_102c19a0, 0);
    if (t1 != 0) {
        ((lifted::V *)this)->f151(1);
    }
}
// END FUNCTION

// FUNCTION: 0x101b41b0 size=0x23
#include "vgui2__Button.h"
namespace lifted {
extern char g_102d8c04;
extern char g_10679600;
int sub_101b3290();
int sub_101d3192(int, int, int, int);
}
int vgui2::Button::vfunc77()
{
    lifted::sub_101d3192((int)&lifted::g_10679600, 0x400, (int)&lifted::g_102d8c04, lifted::sub_101b3290());
    return (int)&lifted::g_10679600;
}
// END FUNCTION

// FUNCTION: 0x101b41e0 size=0x22
#include "vgui2__Button.h"
// TARGET: vgui2::Button::vfunc165
void vgui2::Button::vfunc165(int a)
{
	vfunc143(a != 0);
	vfunc6();
}
// END FUNCTION

// FUNCTION: 0x101b4210 size=0x1d
#include "vgui2__Button.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual bool f47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual int f138(int); };
}
void vgui2::Button::vfunc85()
{
    bool t0 = ((lifted::V *)this)->f47();
    if (t0 != 0) {
        ((lifted::V *)this)->f138(1);
    }
}
// END FUNCTION

// FUNCTION: 0x101b4230 size=0x15
#include "vgui2__Button.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual int f138(int); };
}
void vgui2::Button::vfunc86()
{
    if ((*(char *)((char *)this + 0xbe)) == 0) {
        ((lifted::V *)this)->f138(0);
    }
}
// END FUNCTION

// FUNCTION: 0x101b4250 size=0x69
#include "vgui2__Button.h"
namespace lifted {
int sub_101ac8b0();
struct V { virtual int f0(); virtual int f1(int); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual int f15(int); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual bool f47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual int f143(int); virtual void u144(); virtual void u145(); virtual bool f146(); virtual void u147(); virtual void u148(); virtual bool f149(int); };
}
void vgui2::Button::vfunc87(int a0)
{
    bool t0 = ((lifted::V *)this)->f47();
    if (t0 != 0) {
        bool t1 = ((lifted::V *)this)->f149(a0);
        if (t1 != 0) {
            bool t2 = ((lifted::V *)this)->f146();
            if (t2 != 0) {
                ((lifted::V *)this)->f15(0);
                ((lifted::V *)this)->f143(1);
                ((lifted::V *)this)->f6();
                int t3 = lifted::sub_101ac8b0();
                ((lifted::V *)t3)->f1(((lifted::V *)this)->f0());
            }
        }
    }
}
// END FUNCTION

// FUNCTION: 0x101b42c0 size=0x8
struct V { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); };
void __fastcall sub_101b42c0(V *self, int edx) { self->v87(); }
// END FUNCTION

// FUNCTION: 0x101b42d0 size=0x83
#include "vgui2__Button.h"
struct IVInput { virtual void v0(); virtual void SetMouseCapture(int); virtual void v2(); virtual void v3(); virtual int GetFocus(); };
IVInput *sub_101ac8b0();
// TARGET: vgui2::Button::vfunc89
void vgui2::Button::vfunc89(int a)
{
	if (vfunc146())
		sub_101ac8b0()->SetMouseCapture(0);
	if (vfunc149(a)) {
		if (vfunc47()) {
			if (vfunc0() == sub_101ac8b0()->GetFocus() || *(bool *)((char *)this + 0xbe))
				vfunc150();
		}
		vfunc143(0);
		vfunc6();
	}
}
// END FUNCTION

// FUNCTION: 0x101b4360 size=0x3f
#include "vgui2__Button.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual int f87(int); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual int f138(int); };
}
void vgui2::Button::vfunc91(int a0)
{
    if (a0 != 0x41) {
        if (a0 != 0x40) {
            *(char *)((char *)this + 0xbe) = 0;
            return;
        }
    }
    int t0 = ((lifted::V *)this)->f138(1);
    *(char *)((char *)this + 0xbe) = 1;
    ((lifted::V *)this)->f87(0);
}
// END FUNCTION

// FUNCTION: 0x101b43a0 size=0x4a
#include "vgui2__Button.h"
void vgui2::Button::vfunc94(int code) {
 if (*((char *)this + 0xbe) && (code == 0x41 || code == 0x40)) {
  vfunc138(1);
  vfunc89(0);
 }
 *((char *)this + 0xbe) = 0;
 vfunc138(0);
}
// END FUNCTION

// FUNCTION: 0x101b43f0 size=0x8c
#include "vgui2__Button.h"
struct SurfV11 {
	virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
	virtual void f8(); virtual void f9(); virtual void f10();
	virtual void SetColor(int r, int g, int b, int a);
};
extern SurfV11 *sub_101ac8d0();
void vgui2::Button::vfunc163(int x0, int y0, int x1, int y1)
{
	sub_101ac8d0()->SetColor(0, 0, 0, 255);
	vfunc133(x0, y0, x1, y0 + 1, 1, 1);
	vfunc133(x0, y0, x0 + 1, y1, 1, 1);
	vfunc133(x0, y1 - 1, x1, y1, 1, 1);
	vfunc133(x1 - 1, y0, x1, y1, 1, 1);
}
// END FUNCTION

// FUNCTION: 0x101b4480 size=0x36
#include "vgui2__Button.h"
void vgui2::Button::vfunc129()
{
	int wide, tall;
	vfunc110(&wide, &tall);
	sub_101a98f0(wide + 8, tall + 8);
}
// END FUNCTION

// FUNCTION: 0x101b4620 size=0x6
#include "vgui2__Button.h"
namespace lifted {
extern char g_102d8b28;
}
int vgui2::Button::vfunc102()
{
    return (int)&lifted::g_102d8b28;
}
// END FUNCTION
