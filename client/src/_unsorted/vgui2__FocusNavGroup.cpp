// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101c2df0 size=0x31
#include "vgui2__FocusNavGroup.h"
// TARGET: vgui2::FocusNavGroup::FocusNavGroup
vgui2::FocusNavGroup::FocusNavGroup(vgui2::Panel *panel) : m_unk4(-1), m_pPanel(panel)
{
	m_hCurrent.sub_101ac6b0(0);
	m_bFlag = false;
}
// END FUNCTION

// FUNCTION: 0x101c2e40 size=0x14e
template <class T> __forceinline T pcd_stage(T x) { return x; }
#include "vgui2__FocusNavGroup.h"
#include "vgui2__Panel.h"

struct SurfaceView { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); };
SurfaceView *sub_101ac8d0();
struct PanelB
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual bool v22();
};

// TARGET: vgui2::FocusNavGroup::vfunc4
void vgui2::FocusNavGroup::vfunc4(vgui2::Panel *panel)
{
	m_hCurrent.sub_101ac6b0((PanelX *)0);
	int position = 9999999;
	if (panel)
		position = panel->vfunc30();
	Panel *best = 0;
	bool first; first = true;
	int bestPos;
	for (;;)
	{
		int target = position - 1;
		int i = 0;
		if (0 < target)
		{
			bestPos = i;
			while (i < m_pPanel->vfunc36()) { Panel *child = m_pPanel->vfunc37(i);
				if (((PanelB *)child)->v22() && child->vfunc47() && pcd_stage(child->vfunc30()))
				{
					int pos = child->vfunc30();
					if (pos == target)
					{
						best = child;
						break;
					}
					if (pos < target && pos > bestPos)
					{
						best = child;
						bestPos = pos;
					}
				} i++; }
			if (!first || (int)best)
				break;
		}
		if (!m_bFlag && m_pPanel->vfunc31())
		{
			Panel *parent = (Panel *)m_pPanel->vfunc31();
			if (parent->vfunc0() != sub_101ac8d0()->v6())
			{
				((Panel *)m_pPanel->vfunc31())->vfunc58((int)m_pPanel);
				break;
			}
		}
		position = 9999999;
		first = false;
	}
	if (!(best)) return; m_hCurrent.sub_101ac6b0((PanelX *)best);
		best->vfunc15(-1);
}
// END FUNCTION

// FUNCTION: 0x101c2f90 size=0x162
#include "vgui2__FocusNavGroup.h"
#include "vgui2__Panel.h"

extern int g_1067b418;

struct RootView_101c2f90 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); };
RootView_101c2f90 *sub_101ac8d0();

void vgui2::FocusNavGroup::vfunc5(vgui2::Panel *panel)
{
	g_1067b418++;
	m_hCurrent.sub_101ac6b0(0);
	int curTab = 0;
	if (panel)
		curTab = panel->vfunc30();
	bool bFirst = true;
	vgui2::Panel *child = 0;
	vgui2::Panel *best = 0;
	for (;;)
	{
		int want = curTab + 1;
		int nextTab; nextTab = 999999;
		for (int i = 0; i < m_pPanel->vfunc36(); i++)
		{
			child = m_pPanel->vfunc37(i);
			if ((char)child->vfunc22() && child->vfunc47() && child->vfunc30())
			{
				int tab = child->vfunc30();
				if (tab == want)
				{
					best = child;
					break;
				}
				if (tab > want && tab < nextTab)
				{
					nextTab = tab;
					best = child;
					continue;
				}
			}
			child = best;
		}
		if (bFirst)
		{
			if (child == 0)
			{
				if (!m_bFlag && m_pPanel->vfunc31())
				{
					vgui2::Panel *parent = (vgui2::Panel *)m_pPanel->vfunc31();
					if (parent->vfunc0() != sub_101ac8d0()->v6() && g_1067b418 < 15)
					{
						((vgui2::Panel *)m_pPanel->vfunc31())->vfunc59((int)m_pPanel);
						goto done;
					}
				}
				curTab = 0;
				bFirst = false;
				continue;
			}
		}
		else if (child == 0)
			break;
		m_hCurrent.sub_101ac6b0((PanelX *)child);
		child->vfunc15(1);
		break;
	}
done:
	g_1067b418--;
}
// END FUNCTION

