// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1010cbd0 size=0x2b
#include "CDivideProxy.h"
namespace lifted {
struct C100e34b0 { bool sub_100e34b0(int, int); };
}
bool CDivideProxy::vfunc0(void* a0, void* a1)
{
    bool t0 = ((lifted::C100e34b0 *)this)->sub_100e34b0(*(int *)&a0, *(int *)&a1);
    if (t0 != 0) {
        if ((*(int *)((char *)this + 0x10)) != 0) {
            return 1;
        }
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1010cc00 size=0x121
#include "CDivideProxy.h"
struct MatVarV
{
	virtual void v0(); virtual void v1();
	virtual void SetFloatValue(float f);
	virtual float GetFloatValue();
	virtual void v4();
	virtual int GetIntValue();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
	virtual void SetVecValue(const float *v, int n);
	virtual void v14(); virtual void v15();
	virtual void GetVecValue(float *v, int n);
};
// TARGET: CDivideProxy::vfunc1
void CDivideProxy::vfunc1(int a)
{
	int type, vecSize;
	sub_100e3560(&type, &vecSize);
	switch (type)
	{
	case 0:
		if (((MatVarV *)m_unk10)->GetFloatValue() != 0.0f)
			sub_100e33c0(((MatVarV *)m_unk0c)->GetFloatValue() / ((MatVarV *)m_unk10)->GetFloatValue());
		break;
	case 2:
	{
		float v1[3], v2[3], v3[3];
		((MatVarV *)m_unk0c)->GetVecValue(v1, vecSize);
		((MatVarV *)m_unk10)->GetVecValue(v2, vecSize);
		v3[0] = v1[0] / v2[0];
		v3[1] = v1[1] / v2[1];
		v3[2] = v1[2] / v2[2];
		((MatVarV *)m_unk04)->SetVecValue(v3, vecSize);
		break;
	}
	case 4:
		if (((MatVarV *)m_unk10)->GetIntValue() != 0)
			((MatVarV *)m_unk04)->SetFloatValue((float)(((MatVarV *)m_unk0c)->GetIntValue() / ((MatVarV *)m_unk10)->GetIntValue()));
		break;
	}
}
// END FUNCTION

// FUNCTION: 0x1010cd90 size=0x1e
#include "CDivideProxy.h"

// VC6 writes CDivideProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CDivideProxy *pcd_emit_1010cd90() { return new CDivideProxy; }

// TARGET: ??_GCDivideProxy@@UAEPAXI@Z
// END FUNCTION
