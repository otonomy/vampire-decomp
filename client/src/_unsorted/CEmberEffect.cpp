// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10118800 size=0x1e
#include "CEmberEffect.h"

// VC6 writes CEmberEffect's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CEmberEffect *pcd_emit_10118800(const CEmberEffect &other) { return new CEmberEffect(other); }

// TARGET: ??_GCEmberEffect@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10118870 size=0xbb
#include "CEmberEffect.h"
#include "Vector.h"
#include <stdlib.h>
struct EmberParticle_10118870 { char pad[0x18]; Vector m_vecVelocity; };
void CEmberEffect::sub_10118870(EmberParticle_10118870 *pParticle, float timeDelta)
{
	float len = VectorNormalize(pParticle->m_vecVelocity);
	len -= 12.0f * timeDelta;
	Vector rnd;
	rnd.x = rand() * 7.629627e-6f - 0.125f;
	rnd.y = rand() * 7.629627e-6f - 0.125f;
	rnd.z = rand() * 7.629627e-6f - 0.125f;
	pParticle->m_vecVelocity += rnd;
	VectorNormalize(pParticle->m_vecVelocity);
	pParticle->m_vecVelocity *= len;
}
// END FUNCTION

// FUNCTION: 0x10118930 size=0x80
#include "CEmberEffect.h"
#include "Vector.h"

Vector CEmberEffect::vfunc12(const SimpleParticleC_t *p, float unused)
{
	float frac = 1.0f - p->m_flLifetime / p->m_flDieTime;
	Vector tint;
	tint.x = (float)p->m_uchColor[0] * frac * 0.003921569f;
	tint.y = (float)p->m_uchColor[1] * frac * 0.003921569f;
	tint.z = (float)p->m_uchColor[2] * frac * 0.003921569f;
	return tint;
}
// END FUNCTION
