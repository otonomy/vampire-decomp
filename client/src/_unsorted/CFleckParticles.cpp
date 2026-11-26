// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1002e710 size=0x1e
#include "CFleckParticles.h"

// VC6 writes CFleckParticles's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CFleckParticles *pcd_emit_1002e710(const CFleckParticles &other) { return new CFleckParticles(other); }

// TARGET: ??_GCFleckParticles@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100e5880 size=0x2f
#include "CFleckParticles.h"
struct ISub { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(int, int, int, int, int, int, int); };
void CFleckParticles::vfunc13(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	((ISub *)((char *)this + 0x78))->v4(a0, a1, a2, a3, a4, a5, a6);
}
// END FUNCTION

// FUNCTION: 0x100e58b0 size=0x3b4
#include "CFleckParticles.h"
#include "CParticleCollision.h"
#include "CMeshBuilder.h"
#include "CGameTrace.h"
#include "VMatrix.h"
#include "Vector.h"

extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
#pragma intrinsic(sin, cos)

struct ParticleDraw
{
    CMeshBuilder *m_pMeshBuilder;
    int m_unk04;
    float m_flTimeDelta;
    CMeshBuilder *GetMeshBuilder() { return m_pMeshBuilder; }
    float GetTimeDelta() const { return m_flTimeDelta; }
};

struct FleckParticle
{
    int m_unk00[3];
    Vector m_Pos;               // 0x0c
    unsigned char m_uchColor[3];// 0x18
    unsigned char m_uchSize;    // 0x1b
    float m_flRoll;             // 0x1c
    float m_flRollDelta;        // 0x20
    float m_flDieTime;          // 0x24
    float m_flLifetime;         // 0x28
    Vector m_vecVelocity;       // 0x2c
};

struct FleckParticlesView
{
    char m_pad[0x78];
    CParticleCollision m_ParticleCollision;
};

extern VMatrix g_104e08d4;

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

static inline void TransformParticle(const VMatrix &vMat, const Vector &vIn, Vector &vOut)
{
    vOut.x = vMat.m[0][0] * vIn.x + (vMat.m[0][1] * vIn.y + vMat.m[0][2] * vIn.z) + vMat.m[0][3];
    vOut.y = vMat.m[1][0] * vIn.x + (vMat.m[1][1] * vIn.y + vMat.m[1][2] * vIn.z) + vMat.m[1][3];
    vOut.z = vMat.m[2][0] * vIn.x + (vMat.m[2][1] * vIn.y + vMat.m[2][2] * vIn.z) + vMat.m[2][3];
}

static inline void MB_Position3f(CMeshBuilder *p, float x, float y, float z)
{
    float *pDst = (float *)p->m_a8;
    *pDst++ = x;
    *pDst++ = y;
    *pDst = z;
}

static inline void MB_Color4ubv(CMeshBuilder *p, const unsigned char *rgba)
{
    int col = rgba[2] | (rgba[1] << 8) | (rgba[0] << 16) | (rgba[3] << 24);
    *(int *)p->m_pCurrColor = col;
}

static inline void MB_TexCoord2f(CMeshBuilder *p, int stage, float s, float t)
{
    float *pDst = (float *)p->m_b0;
    *pDst++ = s;
    *pDst = t;
}

bool CFleckParticles::vfunc3(FleckParticle *pParticle, ParticleDraw *pDraw, float &sortKey)
{
    const float timeDelta = pDraw->GetTimeDelta();

    pParticle->m_flLifetime += timeDelta;
    if (pParticle->m_flLifetime >= pParticle->m_flDieTime)
        return false;

    Vector tPos;
    TransformParticle(g_104e08d4, pParticle->m_Pos, tPos);
    sortKey = (int)tPos.z;

    Vector color;
    color.x = pParticle->m_uchColor[0] * (1.0f / 255.0f);
    color.y = pParticle->m_uchColor[1] * (1.0f / 255.0f);
    color.z = pParticle->m_uchColor[2] * (1.0f / 255.0f);

    float roll = pParticle->m_flRoll += timeDelta * pParticle->m_flRollDelta;
    float size = pParticle->m_uchSize;
    float alpha = 1.0f - pParticle->m_flLifetime / pParticle->m_flDieTime;

    CMeshBuilder *pBuilder;
    if (!(alpha < 0.001f) && (pBuilder = pDraw->GetMeshBuilder()) != 0)
    {
        unsigned char ubColor[4];
        ubColor[0] = (unsigned char)RoundFloatToInt(color.x * 254.9f);
        ubColor[1] = (unsigned char)RoundFloatToInt(color.y * 254.9f);
        ubColor[2] = (unsigned char)RoundFloatToInt(color.z * 254.9f);
        ubColor[3] = (unsigned char)RoundFloatToInt(alpha * 254.9f);

        float ca = cos(roll);
        float sa = sin(roll);

        MB_Position3f(pBuilder, (sa - ca) * size + tPos.x, (-sa - ca) * size + tPos.y, tPos.z);
        MB_Color4ubv(pBuilder, ubColor);
        MB_TexCoord2f(pBuilder, 0, 0, 1.0f);
        pBuilder->sub_10005230();

        pBuilder->sub_100319d0((-ca - sa) * size + tPos.x, (ca - sa) * size + tPos.y, tPos.z);
        pBuilder->sub_100052c0(ubColor);
        pBuilder->sub_10031a20(0, 0, 0);
        pBuilder->sub_10005230();

        pBuilder->sub_100319d0((ca - sa) * size + tPos.x, (sa + ca) * size + tPos.y, tPos.z);
        pBuilder->sub_100052c0(ubColor);
        pBuilder->sub_10031a20(0, 1.0f, 0);
        pBuilder->sub_10005230();

        pBuilder->sub_100319d0((sa + ca) * size + tPos.x, (sa - ca) * size + tPos.y, tPos.z);
        pBuilder->sub_100052c0(ubColor);
        pBuilder->sub_10031a20(0, 1.0f, 1.0f);
        pBuilder->sub_10005230();
    }

    CGameTrace trace;
    ((FleckParticlesView *)this)->m_ParticleCollision.vfunc5(pParticle->m_Pos, pParticle->m_vecVelocity, &pParticle->m_flRollDelta, timeDelta, &trace);
    return true;
}
// END FUNCTION
