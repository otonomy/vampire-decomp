// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10055980 size=0x71
#include "CHudInfo.h"
extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
char *sub_1018c870(const char *);
// TARGET: ??0CHudInfo@@QAE@H@Z
CHudInfo::CHudInfo(int a)
    : CManagedHudElement(a, (int)"HudInfo")
{
    memset(m_arr198, 0, sizeof(m_arr198));
    vfunc63(0);
    m_n180 = 0;
    IFontLike *p = sub_101ac830();
    m_nFont = p->GetFont(sub_1018c870("Trebuchet"));
}
// END FUNCTION

// FUNCTION: 0x10055a00 size=0x1e
#include "CHudInfo.h"

// VC6 writes CHudInfo's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CHudInfo *pcd_emit_10055a00(const CHudInfo &other) { return new CHudInfo(other); }

// TARGET: ??_GCHudInfo@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10055a20 size=0x22
#include "CHudInfo.h"
CHudInfo::~CHudInfo()
{
	sub_101a9ff0(0);
}
// END FUNCTION

// FUNCTION: 0x10055a50 size=0x1b7
#include "CHudInfo.h"
#include "engineclient.h"

struct VSurf_10055a50
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10();
	virtual void vfunc11(int, int, int, int);
	virtual void vfunc12(int, int, int, int);
};
extern float sub_100cd9e0(float cur, float target, float dt, float speed);
extern VSurf_10055a50 *sub_101ac8d0();

// TARGET: CHudInfo::vfunc98
void CHudInfo::vfunc98()
{
	if (!vfunc107())
		return;
	float flFrame = engine->vfunc41(1);
	if (m_unk31c == 1)
	{
		m_flPos = sub_100cd9e0(m_flPos, 210.0f, flFrame, 280.0f);
		if (m_flPos == 210.0f)
			m_unk31c = 0;
	}
	else if (m_unk31c == 2)
	{
		m_flPos = sub_100cd9e0(m_flPos, 0.0f, flFrame, 280.0f);
		if (m_flPos == 0.0f)
		{
			*(char *)m_arr198 = 0;
			m_unk31c = 0;
		}
	}
	if (m_unk178 == 0)
	{
		sub_101ac8d0()->vfunc11(0, 0, 0, (int)m_flPos);
		sub_101ac8d0()->vfunc12(0, 0, m_unk184, m_unk188);
	}
	const char *text = (const char *)m_arr198;
	int w = g_pMatSystemSurface->vfunc15(m_nFont, text);
	int x = (m_unk184 - w - 0x46) / 2;
	if (x < 0x23)
		x = 0x23;
	if (m_unk178 == 1)
		g_pMatSystemSurface->vfunc12(m_nFont, x + 2, 0x25, 0, 0, 0, (int)(m_flPos + 32.0f), text);
	g_pMatSystemSurface->vfunc12(m_nFont, x, 0x23, m_unk18c, m_unk194, m_unk190, (int)(m_flPos + 32.0f), text);
}
// END FUNCTION

// FUNCTION: 0x10055d20 size=0xe
struct V_10055d20 { int m_unk[0x198 / 4]; char m_b198; };
// TARGET: sub_10055d20
int __fastcall sub_10055d20(V_10055d20 *self)
{
	return self->m_b198 != 0;
}
// END FUNCTION
