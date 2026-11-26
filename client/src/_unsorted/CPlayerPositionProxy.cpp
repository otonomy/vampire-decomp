// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10124ed0 size=0x37
#include "CPlayerPositionProxy.h"
#include "CKeyValuesX.h"
bool CPlayerPositionProxy::vfunc0(void *pMaterial, void *pKeyValues)
{
	if (!CResultProxy::vfunc0(pMaterial, pKeyValues))
		return false;
	m_flScale = ((CKeyValuesX *)pKeyValues)->sub_10128540("scale", 0.005f);
	return true;
}
// END FUNCTION

// FUNCTION: 0x10124f10 size=0x52
#include "C_BasePlayer.h"
#include "CPlayerPositionProxy.h"
#include "C_BasePlayer.h"
#include "Vector.h"

struct ResultVarView {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12();
	virtual void SetVecValue(const float *pVal, int nComps);
};

// TARGET: CPlayerPositionProxy::vfunc1
void CPlayerPositionProxy::vfunc1(int a)
{
	if (C_BasePlayer::GetLocalPlayer()) {
		float scale = *(float *)((char *)this + 0xc);
		Vector v;
		VectorMultiply(C_BasePlayer::GetLocalPlayer()->GetAbsOrigin(), scale, v);
		((ResultVarView *)*(void **)((char *)this + 4))->SetVecValue(v.Base(), 3);
	}
}
// END FUNCTION

// FUNCTION: 0x10124fd0 size=0x1e
#include "CPlayerPositionProxy.h"

// VC6 writes CPlayerPositionProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CPlayerPositionProxy *pcd_emit_10124fd0() { return new CPlayerPositionProxy; }

// TARGET: ??_GCPlayerPositionProxy@@UAEPAXI@Z
// END FUNCTION
