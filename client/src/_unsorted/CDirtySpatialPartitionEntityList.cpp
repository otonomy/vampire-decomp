// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10042c30 size=0x68
#include "CDirtySpatialPartitionEntityList.h"
#include "utlvector.h"

void __cdecl sub_101d1296(void *p);

CAutoGameSystem *CDirtySpatialPartitionEntityList::vfunc8(unsigned int flags)
{
	((CUtlVector<int> *)((char *)this + 0xc))->~CUtlVector<int>();
	sub_100f3f80();
	if (flags & 1)
		sub_101d1296(this);
	return this;
}
// END FUNCTION

// FUNCTION: 0x10042ca0 size=0x27
extern int g_104a5808;

struct CDirtyIfaceView {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10(int p);
};

bool __fastcall sub_10042ca0(char *p)
{
    int a;
    if (p != 0) {
        a = (int)(p + 8);
    } else {
        a = 0;
    }
    ((CDirtyIfaceView *)g_104a5808)->vfunc10(a);
    return true;
}
// END FUNCTION

// FUNCTION: 0x10042cd0 size=0x23
#include "engineclient.h"
#include "CDirtySpatialPartitionEntityList.h"


struct CDirtyList100dbc20 { char pad[8]; int m_8; };

// TARGET: CDirtySpatialPartitionEntityList::vfunc1
void CDirtySpatialPartitionEntityList::vfunc1()
{
	CDirtyList100dbc20 *p = (CDirtyList100dbc20 *)this;
	partition->vfunc11(p ? &p->m_8 : 0);
}
// END FUNCTION

// FUNCTION: 0x10042dc0 size=0x8
#include "CDirtySpatialPartitionEntityList.h"
void CDirtySpatialPartitionEntityList::vfunc5()
{
    *(int *)((char *)this + 0x18) = 0;
}
// END FUNCTION
