// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101c81f0 size=0x6b
#include "vgui2__PageTab.h"
struct SchemeView {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual int *GetColor(int *out, const char *name, int def);
};
int vgui2::PageTab::vfunc74(int a)
{
	Button::vfunc74(a);
	SchemeView *s = (SchemeView *)a;
	int c, d;
	*(int *)((char *)this + 0xf1) = *s->GetColor(&d, "BrightControlText", *(int *)vfunc53((int)&c));
	int *p = s->GetColor(&d, "FgColorDim", *(int *)vfunc53((int)&c));
	*(int *)((char *)this + 0xf5) = *p;
	return (int)p;
}
// END FUNCTION

// FUNCTION: 0x101c8260 size=0x44
#include "vgui2__PageTab.h"
namespace lifted {
extern char g_102d3884;
extern char g_102d3890;
struct C101aa220 { int sub_101aa220(); };
struct C101ac8c0 { int sub_101ac8c0(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual int f3(int); virtual int f4(int); };
}
int vgui2::PageTab::vfunc164(int a0, int a1, int a2, int a3)
{
    int t0 = ((lifted::C101ac8c0 *)this)->sub_101ac8c0();
    int t1 = ((lifted::V *)t0)->f4(((lifted::C101aa220 *)this)->sub_101aa220());
    if ((*(char *)((char *)this + 0xf0)) != 0) {
        return ((lifted::V *)t1)->f3((int)&lifted::g_102d3890);
    }
    return ((lifted::V *)t1)->f3((int)&lifted::g_102d3884);
}
// END FUNCTION

// FUNCTION: 0x101c82b0 size=0x24
#include "vgui2__PageTab.h"
int vgui2::PageTab::vfunc156(int a0)
{
    if ((*(char *)((char *)this + 0xf0)) != 0) {
        *(int *)((char *)a0) = *(int *)((char *)this + 0xf1);
        return a0;
    }
    *(int *)((char *)a0) = *(int *)((char *)this + 0xf5);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101c82e0 size=0x24
#include "vgui2__PageTab.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int vgui2::PageTab::vfunc166(char a0)
{
    *(char *)((char *)this + 0xf0) = a0;
    ((lifted::V *)this)->f57(0, 0);
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101c8310 size=0xbd
#include "vgui2__PageTab.h"
#include "vgui2__KeyValues.h"
struct IInput101c8310 { virtual void v0(); virtual void v1(int); };
IInput101c8310 *sub_101ac8b0();

void vgui2::PageTab::vfunc87(int code)
{
    if (code == 1)
    {
        vfunc43(new vgui2::KeyValues("OpenContextMenu", "row", -1));
        return;
    }
    if (vfunc47() && vfunc149(code) && vfunc146())
    {
        vfunc15(0);
        vfunc150();
        vfunc143(1);
        vfunc6();
        IInput101c8310 *p = sub_101ac8b0();
        p->v1(vfunc0());
    }
}
// END FUNCTION

// FUNCTION: 0x101c83d0 size=0x34
#include "vgui2__PageTab.h"
namespace lifted {
int sub_101ac8b0();
struct V { virtual void u0(); virtual int f1(int); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual int f143(int); virtual void u144(); virtual void u145(); virtual bool f146(); };
}
void vgui2::PageTab::vfunc89(int a0)
{
    bool t0 = ((lifted::V *)this)->f146();
    if (t0 != 0) {
        ((lifted::V *)(lifted::sub_101ac8b0()))->f1(0);
    }
    ((lifted::V *)this)->f143(0);
    ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101c9530 size=0x24
#include "vgui2__PageTab.h"
vgui2::PageTab *pcd_emit_101c9530(const vgui2::PageTab &o) { return new vgui2::PageTab(o); }
// TARGET: ??_GPageTab@vgui2@@UAEPAXI@Z
// END FUNCTION
