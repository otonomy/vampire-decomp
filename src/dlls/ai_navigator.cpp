// Matched functions only. Written by pcdecomp; change it through pcdecomp.
// named by the DLL's own strings
#include "vampire.h"

// FUNCTION: 0x102eca50 size=0x93
#include "CAI_Navigator.h"

struct TObj {
	char m_pad[0x84];
	TObj *sub_1030bec0();
};
void *operator new(unsigned int);

CAI_Navigator::CAI_Navigator(int pOuter) :
	CAI_Component((void *)pOuter),
	m_i54(-1)
{
	TObj *p = (TObj *)operator new(0x84);
	m_p30 = (CAI_NavRoute *)(p ? p->sub_1030bec0() : 0);
	m_pProviders = 0;
	m_b34 = 0;
	m_i38 = 0;
	m_i18 = 0;
	m_b1c = 0;
	m_b50 = 1;
	m_pair58.Set(0.25f);
	m_pair60.Set(3.0f);
	m_i20 = 0;
	m_i24 = 0;
	m_i28 = 0;
}
// END FUNCTION

// FUNCTION: 0x102ecb20 size=0x1e
#include "CAI_Navigator.h"

// TARGET: CAI_Navigator::vfunc0
CAI_Navigator *CAI_Navigator::vfunc0(unsigned int flags)
{
	this->CAI_Navigator::~CAI_Navigator();
	if (flags & 1)
		operator delete(this);
	return this;
}
// END FUNCTION

// FUNCTION: 0x102ecb50 size=0x28
#include "CAI_Navigator.h"

// TARGET: CAI_Navigator::vfunc3
void CAI_Navigator::vfunc3(int a)
{
    char *owner = (char *)m_pOuter;
    m_i20 = *(int *)(owner + 0x5d44);
    m_i24 = *(int *)(owner + 0x5d40);
    m_i28 = *(int *)(owner + 0x5d38);
    m_pProviders = (CAI_NavProviderList *)a;
}
// END FUNCTION

// FUNCTION: 0x102ecb90 size=0x31
void __fastcall sub_1030bf50(void *pThis);
extern int vt_1049d9c4;
extern int vt_1049d994;
extern int vt_1049a0f8;
// TARGET: sub_102ecb90
void __fastcall sub_102ecb90(int *pThis)
{
    int iVar1 = pThis[0xc];
    pThis[0] = (int)&vt_1049d9c4;
    pThis[4] = (int)&vt_1049d994;
    if (iVar1 != 0) {
        sub_1030bf50((void *)iVar1);
        operator delete((void *)iVar1);
    }
    pThis[0] = (int)&vt_1049a0f8;
}
// END FUNCTION

// FUNCTION: 0x102ecbe0 size=0xd
bool sub_102ecbe0(int a)
{
	return a > 1;
}
// END FUNCTION

// FUNCTION: 0x102ecc00 size=0xa
struct CUnknown102ecc00Outer { char p[0x5d3c]; int a; };
struct CUnknown102ecc00 { int v; CUnknown102ecc00Outer *o; int sub_102ecc00(); };
// TARGET: CUnknown102ecc00::sub_102ecc00
int CUnknown102ecc00::sub_102ecc00() { return o->a; }
// END FUNCTION

// FUNCTION: 0x102ecc20 size=0xa
int __fastcall sub_102ecc20(char *self)
{
	return *(int *)(*(char **)(self + 4) + 0x5d3c);
}
// END FUNCTION

// FUNCTION: 0x102ecc40 size=0x60
#include "CAI_BaseNPC.h"
#include "CAI_Navigator.h"
#include "CEHandleGet.h"
void *CAI_Navigator::sub_102ecc40()
{
	int t = sub_102ee620();
	if (t == 2 || sub_102ee620() == 1 || sub_102ee620() == 7)
		return ((CAI_BaseNPC *)m_pOuter)->sub_102729d0();
	return EHandle_Get((unsigned int &)m_p30->m_i30);
}
// END FUNCTION

// FUNCTION: 0x102eccc0 size=0x8
namespace lifted {
struct C100012f3 { int sub_100012f3(); };
}
struct CUnknown102eccc0 { int sub_102eccc0(); };
int CUnknown102eccc0::sub_102eccc0()
{
    return ((lifted::C100012f3 *)(*(int *)((char *)this + 4)))->sub_100012f3();
}
// END FUNCTION

// FUNCTION: 0x102ecce0 size=0xb
#define T(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();
#define H(p) T(p##0) T(p##1) T(p##2) T(p##3) T(p##4) T(p##5) T(p##6) T(p##7) T(p##8) T(p##9)
struct CSlots
{
	H(a) H(b) H(c) H(d) H(e) T(f0)
	virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5();
	virtual void target();
};
struct COwner
{
	int pad;
	CSlots *m_pOuter;
};

void __fastcall sub_102ecce0(COwner *self)
{
	self->m_pOuter->target();
}
// END FUNCTION

// FUNCTION: 0x102ecd00 size=0x10
struct CUnknown102ecd00
{
	char pad_0000[0x4];
	char *m_pSub4;
	void sub_102ecd00(int a);
};

// TARGET: CUnknown102ecd00::sub_102ecd00
void CUnknown102ecd00::sub_102ecd00(int a)
{
	*(int *)(m_pSub4 + 0x164) = a;
}
// END FUNCTION

// FUNCTION: 0x102ecd20 size=0x4bd
#include "CAI_Waypoint.h"
#include "CHL2_Player.h"
#include "CSoundControllerImp.h"
#include "CTriggerProximity.h"
#include "CUnknown102c63b0.h"
#include "CUnknown102c6460.h"
#include "CUnknown102ca630.h"
#include "CUnknown102dc2c0.h"
#include "CEHandleGet.h"
#include "CAI_Navigator.h"
#include "CAI_Network.h"
#include "CAI_Pathfinder.h"
#include "CUnknown102ee270.h"
#include "CUnknown102ee120.h"
#include "CAI_Motor.h"
#include "CEntityVSlots.h"
#include "CBaseEntity.h"

struct AI_NavGoal
{
	int type;		// 0x00
	Vector dest;		// 0x04
	int destNode;		// 0x10
	int activity;		// 0x14
	int arrivalActivity;	// 0x18
	int arrivalSequence;	// 0x1c
	float tolerance;	// 0x20
	unsigned int flags;	// 0x24
	CBaseEntity *pTarget;	// 0x28
	Vector direction;	// 0x2c
	int m38;		// 0x38
	int m3c;		// 0x3c
};

#define NV(a) virtual void v##a();
#define NV10(a) NV(a##0) NV(a##1) NV(a##2) NV(a##3) NV(a##4) NV(a##5) NV(a##6) NV(a##7) NV(a##8) NV(a##9)
#define NV100(a) NV10(a##0) NV10(a##1) NV10(a##2) NV10(a##3) NV10(a##4) NV10(a##5) NV10(a##6) NV10(a##7) NV10(a##8) NV10(a##9)

struct NavNPCView
{
	NV100(0) NV100(1) NV100(2) NV100(3) NV100(4)
	NV10(50) NV10(51) NV10(52) NV10(53) NV10(54) NV10(55) NV10(56) NV10(57)
	NV(580) NV(581) NV(582) NV(583) NV(584) NV(585)
	virtual CBaseHandle v586();
};

struct NavOuterView
{
	char pad[0x98];
	NavNPCView *m_pNPC98;
};

float sub_102d61b0(int hull);

struct NavSelfView : CAI_Navigator
{
	bool sub_102f1dc0(int a, bool b);
	Vector sub_102ee9c0(int node);
};

struct NavRouteView : CAI_NavRoute
{
	void sub_1030b950(const Vector &vecGoal);
};

struct NavNetworkView : CAI_NavProviderList
{
	int NearestNodeToNPC(int pOuter) { return sub_102f3c10(pOuter, ((CEntityVSlots *)pOuter)->slot217()); }
};

static inline float HullWidth(int hull) { return sub_102d61b0(hull); }
static inline CBaseEntity *LookupHandle(const unsigned int *pHandle) { return g_10566458->sub_100290c0(pHandle); }

extern Vector g_1070d1b0;
extern Vector g_1093404c;
extern Vector g_10934060;
extern CBaseEntity *g_10934058;
extern const float g_1049d980;
extern const float g_1049d97c;
extern const float g_104454c4;

bool CAI_Navigator::sub_102ecd20(void *pGoal, int nFlags)
{
	const AI_NavGoal &goal = *(const AI_NavGoal *)pGoal;

	m_n08 = *(int *)((int)m_pOuter + 0x156c);
	m_n0c = gpGlobals->framecount;
	CAI_Component *pPathfinder = (CAI_Component *)sub_102ecc00();
	pPathfinder->m_n08 = *(int *)((int)pPathfinder->m_pOuter + 0x156c);
	pPathfinder->m_n0c = gpGlobals->framecount;

	CAI_NavRoute *pPath = m_p30;
	vfunc7();

	if (nFlags & 1)
		((CUnknown102ee270 *)this)->sub_102f28a0();
	else if (nFlags & 2)
	{
		*(CBaseHandle *)&pPath->m_i30 = (IHandleEntity *)0;
		*(Vector *)&pPath->m_v34 = g_1070d1b0;
	}

	if (goal.activity != -1)
		((CUnknown102ee120 *)this)->sub_102ee250(goal.activity);

	if (goal.tolerance == g_1049d980)
		pPath->SetGoalTolerance(HullWidth(m_n08));
	else if (goal.tolerance != g_1049d97c)
		pPath->SetGoalTolerance(goal.tolerance);
	else if (pPath->m_fl28 == g_104454c4)
	{
		pPath->SetGoalTolerance(HullWidth(m_n08));
		CBaseEntity *pTarget = 0;
		if (goal.type == 1 || goal.type == 2 || goal.type == 7)
		{
			if (goal.type == 1)
				pTarget = LookupHandle((const unsigned int *)((int)m_pOuter + 0x5ce4));
			else if (goal.type == 2)
				pTarget = (CBaseEntity *)((CEntityVSlots *)m_pOuter)->slot167();
			else
				pTarget = (CBaseEntity *)((NavOuterView *)m_pOuter)->m_pNPC98->v586().Get();
		}
		if (pTarget && pTarget->m_p9c)
			pPath->SetGoalTolerance((HullWidth(m_n08) + HullWidth(*(int *)((char *)pTarget->m_p9c + 0x1568))) * 0.5);
	}

	pPath->m_fl40 = HullWidth(m_n08) * 0.5;

	if (goal.direction != g_10934060)
		pPath->sub_1030be20((const int *)&goal.direction);
	pPath->m_i08 = goal.m38;
	pPath->m_i04 = goal.m3c;

	if (goal.flags & 2)
	{
		int startNode = ((NavNetworkView *)m_pProviders)->NearestNodeToNPC((int)m_pOuter);
		if (startNode == -1)
			return false;
		int endNode = ((CAI_Network *)m_pProviders)->sub_102f41b0(&goal.dest);
		if (endNode == -1)
			return false;
		CAI_Waypoint *pWaypoints = ((CAI_Pathfinder *)sub_102ecc00())->sub_102fd240(startNode, endNode);
		if (!pWaypoints)
			return false;
		pPath->sub_1030ba50(4);
		pPath->sub_1030b4d0((int)pWaypoints, 0);
		pPath->sub_1030b8e0();
		return true;
	}

	pPath->sub_1030ba50(goal.type);
	pPath->m_i60 = goal.flags;
	CBaseEntity *pTarget = goal.pTarget;
	if (goal.type == 1 || goal.type == 2 || goal.type == 7)
	{
		if (goal.type == 1)
			pTarget = ((EHANDLE *)((int)m_pOuter + 0x5ce4))->Get();
		else if (goal.type == 2)
			pTarget = (CBaseEntity *)((CEntityVSlots *)m_pOuter)->slot167();
		else
			pTarget = (CBaseEntity *)((NavOuterView *)m_pOuter)->m_pNPC98->v586().Get();
		if (goal.dest != g_1093404c)
			*(Vector *)&pPath->m_v34 = goal.dest;
	}
	else
	{
		if (goal.dest != g_1093404c)
			((NavRouteView *)pPath)->sub_1030b950(goal.dest);
		else if (goal.destNode != -1)
			((NavRouteView *)pPath)->sub_1030b950(((NavSelfView *)this)->sub_102ee9c0(goal.destNode));
	}

	if (pTarget > g_10934058)
		((EHANDLE *)&pPath->m_i30)->Set(pTarget);

	bool bResult = (goal.flags >> 3) & 1;
	bResult = ((NavSelfView *)this)->sub_102f1dc0(1, bResult);
	if (!bResult)
	{
		if (nFlags & 4)
			((CUnknown102ee270 *)this)->sub_102f28a0();
	}
	else
	{
		if (goal.flags & 1)
		{
			sub_102e0b40((float *)m_i20);
			CAI_Motor *pMotor = (CAI_Motor *)m_i20;
			pMotor->sub_102e2020((const float *)pPath->sub_1030ba30(), 0);
		}
		sub_102f13d0(1);
		if (goal.arrivalActivity != -1)
			pPath->sub_1030b550(goal.arrivalActivity);
		else if (goal.arrivalSequence != -1)
			pPath->sub_1030b5b0(goal.arrivalSequence);
		else
			pPath->sub_1030b550(1);
	}
	return bResult;
}
// END FUNCTION

// FUNCTION: 0x102ed310 size=0x5a
#include "CAI_Navigator.h"
#include "CBaseEntity.h"
void CAI_Navigator::sub_102ed310(CBaseEntity *pEnt, const Vector *pPosition)
{
	vfunc7();
	CAI_NavRoute *pRoute = m_p30;
	pRoute->m_v34.x = pPosition->x;
	pRoute->m_v34.y = pPosition->y;
	pRoute->m_v34.z = pPosition->z;
	*(EHANDLE *)&pRoute->m_i30 = pEnt;
	sub_102f1dc0(0, 0);
}
// END FUNCTION

// FUNCTION: 0x102ed390 size=0x77
#include "CAI_Navigator.h"

#define OV(n) virtual void v##n();
#define OV10(p) OV(p##0) OV(p##1) OV(p##2) OV(p##3) OV(p##4) OV(p##5) OV(p##6) OV(p##7) OV(p##8) OV(p##9)
struct CNavOwner {
	OV(0) OV(1) OV(2) OV(3) OV(4) OV(5) OV(6) OV(7) OV(8) OV(9)
	OV10(1) OV10(2) OV10(3) OV10(4) OV10(5) OV10(6) OV10(7) OV10(8) OV10(9)
	OV10(10) OV10(11) OV10(12) OV10(13) OV10(14) OV10(15) OV10(16) OV10(17) OV10(18) OV10(19)
	OV10(20) OV10(21)
	virtual const int *v220();	// GetLocalOrigin
};

struct CNavOwnerData {	// the pathfinder
	int sub_10304670(const int *origin, int center, int radius, int arc, int stepDist, int bClockwise, float goalTolerance, int a6, int a7);	// BuildRadialRoute, stub 0x1000dcc9
};

