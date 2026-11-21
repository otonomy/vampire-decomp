// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "vampire.h"

// FUNCTION: 0x101404d0 size=0x9
#include "CBaseMoveBehavior.h"
#include "CLogicalEntity.h"

int CBaseMoveBehavior::vfunc117()
{
	return ((CLogicalEntity *)this)->CLogicalEntity::vfunc117() & ~0x200;
}
// END FUNCTION

// FUNCTION: 0x101404f0 size=0x6
#include "CBaseMoveBehavior.h"
#include "datamap.h"
namespace lifted {
extern char g_1057a3fc;
}
datamap_t * CBaseMoveBehavior::vfunc82()
{
    return (datamap_t *)((int)&lifted::g_1057a3fc);
}
// END FUNCTION

// FUNCTION: 0x10140580 size=0x76
#include "CBaseMoveBehavior.h"
#include "CPathKeyFrame.h"
#include "Vector.h"

#define SV(n) virtual void v##n();
#define SV10(p) SV(p##0) SV(p##1) SV(p##2) SV(p##3) SV(p##4) SV(p##5) SV(p##6) SV(p##7) SV(p##8) SV(p##9)

struct SlotMover {
	SV10(0) SV10(1) SV10(2) SV10(3) SV10(4) SV10(5) SV10(6) SV10(7) SV10(8) SV10(9)
	SV10(10) SV10(11) SV10(12) SV10(13) SV10(14) SV10(15) SV10(16) SV10(17) SV10(18) SV10(19)
	SV10(20) SV10(21)
	virtual Vector *v220();
	virtual Vector *v221();
};

// TARGET: CBaseMoveBehavior::vfunc103
void CBaseMoveBehavior::vfunc103()
{
	*(CBaseMoveBehavior **)((char *)this + 0x4a0) = this;
	*(int *)((char *)this + 0x4b0) = 0;
	vfunc93(1, 0);
	Vector *pOrigin = ((SlotMover *)this)->v220();
	*(Vector *)((char *)this + 0x450) = *pOrigin;
	Vector *pAngles = ((SlotMover *)this)->v221();
	*(Vector *)((char *)this + 0x45c) = *pAngles;
	sub_100b3b00();
	CPathKeyFrame::vfunc103();
}
// END FUNCTION

// FUNCTION: 0x10140620 size=0x49
#include "CBaseMoveBehavior.h"
#include <string.h>

#define S10(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); \
	virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();
#define S100(p) S10(p##0) S10(p##1) S10(p##2) S10(p##3) S10(p##4) S10(p##5) S10(p##6) S10(p##7) S10(p##8) S10(p##9)

struct CMoveBehaviorView
{
	S100(a) S100(b)
	S10(c0) S10(c1) S10(c2) S10(c3)
	virtual void d0();
	virtual void vfunc241(int a);
	char m_pad0004[0x3f4 - 4];
	float m_f3f4;
	char m_pad3f8[4];
	float m_f3fc;
	void sub_10140040();	// CPathKeyFrame::vfunc113 (stub 0x10006924)
};

// TARGET: CBaseMoveBehavior::vfunc113
void CBaseMoveBehavior::vfunc113()
{
	CMoveBehaviorView *p = (CMoveBehaviorView *)this;
	p->sub_10140040();
	*(volatile float *)&p->m_f3fc = p->m_f3f4 + 0.5;
	const char *pszClass = *(const char * volatile *)&m_classname11c;
	if (!pszClass)
		pszClass = "";
	if (!_strcmpi(pszClass, "move_keyframed"))
		p->vfunc241(1);
}
// END FUNCTION

// FUNCTION: 0x10140750 size=0xe
#include "CBaseMoveBehavior.h"
int CBaseMoveBehavior::vfunc153()
{
	return m_unk4b4 != 0;
}
// END FUNCTION

// FUNCTION: 0x10140770 size=0x244
#include "CBaseEntity.h"
#include "CBaseMoveBehavior.h"
#include "CEntityVSlots.h"
#include "Vector.h"
// TARGET: CBaseMoveBehavior::vfunc241

struct CMoveBehaviorFields
{
	char m_pad0000[0x450];
	Vector m_vOrigin;	// 0x450
	Vector m_vAngles;	// 0x45c
	char m_pad0468[0x478 - 0x468];
	const char *m_pszNextKey;	// 0x478
	float m_flNextTime;	// 0x47c
	CMoveBehaviorFields *m_pNext;	// 0x480
	CMoveBehaviorFields *m_pPrev;	// 0x484
};

int CBaseMoveBehavior::sub_101402b0(int nIndex)
{
	CMoveBehaviorFields *p = (CMoveBehaviorFields *)this;
	if (nIndex == 1)
		p = p->m_pNext;
	else if (nIndex == -1)
		p = p->m_pPrev;
	return (int)p;
}

int CBaseMoveBehavior::sub_101402f0(int nIndex)
{
	CMoveBehaviorFields *p = (CMoveBehaviorFields *)this;
	if (nIndex == 1)
		p = p->m_pPrev;
	else if (nIndex == -1)
		p = p->m_pNext;
	return (int)p;
}

