// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10036cf0 size=0x1e
#include "CExplosionOverlay.h"

// VC6 writes CExplosionOverlay's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CExplosionOverlay *pcd_emit_10036cf0() { return new CExplosionOverlay; }

// TARGET: ??_GCExplosionOverlay@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101a3250 size=0x6a1
#include "CExplosionOverlay.h"
#include "engineclient.h"

extern float g_104cfddc;
const Vector &sub_10198d30();
const Vector &sub_10198d50();

struct MeshDesc_101a3250
{
	int m_VertexSize_Position;
	int m_VertexSize_BoneWeight;
	int m_VertexSize_BoneMatrixIndex;
	int m_VertexSize_Normal;
	int m_VertexSize_Color;
	int m_VertexSize_Specular;
	int m_VertexSize_TexCoord[4];
	int m_VertexSize_TangentS;
	int m_VertexSize_TangentT;
	int m_VertexSize_TangentSxT;
	int m_VertexSize_UserData;
	int m_ActualVertexSize;
	int m_FirstVertex;
	int m_NumBoneWeights;
	float *m_pPosition;
	float *m_pBoneWeight;
	unsigned char *m_pBoneMatrixIndex;
	float *m_pNormal;
	unsigned char *m_pColor;
	unsigned char *m_pSpecular;
	float *m_pTexCoord[4];
	float *m_pTangentS;
	float *m_pTangentT;
	float *m_pTangentSxT;
	float *m_pUserData;
	unsigned short *m_pIndices;
};

struct IMesh_101a3250
{
	virtual void LockMesh(int numVerts, int numIndices, MeshDesc_101a3250 &desc) = 0;
	virtual void v1() = 0;
	virtual void v2() = 0;
	virtual void v3() = 0;
	virtual void v4() = 0;
	virtual void v5() = 0;
	virtual void v6() = 0;
	virtual void v7() = 0;
	virtual void v8() = 0;
	virtual void v9() = 0;
	virtual void SetPrimitiveType(int type) = 0;
	virtual void v11() = 0;
	virtual void Draw(int firstIndex = -1, int numIndices = 0) = 0;
};

__forceinline void IncrementFloatPointer_101a3250(float *&p, int vertexSize)
{
	p = (float *)((unsigned char *)p + vertexSize);
}

__forceinline unsigned char FastFToC_101a3250(float c)
{
	volatile float dc;
	dc = c * 255.0f + (float)(1 << 23);
	return *(unsigned char *)&dc;
}

__forceinline Vector Subtract_101a3250(const Vector &a, const Vector &b)
{
	Vector res;
	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return res;
}

struct MeshBuilder_101a3250 : public MeshDesc_101a3250
{
	IMesh_101a3250 *m_pMesh;
	bool m_bModify;
	int m_NumVertices;
	int m_NumIndices;
	int m_MaxVertex;
	int m_MaxIndex;
	int m_CurrentVertex;
	int m_CurrentIndex;
	int m_Type;
	bool m_GenerateIndices;
	float *m_pCurrPosition;
	float *m_pCurrNormal;
	float *m_pCurrTexCoord[4];
	unsigned char *m_pCurrColor;

	__forceinline MeshBuilder_101a3250()
		: m_pMesh(0), m_NumVertices(0), m_NumIndices(0), m_MaxVertex(0), m_MaxIndex(0),
		  m_CurrentVertex(0), m_CurrentIndex(0), m_GenerateIndices(false)
	{
	}

	void sub_100421f0(int type, int numPrimitives);
	void sub_100422e0();
	void sub_10041e00(const float *v);	// Position3fv
	void sub_1004afc0(float r, float g, float b, float a);	// Color4f
	void sub_10031a20(int stage, float s, float t);	// TexCoord2f
	void sub_10005230();	// AdvanceVertex
	void sub_10041c90(bool bSpewData, bool bDraw);	// End

	__forceinline void Begin(IMesh_101a3250 *pMesh, int type, int numPrimitives)
	{
		m_pMesh = pMesh;
		m_bModify = false;
		sub_100421f0(type, numPrimitives);
		m_MaxIndex = 0;
		m_MaxVertex = 0;
		m_GenerateIndices = true;
		m_Type = type;
		m_pMesh->SetPrimitiveType(2);
		m_pMesh->LockMesh(m_NumVertices, m_NumIndices, *this);
		sub_100422e0();
	}

