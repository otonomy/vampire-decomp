// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100be2b0 size=0x6
#include "C_RopeKeyframe.h"
namespace lifted {
extern char g_102b5c94;
}
int C_RopeKeyframe::vfunc16()
{
    return (int)&lifted::g_102b5c94;
}
// END FUNCTION

// FUNCTION: 0x100be2c0 size=0x3
#include "C_RopeKeyframe.h"
int C_RopeKeyframe::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100bf130 size=0x1e
#include "C_RopeKeyframe.h"

// VC6 writes C_RopeKeyframe's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_RopeKeyframe *pcd_emit_100bf130(const C_RopeKeyframe &other) { return new C_RopeKeyframe(other); }

// TARGET: ??_GC_RopeKeyframe@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100bf3f0 size=0x2b5
#include "C_RopeKeyframe.h"
#include "engineclient.h"
#include "ConVar.h"
#include <stdlib.h>

#pragma pack(push, 4)
struct CCycleCountL
{
	CCycleCountL() { m_Int64 = 0; }
	void Sample()
	{
		unsigned long *pSample = (unsigned long *)&m_Int64;
		__asm
		{
			mov ecx, pSample
			rdtsc
			mov [ecx], eax
			mov [ecx+4], edx
		}
	}
	CCycleCountL &operator+=(const CCycleCountL &o) { m_Int64 += o.m_Int64; return *this; }
	unsigned __int64 m_Int64;
};

struct CFastTimerL
{
	void Start() { m_Duration.Sample(); }
	void End()
	{
		CCycleCountL cnt;
		cnt.Sample();
		m_Duration.m_Int64 = cnt.m_Int64 - m_Duration.m_Int64;
	}
	CCycleCountL GetDuration() const { return m_Duration; }
	CCycleCountL m_Duration;
};

struct CTimeAdderL
{
	CTimeAdderL(CCycleCountL *pTotal) { m_pTotal = pTotal; m_Timer.Start(); }
	~CTimeAdderL() { End(); }
	void End()
	{
		if (m_pTotal)
		{
			m_Timer.End();
			*m_pTotal += m_Timer.GetDuration();
			m_pTotal = 0;
		}
	}
	CCycleCountL *m_pTotal;
	int m_unk4;
	CFastTimerL m_Timer;
};
#pragma pack(pop)

extern ConVar g_104a3ce0;
extern CCycleCountL g_104a3b38;
extern int g_104a3d54;
static float g_102b5c8c;

void C_RopeKeyframe::ClientThink()
{
	if (!g_104a3ce0.GetBool())
		return;
	if (!sub_100c04d0())
		return;

	if (engine->vfunc44() > m_nLastFrame + 1)
	{
		m_nLastFrame = engine->vfunc44();
		if (!sub_100bf790(m_bApplyWind))
		{
			CTimeAdderL adder(&g_104a3b38);
			sub_100bf360(engine->vfunc41(0));
			g_104a3d54 += *(int *)((char *)&m_RopePhysics + 0xc);
			m_b410 = 0;
			m_flCurWindTime += engine->vfunc41(0);
			m_flTimeToNextGust = (double)m_flTimeToNextGust - engine->vfunc41(0);
			if (m_flTimeToNextGust <= 0.0f)
			{
				Vector dir;
				dir.x = rand() * (2.0f / 32767.0f) - 1.0f;
				dir.y = rand() * (2.0f / 32767.0f) - 1.0f;
				dir.z = rand() * (2.0f / 32767.0f) - 1.0f;
				m_vWindDir = dir;
				VectorNormalize(m_vWindDir);
				m_vWindDir *= g_102b5c8c;
				m_vWindDir *= rand() * (2.0f / 32767.0f) - 1.0f;
				m_flCurWindTime = 0;
				m_flWindDuration = rand() * (1.0f / 32767.0f) + 2.0f;
				m_flTimeToNextGust = rand() * (2.0f / 32767.0f) + 2.0f;
			}
		}
		sub_100c03b0();
	}
	vfunc83(engine->Time(0) + 0.0666);
}
// END FUNCTION
