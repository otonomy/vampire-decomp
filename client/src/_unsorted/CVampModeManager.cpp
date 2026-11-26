// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10162320 size=0x1e
#include "CVampModeManager.h"

// VC6 writes CVampModeManager's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CVampModeManager *pcd_emit_10162320() { return new CVampModeManager; }

// TARGET: ??_GCVampModeManager@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10162350 size=0x15
#include "CVampModeManager.h"
namespace lifted {
extern int g_104a5824;
extern int g_105f99d8;
int sub_10029490();
int sub_1012c6d0();
}
int CVampModeManager::vfunc0()
{
    lifted::g_105f99d8 = lifted::sub_10029490();
    lifted::g_104a5824 = lifted::sub_1012c6d0();
    return lifted::g_104a5824;
}
// END FUNCTION

// FUNCTION: 0x10162370 size=0x72
#include "CInput.h"
#include "CVampModeManager.h"
namespace lifted {
extern int g_105f99d8;
int sub_10029490();
int sub_100429f0();
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual int f3(); virtual int f4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual int f16(); virtual int f17(); };
}
void CVampModeManager::vfunc1(char a0, int a1)
{
    if (a0 != 0) {
        int t0 = lifted::sub_100429f0();
        if (lifted::g_105f99d8 != t0) {
            ((lifted::V *)lifted::g_105f99d8)->f4();
            input->vfunc17();
            lifted::g_105f99d8 = lifted::sub_100429f0();
            ((lifted::V *)lifted::g_105f99d8)->f3(); return;
        }
        return;
    }
    int t1 = lifted::sub_10029490();
    if (lifted::g_105f99d8 != t1) {
        ((lifted::V *)lifted::g_105f99d8)->f4();
        lifted::g_105f99d8 = lifted::sub_10029490();
        input->vfunc16();
        ((lifted::V *)lifted::g_105f99d8)->f3();
    }
}
// END FUNCTION

// FUNCTION: 0x101623f0 size=0x3
#include "CVampModeManager.h"
void CVampModeManager::vfunc6(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x10162400 size=0x3
#include "CVampModeManager.h"
void CVampModeManager::vfunc7(int a0, int a1)
{
}
// END FUNCTION

// FUNCTION: 0x10162410 size=0x3
#include "CVampModeManager.h"
void CVampModeManager::vfunc2(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x10162420 size=0x1
#include "CVampModeManager.h"
void CVampModeManager::vfunc3()
{
}
// END FUNCTION

// FUNCTION: 0x10162430 size=0x16
#include "CVampModeManager.h"
namespace lifted {
extern int g_105f99d8;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual int f32(float); };
}
int CVampModeManager::vfunc4(float a0)
{
    return ((lifted::V *)lifted::g_105f99d8)->f32(a0);
}
// END FUNCTION
