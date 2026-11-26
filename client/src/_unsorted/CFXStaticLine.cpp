// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100e6580 size=0x82
#include "Vector.h"
#include "CFXStaticLine.h"
struct IMatSys25 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual struct IMatObj *Find(const char *name, int a, int b); };
struct IMatObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void Ref(int a); };
extern IMatSys25 *g_104a57ec;
CFXStaticLine::CFXStaticLine(int a1, const Vector *start, const Vector *end, float width, float f5, const char *material, float f7)
	: CClientSideEffect(a1)
{
	if (g_104a57ec) {
		IMatObj *mat = g_104a57ec->Find(material, 0, 1);
		*(IMatObj **)((char *)this + 0xc) = mat;
		mat->Ref(0);
		*(Vector *)((char *)this + 0x10) = *start;
		*(Vector *)((char *)this + 0x1c) = *end;
		*(float *)((char *)this + 0x28) = f7;
		*(float *)((char *)this + 0x2c) = f5;
		*(float *)((char *)this + 0x30) = width * 0.5f;
	}
}
// END FUNCTION

// FUNCTION: 0x100e6610 size=0x1e
#include "CFXStaticLine.h"

// VC6 writes CFXStaticLine's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CFXStaticLine *pcd_emit_100e6610(const CFXStaticLine &other) { return new CFXStaticLine(other); }

// TARGET: ??_GCFXStaticLine@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100e6650 size=0x595
#include "CFXStaticLine.h"
#include "engineclient.h"

struct MeshDesc_100e6650
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

struct IMesh_100e6650
{
	virtual void LockMesh(int numVerts, int numIndices, MeshDesc_100e6650 &desc) = 0;
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

inline void IncrementFloatPointer_100e6650(float *&p, int vertexSize)
{
	p = (float *)((unsigned char *)p + vertexSize);
}

struct MeshBuilder_100e6650 : public MeshDesc_100e6650
{
	IMesh_100e6650 *m_pMesh;
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

	MeshBuilder_100e6650()
		: m_pMesh(0), m_NumVertices(0), m_NumIndices(0), m_MaxVertex(0), m_MaxIndex(0),
		  m_CurrentVertex(0), m_CurrentIndex(0), m_GenerateIndices(false)
	{
	}

	void sub_100421f0(int type, int numPrimitives);
	void sub_100422e0();
	void sub_10041e00(const float *v);
	void sub_100319f0(const float *v);
	void sub_10031a20(int stage, float s, float t);
	void sub_10042960(int r, int g, int b, int a);
	void sub_10005230();
	void sub_10041c90(bool bSpewData, bool bDraw);

	void Begin(IMesh_100e6650 *pMesh, int type, int numPrimitives)
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

	void Position3fv(const float *v)
	{
		float *pDst = m_pCurrPosition;
		*pDst++ = *v++;
		*pDst++ = *v++;
		*pDst = *v;
	}
	void Normal3fv(const float *n)
	{
		float *pDst = m_pCurrNormal;
		*pDst++ = *n++;
		*pDst++ = *n++;
		*pDst = *n;
	}
	void TexCoord2f(int stage, float s, float t)
	{
		float *pDst = m_pCurrTexCoord[stage];
		*pDst++ = s;
		*pDst = t;
	}
	void Color4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		int col = b | (g << 8) | (r << 16) | (a << 24);
		*(int *)m_pCurrColor = col;
	}
	void AdvanceVertex()
	{
		if (++m_CurrentVertex > m_MaxVertex)
			m_MaxVertex = m_CurrentVertex;
		IncrementFloatPointer_100e6650(m_pCurrPosition, m_VertexSize_Position);
		IncrementFloatPointer_100e6650(m_pCurrNormal, m_VertexSize_Normal);
		IncrementFloatPointer_100e6650(m_pCurrTexCoord[0], m_VertexSize_TexCoord[0]);
		IncrementFloatPointer_100e6650(m_pCurrTexCoord[1], m_VertexSize_TexCoord[1]);
		IncrementFloatPointer_100e6650(m_pCurrTexCoord[2], m_VertexSize_TexCoord[2]);
		IncrementFloatPointer_100e6650(m_pCurrTexCoord[3], m_VertexSize_TexCoord[3]);
		m_pCurrColor += m_VertexSize_Color;
	}
};

struct StaticLineFlags_100e6650
{
	unsigned int flipHorizontal : 1;
	unsigned int flipVertical : 1;
};

