// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100cb590 size=0x10
#include "CHLClient.h"
namespace lifted {
int sub_10192880(int);
}
int CHLClient::vfunc41(int a0)
{
    return lifted::sub_10192880(a0);
}
// END FUNCTION

// FUNCTION: 0x100cb990 size=0x88
#include "CHLClient.h"
struct SaveMgrV1 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(int a); };
struct ObjA1 { virtual void v0(); virtual void v1(); };
struct ObjB1 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); };
struct ObjC1 { virtual void v0(); virtual void v1(); virtual void v2(); };
extern SaveMgrV1 *g_102c37a0;
extern ObjA1 *g_102bc800;
extern ObjB1 *g_105f99d8;
extern ObjA1 *g_1027ba58;
extern ObjC1 *g_102d43d8;
extern int g_104a5820;
int sub_1012b820();
void sub_10106bb0();
void sub_1002c400();
void sub_1004a9c0();
void sub_100f4180();
void sub_10167000();
struct S100cc040 { void sub_100cc040(); };
struct CHud { void sub_100f07f0(); };
extern CHud g_104cfe38;
// TARGET: CHLClient::vfunc1
void CHLClient::vfunc1()
{
	g_102c37a0->v10(sub_1012b820());
	g_102bc800->v1();
	sub_10106bb0();
	g_105f99d8->v4();
	g_105f99d8->v2();
	g_1027ba58->v1();
	sub_1002c400();
	sub_1004a9c0();
	g_102d43d8->v2();
	((S100cc040 *)this)->sub_100cc040();
	sub_100f4180();
	g_104cfe38.sub_100f07f0();
	sub_10167000();
	g_104a5820 = 0;
}
// END FUNCTION

// FUNCTION: 0x100cba20 size=0x1a
#include "CHLClient.h"
namespace lifted {
extern int g_102bc800;
extern char g_104cfe38;
struct C100f0cf0 { int sub_100f0cf0(); };
struct V { virtual int f0(); };
}
int CHLClient::vfunc6()
{
    ((lifted::V *)lifted::g_102bc800)->f0();
    ((lifted::C100f0cf0 *)((int)&lifted::g_104cfe38))->sub_100f0cf0();
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100cba40 size=0x1d
#include "CHLClient.h"
namespace lifted {
extern int g_105f99d8;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(int, int); };
}
int CHLClient::vfunc7(int a0, int a1)
{
    ((lifted::V *)lifted::g_105f99d8)->f6(a0, a1);
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100cba60 size=0x1e
#include "CHLClient.h"
namespace lifted {
extern int g_1027ba58;
extern int g_105f99d8;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual int f8(float); virtual void u9(); virtual void u10(); virtual void u11(); virtual int f12(); };
}
int CHLClient::vfunc8(float a0)
{
    ((lifted::V *)lifted::g_1027ba58)->f12();
    return ((lifted::V *)lifted::g_105f99d8)->f8(a0);
}
// END FUNCTION

// FUNCTION: 0x100cba80 size=0x46
#include "engineclient.h"
#include "CHLClient.h"
#include "IClientMode.h"
struct IObj135100 { virtual void v0(); virtual void v1(); };
extern IClientMode *g_105f99d8;
IObj135100 *sub_10135100();
void sub_100f4240(float);
void sub_1002c430();
void CHLClient::vfunc9(int a)
{
    float f = engine->vfunc41(0);
    g_105f99d8->vfunc9(a);
    sub_10135100()->v1();
    sub_100f4240(f);
    sub_1002c430();
}
// END FUNCTION

// FUNCTION: 0x100cbad0 size=0xf
#include "CHLClient.h"
namespace lifted {
extern char g_104cfe38;
struct C100f0cf0 { int sub_100f0cf0(); };
int sub_10118dd0();
}
int CHLClient::vfunc10()
{
    ((lifted::C100f0cf0 *)((int)&lifted::g_104cfe38))->sub_100f0cf0();
    return lifted::sub_10118dd0();
}
// END FUNCTION

// FUNCTION: 0x100cbae0 size=0x6
#include "CHLClient.h"
namespace lifted {
extern int g_104a6d20;
}
int CHLClient::vfunc5()
{
    return lifted::g_104a6d20;
}
// END FUNCTION

