// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100e6d60 size=0xa4
#include "CGameMovement.h"
#include "CUnknown10739d08.h"

extern CUnknown10739d08 g_105e8120;

inline void SetVec(Vector &v, float x, float y, float z)
{
	v.x = x;
	v.y = y;
	v.z = z;
}

CGameMovement::CGameMovement()
{
	m_field0c = 0;
	m_field10 = 0;
	m_pPlayer = 0;
	SetVec(m_vecHullMin, -16.0f, -16.0f, 0.0f);
	SetVec(m_vecHullMax, 16.0f, 16.0f, 72.0f);
	SetVec(m_vecDuckHullMin, -16.0f, -16.0f, 0.0f);
	SetVec(m_vecDuckHullMax, 16.0f, 16.0f, 36.0f);
	SetVec(m_vecView, 0.0f, 0.0f, 64.0f);
	SetVec(m_vecDuckView, 0.0f, 0.0f, 30.0f);
	SetVec(m_vecObsHullMin, -10.0f, -10.0f, -10.0f);
	SetVec(m_vecObsHullMax, 10.0f, 10.0f, 10.0f);
	m_field98 = 0;
	m_fieldA0 = 1.0f;
	m_fieldA8 = g_105e8120.sub_1014cfb0();
}
// END FUNCTION

