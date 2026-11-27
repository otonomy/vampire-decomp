// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10027530 size=0x6
#include "C_WeaponRanged_FlameThrower.h"
namespace lifted {
extern char g_1027a990;
}
int C_WeaponRanged_FlameThrower::vfunc17()
{
    return (int)&lifted::g_1027a990;
}
// END FUNCTION

// FUNCTION: 0x10027590 size=0x6
#include "C_WeaponRanged_FlameThrower.h"
namespace lifted {
extern char g_1027a9ac;
}
int C_WeaponRanged_FlameThrower::vfunc16()
{
    return (int)&lifted::g_1027a9ac;
}
// END FUNCTION

// FUNCTION: 0x100275a0 size=0x3
#include "C_WeaponRanged_FlameThrower.h"
int C_WeaponRanged_FlameThrower::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100277b0 size=0x90
#include "C_WeaponRanged_FlameThrower.h"
#include "engineclient.h"
extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
// TARGET: ??0C_WeaponRanged_FlameThrower@@QAE@XZ
C_WeaponRanged_FlameThrower::C_WeaponRanged_FlameThrower()
{
	m_i156c = -1;
	m_f157c = (float)engine->Time(0);
	m_i1574 = 0;
	m_i1570 = 0;
	memset(m_a978, 0, sizeof(m_a978));
	memset(m_iList, 0, sizeof(m_iList));
	m_i1534 = 0;
	m_i1530 = 1;
}
// END FUNCTION

// FUNCTION: 0x10027840 size=0x1e
#include "C_WeaponRanged_FlameThrower.h"

// VC6 writes C_WeaponRanged_FlameThrower's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_WeaponRanged_FlameThrower *pcd_emit_10027840(const C_WeaponRanged_FlameThrower &other) { return new C_WeaponRanged_FlameThrower(other); }

// TARGET: ??_GC_WeaponRanged_FlameThrower@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10027980 size=0xb
#include "C_WeaponRanged_FlameThrower.h"
void C_WeaponRanged_FlameThrower::vfunc143()
{
    *(int *)((char *)this + 0x156c) = -1;
}
// END FUNCTION

// FUNCTION: 0x10027cd0 size=0x4c
#include "C_WeaponRanged_FlameThrower.h"
struct FlameSlot { int m_state; int m_4; int m_x; int m_y; int m_z; int pad[10]; };
struct FlameView { char pad[0x978]; FlameSlot m_slots[50]; };
bool C_WeaponRanged_FlameThrower::vfunc116(int idx, int pOut)
{
	FlameView *v = (FlameView *)this;
	if (idx > -1 && idx < 50 && v->m_slots[idx].m_state == 1) {
		int *out = (int *)pOut;
		if (out) {
			out[0] = v->m_slots[idx].m_x;
			out[1] = v->m_slots[idx].m_y;
			out[2] = v->m_slots[idx].m_z;
		}
		return true;
	}
	return false;
}
// END FUNCTION

// FUNCTION: 0x10028230 size=0x48
#include "C_WeaponRanged_FlameThrower.h"
// TARGET: C_WeaponRanged_FlameThrower::vfunc118
void C_WeaponRanged_FlameThrower::vfunc118(int a)
{
    if (m_i166c == a)
        m_i166c = 0;
    if (m_i1668 == a)
        m_i1668 = 0;
    for (int i = 0; i < 50; i++) {
        if (m_iList[i] == a)
            m_iList[i] = 0;
    }
}
// END FUNCTION
