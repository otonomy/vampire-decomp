// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101342e0 size=0x48
#include "utlvector.h"

struct SoundPatch_101342e0
{
	void sub_10133a20();
};

struct SoundCtl_101342e0
{
	char pad_0[0x0c];
	CUtlVector<SoundPatch_101342e0 *> m_soundList; // 0x0c..0x1f
	char pad_20[0x0c];
	int m_nField2c;                                // 0x2c

	void sub_101342e0();
};

void SoundCtl_101342e0::sub_101342e0()
{
	for (int i = m_soundList.Count() - 1; i >= 0; i--)
	{
		m_soundList[i]->sub_10133a20();
	}
	m_soundList.Purge();
	m_nField2c = 0;
}
// END FUNCTION

// FUNCTION: 0x101349b0 size=0x28
#include "CSoundControllerImp.h"
#include "CSoundList101340a0.h"
void CSoundControllerImp::vfunc5(void *pSound)
{
	if (pSound) {
		((SoundV_10133a20 *)pSound)->sub_10133a20();
		vfunc4(pSound);
		((CSoundList101340a0 *)this)->sub_101340a0((SoundV_10133a20 *)pSound);
	}
}
// END FUNCTION

// FUNCTION: 0x101349e0 size=0xc2
#include "CBaseEntityList.h"
#include "Pool.h"
#include "CBaseHandle.h"
#include "CBaseEntityList.h"

extern Pool g_105e5aac;

inline IHandleEntity *CBaseHandle::Get() const
{
	if (IsValid())
	{
		const CBaseEntityListEntry *pInfo = &g_pEntityList->m_EntPtrArray[GetEntryIndex()];
		if (pInfo->m_SerialNumber == GetSerialNumber())
			return (IHandleEntity *)pInfo->m_pEntity;
	}
	return 0;
}

inline CBaseHandle GetNetworkableHandle(int nEntIndex)
{
	if (g_pEntityList->m_EntPtrArray[nEntIndex].m_pEntity)
		return CBaseHandle(nEntIndex, g_pEntityList->m_EntPtrArray[nEntIndex].m_SerialNumber);
	else
		return CBaseHandle();
}

struct CSoundEnvelope
{
	float m_current;
	float m_dest;
	float m_delta;
	bool m_active;

	CSoundEnvelope()
	{
		m_current = 0.0f;
		m_dest = 0.0f;
		m_delta = 0.0f;
		m_active = false;
	}
};

struct CUnknown101bcef0
{
	char m_pad[0x28];
	void sub_101347f0();
	CUnknown101bcef0() { sub_101347f0(); }
};

struct CSoundPatch
{
	CSoundEnvelope m_pitch;
	CSoundEnvelope m_volume;
	int m_pad20[3];
	const char *m_iszSoundName;
	CBaseHandle m_hEntity;
	int m_pad34[4];
	CUnknown101bcef0 m_filter;

	CSoundPatch()
	{
		m_iszSoundName = 0;
	}

	static void *operator new(unsigned int nSize)
	{
		return g_105e5aac.sub_1010e3e0(nSize);
	}

	void sub_101337a0(void *filter, IHandleEntity *pEnt, int channel, const char *pSoundName, int soundlevel);
};

// TARGET: ?sub_101349e0@CUnknown101349e0@@QAEPAUCSoundPatch@@PAXHPBD@Z
struct CUnknown101349e0
{
	CSoundPatch *sub_101349e0(void *filter, int nEntIndex, const char *pSoundName);
};

CSoundPatch *CUnknown101349e0::sub_101349e0(void *filter, int nEntIndex, const char *pSoundName)
{
	CSoundPatch *pSound = new CSoundPatch;
	CBaseHandle hEnt = (nEntIndex != -1) ? GetNetworkableHandle(nEntIndex) : CBaseHandle(0, 0);
	pSound->sub_101337a0(filter, hEnt.Get(), 0, pSoundName, 75);
	return pSound;
}
// END FUNCTION

