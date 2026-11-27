// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10120e40 size=0x1e
#include "CPrediction.h"

// VC6 writes CPrediction's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CPrediction *pcd_emit_10120e40() { return new CPrediction; }

// TARGET: ??_GCPrediction@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10120e90 size=0x31
#include "CPrediction.h"
struct CV_10120e90 { virtual void v0(); virtual bool v1(); char pad[0x2c - 4]; void *m_p2c; };
extern CV_10120e90 *g_104e170c;
struct View_10120e90 { char pad[0x34]; bool m_b34; };
void CPrediction::vfunc1()
{
	((View_10120e90 *)this)->m_b34 = (g_104e170c->v1() ? 0 : g_104e170c->m_p2c) != 0;
}
// END FUNCTION

// FUNCTION: 0x10120ed0 size=0x1
#include "CPrediction.h"
void CPrediction::vfunc2()
{
}
// END FUNCTION

// FUNCTION: 0x10121c20 size=0x27b
#include "CPrediction.h"
#include "ConVar.h"
#include "engineclient.h"
#include "CClientEntityList.h"
#include "C_BasePlayer.h"

struct NetSub_6 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual int entindex(); };
struct PEnt_6 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual const char *GetClassname();
	int m_n4;
	NetSub_6 m_net;
	char m_pad[0xe4 - 0xc];
	unsigned int m_hHandle;
	bool sub_100a2600();
	void sub_100a2760(bool a, int b);
};
struct IPreds_6 { virtual PEnt_6 *GetPredictable(int i); virtual int GetPredictableCount(); };
extern IPreds_6 *g_102af678;
extern ConVar g_104e1708;
extern ConVar g_104e15c8;
extern ConVar g_104e16b0;
extern char g_102de300[];
extern "C" __declspec(dllimport) int __cdecl Q_snprintf(char *, int, const char *, ...);

// TARGET: CPrediction::vfunc6
void CPrediction::vfunc6(bool error_check, int commands_acknowledged)
{
	bool entityDumped = false;
	if (!C_BasePlayer::GetLocalPlayer())
		return;
	if (g_104e1708.GetInt())
	{
		bool showlist = g_104e15c8.GetBool();
		int c = g_102af678->GetPredictableCount();
		int i;
		for (i = 0; i < c; i++)
		{
			PEnt_6 *ent = g_102af678->GetPredictable(i);
			if (!ent)
				continue;
			if (ent->sub_100a2600())
				ent->sub_100a2760(error_check, commands_acknowledged);
			if (showlist)
			{
				char sz[32];
				if (ent->m_net.entindex() == -1)
					Q_snprintf(sz, sizeof(sz), "handle %u", ent->m_hHandle);
				else
					Q_snprintf(sz, sizeof(sz), "%i", ent->m_net.entindex());
				engine->vfunc60(i, "%s:  %s (%s)", sz, ent->GetClassname(), ent->sub_100a2600() ? "predicted" : "created");
			}
			if (!entityDumped && sub_10121b00(ent))
			{
				entityDumped = true;
				sub_10121150(ent, commands_acknowledged);
			}
		}
		if (showlist)
		{
			while (i < 32)
			{
				engine->vfunc60(i, g_102de300);
				i++;
			}
		}
		if (error_check)
			sub_10120ee0(commands_acknowledged);
	}
	int dumpentindex = g_104e16b0.GetInt();
	if (!entityDumped && dumpentindex != -1)
	{
		int last_entity = ClientEntityList().vfunc6();
		if (dumpentindex >= 0 && dumpentindex <= last_entity)
		{
			C_BaseEntity *ent = ClientEntityList().sub_100d0cf0(dumpentindex);
			if (ent)
				sub_10121150(ent, commands_acknowledged);
		}
	}
	if (g_104e1708.GetInt() && !m_bOldCLPredictValue)
		sub_101219a0();
	m_bOldCLPredictValue = g_104e1708.GetBool();
}
// END FUNCTION

// FUNCTION: 0x10121ea0 size=0x399
#include "Vector.h"
#include "QAngle.h"
#include "CPrediction.h"
#include "C_BasePlayer.h"
#include "CGlobalVarsBase.h"
#include "CVStatList_t.h"
#include "ehandle.h"

