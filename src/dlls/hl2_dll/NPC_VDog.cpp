// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "vampire.h"

// FUNCTION: 0x103743c0 size=0x327
#include "CNPC_VDog.h"
#include "engineiface.h"
#include "globalvars.h"

#define VDOG_FILE "E:\\Vampire\\main\\dlls\\hl2_dll\\NPC_VDog.cpp"

// MATCH-PENDING steering (R17): the game reloads m_IdealState after each ALERT stamp, which VC6 does when the stamps
// reach one shared `return m_IdealState`, and keeps the 0x35d block ahead of the busy test. The volatile read and
// the dead goto stand in for that structure until it is found. Writing the ALERT stamps as an if / else chain that
// falls into one `return m_IdealState` (the busy test reached by `goto`) gives every byte but one tail merge: VC6
// then merges the 0x36d and 0x35d stamps, which both set NPC_STATE_COMBAT.
static inline int SetIdeal(volatile int *p, int s) { *p = s; return *p; }
#define VDOG_SET(state, line) { r = SetIdeal(&m_IdealState, state); m_pszFile1b3c = VDOG_FILE; m_nLine1b40 = (line); return r; }

int CNPC_VDog::vfunc461()
{
	int r;

	m_n1b38 = 0xd;
	switch (m_NPCState)
	{
	case NPC_STATE_ALERT:
		if (sub_1001482b(0x44))
			VDOG_SET(8, 0x357);
		if (!sub_1001482b(0x54) && !sub_1001482b(0x46))
		{
			// slot 462 is CAI_BaseNPC's; CNPC_VAnimal is declared on CBaseEntity, so the dog reaches it through its
			// real base class
			if (sub_1001482b(0x6a) || sub_1001482b(0x6d) || sub_1001482b(0x6f) || sub_1001482b(0x70)
				|| ((CAI_BaseNPC *)this)->vfunc462())
				goto L_check;
			if (sub_1001482b(0x78))
				VDOG_SET(NPC_STATE_COMBAT, 0x36d);
			if (sub_1001482b(0x7c) || sub_1001482b(0x7d))
				VDOG_SET(NPC_STATE_IDLE, 0x372);
			goto L_check;
		}
		{ r = SetIdeal(&m_IdealState, NPC_STATE_COMBAT); m_pszFile1b3c = VDOG_FILE; m_nLine1b40 = 0x35d; if (0) goto L_check; return r; }
	L_check:
		if (sub_103747c0(1))
			return m_IdealState;
		break;

	case NPC_STATE_IDLE:
		if (sub_1001482b(0x44))
			SetIdealState(8, VDOG_FILE, 0x30f);
		else if (sub_1001482b(0x54))
			SetIdealState(NPC_STATE_COMBAT, VDOG_FILE, 0x31d);
		else
		{
			if (sub_1001482b(0x4c) || sub_1001482b(0x4d))
			{
				m_b5b80 = 0;
				break;
			}
			if (sub_1001482b(1))
			{
				SetCondition(0x7b);
				return CNPC_VAnimal::vfunc461();
			}
			if (sub_1001482b(0x6a) || sub_1001482b(0x6d) || sub_1001482b(0x6e) || sub_1001482b(0x6f)
				|| sub_1001482b(0x6b) || sub_1001482b(0x70) || sub_1001482b(0x5e))
				break;
			if (sub_1001482b(0x2b))
			{
				SetIdealState(NPC_STATE_ALERT, VDOG_FILE, 0x347);
				SetCondition(0x7b);
				m_fl6678 = gpGlobals->curtime;
				m_fl6680 = m_fl667c;
			}
			break;
		}
		if (enginerandom->vfunc2(0, 0x63) < 0x32)
			SetCondition(0x7b);
		return m_IdealState;
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

class CDogSlotView	// slots 596 and 600 of the dog
{
public:
	VIEW_SLOT100(0)
	VIEW_SLOT10(10) VIEW_SLOT10(11) VIEW_SLOT10(12) VIEW_SLOT10(13) VIEW_SLOT10(14) VIEW_SLOT10(15)
	VIEW_SLOT(160) VIEW_SLOT(161) VIEW_SLOT(162) VIEW_SLOT(163) VIEW_SLOT(164) VIEW_SLOT(165) VIEW_SLOT(166)
	VIEW_SLOT(167) VIEW_SLOT(168) VIEW_SLOT(169)
	VIEW_SLOT10(17) VIEW_SLOT10(18) VIEW_SLOT10(19)
	VIEW_SLOT100(2) VIEW_SLOT100(3) VIEW_SLOT100(4)
	VIEW_SLOT10(50) VIEW_SLOT10(51) VIEW_SLOT10(52) VIEW_SLOT10(53) VIEW_SLOT10(54) VIEW_SLOT10(55) VIEW_SLOT10(56) VIEW_SLOT10(57) VIEW_SLOT10(58)
	VIEW_SLOT(590) VIEW_SLOT(591) VIEW_SLOT(592) VIEW_SLOT(593) VIEW_SLOT(594) VIEW_SLOT(595)
	virtual void vfunc596(void *pEnt);
	VIEW_SLOT(597) VIEW_SLOT(598) VIEW_SLOT(599)
	virtual void vfunc600(void *p);
};

#include "CUnknown103160c0.h"

void CNPC_VDog::sub_10374e50()
{
	// The slots 596 and 600 are CAI_BaseNPCTroika's; CNPC_VAnimal is declared on CBaseEntity, so the dog's class
	// does not reach them and this view stands in for the real base until the hierarchy is declared.
	CDogSlotView *view = (CDogSlotView *)this;

	view->vfunc596(m_h628c.Get());
	SetIdealState(NPC_STATE_COMBAT, VDOG_FILE, 0x52a);
	view->vfunc600(vfunc167());
	if (GetSquad() && vfunc167())
		GetSquad()->sub_103161a0((int)vfunc167());
}
// END FUNCTION
