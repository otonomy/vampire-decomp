// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1016b180 size=0x1e
#include "VBarterLabel.h"

// VC6 writes VBarterLabel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
VBarterLabel *pcd_emit_1016b180(const VBarterLabel &other) { return new VBarterLabel(other); }

// TARGET: ??_GVBarterLabel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1016b2a0 size=0x26
#include "VBarterLabel.h"
namespace lifted {
extern char g_1027b3d0;
extern char g_104cfe38;
struct C100f0ed0 { int sub_100f0ed0(int); };
struct C1016d150 { int sub_1016d150(); };
int sub_101aa640();
}
void VBarterLabel::vfunc85()
{
    int t0 = lifted::sub_101aa640();
    *(char *)((char *)this + 0xb9) = 1;
    int t1 = ((lifted::C100f0ed0 *)((int)&lifted::g_104cfe38))->sub_100f0ed0((int)&lifted::g_1027b3d0);
    ((lifted::C1016d150 *)t1)->sub_1016d150();
}
// END FUNCTION

// FUNCTION: 0x1016b2d0 size=0x26
#include "VBarterLabel.h"
namespace lifted {
extern char g_1027b3d0;
extern char g_104cfe38;
struct C100f0ed0 { int sub_100f0ed0(int); };
struct C1016d150 { int sub_1016d150(); };
int sub_101aa650();
}
void VBarterLabel::vfunc86()
{
    int t0 = lifted::sub_101aa650();
    *(char *)((char *)this + 0xb9) = 0;
    int t1 = ((lifted::C100f0ed0 *)((int)&lifted::g_104cfe38))->sub_100f0ed0((int)&lifted::g_1027b3d0);
    ((lifted::C1016d150 *)t1)->sub_1016d150();
}
// END FUNCTION

// FUNCTION: 0x1016b300 size=0x24a
template <class T> __forceinline T pcd_stage(T x) { return x; }
#include "ehandle.h"
#include "CHud.h"
#include "VBarterUI.h"
#include "VBarterLabel.h"

#define V1(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4(); virtual void a##5(); virtual void a##6(); virtual void a##7(); virtual void a##8(); virtual void a##9();

struct InnerV { virtual void i0(); virtual void i1(); virtual void i2(); virtual void i3(); virtual void i4(); virtual void i5(); virtual void i6(); virtual void i7(); virtual void i8(); virtual int vf9(); };
struct SubV {
	V1(a) V1(b) V1(c) V1(d) V1(e) V1(f) V1(g) V1(h) V1(i) V1(j) V1(k) V1(l) V1(m) V1(n) V1(o) V1(p) V1(q) V1(r) V1(s) V1(t) V1(u) V1(v)
	virtual void z0(); virtual void z1(); virtual void z2();
	virtual int vf223(int);
	int mFour; InnerV in8;
};
struct PlayerV {
	V1(a) V1(b) V1(c) V1(d) V1(e) V1(f) V1(g) V1(h) V1(i) V1(j) V1(k) V1(l) V1(m) V1(n) V1(o) V1(p)
	virtual void z0(); virtual void z1(); virtual void z2(); virtual void z3(); virtual void z4(); virtual void z5(); virtual void z6();
	virtual SubV *vf167();
	virtual void vf168(void *);
	virtual void vf169(SubV *);
};
struct EngV { V1(a) V1(b) virtual void y0(); virtual void y1(); virtual void y2(); virtual void y3(); virtual void y4(); virtual void y5(); virtual void y6(); virtual void vf27(int); };

struct HE {
	char pad[0x181]; bool m181;
	void sub_1016f500(void *ent, bool b);
	bool sub_10170030();
	void sub_1016f4a0();
	void sub_10170aa0(void *ent, bool b);
	void sub_10170430(int);
	void sub_1016f5f0(void *ent, bool b);
	void sub_1016d150();
};
struct BL {
	char pad[0xb8]; bool m_b8, m_b9, m_ba, m_bb; CBaseHandle m_h;
};

extern CHud g_104cfe38;
extern PlayerV *g_104a0d50;
extern EngV *g_104a57d4;
extern int g_104a0d48;

void VBarterLabel::vfunc89(int)
{
	BL *p = (BL *)this;
	if (p->m_bb) {
		p->m_bb = false;
		void *e1 = p->m_h.Get();
		((HE *)g_104cfe38.sub_100f0ed0("VBarterUI"))->sub_1016f500(e1, p->m_b8);
		if (((HE *)pcd_stage(g_104cfe38.sub_100f0ed0("VBarterUI")))->m181) {
			void *ent = p->m_h.Get();
			PlayerV *pl = g_104a0d50;
			if (!pl || !ent)
				return; pl->vf169(pl->vf167());
			pl->vf168(ent);
			g_104a57d4->vf27(pl->vf167()->vf223(1));
			g_104a0d48 = pl->vf167()->in8.vf9();
		} else {
			if (((HE *)g_104cfe38.sub_100f0ed0("VBarterUI"))->sub_10170030()) {
				((HE *)g_104cfe38.sub_100f0ed0("VBarterUI"))->sub_1016f4a0();
				((HE *)g_104cfe38.sub_100f0ed0("VBarterUI"))->sub_10170aa0(p->m_h.Get(), p->m_b8);
			}
		}
	} else {
		((HE *)g_104cfe38.sub_100f0ed0("VBarterUI"))->sub_1016f4a0();
		p->m_ba = true;
		((HE *)g_104cfe38.sub_100f0ed0("VBarterUI"))->sub_1016f5f0(p->m_h.Get(), p->m_b8);
	}
	((HE *)g_104cfe38.sub_100f0ed0("VBarterUI"))->sub_10170430(1);
	((HE *)g_104cfe38.sub_100f0ed0("VBarterUI"))->sub_1016d150();
}
// END FUNCTION

// FUNCTION: 0x1016b550 size=0xa
#include "VBarterLabel.h"
void VBarterLabel::vfunc88(int a0)
{
    *(char *)((char *)this + 0xbb) = 1;
}
// END FUNCTION
