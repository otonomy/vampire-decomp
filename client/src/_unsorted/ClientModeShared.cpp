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

// FUNCTION: 0x100d4040 size=0x196
#include "ClientModeShared.h"
#include "C_BasePlayer.h"
#include "C_BaseCineCamera.h"
#include "CInput.h"

void sub_101090a0(const QAngle &angles, Vector *forward, Vector *right, Vector *up);
void sub_10108fd0(const Vector &start, float scale, const Vector &direction, Vector &dest);

#define VMV(n) virtual void v##n();
#define VMV10(p) VMV(p##0) VMV(p##1) VMV(p##2) VMV(p##3) VMV(p##4) VMV(p##5) VMV(p##6) VMV(p##7) VMV(p##8) VMV(p##9)
struct WeaponView_100d4040
{
	VMV(0) VMV(1) VMV(2) VMV(3) VMV(4) VMV(5) VMV(6) VMV(7) VMV(8) VMV(9)
	VMV10(1) VMV10(2) VMV10(3) VMV10(4) VMV10(5) VMV10(6) VMV10(7) VMV10(8) VMV10(9)
	VMV10(10) VMV10(11) VMV10(12) VMV10(13) VMV10(14) VMV10(15) VMV10(16) VMV10(17) VMV10(18) VMV10(19)
	VMV10(20) VMV10(21) VMV10(22) VMV10(23)
	VMV(240) VMV(241) VMV(242) VMV(243)
	virtual void vfunc244(void *cmd);
	VMV(245) VMV(246)
	virtual bool vfunc247();
};
struct VMRecord_100d4040 { char m_pad[8]; Vector m_vecOrigin; Vector m_ang1; Vector m_ang2; };
struct ViewObj_100d4040
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual VMRecord_100d4040 *vfunc6(int);
};
extern ViewObj_100d4040 *g_102d43d8;
WeaponView_100d4040 *sub_1009b210();

// TARGET: ClientModeShared::vfunc15
void ClientModeShared::vfunc15(int cmdp)
{
	char *cmd = (char *)cmdp;
	C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
	WeaponView_100d4040 *pWeapon = sub_1009b210();
	if (pWeapon)
		pWeapon->vfunc244(cmd);
	C_BaseCineCamera *pCam = 0;
	if (pPlayer) {
		pCam = (C_BaseCineCamera *)pPlayer->sub_100a7890();
		if (pCam && pCam->sub_10001970())
			input->vfunc33(cmd + 0x38, cmd + 0x50, cmd + 0x28);
		else
			input->vfunc31(cmd);
	}
	if (input->vfunc48()) {
		cmd[0x16] = 1;
		float a, b;
		input->vfunc49(&a, &b);
		a *= 0.5f;
		b *= 0.5f;
		*(float *)(cmd + 0x18) = -a;
		*(float *)(cmd + 0x1c) = -b;
		*(float *)(cmd + 0x20) = a;
		*(float *)(cmd + 0x24) = b;
	}
	if (pCam && pCam->sub_10001970() && pCam->sub_100019a0())
		return;
	if (pWeapon && pWeapon->vfunc247()) {
		for (int i = 0; i < 2; i++) {
			VMRecord_100d4040 *p = g_102d43d8->vfunc6(i);
			if (p) {
				Vector fwd, right, up;
				sub_101090a0(*(QAngle *)&p->m_ang2, &fwd, &right, &up);
				sub_10108fd0(p->m_vecOrigin, p->m_ang2.x * -0.035f, fwd, p->m_vecOrigin);
				sub_10108fd0(p->m_vecOrigin, p->m_ang2.x * -0.03f, right, p->m_vecOrigin);
				sub_10108fd0(p->m_vecOrigin, p->m_ang2.x * -0.02f, up, p->m_vecOrigin);
			}
		}
	}
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

// FUNCTION: 0x100d4310 size=0xe9
#include "ClientModeShared.h"
#include "CVMainMenu.h"
#include "CHudDialog.h"
#include "C_BasePlayer.h"
#include "CClientEntityList.h"
#define G(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4(); virtual void a##5(); virtual void a##6(); virtual void a##7(); virtual void a##8(); virtual void a##9();
#define H(a) G(a##0) G(a##1) G(a##2) G(a##3) G(a##4) G(a##5) G(a##6) G(a##7) G(a##8) G(a##9)
struct IUnk246_100d4310 {
	H(a) H(b) G(c0) G(c1) G(c2) G(c3) virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5();
	virtual int v246(int, int, const char *);
};
struct IEnt25_100d4310 {
	G(a0) G(a1) virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4();
	virtual bool v25(int);
};
struct WizMgr_100d4310 {
	char pad0[0x10];
	struct Sub { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9();
		virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5(); virtual void b6(); virtual void b7(); virtual void b8(); virtual void b9();
		virtual void c0(); virtual void c1(); virtual bool v22(); } m_sub;
	int sub_10175e10(int, int, const char *);
};
extern CVMainMenu *g_103ef0b4;
extern WizMgr_100d4310 *g_105fb1f8;
extern char g_103eee48;
extern CHudDialog *g_103eee40;
bool sub_10052ed0();
CHudDialog *sub_10052ef0();
IUnk246_100d4310 *sub_1009b210();
// TARGET: ClientModeShared::vfunc16
int ClientModeShared::vfunc16(int down, int key, const char *binding)
{
	C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
	if (g_103ef0b4 && (char)g_103ef0b4->vfunc22())
		return g_103ef0b4->sub_10065db0(down, key, (int)binding);
	if (g_105fb1f8 && g_105fb1f8->m_sub.v22())
		return g_105fb1f8->sub_10175e10(down, key, binding);
	if (sub_10052ed0())
		return sub_10052ef0()->vfunc114(down, key, (int)binding);
	if (g_103eee48)
		return g_103eee40->sub_10061450(down, key, (int)binding);
	if (down && pPlayer && *(int *)((char *)pPlayer + 0x16b8) > 0) {
		IEnt25_100d4310 *pEnt = (IEnt25_100d4310 *)cl_entitylist->sub_100d0cf0(*(int *)((char *)pPlayer + 0x16b8));
		if (pEnt && pEnt->v25(key))
			return 0;
	}
	IUnk246_100d4310 *p = sub_1009b210();
	if (p)
		return p->v246(down, key, binding);
	return 1;
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
