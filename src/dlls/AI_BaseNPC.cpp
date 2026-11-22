// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "vampire.h"

// FUNCTION: 0x10265ad0 size=0x2f7
#include "CSoundControllerImp.h"
#include "CTriggerProximity.h"
#include "CUnknown102c63b0.h"
#include "CUnknown102c6460.h"
#include "CUnknown102ca630.h"
#include "CUnknown102dc2c0.h"
#include "CAI_BaseNPC_vfunc144.h"
#include "CBaseEntity.h"
#include "CEHandleGet.h"
#include "CUnknown100290c0.h"
#include "CDevFlagObj.h"
#include "CCineNPC.h"
#include "CUnknown103158f0.h"
#include "IPhysicsObject.h"

#define FILE_ "E:\\Vampire\\main\\dlls\\AI_BaseNPC.cpp"

struct CScriptView144
{
	char m_pad0000[0x204];
	unsigned int m_flags204;
	char m_pad0208[0x5f91 - 0x208];
	char m_b5f91;
};

#include "ConVar.h"

extern ConVar g_10924a68;	// the AI condition debug convar
extern ConVar g_106bbaa0;

void CAI_BaseNPC::vfunc144(int a)
{
	CAI_BaseNPCUnit144 *p = (CAI_BaseNPCUnit144 *)this;
	const CAI_NPCDamageRecord *pInfo = (const CAI_NPCDamageRecord *)a;

	if (p->m_pSchedule5c38 && (int)p->m_pSchedule5c38 == p->sub_102cc1f0(0x3a))
		return;

	if (p->m_nState5cc0 == 4)
	{
		if (((CUnknown100290c0 *)g_10566458)->sub_100290c0((unsigned int *)&p->m_hScript5d74))
		{
			CScriptView144 *pScript = (CScriptView144 *)((CUnknown100290c0 *)g_10566458)->sub_100290c0((unsigned int *)&p->m_hScript5d74);
			if (pScript->m_b5f91 && (((CScriptView144 *)((CUnknown100290c0 *)g_10566458)->sub_100290c0((unsigned int *)&p->m_hScript5d74))->m_flags204 & 0x2080) != 0x80)
			{
				p->m_LastDamage.m_n00 = pInfo->m_n00;
				p->m_LastDamage.m_n04 = pInfo->m_n04;
				p->m_LastDamage.m_n08 = pInfo->m_n08;
				p->m_LastDamage.m_n0c = pInfo->m_n0c;
				p->m_LastDamage.m_vecForce.sub_1003e4b0(pInfo->m_vecForce);
				p->m_LastDamage.m_vecPosition.sub_1003e4b0(pInfo->m_vecPosition);
				p->m_LastDamage.m_n28 = pInfo->m_n28;
				p->m_LastDamage.m_pInflictor = pInfo->m_pInflictor;
				p->m_LastDamage.m_n30 = pInfo->m_n30;
				p->m_LastDamage.m_n34 = pInfo->m_n34;
				p->m_LastDamage.m_n38 = pInfo->m_n38;
				p->m_LastDamage.m_n3c = pInfo->m_n3c;
				p->m_LastDamage.m_n40 = pInfo->m_n40;
				p->m_LastDamage.m_n44 = pInfo->m_n44;
				p->m_LastDamage.m_b48 = pInfo->m_b48;
				p->m_LastDamage.m_b49 = pInfo->m_b49;
				p->m_LastDamage.m_b4a = pInfo->m_b4a;
				return;
			}
			((CCineNPC *)((CUnknown100290c0 *)g_10566458)->sub_100290c0((unsigned int *)&p->m_hScript5d74))->sub_101a8c30();
			IPhysicsObject *pPhys;
			if (g_106bbaa0.GetBool() && (pPhys = p->m_pPhysObj36c))
			{
				Vector vecTmp;
				Vector vecPos;
				vecPos = *p->vfunc263(&vecTmp);
				pPhys->vfunc39((float *)&vecPos, 0);
			}
		}
	}

	p->vfunc511();
	if (p->m_n153c == -1 || !p->m_h1538.Get())
		p->vfunc488();

	p->sub_10265a90(pInfo->m_pInflictor);
	if (((CBaseEntity *)p)->sub_100b3700() & 0x2000)
	{
		*(int *)((char *)p + 0x1ec) = 0;
		p->sub_10265a40();
	}
	p->sub_1032b9b0(a);
	p->m_pszFile1b3c = FILE_;
	p->m_nLine1b40 = 0x217;
	p->m_nIdealState5cc4 = 7;
	if (g_10924a68.GetBool())
		AI_CONDITION_TRACE(0x4c);
	p->sub_10269a20(0x4c);
	p->m_hAttacker5b7c = pInfo->m_pInflictor;
	p->m_b5b80 = 1;
	p->sub_1028ae60();
	if (p->m_pSquad5da4)
		((CUnknown103158f0 *)p->m_pSquad5da4)->sub_103158f0((CBaseEntity *)p);
	if ((char)p->vfunc552())
		p->sub_102695d0();
	else
		sub_101babc0(0x20, p->vfunc217(), 0x180, 30.0f, 0);
	p->m_pszFile1b3c = FILE_;
	p->m_nLine1b40 = 0x241;
	p->m_nIdealState5cc4 = 7;
	p->sub_1026e340(7);
}
// END FUNCTION

// FUNCTION: 0x1026d050 size=0x4f
struct SSquadView { void sub_10316700(void *pNPC); };
struct SDbgSink { void sub_102dfc10(const char *); };
extern SDbgSink *g_109203f0;
char *__cdecl sub_101d3730(const char *, const char *, int);

struct SNpcView5bb0 {
    char pad[0x5bb0];
    int m_n5bb0;
    char pad2[0x5da4 - 0x5bb4];
    void *m_p5da4;
    void sub_1026d050();
};

// TARGET: SNpcView5bb0::sub_1026d050
void SNpcView5bb0::sub_1026d050()
{
    if (m_n5bb0 <= 0) {
        SSquadView *pSquad = *(SSquadView **)&m_p5da4;
        if (pSquad)
            pSquad->sub_10316700(this);
        g_109203f0->sub_102dfc10(sub_101d3730("%s(%d) :", "E:\\Vampire\\main\\dlls\\AI_BaseNPC.cpp", 0xf36));
    }
    ++m_n5bb0;
}
// END FUNCTION