struct CMoveDataView
{
    bool m_bFirstRunOfFunctions;    // 0x00
    int m_nPlayerHandle;            // 0x04
    int m_nImpulseCommand;          // 0x08
    QAngle m_vecViewAngles;         // 0x0c
    int m_unk18, m_unk1c, m_unk20;
    int m_nButtons;                 // 0x24
    int m_unk28;
    float m_flForwardMove;          // 0x2c
    float m_flSideMove;             // 0x30
    float m_flUpMove;               // 0x34
    int m_unk38;
    int m_unk3c;
    Vector m_vecVelocity;           // 0x40
    int m_unk4c, m_unk50, m_unk54;
    QAngle m_vecAngles;             // 0x58
    QAngle m_vecOldAngles;          // 0x64
    QAngle m_vecAbsAngles;          // 0x70
    int m_unk7c[(0xa4 - 0x7c) / 4];
    int m_unka4;
    int m_unka8;
    float m_flac;
    int m_unkb0;
    float m_flb4;
    int m_unkb8, m_unkbc;
    int m_unkc0;
    int m_unkc4;
    int m_unkc8, m_unkcc;
    bool m_bd0;
};

struct CUserCmdView
{
    int m_unk00[5];
    QAngle viewangles;      // 0x14
    float forwardmove;      // 0x20
    float sidemove;         // 0x24
    float upmove;           // 0x28
    int m_unk2c;
    int buttons;            // 0x30
    int m_unk34;
    unsigned char impulse;  // 0x38
};

class CUnknown1009f760 { public: char *sub_1009f760(); };
class CUnknown1014d030 { public: float sub_1014d030(); };
class CUnknown1014d040 { public: float sub_1014d040(); };
extern CUnknown1014d030 g_105e8120;

class IClientVehicleView
{
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void SetupMove(C_BasePlayer *player, CUserCmdView *ucmd, void *pHelper, CMoveDataView *move);
};

bool sub_1008c770(void *pStudioHdr, int iSequence, float flCycleFrom, float flCycleTo, const float *poseParameter, Vector &deltaPos, QAngle &deltaAngles);

#define P(T, off) (*(T *)((char *)player + (off)))

void CPrediction::vfunc16(C_BasePlayer *player, CUserCmdView *ucmd, void *pHelper, CMoveDataView *move)
{
    move->m_bFirstRunOfFunctions = vfunc14();
    move->m_nPlayerHandle = P(int, 0xe4);
    move->m_nPlayerHandle = P(int, 0xe4);
    player->sub_1009fa70();
    move->m_vecVelocity = P(Vector, 0xb4);
    move->m_vecAbsAngles = *(QAngle *)((CUnknown1009f760 *)player)->sub_1009f760();
    move->m_vecOldAngles = move->m_vecAngles;
    move->m_unk28 = P(int, 0x1708);
    move->m_unk3c = P(int, 0x18cc);
    move->m_vecAngles = ucmd->viewangles;
    move->m_vecViewAngles = ucmd->viewangles;
    move->m_nImpulseCommand = ucmd->impulse;
    move->m_nButtons = ucmd->buttons;
    if (!P(char, 0x160d))
    {
        move->m_nButtons = ucmd->buttons;
    }
    else
    {
        move->m_nButtons = ucmd->buttons & ~0x801;
        P(int, 0x18c4) &= ~0x801;
    }
    move->m_unka8 = 0;
    move->m_unka4 = 0;

    CVStatList_t *stats = ((CVStatListSet *)((char *)player + 0x1164))->Find(0);
    move->m_flac = (float)(stats->sub_1015dbd0(2) * 10 - 10);
    P(float, 0x160) = g_105e8120.sub_1014d030();
    move->m_unkc0 = P(int, 0x1644);
    move->m_flb4 = ((CUnknown1014d040 *)&g_105e8120)->sub_1014d040();
    move->m_unkb0 = 0;
    move->m_unkc4 = P(int, 0x1078);
    move->m_bd0 = false;

    if ((player->sub_100a2450() & 0x40) || P(char, 0x160d))
    {
        move->m_flForwardMove = 0;
        move->m_flSideMove = 0;
        move->m_flUpMove = 0;
    }
    else if (P(unsigned char, 0x16f4) & 0x80)
    {
        move->m_flForwardMove = 0;
        move->m_flSideMove = 0;
        move->m_flUpMove = 0;
        void *hdr = (void *)player->sub_1008f900(-1);
        if (hdr && P(int, 0x63c) >= 0)
        {
            float rate = player->vfunc138(P(int, 0x63c));
            float flPrev = (P(float, 0x19f0) - P(float, 0x70)) * rate + P(float, 0x648);
            float flCur = rate * gpGlobals->frametime + flPrev;
            if (flPrev < 0.0f)
                flPrev = 0.0f;
            if (flCur > 1.0f)
                flCur = 1.0f;
            Vector deltaPos(0, 0, 0);
            QAngle deltaAngles(0, 0, 0);
            if (flPrev < flCur)
            {
                if (sub_1008c770(hdr, P(int, 0x63c), flPrev, flCur, (float *)((char *)player + 0x5d4), deltaPos, deltaAngles))
                {
                    move->m_flForwardMove = deltaPos.x / gpGlobals->frametime;
                    move->m_flSideMove = deltaPos.y / gpGlobals->frametime;
                    move->m_flUpMove = deltaPos.z / gpGlobals->frametime;
                    move->m_bd0 = true;
                }
            }
        }
    }
    else
    {
        move->m_flForwardMove = ucmd->forwardmove;
        move->m_flSideMove = ucmd->sidemove;
        move->m_flUpMove = ucmd->upmove;
    }

    C_BaseEntity *pVehicle = (C_BaseEntity *)P(CBaseHandle, 0x19c4).Get();
    if (pVehicle)
        ((IClientVehicleView *)pVehicle->vfunc63())->SetupMove(player, ucmd, pHelper, move);
}
// END FUNCTION