	__forceinline void Position3fv(const float *v)
	{
		float *pDst = m_pCurrPosition;
		*pDst++ = *v++;
		*pDst++ = *v++;
		*pDst = *v;
	}
	__forceinline void Color4f(float r, float g, float b, float a)
	{
		int col = (FastFToC_101a3250(b)) | (FastFToC_101a3250(g) << 8) | (FastFToC_101a3250(r) << 16) | (FastFToC_101a3250(a) << 24);
		*(int *)m_pCurrColor = col;
	}
	__forceinline void TexCoord2f(int stage, float s, float t)
	{
		float *pDst = m_pCurrTexCoord[stage];
		*pDst++ = s;
		*pDst = t;
	}
	__forceinline void AdvanceVertex()
	{
		if (++m_CurrentVertex > m_MaxVertex)
			m_MaxVertex = m_CurrentVertex;
		IncrementFloatPointer_101a3250(m_pCurrPosition, m_VertexSize_Position);
		IncrementFloatPointer_101a3250(m_pCurrNormal, m_VertexSize_Normal);
		IncrementFloatPointer_101a3250(m_pCurrTexCoord[0], m_VertexSize_TexCoord[0]);
		IncrementFloatPointer_101a3250(m_pCurrTexCoord[1], m_VertexSize_TexCoord[1]);
		IncrementFloatPointer_101a3250(m_pCurrTexCoord[2], m_VertexSize_TexCoord[2]);
		IncrementFloatPointer_101a3250(m_pCurrTexCoord[3], m_VertexSize_TexCoord[3]);
		m_pCurrColor += m_VertexSize_Color;
	}
};

void CExplosionOverlay::vfunc4()
{
	Vector vToGlow;
	if (m_bDirectional)
		vToGlow = m_vDirection;
	else
		vToGlow = Subtract_101a3250(m_vPos, sub_10198d30());

	VectorNormalize(vToGlow);

	float flDot = vToGlow.Dot(sub_10198d50());
	if (flDot <= g_104cfddc)
		return;

	sub_100eee60(vToGlow);
	if (m_flProxyRadius == 0)
		return;

	for (int iSprite = 0; iSprite < m_nSprites; iSprite++)
	{
		CGlowSprite *pSprite = &m_Sprites[iSprite];

		float flHorzSize, flVertSize;
		Vector vColor;
		vfunc2(flDot, pSprite, &flHorzSize, &flVertSize, &vColor);

		Vector vBasePt, vUp, vRight;
		vfunc3(vToGlow, flHorzSize, flVertSize, vBasePt, vUp, vRight);

		void *pMaterial = materials->FindMaterial("sun\\overlay", 0, true);
		IMesh_101a3250 *pMesh = (IMesh_101a3250 *)materials->GetDynamicMesh(false, 0, 0, pMaterial);

		MeshBuilder_101a3250 builder;
		builder.Begin(pMesh, 7, 1);

		Vector vPt;

		vPt = vBasePt - vRight + vUp;
		builder.Position3fv(vPt.Base());
		builder.Color4f(vColor.x, vColor.y, vColor.z, 1);
		builder.TexCoord2f(0, 0, 1);
		builder.AdvanceVertex();

		vPt = vBasePt + vRight + vUp;
		builder.Position3fv(vPt.Base());
		builder.Color4f(vColor.x, vColor.y, vColor.z, 1);
		builder.TexCoord2f(0, 1, 1);
		builder.AdvanceVertex();

		vPt.sub_10039080((vBasePt + vRight).sub_100b9b80(vUp));
		builder.sub_10041e00(vPt.Base());
		builder.sub_1004afc0(vColor.x, vColor.y, vColor.z, 1);
		builder.sub_10031a20(0, 1, 0);
		builder.sub_10005230();

		vPt.sub_10039080(vBasePt.sub_100b9b80(vRight).sub_100b9b80(vUp));
		builder.sub_10041e00(vPt.Base());
		builder.sub_1004afc0(vColor.x, vColor.y, vColor.z, 1);
		builder.sub_10031a20(0, 0, 0);
		builder.sub_10005230();

		builder.sub_10041c90(false, true);
	}
}
// END FUNCTION
