// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "vampire.h"

// FUNCTION: 0x103743c0 size=0x327
#include "CNPC_VDog.h"
#include "CDevFlagObj.h"
#include "engineiface.h"
#include "globalvars.h"

extern CDevFlagObj *g_10924a6c;

#define VDOG_INT(off) (*(int *)((char *)this + (off)))
#define VDOG_IDEAL (*(int *)((char *)this + 0x5cc4))
#define VDOG_FILE "E:\\Vampire\\main\\dlls\\hl2_dll\\NPC_VDog.cpp"
#define VDOG_STAMP(line) { VDOG_INT(0x1b3c) = (int)VDOG_FILE; VDOG_INT(0x1b40) = (line); }
static inline int SetIdeal(volatile int *p, int s) { *p = s; return *p; }
#define VDOG_SET(state, line) { r = SetIdeal(&VDOG_IDEAL, state); VDOG_STAMP(line); return r; }

int CNPC_VDog::vfunc461()
{
	int r;

	VDOG_INT(0x1b38) = 0xd;
	switch (VDOG_INT(0x5cc0))
	{
	case 3:
		if (sub_1001482b(0x44))
			VDOG_SET(8, 0x357);
		if (!sub_1001482b(0x54) && !sub_1001482b(0x46))
		{
			if ((sub_1001482b(0x6a) || sub_1001482b(0x6d) || sub_1001482b(0x6f) || sub_1001482b(0x70)
				|| (*(char (__fastcall **)(CNPC_VDog *))(*(int *)this + 0x738))(this)))
				goto L_check;
			if (sub_1001482b(0x78))
				VDOG_SET(2, 0x36d);
			if (sub_1001482b(0x7c) || sub_1001482b(0x7d))
				VDOG_SET(1, 0x372);
			goto L_check;
		}
		{ r = SetIdeal(&VDOG_IDEAL, 2); VDOG_STAMP(0x35d); if (0) goto L_check; return r; }
	L_check:
		if (sub_103747c0(1))
			return VDOG_INT(0x5cc4);
		break;
	case 1:
		if (sub_1001482b(0x44))
		{
			VDOG_INT(0x1b40) = 0x30f;
			VDOG_IDEAL = 8;
		}
		else if (sub_1001482b(0x54))
		{
			VDOG_INT(0x1b40) = 0x31d;
			VDOG_IDEAL = 2;
		}
		else
		{
			if (sub_1001482b(0x4c) || sub_1001482b(0x4d))
			{
				*(char *)((char *)this + 0x5b80) = 0;
				break;
			}
			if (sub_1001482b(1))
			{
				g_10924a6c->vfunc1();
				sub_100041b0(0x7b);
				return CNPC_VAnimal::vfunc461();
			}
			if (sub_1001482b(0x6a) || sub_1001482b(0x6d) || sub_1001482b(0x6e) || sub_1001482b(0x6f)
				|| sub_1001482b(0x6b) || sub_1001482b(0x70) || sub_1001482b(0x5e))
				break;
			if (sub_1001482b(0x2b))
			{
				VDOG_STAMP(0x347);
				VDOG_IDEAL = 3;
				g_10924a6c->vfunc1();
				sub_100041b0(0x7b);
				int a = VDOG_INT(0x667c);
				EngineGlobals::CGlobalVars *g = gpGlobals;
				int t = *(int *)&g->curtime;
				VDOG_INT(0x6678) = t;
				VDOG_INT(0x6680) = a;
			}
			break;
		}
		VDOG_INT(0x1b3c) = (int)VDOG_FILE;
		if (enginerandom->vfunc2(0, 0x63) < 0x32)
		{
			g_10924a6c->vfunc1();
			sub_100041b0(0x7b);
		}
		return VDOG_INT(0x5cc4);
	}
	return CNPC_VAnimal::vfunc461();
}
// END FUNCTION

// FUNCTION: 0x10374b00 size=0x1fc
#include <math.h>
#include "CNPC_VDog.h"

CBaseEntity *sub_101cda50();	// the local player

// The game's vector length sums the squares as x*x + (y*y + z*z) (z*z is computed first); Vector::Length() in
// Vector.h groups them the other way.
static inline float VectorLength2(const Vector &v)
{
	return FastSqrt(v.x * v.x + (v.y * v.y + v.z * v.z));
}

