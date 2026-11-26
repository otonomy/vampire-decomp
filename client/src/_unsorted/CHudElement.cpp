// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100bbd80 size=0x1
#include "CHudElement.h"
void CHudElement::vfunc1()
{
}
// END FUNCTION

// FUNCTION: 0x100bbd90 size=0x1
#include "CHudElement.h"
void CHudElement::vfunc2()
{
}
// END FUNCTION

// FUNCTION: 0x100bbda0 size=0x1
#include "CHudElement.h"
void CHudElement::vfunc3()
{
}
// END FUNCTION

// FUNCTION: 0x100bbdb0 size=0x1
#include "CHudElement.h"
void CHudElement::vfunc4()
{
}
// END FUNCTION

// FUNCTION: 0x100bbdc0 size=0x1
#include "CHudElement.h"
void CHudElement::vfunc6()
{
}
// END FUNCTION

// FUNCTION: 0x100bbdd0 size=0x1
#include "CHudElement.h"
void CHudElement::vfunc7()
{
}
// END FUNCTION

// FUNCTION: 0x100bbde0 size=0x4
#include "CHudElement.h"
int CHudElement::vfunc8()
{
    return *(int *)((char *)this + 8);
}
// END FUNCTION

// FUNCTION: 0x100bbdf0 size=0x4
#include "CHudElement.h"
bool CHudElement::vfunc10()
{
    return *(bool *)((char *)this + 4);
}
// END FUNCTION

// FUNCTION: 0x100f0540 size=0x3
#include "CHudElement.h"
void CHudElement::vfunc5(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x100f0550 size=0x1e
#include "CHudElement.h"

// VC6 writes CHudElement's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CHudElement *pcd_emit_100f0550(const CHudElement &other) { return new CHudElement(other); }

// TARGET: ??_GCHudElement@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100f0590 size=0xa
#include "CHudElement.h"
bool CHudElement::vfunc11(char a0)
{
    *(char *)((char *)this + 4) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x100f05a0 size=0xa
#include "CHudElement.h"
int CHudElement::vfunc12(int a0)
{
    *(int *)((char *)this + 0xc) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x100f05b0 size=0x14
#include "CHudElement.h"
#include "CHud.h"
bool CHudElement::sub_100f05b0()
{
	return !gHUD.sub_100f10d0(m_unkc);
}
// END FUNCTION
