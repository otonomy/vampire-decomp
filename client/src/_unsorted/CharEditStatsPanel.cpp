// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1017d6e0 size=0x4c
#include "CharEditStatsPanel.h"
extern int g_105fb6e4;
CharEditStatsPanel::~CharEditStatsPanel()
{
	sub_1017f640();
	g_105fb6e4 = 0;
	((CStatsSub1017f860 *)((char *)this + 0x1a4))->sub_1017f860();
	((CStatsSub1017f860 *)((char *)this + 0x158))->sub_1017f860();
	((CStatsSub1017f860 *)((char *)this + 0x10c))->sub_1017f860();
	((CStatsSub1017f860 *)((char *)this + 0xc0))->sub_1017f860();
}
// END FUNCTION

// FUNCTION: 0x1017d730 size=0x1e
#include "CharEditStatsPanel.h"

// VC6 writes CharEditStatsPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CharEditStatsPanel *pcd_emit_1017d730(const CharEditStatsPanel &other) { return new CharEditStatsPanel(other); }

// TARGET: ??_GCharEditStatsPanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10180e20 size=0x5df
#include "CharEditStatsPanel.h"
#include "CharEditPanel.h"
#include "vgui2__TextEntry.h"
#include "CHud.h"
#include "StatOwner2.h"
#include "CStatDefault3List.h"
#include "C_BasePlayer.h"
#include "engineclient.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct VFeatRec_10180e20
{
	int m_nID;
	int m_unk04;
	const char *m_psz08;
	int m_unk0c;
	int m_unk10;
	const char *m_psz14;
	void sub_1014ada0(int id);
};
extern int g_105e8138;
extern VFeatRec_10180e20 **g_105e813c;
extern unsigned char g_10680f34;
extern VFeatRec_10180e20 g_10680f40;
void sub_1007db20();
extern int g_105fb600[];
extern bool g_105fb1fc;
extern bool g_105fb1fd;
extern CStatDefault3List g_105e74fc;
bool sub_101713e0();
bool sub_10174370();
void sub_10174d90(const char *pszPopup);
int sub_1017f0f0(int);
char *sub_10170f60();

struct FeatLabel_10180e20 { void sub_1017d340(int bSelected); };

struct IntroPanel_10180e20
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
	virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
	virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
	virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
	virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127(); virtual void v128(); virtual void v129();
	virtual void v130(); virtual void v131(); virtual void v132(); virtual void v133(); virtual void v134(); virtual void v135(); virtual void v136(); virtual void v137(); virtual void v138(); virtual void v139();
	virtual void v140(); virtual void v141(); virtual void v142(); virtual void v143();
	virtual bool vfunc144();
};

static inline VFeatRec_10180e20 *FindFeat_10180e20(int id)
{
	for (int i = 0; i < g_105e8138; i++)
	{
		if (g_105e813c[i]->m_nID == id)
			return g_105e813c[i];
	}
	if (!(g_10680f34 & 1))
	{
		g_10680f34 |= 1;
		g_10680f40.sub_1014ada0(-1);
		atexit(sub_1007db20);
	}
	return &g_10680f40;
}

typedef vgui2::Panel PanelBase_10180e20;

