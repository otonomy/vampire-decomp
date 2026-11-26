// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1005da90 size=0x70
#include "CHudTimerUI.h"
// TARGET: ??0CHudTimerUI@@QAE@H@Z
CHudTimerUI::CHudTimerUI(int parent) : CManagedHudElement(parent, (int)"HudTimer")
{
	sub_1005db50();
	vfunc63(0);
	vfunc64(1);
	m_unk194.v = -1;
	m_unk190 = 0;
	m_unk188 = 0;
	m_unk18c = 0;
	m_unk198 = 0;
}
// END FUNCTION

// FUNCTION: 0x1005db00 size=0x1e
#include "CHudTimerUI.h"

// VC6 writes CHudTimerUI's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CHudTimerUI *pcd_emit_1005db00(const CHudTimerUI &other) { return new CHudTimerUI(other); }

// TARGET: ??_GCHudTimerUI@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1005db20 size=0x22
#include "CHudTimerUI.h"
CHudTimerUI::~CHudTimerUI()
{
	sub_101a9ff0(0);
}
// END FUNCTION

// FUNCTION: 0x1005dc60 size=0x2a8
#include "CHudTimerUI.h"
#include "ehandle.h"
#include "engineclient.h"
#include "CVStatList_t.h"
#include "Tier1.h"

struct CStatOwner_10099880
{
	char m_pad0000[0x1178];
	int m_nLists;
	CVStatList_t **m_pLists;

	CVStatList_t *FindStatList(int type)
	{
		for (int i = 0; i < m_nLists; i++)
		{
			if (m_pLists[i]->m_field10 == type)
				return m_pLists[i];
		}
		static CVStatList_t s_default(-1);
		return &s_default;
	}
};

extern void *g_104a0d50;
extern "C" float sub_100cd9e0(float cur, float target, float dt, float rate);

#define TIMER_ACTIVE (*(bool *)&m_unk18c)
#define TIMER_TARGET (*(CBaseHandle *)&m_unk194)
#define ENT_F(e, off) (*(float *)((char *)(e) + (off)))
#define ENT_I(e, off) (*(int *)((char *)(e) + (off)))

void CHudTimerUI::vfunc98()
{
	CStatOwner_10099880 *pPlayer = (CStatOwner_10099880 *)g_104a0d50;
	if (TIMER_ACTIVE)
	{
		if (!pPlayer)
		{
			TIMER_ACTIVE = false;
			m_unk188 = 0;
			return;
		}
		if (!TIMER_TARGET.Get())
			TIMER_ACTIVE = false;
	}

	if (TIMER_ACTIVE)
		m_unk188 = sub_100cd9e0(m_unk188, 210.0f, engine->vfunc41(1), 105.0f);
	else
		m_unk188 = sub_100cd9e0(m_unk188, 0.0f, engine->vfunc41(1), 105.0f);

	if (!vfunc107())
		return;

	if (TIMER_TARGET.Get())
	{
		void *pTarget = TIMER_TARGET.Get();
		float t;
		if (ENT_I(pTarget, 0x418) == 1)
			t = ENT_F(pTarget, 0x410) - ENT_F(pTarget, 0x414);
		else
			t = ENT_F(pTarget, 0x414);
		m_unk190 = (t > ENT_F(pTarget, 0x410)) ? ENT_F(pTarget, 0x410) : ((t < 0.0f) ? 0.0f : t);
	}

	int secs = (int)m_unk190;
	int mins = secs / 60;
	int rem = secs % 60;
	if (pPlayer)
	{
		int n = pPlayer->FindStatList(3)->sub_1015dbd0(3);
		if (n > 0 && engine->vfunc44() % (n + 1) != 0)
			goto draw;
	}
	m_unk198 = (int)((m_unk190 - secs) * 100.0f);
draw:
	char buf[32];
	g_101e3190(buf, 32, "%02d:%02d:%02d", mins, rem, m_unk198);
	g_pMatSystemSurface->vfunc12(m_unk19c, 0, 0, 255, 0, 0, (int)m_unk188, buf);
}
// END FUNCTION

// FUNCTION: 0x1005df20 size=0x43
#include "CHudTimerUI.h"
struct IUnkG286860 { virtual void v0(); virtual void v1(); virtual bool Check(int); };
extern IUnkG286860 *g_10286860;
bool sub_10163bf0();
// TARGET: ?vfunc107@CHudTimerUI@@UAE_NXZ
bool CHudTimerUI::vfunc107()
{
	if (*(float *)&m_unk188 < 1.0 && !m_unk18c)
		return false;
	return sub_10163bf0() && !g_10286860->Check(0);
}
// END FUNCTION

// FUNCTION: 0x1005df70 size=0x79
#include "CHudTimerUI.h"

extern void *g_102b8e9c;

int sub_101146c0();
int sub_10114660(int, int);

struct PanelV
{
	virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4();
	virtual void vfunc5(int);
};

struct EntityV
{
	virtual void e0();
	virtual int *vfunc1();
};

struct EntListV
{
	void *sub_100d0cf0(int);
};

void CHudTimerUI::vfunc114(int a0, int a1, int a2)
{
	sub_10114660(a2, a1);
	int a = sub_101146c0();
	int b = sub_101146c0();
	PanelV *p = (PanelV *)((char *)this + 0x170);
	if (a & 2)
	{
		p->vfunc5(0);
		return;
	}
	p->vfunc5(1);
	EntityV *e = (EntityV *)((EntListV *)g_102b8e9c)->sub_100d0cf0(b);
	if (e)
		m_unk194.v = *e->vfunc1();
	else
		m_unk194.v = -1;
}
// END FUNCTION