// FUNCTION: 0x100cbaf0 size=0xf
#include "CHLClient.h"
int CHLClient::vfunc11(int a0, int a1, int a2, int a3)
{
    *(int *)((char *)a3) = 0;
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100cbb00 size=0x3
#include "CHLClient.h"
void CHLClient::vfunc12(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x100cbb10 size=0x19
#include "CHLClient.h"
namespace lifted {
extern int g_1027ba58;
extern int g_102ccd98;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(int); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual int f16(); };
}
int CHLClient::vfunc13()
{
    ((lifted::V *)lifted::g_1027ba58)->f16();
    return ((lifted::V *)lifted::g_102ccd98)->f4(1);
}
// END FUNCTION

// FUNCTION: 0x100cbb30 size=0x19
#include "CHLClient.h"
namespace lifted {
extern int g_1027ba58;
extern int g_102ccd98;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(int); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual int f17(); };
}
int CHLClient::vfunc14()
{
    ((lifted::V *)lifted::g_1027ba58)->f17();
    return ((lifted::V *)lifted::g_102ccd98)->f4(0);
}
// END FUNCTION

// FUNCTION: 0x100cbb50 size=0xb
#include "CHLClient.h"
namespace lifted {
extern int g_1027ba58;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual int f18(); };
}
int CHLClient::vfunc44()
{
    return ((lifted::V *)lifted::g_1027ba58)->f18();
}
// END FUNCTION

// FUNCTION: 0x100cbb60 size=0x13
#include "CHLClient.h"
namespace lifted {
extern int g_1027ba58;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual int f15(int, float); };
}
int CHLClient::vfunc15(int a0, float a1)
{
    return ((lifted::V *)lifted::g_1027ba58)->f15(a0, a1);
}
// END FUNCTION

// FUNCTION: 0x100cbb80 size=0xb
#include "CHLClient.h"
namespace lifted {
extern int g_1027ba58;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual int f14(); };
}
int CHLClient::vfunc16()
{
    return ((lifted::V *)lifted::g_1027ba58)->f14();
}
// END FUNCTION

// FUNCTION: 0x100cbb90 size=0xb
#include "CHLClient.h"
namespace lifted {
extern int g_1027ba58;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual int f19(); };
}
int CHLClient::vfunc17()
{
    return ((lifted::V *)lifted::g_1027ba58)->f19();
}
// END FUNCTION

// FUNCTION: 0x100cbba0 size=0xb
#include "CHLClient.h"
namespace lifted {
extern int g_1027ba58;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual int f11(); };
}
int CHLClient::vfunc18()
{
    return ((lifted::V *)lifted::g_1027ba58)->f11();
}
// END FUNCTION

// FUNCTION: 0x100cbbb0 size=0xb
#include "CHLClient.h"
namespace lifted {
extern int g_1027ba58;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual int f10(); };
}
int CHLClient::vfunc19()
{
    return ((lifted::V *)lifted::g_1027ba58)->f10();
}
// END FUNCTION

// FUNCTION: 0x100cbbc0 size=0x77
#include "CHLClient.h"

extern void *g_1027ba58;
extern void *g_104a5808;

void sub_1009db70(int);
void sub_100923c0(char, char);

struct EngV
{
	virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3();
	virtual void e4(); virtual void e5(); virtual void e6(); virtual void e7();
	virtual void e8(); virtual void e9(); virtual void e10(); virtual void e11();
	virtual void e12(); virtual void e13(); virtual void e14(); virtual void e15();
	virtual void vfunc16(int, int);
};

struct ModeV
{
	virtual void m0();
	virtual void m1();
	virtual void m2();
	virtual void vfunc3(int, int, int, int, int, int);
};

void CHLClient::vfunc20(int a0, int a1, int a2, int a3, int a4, int a5)
{
	((EngV *)g_104a5808)->vfunc16(0xac, 0);
	sub_1009db70(1);
	sub_100923c0(1, 0);
	((ModeV *)g_1027ba58)->vfunc3(a0, a1, a2, a3, a4, a5);
	sub_100923c0(0, 0);
	((EngV *)g_104a5808)->vfunc16(0xac, 1);
	sub_1009db70(0);
}
// END FUNCTION

// FUNCTION: 0x100cbc40 size=0x13
#include "CHLClient.h"
namespace lifted {
extern int g_1027ba58;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(int, int, int, float); };
}
int CHLClient::vfunc21(int a0, int a1, int a2, float a3)
{
    return ((lifted::V *)lifted::g_1027ba58)->f4(a0, a1, a2, a3);
}
// END FUNCTION