// FUNCTION: 0x1026d460 size=0x29c
#include "utlrbtree.h"
#include "CAI_BaseNPC.h"
#include "CEntitySoundOriginView.h"
#include "CPASAttenuationFilter.h"
#include "CUnknown1017d630.h"
#include "CUnknown1017d680.h"
#include "ConVar.h"
#include "engineserver.h"
#include "engineiface.h"

struct SurfData { char pad[0x24]; float f24; float f28; float f2c; float f30; };
struct SurfLookup { SurfData *sub_10207c40(void *pNpc); };
struct SndRec { char pad[0x2c]; unsigned short s2c; unsigned short s2e; };
struct SndTable { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual const char *vfunc6(int idx); };
struct NpcView : public CEntitySoundOriginView {
	char pad1[0x2e0 - 4];
	int m_pEdict2e0;
	char pad2[0x5b90 - 0x2e4];
	SndRec *m_pSnd5b90;
};

extern void *sub_101cda50();
extern int __fastcall sub_1017cf90(void *p);
extern SurfLookup g_1074f028;
extern ConVar g_109203f8;
extern ConVar g_10920160;
extern ConVar g_109204a8;
extern ConVar g_10920440;
extern ConVar g_10920280;
extern SndTable *g_10723944;
extern int sub_10228350(float a);

static inline int CvI(ConVar &c) { if (c.m_pParent->vfunc1()) return 0; ConVar *p = c.m_pParent; int v = p->m_nValue; if (*(short *)&p == -1) return v; return v; }

static inline void GetStepSoundParams(SurfData *pData, int nSide, float &flVolume, float &flLevel)
{
	if (CvI(g_109203f8) != 0) {
		switch (nSide) {
		case 0:
			flVolume = pData->f24;
			flLevel = pData->f28;
			break;
		case 1:
			flVolume = pData->f2c;
			flLevel = pData->f30;
			break;
		default:
			__assume(0);
		}
	} else {
		switch (nSide) {
		case 0:
			flVolume = g_10920440.GetFloat();
			flLevel = g_10920280.GetFloat();
			break;
		case 1:
			flVolume = g_10920160.GetFloat();
			flLevel = g_109204a8.GetFloat();
			break;
		default:
			__assume(0);
		}
	}
}

void CAI_BaseNPC::sub_1026d460(int nSide)
{
	NpcView *self = (NpcView *)this;
	void *pPlayer = sub_101cda50();
	if (pPlayer) {
		if (((CUnknown1017d630 *)pPlayer)->sub_1017d630() || ((CUnknown1017d680 *)pPlayer)->sub_1017d680() || sub_1017cf90(pPlayer))
			return;
	}
	SurfData *pData = g_1074f028.sub_10207c40(this);
	float flVolume;
	float flLevel;
	GetStepSoundParams(pData, nSide, flVolume, flLevel);
	if (g_10723944 && self->m_pSnd5b90) {
		int nLevel = sub_10228350(flLevel);
		CPASAttenuationFilter filter(self, (soundlevel_t)nLevel);
		int nIndex;
		if (enginerandom->vfunc2(0, 1))
			nIndex = self->m_pSnd5b90->s2c;
		else
			nIndex = self->m_pSnd5b90->s2e;
		const char *pszName = g_10723944->vfunc6(nIndex);
		if (pszName && *pszName) {
			int edict = self->m_pEdict2e0;
			enginesound->vfunc2(&filter, engine->vfunc35(edict), 4, pszName, flVolume, nLevel, 0, 100, 0, 0, 1, 0);
		}
	}
}
// END FUNCTION

// FUNCTION: 0x1026d7b0 size=0x21
namespace lifted {
extern char g_105cb988;
}
struct CUnknown1026d7b0 { void sub_1026d7b0(int, int, int, int); };
void CUnknown1026d7b0::sub_1026d7b0(int a0, int a1, int a2, int a3)
{
    *(int *)((char *)this + 0x1b3c) = (int)&lifted::g_105cb988;
    *(int *)((char *)this + 0x1b40) = 0xffc;
    *(int *)((char *)this + 0x5cc4) = 3;
}
// END FUNCTION

// FUNCTION: 0x1026f4d0 size=0x86
#include "CAI_BaseNPC.h"

#define FIELD(type, off) (*(type *)((char *)this + (off)))

int CAI_BaseNPC::sub_1026f4d0()
{
	FIELD(int, 0x1b2c) = 0;
	FIELD(int, 0x1b30) = 0;
	FIELD(int, 0x1b34) = 0;
	FIELD(int, 0x1b44) = 0;
	FIELD(int, 0x1b48) = 0;
	int state = vfunc460();
	if (state == 0)
		state = vfunc461();
	if ((FIELD(unsigned int, 0x14bc) & 0x20000) == 0x20000) {
		switch (state) {
		case 1:
			FIELD(int, 0x1b40) = 0x12f7;
			break;
		case 3:
			FIELD(int, 0x1b40) = 0x12f8;
			break;
		default:
			return state;
		}
		FIELD(const char *, 0x1b3c) = "E:\\Vampire\\main\\dlls\\AI_BaseNPC.cpp";
		state = FIELD(int, 0x5cc4) = 0xb;
	}
	return state;
}
// END FUNCTION

// FUNCTION: 0x1026f660 size=0x3d8
#include "CBaseEntity.h"
#include "CAI_BaseNPC_vfunc461.h"
#include "CAI_Motor.h"

#define FILE_ "E:\\Vampire\\main\\dlls\\AI_BaseNPC.cpp"

typedef void (*FnDevWarning)(int, const char *, ...);
extern FnDevWarning g_109f3658;

