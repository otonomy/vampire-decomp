// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10044eb0 size=0x91
#include "CFXDiscreetLine.h"
#include "Vector.h"

struct IMat_10044eb0 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual IMatInst_10044eb0 *FindMaterial(const char *name, int a, int b);
};
extern IMat_10044eb0 *g_104a57ec;

CFXDiscreetLine::CFXDiscreetLine(const char *name, const Vector &start, const Vector &direction, float velocity, float length, float clipLength, float scale, float life, const char *shader)
	: CClientSideEffect((int)name)
{
	if (g_104a57ec) {
		m_pMaterial = g_104a57ec->FindMaterial(shader, 0, 1);
		m_pMaterial->v12(0);
		m_vStart = start;
		m_vDir = direction;
		m_flVelocity = velocity;
		m_flClip = clipLength;
		m_flScale = scale;
		m_flUnk10 = life;
		m_flUnk30 = 0;
		m_flLength = length;
	}
}
// END FUNCTION

// FUNCTION: 0x10044f50 size=0x1e
#include "CFXDiscreetLine.h"

// VC6 writes CFXDiscreetLine's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CFXDiscreetLine *pcd_emit_10044f50(const CFXDiscreetLine &other) { return new CFXDiscreetLine(other); }

// TARGET: ??_GCFXDiscreetLine@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10044f90 size=0x6a0
#include "CFXDiscreetLine.h"
#include "engineclient.h"
#include <math.h>

void sub_10108fd0(const Vector &start, float scale, const Vector &direction, Vector &dest);
void sub_10045630(const Vector &a, const Vector &b, Vector &result);
const Vector &sub_10198d30();

#define dl_max(a, b) (((a) > (b)) ? (a) : (b))
#define dl_min(a, b) (((a) < (b)) ? (a) : (b))

static inline Vector DLCross(const Vector &a, const Vector &b)
{
	Vector res;
	sub_10045630(a, b, res);
	return res;
}

struct DLMeshDesc
{
	int m_VertexSize_Position;
	int m_VertexSize_BoneWeight;
	int m_VertexSize_BoneMatrixIndex;
	int m_VertexSize_Normal;
	int m_VertexSize_Color;
	int m_VertexSize_Specular;
	int m_VertexSize_TexCoord[4];
	int m_unk28[(0x80 - 0x28) / 4];
};

struct DLMesh
{
	virtual void LockMesh(int numVerts, int numIndices, DLMeshDesc &desc);
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void SetPrimitiveType(int type);
	virtual void v11();
	virtual void Draw(int firstIndex, int numIndices);
};

struct DLMeshBuilder : public DLMeshDesc
{
	DLMesh *m_pMesh;
	bool m_bGenerateIndices;
	int m_NumVertices;
	int m_NumIndices;
	int m_n90;
	int m_n94;
	int m_nCurrentVertex;
	int m_n9c;
	int m_Type;
	bool m_bA4;
	float *m_pCurrPosition;
	float *m_pCurrNormal;
	float *m_pCurrTexCoord[4];
	unsigned char *m_pCurrColor;

	DLMeshBuilder()
		: m_pMesh(0), m_NumVertices(0), m_NumIndices(0), m_n90(0), m_n94(0),
		  m_nCurrentVertex(0), m_n9c(0), m_bA4(false)
	{
	}
	void sub_100421f0(int type, int numPrimitives);
	void sub_100422e0();
	void sub_10005230();
	void sub_10031a20(int stage, float s, float t);
	void sub_10042960(int r, int g, int b, int a);
	void sub_100319f0(const float *n);
	void sub_10041c90(bool bSpewData, bool bDraw);

	__forceinline void Begin(DLMesh *pMesh, int type, int numPrimitives)
	{
		m_pMesh = pMesh;
		m_bGenerateIndices = false;
		sub_100421f0(type, numPrimitives);
		m_n94 = 0;
		m_n90 = 0;
		m_bA4 = true;
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
	__forceinline void Normal3fv(const float *n)
	{
		float *pDst = m_pCurrNormal;
		*pDst++ = *n++;
		*pDst++ = *n++;
		*pDst = *n;
	}
	__forceinline void TexCoord2f(int stage, float s, float t)
	{
		float *pDst = m_pCurrTexCoord[stage];
		*pDst++ = s;
		*pDst = t;
	}
	__forceinline void Color4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		int col = r | (g << 8) | (b << 16) | (a << 24);
		*(int *)m_pCurrColor = col;
	}
	__forceinline void AdvanceVertex()
	{
		if (++m_nCurrentVertex > m_n90)
			m_n90 = m_nCurrentVertex;
		m_pCurrPosition = (float *)((unsigned char *)m_pCurrPosition + m_VertexSize_Position);
		m_pCurrNormal = (float *)((unsigned char *)m_pCurrNormal + m_VertexSize_Normal);
		m_pCurrTexCoord[0] = (float *)((unsigned char *)m_pCurrTexCoord[0] + m_VertexSize_TexCoord[0]);
		m_pCurrTexCoord[1] = (float *)((unsigned char *)m_pCurrTexCoord[1] + m_VertexSize_TexCoord[1]);
		m_pCurrTexCoord[2] = (float *)((unsigned char *)m_pCurrTexCoord[2] + m_VertexSize_TexCoord[2]);
		m_pCurrTexCoord[3] = (float *)((unsigned char *)m_pCurrTexCoord[3] + m_VertexSize_TexCoord[3]);
		m_pCurrColor += m_VertexSize_Color;
	}
};