// FUNCTION: 0x100cbc60 size=0x76
#include "engineclient.h"
#include "Vector.h"

struct ViewV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void vfunc4(int);
};
extern ViewV *g_102d43d8;
extern float g_103ecd74;
extern Vector g_103ecd78;

int sub_10198d30();
void sub_1004a9e0();

// TARGET: sub_100cbc60
void __stdcall sub_100cbc60(int n)
{
	g_103ecd74 = 0.0f;
	g_102d43d8->vfunc4(n);
	if (g_103ecd74 > 0.0f)
	{
		Vector temp;
		g_103ecd78 = *engine->vfunc23(&temp, (void *)sub_10198d30(), 1);
		sub_1004a9e0();
	}
}
// END FUNCTION

// FUNCTION: 0x100cbce0 size=0x17
#include "CHLClient.h"
namespace lifted {
extern int g_102d5238;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(int, int, int); };
}
int CHLClient::vfunc25(int a0)
{
    return ((lifted::V *)lifted::g_102d5238)->f4(0, 0, a0);
}
// END FUNCTION

// FUNCTION: 0x100cbd00 size=0xbb
#include "CHLClient.h"
#include "CHud.h"
#include "ConVar.h"
#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();
struct O5808 { V4(a) V4(b) V4(c) V4(d) virtual void s16(int a, int b); };
struct O5238 { virtual void s0(); virtual void s1(); };
struct Occd98 { virtual void s0(); virtual void s1(); virtual void s2(int a); };
struct O9850 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); };
struct O43d8 { virtual void s0(); virtual void s1(); };
struct OEng
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
	virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
	virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
	virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
	virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
	virtual void v49(); virtual void v50(); virtual int v51();
};
extern bool g_104a579c;
extern O5808 *g_104a5808;
extern O5238 *g_102d5238;
extern Occd98 *g_102ccd98;
extern O9850 *g_102b9850;
extern O43d8 *g_102d43d8;
extern OEng *g_104a57d4;
extern ConVar g_104e1708;
extern void sub_1002c400();
extern void sub_100f4190(int);
extern void sub_100e2fa0();
extern void sub_10057650();
void CHLClient::vfunc2(int a)
{
	if (g_104a579c)
		return;
	g_104a579c = true;
	g_104a5808->s16(0xac, 0);
	g_102d5238->s1();
	g_102ccd98->s2(a);
	sub_1002c400();
	g_102b9850->s4();
	g_102d43d8->s1();
	sub_100f4190(a);
	sub_100e2fa0();
	g_104e1708.sub_100dfa90(g_104a57d4->v51() > 1);
	gHUD.sub_100f08d0();
	sub_10057650();
	g_104a57d4->v0();
	g_104a5808->s16(0xac, 1);
}
// END FUNCTION

// FUNCTION: 0x100cbdd0 size=0x77
#include "CClientEntityList.h"
#include "CHLClient.h"
#include "CClientEntityList.h"

extern char g_104a579c;
extern void *g_102ccd98;
extern void *g_1028073c;
extern void *g_102cdad8;
extern void *g_102cef78;
extern char g_104e0768;
extern char g_104cfe38;

struct IVt3
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};
struct IVt1
{
    virtual void v0();
    virtual void v1();
};
struct IVt8
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};
struct CPMBView
{
    void sub_101177a0();
};
struct V104cfe38
{
    void sub_100f0900();
};
struct S100cc040
{
    void sub_100cc040();
};

void sub_100576b0();
void sub_100f41f0();
void sub_100f4200();

// TARGET: CHLClient::vfunc4
void CHLClient::vfunc4()
{
    if (!g_104a579c)
        return;

    g_104a579c = 0;
    sub_100576b0();
    sub_100f41f0();
    ((IVt3 *)g_102ccd98)->v3();
    cl_entitylist->sub_100d0b40();
    sub_100f4200();
    ((IVt1 *)g_1028073c)->v1();
    ((CPMBView *)&g_104e0768)->sub_101177a0();
    ((V104cfe38 *)&g_104cfe38)->sub_100f0900();
    ((IVt3 *)g_102cdad8)->v3();
    ((IVt8 *)g_102cef78)->v8();
    ((S100cc040 *)this)->sub_100cc040();
}
// END FUNCTION

