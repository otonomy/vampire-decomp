// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10187000 size=0x1e
#include "VMapIconButton.h"

// VC6 writes VMapIconButton's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
VMapIconButton *pcd_emit_10187000(const VMapIconButton &other) { return new VMapIconButton(other); }

// TARGET: ??_GVMapIconButton@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10187020 size=0x31
#include "VMapIconButton.h"
struct MapIconObj { virtual ~MapIconObj(); };
VMapIconButton::~VMapIconButton()
{
	MapIconObj *a = *(MapIconObj **)((char *)this + 0xc8);
	if (a)
		delete a;
	MapIconObj *b = *(MapIconObj **)((char *)this + 0xcc);
	if (b)
		delete b;
}
// END FUNCTION

// FUNCTION: 0x10187070 size=0x93
#include "VMapIconButton.h"
struct PV_10187070 { void sub_101ab130(); };

void VMapIconButton::vfunc98()
{
	int a, b;
	sub_101a98c0(&a, &b);
	((PV_10187070 *)this)->sub_101ab130();
	sub_101ab1a0();
	if (*(int *)((char *)this + 0xc8) && *(int *)((char *)this + 0xcc) && (char)vfunc22()) {
		CHUDSprite10059620 *spr;
		if (*((char *)this + 0xc1) || *((char *)this + 0xc0))
			spr = *(CHUDSprite10059620 **)((char *)this + 0xcc);
		else
			spr = *(CHUDSprite10059620 **)((char *)this + 0xc8);
		if (spr)
			spr->sub_10059620(a, b, m_n0b8, m_n0bc);
		sub_101b2610();
	}
}
// END FUNCTION

// FUNCTION: 0x10187110 size=0x11
#include "VMapIconButton.h"
namespace lifted {
int sub_101aa640();
}
void VMapIconButton::vfunc85()
{
    int t0 = lifted::sub_101aa640();
    *(char *)((char *)this + 0xc1) = 1;
}
// END FUNCTION

// FUNCTION: 0x10187130 size=0x1e
#include "VMapIconButton.h"
void VMapIconButton::vfunc86() { Panel::vfunc86(); *((char *)this + 0xc1) = 0; *((char *)this + 0xc2) = 0; *(int *)((char *)this + 0xc4) = 0; }
// END FUNCTION

// FUNCTION: 0x10187150 size=0x50
#include "engineclient.h"
#include "VMapIconButton.h"

extern char *g_102d27bc[];
extern char *g_102d27ec[];



void sub_10187fd0();
int sub_10187950();

void VMapIconButton::vfunc87(int arg)
{
	if (*(char *)((char *)this + 0xc0))
		return;
	*(char *)((char *)this + 0xc2) = 1;
	sub_10187fd0();
	if (sub_10187950())
		engine->vfunc27(g_102d27ec[*(int *)((char *)this + 0xd0)], 1);
	else
		engine->vfunc27(g_102d27bc[*(int *)((char *)this + 0xd0)], 1);
}
// END FUNCTION

// FUNCTION: 0x101871a0 size=0x14
#include "VMapIconButton.h"
void VMapIconButton::vfunc89(int a0)
{
    *(int *)((char *)this + 0xc4) = 6;
    *(char *)((char *)this + 0xc2) = 0;
}
// END FUNCTION
