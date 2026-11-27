// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100bce30 size=0x6
#include "C_PlayerResource.h"
namespace lifted {
extern char g_102b55bc;
}
int C_PlayerResource::vfunc16()
{
    return (int)&lifted::g_102b55bc;
}
// END FUNCTION

// FUNCTION: 0x100bce40 size=0x3
#include "C_PlayerResource.h"
int C_PlayerResource::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100bd200 size=0xe5
#include "C_PlayerResource.h"
#include <string.h>
extern C_PlayerResource *g_104a38f8;
// TARGET: ??0C_PlayerResource@@QAE@XZ
C_PlayerResource::C_PlayerResource()
{
	memset(m_a728, 0, sizeof(m_a728));
	memset(m_ab48, 0, sizeof(m_ab48));
	memset(m_abcc, 0, sizeof(m_abcc));
	memset(m_ac50, 0, sizeof(m_ac50));
	memset(m_a410, 0, sizeof(m_a410));
	memset(m_a494, 0, sizeof(m_a494));
	memset(m_a518, 0, sizeof(m_a518));
	memset(m_a59c, 0, sizeof(m_a59c));
	memset(m_a620, 0, sizeof(m_a620));
	memset(m_a6a4, 0, sizeof(m_a6a4));
	memset(m_acd4, 0, sizeof(m_acd4));
	memset(m_ad58, 0, sizeof(m_ad58));
	memset(m_ad79, 0, sizeof(m_ad79));
	g_104a38f8 = this;
}
// END FUNCTION

// FUNCTION: 0x100bd2f0 size=0x5
#include "C_PlayerResource.h"
int C_PlayerResource::vfunc135(int a0)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100bd300 size=0x5
#include "C_PlayerResource.h"
int C_PlayerResource::vfunc136(int a0)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100bd310 size=0x9
#include "C_PlayerResource.h"
namespace lifted {
extern float g_101e34f0;
}
float C_PlayerResource::vfunc137(int a0)
{
    return lifted::g_101e34f0;
}
// END FUNCTION

