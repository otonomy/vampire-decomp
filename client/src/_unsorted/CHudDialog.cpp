// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10052980 size=0x50e
#include "CHudDialog.h"
#include "CHUDSprite.h"
#include "ScopeTrace.h"

char *sub_1018c870(const char *);
int sub_100cd0f0();
int sub_100cd100();
extern int g_10285ad0;
extern CHudDialog *g_103ee138;

struct DlgScheme_10052980
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual int GetFont(const char *name);
	virtual void v5();
	virtual DlgColor GetColor(const char *name);
};

CHudDialog::CHudDialog(int a)
	: CManagedHudElement(a, (int)"VDialog"), m_n178(0), m_n17c(0), m_n180(0), m_n184(0), m_n188(0)
{
	ScopeTrace st("CHudDialog::CHudDialog", g_102de300);
	sub_100545d0();
	m_n194 = (int)(832 * (sub_100cd100() / 1024.0));
	m_n198 = (int)(163 * (sub_100cd0f0() / 768.0));
	m_n19c = (int)(22 * (sub_100cd0f0() / 768.0));
	m_n1a0 = (sub_100cd100() - m_n194) / 2;
	sub_101a99f0(1);
	vfunc64(1);
	vfunc63(0);
	int y = sub_100cd0f0() - m_n19c;
	sub_101a9890(m_n1a0, y - m_n198);
	sub_101a98f0(m_n194, m_n198);
	DlgScheme_10052980 *pScheme = (DlgScheme_10052980 *)sub_101ac830();
	m_nFonts[0] = pScheme->GetFont(sub_1018c870("Dlg_Base"));
	m_nFonts[1] = pScheme->GetFont(sub_1018c870("Dlg_Base"));
	m_nFonts[2] = pScheme->GetFont(sub_1018c870("Dlg_Base"));
	m_nFonts[3] = pScheme->GetFont(sub_1018c870("Dlg_Persuasion"));
	m_nFonts[4] = pScheme->GetFont(sub_1018c870("Dlg_Seduction"));
	m_nFonts[5] = pScheme->GetFont(sub_1018c870("Dlg_Dominate"));
	m_nFonts[6] = pScheme->GetFont(sub_1018c870("Dlg_Dementation"));
	m_nFonts[7] = pScheme->GetFont(sub_1018c870("Dlg_Intimidate"));
	m_aColors[0] = pScheme->GetColor("Dlg_Base");
	m_aColors[1] = pScheme->GetColor("Dlg_Persuasion");
	m_aColors[2] = pScheme->GetColor("Dlg_Seduction");
	m_aColors[3] = pScheme->GetColor("Dlg_Dominate");
	m_aColors[4] = pScheme->GetColor("Dlg_Dementation");
	m_aColors[5] = pScheme->GetColor("Dlg_Intimidate");
	m_colError = pScheme->GetColor("Dlg_Error");
	m_colFillBkg = pScheme->GetColor("Dlg_FillBkg");
	g_10285ad0 = m_colFillBkg.c[3];
	for (int y2 = 0; y2 < 2; y2++)
	{
		for (int x = 0; x < 2; x++)
		{
			m_pCorners[y2][x] = new CHUDSprite("hud/DialogFrmCrnrs", x * 64, y2 * 64, 64, 64, 128, 128);
			m_pEdges[y2][x] = new CHUDSprite("hud/DialogFrmEdgs", x * 8, y2 * 8, 8, 8, 16, 16);
		}
	}
	m_n18c = 0;
	sub_10054bd0(true);
	m_col5a70.c[0] = 230;
	m_col5a70.c[1] = 180;
	m_col5a70.c[2] = 0;
	m_col5a74.c[1] = 255;
	m_col5a74.c[2] = 255;
	m_col5a74.c[0] = 255;
	m_col5a78.c[0] = 155;
	m_col5a78.c[1] = 110;
	m_col5a78.c[2] = 0;
	m_col5a7c.c[1] = 170;
	m_col5a7c.c[2] = 170;
	m_col5a7c.c[0] = 170;
	g_103ee138 = this;
	m_b190 = true;
}
// END FUNCTION

// FUNCTION: 0x10052eb0 size=0x1e
#include "CHudDialog.h"

// VC6 writes CHudDialog's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CHudDialog *pcd_emit_10052eb0(const CHudDialog &other) { return new CHudDialog(other); }