struct CNavRouteTol : CAI_NavRoute {
	float GetGoalTolerance() const { return m_fl28; }
};
// TARGET: CAI_Navigator::sub_102ed390
void CAI_Navigator::sub_102ed390(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	vfunc7();
	m_p30->sub_1030ba50(4);
	CAI_NavRoute *pPath = m_p30;
	pPath->sub_1030b4d0(((CNavOwnerData *)sub_102ecc00())->sub_10304670(((CNavOwner *)m_pOuter)->v220(), a1, a2, a3, a4, a5, ((CNavRouteTol *)pPath)->GetGoalTolerance(), a6, a7), true);
	sub_102ee6a0();
}
// END FUNCTION

// FUNCTION: 0x102ed430 size=0xc7
#include "CAI_Navigator.h"

struct S_PF { void *sub_102ff3e0(int idx, int a, int b); };
struct S_Route {
    void sub_1030b4d0(void *p, int a);
    void sub_1030b8e0();
    const Vector *sub_1030b990();
};

// TARGET: CAI_Navigator::sub_102ed430
bool CAI_Navigator::sub_102ed430(const Vector *pPosition, int a, int b, int c)
{
    vfunc7();
    CAI_NavProviderList *pList = m_pProviders;
    if (pList->m_nCount <= 0)
        return false;
    m_n08 = *(int *)((int)m_pOuter + 0x156c);
    m_n0c = gpGlobals->framecount;
    int idx = pList->sub_102f3c10((int)m_pOuter, pPosition);
    if (idx == -1)
        return false;
    void *p = ((S_PF *)sub_102ecc00())->sub_102ff3e0(idx, a, b);
    if (!p)
        return false;
    m_p30->sub_1030ba50(4);
    ((S_Route *)m_p30)->sub_1030b4d0(p, 0);
    ((S_Route *)m_p30)->sub_1030b8e0();
    const Vector *v = ((S_Route *)m_p30)->sub_1030b990();
    float dx = pPosition->x - v->x;
    float dy = pPosition->y - v->y;
    float dz = pPosition->z - v->z;
    *(float *)&m_i14 = dx * dx + dy * dy + dz * dz;
    return true;
}
// END FUNCTION

// FUNCTION: 0x102ed540 size=0x9b
#include "CAI_Navigator.h"

struct IRandomStream
{
	virtual void v0();
	virtual float RandomFloat(float flMin, float flMax);
};

extern IRandomStream *g_1070b244;
extern Vector g_1070d1b0;
Vector sub_101d2f40(float yaw);

struct CNavV : CAI_Navigator
{
	bool sub_102ed540(float minRadius, float maxRadius, bool c);
	bool sub_102ed610(const Vector *pDir, float flDist, float flMax, bool c);
	bool sub_102ed940(float f, const Vector *pVec, bool c);
};

// TARGET: sub_102ed540
bool CNavV::sub_102ed540(float minRadius, float maxRadius, bool c)
{
	for ( int i = 0; i < 5; i++ )
	{
		float dist = g_1070b244->RandomFloat( minRadius, maxRadius );
		Vector dir = sub_101d2f40( g_1070b244->RandomFloat( 0, 359.99 ) );

		if ( sub_102ed610( &dir, dist, minRadius, c ) )
			return true;
	}

	return sub_102ed940( 1, &g_1070d1b0, c );
}
// END FUNCTION

// FUNCTION: 0x102ed610 size=0x191
#include "utlmemory.h"
#include "CAI_MoveProbe.h"
#include "CEntityVSlots.h"
#include "CAI_Navigator.h"

extern int g_10934058;
extern Vector g_10934060;
extern const float g_1049d97c;	// AIN_DEF_TOLERANCE (-1.0f)

struct CAI_NavGoalRecord
{
	CAI_NavGoalRecord(int iType, const Vector &dest, int act = -1, float flTolerance = g_1049d97c, int iFlags = 0)
		: m_iType(iType),
		  m_vecDest(dest),
		  m_iNode(-1),
		  m_hTarget(-1),
		  m_iSeq(-1),
		  m_iAct(act),
		  m_flSpeed(flTolerance),
		  m_flTolerance(iFlags),
		  m_hParam(g_10934058),
		  m_vecOrg(g_10934060),
		  m_i38(0),
		  m_i3c(0)
	{
	}
	int m_iType;
	Vector m_vecDest;
	int m_iNode;
	int m_hTarget;
	int m_iSeq;
	int m_iAct;
	float m_flSpeed;
	int m_flTolerance;
	int m_hParam;
	Vector m_vecOrg;
	int m_i38;
	int m_i3c;
};

bool CAI_Navigator::sub_102ed610(const Vector *pDir, float flDist, float flMax, int c)
{
	AIMoveTrace_t trace;
	Vector vecScaled = *pDir * flDist;
	Vector vecEnd(vecScaled + *((CEntityVSlots *)m_pOuter)->slot220());
	int navType = m_i18;
	CAI_MoveProbe *pProbe = (CAI_MoveProbe *)m_i24;

	pProbe->sub_102e6d70(navType, ((CEntityVSlots *)m_pOuter)->slot220()->Base(), vecEnd.Base(), 0x2400b, 0, 100.0f, 0, &trace, c, 0);

	if (trace.fStatus != 0 && !((flDist - trace.m_fields.f24) > flMax))
		return false;

	return sub_102ecd20(&CAI_NavGoalRecord(4, *(Vector *)&trace.m_fields.e0), 0);
}
// END FUNCTION

// FUNCTION: 0x102ed820 size=0xe0
#include "CEntitySoundOriginView.h"

class Vector2D
{
public:
	float x, y;
	float Length() const;
	Vector2D &operator/=(float fl);
};

inline float Vector2DLength(Vector2D const &v)
{
	return (float)FastSqrt(v.x * v.x + v.y * v.y);
}

inline float Vector2D::Length() const
{
	return Vector2DLength(*this);
}

inline Vector2D &Vector2D::operator/=(float fl)
{
	float oofl = 1.0f / fl;
	x *= oofl;
	y *= oofl;
	return *this;
}

inline float Vector2DNormalize(Vector2D &v)
{
	float l = v.Length();
	if (l != 0.0f)
	{
		v /= l;
	}
	else
	{
		v.x = v.y = 0.0f;
	}
	return l;
}

inline float ComputePathDirection(int navType, const Vector &start, const Vector &end, Vector *pDirection)
{
	if (navType == 0)
	{
		VectorSubtract(end, start, *pDirection);
		pDirection->z = 0.0f;
		return Vector2DNormalize(*(Vector2D *)pDirection);
	}
	else
	{
		VectorSubtract(end, start, *pDirection);
		return VectorNormalize(*pDirection);
	}
}

struct CNavView {
	int m_0;
	CEntitySoundOriginView *m_pOwner;
	char m_pad[0x10];
	int m_nFlag;
	int GetNavType() { return m_nFlag; }
	const Vector &GetLocalOrigin() { return *(const Vector *)m_pOwner->GetOrigin(); }
	bool sub_102ed610(const Vector &v, float len, float a, bool b);
	bool sub_102ed820(const Vector &goalPos, float minDist, bool fShouldDeflect);
};

bool CNavView::sub_102ed820(const Vector &goalPos, float minDist, bool fShouldDeflect)
{
	Vector vDir = goalPos;
	float dist = ComputePathDirection(GetNavType(), GetLocalOrigin(), goalPos, &vDir);
	return sub_102ed610(vDir, dist, minDist, fShouldDeflect);
}
// END FUNCTION

// FUNCTION: 0x102ed940 size=0x60
#include "CAI_Navigator.h"
#include "CAI_BaseNPC.h"
bool CAI_Navigator::sub_102ed940(float f, const Vector *pVec, int c)
{
	m_n08 = *(int *)((int)m_pOuter + 0x156c);
	m_n0c = *(int *)(((int *)gpGlobals) + 1);
	CAI_Component *p = (CAI_Component *)sub_102ecc00();
	p->m_n08 = *(int *)((int)p->m_pOuter + 0x156c);
	p->m_n0c = *(int *)(((int *)gpGlobals) + 1);
	return sub_102ed430((const Vector *)((CAI_BaseNPC *)m_pOuter)->vfunc220(), *(int *)&f, (int)pVec, c);
}
// END FUNCTION

// FUNCTION: 0x102ed9c0 size=0xa6
#include "CAI_Navigator.h"


struct CAI_PathfinderView
{
	int m_pVtable;
	int m_pOuter;
	int m_n08;
	int m_n0c;

	int sub_10302e50(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};


bool CAI_Navigator::sub_102ed9c0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, Vector *pOut)
{
	m_n08 = *(int *)((int)m_pOuter + 0x156c);
	m_n0c = gpGlobals->framecount;
	CAI_PathfinderView *pPathfinder = (CAI_PathfinderView *)sub_102ecc00();
	pPathfinder->m_n08 = *(int *)((int)pPathfinder->m_pOuter + 0x156c);
	pPathfinder->m_n0c = gpGlobals->framecount;
	int node = ((CAI_PathfinderView *)sub_102ecc00())->sub_10302e50(a1, a2, a3, a4, a5, a6, a7);
	if (node == -1)
		return false;
	Vector vecPos;
	Vector *pNode = sub_102ee9c0(&vecPos, node);
	pOut->x = pNode->x;
	pOut->y = pNode->y;
	pOut->z = pNode->z;
	return true;
}
// END FUNCTION

// FUNCTION: 0x102edaa0 size=0x30
namespace lifted {
extern char g_1070d1b0;
struct C10015901 { int sub_10015901(int, int, int, int, int, int, int, int); };
}
struct CUnknown102edaa0 { int sub_102edaa0(int, int, int, int, int, int, int); };
int CUnknown102edaa0::sub_102edaa0(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    return ((lifted::C10015901 *)this)->sub_10015901(a0, a1, a2, a3, a4, (int)&lifted::g_1070d1b0, a5, a6);
}
// END FUNCTION

// FUNCTION: 0x102edae0 size=0x92
#include "CUnknown103008f0.h"



// TARGET: CAI_Navigator::sub_102edae0
bool CAI_Navigator::sub_102edae0(const Vector *pPosition, float flDistance, int c, Vector *pOut)
{
	m_n08 = *(int *)((int)m_pOuter + 0x156c);
	m_n0c = gpGlobals->framecount;
	CUnknown103008f0 *pFinder = (CUnknown103008f0 *)sub_102ecc00();
	pFinder->m_n08 = *(int *)((int)pFinder->m_pOuter + 0x156c);
	pFinder->m_n0c = gpGlobals->framecount;
	int nNode = ((CUnknown103008f0 *)sub_102ecc00())->sub_103008f0(pPosition, flDistance, c);
	if (nNode == -1)
		return false;
	Vector position;
	*pOut = *sub_102ee9c0(&position, nNode);
	return true;
}
// END FUNCTION

// FUNCTION: 0x102edbb0 size=0x92
#include "CUnknown103008f0.h"



// TARGET: CAI_Navigator::sub_102edbb0
bool CAI_Navigator::sub_102edbb0(const Vector *pPosition, float flDistance, int c, Vector *pOut)
{
	m_n08 = *(int *)((int)m_pOuter + 0x156c);
	m_n0c = gpGlobals->framecount;
	CUnknown103008f0 *pFinder = (CUnknown103008f0 *)sub_102ecc00();
	pFinder->m_n08 = *(int *)((int)pFinder->m_pOuter + 0x156c);
	pFinder->m_n0c = gpGlobals->framecount;
	int nNode = ((CUnknown103008f0 *)sub_102ecc00())->sub_10301010(pPosition, flDistance, c);
	if (nNode == -1)
		return false;
	Vector position;
	*pOut = *sub_102ee9c0(&position, nNode);
	return true;
}
// END FUNCTION

// FUNCTION: 0x102edc80 size=0x9c
#include "CUnknown103008f0.h"



bool CAI_Navigator::sub_102edc80(const Vector *pPosition, float flDistance, int c, int d, Vector *pOut, int e)
{
	m_n08 = *(int *)((int)m_pOuter + 0x156c);
	m_n0c = gpGlobals->framecount;
	CUnknown103008f0 *pFinder = (CUnknown103008f0 *)sub_102ecc00();
	pFinder->m_n08 = *(int *)((int)pFinder->m_pOuter + 0x156c);
	pFinder->m_n0c = gpGlobals->framecount;
	int nNode = ((CUnknown103008f0 *)sub_102ecc00())->sub_10301720(pPosition, flDistance, c, d, e);
	if (nNode == -1)
		return false;
	Vector position;
	*pOut = *sub_102ee9c0(&position, nNode);
	return true;
}
// END FUNCTION

// FUNCTION: 0x102edd50 size=0xa1
#include "CUnknown103008f0.h"



// TARGET: CAI_Navigator::sub_102edd50
bool CAI_Navigator::sub_102edd50(const Vector *pPosition, float flDistance, int c, int d, int e, Vector *pOut, int f)
{
	m_n08 = *(int *)((int)m_pOuter + 0x156c);
	m_n0c = gpGlobals->framecount;
	CUnknown103008f0 *pFinder = (CUnknown103008f0 *)sub_102ecc00();
	pFinder->m_n08 = *(int *)((int)pFinder->m_pOuter + 0x156c);
	pFinder->m_n0c = gpGlobals->framecount;
	int nNode = ((CUnknown103008f0 *)sub_102ecc00())->sub_10302320(pPosition, flDistance, c, d, e, f);
	if (nNode == -1)
		return false;
	Vector position;
	*pOut = *sub_102ee9c0(&position, nNode);
	return true;
}
// END FUNCTION

// FUNCTION: 0x102ede30 size=0x245
#include "CAI_Waypoint.h"
#include "CAI_Navigator.h"
#include "CAI_Pathfinder.h"
#include "CVProfile.h"
#include "CBasePlayer.h"
#include "CUnknown102ee120.h"

__declspec(dllimport) void vtune(bool bEnable);

struct CCycleCountX
{
	unsigned __int64 m_Int64;
	void Sample()
	{
		unsigned long *pSample = (unsigned long *)&m_Int64;
		__asm {
			mov ecx, pSample
			rdtsc
			mov [ecx], eax
			mov [ecx+4], edx
		}
	}
	void End()
	{
		CCycleCountX cnt;
		cnt.m_Int64 = 0;
		cnt.Sample();
		m_Int64 = cnt.m_Int64 - m_Int64;
	}
	void operator+=(CCycleCountX &other) { m_Int64 += other.m_Int64; }
};

inline bool NavNodeExitFull(CVProfNode *node)
{
	if (--node->m_nRecursions == 0 && node->m_nCurFrameCalls != 0) {
		((CCycleCountX *)&node->m_CurFrameTime)->End();
		*(CCycleCountX *)&node->m_TotalTime += *(CCycleCountX *)&node->m_CurFrameTime;
		CVProfile *q = g_109f3648;
		int d = --q->m_nGroupStackDepth;
		int cur = q->m_GroupIDStack[d + 1];
		int prev = q->m_GroupIDStack[d];
		if (prev != cur && q->m_bVTuneGroupsEnabled && cur == q->m_nVTuneGroupID)
			vtune(false);
	}
	return node->m_nRecursions == 0;
}

