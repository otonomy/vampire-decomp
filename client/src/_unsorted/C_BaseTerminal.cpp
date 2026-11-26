// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100c6890 size=0x6
#include "C_BaseTerminal.h"
namespace lifted {
extern char g_102b7144;
}
int C_BaseTerminal::vfunc16()
{
    return (int)&lifted::g_102b7144;
}
// END FUNCTION

// FUNCTION: 0x100c68a0 size=0x3
#include "C_BaseTerminal.h"
int C_BaseTerminal::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100c6bf0 size=0x1e
#include "C_BaseTerminal.h"

// VC6 writes C_BaseTerminal's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_BaseTerminal *pcd_emit_100c6bf0(const C_BaseTerminal &other) { return new C_BaseTerminal(other); }

// TARGET: ??_GC_BaseTerminal@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100c6c10 size=0xa6
#include "engineclient.h"
#include "C_BaseTerminal.h"
extern "C" __declspec(dllimport) void __cdecl Plat_Free(void *);
// TARGET: ??1C_BaseTerminal@@UAE@XZ
C_BaseTerminal::~C_BaseTerminal()
{
	engine->vfunc12(this);
	sub_100c7550();
	m_size = 0;
	if (m_grow != -1) {
		if (m_pMem) {
			Plat_Free(m_pMem);
			m_pMem = 0;
		}
		m_alloc = 0;
	}
	m_pElements = m_pMem;
	if (m_grow != -1) {
		if (m_pMem) {
			Plat_Free(m_pMem);
			m_pMem = 0;
		}
		m_alloc = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x100c7090 size=0x4b5
#define PCD_LPF_CTOR
#include "C_BaseTerminal.h"
#include "C_RecipientFilter.h"
#include "engineclient.h"
#include <string.h>

char *sub_1004ba40(const char *fmt, ...);	// VarArgs
extern "C" __declspec(dllimport) float RandomFloat(float flMinVal, float flMaxVal);
extern "C" __declspec(dllimport) int RandomInt(int iMinVal, int iMaxVal);

struct TermRecord_100c7090
{
	int m_a[0x12];
};

#define clamp_100c7090(val, minVal, maxVal) (((val) > (maxVal)) ? (maxVal) : (((val) < (minVal)) ? (minVal) : (val)))

bool C_BaseTerminal::vfunc25(int key)
{
	if (key == 0x60)
		return false;

	if (!m_bF04)
		return false;

	if (!m_bE88)
		return true;

	char text[40];
	strcpy(text, m_szText);
	int cursor = clamp_100c7090(m_nE78 - m_nE8c, 0, (int)strlen(text));

	if (m_bF0c && key == 0x63)
	{
		m_bF0c = false;
		engine->vfunc27("hackcmd break", 1);
		return true;
	}
	m_bF0c = false;

	if (m_nF10 & 4)
	{
		if (key == 0x1b)
		{
			engine->vfunc27("hackcmd quit", 1);
			return true;
		}
		engine->vfunc27(sub_1004ba40("hackcmd %c", key), 1);
		return true;
	}

	if (m_nF10 & 1)
	{
		if (key == 0xd || key == 0xa9 || key == 0x1b)
		{
			engine->vfunc27("hackcmd ", 1);
			return true;
		}
		return true;
	}

	if (key == 0x85)
	{
		m_bF0c = true;
	}
	else if (key == 0xd || key == 0xa9)
	{
		char cmd[76];
		strcpy(cmd, "hackcmd ");
		strcat(cmd, text);
		engine->vfunc27(cmd, 1);
	}
	else if (key == 0x1b)
	{
		engine->vfunc27("hackcmd quit", 1);
	}
	else if (key == 0x7f && cursor > 0)
	{
		memmove(&text[cursor - 1], &text[cursor], strlen(&text[cursor]) + 1);
		cursor--;
	}
	else
	{
		if (m_nF14 && strlen(m_szText) >= (unsigned int)m_nF14)
			return true;

		if (key == 0x82 || key == 0xa3)
		{
			if (m_bF0d)
				cursor--;
		}
		else if (key == 0x83 || key == 0xa5)
		{
			if (m_bF0d)
				cursor++;
		}
		else if (key == 0x80 || key == 0xa1 || key == 0x97)
		{
			if (m_bF0d)
				cursor = 0;
		}
		else if (key == 0x81 || key == 0xa7 || key == 0x98)
		{
			if (m_bF0d)
				cursor = strlen(text);
		}
		else if (key >= 0x20 && key < 0x7f)
		{
			return true;
		}
	}

	if ((int)strlen(text) + m_nE8c < m_nStride - m_nE84)
	{
		if (m_nE7c >= 0 && m_nE7c < m_nMax)
			((TermRecord_100c7090 *)m_rgData)[m_nE7c] = *(TermRecord_100c7090 *)m_aE90;

		m_nE78 = m_nE8c;
		for (char *p = text; *p; p++)
			sub_100c8060(*p);

		m_nE78 = m_nE8c + clamp_100c7090(cursor, 0, (int)strlen(text));
		strcpy(m_szText, text);
		m_b7a8 = true;

		if (m_nF10 & 8)
		{
			const char *pszSound = engine->vfunc8(m_nF18);
			if (pszSound && *pszSound)
			{
				float vol = RandomFloat(0.85f, 1.0f);
				int pitch = RandomInt(95, 105);
				CLocalPlayerFilter filter;
				enginesound->vfunc2(filter, entindex(), 3, pszSound, vol, 75, 0, pitch, 0, 0, 1, 0);
			}
		}
	}

	return true;
}
// END FUNCTION

// FUNCTION: 0x100c7620 size=0x5e
#include "engineclient.h"
#include "C_BaseTerminal.h"
#include "C_BaseEntity.h"
#include "IClientNetworkable.h"



void C_BaseTerminal::vfunc29(char b)
{
	C_BaseEntity::vfunc29(b);

	if (IsDormant())
	{
		sub_100c7550();
		vfunc83(-1.0f);
	}
	else
	{
		vfunc83(engine->Time(0) + 0.25);
	}
}
// END FUNCTION
