// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10170d60 size=0x1e
#include "FuckYouValveLabel.h"

// VC6 writes FuckYouValveLabel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
FuckYouValveLabel *pcd_emit_10170d60(const FuckYouValveLabel &other) { return new FuckYouValveLabel(other); }

// TARGET: ??_GFuckYouValveLabel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10170da0 size=0x33
#include "FuckYouValveLabel.h"
namespace lifted {
struct C101b2e60 { int sub_101b2e60(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual int f51(int); virtual void u52(); virtual int f53(int); };
}
int FuckYouValveLabel::vfunc74(int a0)
{
    int l0;
    ((lifted::V *)this)->f53((int)((char *)&l0));
    ((lifted::C101b2e60 *)this)->sub_101b2e60(a0);
    return ((lifted::V *)this)->f51(l0);
}
// END FUNCTION
