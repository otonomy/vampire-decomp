// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100c8e10 size=0x6
#include "C_VGuiScreen.h"

// TARGET: C_VGuiScreen::vfunc16
int C_VGuiScreen::vfunc16()
{
	return (int)"C_VGuiScreen";
}
// END FUNCTION

// FUNCTION: 0x100c9110 size=0x41
#include "C_VGuiScreen.h"
C_VGuiScreen *pcd_emit_100c9110() { return new C_VGuiScreen; }
// TARGET: ??_GC_VGuiScreen@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100c9220 size=0x4e
#include "C_VGuiScreen.h"

struct ResV57
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void v9();
	virtual void v10();
	virtual void v11();
	virtual void v12();
	virtual void v13();
	virtual void v14();
	virtual void v15();
	virtual void v16();
	virtual void v17();
	virtual void v18();
	virtual void v19();
	virtual void v20();
	virtual void v21();
	virtual void v22();
	virtual void v23();
	virtual void v24();
	virtual void v25();
	virtual void v26();
	virtual void v27();
	virtual void v28();
	virtual void v29();
	virtual void v30();
	virtual void v31();
	virtual void v32();
	virtual void v33();
	virtual void v34();
	virtual void v35();
	virtual void v36();
	virtual void v37();
	virtual void v38();
	virtual void v39();
	virtual void v40();
	virtual void v41();
	virtual void v42();
	virtual void v43();
	virtual void v44();
	virtual void v45();
	virtual void v46();
	virtual void v47();
	virtual void v48();
	virtual void v49();
	virtual void v50();
	virtual void v51();
	virtual void v52();
	virtual void v53();
	virtual void v54();
	virtual void v55();
	virtual void v56();
	virtual int vfunc57(int, int, int);
};

int C_VGuiScreen::vfunc64(int a1, int a2, int a3)
{
	C_BaseEntity *pEntity = (C_BaseEntity *)a1;
	C_BaseEntity *pRenderable = pEntity->GetBaseEntity();
	if (pRenderable && this->m_n43c > 0)
		return ((ResV57 *)pRenderable)->vfunc57(this->m_n43c, a2, a3);
	return C_BaseEntity::vfunc64(a1, a2, a3);
}
// END FUNCTION

// FUNCTION: 0x100c93c0 size=0x2bb
#include "C_VGuiScreen.h"
#include "C_BasePlayer.h"
#include "Ray_t.h"
#include "engineclient.h"

struct IClientMode_105f99d8
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
	virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32();
	virtual void ActivateInGameVGuiContext(void *pPanel);
	virtual void DeactivateInGameVGuiContext();
};
extern IClientMode_105f99d8 *g_105f99d8;

struct IInputInternal_101ac8b0
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14();
	virtual void InternalCursorMoved(int x, int y);
	virtual void InternalMousePressed(int code);
	virtual void v17();
	virtual void InternalMouseReleased(int code);
};
IInputInternal_101ac8b0 *sub_101ac8b0();

void sub_101090a0(const QAngle &angles, Vector *forward, Vector *right, Vector *up);
void sub_10108fd0(const Vector &start, float scale, const Vector &direction, Vector &dest);

void C_VGuiScreen::ClientThink()
{
	C_BaseEntity::ClientThink();

	void *pPanel = m_c.sub_101104a0();
	if (!pPanel)
		return;

	C_BasePlayer *pLocalPlayer = C_BasePlayer::GetLocalPlayer();
	if (!pLocalPlayer)
		return;

	Vector vecEyePosition;
	VectorAdd(pLocalPlayer->GetAbsOrigin(), *(Vector *)((char *)pLocalPlayer + 0x148), vecEyePosition);

	QAngle viewAngles;
	engine->GetViewAngles(viewAngles);

	Vector viewDir, endPos;
	sub_101090a0(viewAngles, &viewDir, 0, 0);
	sub_10108fd0(vecEyePosition, 1000.0f, viewDir, endPos);

	Ray_t lookDir;
	lookDir.Init(vecEyePosition, endPos);

	float u, v;
	if (!sub_100c9740(lookDir, &u, &v, 0))
		return;

	if ((u < 0) || (v < 0) || (u > 1) || (v > 1))
		return;

	g_105f99d8->ActivateInGameVGuiContext(pPanel);

	int px = (int)(u * m_nPixelWidth + 0.5f);
	int py = (int)(v * m_nPixelHeight + 0.5f);

	if ((px != m_nOldPx) || (py != m_nOldPy))
	{
		sub_101ac8b0()->InternalCursorMoved(px, py);
		m_nOldPx = px;
		m_nOldPy = py;
	}

	if (m_nButtonPressed & 1)
		sub_101ac8b0()->InternalMousePressed(0);
	if (m_nButtonPressed & 0x800)
		sub_101ac8b0()->InternalMousePressed(1);
	if (m_nButtonReleased & 1)
		sub_101ac8b0()->InternalMouseReleased(0);
	if (m_nButtonReleased & 0x800)
		sub_101ac8b0()->InternalMouseReleased(1);

	g_105f99d8->DeactivateInGameVGuiContext();
}
// END FUNCTION
