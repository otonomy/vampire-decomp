// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101c84a0 size=0x1e
#include "vgui2__PropertySheet.h"

// VC6 writes vgui2::PropertySheet's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::PropertySheet *pcd_emit_101c84a0(const vgui2::PropertySheet &other) { return new vgui2::PropertySheet(other); }

// TARGET: ??_GPropertySheet@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101c84c0 size=0x26
#include "vgui2__PropertySheet.h"
namespace vgui2 {
PropertySheet::~PropertySheet()
{
	::operator delete(*(void **)((char *)this + 0x6c));
	::operator delete(*(void **)((char *)this + 0x60));
}
}
// END FUNCTION

// FUNCTION: 0x101c84f0 size=0x285
#include "vgui2__PropertySheet.h"
#include "vgui2__Button.h"

extern "C" __declspec(noreturn) void exit(int);
extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)

void *sub_101b6840(unsigned int size);
struct CUnknown101b5670 { CUnknown101b5670 *sub_101b5670(const char *name); };
struct Button_101b3630 { Button_101b3630 *sub_101b3630(void *parent, const char *name, const char *text); };
extern void *vt_102551e4;

struct TabColor
{
	unsigned char _color[4];
	void Init() { _color[0] = 0; _color[1] = 0; _color[2] = 0; _color[3] = 0; }
};
struct PageTabMem
{
	void *vtable;
	char pad4[0xf0 - 4];
	bool _active;	// 0xf0
	TabColor _textColor;	// 0xf1
	TabColor _dimTextColor;	// 0xf5
};

struct PanelDar
{
	int _count;
	int _capacity;
	vgui2::Panel **_data;

	int Find(vgui2::Panel *elem)
	{
		for (int i = 0; i < _count; i++)
		{
			if (_data[i] == elem)
				return i;
		}
		return -1;
	}
	void EnsureCapacity(int wantedCapacity)
	{
		if (wantedCapacity <= _capacity)
			return;
		int newCapacity = _capacity;
		if (newCapacity == 0)
			newCapacity = 1;
		while (newCapacity < wantedCapacity)
			newCapacity *= 2;
		vgui2::Panel **newData = new vgui2::Panel *[newCapacity];
		if (newData == 0)
			exit(0);
		memset(newData, 0, sizeof(vgui2::Panel *) * newCapacity);
		_capacity = newCapacity;
		for (int i = 0; i < _count; i++)
			newData[i] = _data[i];
		delete[] _data;
		_data = newData;
	}
	void AddElement(vgui2::Panel *elem)
	{
		EnsureCapacity(_count + 1);
		_data[_count] = elem;
		_count++;
	}
};

void vgui2::PropertySheet::vfunc107(vgui2::Panel *page, const char *title, int unused)
{
	PanelDar &pages = *(PanelDar *)((char *)this + 0x58);
	PanelDar &pageTabs = *(PanelDar *)((char *)this + 0x64);
	if (pages.Find(page) >= 0)
		return;

	vgui2::Panel *tab;
	PageTabMem *mem = (PageTabMem *)vgui2::Panel::operator new(0xfc);
	if (mem)
	{
		((Button_101b3630 *)mem)->sub_101b3630(this, "tab", title);
		mem->_textColor.Init();
		mem->_dimTextColor.Init();
		mem->vtable = &vt_102551e4;
		void *kvmem = sub_101b6840(0x1c);
		((Button *)mem)->Button::vfunc161((int)(kvmem ? ((CUnknown101b5670 *)kvmem)->sub_101b5670("TabPressed") : 0));
		mem->_active = false;
		tab = (vgui2::Panel *)mem;
	}
	else
		tab = 0;

	tab->vfunc41((int)this);
	int wide, tall;
	tab->sub_101a9920(&wide, &tall);
	tab->sub_101a98f0(m_unk78, tall);
	int x, y;
	tab->sub_101a98c0(&x, &y);
	tab->sub_101a9890(x, y + m_h80);
	tab->vfunc63(0);

	pageTabs.AddElement(tab);
	pages.AddElement(page);

	page->vfunc33((int)this);
	page->vfunc21(0);
}
// END FUNCTION

