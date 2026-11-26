// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10045740 size=0x1e
#include "CFXLine.h"

// VC6 writes CFXLine's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CFXLine *pcd_emit_10045740(const CFXLine &other) { return new CFXLine(other); }

// TARGET: ??_GCFXLine@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10045780 size=0x4cc
#include "CFXLine.h"
#include "engineclient.h"

#define Assert(_exp) ((void)(_exp))

struct MeshDesc_10045780
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

struct IMesh_10045780
{
	virtual void LockMesh(int numVerts, int numIndices, MeshDesc_10045780 &desc) = 0;
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

inline void IncrementFloatPointer_10045780(float *&pBufferPointer, int vertexSize)
{
	pBufferPointer = (float *)((unsigned char *)pBufferPointer + vertexSize);
}

struct MeshBuilder_10045780 : public MeshDesc_10045780
{
	IMesh_10045780 *m_pMesh;	// 0x80
	bool m_bModify;		// 0x84
	int m_NumVertices;	// 0x88
	int m_NumIndices;	// 0x8c
	int m_MaxVertex;	// 0x90
	int m_MaxIndex;		// 0x94
	int m_CurrentVertex;	// 0x98
	int m_CurrentIndex;	// 0x9c
	int m_Type;		// 0xa0
	bool m_GenerateIndices;	// 0xa4
	float *m_pCurrPosition;	// 0xa8
	float *m_pCurrNormal;	// 0xac
	float *m_pCurrTexCoord[4];	// 0xb0
	unsigned char *m_pCurrColor;	// 0xc0

	MeshBuilder_10045780()
		: m_pMesh(0), m_NumVertices(0), m_NumIndices(0), m_MaxVertex(0), m_MaxIndex(0),
		  m_CurrentVertex(0), m_CurrentIndex(0), m_GenerateIndices(false)
	{
	}

	void sub_100421f0(int type, int numPrimitives);	// ComputeNumVertsAndIndices
	void sub_100422e0();	// Reset
	void sub_10041c90(bool bSpewData, bool bDraw);	// End

	void Begin(IMesh_10045780 *pMesh, int type, int numPrimitives)
	{
		m_pMesh = pMesh;
		m_bModify = false;
		sub_100421f0(type, numPrimitives);
		m_MaxIndex = 0;
		m_MaxVertex = 0;
		m_GenerateIndices = true;
		m_Type = type;
		m_pMesh->SetPrimitiveType(type == 7 ? 2 : type);
		m_pMesh->LockMesh(m_NumVertices, m_NumIndices, *this);
		sub_100422e0();
	}

	void sub_10042960(unsigned char r, unsigned char g, unsigned char b, unsigned char a)	// Color4ub
	{
		int col = b | (g << 8) | (r << 16) | (a << 24);
		*(int *)m_pCurrColor = col;
	}

	void sub_10041e00(const float *v)	// Position3fv
	{
		float *pDst = m_pCurrPosition;
		*pDst++ = *v++;
		*pDst++ = *v++;
		*pDst = *v;
	}

	void sub_100319f0(const float *n)	// Normal3fv
	{
		float *pDst = m_pCurrNormal;
		*pDst++ = *n++;
		*pDst++ = *n++;
		*pDst = *n;
	}

	void sub_10031a20(int stage, float s, float t)	// TexCoord2f
	{
		Assert(m_pTexCoord[stage] && m_pCurrTexCoord[stage]);
		float *pDst = m_pCurrTexCoord[stage];
		*pDst++ = s;
		*pDst = t;
	}

