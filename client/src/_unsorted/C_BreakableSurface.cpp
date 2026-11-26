// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100b6e70 size=0x6
#include "C_BreakableSurface.h"
namespace lifted {
extern char g_102b41b4;
}
int C_BreakableSurface::vfunc16()
{
    return (int)&lifted::g_102b41b4;
}
// END FUNCTION

// FUNCTION: 0x100b6e80 size=0x3
#include "C_BreakableSurface.h"
int C_BreakableSurface::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100b7100 size=0x350
#include "C_BreakableSurface.h"

int sub_10114660(int, int);
int sub_10114690();

#define LEGAL(p, x, y) ((x) < (p)->m_nWidth && (y) < (p)->m_nHeight && (x) >= 0 && (y) >= 0)

inline void SetPanelSolid(C_BreakableSurface *p, int x, int y, bool b)
{
	if (LEGAL(p, x, y))
	{
		if (b)
			p->m_nPanelFlags[x * 16 + y] |= 1;
		else
			p->m_nPanelFlags[x * 16 + y] &= ~1;
	}
}

inline void SetPanelStale(C_BreakableSurface *p, int x, int y, bool b)
{
	if (LEGAL(p, x, y))
	{
		if (b)
			p->m_nPanelFlags[x * 16 + y] |= 2;
		else
			p->m_nPanelFlags[x * 16 + y] &= ~2;
	}
}

inline void SetPanelStale2(C_BreakableSurface *p, int x, int y, bool b)
{
	if (p->sub_100b7450(x, y))
	{
		if (b)
			p->m_nPanelFlags[x * 16 + y] |= 2;
		else
			p->m_nPanelFlags[x * 16 + y] &= ~2;
	}
}

inline bool IsPanelStale(C_BreakableSurface *p, int x, int y)
{
	return (((unsigned int)p->m_nPanelFlags[x * 16 + y] >> 1) & 1) != 0;
}

void C_BreakableSurface::ReceiveMessage(int classID, bf_read &msg)
{
	sub_10114660((int)&msg, classID);
	char nCommand = sub_10114690();
	if (nCommand == 2)
	{
		m_nWidth = sub_10114690();
		m_nHeight = sub_10114690();
	}
	else if (nCommand == 1)
	{
		int x, y;
		for (x = 0; x < m_nWidth; x++)
		{
			for (y = 0; y < m_nHeight; y++)
				SetPanelSolid(this, x, y, false);
		}
		for (x = 0; x < m_nWidth; x++)
		{
			for (y = 0; y < m_nHeight; y++)
				sub_100b8130(x, y);
		}
	}
	else if (nCommand == 0)
	{
		int x = sub_10114690();
		int y = sub_10114690();
		SetPanelSolid(this, x, y, false);
		SetPanelStale(this, x, y, true);
		SetPanelStale(this, x, y + 1, true);
		SetPanelStale(this, x, y - 1, true);
		SetPanelStale(this, x - 1, y, true);
		SetPanelStale(this, x + 1, y, true);
		SetPanelStale(this, x + 1, y + 1, true);
		SetPanelStale2(this, x - 1, y + 1, true);
		SetPanelStale2(this, x + 1, y - 1, true);
		sub_100b7490(x - 1, y - 1, true);
	}
	else if (nCommand == 3)
	{
		for (int x = 0; x < m_nWidth; x++)
		{
			for (int y = 0; y < m_nHeight; y++)
			{
				if (IsPanelStale(this, x, y))
					sub_100b8130(x, y);
			}
		}
	}
}
// END FUNCTION

// FUNCTION: 0x100b7760 size=0x1e
#include "C_BreakableSurface.h"

// VC6 writes C_BreakableSurface's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_BreakableSurface *pcd_emit_100b7760(const C_BreakableSurface &other) { return new C_BreakableSurface(other); }

// TARGET: ??_GC_BreakableSurface@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100b7b00 size=0x12
#include "C_BreakableSurface.h"
namespace lifted {
bool sub_1009fd30();
}
bool C_BreakableSurface::vfunc79()
{
    if ((*(char *)((char *)this + 0x43c)) != 0) {
        return 0;
    }
    return lifted::sub_1009fd30();
}
// END FUNCTION

// FUNCTION: 0x100b7b20 size=0x12
#include "C_BreakableSurface.h"
bool C_BreakableSurface::IsTransparent()
{
	if (m_bUnk438)
		return true;
	return C_BaseEntity::IsTransparent();
}
// END FUNCTION