bool CAI_Navigator::sub_102ede30(int a, int b)
{
	CVProfile *p = g_109f3648;
	const char *pszName = "CAI_Navigator_PrependLocalAvoidance";
	if (p->m_enabled || !p->m_bAtRoot) {
		if (p->m_pCurNode->m_pszName != pszName)
			p->m_pCurNode = p->m_pCurNode->GetSubNode(pszName, 0, "Unaccounted");
		p->m_pCurNode->EnterScope();
		p->m_bAtRoot = false;
	}
	int i18 = m_i18;
	float *pOrigin = ((CBasePlayer *)m_pOuter)->vfunc220();
	CAI_Waypoint *pWaypoint = ((CAI_Pathfinder *)sub_102ecc00())->sub_10304020((int)pOrigin, (const float *)((CUnknown102ee120 *)this)->sub_102ee5e0(), (int)sub_102ecc40(), 1, -1, 0, a, i18, 0x202400b, b);
	if (!pWaypoint) {
		g_109f3648->ExitScopeInlined();
		return false;
	}
	CAI_NavRoute *pRoute = m_p30;
	bool r = ((CUnknown10319f70 *)&pRoute->m_pWaypoint)->sub_10319f30(pWaypoint);
	CVProfile *q = g_109f3648;
	if (!q->m_bAtRoot || q->m_enabled) {
		if (NavNodeExitFull(q->m_pCurNode))
			q->m_pCurNode = q->m_pCurNode->m_pParent;
		q->m_bAtRoot = (q->m_pCurNode == q->m_pRoot);
	}
	return r;
}
// END FUNCTION

// FUNCTION: 0x102ee120 size=0xb
#include "CUnknown102ee120.h"
void CUnknown102ee120::sub_102ee120(int a, int b, int c)
{
	m_unk30->m_unk24.sub_10319f70(a, b, c);
}
// END FUNCTION

// FUNCTION: 0x102ee140 size=0x8
namespace lifted {
struct C1000f89e { int sub_1000f89e(); };
}
struct CUnknown102ee140 { int sub_102ee140(); };
int CUnknown102ee140::sub_102ee140()
{
    return ((lifted::C1000f89e *)(*(int *)((char *)this + 0x30)))->sub_1000f89e();
}
// END FUNCTION

// FUNCTION: 0x102ee160 size=0x30
#include "CUnknown102ee120.h"
#include "CBaseEntity.h"
CBaseEntity *CUnknown102ee120::sub_102ee160()
{
	return m_unk30->m_hTarget30.Get();
}
// END FUNCTION

// FUNCTION: 0x102ee1a0 size=0x7
struct CUnknown102ee1a0 { float sub_102ee1a0(); };
float CUnknown102ee1a0::sub_102ee1a0()
{
    return *(float *)((char *)(*(int *)((char *)this + 0x30)) + 0x28);
}
// END FUNCTION

// FUNCTION: 0x102ee1c0 size=0xd
#include "CUnknown102ee120.h"
void CUnknown102ee120::sub_102ee1c0(int value)
{
	m_unk30->m_unk28 = value;
}
// END FUNCTION

// FUNCTION: 0x102ee1e0 size=0xf
namespace lifted {
int __stdcall sub_1000b2ee(int, int);
}
int __stdcall sub_102ee1e0(int a0)
{
    return lifted::sub_1000b2ee(a0, 0);
}
// END FUNCTION

// FUNCTION: 0x102ee200 size=0xa
namespace lifted {
int __stdcall sub_1000b2ee(int, int);
}
int sub_102ee200()
{
    return lifted::sub_1000b2ee(0, 0);
}
// END FUNCTION

// FUNCTION: 0x102ee220 size=0x1f
#include "CAI_Navigator.h"

struct CUnk102ee220Route
{
    void sub_1030b950(const Vector *pPosition);
};

// TARGET: CAI_Navigator::sub_102ee220
void CAI_Navigator::sub_102ee220(const Vector *pPosition)
{
    ((CUnk102ee220Route *)m_p30)->sub_1030b950(pPosition);
    sub_102f1dc0(0, 0);
}
// END FUNCTION

// FUNCTION: 0x102ee250 size=0xd
#include "CUnknown102ee120.h"
// CAI_Navigator::SetMovementActivity (2003 SDK ai_navigator.cpp): returns GetPath()->SetMovementActivity(activity),
// the path's inline `return (m_activity = activity);` (+0x2c). The returned value is why the activity is in eax.
struct CUnknown102ee120V : CUnknown102ee120
{
	int sub_102ee250(int activity);
};
int CUnknown102ee120V::sub_102ee250(int activity)
{
	return m_unk30->m_unk2c = activity;
}
// END FUNCTION

// FUNCTION: 0x102ee270 size=0x13
#include "CUnknown102ee270.h"

char CUnknown102ee270::sub_102ee270()
{
	sub_102f28a0();
	vfunc7();
	return 1;
}
// END FUNCTION

// FUNCTION: 0x102ee2a0 size=0x8
namespace lifted {
struct C100117c0 { int sub_100117c0(); };
}
struct CUnknown102ee2a0 { int sub_102ee2a0(); };
int CUnknown102ee2a0::sub_102ee2a0()
{
    return ((lifted::C100117c0 *)(*(int *)((char *)this + 0x30)))->sub_100117c0();
}
// END FUNCTION

// FUNCTION: 0x102ee2c0 size=0x8
namespace lifted {
struct C1000b5a5 { int sub_1000b5a5(); };
}
struct CUnknown102ee2c0 { int sub_102ee2c0(); };
int CUnknown102ee2c0::sub_102ee2c0()
{
    return ((lifted::C1000b5a5 *)(*(int *)((char *)this + 0x30)))->sub_1000b5a5();
}
// END FUNCTION

// FUNCTION: 0x102ee2e0 size=0x7
struct CUnknown102ee2e0 { char sub_102ee2e0(); };
char CUnknown102ee2e0::sub_102ee2e0()
{
    return *(char *)((char *)(*(int *)((char *)this + 0x30)) + 0x10);
}
// END FUNCTION

// FUNCTION: 0x102ee300 size=0x5c
#include "CAI_Navigator.h"
#include "CAI_Pathfinder.h"

namespace block_102ee300 {
	struct CNavUnit : CAI_Navigator { int sub_102ecc00(); };
	int CNavUnit::sub_102ecc00() { return *(int *)(*(int *)((char *)this + 4) + 0x5d3c); }
}
using namespace block_102ee300;

void CAI_Navigator::sub_102ee300(int a, int b, int c, int d, int e)
{
	m_n08 = *(int *)((int)m_pOuter + 0x156c);
	m_n0c = gpGlobals->framecount;
	CAI_Pathfinder *p = (CAI_Pathfinder *)((CNavUnit *)this)->sub_102ecc00();
	p->m_n08 = *(int *)((char *)p->m_pOuter + 0x156c);
	p->m_n0c = gpGlobals->framecount;
	((CAI_Pathfinder *)((CNavUnit *)this)->sub_102ecc00())->sub_10300140(a, b, c, d, e);
}
// END FUNCTION

// FUNCTION: 0x102ee380 size=0x4d
#include "CAI_Navigator.h"
struct CAI_PathfinderView { void sub_102fdcc0(int a, int b); };
namespace block_102ee380 {
struct CAI_NavigatorUnit : CAI_Navigator { int sub_102ecc00(); };
int CAI_NavigatorUnit::sub_102ecc00() { return *(int *)((int)m_pOuter + 0x5d3c); }
}
using namespace block_102ee380;
// TARGET: CAI_Navigator::sub_102ee380
void CAI_Navigator::sub_102ee380(int a, int b)
{
	CAI_NavigatorUnit *u = (CAI_NavigatorUnit *)this;
	m_n08 = *(int *)((int)m_pOuter + 0x156c);
	m_n0c = *(int *)((char *)gpGlobals + 4);
	int *p = (int *)u->sub_102ecc00();
	p[2] = *(int *)(p[1] + 0x156c);
	p[3] = *(int *)((char *)gpGlobals + 4);
	((CAI_PathfinderView *)u->sub_102ecc00())->sub_102fdcc0(a, b);
}
// END FUNCTION

// FUNCTION: 0x102ee3f0 size=0x7
struct CUnknown102ee3f0 { int sub_102ee3f0(); };
int CUnknown102ee3f0::sub_102ee3f0()
{
    return *(int *)((char *)(*(int *)((char *)this + 0x30)) + 0x2c);
}
// END FUNCTION

// FUNCTION: 0x102ee410 size=0x8
namespace lifted {
struct C100039b8 { int sub_100039b8(); };
}
struct CUnknown102ee410 { int sub_102ee410(); };
int CUnknown102ee410::sub_102ee410()
{
    return ((lifted::C100039b8 *)(*(int *)((char *)this + 0x30)))->sub_100039b8();
}
// END FUNCTION

// FUNCTION: 0x102ee430 size=0x8d
#include "CAI_BaseNPC.h"
#include "CAI_Navigator.h"
#include "CBaseAnimating.h"

const char *sub_1025d730(int activity);
void sub_1027e590(CBaseEntity *pEnt, const char *pszFormat, ...);

int CAI_Navigator::sub_102ee430()
{
	int sequence = m_p30->sub_1030b580();
	if (sequence == -1)
	{
		CAI_BaseNPC *pOuter = (CAI_BaseNPC *)m_pOuter;
		sequence = pOuter->sub_1008dc40(pOuter->sub_10271ff0(m_p30->sub_1030b520(), 0), sequence);
		if (sequence == -1)
		{
			CAI_NavRoute *pRoute = m_p30;
			CBaseEntity *pEnt = (CBaseEntity *)m_pOuter;
			sub_1027e590(pEnt, "No appropriate sequence for arrival activity %s (%d)\n", sub_1025d730(pRoute->sub_1030b520()), pRoute->sub_1030b520());
			pOuter = (CAI_BaseNPC *)m_pOuter;
			sequence = pOuter->sub_1008dc40(pOuter->sub_10271ff0(1, 0), -1);
		}
		m_p30->sub_1030b5b0(sequence);
	}
	return sequence;
}
// END FUNCTION

// FUNCTION: 0x102ee4f0 size=0x8
struct CInner100016b3 { void sub_100016b3(); };
struct CUnknown102ee4f0 { char pad[0x30]; CInner100016b3 *m_pInner; void sub_102ee4f0(); };
void CUnknown102ee4f0::sub_102ee4f0() { m_pInner->sub_100016b3(); }
// END FUNCTION

// FUNCTION: 0x102ee510 size=0x8
namespace lifted {
struct C10001b77 { int sub_10001b77(); };
}
struct CUnknown102ee510 { int sub_102ee510(); };
int CUnknown102ee510::sub_102ee510()
{
    return ((lifted::C10001b77 *)(*(int *)((char *)this + 0x30)))->sub_10001b77();
}
// END FUNCTION

// FUNCTION: 0x102ee530 size=0x8
namespace lifted {
struct C1000745a { int sub_1000745a(); };
}
struct CUnknown102ee530 { int sub_102ee530(); };
int CUnknown102ee530::sub_102ee530()
{
    return ((lifted::C1000745a *)(*(int *)((char *)this + 0x30)))->sub_1000745a();
}
// END FUNCTION

// FUNCTION: 0x102ee550 size=0x2c
struct CVecTarget102ee550 {
    void sub_1000745a(float *pVec);
};
struct CVecUnit102ee550 {
    char pad[0x30];
    CVecTarget102ee550 *m_pTarget;
    void sub_102ee550(int a);
};
void sub_10139550(int a, float *pVec);
void sub_1030b5e0(float *pVec);

// TARGET: sub_102ee550
void CVecUnit102ee550::sub_102ee550(int a)
{
    float v[3];
    sub_10139550(a, v);
    m_pTarget->sub_1000745a(v);
}
// END FUNCTION

// FUNCTION: 0x102ee590 size=0x8
struct B { void sub_10014ef2(int *); };
struct A { char pad[0x30]; B *b; void sub_102ee590(int *x); };
void A::sub_102ee590(int *x) { b->sub_10014ef2(x); }
// END FUNCTION

// FUNCTION: 0x102ee5b0 size=0x14
struct CUnknown1030b610;
struct CUnknown102ee5b0
{
	char m_pad0000[0x30];
	CUnknown1030b610 *m_p30;

	int sub_102ee5b0(int a);
};
struct CUnknown1030b610
{
	void sub_1030b6b0(int a);
};

// TARGET: CUnknown102ee5b0::sub_102ee5b0
int CUnknown102ee5b0::sub_102ee5b0(int a)
{
	m_p30->sub_1030b6b0(a);
	return a;
}
// END FUNCTION

// FUNCTION: 0x102ee5e0 size=0x8
#include "CUnknown102ee120.h"
#include "CUnknown1030bc20.h"
CUnknown1030bc20_Record *CUnknown102ee120::sub_102ee5e0()
{
	return ((CUnknown1030bc20 *)m_unk30)->sub_1030b7c0();
}
// END FUNCTION

// FUNCTION: 0x102ee600 size=0x8
struct CInner1000a704 { int sub_1000a704(); };
struct CUnknown102ee600 { char pad[0x30]; CInner1000a704 *m_pInner; int sub_102ee600(); };
int CUnknown102ee600::sub_102ee600() { return m_pInner->sub_1000a704(); }
// END FUNCTION

// FUNCTION: 0x102ee620 size=0x8
namespace lifted {
struct C100113d8 { int sub_100113d8(); };
}
struct CUnknown102ee620 { int sub_102ee620(); };
int CUnknown102ee620::sub_102ee620()
{
    return ((lifted::C100113d8 *)(*(int *)((char *)this + 0x30)))->sub_100113d8();
}
// END FUNCTION

// FUNCTION: 0x102ee640 size=0x8
namespace lifted {
struct C1000ee58 { int sub_1000ee58(); };
}
struct CUnknown102ee640 { int sub_102ee640(); };
int CUnknown102ee640::sub_102ee640()
{
    return ((lifted::C1000ee58 *)(*(int *)((char *)this + 0x30)))->sub_1000ee58();
}
// END FUNCTION

// FUNCTION: 0x102ee660 size=0x8
namespace lifted {
struct C1000c6f3 { int sub_1000c6f3(); };
}
struct CUnknown102ee660 { int sub_102ee660(); };
int CUnknown102ee660::sub_102ee660()
{
    return ((lifted::C1000c6f3 *)(*(int *)((char *)this + 0x30)))->sub_1000c6f3();
}
// END FUNCTION

// FUNCTION: 0x102ee680 size=0xf
struct CUnknown1030ba70
{
	int sub_1030ba70();
};

// TARGET: sub_102ee680
bool __fastcall sub_102ee680(char *pThis)
{
	return ((CUnknown1030ba70 *)*(int *)(pThis + 0x30))->sub_1030ba70() != 0;
}
// END FUNCTION

// FUNCTION: 0x102ee6a0 size=0x17
struct CUnk102ee6a0 {
    char pad[0x30];
    void *m_30;
    int sub_102ee6a0();
};

struct S102ee6a0 { char pad[0x24]; int m_field; };

int CUnk102ee6a0::sub_102ee6a0()
{
    S102ee6a0 *p = (S102ee6a0 *)m_30;
    if (p && p->m_field)
        return 1;
    return 0;
}
// END FUNCTION

// FUNCTION: 0x102ee6d0 size=0x1e5
// TARGET: CAI_Navigator::sub_102ee6d0
#include "CAI_Navigator.h"
#include "CAI_Waypoint.h"
#include "CAI_BaseNPC.h"

class CUnk102ee940 { public: float sub_102ee940(); };

float sub_10146150(const Vector *v);

#define WP_VEC(p) (*(Vector *)(p)->m_vecPos)