// FUNCTION: 0x101225f0 size=0x250
template <class T> __forceinline T pcd_stage(T x) { return x; }
#include "CPrediction.h"
#include "CGameTrace.h"
#include "Ray_t.h"
#include "CTraceFilterSimple.h"
#include "CUnknown1070b254.h"
#include "ConVar.h"
#include "QAngle.h"

extern ConVar *g_103edd9c;
extern ConVar *g_104e1584;
extern int g_104e16f4;
extern float g_104e16f8;
void sub_101090a0(const QAngle &angles, Vector *forward, Vector *right, Vector *up);
void sub_10108fd0(const Vector &start, float scale, const Vector &dir, Vector &dest);
void sub_101659b0(const Vector &start, const Vector &end, int r, int g, int b, bool noDepthTest, float duration);

static inline void UTIL_TraceLine(const Vector &vecAbsStart, const Vector &vecAbsEnd, unsigned int mask, const void *ignore, int collisionGroup, CGameTrace *ptr)
{
	Ray_t ray;
	ray.sub_10005e00(&vecAbsStart.x, &vecAbsEnd.x);
	CTraceFilterSimple traceFilter;
	traceFilter.sub_1004b5c0(ignore, collisionGroup);
	g_104a582c->vfunc4(&ray, mask, (CTraceFilterNoCharacterCollide *)&traceFilter, ptr);
	if ((g_103edd9c->vfunc1() ? 0 : g_103edd9c->m_nValue) != 0)
	{
		sub_101659b0(*(const Vector *)ptr->m_startpos, *(const Vector *)ptr->m_endpos, 255, 0, 0, true, -1.0f);
	}
}

void CPrediction::vfunc19(const Vector &origin, const QAngle &angles, const Vector &viewofs)
{
	if (g_104e16f4 == -1)
		return;

	Vector forward;
	sub_101090a0(angles, &forward, 0, 0);
	forward.z = 0;

	float heights[6];
	int count = 0;
	for (int dist = 36; dist < 108; dist += 12)
	{
		Vector start;
		sub_10108fd0(origin, (float)dist, forward, start);
		start.z = pcd_stage(viewofs.z) + start.z;
		Vector end;
		end.x = start.x;
		end.y = start.y;
		end.z = start.z - 160.0f;

		CGameTrace tr;
		UTIL_TraceLine(start, end, 0x200400b, 0, 6, &tr);
		if (tr.m_allsolid || tr.m_fraction == 1.0f)
			return;
		heights[count++] = start.z + tr.m_fraction * (end.z - start.z);
	}

	int lastStep = 0;
	int nSteps = 0;
	for (int i = 1; i < count; i++)
	{
		int t0 = heights[i] - heights[i - 1]; int step = (int)(t0);
		if (step > -0.1 && step < 0.1)
			continue;
		if (lastStep)
		{
			int diff = step - lastStep;
			if (diff > 0.1 || diff < -0.1)
				return;
		}
		nSteps++;
		lastStep = step;
	}

	if (!lastStep)
	{
		g_104e16f8 = 0;
		return;
	}
	if (nSteps < 2)
		return;
	g_104e16f8 = (g_104e1584->vfunc1() ? 0.0f : g_104e1584->m_fValue) * -lastStep;
}

