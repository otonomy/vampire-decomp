// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10124c50 size=0x37
#include "CPlayerViewProxy.h"
#include "CKeyValuesX.h"
bool CPlayerViewProxy::vfunc0(void *pMaterial, void *pKeyValues)
{
	if (!CResultProxy::vfunc0(pMaterial, pKeyValues))
		return false;
	m_flScale = ((CKeyValuesX *)pKeyValues)->sub_10128540("scale", 2.0f);
	return true;
}
// END FUNCTION

// FUNCTION: 0x10124c90 size=0xa6
#include "CPlayerViewProxy.h"
#include "Vector.h"
#include "C_BasePlayer.h"
void sub_101090a0(const QAngle &angles, Vector *forward, Vector *right, Vector *up);
// TARGET: CPlayerViewProxy::vfunc1
void CPlayerViewProxy::vfunc1(void *pArg)
{
    if (!pArg)
        return;
    C_BaseEntity *pEntity = (C_BaseEntity *)((char *)pArg - 4);
    C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
    if (!pPlayer)
        return;
    const Vector &a = pPlayer->GetAbsOrigin();
    const Vector &b = pEntity->GetAbsOrigin();
    Vector vecDelta;
    vecDelta.x = b.x - a.x;
    vecDelta.y = b.y - a.y;
    vecDelta.z = b.z - a.z;
    VectorNormalize(vecDelta);
    Vector forward;
    sub_101090a0(pPlayer->GetAbsAngles(), &forward, 0, 0);
    sub_100e33c0(DotProduct(forward, vecDelta) * m_flScale);
}
// END FUNCTION

// FUNCTION: 0x10124da0 size=0x1e
#include "CPlayerViewProxy.h"

// VC6 writes CPlayerViewProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CPlayerViewProxy *pcd_emit_10124da0() { return new CPlayerViewProxy; }

// TARGET: ??_GCPlayerViewProxy@@UAEPAXI@Z
// END FUNCTION
