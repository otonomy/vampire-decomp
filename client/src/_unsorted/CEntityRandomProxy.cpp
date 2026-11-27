// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101250d0 size=0x3d
#include "CEntityRandomProxy.h"
#include "CClampProxy.h"
bool CEntityRandomProxy::vfunc0(void *pMaterial, void *pKeyValues)
{
	if (!CResultProxy::vfunc0(pMaterial, pKeyValues))
		return false;
	if (!m_Input.sub_100e3140(pMaterial, pKeyValues, "scale", 1.0f))
		return false;
	return true;
}
// END FUNCTION

// FUNCTION: 0x10125110 size=0x36
#include "CEntityRandomProxy.h"

// TARGET: CEntityRandomProxy::vfunc1
void CEntityRandomProxy::vfunc1(int pEntity)
{
	if ( !pEntity )
		return;
	float flValue = *(float *)((char *)pEntity + 0x178);
	m_pResultVar->SetFloatValue(flValue * m_Input.sub_100e3270());
}
// END FUNCTION

// FUNCTION: 0x101251b0 size=0x1e
#include "CEntityRandomProxy.h"

// VC6 writes CEntityRandomProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CEntityRandomProxy *pcd_emit_101251b0() { return new CEntityRandomProxy; }

// TARGET: ??_GCEntityRandomProxy@@UAEPAXI@Z
// END FUNCTION