void CharEditStatsPanel::vfunc78(int nCommand)
{
	const char *command = (const char *)nCommand;
	if (!_strcmpi(command, "refresh"))
	{
		if (m_n1f8)
		{
			m_n1f8 = 0;
			sub_10180c40(-1, 1);
		}
		if (!m_n1f4)
			sub_10181cc0();
		else
			sub_10180de0();
		return;
	}
	if (command[0] == 'v' && command[1] == ' ')
	{
		sub_10180950(command + 2);
		return;
	}
	if (command[0] == 'f' && command[1] == ' ')
	{
		int iFeat = atoi(command + 2);
		int id = g_105fb600[iFeat];
		const char *psz = FindFeat_10180e20(id)->m_psz14;
		m_p2ac->vfunc108(psz ? psz : "");
		psz = FindFeat_10180e20(id)->m_psz08;
		m_p2b0->vfunc107(psz ? psz : "");
		m_p2b4->vfunc107("");
		m_p2b8->vfunc107("");
		m_p2a0->vfunc108("");
		m_p2a8->vfunc107("");
		m_p2a4->vfunc21(0);
		if (m_p1f0)
			((FeatLabel_10180e20 *)m_p1f0)->sub_1017d340(0);
		if (iFeat >= 0 && iFeat < 16)
		{
			m_p1f0 = m_pFeatLabels[iFeat];
			m_n1fc = 0;
			m_n200 = 0;
			((FeatLabel_10180e20 *)m_p1f0)->sub_1017d340(1);
		}
		return;
	}
	if (command[0] == 's' && command[1] == ' ')
	{
		sub_10181400(command);
		return;
	}
	if (!_strcmpi(command, "accept"))
	{
		bool bInGame = sub_101713e0();
		if (bInGame)
		{
			bool bNone = true;
			for (int i = 0; i < 7; i++)
			{
				if (*(int *)((char *)this + 0x80 + i * 8))
				{
					bNone = false;
					sub_10182230(i, 1);
				}
				else
					sub_10182230(i, 0);
			}
			if (!bNone)
			{
				m_p2ac->vfunc108("");
				m_p2b0->vfunc107("");
				m_p2b4->vfunc107("");
				m_p2b8->vfunc107("");
				m_p2a0->vfunc108(g_105f93c0.sub_1015f2f0("UIMiscStrs")->sub_1015ecd0(17));
				m_p2a8->vfunc107(g_105f93c0.sub_1015f2f0("UIMiscStrs")->sub_1015ecd0(18));
				m_p2a4->vfunc21(0);
				return;
			}
			if (sub_10174370())
			{
				sub_10174d90("Misc_Popup_NoName");
				return;
			}
		}
		CharEditPanel *pPanel = (CharEditPanel *)gHUD.FindElement("CharEditPanel");
		pPanel->sub_101733d0(false);
		pPanel->m_unk274 = 0;
		engine->vfunc27("vclan teamchoose done", 1);
		if (bInGame)
		{
			engine->vfunc27("giftxp 0", 1);
			engine->vfunc27("init_hotkeys", 1);
		}
		return;
	}
	if (!_strcmpi(command, "cancel"))
	{
		if (sub_101713e0() && !g_105fb1fc)
		{
			sub_10174d90("Misc_Popup_WarnCancel");
			return;
		}
		sub_10180de0();
		return;
	}
	if (!_strcmpi(command, "AutoLevelOn"))
	{
		sub_10181b80(1);
		return;
	}
	if (!_strcmpi(command, "AutoLevelOff"))
	{
		sub_10181b80(0);
		return;
	}
	if (!_strcmpi(command, "AutoSpendPoints"))
	{
		C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
		if (!pPlayer)
			return;
		int nLevel = g_105e74fc.sub_10140000(pPlayer->sub_1008ebb0())->m_b4;
		if (!sub_101713e0())
			return;
		if (sub_1017f0f0(1) == nLevel)
			return;
		char buf[32];
		sprintf(buf, "vautolvl %d -1", nLevel);
		engine->vfunc27(buf, 1);
		sub_1017dbc0();
		sub_1017f290();
		return;
	}
	if (!_strcmpi(command, "SkipIntro"))
	{
		if (m_p2e8 && sub_10170f60())
		{
			if (((IntroPanel_10180e20 *)m_p2e8)->vfunc144())
				sub_10170f60()[0xee8] = 1;
			else
				sub_10170f60()[0xee8] = 0;
		}
		return;
	}
	if (!_strcmpi(command, "reset"))
	{
		if (sub_101713e0() && !g_105fb1fd)
		{
			sub_10174d90("Misc_Popup_WarnResetStats");
			return;
		}
		sub_10180c40(-1, 1);
		return;
	}
	PanelBase_10180e20::vfunc78(nCommand);
}
// END FUNCTION

// FUNCTION: 0x10182330 size=0x21
#include "CharEditStatsPanel.h"
int sub_1016a6b0();
void CharEditStatsPanel::vfunc123()
{
	int n = sub_1016a6b0();
	vfunc33(n);
	sub_101aa0a0(1000);
}
// END FUNCTION

// FUNCTION: 0x10182360 size=0xc4
#include "CharEditStatsPanel.h"
typedef vgui2::Panel PanelT;
bool sub_101713e0();
// TARGET: ?vfunc21@CharEditStatsPanel@@UAEHH@Z
int CharEditStatsPanel::vfunc21(int bShow)
{
	((PanelT *)this)->sub_101a99f0(bShow);
	if ((char)bShow)
	{
		sub_10182460();
		if (sub_101713e0())
		{
			m_p2d8->vfunc21(1);
			m_p2bc->vfunc21(0);
			m_p2c0->vfunc21(0);
			m_p2c4->vfunc21(0);
			m_p2c8->vfunc21(0);
			return sub_1017f290();
		}
		m_p2d8->vfunc21(0);
		m_p2bc->vfunc21(1);
		m_p2c0->vfunc21(1);
		m_p2c4->vfunc21(1);
		m_p2c8->vfunc21(1);
		return sub_1017f290();
	}
	return sub_10182450();
}
// END FUNCTION

// FUNCTION: 0x10182440 size=0x1
#include "CharEditStatsPanel.h"
void CharEditStatsPanel::vfunc3()
{
}
// END FUNCTION

// FUNCTION: 0x101824d0 size=0x6
#include "CharEditStatsPanel.h"
namespace lifted {
extern char g_102d1750;
}
int CharEditStatsPanel::vfunc102()
{
    return (int)&lifted::g_102d1750;
}
// END FUNCTION
