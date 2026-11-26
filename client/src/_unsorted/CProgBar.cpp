// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1005fb20 size=0x1e
#include "CProgBar.h"

// VC6 writes CProgBar's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CProgBar *pcd_emit_1005fb20(const CProgBar &other) { return new CProgBar(other); }

// TARGET: ??_GCProgBar@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1005fc80 size=0x29
#include "CProgBar.h"
CProgBar::~CProgBar()
{
	sub_101a9ff0(0);
	sub_1005fcb0();
}
// END FUNCTION

// FUNCTION: 0x1005fe10 size=0x27
#include "CProgBar.h"
void CProgBar::vfunc112()
{
	m_b17c = 0;
	m_b17d = 0;
	m_b17e = 0;
	m_n178 = 0;
	m_n1a8 = 0;
	m_b1b4 = 0;
}
// END FUNCTION

// FUNCTION: 0x1005ff70 size=0x414
#include "CProgBar.h"
#include "CHUDSprite.h"
#include "engineclient.h"

float sub_100cd9e0(float cur, float target, float dt, float speed);
int sub_100cd100();
int sub_100cd0f0();
extern "C" __declspec(dllimport) int Q_snprintf(char *pDest, int maxLen, const char *pFormat, ...);

struct wrect_1005ff70 { int left; int right; int top; int bottom; };

#define clamp(val, min, max) (((val) > (max)) ? (max) : (((val) < (min)) ? (min) : (val)))
#define XRES(x) ((x) * (sub_100cd100() / 1024.0))
#define YRES(y) ((y) * (sub_100cd0f0() / 768.0))

void CProgBar::vfunc98()
{
	if (!vfunc107())
	{
		sub_1005fcb0();
		return;
	}
	if (!sub_1005fcf0())
		return;
	float frametime = engine->vfunc41(1);
	if (m_b17d && m_fl178 < 255.0f)
	{
		m_fl178 = sub_100cd9e0(m_fl178, 255.0f, frametime, 170.0f);
	}
	else if (m_b17e && m_fl178 > 0.0f)
	{
		if (m_n1ac > 0)
			m_fl178 = sub_100cd9e0(m_fl178, 0, frametime, 51.0f);
		else
			m_fl178 = sub_100cd9e0(m_fl178, 0, frametime, 170.0f);
	}
	else
	{
		m_b17d = 0;
		m_b17e = 0;
	}
	m_fl178 = clamp(m_fl178, 0.0f, 255.0);
	if (!m_b17c && !m_b17d && !m_b17e)
		return;

	int off = m_n1a4 - m_n1a4 * m_n1a8 / 100;
	wrect_1005ff70 rc;
	rc.left = off;
	rc.right = m_n1a4;
	rc.top = 0;
	rc.bottom = 32;
	m_pSprite1bc->sub_1005c430(m_n180, m_n184, (int)(m_n19c - XRES(off)), m_n188, (int)&rc, (int)m_fl178);
	m_pSprite1b8->sub_10059b70(m_n180, m_n184, m_n18c, m_n188, (int)m_fl178);

	char buf[64];
	if (m_b1b4 & 4)
	{
		if (m_b17c)
			Q_snprintf(buf, 64, sub_1005fea0(9), m_n1ac);
		else if (m_b1b4 & 8)
			Q_snprintf(buf, 64, sub_1005fea0(2));
		else if (m_n1b0 > 0)
			Q_snprintf(buf, 64, sub_1005fea0(3));
		else
			Q_snprintf(buf, 64, sub_1005fea0(4));
	}
	else if (m_b1b4 & 0x20)
	{
		if (m_b17c)
			Q_snprintf(buf, 64, sub_1005fea0(5));
		else if (m_b1b4 & 0x40)
			Q_snprintf(buf, 64, sub_1005fea0(6));
		else
			Q_snprintf(buf, 64, sub_1005fea0(4));
	}
	else if (m_b1b4 & 0x80)
	{
		if (m_b17c)
			Q_snprintf(buf, 64, sub_1005fea0(7));
		else
			Q_snprintf(buf, 64, sub_1005fea0(8));
	}

	int y = (int)YRES(4);
	int x = (m_n19c - g_pMatSystemSurface->vfunc15(m_n1c0, buf)) / 2;
	g_pMatSystemSurface->vfunc13(m_n1c0, (int)(x + XRES(2)), (int)(y + YRES(2)), m_n19c, m_n198, 0, 0, 0, (int)m_fl178, buf);
	g_pMatSystemSurface->vfunc13(m_n1c0, x, y, m_n19c, m_n198, 255, 255, 255, (int)m_fl178, buf);
}
// END FUNCTION
