// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10003fa0 size=0x6
#include "C_ParticleStorm.h"
namespace lifted {
extern char g_10271a44;
}
int C_ParticleStorm::vfunc16()
{
    return (int)&lifted::g_10271a44;
}
// END FUNCTION

// FUNCTION: 0x10003fb0 size=0x3
#include "C_ParticleStorm.h"
int C_ParticleStorm::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10004400 size=0x1e
#include "C_ParticleStorm.h"

// VC6 writes C_ParticleStorm's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_ParticleStorm *pcd_emit_10004400(const C_ParticleStorm &other) { return new C_ParticleStorm(other); }

// TARGET: ??_GC_ParticleStorm@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10004510 size=0x42
#include "C_ParticleStorm.h"
#include "Vector.h"

extern char g_104e0768[];

// TARGET: C_ParticleStorm::OnDataChanged
void C_ParticleStorm::OnDataChanged(int updateType)
{
	C_BaseEntity::OnDataChanged(updateType);
	if (updateType == 0)
	{
		sub_10004480(GetAbsOrigin(), 1);
		((IPrototypeAppEffect *)((char *)this + 0x468))->vfunc1(g_104e0768, 0);
	}
}
// END FUNCTION

// FUNCTION: 0x10004570 size=0x9f
#include "C_ParticleStorm.h"
#include "CParticleMgr.h"
#include "CParticleEffectBinding.h"
struct CL { int sub_101165c0(unsigned char); };
struct SpawnTimer
{
    float m_t0;
    float m_t1;
    void Init(float rate) { m_t0 = 1.0f / rate; m_t1 = 0; }
};
#define BIND ((CParticleEffectBinding *)((char *)this + 0x414))
// TARGET: C_ParticleStorm::vfunc1
void C_ParticleStorm::vfunc1(void *pParticleMgr, void *pArgs)
{
    CParticleMgr *pMgr = (CParticleMgr *)pParticleMgr;
    if (!pMgr->sub_101175b0(BIND, (IParticleEffectP *)this))
        return;
    m_Pos = GetAbsOrigin();
    m_Mat = BIND->sub_101163a0("particle/dx8_particle_cloud");
    IMaterial *pMaterial = (IMaterial *)((CL *)BIND)->sub_101165c0(m_Mat);
    if (pMaterial)
        m_Renderer.sub_1004a860(pMaterial);
    ((SpawnTimer *)&m_t0)->Init(m_SpawnRate);
    m_pMgr = pMgr;
}
// END FUNCTION
