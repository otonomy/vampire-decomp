// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1016b560 size=0x1c0
#include "VBarterUI.h"
#include "StatOwner2.h"
#include "CHUDSprite.h"
class IVScheme { public: virtual int v0(); virtual void *LoadScheme(const char *); };
IVScheme *sub_101ac8c0();
extern void (*g_101e3108)(const char *pMsg, ...);
extern "C" __declspec(dllimport) char *Q_strncpy(char *, const char *, int);
struct CUnknown1016eea0 { void sub_1016eea0(int); };

#define F(T, off) (*(T *)((char *)this + (off)))

// TARGET: ??0VBarterUI@@QAE@H@Z
VBarterUI::VBarterUI(int a)
	: CHudElement(a), CBasePanel(0, a)
{
	F(char, 0x4d8) = 0;
	void *scheme = sub_101ac8c0()->LoadScheme("Resource/VampireScheme.res");
	if (!scheme)
		g_101e3108("Error loading '%s'\n", "Resource/VampireScheme.res");
	CBasePanel::sub_101aa230(scheme);
	((CUnknown1016eea0 *)(CBasePanel *)this)->sub_1016eea0(0);
	vfunc39(0);
	vfunc54(2);
	F(char, 0x180) = 1;
	int i;
	for (i = 0; i < 0x18; i++)
	{
		m_Slots1[i].b = 0;
		m_Slots1[i].a = 0;
		m_Slots1[i].c = 0;
	}
	for (i = 0; i < 0x20; i++)
	{
		m_Slots2[i].b = 0;
		m_Slots2[i].a = 0;
		m_Slots2[i].c = 0;
	}
	F(int, 0x43c) = 0;
	F(int, 0x438) = 0;
	F(int, 0x440) = 0;
	F(int, 0x428) = 0;
	F(int, 0x44c) = -1;
	F(char, 0x450) = 0;
	F(char, 0x4d0) = 0;
	F(int, 0x4d4) = 0;
	F(char, 0x4d9) = 0;
	F(char, 0x4da) = 0;
	F(CHUDSprite *, 0x4e0) = new CHUDSprite("hud/Barter_Loot/Bart_SelectionFrame", 0, 0, 0x100, 0x200, 0x100, 0x200);
	F(char, 0x4e8) = 0;
	F(int, 0x4e4) = 0;
	F(int, 0x430) = 0;
	F(int, 0x42c) = 0;
	F(int, 0x444) = 0;
	F(int, 0x448) = 0;
	F(char, 0x4db) = 0;
	F(char, 0x181) = 0;
	F(int, 0x184) = -1;
	Q_strncpy((char *)this + 0x4e9, (const char *)g_105f93c0.sub_1015f2f0("UIBarterStrs")->sub_1015ecd0(7), 0x10);
	Q_strncpy((char *)this + 0x4f9, (const char *)g_105f93c0.sub_1015f2f0("UIBarterStrs")->sub_1015ecd0(8), 0x10);
}
// END FUNCTION

// FUNCTION: 0x1016b720 size=0x1e
#include "VBarterUI.h"

// VC6 writes VBarterUI's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
VBarterUI *pcd_emit_1016b720(const VBarterUI &other) { return new VBarterUI(other); }

// TARGET: ??_GVBarterUI@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1016b740 size=0x48
#include "VBarterUI.h"
struct VBarterChild { virtual ~VBarterChild(); };
// TARGET: ??1VBarterUI@@UAE@XZ
VBarterUI::~VBarterUI()
{
    sub_1016cdc0();
    VBarterChild *a = *(VBarterChild **)((char *)this + 0x4e0);
    if (a)
        delete a;
    VBarterChild *b = *(VBarterChild **)((char *)this + 0x4e4);
    if (b)
        delete b;
}
// END FUNCTION

// FUNCTION: 0x1016edf0 size=0xae
#include "VBarterUI.h"

extern int sub_100cd100();
extern int sub_100cd0f0();

namespace lifted {
struct C101a9950 { void sub_101a9950(int x, int y, int w, int h); };
struct C101aa0a0 { void sub_101aa0a0(int z); };
}

#define XRES(x) (x * ((float)sub_100cd100() / 1024.0))
#define YRES(y) (y * ((float)sub_100cd0f0() / 768.0))

// TARGET: VBarterUI::sub_1016edf0
void VBarterUI::sub_1016edf0()
{
	sub_1016cdc0();
	CBasePanel *pPanel = (CBasePanel *)((char *)this + 0x10);
	((lifted::C101a9950 *)pPanel)->sub_101a9950(
		(int)(sub_100cd100() - XRES(1024)),
		0,
		(int)XRES(1024),
		(int)YRES(768)
	);
	pPanel->vfunc54(2);
	((lifted::C101aa0a0 *)pPanel)->sub_101aa0a0(0x76c);
	sub_1016b790();
}
// END FUNCTION