// FUNCTION: 0x10134ba0 size=0xc9
#include "CSoundControllerImp.h"
#include "Pool.h"
#include "CBaseHandle.h"
#include "CBaseEntityList.h"

extern Pool g_105e5aac;

inline IHandleEntity *CBaseHandle::Get() const
{
	if (IsValid())
	{
		const CBaseEntityListEntry *pInfo = &g_pEntityList->m_EntPtrArray[GetEntryIndex()];
		if (pInfo->m_SerialNumber == GetSerialNumber())
			return (IHandleEntity *)pInfo->m_pEntity;
	}
	return 0;
}

inline CBaseHandle GetNetworkableHandle(int nEntIndex)
{
	if (g_pEntityList->m_EntPtrArray[nEntIndex].m_pEntity)
		return CBaseHandle(nEntIndex, g_pEntityList->m_EntPtrArray[nEntIndex].m_SerialNumber);
	else
		return CBaseHandle();
}

struct CSoundEnvelope
{
	float m_current;
	float m_dest;
	float m_delta;
	bool m_active;

	CSoundEnvelope()
	{
		m_current = 0.0f;
		m_dest = 0.0f;
		m_delta = 0.0f;
		m_active = false;
	}
};

struct CUnknown101bcef0
{
	char m_pad[0x28];
	void sub_101347f0();
	CUnknown101bcef0() { sub_101347f0(); }
};

struct CSoundPatch
{
	CSoundEnvelope m_pitch;
	CSoundEnvelope m_volume;
	int m_pad20[3];
	const char *m_iszSoundName;
	CBaseHandle m_hEntity;
	int m_pad34[4];
	CUnknown101bcef0 m_filter;

	CSoundPatch()
	{
		m_iszSoundName = 0;
	}

	static void *operator new(unsigned int nSize)
	{
		return g_105e5aac.sub_1010e3e0(nSize);
	}

	void sub_101337a0(void *filter, IHandleEntity *pEnt, int channel, const char *pSoundName, int soundlevel);
};

// TARGET: CSoundControllerImp::vfunc6
CSoundPatch *CSoundControllerImp::vfunc6(void *filter, int nEntIndex, int channel, const char *pSoundName, int soundlevel)
{
	CSoundPatch *pSound = new CSoundPatch;
	CBaseHandle hEnt = nEntIndex != -1 ? GetNetworkableHandle(nEntIndex) : CBaseHandle(0, 0);
	pSound->sub_101337a0(filter, hEnt.Get(), channel, pSoundName, soundlevel);
	return pSound;
}
// END FUNCTION

// FUNCTION: 0x10134c70 size=0x75
#include "CSoundControllerImp.h"

struct ControllerV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4();
	virtual void vfunc5(void *pSound);
};
struct VecV
{
	int m_pMemory;	// 0x00
	int m_alloc;	// 0x04
	int m_grow;		// 0x08
	int m_size;		// 0x0c
	int m_elements;	// 0x10
	int sub_1007db70();
	void sub_10039e60();
};
struct SoundView
{
	char m_pad00[0x44];
	void *m_vt44;
	char m_pad48[0x4c - 0x48];
	VecV m_vec;
};
struct PoolV
{
	void sub_1010e440(void *);
};
extern PoolV g_105e5aac;
extern char g_10226214[];
extern "C" __declspec(dllimport) void Plat_Free(void *);

// TARGET: CSoundControllerImp::vfunc9
void CSoundControllerImp::vfunc9(void *pSound)
{
	if (!pSound)
		return;
	SoundView *p = (SoundView *)pSound;
	((ControllerV *)this)->vfunc5(pSound);
	VecV *pVec = &p->m_vec;
	for (int i = pVec->m_size - 1; i >= 0; i--)
		pVec->sub_1007db70();
	pVec->m_size = 0;
	pVec->sub_10039e60();
	pVec->m_elements = pVec->m_pMemory;
	if (pVec->m_grow != -1)
	{
		if (pVec->m_pMemory)
		{
			Plat_Free((void *)pVec->m_pMemory);
			pVec->m_pMemory = 0;
		}
		pVec->m_alloc = 0;
	}
	p->m_vt44 = (void *)g_10226214;
	g_105e5aac.sub_1010e440(pSound);
}
// END FUNCTION

