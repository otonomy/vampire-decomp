// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101c5d30 size=0x1e
#include "vgui2__RadioButton.h"

// VC6 writes vgui2::RadioButton's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::RadioButton *pcd_emit_101c5d30(const vgui2::RadioButton &other) { return new vgui2::RadioButton(other); }

// TARGET: ??_GRadioButton@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101c5d50 size=0x22
#include "vgui2__RadioButton.h"
struct CheckObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual ~CheckObj(); };
vgui2::RadioButton::~RadioButton()
{
	CheckObj *p = *(CheckObj **)((char *)this + 0xf4);
	if (p)
		delete p;
}
// END FUNCTION

// FUNCTION: 0x101c5eb0 size=0x5
#include "vgui2__RadioButton.h"
int vgui2::RadioButton::vfunc164(int a0, int a1, int a2, int a3)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x101c5ec0 size=0x7
#include "vgui2__RadioButton.h"
int vgui2::RadioButton::vfunc166()
{
    return *(int *)((char *)this + 0x100);
}
// END FUNCTION

// FUNCTION: 0x101c5ed0 size=0xd
#include "vgui2__RadioButton.h"
int vgui2::RadioButton::vfunc167(int a0)
{
    *(int *)((char *)this + 0x100) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101c5ee0 size=0x7
#include "vgui2__RadioButton.h"
int vgui2::RadioButton::vfunc168()
{
    return *(int *)((char *)this + 0xf8);
}
// END FUNCTION

// FUNCTION: 0x101c5ef0 size=0x188
#include "vgui2__RadioButton.h"

extern void *sub_101b6840(unsigned int size);

struct IVGui_101c5ef0 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void PostMessage(int target, void *params, int from, float delaySeconds);
};
extern IVGui_101c5ef0 *sub_101ac8f0();

struct KV_101c5ef0 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void SetInt(const char *keyName, int value);
	virtual void v16();
	virtual void SetPtr(const char *keyName, void *value);
	virtual KV_101c5ef0 *MakeCopy();
	KV_101c5ef0 *sub_101b5670(const char *name);
};

struct PanelView_101c5ef0 {
	virtual int v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30();
	virtual PanelView_101c5ef0 *GetParent();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
	virtual int GetChildCount();
	virtual vgui2::Panel *GetChild(int index);
	virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
	virtual void PostActionSignal(KV_101c5ef0 *message);
	virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
	virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
	virtual void v54(); virtual void v55(); virtual void v56();
	virtual void InvalidateLayout(bool layoutNow, bool reloadScheme);
};

// TARGET: vgui2::RadioButton::vfunc143
void vgui2::RadioButton::vfunc143(char state)
{
	if (state == 1)
	{
		if (!vfunc47())
			return;

		int &oldTabPosition = *(int *)((char *)this + 0xf8);
		vfunc29(oldTabPosition);

		KV_101c5ef0 *msg = (KV_101c5ef0 *)sub_101b6840(0x1c);
		if (msg)
			msg = msg->sub_101b5670("RadioButtonChecked");
		else
			msg = 0;

		msg->SetPtr("panel", this);
		msg->SetInt("tabposition", oldTabPosition);

		PanelView_101c5ef0 *parent = ((PanelView_101c5ef0 *)this)->GetParent();
		if (parent)
		{
			for (int i = 0; i < parent->GetChildCount(); i++)
			{
				vgui2::RadioButton *child = dynamic_cast<vgui2::RadioButton *>(parent->GetChild(i));
				if (child && child->vfunc168() == oldTabPosition)
				{
					sub_101ac8f0()->PostMessage(child->vfunc0(), msg->MakeCopy(), vfunc0(), 0.0f);
				}
			}
		}

		vfunc15(0);
		((PanelView_101c5ef0 *)this)->PostActionSignal(msg);
	}
	else
	{
		if (vfunc30())
		{
			*(int *)((char *)this + 0xf8) = vfunc30();
		}
		vfunc29(0);
	}

	((PanelView_101c5ef0 *)this)->InvalidateLayout(false, false);
	vfunc6();
	Button::vfunc143(state);
}
// END FUNCTION

// FUNCTION: 0x101c6080 size=0x51
#include "vgui2__RadioButton.h"

struct RBView_101c6080
{
	char m_pad0[0xfc];
	int m_nColor;	// 0xfc
};