// FUNCTION: 0x100bd320 size=0x3
#include "C_PlayerResource.h"
void C_PlayerResource::vfunc138(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x100bd330 size=0x1e
#include "C_PlayerResource.h"

// VC6 writes C_PlayerResource's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_PlayerResource *pcd_emit_100bd330(const C_PlayerResource &other) { return new C_PlayerResource(other); }

// TARGET: ??_GC_PlayerResource@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100bd350 size=0x31
#include "C_PlayerResource.h"
extern C_PlayerResource *g_104a38f8;
// TARGET: ??1C_PlayerResource@@UAE@XZ
C_PlayerResource::~C_PlayerResource()
{
	g_104a38f8 = 0;
}
// END FUNCTION

// FUNCTION: 0x100bd390 size=0x28
#include "C_PlayerResource.h"
// TARGET: ?vfunc120@C_PlayerResource@@UAEHH@Z
int C_PlayerResource::vfunc120(int i) { if (!vfunc133(i)) return 0; return m_a410[i]; }
// END FUNCTION

// FUNCTION: 0x100bd3c0 size=0x28
#include "C_PlayerResource.h"
int C_PlayerResource::vfunc121(int i)
{
	if (!vfunc133(i))
		return 0;
	return m_a494[i];
}
// END FUNCTION

// FUNCTION: 0x100bd3f0 size=0x28
#include "C_PlayerResource.h"
int C_PlayerResource::vfunc122(int i) { if (!vfunc133(i)) return 0; return m_a518[i]; }
// END FUNCTION

// FUNCTION: 0x100bd420 size=0x28
#include "C_PlayerResource.h"
// TARGET: ?vfunc123@C_PlayerResource@@UAEHH@Z
int C_PlayerResource::vfunc123(int i) { if (!vfunc133(i)) return 0; return m_a59c[i]; }
// END FUNCTION

// FUNCTION: 0x100bd450 size=0x28
#include "C_PlayerResource.h"
int C_PlayerResource::vfunc124(int i) { if (!vfunc133(i)) return 0; return m_a620[i]; }
// END FUNCTION

// FUNCTION: 0x100bd480 size=0x3e
#include "C_PlayerResource.h"
int C_PlayerResource::vfunc125(int idx)
{
	if (!vfunc133(idx))
		return 0;
	int v = m_a620[idx];
	int n = 0;
	for (int i = 0; i < 2; i++)
		if (v & (1 << i))
			n++;
	return n;
}
// END FUNCTION

// FUNCTION: 0x100bd4c0 size=0x28
#define V8(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7();
class PRView {
public:
	V8(a) V8(b) V8(c) V8(d) V8(e) V8(f) V8(g) V8(h) V8(i) V8(j) V8(k) V8(l) V8(m) V8(n) V8(o) V8(p)
	virtual void z0(); virtual void z1(); virtual void z2(); virtual void z3(); virtual void z4();
	virtual bool IsConnected(int i);
	char pad[0x6a4 - 4];
	int m6a4[1];
	int sub_100bd4c0(int i);
};
int PRView::sub_100bd4c0(int i)
{
	if (!IsConnected(i))
		return 0;
	return m6a4[i];
}
// END FUNCTION

// FUNCTION: 0x100bd4f0 size=0x3e
#include "C_PlayerResource.h"
int C_PlayerResource::vfunc127(int idx)
{
	if (!vfunc133(idx))
		return 0;
	int v = m_a6a4[idx];
	int n = 0;
	for (int i = 0; i < 8; i++)
		if (v & (1 << i))
			n++;
	return n;
}
// END FUNCTION

// FUNCTION: 0x100bd5b0 size=0x69
#include "engineclient.h"
#include "C_PlayerResource.h"


extern char *(*g_101e3188)(char *, const char *, int);

const char *C_PlayerResource::vfunc128(int index)
{
	if ( !vfunc133(index) )
		return "unconnected";
	int info[3];
	engine->vfunc30(index, info);
	char *name = (char *)info[1];
	if ( name )
		g_101e3188((char *)this + 0x728 + index * 32, name, 0x20);
	return (char *)this + 0x728 + index * 32;
}
// END FUNCTION

// FUNCTION: 0x100bd620 size=0x28
#include "C_PlayerResource.h"
int C_PlayerResource::vfunc129(int i) { if (!vfunc133(i)) return 0; return m_ab48[i]; }
// END FUNCTION

// FUNCTION: 0x100bd650 size=0x28
#include "C_PlayerResource.h"
int C_PlayerResource::vfunc130(int i) { if (!vfunc133(i)) return 0; return m_abcc[i]; }
// END FUNCTION

// FUNCTION: 0x100bd680 size=0x28
#include "C_PlayerResource.h"
// TARGET: ?vfunc131@C_PlayerResource@@UAEHH@Z
int C_PlayerResource::vfunc131(int i) { if (!vfunc133(i)) return 0; return m_ac50[i]; }
// END FUNCTION

// FUNCTION: 0x100bd6b0 size=0x28
#include "C_PlayerResource.h"
int C_PlayerResource::vfunc132(int i) { if (!vfunc133(i)) return 0; return m_acd4[i]; }
// END FUNCTION

// FUNCTION: 0x100bd6e0 size=0xe
#include "C_PlayerResource.h"
bool C_PlayerResource::vfunc133(int a0)
{
    return *(bool *)((char *)a0 + (int)this + 0xd58);
}
// END FUNCTION

// FUNCTION: 0x100bd6f0 size=0xe
#include "C_PlayerResource.h"
// TARGET: C_PlayerResource::vfunc134
char C_PlayerResource::vfunc134(int i) { return m_ad79[i]; }
// END FUNCTION
