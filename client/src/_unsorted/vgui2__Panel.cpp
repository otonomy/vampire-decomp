// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10029520 size=0x4
#include "vgui2__Panel.h"
int vgui2::Panel::vfunc0()
{
    return *(int *)((char *)this + 4);
}
// END FUNCTION

// FUNCTION: 0x10029530 size=0x3
#include "vgui2__Panel.h"
void * vgui2::Panel::vfunc1()
{
    return this;
}
// END FUNCTION

// FUNCTION: 0x101a9460 size=0x1e
#include "vgui2__Panel.h"

// VC6 writes vgui2::Panel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::Panel *pcd_emit_101a9460(const vgui2::Panel &other) { return new vgui2::Panel(other); }

// TARGET: ??_GPanel@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101a9530 size=0xb5
#include "vgui2__Panel.h"

struct SurfaceSizeView0
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

struct ParentView0
{
	int sub_101aa220();
};

struct PanelSelfView0
{
	void sub_101aa230(int);
	void sub_101a9ff0(int);
};

int sub_101ac8d0();

vgui2::Panel::Panel(Panel *parent, const char *name)
{
	SurfaceSizeView0 *pSurface = (SurfaceSizeView0 *)sub_101ac8d0();
	int nWide, nTall;
	pSurface->v39(&nTall, &nWide);

	double flW = nWide * 0.0013020833333333333;
	int nW = (int)(flW * 24.0);
	double flH = nTall * 0.0009765625;
	int nH = (int)(flH * 64.0);

	sub_101a96a0(0, 0, nH, nW);

	sub_101a9810(name);
	((PanelSelfView0 *)this)->sub_101a9ff0((int)parent);
	if (parent != 0)
	{
		int nValue = ((ParentView0 *)parent)->sub_101aa220();
		((PanelSelfView0 *)this)->sub_101aa230(nValue);
	}
}
// END FUNCTION

// FUNCTION: 0x101a9860 size=0xd
#include "vgui2__Panel.h"
// TARGET: vgui2::Panel::vfunc18
const char *vgui2::Panel::vfunc18() { const char *s = *(const char **)((char *)this + 0x2c); return s ? s : ""; }
// END FUNCTION

// FUNCTION: 0x101a9870 size=0x16
#include "vgui2__Panel.h"
namespace lifted {
extern char g_102d813c;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual int f102(); };
}
int vgui2::Panel::vfunc19()
{
    int t0 = ((lifted::V *)this)->f102();
    if (t0 != 0) {
        return *(int *)((char *)t0 + 8);
    }
    return (int)&lifted::g_102d813c;
}
// END FUNCTION

