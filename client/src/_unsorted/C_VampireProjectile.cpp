// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100c6840 size=0x3
#include "C_VampireProjectile.h"
bool C_VampireProjectile::vfunc144()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100c6850 size=0x7
#include "C_VampireProjectile.h"
namespace lifted {
extern float g_1022d918;
}
float C_VampireProjectile::vfunc145()
{
    return lifted::g_1022d918;
}
// END FUNCTION

// FUNCTION: 0x100c6860 size=0x11
struct B1_100c6860 { int a; };
struct B2_100c6860 { int b; };
struct T_100c6860 : B1_100c6860, B2_100c6860 { void f(); };
struct V_100c6860 : T_100c6860 {
	int m_unk[(0x20 - 12) / 4];
	void (T_100c6860::*m_pfn)();
};
// TARGET: sub_100c6860
void __fastcall sub_100c6860(V_100c6860 *self)
{
	if (self->m_pfn)
		(self->*self->m_pfn)();
}
// END FUNCTION

// FUNCTION: 0x100c6880 size=0x3
#include "C_VampireProjectile.h"
int C_VampireProjectile::vfunc86()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10151d00 size=0x6
#include "C_VampireProjectile.h"
namespace lifted {
extern char g_102ca214;
}
int C_VampireProjectile::vfunc16()
{
    return (int)&lifted::g_102ca214;
}
// END FUNCTION

// FUNCTION: 0x10151d10 size=0x3
#include "C_VampireProjectile.h"
int C_VampireProjectile::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10151fc0 size=0x4b
#include "C_VampireProjectile.h"
#include "CBaseHandle.h"
C_VampireProjectile::C_VampireProjectile()
{
	m_unk798 = 0;
	m_unk7e4 = 0;
}
// END FUNCTION

// FUNCTION: 0x10152010 size=0x1e
#include "C_VampireProjectile.h"

// VC6 writes C_VampireProjectile's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_VampireProjectile *pcd_emit_10152010(const C_VampireProjectile &other) { return new C_VampireProjectile(other); }

// TARGET: ??_GC_VampireProjectile@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10152030 size=0x27
#include "C_VampireProjectile.h"
C_VampireProjectile::~C_VampireProjectile()
{
}
// END FUNCTION

// FUNCTION: 0x10152060 size=0xb
#include "C_VampireProjectile.h"
namespace lifted {
extern char g_102ca2c4;
int __stdcall sub_100a0710(int);
}
void C_VampireProjectile::vfunc21()
{
    lifted::sub_100a0710((int)&lifted::g_102ca2c4);
}
// END FUNCTION

// FUNCTION: 0x10152070 size=0x3b
#include "C_VampireProjectile.h"
namespace lifted {
extern char g_104d4970;
struct C10043230 { int sub_10043230(int); };
struct C1009fc60 { int sub_1009fc60(int, int); };
struct C100a2850 { int sub_100a2850(int, int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(); };
}
void C_VampireProjectile::vfunc19()
{
    ((lifted::V *)this)->f21();
    ((lifted::C10043230 *)((char *)this + 0x190))->sub_10043230(2);
    ((lifted::C100a2850 *)this)->sub_100a2850((int)&lifted::g_104d4970, (int)&lifted::g_104d4970);
    ((lifted::C1009fc60 *)this)->sub_1009fc60(0xd, 0);
    int t0 = (*(int *)((char *)this + 0x74)) | 0xa0;
    *(int *)((char *)this + 0x74) = t0;
}
// END FUNCTION

// FUNCTION: 0x101520d0 size=0x3
#include "C_VampireProjectile.h"
void C_VampireProjectile::vfunc96(int a0, int a1, int a2, int a3)
{
}
// END FUNCTION

// FUNCTION: 0x101520e0 size=0x1
#include "C_VampireProjectile.h"
void C_VampireProjectile::vfunc143()
{
}
// END FUNCTION

// FUNCTION: 0x10152210 size=0x3
#include "C_VampireProjectile.h"
void C_VampireProjectile::vfunc147(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x10152420 size=0x16
#include "C_VampireProjectile.h"

// TARGET: C_VampireProjectile::vfunc113
bool C_VampireProjectile::vfunc113(bool isbeingremoved, C_BaseEntity *predicted)
{
	C_BaseEntity::vfunc113(isbeingremoved, predicted);
	return isbeingremoved;
}
// END FUNCTION