// FUNCTION: 0x100cbe50 size=0x1a
#include "CHLClient.h"
namespace lifted {
extern int g_102d43d8;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual int f5(int, int, int); };
}
int CHLClient::vfunc23(int a0, int a1)
{
    return ((lifted::V *)lifted::g_102d43d8)->f5(a0, a1, 0);
}
// END FUNCTION

// FUNCTION: 0x100cbe80 size=0xb
#include "CHLClient.h"
namespace lifted {
extern int g_102bc800;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual int f17(); };
}
int CHLClient::vfunc26()
{
    return ((lifted::V *)lifted::g_102bc800)->f17();
}
// END FUNCTION

// FUNCTION: 0x100cbe90 size=0x15
#include "CHLClient.h"
namespace lifted {
struct C10136da0 { int sub_10136da0(int); };
}
void CHLClient::vfunc27(int a0, int a1)
{
    if (a0 != 0) {
        ((lifted::C10136da0 *)a0)->sub_10136da0(a1);
    }
}
// END FUNCTION

// FUNCTION: 0x100cbeb0 size=0x10
#include "CHLClient.h"
namespace lifted {
struct C10136d90 { int sub_10136d90(); };
}
void CHLClient::vfunc28(int a0)
{
    if (a0 != 0) {
        ((lifted::C10136d90 *)a0)->sub_10136d90();
    }
}
// END FUNCTION

// FUNCTION: 0x100cbec0 size=0x6
#include "CHLClient.h"
int CHLClient::vfunc29()
{
    return 0x38;
}
// END FUNCTION

// FUNCTION: 0x100cbed0 size=0x3
#include "CHLClient.h"
void CHLClient::vfunc30(int a0, int a1)
{
}
// END FUNCTION

// FUNCTION: 0x100cbef0 size=0x67
#include "CHLClient.h"

extern int (*g_101e31b4)(const char *, const char *);

struct IAppSystemV
{
	virtual void *v0(const char *pName);
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(int a, void *b, int (*cb)(int, int, int, int));
};

extern IAppSystemV *g_104a5804;
extern void *g_102b848c;
extern void *g_102b8490;

int sub_100cbee0(int a, int b, int c, int d);

// TARGET: CHLClient::vfunc31
void CHLClient::vfunc31(const char *name)
{
	int (*cmp)(const char *, const char *) = g_101e31b4;
	if (cmp(name, "VguiScreen") == 0)
	{
		g_102b848c = g_104a5804->v0(name);
		return;
	}
	if (cmp(name, "Materials") == 0)
	{
		void *pMat = g_104a5804->v0(name);
		g_102b8490 = pMat;
		g_104a5804->v6(0, pMat, sub_100cbee0);
	}
}
// END FUNCTION

// FUNCTION: 0x100cc660 size=0x98
#include "engineclient.h"
#include "CHLClient.h"
#include "CHud.h"


struct VProfPanel
{
    void sub_1018dfc0();
};

extern int g_102b8498;

void sub_100cc570();
void sub_100cc620();
void sub_100cc650();
void sub_100cc630();
void sub_100cc640();
void sub_1009db80(int);
void sub_1009db70(int);

void CHLClient::vfunc32(int n)
{
    g_102b8498 = n;
    switch (n)
    {
    case 5:
        sub_100cc570();
        break;
    case 6:
        sub_100cc620();
        break;
    case 1:
        sub_1009db80(0);
        sub_1009db70(0);
        partition->vfunc16(0xac, 1);
        sub_100cc630();
        break;
    case 2:
        sub_100cc640();
        break;
    case 3:
        sub_100cc650();
        break;
    case 0:
        ((VProfPanel *)gHUD.FindElement("CVProfPanel"))->sub_1018dfc0();
        break;
    case 4:
        break;
    }
}
// END FUNCTION

// FUNCTION: 0x100cc700 size=0x10
#include "CHLClient.h"
namespace lifted {
int sub_1012b830(int);
}
int CHLClient::vfunc33(int a0)
{
    return lifted::sub_1012b830(a0);
}
// END FUNCTION

