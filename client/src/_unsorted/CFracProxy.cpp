// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1010d2e0 size=0xf2
#include "CFracProxy.h"
struct IMatVarF {
	virtual void v0(); virtual void v1(); virtual void v2();
	virtual float GetFloatValue();
	virtual void SetIntValue(int);
	virtual int GetIntValue();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
	virtual void SetVecValue(const float *, int);
	virtual void v14(); virtual void v15();
	virtual void GetVecValue(float *, int);
};
void CFracProxy::vfunc1(int)
{
	int type, size;
	sub_100e3560(&type, &size);
	switch (type) {
	case 0:
	{
		float f = ((IMatVarF *)m_unk0c)->GetFloatValue();
		sub_100e33c0(f - (int)f);
		break;
	}
	case 2:
	{
		float v[3];
		((IMatVarF *)m_unk0c)->GetVecValue(v, size);
		v[0] = v[0] - (int)v[0];
		v[1] = v[1] - (int)v[1];
		v[2] = v[2] - (int)v[2];
		((IMatVarF *)m_unk04)->SetVecValue(v, size);
		break;
	}
	case 4:
		((IMatVarF *)m_unk04)->SetIntValue(((IMatVarF *)m_unk0c)->GetIntValue());
		break;
	}
}
// END FUNCTION

// FUNCTION: 0x1010d440 size=0x1e
#include "CFracProxy.h"

// VC6 writes CFracProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CFracProxy *pcd_emit_1010d440() { return new CFracProxy; }

// TARGET: ??_GCFracProxy@@UAEPAXI@Z
// END FUNCTION