const Vector &sub_10198d30();
void sub_10045630(const Vector &a, const Vector &b, Vector &result);
void sub_10108fd0(const Vector &start, float scale, const Vector &direction, Vector &dest);

void CFXStaticLine::vfunc1(double frametime)
{
	Vector lineDir, viewDir, cross;
	Vector tmp;

	vfunc5(frametime);

	Vector &start = *(Vector *)((char *)this + 0x10);
	Vector &end = *(Vector *)((char *)this + 0x1c);
	float &scale = *(float *)((char *)this + 0x30);

	VectorSubtract(end, start, lineDir);
	VectorSubtract(end, sub_10198d30(), viewDir);

	{
		Vector res;
		sub_10045630(lineDir, viewDir, res);
		cross = res;
	}

	VectorNormalize(cross);

	IMesh_100e6650 *pMesh = (IMesh_100e6650 *)materials->GetDynamicMesh(true, 0, 0, *(void **)((char *)this + 0xc));
	MeshBuilder_100e6650 meshBuilder;
	meshBuilder.Begin(pMesh, 7, 1);

	StaticLineFlags_100e6650 &flags = *(StaticLineFlags_100e6650 *)((char *)this + 0x28);
	bool flipHorizontal = flags.flipHorizontal;
	bool flipVertical = flags.flipVertical;

	sub_10108fd0(start, -scale, cross, tmp);
	meshBuilder.Position3fv(tmp.Base());
	meshBuilder.Normal3fv(cross.Base());
	if (flipHorizontal)
		meshBuilder.TexCoord2f(0, 0.0f, 1.0f);
	else if (flipVertical)
		meshBuilder.TexCoord2f(0, 0.0f, 0.0f);
	else
		meshBuilder.TexCoord2f(0, 1.0f, 1.0f);
	meshBuilder.Color4ub(255, 255, 255, 255);
	meshBuilder.AdvanceVertex();

	sub_10108fd0(start, scale, cross, tmp);
	meshBuilder.Position3fv(tmp.Base());
	meshBuilder.Normal3fv(cross.Base());
	if (flipHorizontal)
		meshBuilder.TexCoord2f(0, 1.0f, 1.0f);
	else if (flipVertical)
		meshBuilder.TexCoord2f(0, 1.0f, 0.0f);
	else
		meshBuilder.TexCoord2f(0, 0.0f, 1.0f);
	meshBuilder.Color4ub(255, 255, 255, 255);
	meshBuilder.AdvanceVertex();

	sub_10108fd0(end, scale, cross, tmp);
	meshBuilder.Position3fv(tmp.Base());
	meshBuilder.Normal3fv(cross.Base());
	if (flipHorizontal)
		meshBuilder.TexCoord2f(0, 1.0f, 0.0f);
	else if (flipVertical)
		meshBuilder.TexCoord2f(0, 1.0f, 1.0f);
	else
		meshBuilder.TexCoord2f(0, 0.0f, 0.0f);
	meshBuilder.Color4ub(255, 255, 255, 255);
	meshBuilder.sub_10005230();

	sub_10108fd0(end, -scale, cross, tmp);
	meshBuilder.Position3fv(tmp.Base());
	meshBuilder.sub_100319f0(cross.Base());
	if (flipHorizontal)
		meshBuilder.sub_10031a20(0, 0.0f, 0.0f);
	else if (flipVertical)
		meshBuilder.sub_10031a20(0, 0.0f, 1.0f);
	else
		meshBuilder.sub_10031a20(0, 1.0f, 0.0f);
	meshBuilder.sub_10042960(255, 255, 255, 255);
	meshBuilder.sub_10005230();

	meshBuilder.sub_10041c90(false, false);
	pMesh->Draw();
}
// END FUNCTION

// FUNCTION: 0x100e6bf0 size=0x18
#include "CFXStaticLine.h"
bool CFXStaticLine::vfunc3()
{
	if (*(float *)((char *)this + 0x2c) > 0.0)
		return true;
	return false;
}
// END FUNCTION

// FUNCTION: 0x100e6c10 size=0x1a
#include "CFXStaticLine.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual int f13(int); };
}
void CFXStaticLine::vfunc4()
{
    if ((*(int *)((char *)this + 0xc)) != 0) {
        int t0 = ((lifted::V *)(*(int *)((char *)this + 0xc)))->f13(0);
        *(int *)((char *)this + 0xc) = 0;
    }
}
// END FUNCTION