	void sub_10005230()	// AdvanceVertex
	{
		if (++m_CurrentVertex > m_MaxVertex)
			m_MaxVertex = m_CurrentVertex;

		IncrementFloatPointer_10045780(m_pCurrPosition, m_VertexSize_Position);
		IncrementFloatPointer_10045780(m_pCurrNormal, m_VertexSize_Normal);
		IncrementFloatPointer_10045780(m_pCurrTexCoord[0], m_VertexSize_TexCoord[0]);
		IncrementFloatPointer_10045780(m_pCurrTexCoord[1], m_VertexSize_TexCoord[1]);
		IncrementFloatPointer_10045780(m_pCurrTexCoord[2], m_VertexSize_TexCoord[2]);
		IncrementFloatPointer_10045780(m_pCurrTexCoord[3], m_VertexSize_TexCoord[3]);
		m_pCurrColor += m_VertexSize_Color;
	}
};

const Vector &sub_10198d30();	// MainViewOrigin
void sub_10045630(const Vector &a, const Vector &b, Vector &result);	// CrossProduct
void sub_10108fd0(const Vector &start, float scale, const Vector &direction, Vector &dest);	// VectorMA

void CFXLine::vfunc1(double frametime)
{
	vfunc5(frametime);

	Vector &start = *(Vector *)((char *)this + 0x10);
	Vector &end = *(Vector *)((char *)this + 0x1c);
	float &scale = *(float *)((char *)this + 0x30);

	Vector lineDir;
	VectorSubtract(end, start, lineDir);
	Vector viewDir;
	VectorSubtract(end, sub_10198d30(), viewDir);
	Vector cross;
	sub_10045630(lineDir, viewDir, cross);
	Vector normal = cross;
	VectorNormalize(normal);

	IMesh_10045780 *pMesh = (IMesh_10045780 *)materials->GetDynamicMesh(true, 0, 0, *(void **)((char *)this + 0xc));

	MeshBuilder_10045780 meshBuilder;
	meshBuilder.Begin(pMesh, 7, 1);

	Vector tmp;

	sub_10108fd0(start, -scale, normal, tmp);
	meshBuilder.sub_10041e00(&tmp.x);
	meshBuilder.sub_10031a20(0, 1.0f, 1.0f);
	meshBuilder.sub_10042960(255, 255, 255, 255);
	meshBuilder.sub_100319f0(&normal.x);
	meshBuilder.sub_10005230();

	sub_10108fd0(start, scale, normal, tmp);
	meshBuilder.sub_10041e00(&tmp.x);
	meshBuilder.sub_10031a20(0, 0.0f, 1.0f);
	meshBuilder.sub_10042960(255, 255, 255, 255);
	meshBuilder.sub_100319f0(&normal.x);
	meshBuilder.sub_10005230();

	sub_10108fd0(end, scale, normal, tmp);
	meshBuilder.sub_10041e00(&tmp.x);
	meshBuilder.sub_10031a20(0, 0.0f, 0.0f);
	meshBuilder.sub_10042960(255, 255, 255, 255);
	meshBuilder.sub_100319f0(&normal.x);
	meshBuilder.sub_10005230();

	sub_10108fd0(end, -scale, normal, tmp);
	meshBuilder.sub_10041e00(&tmp.x);
	meshBuilder.sub_10031a20(0, 1.0f, 0.0f);
	meshBuilder.sub_10042960(255, 255, 255, 255);
	meshBuilder.sub_100319f0(&normal.x);
	meshBuilder.sub_10005230();

	meshBuilder.sub_10041c90(false, false);
	pMesh->Draw();
}
// END FUNCTION

// FUNCTION: 0x10045c50 size=0x18
#include "CFXLine.h"
bool CFXLine::vfunc3()
{
	if (m_flUnk2c > 0.0)
		return true;
	return false;
}
// END FUNCTION

// FUNCTION: 0x10045c70 size=0x1a
#include "CFXLine.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual int f13(int); };
}
void CFXLine::vfunc4()
{
    if ((*(int *)((char *)this + 0xc)) != 0) {
        int t0 = ((lifted::V *)(*(int *)((char *)this + 0xc)))->f13(0);
        *(int *)((char *)this + 0xc) = 0;
    }
}
// END FUNCTION

// FUNCTION: 0x10045c90 size=0x3d
#include "CFXLine.h"
void sub_10108fd0(const float *a, float s, const float *b, float *c);
void CFXLine::vfunc5(double dt)
{
	m_flUnk2c -= dt;
	float f = (float)dt;
	float *p = (float *)((char *)this + 0x10);
	float *d = (float *)((char *)this + 0x34);
	sub_10108fd0(p, f, d, p);
	float *q = (float *)((char *)this + 0x1c);
	sub_10108fd0(q, f, d, q);
}
// END FUNCTION
