// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10124dc0 size=0x37
#include "CPlayerSpeedProxy.h"
#include "CKeyValuesX.h"
bool CPlayerSpeedProxy::vfunc0(void *pMaterial, void *pKeyValues)
{
	if (!CResultProxy::vfunc0(pMaterial, pKeyValues))
		return false;
	m_flScale = ((CKeyValuesX *)pKeyValues)->sub_10128540("scale", 0.005f);
	return true;
}
// END FUNCTION

// FUNCTION: 0x10124e00 size=0x4f
#include "C_BasePlayer.h"
#include "CPlayerSpeedProxy.h"
#include "Vector.h"

struct SpeedEntView
{
	char pad[0xa8];
	Vector m_vecVelocity;
};

struct SpeedProxyView
{
	void *vt;
	int m_unk04;
	int m_unk08;
	float m_flScale;
	void sub_100e33c0(float);
};


// TARGET: CPlayerSpeedProxy::vfunc1
void CPlayerSpeedProxy::vfunc1(int)
{
	SpeedEntView *e = (SpeedEntView *)C_BasePlayer::GetLocalPlayer();
	SpeedProxyView *self = (SpeedProxyView *)this;
	if (e)
		self->sub_100e33c0(e->m_vecVelocity.Length() * self->m_flScale);
}
// END FUNCTION

// FUNCTION: 0x10124eb0 size=0x1e
#include "CPlayerSpeedProxy.h"

// VC6 writes CPlayerSpeedProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CPlayerSpeedProxy *pcd_emit_10124eb0() { return new CPlayerSpeedProxy; }

// TARGET: ??_GCPlayerSpeedProxy@@UAEPAXI@Z
// END FUNCTION