bool CAI_Navigator::sub_102ee6d0(Vector *pResult, float flDistance)
{
	CAI_NavRoute *pRoute = m_p30;
	CAI_Waypoint *pWaypoint = (CAI_Waypoint *)pRoute->m_pWaypoint.m_p;
	if (!pWaypoint)
		return false;

	float flRemaining = flDistance;
	Vector vecOrigin = *(Vector *)((CAI_BaseNPC *)m_pOuter)->vfunc220();

	while (pWaypoint->m_pNext)
	{
		float flStep;
		if (m_i18 == 0)
		{
			Vector vecDelta = WP_VEC(pWaypoint) - vecOrigin;
			flStep = ((CUnk102ee940 *)&vecDelta)->sub_102ee940();
		}
		else
		{
			flStep = sub_10146150(&WP_VEC(pWaypoint).sub_10146190(vecOrigin));
		}
		if (flStep > flRemaining)
			break;
		vecOrigin = WP_VEC(pWaypoint);
		pWaypoint = pWaypoint->m_pNext;
		flRemaining -= flStep;
	}

	float flStep;
	if (m_i18 == 0)
	{
		Vector vecDelta = WP_VEC(pWaypoint) - vecOrigin;
		flStep = ((CUnk102ee940 *)&vecDelta)->sub_102ee940();
	}
	else
	{
		flStep = sub_10146150(&WP_VEC(pWaypoint).sub_10146190(vecOrigin));
	}

	if (flStep - flRemaining < 0.1)
	{
		*pResult = WP_VEC(pWaypoint);
		return true;
	}

	*pResult = WP_VEC(pWaypoint) - vecOrigin;
	VectorNormalize(*pResult);
	VectorMA(vecOrigin, flRemaining, *pResult, *pResult);
	return true;
}
// END FUNCTION

// FUNCTION: 0x102ee940 size=0x1f
#include "Vector.h"

struct CUnk102ee940 : public Vector
{
    float sub_102ee940();
};
float CUnk102ee940::sub_102ee940()
{
    return FastSqrt(y * y + x * x);
}
// END FUNCTION

// FUNCTION: 0x102ee970 size=0x33
#include "CAI_Pathfinder.h"
#include "CBaseEntity.h"
#include "CBaseEntitySlots.h"

extern int *g_1070b228;

struct CEntitySlots220 : public CBaseEntitySlots
{
	virtual void s194(); virtual void s195(); virtual void s196(); virtual void s197(); virtual void s198();
	virtual void s199(); virtual void s200(); virtual void s201(); virtual void s202(); virtual void s203();
	virtual void s204(); virtual void s205(); virtual void s206(); virtual void s207(); virtual void s208();
	virtual void s209(); virtual void s210(); virtual void s211(); virtual void s212(); virtual void s213();
	virtual void s214(); virtual void s215(); virtual void s216(); virtual void s217(); virtual void s218();
	virtual void s219();
	virtual float *slot220();
};

// TARGET: CAI_Pathfinder::sub_102ee970
void CAI_Pathfinder::sub_102ee970()
{
	CBaseEntity *pOwner = (CBaseEntity *)m_pOuter;
	CAI_PathfinderNetwork *pNetwork = m_pNetwork;
	m_n08 = *(int *)((char *)pOwner + 0x156c);
	m_n0c = g_1070b228[1];
	float *pPosition = ((CEntitySlots220 *)pOwner)->slot220();
	pNetwork->sub_102f3c10(pOwner, pPosition);
}
// END FUNCTION

// FUNCTION: 0x102ee9c0 size=0x4c
#include "CAI_Navigator.h"
#include "Vector.h"
extern int g_106c994c;

Vector *CAI_Navigator::sub_102ee9c0(Vector *pOut, int index)
{
	CAI_NavProvider *pNode;
	int hull = m_n08;
	CAI_NavProviderList *pList = m_pProviders;
	if (index >= 0 && index < pList->m_nCount)
		pNode = pList->m_ppItems[index];
	else
	{
		g_106c994c++;
		pNode = 0;
	}
	pNode->sub_102fb0d0(pOut, hull);
	return pOut;
}
// END FUNCTION

// FUNCTION: 0x102eea30 size=0x3
#include "CAI_Navigator.h"
void CAI_Navigator::vfunc4(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x102eea50 size=0x1
#include "CAI_Navigator.h"
void CAI_Navigator::vfunc6()
{
}
// END FUNCTION

// FUNCTION: 0x102eea70 size=0xe
// TARGET: CAI_Navigator::vfunc7
#include "CAI_Navigator.h"

void CAI_Navigator::vfunc7()
{
    sub_102eeb70();
    m_b1c = 1;
}
// END FUNCTION

// FUNCTION: 0x102eea90 size=0x15
#include "CAI_Navigator.h"

struct CUnknown102eccc0
{
	void sub_102eccc0();
};

// TARGET: CAI_Navigator::vfunc8
void CAI_Navigator::vfunc8()
{
	sub_102eeb70();
	((CUnknown102eccc0 *)this)->sub_102eccc0();
	*(char *)((char *)this + 0x1c) = 1;
}
// END FUNCTION

// FUNCTION: 0x102eeac0 size=0x10
#include "CAI_Navigator.h"
#include "vampire.h"

// TARGET: CAI_Navigator::vfunc11
void CAI_Navigator::vfunc11(int a)
{
	sub_102eeb70();
	m_b1c = 1;
}
// END FUNCTION

// FUNCTION: 0x102eeae0 size=0x4b
#include "CAI_BaseNPC.h"
#include "CAI_Navigator.h"
struct CNavNPCView : CAI_BaseNPC
{
	char m_pad[0x1b44 - 4];
	const char *m_pszFile;
	int m_nLine;
};

void CAI_Navigator::vfunc10(int a, float b)
{
	sub_102eeb70();
	CNavNPCView *pNPC = (CNavNPCView *)m_pOuter;
	pNPC->m_pszFile = "E:\\Vampire\\main\\dlls\\ai_navigator.cpp";
	((CNavNPCView *)m_pOuter)->m_nLine = 0x406;
	((CNavNPCView *)m_pOuter)->vfunc448(a);
	((CNavNPCView *)m_pOuter)->sub_10272650(((CNavNPCView *)m_pOuter)->sub_1027a6c0());
	m_b1c = 1;
}
// END FUNCTION

// FUNCTION: 0x102eeb50 size=0xd
#include "CAI_Navigator.h"

void CAI_Navigator::vfunc9(int a, float b)
{
	vfunc10(a, b);
}
// END FUNCTION

// FUNCTION: 0x102eeb70 size=0x1a
namespace lifted {
struct C1000b550 { int sub_1000b550(); };
}
struct CUnknown102eeb70 { int sub_102eeb70(); };
int CUnknown102eeb70::sub_102eeb70()
{
    *(int *)((char *)this + 0x54) = -1;
    *(int *)((char *)this + 0x58) = -1082130432;
    *(int *)((char *)this + 0x60) = -1082130432;
    return ((lifted::C1000b550 *)(*(int *)((char *)this + 0x28)))->sub_1000b550();
}
// END FUNCTION

// FUNCTION: 0x102eeba0 size=0xa
struct CUnknown102eeba0 { int p[6]; int a; void sub_102eeba0(int v); };
// TARGET: CUnknown102eeba0::sub_102eeba0
void CUnknown102eeba0::sub_102eeba0(int v) { a = v; }
// END FUNCTION

// FUNCTION: 0x102eebc0 size=0xda
#include "CAI_Navigator.h"
#include "CEntityVSlots.h"
#include "CUnknown1030bc20.h"
struct CNavMotorV
{
	virtual void v0(); virtual void v1(); virtual void v2();
	virtual void v3();
	virtual int v4(CUnknown1030bc20_Record *pGoal, float flValue);
	virtual void v5();
};
namespace block_102ee3f0 {
struct CNavUnit : CAI_Navigator { int sub_102ee3f0(); };
int CNavUnit::sub_102ee3f0() { return m_p30->m_i2c; }
}
using namespace block_102ee3f0;
// TARGET: CAI_Navigator::vfunc13
int CAI_Navigator::vfunc13(int a)
{
	if (m_i18 != 3) {
		Vector vecGoal = *sub_102ee140();
		if (vecGoal.z > ((CEntityVSlots *)m_pOuter)->slot220()->z)
			((CEntityVSlots *)m_pOuter)->slot310(0x33);
		else
			((CEntityVSlots *)m_pOuter)->slot310(0x34);
		((CNavMotorV *)m_i20)->v3();
	}
	sub_10008832(3);
	CAI_NavRoute *pRoute = m_p30;
	CNavMotorV *pMotor = (CNavMotorV *)m_i20;
	int nResult = pMotor->v4(((CUnknown1030bc20 *)pRoute)->sub_1030b7c0(), pRoute->sub_1030b880());
	if (nResult == 1) {
		sub_102f0400();
		if (m_p30->sub_1030bc00() != 3) {
			((CEntityVSlots *)m_pOuter)->slot310(((CNavUnit *)this)->sub_102ee3f0());
			((CNavMotorV *)m_i20)->v5();
			sub_10008832(0);
		}
	}
	return nResult;
}
// END FUNCTION

// FUNCTION: 0x102eece0 size=0x10a
#include "CBaseEntity.h"
#include "CAI_Navigator.h"
#include "CUnknown1030bc20.h"
#include "CUnknown1070b22c.h"
extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
struct NavResult { int v[14]; };
struct CNavQuery { int sub_10012b43(int a, int b, void *c, int d, int e, float f, int g, NavResult *h, int i, int j); };
struct CNavMotorV { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void v6(void *p); virtual void v7(); virtual void v8(); };
struct CNavOwnerV {
	U22C_SLOTS10(a0) U22C_SLOTS10(a1) U22C_SLOTS10(a2) U22C_SLOTS10(a3) U22C_SLOTS10(a4)
	U22C_SLOTS10(a5) U22C_SLOTS10(a6) U22C_SLOTS10(a7) U22C_SLOTS10(a8) U22C_SLOTS10(a9)
	U22C_SLOTS10(b0) U22C_SLOTS10(b1) U22C_SLOTS10(b2) U22C_SLOTS10(b3) U22C_SLOTS10(b4)
	U22C_SLOTS10(b5) U22C_SLOTS10(b6) U22C_SLOTS10(b7) U22C_SLOTS10(b8) U22C_SLOTS10(b9)
	U22C_SLOTS10(c0) U22C_SLOTS10(c1)
	virtual void *v220();
};
struct CNavUnit : CAI_Navigator { int sub_10009322(); void sub_10006744(); };
bool sub_100147a4();
int CAI_Navigator::vfunc14(int param)
{
	int one = 1;
	if (m_i18 != one) {
		if (((CBaseEntity *)m_pOuter)->sub_100b3700() & 1) {
			NavResult r;
			memset(&r, 0, sizeof(r));
			CUnknown1030bc20 *route = (CUnknown1030bc20 *)m_p30;
			void *ent = ((CNavOwnerV *)m_pOuter)->v220();
			CNavQuery *q = (CNavQuery *)m_i24;
			int t = ((CNavUnit *)this)->sub_10009322();
			CUnknown1030bc20_Record *rec = route->sub_1030b7c0();
			q->sub_10012b43(1, (int)ent, rec, 0x202400b, t, 100.0f, 0, &r, param, 0);
			if (r.v[0] < 0)
				return r.v[0];
			sub_10008832(1);
			((CNavMotorV *)m_i20)->v6(&r.v[10]);
			return 0;
		}
		if (m_i18 != one)
			goto L1;
	}
	if (((CBaseEntity *)m_pOuter)->sub_100b3700() & 1) {
		((CNavMotorV *)m_i20)->v8();
		sub_10008832(0);
		if (sub_100147a4()) {
			vfunc8();
			return 0;
		}
		((CNavUnit *)this)->sub_10006744();
		return one;
	}
L1:
	((CNavMotorV *)m_i20)->v7();
	return 0;
}
// END FUNCTION

// FUNCTION: 0x102eee40 size=0x11d
#include "CAI_Navigator.h"
#include "CAI_BaseNPC.h"
#include "CUnknown102e12c0.h"
#include "CHolderInner24.h"

double __fastcall sub_10008bfc(CUnknown102e12c0 *p);
float sub_100067ad(Vector *pVec);

void CAI_Navigator::vfunc17(CAI_NavGoal *pGoal)
{
	pGoal->m_i30 = m_i18;
	pGoal->m_vecStart = *m_p30->sub_1030b7c0();
	Vector *delta = &pGoal->m_vecDelta;
	int bFlag = m_i18;
	float *pOrigin = ((CAI_BaseNPC *)m_pOuter)->vfunc220();
	delta->x = pGoal->m_vecStart.x - pOrigin[0];
	delta->y = pGoal->m_vecStart.y - pOrigin[1];
	float flLen;
	if (bFlag == 0) {
		delta->z = 0;
		flLen = sub_100067ad(delta);
	} else {
		delta->z = pGoal->m_vecStart.z - pOrigin[2];
		flLen = VectorNormalize(*delta);
	}
	pGoal->m_flDist = flLen;
	pGoal->m_vecDir = *delta;
	double flSpeed = sub_10008bfc((CUnknown102e12c0 *)m_i20);
	pGoal->m_f24 = (float)flSpeed;
	pGoal->m_f2c = (float)(((CUnknown102e12c0 *)m_i20)->m_f30 * flSpeed);
	pGoal->m_p34 = sub_102ecc40();
	if (pGoal->m_f2c > pGoal->m_flDist)
		pGoal->m_f2c = pGoal->m_flDist;
	if (((CHolderInner24 *)m_p30)->sub_1030bd50()) {
		pGoal->m_flags |= 1;
	} else {
		CHolderInner24_Node *pNode = ((CHolderInner24 *)m_p30)->m_pNode;
		if (pNode->m_pNext && pNode->m_pNext->m_i2c != pNode->m_i2c)
			pGoal->m_flags |= 4;
	}
	pGoal->m_pRoute = m_p30;
}
// END FUNCTION

// FUNCTION: 0x102eefb0 size=0xe1
#include "CAI_DefMovementSink.h"
#include "CAI_Navigator.h"
#include "CBaseEntitySlots.h"
struct Info102eefb0
{
	char m_pad00[0x28];
	float m_f28;
	char m_pad2c[0x38 - 0x2c];
	unsigned int m_uFlags;
	char m_pad3c[0x44 - 0x3c];
	int m_i44;
	char m_pad48[0x60 - 0x48];
	CBaseEntitySlots *m_p60;
};

struct CNavRoute102eefb0
{
	char m_pad00[0x28];
	float m_f28;
	char m_pad2c[0x40 - 0x2c];
	float m_f40;
};

struct CSinkDispatch102eefb0
{
	virtual void slot0();
	virtual char vfunc1(void *pGoal, float flValue, int *pOut);
};

#define NAV102EEFB0 ((CAI_Navigator *)((char *)this - 0x10))
#define ROUTE102EEFB0 ((CNavRoute102eefb0 *)NAV102EEFB0->m_p30)

bool CAI_DefMovementSink::sub_102eefb0(void *pGoal, float flValue, int *pOut)
{
	bool bSet = false;
	Info102eefb0 *pInfo = (Info102eefb0 *)pGoal;
	unsigned int uFlags = pInfo->m_uFlags;
	unsigned int flag1 = uFlags & 1;
	float flLimit;
	if ( flag1 )
	{
		flLimit = ROUTE102EEFB0->m_f28;
	}
	else if ( uFlags & 4 )
	{
		goto Delegate;
	}
	else
	{
		bSet = true;
		flLimit = ROUTE102EEFB0->m_f40;
	}
	if ( flValue > pInfo->m_f28 )
	{
		*pOut = 0;
		return true;
	}
	if ( flLimit > pInfo->m_f28 )
	{
		if ( flag1 && pInfo->m_i44 == -3 )
		{
			if ( pInfo->m_p60->slot153() != 0 )
				goto Delegate;
		}
		pInfo->m_f28 = flValue;
		*pOut = 0;
		if ( bSet )
		{
			NAV102EEFB0->sub_102f0400();
			return true;
		}
		if ( flValue < 0.01 )
			*pOut = pInfo->m_i44;
		return true;
	}
Delegate:
	return ((CSinkDispatch102eefb0 *)((char *)NAV102EEFB0->m_pOuter + 0x19b0))->vfunc1(pGoal, flValue, pOut);
}
// END FUNCTION

// FUNCTION: 0x102ef0e0 size=0x8a
struct Info102ef0e0
{
	char m_pad0000[0x28];
	float m_f28;	// 0x28
	char m_pad002c[0x38 - 0x2c];
	unsigned int m_flags38;	// 0x38
	char m_pad003c[0x44 - 0x3c];
	int m_n44;	// 0x44
};

struct Ctrl102ef0e0
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual char vfunc4(Info102ef0e0 *pInfo, float flTime, int *pOut);
};

