// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10051c60 size=0x9c
#include "CHudAreaIcon.h"
// TARGET: ??0CHudAreaIcon@@QAE@H@Z
CHudAreaIcon::CHudAreaIcon(int a)
    : CManagedHudElement(a, (int)"HudAreaIcon")
{
    m_p178 = 0;
    m_unk194 = 0;
    m_unk198 = 0;
    m_unk17c = -1;
    vfunc63(0);
    vfunc62(0);
    vfunc64(1);
    sub_101a99f0(1);
    m_b190 = true;
    m_unk1b0 = 0;
    m_unk1a8 = 0;
    m_unk1ac = 0;
    m_p19c = 0;
    m_p1a0 = 0;
    m_p1a4 = 0;
    sub_100527c0();
}
// END FUNCTION

// FUNCTION: 0x10051d20 size=0x1e
#include "CHudAreaIcon.h"

// VC6 writes CHudAreaIcon's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CHudAreaIcon *pcd_emit_10051d20(const CHudAreaIcon &other) { return new CHudAreaIcon(other); }

// TARGET: ??_GCHudAreaIcon@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10051d40 size=0x5b
#include "CHudAreaIcon.h"
// TARGET: ??1CHudAreaIcon@@UAE@XZ
CHudAreaIcon::~CHudAreaIcon()
{
	if (m_p178)
		delete m_p178;
	if (m_p19c)
		delete m_p19c;
	if (m_p1a0)
		delete m_p1a0;
	if (m_p1a4)
		delete m_p1a4;
}
// END FUNCTION

// FUNCTION: 0x100524a0 size=0x2ba
#include "CHudAreaIcon.h"
#include "CHUDSprite.h"
#include "ConVar.h"

int sub_100cd100();
int sub_100cd0f0();

#define XRES(x) ((int)((x) * (sub_100cd100() / 1024.0)))
#define YRES(y) ((int)((y) * (sub_100cd0f0() / 768.0)))
#define ANGLE2SHORT(x) ((int)((x) * (65536.0f / 360.0f)) & 65535)
#define SHORT2ANGLE(x) ((x) * (360.0f / 65536.0f))

extern ConVar g_103edee8;
extern ConVar g_103edea0;
extern ConVar g_103ee050;
extern ConVar g_103ee008;

void CHudAreaIcon::vfunc98()
{
	if (!vfunc107())
		return;

	sub_10051df0();

	if (m_p178)
		((CHUDSprite *)m_p178)->sub_10059b70(m_unk188, m_unk18c, m_unk180, m_unk184, (int)m_unk194);

	if (m_p19c && m_p1a0 && m_p1a4)
	{
		int w = XRES(128);
		int h = YRES(128);
		int x = XRES(g_103edee8.GetInt());
		int y = YRES(g_103edea0.GetInt() + 64);
		((CHUDSprite *)m_p19c)->sub_1005b420(x, y, w, h, 255, 255, 255, (int)m_unk1ac,
			SHORT2ANGLE(ANGLE2SHORT(180.0f - m_unk1b0)) * 0.017453292f);

		w = XRES(128);
		h = YRES(128);
		x = XRES(g_103ee050.GetInt());
		y = YRES(g_103ee008.GetInt());
		((CHUDSprite *)m_p1a0)->sub_10059b70(x, y, w, h, (int)m_unk1a8);
		((CHUDSprite *)m_p1a4)->sub_10059b70(x, y, w, h, (int)m_unk1a8);
	}
}
// END FUNCTION

// FUNCTION: 0x10052760 size=0x37
#include "CHudAreaIcon.h"
struct IUnkG286860 { virtual void v0(); virtual void v1(); virtual bool Check(int); };
extern IUnkG286860 *g_10286860;
bool CHudAreaIcon::vfunc107()
{
	if (!sub_100ca9c0())
		return false;
	return sub_10163bf0() && !g_10286860->Check(0);
}
// END FUNCTION
