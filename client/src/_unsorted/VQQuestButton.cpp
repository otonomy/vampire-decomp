// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101880d0 size=0x1e
#include "VQQuestButton.h"

// VC6 writes VQQuestButton's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
VQQuestButton *pcd_emit_101880d0(const VQQuestButton &other) { return new VQQuestButton(other); }

// TARGET: ??_GVQQuestButton@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10188100 size=0x77
#include "VQQuestButton.h"

struct QBtnScheme
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual int *vfunc5(int *pOut, const char *pszName, int nDefault);
};
struct QBtnColorSlots
{
	virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
	virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
	virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
	virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
	virtual void s50(); virtual void s51(); virtual void s52();
	virtual int *vfunc53(int *pOut);
};
#pragma pack(push, 1)
struct QBtnView
{
	char m_pad[0xf1];
	int m_nBright;
	int m_nDim;
};
#pragma pack(pop)

// TARGET: VQQuestButton::vfunc74
int VQQuestButton::vfunc74(int pScheme)
{
	QBtnScheme *s = (QBtnScheme *)pScheme;
	QBtnView *v = (QBtnView *)this;
	QBtnColorSlots *c = (QBtnColorSlots *)this;
	int clrA;
	int clrB;
	int *p;
	Button::vfunc74(pScheme);
	vfunc152(0);
	v->m_nBright = *s->vfunc5(&clrB, "BrightControlText", *c->vfunc53(&clrA));
	p = s->vfunc5(&clrB, "FgColorDim", *c->vfunc53(&clrA));
	v->m_nDim = *p;
	return (int)p;
}
// END FUNCTION

// FUNCTION: 0x10188180 size=0x44
#include "VQQuestButton.h"
namespace lifted {
extern char g_102d3884;
extern char g_102d3890;
struct C101aa220 { int sub_101aa220(); };
struct C101ac8c0 { int sub_101ac8c0(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual int f3(int); virtual int f4(int); };
}
int VQQuestButton::vfunc164(int a0, int a1, int a2, int a3)
{
    int t0 = ((lifted::C101ac8c0 *)this)->sub_101ac8c0();
    int t1 = ((lifted::V *)t0)->f4(((lifted::C101aa220 *)this)->sub_101aa220());
    if ((*(char *)((char *)this + 0xf0)) != 0) {
        return ((lifted::V *)t1)->f3((int)&lifted::g_102d3890);
    }
    return ((lifted::V *)t1)->f3((int)&lifted::g_102d3884);
}
// END FUNCTION

// FUNCTION: 0x101881d0 size=0x24
#include "VQQuestButton.h"
int VQQuestButton::vfunc156(int a0)
{
    if ((*(char *)((char *)this + 0xf0)) != 0) {
        *(int *)((char *)a0) = *(int *)((char *)this + 0xf1);
        return a0;
    }
    *(int *)((char *)a0) = *(int *)((char *)this + 0xf5);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x10188200 size=0x24
#include "VQQuestButton.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int VQQuestButton::vfunc166(char a0)
{
    *(char *)((char *)this + 0xf0) = a0;
    ((lifted::V *)this)->f57(0, 0);
    return ((lifted::V *)this)->f6();
}
// END FUNCTION
