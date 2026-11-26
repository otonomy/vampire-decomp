// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100389a0 size=0x57
#include "C_TEGunshotDecal.h"
C_TEGunshotDecal::C_TEGunshotDecal()
{
    m_v1.Init(); m_v2.Init(); m_v3.Init();
    m_v4.Init();
    m_unk4c = 0; m_unk50 = 0;
    m_unk34 = -1; m_unk38 = 0x43; m_unk3c = 1;
}
// TARGET: ??0C_TEGunshotDecal@@QAE@XZ
// END FUNCTION

// FUNCTION: 0x10038a00 size=0x1e
#include "C_TEGunshotDecal.h"

// VC6 writes C_TEGunshotDecal's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_TEGunshotDecal *pcd_emit_10038a00(const C_TEGunshotDecal &other) { return new C_TEGunshotDecal(other); }

// TARGET: ??_GC_TEGunshotDecal@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10038a40 size=0x18
#include "C_TEGunshotDecal.h"
namespace lifted {
extern char g_1027e718;
extern int g_104a57e0;
struct V { virtual void u0(); virtual void u1(); virtual int f2(int); };
}
void C_TEGunshotDecal::vfunc13()
{
    int t0 = ((lifted::V *)lifted::g_104a57e0)->f2((int)&lifted::g_1027e718);
    *(int *)((char *)this + 0x50) = t0;
}
// END FUNCTION

// FUNCTION: 0x10038c40 size=0x2dd
#define PCD_LPF_CTOR
#include "C_TEGunshotDecal.h"
#include "C_RecipientFilter.h"
#include "CSoundParameters.h"
#include "CGameTrace.h"
#include "engineclient.h"
#include "Tier1.h"

extern "C" int __cdecl sprintf(char *, const char *, ...);
__declspec(dllimport) void DevMsg(int level, const char *pMsg, ...);
__declspec(dllimport) void Q_strncpy(char *pDest, const char *pSrc, int maxLen);
extern void (*g_101e310c)(const char *pMsg, ...);	// Warning
bool sub_1012d7f0(const char *pName, CSoundParameters &params);	// soundemitter GetParametersForSound(name, params)

struct CImpactSurfaceData	// the surface record physprops slot 5 returns: its impact sounds
{
	char m_pad00[0x3e];
	unsigned short m_nImpactSound;	// 0x3e
	unsigned short m_unk40;
	unsigned short m_nImpactSounds[6][3];	// 0x42
};

#define GD_TYPE (*(int *)&m_v4.y)	// 0x44
#define GD_VARIANT (*(int *)&m_v4.z)	// 0x48

void C_TEGunshotDecal::vfunc18(CGameTrace *pTrace)
{
	CImpactSurfaceData *psurf = (CImpactSurfaceData *)physprops->vfunc5(pTrace->m_surfaceProps);
	if (GD_TYPE == -1 || GD_TYPE >= 6)
	{
		const char *pName = physprops->vfunc6(psurf->m_nImpactSound);
		if (pName && *pName)
		{
			enginesound->vfunc0(pName, 0);
			float vol = enginerandom->RandomFloat(0.75f, 1.0f);
			int pitch = enginerandom->RandomInt(94, 106);
			CSoundParameters params;
			if (!sub_1012d7f0(pName, params))
			{
				params.channel = 0;
				params.volume = 1.0f;
				params.pitch = 100;
				params.pitchlow = 100;
				params.pitchhigh = 100;
				params.soundlevel = 75;
				params.play_to_owner_only = false;
				params.count = 0;
				Q_strncpy(params.soundname, pName, sizeof(params.soundname));
			}
			CLocalPlayerFilter filter;
			enginesound->vfunc2(filter, 0, 3, pName, vol, 75, 0, pitch, (const Vector *)pTrace->m_endpos, 0, 1, 0);
		}
	}
	else
	{
		unsigned short sound = psurf->m_nImpactSounds[GD_TYPE][GD_VARIANT];
		if (sound > 0)
		{
			const char *pName;
			if (!(m_unk4c & 1))
				pName = physprops->vfunc6(sound);
			else
			{
				char buf[64];
				sprintf(buf, "Disciplines/Thaumaturgy/Blood Shield/Hit_%d", g_101e31a4(1, 3));
				pName = buf;
			}

			DevMsg(3, "impactType: %s\n", pName);
			if (pName && *pName)
			{
				enginesound->vfunc0(pName, 0);
				CLocalPlayerFilter filter;
				float vol = enginerandom->RandomFloat(0.75f, 1.0f);
				int pitch = enginerandom->RandomInt(94, 106);
				enginesound->vfunc2(filter, 0, 3, pName, vol, 75, 0, pitch, (const Vector *)pTrace->m_endpos, 0, 1, 0);
			}
			else
			{
				g_101e310c("Empty sound name in C_TEGunshotDecal::PlayImpactSound()\n  Props - %d, Group - %d, Type - %d\n", pTrace->m_surfaceProps, GD_TYPE, GD_VARIANT);
			}
		}
	}
}
// END FUNCTION

// FUNCTION: 0x10039620 size=0xba
#include "engineclient.h"
#include "C_TEGunshotDecal.h"
extern bool sub_100b42a0(Vector origin, int decal, Vector a, Vector b, float c, float d, float e, int f);
void C_TEGunshotDecal::vfunc16(int a, int b)
{
	Vector up;
	up.x = 0; up.y = 0; up.z = 1.0f;
	Vector right;
	right.x = 1.0f; right.y = 0; right.z = 0;
	int decal = engine->vfunc1(m_unk38, *(int *)((char *)this + 0x40));
	if (decal)
		sub_100b42a0(m_v1, decal, right, up, 0.8f, 0.8f, 0.8f, m_unk3c);
}
// END FUNCTION

// FUNCTION: 0x100396e0 size=0x6
#include "C_TEGunshotDecal.h"
namespace lifted {
extern char g_1027ffac;
}
int C_TEGunshotDecal::vfunc9()
{
    return (int)&lifted::g_1027ffac;
}
// END FUNCTION

// FUNCTION: 0x100396f0 size=0x3
#include "C_TEGunshotDecal.h"
int C_TEGunshotDecal::vfunc8()
{
    return 0;
}
// END FUNCTION