// FUNCTION: 0x101a99b0 size=0x3d
#include "vgui2__Panel.h"
struct Chain2 { virtual void c0(); virtual int Slot1(); };
struct Chain1 { virtual void c0(); virtual Chain2 *Slot1(int); };
struct SurfView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual int Slot18(int);
};
SurfView *sub_101ac900();
int vgui2::Panel::vfunc31()
{
	int h = sub_101ac900()->Slot18(vfunc0());
	if (h)
	{
		Chain1 *c = (Chain1 *)sub_101ac900();
		return (c->Slot1(h))->Slot1();
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x101a9a20 size=0x1e
#include "vgui2__Panel.h"
namespace lifted {
int sub_101ac900();
struct V { virtual int f0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual int f14(int); };
}
int vgui2::Panel::vfunc22()
{
    return ((lifted::V *)(lifted::sub_101ac900()))->f14(((lifted::V *)this)->f0());
}
// END FUNCTION

// FUNCTION: 0x101a9a40 size=0x1e
#include "vgui2__Panel.h"
namespace lifted {
int sub_101ac900();
struct V { virtual int f0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); };
}
int vgui2::Panel::vfunc48()
{
    return ((lifted::V *)(lifted::sub_101ac900()))->f21(((lifted::V *)this)->f0());
}
// END FUNCTION

// FUNCTION: 0x101a9a60 size=0x25
#include "vgui2__Panel.h"
namespace lifted {
int sub_101ac8d0();
struct V { virtual int f0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual int f51(int); };
}
int vgui2::Panel::vfunc6()
{
    *(char *)((char *)this + 0x18) = 1;
    return ((lifted::V *)(lifted::sub_101ac8d0()))->f51(((lifted::V *)this)->f0());
}
// END FUNCTION

// FUNCTION: 0x101a9a90 size=0x55
#include "vgui2__Panel.h"

extern void *sub_101ac8d0();
extern void *sub_101ac900();

struct IFontView101a9a90
{
	virtual void f0();
	virtual void f1();
	virtual void f2();
	virtual void f3();
	virtual void f4();
	virtual void f5();
	virtual void f6();
};

struct ISurfView101a9a90
{
	virtual void s0();
	virtual IFontView101a9a90 *s1(int h);
	virtual void s2();
	virtual void s3();
	virtual void s4();
	virtual void s5();
	virtual void s6();
	virtual void s7();
	virtual void s8();
	virtual void s9();
	virtual void s10();
	virtual void s11();
	virtual void s12();
	virtual void s13();
	virtual void s14();
	virtual void s15();
	virtual int s16(int x);
	virtual int s17(int a, int b);
};

struct IOtherView101a9a90
{
	virtual void o0();
	virtual void o1();
	virtual void o2();
	virtual void o3();
	virtual void o4();
	virtual void o5();
	virtual int o6();
};

void vgui2::Panel::vfunc5()
{
	int b = ((IOtherView101a9a90 *)sub_101ac8d0())->o6();
	int n = ((ISurfView101a9a90 *)sub_101ac900())->s16(b);
	for (int i = 0; i < n; i++)
	{
		int h = ((ISurfView101a9a90 *)sub_101ac900())->s17(b, i);
		((ISurfView101a9a90 *)sub_101ac900())->s1(h)->f6();
	}
}
// END FUNCTION

// FUNCTION: 0x101a9b30 size=0x35
#include "vgui2__Panel.h"
namespace lifted {
struct C101a9af0 { int sub_101a9af0(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual bool f22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual int f83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual int f101(); };
}
void vgui2::Panel::vfunc3()
{
    ((lifted::V *)this)->f83();
    bool t0 = ((lifted::V *)this)->f22();
    if (t0 != 0) {
        if ((*(char *)((char *)this + 0x30)) != 0) {
            ((lifted::C101a9af0 *)this)->sub_101a9af0();
            *(char *)((char *)this + 0x30) = 0;
            ((lifted::V *)this)->f101(); return;
        }
    }
}
// END FUNCTION

// FUNCTION: 0x101a9b70 size=0xd
#include "vgui2__Panel.h"
// TARGET: vgui2::Panel::vfunc4
void vgui2::Panel::vfunc4()
{
	vfunc106(m_b18);
}
// END FUNCTION

// FUNCTION: 0x101a9b80 size=0x2f9
#include "vgui2__Panel.h"
#include "vgui2__BuildGroup.h"
#include "utlvector.h"

namespace vgui2
{

struct IPanel_Paint
{
	virtual void u0();
	virtual void u1();
	virtual void u2();
	virtual void u3();
	virtual void u4();
	virtual void u5();
	virtual void u6();
	virtual void u7();
	virtual void u8();
	virtual void u9();
	virtual void GetClipRect(unsigned int vpanel, int &x0, int &y0, int &x1, int &y1);
};

struct ISurface_Paint
{
	virtual void u0();
	virtual void u1();
	virtual void u2();
	virtual void u3();
	virtual void u4();
	virtual void u5();
	virtual void u6();
	virtual void u7();
	virtual void PushMakeCurrent(unsigned int vpanel, bool useInsets);
	virtual void PopMakeCurrent(unsigned int vpanel);
	virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14();
	virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
	virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24();
	virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29();
	virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34();
	virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39();
	virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44();
	virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49();
	virtual void SwapBuffers(unsigned int vpanel);
	virtual void Invalidate(unsigned int vpanel);
	virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56();
	virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61();
	virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66();
	virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71();
	virtual void u72(); virtual void u73(); virtual void u74();
	virtual bool ShouldPaintChildPanel(unsigned int vpanel);
};

struct PanelLayout
{
	virtual unsigned int GetVPanel();
	virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5();
	virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10();
	virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15();
	virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20();
	virtual void u21();
	virtual bool IsVisible();
	virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27();
	virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32();
	virtual void u33(); virtual void u34(); virtual void u35();
	virtual int GetChildCount();
	virtual PanelLayout *GetChild(int index);
	virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42();
	virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47();
	virtual bool IsPopup();
	virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53();
	virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58();
	virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63();
	virtual void u64(); virtual void u65(); virtual void u66();
	virtual bool IsBuildGroupEnabled();
	virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72();
	virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77();
	virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82();
	virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87();
	virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92();
	virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96();
	virtual void PaintBackground();
	virtual void Paint();
	virtual void PaintBorder();
	virtual void PaintBuildOverlay();
	virtual void u101(); virtual void u102();
	virtual void PostChildPaint();
	virtual void u104(); virtual void u105();
	virtual void PaintTraverse(bool repaint);

	int m_pad04[4];
	void *_border;                // +0x14
	bool _needsRepaint;           // +0x18
	char m_pad19[3];
	BuildGroup *_buildGroup;      // +0x1c
	int m_pad20[2];
	bool _paintBorderEnabled;     // +0x28
	bool _paintBackgroundEnabled; // +0x29
	bool _paintEnabled;           // +0x2a
	char m_pad2b[0x29];
	bool _postChildPaintEnabled;  // +0x54
};

struct PHandle_Paint
{
	unsigned int m_hPanel;
	PanelLayout *sub_101ac670();
};

}

vgui2::ISurface_Paint *sub_101ac8d0();
vgui2::IPanel_Paint *sub_101ac900();

// TARGET: ?vfunc106@Panel@vgui2@@UAEX_N@Z
void vgui2::Panel::vfunc106(bool repaint)
{
	PanelLayout *self = (PanelLayout *)this;

	if (!self->IsVisible())
	{
		return;
	}

	if (self->_needsRepaint)
	{
		repaint = true;
	}

	self->_needsRepaint = false;

	int clipRect[4];
	sub_101ac900()->GetClipRect(self->GetVPanel(), clipRect[0], clipRect[1], clipRect[2], clipRect[3]);

	if ((clipRect[2] <= clipRect[0]) || (clipRect[3] <= clipRect[1]))
	{
		repaint = false;
	}

	if (repaint && (self->_paintBorderEnabled || self->_paintBackgroundEnabled || self->_paintEnabled))
	{
		sub_101ac8d0()->PushMakeCurrent(self->GetVPanel(), false);
		if (self->_paintBackgroundEnabled)
		{
			self->PaintBackground();
		}
		sub_101ac8d0()->PopMakeCurrent(self->GetVPanel());

		sub_101ac8d0()->PushMakeCurrent(self->GetVPanel(), true);
		if (self->_paintEnabled)
		{
			self->Paint();
		}
		sub_101ac8d0()->PopMakeCurrent(self->GetVPanel());
	}

	int childCount = self->GetChildCount();
	for (int i = 0; i < childCount; i++)
	{
		PanelLayout *child = self->GetChild(i);
		if (!child->IsPopup())
		{
			if (sub_101ac8d0()->ShouldPaintChildPanel(child->GetVPanel()))
			{
				child->PaintTraverse(repaint);
			}
			else
			{
				sub_101ac8d0()->Invalidate(child->GetVPanel());
				if (repaint)
				{
					child->_needsRepaint = true;
				}
			}
		}
	}

	if (repaint)
	{
		if (self->_paintBorderEnabled && self->_border != 0)
		{
			sub_101ac8d0()->PushMakeCurrent(self->GetVPanel(), false);
			self->PaintBorder();
			sub_101ac8d0()->PopMakeCurrent(self->GetVPanel());
		}

		if (self->IsBuildGroupEnabled())
		{
			CUtlVector<PHandle_Paint> *controlGroup = (CUtlVector<PHandle_Paint> *)self->_buildGroup->vfunc14();
			for (int i = 0; i < controlGroup->Size(); ++i)
			{
				sub_101ac8d0()->PushMakeCurrent(((*controlGroup)[i].sub_101ac670())->GetVPanel(), false);
				((*controlGroup)[i].sub_101ac670())->PaintBuildOverlay();
				sub_101ac8d0()->PopMakeCurrent(((*controlGroup)[i].sub_101ac670())->GetVPanel());
			}
			self->_buildGroup->vfunc18();
		}

		if (self->_postChildPaintEnabled)
		{
			sub_101ac8d0()->PushMakeCurrent(self->GetVPanel(), false);
			self->PostChildPaint();
			sub_101ac8d0()->PopMakeCurrent(self->GetVPanel());
		}
	}

	sub_101ac8d0()->SwapBuffers(self->GetVPanel());
}
// END FUNCTION

// FUNCTION: 0x101a9e80 size=0x17
#include "vgui2__Panel.h"
namespace lifted {
struct V { virtual int f0(); virtual void u1(); virtual int f2(int); };
}
int vgui2::Panel::vfunc99()
{
    return ((lifted::V *)(*(int *)((char *)this + 0x14)))->f2(((lifted::V *)this)->f0());
}
// END FUNCTION

// FUNCTION: 0x101a9ea0 size=0x56
#include "vgui2__Panel.h"

extern void *sub_101ac8d0();

struct ISurfV97
{
	virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
	virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
	virtual void d8(); virtual void d9();
	virtual void s10(int a);
	virtual void d11();
	virtual void s12(int a, int b, int c, int d);
};

void vgui2::Panel::vfunc97()
{
	int a, b, c;
	sub_101a9920(&c, &b);
	vfunc52((int)&a);
	((ISurfV97 *)sub_101ac8d0())->s10(a);
	((ISurfV97 *)sub_101ac8d0())->s12(0, 0, c, b);
}
// END FUNCTION

// FUNCTION: 0x101a9f00 size=0x1
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc98()
{
}
// END FUNCTION

// FUNCTION: 0x101a9f10 size=0x1
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc103()
{
}
// END FUNCTION

// FUNCTION: 0x101a9f20 size=0x9b
#include "vgui2__Panel.h"
struct ISurfX {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
	virtual void SetColor(int, int, int, int);
	virtual void FillRect(int, int, int, int);
};
ISurfX *sub_101ac8d0();
// TARGET: vgui2::Panel::vfunc100
void vgui2::Panel::vfunc100()
{
	int w, t;
	sub_101a9920(&w, &t);
	sub_101ac8d0()->SetColor(0, 0, 0, 255);
	sub_101ac8d0()->FillRect(0, 0, w, 2);
	sub_101ac8d0()->FillRect(0, t - 2, w, t);
	sub_101ac8d0()->FillRect(0, 2, 2, t - 2);
	sub_101ac8d0()->FillRect(w - 2, 2, w, t - 2);
}
// END FUNCTION

// FUNCTION: 0x101a9fc0 size=0x21
#include "vgui2__Panel.h"
bool vgui2::Panel::vfunc73() { if ((char)vfunc22() && *((char *)this + 0x29) && *((unsigned char *)this + 0x27) == 0xff) return true; return false; }
// END FUNCTION

// FUNCTION: 0x101a9ff0 size=0x60
#include "vgui2__Panel.h"

struct SurfView {
	virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
	virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
	virtual void s15(int, int);
};
int sub_101ac900();

void vgui2::Panel::vfunc33(int p)
{
	if (p)
	{
		SurfView *surf = (SurfView *)sub_101ac900();
		surf->s15(this->vfunc0(), ((vgui2::Panel *)p)->vfunc0());
		if (m_unk4[1] == 1)
			m_unk4[1] = ((vgui2::Panel *)p)->sub_101aa220();
	}
	else
	{
		SurfView *surf = (SurfView *)sub_101ac900();
		surf->s15(this->vfunc0(), 0);
	}
}
// END FUNCTION

// FUNCTION: 0x101aa080 size=0x3
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc10(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101aa090 size=0x3
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc11(int a0, int a1)
{
}
// END FUNCTION

// FUNCTION: 0x101aa0d0 size=0x1e
#include "vgui2__Panel.h"
namespace lifted {
int sub_101ac900();
struct V { virtual int f0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual int f19(int); };
}
int vgui2::Panel::vfunc49()
{
    return ((lifted::V *)(lifted::sub_101ac900()))->f19(((lifted::V *)this)->f0());
}
// END FUNCTION

// FUNCTION: 0x101aa0f0 size=0x32
#include "vgui2__Panel.h"
namespace lifted {
int sub_101ac900();
struct V { virtual int f0(int); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual bool f20(int); };
}
bool vgui2::Panel::vfunc34(int a0)
{
    if (a0 == 0) {
        return 0;
    }
    int t0 = lifted::sub_101ac900();
    return ((lifted::V *)t0)->f20(((lifted::V *)this)->f0(a0));
}
// END FUNCTION

// FUNCTION: 0x101aa200 size=0xa
#include "vgui2__Panel.h"
bool vgui2::Panel::vfunc39(char a0)
{
    *(char *)((char *)this + 0x32) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101aa210 size=0x4
#include "vgui2__Panel.h"
bool vgui2::Panel::vfunc40()
{
    return *(bool *)((char *)this + 0x32);
}
// END FUNCTION

// FUNCTION: 0x101aa250 size=0x5
#include "vgui2__Panel.h"
int vgui2::Panel::vfunc72(int a0)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x101aa5c0 size=0x58
#include "vgui2__Panel.h"
#include "vgui2__BuildGroup.h"

struct VGuiSystemView
{
	virtual void s0();
	virtual void s1();
	virtual void s2();
	virtual void s3();
	virtual void s4();
	virtual void s5();
	virtual void s6();
	virtual void s7();
	virtual void s8();
	virtual int s9();
};

struct VGuiSchemeView
{
	virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
	virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
	virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
	virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
	virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
	virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
	virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
	virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
	virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
	virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
	virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47();
	virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
	virtual int s52(int);
};

int sub_101ac8b0();
int sub_101ac8d0();

int vgui2::Panel::vfunc12()
{
	int i = vfunc55();
	if (vfunc67())
		i = (*(vgui2::BuildGroup **)((char *)this + 0x1c))->vfunc22(this);

	if (((VGuiSystemView *)sub_101ac8b0())->s9() != 0)
		i = ((VGuiSystemView *)sub_101ac8b0())->s9();

	return ((VGuiSchemeView *)sub_101ac8d0())->s52(i);
}
// END FUNCTION

// FUNCTION: 0x101aa620 size=0x1
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc83()
{
}
// END FUNCTION

// FUNCTION: 0x101aa630 size=0x3
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc84(int a0, int a1)
{
}
// END FUNCTION

// FUNCTION: 0x101aa640 size=0x1
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc85()
{
}
// END FUNCTION

// FUNCTION: 0x101aa650 size=0x1
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc86()
{
}
// END FUNCTION

// FUNCTION: 0x101aa660 size=0x3
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc87(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101aa670 size=0x3
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc88(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101aa680 size=0x3
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc89(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101aa780 size=0x20
#include "vgui2__Panel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual int f31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual int f95(); };
}
void vgui2::Panel::vfunc95()
{
    int t0 = ((lifted::V *)this)->f31();
    if (t0 != 0) {
        ((lifted::V *)(((lifted::V *)this)->f31()))->f95(); return;
    }
}
// END FUNCTION

// FUNCTION: 0x101aa7a0 size=0x20
#include "vgui2__Panel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual int f31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual int f96(); };
}
void vgui2::Panel::vfunc96()
{
    int t0 = ((lifted::V *)this)->f31();
    if (t0 != 0) {
        ((lifted::V *)(((lifted::V *)this)->f31()))->f96(); return;
    }
}
// END FUNCTION

// FUNCTION: 0x101aa7c0 size=0x77
#include "vgui2__Panel.h"

int sub_101ac900();

struct SurfV
{
	virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
	virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
	virtual void vfunc10(int, int *, int *, int *, int *);
};

struct SelfV
{
	virtual int vfunc0();
};

bool vgui2::Panel::vfunc25(int x, int y)
{
	int l, t, r, b;
	((SurfV *)sub_101ac900())->vfunc10(((SelfV *)this)->vfunc0(), &l, &t, &r, &b);
	if (x < l)
		return false;
	if (y < t)
		return false;
	if (x >= r)
		return false;
	bool inside = y < b;
	return inside;
}
// END FUNCTION

// FUNCTION: 0x101aaad0 size=0xa
#include "vgui2__Panel.h"
int vgui2::Panel::vfunc54(int a0)
{
    *(int *)((char *)this + 0xc) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101aaae0 size=0x4
#include "vgui2__Panel.h"
int vgui2::Panel::vfunc55()
{
    return *(int *)((char *)this + 0xc);
}
// END FUNCTION

// FUNCTION: 0x101aabb0 size=0x34
#include "vgui2__Panel.h"
struct IPanelView {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual int Slot10(int vpanel, int a, int b, int c, int d);
};
IPanelView *sub_101ac900();
// TARGET: vgui2::Panel::vfunc9
int vgui2::Panel::vfunc9(int a, int b, int c, int d)
{
	return sub_101ac900()->Slot10(vfunc0(), a, b, c, d);
}
// END FUNCTION

// FUNCTION: 0x101aabf0 size=0x1e
#include "vgui2__Panel.h"
namespace lifted {
int sub_101ac900();
struct V { virtual int f0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual int f16(int); };
}
int vgui2::Panel::vfunc36()
{
    return ((lifted::V *)(lifted::sub_101ac900()))->f16(((lifted::V *)this)->f0());
}
// END FUNCTION

// FUNCTION: 0x101aac60 size=0x22
#include "vgui2__Panel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual int f31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual int f58(int); };
}
void vgui2::Panel::vfunc58(int a0)
{
    int t0 = ((lifted::V *)this)->f31();
    if (t0 != 0) {
        ((lifted::V *)(((lifted::V *)this)->f31()))->f58((int)this);
    }
}
// END FUNCTION

// FUNCTION: 0x101aac90 size=0x22
#include "vgui2__Panel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual int f31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual int f59(int); };
}
void vgui2::Panel::vfunc59(int a0)
{
    int t0 = ((lifted::V *)this)->f31();
    if (t0 != 0) {
        ((lifted::V *)(((lifted::V *)this)->f31()))->f59((int)this);
    }
}
// END FUNCTION

// FUNCTION: 0x101aacc0 size=0xc
#include "vgui2__Panel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual int f105(int); };
}
int vgui2::Panel::vfunc15(int a0)
{
    a0 = (int)this;
    return ((lifted::V *)this)->f105(a0);
}
// END FUNCTION

// FUNCTION: 0x101aad00 size=0x3
#include "vgui2__Panel.h"
int vgui2::Panel::vfunc17()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x101aad10 size=0x22
#include "vgui2__Panel.h"
struct ISurf { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); };
ISurf *sub_101ac8b0();
// TARGET: ?vfunc56@Panel@vgui2@@UAE_NXZ
bool vgui2::Panel::vfunc56() { ISurf *s = sub_101ac8b0(); int a = vfunc0(); return s->v3() == a ? true : false; }
// END FUNCTION

// FUNCTION: 0x101aad40 size=0xa
#include "vgui2__Panel.h"
int vgui2::Panel::vfunc29(int a0)
{
    *(int *)((char *)this + 0x34) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101aad50 size=0x4
#include "vgui2__Panel.h"
int vgui2::Panel::vfunc30()
{
    return *(int *)((char *)this + 0x34);
}
// END FUNCTION

// FUNCTION: 0x101aad60 size=0x3
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc13(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101aad70 size=0x1
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc79()
{
}
// END FUNCTION

// FUNCTION: 0x101aad80 size=0xda
#include "vgui2__Panel.h"

extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)

int sub_101ac8f0();
void *sub_101d12a1(unsigned int);
void sub_101d1296(void *);
__declspec(noreturn) void sub_101d309f(int);

struct IPanelV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14();
	virtual int v15(int id);
};

struct CIntList
{
	int m_nCount;
	int m_nCapacity;
	int *m_pData;
};

void vgui2::Panel::vfunc41(int arg)
{
	Panel *pTarget = (Panel *)arg;
	int value = ((IPanelV *)sub_101ac8f0())->v15(pTarget->vfunc0());

	CIntList &list = *(CIntList *)((char *)this + 0x38);

	int i = 0;
	if ( list.m_nCount > 0 )
	{
		int size = list.m_nCount;
		int *p = list.m_pData;
		do
		{
			if ( *p == value )
				goto found;
			i++;
			p++;
		}
		while ( i < size );
	}
	goto grow;

found:
	if ( i >= 0 )
		return;

grow:
	int newSize = *(volatile int *)&list.m_nCount + 1;
	int cap = list.m_nCapacity;
	if ( newSize > cap )
	{
		if ( cap == 0 )
			cap = 1;
		while ( cap < newSize )
			cap += cap;

		int nBytes = cap * 4;
		int *pNew = (int *)sub_101d12a1(nBytes);
		if ( !pNew )
			sub_101d309f(0);

		memset(pNew, 0, nBytes);
		list.m_nCapacity = cap;

		for ( int j = 0; j < list.m_nCount; j++ )
			pNew[j] = list.m_pData[j];

		sub_101d1296(list.m_pData);
		list.m_pData = pNew;
	}

	list.m_pData[list.m_nCount] = value;
	list.m_nCount = list.m_nCount + 1;
}
// END FUNCTION

// FUNCTION: 0x101aae60 size=0x65
struct P42Target
{
    virtual int vfunc0();
};

struct Surf42
{
    virtual void v0() = 0;  virtual void v1() = 0;  virtual void v2() = 0;  virtual void v3() = 0;
    virtual void v4() = 0;  virtual void v5() = 0;  virtual void v6() = 0;  virtual void v7() = 0;
    virtual void v8() = 0;  virtual void v9() = 0;  virtual void v10() = 0; virtual void v11() = 0;
    virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0;
    virtual int vfunc15(int) = 0;
};
Surf42 *sub_101ac8f0();

struct PanelV42
{
    char m_pad[0x38];
    int m_nCount;
    int m_nAlloc;
    int *m_pArray;

    int Find(int id)
    {
        for (int i = 0; i < m_nCount; i++)
            if (m_pArray[i] == id)
                return i;
        return -1;
    }
    bool IsValidIndex(int i) { return i >= 0 && i < m_nCount; }
    void sub_101aae60(P42Target *pTarget);
};

// TARGET: PanelV42::sub_101aae60
void PanelV42::sub_101aae60(P42Target *pTarget)
{
    int id = sub_101ac8f0()->vfunc15(pTarget->vfunc0());
    int i = Find(id);
    if (IsValidIndex(i))
    {
        for (int j = i; j < m_nCount - 1; j++)
            m_pArray[j] = m_pArray[j + 1];
        m_nCount--;
    }
}
// END FUNCTION

// FUNCTION: 0x101ab040 size=0x4
#include "vgui2__Panel.h"
int vgui2::Panel::vfunc61()
{
    return *(int *)((char *)this + 0x14);
}
// END FUNCTION

// FUNCTION: 0x101ab050 size=0xa
#include "vgui2__Panel.h"
bool vgui2::Panel::vfunc62(char a0)
{
    *(char *)((char *)this + 0x28) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101ab060 size=0xa
#include "vgui2__Panel.h"
bool vgui2::Panel::vfunc63(char a0)
{
    *(char *)((char *)this + 0x29) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101ab070 size=0xa
#include "vgui2__Panel.h"
bool vgui2::Panel::vfunc64(char a0)
{
    *(char *)((char *)this + 0x2a) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101ab080 size=0xa
#include "vgui2__Panel.h"
bool vgui2::Panel::vfunc104(char a0)
{
    *(char *)((char *)this + 0x54) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101ab090 size=0x34
#include "vgui2__Panel.h"
struct IPanelView {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11();
	virtual int Slot12(int vpanel, int a, int b, int c, int d);
};
IPanelView *sub_101ac900();
// TARGET: vgui2::Panel::vfunc8
int vgui2::Panel::vfunc8(int a, int b, int c, int d)
{
	return sub_101ac900()->Slot12(vfunc0(), a, b, c, d);
}
// END FUNCTION

// FUNCTION: 0x101ab210 size=0x4
#include "vgui2__Panel.h"
bool vgui2::Panel::vfunc47()
{
    return *(bool *)((char *)this + 0x19);
}
// END FUNCTION

// FUNCTION: 0x101ab260 size=0xf
#include "vgui2__Panel.h"
namespace lifted {
struct V { virtual void u0(); virtual bool f1(); };
}
bool vgui2::Panel::vfunc67()
{
    if ((*(int *)((char *)this + 0x1c)) == 0) {
        return 0;
    }
    return ((lifted::V *)(*(int *)((char *)this + 0x1c)))->f1();
}
// END FUNCTION

// FUNCTION: 0x101ab290 size=0xa
#include "vgui2__Panel.h"
int vgui2::Panel::vfunc50(int a0)
{
    *(int *)((char *)this + 0x24) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101ab2a0 size=0xa
#include "vgui2__Panel.h"
int vgui2::Panel::vfunc51(int a0)
{
    *(int *)((char *)this + 0x20) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101ab2b0 size=0xc
#include "vgui2__Panel.h"
int vgui2::Panel::vfunc52(int a0)
{
    *(int *)((char *)a0) = *(int *)((char *)this + 0x24);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101ab2c0 size=0xc
#include "vgui2__Panel.h"
int vgui2::Panel::vfunc53(int a0)
{
    *(int *)((char *)a0) = *(int *)((char *)this + 0x20);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101ab2f0 size=0x1
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc101()
{
}
// END FUNCTION

// FUNCTION: 0x101ab300 size=0x71
#include "vgui2__Panel.h"

void vgui2::Panel::sub_101ab300(bool arg1, bool arg2)
{
	((char *)this)[0x30] = 1;
	if ( arg1 )
	{
		if ( arg2 )
			((char *)this)[0x31] = 1;
		sub_101ab2d0();
	}
	if ( arg2 )
	{
		((char *)this)[0x31] = 1;
		vfunc6();
		for ( int i = 0; i < vfunc36(); i++ )
			vfunc37(i)->vfunc57(0, 1);
	}
}
// END FUNCTION

// FUNCTION: 0x101ab380 size=0xe
#include "vgui2__Panel.h"
// TARGET: vgui2::Panel::vfunc69
bool vgui2::Panel::vfunc69() { if (vfunc55()) return false; return true; }
// END FUNCTION

// FUNCTION: 0x101ab390 size=0x32
#include "vgui2__Panel.h"
struct SurfView {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
 virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
 virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
 virtual void s24(); virtual void s25(); virtual void s26();
 virtual void GetScreenSize(int &wide, int &tall);
};
SurfView *sub_101ac8b0();
// TARGET: vgui2::Panel::vfunc70
void vgui2::Panel::vfunc70()
{
    int wide, tall;
    sub_101ac8b0()->GetScreenSize(wide, tall);
    vfunc25(wide, tall);
}
// END FUNCTION

// FUNCTION: 0x101ab3d0 size=0x3
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc78(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101ab3e0 size=0x1
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc80()
{
}
// END FUNCTION

// FUNCTION: 0x101ab3f0 size=0x1
#include "vgui2__Panel.h"
void vgui2::Panel::vfunc81()
{
}
// END FUNCTION

// FUNCTION: 0x101ab400 size=0x48
#include "vgui2__Panel.h"
namespace lifted {
int sub_101ac8f0();
struct V { virtual int f0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual bool f8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual int f17(int); virtual void u18(); virtual void u19(); virtual int f20(int); };
}
void vgui2::Panel::vfunc71()
{
    if ((*(char *)((char *)this + 0x10)) == 0) {
        *(char *)((char *)this + 0x10) = 1;
        *(char *)((char *)this + 0x32) = 0;
        bool t0 = ((lifted::V *)(lifted::sub_101ac8f0()))->f8();
        if (t0 != 0) {
            int t1 = lifted::sub_101ac8f0();
            ((lifted::V *)t1)->f17(((lifted::V *)this)->f0()); return;
        }
        ((lifted::V *)this)->f20(1);
    }
}
// END FUNCTION

// FUNCTION: 0x101ab490 size=0x49
#include "vgui2__Panel.h"
struct KVView {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual int *v6(int *, const char *);
};
// TARGET: ?vfunc74@Panel@vgui2@@UAEHH@Z
int vgui2::Panel::vfunc74(int a)
{
	KVView *kv = (KVView *)a;
	int c;
	vfunc51(*kv->v6(&c, "FgColor"));
	return vfunc50(*kv->v6(&c, "BgColor"));
}
// END FUNCTION

// FUNCTION: 0x101ab860 size=0x6
#include "vgui2__Panel.h"
namespace lifted {
extern int g_102d7be0;
}
int vgui2::Panel::vfunc77()
{
    return lifted::g_102d7be0;
}
// END FUNCTION

// FUNCTION: 0x101ab880 size=0xd
#include "vgui2__Panel.h"
namespace lifted {
struct C101be7d0 { int sub_101be7d0(); };
}
void vgui2::Panel::vfunc2()
{
    if ((*(int *)((char *)this + 0x50)) != 0) {
        ((lifted::C101be7d0 *)(*(int *)((char *)this + 0x50)))->sub_101be7d0(); return;
    }
}
// END FUNCTION

// FUNCTION: 0x101abf60 size=0x6
#include "vgui2__Panel.h"
namespace lifted {
extern char g_102d8128;
}
int vgui2::Panel::vfunc102()
{
    return (int)&lifted::g_102d8128;
}
// END FUNCTION

// FUNCTION: 0x101abf70 size=0x4cc
#include "vgui2__Panel.h"
#pragma pointers_to_members(full_generality, virtual_inheritance)
struct MMItem {
	int p0; int id; int p8; int pc;
	void (vgui2::Panel::*func)();
	int numParams; int t1; const char *n1; int t2; const char *n2; int nameSymbol; int pad[2];
};
struct PMap { MMItem *items; int numFields; int p8; PMap *base; int processed; };
struct KVV {
	virtual const char *GetName(); virtual int GetNameSymbol();
	virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
	virtual int GetInt(const char *, int); virtual float GetFloat(const char *, float);
	virtual const char *GetString(const char *, const char *); virtual void *GetPtr(const char *, void *);
};
struct IVG { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void DPrintf(const char *, ...); };
IVG *sub_101ac8f0();
typedef void (vgui2::Panel::*F_Void)();
typedef void (vgui2::Panel::*F_II)(int, int);
typedef void (vgui2::Panel::*F_PI)(void *, int);
typedef void (vgui2::Panel::*F_SI)(const char *, int);
typedef void (vgui2::Panel::*F_SS)(const char *, const char *);
typedef void (vgui2::Panel::*F_IS)(int, const char *);
typedef void (vgui2::Panel::*F_PS)(void *, const char *);
typedef void (vgui2::Panel::*F_B)(bool);
typedef void (vgui2::Panel::*F_S)(const char *);
typedef void (vgui2::Panel::*F_I)(int);
typedef void (vgui2::Panel::*F_F)(float);
typedef void (vgui2::Panel::*F_P)(void *);
// TARGET: vgui2::Panel::vfunc16
void vgui2::Panel::vfunc16(void *pp, int from)
{
	KVV *params = (KVV *)pp;
	int id = params->GetInt("_id", 0);
	int iMessageName = params->GetNameSymbol();
	PMap *panelMap = (PMap *)vfunc102();
	if (!panelMap->processed)
		sub_101ac570(panelMap);
	for (; panelMap != 0; panelMap = panelMap->base)
	{
		MMItem *m = panelMap->items;
		for (int i = 0; i < panelMap->numFields; i++)
		{
			if ((id && m[i].id == id) || (iMessageName == m[i].nameSymbol))
			{
				switch (m[i].numParams)
				{
				case 2:
					if (m[i].t1 == 2 && m[i].t2 == 2)
						(this->*((F_II)m[i].func))(params->GetInt(m[i].n1, 0), params->GetInt(m[i].n2, 0));
					else if (m[i].t1 == 4 && m[i].t2 == 2)
						(this->*((F_PI)m[i].func))(params->GetPtr(m[i].n1, 0), params->GetInt(m[i].n2, 0));
					else if (m[i].t1 == 1 && m[i].t2 == 2)
						(this->*((F_SI)m[i].func))(params->GetString(m[i].n1, ""), params->GetInt(m[i].n2, 0));
					else if (m[i].t1 == 1 && m[i].t2 == 1)
						(this->*((F_SS)m[i].func))(params->GetString(m[i].n1, ""), params->GetString(m[i].n2, ""));
					else if (m[i].t1 == 2 && m[i].t2 == 1)
						(this->*((F_IS)m[i].func))(params->GetInt(m[i].n1, 0), params->GetString(m[i].n2, ""));
					else if (m[i].t1 == 4 && m[i].t2 == 1)
						(this->*((F_PS)m[i].func))(params->GetPtr(m[i].n1, 0), params->GetString(m[i].n2, ""));
					else
						sub_101ac8f0()->DPrintf("Message '%s', sent to '%s', has invalid parameter types\n", params->GetName(), vfunc18());
					break;
				case 1:
					switch (m[i].t1)
					{
					case 5:
						(this->*((F_B)m[i].func))(params->GetInt(m[i].n1, 0) != 0);
						break;
					case 1:
						(this->*((F_S)m[i].func))(params->GetString(m[i].n1, ""));
						break;
					case 2:
						(this->*((F_I)m[i].func))(params->GetInt(m[i].n1, 0));
						break;
					case 3:
						(this->*((F_F)m[i].func))(params->GetFloat(m[i].n1, 0));
						break;
					case 4:
						(this->*((F_P)m[i].func))(params->GetPtr(m[i].n1, 0));
						break;
					case 6:
						if (m[i].n1)
							(this->*((F_P)m[i].func))(params->GetPtr(m[i].n1, 0));
						else
							(this->*((F_P)m[i].func))(params);
						break;
					default:
						sub_101ac8f0()->DPrintf("Message '%s', sent to '%s', has an invalid parameter type\n", params->GetName(), vfunc18());
						break;
					}
					break;
				default:
					(this->*(m[i].func))();
					break;
				}
				break;
			}
		}
	}
}
// END FUNCTION

// FUNCTION: 0x101ac440 size=0x27
#include "vgui2__Panel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual bool f14(int); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual int f38(int, int); };
}
bool vgui2::Panel::vfunc44(int a0, int a1)
{
    int t0 = ((lifted::V *)this)->f38(a0, 0);
    if (t0 != 0) {
        return ((lifted::V *)t0)->f14(a1);
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x101ac640 size=0xc
#include "vgui2__Panel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual int f20(int); };
}
void vgui2::Panel::vfunc82()
{
    if (((int)this) != 0) {
        ((lifted::V *)this)->f20(1);
    }
}
// END FUNCTION