// FUNCTION: 0x101c3100 size=0xa
#include "vgui2__FocusNavGroup.h"
bool vgui2::FocusNavGroup::vfunc8(char a0)
{
    *(char *)((char *)this + 0x10) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101c3110 size=0xdf
#include "vgui2__FocusNavGroup.h"
#include "vgui2__Panel.h"

extern void *sub_101b6840(int);
extern void *sub_101ac8f0();

struct NavHandle
{
	vgui2::Panel *sub_101ac670();
	void sub_101ac6b0(vgui2::Panel *p);
};

struct KVBuild
{
	void *sub_101b56c0(const char *, const char *, int);
};

struct IVGuiView
{
	virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3();
	virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7();
	virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11();
	virtual void g12(); virtual void g13(); virtual void g14(); virtual void g15();
	virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19();
	virtual void g20(int, void *, int, int);
};

void vgui2::FocusNavGroup::vfunc1(vgui2::Panel *newFocus)
{
	NavHandle *h = (NavHandle *)((char *)this + 4);
	if ( newFocus == h->sub_101ac670() )
		return;

	if ( h->sub_101ac670() )
	{
		void *kv = sub_101b6840(0x1c);
		if ( kv )
			kv = ((KVBuild *)kv)->sub_101b56c0("SetAsDefaultButton", "state", 0);
		else
			kv = 0;
		((IVGuiView *)(void *)sub_101ac8f0())->g20(h->sub_101ac670()->vfunc0(), kv, 0, 0);
	}

	h->sub_101ac6b0(newFocus);

	if ( h->sub_101ac670() )
	{
		void *kv = sub_101b6840(0x1c);
		if ( kv )
			kv = ((KVBuild *)kv)->sub_101b56c0("SetAsDefaultButton", "state", 1);
		else
			kv = 0;
		((IVGuiView *)(void *)sub_101ac8f0())->g20(h->sub_101ac670()->vfunc0(), kv, 0, 0);
	}
}
// END FUNCTION

// FUNCTION: 0x101c31f0 size=0x8
#include "vgui2__FocusNavGroup.h"
namespace lifted {
struct C101ac670 { int sub_101ac670(); };
}
int vgui2::FocusNavGroup::vfunc2()
{
    return ((lifted::C101ac670 *)((int)this + 4))->sub_101ac670();
}
// END FUNCTION

// FUNCTION: 0x101c3200 size=0x4d
#include "vgui2__Panel.h"
#include "vgui2__FocusNavGroup.h"

int vgui2::FocusNavGroup::vfunc3(int arg)
{
	for (int i = 0; i < this->m_pPanel->vfunc36(); i++)
	{
		int r = this->m_pPanel->vfunc37(i)->vfunc72(arg);
		if (r)
			return r;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x101c3250 size=0x4e
#include "vgui2__FocusNavGroup.h"
#include "vgui2__Panel.h"

vgui2::Panel *vgui2::FocusNavGroup::vfunc0()
{
	for (int i = 0; i < m_pPanel->vfunc36(); i++)
	{
		if (m_pPanel->vfunc37(i)->vfunc30() == 1)
			return m_pPanel->vfunc37(i);
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x101c32a0 size=0x8
#include "vgui2__FocusNavGroup.h"
namespace lifted {
struct C101ac670 { int sub_101ac670(); };
}
int vgui2::FocusNavGroup::vfunc6()
{
    return ((lifted::C101ac670 *)((int)this + 0xc))->sub_101ac670();
}
// END FUNCTION

// FUNCTION: 0x101c32b0 size=0x8
#include "vgui2__FocusNavGroup.h"
namespace lifted {
struct C101ac6b0 { int sub_101ac6b0(); };
}
int vgui2::FocusNavGroup::vfunc7()
{
    return ((lifted::C101ac6b0 *)((int)this + 0xc))->sub_101ac6b0();
}
// END FUNCTION
