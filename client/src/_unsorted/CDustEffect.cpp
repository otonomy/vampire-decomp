// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100ba3f0 size=0x4f9
#include "CDustEffect.h"
#include "C_Func_Dust.h"
#include "VMatrix.h"
#include "Vector.h"
#include "engineclient.h"

extern "C" double sin(double);
#pragma intrinsic(sin)

#define M_PI 3.14159265358979323846
#define Assert(_exp) ((void)(_exp))

inline int RoundFloatToInt(float f)
{
	int nResult;
	__asm
	{
		fld f
		fistp nResult
	}
	return nResult;
}

class MeshBuilderLocal
{
public:
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
	void *m_pMesh;
	bool m_bModify;
	int m_MaxVertices;
	int m_MaxIndices;
	int m_NumVertices;
	int m_NumIndices;
	int m_CurrentVertex;
	int m_CurrentIndex;
	int m_Type;
	bool m_GenerateIndices;
	float *m_pCurrPosition;
	float *m_pCurrNormal;
	float *m_pCurrTexCoord[4];
	unsigned char *m_pCurrColor;

	inline void IncrementFloatPointer(float *&pBufferPointer, int vertexSize)
	{
		pBufferPointer = reinterpret_cast<float *>(reinterpret_cast<unsigned char *>(pBufferPointer) + vertexSize);
	}
	inline void sub_100319d0(float x, float y, float z)	// Position3f
	{
		float *pDst = m_pCurrPosition;
		*pDst++ = x;
		*pDst++ = y;
		*pDst = z;
	}
	inline void sub_10031a20(int stage, float s, float t)	// TexCoord2f
	{
		float *pDst = m_pCurrTexCoord[stage];
		*pDst++ = s;
		*pDst = t;
	}
	inline void sub_100052c0(const unsigned char *rgba)	// Color4ubv
	{
		Assert(rgba);
		Assert(m_pColor && m_pCurrColor);
		int col = rgba[2] | (rgba[1] << 8) | (rgba[0] << 16) | (rgba[3] << 24);
		*(int *)m_pCurrColor = col;
	}
	inline void sub_10005230()	// AdvanceVertex
	{
		if (++m_CurrentVertex > m_NumVertices)
			m_NumVertices = m_CurrentVertex;
		IncrementFloatPointer(m_pCurrPosition, m_VertexSize_Position);
		IncrementFloatPointer(m_pCurrNormal, m_VertexSize_Normal);
		IncrementFloatPointer(m_pCurrTexCoord[0], m_VertexSize_TexCoord[0]);
		IncrementFloatPointer(m_pCurrTexCoord[1], m_VertexSize_TexCoord[1]);
		IncrementFloatPointer(m_pCurrTexCoord[2], m_VertexSize_TexCoord[2]);
		IncrementFloatPointer(m_pCurrTexCoord[3], m_VertexSize_TexCoord[3]);
		m_pCurrColor += m_VertexSize_Color;
	}
};

struct ParticleDraw
{
	MeshBuilderLocal *m_pMeshBuilder;
	int m_unk04;
	float m_PartialFrameTime;
	MeshBuilderLocal *GetMeshBuilder() { return m_pMeshBuilder; }
	float GetTimeDelta() const { return m_PartialFrameTime; }
};

struct CFuncDustParticle
{
	int m_unk00;
	int m_unk04;
	int m_unk08;
	Vector m_Pos;
	Vector m_vVelocity;
	float m_Lifetime;
	float m_DieTime;
	float m_flSize;
};

extern VMatrix g_104e08d4;
void sub_100e2fc0(float flTime, Vector &vecVelocity);	// GetWindspeedAtTime

inline void TransformParticle_xzy(const VMatrix &vMat, const Vector &vIn, Vector &vOut)
{
	vOut.x = vMat.m[0][0] * vIn.x + vMat.m[0][1] * vIn.y + vMat.m[0][2] * vIn.z + vMat.m[0][3];
	vOut.y = vMat.m[1][0] * vIn.x + vMat.m[1][1] * vIn.y + vMat.m[1][2] * vIn.z + vMat.m[1][3];
	vOut.z = vMat.m[2][0] * vIn.x + vMat.m[2][1] * vIn.y + vMat.m[2][2] * vIn.z + vMat.m[2][3];
}

