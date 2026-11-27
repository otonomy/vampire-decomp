// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100e53a0 size=0x1
#include "C_BaseExplosionEffect.h"
void C_BaseExplosionEffect::vfunc4()
{
}
// END FUNCTION

// FUNCTION: 0x100e53b0 size=0x7d
#include "engineclient.h"
#include "C_BaseExplosionEffect.h"
#include "ConVar.h"
#include "Vector.h"

struct dlight_t_100e53b0
{
	int flags;
	Vector origin;
	float radius;
	unsigned char r, g, b, exponent;
	float die;
	float decay;
};



struct C_BaseExplosionEffect_Helper_100e53b0
{
	void *vtable;
	Vector m_vecOrigin;  // 0x04
	char pad_10[0x10];
	int m_fFlags;        // 0x20
};

extern ConVar *g_105fb29c;

void C_BaseExplosionEffect::vfunc5()
{
	C_BaseExplosionEffect_Helper_100e53b0 *pSelf = (C_BaseExplosionEffect_Helper_100e53b0 *)this;
	if (pSelf->m_fFlags & 2)
		return;

	if (g_105fb29c->vfunc1() || !g_105fb29c->m_nValue)
		return;

	dlight_t_100e53b0 *dl = ((dlight_t_100e53b0 *)effects->CL_AllocDlight(0));
	dl->origin = pSelf->m_vecOrigin;
	dl->decay = 200.0f;
	dl->radius = 255.0f;
	dl->r = 255;
	dl->g = 220;
	dl->b = 128;
	dl->die = (float)(engine->Time(0) + 0.1f);
}
// END FUNCTION

// FUNCTION: 0x100e5430 size=0x13c
#define PCD_LPF_CTOR
#include "engineclient.h"
#include "C_RecipientFilter.h"
#include "C_BaseExplosionEffect.h"
// TARGET: C_BaseExplosionEffect::vfunc1
void C_BaseExplosionEffect::vfunc1()
{
	if (m_fFlags & 4)
		return;
	CLocalPlayerFilter filter;
	switch (enginerandom->RandomInt(0, 2)) {
	case 0:
		enginesound->vfunc0("weapons/explode3.wav", 0);
		enginesound->EmitSound(filter, 0, 6, "weapons/explode3.wav", 1.0f, 0x3e99999a, 0, 100, (int)&m_vecOrigin, 0, 1, 0);
		break;
	case 1:
		enginesound->vfunc0("weapons/explode4.wav", 0);
		enginesound->EmitSound(filter, 0, 6, "weapons/explode4.wav", 1.0f, 0x3e99999a, 0, 100, (int)&m_vecOrigin, 0, 1, 0);
		break;
	case 2:
		enginesound->vfunc0("weapons/explode5.wav", 0);
		enginesound->EmitSound(filter, 0, 6, "weapons/explode5.wav", 1.0f, 0x3e99999a, 0, 100, (int)&m_vecOrigin, 0, 1, 0);
		break;
	}
}
// END FUNCTION
