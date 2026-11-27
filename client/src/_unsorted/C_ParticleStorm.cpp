// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10003fa0 size=0x6
#include "C_ParticleStorm.h"
namespace lifted {
extern char g_10271a44;
}
int C_ParticleStorm::vfunc16()
{
    return (int)&lifted::g_10271a44;
}
// END FUNCTION

// FUNCTION: 0x10003fb0 size=0x3
#include "C_ParticleStorm.h"
int C_ParticleStorm::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10004400 size=0x1e
#include "C_ParticleStorm.h"

// VC6 writes C_ParticleStorm's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_ParticleStorm *pcd_emit_10004400(const C_ParticleStorm &other) { return new C_ParticleStorm(other); }

// TARGET: ??_GC_ParticleStorm@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10004510 size=0x42
#include "C_ParticleStorm.h"
#include "Vector.h"

extern char g_104e0768[];

// TARGET: C_ParticleStorm::OnDataChanged
void C_ParticleStorm::OnDataChanged(int updateType)
{
	C_BaseEntity::OnDataChanged(updateType);
	if (updateType == 0)
	{
		sub_10004480(GetAbsOrigin(), 1);
		((IPrototypeAppEffect *)((char *)this + 0x468))->vfunc1(g_104e0768, 0);
	}
}
// END FUNCTION
