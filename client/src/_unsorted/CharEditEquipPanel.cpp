// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10178850 size=0x1e
#include "CharEditEquipPanel.h"

// VC6 writes CharEditEquipPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CharEditEquipPanel *pcd_emit_10178850(const CharEditEquipPanel &other) { return new CharEditEquipPanel(other); }

// TARGET: ??_GCharEditEquipPanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1017a690 size=0x3
#include "CharEditEquipPanel.h"
void CharEditEquipPanel::vfunc124(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1017a7b0 size=0x6
#include "CharEditEquipPanel.h"
namespace lifted {
extern char g_102d0e80;
}
int CharEditEquipPanel::vfunc102()
{
    return (int)&lifted::g_102d0e80;
}
// END FUNCTION

// FUNCTION: 0x1017a7d0 size=0x1
#include "CharEditEquipPanel.h"
void CharEditEquipPanel::vfunc119()
{
}
// END FUNCTION

// FUNCTION: 0x1017ab90 size=0x21
#include "CharEditEquipPanel.h"
int sub_1016a6b0();
void CharEditEquipPanel::vfunc123()
{
	int n = sub_1016a6b0();
	vfunc33(n);
	sub_101aa0a0(1000);
}
// END FUNCTION

// FUNCTION: 0x1017abc0 size=0x28
#include "CharEditEquipPanel.h"
namespace lifted {
struct C1017ac30 { int sub_1017ac30(); };
struct C1017ac40 { int sub_1017ac40(); };
struct C101a99f0 { int sub_101a99f0(int); };
}
int CharEditEquipPanel::vfunc21(int a0)
{
    int t0 = ((lifted::C101a99f0 *)this)->sub_101a99f0(a0);
    if (((char)a0) != 0) {
        return ((lifted::C1017ac40 *)this)->sub_1017ac40();
    }
    return ((lifted::C1017ac30 *)this)->sub_1017ac30();
}
// END FUNCTION

// FUNCTION: 0x1017ac00 size=0x28
#include "engineclient.h"
#include "CharEditEquipPanel.h"
extern int g_104a0d50;
void CharEditEquipPanel::vfunc3()
{
	if (engine->IsInGame() && g_104a0d50)
		sub_10179850();
}
// END FUNCTION