/* judged with these header patches (not saved):
[
 {
  "path": "include/CPrediction.h",
  "old": "    virtual void vfunc19();",
  "new": "    virtual void vfunc19(const class Vector &origin, const class QAngle &angles, const class Vector &viewofs);"
 }
]
*/
// END FUNCTION

// FUNCTION: 0x101230c0 size=0x4
#include "CPrediction.h"
bool CPrediction::vfunc12()
{
    return *(bool *)((char *)this + 0x24);
}
// END FUNCTION

// FUNCTION: 0x101230d0 size=0x4
#include "CPrediction.h"
int CPrediction::vfunc13()
{
    return *(int *)((char *)this + 0x28);
}
// END FUNCTION

// FUNCTION: 0x101230e0 size=0x4
#include "CPrediction.h"
bool CPrediction::vfunc14()
{
    return *(bool *)((char *)this + 0x2c);
}
// END FUNCTION

// FUNCTION: 0x101230f0 size=0x11
#include "C_BasePlayer.h"
#include "CPrediction.h"
int CPrediction::vfunc7()
{
    if (C_BasePlayer::GetLocalPlayer() == 0) {
        return ((int)C_BasePlayer::GetLocalPlayer());
    }
    return *(int *)((char *)((int)C_BasePlayer::GetLocalPlayer()) + 0x90);
}
// END FUNCTION

// FUNCTION: 0x10123110 size=0x37
#include "C_BasePlayer.h"
#include "CPrediction.h"
#include "C_BasePlayer.h"
#include "Vector.h"
// TARGET: CPrediction::vfunc8
void CPrediction::vfunc8(Vector *v)
{
    if (C_BasePlayer::GetLocalPlayer() == 0) {
        v->x = 0;
        v->y = 0;
        v->z = 0;
    } else {
        *v = C_BasePlayer::GetLocalPlayer()->GetAbsOrigin();
    }
}
// END FUNCTION

// FUNCTION: 0x10123150 size=0x28
#include "C_BasePlayer.h"
#include "CPrediction.h"
namespace lifted {
struct C100a2030 { int sub_100a2030(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual int f44(int); };
}
void CPrediction::vfunc9(int a0)
{
    int t0 = ((int)C_BasePlayer::GetLocalPlayer());
    if (t0 != 0) {
        ((lifted::C100a2030 *)t0)->sub_100a2030(a0);
        ((lifted::V *)t0)->f44(a0);
    }
}
// END FUNCTION

// FUNCTION: 0x10123180 size=0x3a
#include "C_BasePlayer.h"
#include "CPrediction.h"
#include "C_BasePlayer.h"
#include "Vector.h"
// TARGET: CPrediction::vfunc10
void CPrediction::vfunc10(Vector *v)
{
    if (C_BasePlayer::GetLocalPlayer() == 0) {
        v->x = 0;
        v->y = 0;
        v->z = 0;
    } else {
        *v = *(Vector *)C_BasePlayer::GetLocalPlayer()->vfunc195();
    }
}
// END FUNCTION

// FUNCTION: 0x101231c0 size=0x32
#include "C_BasePlayer.h"
#include "CPrediction.h"
#include "Vector.h"
#define V10(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4(); virtual void a##5(); virtual void a##6(); virtual void a##7(); virtual void a##8(); virtual void a##9();
struct PlayerView {
 V10(a0) V10(a1) V10(a2) V10(a3) V10(a4) V10(a5) V10(a6) V10(a7) V10(a8) V10(a9)
 V10(b0) V10(b1) V10(b2) V10(b3) V10(b4) V10(b5) V10(b6)
 virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5();
 virtual void c6(); virtual void c7(); virtual void c8(); virtual void c9(); virtual void d0(); virtual void d1();
 virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
 virtual void d8(); virtual void d9(); virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3();
 virtual void e4(); virtual void e5();
 virtual void vfunc196(Vector v);
};
// TARGET: CPrediction::vfunc11
void CPrediction::vfunc11(const Vector *v)
{
    if (C_BasePlayer::GetLocalPlayer())
        ((PlayerView *)C_BasePlayer::GetLocalPlayer())->vfunc196(*v);
}
// END FUNCTION

// FUNCTION: 0x10123200 size=0x4
#include "CPrediction.h"
int CPrediction::vfunc15()
{
    return *(int *)((char *)this + 0x30);
}
// END FUNCTION