void CFXDiscreetLine::vfunc1(double frametime)
{
	Vector lineDir, viewDir, cross;
	Vector vecEnd, vecStart;
	Vector tmp;

	vfunc5(frametime);

	float sDistance = m_flUnk30 * m_flVelocity;
	float eDistance = sDistance - m_flLength;

	sDistance = dl_max(0.0f, sDistance);
	eDistance = dl_max(0.0f, eDistance);

	if ((sDistance == 0.0f) && (eDistance == 0.0f))
		return;

	if (m_flClip != 0.0f)
	{
		sDistance = dl_min(sDistance, m_flClip);
		eDistance = dl_min(eDistance, m_flClip);
	}

	float dDistance = fabs(sDistance - eDistance);
	float dTotal = (m_flLength != 0.0f) ? m_flLength : 0.01f;
	float fOffset = (dDistance / dTotal);

	sub_10108fd0(m_vStart, sDistance, m_vDir, vecEnd);
	sub_10108fd0(m_vStart, eDistance, m_vDir, vecStart);

	VectorSubtract(vecEnd, vecStart, lineDir);
	VectorSubtract(vecEnd, sub_10198d30(), viewDir);

	cross = DLCross(lineDir, viewDir);
	VectorNormalize(cross);

	DLMesh *pMesh = (DLMesh *)materials->GetDynamicMesh(true, 0, 0, m_pMaterial);
	DLMeshBuilder meshBuilder;
	meshBuilder.Begin(pMesh, 7, 1);

	sub_10108fd0(vecStart, -m_flScale, cross, tmp);
	meshBuilder.Position3fv(&tmp.x);
	meshBuilder.TexCoord2f(0, 1.0f, fOffset);
	meshBuilder.Color4ub(255, 255, 255, 255);
	meshBuilder.Normal3fv(&cross.x);
	meshBuilder.AdvanceVertex();

	sub_10108fd0(vecStart, m_flScale, cross, tmp);
	meshBuilder.Position3fv(&tmp.x);
	meshBuilder.TexCoord2f(0, 0.0f, fOffset);
	meshBuilder.Color4ub(255, 255, 255, 255);
	meshBuilder.Normal3fv(&cross.x);
	meshBuilder.AdvanceVertex();

	sub_10108fd0(vecEnd, m_flScale, cross, tmp);
	meshBuilder.Position3fv(&tmp.x);
	meshBuilder.TexCoord2f(0, 0.0f, 0.0f);
	meshBuilder.Color4ub(255, 255, 255, 255);
	meshBuilder.Normal3fv(&cross.x);
	meshBuilder.AdvanceVertex();

	sub_10108fd0(vecEnd, -m_flScale, cross, tmp);
	meshBuilder.Position3fv(&tmp.x);
	meshBuilder.sub_10031a20(0, 1.0f, 0.0f);
	meshBuilder.sub_10042960(255, 255, 255, 255);
	meshBuilder.sub_100319f0(&cross.x);
	meshBuilder.sub_10005230();

	meshBuilder.sub_10041c90(false, false);
	pMesh->Draw(-1, 0);
}
// END FUNCTION

// FUNCTION: 0x10045670 size=0x18
#include "CFXDiscreetLine.h"
bool CFXDiscreetLine::vfunc3()
{
	if (m_flUnk10 > 0.0)
		return true;
	return false;
}
// END FUNCTION

// FUNCTION: 0x10045690 size=0x1a
#include "CFXDiscreetLine.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual int f13(int); };
}
void CFXDiscreetLine::vfunc4()
{
    if ((*(int *)((char *)this + 0xc)) != 0) {
        int t0 = ((lifted::V *)(*(int *)((char *)this + 0xc)))->f13(0);
        *(int *)((char *)this + 0xc) = 0;
    }
}
// END FUNCTION

// FUNCTION: 0x100456b0 size=0x17
#include "CFXDiscreetLine.h"
void CFXDiscreetLine::vfunc5(double dt)
{
	m_flUnk30 += dt;
	m_flUnk10 -= dt;
}
// END FUNCTION
