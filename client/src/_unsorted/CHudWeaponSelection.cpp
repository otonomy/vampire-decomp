// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101a7660 size=0x1e
#include "CHudWeaponSelection.h"

// VC6 writes CHudWeaponSelection's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CHudWeaponSelection *pcd_emit_101a7660(const CHudWeaponSelection &other) { return new CHudWeaponSelection(other); }

// TARGET: ??_GCHudWeaponSelection@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101a7680 size=0x6a
#include "CHudWeaponSelection.h"
extern "C" __declspec(dllimport) void Msg(const char *, ...);
struct SchemeV {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual int GetFont(const char *name);
};
struct HudObj10678dd4 { void sub_101a8c80(); };
extern HudObj10678dd4 g_10678dd4;
int sub_1018ccb0(const char *);
SchemeV *sub_1018ccd0(int);
const char *sub_1018c870(const char *);
extern int g_10678d8c;
extern int g_10678d44;
void CHudWeaponSelection::vfunc1()
{
	vfunc7();
	g_10678dd4.sub_101a8c80();
	*(float *)((char *)this + 0x18) = -1.0f;
	g_10678d8c = sub_1018ccb0("Resource/VampireScheme.res");
	if (!g_10678d8c) {
		Msg("Error loading '%s'\n", "Resource/VampireScheme.res");
		return;
	}
	SchemeV *scheme = sub_1018ccd0(g_10678d8c);
	g_10678d44 = scheme->GetFont(sub_1018c870("HudFont"));
}
// END FUNCTION

// FUNCTION: 0x101a76f0 size=0x13
#include "CHudWeaponSelection.h"
namespace lifted {
extern char g_10678dd4;
struct C101a8c90 { int sub_101a8c90(); };
}
void CHudWeaponSelection::vfunc7()
{
    int t0 = ((lifted::C101a8c90 *)((int)&lifted::g_10678dd4))->sub_101a8c90();
    *(char *)((char *)this + 0x1c) = 0;
}
// END FUNCTION

// FUNCTION: 0x101a7710 size=0xab
#include "CHudWeaponSelection.h"
#include "CHud.h"

extern const char g_102af2e8[];
int sub_100ccdc0(void *);
int sub_100ccde0(void *);
int sub_100cd100();
struct CHudRes100f0180 { void sub_100f0180(int); };
struct XRes101a8ca0 { void sub_101a8ca0(); };
extern XRes101a8ca0 g_10678dd4;
extern int g_10678d98;
extern int g_10678dd0;
extern int g_10678dcc;
extern int g_10678cf0;

void CHudWeaponSelection::vfunc2()
{
	m_pBucket1 = gHUD.GetIcon("bucket1");
	m_pSelection = gHUD.GetIcon("selection");
	g_10678d98 = sub_100ccdc0(m_pBucket1);
	g_10678dd0 = sub_100ccde0(m_pBucket1);
	CHudRes100f0180 *pRes = (CHudRes100f0180 *)gHUD.FindElement(g_102af2e8);
	pRes->sub_100f0180(g_10678dd0);
	g_10678dd4.sub_101a8ca0();
	if (sub_100cd100() >= 640)
	{
		g_10678dcc = 20;
		g_10678cf0 = 4;
	}
	else
	{
		g_10678dcc = 10;
		g_10678cf0 = 2;
	}
	vfunc7();
}
// END FUNCTION

// FUNCTION: 0x101a78c0 size=0x124
#include "C_BasePlayer.h"
#include "CHudWeaponSelection.h"

extern "C" int __cdecl _strcmpi(const char *, const char *);

struct CWeaponInfo_101a78c0
{
	char pad0[0x2450];
	char m_szName[64];
};

struct CWeapon_101a78c0
{
	char pad0[0x954];
	int m_n954;
	CWeaponInfo_101a78c0 *sub_1007b160();
};

struct CHudPanel_101a78c0
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
	virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
	virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
	virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
	virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
	virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
	virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
	virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
	virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104();
	virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
	virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114();
	virtual void v115();
	virtual void v116(int a, int b); // +0x1d0
};

