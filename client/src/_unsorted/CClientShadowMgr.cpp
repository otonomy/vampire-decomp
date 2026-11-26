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
#include "engineclient.h"
#include "CClientShadowMgr.h"
#include "Vector.h"
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
	m_d8 = engine->vfunc96() >= 80;
	if (m_d8)
	{
		m_1c.sub_100cd1f0("engine/rendershadow");
		m_20.sub_100cd1f0("engine/rendershadow_soft");
		m_24.sub_100cd1f0("engine/rendermodelshadow");
		m_28.sub_100cd1f0("engine/shadowbuild");
		m_48.sub_100d4560();
	}
	m_d9 = false;
	materials->AddRestoreFunc((int)(sub_100d58f0));
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

// FUNCTION: 0x100d5d70 size=0x330
#include "engineclient.h"
#include "CClientShadowMgr.h"

struct MeshView_100d5d70
{
	virtual void LockMesh(int numVerts, int numIndices, void *desc);
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void SetPrimitiveType(int type);
	virtual void v11();
	virtual void Draw(int firstIndex, int numIndices);
};

struct MeshBuilder_100d5d70
{
	int m_VertexSize_Position;	// 0x00
	int m_VertexSize_BoneWeight;
	int m_VertexSize_BoneMatrixIndex;
	int m_VertexSize_Normal;	// 0x0c
	int m_VertexSize_Color;	// 0x10
	int m_VertexSize_Specular;
	int m_VertexSize_TexCoord[4];	// 0x18
	int m_unk28[(0x80 - 0x28) / 4];
	MeshView_100d5d70 *m_pMesh;	// 0x80
	bool m_b84;
	int m_NumVerts;	// 0x88
	int m_NumIndices;	// 0x8c
	int m_NumVertices;	// 0x90
	int m_n94;
	int m_CurrentVertex;	// 0x98
	int m_n9c;
	int m_Type;	// 0xa0
	bool m_GenerateIndices;	// 0xa4
	float *m_pCurrPosition;	// 0xa8
	float *m_pCurrNormal;	// 0xac
	float *m_pCurrTexCoord[4];	// 0xb0
	unsigned char *m_pCurrColor;	// 0xc0

	MeshBuilder_100d5d70()
	{
		m_pMesh = 0;
		m_NumVerts = 0; m_NumIndices = 0; m_NumVertices = 0; m_n94 = 0; m_CurrentVertex = 0; m_n9c = 0;
		m_GenerateIndices = false;
	}

	void sub_100421f0(int type, int numPrimitives);	// ComputeNumVertsAndIndices
	void sub_100422e0();
	void sub_100319d0(float x, float y, float z);
	void sub_10031a20(int stage, float s, float t);
	void sub_10042960(int r, int g, int b, int a);
	void sub_10005230();
	void sub_10041c90(int a, int b);

	void Begin(MeshView_100d5d70 *pMesh, int type, int numPrimitives)
	{
		m_pMesh = pMesh;
		m_b84 = false;
		sub_100421f0(type, numPrimitives);
		m_n94 = 0;
		m_NumVertices = 0;
		m_GenerateIndices = true;
		m_Type = type;
		m_pMesh->SetPrimitiveType(2);
		m_pMesh->LockMesh(m_NumVerts, m_NumIndices, this);
		sub_100422e0();
	}
	void Position3f(float x, float y, float z)
	{
		float *pDst = m_pCurrPosition;
		*pDst++ = x;
		*pDst++ = y;
		*pDst = z;
	}
	void TexCoord2f(int stage, float s, float t)
	{
		float *pDst = m_pCurrTexCoord[stage];
		*pDst++ = s;
		*pDst = t;
	}
	void Color4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		*(int *)m_pCurrColor = (a << 24) | (r << 16) | (g << 8) | b;
	}
	void AdvanceVertex()
	{
		if (++m_CurrentVertex > m_NumVertices)
			m_NumVertices = m_CurrentVertex;
		m_pCurrPosition = (float *)((char *)m_pCurrPosition + m_VertexSize_Position);
		m_pCurrNormal = (float *)((char *)m_pCurrNormal + m_VertexSize_Normal);
		m_pCurrTexCoord[0] = (float *)((char *)m_pCurrTexCoord[0] + m_VertexSize_TexCoord[0]);
		m_pCurrTexCoord[1] = (float *)((char *)m_pCurrTexCoord[1] + m_VertexSize_TexCoord[1]);
		m_pCurrTexCoord[2] = (float *)((char *)m_pCurrTexCoord[2] + m_VertexSize_TexCoord[2]);
		m_pCurrTexCoord[3] = (float *)((char *)m_pCurrTexCoord[3] + m_VertexSize_TexCoord[3]);
		m_pCurrColor += m_VertexSize_Color;
	}
};

void CClientShadowMgr::vfunc13(int w, int h)
{
	if (!*((bool *)this + 0xd8))
		return;

	materials->Bind((const void *)m_unk1c, 0);
	MeshView_100d5d70 *pMesh = (MeshView_100d5d70 *)materials->GetDynamicMesh(true, 0, 0, 0);

	MeshBuilder_100d5d70 meshBuilder;
	meshBuilder.Begin(pMesh, 7, 1);

	meshBuilder.Position3f(0.0f, 0.0f, 0.0f);
	meshBuilder.TexCoord2f(0, 0.0f, 0.0f);
	meshBuilder.Color4ub(0, 0, 0, 0);
	meshBuilder.AdvanceVertex();

	meshBuilder.Position3f(w, 0.0f, 0.0f);
	meshBuilder.TexCoord2f(0, 1.0f, 0.0f);
	meshBuilder.Color4ub(0, 0, 0, 0);
	meshBuilder.AdvanceVertex();

	meshBuilder.sub_100319d0(w, h, 0.0f);
	meshBuilder.sub_10031a20(0, 1.0f, 1.0f);
	meshBuilder.sub_10042960(0, 0, 0, 0);
	meshBuilder.sub_10005230();

	meshBuilder.sub_100319d0(0.0f, h, 0.0f);
	meshBuilder.sub_10031a20(0, 0.0f, 1.0f);
	meshBuilder.sub_10042960(0, 0, 0, 0);
	meshBuilder.sub_10005230();

	meshBuilder.sub_10041c90(0, 0);
	pMesh->Draw(-1, 0);
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
#include "CClientEntityList.h"
#include "ConVar.h"
#include "CClientEntityList.h"
#include "C_BaseEntity.h"
#include "CClientShadowMgr.h"

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

	int nHighest = cl_entitylist->vfunc6();
	for (int i = 0; i <= nHighest; i++)
	{
		C_BaseEntity *pEnt = cl_entitylist->sub_100d0cf0(i);
		if (pEnt)
			pEnt->sub_1009e2d0(1);
	}
}
// END FUNCTION
