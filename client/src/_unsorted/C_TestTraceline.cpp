// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10041440 size=0x6
#include "C_TestTraceline.h"
namespace lifted {
extern char g_10282744;
}
int C_TestTraceline::vfunc16()
{
    return (int)&lifted::g_10282744;
}
// END FUNCTION

// FUNCTION: 0x10041450 size=0x3
#include "C_TestTraceline.h"
int C_TestTraceline::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10041740 size=0x1e
#include "C_TestTraceline.h"

// VC6 writes C_TestTraceline's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_TestTraceline *pcd_emit_10041740(const C_TestTraceline &other) { return new C_TestTraceline(other); }

// TARGET: ??_GC_TestTraceline@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10041e30 size=0x3a7
#include "C_TestTraceline.h"
#include "CMeshBuilder.h"
#include "CGameTrace.h"
#include "Ray_t.h"
#include "CTraceFilterSimple.h"
#include "ConVar.h"
#include "engineclient.h"

class CUnknown100421e0 { public: void sub_100421e0(); };

class IMeshView
{
public:
    virtual void LockMesh(int numVerts, int numIndices, CMeshBuilder *desc);
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void SetPrimitiveType(int type);
    virtual void v11();
    virtual void Draw(int firstIndex, int numIndices);
};

void sub_101090a0(const QAngle &angles, Vector *forward, Vector *right, Vector *up);
void sub_101659b0(const float *start, const float *end, int r, int g, int b, bool noDepthTest, float duration);
extern ConVar g_103edd98;

#define MB(T, off) (*(T *)((char *)&meshBuilder + (off)))

static inline void UTIL_TraceLine(const Vector &vecAbsStart, const Vector &vecAbsEnd, unsigned int mask, const void *ignore, int collisionGroup, CGameTrace *ptr)
{
    Ray_t ray;
    ray.sub_10042370();
    ray.sub_10005e00(&vecAbsStart.x, &vecAbsEnd.x);
    CTraceFilterSimple traceFilter;
    traceFilter.sub_1004b5c0(ignore, collisionGroup);
    enginetrace->vfunc4((int)&ray, mask, &traceFilter, (int)ptr);
    if (g_103edd98.GetBool())
        sub_101659b0(ptr->m_startpos, ptr->m_endpos, 255, 0, 0, true, -1.0f);
}

int C_TestTraceline::DrawModel(int flags, int a1)
{
    CGameTrace tr;
    ((CUnknown100421e0 *)&tr)->sub_100421e0();
    Vector forward, right, up, endpos;
    sub_101090a0(GetAbsAngles(), &forward, &right, &up);
    endpos = GetAbsOrigin() + forward * 56755.84f;

    UTIL_TraceLine(GetAbsOrigin(), endpos, 0x400b, 0, 0, &tr);

    IMeshView *pMesh = (IMeshView *)materials->GetDynamicMesh(true, 0, 0, *(void **)((char *)this + 0x410));

    CMeshBuilder meshBuilder;
    MB(int, 0x88) = 0;
    MB(int, 0x8c) = 0;
    meshBuilder.m_n90 = 0;
    meshBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_i98 = 0;
    meshBuilder.m_nIndexCount = 0;
    MB(bool, 0xa4) = false;

    MB(IMeshView *, 0x80) = pMesh;
    MB(bool, 0x84) = false;
    meshBuilder.sub_100421f0(1, 1);
    meshBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_n90 = 0;
    MB(bool, 0xa4) = true;
    MB(int, 0xa0) = 1;
    MB(IMeshView *, 0x80)->SetPrimitiveType(1);
    MB(IMeshView *, 0x80)->LockMesh(MB(int, 0x88), MB(int, 0x8c), &meshBuilder);
    meshBuilder.sub_100422e0();

    {
        const float *v = &GetAbsOrigin().x;
        float *pDst = (float *)meshBuilder.m_a8;
        *pDst++ = *v++;
        *pDst++ = *v++;
        *pDst = *v;
    }
    *(int *)meshBuilder.m_pCurrColor = 0xffffffff;

    if (++meshBuilder.m_i98 > meshBuilder.m_n90)
        meshBuilder.m_n90 = meshBuilder.m_i98;
    meshBuilder.m_a8 += meshBuilder.m_i0;
    meshBuilder.m_ac += meshBuilder.m_ic;
    meshBuilder.m_b0 += meshBuilder.m_i18;
    meshBuilder.m_b4 += meshBuilder.m_i1c;
    meshBuilder.m_b8 += meshBuilder.m_i20;
    meshBuilder.m_bc += meshBuilder.m_i24;
    meshBuilder.m_c0 += meshBuilder.m_i10;

    {
        const float *v = tr.m_endpos;
        float *pDst = (float *)meshBuilder.m_a8;
        *pDst++ = *v++;
        *pDst++ = *v++;
        *pDst = *v;
    }
    meshBuilder.sub_10042330(255, 255, 255);
    meshBuilder.sub_10005230();
    meshBuilder.sub_10041c90(false, false);
    pMesh->Draw(-1, 0);

    if (tr.m_fraction != 1.0)
    {
        unsigned char color[3];
        color[0] = 0;
        color[1] = 255;
        color[2] = 0;
        sub_100417c0(*(Vector *)tr.m_endpos, color);
    }

    if (!tr.m_allsolid && tr.m_fractionleftsolid != 0.0)
    {
        unsigned char color[3];
        color[0] = 255;
        color[1] = 0;
        color[2] = 0;
        sub_100417c0(*(Vector *)tr.m_startpos, color);
    }
    return 1;
}
// END FUNCTION