int CAI_BaseNPC::vfunc461()
{
	CAI_BaseNPCUnit461 *p = (CAI_BaseNPCUnit461 *)this;
	p->m_n1b38 = 1;
	switch (p->m_nState5cc0) {
	case 1:
		if (p->sub_10269d30(0x54) || p->sub_10269d30(0x46)) {
			p->m_nLine1b40 = 0x136a;
			p->m_nIdealState5cc4 = 2;
		} else if (p->sub_10269d30(0x4c)) {
			p->m_b5b80 = 0;
			sub_102e0b40((float *)p->m_pMotor5d44);
			Vector v = ((CEnemiesView *)p->vfunc541())->sub_102dfed0((CBaseEntity *)p->vfunc167());
			p->m_pMotor5d44->sub_102e2020(&v.x, 0);
			p->m_nLine1b40 = 0x1373;
			p->m_nIdealState5cc4 = 3;
		} else if (p->sub_10269d30(0x4d)) {
			p->m_b5b80 = 0;
			sub_102e0b40((float *)p->m_pMotor5d44);
			Vector v = ((CEnemiesView *)p->vfunc541())->sub_102dfed0((CBaseEntity *)p->vfunc167());
			p->m_pMotor5d44->sub_102e2020(&v.x, 0);
			p->m_nLine1b40 = 0x137c;
			p->m_nIdealState5cc4 = 3;
		} else if (p->sub_10269d30(0x6a) || p->sub_10269d30(0x6d) || p->sub_10269d30(0x6e) || p->sub_10269d30(0x6f) || p->sub_10269d30(0x6b) || p->sub_10269d30(0x70)) {
			S101b9920 *pObj = (S101b9920 *)p->vfunc474();
			if (!pObj)
				return p->m_nIdealState5cc4;
			sub_102e0b40((float *)p->m_pMotor5d44);
			CAI_Motor *pMotor = p->m_pMotor5d44;
			pMotor->sub_102e2020((const float *)pObj->sub_101b99d0(), 0);
			int n = *(int *)((char *)pObj + 4);
			if (n != 1 && n != 8 && n != 0x10)
				return p->m_nIdealState5cc4;
			p->m_nLine1b40 = 0x1397;
			p->m_nIdealState5cc4 = 3;
		} else if (p->sub_10269d30(0x5e)) {
			p->m_nLine1b40 = 0x139e;
			p->m_nIdealState5cc4 = 3;
		} else {
			return p->m_nIdealState5cc4;
		}
		p->m_pszFile1b3c = FILE_;
		break;
	case 3:
		if (p->sub_10269d30(0x54) || p->sub_10269d30(0x46)) {
			p->m_nLine1b40 = 0x13ac;
			p->m_nIdealState5cc4 = 2;
			p->m_pszFile1b3c = FILE_;
		} else if (p->sub_10269d30(0x6a) || p->sub_10269d30(0x6d)) {
			p->m_pszFile1b3c = FILE_;
			p->m_nLine1b40 = 0x13b2;
			p->m_nIdealState5cc4 = 3;
			S101b9920 *pObj = (S101b9920 *)p->vfunc474();
			if (pObj) {
				sub_102e0b40((float *)p->m_pMotor5d44);
				CAI_Motor *pMotor = p->m_pMotor5d44;
				pMotor->sub_102e2020((const float *)pObj->sub_101b99d0(), 0);
			}
			g_10739a4c.sub_101e3d70((CUnknown101e3cfObj *)p);
			return p->m_nIdealState5cc4;
		} else if (p->vfunc462()) {
			p->m_nLine1b40 = 0x13c0;
			p->m_nIdealState5cc4 = 1;
			p->m_pszFile1b3c = FILE_;
		}
		break;
	case 2:
		if (!p->vfunc167()) {
			p->m_pszFile1b3c = FILE_;
			p->m_nLine1b40 = 0x13cc;
			p->m_nIdealState5cc4 = 3;
			g_109f3658(2, "***Combat state with no enemy!\n");
			return p->m_nIdealState5cc4;
		}
		break;
	case 4:
		if (p->sub_10269d30(0x5c) || p->sub_10269d30(0x4c) || p->sub_10269d30(0x4d)) {
			p->m_b5b80 = 0;
			p->sub_1027d0a0();
			return p->m_nIdealState5cc4;
		}
		break;
	case 7:
		p->m_nLine1b40 = 0x13dd;
		p->m_nIdealState5cc4 = 7;
		p->m_pszFile1b3c = FILE_;
		break;
	}
	return p->m_nIdealState5cc4;
}
// END FUNCTION

// FUNCTION: 0x10273390 size=0x2c1
#include "CBaseEntity.h"
#include "CBaseAnimating.h"
#include "CAI_BaseNPC.h"
#include "CAI_Motor.h"
#include "CUnknown102ee270.h"
#include "globalvars.h"
#include "Vector.h"
#include <string.h>

extern int g_1093407c;

void sub_10272650(int a);
void sub_10273aa0();
void sub_1026d7b0();

struct CUnknown1026a2a0
{
    void sub_1026a2a0(int a);
};

struct CObj1a9c
{
    void sub_102cc7e0();
};

struct CObj5d34
{
    char m_pad00[0x2c];
    int m_field2c;
};

struct CCondBits5c5c
{
    unsigned int m_bits[6];
    void ClearAll() { if (this) memset(this, 0, sizeof(m_bits)); }
};