// TARGET: vgui2::RadioButton::vfunc101
void vgui2::RadioButton::vfunc101()
{
	RBView_101c6080 *v = (RBView_101c6080 *)this;
	if ( vfunc144() )
		vfunc51(v->m_nColor);
	else
	{
		int clr;
		vfunc51(*(int *)vfunc156((int)&clr));
	}
	Button::vfunc101();
}
// END FUNCTION

// FUNCTION: 0x101c60e0 size=0x92
#include "vgui2__RadioButton.h"
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
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
	virtual int GetInt(const char *name, int def);
};
ISchemeMgrX *sub_101ac8c0();
struct RB { char pad[0xf4]; int m_nf4; int m_nf8; ColorX m_cfc; int m_n100; };
void vgui2::RadioButton::vfunc75(int a)
{
	Button::vfunc75(a);
	ISchemeX *pScheme = sub_101ac8c0()->GetIScheme(sub_101aa220());
	ColorX t1, t2;
	RB *p = (RB *)this;
	p->m_cfc = *pScheme->GetColor(&t2, "BrightControlText", *pScheme->GetColor2(&t1, "ControlText"));
	p->m_n100 = ((IKVX *)a)->GetInt("SubTabPosition", 0);
	p->m_nf8 = vfunc30();
	vfunc123(0, p->m_nf4, 0);
}
// END FUNCTION

// FUNCTION: 0x101c6180 size=0x26
#include "vgui2__RadioButton.h"
namespace lifted {
extern char g_102da864;
struct C101b4100 { int sub_101b4100(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual int f15(int, int); };
}
int vgui2::RadioButton::vfunc76(int a0)
{
    ((lifted::C101b4100 *)this)->sub_101b4100(a0);
    return ((lifted::V *)a0)->f15((int)&lifted::g_102da864, *(int *)((char *)this + 0x100));
}
// END FUNCTION

// FUNCTION: 0x101c61b0 size=0x23
#include "vgui2__RadioButton.h"
namespace lifted {
extern char g_102da874;
extern char g_1067bca0;
int sub_101b41b0();
int sub_101d3192(int, int, int, int);
}
int vgui2::RadioButton::vfunc77()
{
    lifted::sub_101d3192((int)&lifted::g_1067bca0, 0x400, (int)&lifted::g_102da874, lifted::sub_101b41b0());
    return (int)&lifted::g_1067bca0;
}
// END FUNCTION

// FUNCTION: 0x101c61e0 size=0x21
#include "vgui2__RadioButton.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual int f143(int); };
}
void vgui2::RadioButton::vfunc169(int a0, int a1)
{
    if (a1 == (*(int *)((char *)this + 0xf8))) {
        if (a0 != ((int)this)) {
            ((lifted::V *)this)->f143(0);
        }
    }
}
// END FUNCTION

// FUNCTION: 0x101c6220 size=0xcc
#include "vgui2__RadioButton.h"
void vgui2::RadioButton::sub_101c6220(int code)
{
	switch (code)
	{
	case 64:
	case 65:
		if (vfunc144())
			Panel::sub_101aa6f0(code);
		else
			vfunc143(1);
		return;
	case 90:
	case 91:
		{
			RadioButton *best = sub_101c62f0(1);
			if (best)
				best->vfunc143(1);
		}
		return;
	case 67:
		sub_101c62f0(1);
		return;
	case 88:
	case 89:
		{
			RadioButton *best = sub_101c62f0(-1);
			if (best)
				best->vfunc143(1);
		}
		return;
	}
	Panel::sub_101aa6f0(code);
}
// END FUNCTION

// FUNCTION: 0x101c6410 size=0x32
#include "vgui2__RadioButton.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual bool f47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual int f143(int); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual bool f149(int); };
}
void vgui2::RadioButton::vfunc87(int a0)
{
    bool t0 = ((lifted::V *)this)->f47();
    if (t0 != 0) {
        bool t1 = ((lifted::V *)this)->f149(a0);
        if (t1 != 0) {
            ((lifted::V *)this)->f143(1);
        }
    }
}
// END FUNCTION

// FUNCTION: 0x101c64f0 size=0x6
#include "vgui2__RadioButton.h"
namespace lifted {
extern char g_102da808;
}
int vgui2::RadioButton::vfunc102()
{
    return (int)&lifted::g_102da808;
}
// END FUNCTION
