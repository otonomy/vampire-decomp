// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100bb4d0 size=0x6
#include "C_Func_LOD.h"
namespace lifted {
extern char g_102b47b0;
}
int C_Func_LOD::vfunc16()
{
    return (int)&lifted::g_102b47b0;
}
// END FUNCTION

// FUNCTION: 0x100bb4e0 size=0x3
#include "C_Func_LOD.h"
int C_Func_LOD::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100bb6f0 size=0x1e
#include "C_Func_LOD.h"

// VC6 writes C_Func_LOD's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_Func_LOD *pcd_emit_100bb6f0(const C_Func_LOD &other) { return new C_Func_LOD(other); }

// TARGET: ??_GC_Func_LOD@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100bb710 size=0x262
#include "C_BasePlayer.h"
#include "C_Func_LOD.h"
#include "ConVar.h"
#include "Vector.h"

extern ConVar *g_104a2b1c;	// lod_Enable (its parent)
extern ConVar *g_104a2a34;	// lod_TransitionDist
extern ConVar *g_106198ac;

struct LODPlayerView { float sub_100aa6d0(); };	// GetFOVDistanceAdjustFactor

struct LODEngineView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10();
	virtual void *vfunc11();
};
extern LODEngineView *g_102d43d8;

const Vector &sub_10198d30();	// CurrentViewOrigin
bool sub_1018f570(void *p, int n, const Vector *pCenter, float flRadius);

bool C_Func_LOD::LODTest()
{
	if (!(g_104a2b1c->vfunc1() ? 0 : g_104a2b1c->m_nValue))
		return true;

	float disappearDist = m_fDisappearDist;
	float transitionDist = m_fDisappearDist + (g_104a2a34->vfunc1() ? 0.0f : g_104a2a34->m_fValue);
	float dist = (sub_10198d30() - vfunc56()).Length();
	if (C_BasePlayer::GetLocalPlayer())
		dist *= ((LODPlayerView *)C_BasePlayer::GetLocalPlayer())->sub_100aa6d0();

	if (dist < disappearDist)
	{
		m_bLastDrawn = true;
		m_LastRenderState = 0;
		return m_bLastDrawn;
	}
	else if (dist < transitionDist)
	{
		if (!(g_106198ac->vfunc1() ? 0 : g_106198ac->m_nValue))
		{
			Vector mins, maxs;
			GetRenderBounds(mins, maxs);
			Vector vCenter = (mins + maxs) * 0.5f;
			float radius = (maxs - vCenter).Length();
			vCenter += GetRenderOrigin();
			if (!sub_1018f570(g_102d43d8->vfunc11(), 5, &vCenter, radius))
				return m_bLastDrawn;
		}

		if (m_LastRenderState == 0 && m_bLastDrawn)
		{
			m_bLastDrawn = false;
		}
		else if (m_LastRenderState == 1 && !m_bLastDrawn)
		{
			m_bLastDrawn = true;
			return m_bLastDrawn;
		}
	}
	else
	{
		m_LastRenderState = 1;
		m_bLastDrawn = false;
	}
	return m_bLastDrawn;
}
// END FUNCTION
