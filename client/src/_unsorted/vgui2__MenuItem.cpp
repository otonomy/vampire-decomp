// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101c6c10 size=0x40
#include "vgui2__MenuItem.h"
using namespace vgui2;
// TARGET: ??0MenuItem@vgui2@@QAE@HHHHD@Z
MenuItem::MenuItem(int a, int b, int c, int d, char e) : Button(a, b, c)
{
	*(int *)((char *)this + 0xf0) = d;
	*((char *)this + 0xf4) = e;
	vfunc166();
}
// END FUNCTION

// FUNCTION: 0x101c6c50 size=0x1e
#include "vgui2__MenuItem.h"

// VC6 writes vgui2::MenuItem's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::MenuItem *pcd_emit_101c6c50(const vgui2::MenuItem &other) { return new vgui2::MenuItem(other); }

// TARGET: ??_GMenuItem@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101c6c70 size=0x33
#include "vgui2__MenuItem.h"
struct IObjF8 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual ~IObjF8(); };
vgui2::MenuItem::~MenuItem()
{
	vgui2::Panel *a = *(vgui2::Panel **)((char *)this + 0xf0);
	if (a)
		delete a;
	IObjF8 *b = *(IObjF8 **)((char *)this + 0xf8);
	if (b)
		delete b;
}
// END FUNCTION

// FUNCTION: 0x101c6cb0 size=0x122
#include "vgui2__MenuItem.h"
#include "MenuItemCheckImage.h"
#include <stddef.h>

#define FI(off) (*(int *)((char *)this + (off)))
#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();
#define V16(n) V4(n##a) V4(n##b) V4(n##c) V4(n##d)
struct SubPanelView {
    V16(a) V16(b)
    virtual void x32();
    virtual void SetParentItem(void *item);
    V4(c) 
    virtual void x38(); virtual void x39(); virtual void x40();
    virtual void Fn41(void *item);
};
struct MenuView {
    V16(a) V16(b) V16(c) V16(d) V16(e) V16(f)
    V4(g) V4(h) V4(i)
    virtual void x108(); virtual void x109(); virtual void x110();
    virtual void s111(int);
    virtual void s112(int, int);
    V4(j) virtual void x117(); virtual void x118(); virtual void x119(); virtual void x120(); virtual void x121();
    virtual void s122(int, int);
    virtual void s123(int, int, int);
    V4(k)
    virtual void s128(int);
    V16(l)
    virtual void s145(int);
    V4(m) virtual void x150(); virtual void x151();
    virtual void s152(int);
    void sub_101c7510(int a);
};
struct Obj38 { void *sub_101b9bc0(const char *s, int v); };
void *operator new(size_t size);

// TARGET: vgui2::MenuItem::vfunc166
void vgui2::MenuItem::vfunc166()
{
    MenuView *v = (MenuView *)this;
    FI(0xf8) = 0;
    FI(0xfc) = 0;
    if (FI(0xf0)) {
        ((SubPanelView *)FI(0xf0))->SetParentItem(this);
        Obj38 *mem = (Obj38 *)::operator new(0x38);
        void *p = mem ? mem->sub_101b9bc0(" 4", sub_101aa220()) : 0;
        FI(0xf8) = (int)p;
        v->s122((int)p, 0);
        ((SubPanelView *)FI(0xf0))->Fn41(this);
    } else if (*((char *)this + 0xf4)) {
        v->s128(1);
        MenuItemCheckImage *img = new MenuItemCheckImage(this);
        FI(0xfc) = (int)img;
        v->s123(0, (int)img, 0);
        v->sub_101c7510(0);
    }
    v->s152(0);
    v->s111(3);
    v->s145(0);
    v->s112(6, 0);
    v->s111(3);
}
// END FUNCTION

// FUNCTION: 0x101c6ec0 size=0x35
#include "vgui2__MenuItem.h"

class F8View_101c6ec0
{
public:
	virtual void v0(); virtual void v1(); virtual void v2();
	virtual int v3(int color);
};

struct MenuItemView_101c6ec0
{
	char m_pad0[0xf8];
	F8View_101c6ec0 *m_pF8;
};

// TARGET: vgui2::MenuItem::vfunc101
void vgui2::MenuItem::vfunc101()
{
	Button::vfunc101();
	MenuItemView_101c6ec0 *v = (MenuItemView_101c6ec0 *)this;
	if ( v->m_pF8 )
	{
		int clr;
		v->m_pF8->v3(*(int *)vfunc156((int)&clr));
	}
}
// END FUNCTION

// FUNCTION: 0x101c6f70 size=0x61
#include "vgui2__MenuItem.h"

extern void *sub_101b6840(unsigned int size);

struct KV_101c6f70 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16();
	virtual void v17(const char *key, int value);
	KV_101c6f70 *sub_101b5670(const char *name);
};

struct IVGui_101c6f70 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void PostMessage(int target, void *params, int from, float delaySeconds);
};
extern IVGui_101c6f70 *sub_101ac8f0();

struct PanelLike_101c6f70 {
	virtual int GetVPanel();
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30();
	virtual PanelLike_101c6f70 *GetParent();
};

void vgui2::MenuItem::vfunc85()
{
	KV_101c6f70 *msg = (KV_101c6f70 *)sub_101b6840(0x1c);
	if (msg)
		msg = msg->sub_101b5670("CursorEnteredMenuItem");
	else
		msg = 0;

	msg->v17("VPanel", vfunc0());
	PanelLike_101c6f70 *parent = (PanelLike_101c6f70 *)vfunc31();
	sub_101ac8f0()->PostMessage(parent->GetVPanel(), msg, 0, 0.0f);
}
// END FUNCTION

