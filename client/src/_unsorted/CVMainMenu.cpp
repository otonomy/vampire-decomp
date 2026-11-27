// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10065840 size=0x1e
#include "CVMainMenu.h"

// VC6 writes CVMainMenu's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CVMainMenu *pcd_emit_10065840(const CVMainMenu &other) { return new CVMainMenu(other); }

// TARGET: ??_GCVMainMenu@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10065860 size=0xe7
#include "CVMainMenu.h"

struct V665d0 { void sub_100665d0(int); };
struct V67520 { void sub_10067520(); };

CVMainMenu::~CVMainMenu()
{
	sub_10066250();
	((V665d0 *)this)->sub_100665d0(1);
	((V67520 *)this)->sub_10067520();
}
// END FUNCTION

// FUNCTION: 0x10065af0 size=0x147
#include "CVMainMenu.h"
#include "engineclient.h"
struct CVMenuSub { void sub_10059b70(int, int, int, int, int); };
float sub_100cd9e0(float, float, float, float);
void sub_1002bc10();
// TARGET: CVMainMenu::vfunc98
void CVMainMenu::vfunc98()
{
	if (!(char)vfunc22())
		return;
	sub_10065950();
	sub_10065a00();
	if (m_n314 != engine->vfunc44()) {
		m_f2d8 = sub_100cd9e0(m_f2d8, m_f2dc, engine->vfunc41(1), 127.5f);
		if (sub_10065c90())
			m_f2e0 = sub_100cd9e0(m_f2e0, 0.0f, engine->vfunc41(1), 127.5f);
		else
			m_f2e0 = sub_100cd9e0(m_f2e0, m_f2dc, engine->vfunc41(1), 127.5f);
		if (m_f2d8 == 0.0f) {
			if (sub_10067750(m_unk2e8))
				sub_10066440();
		} else {
			sub_10066af0();
			if (m_p300)
				m_p300->sub_10059b70(m_n30c, m_n310, m_n304, m_n308, (int)m_f2d8);
		}
		m_n314 = engine->vfunc44();
	}
	sub_1002bc10();
}
// END FUNCTION

// FUNCTION: 0x10065c40 size=0x4f
#include "CVMainMenu.h"

struct VSurface {
	virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
	virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
	virtual void d8(); virtual void d9(); virtual void d10();
	virtual void v11(int, int, int, int);
	virtual void v12(int, int, int, int);
};
struct VPanel_101a98f0 {
	void sub_101a98f0(int, int);
};
int sub_101ac8d0();

void CVMainMenu::vfunc97()
{
	((VSurface *)sub_101ac8d0())->v11(0, 0, 0, 0xff);
	((VPanel_101a98f0 *)this)->sub_101a98f0(*(int *)((char *)this + 0x184), *(int *)((char *)this + 0x188));
	((VSurface *)sub_101ac8d0())->v12(0, 0, *(int *)((char *)this + 0x184), *(int *)((char *)this + 0x188));
}
// END FUNCTION