bool CBaseMoveBehavior::vfunc241(int nDir)
{
	if (nDir == 0)
	{
		((CEntityVSlots *)this)->slot242();
		return false;
	}

	if (m_unk4b4 == nDir)
	{
		if (*(float *)((char *)this + 0x3f4) >= m_flAnimEndTime)
		{
			m_p4a0 = (CBaseMoveBehavior *)m_p4a4;
			m_flTimeIntoFrame = 0.0f;
			if (((CBaseMoveBehavior *)m_p4a4)->sub_101402b0(nDir) == 0)
			{
				m_flAnimEndTime = 0.0f;
				m_fl494 = 0.0f;
				((CEntityVSlots *)this)->slot242();
				return false;
			}
			m_p4a4 = ((CBaseMoveBehavior *)m_p4a4)->sub_101402b0(nDir);
		}
	}
	else
	{
		if (m_unk4b4 != 0)
			((CEntityVSlots *)this)->slot242();

		m_unk4b4 = nDir;

		if (nDir == 1)
		{
			m_p4a4 = ((CBaseMoveBehavior *)m_p4a0)->sub_101402b0(nDir);
		}
		else if (nDir == -1)
		{
			CBaseMoveBehavior *pCur = (CBaseMoveBehavior *)m_p4a0;
			if (m_flTimeIntoFrame > 0.0f)
			{
				m_p4a4 = (int)pCur;
				m_p4a0 = (CBaseMoveBehavior *)pCur->sub_101402b0(1);
			}
			else
			{
				m_p4a4 = pCur->sub_101402f0(1);
			}
		}

		if (m_p4a4 == 0)
		{
			((CEntityVSlots *)this)->slot242();
			return false;
		}

		m_pPostKeyFrame = (CBaseEntity *)((CBaseMoveBehavior *)m_p4a4)->sub_101402b0(nDir);
		if (m_pPostKeyFrame == 0)
			m_pPostKeyFrame = (CBaseEntity *)(CBaseMoveBehavior *)m_p4a4;
		m_pPreKeyFrame = (CBaseEntity *)((CBaseMoveBehavior *)m_p4a0)->sub_101402f0(nDir);
		if (m_pPreKeyFrame == 0)
			m_pPreKeyFrame = (CBaseEntity *)m_p4a0;
	}

	if (m_p4a4 == 0)
		return false;

	float flStart;
	float flNextTime;
	if (m_unk4b4 == 1)
	{
		flStart = *(float *)((char *)this + 0x3f4) - m_flTimeIntoFrame;
		m_fl494 = flStart;
		flNextTime = ((CMoveBehaviorFields *)(void *)m_p4a0)->m_flNextTime;
	}
	else
	{
		if (m_flTimeIntoFrame != 0.0f)
			m_flTimeIntoFrame = ((CMoveBehaviorFields *)(void *)m_p4a4)->m_flNextTime - m_flTimeIntoFrame;
		flStart = *(float *)((char *)this + 0x3f4) - m_flTimeIntoFrame;
		m_fl494 = flStart;
		flNextTime = ((CMoveBehaviorFields *)(void *)m_p4a4)->m_flNextTime;
	}

	float flEndTime = flNextTime + *(float *)((char *)this + 0x3f4) - m_flTimeIntoFrame;
	m_flAnimEndTime = flEndTime;
	float flSpan = *(volatile float *)((char *)this + 0x498) - flStart;
	Vector vecDelta = ((CMoveBehaviorFields *)(void *)m_p4a0)->m_vOrigin -
					  ((CMoveBehaviorFields *)(void *)m_p4a4)->m_vOrigin;
	float flDist = FastSqrt(vecDelta.LengthSqr());
	m_flAverageSpeedAcrossFrame = flSpan / flDist;
	*(float *)((char *)this + 0x3fc) = m_flAnimEndTime;
	return true;
}
// END FUNCTION

// FUNCTION: 0x10140a60 size=0xb7
#include "CBaseMoveBehavior.h"
struct MoveView10140a60 {
	char pad0[0x3f4];
	float m_f3f4;
	char pad1[4];
	int m_n3fc;
	char pad2[0x494 - 0x400];
	float m_f494;
	float m_f498;
	char pad3[4];
	int m_n4a0;
	int m_n4a4;
	char pad4[8];
	float m_f4b0;
	int m_n4b4;
};
extern float g_1070d1b0[3];
extern float g_1070d9d0[3];