// FUNCTION: 0x100e6e10 size=0x3
#include "CGameMovement.h"
void CGameMovement::vfunc13(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x100e6e20 size=0x1e
#include "CGameMovement.h"
namespace lifted {
int sub_100e6e40();
int sub_101d1296(int);
}
CGameMovement * CGameMovement::vfunc0(unsigned int a0)
{
    int t0 = lifted::sub_100e6e40();
    if ((*(char *)&a0 & 1) != 0) {
        lifted::sub_101d1296((int)this);
    }
    return this;
}
// END FUNCTION

// FUNCTION: 0x100e6e70 size=0x2f
#include "CGameMovement.h"

// TARGET: CGameMovement::vfunc14
int CGameMovement::vfunc14(int type)
{
	switch (type) {
	case 0:
		return 0x14;
	case 1:
		return 0x1a;
	case 2:
		return 0xd;
	}
	return 1;
}
// END FUNCTION

// FUNCTION: 0x100e6eb0 size=0x11
#include "CGameMovement.h"
float * CGameMovement::vfunc2(char a0, int a1)
{
    if (a0 != 0) {
        return (float *)((char *)this + 0x2c);
    }
    return (float *)((char *)this + 0x14);
}
// END FUNCTION

// FUNCTION: 0x100e6ed0 size=0x11
#include "CGameMovement.h"
float * CGameMovement::vfunc3(char a0, int a1)
{
    if (a0 != 0) {
        return (float *)((char *)this + 0x38);
    }
    return (float *)((char *)this + 0x20);
}
// END FUNCTION

// FUNCTION: 0x100e6f50 size=0x11
#include "CGameMovement.h"
float * CGameMovement::vfunc4(char a0, int a1)
{
    if (a0 != 0) {
        return (float *)((char *)this + 0x68);
    }
    return (float *)((char *)this + 0x5c);
}
// END FUNCTION

// FUNCTION: 0x100e6f70 size=0x4f
#include "CGameMovement.h"

struct CGlobalVars_ { char pad[0x14]; int maxClients; };
extern int g_102b8494;

struct Vel { float x; float y; };

char CGameMovement::vfunc15(void *pSurface, float volume)
{
	if ( ((CGlobalVars_ *)(void *)g_102b8494)->maxClients > 1 && m_field10 == 0 )
	{
		Vel *vel = (Vel *)((char *)m_pPlayer + 0x40);
		float len = (*g_102be4dc)(vel->x * vel->x + vel->y * vel->y);
		if ( len <= 195.0f )
			return false;
	}
	return true;
}
// END FUNCTION

// FUNCTION: 0x100e6fc0 size=0xee
#include "CGlobalVarsBase.h"
#include "engineclient.h"
#include "CGameMovement.h"
#include "CGameMovementViews.h"
#include "ConVar.h"


class ISoundEmitter
{
public:
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5();
	virtual int vfunc6(short index);	// slot 6
};

class ISoundSystem
{
public:
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void vfunc5(void *origin, int channel, int name, float volume, int level, int flags, int pitch);	// slot 5
	virtual void v6(); virtual void v7(); virtual void v8();
	virtual ISoundEmitter *GetEmitter();	// slot 9
};


extern ConVar *g_104dfaa4;
extern ISoundSystem *g_104df784;

// TARGET: CGameMovement::vfunc16
void CGameMovement::vfunc16(void *pSurface, float volume, char bForce)
{
	if ( gpGlobals->maxClients > 1 )
	{
		if ( g_104dfaa4->vfunc1() )
			return;
		if ( g_104dfaa4->m_fValue == 0.0f )
			return;
	}
	if ( !pSurface )
		return;
	ISoundEmitter *pEmitter = g_104df784->GetEmitter();
	if ( !bForce )
	{
		if ( !vfunc15(pSurface, volume) )
			return;
	}
	int bAlt = *(int *)((char *)m_pMove + 0x1700);
	unsigned short snd;
	if ( bAlt )
		snd = *(unsigned short *)((char *)pSurface + 0x2c);
	else
		snd = *(unsigned short *)((char *)pSurface + 0x2e);
	*(int *)((char *)m_pMove + 0x1700) = (bAlt == 0);
	if ( snd == 0 )
		return;
	if ( *(char *)m_pPlayer == 0 )
		return;
	int name = pEmitter->vfunc6(snd);
	ISoundSystem *pSys = g_104df784;
	pSys->vfunc5((char *)m_pPlayer + 0x70, 4, name, volume, 0x4b, 0, enginerandom->RandomInt(0, 10) + 0x5f);
}
// END FUNCTION

// FUNCTION: 0x100e7860 size=0x7
#include "CGameMovement.h"
namespace lifted {
extern float g_101e34ec;
}
float CGameMovement::vfunc23()
{
    return lifted::g_101e34ec;
}
// END FUNCTION

// FUNCTION: 0x100e7d30 size=0xe6
#include "CGlobalVarsBase.h"
#include "CGameMovement.h"

struct MoveDataView {
    char m_pad16fc[0x16fc];
    float m_fl16fc;
    char m_pad1700[0x1994 - 0x1700];
    float m_fl1994;
    float m_fl1998;
};



// TARGET: CGameMovement::vfunc24
void CGameMovement::vfunc24()
{
    float fDecay = gpGlobals->frametime * 1000.0f;
    if (((MoveDataView *)m_pMove)->m_fl1994 > 0.0f)
    {
        ((MoveDataView *)m_pMove)->m_fl1994 -= fDecay;
        if (((MoveDataView *)m_pMove)->m_fl1994 < 0.0f)
            ((MoveDataView *)m_pMove)->m_fl1994 = 0.0f;
    }
    if (((MoveDataView *)m_pMove)->m_fl16fc > 0.0f)
    {
        ((MoveDataView *)m_pMove)->m_fl16fc -= fDecay;
        if (((MoveDataView *)m_pMove)->m_fl16fc < 0.0f)
            ((MoveDataView *)m_pMove)->m_fl16fc = 0.0f;
    }
    if (((MoveDataView *)m_pMove)->m_fl1998 > 0.0f)
    {
        ((MoveDataView *)m_pMove)->m_fl1998 -= fDecay;
        if (((MoveDataView *)m_pMove)->m_fl1998 < 0.0f)
            ((MoveDataView *)m_pMove)->m_fl1998 = 0.0f;
    }
}
// END FUNCTION

// FUNCTION: 0x100e7e20 size=0x70
#include "CGlobalVarsBase.h"
#include "CGameMovement.h"


struct G104dfa5cV
{
	virtual void vfunc0();
	virtual bool vfunc1();
	char pad0[0x24];
	float m_field28;	// 0x28
};
extern G104dfa5cV *g_104dfa5c;

void CGameMovement::vfunc1(void *pMove, void *pPlayer)
{
	float savedTime = gpGlobals->frametime;
	sub_100ec390();
	m_bDc = 0;
	m_pMove = pMove;
	m_pPlayer = pPlayer;
	*(float *)((char *)m_pPlayer + 0x38) = g_104dfa5c->vfunc1() ? 0.0f : g_104dfa5c->m_field28;
	vfunc5();
	sub_100e7e90();
	gpGlobals->frametime = savedTime;
}
// END FUNCTION

// FUNCTION: 0x100e7ec0 size=0x2ac
#include "CGlobalVarsBase.h"
#include "CGameMovement.h"


struct CMovePlayer_100e7ec0
{
	char pad_0[0x1078];
	float m_fl1078;             // 0x1078
	char pad_107c[0x69c];
	Vector m_vecPunchAngle;     // 0x1718
	Vector m_vecPunchAngleVel;  // 0x1724
};


#define MV ((CMovePlayer_100e7ec0 *)m_pMove)
#define CLAMP(v, lo, hi) ((v) > (hi) ? (hi) : ((v) < (lo) ? (lo) : (v)))

void CGameMovement::vfunc7()
{
	if (MV->m_vecPunchAngle.LengthSqr() > 0.001 ||
		MV->m_vecPunchAngleVel.LengthSqr() > 0.001)
	{
		*(QAngle *)&MV->m_vecPunchAngle += *(QAngle *)&MV->m_vecPunchAngleVel * gpGlobals->frametime * MV->m_fl1078;

		float flDecay = 1.0f - MV->m_fl1078 * gpGlobals->frametime * 9.0f;
		if (flDecay < 0.0f)
			flDecay = 0.0f;
		MV->m_vecPunchAngleVel *= flDecay;

		float flAngleDecay = MV->m_fl1078 * gpGlobals->frametime * 65.0f;
		if (flAngleDecay > 2.0f)
			flAngleDecay = 2.0f;
		if (flAngleDecay < 0.0f)
			flAngleDecay = 0.0f;

		MV->m_vecPunchAngleVel -= MV->m_vecPunchAngle * flAngleDecay;

		MV->m_vecPunchAngle = Vector(
			CLAMP(MV->m_vecPunchAngle.x, -89.0f, 89.0f),
			CLAMP(MV->m_vecPunchAngle.y, -179.0f, 179.0f),
			CLAMP(MV->m_vecPunchAngle.z, -89.0f, 89.0f));
	}
}
// END FUNCTION

// FUNCTION: 0x100e9640 size=0x29
#include "CGameMovement.h"
struct V100e9640 { char pad[0x1884]; int m_a; char pad2[0x199c - 0x1888]; float m_f; };
char CGameMovement::vfunc9()
{
	V100e9640 *p = (V100e9640 *)m_pMove;
	if (p->m_a)
		return 0;
	if (p->m_f != 0.0f)
		return 0;
	return 1;
}
// END FUNCTION

// FUNCTION: 0x100e9670 size=0x98
#include "CGlobalVarsBase.h"
#include "CGameMovement.h"
#include "CGameMovementViews.h"
#define PLAYER ((CMovePlayerView *)m_pPlayer)
// TARGET: CGameMovement::vfunc10
void CGameMovement::vfunc10(Vector &wishdir, float wishspeed, float accel)
{
    if (!vfunc9())
        return;
    Vector &vel = PLAYER->m_vecVelocity;
    float t1 = wishdir.x; float addspeed = wishspeed - (vel.z * wishdir.z + vel.y * wishdir.y + t1 * vel.x);
    if (addspeed <= 0)
        return;
    float t0 = gpGlobals->frametime * m_fieldA0 * wishspeed; float accelspeed = t0 * accel;
    if (accelspeed > addspeed)
        accelspeed = addspeed;
    for (int i = 0; i < 3; ++i)
        PLAYER->m_vecVelocity[i] += wishdir[i] * accelspeed;
}
// END FUNCTION

// FUNCTION: 0x100e9710 size=0x724
template <class T> __forceinline T pcd_stage(T x) { return x; }
#include "CBaseEntityList.h"
#include "CGameMovement.h"
#include "CGameMovementViews.h"
#include "CVProfile.h"
#include "Ray_t.h"
#include "CGameTrace.h"
#include "CUnknown100290c0.h"
#include "CGlobalVarsBase.h"
#include "ConVar.h"

extern CVProfile *g_101e3138;
typedef void (CVProfile::*EnterScopeFn)(const char *, int, const char *, bool);
typedef void (CVProfile::*ExitScopeFn)();
extern EnterScopeFn g_101e3134;
extern ExitScopeFn g_101e3130;
void sub_100e7380(int, int, int, int, int);
void sub_101090a0(const QAngle &angles, Vector *forward, Vector *right, Vector *up);	// AngleVectors
extern bool g_102bb1a8;	// g_bMovementOptimizations
extern ConVar g_104dfc98;	// sv_accelerate

class CUnknown100e9e40
{
public:
	unsigned int m_Index;
	CUnknown100e9e40() { m_Index = 0xffffffff; }
	void *sub_100e9e40(int pEnt);
};

struct CWalkMoveSub { virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5(); virtual void g6(); virtual unsigned int g7(); };

struct CWalkMoveView
{
	char m_pad0000[0xc];
	CWalkMoveSub m_sub;	// 0xc
	char m_pad0010[0x90 - 0x10];
	int m_nWaterLevel;	// 0x90
	char m_pad0094[0x154 - 0x94];
	Vector m_vecBaseVelocity;	// 0x154
	char m_pad0160[0x1740 - 0x160];
	float m_flStepSize;	// 0x1740
	bool m_bAllowAutoMovement;	// 0x1744
	char m_pad1745[0x199c - 0x1745];
	float m_flWaterJumpTime;	// 0x199c
};

#define PLAYER ((CMovePlayerView *)m_pPlayer)
#define MOVE ((CWalkMoveView *)m_pMove)

inline void TracePlayerBBox(CGameMovement *gm, const Vector &start, const Vector &end, unsigned int fMask, int collisionGroup, CGameTrace &pm)
{
	(g_101e3138->*g_101e3134)("CGameMovement::TracePlayerBBox", 0, "Unaccounted", false);
	Ray_t ray;
	ray.sub_100e91e0(start, end, gm->sub_100e6ef0(), (float *)gm->sub_100e6f20(), (char)((((CWalkMoveView *)gm->m_pMove)->m_sub.g7() >> 6) & 1), 0);
	sub_100e7380((int)&ray, fMask, ((CUnknown100290c0 *)g_pEntityList)->sub_1007aca0(&((CMovePlayerView *)gm->m_pPlayer)->m_hRef), collisionGroup, (int)&pm);
	(g_101e3138->*g_101e3130)();
}

void CGameMovement::vfunc11()
{
	int i;
	Vector wishvel;
	float fmove, smove;
	Vector wishdir;
	float wishspeed;
	Vector dest;
	CGameTrace pm;
	Vector forward, right, up;
	Vector original, originalvel, down, downvel;
	sub_101090a0(*(QAngle *)&PLAYER->m_vec58, &forward, &right, &up);

	float downdist, updist;

	CUnknown100e9e40 oldground;
	oldground.sub_100e9e40((int)((CMoveDataView *)m_pMove)->g104());

	fmove = PLAYER->m_flForwardMove;
	smove = PLAYER->m_flSideMove;

	if (g_102bb1a8)
	{
		if (forward[2] != 0)
		{
			forward[2] = 0;
			VectorNormalize(forward);
		}
		if (right[2] != 0)
		{
			right[2] = 0;
			VectorNormalize(right);
		}
	}
	else
	{
		forward[2] = 0;
		right[2] = 0;
		VectorNormalize(forward);
		VectorNormalize(right);
	}

	i = 0; while (i < 2) { wishvel[i] = fmove * forward[i] + right[i] * smove; i = 1 + i; }
	wishvel[2] = 0;

	VectorCopy(wishvel, wishdir);
	wishspeed = VectorNormalize(wishdir);

	if (wishspeed > PLAYER->m_flMaxSpeed)
	{
		VectorScale(wishvel, PLAYER->m_flMaxSpeed / wishspeed, wishvel);
		wishspeed = PLAYER->m_flMaxSpeed;
	}

	PLAYER->m_vecVelocity[2] = 0;
	if (pcd_stage(PLAYER->m_bD0))
	{
		PLAYER->m_vecVelocity = wishvel;
	}
	else
	{
		vfunc10(wishdir, wishspeed, g_104dfc98.GetFloat());
	}
	PLAYER->m_vecVelocity[2] = 0;

	VectorAdd(PLAYER->m_vecVelocity, MOVE->m_vecBaseVelocity, PLAYER->m_vecVelocity);

	if (PLAYER->m_vecVelocity.Length() < 1.0f)
	{
		PLAYER->m_vecVelocity.Init();
		return;
	}

	dest[0] = PLAYER->m_vecOrigin[0] + PLAYER->m_vecVelocity[0] * gpGlobals->frametime;
	dest[1] = PLAYER->m_vecOrigin[1] + gpGlobals->frametime * PLAYER->m_vecVelocity[1];
	dest[2] = PLAYER->m_vecOrigin[2];

	TracePlayerBBox(this, PLAYER->m_vecOrigin, dest, 0x201400b, 6, pm);

	PLAYER->m_vec80 += (wishdir * wishspeed);

	if (pm.m_fraction == 1)
	{
		VectorCopy(*(Vector *)pm.m_endpos, PLAYER->m_vecOrigin);
		return;
	}

	if (0 == ((CUnknown100290c0 *)g_pEntityList)->sub_1007aca0(&oldground.m_Index) && MOVE->m_nWaterLevel == 0)
		return; else { if (!(MOVE->m_flWaterJumpTime)) { VectorCopy(PLAYER->m_vecOrigin, original);
	VectorCopy(PLAYER->m_vecVelocity, originalvel);

	slot19((int)&dest, (int)&pm);

	VectorCopy(PLAYER->m_vecOrigin, down);
	VectorCopy(PLAYER->m_vecVelocity, downvel);

	VectorCopy(original, PLAYER->m_vecOrigin);
	VectorCopy(originalvel, PLAYER->m_vecVelocity);

	VectorCopy(PLAYER->m_vecOrigin, dest);
	if (MOVE->m_bAllowAutoMovement)
		dest[2] = MOVE->m_flStepSize + dest[2];

	TracePlayerBBox(this, PLAYER->m_vecOrigin, dest, 0x201400b, 6, pm);

	if (!pm.m_startsolid && !pm.m_allsolid)
		VectorCopy(*(Vector *)pm.m_endpos, PLAYER->m_vecOrigin);

	slot19(0, 0);

	VectorCopy(PLAYER->m_vecOrigin, dest);
	if (MOVE->m_bAllowAutoMovement)
		dest[2] -= MOVE->m_flStepSize;

	TracePlayerBBox(this, PLAYER->m_vecOrigin, dest, 0x201400b, 6, pm);

	if (0.7 > pm.m_planeNormal[2])
		goto usedown;

	if (!pm.m_startsolid && !pm.m_allsolid)
		VectorCopy(*(Vector *)pm.m_endpos, PLAYER->m_vecOrigin);

	VectorCopy(PLAYER->m_vecOrigin, up);

	downdist = (down[0] - original[0]) * (down[0] - original[0])
		+ (down[1] - original[1]) * (down[1] - original[1]);
	updist = ((up[1] - original[1]) * (up[1] - original[1]))
		+ ((up[0] - original[0]) * (up[0] - original[0]));

	if (downdist > updist)
	{
usedown:
		VectorCopy(down, PLAYER->m_vecOrigin);
		VectorCopy(downvel, PLAYER->m_vecVelocity);
	}
	else
		PLAYER->m_vecVelocity[2] = downvel[2];

	float stepDist; stepDist = PLAYER->m_vecOrigin.z - original.z;
	if (stepDist > 0)
		PLAYER->m_fl007C = stepDist + PLAYER->m_fl007C; } }
}
// END FUNCTION

// FUNCTION: 0x100eaa70 size=0x77
#include "CGameMovement.h"

void CGameMovement::vfunc18()
{
	sub_100ec450();
	if (((unsigned char *)m_pPlayer)[0x24] & 2)
		slot17();
	else
		*(int *)((char *)m_pPlayer + 0x28) &= ~2;

	float *p = (float *)m_pPlayer;
	float *b = (float *)((char *)m_pMove + 0x154);
	float fx = p[0x10];
	p[0x10] = fx + b[0];
	float fy = p[0x11];
	p[0x11] = fy + b[1];
	float fz = p[0x12];
	p[0x12] = fz + b[2];

	slot19(0, 0);

	float *p2 = (float *)m_pPlayer;
	float *b2 = (float *)((char *)m_pMove + 0x154);
	float gx = p2[0x10];
	p2[0x10] = gx - b2[0];
	float gy = p2[0x11];
	p2[0x11] = gy - b2[1];
	float gz = p2[0x12];
	p2[0x12] = gz - b2[2];
}
// END FUNCTION

// FUNCTION: 0x100eb1f0 size=0x46
#include "CGameMovement.h"
struct CSurfProp { char pad[0x72]; char m_bFlag; };
struct CSurfSys {
	virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
	virtual CSurfProp *Get(int i);
};
struct CPhysSys {
	virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
	virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8();
	virtual CSurfSys *GetSurfaceProps();
};
struct CTraceView { char pad[0x30]; unsigned int m_flags; char pad2[0xc]; short m_surf; };
extern CPhysSys *g_104df784;

// TARGET: CGameMovement::vfunc21
char CGameMovement::vfunc21(void *pTrace)
{
	CTraceView *t = (CTraceView *)pTrace;
	if (t->m_flags & 0x20000000)
		return 1;
	CSurfSys *p = g_104df784->GetSurfaceProps();
	if (p) {
		CSurfProp *s = p->Get(t->m_surf);
		if (s && s->m_bFlag)
			return 1;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x100eb240 size=0x4fc
#include "CGameMovement.h"
#include "CGameMovementViews.h"
#include "IClientCollideable.h"
#include "CBaseEntityList.h"
#include "CUnknown100290c0.h"
#include "CGlobalVarsBase.h"
#include "CVProfile.h"
#include "Ray_t.h"
#include "engineclient.h"

struct CUnknown1009fc60 { void sub_1009fc60(int a, int b); };
struct CUnknown1009fc90 { int sub_1009fc90(int a); };
struct CUnknown1014cf80 { float sub_1014cf80(); };
struct CUnknown1014cf90 { float sub_1014cf90(); };
struct MoveEnt_100eb240
{
	char m_pad0000[0x160];
	float m_flGravity;	// 0x160
	char m_pad0164[0x19ac - 0x164];
	Vector m_vecLadderNormal;	// 0x19ac
};
extern CUnknown1014cf80 g_105e8120;
extern CVProfile *g_101e3138;
extern Vector g_104d4970;
void sub_10108fd0(const float *start, float scale, const float *direction, float *dest);
void sub_100e7380(int pRay, int fMask, int pIgnore, int collisionGroup, int pTrace);

struct VProfScope_100eb240
{
	VProfScope_100eb240(const char *pszName, int detailLevel, const char *pszBudgetGroupName, bool bAssertAccounted)
	{
		g_101e3138->EnterScope(pszName, detailLevel, pszBudgetGroupName, bAssertAccounted);
	}
	~VProfScope_100eb240() { g_101e3138->ExitScope(); }
};

#define PLAYER ((CMovePlayerView *)m_pPlayer)
#define MOVEENT ((MoveEnt_100eb240 *)m_pMove)
#define COLL ((IClientCollideable *)((char *)m_pMove + 0xc))

char CGameMovement::vfunc20()
{
	CGameTrace pm;
	bool onFloor;
	Vector floor;
	Vector wishdir;
	Vector end;

	if (COLL->GetSolid() == 9)
		return 0;

	if (COLL->GetSolid() == 10)
	{
		wishdir = -MOVEENT->m_vecLadderNormal;
	}
	else
	{
		if (PLAYER->m_flForwardMove || PLAYER->m_flSideMove)
		{
			for (int i = 0; i < 3; i++)
				wishdir[i] = PLAYER->m_flForwardMove * m_vecForward[i] + m_vecRight[i] * PLAYER->m_flSideMove;
			VectorNormalize(wishdir);
		}
		else
		{
			return 0;
		}
	}

	sub_10108fd0(&PLAYER->m_vecOrigin.x, 2.0f, &wishdir.x, &end.x);
	{
		const Vector &start = PLAYER->m_vecOrigin;
		VProfScope_100eb240 vprof("CGameMovement::TracePlayerBBox", 0, "Unaccounted", false);
		Ray_t ray;
		ray.sub_100e91e0(start, end, sub_100e6ef0(), &sub_100e6f20()->x, ((unsigned int)COLL->Collideable_vfunc7() >> 6) & 1, 0);
		sub_100e7380((int)&ray, 0x201400b, (int)((CUnknown100290c0 *)g_pEntityList)->sub_1007aca0(&PLAYER->m_hRef), 6, (int)&pm);
	}

	if (pm.m_fraction == 1.0f || !vfunc21(&pm))
		return 0;

	((CUnknown1009fc60 *)m_pMove)->sub_1009fc60(10, 0);
	((CUnknown1009fc90 *)m_pMove)->sub_1009fc90(0);

	MOVEENT->m_vecLadderNormal = *(Vector *)pm.m_planeNormal;

	floor = PLAYER->m_vecOrigin;
	floor[2] += (sub_100e6ef0()[2] - 1);

	if (enginetrace->GetPointContents(floor, 0) == 1)
		onFloor = true;
	else
		onFloor = false;

	MOVEENT->m_flGravity = 0;

	float forward = 0, right = 0;
	if (PLAYER->m_fFlags24 & 0x10)
		forward = -g_105e8120.sub_1014cf80();
	if (PLAYER->m_fFlags24 & 8)
		forward = g_105e8120.sub_1014cf80();
	if (PLAYER->m_fFlags24 & 0x200)
		right = -((CUnknown1014cf90 *)&g_105e8120)->sub_1014cf90();
	if (PLAYER->m_fFlags24 & 0x400)
		right = ((CUnknown1014cf90 *)&g_105e8120)->sub_1014cf90();

	if (2 & PLAYER->m_fFlags24)
	{
		((CUnknown1009fc60 *)m_pMove)->sub_1009fc60(3, 0);
		PLAYER->m_n00c0 = 7;
		PLAYER->m_flB8 = gpGlobals->curtime;
		((CUnknown1009fc90 *)m_pMove)->sub_1009fc90(0);
		VectorScale(*(Vector *)pm.m_planeNormal, 270, PLAYER->m_vecVelocity);
		PLAYER->m_vecVelocity.z = 0;
	}
	else if (forward != 0 || right != 0)
	{
		Vector velocity, perp, cross, lateral, tmp;
		float normal;
		Vector &n = *(Vector *)pm.m_planeNormal;

		VectorScale(m_vecForward, forward, velocity);
		sub_10108fd0(&velocity.x, right, &m_vecRight.x, &velocity.x);

		tmp = g_104d4970;
		tmp[2] = 1;
		CrossProduct(tmp, n, perp);
		VectorNormalize(perp);

		normal = DotProduct(velocity, n);
		VectorScale(n, normal, cross);
		VectorSubtract(velocity, cross, lateral);

		CrossProduct(n, perp, tmp);
		sub_10108fd0(&lateral.x, -normal, &tmp.x, &PLAYER->m_vecVelocity.x);

		if (onFloor && normal > 0)
			sub_10108fd0(&PLAYER->m_vecVelocity.x, g_105e8120.sub_1014cf80(), &n.x, &PLAYER->m_vecVelocity.x);
	}
	else
	{
		PLAYER->m_vecVelocity.Init();
	}
	return 1;
}
// END FUNCTION

// FUNCTION: 0x100ebc00 size=0x8d
#include "CGameMovement.h"
#include <math.h>
void sub_101090a0(const QAngle &angles, Vector *forward, Vector *right, Vector *up);

// TARGET: CGameMovement::vfunc6
float CGameMovement::vfunc6(const QAngle &angles, const Vector &vec, float scale, float threshold)
{
	Vector forward, right, up;
	sub_101090a0(angles, &forward, &right, &up);
	int sign = -1;
	float d = right.x * vec.x + right.y * vec.y + right.z * vec.z;
	if (!(d < 0.0f))
		sign = 1;
	float s = (float)sign;
	float a = fabs(d);
	if (a < threshold)
		return s * (a / threshold * scale);
	return s * scale;
}
// END FUNCTION

// FUNCTION: 0x100ed950 size=0x4f
#include "CGameMovement.h"
#include "CGameMovementViews.h"

struct VMove_100a2450 { int sub_100a2450(); };

void CGameMovement::vfunc25()
{
	if (m_bDc)
		return;
	if ((((VMove_100a2450 *)m_pMove)->sub_100a2450() & 2) == 0)
		return;
	((CMovePlayerView *)m_pPlayer)->m_flForwardMove *= 0.33333334f;
	((CMovePlayerView *)m_pPlayer)->m_flSideMove *= 0.33333334f;
	((CMovePlayerView *)m_pPlayer)->m_flUpMove *= 0.33333334f;
	m_bDc = 1;
}
// END FUNCTION
