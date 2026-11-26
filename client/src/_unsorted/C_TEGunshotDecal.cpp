// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100389a0 size=0x57
#include "C_TEGunshotDecal.h"
C_TEGunshotDecal::C_TEGunshotDecal()
{
    m_v1.Init(); m_v2.Init(); m_v3.Init();
    m_v4.Init();
    m_unk4c = 0; m_unk50 = 0;
    m_unk34 = -1; m_unk38 = 0x43; m_unk3c = 1;
}
// TARGET: ??0C_TEGunshotDecal@@QAE@XZ
// END FUNCTION

// FUNCTION: 0x10038a00 size=0x1e
#include "C_TEGunshotDecal.h"

// VC6 writes C_TEGunshotDecal's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_TEGunshotDecal *pcd_emit_10038a00(const C_TEGunshotDecal &other) { return new C_TEGunshotDecal(other); }

// TARGET: ??_GC_TEGunshotDecal@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10038a40 size=0x18
#include "C_TEGunshotDecal.h"
namespace lifted {
extern char g_1027e718;
extern int g_104a57e0;
struct V { virtual void u0(); virtual void u1(); virtual int f2(int); };
}
void C_TEGunshotDecal::vfunc13()
{
    int t0 = ((lifted::V *)lifted::g_104a57e0)->f2((int)&lifted::g_1027e718);
    *(int *)((char *)this + 0x50) = t0;
}
// END FUNCTION

// FUNCTION: 0x10039620 size=0xba
#include "engineclient.h"
#include "C_TEGunshotDecal.h"
extern bool sub_100b42a0(Vector origin, int decal, Vector a, Vector b, float c, float d, float e, int f);
void C_TEGunshotDecal::vfunc16(int a, int b)
{
	Vector up;
	up.x = 0; up.y = 0; up.z = 1.0f;
	Vector right;
	right.x = 1.0f; right.y = 0; right.z = 0;
	int decal = engine->vfunc1(m_unk38, *(int *)((char *)this + 0x40));
	if (decal)
		sub_100b42a0(m_v1, decal, right, up, 0.8f, 0.8f, 0.8f, m_unk3c);
}
// END FUNCTION

// FUNCTION: 0x100396e0 size=0x6
#include "C_TEGunshotDecal.h"
namespace lifted {
extern char g_1027ffac;
}
int C_TEGunshotDecal::vfunc9()
{
    return (int)&lifted::g_1027ffac;
}
// END FUNCTION

// FUNCTION: 0x100396f0 size=0x3
#include "C_TEGunshotDecal.h"
int C_TEGunshotDecal::vfunc8()
{
    return 0;
}
// END FUNCTION
