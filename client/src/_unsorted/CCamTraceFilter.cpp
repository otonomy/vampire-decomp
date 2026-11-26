// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100fbf30 size=0x62
#include "engineclient.h"

struct Ent11V_100fbf30 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10();
	virtual int v11();
};

struct SubV6_100fbf30 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5();
	virtual void *v6();
};

bool __stdcall sub_100fbf30(void *a1, void *a2)
{
	if (!a1)
		return true;
	if (staticpropmgr->vfunc3(a1))
		return ((Ent11V_100fbf30 *)a1)->v11() != 0;
	if (!((SubV6_100fbf30 *)((char *)a1 + 0xc))->v6())
		return false;
	if (*(int *)((char *)a1 + 0x3f0))
		return false;
	return *(int *)((char *)a1 + 0x3ec) == 0 ? true : false;
}
// END FUNCTION