// FUNCTION: 0x100cc710 size=0x85
#include "CHLClient.h"
#include "CSave.h"
// TARGET: CHLClient::vfunc34
void CHLClient::vfunc34(void *pData, int a, int b, int c, int d, int e)
{
	CSave save(pData);
	save.vfunc3(a, b, c, d, e);
	save.m_nSections = 0;
	if (save.m_nGrow != -1)
	{
		if (save.m_pSections)
		{
			Plat_Free(save.m_pSections);
			save.m_pSections = 0;
		}
		save.m_nAlloc = 0;
	}
	save.m_pElements = save.m_pSections;
	if (save.m_nGrow != -1 && save.m_pElements)
		Plat_Free(save.m_pElements);
}
// END FUNCTION

// FUNCTION: 0x100cc7a0 size=0x85
#include "CHLClient.h"
#include "CRestore.h"
// TARGET: CHLClient::vfunc35
void CHLClient::vfunc35(void *pData, int a1, int a2, int a3, int a4, int a5)
{
	CRestore restore(pData);
	restore.sub_1012a840(a1, a2, a3, a4, a5);
}
// END FUNCTION

// FUNCTION: 0x100cc830 size=0xb
#include "CHLClient.h"
namespace lifted {
extern int g_102c37a0;
struct V { virtual void u0(); virtual int f1(); };
}
int CHLClient::vfunc36()
{
    return ((lifted::V *)lifted::g_102c37a0)->f1();
}
// END FUNCTION

// FUNCTION: 0x100cc840 size=0x73
#include "CHLClient.h"
#include "CSave.h"

struct SaveMgrView
{
    virtual void v0();
    virtual void v1();
    virtual void SaveGame(CSave *pSave);
};
extern SaveMgrView *g_102c37a0;

void CHLClient::vfunc37(void *pData)
{
    CSave save(pData);
    g_102c37a0->SaveGame(&save);
    ((CUtlVector<int> *)((char *)&save + 4))->~CUtlVector();
}
// END FUNCTION

// FUNCTION: 0x100cc8c0 size=0x7e
#include "CHLClient.h"
#include "CSave.h"
struct SaveMgrView38 {
	virtual void v0(); virtual void v1(); virtual void v2();
	virtual void SaveGame(CSave *);
	virtual void v4();
};
extern SaveMgrView38 *g_102c37a0;
extern "C" __declspec(dllimport) void Plat_Free(void *);
// TARGET: ?vfunc38@CHLClient@@UAEXPAX@Z
void CHLClient::vfunc38(void *pData)
{
	CSave save(pData);
	g_102c37a0->SaveGame(&save);
	g_102c37a0->v4();
	save.m_nSections = 0;
	if (save.m_nGrow != -1)
	{
		if (save.m_pSections)
		{
			Plat_Free(save.m_pSections);
			save.m_pSections = 0;
		}
		save.m_nAlloc = 0;
	}
	save.m_pElements = save.m_pSections;
	if (save.m_nGrow != -1 && save.m_pSections)
		Plat_Free(save.m_pSections);
}
// END FUNCTION

// FUNCTION: 0x100cc940 size=0x7e
#include "CHLClient.h"
#include "CRestore.h"
struct SaveMgrV {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void Prepare();
	virtual void Restore(CRestore *pRestore);
};
extern SaveMgrV *g_102c37a0;
void CHLClient::vfunc39(void *pData)
{
	CRestore restore(pData);
	g_102c37a0->Prepare();
	g_102c37a0->Restore(&restore);
}
// END FUNCTION

// FUNCTION: 0x100cc9c0 size=0x85
#include "CHLClient.h"
#include "CRestore.h"
struct SaveMgrV40
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
	virtual void v7(CRestore *pRestore, int a, int b);
	virtual void v8();
};
extern SaveMgrV40 *g_102c37a0;
// TARGET: CHLClient::vfunc40
void CHLClient::vfunc40(void *pData, int a)
{
	CRestore restore(pData);
	g_102c37a0->v7(&restore, a, 0);
	g_102c37a0->v8();
}
// END FUNCTION

// FUNCTION: 0x100cca70 size=0x27
#include "CHLClient.h"
struct VX { void sub_10056bc0(int, int, int); };
int sub_100561f0();
// TARGET: ?vfunc43@CHLClient@@UAEXHHH@Z
void CHLClient::vfunc43(int a, int b, int c) { if (sub_100561f0()) ((VX *)sub_100561f0())->sub_10056bc0(a, b, c); }
// END FUNCTION
