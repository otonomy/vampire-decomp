// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100d5390 size=0x1
#include "CClientShadowMgr.h"
void CClientShadowMgr::vfunc3()
{
}
// END FUNCTION

// FUNCTION: 0x100d53a0 size=0x1
#include "CClientShadowMgr.h"
void CClientShadowMgr::vfunc4()
{
}
// END FUNCTION

// FUNCTION: 0x100d53b0 size=0x3
#include "CClientShadowMgr.h"
void CClientShadowMgr::vfunc7(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x100d5830 size=0xb2
#include "CClientShadowMgr.h"
#include "Vector.h"
struct IEng_100d5830 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
	virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
	virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
	virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
	virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
	virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
	virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
	virtual void v95();
	virtual int GetDXSupportLevel();
};
struct IMatSys_100d5830 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
	virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
	virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
	virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
	virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
	virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
	virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
	virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
	virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104();
	virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
	virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114();
	virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
	virtual void AddRestoreCallback(void (*fn)());
};
extern IEng_100d5830 *g_104a57d4;
extern IMatSys_100d5830 *g_104a57ec;
extern void sub_100d58f0();
struct MH_100d5830 {
	int m_h;
	void sub_100cd1f0(const char *name);
};
struct Sub_100d5830 {
	char m_data[0x90];
	void sub_100d4560();
};
struct SM_100d5830 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
	virtual void SetShadowDir(const Vector &dir);
	char pad[0x14];
	MH_100d5830 m_18, m_1c, m_20, m_24, m_28;
	char pad2[0x1c];
	Sub_100d5830 m_48;
	bool m_d8;
	bool m_d9;
	bool sub_100d5830();
};
// TARGET: SM_100d5830::sub_100d5830
bool SM_100d5830::sub_100d5830()
{
	m_18.sub_100cd1f0("engine/simpleshadow");
	Vector dir(1.0f, 1.0f, -3.0f);
	SetShadowDir(dir);
	m_d8 = g_104a57d4->GetDXSupportLevel() >= 80;
	if (m_d8)
	{
		m_1c.sub_100cd1f0("engine/rendershadow");
		m_20.sub_100cd1f0("engine/rendershadow_soft");
		m_24.sub_100cd1f0("engine/rendermodelshadow");
		m_28.sub_100cd1f0("engine/shadowbuild");
		m_48.sub_100d4560();
	}
	m_d9 = false;
	g_104a57ec->AddRestoreCallback(sub_100d58f0);
	return true;
}
// END FUNCTION

// FUNCTION: 0x100d59b0 size=0x7a
#include "CClientShadowMgr.h"

struct ColorView
{
	virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3();
	virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7();
	virtual void c8(); virtual void c9(); virtual void c10(); virtual void c11();
	virtual void c12(); virtual void c13(); virtual void c14(); virtual void c15();
	virtual void c16(); virtual void c17(); virtual void c18(); virtual void c19();
	virtual void c20(); virtual void c21(); virtual void c22(); virtual void c23();
	virtual void c24(); virtual void c25(); virtual void c26(); virtual void c27();
	virtual void c28(); virtual void c29();
	virtual void c30(float, float, float);
};

void CClientShadowMgr::vfunc15(int r, int g, int b)
{
	ColorView *p = *(ColorView **)((char *)this + 0x18);
	float fb = (float)(b & 0xff) * 0.003921569f;
	float fg = (float)(g & 0xff) * 0.003921569f;
	float fr = (float)(r & 0xff) * 0.003921569f;
	p->c30(fr, fg, fb);

	((unsigned char *)this)[0x14] = (unsigned char)r;
	((unsigned char *)this)[0x15] = (unsigned char)g;
	((unsigned char *)this)[0x16] = (unsigned char)b;
}
// END FUNCTION

// FUNCTION: 0x100d5ce0 size=0x4f
#include "CClientShadowMgr.h"
#include "Vector.h"

void CClientShadowMgr::vfunc14(const void *pDirection)
{
	const Vector *pDir = (const Vector *)pDirection;
	Vector &vec = *(Vector *)&m_unk08;
	vec = *pDir;
	(*g_102be4e8)(vec);
	unsigned short h = m_Shadows.m_Head;
	while ( h != CUtlLinkedList240::InvalidIndex() )
		h = m_Shadows.m_pMemory[h].m_Next;
}
// END FUNCTION

// FUNCTION: 0x100d71d0 size=0x3c3
#include "engineclient.h"
#include "CClientShadowMgr.h"
#include "CBaseHandle.h"
#include "IClientEntity.h"
#include "IClientRenderable.h"
#include "Vector.h"
#include "QAngle.h"

struct Shadow240
{
	CBaseHandle m_Entity;          // 0x00
	unsigned short m_ShadowHandle; // 0x04
	unsigned short m_pad06;        // 0x06
	unsigned short m_Flags;        // 0x08
	char m_pad0a[0x4a];            // 0x0a
	Vector m_LightOrigin;          // 0x54
	Vector m_Dir;                  // 0x60
	Vector m_LastOrigin;           // 0x6c
	QAngle m_LastAngles;           // 0x78
	int m_unk84;                   // 0x84
	Vector m_Color;                // 0x88
	Vector m_Unk94;                // 0x94
	float m_CenterZ;               // 0xa0
	float m_HalfHeight;            // 0xa4
	char m_padA8[0x48];            // 0xa8 (total 0xf0 = 240)
};

struct ShadowArray_100d8620
{
	Shadow240 *m_pMemory;
	Shadow240 *sub_100d8620(unsigned int i);
};

extern int sub_1009e230();