// FUNCTION: 0x101c6fe0 size=0x61
#include "vgui2__MenuItem.h"

extern void *sub_101b6840(unsigned int size);

struct KV_101c6fe0 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16();
	virtual void v17(const char *key, int value);
	KV_101c6fe0 *sub_101b5670(const char *name);
};

struct IVGui_101c6fe0 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void PostMessage(int target, void *params, int from, float delaySeconds);
};
extern IVGui_101c6fe0 *sub_101ac8f0();

struct PanelLike_101c6fe0 {
	virtual int GetVPanel();
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30();
	virtual PanelLike_101c6fe0 *GetParent();
};

void vgui2::MenuItem::vfunc86()
{
	KV_101c6fe0 *msg = (KV_101c6fe0 *)sub_101b6840(0x1c);
	if (msg)
		msg = msg->sub_101b5670("CursorExitedMenuItem");
	else
		msg = 0;

	msg->v17("VPanel", vfunc0());
	PanelLike_101c6fe0 *parent = (PanelLike_101c6fe0 *)vfunc31();
	sub_101ac8f0()->PostMessage(parent->GetVPanel(), msg, 0, 0.0f);
}
// END FUNCTION

// FUNCTION: 0x101c7050 size=0x2e
#include "vgui2__MenuItem.h"
struct CUnknown101c0c10 { int sub_101c0c10(); };
void vgui2::MenuItem::vfunc94(int code) {
 if (((CUnknown101c0c10 *)vfunc31())->sub_101c0c10() != 1 || !*(int *)((char *)this + 0xf0))
  Button::vfunc94(code);
}
// END FUNCTION

// FUNCTION: 0x101c70e0 size=0xf
#include "vgui2__MenuItem.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual int f31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual int f81(); };
}
void vgui2::MenuItem::vfunc81()
{
    ((lifted::V *)(((lifted::V *)this)->f31()))->f81();
}
// END FUNCTION

// FUNCTION: 0x101c71f0 size=0x1f4
#include "vgui2__MenuItem.h"
extern "C" int atoi(const char *);
#define D1(n) virtual void n(){}
#define D4(p) virtual void p##a(){} virtual void p##b(){} virtual void p##c(){} virtual void p##d(){}
#define D16(p) D4(p##1) D4(p##2) D4(p##3) D4(p##4)
struct Col { unsigned v; };
struct Sch {
	virtual const char *GetResourceString(const char *, int);
	D1(a1) D1(a2) D1(a3) virtual int GetFont(const char *); virtual Col GetColor(const char *, Col);
};
struct Arr { D16(q) D4(r) D4(s) D4(t) D1(u1) D1(u2) virtual void sf(int); };
struct Par { D16(q) D16(r) D16(s) D4(t) D4(u) D1(w) virtual int s57(int, int); };
struct MV {
	D16(a) D4(b) D4(c) D4(d) D1(e1) D1(e2) D1(e3) virtual Par *GetParent();
	D16(h) D4(i) virtual Col s52(); virtual Col s53();
	D16(j) D16(k) D16(l) D4(m) D4(n) D1(o1) D1(o1b)
	virtual void s112(int);
	D4(v) D1(w1) D1(w2) virtual int s119(); D1(s120) D1(s121) virtual void s122(Arr *, int); virtual void s123(int, void *, int);
	D16(x) D4(y) D4(z) D4(zz) D1(z1) virtual void s153(Col, Col); virtual void s154(Col, Col); virtual void s155(Col, Col);
	char pad[0xf0]; bool chk; Arr *arrow; struct Chk *check;
};
struct Chk { int pad[8]; int font; };
// TARGET: vgui2::MenuItem::vfunc74
int vgui2::MenuItem::vfunc74(int pS)
{
	Sch *s = (Sch *)pS;
	MV *t = (MV *)this;
	Button::vfunc74(pS);
	t->s153(s->GetColor("Menu/FgColor", t->s53()), s->GetColor("Menu/BgColor", t->s52()));
	t->s154(s->GetColor("Menu/ArmedFgColor", t->s53()), s->GetColor("Menu/ArmedBgColor", t->s52()));
	t->s155(s->GetColor("Menu/ArmedFgColor", t->s53()), s->GetColor("Menu/ArmedBgColor", t->s52()));
	t->s112(atoi(s->GetResourceString("Menu/TextInset", 0)));
	Chk *c = t->check;
	if (c)
		c->font = s->GetFont("Marlett");
	if (t->arrow) {
		t->s122(t->arrow, 0);
		if (t->s119() != -1)
			t->arrow->sf(t->s119());
		else
			t->arrow->sf(s->GetFont("Marlett"));
	} else if (t->chk) {
		t->s123(0, t->check, 0);
	}
	return t->GetParent()->s57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101c7480 size=0x5
#include "vgui2__MenuItem.h"
int vgui2::MenuItem::vfunc164(int a0, int a1, int a2, int a3)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x101c7650 size=0x6
#include "vgui2__MenuItem.h"
namespace lifted {
extern char g_102daaa8;
}
int vgui2::MenuItem::vfunc102()
{
    return (int)&lifted::g_102daaa8;
}
// END FUNCTION
