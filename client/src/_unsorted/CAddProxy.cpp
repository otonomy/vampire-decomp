// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1010c6c0 size=0x2b
#include "CAddProxy.h"
namespace lifted {
struct C100e34b0 { bool sub_100e34b0(int, int); };
}
bool CAddProxy::vfunc0(void* a0, void* a1)
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

// FUNCTION: 0x1010c6f0 size=0xfb
#include "CAddProxy.h"
struct IMV { virtual void v0(); virtual void v1(); virtual void SetFloatValue(float f); virtual float GetFloatValue(); virtual void v4(); virtual int GetIntValue(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void SetVecValue(const float *v, int n); virtual void v14(); virtual void v15(); virtual void GetVecValue(float *v, int n); virtual int VectorSize(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual int GetType(); };

// TARGET: CAddProxy::vfunc1
void CAddProxy::vfunc1(int)
{
	int type, vecSize;
	sub_100e3560(&type, &vecSize);
	switch (type)
	{
	case 0:
		sub_100e33c0(((IMV *)m_unk0c)->GetFloatValue() + ((IMV *)m_unk10)->GetFloatValue());
		break;
	case 2:
	{
		float a[3], b[3], c[3];
		((IMV *)m_unk0c)->GetVecValue(a, vecSize);
		((IMV *)m_unk10)->GetVecValue(b, vecSize);
		c[0] = a[0] + b[0];
		c[1] = a[1] + b[1];
		c[2] = a[2] + b[2];
		((IMV *)m_unk04)->SetVecValue(c, vecSize);
		break;
	}
	case 4:
		((IMV *)m_unk04)->SetFloatValue((float)(((IMV *)m_unk0c)->GetIntValue() + ((IMV *)m_unk10)->GetIntValue()));
		break;
	}
}
// END FUNCTION

// FUNCTION: 0x1010c850 size=0x1e
#include "CAddProxy.h"

// VC6 writes CAddProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CAddProxy *pcd_emit_1010c850() { return new CAddProxy; }

// TARGET: ??_GCAddProxy@@UAEPAXI@Z
// END FUNCTION
