// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10097ec0 size=0x1e
#include "C_BaseCombatCharacter.h"

// VC6 writes C_BaseCombatCharacter's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_BaseCombatCharacter *pcd_emit_10097ec0(const C_BaseCombatCharacter &other) { return new C_BaseCombatCharacter(other); }

// TARGET: ??_GC_BaseCombatCharacter@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10097ee0 size=0x27
#include "C_BaseCombatCharacter.h"
// TARGET: ??1C_BaseCombatCharacter@@UAE@XZ
C_BaseCombatCharacter::~C_BaseCombatCharacter()
{
}
// END FUNCTION

// FUNCTION: 0x10097fa0 size=0x2d
#include "C_BaseCombatCharacter.h"
#include "CBaseEntityList.h"
extern CBaseEntityList *g_102b8e98;
void *C_BaseCombatCharacter::vfunc148()
{
	unsigned int h = *(unsigned int *)((char *)this + 0x105c);
	if (h != 0xffffffff) {
		CBaseEntityListEntry *e = &g_102b8e98->m_EntPtrArray[h & 0x1fff];
		if (e->m_SerialNumber == (int)(h >> 13))
			return e->m_pEntity;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x10098120 size=0xa8
#include "C_BaseCombatCharacter.h"
#include "C_BaseCombatWeapon.h"
#include "ehandle.h"

inline C_BaseCombatWeapon *GetAW10098120(char *self)
{
	unsigned int h = *(unsigned int *)(self + 0x105c);
	if (h != 0xffffffff)
	{
		CBaseEntityListEntry &e = g_102b8e98->m_EntPtrArray[h & 0x1fff];
		if (e.m_SerialNumber == (int)(h >> 13))
			return (C_BaseCombatWeapon *)e.m_pEntity;
	}
	return 0;
}

bool C_BaseCombatCharacter::vfunc147(C_BaseCombatWeapon *pWeapon, int)
{
	if (!pWeapon->vfunc185())
		return false;
	if (((CBaseHandle *)((char *)this + 0x105c))->Get() && !GetAW10098120((char *)this)->vfunc189((int)pWeapon))
		return false;
	((CBaseHandle *)((char *)this + 0x105c))->m_Index = *pWeapon->vfunc1();
	pWeapon->vfunc188();
	return true;
}
// END FUNCTION

// FUNCTION: 0x100981d0 size=0x6
#include "C_BaseCombatCharacter.h"
namespace lifted {
extern char g_102ae7ac;
}
int C_BaseCombatCharacter::vfunc16()
{
    return (int)&lifted::g_102ae7ac;
}
// END FUNCTION

// FUNCTION: 0x100981e0 size=0x3
#include "C_BaseCombatCharacter.h"
int C_BaseCombatCharacter::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10098710 size=0x6
#include "C_BaseCombatCharacter.h"
namespace lifted {
extern char g_102ae794;
}
int C_BaseCombatCharacter::vfunc17()
{
    return (int)&lifted::g_102ae794;
}
// END FUNCTION

// FUNCTION: 0x10099850 size=0x14
#include "C_BaseCombatCharacter.h"
namespace lifted {
extern char g_102aea5c;
extern char g_102aea78;
bool sub_10099870();
}
int C_BaseCombatCharacter::vfunc143()
{
    bool t0 = lifted::sub_10099870();
    if (t0 != 0) {
        return (int)&lifted::g_102aea78;
    }
    return (int)&lifted::g_102aea5c;
}
// END FUNCTION

// FUNCTION: 0x10099c00 size=0x21f
#include "Vector.h"
#include "C_BaseCombatCharacter.h"
struct CUnknown10094ec0 { int sub_10094ec0(const char *); };
struct Q8_Obj { void sub_100af150(); };
extern int sub_100b47b0(const char *, int, int, int, int, int, float, float, float, float);
struct Q8_Weap
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56();
	virtual bool vfunc57(int, int, int);
	int sub_1007b160();
};
struct Q8_Glob { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
	virtual int vfunc39(); };
struct Q8_Temp { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void vfunc6(int, int, int, int, int, int, int, int, int); };
extern Q8_Glob *g_104a57e4;
extern Q8_Temp *g_1028073c;
extern int g_104d5190;
extern "C" int atoi(const char *);

void C_BaseCombatCharacter::vfunc127(const Vector &origin, const QAngle &angles, int event, const char *options)
{
	Vector vA, vB, vC, vD;
	int hTime = g_104a57e4->vfunc39();
	int idx;
	switch (event)
	{
	case 5003: idx = 0; break;
	case 5013: idx = 1; break;
	case 5023: idx = 2; break;
	case 5033: idx = 3; break;
	default: goto other;
	}
	if (*(int *)((char *)this + 0x77c) > idx)
	{
		Q8_Weap *pW = (Q8_Weap *)vfunc148();
		if (!pW || !pW->vfunc57(idx + 1, (int)&vB, (int)&vA))
			vfunc57(idx + 1, (int)&vB, (int)&vA);
		pW = (Q8_Weap *)vfunc148();
		if (pW)
		{
			g_1028073c->vfunc6((int)&vB, (int)&vA, atoi(options), hTime, 0, pW->sub_1007b160() + 0x50270, pW->sub_1007b160() + 0x502f0, (int)pW, 1);
		}
		else
			g_1028073c->vfunc6((int)&vB, (int)&vA, atoi(options), hTime, 0, 0, 0, 0, 0);
		return;
	}
other:
	if (event != 0x1400)
	{
		C_BaseAnimating::sub_100935a0(origin, angles, event, options);
	}
	else
	{
		if (!(*(int *)((char *)this + 0x74) & 0x300))
		{
			Q8_Weap *pW = (Q8_Weap *)vfunc148();
			if (pW)
			{
				int i = ((CUnknown10094ec0 *)pW)->sub_10094ec0("slampoint");
				if (i >= 0 && pW->vfunc57(i, (int)&vC, (int)&vD))
				{
					Q8_Obj *p = (Q8_Obj *)sub_100b47b0(options, (int)&vC, (int)&g_104d5190, 0, 6, i, 1.0f, 1.0f, 1.0f, 1.0f);
					if (p)
						p->sub_100af150();
				}
			}
		}
	}
}
// END FUNCTION