// TARGET: CAI_BaseNPC::sub_10273390
void CAI_BaseNPC::sub_10273390()
{
    char *pSelf = (char *)this;

    ((CBaseEntity *)this)->sub_100a9290(1);
    *(EHANDLE *)(pSelf + 0x5b7c) = (CBaseEntity *)0;
    *(bool *)(pSelf + 0x5b80) = false;
    ((CBaseAnimating *)this)->sub_100904a0();
    ((CBaseEntity *)this)->sub_100b3580(0x12000);
    *(float *)(pSelf + 0x3ec) = 1.0f;
    *(int *)(pSelf + 0x1fc) = 2;

    sub_102e0b40((float *)*(void **)(pSelf + 0x5d44));
    CAI_Motor *pMotor = (CAI_Motor *)*(void **)(pSelf + 0x5d44);

    float yaw = ((Vector *)((CAI_BaseNPC *)this)->vfunc221())->y;
    if (*(char *)((char *)pMotor + 0x28) != 0)
    {
        if (yaw >= 180.0f)
            yaw -= 180.0f;
        else
            yaw += 180.0f;
    }
    if (*(int *)((char *)pMotor + 0x1c) == 0x43340000)
        *(float *)((char *)pMotor + 0x34) = yaw;
    else
        *(float *)((char *)pMotor + 0x34) = pMotor->sub_102e0a80(yaw);

    *(int *)(pSelf + 0x208) = 100;
    *(int *)(pSelf + 0x200) = 0;
    *(const char **)(pSelf + 0x1b3c) = "E:\\Vampire\\main\\dlls\\AI_BaseNPC.cpp";
    *(int *)(pSelf + 0x1b40) = 0x1af1;
    *(int *)(pSelf + 0x5cc4) = 1;

    if (((CBaseAnimating *)this)->sub_1008dd30(1, -1) >= 0)
    {
        sub_10272650(1);
    }
    else if (((CBaseAnimating *)this)->sub_1008dd30(0xf1, -1) >= 0)
    {
        sub_10272650(0xf1);
    }
    else
    {
        *(int *)(pSelf + 0x6f0) = 0;
    }

    *(char *)(pSelf + 0x1a40) = 0;
    *(int *)(pSelf + 0x1a44) = 0x202400b;
    ((CObj5d34 *)*(void **)(pSelf + 0x5d34))->m_field2c = g_1093407c;
    ((CAI_BaseNPC *)this)->sub_10280d30();
    ((CUnknown102ee270 *)*(void **)(pSelf + 0x5d34))->sub_102ee270();
    ((CBaseAnimating *)this)->sub_10095be0();
    ((CBaseAnimating *)this)->sub_1008f540();

    *(int *)(pSelf + 0x5ddc) = 0;
    *(int *)(pSelf + 0x5d8c) = 0;
    ((CAI_BaseNPC *)this)->sub_10279a50(0);
    *(float *)(pSelf + 0x5de4) = 1024.0f;
    ((CUnknown1026a2a0 *)this)->sub_1026a2a0(0x45400000);
    *(char *)(pSelf + 0x5cd8) = 0;

    unsigned int nFlags = *(unsigned int *)(pSelf + 0x204);
    unsigned char bFlag = (unsigned char)(nFlags >> 8);
    if (bFlag & 1)
    {
        *(float *)(pSelf + 0x5de4) = 1.0e9f;
        ((CUnknown1026a2a0 *)this)->sub_1026a2a0(0x45bb8000);
    }

    ((CCondBits5c5c *)(pSelf + 0x5c5c))->ClearAll();
    ((CObj1a9c *)(pSelf + 0x1a9c))->sub_102cc7e0();
    ((CObj1a9c *)(pSelf + 0x1ae0))->sub_102cc7e0();
    ((CAI_BaseNPC *)this)->sub_10274ca0();
    *(int *)(pSelf + 0x1f0) = (int)sub_1026d7b0;

    if (gpGlobals->curtime > 1.0)
    {
        ((void (__fastcall *)(void *))sub_10273aa0)(this);
    }
    else
    {
        ((CBaseEntity *)this)->sub_100ac4e0((int)sub_10273aa0, 0, 0);
        *(float *)(pSelf + 0x17c) = gpGlobals->curtime + 0.1;
    }

    *(char *)(pSelf + 0x1b28) = 0;
    *(int *)(pSelf + 0x5b58) = 0;
    *(float *)(pSelf + 0x5b5c) = gpGlobals->curtime;
    *(int *)(pSelf + 0x5b84) = 0;
    *(int *)(pSelf + 0x5b88) = 0;
    *(int *)(pSelf + 0x5b8c) = 0x7f7fffff;
    *(int *)(pSelf + 0x5cc8) = 0;
    *(int *)(pSelf + 0x5b98) = 10;
    *(EHANDLE *)(pSelf + 0x5ba8) = (CBaseEntity *)0;
    *(int *)(pSelf + 0x5b90) = 0;
    *(bool *)(pSelf + 0x5d78) = false;
    *(bool *)(pSelf + 0x5bc4) = false;
    ((CAI_BaseNPC *)this)->sub_10270180(0, 0);
    *(int *)(pSelf + 0x5d98) = 0;
    *(int *)(pSelf + 0x5d9c) = 0;
    *(int *)(pSelf + 0x5ce8) = 0;
    *(int *)(pSelf + 0x5d6c) = 0;
    *(int *)(pSelf + 0x5da0) = 0;
    *(int *)(pSelf + 0x5db4) = 0;
}
// END FUNCTION

// FUNCTION: 0x10274e30 size=0x741
#include "CAI_BaseNPC.h"
#include "CAI_Motor.h"
#include "CBaseCombatWeapon.h"
#include "CBaseEntity.h"
#include "Vector.h"
#include <string.h>
#include <stdlib.h>
#include "animevent_t.h"
struct EntV { void sub_101a8890(int a); void sub_101a7230(int a); };
struct ObjA { void sub_102d09b0(CAI_BaseNPC *p, int a); };
struct ObjB { void sub_102db3e0(CAI_BaseNPC *p, int a); };
struct ObjM { void sub_102e0b40(); void sub_102e1c10(float a, float b); };
struct WpnV { int sub_102521f0(); virtual void v0(); };
struct NpcV : public CAI_BaseNPC {
	void sub_101b0c10(const char *s);
	int sub_100b3700();
	void sub_1026d460(int a);
	void sub_10260a50(int a);
	void sub_1032a910(int a, int b);
	void sub_1032e210(animevent_t *e);
	void sub_1032e330(animevent_t *e);
	void sub_10273e80(int a);
	NpcV *sub_1032e7b0();
	int sub_1008f7b0(const char *s);
	int sub_1008f6c0(const char *s);
	float sub_10095cb0(int a, int b);
};
#define NPC_V10(p) CAI_NPC_V(p##0) CAI_NPC_V(p##1) CAI_NPC_V(p##2) CAI_NPC_V(p##3) CAI_NPC_V(p##4) CAI_NPC_V(p##5) CAI_NPC_V(p##6) CAI_NPC_V(p##7) CAI_NPC_V(p##8) CAI_NPC_V(p##9)
struct Slots192 {
	CAI_NPC_V(0) CAI_NPC_V(1) CAI_NPC_V(2) CAI_NPC_V(3) CAI_NPC_V(4) CAI_NPC_V(5) CAI_NPC_V(6) CAI_NPC_V(7) CAI_NPC_V(8) CAI_NPC_V(9) NPC_V10(1) NPC_V10(2) NPC_V10(3) NPC_V10(4) NPC_V10(5) NPC_V10(6) NPC_V10(7) NPC_V10(8) NPC_V10(9)
	NPC_V10(10) NPC_V10(11) NPC_V10(12) NPC_V10(13) NPC_V10(14) NPC_V10(15) NPC_V10(16) NPC_V10(17) NPC_V10(18)
	CAI_NPC_V(190) CAI_NPC_V(191)
	virtual Vector vfunc192();
};
void sub_10272650(int a);
void sub_101aeb60(int edict, const char *s, float v, int a, int b, int c);
struct FindObj { void *sub_100f7fe0(const char *s, const float *origin, float radius, void *pSearch, void *pActivator); void *sub_100f7f20(int a, const char *s, void *b, int c); };
extern FindObj g_106eb5d8;
#include "engineiface.h"
__declspec(dllimport) void DevMsg(const char *fmt, ...);

