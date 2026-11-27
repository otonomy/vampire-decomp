// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1010ca20 size=0x2b
#include "CMultiplyProxy.h"
namespace lifted {
struct C100e34b0 { bool sub_100e34b0(int, int); };
}
bool CMultiplyProxy::vfunc0(void* a0, void* a1)
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

// FUNCTION: 0x1010ca50 size=0xfc
#include "CMultiplyProxy.h"
struct IMatVarM {
	virtual void v0(); virtual void v1();
	virtual void SetFloatValue(float);
	virtual float GetFloatValue();
	virtual void v4();
	virtual int GetIntValue();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
	virtual void SetVecValue(const float *, int);
	virtual void v14(); virtual void v15();
	virtual void GetVecValue(float *, int);
};
struct Vec3x { float v[3]; };
void CMultiplyProxy::vfunc1(int)
{
	int type, size;
	sub_100e3560(&type, &size);
	switch (type) {
	case 0:
		sub_100e33c0(((IMatVarM *)m_unk0c)->GetFloatValue() * ((IMatVarM *)m_unk10)->GetFloatValue());
		break;
	case 2:
	{
		struct { Vec3x b, a, c; } s;
		((IMatVarM *)m_unk0c)->GetVecValue(s.a.v, size);
		((IMatVarM *)m_unk10)->GetVecValue(s.b.v, size);
		s.c.v[0] = s.a.v[0] * s.b.v[0];
		s.c.v[1] = s.a.v[1] * s.b.v[1];
		s.c.v[2] = s.a.v[2] * s.b.v[2];
		((IMatVarM *)m_unk04)->SetVecValue(s.c.v, size);
		break;
	}
	case 4:
		((IMatVarM *)m_unk04)->SetFloatValue((float)(((IMatVarM *)m_unk0c)->GetIntValue() * ((IMatVarM *)m_unk10)->GetIntValue()));
		break;
	}
}
// END FUNCTION

// FUNCTION: 0x1010cbb0 size=0x1e
#include "CMultiplyProxy.h"

// VC6 writes CMultiplyProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CMultiplyProxy *pcd_emit_1010cbb0() { return new CMultiplyProxy; }

// TARGET: ??_GCMultiplyProxy@@UAEPAXI@Z
// END FUNCTION
