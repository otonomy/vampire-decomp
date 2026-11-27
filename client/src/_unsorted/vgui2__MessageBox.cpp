// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101c6780 size=0x137
#include "vgui2__MessageBox.h"
#include "vgui2__Label.h"
#define V2(n) virtual void vf##n(); virtual void vf##n##b();
struct Button_101b3630 : public vgui2::Panel {
	Button_101b3630 *sub_101b3630(vgui2::Panel *, const char *, const char *);
	V2(107) V2(109) V2(111) V2(113) V2(115) V2(117) V2(119) V2(121) V2(123) V2(125) V2(127) V2(129) V2(131) V2(133)
	V2(135) V2(137) V2(139) V2(141) V2(143) V2(145) V2(147) V2(149) V2(151) V2(153) V2(155) V2(157) V2(159)
	virtual void vf161();
	virtual void SetText(const char *);
};
struct CUnknown101b5670 { CUnknown101b5670 *sub_101b5670(const char *); };
struct CUnknown101b9560 { void sub_101b9560(int); };
void *sub_101b6840(int);
extern char g_102da9a4[];
#define m_pButton (*(Button_101b3630 **)((char *)this + 0xe4))
#define m_pLabel (*(vgui2::Label **)((char *)this + 0xe8))
#define m_pCmd (*(CUnknown101b5670 **)((char *)this + 0xec))
// TARGET: vgui2::MessageBox::MessageBox
vgui2::MessageBox::MessageBox(const char *title, const char *text, vgui2::Panel *parent) : vgui2::Frame(parent, 0, 0)
{
	int wide, tall;
	vfunc118((int)title, 1);
	((CUnknown101b9560 *)this)->sub_101b9560(0);
	vfunc126(0);
	vfunc128(0);
	vfunc121(0);
	void *p = vgui2::Panel::operator new(0xb8);
	m_pLabel = p ? new (p) vgui2::Label(this, 0, text) : 0;
	m_pLabel->vfunc110(&wide, &tall);
	wide = 0x1e0;
	tall = 0xa0;
	m_pLabel->sub_101a98f0(0x1e0, 0xa0);
	void *q = vgui2::Panel::operator new(0xf0);
	m_pButton = q ? ((Button_101b3630 *)q)->sub_101b3630(this, 0, g_102da9a4) : 0;
	m_pButton->SetText("Close");
	m_pButton->vfunc41((int)this);
	void *r = sub_101b6840(0x1c);
	m_pCmd = r ? ((CUnknown101b5670 *)r)->sub_101b5670("Command") : 0;
	sub_101a98f0(wide + 0x64, tall + 0x64);
}
// END FUNCTION

// FUNCTION: 0x101c68c0 size=0x1e
#include "vgui2__MessageBox.h"

// VC6 writes vgui2::MessageBox's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::MessageBox *pcd_emit_101c68c0(const vgui2::MessageBox &other) { return new vgui2::MessageBox(other); }

// TARGET: ??_GMessageBox@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101c68e0 size=0x20
#include "vgui2__MessageBox.h"
struct MsgObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); };
vgui2::MessageBox::~MessageBox()
{
	MsgObj *p = *(MsgObj **)((char *)this + 0xec);
	if (p)
		p->v21();
}
// END FUNCTION

// FUNCTION: 0x101c6900 size=0xc3
#include "vgui2__MessageBox.h"
struct ISurfaceA { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(int); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(int &, int &); };
ISurfaceA *sub_101ac8d0();
ISurfaceA *sub_101ac8b0();
// TARGET: vgui2::MessageBox::vfunc145
void vgui2::MessageBox::vfunc145()
{
	int a, d, b, c;
	sub_101ac8d0()->v39(b, a);
	sub_101a9920(&c, &d);
	sub_101a9890((b - c) / 2, (a - d) / 2);
	vfunc101();
	vfunc21(1);
	vfunc46(1);
	vfunc49();
	vgui2::Panel *&p = *(vgui2::Panel **)((char *)this + 0xe4);
	if ((char)p->vfunc22())
		p->vfunc15(0);
	else
		vfunc15(0);
	sub_101ac8b0()->v25(vfunc0());
}
// END FUNCTION