#define NPC_F(T, off) (*(T *)((char *)this + (off)))
#define NPC_H(off) (*(EHANDLE *)((char *)this + (off)))

void CAI_BaseNPC::vfunc259(animevent_t *pEvent)
{
	NpcV *self = (NpcV *)this;
	switch (pEvent->event) {
	case 1000:
		if (NPC_F(int, 0x5cc0) == 4) { NPC_F(int, 0x200) = 1; NPC_F(int, 0x210) = 0; }
		return;
	case 0x3f2:
		if (NPC_F(int, 0x5cc0) == 4) { NPC_F(int, 0x200) = 0; NPC_F(int, 0x210) = NPC_F(int, 0x208); }
		return;
	case 0x3ec:
		self->sub_101b0c10(pEvent->options);
		return;
	case 0x3f0:
		self->sub_101b0c10(pEvent->options);
		return;
	case 0x3f1:
		if (!enginerandom->vfunc2(0, 2)) return;
	case 0x3ed:
		sub_101aeb60(NPC_F(int, 0x2e0), pEvent->options, 1.0f, 0x50, 0, 100);
		return;
	case 0x3eb: {
		char *p98 = NPC_F(char *, 0x98);
		int pEdi = 0;
		if (p98) pEdi = *(int *)(p98 + 0x62ec);
		if (NPC_H(0x5d74)) {
			((EntV *)NPC_H(0x5d74).Get())->sub_101a7230(atoi(pEvent->options));
			return;
		}
		if (NPC_F(ObjA *, 0x5ddc)) {
			NPC_F(ObjA *, 0x5ddc)->sub_102d09b0(this, atoi(pEvent->options));
			return;
		}
		if (pEdi)
			((ObjB *)pEdi)->sub_102db3e0(this, atoi(pEvent->options));
		return;
	}
	case 0x3e9:
		if (NPC_H(0x5d74))
			((EntV *)NPC_H(0x5d74).Get())->sub_101a8890(0);
		return;
	case 0x3ea:
		if (NPC_H(0x5d74))
			((EntV *)NPC_H(0x5d74).Get())->sub_101a8890(1);
		return;
	case 0x3fc:
	case 0x3fd:
	case 0x3fe:
		DevMsg("Bodygroup!\n");
		return;
	case 0x7d2:
		if (self->sub_100b3700() & 1) self->sub_101b0c10("AI_BaseNPC.BodyDrop_Heavy");
		return;
	case 0x7d1:
		if (self->sub_100b3700() & 1) self->sub_101b0c10("AI_BaseNPC.BodyDrop_Light");
		return;
	case 0x7da:
		self->sub_101b0c10("AI_BaseNPC.SwishSound");
		return;
	case 0x7e4:
		sub_10272650(1);
		NPC_F(int, 0x5d8c) &= ~0x2000;
		self->sub_10095cb0(0, *(int *)(vfunc221() + 1));
		NPC_F(int, 0x19c) |= 0x10;
		return;
	case 0x7e6:
		if (pEvent->options) {
			int n = atoi(pEvent->options);
			NPC_F(ObjM *, 0x5d44)->sub_102e0b40();
			double flYaw = vfunc219()[1] + (double)n;
			NPC_F(ObjM *, 0x5d44)->sub_102e1c10((float)flYaw, -1.0f);
		}
		return;
	case 0x7f8: {
		WpnV *w = 0;
		if (pEvent->options && strlen(pEvent->options)) {
			char *f = (char *)g_106eb5d8.sub_100f7fe0(pEvent->options, vfunc217(), 256.0f, this, 0);
			if (f) w = *(WpnV **)(f + 0xa0);
		} else {
			char *pe = (char *)NPC_H(0x5ce4).Get();
			if (pe) w = *(WpnV **)(pe + 0xa0);
		}
		if (w) {
			if (w->sub_102521f0()) {
				NPC_F(const char *, 0x1b44) = "E:\\Vampire\\main\\dlls\\AI_BaseNPC.cpp";
				NPC_F(int, 0x1b48) = 0x1f06;
				vfunc448((int)"Weapon in use by someone else");
				return;
			}
			if (!vfunc382(w)) {
				NPC_F(const char *, 0x1b44) = "E:\\Vampire\\main\\dlls\\AI_BaseNPC.cpp";
				NPC_F(int, 0x1b48) = 0x1f0e;
				vfunc448((int)"Can't use this weapon type");
				return;
			}
			((CBaseCombatWeapon *)w)->vfunc341((CBaseEntity *)(void *)this);
			vfunc383(w, 0);
			self->sub_10273e80(0);
			return;
		}
		NPC_F(const char *, 0x1b44) = "E:\\Vampire\\main\\dlls\\AI_BaseNPC.cpp";
		NPC_F(int, 0x1b48) = 0x1f19;
		vfunc448((int)"Weapon stolen by someone else");
		return;
	}
	case 0x7fb: {
		NpcV *a = self->sub_1032e7b0();
		if (!a) return;
		const char *o = pEvent->options;
		if (!o) return;
		int i = atoi(o);
		if (i == -1) return;
		a->sub_10260a50(i);
		return;
	}
	case 0x7fa: {
		NpcV *a = self->sub_1032e7b0();
		if (!a) return;
		const char *o = pEvent->options;
		if (!o) return;
		int i = a->sub_1008f7b0(o);
		if (i == -1) return;
		a->sub_10260a50(i);
		return;
	}
	case 0x7fc: {
		NpcV *a = self->sub_1032e7b0();
		if (!a) return;
		const char *o = pEvent->options;
		if (!o) return;
		int i = a->sub_1008f6c0(o);
		if (i == -1) return;
		self->sub_1032a910(i, 0);
		return;
	}
	case 0x7f9: {
		const char *o = pEvent->options;
		if (o) {
			void *e = g_106eb5d8.sub_100f7f20(0, o, this, 0);
			if (e) ((Slots192 *)e)->vfunc192();
		}
		vfunc385(self->sub_1032e7b0(), 0, 0);
		return;
	}
	case 0x802:
	case 0x803:
		self->sub_1026d460(0);
		return;
	case 0x804:
	case 0x805:
		self->sub_1026d460(1);
		return;
	}
	if ((CAI_BaseNPC *)pEvent->pSource == this && (pEvent->event < 3000 || pEvent->event > 4002)) {
		self->sub_1032e330(pEvent);
		return;
	}
	self->sub_1032e210(pEvent);
}
// END FUNCTION

