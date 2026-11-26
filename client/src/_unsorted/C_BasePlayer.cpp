// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10002af0 size=0xe
struct V_10002af0 { int m_unk[0x19cc / 4]; int m_n19cc; };
// TARGET: sub_10002af0
int __fastcall sub_10002af0(V_10002af0 *self)
{
	return self->m_n19cc != 0;
}
// END FUNCTION

// FUNCTION: 0x10002b00 size=0x7
#include "C_BasePlayer.h"
int C_BasePlayer::vfunc84()
{
    return *(int *)((char *)this + 0x1990);
}
// END FUNCTION

// FUNCTION: 0x10002b10 size=0x2d
#include "CBaseEntityList.h"
#include "C_BasePlayer.h"
#include "CBaseEntityList.h"
C_BaseCombatWeapon *C_BasePlayer::vfunc167()
{
	unsigned int h = *(unsigned int *)((char *)this + 0x1a08);
	if (h != 0xffffffff) {
		CBaseEntityListEntry *e = &g_pEntityList->m_EntPtrArray[h & 0x1fff];
		if (e->m_SerialNumber == (int)(h >> 13))
			return (C_BaseCombatWeapon *)e->m_pEntity;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x10002b40 size=0x2d
#include "CBaseEntityList.h"
#include "C_BasePlayer.h"
struct EntInfo_10002b40 { void *m_pEntity; int m_SerialNumber; EntInfo_10002b40 *m_pPrev; };
struct EntList_10002b40 { int m_unk0; EntInfo_10002b40 m_Info[0x2000]; };
struct View_10002b40 { char pad[0x1a0c]; unsigned long m_hHandle; void *sub_10002b40(); };
void *View_10002b40::sub_10002b40()
{
	unsigned long h = m_hHandle;
	if (h != 0xffffffff)
	{
		EntInfo_10002b40 *pInfo = &((EntList_10002b40 *)g_pEntityList)->m_Info[h & 0x1fff];
		if (pInfo->m_SerialNumber == (int)(h >> 13))
			return pInfo->m_pEntity;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x10002b70 size=0x5
#include "C_BasePlayer.h"
int C_BasePlayer::vfunc175(int a0, int a1)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10002b80 size=0x7
#include "C_BasePlayer.h"
namespace lifted {
extern float g_101e34ec;
}
float C_BasePlayer::vfunc176()
{
    return lifted::g_101e34ec;
}
// END FUNCTION

// FUNCTION: 0x1002a2f0 size=0xaf
#include "CBaseEntityList.h"
#include "C_BasePlayer.h"
#include "ehandle.h"
#include "QAngle.h"
#include "matrix3x4_t.h"
void sub_10108a50(const matrix3x4_t &a, const matrix3x4_t &b, matrix3x4_t &out);
void sub_10107eb0(const matrix3x4_t &m, QAngle &out);
struct CVehicleView { char pad[0x26c]; matrix3x4_t m_mat; void sub_1009f8a0(); };
struct QAngleD : QAngle { ~QAngleD() {} };
int C_BasePlayer::vfunc108()
{
	unsigned long h = *(unsigned long *)((char *)this + 0x208);
	CVehicleView *pVehicle = 0;
	if (h != 0xffffffff) {
		CBaseEntityListEntry &e = g_pEntityList->m_EntPtrArray[h & 0x1fff];
		if (e.m_SerialNumber == (int)(h >> 13))
			pVehicle = (CVehicleView *)e.m_pEntity;
	}
	if (!pVehicle)
		return (int)((char *)this + 0x1888);
	matrix3x4_t m0, m1;
	sub_101094e0(*(QAngle *)((char *)this + 0x1888), m0);
	pVehicle->sub_1009f8a0();
	sub_10108a50(pVehicle->m_mat, m0, m1);
	static QAngleD s_angles;
	sub_10107eb0(m1, s_angles);
	return (int)&s_angles;
}
// END FUNCTION

// FUNCTION: 0x1002a3b0 size=0x7
#include "C_BasePlayer.h"
char * C_BasePlayer::vfunc109()
{
    return (char *)this + 0x1888;
}
// END FUNCTION

// FUNCTION: 0x1002a3c0 size=0x11
#include "C_BasePlayer.h"
namespace lifted {
int __stdcall sub_1007dbb0(int);
}
int C_BasePlayer::vfunc107(int a0)
{
    lifted::sub_1007dbb0(a0);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x100a49f0 size=0x6
#include "C_BasePlayer.h"
namespace lifted {
extern char g_102b0be8;
}
int C_BasePlayer::vfunc16()
{
    return (int)&lifted::g_102b0be8;
}
// END FUNCTION

// FUNCTION: 0x100a4a00 size=0x3
#include "C_BasePlayer.h"
int C_BasePlayer::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100a5220 size=0x6
#include "C_BasePlayer.h"
namespace lifted {
extern char g_102b0bd0;
}
int C_BasePlayer::vfunc17()
{
    return (int)&lifted::g_102b0bd0;
}
// END FUNCTION

// FUNCTION: 0x100a54a0 size=0x1e
#include "C_BasePlayer.h"

// VC6 writes C_BasePlayer's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_BasePlayer *pcd_emit_100a54a0() { return new C_BasePlayer; }

// TARGET: ??_GC_BasePlayer@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100a58a0 size=0x9
#include "C_BasePlayer.h"
void C_BasePlayer::vfunc177() { IsTransparent(); }
// END FUNCTION

// FUNCTION: 0x100a58b0 size=0x45
#include "CBaseEntityList.h"
#include "C_BasePlayer.h"
#include "CBaseEntityList.h"
// TARGET: C_BasePlayer::vfunc119
void C_BasePlayer::vfunc119(int ent) {
	unsigned int *ph = (unsigned int *)((char *)this + 0x14e8);
	void *p;
	if (*ph == 0xffffffff)
		p = 0;
	else {
		CBaseEntityListEntry *e = &g_pEntityList->m_EntPtrArray[*ph & 0x1fff];
		p = (e->m_SerialNumber == (int)(*ph >> 13)) ? e->m_pEntity : 0;
	}
	if ((void *)ent == p)
		*ph = 0xffffffff;
}
// END FUNCTION

// FUNCTION: 0x100a5900 size=0x9
struct V { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); };
void __fastcall sub_100a5900(char *self, int edx) { ((V *)(self + 4))->v11(); }
// END FUNCTION

// FUNCTION: 0x100a5a90 size=0x40
#include "C_BasePlayer.h"
#include "engineclient.h"
#include <stdio.h>

void C_BasePlayer::vfunc188(int nRole)
{
	if (!*((bool *)this + 0x19c8))
		return;
	if (nRole > 0)
		return;
	char szCmd[64];
	sprintf(szCmd, "vehicleRole %i\n", nRole);
	engine->vfunc27(szCmd, true);
}
// END FUNCTION

// FUNCTION: 0x100a5ad0 size=0x55
#include "C_BasePlayer.h"
#include "C_BaseAnimating.h"

extern int g_104a0d4c;

struct PlayerPre_100a5ad0
{
	void sub_100a99d0();
	int sub_10097f80(int i);
};

struct PlayerData_100a5ad0
{
	char m_pad0[0x16f4];
	int m_n16f4;	// 0x16f4
	char m_pad16f8[0x19c8 - 0x16f8];
	char m_b19c8;	// 0x19c8
	char m_b19c9;	// 0x19c9
	char m_pad19ca[0x1a28 - 0x19ca];
	int m_nOldStats[32];	// 0x1a28: compared by OnDataChanged
};

#define SELF ((PlayerData_100a5ad0 *)this)

void C_BasePlayer::OnPreDataChanged(int updateType)
{
	((PlayerPre_100a5ad0 *)this)->sub_100a99d0();
	g_104a0d4c = SELF->m_n16f4;
	for (int i = 0; i < 32; i++)
		SELF->m_nOldStats[i] = ((PlayerPre_100a5ad0 *)this)->sub_10097f80(i);
	SELF->m_b19c9 = SELF->m_b19c8;
	// BaseClass::OnPreDataChanged: C_BaseAnimating's slot-4 override, called with the networkable part
	((C_BaseAnimating *)((char *)this + 8))->sub_100948d0(updateType);
}
// END FUNCTION

// FUNCTION: 0x100a5b60 size=0x451
#include "C_BasePlayer.h"
#include "ehandle.h"
#include "CInput.h"
#include "CHud.h"
#include "ConVar.h"
#include "engineclient.h"
#include <stdlib.h>

struct Obj_100a99d0 { bool sub_100a99d0(); };
struct CUnknown100a2e40 { void sub_100a2e40(int); };
struct CUnknown100a6920 { bool sub_100a6920(); };
struct CHost_10097f80 { int sub_10097f80(int); };
struct PV { bool sub_100aa320(int, int); };

struct WeaponData_100a5b60 { char m_pad[0x2428]; int m_iFlags; };
struct WeaponRes_100a5b60 { WeaponData_100a5b60 *sub_101a92d0(int iAmmo); };
extern WeaponRes_100a5b60 g_10678dd4;

struct CHudHistoryResource_100a5b60 { void sub_100f0250(int type, int id, int count); };

struct WeaponInfoHolder_100a5b60 { char m_pad[0x2440]; int m_n2440; };
struct Weapon_100a5b60 { WeaponInfoHolder_100a5b60 *sub_1007b160(); };

struct Sub63Obj_100a5b60 { virtual void OnPlayerData(C_BasePlayer *pPlayer); };
#define EV(n) virtual void e##n();
#define EV10(p) EV(p##0) EV(p##1) EV(p##2) EV(p##3) EV(p##4) EV(p##5) EV(p##6) EV(p##7) EV(p##8) EV(p##9)
struct Ent_100a5b60
{
    EV10(0) EV10(1) EV10(2) EV10(3) EV10(4) EV10(5)
    EV(60) EV(61) EV(62)
    virtual Sub63Obj_100a5b60 *vfunc63();
};
struct PlayerV_100a5b60
{
    EV10(0) EV10(1) EV10(2) EV10(3) EV10(4) EV10(5) EV10(6) EV10(7) EV10(8) EV10(9)
    EV10(10) EV10(11) EV10(12) EV10(13)
    EV(140) EV(141) EV(142) EV(143) EV(144) EV(145) EV(146) EV(147)
    virtual Weapon_100a5b60 *vfunc148();
};
struct Renderable_100a5b60
{
    virtual void r0();
    virtual const Vector &GetRenderOrigin();
};

extern ConVar g_105f9990;
extern ConVar g_104d3fc0;
extern ConVar g_104a0b88;
extern float g_104cfe5c;

bool sub_1018c840();
void sub_101713c0(int);
void sub_10101b90(bool);
void sub_100c0c90(void *);
void sub_10171390();
float sub_100cd330(const Vector *pos, float minz, float maxz);

#define PL(type, off) (*(type *)((char *)this + (off)))

void C_BasePlayer::OnDataChanged(int updateType)
{
    if (((Obj_100a99d0 *)this)->sub_100a99d0())
        ((CUnknown100a2e40 *)this)->sub_100a2e40(1);

    C_BaseVCombatCharacter::OnDataChanged(updateType);

    if (((Obj_100a99d0 *)this)->sub_100a99d0())
    {
        switch (PL(int, 0x15e8))
        {
        case 8:
            input->vfunc35();
            break;
        case 0x10:
            input->vfunc37();
            break;
        }
        PL(int, 0x15e8) = 0;

        *render->vfunc41() = (unsigned char *)this + 0x166c;

        if (((CUnknown100a6920 *)this)->sub_100a6920() && PL(CBaseHandle, 0x19c4).Get() &&
            ((Ent_100a5b60 *)PL(CBaseHandle, 0x19c4).Get())->vfunc63())
        {
            ((Ent_100a5b60 *)PL(CBaseHandle, 0x19c4).Get())->vfunc63()->OnPlayerData(this);
        }

        if ((PL(unsigned int, 0x1610) & 1) && sub_1018c840())
        {
            PL(unsigned int, 0x1610) &= ~1;
            sub_101713c0(1);
            engine->ClientCmd("chooseteam");
        }

        for (int i = 0; i < 32; i++)
        {
            if (((CHost_10097f80 *)this)->sub_10097f80(i) > ((int *)((char *)this + 0x1a28))[i])
            {
                WeaponData_100a5b60 *pWeaponData = g_10678dd4.sub_101a92d0(i);
                if (!pWeaponData || !(pWeaponData->m_iFlags & 0x40))
                {
                    CHudHistoryResource_100a5b60 *pHudHR = (CHudHistoryResource_100a5b60 *)gHUD.FindElement("CHudHistoryResource");
                    pHudHR->sub_100f0250(1, i, abs(((CHost_10097f80 *)this)->sub_10097f80(i) - ((int *)((char *)this + 0x1a28))[i]));
                }
            }
        }

        int nMax = g_105f9990.GetInt();
        if (PL(int, 0x1690) == 0)
            PL(int, 0x1690) = nMax;
        if (PL(int, 0x1690) == nMax)
            g_104cfe5c = 0;
        else
            g_104cfe5c = (float)PL(int, 0x1690) / nMax * g_104d3fc0.GetFloat() * g_104a0b88.GetFloat();

        sub_10101b90(vfunc84() <= 0);
        const float &flFrameRate = PL(float, 0x1078);
        float flRate = vfunc84() > 0 ? 1.0f / flFrameRate : 0.2f;
        engine->vfunc43(flRate);

        sub_100c0c90((char *)this + 0x17f8);
        sub_10171390();

        bool bShow = false;
        Weapon_100a5b60 *pWeapon = ((PlayerV_100a5b60 *)this)->vfunc148();
        if (pWeapon && pWeapon->sub_1007b160()->m_n2440 == 0x10)
            bShow = true;
        if (((PV *)this)->sub_100aa320(0x10, 0) || ((PV *)this)->sub_100aa320(0x200, 0) || ((PV *)this)->sub_100aa320(2, 0))
            bShow = true;
        if (vfunc84() <= 0)
            bShow = true;

        if (PL(int, 0x90) == 3 || (PL(int, 0x90) > 1 && !(sub_100a2450() & 1)))
        {
            Renderable_100a5b60 *pRend = (Renderable_100a5b60 *)((char *)this + 4);
            Vector vecOrigin = pRend->GetRenderOrigin();
            float flDepth = sub_100cd330(&vecOrigin, vecOrigin.z, vecOrigin.z + 512.0f);
            flDepth = flDepth - pRend->GetRenderOrigin().z - PL(float, 0x150);
            if (PL(int, 0x90) == 3)
                input->vfunc46(-1, *(int *)&flDepth);
            else
                input->vfunc46(1, *(int *)&flDepth);
            bShow = true;
        }
        else
        {
            input->vfunc46(0, 0);
        }

        if (bShow)
            input->vfunc37();
        else
            input->vfunc38();
    }
    sub_100a5fc0();
}
// END FUNCTION

// FUNCTION: 0x100a6b10 size=0x71
#include "engineclient.h"
#include "C_BasePlayer.h"
#include "Vector.h"
#include "QAngle.h"




bool __fastcall sub_100a99d0(void *self);

bool C_BasePlayer::sub_100a6b10()
{
	if (!sub_100a99d0(this))
	{
		float dt = engine->Time(0) - render->vfunc42();
		Vector origin;
		QAngle angles;
		vfunc149(dt, &origin, &angles);
		sub_100a2100(angles);
		sub_100a2030(&origin);
	}
	return true;
}
// END FUNCTION

// FUNCTION: 0x100a6e50 size=0x3
#include "C_BasePlayer.h"
void C_BasePlayer::vfunc154(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x100a6e60 size=0x400
#include "C_BasePlayer.h"
#include "engineclient.h"
#include "ConVar.h"
#include "Ray_t.h"
#include "CGameTrace.h"
#include "CTraceFilterSimple.h"
#include "Vector.h"

struct dlight_t
{
	int flags;
	Vector origin;
	float radius;
	unsigned char r, g, b;
	signed char exponent;
	float die;
	float decay;
	float minlight;
	int key;
	int style;
	Vector m_Direction;
	float m_InnerAngle;
	float m_OuterAngle;
};

const Vector &sub_10198d50();
void sub_101659b0(const Vector &start, const Vector &end, int r, int g, int b, bool noDepthTest, float duration);
extern ConVar g_103edd98;

struct EyePosView
{
	virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
	virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8();
	virtual const Vector &vfunc9();
};

static inline void UTIL_TraceLine(const Vector &vecAbsStart, const Vector &vecAbsEnd, unsigned int mask, const void *ignore, int collisionGroup, CGameTrace *ptr)
{
	Ray_t ray;
	ray.Init(vecAbsStart, vecAbsEnd);
	CTraceFilterSimple traceFilter;
	traceFilter.sub_1004b5c0(ignore, collisionGroup);
	enginetrace->vfunc4((int)&ray, mask, &traceFilter, (int)ptr);
	if (g_103edd98.GetBool())
		sub_101659b0(*(Vector *)ptr->m_startpos, *(Vector *)ptr->m_endpos, 255, 0, 0, true, -1.0f);
}

#define F(type, off) (*(type *)((char *)this + (off)))
#define m_pFlashlight F(dlight_t *, 0x19f8)
#define m_pFlashlightTarget F(dlight_t *, 0x19fc)
#define m_index F(int, 0x44)

void C_BasePlayer::vfunc156()
{
	if (sub_1009f140(8))
	{
		if (!m_pFlashlight || m_pFlashlight->key != m_index)
		{
			m_pFlashlight = (dlight_t *)effects->CL_AllocDlight(m_index);
			m_pFlashlight->flags = 1;
			m_pFlashlight->radius = 1000;
			m_pFlashlight->m_InnerAngle = 6;
			m_pFlashlight->m_OuterAngle = 10;
			m_pFlashlight->r = m_pFlashlight->g = m_pFlashlight->b = 255;
			m_pFlashlight->exponent = 7;
			m_pFlashlight->die = engine->Time(0) + 0.2f;
		}

		if (!m_pFlashlightTarget || m_pFlashlightTarget->key != -m_index)
		{
			m_pFlashlightTarget = (dlight_t *)effects->CL_AllocDlight(-m_index);
			m_pFlashlightTarget->flags = 2;
			m_pFlashlightTarget->radius = 80;
		}

		VectorCopy(((EyePosView *)this)->vfunc9(), m_pFlashlight->origin);
		m_pFlashlight->origin.z += F(float, 0x150);
		VectorCopy(sub_10198d50(), m_pFlashlightTarget->m_Direction);
		VectorCopy(sub_10198d50(), m_pFlashlight->m_Direction);

		CGameTrace tr;
		UTIL_TraceLine(m_pFlashlight->origin, m_pFlashlight->origin + sub_10198d50() * 1000.0f, 0x2000b, 0, 0, &tr);

		VectorCopy(*(Vector *)tr.m_endpos, m_pFlashlightTarget->origin);

		float falloff = tr.m_fraction * 1000;
		if (falloff < 500)
			falloff = 1.0f;
		else
			falloff = 500.0 / falloff;

		m_pFlashlightTarget->radius = 80;
		m_pFlashlightTarget->r = m_pFlashlightTarget->g = m_pFlashlightTarget->b = falloff * falloff * 255;
		m_pFlashlightTarget->exponent = 0;

		m_pFlashlight->die = engine->Time(0) + 0.2f;
		m_pFlashlightTarget->die = engine->Time(0) + 0.2f;

		render->vfunc2(m_pFlashlightTarget);
	}
	else
	{
		if (m_pFlashlight && m_pFlashlight->key == m_index)
		{
			m_pFlashlight->die = engine->Time(0);
			m_pFlashlight = 0;
		}
		if (m_pFlashlightTarget && m_pFlashlightTarget->key == -m_index)
		{
			m_pFlashlightTarget->die = engine->Time(0);
			m_pFlashlightTarget = 0;
		}
	}
}
// END FUNCTION

// FUNCTION: 0x100a7640 size=0x60
#include "C_BasePlayer.h"
#include "Vector.h"

struct CUnknown1009f6e0 { char *sub_1009f6e0(); };

bool C_BasePlayer::vfunc74()
{
	Vector delta;
	delta = *(Vector *)((CUnknown1009f6e0 *)this)->sub_1009f6e0() - *(Vector *)((char *)this + 0x54);
	for (int i = 0; i < 3; i++)
		if (delta[i] > 128.0)
			return true;
	return C_BaseEntity::vfunc74();
}
// END FUNCTION

// FUNCTION: 0x100a76a0 size=0xca
#include "C_BasePlayer.h"
#include "C_BaseEntity.h"
#include "ehandle.h"
#include "IClientRenderable.h"
#include "CBaseEntityList.h"

struct LeafView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual bool v12(void *pEntity);
};
struct CUnknown1009f6e0 { char *sub_1009f6e0(); };
struct CUnknown1009f6f0 { char *sub_1009f6f0(); };

extern LeafView *g_105f99d8;

// TARGET: C_BasePlayer::vfunc37
void C_BasePlayer::vfunc37()
{
	if ( !((IClientRenderable *)((char *)this + 4))->ShouldDraw() )
		return;
	if ( !((LeafView *)g_105f99d8)->v12(this) )
		return;

	CBaseHandle &h = *(CBaseHandle *)((char *)this + 0x188);
	if ( h.Get() )
		sub_1009fc60(0xb, 0);

	if ( sub_1009f140(0x10) )
		vfunc132(0);

	if ( vfunc74() )
	{
		sub_100a2030(((CUnknown1009f6e0 *)this)->sub_1009f6e0());
		sub_100a2100(*(QAngle *)((CUnknown1009f6f0 *)this)->sub_1009f6f0());
		vfunc132(0);
		vfunc68(0);
	}

	vfunc76();
}
// END FUNCTION

// FUNCTION: 0x100a7ab0 size=0x1a
#include "C_BasePlayer.h"
namespace lifted {
struct C100019a0 { bool sub_100019a0(); };
int sub_100a7890();
}
bool C_BasePlayer::vfunc174()
{
    int t0 = lifted::sub_100a7890();
    if (t0 != 0) {
        bool t1 = ((lifted::C100019a0 *)t0)->sub_100019a0();
        if (t1 == 0) {
            return 1;
        }
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100a7b80 size=0xaf
#include "engineclient.h"
#include "C_BasePlayer.h"
#include "C_BaseCombatWeapon.h"

extern "C" __declspec(dllimport) int Q_snprintf(char *pDest, int maxLen, const char *pFormat, ...);



// TARGET: C_BasePlayer::vfunc158
void C_BasePlayer::vfunc158()
{
	if (vfunc167()->vfunc169())
	{
		char szBuf[128];
		Q_snprintf(szBuf, sizeof(szBuf), "%s %i", (const char *)vfunc167()->vfunc223(), vfunc167()->vfunc169());
		engine->vfunc27(szBuf, true);
	}
	else
	{
		engine->vfunc27((const char *)vfunc167()->vfunc223(), true);
	}
}
// END FUNCTION

// FUNCTION: 0x100a7c30 size=0xb
#include "C_BasePlayer.h"
bool sub_10050f60();
// TARGET: C_BasePlayer::vfunc163
bool C_BasePlayer::vfunc163() { if (sub_10050f60()) return false; return true; }
// END FUNCTION

// FUNCTION: 0x100a7c40 size=0x288
template <class T> __forceinline T pcd_stage(T x) { return x; }
#define PCD_LPF_CTOR
#include "C_BasePlayer.h"
#include "C_BaseCombatWeapon.h"
#include "C_RecipientFilter.h"
#include "engineclient.h"
#include "CHud.h"
#include "ConVar.h"

extern ConVar g_1049e880;
bool sub_1018c770();
bool sub_10170bf0();
void sub_10170c30(int slot);
void sub_1004f810();
void sub_10186e20(C_BasePlayer *pPlayer, int n);

struct CView { int slot; int pos; char sub_100a8db0(); };
struct CUnk100aa4a0 { void sub_100aa4a0(CView *p); };
struct CUnknown101a79f0 { void sub_101a79f0(); };
struct HudSelView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual bool IsActive();	// 10
};
struct NetView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8();
	virtual int entindex();	// 9
};
struct PlayerSelView
{
	char pad0[0x1614];
	CView m_sel[2];	// 0x1614
	int m_iSel;	// 0x1624
	CView *GetSel() { return &m_sel[m_iSel]; }
	CView *sub_100a9000(int slot);
	CView *sub_100a9190(int slot, int pos);
};
#define SELF ((PlayerSelView *)this)

void C_BasePlayer::vfunc159(int slot, int a2, int a3)
{
	if (sub_1018c770())
		return;
	if (8 < slot)
		return;
	if (!(!vfunc163())) { if (sub_10170bf0())
	{
		if (slot == 0 || slot == 7)
			return;
		sub_10170c30(slot);
		return;
	}
	HudSelView *pHud = (HudSelView *)gHUD.sub_100f0ed0("CHudWeaponSelection");
	bool bWasActive = pHud->IsActive();
	((CUnknown101a79f0 *)pHud)->sub_101a79f0();
	if (pHud->IsActive() && SELF->GetSel() && SELF->GetSel()->slot == slot)
	{
		enginesound->vfunc0("common/wpn_moveselect.wav", 0);
		CLocalPlayerFilter filter;
		enginesound->EmitSound(filter, ((NetView *)((char *)this + 8))->entindex(), 3, "common/wpn_moveselect.wav", 1.0f, 0, 0, 100, 0, 0, 1, 0);
		if (SELF->GetSel())
		{
			if (bWasActive)
				((CUnk100aa4a0 *)this)->sub_100aa4a0(SELF->sub_100a9190(slot, pcd_stage(SELF->GetSel()->pos) + 1));
			else
			{
				C_BaseCombatWeapon *pWeapon = (C_BaseCombatWeapon *)vfunc148();
				if (!(pWeapon && pWeapon->vfunc220() == slot - 1 && pWeapon->vfunc176())) ((CUnk100aa4a0 *)this)->sub_100aa4a0(SELF->sub_100a9000(slot)); else vfunc168((int)pWeapon);
			}
		}
		if (!SELF->GetSel())
			((CUnk100aa4a0 *)this)->sub_100aa4a0(SELF->sub_100a9000(slot));
	}
	else
	{
		sub_1004f810();
		vfunc168((int)vfunc164(slot - 1));
		((CUnk100aa4a0 *)this)->sub_100aa4a0(SELF->sub_100a9000(slot));
		if (SELF->GetSel() && g_1049e880.GetBool())
		{
			CView next = *SELF->sub_100a9190(slot, (1 + pcd_stage(SELF->GetSel()->pos)));
			if (!next.sub_100a8db0())
				((CUnk100aa4a0 *)this)->sub_100aa4a0(&next);
		}
	}
	if (!SELF->GetSel()->sub_100a8db0())
		sub_10186e20(this, 0);
	else
		sub_10170bf0(); }
}

/* judged with these header patches (not saved):
[
 {
  "path": "C_BasePlayer.h",
  "old": "\tvirtual void vfunc159();",
  "new": "\tvirtual void vfunc159(int slot, int, int);"
 },
 {
  "path": "C_BasePlayer.h",
  "old": "\tvirtual void vfunc164();",
  "new": "\tvirtual C_BaseCombatWeapon *vfunc164(int);"
 }
]
*/
// END FUNCTION

// FUNCTION: 0x100a8030 size=0x8
#include "C_BasePlayer.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual int f148(); };
}
int C_BasePlayer::vfunc171()
{
    return ((lifted::V *)this)->f148();
}
// END FUNCTION

// FUNCTION: 0x100a8040 size=0x30
#include "CInput.h"
#include "C_BasePlayer.h"
#include "C_BasePlayer.h"
namespace lifted {
struct C100a9af0 { int sub_100a9af0(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual int f29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual int f148(); };
}
int C_BasePlayer::vfunc173()
{
    int t0 = input->vfunc29();
    if (t0 == 0) {
        if (((int)this) == ((int)C_BasePlayer::GetLocalPlayer())) {
            return ((lifted::C100a9af0 *)this)->sub_100a9af0(0);
        }
    }
    return ((lifted::V *)this)->f148();
}
// END FUNCTION

// FUNCTION: 0x100a87e0 size=0x2a
#include "C_BasePlayer.h"
namespace lifted {
struct V { virtual void u0(); virtual int f1(); };
}
void C_BasePlayer::vfunc168(int a0)
{
    if (a0 != 0) {
        *(int *)((char *)this + 0x1a08) = *(int *)((char *)(((lifted::V *)a0)->f1()));
        return;
    }
    *(int *)((char *)this + 0x1a08) = -1;
}
// END FUNCTION

// FUNCTION: 0x100a8810 size=0x2a
#include "C_BasePlayer.h"
namespace lifted {
struct V { virtual void u0(); virtual int f1(); };
}
void C_BasePlayer::vfunc169(int a0)
{
    if (a0 != 0) {
        *(int *)((char *)this + 0x1a0c) = *(int *)((char *)(((lifted::V *)a0)->f1()));
        return;
    }
    *(int *)((char *)this + 0x1a0c) = -1;
}
// END FUNCTION

// FUNCTION: 0x100a8920 size=0x100
#include "CBaseEntityList.h"
#include "C_BasePlayer.h"
#include "C_BaseCombatWeapon.h"
#include "CBaseHandle.h"
#include "CBaseEntityList.h"
#include "utlvector.h"

extern CUtlVector<CBaseHandle> g_1049d8f8;
extern CUtlVector<CBaseHandle> g_1049d978;

void sub_10186e20(C_BasePlayer *, int);

inline IHandleEntity *CBaseHandle::Get() const
{
	if (!IsValid())
		return 0;
	const CBaseEntityListEntry *pInfo = &g_pEntityList->m_EntPtrArray[GetEntryIndex()];
	if (pInfo->m_SerialNumber != GetSerialNumber())
		return 0;
	return (IHandleEntity *)pInfo->m_pEntity;
}

C_BaseCombatWeapon *C_BasePlayer::vfunc165(int slot, int pos)
{
	CUtlVector<CBaseHandle> *pList = &g_1049d8f8;
	if (*(int *)((char *)this + 0x1624) != 0)
		pList = &g_1049d978;

	if (pos >= 7 || slot >= 6)
		return 0;

	int bestPos = 7;
	C_BaseCombatWeapon *pBest = 0;

	for (int i = 0; i < pList->Count(); i++)
	{
		C_BaseCombatWeapon *pWeapon = (C_BaseCombatWeapon *)(*pList)[i].Get();
		if (!pWeapon)
			continue;
		if (!pWeapon->vfunc176())
			continue;
		if (pWeapon->vfunc220() == slot && pWeapon->vfunc221() <= bestPos && pWeapon->vfunc221() >= pos)
		{
			bestPos = pWeapon->vfunc221();
			pBest = pWeapon;
		}
	}

	sub_10186e20(this, 0);
	return pBest;
}
// END FUNCTION

// FUNCTION: 0x100a8bc0 size=0x87
#include "CBaseEntityList.h"
#include "C_BasePlayer.h"
struct CEntInfo8bc0 { void *m_pEntity; int m_Serial; int m_unk; };
struct CEntList8bc0 { int m_unk; CEntInfo8bc0 m_Ent[0x2000]; };
static inline void *HandleToEnt(unsigned long h)
{
	if (h != 0xffffffff)
	{
		CEntInfo8bc0 *e = &((CEntList8bc0 *)g_pEntityList)->m_Ent[h & 0x1fff];
		if (e->m_Serial == (int)(h >> 13))
			return e->m_pEntity;
	}
	return 0;
}
void C_BasePlayer::vfunc172(C_BaseCombatWeapon *pWeapon)
{
	if (HandleToEnt(*(unsigned long *)((char *)this + 0x1a08)) == pWeapon)
		vfunc168(0);
	if (HandleToEnt(*(unsigned long *)((char *)this + 0x1a0c)) == pWeapon)
		*(unsigned long *)((char *)this + 0x1a0c) = 0xffffffff;
}
// END FUNCTION

// FUNCTION: 0x100a9920 size=0x86
#include "CBaseEntityList.h"
#include "C_BasePlayer.h"
#include "ehandle.h"
#define V10(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7(); virtual void n##8(); virtual void n##9();
#define V100(n) V10(n##a) V10(n##b) V10(n##c) V10(n##d) V10(n##e) V10(n##f) V10(n##g) V10(n##h) V10(n##i) V10(n##j)
struct IName223 { V100(p) V100(q) V10(r) V10(s) virtual void a0(); virtual void a1(); virtual void a2(); virtual const char *GetName(); };
struct HandleVec { CBaseHandle *m_pMem; int m_alloc; int m_grow; int m_size; };
extern HandleVec g_1049d8f8;
extern HandleVec g_1049d978;
extern "C" int _strcmpi(const char *, const char *);
static inline IName223 *ResolveH(const CBaseHandle &r)
{
	if (r.m_Index != 0xffffffff) {
		CBaseEntityListEntry &e = g_pEntityList->m_EntPtrArray[r.m_Index & 0x1fff];
		if (e.m_SerialNumber == (int)(r.m_Index >> 13))
			return (IName223 *)e.m_pEntity;
	}
	return 0;
}
// TARGET: C_BasePlayer::vfunc194
C_BaseEntity *C_BasePlayer::vfunc194(const char *pName)
{
	HandleVec *pVec = &g_1049d8f8;
	if (*(int *)((char *)this + 0x1624))
		pVec = &g_1049d978;
	for (int i = 0; i < pVec->m_size; i++) {
		IName223 *pEnt = ResolveH(*(pVec->m_pMem + i));
		if (!_strcmpi(pEnt->GetName(), pName))
			return (C_BaseEntity *)pEnt;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x100a99b0 size=0x1e
#include "CInput.h"
#include "C_BasePlayer.h"
namespace lifted {
struct C1008f720 { int sub_1008f720(); };
}
int C_BasePlayer::vfunc86()
{
    int t0 = input->vfunc29();
    if (t0 != 0) {
        return ((lifted::C1008f720 *)this)->sub_1008f720();
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100a99f0 size=0x3
#include "C_BasePlayer.h"
void C_BasePlayer::vfunc189(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x100a9a00 size=0x2f
#include "C_BasePlayer.h"
struct CUnknown100a2450 { int sub_100a2450(); };
struct Fields_100a9a00 { char p0[0x88]; int m_i88; char p1[0xb0 - 0x8c]; float m_fb0; char p2[0x1704 - 0xb4]; float m_f1704; };
void C_BasePlayer::vfunc179()
{
	vfunc181();
	Fields_100a9a00 *f = (Fields_100a9a00 *)this;
	if (f->m_i88 < 1 && !(((CUnknown100a2450 *)this)->sub_100a2450() & 1))
		f->m_f1704 = -f->m_fb0;
}
// END FUNCTION

// FUNCTION: 0x100a9a30 size=0x4d
#include "C_BasePlayer.h"
struct PlayerView { char p0[0x63c]; int m63c; char p1[0x1704 - 0x640]; int m1704; };
void C_BasePlayer::vfunc180()
{
	if (vfunc18()) {
		vfunc182();
		int f = sub_100a2450();
		PlayerView *v = (PlayerView *)this;
		if (f & 1)
			v->m1704 = 0;
		if (v->m63c == -1)
			v->m63c = 0;
		vfunc136(0);
	}
	sub_100aa040();
}
// END FUNCTION

// FUNCTION: 0x100a9ac0 size=0x23
#include "C_BasePlayer.h"
namespace lifted {
struct C10095070 { int sub_10095070(); };
struct C100a99d0 { bool sub_100a99d0(); };
int sub_100aaab0();
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual int f155(); };
}
int C_BasePlayer::vfunc62()
{
    bool t0 = ((lifted::C100a99d0 *)this)->sub_100a99d0();
    if (t0 != 0) {
        ((lifted::V *)this)->f155();
    }
    lifted::sub_100aaab0();
    return ((lifted::C10095070 *)this)->sub_10095070();
}
// END FUNCTION

// FUNCTION: 0x100a9b00 size=0x4d
#include "Vector.h"
#include "C_BasePlayer.h"
Vector C_BasePlayer::vfunc150(const Vector &v) {
 return *(Vector *)((char *)this + 0x148) + v;
}
// END FUNCTION

// FUNCTION: 0x100a9bd0 size=0x3
#include "C_BasePlayer.h"
void C_BasePlayer::vfunc151(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
}
// END FUNCTION

// FUNCTION: 0x100a9c10 size=0x2a
#include "C_BasePlayer.h"
namespace lifted {
struct V { virtual void u0(); virtual int f1(); };
}
void C_BasePlayer::vfunc185(int a0)
{
    if (a0 != 0) {
        *(int *)((char *)this + 0x1a10) = *(int *)((char *)(((lifted::V *)a0)->f1()));
        return;
    }
    *(int *)((char *)this + 0x1a10) = -1;
}
// END FUNCTION

// FUNCTION: 0x100a9c40 size=0x44
#include "C_BasePlayer.h"
#include "C_BasePlayer.h"

bool C_BasePlayer::vfunc147(C_BaseCombatWeapon *pWeapon, int n)
{
	if (C_BaseCombatCharacter::vfunc147(pWeapon, n))
	{
		if (this == C_BasePlayer::GetLocalPlayer())
		{
			char *p = sub_100a9af0(n);
			if (p)
				*(unsigned int *)(p + 0x74) &= 0xffffffbf;
		}
		sub_100a9c90();
		return true;
	}
	return false;
}
// END FUNCTION

// FUNCTION: 0x100a9ca0 size=0xb
#include "C_BasePlayer.h"
struct Obj_100a99d0 { char sub_100a99d0(); };
// TARGET: C_BasePlayer::vfunc94
bool C_BasePlayer::vfunc94()
{
	return ((Obj_100a99d0 *)this)->sub_100a99d0() ? true : false;
}
// END FUNCTION

// FUNCTION: 0x100a9cb0 size=0x53
#include "CGlobalVarsBase.h"
#include "C_BasePlayer.h"
#include "C_BaseCombatWeapon.h"



// TARGET: C_BasePlayer::vfunc181
void C_BasePlayer::vfunc181()
{
	if ( gpGlobals->curtime < *(float *)((char *)this + 0xfd8) )
		return;

	if ( !vfunc148() )
		return;

	if ( !((C_BaseCombatWeapon *)vfunc148())->vfunc168() )
		return;

	((C_BaseCombatWeapon *)vfunc148())->vfunc191();
}
// END FUNCTION

// FUNCTION: 0x100a9df0 size=0x1
#include "C_BasePlayer.h"
void C_BasePlayer::vfunc184()
{
}
// END FUNCTION

// FUNCTION: 0x100aa240 size=0x7
#include "C_BasePlayer.h"
char * C_BasePlayer::vfunc195()
{
    return (char *)this + 0x1888;
}
// END FUNCTION

// FUNCTION: 0x100aa250 size=0x21
#include "C_BasePlayer.h"
int C_BasePlayer::vfunc196(int a0, int a1, int a2)
{
    *(int *)((char *)this + 0x1888) = a0;
    *(int *)((char *)this + 0x188c) = a1;
    *(int *)((char *)this + 0x1890) = a2;
    return a2;
}
// END FUNCTION

// FUNCTION: 0x100aa280 size=0x93
#include "engineclient.h"
#include "C_BasePlayer.h"

extern unsigned int g_104cfe50;



struct Mode_100aa280
{
	int a;
	int b;
	void sub_100a8f90(C_BasePlayer *pPlayer);
};

struct PlayerFields_100aa280
{
	char pad0[0x15f0];
	float m_flNextTime;
	char pad1[0x1614 - 0x15f4];
	Mode_100aa280 m_Modes[2];
	int m_iMode;
};

// TARGET: C_BasePlayer::vfunc191
void C_BasePlayer::vfunc191()
{
	g_104cfe50 &= 0xfefff7ff;

	PlayerFields_100aa280 *self = (PlayerFields_100aa280 *)this;
	if (!&self->m_Modes[self->m_iMode])
	{
		vfunc160(0);
		return;
	}

	if (self->m_flNextTime < engine->Time(0))
	{
		self->m_flNextTime = engine->Time(0) + 0.01;
		self->m_Modes[self->m_iMode].sub_100a8f90(this);
	}
}
// END FUNCTION

// FUNCTION: 0x100aa350 size=0x55
#include "C_BasePlayer.h"
#include "C_BaseCombatWeapon.h"

// TARGET: C_BasePlayer::vfunc192
C_BaseCombatWeapon *C_BasePlayer::vfunc192()
{
	for ( int i = 0; i < 6; i++ )
	{
		for ( int j = 0; j < 7; j++ )
		{
			C_BaseCombatWeapon *pWeapon = vfunc166(i, j, 0);
			if ( pWeapon && pWeapon->vfunc176() )
				return pWeapon;
		}
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x100aa3b0 size=0x55
#include "C_BasePlayer.h"
#include "C_BaseCombatWeapon.h"

// TARGET: C_BasePlayer::vfunc193
C_BaseCombatWeapon *C_BasePlayer::vfunc193()
{
	for ( int i = 5; i >= 0; i-- )
	{
		for ( int j = 6; j >= 0; j-- )
		{
			C_BaseCombatWeapon *pWeapon = vfunc166(i, j, 0);
			if ( pWeapon && pWeapon->vfunc176() )
				return pWeapon;
		}
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x100aa5d0 size=0x1f
#include "C_BasePlayer.h"

struct EngineView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
	virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
	virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
	virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
	virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
	virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
	virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
	virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
	virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
	virtual void v76();
	virtual void v77(float f);
};

extern void *g_104a57d4;

float __fastcall sub_100aa5f0(void *self);

void C_BasePlayer::vfunc186()
{
	((EngineView *)g_104a57d4)->v77(sub_100aa5f0(this));
}
// END FUNCTION