// FUNCTION: 0x101c8780 size=0x35
#include "vgui2__PropertySheet.h"
struct PSView { char pad[0x58]; int m_n; int m_unk5c; int *m_data; };
// TARGET: vgui2::PropertySheet::vfunc108
void vgui2::PropertySheet::vfunc108(int panel)
{
    PSView *v = (PSView *)this;
    int i;
    for (i = 0; i < v->m_n; i++) {
        if (v->m_data[i] == panel) {
            if (i >= 0)
                vfunc127(i);
            return;
        }
    }
}
// END FUNCTION

// FUNCTION: 0x101c87c0 size=0x16
#include "vgui2__PropertySheet.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int vgui2::PropertySheet::vfunc109(int a0)
{
    *(int *)((char *)this + 0x78) = a0;
    return ((lifted::V *)this)->f57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101c87e0 size=0x19
#include "vgui2__PropertySheet.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int vgui2::PropertySheet::vfunc110(int a0)
{
    *(int *)((char *)this + 0x80) = a0;
    return ((lifted::V *)this)->f57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101c8800 size=0x3b
#include "vgui2__PropertySheet.h"
extern "C" char *strcpy(char *, const char *);
#pragma intrinsic(strcpy)
struct SheetView { char pad[0x84]; int m84; char m88[0x20]; char ma8; };
// TARGET: vgui2::PropertySheet::vfunc111
void vgui2::PropertySheet::vfunc111(const char *s, int a, char flag)
{
	SheetView *v = (SheetView *)this;
	v->m84 = a;
	strcpy(v->m88, s);
	v->ma8 = flag;
	vfunc57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101c89f0 size=0x4
#include "vgui2__PropertySheet.h"
int vgui2::PropertySheet::vfunc112()
{
    return *(int *)((char *)this + 0x70);
}
// END FUNCTION

// FUNCTION: 0x101c8a00 size=0x4
#include "vgui2__PropertySheet.h"
int vgui2::PropertySheet::vfunc119()
{
    return *(int *)((char *)this + 0x74);
}
// END FUNCTION

// FUNCTION: 0x101c8a10 size=0x4
#include "vgui2__PropertySheet.h"
int vgui2::PropertySheet::vfunc123()
{
    return *(int *)((char *)this + 0x58);
}
// END FUNCTION

// FUNCTION: 0x101c8a20 size=0xb
#include "vgui2__PropertySheet.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual int f109(); };
}
int vgui2::PropertySheet::vfunc120()
{
    return ((lifted::V *)(*(int *)((char *)this + 0x74)))->f109();
}
// END FUNCTION

// FUNCTION: 0x101c8aa0 size=0xf
#include "vgui2__PropertySheet.h"
// TARGET: vgui2::PropertySheet::vfunc15
int vgui2::PropertySheet::vfunc15(int x) { vgui2::Panel *p = *(vgui2::Panel **)((char *)this + 0x70); if (p) return p->vfunc15(x); }
// END FUNCTION

// FUNCTION: 0x101c8ab0 size=0x245
#include "vgui2__PropertySheet.h"
#define VV(n) virtual void n();
#define V5(p) VV(p##0) VV(p##1) VV(p##2) VV(p##3) VV(p##4)
#define V10(p) V5(p##a) V5(p##b)
struct SChild
{
	V5(a) VV(a5)
	virtual void vfunc6();
	V10(b) VV(c0) VV(c1) VV(c2) VV(c3)
	virtual void SetVisible(int b);
	V10(d) V10(e) V5(f) VV(g0) VV(g1)
	virtual void vfunc49();
	V10(h) VV(i0) VV(i1) VV(i2)
	virtual void vfunc63(bool b);
	V10(j) V10(k) V10(l) V10(m) V5(n) VV(o0) VV(o1)
	virtual void vfunc111(int n);
	V5(p) VV(q0)
	virtual void vfunc118(int n);
	void sub_101a9950(int x, int y, int w, int h);
};
struct SSurface
{
	V10(a) V10(b) V10(c) V5(d) VV(e0) VV(e1) VV(e2) VV(e3)
	virtual void GetScreenSize(int *w, int *h);
};
struct SColorB { VV(a0) VV(a1) VV(a2) VV(a3) virtual int vfunc4(const char *psz); };
struct SColorA { VV(a0) VV(a1) VV(a2) VV(a3) virtual SColorB *vfunc4(int a); };
struct SPS
{
	V10(a) V10(b) V10(c) V10(d) V10(e) V10(f) V10(g) V10(h) V10(i) V10(j) V10(k) V10(l) V5(m) VV(n0) VV(n1)
	virtual void vfunc127(int a);
	char pad[0x64 - 0x4];
	int m_nPanels;
	char pad2[4];
	SChild **m_ppPanels;
	SChild *m_pPage;
	SChild *m_pActive;
	int m_nTabWide;
	char pad3[4];
	int m_nGap;
	int m_nFont;
	char m_szScheme[0x20];
	bool m_bFlag;
	void sub_101a9980(int *x, int *y, int *w, int *h);
	int sub_101aa220();
};
extern SSurface *sub_101ac8d0();
extern SColorA *sub_101ac8c0();
#define PANEL(i) ((i) >= 0 && (i) < ps->m_nPanels ? ps->m_ppPanels[i] : (SChild *)0)
// TARGET: vgui2::PropertySheet::vfunc101
void vgui2::PropertySheet::vfunc101()
{
	SPS *ps = (SPS *)this;
	Panel::vfunc101();
	if (!ps->m_pPage)
		ps->vfunc127(0);
	int sw, sh;
	sub_101ac8d0()->GetScreenSize(&sw, &sh);
	int x, y, wide, tall;
	ps->sub_101a9980(&x, &y, &wide, &tall);
	if (ps->m_pPage) {
		double s = sh * 0.0013020833333333333;
		double v = s * 28.0 + ps->m_nGap;
		ps->m_pPage->sub_101a9950(0, (int)v, wide, (int)(tall - v));
	}
	int n = ps->m_nPanels;
	int xpos = 0;
	int color;
	if (ps->m_szScheme[0])
		color = sub_101ac8c0()->vfunc4(ps->sub_101aa220())->vfunc4(ps->m_szScheme);
	else
		color = -1;
	for (int i = 0; i < n; i++) {
		SChild *c = PANEL(i);
		c->vfunc111(ps->m_nFont);
		if (color != -1) {
			c = PANEL(i);
			c->vfunc118(color);
		}
		c = PANEL(i);
		c->vfunc63(ps->m_bFlag);
		if (PANEL(i) == ps->m_pActive) {
			double s = sh * 0.0013020833333333333;
			ps->m_pActive->sub_101a9950(xpos, (int)(s * 2.0 + ps->m_nGap), ps->m_nTabWide, (int)(s * 27.0));
		} else {
			c = PANEL(i);
			double s = sh * 0.0013020833333333333;
			c->sub_101a9950(xpos, (int)(s * 4.0 + ps->m_nGap), ps->m_nTabWide, (int)(s * 25.0));
		}
		c = PANEL(i);
		c->SetVisible(1);
		xpos += ps->m_nTabWide + 1;
	}
	if (ps->m_pPage) {
		ps->m_pPage->vfunc49();
		ps->m_pPage->vfunc6();
	}
	if (ps->m_pActive) {
		ps->m_pActive->vfunc49();
		ps->m_pActive->vfunc6();
	}
}
// END FUNCTION

// FUNCTION: 0x101c8d00 size=0x3e
#include "vgui2__PropertySheet.h"
struct VecView
{
	char pad[0x64];
	int m_Size;
	int pad2;
	int *m_pData;
	int Count() const { return m_Size; }
	int Get(int i) const { return (i >= 0 && i < *(volatile int *)&m_Size) ? m_pData[i] : 0; }
};
void vgui2::PropertySheet::vfunc126(int panel)
{
	VecView *v = (VecView *)this;
	int n = v->Count();
	for (int i = 0; i < n; i++)
	{
		if (v->Get(i) == panel)
		{
			vfunc127(i);
			return;
		}
	}
}
// END FUNCTION

// FUNCTION: 0x101c8d70 size=0x12
#include "vgui2__PropertySheet.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual int f129(int, int); };
}
int vgui2::PropertySheet::vfunc124(int a0)
{
    return ((lifted::V *)this)->f129(a0, 0);
}
// END FUNCTION

// FUNCTION: 0x101c8d90 size=0x12
#include "vgui2__PropertySheet.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual int f129(int, int); };
}
int vgui2::PropertySheet::vfunc125(int a0)
{
    return ((lifted::V *)this)->f129(a0, 1);
}
// END FUNCTION

