// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10030c30 size=0x6
#include "C_SteamJet.h"
namespace lifted {
extern char g_1027ce9c;
}
int C_SteamJet::vfunc16()
{
    return (int)&lifted::g_1027ce9c;
}
// END FUNCTION

// FUNCTION: 0x10030c40 size=0x3
#include "C_SteamJet.h"
int C_SteamJet::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10030fd0 size=0x1e
#include "C_SteamJet.h"

// VC6 writes C_SteamJet's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_SteamJet *pcd_emit_10030fd0(const C_SteamJet &other) { return new C_SteamJet(other); }

// TARGET: ??_GC_SteamJet@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10031070 size=0x3e
#include "C_SteamJet.h"

extern char g_104e0768[];

void C_SteamJet::OnDataChanged(int updateType)
{
	C_BaseEntity::OnDataChanged(updateType);
	if (updateType == 0)
		((IPrototypeAppEffect *)((char *)this + 0x468))->vfunc1(g_104e0768, 0);
	m_Lifetime = m_JetLength / m_Speed;
}
// END FUNCTION
