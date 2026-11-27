// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100608d0 size=0xc3
#include "CSignUI.h"
extern char g_103eee48;
extern CSignUI *g_103eee40;
// TARGET: ??0CSignUI@@QAE@H@Z
CSignUI::CSignUI(int a)
    : CManagedHudElement(a, (int)"SignUI")
{
	vfunc63(0);
	vfunc62(0);
	vfunc64(0);
	sub_101a99f0(0);
	m_unk178 = 0;
	m_unk17c = 0;
	g_103eee48 = 0;
	m_b180 = 1;
	m_b1c9 = 0;
	m_f18c = 0.5f;
	g_103eee40 = this;
	m_b181 = 0;
	m_unk188 = 0;
}
// END FUNCTION

// FUNCTION: 0x100609a0 size=0x1e
#include "CSignUI.h"

// VC6 writes CSignUI's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CSignUI *pcd_emit_100609a0(const CSignUI &other) { return new CSignUI(other); }

// TARGET: ??_GCSignUI@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100609c0 size=0xef
#include "CSignUI.h"
extern CSignUI *g_103eee40;
// TARGET: ??1CSignUI@@UAE@XZ
CSignUI::~CSignUI()
{
	sub_101a9ff0(0);
	sub_10060c30();
	g_103eee40 = 0;
}
// END FUNCTION

// FUNCTION: 0x100612a0 size=0xca
#include "CSignUI.h"
#include "engineclient.h"
#include "CHud.h"

void sub_10114660(int, int);
int sub_10114690();
int sub_101146c0();
float sub_101146d0();
int sub_101146e0();
void sub_1018ccf0(int);
void sub_101a7ac0(void *);
extern int g_103eee44;
struct SignUIView_100612a0
{
	void sub_10061370();
	void sub_100613a0();
	void sub_10061520(int);
};

void CSignUI::vfunc114(int a, int b, int c)
{
	sub_10114660(c, b);
	int flag = sub_10114690();
	m_f18c = sub_101146d0();
	g_103eee44 = sub_101146c0();
	if (flag)
	{
		sub_101a7ac0(gHUD.FindElement("CHudWeaponSelection"));
		if (sub_10114690())
			((SignUIView_100612a0 *)this)->sub_10061370();
		*((char *)this + 0x182) = m_b181;
		vfunc5_hud(true);
		*(float *)&m_unk184 = engine->Time(1);
		((SignUIView_100612a0 *)this)->sub_10061520(sub_101146e0());
		sub_1018ccf0(8);
	}
	else
	{
		((SignUIView_100612a0 *)this)->sub_100613a0();
		vfunc5_hud(false);
	}
}
// END FUNCTION
