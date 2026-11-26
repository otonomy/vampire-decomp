// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1010f180 size=0x1
// TARGET: sub_1010f180
void sub_1010f180()
{
}
// END FUNCTION

// FUNCTION: 0x1010f190 size=0x1
#include "CMoveHelperClient.h"

// TARGET: CMoveHelperClient::vfunc12
void CMoveHelperClient::vfunc12()
{
}
// END FUNCTION

// FUNCTION: 0x1010f1a0 size=0x1e
#include "CMoveHelperClient.h"

// VC6 writes CMoveHelperClient's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CMoveHelperClient *pcd_emit_1010f1a0() { return new CMoveHelperClient; }

// TARGET: ??_GCMoveHelperClient@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1010f1c0 size=0x5f
#include "CMoveHelperClient.h"
#include "utlvector.h"

// TARGET: CMoveHelperClient::~CMoveHelperClient
extern int g_104df784;
extern char vt_10235714;

CMoveHelperClient::~CMoveHelperClient()
{
	g_104df784 = 0;
	((CUtlVector<int> *)((char *)this + 0xc))->~CUtlVector<int>();
	*(void **)this = &vt_10235714;
}
// END FUNCTION

// FUNCTION: 0x1010f260 size=0x8
#include "CMoveHelperClient.h"

// TARGET: CMoveHelperClient::vfunc1
void CMoveHelperClient::vfunc1()
{
	m_unk18 = 0;
}
// END FUNCTION

// FUNCTION: 0x1010f3e0 size=0x1
#include "CMoveHelperClient.h"

// TARGET: CMoveHelperClient::vfunc3
void CMoveHelperClient::vfunc3()
{
}
// END FUNCTION

// FUNCTION: 0x1010f3f0 size=0x8e
#include "engineclient.h"
#include "CMoveHelperClient.h"
#include "CWaterEnum.h"

int CMoveHelperClient::vfunc22(const Vector &pt)
{
	int ent = -1;
	if (engine->vfunc19(0, pt) & 0x4030)
		return 0;
	CWaterEnum we;
	we.m_vecPoint = pt;
	we.m_pEntIndex = &ent;
	we.m_nContents = 0;
	partition->vfunc15(4, pt, 0, &we);
	if (!(we.m_nContents & 0x4030))
		return -1;
	return ent;
}
// END FUNCTION

// FUNCTION: 0x1010f530 size=0x7b
#include "Vector.h"
#include "CWaterEnum.h"
#include "CMoveHelperClient.h"

#define V10(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7(); virtual void n##8(); virtual void n##9();

struct IEngine {
	V10(a)
	virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4();
	virtual void b5(); virtual void b6(); virtual void b7(); virtual void b8();
	virtual int vfunc19(int, Vector *);
};
extern IEngine *g_104a57d4;

struct IPartition {
	V10(a)
	virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4();
	virtual void vfunc15(int, Vector *, int, CWaterEnum *);
};
extern IPartition *g_104a5808;

// TARGET: CMoveHelperClient::vfunc16
int CMoveHelperClient::vfunc16(Vector *p)
{
	int result = g_104a57d4->vfunc19(0, p);
	if (result & 1)
		return result;
	CWaterEnum water;
	water.m_vecPoint = *p;
	water.m_nContents = 0;
	water.m_pEntIndex = 0;
	g_104a5808->vfunc15(4, p, 0, &water);
	return water.m_nContents == 0 ? result : 0;
}
// END FUNCTION

// FUNCTION: 0x1010f5b0 size=0xb4
#include "engineclient.h"
#include "CMoveHelperClient.h"
#include "C_RecipientFilter.h"
struct CUnknown100be160
{
	void *m_vt;
	char m_a, m_b;
	void *m_pMem;
	int m_nAlloc;
	int m_nGrow;
	int m_Size;
	void *m_pElements;
	int m_n1c, m_n20, m_n24;
	char m_c, m_d;
	~CUnknown100be160()
	{
		m_Size = 0;
		if (m_nGrow != -1)
		{
			if (m_pMem)
			{
				Plat_Free(m_pMem);
				m_pMem = 0;
			}
			m_nAlloc = 0;
		}
		m_pElements = m_pMem;
		if (m_nGrow != -1)
		{
			if (m_pElements)
				Plat_Free(m_pElements);
		}
	}
	void *sub_100be160();
	void sub_100be0d0();
};
void CMoveHelperClient::sub_1010f5b0(const Vector &origin, int channel, const char *sample, float volume, int level, int flags, int pitch)
{
	if (!sample)
		return;
	enginesound->vfunc0(sample, 0);
	CUnknown100be160 filter;
	filter.sub_100be160();
	filter.sub_100be0d0();
	enginesound->vfunc2(*(IRecipientFilter *)&filter, -1, channel, sample, volume, level, 0, pitch, &origin, 0, 1, 0);
}
// END FUNCTION