void CNPC_VDog::vfunc433()
{
	sub_102b27f0();
	if (m_b6660)
		SetCondition(0x7e);
	if (m_n6664 == 6)
		return;
	if (!sub_10014df8(0x6f) && !sub_10014df8(0x5a))
	{
		if (m_Activity == 0x6e)
			SetCondition(0x7c);
		return;
	}
	if (m_n665c != 2)
	{
		if (m_n665c == 0)
		{
			if (m_n6664 == 5)
			{
				m_n665c = 2;
				SetCondition(0x7d);
			}
			else if (m_n6664 == 4)
				m_n665c = 1;
		}
		Vector vecPlayerOrigin = *(Vector *)sub_101cda50()->vfunc220();
		Vector vecMyOrigin = *(Vector *)vfunc220();
		float flDist = fabs(VectorLength2(vecPlayerOrigin - vecMyOrigin));
		if (m_Activity == 0x6e && flDist < m_fl666c)
		{
			if (m_n665c == 0)
				m_n665c = 1;
			if (m_n665c == 1)
				SetCondition(0x78);
		}
		else if (flDist < m_fl6668)
			SetCondition(0x2b);
		else if (flDist >= m_fl6668)
			SetCondition(0x7c);
		m_fl667c = flDist;
	}
	else
		SetCondition(0x7d);
}
// END FUNCTION

// FUNCTION: 0x10374d80 size=0x99
#include "CNPC_VDog.h"

#define VDOG_FILE "E:\\Vampire\\main\\dlls\\hl2_dll\\NPC_VDog.cpp"

int CNPC_VDog::vfunc460()
{
	if (sub_10014df8(0x78) || sub_10014df8(0x7e))
	{
		sub_10374e50();
		return m_IdealState;
	}
	if (sub_10014df8(0x79))
		SetIdealState(NPC_STATE_ALERT, VDOG_FILE, 0x517);
	else if (sub_10014df8(0x7c) && m_IdealState == NPC_STATE_ALERT)
		SetIdealState(NPC_STATE_IDLE, VDOG_FILE, 0x51d);
	return sub_1000cc34();
}
// END FUNCTION

// FUNCTION: 0x10374e50 size=0xb9
#include "CBaseEntity.h"
#include "CNPC_VDog.h"
#include "CBCCSlotViews.h"

class CDogSlotView	// slots 167, 596 and 600 of the dog
{
public:
	VIEW_SLOT100(0)
	VIEW_SLOT10(10) VIEW_SLOT10(11) VIEW_SLOT10(12) VIEW_SLOT10(13) VIEW_SLOT10(14) VIEW_SLOT10(15)
	VIEW_SLOT(160) VIEW_SLOT(161) VIEW_SLOT(162) VIEW_SLOT(163) VIEW_SLOT(164) VIEW_SLOT(165) VIEW_SLOT(166)
	virtual void *vfunc167();
	VIEW_SLOT(168) VIEW_SLOT(169)
	VIEW_SLOT10(17) VIEW_SLOT10(18) VIEW_SLOT10(19)
	VIEW_SLOT100(2) VIEW_SLOT100(3) VIEW_SLOT100(4)
	VIEW_SLOT10(50) VIEW_SLOT10(51) VIEW_SLOT10(52) VIEW_SLOT10(53) VIEW_SLOT10(54) VIEW_SLOT10(55) VIEW_SLOT10(56) VIEW_SLOT10(57) VIEW_SLOT10(58)
	VIEW_SLOT(590) VIEW_SLOT(591) VIEW_SLOT(592) VIEW_SLOT(593) VIEW_SLOT(594) VIEW_SLOT(595)
	virtual void vfunc596(void *pEnt);
	VIEW_SLOT(597) VIEW_SLOT(598) VIEW_SLOT(599)
	virtual void vfunc600(void *p);
};

class CDogThing
{
public:
	void sub_103161a0(void *p);
};

struct CDogHandleEntry
{
	void *m_pEnt;
	int m_serial;
	int m_pad;
};
extern char *g_10566458;

void CNPC_VDog::sub_10374e50()
{
	char *p = (char *)this;
	CDogSlotView *view = (CDogSlotView *)this;
	unsigned int h = *(unsigned int *)(p + 0x628c);
	void *pEnt;
	if (h != 0xffffffff) {
		CDogHandleEntry *e = &((CDogHandleEntry *)(g_10566458 + 4))[h & 0x1fff];
		if (e->m_serial != (int)(h >> 13))
			pEnt = 0;
		else
			pEnt = e->m_pEnt;
	} else {
		pEnt = 0;
	}
	view->vfunc596(pEnt);
	*(const char **)(p + 0x1b3c) = "E:\\Vampire\\main\\dlls\\hl2_dll\\NPC_VDog.cpp";
	*(int *)(p + 0x1b40) = 0x52a;
	*(int *)(p + 0x5cc4) = 2;
	view->vfunc600(view->vfunc167());
	if (*(int *)(p + 0x5bb0) <= 0 && *(int *)(p + 0x5da4) != 0 && view->vfunc167() != 0) {
		CDogThing *pThing = *(int *)(p + 0x5bb0) <= 0 ? *(CDogThing **)(p + 0x5da4) : 0;
		pThing->sub_103161a0(view->vfunc167());
	}
}
// END FUNCTION