// FUNCTION: 0x1027be60 size=0xb5
#include "CAI_BaseNPC.h"
#include "CUnknown102ee270.h"
#include "CGlobalEntityList.h"

extern CGlobalEntityList *g_10566458;
extern void (__cdecl *g_109f3650)(int, const char *, ...);

struct CHandleView
{
	unsigned int m_Index;

	CGlobalEntityList_Ent *Get() const
	{
		if (m_Index != 0xffffffff) {
			CGlobalEntityList_Slot *pSlot = &g_10566458->m_Slots[m_Index & 0x1fff];
			if (pSlot->m_Serial == (int)(m_Index >> 13))
				return pSlot->m_pEntity;
		}
		return 0;
	}
};

struct CConditionBits
{
	int m_Bits[6];

	void ClearAll()
	{
		if (this)
			for (int i = 0; i < 6; i++)
				m_Bits[i] = 0;
	}
};

#define NV1(n) virtual void nv##n();
#define NV10(p) NV1(p##0) NV1(p##1) NV1(p##2) NV1(p##3) NV1(p##4) NV1(p##5) NV1(p##6) NV1(p##7) NV1(p##8) NV1(p##9)
#define NV100(p) NV10(p##0) NV10(p##1) NV10(p##2) NV10(p##3) NV10(p##4) NV10(p##5) NV10(p##6) NV10(p##7) NV10(p##8) NV10(p##9)

struct CAI_BaseNPCLevelView	// the NPC as the level transition cleanup sees it
{
	NV100(a) NV10(b0) NV10(b1) NV10(b2) NV10(b3) NV10(b4) NV10(b5) NV1(c0) NV1(c1) NV1(c2) NV1(c3) NV1(c4) NV1(c5) NV1(c6)
	virtual int slot167();

	char m_pad0004[0xfec - 4];
	int m_nFec;
	char m_pad0ff0[0x1b3c - 0xff0];
	const char *m_pszFile1b3c;
	int m_nLine1b40;
	char m_pad1b44[0x5c5c - 0x1b44];
	CConditionBits m_Conditions;
	char m_pad5c74[0x5cc0 - 0x5c74];
	int m_nState5cc0;
	int m_nState5cc4;
	char m_pad5cc8[0x5d34 - 0x5cc8];
	CUnknown102ee270 *m_pNavigator;
	char m_pad5d38[0x5d74 - 0x5d38];
	CHandleView m_hScripted;

	void sub_10280d30();
	void sub_1026e340(int newState);
	const char *sub_100ab4f0();
};

void CAI_BaseNPC::sub_1027be60()
{
	CAI_BaseNPCLevelView *p = (CAI_BaseNPCLevelView *)this;
	p->m_pNavigator->sub_102ee270();
	p->sub_10280d30();
	p->m_nFec = 0;
	if (!p->slot167())
		p->m_Conditions.ClearAll();
	if (p->m_nState5cc0 == 4 && (!p->m_hScripted.Get())) {
		p->sub_1026e340(1);
		p->m_pszFile1b3c = "E:\\Vampire\\main\\dlls\\AI_BaseNPC.cpp";
		p->m_nLine1b40 = 0x28d0;
		p->m_nState5cc4 = 1;
		g_109f3650(1, "Scripted Sequence stripped on level transition for %s\n", p->sub_100ab4f0());
	}
}
// END FUNCTION

// FUNCTION: 0x1027d0a0 size=0x99
#include "CAI_BaseNPC.h"
#include "CCineNPC.h"
struct CAI_BaseNPC_Cine { char pad[0x5d74]; CHandle<CCineNPC> m_hCine; };

bool CAI_BaseNPC::sub_1027d0a0()
{
    char *p = (char *)this;
    if (*(int *)(p + 0x200) == 1) {
        *(const char **)(p + 0x1b3c) = "E:\\Vampire\\main\\dlls\\AI_BaseNPC.cpp";
        *(int *)(p + 0x1b40) = 0x2a70;
        *(int *)(p + 0x5cc4) = 7;
        return false;
    }
    CAI_BaseNPC_Cine *c = (CAI_BaseNPC_Cine *)this;
    if (c->m_hCine)
        c->m_hCine->sub_101a8c30();
    return true;
}
// END FUNCTION

// FUNCTION: 0x1027d170 size=0x5d4
#include "CEHandleGet.h"
#include "CSoundControllerImp.h"
#include "CTriggerProximity.h"
#include "CUnknown101d7520.h"
#include "CUnknown101daec0.h"
#include "CUnknown101e56e0.h"
#include "CUnknown101e7c50.h"
#include "CUnknown101f4c80.h"
#include "CUnknown10202b10.h"
#include "CUnknown10206400.h"
#include "CUnknown102c63b0.h"
#include "CUnknown102c6460.h"
#include "CUnknown102ca630.h"
#include "CUnknown102dc2c0.h"
#include "CUnknown1073dc28.h"
#include "CAI_BaseNPC.h"
#include "CEntityVSlots.h"
#include "CCollisionProperty.h"
#include "ScopeTrace.h"
#include "CAI_BaseNPC_vfunc144.h"
#include "CCineNPC.h"
#include "CUnknown103158f0.h"
#include "IPhysicsObject.h"

#include "ConVar.h"

// The game's first decliner of the header inline EHandleEntityList::LookupEntity in this unit is
// CAI_BaseNPC::Event_Killed (0x10265ad0, judged 0 below as a same-unit copy): its LookupEntity COMDAT is compiled
// before CineCleanup, so VC6 knows the call's side effects (not its registers) there, as in the game.
extern ConVar g_106bbaa0;
extern ConVar g_10924a68;
#define FILE_144 "E:\\Vampire\\main\\dlls\\AI_BaseNPC.cpp"