struct IClientEntityList_100d71d0
{
	virtual void v0() = 0;
	virtual void v1() = 0;
	virtual void v2() = 0;
	virtual void v3() = 0;
	virtual IClientEntity *GetClientEntityFromHandle(CBaseHandle h) = 0; // slot 4 (+0x10)
};





struct Bounds_100d71d0
{
	Vector mins;
	Vector maxs;
};

struct IClientShadowMgr_100d71d0
{
	virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
	virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
	virtual void v8() = 0; virtual void v9() = 0;
	virtual void DestroyShadow(unsigned short handle) = 0; // slot 10 (+0x28)
};

struct CClientShadowMgr_100d71d0 : public CClientShadowMgr
{
	void sub_100d71d0(unsigned int handle, const Vector &lightOrigin, const Vector &color,
		const Vector &v3, const Bounds_100d71d0 *pBounds, bool bForce);
};

void CClientShadowMgr_100d71d0::sub_100d71d0(unsigned int handle, const Vector &lightOrigin,
	const Vector &color, const Vector &v3, const Bounds_100d71d0 *pBounds, bool bForce)
{
	if ((unsigned short)handle == 0xffff)
		return;

	CBaseHandle hEnt = ((ShadowArray_100d8620 *)&m_Shadows)->sub_100d8620(handle)->m_Entity;
	IClientEntity *pEnt = ((IClientEntityList_100d71d0 *)(sub_1009e230() + 0x1803c))->GetClientEntityFromHandle(hEnt);
	if (!pEnt)
	{
		((IClientShadowMgr_100d71d0 *)this)->DestroyShadow((unsigned short)handle);
		return;
	}

	IClientRenderable *pRenderable = pEnt;
	if (!pRenderable->GetModel())
		return;

	Shadow240 &shadow = *(Shadow240 *)&m_Shadows.InternalElement((unsigned short)handle);
	if (shadow.m_ShadowHandle == 0xffff)
		return;

	const Vector &origin = pRenderable->GetRenderOrigin();
	const QAngle &angles = pRenderable->GetRenderAngles();

	Vector center = origin;
	center.z += pBounds->mins.z;
	float halfHeight = (pBounds->maxs.z - pBounds->mins.z) * 0.5f;

	if (bForce ||
		origin != shadow.m_LastOrigin ||
		angles != shadow.m_LastAngles ||
		lightOrigin != shadow.m_LightOrigin ||
		color != shadow.m_Color ||
		v3 != shadow.m_Unk94 ||
		halfHeight != shadow.m_HalfHeight ||
		center.z != shadow.m_CenterZ)
	{
		shadow.m_LastOrigin = origin;
		shadow.m_LastAngles = angles;
		shadow.m_LightOrigin = lightOrigin;

		VectorSubtract(center, lightOrigin, shadow.m_Dir);
		VectorNormalize(shadow.m_Dir);
		shadow.m_Dir.z -= 0.33f;
		VectorNormalize(shadow.m_Dir);

		shadow.m_Color = color;
		shadow.m_Unk94 = v3;
		shadow.m_HalfHeight = halfHeight;
		shadow.m_CenterZ = center.z;

		Vector &defaultDir = *(Vector *)&m_unk08;
		Vector oldDir = defaultDir;
		defaultDir = shadow.m_Dir;

		shadow.m_Flags |= 4;

		const model_t *pModel = pRenderable->GetModel();
		int oldState = materials->vfunc98();
		materials->vfunc94(0);

		switch (modelinfo->GetModelType(pModel))
		{
		case 1:
			sub_100d7180((int)pEnt, handle, (int *)pBounds);
			break;
		case 3:
			sub_100d7130((int)pEnt, handle, (int *)pBounds);
			break;
		}

		materials->vfunc94(oldState);
		defaultDir = oldDir;
	}

	shadowmgr->vfunc11(shadow.m_ShadowHandle, color);
}

// TARGET: CClientShadowMgr_100d71d0::sub_100d71d0
// END FUNCTION

// FUNCTION: 0x100d7e50 size=0x1c
#include "CClientShadowMgr.h"
void *CClientShadowMgr::vfunc16(unsigned short h)
{
	return &m_Shadows.m_pMemory[h].m_Data[0x54];
}
// END FUNCTION

// FUNCTION: 0x100d7ec0 size=0xfb
#include "ConVar.h"
#include "CClientEntityList.h"
#include "C_BaseEntity.h"
#include "CClientShadowMgr.h"

extern CClientEntityList *g_102b8e9c;
extern ConVar g_104cf010;
extern ConVar g_1049dbd8;
extern ConVar g_105fb370;
extern ConVar g_104cefc0;
extern bool g_104cf1b8;
extern bool g_104cf008;
extern int g_104cf1b4;
extern int g_104cf004;
void sub_100d7fc0();

// TARGET: CClientShadowMgr::vfunc6
void CClientShadowMgr::vfunc6()
{
	sub_100d7fc0();

	bool bA = g_104cf010.GetInt() != 0;
	bool bB = g_1049dbd8.GetInt() != 0;
	int nC = g_105fb370.GetInt();
	int nD = g_104cefc0.GetInt();

	if (g_104cf1b8 == bA && g_104cf008 == bB && g_104cf1b4 == nC && g_104cf004 == nD)
		return;

	g_104cf1b8 = bA;
	g_104cf008 = bB;
	g_104cf1b4 = nC;
	g_104cf004 = nD;

	int nHighest = g_102b8e9c->vfunc6();
	for (int i = 0; i <= nHighest; i++)
	{
		C_BaseEntity *pEnt = g_102b8e9c->sub_100d0cf0(i);
		if (pEnt)
			pEnt->sub_1009e2d0(1);
	}
}
// END FUNCTION
