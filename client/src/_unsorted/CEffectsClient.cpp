// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100e1ae0 size=0x1e
#include "CEffectsClient.h"

// VC6 writes CEffectsClient's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CEffectsClient *pcd_emit_100e1ae0() { return new CEffectsClient; }

// TARGET: ??_GCEffectsClient@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100e1b10 size=0x3
// TARGET: sub_100e1b10
void __stdcall sub_100e1b10(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)
{
}
// END FUNCTION

// FUNCTION: 0x100e1b20 size=0xc9
#include "CEffectsClient.h"
#include "CPVSFilter.h"
#include "Vector.h"

extern void *g_1028073c;

struct ITempEntsView12
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void v9();
	virtual void v10();
	virtual void v11();
	virtual void *v12(const Vector &origin, int a, int c, float b);
	virtual void v13(void *result);
};

void CEffectsClient::vfunc2(const Vector &origin, int a, float b, int c)
{
	CPVSFilter filter(origin);
	C_RecipientFilter *pFilter = &filter;
	if (CanSend()) {
		if (pFilter->vfunc2())
			((ITempEntsView12 *)g_1028073c)->v13(((ITempEntsView12 *)g_1028073c)->v12(origin, a, c, b * 0.1f));
	}
}
// END FUNCTION

// FUNCTION: 0x100e1bf0 size=0xb3
#include "CEffectsClient.h"
#include "CPVSFilter.h"
#include "Vector.h"

void sub_10046170(const Vector &origin, int a, int b, int c);

// TARGET: CEffectsClient::vfunc3
void CEffectsClient::vfunc3(const Vector &origin, int a, int b, int c)
{
    CPVSFilter filter(origin);
    C_RecipientFilter *pFilter = &filter;
    if (CanSend()) {
        if (pFilter->vfunc2())
            sub_10046170(origin, a, b, c);
    }
}
// END FUNCTION

// FUNCTION: 0x100e1cb0 size=0xb3
#include "CEffectsClient.h"
#include "CPVSFilter.h"
#include "Vector.h"

void sub_100bae90(const Vector &origin, int a, int b, int c);

// TARGET: CEffectsClient::vfunc4
void CEffectsClient::vfunc4(const Vector &origin, int a, int b, int c)
{
    CPVSFilter filter(origin);
    C_RecipientFilter *pFilter = &filter;
    if (CanSend()) {
        if (pFilter->vfunc2())
            sub_100bae90(origin, a, b, c);
    }
}
// END FUNCTION

// FUNCTION: 0x100e1d70 size=0xb5
#include "CEffectsClient.h"
#include "CPVSFilter.h"
#include "Vector.h"

void sub_10044870(const Vector &origin, int a, int b, int c, int d);

// TARGET: CEffectsClient::vfunc5
void CEffectsClient::vfunc5(const Vector &origin, int a, int b, int c)
{
    CPVSFilter filter(origin);
    C_RecipientFilter *pFilter = &filter;
    if (CanSend()) {
        if (pFilter->vfunc2())
            sub_10044870(origin, a, b, c, 0);
    }
}
// END FUNCTION

// FUNCTION: 0x100e1e30 size=0xa9
#include "CEffectsClient.h"
#include "CPVSFilter.h"
#include "Vector.h"

void sub_10046b50(const Vector &origin, int a);

// TARGET: CEffectsClient::vfunc6
void CEffectsClient::vfunc6(const Vector &origin, int a)
{
    CPVSFilter filter(origin);
    C_RecipientFilter *pFilter = &filter;
    if (CanSend()) {
        if (pFilter->vfunc2())
            sub_10046b50(origin, a);
    }
}
// END FUNCTION

// FUNCTION: 0x100e1ee0 size=0xae
#include "CEffectsClient.h"
#include "CPVSFilter.h"
#include "Vector.h"

void sub_10046fb0(const Vector &origin, int a, int b);

// TARGET: CEffectsClient::vfunc7
void CEffectsClient::vfunc7(const Vector &origin, int a, int b)
{
    CPVSFilter filter(origin);
    C_RecipientFilter *pFilter = &filter;
    if (CanSend()) {
        if (pFilter->vfunc2())
            sub_10046fb0(origin, a, b);
    }
}
// END FUNCTION

// FUNCTION: 0x100e1f90 size=0xaf
#include "CEffectsClient.h"
#include "CPVSFilter.h"
#include "Vector.h"

void sub_10046b50(const Vector &origin, int a);
void sub_10044730(const Vector *pPos);

// TARGET: CEffectsClient::vfunc8
void CEffectsClient::vfunc8(const Vector &origin, int a)
{
	CPVSFilter filter(origin);
	C_RecipientFilter *pFilter = &filter;
	if (CanSend()) {
		if (pFilter->vfunc2()) {
			sub_10046b50(origin, a);
			sub_10044730(&origin);
		}
	}
}
// END FUNCTION

// FUNCTION: 0x100e2060 size=0x3
// TARGET: sub_100e2060
bool sub_100e2060()
{
	return false;
}
// END FUNCTION
