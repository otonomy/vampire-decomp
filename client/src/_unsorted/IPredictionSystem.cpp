// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100be270 size=0x20
#include "IPredictionSystem.h"
namespace lifted {
extern char g_10232134;
int sub_101d1296(int);
}
void * IPredictionSystem::vfunc0(char a0)
{
    *(int *)this = (int)&lifted::g_10232134;
    if ((a0 & 1) != 0) {
        lifted::sub_101d1296((int)this);
    }
    return this;
}
// END FUNCTION
