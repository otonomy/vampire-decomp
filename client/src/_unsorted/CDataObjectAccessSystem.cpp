// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1011aea0 size=0x221
#include "ScopeTrace.h"
#include "CDataObjectAccessSystem.h"

struct HashView_1011e890 { void sub_1011e890(int, int, int, void *, void *); };
struct HashView_1011e9a0 { void sub_1011e9a0(int, int, int, void *, void *); };
struct HashView_1011eab0 { void sub_1011eab0(int, int, int, void *, void *); };
struct HashView_1011ebc0 { void sub_1011ebc0(int, int, int, void *, void *); };
struct STView_1011b0d0 { void sub_1011b0d0(const char *, const char *, const char *); };

struct RawInst_100 { void *vptr; char hash[0x24]; };

extern char vt_10235b4c[];
extern char vt_10235b38[];
extern char vt_10235b24[];
extern char vt_10235b10[];
extern char vt_10235afc[];
extern char sub_1011e7d0[];
extern char sub_1011e7f0[];
extern char sub_1011e800[];
extern char sub_1011e820[];
extern char sub_1011e830[];
extern char sub_1011e850[];
extern char sub_1011e860[];
extern char sub_1011e880[];

// TARGET: ?vfunc0@CDataObjectAccessSystem@@UAE_NXZ
bool CDataObjectAccessSystem::vfunc0()
{
	ScopeTrace initTrace("CDataObjectAccessSystem::Init", g_102de300, g_102de300);
	RawInst_100 *p = (RawInst_100 *)operator new(0x28);
	RawInst_100 *q;
	if (p)
	{
		p->vptr = vt_10235b4c;
		((HashView_1011e890 *)p->hash)->sub_1011e890(0x40, 0, 0, sub_1011e7d0, sub_1011e7f0);
		p->vptr = vt_10235b38;
		q = p;
	}
	else
		q = 0;
	{
		ScopeTrace t("CDataObjectAccessSystem::AddDataAccessor", g_102de300, g_102de300);
		if (!m_data[1])
			m_data[1] = q;
	}
	p = (RawInst_100 *)operator new(0x28);
	if (p)
	{
		p->vptr = vt_10235b4c;
		((HashView_1011e9a0 *)p->hash)->sub_1011e9a0(0x40, 0, 0, sub_1011e800, sub_1011e820);
		p->vptr = vt_10235b24;
		q = p;
	}
	else
		q = 0;
	{
		ScopeTrace t("CDataObjectAccessSystem::AddDataAccessor", g_102de300, g_102de300);
		if (!m_data[0])
			m_data[0] = q;
	}
	p = (RawInst_100 *)operator new(0x28);
	if (p)
	{
		p->vptr = vt_10235b4c;
		((HashView_1011eab0 *)p->hash)->sub_1011eab0(0x40, 0, 0, sub_1011e830, sub_1011e850);
		p->vptr = vt_10235b10;
		q = p;
	}
	else
		q = 0;
	{
		char tbuf[1];
		((STView_1011b0d0 *)tbuf)->sub_1011b0d0("CDataObjectAccessSystem::AddDataAccessor", g_102de300, g_102de300);
		if (!m_data[2])
			m_data[2] = q;
		(g_ScopeTraceStackDepth)--;
	}
	p = (RawInst_100 *)operator new(0x28);
	if (p)
	{
		p->vptr = vt_10235b4c;
		((HashView_1011ebc0 *)p->hash)->sub_1011ebc0(0x40, 0, 0, sub_1011e860, sub_1011e880);
		p->vptr = vt_10235afc;
		q = p;
	}
	else
		q = 0;
	sub_1011b1d0(3, q);
	return true;
}
// END FUNCTION

// FUNCTION: 0x1011b150 size=0x77
#include "ScopeTrace.h"
extern char g_102de300[];
struct IObj { virtual ~IObj(); };
struct Sys {
    char pad[8];
    IObj *m_pObjects[32];
};

void __fastcall sub_1011b150(Sys *self)
{
    g_ScopeTraceStack[g_ScopeTraceStackDepth].name = "CDataObjectAccessSystem::Shutdown";
    g_ScopeTraceStack[g_ScopeTraceStackDepth].entity = g_102de300;
    g_ScopeTraceStack[g_ScopeTraceStackDepth].extra = g_102de300;
    (g_ScopeTraceStackDepth)++;
    for (int i = 0; i < 32; i++) {
        delete self->m_pObjects[i];
        self->m_pObjects[i] = 0;
    }
    (g_ScopeTraceStackDepth)--;
}
// END FUNCTION

// FUNCTION: 0x1011b250 size=0x1e
#include "CDataObjectAccessSystem.h"
namespace lifted {
int sub_100f3f80();
int sub_101d1296(int);
}
CAutoGameSystem * CDataObjectAccessSystem::vfunc8(unsigned int a0)
{
    int t0 = lifted::sub_100f3f80();
    if ((*(char *)&a0 & 1) != 0) {
        lifted::sub_101d1296((int)this);
    }
    return this;
}
// END FUNCTION
