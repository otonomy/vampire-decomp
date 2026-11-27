// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10035c90 size=0x39
#include "C_TEDecal.h"
// TARGET: ??0C_TEDecal@@QAE@XZ
C_TEDecal::C_TEDecal()
{
	m_vecOrigin.Init(0, 0, 0);
	m_vecStart.Init(0, 0, 0);
	m_unk28 = 0;
	m_unk30 = 0;
	m_unk2c = 0;
	m_unk38 = 0;
}
// END FUNCTION

// FUNCTION: 0x10035cd0 size=0x1e
#include "C_TEDecal.h"

// VC6 writes C_TEDecal's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_TEDecal *pcd_emit_10035cd0(const C_TEDecal &other) { return new C_TEDecal(other); }

// TARGET: ??_GC_TEDecal@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10035d10 size=0x18
#include "C_TEDecal.h"
namespace lifted {
extern char g_1027e718;
extern int g_104a57e0;
struct V { virtual void u0(); virtual void u1(); virtual int f2(int); };
}
void C_TEDecal::vfunc13()
{
    int t0 = ((lifted::V *)lifted::g_104a57e0)->f2((int)&lifted::g_1027e718);
    *(int *)((char *)this + 0x38) = t0;
}
// END FUNCTION

// FUNCTION: 0x10035dd0 size=0x98
#include "C_TEDecal.h"
#include "C_RecipientFilter.h"

void TE_Decal(IRecipientFilter &filter, float delay, const Vector *pos, const Vector *start, int entity, int hitbox, int index, bool b);

void C_TEDecal::PostDataUpdate(int updateType)
{
	CBroadcastRecipientFilter filter;
	TE_Decal(filter, 0.0f, &m_vecOrigin, &m_vecStart, m_unk28, m_unk2c, m_unk30, m_b34);
}
// END FUNCTION

// FUNCTION: 0x10035e70 size=0x6
#include "C_TEDecal.h"
namespace lifted {
extern char g_1027ec44;
}
int C_TEDecal::vfunc9()
{
    return (int)&lifted::g_1027ec44;
}
// END FUNCTION

// FUNCTION: 0x10035e80 size=0x3
#include "C_TEDecal.h"
int C_TEDecal::vfunc8()
{
    return 0;
}
// END FUNCTION
