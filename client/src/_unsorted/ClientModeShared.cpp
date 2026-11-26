// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100d3f50 size=0x1e
#include "ClientModeShared.h"

// VC6 writes ClientModeShared's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
ClientModeShared *pcd_emit_100d3f50() { return new ClientModeShared; }

// TARGET: ??_GClientModeShared@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100d4030 size=0x1
#include "ClientModeShared.h"
void ClientModeShared::vfunc2()
{
}
// END FUNCTION

// FUNCTION: 0x100d41e0 size=0x5
#include "ClientModeShared.h"
bool ClientModeShared::vfunc11(int a0)
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100d41f0 size=0x3
#include "ClientModeShared.h"
bool ClientModeShared::vfunc13()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100d4200 size=0x16
#define V8(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7();
struct O_100d4200 {
V8(a) V8(b) V8(c) V8(d) V8(e) V8(f) V8(g) V8(h) V8(i) V8(j) V8(k) V8(l) V8(m) V8(n) V8(o) V8(p) V8(q) V8(r) V8(s) V8(t) V8(u) V8(v) V8(w) V8(x) V8(y) V8(z) V8(A) V8(B) V8(C) V8(D)
virtual void E0(); virtual void E1(); virtual void E2(); virtual void E3(); virtual void E4();
virtual void v245(int, int); };
O_100d4200 *sub_1009b210();
struct S_100d4200 { void sub_100d4200(int a, int b); };
void S_100d4200::sub_100d4200(int a, int b)
{
	O_100d4200 *p = sub_1009b210();
	if (p)
		p->v245(a, b);
}
// END FUNCTION

// FUNCTION: 0x100d4220 size=0x3
#include "ClientModeShared.h"
bool ClientModeShared::vfunc26()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100d4230 size=0x3
#include "ClientModeShared.h"
bool ClientModeShared::vfunc10()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100d4240 size=0x45
#include "CInput.h"
#include "engineclient.h"
#include "ClientModeShared.h"
struct PlV { char pad[0x44]; int m44; char pad2[0x160c - 0x48]; bool m160c; };
// TARGET: ?vfunc12@ClientModeShared@@UAE_NPAX@Z
bool ClientModeShared::vfunc12(void *p)
{
	PlV *pl = (PlV *)p;
	bool r;
	if (pl->m44 == render->vfunc39() && input->vfunc30() < 24.0f)
		r = false;
	else
		r = !pl->m160c;
	return r;
}
// END FUNCTION

// FUNCTION: 0x100d4290 size=0x3
#include "ClientModeShared.h"
bool ClientModeShared::vfunc14()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100d42a0 size=0x3
#include "ClientModeShared.h"
void ClientModeShared::vfunc28(int a0, int a1, int a2, int a3)
{
}
// END FUNCTION

// FUNCTION: 0x100d42b0 size=0x3
#include "ClientModeShared.h"
void ClientModeShared::vfunc29(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x100d42c0 size=0x1
#include "ClientModeShared.h"
void ClientModeShared::vfunc30()
{
}
// END FUNCTION

// FUNCTION: 0x100d42d0 size=0x1
#include "ClientModeShared.h"
void ClientModeShared::vfunc31()
{
}
// END FUNCTION

// FUNCTION: 0x100d42e0 size=0x1
#include "ClientModeShared.h"
void ClientModeShared::vfunc35()
{
}
// END FUNCTION

// FUNCTION: 0x100d4400 size=0x3
#include "ClientModeShared.h"
int ClientModeShared::vfunc20()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100d4410 size=0x28
#include "ClientModeShared.h"
struct CObj_100f2490 { void sub_100f2490(int a); };
extern CObj_100f2490 *g_104cef90;
extern int g_104cef94;
void ClientModeShared::vfunc17(int a)
{
	if (!g_104cef94) {
		g_104cef94 = a;
		if (g_104cef90)
			g_104cef90->sub_100f2490(a);
	}
}
// END FUNCTION

// FUNCTION: 0x100d4440 size=0x1a
#include "ClientModeShared.h"
namespace lifted {
extern int g_104cef90;
extern int g_104cef94;
struct C100f24a0 { int sub_100f24a0(); };
}
void ClientModeShared::vfunc18()
{
    lifted::g_104cef94 = 0;
    if (lifted::g_104cef90 != 0) {
        ((lifted::C100f24a0 *)lifted::g_104cef90)->sub_100f24a0(); return;
    }
}
// END FUNCTION

// FUNCTION: 0x100d4460 size=0x1a
#include "ClientModeShared.h"
namespace lifted {
extern int g_104cef90;
int sub_100f1fb0(int, int);
}
void ClientModeShared::vfunc23(int a0)
{
    int t0 = lifted::g_104cef90;
    if (t0 != 0) {
        lifted::sub_100f1fb0(t0, a0);
    }
}
// END FUNCTION

// FUNCTION: 0x100d4480 size=0xe
#include "ClientModeShared.h"
extern void *g_104cef94;
// TARGET: ClientModeShared::vfunc19
bool ClientModeShared::vfunc19() { return g_104cef94 != 0; }
// END FUNCTION

// FUNCTION: 0x100d4490 size=0x31
#include "ClientModeShared.h"
namespace lifted {
extern int g_102b9318;
extern int g_104cef90;
struct C100f2650 { int sub_100f2650(int); };
int sub_101ac8f0();
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(); };
}
void ClientModeShared::vfunc24(int a0)
{
    if (lifted::g_104cef90 != 0) {
        ((lifted::C100f2650 *)lifted::g_104cef90)->sub_100f2650(a0);
    }
    if (lifted::g_102b9318 == -1) {
        lifted::g_102b9318 = ((lifted::V *)(lifted::sub_101ac8f0()))->f21();
    }
}
// END FUNCTION

// FUNCTION: 0x100d44d0 size=0x36
#include "ClientModeShared.h"
namespace lifted {
extern int g_102b9318;
extern int g_104cef90;
int sub_101ac8f0();
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual int f22(int); };
}
void ClientModeShared::vfunc25()
{
    if (lifted::g_104cef90 != 0) {
        ((lifted::V *)lifted::g_104cef90)->f4();
    }
    if (lifted::g_102b9318 != -1) {
        int t0 = ((lifted::V *)(lifted::sub_101ac8f0()))->f22(lifted::g_102b9318);
        lifted::g_102b9318 = -1;
    }
}
// END FUNCTION

// FUNCTION: 0x100d4510 size=0x38
#include "ClientModeShared.h"
struct IObjA { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
  virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
  virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(int, int); virtual int v24(int); };
struct IGet { virtual int get(); };
IObjA *sub_101ac8f0();
extern int g_102b9318;
// TARGET: ClientModeShared::vfunc33
int ClientModeShared::vfunc33(int a)
{
  IObjA *o = sub_101ac8f0();
  o->v23(g_102b9318, ((IGet *)a)->get());
  return sub_101ac8f0()->v24(g_102b9318);
}
// END FUNCTION

// FUNCTION: 0x100d4550 size=0xf
#include "ClientModeShared.h"
namespace lifted {
int sub_101ac8f0();
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual int f24(int); };
}
int ClientModeShared::vfunc34()
{
    return ((lifted::V *)(lifted::sub_101ac8f0()))->f24(-1);
}
// END FUNCTION
