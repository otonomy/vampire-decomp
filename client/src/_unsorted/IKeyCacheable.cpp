// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10153b40 size=0x20
#include "IKeyCacheable.h"
namespace lifted {
extern char g_10248374;
int sub_101d1296(int);
}
void * IKeyCacheable::vfunc2(char a0)
{
    *(int *)this = (int)&lifted::g_10248374;
    if ((a0 & 1) != 0) {
        lifted::sub_101d1296((int)this);
    }
    return this;
}
// END FUNCTION
