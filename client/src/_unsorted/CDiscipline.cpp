// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1004e8b0 size=0x18a
#include "CDiscipline.h"
int sub_100cd0f0();
char *sub_1018c870(const char *);
extern char g_103ede7c;
extern int g_103ede80;
extern int g_10284b9c;
extern CDiscipline *g_103ede78;
// TARGET: ??0CDiscipline@@QAE@H@Z
CDiscipline::CDiscipline(int a)
	: CManagedHudElement(a, (int)"Discipline")
{
	sub_1004eb00();
	vfunc63(0);
	sub_101a9890(m_unk178, m_unk17c);
	sub_101a98f0(m_n180 << 2, sub_100cd0f0());
	m_n188 = m_n180;
	m_n18c = m_n184;
	m_c1a4 = 0;
	m_b1a6 = false;
	m_b1a5 = false;
	m_n1a0 = 0xff;
	m_nEntries = 0;
	int i = 0;
	CDisciplineEntry *e = m_Entries;
	do {
		e->m_nId = -1;
		e->m_unk4 = 0;
		e++;
		i++;
	} while (i < 6);
	m_p1f4 = 0;
	m_p1f8 = 0;
	g_103ede7c = 0;
	g_103ede80 = 0;
	g_10284b9c = -1;
	g_103ede78 = this;
	IDiscScheme *s = sub_101ac830();
	m_nFont200 = s->GetFont(sub_1018c870("Copperplate"));
	m_clr[0] = s->GetColor("DiscUI_Aqua");
	m_clr[1] = s->GetColor("DiscUI_Orange");
	m_clr[2] = s->GetColor("DiscUI_Yellow");
	m_clr[3] = s->GetColor("DiscUI_Gray");
}
// END FUNCTION

// FUNCTION: 0x1004ea80 size=0x75
#include "CDiscipline.h"
// TARGET: ??1CDiscipline@@UAE@XZ
CDiscipline::~CDiscipline()
{
	CBasePanel::sub_101a9ff0(0);
	for (int i = 0; i < m_nEntries; i++)
		if (m_Entries[i].m_nId != -1)
			sub_1004ed00(m_Entries[i].m_nId);
	if (m_p1f4) delete m_p1f4;
	if (m_p1f8) delete m_p1f8;
}
// END FUNCTION

// FUNCTION: 0x1004f270 size=0x62
#include "CDiscipline.h"

void CDiscipline::vfunc114(int id, int val)
{
	int idx = sub_1004ec90(id);
	if (idx == -1)
	{
		idx = sub_1004ecb0(id);
		if (idx == -1)
			return;
	}

	if (m_Entries[idx].m_unk4 < val)
	{
		sub_1004ed80(id, 1, 0);
	}
	else if (m_Entries[idx].m_unk4 > 0 && val == 0)
	{
		sub_1004ed80(id, 0, 0);
	}

	m_Entries[idx].m_unk4 = val;

	if (val <= 0)
	{
		sub_1004ed00(id);
	}
}
// END FUNCTION

// FUNCTION: 0x1004f2e0 size=0x23
#include "CDiscipline.h"
bool sub_10163bf0();
struct IUnkG286860 { virtual void v0(); virtual void v1(); virtual bool Check(int); };
extern IUnkG286860 *g_10286860;
bool CDiscipline::vfunc107()
{
	return sub_10163bf0() && !g_10286860->Check(0);
}
// END FUNCTION

// FUNCTION: 0x1004f310 size=0x3e3
#include "CDiscipline.h"
#include "CHUDSprite.h"
#include "C_BasePlayer.h"
#include "CHud.h"
#include "CInput.h"
#include "ConVar.h"
#include "engineclient.h"

extern ConVar g_105faa30;
extern bool g_103ede7c;
extern int g_103ede80;
extern int g_10284b9c;
extern int g_10284b84[];
extern int g_103ede48[];
extern int g_103ede5c[];
int sub_100cd100();
int sub_100cd0f0();
extern "C" int sprintf(char *, const char *, ...);

void CDiscipline::vfunc98()
{
	int x, y;
	sub_101a98c0(&x, &y);
	if (m_b1a5 && m_n1a0 < 255) {
		m_n1a0 = m_n1a0 + 5 > 255 ? 255 : m_n1a0 + 5;
	} else if (m_b1a6 && m_n1a0 > 0) {
		m_n1a0 = m_n1a0 - 5 < 0 ? 0 : m_n1a0 - 5;
	}
	x = x + m_n180 * 3;
	y = y + m_n18c * 4 + 20;
	if (!m_p1f4) {
		m_p1f4 = (CDisciplineChild *)new CHUDSprite("hud/BloodDrop", 0, 0, 16, 16, 16, 16);
		m_p1f8 = (CDisciplineChild *)new CHUDSprite("hud/FaithDrop", 0, 0, 16, 16, 16, 16);
	}
	C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
	CHUDSprite *pDrop;
	if (pPlayer && !pPlayer->sub_1008eb70())
		pDrop = (CHUDSprite *)m_p1f8;
	else
		pDrop = (CHUDSprite *)m_p1f4;
	static ConVar *v_hidevgui = cvar->FindVar("v_hidevgui");
	if (v_hidevgui && v_hidevgui->GetInt())
		return;
	if (!g_105faa30.GetInt())
		return;
	if (input->vfunc52() > 0.0f)
		return;
	sub_1004fa40();
	if (!g_103ede7c)
		return;
	if (pPlayer) {
		if (pPlayer->m_StatListManager.Find(0)->sub_1015dbd0(12) < g_103ede80)
			g_103ede80 = pPlayer->m_StatListManager.Find(0)->sub_1015dbd0(12);
	}
	if (g_103ede80 <= 0)
		return;
	char buf[32];
	sprintf(buf, "discipline_%d", g_10284b9c);
	CHudSub *pIcon = (CHudSub *)gHUD.GetIcon(buf);
	if (!pIcon)
		return;
	x = (sub_100cd100() - m_n180) / 2;
	y = (sub_100cd0f0() - m_n184) / 2;
	if (pIcon->m_pObj)
		((CHUDSprite *)pIcon->m_pObj)->sub_10059620(x, y, m_n180, m_n184);
	if (g_103ede80 > 1) {
		sprintf(buf, "discipline_%ds", g_10284b9c);
		CHudSub *pIcon2 = (CHudSub *)gHUD.GetIcon(buf);
		if (pIcon2->m_pObj)
			((CHUDSprite *)pIcon2->m_pObj)->sub_10059b70(x, y, m_n188, m_n18c, g_10284b84[g_103ede80]);
	}
	for (int i = 0; i < g_103ede80; i++)
		pDrop->sub_10059620(x + g_103ede48[i], y + g_103ede5c[i], m_n190, m_n194);
}
// END FUNCTION
