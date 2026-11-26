// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10052eb0 size=0x1e
#include "CHudDialog.h"

// VC6 writes CHudDialog's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CHudDialog *pcd_emit_10052eb0(const CHudDialog &other) { return new CHudDialog(other); }

// TARGET: ??_GCHudDialog@@UAEPAXI@Z
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