// FUNCTION: 0x1010f670 size=0x3
// TARGET: sub_1010f670
void __stdcall sub_1010f670(int, int, int, int, int, int, int, int, int, int, int, int)
{
}
// END FUNCTION

// FUNCTION: 0x1010f680 size=0x6
#include "CPhysicsIfaces.h"

extern CPhysSurfacePropsIface *g_104e0c94;

// TARGET: sub_1010f680
CPhysSurfacePropsIface *sub_1010f680()
{
	return g_104e0c94;
}
// END FUNCTION

// FUNCTION: 0x1010f690 size=0x64
#include <stdarg.h>
#include "CMoveHelperClient.h"

extern int (__cdecl *g_101e31a8)(char *, int, const char *, va_list);
extern int (__cdecl *g_101e3118)(int, const char *, ...);
extern int (__cdecl *g_101e3108)(const char *, ...);

// TARGET: vfunc15
void CMoveHelperClient::vfunc15(bool bDevMsg, const char *fmt, ...)
{
	char buf[0x2000];
	va_list args;
	va_start(args, fmt);
	g_101e31a8(buf, 0x2000, fmt, args);
	va_end(args);
	if (bDevMsg)
		g_101e3118(1, buf);
	else
		g_101e3108(buf);
}
// END FUNCTION

// FUNCTION: 0x1010f700 size=0x4c
#include "CMoveHelperClient.h"
#include <stdarg.h>
extern "C" __declspec(dllimport) int __cdecl Q_vsnprintf(char *, unsigned int, const char *, va_list);
struct EngV { void **vt; };
extern EngV *g_104a57d4;
void CMoveHelperClient::vfunc4(int idx, const char *fmt, ...)
{
	char msg[8192];
	va_list args;
	va_start(args, fmt);
	Q_vsnprintf(msg, sizeof(msg), fmt, args);
	va_end(args);
	((void (__cdecl *)(EngV *, int, char *))g_104a57d4->vt[60])(g_104a57d4, idx, msg);
}
// END FUNCTION

// FUNCTION: 0x1010f750 size=0xe
#include "engineclient.h"
struct CView { void sub_1010f750(); };
// TARGET: ?sub_1010f750@CView@@QAEXXZ
void CView::sub_1010f750() { engine->vfunc75(); }
// END FUNCTION

// FUNCTION: 0x1010f760 size=0xb
struct IMI { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); };
extern IMI *g_104a57f8;
struct CView { void sub_1010f760(); };
// TARGET: ?sub_1010f760@CView@@QAEXXZ
void CView::sub_1010f760() { g_104a57f8->v6(); }
// END FUNCTION

// FUNCTION: 0x1010f770 size=0xb
#include "CMoveHelperClient.h"
struct IView_104a57f8 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); };
extern IView_104a57f8 *g_104a57f8;
// TARGET: CMoveHelperClient::vfunc19
void CMoveHelperClient::vfunc19()
{
	g_104a57f8->v3();
}
// END FUNCTION

// FUNCTION: 0x1010f780 size=0x6a
#include "CMoveHelperClient.h"
#include "FileSystemViews.h"

extern "C" void *__cdecl malloc(unsigned int);

void *CMoveHelperClient::vfunc20(const char *name, int *pSize)
{
	int h = g_104a580c->vfunc0(name, "rb", 0);
	if ( h )
	{
		int size = g_104a580c->vfunc6(h);
		if ( pSize )
			*pSize = size;
		void *buf = malloc(size);
		g_104a580c->vfunc2(buf, size, h);
		g_104a580c->vfunc1(h);
		return buf;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x1010f7f0 size=0xe
extern "C" void free(void *);
struct CView { void sub_1010f7f0(void *); };
// TARGET: ?sub_1010f7f0@CView@@QAEXPAX@Z
void CView::sub_1010f7f0(void *p) { free(p); }
// END FUNCTION

// FUNCTION: 0x1010f800 size=0x3
#include "CMoveHelperClient.h"

// TARGET: CMoveHelperClient::vfunc7
bool CMoveHelperClient::vfunc7()
{
	return true;
}
// END FUNCTION

// FUNCTION: 0x1010f810 size=0x3
// TARGET: sub_1010f810
void __stdcall sub_1010f810(int)
{
}
// END FUNCTION

// FUNCTION: 0x1010f820 size=0x7
// TARGET: sub_1010f820
double __stdcall sub_1010f820(int x)
{
	return x;
}
// END FUNCTION

// FUNCTION: 0x1010f830 size=0x3d
#include "CClientEntityList.h"
struct G { int u0; void *p; int idx; };
struct H {
	unsigned long m;
	bool operator==(const H &o) const { return m == o.m; }
};
static inline H Cur()
{
	H r;
	if (((G *)cl_entitylist)->p)
		r.m = ((G *)cl_entitylist)->idx << 13;
	else
		r.m = 0xFFFFFFFF;
	return r;
}
bool __stdcall sub_1010f830(const H *h)
{
	return *h == Cur();
}
// END FUNCTION