// FUNCTION: 0x101c8db0 size=0x8b
#include "vgui2__PropertySheet.h"
#include <string.h>
struct CSheetPageView {
virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9();
virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24(); virtual void a25(); virtual void a26(); virtual void a27(); virtual void a28(); virtual void a29();
virtual void a30(); virtual void a31(); virtual void a32(); virtual void a33(); virtual void a34(); virtual void a35(); virtual void a36(); virtual void a37(); virtual void a38(); virtual void a39();
virtual void a40(); virtual void a41(); virtual void a42(); virtual void a43(); virtual void a44(); virtual void a45(); virtual void vfunc46(int);
virtual void a47(); virtual void a48(); virtual void a49();
virtual void a50(); virtual void a51(); virtual void a52(); virtual void a53(); virtual void a54(); virtual void a55(); virtual void a56(); virtual void a57(); virtual void a58(); virtual void a59();
virtual void a60(); virtual void a61(); virtual void a62(); virtual void a63(); virtual void a64(); virtual void a65(); virtual void a66(); virtual void a67(); virtual void a68(); virtual void a69();
virtual void a70(); virtual void a71(); virtual void a72(); virtual void a73(); virtual void a74(); virtual void a75(); virtual void a76(); virtual void a77(); virtual void a78(); virtual void a79();
virtual void a80(); virtual void a81(); virtual void a82(); virtual void a83(); virtual void a84(); virtual void a85(); virtual void a86(); virtual void a87(); virtual void a88(); virtual void a89();
virtual void a90(); virtual void a91(); virtual void a92(); virtual void a93(); virtual void a94(); virtual void a95(); virtual void a96(); virtual void a97(); virtual void a98(); virtual void a99();
virtual void a100(); virtual void a101(); virtual void a102(); virtual void a103(); virtual void a104(); virtual void a105(); virtual void a106(); virtual void a107(); virtual void a108();
virtual void vfunc109(char *, int);
};
struct CPageVec
{
	int m_unk60; int m_nCount; int m_unk68; CSheetPageView **m_pData;
	bool IsValidIndex(int i) const { return (i >= 0) && (i < m_nCount); }
	CSheetPageView *Get(int i) const { return IsValidIndex(i) ? m_pData[i] : 0; }
};
void vgui2::PropertySheet::vfunc129(const char *pszName, int a1)
{
	for (int i = 0; i < ((CPageVec *)((char *)this + 0x60))->m_nCount; i++)
	{
		char szTitle[50];
		((CPageVec *)((char *)this + 0x60))->Get(i)->vfunc109(szTitle, 50);
		int n = strlen(szTitle);
		if (!_strnicmp(pszName, szTitle, n))
			((CPageVec *)((char *)this + 0x60))->Get(i)->vfunc46(a1);
	}
}
// END FUNCTION

