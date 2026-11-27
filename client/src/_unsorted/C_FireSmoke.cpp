// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100b5080 size=0x6
#include "C_FireSmoke.h"
namespace lifted {
extern char g_102b3894;
}
int C_FireSmoke::vfunc16()
{
    return (int)&lifted::g_102b3894;
}
// END FUNCTION

// FUNCTION: 0x100b5090 size=0x3
#include "C_FireSmoke.h"
int C_FireSmoke::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100b52c0 size=0x1aa
#include "C_FireSmoke.h"
#include "CLitSmokeEmitter.h"
#include <stddef.h>

CSmartPtr<CParticleEffect> sub_10118820(const char *name);

// TARGET: C_FireSmoke::C_FireSmoke
C_FireSmoke::C_FireSmoke()
    : m_flChildFlameSpread(-1.0f), m_nUnk27fc(0)
{
    m_flStartScale = 0.0f;
    m_flScale = 0.0f;
    m_flScaleTime = 0.0f;
    m_nFlags = 0;
    m_nFlameModelIndex = 0;
    m_flScaleRegister = 0.0f;
    m_flScaleStart = 0.0f;
    m_flScaleEnd = 0.0f;
    m_flScaleTimeStart = 0.0f;
    m_flScaleTimeEnd = 0.0f;
    m_bClipTested = false;
    for (int i = 0; i < 8; i++)
        m_entFlames[i].vfunc78();
    m_pEmberEmitter = (CParticleEffect *)sub_10118820("C_FireSmoke::m_pEmberEmitter");
    CLitSmokeEmitter *pSmoke = new CLitSmokeEmitter("C_FireSmoke::m_pSmokeEmitter");
    CSmartPtr<CLitSmokeEmitter> ret(pSmoke);
    m_pSmokeEmitter = (CParticleEffect *)ret;
}
// END FUNCTION

// FUNCTION: 0x100b5490 size=0x1e
#include "C_FireSmoke.h"

// VC6 writes C_FireSmoke's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_FireSmoke *pcd_emit_100b5490(const C_FireSmoke &other) { return new C_FireSmoke(other); }

// TARGET: ??_GC_FireSmoke@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100b54f0 size=0x95
#include "C_FireSmoke.h"
C_FireSmoke::~C_FireSmoke()
{
	if (m_p2800) {
		delete m_p2800;
		m_p2800 = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x100b5590 size=0x1b
#include "C_FireSmoke.h"
void C_FireSmoke::vfunc37()
{
	if (m_nFlags & 1) {
		sub_100b5d90();
		sub_100b55b0();
	}
}
// END FUNCTION