void CBaseMoveBehavior::vfunc242()
{
	MoveView10140a60 *p = (MoveView10140a60 *)this;
	p->m_f4b0 = 0;
	if (p->m_n4b4 == 1) {
		if (p->m_f3f4 < p->m_f498) {
			p->m_f4b0 = p->m_f3f4 - p->m_f494;
		} else if (p->m_n4a4 != 0) {
			p->m_n4a0 = p->m_n4a4;
		}
	} else if (p->m_n4b4 == -1) {
		p->m_n4a0 = p->m_n4a4;
		if (p->m_f3f4 < p->m_f498)
			p->m_f4b0 = p->m_f498 - p->m_f3f4;
	}
	p->m_n3fc = 0;
	p->m_n4b4 = 0;
	p->m_f494 = 0;
	p->m_f498 = 0;
	p->m_n4a4 = 0;
	sub_100b2e30(g_1070d1b0);
	sub_100b2f50(g_1070d9d0);
}
// END FUNCTION

// FUNCTION: 0x10140b50 size=0x59
#include "CBaseMoveBehavior.h"
extern "C" int __cdecl _strcmpi(const char *, const char *);
struct CMoveView : public CBaseEntity {
	virtual bool vfunc241(int a);
};
// TARGET: CBaseMoveBehavior::vfunc133
void CBaseMoveBehavior::vfunc133()
{
	CMoveView *p = (CMoveView *)this;
	const char *psz = m_classname11c;
	if (!psz)
		psz = "";
	if (!_strcmpi(psz, "move_keyframed")) {
		int n = m_unk4b4;
		if (!p->vfunc241(n))
			p->vfunc241(-n);
	}
	if (m_pfn0114)
		(this->*m_pfn0114)();
}
// END FUNCTION

// FUNCTION: 0x10140c00 size=0x259
// TARGET: CBaseMoveBehavior::vfunc135

#include "CBaseMoveBehavior.h"
#include "CBaseEntitySlots.h"
#include "CEntityVSlots.h"
#include "Vector.h"
#include "Quaternion.h"

class CInterpolatorView
{
public:
	virtual void v0();
	virtual void v1();
	virtual void slot2(int index, const Vector *pVec);
	virtual void slot3(float flFrac, Vector *pOut);
};

class CPhysicsView
{
public:
	void sub_100b2e30(const float *pVec);
	void sub_100b2f50(const float *pVec);
};

void *sub_1013fdb0(int interpolator);
void Motion_SetKeyAngles(int index, const Vector *pVec);
void sub_101301f0(float flFrac, int interpolator, Quaternion *pOut);
void sub_1013b240(const Quaternion *pIn, Vector *pOut);

float CBaseMoveBehavior::vfunc135(float flFrameTime)
{
	if (!m_p4a0 || !m_p4a4)
		return flFrameTime;
	if (!((CBaseEntitySlots *)this)->slot153())
		return flFrameTime;

	float flTime = flFrameTime + *(float *)((char *)this + 0x3f4) - m_fl494;
	m_flTimeIntoFrame = flTime;
	float flFrac = flTime / (m_flAnimEndTime - m_fl494);

	Vector vecInterp;
	CInterpolatorView *pInterp = (CInterpolatorView *)sub_1013fdb0(m_iPositionInterpolator);
	if (pInterp)
	{
		pInterp->slot2(-1, (const Vector *)((char *)m_pPreKeyFrame + 0x450));
		Motion_SetKeyAngles(-1, (const Vector *)((char *)m_pPreKeyFrame + 0x468));
		pInterp->slot2(0, (const Vector *)((char *)m_p4a0 + 0x450));
		Motion_SetKeyAngles(0, (const Vector *)((char *)m_p4a0 + 0x468));
		pInterp->slot2(1, (const Vector *)((char *)m_p4a4 + 0x450));
		Motion_SetKeyAngles(1, (const Vector *)((char *)m_p4a4 + 0x468));
		pInterp->slot2(2, (const Vector *)((char *)m_pPostKeyFrame + 0x450));
		Motion_SetKeyAngles(2, (const Vector *)((char *)m_pPostKeyFrame + 0x468));
		pInterp->slot3(flFrac, &vecInterp);
	}
	else
	{
		vecInterp.x = 0.0f;
		vecInterp.y = 0.0f;
		vecInterp.z = 0.0f;
	}

	Quaternion qRot;
	sub_101301f0(flFrac, m_iRotationInterpolator, &qRot);
	Vector vecAng;
	sub_1013b240(&qRot, &vecAng);

	float inv = 1.0f / flFrameTime;

	{
		Vector vecVel = (vecInterp - *((CEntityVSlots *)this)->slot220()) * inv;
		((CPhysicsView *)this)->sub_100b2e30((const float *)&vecVel);
	}
	{
		Vector vecVel = (vecAng - *((CEntityVSlots *)this)->slot221()) * inv;
		((CPhysicsView *)this)->sub_100b2f50((const float *)&vecVel);
	}

	return flFrameTime;
}
// END FUNCTION

// FUNCTION: 0x10140f30 size=0x1e
#include "CBaseMoveBehavior.h"

void sub_100aa7b0(void *p);

// TARGET: CBaseMoveBehavior::vfunc5
CBaseEntity *CBaseMoveBehavior::vfunc5(unsigned int flags)
{
	sub_1000cb8a();
	if (flags & 1)
		sub_100aa7b0(this);
	return this;
}
// END FUNCTION