// FUNCTION: 0x101c90f0 size=0x295
#include "vgui2__PropertySheet.h"
#include "vgui2__PageTab.h"

extern void *sub_101b6840(unsigned int size);

struct KV_101c90f0 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16();
	virtual void SetPtr(const char *key, void *value);
	KV_101c90f0 *sub_101b5670(const char *name);
};

struct IVGui_101c90f0 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void PostMessage(int target, void *params, int from, float delaySeconds);
};
extern IVGui_101c90f0 *sub_101ac8f0();

static inline KV_101c90f0 *NewKV(const char *name)
{
	KV_101c90f0 *kv = (KV_101c90f0 *)sub_101b6840(0x1c);
	return kv ? kv->sub_101b5670(name) : 0;
}

struct PageDar_101c90f0
{
	int _count;
	int _capacity;
	vgui2::Panel **_data;
	vgui2::Panel *Get(int i) { return (i >= 0 && i < _count) ? _data[i] : 0; }
};

struct SheetFields_101c90f0
{
	char pad0[0x58];
	PageDar_101c90f0 _pages;	// 0x58
	PageDar_101c90f0 _pageTabs;	// 0x64
	vgui2::Panel *_activePage;	// 0x70
	vgui2::Panel *_activeTab;	// 0x74
	int m_78;
	int _activeTabIndex;	// 0x7c
};

