// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101b87f0 size=0x3
#include "vgui2__MenuButton.h"
void vgui2::MenuButton::vfunc166(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101b8800 size=0x3
#include "vgui2__MenuButton.h"
void vgui2::MenuButton::vfunc167(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101c95b0 size=0x1e
#include "vgui2__MenuButton.h"

// VC6 writes vgui2::MenuButton's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::MenuButton *pcd_emit_101c95b0(const vgui2::MenuButton &other) { return new vgui2::MenuButton(other); }

// TARGET: ??_GMenuButton@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101c95e0 size=0x3a
#include "vgui2__MenuButton.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual int f33(int); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual int f41(int); };
}
void vgui2::MenuButton::vfunc168(int a0)
{
    *(int *)((char *)this + 0xf0) = a0;
    if (a0 != 0) {
        ((lifted::V *)a0)->f21(0);
        ((lifted::V *)(*(int *)((char *)this + 0xf0)))->f41((int)this);
        ((lifted::V *)(*(int *)((char *)this + 0xf0)))->f33((int)this);
    }
}
// END FUNCTION

// FUNCTION: 0x101c9620 size=0x3
#include "vgui2__MenuButton.h"
void vgui2::MenuButton::vfunc163(int a0, int a1, int a2, int a3)
{
}
// END FUNCTION

// FUNCTION: 0x101c9630 size=0xd
#include "vgui2__MenuButton.h"
int vgui2::MenuButton::vfunc172(int a0)
{
    *(int *)((char *)this + 0xf4) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101c9640 size=0x44
#include "vgui2__MenuButton.h"
namespace lifted {
struct C101b4250 { int sub_101b4250(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual bool f70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual int f147(); virtual void u148(); virtual bool f149(int); };
}
void vgui2::MenuButton::vfunc87(int a0)
{
    if ((*(int *)((char *)this + 0xf0)) != 0) {
        bool t0 = ((lifted::V *)this)->f70();
        if (t0 != 0) {
            bool t1 = ((lifted::V *)this)->f149(a0);
            if (t1 != 0) {
                ((lifted::V *)this)->f147();
                ((lifted::C101b4250 *)this)->sub_101b4250(a0);
            }
        }
    }
}
// END FUNCTION

// FUNCTION: 0x101c9690 size=0x37
#include "vgui2__MenuButton.h"
namespace lifted {
struct C101b37a0 { int sub_101b37a0(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual int f5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual int f167(int); };
}
void vgui2::MenuButton::vfunc169()
{
    if ((*(int *)((char *)this + 0xf0)) != 0) {
        ((lifted::V *)(*(int *)((char *)this + 0xf0)))->f21(0);
        ((lifted::C101b37a0 *)this)->sub_101b37a0(0);
        ((lifted::V *)this)->f5();
        ((lifted::V *)this)->f167(*(int *)((char *)this + 0xf0));
    }
}
// END FUNCTION

// FUNCTION: 0x101c96d0 size=0x13
#include "vgui2__MenuButton.h"
namespace lifted {
struct C101b3b20 { int sub_101b3b20(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual void u168(); virtual int f169(); };
}
void vgui2::MenuButton::vfunc81()
{
    ((lifted::V *)this)->f169();
    ((lifted::C101b3b20 *)this)->sub_101b3b20();
}
// END FUNCTION

// FUNCTION: 0x101c96f0 size=0x41
#include "vgui2__MenuButton.h"
struct KV101b5670 { KV101b5670 *sub_101b5670(const char *); };
void *sub_101b6840(int);
// TARGET: ?vfunc170@MenuButton@vgui2@@UAEHXZ
int vgui2::MenuButton::vfunc170()
{
	vfunc169();
	KV101b5670 *kv = (KV101b5670 *)sub_101b6840(0x1c);
	return vfunc43(kv ? kv->sub_101b5670("MenuClose") : 0);
}
// END FUNCTION

// FUNCTION: 0x101c9740 size=0xd
#include "vgui2__MenuButton.h"
int vgui2::MenuButton::vfunc171(int a0)
{
    *(int *)((char *)this + 0xf8) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101c9750 size=0x21e
#include "vgui2__MenuButton.h"

struct SurfV_101c9750
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
	virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
	virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
	virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71();
	virtual void GetCursorPos(int *x, int *y);
	virtual void v73(); virtual void v74();
	virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82();
	virtual void GetWorkspaceBounds(int *x, int *y, int *wide, int *tall);
};
SurfV_101c9750 *sub_101ac8d0();

struct MenuV_101c9750
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void SetVisible(bool);
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
	virtual void MoveToFront(bool);
	virtual bool IsVisible();
	virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
	virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
	virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
	virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
	virtual bool IsEnabled();
	virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52();
	virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57();
	virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62();
	virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
	virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72();
	virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
	virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82();
	virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
	virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92();
	virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97();
	virtual void v98(); virtual void v99(); virtual void v100();
	virtual void PerformLayout();
	void sub_101a9920(int *, int *);
	void sub_101a9890(int, int);
	void sub_101a9980(int *, int *, int *, int *);
	void sub_101a9950(int, int, int, int);
};

struct PanelV_101c9750
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25();
	virtual void LocalToScreen(int *x, int *y);
};

#define MB_MENU (*(MenuV_101c9750 **)((char *)this + 0xf0))
#define MB_DIR (*(int *)((char *)this + 0xf4))
#define MB_OFFSET (*(int *)((char *)this + 0xf8))

#pragma warning(disable: 4716)
int vgui2::MenuButton::vfunc147()
{
	if (MB_MENU->IsVisible())
	{
		vfunc169();
	}
	else if (MB_MENU->IsEnabled())
	{
	MB_MENU->PerformLayout();

	int x, y, wide, tall;
	sub_101a9920(&wide, &tall);
	if (MB_DIR == 4)
	{
		sub_101ac8d0()->GetCursorPos(&x, &y);
	}
	else if (MB_DIR == 5)
	{
		x = 0;
		y = tall;
		((PanelV_101c9750 *)vfunc31())->LocalToScreen(&x, &y);
		x--;
		y += MB_OFFSET;
	}
	else
	{
		x = 0;
		y = tall;
		((PanelV_101c9750 *)this)->LocalToScreen(&x, &y);
	}
	int mwide, mtall;
	MB_MENU->sub_101a9920(&mwide, &mtall);
	int bwide, btall;
	sub_101a9920(&bwide, &btall);
	switch (MB_DIR)
	{
	case 2:
		y = y - (mtall + btall);
		MB_MENU->sub_101a9890(x, y - 1);
		break;
	case 3:
		MB_MENU->sub_101a9890(x, y + 1);
		break;
	default:
		MB_MENU->sub_101a9890(x + 1, y + 1);
		break;
	}
	int mx, my, mw, mh;
	MB_MENU->sub_101a9980(&mx, &my, &mw, &mh);
	int wx, wy, ww, wh;
	sub_101ac8d0()->GetWorkspaceBounds(&wx, &wy, &ww, &wh);
	if (mx < wx)
		mx = wx;
	if (mx + mw > wx + ww)
		mx = wx - mw + ww;
	MB_MENU->sub_101a9950(mx, my, mw, mh);
	vfunc49();
	vfunc166((int)MB_MENU);
	Button::vfunc141(true);
	MB_MENU->MoveToFront(true);
	MB_MENU->SetVisible(false);
	}
}
// END FUNCTION

// FUNCTION: 0x101c9a30 size=0x66
#include "vgui2__MenuButton.h"

extern void *sub_101b6840(unsigned int size);

struct KV_101c9a30 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16();
	virtual void v17(const char *key, int value);
	KV_101c9a30 *sub_101b5670(const char *name);
};

struct IVGui_101c9a30 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void PostMessage(int target, void *params, int from, float delaySeconds);
};
extern IVGui_101c9a30 *sub_101ac8f0();

struct PanelLike_101c9a30 {
	virtual int GetVPanel();
};

struct ButtonV_101c9a30 {
	void sub_101b4210();
};

// TARGET: vgui2::MenuButton::vfunc85
void vgui2::MenuButton::vfunc85()
{
	((ButtonV_101c9a30 *)this)->sub_101b4210();

	KV_101c9a30 *msg = (KV_101c9a30 *)sub_101b6840(0x1c);
	if (msg)
		msg = msg->sub_101b5670("CursorEnteredMenuButton");
	else
		msg = 0;

	msg->v17("VPanel", vfunc0());
	PanelLike_101c9a30 *parent = (PanelLike_101c9a30 *)vfunc31();
	sub_101ac8f0()->PostMessage(parent->GetVPanel(), msg, 0, 0.0f);
}
// END FUNCTION

// FUNCTION: 0x101c9af0 size=0x6
#include "vgui2__MenuButton.h"
namespace lifted {
extern char g_102dadc8;
}
int vgui2::MenuButton::vfunc102()
{
    return (int)&lifted::g_102dadc8;
}
// END FUNCTION