inline void RenderParticle_Color255Size(ParticleDraw *pDraw, const Vector &pos, const Vector &color, const float alpha, const float size)
{
	if (alpha < 0.5f)
		return;

	MeshBuilderLocal *pBuilder = pDraw->GetMeshBuilder();
	if (!pBuilder)
		return;

	unsigned char ubColor[4];
	ubColor[0] = (unsigned char)RoundFloatToInt(color.x);
	ubColor[1] = (unsigned char)RoundFloatToInt(color.y);
	ubColor[2] = (unsigned char)RoundFloatToInt(color.z);
	ubColor[3] = (unsigned char)RoundFloatToInt(alpha);

	pBuilder->sub_100319d0(pos.x - size, pos.y - size, pos.z);
	pBuilder->sub_100052c0(ubColor);
	pBuilder->sub_10031a20(0, 0, 1.0f);
	pBuilder->sub_10005230();

	pBuilder->sub_100319d0(pos.x - size, pos.y + size, pos.z);
	pBuilder->sub_100052c0(ubColor);
	pBuilder->sub_10031a20(0, 0, 0);
	pBuilder->sub_10005230();

	pBuilder->sub_100319d0(pos.x + size, pos.y + size, pos.z);
	pBuilder->sub_100052c0(ubColor);
	pBuilder->sub_10031a20(0, 1.0f, 0);
	pBuilder->sub_10005230();

	pBuilder->sub_100319d0(pos.x + size, pos.y - size, pos.z);
	pBuilder->sub_100052c0(ubColor);
	pBuilder->sub_10031a20(0, 1.0f, 1.0f);
	pBuilder->sub_10005230();
}

bool CDustEffect::vfunc3(CFuncDustParticle *pParticle, ParticleDraw *pDraw, float &sortKey)
{
	float alpha;

	if (m_pDust->m_DustFlags & 4)
	{
		alpha = 1.0f;
	}
	else
	{
		pParticle->m_Lifetime += pDraw->GetTimeDelta();
		if (pParticle->m_Lifetime >= pParticle->m_DieTime)
			return false;

		Vector vecWind;
		sub_100e2fc0(engine->Time(0), vecWind);

		for (int i = 0; i < 2; i++)
		{
			if (pParticle->m_vVelocity[i] < vecWind[i])
			{
				pParticle->m_vVelocity[i] += engine->vfunc41(0) * 50.0;
				if (pParticle->m_vVelocity[i] > vecWind[i])
					pParticle->m_vVelocity[i] = vecWind[i];
			}
			else if (pParticle->m_vVelocity[i] > vecWind[i])
			{
				pParticle->m_vVelocity[i] -= engine->vfunc41(0) * 50.0;
				if (pParticle->m_vVelocity[i] < vecWind[i])
					pParticle->m_vVelocity[i] = vecWind[i];
			}
		}

		VectorMA(pParticle->m_Pos, pDraw->GetTimeDelta(), pParticle->m_vVelocity, pParticle->m_Pos);

		float lifetimePercent = pParticle->m_Lifetime / pParticle->m_DieTime;
		alpha = (sin(lifetimePercent * (M_PI * 2) - M_PI * 0.5) + 1.0) * 0.5;
	}

	Vector tPos;
	TransformParticle_xzy(g_104e08d4, pParticle->m_Pos, tPos);
	sortKey = (int)tPos.z;

	if (-tPos.z > m_pDust->m_DistMax)
		return true;

	alpha *= 1.0f + tPos.z / m_pDust->m_DistMax;

	float size = pParticle->m_flSize;
	if (m_pDust->m_DustFlags & 2)
		size *= -tPos.z;

	Vector color(m_pDust->m_Color[0], m_pDust->m_Color[1], m_pDust->m_Color[2]);
	RenderParticle_Color255Size(pDraw, tPos, color, alpha * m_pDust->m_Color[3], size);
	return true;
}
// END FUNCTION

// FUNCTION: 0x100bb410 size=0x1e
#include "CDustEffect.h"

// VC6 writes CDustEffect's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CDustEffect *pcd_emit_100bb410() { return new CDustEffect; }

// TARGET: ??_GCDustEffect@@UAEPAXI@Z
// END FUNCTION