struct Main102ef0e0
{
	char m_pad0000[0x19b0];
	Ctrl102ef0e0 m_Ctrl;	// 0x19b0
};

struct Sub102ef0e0
{
	char sub_102efde0(Info102ef0e0 *pInfo, float flTime);	// stub 0x10006bf9
};

extern double g_10449280;

// TARGET: sub_102ef0e0
char __fastcall sub_102ef0e0(void *self, int unused, Info102ef0e0 *pInfo, float flTime, int *pOut)
{
	Main102ef0e0 *pMain = *(Main102ef0e0 **)((char *)self - 0xc);
	if (!pMain->m_Ctrl.vfunc4(pInfo, flTime, pOut)) {
		if (!((Sub102ef0e0 *)((char *)self - 0x10))->sub_102efde0(pInfo, flTime)) {
			if (flTime < g_10449280) {
				*pOut = pInfo->m_n44;
				pInfo->m_f28 = 0;
				return 1;
			}
			return 0;
		}
		*pOut = 0;
		pInfo->m_f28 = flTime;
		pInfo->m_flags38 |= 2;
	}
	return 1;
}
// END FUNCTION

// FUNCTION: 0x102ef1a0 size=0x14b
template <class T> __forceinline T pcd_stage(T x) { return x; }
#include "CAI_DefMovementSink.h"
#include "CAI_Navigator.h"
struct Info102ef1a0
{
	char m_pad00[0x28];
	float m_f28;
	char m_pad2c[0x0c];
	unsigned int m_uFlags;
};

struct CNavRoute102ef1a0
{
	char m_pad00[0x28];
	float m_f28;
};

struct CSinkDispatch102ef1a0
{
	virtual void s0();
	virtual void s1();
	virtual char s2(void *pGoal, float flValue, int *pOut);
};

struct CNavView102ef1a0 : CAI_Navigator
{
	bool Prepend(float dist) { return sub_102ede30(dist, 0); }
};

float __fastcall sub_102f1d90(CAI_Navigator *pNav);
float __cdecl sub_102d61b0(int index);

#define NAV102EF1A0 ((CAI_Navigator *)((char *)this - 0x10))

bool CAI_DefMovementSink::sub_102ef1a0(void *pGoal, float flValue, int *pOut)
{
	Info102ef1a0 *pInfo = (Info102ef1a0 *)pGoal;
	if ( ((CSinkDispatch102ef1a0 *)((char *)NAV102EF1A0->m_pOuter + 0x19b0))->s2(pGoal, flValue, pOut) )
		return true;

	if ( pInfo->m_uFlags & 1 )
	{
		float fLimit = sub_102f1d90(NAV102EF1A0);
		if ( fLimit <= flValue )
		{
			*pOut = 0;
			return true;
		}
		float flRoute = ((CNavRoute102ef1a0 *)NAV102EF1A0->m_p30)->m_f28;
		if ( (pInfo->m_f28 - flRoute) < flValue )
		{
			if ( pInfo->m_f28 > flValue )
				pInfo->m_f28 = flValue;
			if ( flValue < 0.125 )
				NAV102EF1A0->vfunc8();
			pInfo->m_uFlags |= 2;
			*pOut = 0;
			return true;
		}
	}
	if ( !(pInfo->m_uFlags & 4) )
	{
		float fA = NAV102EF1A0->sub_102f1cf0();
		double flHalf = sub_102d61b0(pcd_stage(NAV102EF1A0->m_n08)) * 0.5;
		if ( fA < flHalf )
		{
			if ( fA + flHalf < flValue )
			{
				*pOut = 0;
				return true;
			}
		}
	}
	if ( flValue < pInfo->m_f28 )
	{
		if ( ((CNavView102ef1a0 *)NAV102EF1A0)->Prepend(flValue) )
		{
			*pOut = 1;
			return true;
		}
	}
	return false;
}
// END FUNCTION

// FUNCTION: 0x102ef350 size=0x67
#include "CUnknown102ef350.h"
// TARGET: CUnknown102ef350Iface::sub_102ef350
bool CUnknown102ef350Iface::sub_102ef350(CUnknown102ef350Item *pItem, int a, int *pOut)
{
	CUnknown102ef350Owner *owner = *(CUnknown102ef350Owner **)((char *)this - 0xc);
	if (owner->m_Sink19b0.vfunc3(pItem, a, pOut))
		return true;
	if (((CUnknown102ef3e0 *)((char *)this - 0x10))->sub_102ef3e0(&pItem->m_Arg44)) {
		*pOut = 0;
		pItem->m_n28 = a;
		pItem->m_flags38 |= 2;
		return true;
	}
	return false;
}
// END FUNCTION

// FUNCTION: 0x102ef3e0 size=0xee
#include "CUnknown102ef3e0.h"
#include "CEHandleGet.h"

struct H102ef3e0 { char m_pad[0x94]; CGlobalEntityList_Ent *m_pOwner; CGlobalEntityList_Ent *MyNPCPointer() { return m_pOwner; } };
struct A102ef3e0 { char m_pad[0x1c]; H102ef3e0 *m_pHolder; };

bool CUnknown102ef3e0::sub_102ef3e0(CUnknown102ef3e0Arg *pArg)
{
	CGlobalEntityList_Ent *pTarget = ((A102ef3e0 *)pArg)->m_pHolder ? ((A102ef3e0 *)pArg)->m_pHolder->MyNPCPointer() : 0;
	if (pTarget) {
		if (EHandle_Get(m_hTarget) != pTarget || gpGlobals->curtime - m_flTimeB > -0.001) {
			m_bNoticed = true;
			m_hTarget = *pTarget->v1();
			m_flTimeA = gpGlobals->curtime + m_flDelayA;
			m_flTimeB = gpGlobals->curtime + m_flDelayB;
		} else if (EHandle_Get(m_hTarget) == pTarget && !(gpGlobals->curtime - m_flTimeA > -0.001)) {
			m_bNoticed = true;
		}
	}
	return m_bNoticed;
}
// END FUNCTION

// FUNCTION: 0x102ef510 size=0x134
#include "CAI_Navigator.h"
#include "CAI_BaseNPC.h"

struct CNavWpView
{
	Vector m_vecPos;
	char m_pad0c[0x2c - 0xc];
	int m_i2c;
	CNavWpView *m_pLinked;	// 0x30
};

struct CNavGlobalView
{
	virtual void vfunc0();
	virtual bool vfunc1();
	char m_pad08[0x2c - 4];
	int m_i2c;
};

extern CNavGlobalView *g_106bbaa4;
extern char g_10934070;
float sub_10146150(const Vector *pVec);

struct CAI_NavigatorUnit : public CAI_Navigator
{
	char sub_102ee660();
};

bool CAI_Navigator::vfunc16(int *pOut)
{
	CAI_BaseNPC *pOwner = (CAI_BaseNPC *)m_pOuter;
	CAI_NavRoute *pRoute = m_p30;
	int bFlat = m_i18;
	CNavWpView *pWp = (CNavWpView *)pRoute->m_pWaypoint.m_p;
	const Vector *pOrigin = (const Vector *)pOwner->vfunc220();
	float flDist;
	if (bFlat == 0)
	{
		float dx = pWp->m_vecPos.x - pOrigin->x;
		float dy = pWp->m_vecPos.y - pOrigin->y;
		flDist = FastSqrt(dx * dx + dy * dy);
	}
	else
	{
		Vector vecDelta = pWp->m_vecPos - *pOrigin;
		flDist = sub_10146150(&vecDelta);
	}
	char bArrived;
	bArrived = ((CAI_NavigatorUnit *)this)->sub_102ee660();
	if ((float)((!g_106bbaa4->vfunc1() && g_106bbaa4->m_i2c) ? 0.25 : 0.0625) >= flDist)
	{
		if (!g_10934070 || !pWp->m_pLinked || pWp->m_pLinked->m_i2c == pWp->m_i2c || flDist < 0.001)
		{
			if (bArrived)
			{
				vfunc8();
				*pOut = 0;
				return true;
			}
			sub_102f0400();
			*pOut = 1;
			return true;
		}
	}
	return false;
}
// END FUNCTION

// FUNCTION: 0x102ef6a0 size=0x1a
// TARGET: sub_102ef6a0
struct CUnk102ef6a0Obj {
    int sub_1027a6c0();
    void sub_10272650(int a);
};
struct CUnk102ef6a0 {
    char pad[0];
    bool sub_102ef6a0(int a);
};
bool CUnk102ef6a0::sub_102ef6a0(int a)
{
    CUnk102ef6a0Obj *o = *(CUnk102ef6a0Obj **)((char *)this - 0xc);
    int r = o->sub_1027a6c0();
    o = *(CUnk102ef6a0Obj **)((char *)this - 0xc);
    o->sub_10272650(r);
    return 1;
}
// END FUNCTION

// FUNCTION: 0x102ef6d0 size=0x6b
#include "CUnknown102ef350.h"
// TARGET: CUnknown102ef350Iface::sub_102ef6d0
bool CUnknown102ef350Iface::sub_102ef6d0(int a, CUnknown102ef3e0Arg *b, int type, int *pOut)
{
	CUnknown102ef350Owner *owner = *(CUnknown102ef350Owner **)((char *)this - 0xc);
	if (!owner->m_Sink19b0.vfunc7(a, (int)b, type, pOut)) {
		if (type == 4) {
			((CUnknown102ef350Outer *)((char *)this - 0x10))->vfunc8();
			*pOut = 0;
			return true;
		}
		if (type == 2) {
			if (((CUnknown102ef3e0 *)((char *)this - 0x10))->sub_102ef3e0(b))
				*pOut = 0;
		}
	}
	return true;
}
// END FUNCTION

// FUNCTION: 0x102ef760 size=0xcf
#include "CAI_BaseNPC.h"
#include "CAI_Navigator.h"

struct CAI_NavMotorView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual char v5(int *pOut);
};

extern Vector *__fastcall sub_1030ba30(void *pThis);

namespace block_102ef760 {
struct CAI_NavigatorUnit : CAI_Navigator {
	float sub_102ee1a0();
};
float CAI_NavigatorUnit::sub_102ee1a0()
{
	return *(float *)((char *)m_p30 + 0x28);
}
}
using namespace block_102ef760;

#define OWNER (*(CAI_BaseNPC **)((char *)pSink - 0xc))
#define NAVP ((CAI_NavigatorUnit *)((char *)pSink - 0x10))

inline float NavGoalDist(CAI_DefMovementSink *pSink)
{
	CAI_NavRoute *pRoute = NAVP->m_p30;
	const Vector &origin = *(Vector *)OWNER->vfunc220();
	int bFlag = NAVP->m_i18;
	const Vector &goal = *sub_1030ba30(pRoute);
	if (bFlag == 0)
		return (goal - origin).Length2D();
	return (goal - origin).Length();
}