void __cdecl sub_101cf390(CAI_BaseNPC *pEnt, const Vector &mins, const Vector &maxs);
float __cdecl sub_102d61e0(int hull);
int __cdecl sub_101cd250(CAI_BaseNPC *pEnt, int mask, CBaseEntity *pIgnore);


namespace block_1027d170
{
struct CScriptView144
{
	char m_pad0000[0x204];
	unsigned int m_spawnflags;
	char m_pad0208[0x5f91 - 0x208];
	char m_bPlayedSequence;
};

struct CDamageInfo144 : CAI_NPCDamageRecord
{
	CBaseEntity *GetAttacker() const { return m_pInflictor; }
};

struct CEventKilled144 : CAI_BaseNPCUnit144
{
	IPhysicsObject *VPhysicsGetObject() const { return m_pPhysObj36c; }
	void SetIdealStateDbg(int state, const char *pszFile, int nLine) { m_pszFile1b3c = pszFile; m_nLine1b40 = nLine; m_nIdealState5cc4 = state; }
	void SetTouchNull() { *(int *)((char *)this + 0x1ec) = 0; }
	void SetCondition(int iCondition) { if (g_10924a68.GetBool()) AI_CONDITION_TRACE(iCondition); sub_10269a20(iCondition); }
	void sub_10265ad0(const CDamageInfo144 &info);
};

void CEventKilled144::sub_10265ad0(const CDamageInfo144 &info)
{
	if (m_pSchedule5c38 && (int)m_pSchedule5c38 == sub_102cc1f0(0x3a))
		return;

	if (m_nState5cc0 == 4 && m_hScript5d74.Get())
	{
		CScriptView144 *pScript = (CScriptView144 *)m_hScript5d74.Get();
		if (pScript->m_bPlayedSequence && (((CScriptView144 *)m_hScript5d74.Get())->m_spawnflags & 0x2080) != 0x80)
		{
			m_LastDamage = info;
			return;
		}
		((CCineNPC *)m_hScript5d74.Get())->sub_101a8c30();
		IPhysicsObject *pPhys;
		if (g_106bbaa0.GetBool() && (pPhys = VPhysicsGetObject()))
		{
			Vector vecTmp;
			Vector vecPos;
			vecPos = *vfunc263(&vecTmp);
			pPhys->vfunc39((float *)&vecPos, 0);
		}
	}

	vfunc511();
	if (m_n153c == -1 || !m_h1538.Get())
		vfunc488();

	sub_10265a90(info.GetAttacker());
	if (((CBaseEntity *)this)->sub_100b3700() & 0x2000)
	{
		SetTouchNull();
		sub_10265a40();
	}
	sub_1032b9b0((int)&info);
	SetIdealStateDbg(7, FILE_144, 0x217);
	SetCondition(0x4c);
	m_hAttacker5b7c = info.GetAttacker();
	m_b5b80 = 1;
	sub_1028ae60();
	if (m_pSquad5da4)
		((CUnknown103158f0 *)m_pSquad5da4)->sub_103158f0((CBaseEntity *)this);
	if ((char)vfunc552())
		sub_102695d0();
	else
		sub_101babc0(0x20, vfunc217(), 0x180, 30.0f, 0);
	SetIdealStateDbg(7, FILE_144, 0x241);
	sub_1026e340(7);
}
}

struct CCineCleanupScript
{
	char m_pad0000[0x204];
	unsigned int m_spawnflags;	// 0x204
	char m_pad0208[0x5f48 - 0x208];
	int m_iszPlay;	// 0x5f48
	char m_pad5f4c[0x5f78 - 0x5f4c];
	int m_saved_movetype;	// 0x5f78
	int m_saved_movecollide;	// 0x5f7c
	int m_n5f80;
	int m_saved_solidflags;	// 0x5f84
	int m_saved_effects;	// 0x5f88
	int m_n5f8c;
	char m_b5f90;
	char m_b5f91;

	void sub_10279cc0(CBaseEntity *pEnt);
	bool HasSpawnFlags(unsigned int bit) { return (m_spawnflags >> bit) & 1; }
};

struct CCineHandle : CBaseHandle
{
	CCineCleanupScript *Get() const
	{
		return (CCineCleanupScript *)CBaseHandle::Get();
	}
	CCineCleanupScript *operator->() const { return Get(); }
};

struct CCineCleanupOwner98
{
	char m_pad0000[0x14b8];
	int m_n14b8;
};

struct ScopeTraceInl
{
	__forceinline ScopeTraceInl(const char *func, const char *name)
	{
		g_109f3620[*g_109f3680].name = func;
		g_109f3620[*g_109f3680].file = name;
		g_109f3620[*g_109f3680].line = g_106b8540;
		(*g_109f3680)++;
	}
	__forceinline ~ScopeTraceInl() { (*g_109f3680)--; }
};

struct CAI_CineCleanupNPC : public CAI_BaseNPC
{
	char m_pad0004[0x98 - 4];
	CCineCleanupOwner98 *m_p98;	// 0x98
	char m_pad009c[0x19c - 0x9c];
	int m_fEffects;	// 0x19c
	char m_pad01a0[0x1ec - 0x1a0];
	int m_pfnTouch;	// 0x1ec
	int m_pfnUse;	// 0x1f0
	char m_pad01f4[0x200 - 0x1f4];
	int m_lifeState;	// 0x200
	unsigned int m_spawnflags;	// 0x204
	char m_pad0208[0x210 - 0x208];
	int m_iHealth;	// 0x210
	char m_pad0214[0x26c - 0x214];
	const char *m_iName;	// 0x26c
	CCollisionProperty m_Collision;	// 0x270
	char m_pad02d4[0x6f4 - 0x2d4];
	int m_n6f4;	// 0x6f4
	char m_pad06f8[0xfec - 0x6f8];
	int m_nfec;	// 0xfec
	char m_pad0ff0[0x1568 - 0xff0];
	int m_nHull;	// 0x1568
	char m_pad156c[0x1b3c - 0x156c];
	const char *m_pszFile;	// 0x1b3c
	int m_nLine;	// 0x1b40
	char m_pad1b44[0x5cc4 - 0x1b44];
	int m_IdealState;	// 0x5cc4
	char m_pad5cc8[0x5d70 - 0x5cc8];
	int m_n5d70;	// 0x5d70
	CCineHandle m_hCine;	// 0x5d74
	char m_pad5d78[0x5de8 - 0x5d78];
	int m_n5de8;	// 0x5de8

