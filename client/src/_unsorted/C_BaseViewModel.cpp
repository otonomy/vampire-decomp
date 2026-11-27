// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1007f6a0 size=0x2d
#include "CBaseEntityList.h"
#include "C_BaseViewModel.h"
#include "CBaseEntityList.h"
void *C_BaseViewModel::vfunc145()
{
	unsigned int h = *(unsigned int *)((char *)this + 0x7d8);
	if (h != 0xffffffff) {
		CBaseEntityListEntry *e = &g_pEntityList->m_EntPtrArray[h & 0x1fff];
		if (e->m_SerialNumber == (int)(h >> 13))
			return e->m_pEntity;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x1007f6d0 size=0x3
#include "C_BaseViewModel.h"
int C_BaseViewModel::vfunc86()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1007f6f0 size=0x1e
#include "C_BaseViewModel.h"

// VC6 writes C_BaseViewModel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_BaseViewModel *pcd_emit_1007f6f0(const C_BaseViewModel &other) { return new C_BaseViewModel(other); }

// TARGET: ??_GC_BaseViewModel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1007f710 size=0x9c
#include "C_BaseViewModel.h"
extern "C" __declspec(dllimport) void Plat_Free(void *);
void sub_100ab050(C_BaseViewModel *);
// TARGET: ??1C_BaseViewModel@@UAE@XZ
C_BaseViewModel::~C_BaseViewModel()
{
	sub_100ab050(this);
	m_size = 0;
	if (m_growSize != -1) {
		if (m_pMem) {
			Plat_Free(m_pMem);
			m_pMem = 0;
		}
		m_allocCount = 0;
	}
	m_pElements = m_pMem;
	if (m_growSize != -1) {
		if (m_pMem) {
			Plat_Free(m_pMem);
			m_pMem = 0;
		}
		m_allocCount = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x1007f7b0 size=0x1
#include "C_BaseViewModel.h"
void C_BaseViewModel::vfunc21()
{
}
// END FUNCTION

// FUNCTION: 0x1007f7c0 size=0x6f
#include "C_BaseViewModel.h"
#include "CCollisionProperty.h"
void C_BaseViewModel::vfunc19()
{
	vfunc21();
	Vector maxs(8.0f, 4.0f, 2.0f);
	Vector mins(-8.0f, -4.0f, -2.0f);
	sub_100a2850(&mins, &maxs);
	((CCollisionProperty *)((char *)this + 0x190))->sub_10043230(0);
	*(unsigned int *)((char *)this + 0x184) &= ~0x40000;
}
// END FUNCTION

// FUNCTION: 0x1007f890 size=0x53
#include "CGlobalVarsBase.h"
#include "Vector.h"
#include "C_BaseViewModel.h"
#define F(T, off) (*(T *)((char *)this + off))
// TARGET: C_BaseViewModel::vfunc143
void C_BaseViewModel::vfunc143(int a)
{
	if (vfunc51())
	{
		F(int, 0x63c) = a;
		F(int, 0x7e4) = (F(int, 0x7e4) + 1) & 7;
		F(int, 0x7f0) = F(int, 0x7e4);
		F(float, 0x6c) = F(float, 0x70) = gpGlobals->curtime;
		F(int, 0x648) = 0;
		sub_10095880();
	}
}
// END FUNCTION

// FUNCTION: 0x1007f940 size=0x6
#include "C_BaseViewModel.h"
namespace lifted {
extern char g_102acde4;
}
int C_BaseViewModel::vfunc16()
{
    return (int)&lifted::g_102acde4;
}
// END FUNCTION

// FUNCTION: 0x1007f950 size=0x3
#include "C_BaseViewModel.h"
int C_BaseViewModel::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1007fbb0 size=0x6
#include "C_BaseViewModel.h"
namespace lifted {
extern char g_102acd28;
}
int C_BaseViewModel::vfunc17()
{
    return (int)&lifted::g_102acd28;
}
// END FUNCTION

// FUNCTION: 0x100ab250 size=0x59
#include "C_BaseViewModel.h"
struct SubObj8 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual bool v8(); };
extern "C" void sub_100ab050(void *);
extern "C" void sub_100aaf40(void *);
// TARGET: C_BaseViewModel::vfunc29
void C_BaseViewModel::vfunc29(char a)
{
	SubObj8 *p = (SubObj8 *)((char *)this + 8);
	if (!p->v8() && a)
		sub_100ab050(this);
	else if (p->v8() && !a)
		sub_100aaf40(this);
	C_BaseEntity::vfunc29(a);
}
// END FUNCTION

// FUNCTION: 0x100ab500 size=0x3
#include "C_BaseViewModel.h"
bool C_BaseViewModel::vfunc142()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100ab510 size=0x12
#include "C_BaseViewModel.h"
namespace lifted {
int sub_100ab2b0(int, int);
}
int C_BaseViewModel::vfunc139(int a0)
{
    return lifted::sub_100ab2b0(a0, 1);
}
// END FUNCTION

// FUNCTION: 0x100ab530 size=0x2aa
#include "Vector.h"
#include "QAngle.h"
#include "C_BaseViewModel.h"
#include "C_BasePlayer.h"
#include "C_BaseCombatWeapon.h"
#include <stdio.h>
#include <stdlib.h>

struct ITempEnts_1028073c
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18();
	virtual void EjectBrass(const Vector &pos, const QAngle &angles, const QAngle &gunAngles, int type, void *p);
};
extern ITempEnts_1028073c *g_1028073c;
C_BaseCombatWeapon *sub_1009b210();
extern "C" __declspec(dllimport) void Msg(const char *fmt, ...);

void C_BaseViewModel::vfunc127(const Vector &origin, const QAngle &angles, int event, const char *options)
{
	if (m_fl650 < 0.0f && m_fl654 >= 0.9)
	{
		Vector attachOrigin;
		QAngle attachAngles;
		switch (event)
		{
		case 6001: case 6002: case 6003: case 6004:
		{
			int iAttachment = event - 6001;
			if (iAttachment > -1 && iAttachment < 4)
			{
				C_BasePlayer *pOwner = sub_100ac070();
				if (pOwner && !pOwner->sub_100a5910())
				{
					int type, count;
					type = count = 1;
					sscanf(options, "%d %d", &type, &count);
					if (!vfunc57(iAttachment + 1, (int)&attachOrigin, (int)&attachAngles))
					{
						Msg("weapon does not have attachment for shell ejection!\n");
						attachOrigin = *(const Vector *)vfunc43();
						attachAngles = *(const QAngle *)vfunc45();
					}
					for (int i = 0; i < count; i++)
						g_1028073c->EjectBrass(attachOrigin, attachAngles, GetAbsAngles(), type, &m_unka8);
					return;
				}
			}
			break;
		}
		case 6011: case 6012: case 6013: case 6014:
		{
			int iAttachment = event - 6011;
			if (iAttachment > -1 && iAttachment < 4)
			{
				int type = atoi(options);
				C_BasePlayer *pOwner = sub_100ac070();
				if (pOwner && !pOwner->sub_100a5910())
				{
					if (!vfunc57(iAttachment + 1, (int)&attachOrigin, (int)&attachAngles))
					{
						Msg("weapon does not have attachment for clip ejection!\n");
						attachOrigin = *(const Vector *)vfunc43();
						attachAngles = *(const QAngle *)vfunc45();
					}
					g_1028073c->EjectBrass(attachOrigin, attachAngles, GetAbsAngles(), type, &m_unka8);
					return;
				}
			}
			break;
		}
		}
	}
	C_BaseCombatWeapon *pWeapon = sub_1009b210();
	if (pWeapon && !pWeapon->vfunc234(this, origin, angles, event, options))
		sub_100935a0(origin, angles, event, options);
}
// END FUNCTION

// FUNCTION: 0x100ab850 size=0x37
#include "C_BaseViewModel.h"
namespace lifted {
struct C100ab990 { int sub_100ab990(int); };
struct C100ac070 { int sub_100ac070(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual int f118(int); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual int f148(); };
}
void C_BaseViewModel::vfunc118(int a0)
{
    int t0 = ((lifted::C100ac070 *)this)->sub_100ac070();
    if (t0 != 0) {
        int t1 = ((lifted::V *)t0)->f148();
        if (t1 != 0) {
            ((lifted::V *)t1)->f118(a0);
        }
    }
    ((lifted::C100ab990 *)this)->sub_100ab990(a0);
}
// END FUNCTION

// FUNCTION: 0x100abe30 size=0x4f
#include "C_BasePlayer.h"
#include "engineclient.h"
#include "C_BasePlayer.h"
#include "C_BaseViewModel.h"


struct CUnknown100a9de0
{
	float sub_100a9de0();
};


float C_BaseViewModel::vfunc122()
{
	float scale = 1.0f;
	float result = engine->Time(0);
	C_BasePlayer *p = C_BasePlayer::GetLocalPlayer();
	if (p)
	{
		scale = p->vfunc176();
		result = ((CUnknown100a9de0 *)p)->sub_100a9de0();
	}
	float v = (result - *(float *)((char *)this + 0x70)) * 10.0f;
	return v * scale;
}
// END FUNCTION

// FUNCTION: 0x100abfa0 size=0x1c
#include "C_BaseViewModel.h"
namespace lifted {
bool __stdcall sub_1009f140(int);
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual int f132(int); };
}
void C_BaseViewModel::vfunc37()
{
    bool t0 = lifted::sub_1009f140(0x10);
    if (t0 != 0) {
        ((lifted::V *)this)->f132(0);
    }
}
// END FUNCTION

// FUNCTION: 0x100abfc0 size=0x25
#include "C_BaseViewModel.h"
namespace lifted {
int sub_1009b210();
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual void u168(); virtual void u169(); virtual void u170(); virtual void u171(); virtual void u172(); virtual void u173(); virtual void u174(); virtual void u175(); virtual void u176(); virtual void u177(); virtual void u178(); virtual void u179(); virtual void u180(); virtual void u181(); virtual void u182(); virtual void u183(); virtual void u184(); virtual void u185(); virtual void u186(); virtual void u187(); virtual void u188(); virtual void u189(); virtual void u190(); virtual void u191(); virtual void u192(); virtual void u193(); virtual void u194(); virtual void u195(); virtual void u196(); virtual void u197(); virtual void u198(); virtual void u199(); virtual void u200(); virtual void u201(); virtual void u202(); virtual void u203(); virtual void u204(); virtual void u205(); virtual void u206(); virtual void u207(); virtual void u208(); virtual void u209(); virtual void u210(); virtual void u211(); virtual void u212(); virtual void u213(); virtual void u214(); virtual void u215(); virtual void u216(); virtual void u217(); virtual void u218(); virtual void u219(); virtual void u220(); virtual void u221(); virtual void u222(); virtual void u223(); virtual void u224(); virtual void u225(); virtual void u226(); virtual void u227(); virtual void u228(); virtual void u229(); virtual void u230(); virtual void u231(); virtual void u232(); virtual void u233(); virtual void u234(); virtual void u235(); virtual void u236(); virtual void u237(); virtual void u238(); virtual void u239(); virtual void u240(); virtual void u241(); virtual void u242(); virtual void u243(); virtual void u244(); virtual void u245(); virtual void u246(); virtual void u247(); virtual int f248(int, int, int); };
}
void C_BaseViewModel::vfunc120(int a0, int a1)
{
    int t0 = lifted::sub_1009b210();
    if (t0 != 0) {
        ((lifted::V *)t0)->f248((int)this, a0, a1);
    }
}
// END FUNCTION
