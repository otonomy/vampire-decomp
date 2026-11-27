// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10079400 size=0x3
#include "CBaseAnimatedTextureProxy.h"
void CBaseAnimatedTextureProxy::vfunc5(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1007a6f0 size=0x1e
#include "CBaseAnimatedTextureProxy.h"

// VC6 writes CBaseAnimatedTextureProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CBaseAnimatedTextureProxy *pcd_emit_1007a6f0() { return new CBaseAnimatedTextureProxy; }

// TARGET: ??_GCBaseAnimatedTextureProxy@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1007a710 size=0x16
#include "CBaseAnimatedTextureProxy.h"
inline IMaterialProxy::~IMaterialProxy() {}
CBaseAnimatedTextureProxy::~CBaseAnimatedTextureProxy()
{
	sub_1007a800();
}
// END FUNCTION

// FUNCTION: 0x1007a730 size=0xc
#include "CBaseAnimatedTextureProxy.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual int f3(int); };
}
void CBaseAnimatedTextureProxy::vfunc2()
{
    if (((int)this) != 0) {
        ((lifted::V *)this)->f3(1);
    }
}
// END FUNCTION

// FUNCTION: 0x1007a740 size=0xbd
#include "CBaseAnimatedTextureProxy.h"
#include "CKeyValuesX.h"
struct IMaterial_ {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
	virtual void *FindVar(const char *name, bool *found, bool complain);
};
bool CBaseAnimatedTextureProxy::vfunc0(void *a, void *b)
{
	IMaterial_ *pMaterial = (IMaterial_ *)a;
	CKeyValuesX *pKeyValues = (CKeyValuesX *)b;
	const char *pName = pKeyValues->sub_10128590("animatedTextureVar", "");
	if (!pName)
		return false;
	bool foundVar;
	m_AnimatedTextureVar = pMaterial->FindVar(pName, &foundVar, false);
	if (!foundVar)
		return false;
	const char *pFrameName = pKeyValues->sub_10128590("animatedTextureFrameNumVar", "");
	if (!pFrameName)
		return false;
	m_AnimatedTextureFrameNumVar = pMaterial->FindVar(pFrameName, &foundVar, false);
	if (!foundVar)
		return false;
	m_FrameRate = pKeyValues->sub_10128540("animatedTextureFrameRate", 15.0f);
	m_WrapAnimation = !pKeyValues->sub_101284c0("animationNoWrap", 0);
	return true;
}
// END FUNCTION

// FUNCTION: 0x1007a810 size=0x13f
#include "CBaseAnimatedTextureProxy.h"
#include "engineclient.h"
struct ITex_1007a810 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual int GetNumAnimationFrames();
};
struct IMatVar_1007a810 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void SetIntValue(int);
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17();
	virtual ITex_1007a810 *GetTextureValue();
};
// TARGET: CBaseAnimatedTextureProxy::vfunc1
void CBaseAnimatedTextureProxy::vfunc1(int pEntity)
{
	int numFrames = ((IMatVar_1007a810 *)m_AnimatedTextureVar)->GetTextureValue()->GetNumAnimationFrames();
	float t = vfunc4(pEntity);
	float prevTime = (double)(t = engine->Time(0) - t) - engine->vfunc41(0);
	if (t < 0.0f)
		t = 0.0f;
	if (prevTime < 0.0f)
		prevTime = 0.0f;
	float prevFrame = m_FrameRate * prevTime;
	int intFrame = (int)(m_FrameRate * t) % numFrames;
	int intPrevFrame = (int)prevFrame % numFrames;
	if (intPrevFrame > intFrame) {
		if (m_WrapAnimation)
			vfunc5(pEntity);
		else {
			if (prevFrame < (float)numFrames)
				vfunc5(pEntity);
			intFrame = numFrames - 1;
		}
	} else if (!m_WrapAnimation) {
		if (prevFrame > (float)numFrames)
			intFrame = numFrames - 1;
	}
	((IMatVar_1007a810 *)m_AnimatedTextureFrameNumVar)->SetIntValue(intFrame);
}
// END FUNCTION