	void sub_1026d160();
	void sub_103281b0(const char *pszBone, int a, int b);
	void sub_100926e0(int bone, Vector &origin, Vector &angles);
	bool sub_100903e0();
	void sub_100b3580(int a);

	void SetSolid(int solid)
	{
		ScopeTraceInl scope("CBaseEntity::SetSolid", m_iName ? m_iName : g_106b8540);
		m_Collision.sub_100dc480(solid);
	}
	void SetSolidFlags(int flags)
	{
		ScopeTrace scope("CBaseEntity::SetSolidFlags", m_iName ? m_iName : g_106b8540, g_106b8540);
		m_Collision.sub_100dc580(flags);
	}
	void AddSolidFlags(int flags)
	{
		ScopeTrace scope("CBaseEntity::AddSolidFlags", m_iName ? m_iName : g_106b8540, g_106b8540);
		m_Collision.AddSolidFlags(flags);
	}
	bool sub_1027d170();
	CCollisionProperty *CollisionProp() { return &m_Collision; }
	const Vector &WorldAlignMins() { return *(Vector *)CollisionProp()->vfunc1(); }
	const Vector &WorldAlignMaxs() { return *(Vector *)CollisionProp()->vfunc2(); }
	const Vector &GetLocalOrigin() { return *(Vector *)vfunc220(); }
	void SetLocalOrigin(const Vector &v) { ((CEntityVSlots *)this)->slot62((float *)&v.x); }
	void SetMoveType(int a, int b) { ((CEntityVSlots *)this)->slot93(a, b); }
	void SetCondition(int iCondition) { if (g_10924a68.GetBool()) AI_CONDITION_TRACE(iCondition); sub_10269a20(iCondition); }
};

// TARGET: CAI_CineCleanupNPC::sub_1027d170
bool CAI_CineCleanupNPC::sub_1027d170()
{
	CAI_CineCleanupNPC *p = this;

	sub_1027f270(0);
	p->m_n5d70 = 0;
	CCineCleanupScript *pOldCine = p->m_hCine.Get();

	if (p->m_hCine.Get())
	{
		if (!p->m_hCine->m_b5f90)
			p->sub_1026d160();
		p->m_hCine->sub_10279cc0(0);
		((CEntityVSlots *)this)->slot93(p->m_hCine->m_saved_movetype, p->m_hCine->m_saved_movecollide);
		p->SetSolidFlags(p->m_hCine->m_saved_solidflags);
		p->m_fEffects = p->m_hCine->m_saved_effects;
		if (p->m_p98)
			p->m_p98->m_n14b8 = p->m_hCine->m_n5f8c;
	}
	else
	{
		p->SetMoveType(4, 0);
		p->SetSolid(2);
		p->SetSolidFlags(0x10);
	}
	p->m_hCine.m_Index = 0xffffffff;
	sub_10279cc0(0);
	p->m_n5de8 = 0;

	if (p->m_lifeState == 1)
	{
		p->m_iHealth = 0;
		p->AddSolidFlags(4);
		sub_1026e340(7);
		p->m_lifeState = 2;
		sub_101cf390(this, p->WorldAlignMins(), Vector(p->WorldAlignMaxs().x, p->WorldAlignMaxs().y, p->WorldAlignMins().z + 2));
		if (pOldCine && pOldCine->HasSpawnFlags(3))
		{
			p->m_pfnUse = 0;
			sub_100ac4e0(0, 0, 0);
			p->m_pfnTouch = 0;
		}
		else
			sub_102695d0();
		if (!p->sub_100903e0())
		{
			p->m_n6f4 = 0;
			p->m_fEffects |= 0x10;
		}
		p->SetMoveType(0, 0);
		return false;
	}

	if (pOldCine && pOldCine->m_iszPlay && pOldCine->m_b5f91)
	{
		if (pOldCine->HasSpawnFlags(13))
		{
			p->sub_103281b0("Bip01", 1, 1);
			Vector origin = p->GetLocalOrigin();
			origin.z -= sub_102d61e0(p->m_nHull) * 0.5f;
			p->SetLocalOrigin(origin);
		}
		else if (!pOldCine->HasSpawnFlags(7))
		{
			Vector new_origin;
			Vector new_angle;
			p->sub_100926e0(0, new_origin, new_angle);

			Vector oldOrigin = p->GetLocalOrigin();
			if ((oldOrigin - new_origin).Length2D() < 8.0)
				new_origin = oldOrigin;

			Vector origin = p->GetLocalOrigin();
			origin.x = new_origin.x;
			origin.y = new_origin.y;
			origin.z += 1;

			if (sub_100b3700() & 0x400)
			{
				origin.z = new_origin.z;
				p->SetLocalOrigin(origin);
			}
			else
			{
				p->SetLocalOrigin(origin);
				p->sub_100b3580(1);
				int drop = sub_101cd250(this, 0x202400b, 0);
				if (drop < 0)
				{
					p->SetLocalOrigin(oldOrigin);
				}
				else if (drop == 0)
				{
					Vector origin = p->GetLocalOrigin();
					origin.z = new_origin.z;
					p->SetLocalOrigin(origin);
					sub_100b3640(1);
				}
			}

			origin = p->GetLocalOrigin();
			((CEntityVSlots *)this)->slot181(&origin, 0, 0);
			p->SetLocalOrigin(origin);
			p->m_fEffects |= 0x10;
		}
		p->m_nfec = 0;
	}

	p->m_pszFile = "E:\\Vampire\\main\\dlls\\AI_BaseNPC.cpp";
	if (p->m_iHealth > 0)
	{
		p->m_nLine = 0x2b1d;
		p->m_IdealState = 1;
	}
	else
	{
		p->m_nLine = 0x2b22;
		p->m_IdealState = 7;
		p->SetCondition(0x4c);
	}
	p->m_spawnflags &= ~0x80;
	return true;
}
// END FUNCTION