// FUNCTION: 0x101c69d0 size=0xc3
#include "vgui2__MessageBox.h"
#define D(n) virtual void d##n();
#define D10(p) D(p##0) D(p##1) D(p##2) D(p##3) D(p##4) D(p##5) D(p##6) D(p##7) D(p##8) D(p##9)
struct PVM
{
	int sub_101ab130(int);
	int sub_101ab1a0();
	void sub_101a9890(int);
};
struct MBView
{
	D10(0) D10(1) D10(2) D10(3) D10(4) D10(5) D10(6) D10(7) D10(8) D10(9)
	D10(10) D10(11) D10(12) D10(13) D(140)
	virtual void v141(int *, int *, int *, int *);
};
struct MBMembers
{
	char m_pad[0xe4];
	PVM *m_pE4;
	PVM *m_pE8;
};
struct XY { int x, y; };
void vgui2::MessageBox::vfunc101()
{
	XY q, p;
	MBMembers *m = (MBMembers *)this;
	((MBView *)this)->v141(&p.x, &p.y, &q.x, &q.y);
	q.x += p.x;
	q.y += p.y;
	m->m_pE8->sub_101a9890(q.y / 2 - m->m_pE8->sub_101ab130(p.y + 15) / 2 + p.y);
	m->m_pE4->sub_101a9890(q.y / 2 - m->m_pE4->sub_101ab130(q.y - m->m_pE4->sub_101ab1a0() - 15) / 2 + p.y);
	sub_101b88c0();
}
// END FUNCTION

// FUNCTION: 0x101c6aa0 size=0x4f
#include "vgui2__MessageBox.h"
namespace lifted {
extern char g_104a5450;
struct C101ac8b0 { int sub_101ac8b0(); };
struct C101b9260 { int sub_101b9260(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual int f7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual int f18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual int f26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual int f43(int); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual int f71(); };
}
int vgui2::MessageBox::vfunc130()
{
    ((lifted::V *)(((lifted::C101ac8b0 *)this)->sub_101ac8b0()))->f26();
    ((lifted::C101b9260 *)this)->sub_101b9260();
    int t0 = ((lifted::V *)(*(int *)((char *)this + 0xec)))->f7();
    if (t0 != 0) {
        ((lifted::V *)this)->f43(((lifted::V *)(*(int *)((char *)this + 0xec)))->f18());
    }
    lifted::g_104a5450 = 1;
    return ((lifted::V *)this)->f71();
}
// END FUNCTION

// FUNCTION: 0x101c6af0 size=0x18
#include "vgui2__MessageBox.h"
namespace lifted {
extern char g_102d82ac;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual int f14(int, int); };
}
int vgui2::MessageBox::vfunc146(int a0)
{
    return ((lifted::V *)(*(int *)((char *)this + 0xec)))->f14((int)&lifted::g_102d82ac, a0);
}
// END FUNCTION

// FUNCTION: 0x101c6b10 size=0x38
#include "vgui2__MessageBox.h"
struct KV23 { KV23 *sub_101b5670(const char *); };
void *sub_101b6840(int);
struct MBV {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
  virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
  virtual void v20(); virtual void v21(); virtual void v22();
  virtual int v23(MBV *, KV23 *, int);
};
// TARGET: vgui2::MessageBox::vfunc149
int vgui2::MessageBox::vfunc149()
{
  MBV *self = (MBV *)this;
  KV23 *kv = (KV23 *)sub_101b6840(0x1c);
  KV23 *msg = kv ? kv->sub_101b5670("Close") : 0;
  return self->v23(self, msg, 0);
}
// END FUNCTION

// FUNCTION: 0x101c6b50 size=0x13
#include "vgui2__MessageBox.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(float); };
}
int vgui2::MessageBox::vfunc147(float a0)
{
    return ((lifted::V *)(*(int *)((char *)this + 0xe4)))->f21(a0);
}
// END FUNCTION

// FUNCTION: 0x101c6b70 size=0x24
#include "vgui2__MessageBox.h"
namespace lifted {
extern char g_102de300;
int __stdcall sub_101b95c0(int);
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual int f162(int); };
}
int vgui2::MessageBox::vfunc148(int a0)
{
    int t0 = lifted::sub_101b95c0(a0);
    int t1 = *(int *)((char *)this + 0xe4);
    a0 = (int)&lifted::g_102de300;
    return ((lifted::V *)t1)->f162(a0);
}
// END FUNCTION

// FUNCTION: 0x101c6bf0 size=0x6
#include "vgui2__MessageBox.h"
namespace lifted {
extern char g_102da960;
}
int vgui2::MessageBox::vfunc102()
{
    return (int)&lifted::g_102da960;
}
// END FUNCTION
