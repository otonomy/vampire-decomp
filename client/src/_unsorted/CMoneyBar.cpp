// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1005f2a0 size=0x1e
#include "CMoneyBar.h"

// VC6 writes CMoneyBar's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CMoneyBar *pcd_emit_1005f2a0(const CMoneyBar &other) { return new CMoneyBar(other); }

// TARGET: ??_GCMoneyBar@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1005f2c0 size=0x22
#include "CMoneyBar.h"
CMoneyBar::~CMoneyBar()
{
	sub_101a9ff0(0);
}
// END FUNCTION

// FUNCTION: 0x1005f2f0 size=0x23
#include "CMoneyBar.h"
bool sub_10163bf0();
struct IUnkG286860 { virtual void v0(); virtual void v1(); virtual bool Check(int); };
extern IUnkG286860 *g_10286860;
bool CMoneyBar::vfunc107()
{
	return sub_10163bf0() && !g_10286860->Check(0);
}
// END FUNCTION

// FUNCTION: 0x1005f320 size=0x12
#include "CMoneyBar.h"
struct CMoneyBarSub
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5(int a);
};
void CMoneyBar::vfunc112()
{
	((CMoneyBarSub *)((char *)this + 0x170))->v5(0);
}
// END FUNCTION

// FUNCTION: 0x1005f340 size=0x1fc
#include "engineclient.h"
#include "CMoneyBar.h"
#include "Tier1.h"
struct PlayerLike { char pad[0x14c8]; int m_nMoney; };
extern PlayerLike *g_104a0d50;
extern float g_1022a374, g_1022a378;
extern double g_10225160, g_101e58e0, g_10227eb8, g_10226fd0;
extern float g_101e34f0;
float sub_100cd9e0(float a, float b, float c, float d);
int sub_100cd0f0(int, int, int, int, char *);
#define clamp(val, lo, hi) (((val) > (hi)) ? (hi) : (((val) < (lo)) ? (lo) : (val)))
void CMoneyBar::vfunc98()
{
	int x, y, w;
	if (!vfunc107())
		return;
	PlayerLike *pl = g_104a0d50;
	if (!pl)
		return;
	sub_101a98c0(&x, &y);
	float dt = clamp(engine->Time(0) - m_flTime17c, g_101e58e0, g_10225160);
	m_flTime17c = engine->Time(0);
	static float s_flSpeed = g_1022a374 / g_1022a378;
	if (m_b181 && m_flCur178 < g_1022a374)
		m_flCur178 = sub_100cd9e0(m_flCur178, g_1022a374, dt, s_flSpeed);
	else if (m_b182 && m_flCur178 > g_101e34f0)
		m_flCur178 = sub_100cd9e0(m_flCur178, 0, dt, s_flSpeed);
	if (m_b181) {
		char buf[64];
		g_101e3190(buf, 64, "%s $%d", m_szText183, pl->m_nMoney);
		sub_1005f590(m_n1a4, (int)buf, &w);
		g_pMatSystemSurface->vfunc12(m_n1a4, w, (int)((float)sub_100cd0f0(255, 255, 32, 255, buf) * g_10226fd0 * g_10227eb8));
	}
}
// END FUNCTION

// FUNCTION: 0x1005f540 size=0x1
#include "CMoneyBar.h"
void CMoneyBar::vfunc97()
{
}
// END FUNCTION
