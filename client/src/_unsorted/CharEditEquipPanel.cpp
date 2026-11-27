// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10178850 size=0x1e
#include "CharEditEquipPanel.h"

// VC6 writes CharEditEquipPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CharEditEquipPanel *pcd_emit_10178850(const CharEditEquipPanel &other) { return new CharEditEquipPanel(other); }

// TARGET: ??_GCharEditEquipPanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1017a330 size=0x284
#include "CharEditEquipPanel.h"
#include "CharEditPanel.h"
#include "CUnknown101ed170.h"
#include "CVStatList_t.h"
#include "C_BasePlayer.h"
#include "CHud.h"
#include "vgui2__Label.h"
#include "vgui2__TextEntry.h"
#include "engineclient.h"
#include <string.h>
#include <stdlib.h>

extern "C" int __cdecl _strcmpi(const char *, const char *);

struct EquipSlotV	// 0x24-byte records at 0x105fb458
{
	int m_unk00[7];
	int m_nCost;	// 0x1c
	int m_unk20;
	void sub_10178790(int);
	void sub_10178820();
};

struct ClanRecordTableV	// CUtlVector of clan records at 0x105e85ec
{
	int m_unk00[3];
	int m_nRecords;	// 0x0c
	CUnknown101ed170 **m_pRecords;	// 0x10

	CUnknown101ed170 *Find(int id)
	{
		for (int i = 0; i < m_nRecords; i++) {
			if (m_pRecords[i]->m_id == id)
				return m_pRecords[i];
		}
		static CUnknown101ed170 s_default(-1);
		return &s_default;
	}
};

struct SchemeColorV
{
	unsigned char r, g, b, a;
	SchemeColorV() {}
};

struct ISchemeV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual SchemeColorV GetColor(const char *name);
};

extern ClanRecordTableV g_105e85ec;
extern int g_105fb5f0;
extern EquipSlotV g_105fb458[];
const char *sub_1017ada0(int clan, int index);
const char *sub_1017ae30(int clan, int index);

typedef vgui2::PropertyPage EquipBaseClass;

#define m_pItemName (*(vgui2::Label **)((char *)this + 0x80))
#define m_pItemDesc (*(vgui2::TextEntry **)((char *)this + 0x84))

void CharEditEquipPanel::vfunc78(int command)
{
	const char *cmd = (const char *)command;
	if (!_strcmpi(cmd, "refresh"))
		sub_1017a7f0();

	if (!strncmp(cmd, "veqTrgB", 7)) {
		int index = atoi(cmd + 7);
		if (index >= g_105e85ec.Find(g_105fb5f0)->m_n0c)
			return;
		C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
		if (!pPlayer)
			return;
		if (((CVStatListSet *)((char *)pPlayer + 0x1164))->Find(0)->sub_1015dbd0(0x22) >= g_105fb458[index].m_nCost)
			g_105fb458[index].sub_10178820();
		else
			g_105fb458[index].sub_10178790(0);

		ISchemeV *pScheme = (ISchemeV *)sub_101ac830();
		m_pItemName->vfunc108(sub_1017ada0(g_105fb5f0, index));
		m_pItemName->vfunc51(*(int *)&pScheme->GetColor("VDesHeaderText"));
		m_pItemDesc->vfunc107(sub_1017ae30(g_105fb5f0, index));
		sub_1017a5c0();
	} else if (!_strcmpi(cmd, "LastArmor")) {
		sub_10179e40();
	} else if (!_strcmpi(cmd, "NextArmor")) {
		sub_10179fe0();
	} else if (!_strcmpi(cmd, "accept")) {
		sub_1017a5c0();
		CharEditPanel *pPanel = (CharEditPanel *)gHUD.FindElement("CharEditPanel");
		pPanel->sub_101733d0(false);
		pPanel->m_unk274 = 0;
		engine->vfunc27("vclan teamchoose done", 1);
	} else if (!_strcmpi(cmd, "cancel")) {
		sub_1017a630();
	} else {
		EquipBaseClass::vfunc78(command);
	}
}
// END FUNCTION

// FUNCTION: 0x1017a690 size=0x3
#include "CharEditEquipPanel.h"
void CharEditEquipPanel::vfunc124(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1017a7b0 size=0x6
#include "CharEditEquipPanel.h"
namespace lifted {
extern char g_102d0e80;
}
int CharEditEquipPanel::vfunc102()
{
    return (int)&lifted::g_102d0e80;
}
// END FUNCTION

// FUNCTION: 0x1017a7d0 size=0x1
#include "CharEditEquipPanel.h"
void CharEditEquipPanel::vfunc119()
{
}
// END FUNCTION

// FUNCTION: 0x1017ab90 size=0x21
#include "CharEditEquipPanel.h"
int sub_1016a6b0();
void CharEditEquipPanel::vfunc123()
{
	int n = sub_1016a6b0();
	vfunc33(n);
	sub_101aa0a0(1000);
}
// END FUNCTION

// FUNCTION: 0x1017abc0 size=0x28
#include "CharEditEquipPanel.h"
namespace lifted {
struct C1017ac30 { int sub_1017ac30(); };
struct C1017ac40 { int sub_1017ac40(); };
struct C101a99f0 { int sub_101a99f0(int); };
}
int CharEditEquipPanel::vfunc21(int a0)
{
    int t0 = ((lifted::C101a99f0 *)this)->sub_101a99f0(a0);
    if (((char)a0) != 0) {
        return ((lifted::C1017ac40 *)this)->sub_1017ac40();
    }
    return ((lifted::C1017ac30 *)this)->sub_1017ac30();
}
// END FUNCTION

// FUNCTION: 0x1017ac00 size=0x28
#include "engineclient.h"
#include "CharEditEquipPanel.h"
extern int g_104a0d50;
void CharEditEquipPanel::vfunc3()
{
	if (engine->IsInGame() && g_104a0d50)
		sub_10179850();
}
// END FUNCTION