struct CPlayer_101a78c0
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
	virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
	virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
	virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
	virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
	virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
	virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
	virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
	virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104();
	virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
	virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114();
	virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
	virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124();
	virtual void v125(); virtual void v126(); virtual void v127(); virtual void v128(); virtual void v129();
	virtual void v130(); virtual void v131(); virtual void v132(); virtual void v133(); virtual void v134();
	virtual void v135(); virtual void v136(); virtual void v137(); virtual void v138(); virtual void v139();
	virtual void v140(); virtual void v141(); virtual void v142(); virtual void v143(); virtual void v144();
	virtual void v145(); virtual void v146(); virtual void v147(); virtual void v148(); virtual void v149();
	virtual void v150(); virtual void v151(); virtual void v152(); virtual void v153(); virtual void v154();
	virtual void v155(); virtual void v156();
	virtual void v157(int a); // +0x274
	virtual void v158(); virtual void v159();
	virtual void v160(int a); // +0x280
	virtual void v161(); virtual void v162(); virtual void v163(); virtual void v164(); virtual void v165();
	virtual void v166();
	virtual CWeapon_101a78c0 *v167(); // +0x29c
	virtual void v168(); virtual void v169(); virtual void v170(); virtual void v171(); virtual void v172();
	virtual void v173(); virtual void v174(); virtual void v175(); virtual void v176(); virtual void v177();
	virtual void v178(); virtual void v179(); virtual void v180(); virtual void v181(); virtual void v182();
	virtual void v183(); virtual void v184(); virtual void v185(); virtual void v186(); virtual void v187();
	virtual void v188(); virtual void v189(); virtual void v190();
	virtual void v191(); // +0x2fc

	bool sub_100a6b90();
};

extern int g_104cfe50;
CHudPanel_101a78c0 *sub_100561f0();
bool __cdecl sub_101a77c0(CPlayer_101a78c0 *pPlayer, CWeapon_101a78c0 *pWpn);

struct CHudWpnSelView_101a78c0
{
	char pad0[0x20];
	CWeapon_101a78c0 *m_pSelectedWeapon;
};

// TARGET: ?vfunc6@CHudWeaponSelection@@UAEXXZ
void CHudWeaponSelection::vfunc6()
{
	CPlayer_101a78c0 *pPlayer = ((CPlayer_101a78c0 *)C_BasePlayer::GetLocalPlayer());
	if (!pPlayer)
		return;

	if (pPlayer->sub_100a6b90())
	{
		if (g_104cfe50 & 1)
		{
			pPlayer->v160(0);
		}
		return;
	}

	CHudWpnSelView_101a78c0 *v = (CHudWpnSelView_101a78c0 *)this;
	v->m_pSelectedWeapon = 0;

	if (pPlayer->v167() && !sub_101a77c0(pPlayer, pPlayer->v167()))
	{
		if (g_104cfe50 & 0x2800000)
		{
			sub_100561f0()->v116(0x16, 0);
			return;
		}
	}

	if (g_104cfe50 & 0x800000)
	{
		v->m_pSelectedWeapon = pPlayer->v167();
		if (v->m_pSelectedWeapon && !_strcmpi(v->m_pSelectedWeapon->sub_1007b160()->m_szName, "bloodpack") && v->m_pSelectedWeapon->m_n954 > 0)
		{
			pPlayer->v157(0);
			return;
		}
		pPlayer->v157(1);
		return;
	}
	else if (g_104cfe50 & 0x2000000)
	{
		v->m_pSelectedWeapon = pPlayer->v167();
		pPlayer->v157(0);
		return;
	}
	else if (g_104cfe50 & 0x1000000)
	{
		pPlayer->v191();
	}
}
// END FUNCTION

// FUNCTION: 0x101a7bc0 size=0x3e
#include "C_BasePlayer.h"
#include "CHudWeaponSelection.h"
#include "C_BasePlayer.h"
bool sub_1018c770();
// TARGET: CHudWeaponSelection::vfunc5
void CHudWeaponSelection::vfunc5(int a)
{
    C_BasePlayer *p = C_BasePlayer::GetLocalPlayer();
    if (p && !sub_1018c770()) {
        C_BaseCombatWeapon *w = p->vfunc167();
        this->sub_101a7fa0(a, p, w, 0, 0, 0, 0, 0);
    }
}
// END FUNCTION