// TARGET: ??_GCHudDialog@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10052f00 size=0x12c
#include "CHudDialog.h"
#include "CHUDSprite.h"
#include "ScopeTrace.h"
#include "CRestore.h"
// TARGET: ??1CHudDialog@@UAE@XZ
CHudDialog::~CHudDialog()
{
	void (*pfnFree)(void *);
	{
		ScopeTrace st("CHudDialog::~CHudDialog", g_102de300);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				if (m_pCorners[i][j])
					delete m_pCorners[i][j];
				if (m_pEdges[i][j])
					delete m_pEdges[i][j];
			}
		sub_101a9ff0(0);
		sub_10054e20();
		pfnFree = g_101e30fc;
	}
	m_n184 = 0;
	if (m_n180 != -1)
	{
		if (m_n178)
		{
			pfnFree((void *)m_n178);
			m_n178 = 0;
		}
		m_n17c = 0;
	}
	m_n188 = m_n178;
	if (m_n180 != -1)
	{
		if (m_n178)
		{
			pfnFree((void *)m_n178);
			m_n178 = 0;
		}
		m_n17c = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x10053080 size=0x6f
#include "CHudDialog.h"

class GBView
{
public:
	virtual void v0();
	virtual bool vfunc1();
	char m_pad0004[0x2c - 4];
	void *m_p2c;
};

struct CHudDialogView
{
	char m_pad1a4[0x1a4];
	float m_fl1a4;		// 0x1a4
	char m_pad1a8[0x1b1 - 0x1a8];
	bool m_b1b1;
	bool m_b1b2;
	bool m_b1b3;
	bool m_b1b4;
};

extern int g_103ee0f4;

bool CHudDialog::vfunc107()
{
	CHudDialogView *v = (CHudDialogView *)this;

	if ( !((GBView *)g_103ee0f4)->vfunc1() )
	{
		if ( ((GBView *)g_103ee0f4)->m_p2c )
			return false;
	}

	if ( v->m_b1b4 && ( v->m_b1b2 || v->m_b1b1 || v->m_b1b3 ) )
		return true;

	return v->m_fl1a4 > 0.0f;
}
// END FUNCTION

// FUNCTION: 0x100534d0 size=0x294
#include "CHudDialog.h"
#include "CHUDSprite.h"
#include "engineclient.h"
#include "ScopeTrace.h"

extern int g_10285ad4;
int sub_101ac8d0();

struct ISurface_100534d0
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10();
	virtual void DrawSetColor(int r, int g, int b, int a);
	virtual void DrawFilledRect(int x0, int y0, int x1, int y1);
};

void CHudDialog::vfunc98()
{
	ScopeTrace st("CHudDialog::Paint", g_102de300);
	if (g_10285ad4 == engine->vfunc44())
		return;
	g_10285ad4 = engine->vfunc44();
	sub_10053200();
	if (!vfunc107())
		return;
	if (m_flAlpha != 0.0f || m_flAlpha1a8 != 0.0f || m_flAlpha1ac != 0.0f)
	{
		int x, y;
		sub_101a98c0(&x, &y);
		int x0 = x - 1;
		int x1 = x + m_n194 + 1;
		int y0 = y - 1;
		int y1 = y + m_n198 + 1;
		((ISurface_100534d0 *)sub_101ac8d0())->DrawSetColor(0, 0, 0, (int)m_flAlpha);
		((ISurface_100534d0 *)sub_101ac8d0())->DrawFilledRect(0, 0, m_n194, m_n198);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				m_pCorners[i][j]->sub_10059b70(x - 1 + (m_n194 - 62) * j, y - 1 + (m_n198 - 62) * i, 64, 64, (int)m_flAlpha);
		m_pEdges[0][0]->sub_10059b70(x0 + 64, y0, m_n194 - 126, 8, (int)m_flAlpha);
		m_pEdges[0][1]->sub_10059b70(x1 - 8, y0 + 64, 8, m_n198 - 126, (int)m_flAlpha);
		m_pEdges[1][1]->sub_10059b70(x0 + 64, y1 - 8, m_n194 - 126, 8, (int)m_flAlpha);
		m_pEdges[1][0]->sub_10059b70(x0, y0 + 64, 8, m_n198 - 126, (int)m_flAlpha);
		sub_10053b50(true);
		sub_10053770(true);
		sub_100530f0();
		m_b190 = false;
	}
}
// END FUNCTION

// FUNCTION: 0x10054440 size=0x1
#include "CHudDialog.h"
void CHudDialog::vfunc97()
{
}
// END FUNCTION

// FUNCTION: 0x10054550 size=0x75
#include "CHudDialog.h"
#include "ScopeTrace.h"