void vgui2::PropertySheet::vfunc127(int index)
{
	SheetFields_101c90f0 *f = (SheetFields_101c90f0 *)this;
	if (index != -1)
	{
		if (f->_pages.Get(index) == f->_activePage)
			return;
		if (!f->_pages.Get(index))
			return;
	}

	if (f->_activePage)
	{
		sub_101ac8f0()->PostMessage(f->_activePage->vfunc0(), NewKV("PageHide"), vfunc0(), 0.0f);
		KV_101c90f0 *msg = NewKV("PageTabActivated");
		msg->SetPtr("panel", 0);
		sub_101ac8f0()->PostMessage(f->_activePage->vfunc0(), msg, vfunc0(), 0.0f);
		f->_activePage->vfunc21(0);
	}
	if (f->_activeTab)
		((vgui2::PageTab *)f->_activeTab)->vfunc166(0);

	if (index != -1)
	{
		f->_activePage = f->_pages.Get(index);
		f->_activeTab = f->_pageTabs.Get(index);
		f->_activeTabIndex = index;

		f->_activePage->vfunc21(1);
		f->_activePage->vfunc49();
		f->_activeTab->vfunc21(1);
		f->_activeTab->vfunc49();
		((vgui2::PageTab *)f->_activeTab)->vfunc166(1);
		f->_activeTab->vfunc15(0);

		sub_101ac8f0()->PostMessage(f->_activePage->vfunc0(), NewKV("PageShow"), vfunc0(), 0.0f);
		KV_101c90f0 *msg = NewKV("PageTabActivated");
		msg->SetPtr("panel", f->_activeTab);
		sub_101ac8f0()->PostMessage(f->_activePage->vfunc0(), msg, vfunc0(), 0.0f);
	}
	else
	{
		f->_activePage = 0;
		f->_activeTab = 0;
		f->_activeTabIndex = 0;
	}

	vfunc43(NewKV("PageChanged"));
	vfunc57(0, 0);
	vfunc6();
}
// END FUNCTION

// FUNCTION: 0x101c9390 size=0x51
#include "vgui2__PropertySheet.h"

// TARGET: vgui2::PropertySheet::vfunc72
int vgui2::PropertySheet::vfunc72(int direction)
{
	if ( !*(vgui2::Panel **)((char *)this + 0x70) )
		return 0;

	for ( int i = 0; i < (*(vgui2::Panel **)((char *)this + 0x70))->vfunc36(); i++ )
	{
		int nRet = (*(vgui2::Panel **)((char *)this + 0x70))->vfunc37(i)->vfunc72(direction);
		if ( nRet )
			return nRet;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x101c93f0 size=0x39
#include "vgui2__PropertySheet.h"
struct KV23 { KV23 *sub_101b5670(const char *); };
void *sub_101b6840(int);
struct PSV {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
  virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
  virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
  virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
  virtual void v40(); virtual void v41(); virtual void v42();
  virtual int v43(KV23 *);
};
// TARGET: vgui2::PropertySheet::vfunc128
int vgui2::PropertySheet::vfunc128()
{
  KV23 *kv = (KV23 *)sub_101b6840(0x1c);
  KV23 *msg = kv ? kv->sub_101b5670("OpenContextMenu") : 0;
  return ((PSV *)this)->v43(msg);
}
// END FUNCTION

// FUNCTION: 0x101c9430 size=0x39
#include "vgui2__PropertySheet.h"
void vgui2::PropertySheet::vfunc92(int code)
{
	switch (code) {
	case 0x59:
		vfunc127(m_w7c - 1);
		break;
	case 0x5b:
		vfunc127(m_w7c + 1);
		break;
	default:
		Panel::sub_101aa6f0(code);
		break;
	}
}
// END FUNCTION

// FUNCTION: 0x101c9520 size=0x6
#include "vgui2__PropertySheet.h"
namespace lifted {
extern char g_102dacf0;
}
int vgui2::PropertySheet::vfunc102()
{
    return (int)&lifted::g_102dacf0;
}
// END FUNCTION