// TARGET: sub_102ef760
char __fastcall sub_102ef760(CAI_DefMovementSink *pSink, int, int *pOut)
{
	if (((CAI_NavMotorView *)((char *)OWNER + 0x19b0))->v5(pOut))
		return 1;
	OWNER->sub_10272650(OWNER->sub_1027a6c0());
	if (NavGoalDist(pSink) < NAVP->sub_102ee1a0() + 0.1f)
	{
		NAVP->vfunc8();
		*pOut = 0;
		return 1;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x102ef870 size=0x1b4
#include "CAI_Navigator.h"
#include "CAI_Motor.h"
#include "CAI_LocalNavigator.h"
#include "CVProfile.h"
#include "CUnknown10270290.h"
#include <string.h>

struct CCycleSample
{
	unsigned __int64 m_Int64;
	void Sample() { unsigned int *p = (unsigned int *)&m_Int64; __asm { mov ecx, p
		rdtsc
		mov [ecx], eax
		mov [ecx + 4], edx } }
};

struct CNavScope
{
	CNavScope() { g_109f3648->EnterScope("CAI_Navigator_MoveEnact", 0, "Unaccounted", false); }
	~CNavScope()
	{
		CVProfile *pProf = g_109f3648;
		if (!pProf->m_bAtRoot || pProf->m_enabled) {
			CVProfNode *pNode = pProf->m_pCurNode;
			if (--pNode->m_nRecursions == 0 && pNode->m_nCurFrameCalls != 0) {
				CCycleSample s;
				s.m_Int64 = 0;
				s.Sample();
				CUnknownCycle100335e0 *pc = &pNode->m_CurFrameTime;
				pc->m_Int64 = s.m_Int64 - pc->m_Int64;
				pNode->m_TotalTime += pc->m_Int64;
				CVProfile *pPop = g_109f3648;
				--pPop->m_nGroupStackDepth;
				int nNew = pPop->m_GroupIDStack[pPop->m_nGroupStackDepth];
				int nOld = pPop->m_GroupIDStack[pPop->m_nGroupStackDepth + 1];
				if (nNew != nOld && pPop->m_bVTuneGroupsEnabled && nOld == pPop->m_nVTuneGroupID)
					vtune(false);
			}
			if (pNode->m_nRecursions == 0)
				pProf->m_pCurNode = pProf->m_pCurNode->m_pParent;
			pProf->m_bAtRoot = (pProf->m_pCurNode == pProf->m_pRoot);
		}
	}
};

// TARGET: CAI_Navigator::vfunc15
int CAI_Navigator::vfunc15(void *pGoal, int a)
{
	CNavScope scope;
	int goal[31];
	memcpy(goal, pGoal, sizeof(goal));
	int nResult = -4;
	int pBlocker = 0;
	nResult = LocalNav()->vfunc3(goal, 0, &pBlocker);
	if (pBlocker)
		((CUnknown10270290 *)m_pOuter)->sub_10270290(pBlocker);
	if (nResult == 0)
		nResult = Motor()->sub_102e23a0((struct CAI_MoveRequest *)goal, *(float *)&a);
	else if (nResult != 1)
		Motor()->vfunc10();
	if (nResult < 0)
		sink5(&nResult);
	return nResult;
}
// END FUNCTION

// FUNCTION: 0x102efaa0 size=0x21a
#include "CUnknown101d7520.h"
#include "CUnknown101daec0.h"
#include "CUnknown101e56e0.h"
#include "CUnknown101e7c50.h"
#include "CUnknown101f4c80.h"
#include "CUnknown10202b10.h"
#include "CUnknown10206400.h"
#include "CUnknown1073dc28.h"
#include "CAI_Navigator.h"
#include "ScopeTrace.h"
#include "globalvars.h"
#include <string.h>

#define V4(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3();
#define V16(a) V4(a##a) V4(a##b) V4(a##c) V4(a##d)
#define V64(a) V16(a##a) V16(a##b) V16(a##c) V16(a##d)

struct NavMoveOwner {
	V64(p) V64(q) V64(r) V16(s) V4(t) V4(u) virtual void v0();
	virtual Vector *vfunc217();
	V16(w) V4(x0) V4(x1) V4(x2) virtual void y0(); virtual void y1();
	virtual float vfunc248();
	V16(a1) V16(a2) V16(a3) V4(b1) V4(b2) V4(b3) virtual void c0();
	virtual void vfunc310(int act);
};
extern float g_104454c4;

struct NavMoveOwnerData {
	char pad0[0x6f0];
	int m6f0;
	char pad1[0xfec - 0x6f4];
	int mAct;
};
struct NavMoveTrace {
	NavMoveTrace() { memset(this, 0, sizeof(*this)); }
	char m_b[0x38];
};
struct NavMoveGoal {
	NavMoveGoal() { memset(this, 0, sizeof(*this)); }
	char m_pre[0x44];
	NavMoveTrace m_trace;
};

static inline float NavLen(const Vector &v)
{
	return FastSqrt(v.x * v.x + (v.y * v.y + v.z * v.z));
}

namespace block_102efaa0 {
struct CAI_NavigatorUnit : CAI_Navigator {
	int sub_102ee3f0();
};
int CAI_NavigatorUnit::sub_102ee3f0() { return m_p30->m_i2c; }
}
using namespace block_102efaa0;

#define OWNER ((NavMoveOwner *)m_pOuter)
#define ODATA ((NavMoveOwnerData *)m_pOuter)

// TARGET: CAI_Navigator::vfunc12
int CAI_Navigator::vfunc12(int a)
{
	ScopeTrace trace("CAI_Navigator::MoveNormal", g_106b8540, g_106b8540);
	if (!sub_102efd50())
		return -4;
	int result = -4;
	if (vfunc16(&result))
		return result;
	float flDist = OWNER->vfunc248();
	int act = ODATA->mAct;
	int s6f0 = ODATA->m6f0;
	Vector savedPos = *OWNER->vfunc217();
	OWNER->vfunc310(((CAI_NavigatorUnit *)this)->sub_102ee3f0());
	if (OWNER->vfunc248() <= g_104454c4 && ODATA->mAct == 2)
		return 0;
	NavMoveGoal goal;
	vfunc17((CAI_NavGoal *)&goal);
	result = vfunc15(&goal, a);
	if (result == 0) {
		if (flDist < 0.01) {
			if (NavLen(*OWNER->vfunc217() - savedPos) < 0.01) {
				ODATA->m6f0 = s6f0;
				OWNER->vfunc310(act);
			}
		}
		if (result == 0 && !m_b51)
			vfunc6();
	}
	return result;
}
// END FUNCTION

// FUNCTION: 0x102efd50 size=0x68
#include "CAI_Navigator.h"

struct NavMotorX {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void vfunc5(); virtual void v6(); virtual void v7();
	virtual void vfunc8();
};
extern void (__cdecl *g_109f3630)(const char *fmt, ...);

bool CAI_Navigator::sub_102efd50()
{
	int status = m_p30->sub_1030bc00();
	int type = m_i18;
	if (status == 0) {
		if (type != 0) {
			g_109f3630("Warning: NPC appears to have wrong nav type in CAI_Navigator::MoveGround()\n");
			switch (type) {
			case 1:
				((NavMotorX *)m_i20)->vfunc8();
				break;
			case 3:
				((NavMotorX *)m_i20)->vfunc5();
				break;
			}
			sub_10008832(0);
		}
	} else if (status == 2 && type != 2) {
		return false;
	}
	sub_100053b7(0);
	*((char *)this + 0x51) = 0;
	return true;
}
// END FUNCTION

// FUNCTION: 0x102efde0 size=0x104
#include "CAI_Motor.h"
#define S1(n) virtual void s##n();
#define S10(p) S1(p##0) S1(p##1) S1(p##2) S1(p##3) S1(p##4) S1(p##5) S1(p##6) S1(p##7) S1(p##8) S1(p##9)
#define S100(p) S10(p##0) S10(p##1) S10(p##2) S10(p##3) S10(p##4) S10(p##5) S10(p##6) S10(p##7) S10(p##8) S10(p##9)
struct V2_102efde0
{
	float x, y;
	V2_102efde0() {}
	V2_102efde0(const V2_102efde0 &o) { x = o.x; y = o.y; }
	float Length() const { return FastSqrt(x * x + y * y); }
	V2_102efde0 &operator/=(float fl) { float oofl = 1.0f / fl; x *= oofl; y *= oofl; return *this; }
};
inline float Vector2DNormalize_102efde0(V2_102efde0 &v)
{
	float l = v.Length();
	if (l != 0.0f)
		v /= l;
	else
		v.x = v.y = 0.0f;
	return l;
}
struct MotorView102efde0 { char m_pad[0x3c]; V2_102efde0 m_v; };
struct CMotorOwner102efde0
{
	S100(0) S10(10) S10(11) S10(12) S10(13) S10(14)
	S1(150) S1(151) S1(152)
	virtual int slot153();
	char m_pad[0x5d44 - 4];
	MotorView102efde0 *m_pMotor;
};
struct CMotorHolder102efde0
{
	char m_pad[0x94];
	CMotorOwner102efde0 *m_pOwner;
	CMotorOwner102efde0 *MyNPCPointer() { return m_pOwner; }
};
struct CMotorArg102efde0
{
	char m_pad0[0xc];
	V2_102efde0 m_dir;
	char m_pad14[0x2c - 0x14];
	float m_f2c;
	char m_pad30[0x60 - 0x30];
	CMotorHolder102efde0 *m_pHolder;
};

bool __stdcall sub_102efde0(CMotorArg102efde0 *pArg, float flDist)
{
	CMotorOwner102efde0 *pBlocker = pArg->m_pHolder ? pArg->m_pHolder->MyNPCPointer() : 0;
	if (!pBlocker)
		return false;
	if (pBlocker->slot153()) {
		if (flDist > pArg->m_f2c * 0.75)
			return true;
		V2_102efde0 vel(pBlocker->m_pMotor->m_v);
		V2_102efde0 norm(vel);
		if (Vector2DNormalize_102efde0(norm) == 0.0f)
			return false;
		if (norm.x * pArg->m_dir.x + norm.y * pArg->m_dir.y > -0.25)
			return true;
	}
	return false;
}
// END FUNCTION

// FUNCTION: 0x102eff40 size=0x2a4
#include "CUnknown101d7520.h"
#include "CUnknown101daec0.h"
#include "CUnknown101e56e0.h"
#include "CUnknown101e7c50.h"
#include "CUnknown101f4c80.h"
#include "CUnknown10202b10.h"
#include "CUnknown10206400.h"
#include "CUnknown1073dc28.h"
#include "CAI_Navigator.h"
#include "ScopeTrace.h"
#include "globalvars.h"

__declspec(dllimport) void DevMsg(const char *pMsg, ...);
__declspec(dllimport) void Warning(const char *pMsg, ...);

#define V4(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3();
#define V16(a) V4(a##a) V4(a##b) V4(a##c) V4(a##d)
#define V64(a) V16(a##a) V16(a##b) V16(a##c) V16(a##d)

struct NavOwner {
    V64(p) V64(q) V64(r) V64(s) V64(t) V64(u) V64(v) V64(w) V4(x) V4(y) V4(z)
    virtual void f0();
    virtual char vfunc525(float flInterval);
};
struct NavOwnerData {
    int vptr;
    char pad[0x156c - 4];
    int m156c;
    char pad2[0x1a40 - 0x1570];
    char b1a40;
    char pad3[0x5d44 - 0x1a41];
    struct NavComp *p5d44;
};
struct NavComp {
    int vptr;
    NavOwnerData *pOuter;
    int stamp8;
    int stampC;
};
struct NavMotor {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void vfunc5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void vfunc10();
    char pad[0x30 - 4];
    float f30;
};
struct NavSelfView {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void OnNavFailed(int code, int force);
};

extern int g_1060fcc4[];
extern float g_104454c4;
extern int __fastcall sub_1030ba70(void *p);
extern char __fastcall sub_10280a20(void *p);

void CAI_Navigator::vfunc5(float flInterval, int a)
{
    ScopeTrace trace("CAI_Navigator::Move", g_106b8540, g_106b8540);
    if (flInterval > 1.0)
        flInterval = 1.0f;
    if (sub_102ee2e0())
        return;
    NavOwner *pOwner = (NavOwner *)m_pOuter;
    if (pOwner->vfunc525(flInterval))
        return;
    NavOwnerData *pData = (NavOwnerData *)m_pOuter;
    if (pData->b1a40) {
        m_n08 = pData->m156c;
        m_n0c = gpGlobals->framecount;
        NavComp *c = (NavComp *)sub_102ecc00();
        c->stamp8 = c->pOuter->m156c;
        c->stampC = gpGlobals->framecount;
        c = (NavComp *)m_i28;
        c->stamp8 = c->pOuter->m156c;
        c->stampC = gpGlobals->framecount;
        c = (NavComp *)m_i24;
        c->stamp8 = c->pOuter->m156c;
        c->stampC = gpGlobals->framecount;
        c = ((NavOwnerData *)m_pOuter)->p5d44;
        c->stamp8 = c->pOuter->m156c;
        c->stampC = gpGlobals->framecount;
        m_p30->sub_1030bc00();
        ((NavMotor *)m_i20)->f30 = flInterval;
        int result = 0;
        if (!sub_1030ba70(m_p30)) {
            Warning("AIError: Move requested with no route!\n");
            result = 1;
        } else if (!m_p30->m_pWaypoint) {
            result = 2;
        }
        if (result == 0) {
            if (sub_10280a20((void *)m_pOuter))
                return;
            int nLoopCount = 0;
            int moveResult = 1;
            m_b1c = 0;
            while (moveResult >= 0 && !m_b1c) {
                if (((NavMotor *)m_i20)->f30 <= g_104454c4) {
                    moveResult = 0;
                    break;
                }
                switch (m_p30->sub_1030bc00()) {
                case 3:
                    moveResult = vfunc13(a);
                    break;
                case 1:
                    moveResult = vfunc14(a);
                    break;
                case 0:
                case 2:
                    moveResult = vfunc12(a);
                    break;
                default:
                    DevMsg("Bogus route move type!");
                    moveResult = -4;
                    break;
                }
                ++nLoopCount;
                if (nLoopCount > 16) {
                    DevMsg("ERROR: AI navigation not terminating. Possibly bad cyclical solving?\n");
                    goto fail;
                }
            }
            if (moveResult < 0) {
                if (moveResult != -3) {
fail:
                    sub_102f1fa0(4.0f, 0);
                }
                ((NavSelfView *)this)->OnNavFailed(0xc, 1);
            }
            return;
        }
        ((NavSelfView *)this)->OnNavFailed(g_1060fcc4[result], 1);
        return;
    } else if (m_i18 == 3) {
        ((NavMotor *)m_i20)->vfunc5();
        sub_10008832(0);
        return;
    } else if (m_i18 != -1) {
        ((NavMotor *)m_i20)->vfunc10();
    }
}
// END FUNCTION

// FUNCTION: 0x102f02a0 size=0x107
#include "CAI_BaseNPC.h"
#include "CAI_DefMovementSink.h"
#include "CAI_Navigator.h"
#include "CUnknown1030bc20.h"
#include "Vector.h"
extern float g_104454c4;
extern double g_1044fab0;
extern float g_10450564;
extern double g_1044e658;
extern double g_10449280;

float __fastcall sub_102ecce0(void *p);
bool __fastcall sub_102ee680(char *p);

#define OWNER (*(void **)((char *)this - 0xc))
#define ROUTE (*(CAI_NavRoute **)((char *)this + 0x20))
#define GETSPEED248(p) (*(float (__fastcall **)(void *))((char *)*(void ***)(p) + 0x3e0))((void *)(p))

float CAI_Navigator::sub_102f02a0()
{
	float base = ((CAI_DefMovementSink *)((char *)OWNER + 0x19b0))->sink0();
	if (!(base >= g_104454c4))
	{
		CAI_Navigator *pNav = (CAI_Navigator *)((char *)this - 0x10);
		float f = sub_102ecce0(pNav);
		if (sub_102ee680((char *)pNav))
		{
			if (GETSPEED248(OWNER) != g_1044fab0)
			{
				if (ROUTE->m_pWaypoint.m_p != 0 && GETSPEED248(OWNER) > g_104454c4)
				{
					CAI_BaseNPC *pNPC = (CAI_BaseNPC *)OWNER;
					CAI_NavRoute *pRoute = ROUTE;
					const float *pOrigin = (const float *)pNPC->vfunc220();
					const float *pGoal = (const float *)((CUnknown1030bc20 *)pRoute)->sub_1030b7c0();
					float dx = pGoal[0] - pOrigin[0];
					float dy = pGoal[1] - pOrigin[1];
					float dz = pGoal[2] - pOrigin[2];
					float sq = dx * dx + dz * dz;
					float d = FastSqrt(sq + dy * dy);
					if (d < g_10450564)
						return ((g_10450564 - d) * g_1044e658 + g_10449280) * f;
				}
			}
		}
		return f;
	}
	return base;
}
// END FUNCTION

// FUNCTION: 0x102f0400 size=0x146
template <class T> __forceinline T pcd_stage(T x) { return x; }
#include "CAI_Navigator.h"
#include "CHolderInner24.h"
#include "CVariantCopy.h"
#include "CUnknown100290c0.h"
#include "CAI_BaseNPCTroika.h"

extern CUnknown100290c0 *g_10566458;
__declspec(dllimport) void DevMsg(const char *fmt, ...);

#define VV(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();
struct CNavA0 { VV(a) };
struct CNavA1 : CNavA0 { VV(b) };
struct CNavA2 : CNavA1 { VV(c) };
struct CNavA3 : CNavA2 { VV(d) };
struct CNavA4 : CNavA3 { VV(e) };
struct CNavA5 : CNavA4 { VV(f) };
struct CNavA6 : CNavA5 { VV(g) };
struct CNavA7 : CNavA6 { VV(h) };
struct CNavA8 : CNavA7 { VV(i) };
struct CNavA9 : CNavA8 { VV(j) };
struct CNavA10 : CNavA9 { VV(k) };
struct CNavInPassEnt : CNavA10
{
	virtual void l0(); virtual void l1(); virtual void l2(); virtual void l3(); virtual void l4(); virtual void l5(); virtual void l6(); virtual void l7();
	virtual void vfunc118(const char *pszName, CBaseEntity *pActivator, CVariantCopy value, int outputID);
};
struct CNavNextTarget : CNavA10
{
	VV(m) VV(n) VV(o) VV(p) VV(q) VV(r)
	virtual void s0(); virtual void s1();
	virtual CNavNextTarget *vfunc172();
};
struct CNavDoorObj { char m_pad[0x4f8]; int m_i4f8; };
struct CNavDoorEnt { char m_pad[0xa4]; CNavDoorObj *m_pObj; };
struct CNavNpc
{
	void sub_102a0bc0(CHolderInner24_Node *p);
	char sub_1027f550(CNavDoorObj *p);
	void sub_10298800(CNavDoorObj *p);
};
struct CNavOwner
{
	char m_pad[0x98];
	CNavNpc *m_p98;
	char m_pad2[0x5de8 - 0x9c];
	CNavNextTarget *m_p5de8;
	const char *sub_1000b5cd();
};

#define OWNER ((CNavOwner *)m_pOuter)

void CAI_Navigator::sub_102f0400()
{
	CHolderInner24_Node *node = ((CHolderInner24 *)m_p30)->m_pNode;
	if (node->m_flags28 & 2) {
		CNavInPassEnt *pEnt = (CNavInPassEnt *)g_10566458->sub_100290c0(&node->m_h20);
		if (pEnt) {
			CVariantCopy v;
			pEnt->vfunc118("InPass", sub_102f05b0(pEnt), v, 0);
		}
	}
	if (((CHolderInner24 *)m_p30)->sub_1030bd50())
		return;
	CNavNpc *npc = OWNER->m_p98;
	if (npc) {
		npc->sub_102a0bc0(node);
		if (node->m_flags28 & 0x10) {
			CNavDoorEnt *pDoor = (CNavDoorEnt *)node->m_h24.Get();
			if (pDoor) {
				CNavDoorObj *pObj = pDoor->m_pObj;
				if (pObj) {
					if (npc->sub_1027f550(pObj) && pObj->m_i4f8 == 1)
						npc->sub_10298800(pObj);
				}
			} else {
				DevMsg("%s trying to open a door that has been deleted!\n", OWNER->sub_1000b5cd());
			}
		}
	}
	if (node->m_pNext && (node->m_flags28 & 2)) {
		OWNER->m_p5de8 = pcd_stage(OWNER->m_p5de8->vfunc172());
		sub_102f2330(0);
		return;
	}
	((CHolderInner24 *)m_p30)->sub_1030ba90();
}
// END FUNCTION

// FUNCTION: 0x102f05b0 size=0x4
struct CUnknown102f05b0 { int sub_102f05b0(); };
int CUnknown102f05b0::sub_102f05b0()
{
    return *(int *)((char *)this + 4);
}
// END FUNCTION

// FUNCTION: 0x102f05d0 size=0xcb
#include "CAI_Navigator.h"

#define SV1(p) virtual void p();
#define SV10(p) SV1(p##0) SV1(p##1) SV1(p##2) SV1(p##3) SV1(p##4) SV1(p##5) SV1(p##6) SV1(p##7) SV1(p##8) SV1(p##9)
#define SV100(p) SV10(p##0) SV10(p##1) SV10(p##2) SV10(p##3) SV10(p##4) SV10(p##5) SV10(p##6) SV10(p##7) SV10(p##8) SV10(p##9)
struct CNavOwnerView
{
    SV100(a) SV100(b)
    SV10(c0) SV10(c1)
    virtual const Vector &vfunc220();
};
struct CNavOwnerView2
{
    SV100(a) SV100(b) SV100(c)
    SV10(d) SV10(e) SV10(f) SV10(g) SV10(h) SV10(i)
    SV1(s0) SV1(s1) SV1(s2) SV1(s3) SV1(s4) SV1(s5) SV1(s6) SV1(s7)
    virtual Vector BodyDirection2D();
};
class Vector2D
{
public:
	vec_t x, y;
	vec_t Dot(const Vector2D &v) const { return x * v.x + y * v.y; }
};
inline Vector2D &AsVector2D(Vector &v) { return *(Vector2D *)&v; }

bool CAI_Navigator::sub_102f05d0(const Vector *pTarget)
{
    if (m_f3c != 0.0f)
        return true;
    Vector vecToPos = (*pTarget - ((CNavOwnerView *)m_pOuter)->vfunc220());
    vecToPos.z = 0;
    VectorNormalize(vecToPos);
    float dot = AsVector2D(((CNavOwnerView2 *)m_pOuter)->BodyDirection2D()).Dot(AsVector2D(vecToPos));
    return m_f3c != 0.0f || dot > 0.766f;
}
// END FUNCTION

// FUNCTION: 0x102f06e0 size=0x222
#include "utlmemory.h"
#include "CBaseEntity.h"
#include "CAI_Navigator.h"
#include "CAI_MoveProbe.h"
#include "CEntityVSlots.h"
#include "CGameTrace.h"
#include "Ray_t.h"
#include "CTraceFilterSimple.h"
#include "CTraceFilterNoCharacterCollide.h"
#include "CUnknown1070b254.h"
#include "CUnknown10738960.h"
#include "CUnknown1003ff80.h"
#include "CGlobalEntityList.h"
#include "CBaseDoor.h"
#include "CAI_BaseNPCTroika.h"

class CUnknown1004f860 { public: void *sub_1004f860(); };
extern CGlobalEntityList *g_10566458;
void sub_10146570(const float *pStart, const float *pEnd, int r, int g, int b, int a, float flDuration);

struct AILocalMoveGoal_t
{
	float m_f[10];
	float m_flMaxDist;	// 0x28
	float m_g[6];
	AIMoveTrace_t m_moveTrace;	// 0x44
	AILocalMoveGoal_t() { memset(this, 0, sizeof(*this)); }
};

inline float LenGrp(const Vector &v)
{
	return FastSqrt(v.x * v.x + (v.y * v.y + v.z * v.z));
}

#define OUTER ((CEntityVSlots *)m_pOuter)

// TARGET: CAI_Navigator::sub_102f06e0
bool CAI_Navigator::sub_102f06e0(void *pWaypoint, char *pbDone)
{
	unsigned int mask = 0x2400b;
	if (m_p30->m_b01)
		mask = 0x2600b;
	CGameTrace trace;
	((CUnknown1003ff80 *)&trace)->sub_1003ff80();
	CEntityVSlots *pOuter = OUTER;
	Vector vecEye;
	Vector *pEye = pOuter->slot193(&vecEye);
	{
		Ray_t ray;
		((CUnknown1004f860 *)&ray)->sub_1004f860();
		ray.sub_1004f7a0(pEye->Base(), (const float *)pWaypoint);
		CTraceFilterSimple filter(pOuter, 0);
		g_1070b254->vfunc4(&ray, mask, (CTraceFilterNoCharacterCollide *)&filter, &trace);
	}
	if (g_10738960.sub_1005f190())
		sub_10146570(trace.m_startpos, trace.m_endpos, 0xff, 0, 0, 1, -1.0f);
	if (trace.m_fraction == 1.0) {
		AIMoveTrace_t mt;
		CAI_NavRoute *pRoute = m_p30;
		((CAI_MoveProbe *)m_i24)->sub_102e6d70(m_i18, OUTER->slot220()->Base(), (const float *)pWaypoint, mask, (const CBaseEntity *)g_10566458->sub_100290c0((unsigned int *)((char *)pRoute + 0x30)), 100.0f, 0, &mt, 0, 0);
		return mt.fStatus >= 0;
	}
	CBaseEntity *pHit = trace.m_pEnt;
	if (pHit) {
		CBaseDoor *pDoor = *(CBaseDoor **)((char *)pHit + 0xa4);
		if (pDoor) {
			CBaseEntity *pNpc = (CBaseEntity *)OUTER;
			if (!pDoor->sub_100eec70(pNpc)) {
				AILocalMoveGoal_t goal;
				float flLen = LenGrp(*(Vector *)trace.m_startpos - *(Vector *)trace.m_endpos);
				int result;
				goal.m_flMaxDist = flLen + 10.0f;
				if (OUTER->slot531(&goal, (CEntityVSlots *)pDoor, flLen, &result)) {
					*pbDone = 1;
					if (result) {
						vfunc10(0xe, 1.4012985e-45f);
						((CAI_BaseNPCTroika *)OUTER)->sub_1027de00((CBaseEntity *)pDoor);
					}
				}
			}
		}
	}
	return false;
}
// END FUNCTION

// FUNCTION: 0x102f09a0 size=0xc2
#include "CUnknown102f09a0.h"
#include "CAI_Waypoint.h"

struct CWaypointFieldsView {
	Vector m_vecPosition;	// 0x00
	char m_pad000c[0x2c - 0xc];
	int m_n2c;	// 0x2c
	CAI_Waypoint *m_pNext;	// 0x30
	int NavType() const { return m_n2c; }
};

// TARGET: CUnknown102f09a0::sub_102f09a0
void CUnknown102f09a0::sub_102f09a0(CAI_Waypoint *pWaypoint, const float *pPosition)
{
	CWaypointFieldsView *pView = (CWaypointFieldsView *)pWaypoint;
	if (*(const Vector *)pPosition != pView->m_vecPosition) {
		CAI_Waypoint *pNext = pView->m_pNext;
		CAI_Waypoint *pNew = new CAI_Waypoint(pPosition, 0, pView->NavType(), 0, -1);
		while ((CAI_Waypoint *)m_pRoute->m_pNode != pNext)
			m_pRoute->sub_1030ba90();
		pNew->SetNext(pNext);
		m_pRoute->sub_1030b4d0((CHolderInner24_Node *)pNew, 0);
	} else {
		while ((CAI_Waypoint *)m_pRoute->m_pNode != pWaypoint)
			m_pRoute->sub_1030ba90();
	}
}
// END FUNCTION

// FUNCTION: 0x102f0ab0 size=0x2a0
#include "CAI_Navigator.h"
#include "CEntityVSlots.h"
#include "CUnk102ee940.h"
#include "Vector.h"

float __cdecl sub_10146150(const Vector *pVec);

struct SimplifyForwardScanParams
{
	float scanDist;
	float radius;
	float increment;
	float maxSamples;
};

struct CAI_NavigatorScan : CAI_Navigator
{
	bool sub_102f0ab0(const SimplifyForwardScanParams &params, CAI_NavPathNode *pCurWaypoint, const Vector &curPoint, float distRemaining, bool skipTest, int *pTestCount, char *pbDone);
	bool sub_10006726(const SimplifyForwardScanParams &params, CAI_NavPathNode *pCurWaypoint, const Vector &curPoint, float distRemaining, bool skipTest, int *pTestCount, char *pbDone);
	void sub_102f09a0(CAI_NavPathNode *pWaypoint, const Vector &point);
};

inline const Vector &GetPos(const CAI_NavPathNode *p) { return *(const Vector *)&p->m_v3Pos; }

inline float ComputePathDistance(int navType, const Vector &start, const Vector &end)
{
	if (navType == 0)
		return (end - start).Length2D();
	else
		return (end - start).Length();
}

// TARGET: CAI_NavigatorScan::sub_102f0ab0
bool CAI_NavigatorScan::sub_102f0ab0(const SimplifyForwardScanParams &params, CAI_NavPathNode *pCurWaypoint, const Vector &curPoint,
                                 float distRemaining, bool skipTest, int *pTestCount, char *pbDone)
{
	if (!(*pTestCount >= params.maxSamples))
	{
		CAI_NavPathNode *pNextWaypoint = pCurWaypoint->m_p30;
		if (distRemaining > 0 && pNextWaypoint && pCurWaypoint->m_p2c == pNextWaypoint->m_p2c && !(pCurWaypoint->m_flags28 & 0x2a))
		{
			Vector nextPoint;
			CAI_NavPathNode *pWaypoint;
			float distToNext;
			if (m_i18 == 0)
			{
				Vector delta = GetPos(pNextWaypoint) - curPoint;
				distToNext = ((CUnk102ee940 *)&delta)->sub_102ee940();
			}
			else
			{
				distToNext = sub_10146150(&((Vector *)&pNextWaypoint->m_v3Pos)->sub_10146190(curPoint));
			}
			if (distToNext < params.increment * 1.10)
			{
				nextPoint = GetPos(pNextWaypoint);
				distRemaining -= distToNext;
				pWaypoint = pNextWaypoint;
			}
			else
			{
				Vector offset = GetPos(pNextWaypoint) - GetPos(pCurWaypoint);
				VectorNormalize(offset);
				offset *= params.increment;
				nextPoint = curPoint + offset;
				distRemaining -= params.increment;
				pWaypoint = pCurWaypoint;
			}

			int navType = m_i18;
			bool skipTestNext = (ComputePathDistance(navType, *((CEntityVSlots *)m_pOuter)->slot220(), nextPoint) > params.radius + 0.1);
			if (sub_10006726(params, pWaypoint, nextPoint, distRemaining, skipTestNext, pTestCount, pbDone))
				return true;
			if (*pbDone)
				return false;
		}

		if (!skipTest && sub_102f05d0(&curPoint))
		{
			++*pTestCount;
			if (sub_102f06e0((void *)&curPoint, pbDone))
			{
				sub_102f09a0(pCurWaypoint, curPoint);
				return true;
			}
		}
	}
	return false;
}
// END FUNCTION

// FUNCTION: 0x102f0e00 size=0x5d
#include "CAI_Navigator.h"
struct CAI_NavigatorView : CAI_Navigator
{
	char sub_102f0ab0(const float *pf, CAI_NavWaypoint *a, CAI_NavWaypoint *b, float flDiff, int c, int *pOut, char *pbDone);
};

// TARGET: CAI_Navigator::sub_102f0e00
bool CAI_Navigator::sub_102f0e00(const float *pfThreshold, char *pbDone)
{
	CAI_NavWaypoint *pWp = m_p30->m_pWaypoint.m_p;
	int pOut;
	float flDiff = *pfThreshold - sub_102f1cf0();
	pOut = 0;
	if (flDiff < 0.1)
		return false;
	char c = ((CAI_NavigatorView *)this)->sub_102f0ab0(pfThreshold, pWp, pWp, flDiff, 1, &pOut, pbDone);
	return c ? true : false;
}
// END FUNCTION

// FUNCTION: 0x102f0e80 size=0x104
#include "CAI_Navigator.h"
#include "CHolderInner24.h"
#include "CEntityVSlots.h"
#include "CUnknown10936c84.h"

extern CUnknown10936c84 g_10936c84;
extern float g_1060fcd8;

bool CAI_Navigator::sub_102f0e80(char *pbDone)
{
	CHolderInner24 *pRoute = (CHolderInner24 *)m_p30;
	CHolderInner24_Node *pNode = pRoute->m_pNode;
	CHolderInner24_Node *pNext = pNode->m_pNext;
	if (pNext) {
		if (sub_102f0e00(&g_1060fcd8, pbDone))
			return true;
		if (*pbDone == 0 && sub_102f05d0((const Vector *)pNext)) {
			int bFlag = m_i18;
			const float *pOrigin = (const float *)((CEntityVSlots *)m_pOuter)->slot220();
			const float *pPos = (const float *)pNext;
			float dx = pPos[0] - pOrigin[0];
			float dy = pPos[1] - *(pOrigin + 1);
			float flDist;
			if (bFlag == 0) {
				float t1 = dx * dx; float t0 = t1 + dy * dy; flDist = FastSqrt(t0);
			} else {
				float dz = pPos[2] - pOrigin[2];
				flDist = FastSqrt(dz * dz + dx * dx + dy * dy);
			}
			if (flDist < g_1060fcd8 && sub_102f06e0(pNext, pbDone)) {
				if (pNode->m_pNext)
					pNode->m_pNext->m_pPrev = pNode->m_pPrev;
				if (pNode->m_pPrev)
					pNode->m_pPrev->m_pNext = pNode->m_pNext;
				g_10936c84.sub_1013dce0((CChainNodeStub *)pNode);
				((CHolderInner24 *)m_p30)->sub_1030b4d0(pNext, 0);
				return true;
			}
		}
	}
	return false;
}
// END FUNCTION

// FUNCTION: 0x102f0fe0 size=0x2f8
// TARGET: CAI_Navigator::sub_102f0fe0
#include "CAI_Navigator.h"
#include "CEntityVSlots.h"
#include "CEHandleGet.h"

struct CNavFinderView
{
	int sub_10304130(const Vector *pOrigin, const Vector *pPoint, CEntityVSlots *pEnt, int a, int b, int flags, float c, int d);
};
struct CNavNodeList
{
	void sub_1013dce0(CAI_NavPathNode *p);
};
struct CNavRouteView : CAI_NavRoute
{
	void sub_1030b4d0(int a, int b);
	const EHANDLE &Target() const { return *(const EHANDLE *)&m_i30; }
	CEntityVSlots *GetTarget() const { return (CEntityVSlots *)Target().Get(); }
	float GetTolerance() const { return *(const float *)&m_i28; }
};
extern CNavNodeList g_10936c84;
void sub_1031a050(void *p);
void sub_1031a0e0(int a, int b);
float sub_10146150(Vector *p);
inline void CopyVec(Vector &d, const Vector &s) { *(CAI_NavVec3 *)&d = *(const CAI_NavVec3 *)&s; }

bool CAI_Navigator::sub_102f0fe0(char *pbDone)
{
	CAI_NavPathNode *pNode = (CAI_NavPathNode *)m_p30->m_pWaypoint.m_p;
	CAI_NavPathNode *pOther = pNode->m_p30;
	if (!pOther || !(pOther->m_flags28 & 4) || pOther->m_p2c || pNode->m_p2c || !(4 & pNode->m_flags28))
		return false; else { float flTolerance;
	Vector vecOther;
	float t;
	{
		Vector vecOwner = *((CEntityVSlots *)m_pOuter)->slot220() - *(Vector *)&pNode->m_v3Pos;
		CopyVec(vecOther, *(Vector *)pOther - *(Vector *)&pNode->m_v3Pos);
		VectorNormalize(vecOther);
		vecOwner.z = 0;
		vecOther.z = 0;
		float flLen = sub_10146150(&vecOwner);
		t = vecOwner.x * vecOther.x + vecOwner.y * vecOther.y + 0.0f * vecOther.z;
		flTolerance = ((CNavRouteView *)m_p30)->GetTolerance();
		if (!(t > flLen * 0.5))
			return false;
	}
	{
	Vector vecPoint = vecOther * t + *(Vector *)&pNode->m_v3Pos;
	int flags = 0;
	if (((CEntityVSlots *)m_pOuter)->slot513() & 1)
		flags = 1;
	if (((CEntityVSlots *)m_pOuter)->slot513() & 2)
		flags |= 4;
	int e1 = ((CNavFinderView *)sub_102ecc00())->sub_10304130(((CEntityVSlots *)m_pOuter)->slot220(), &vecPoint, ((CNavRouteView *)m_p30)->GetTarget(), 1, -1, flags, flTolerance, 0);
	if (!e1)
		return false;
	int e2 = ((CNavFinderView *)sub_102ecc00())->sub_10304130(&vecPoint, (const Vector *)pOther, ((CNavRouteView *)m_p30)->GetTarget(), 1, -1, flags, flTolerance, 0);
	if (!e2)
	{
		sub_1031a050((void *)e1);
		return false;
	}
	sub_1031a0e0(e1, e2);
	sub_1031a0e0(e1, (int)pOther->m_p30);
	CAI_NavPathNode *pPrev = pNode->m_p30;
	if (pPrev)
		pPrev->m_p34 = pNode->m_p34;
	if (pNode->m_p34)
		pNode->m_p34->m_p30 = pNode->m_p30;
	g_10936c84.sub_1013dce0(pNode);
	if (pPrev)
	{
		if (pPrev->m_p30)
			pPrev->m_p30->m_p34 = pPrev->m_p34;
		if (pPrev->m_p34)
			pPrev->m_p34->m_p30 = pPrev->m_p30;
		g_10936c84.sub_1013dce0(pPrev);
	}
	((CNavRouteView *)m_p30)->sub_1030b4d0(e1, 0);
	}
	return true; }
}
// END FUNCTION

// FUNCTION: 0x102f13a0 size=0x17
extern int g_1060fce8;

struct CUnk102f13a0 {
    bool sub_102f13a0(int a);
    char sub_102f0e00(void *p, int a);
};

bool CUnk102f13a0::sub_102f13a0(int a)
{
    if (sub_102f0e00(&g_1060fce8, a))
        return true;
    return false;
}
// END FUNCTION

// FUNCTION: 0x102f13d0 size=0xeb
#include "CAI_Navigator.h"
#include "CUnknown1027d990.h"

struct NavLink_t {
	char pad[0x2c];
	int n2c;
};

struct NavWp_t {
	char pad[0x28];
	unsigned char bFlags;
	char pad29[3];
	int n2c;
	NavLink_t *pLink;
};

struct NavTimerView_t {
	char pad[0x24];
	NavWp_t *pWp;
};

struct NavSelfView_t {
	char pad[0x30];
	NavTimerView_t *pRoute;
	char pad34[0x38 - 0x34];
	float flNext;
	float flArg;
};


extern float g_1049d988;

bool CAI_Navigator::sub_102f13d0(unsigned char bArg)
{
	NavSelfView_t *pView = (NavSelfView_t *)this;
	pView->flArg = (float)bArg;
	int nState = ((CUnknown1027d990 *)m_pOuter)->sub_1027d990();
	if (nState == 0 || nState == 2) {
		NavWp_t *pWp = pView->pRoute->pWp;
		if (pWp) {
			NavLink_t *pLink = pWp->pLink;
			if (pLink && pWp->n2c == pLink->n2c && !(pWp->bFlags & 0x2a)) {
				char bDone = 0;
				if (pView->flArg != 0.0f || pView->flNext <= gpGlobals->curtime) {
					pView->flNext = g_1049d988 + gpGlobals->curtime;
					if (sub_102f0e80(&bDone))
						return true;
					if (bDone)
						return false;
					if (sub_102f0fe0(&bDone))
						return true;
					if (bDone)
						return false;
				}
				if (sub_102f13a0(&bDone))
					return true;
			}
		}
	}
	return false;
}
// END FUNCTION

// FUNCTION: 0x102f1500 size=0xda
#include "CEntityVSlots.h"

struct HelperParams102f1500
{
	int m_n0;
	float m_f4;
	float m_f8;
	float m_fC;
	float m_f10;
	float Get10() { return m_f10; }
};

struct View102f1500
{
	char pad0[0x28];
	float m_f28;
	float Get() { return m_f28; }
};

struct CUnknown102ee120_y
{
	char pad0[4];
	CEntityVSlots *m_pEntity;
	char pad8[0x28];
	View102f1500 *m_p30;

	char sub_102ee6a0();
	Vector *sub_102ee5e0();
	char sub_102ee660();
	void sub_102f0400();
	char sub_102f1690(HelperParams102f1500 *pParams);
	int sub_102f1500(HelperParams102f1500 *pParams);
};

int CUnknown102ee120_y::sub_102f1500(HelperParams102f1500 *pParams)
{
	int nResult = 0;
	if (sub_102ee6a0())
	{
		const Vector *pOrigin = m_pEntity->slot220();
		const Vector *pPos = sub_102ee5e0();
		float dx = pPos->x - pOrigin->x;
		float dy = pPos->y - pOrigin->y;
		float dz = pPos->z - pOrigin->z;
		float flDist = FastSqrt(dz * dz + dy * dy + dx * dx);
		if (sub_102ee660())
		{
			if (flDist <= ((pParams->Get10() > m_p30->Get()) ? pParams->Get10() : m_p30->Get()))
				return 2;
		}
		else
		{
			if (flDist <= pParams->m_fC)
			{
				sub_102f0400();
				nResult = 1;
			}
			if (sub_102f1690(pParams))
				return 1;
		}
	}
	return nResult;
}
// END FUNCTION

// FUNCTION: 0x102f1620 size=0x50
struct HelperParams102f1690
{
	int m_n0;
	float m_fl4;
	float m_fl8;
	float m_flC;
	float m_fl10;
	int m_n14;
	int m_n18;
	bool m_b1c;
};

struct CUnknown102ee120_x
{
	bool sub_102f1690(HelperParams102f1690 *pParams);
	void sub_102f1620(int a, int b, float c, float d, int e);
};

void CUnknown102ee120_x::sub_102f1620(int a, int b, float c, float d, int e)
{
	HelperParams102f1690 params;
	params.m_n0 = a;
	params.m_fl4 = c;
	params.m_fl8 = d;
	params.m_flC = 0;
	params.m_fl10 = 0;
	params.m_n14 = e;
	params.m_n18 = b;
	params.m_b1c = true;
	sub_102f1690(&params);
}
// END FUNCTION

// FUNCTION: 0x102f1690 size=0x168
#include "CUnknown102ee120.h"
extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)

#define VP(n) virtual void v##n();
#define VP10(n) VP(n##0) VP(n##1) VP(n##2) VP(n##3) VP(n##4) VP(n##5) VP(n##6) VP(n##7) VP(n##8) VP(n##9)
struct HelperEnt102f1690
{
	VP10(0) VP10(1) VP10(2) VP10(3) VP10(4) VP10(5) VP10(6) VP10(7) VP10(8) VP10(9)
	VP10(10) VP10(11) VP10(12) VP10(13) VP10(14) VP10(15) VP10(16) VP10(17) VP10(18) VP10(19)
	VP10(20) VP(210) VP(211) VP(212) VP(213) VP(214) VP(215) VP(216) VP(217) VP(218) VP(219)
	virtual float *v220();
};

struct HelperTrace102f1690
{
	int m_0;
	int pad4[6];
	int m_1c;
	int pad20;
	float m_24;
	int pad28[4];
};

struct HelperParams102f1690
{
	int m_0;
	float m_4;
	float m_8;
	int pad0c[2];
	int m_14;
	int m_18;
	char m_1c;
};

struct HelperTracer102f1690
{
	void sub_102e6d70(int a, float *b, int c, int d, int e, float f, int g, HelperTrace102f1690 *h, int i, int j);
};

struct HelperSelf102f1690
{
	char pad0[4];
	HelperEnt102f1690 *m_4;
	char pad8[0x1c];
	HelperTracer102f1690 *m_24;
	char pad28[8];
	CUnknown1030bc20 *m_30;
};

class CUnknown1030bc20_x : public CUnknown1030bc20
{
public:
	bool sub_1030bd50();
	int sub_1030b7e0();
};

extern float (*g_10579660)(float);

static inline float Dist102f1690(const float *b, const float *a)
{
	float dx = b[0] - a[0];
	float dy = b[1] - a[1];
	float dz = b[2] - a[2];
	return g_10579660(dx * dx + dy * dy + dz * dz);
}

class CUnknown102ee120_x : public CUnknown102ee120
{
public:
	bool sub_102f1690(HelperParams102f1690 *p);
	void sub_102f0400();
	void sub_102ede30(float f, int a);
};

bool CUnknown102ee120_x::sub_102f1690(HelperParams102f1690 *p)
{
	HelperSelf102f1690 *self = (HelperSelf102f1690 *)this;
	if (((CUnknown1030bc20_x *)self->m_30)->m_unk24 == 0)
		return false;
	bool result = false;
	if ((p->m_1c && !(((CUnknown1030bc20_x *)self->m_30)->sub_1030bc20() & 0x22))
		|| Dist102f1690((float *)sub_102ee5e0(), self->m_4->v220()) < p->m_4)
	{
		if (((CUnknown1030bc20_x *)self->m_30)->sub_1030bd50())
			return false;
		HelperTrace102f1690 tr;
		memset(&tr, 0, sizeof(tr));
		CUnknown1030bc20_x *t = (CUnknown1030bc20_x *)self->m_30;
		float *eye = self->m_4->v220();
		HelperTracer102f1690 *tracer = self->m_24;
		int p18 = p->m_18;
		int p0 = p->m_0;
		int mask = t->sub_1030b7e0();
		tracer->sub_102e6d70(2, eye, mask, p0, p18, 100.0f, 0, &tr, 0, 0);
		if (tr.m_24 - p->m_8 < 0.01 || (p->m_14 == 2 && tr.m_0 == -3))
		{
			sub_102f0400();
			result = true;
		}
		else if (tr.m_1c != 0 && p->m_14 == 1)
		{
			sub_102ede30(tr.m_24, 0);
		}
	}
	return result;
}
// END FUNCTION

// FUNCTION: 0x102f1860 size=0x79
#include "Vector.h"

#define V10(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();
#define V100(p) V10(p##0) V10(p##1) V10(p##2) V10(p##3) V10(p##4) V10(p##5) V10(p##6) V10(p##7) V10(p##8) V10(p##9)

struct CSlot514View
{
	V100(a) V100(b) V100(c) V100(d) V100(e)
	V10(f0) virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13();
	virtual void slot514(int nType, const Vector *pA, const Vector *pB, float *pDist);
};

class CUnknown102f1860
{
public:
	int m_n0004;
	CSlot514View *m_pTarget;	// 0x04
	float sub_102f1860(int nType, const Vector &vecA, const Vector &vecB);
};

float CUnknown102f1860::sub_102f1860(int nType, const Vector &vecA, const Vector &vecB)
{
	float flDist = (vecA - vecB).Length();
	if (nType == 2 || nType == 8)
		flDist += flDist;
	m_pTarget->slot514(nType, &vecA, &vecB, &flDist);
	return flDist;
}
// END FUNCTION

// FUNCTION: 0x102f1900 size=0xd2
#include "CAI_Pathfinder.h"

extern void (__cdecl *g_109f3630)(const char *fmt, ...);	// DevMsg
extern int g_106c994c;

// TARGET: CAI_Pathfinder::sub_102f1900
char CAI_Pathfinder::sub_102f1900(int nodeNum, unsigned int collisionMask)
{
	float vecPosition[3];
	CAI_PathfinderNode *pNode;
	if (!m_pNetwork) {
		g_109f3630("CanFitAtNode() called with no network!\n");
		return 0;
	}
	if (nodeNum >= 0 && nodeNum < m_pNetwork->m_nNodes) {
		pNode = m_pNetwork->m_ppNodes[nodeNum];
	} else {
		g_106c994c++;
		pNode = 0;
	}
	pNode->sub_102fb0d0(vecPosition, m_n08);
	if (pNode->m_nType == 2) {
		CAI_MoveProbe *pProbe = m_pMoveProbe;
		if (!pProbe->sub_102e7270(vecPosition, collisionMask, 0, 0, 0, 0))
			return 0;
	}
	if (pNode->m_nType == 4 && (pNode->m_fFlags & 0x1d)) {
		CAI_MoveProbe *pProbe = m_pMoveProbe;
		if (!pProbe->sub_102e7270(vecPosition, collisionMask, 0, 0, 0, 0))
			return 0;
	}
	return sub_102f1a20(vecPosition, collisionMask) != 0;
}
// END FUNCTION