// FUNCTION: 0x10134d30 size=0xc
struct CSndView101339f0 { void sub_101339f0(); };
// TARGET: sub_10134d30
void __stdcall sub_10134d30(CSndView101339f0 *p) { p->sub_101339f0(); }
// END FUNCTION

// FUNCTION: 0x10134d40 size=0xc
void __fastcall sub_10133a00(void *self);
// TARGET: sub_10134d40
void __stdcall sub_10134d40(void *p)
{
	sub_10133a00(p);
}
// END FUNCTION

// FUNCTION: 0x10134d70 size=0x101
#include "engineclient.h"
#include "CSoundControllerImp.h"
#include "Tier1.h"


// TARGET: CSoundControllerImp::vfunc16
float CSoundControllerImp::vfunc16(void *pSound, int soundCommand, envelopePoint_t *points, int numPoints)
{
    float amplitude = 0.0f;
    float duration = 0.0f;
    float totalDuration = 0.0f;

    vfunc4(pSound);

    for (int i = 0; i < numPoints; i++) {
        if (points[i].amplitudeMin != -1.0f || points[i].amplitudeMax != -1.0f) {
            amplitude = enginerandom->RandomFloat(points[i].amplitudeMin, points[i].amplitudeMax);
        } else if (i == 0) {
            g_101e3108("Invalid starting amplitude value in envelope!  (Cannot be -1)\n");
        }

        if (points[i].durationMin != -1.0f || points[i].durationMax != -1.0f) {
            duration = enginerandom->RandomFloat(points[i].durationMin, points[i].durationMax);
        } else if (i == 0) {
            g_101e3108("Invalid starting duration value in envelope! (Cannot be -1)\n");
        }

        vfunc3(pSound, totalDuration, soundCommand, duration, amplitude);
        totalDuration += duration;
    }
    return totalDuration;
}
// END FUNCTION

// FUNCTION: 0x10134e80 size=0x1f
struct Pair_10134e80 { int a, b; };
struct SC_10134e80
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(int, int, Pair_10134e80);
	void sub_10134e80(int, int, Pair_10134e80 *);
};
void SC_10134e80::sub_10134e80(int a, int b, Pair_10134e80 *c)
{
	v16(a, b, *c);
}
// END FUNCTION

// FUNCTION: 0x10134ea0 size=0x24
struct SndItem { void sub_10133e50(int a); };
struct VSndCtl { int m0, m4, m8; SndItem **m_pData; int m10, m14; int m_n; void sub_10134ea0(int a); };
// TARGET: ?sub_10134ea0@VSndCtl@@QAEXH@Z
void VSndCtl::sub_10134ea0(int a) { for (int i = m_n - 1; i >= 0; i--) m_pData[i]->sub_10133e50(a); }
// END FUNCTION

// FUNCTION: 0x10134ed0 size=0x26
#include "CSoundControllerImp.h"

class SP_10133d70
{
public:
	int m_unk00, m_unk04, m_unk08, m_unk0c, m_unk10, m_unk14, m_unk18, m_unk1c;
	int m_unk20, m_unk24, m_unk28, m_unk2c, m_unk30, m_unk34, m_unk38;
	int m_bIsPlaying;	// 0x3c
	void sub_10133d70();
};

// TARGET: CSoundControllerImp::vfunc18
void CSoundControllerImp::vfunc18()
{
	for ( int i = m_nSoundCount - 1; i >= 0; --i )
	{
		SP_10133d70 *pSound = (SP_10133d70 *)m_ppSounds[i];
		if ( pSound && pSound->m_bIsPlaying )
			pSound->sub_10133d70();
	}
}
// END FUNCTION