void CHudDialog::SetDrawLastPickEnabled(bool bEnabled)
{
    ScopeTrace trace("CHudDialog::SetDrawLastPickEnabled", "", "");
    if (*(bool *)((char *)this + 0x1b3) != bEnabled)
        *(char *)((char *)this + 0x190) = 1;
    *(bool *)((char *)this + 0x1b3) = bEnabled;
}
// END FUNCTION

// FUNCTION: 0x100545d0 size=0x99
#include "CHudDialog.h"
#include "ScopeTrace.h"
#include <string.h>
// TARGET: CHudDialog::vfunc112
void CHudDialog::vfunc112()
{
	ScopeTrace st("CHudDialog::Init", g_102de300);
	sub_10054e20();
	m_b1b3 = false;
	m_b1b4 = false;
	m_b1b0 = false;
	m_b1b1 = false;
	m_flAlpha = 0;
	m_flAlpha1a8 = 0;
	m_flAlpha1ac = 0;
	memset(m_pad0a28, 0, sizeof(m_pad0a28));
}
// END FUNCTION

// FUNCTION: 0x10054b50 size=0x7
#include "CHudDialog.h"
bool CHudDialog::vfunc116()
{
    return *(bool *)((char *)this + 0x1b4);
}
// END FUNCTION

// FUNCTION: 0x10054d10 size=0x69
#include "CHudDialog.h"
#include "ScopeTrace.h"

struct DialogView { char pad[0x18c]; int m_unk18c; };

void CHudDialog::ScrollDn()
{
	ScopeTrace scope("CHudDialog::ScrollDn", g_102de300);
	if ( ((DialogView *)this)->m_unk18c > 0 )
		((DialogView *)this)->m_unk18c--;
}
// END FUNCTION

// FUNCTION: 0x10054d80 size=0x91
#include "CHudDialog.h"
#include "ScopeTrace.h"

struct DV_10054d80 { char pad[0x184]; int m184; char pad2[4]; int m18c; };

void CHudDialog::ScrollUp()
{
	ScopeTrace trace("CHudDialog::ScrollUp", g_102de300);
	DV_10054d80 *v = (DV_10054d80 *)this;
	int top;
	int a = v->m184;
	if (a - sub_10055650() < 0)
		top = 0;
	else {
		int b = v->m184;
		top = b - sub_10055650();
	}
	if (v->m18c < top)
		v->m18c++;
}
// END FUNCTION

// FUNCTION: 0x100553f0 size=0x254
#include "CHudDialog.h"
#include "ScopeTrace.h"

void sub_10114660(void *pbuf, int iSize);
int sub_10114690();
const char *sub_101146e0();
extern "C" char *__cdecl strncat(char *, const char *, unsigned int);

void CHudDialog::sub_100544d0(bool bEnabled)
{
	ScopeTrace trace("CHudDialog::SetResponsesEnabled", g_102de300);
	bool bOld = *((bool *)this + 0x1b1);
	*((bool *)this + 0x1b1) = bEnabled;
	if (bOld != bEnabled)
		*((bool *)this + 0x190) = true;
}

// TARGET: CHudDialog::vfunc115
void CHudDialog::vfunc115(int pszName, int iSize, int pbuf)
{
	ScopeTrace trace("CHudDialog::DialogControl", g_102de300);
	sub_10114660((void *)pbuf, iSize);
	switch (sub_10114690())
	{
	case 8:
	{
		bool b = sub_10114690() != 0;
		sub_10055360(b);
		vfunc5_hud(b);
		break;
	}
	case 0:
		sub_10054670(sub_10114690());
		break;
	case 1:
	{
		int n = sub_10114690();
		if (n)
		{
			if (n > 0 && n <= 4)
			{
				const char *s = sub_101146e0();
				strncat(m_szOptions[n - 1], s, 0x800);
			}
		}
		else
			strncat(m_szText, sub_101146e0(), 0x800);
		break;
	}
	case 2:
	{
		int i;
		for (i = 0; i < m_nOptions; i++)
			m_iOptionA[i] = sub_10114690();
		for (i = 0; i < m_nOptions; i++)
			m_iOptionB[i] = sub_10114690();
		break;
	}
	case 5:
		sub_10054f70(3, m_szItems[sub_10114690()]);
		break;
	case 6:
	{
		bool b = sub_10114690() != 0;
		sub_10054bd0(b);
		break;
	}
	case 7:
	{
		bool b = sub_10114690() != 0;
		sub_100544d0(b);
		SetDrawLastPickEnabled(!b);
		break;
	}
	case 3:
		sub_10054860();
		break;
	case 4:
		break;
	}
}
// END FUNCTION
