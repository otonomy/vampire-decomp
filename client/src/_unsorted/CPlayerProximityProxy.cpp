// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10124b20 size=0x37
#include "CPlayerProximityProxy.h"
#include "CKeyValuesX.h"
bool CPlayerProximityProxy::vfunc0(void *pMaterial, void *pKeyValues)
{
	if (!CResultProxy::vfunc0(pMaterial, pKeyValues))
		return false;
	m_flRadius = ((CKeyValuesX *)pKeyValues)->sub_10128540("scale", 0.002f);
	return true;
}
// END FUNCTION

// FUNCTION: 0x10124b60 size=0x6b
#include "C_BasePlayer.h"
#include "CPlayerProximityProxy.h"
#include "Vector.h"


// TARGET: CPlayerProximityProxy::vfunc1
void CPlayerProximityProxy::vfunc1(int arg)
{
	void *pC_BaseEntity = (void *)arg;
	if (pC_BaseEntity)
	{
		C_BaseEntity *pLocal = ((C_BaseEntity *)C_BasePlayer::GetLocalPlayer());
		C_BaseEntity *pEnt = (C_BaseEntity *)((char *)pC_BaseEntity - 4);
		if (pLocal)
		{
			Vector delta;
			delta = pEnt->GetAbsOrigin() - pLocal->GetAbsOrigin();
			sub_100e33c0(FastSqrt(delta.x * delta.x + (delta.y * delta.y + delta.z * delta.z)) * m_flRadius);
		}
	}
}
// END FUNCTION

// FUNCTION: 0x10124c30 size=0x1e
#include "CPlayerProximityProxy.h"

// VC6 writes CPlayerProximityProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CPlayerProximityProxy *pcd_emit_10124c30() { return new CPlayerProximityProxy; }

// TARGET: ??_GCPlayerProximityProxy@@UAEPAXI@Z
// END FUNCTION
