// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1013a1a0 size=0xc
#include "CTextureScrollMaterialProxy.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual int f3(int); };
}
void CTextureScrollMaterialProxy::vfunc2()
{
    if (((int)this) != 0) {
        ((lifted::V *)this)->f3(1);
    }
}
// END FUNCTION

// FUNCTION: 0x1013a1e0 size=0x75
#include "CTextureScrollMaterialProxy.h"
#include "CKeyValuesX.h"

struct IMaterialView
{
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual void *FindVar(const char *name, bool *found, bool complain);
};

bool CTextureScrollMaterialProxy::vfunc0(void *pMaterial, void *pKeyValues)
{
    CKeyValuesX *pKV = (CKeyValuesX *)pKeyValues;
    const char *pVar = pKV->sub_10128590("textureScrollVar", "");
    if (!pVar)
        return false;
    bool bFound;
    m_pVar = ((IMaterialView *)pMaterial)->FindVar(pVar, &bFound, false);
    if (!bFound)
        return false;
    m_flRate = pKV->sub_10128540("textureScrollRate", 1.0f);
    m_flAngle = pKV->sub_10128540("textureScrollAngle", 0.0f);
    return true;
}
// END FUNCTION

// FUNCTION: 0x1013a260 size=0x132
#include "CTextureScrollMaterialProxy.h"
#include "engineclient.h"
#include <math.h>

struct VMat { float m[16]; };
struct IMatVarView {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10();
    virtual void SetVecValue(float x, float y, float z);
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22();
    virtual int GetType();
    virtual void v24(); virtual void v25();
    virtual void SetMatrixValue(VMat &m);
};
extern "C" void sub_101a2b00(VMat *, float, float, float);

// TARGET: CTextureScrollMaterialProxy::vfunc1
void CTextureScrollMaterialProxy::vfunc1(int)
{
    if (!m_pVar) return;
    float rate = m_flRate;
    double angle = m_flAngle * 0.017453292519943295;
    float s = (float)(cos(angle) * engine->Time(0)) * rate;
    float t = (float)(sin(angle) * engine->Time(0)) * rate;
    if (s < 0.0f) s += 1.0f + (int)s * -1.0f;
    if (t < 0.0f) t += 1.0f + (int)t * -1.0f;
    s = s - (int)s;
    t = t - (int)t;
    if (((IMatVarView *)m_pVar)->GetType() == 7) {
        VMat mat;
        sub_101a2b00(&mat, s, t, 0.0f);
        ((IMatVarView *)m_pVar)->SetMatrixValue(mat);
    } else {
        ((IMatVarView *)m_pVar)->SetVecValue(s, t, 0.0f);
    }
}
// END FUNCTION
