// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10196530 size=0x460
#include "CViewEffects.h"
#include "ScopeTrace.h"
#include "engineclient.h"
#include <math.h>
#include <string.h>

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

void CViewEffects::vfunc6()
{
	ScopeTrace trace("CViewEffects::CalcShake", g_102de300, g_102de300);
	float fraction, freq;
	int i;

	if (m_nState == 2)
	{
		if (!(m_flWaveTime <= 0.0f || m_flWaveAmplitude <= 0.0f || m_flWaveDuration <= 0.0f || m_flWaveFrequency <= 0.0f))
		{
			float phase = max(0.01, engine->Time(0) - m_flWaveTime) / m_flWaveDuration;
			m_vecShakeOffset.x = 0;
			m_vecShakeOffset.y = 0;
			m_vecShakeOffset.z = sin(phase) * m_flWaveAmplitude;
			m_flShakeAngle = cos(phase) * m_flWaveFrequency;
		}
		else
		{
			memset(&m_nState, 0, 0x38);
		}
	}

	switch (m_Shake.type)
	{
	case 0:
		if (m_Shake.time == 0.0f)
			return;
		if (engine->Time(0) > m_Shake.time || m_Shake.duration <= 0.0f || m_Shake.amplitude <= 0.0f || m_Shake.frequency <= 0.0f)
		{
			memset(&m_Shake, 0, sizeof(m_Shake));
			return;
		}
		{
			float frametime = engine->vfunc41(0);
			if (engine->Time(0) > m_Shake.nextShake)
			{
				m_Shake.nextShake = engine->Time(0) + 1.0f / m_Shake.frequency;
				for (i = 0; i < 3; i++)
					m_Shake.offset[i] = enginerandom->RandomFloat(-m_Shake.amplitude, m_Shake.amplitude);
				m_Shake.angle = enginerandom->RandomFloat(-m_Shake.amplitude * 0.25, m_Shake.amplitude * 0.25);
			}
			fraction = (m_Shake.time - engine->Time(0)) / m_Shake.duration;
			if (fraction)
				freq = m_Shake.frequency / fraction;
			else
				freq = 0;
			fraction *= fraction;
			fraction = fraction * sin(engine->Time(0) * freq);
			for (i = 0; i < 3; i++)
				m_Shake.appliedOffset[i] = m_Shake.offset[i] * fraction;
			m_Shake.appliedAngle = m_Shake.angle * fraction;
			m_Shake.amplitude -= (frametime / (m_Shake.frequency * m_Shake.duration)) * m_Shake.amplitude;
		}
		break;
	case 1:
		if (m_Shake.time == 0.0f)
			return;
		if (engine->Time(0) > m_Shake.time || m_Shake.duration <= 0.0f || m_Shake.amplitude <= 0.0f || m_Shake.frequency <= 0.0f)
		{
			memset(&m_Shake, 0, sizeof(m_Shake));
			return;
		}
		{
			float frametime = engine->vfunc41(0);
			if (engine->Time(0) > m_Shake.nextShake)
			{
				m_Shake.nextShake = engine->Time(0) + 1.0f / m_Shake.frequency;
				for (i = 0; i < 3; i++)
					m_Shake.offset[i] = 0;
				m_Shake.angle = enginerandom->RandomFloat(-m_Shake.amplitude * 0.25, m_Shake.amplitude * 0.25);
			}
			fraction = (m_Shake.time - engine->Time(0)) / m_Shake.duration;
			if (fraction)
				freq = m_Shake.frequency / fraction;
			else
				freq = 0;
			fraction *= fraction;
			fraction = fraction * sin(engine->Time(0) * freq);
			for (i = 0; i < 3; i++)
				m_Shake.appliedOffset[i] = m_Shake.offset[i] * fraction;
			m_Shake.appliedAngle = m_Shake.angle * fraction;
			m_Shake.amplitude -= (frametime / (m_Shake.frequency * m_Shake.duration)) * m_Shake.amplitude;
		}
		break;
	default:
		memcpy(&m_nState, &m_Shake, sizeof(m_Shake));
		memset(&m_Shake, 0, sizeof(m_Shake));
		break;
	}
}
// END FUNCTION

// FUNCTION: 0x10196990 size=0x1ff
#include "CViewEffects.h"
#include "ScopeTrace.h"
extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
struct S56 { int d[14]; };
extern float g_101e34f0;
void sub_10109340(const Vector *v, QAngle *a);
void sub_10108fd0(const Vector *start, float scale, const Vector *dir, Vector *dest);
void CViewEffects::vfunc7(Vector &origin, QAngle &angles, float factor)
{
	ScopeTrace trace("CViewEffects::ApplyShake", g_102de300);
	if (vfunc12()) {
		QAngle saved = angles;
		*(Vector *)&angles += m_vecHolyLight;
		if (m_flHolyLightStrength > g_101e34f0) {
			Vector v(-17.0f, -97.0f, 10.0f);
			QAngle ang;
			sub_10109340(&v, &ang);
			for (int i = 0; i < 3; i++) {
				int t = (int)((ang[i] - angles[i] + 180.0f) * 182.04445f) & 0xffff;
				angles[i] += ((float)t * 0.005493164f - 180.0f) * m_flHolyLightStrength;
				m_vecHolyLight[i] = angles[i] - saved[i];
			}
			m_flHolyLightStrength = 0.0f;
		}
	}
	switch (m_unk18) {
	case 0:
		sub_10108fd0(&origin, factor, (Vector *)&m_unk40, &origin);
		angles.z += factor * *(float *)&m_unk4c;
		break;
	case 1:
		sub_10108fd0(&origin, factor, (Vector *)&m_unk40, &origin);
		angles.x += factor * *(float *)&m_unk4c;
		break;
	default:
		*(S56 *)&m_nState = *(S56 *)&m_unk18;
		memset(&m_unk18, 0, sizeof(S56));
		break;
	}
}
// END FUNCTION

// FUNCTION: 0x10196b90 size=0xe7
#include "CViewEffects.h"

static inline float anglemod(float a)
{
	a = (360.0f / 65536.0f) * ((int)(a * (65536.0f / 360.0f)) & 65535);
	return a;
}

// TARGET: CViewEffects::vfunc8
void CViewEffects::vfunc8(Vector &origin, QAngle &angles, float factor)
{
	if (m_nState != 2)
		return;

	bool bNeg = false;
	float a = anglemod(angles.y + m_flAppliedAngle);
	if (a > 180.0f)
	{
		a = (float)(180.0 - (a - 180.0f));
		bNeg = true;
	}
	a /= 90.0f;
	if (a > 1.0)
	{
		a = (float)(1.0 - (a - 1.0));
	}
	if (bNeg)
	{
		a = -a;
	}
	m_flAppliedAngle = a * m_flShakeAngle * factor;
	m_vecAppliedOffset = m_vecShakeOffset * factor;
	angles.z += m_flAppliedAngle;
	VectorAdd(m_vecAppliedOffset, origin, origin);
}
// END FUNCTION

// FUNCTION: 0x10196c80 size=0xe5
#include "CViewEffects.h"

void CViewEffects::vfunc9(Vector &origin, QAngle &angles, float factor)
{
	if (m_nState != 2)
		return;

	bool bFlip = false;
	float a = angles[1] + m_flAppliedAngle;
	int i = (int)(a * 182.04445f) & 0xffff;
	a = (float)i * 0.005493164f;
	if (a > 180.0f)
	{
		a -= 180.0f;
		bFlip = true;
		a = 180.0 - a;
	}
	a *= 0.011111111f;
	if (a > 1.0)
	{
		a -= 1.0;
		a = 1.0 - a;
	}
	if (bFlip)
		a = -a;
	m_flAppliedAngle = a * m_flShakeAngle * factor;
	m_vecAppliedOffset = m_vecShakeOffset * factor;
	angles.z = 0;
	origin -= m_vecAppliedOffset;
}
// END FUNCTION

// FUNCTION: 0x10197190 size=0x323
#include "CViewEffects.h"
#include "ScopeTrace.h"
#include "engineclient.h"

struct screenfade_t
{
	float Speed;	// 0x00: alpha change per second
	float End;	// 0x04: when the fade ends
	float Reset;	// 0x08: when it is removed
	unsigned char r, g, b, alpha;	// 0x0c
	int Flags;	// 0x10
};

struct ScreenFade_t	// the message a fade starts from
{
	unsigned short duration;
	unsigned short holdTime;
	short fadeFlags;
	unsigned char r, g, b, a;
};

struct FadeListView	// m_FadeList, a CUtlVector<screenfade_t *> at +4
{
	screenfade_t **m_pMemory;
	int m_nAllocationCount;
	int m_nGrowSize;
	int m_Size;
	screenfade_t **m_pElements;

	void sub_101979e0(int elem, int num);	// ShiftElementsLeft

	screenfade_t *&operator[](int i) { return m_pMemory[i]; }
	int Count() const { return m_Size; }
	int Find(screenfade_t *const &src) const
	{
		for (int i = 0; i < Count(); ++i)
		{
			if (m_pMemory[i] == src)
				return i;
		}
		return -1;
	}
	void Remove(int elem)
	{
		sub_101979e0(elem, 1);
		--m_Size;
	}
	bool FindAndRemove(screenfade_t *const &src)
	{
		int elem = Find(src);
		if (elem != -1)
		{
			Remove(elem);
			return true;
		}
		return false;
	}
};

#define m_FadeList (*(FadeListView *)&m_unk04)

extern void (*g_106187fc)(int);	// s_pfnFadeDoneCallback
extern int g_10618700;	// s_nCallbackParameter

extern "C" void *__cdecl memset(void *, int, unsigned int);
#pragma intrinsic(memset)

// FadeCalculate
void CViewEffects::vfunc16()
{
	ScopeTrace st("CViewEffects::FadeCalculate", g_102de300, g_102de300);

	int i;
	int iSize = m_FadeList.Count();
	for (i = iSize - 1; i >= 0; i--)
	{
		screenfade_t *pFade = m_FadeList[i];

		if (pFade->Flags & 8)
			pFade->Reset = engine->Time(0) + 0.1;

		if (engine->Time(0) > pFade->Reset && engine->Time(0) > pFade->End)
		{
			if (pFade->Flags & 0x20)
			{
				pFade->Flags = (pFade->Flags & ~0x22) | 1;
				pFade->Reset = engine->Time(0);
				pFade->Speed = -pFade->Speed;
				if (pFade->Speed != 0.0f)
				{
					pFade->End = pFade->alpha / pFade->Speed;
					pFade->End += engine->Time(0);
				}
				continue;
			}

			if (g_106187fc)
			{
				g_106187fc(g_10618700);
				g_106187fc = 0;
				g_10618700 = 0;
			}

			if (pFade->Flags & 0x40)
			{
				engine->ClientCmd("disconnect");
				ScreenFade_t sf;
				memset(&sf, 0, sizeof(sf));
				sf.duration = 0xa00;
				sf.r = 0;
				sf.g = 0;
				sf.b = 0;
				sf.a = 255;
				sf.holdTime = 0x200;
				sf.fadeFlags = 1;
				vfunc4(0, 0, &sf);
			}

			m_FadeList.FindAndRemove(pFade);
			delete pFade;
		}
	}

	*(unsigned char *)&m_unk98 = 0;
	m_unk88 = m_unk8c = m_unk90 = m_unk94 = 0;

	for (i = 0; i < m_unk10; i++)
	{
		screenfade_t *pFade = ((screenfade_t **)m_unk04)[i];

		m_unk88 += pFade->r;
		m_unk8c += pFade->g;
		m_unk90 += pFade->b;

		int iFadeAlpha;
		if (pFade->Flags & 3)
		{
			iFadeAlpha = pFade->Speed * (pFade->End - engine->Time(0));
			if (pFade->Flags & 2)
				iFadeAlpha += pFade->alpha;
			iFadeAlpha = iFadeAlpha < pFade->alpha ? iFadeAlpha : pFade->alpha;
			iFadeAlpha = 0 > iFadeAlpha ? 0 : iFadeAlpha;
		}
		else
		{
			iFadeAlpha = pFade->alpha;
		}

		if (iFadeAlpha > m_unk94)
			m_unk94 = iFadeAlpha;

		if (pFade->Flags & 4)
			*(unsigned char *)&m_unk98 = 1;
	}

	if (m_unk10)
	{
		m_unk88 /= m_unk10;
		m_unk8c /= m_unk10;
		m_unk90 /= m_unk10;
	}
}
// END FUNCTION

// FUNCTION: 0x101974c0 size=0xbe
#include "CViewEffects.h"
#include "ScopeTrace.h"
extern "C" void *__cdecl memmove(void *, const void *, unsigned int);
struct FadeV101974c0 { int pad[4]; int flags; };
struct VecV101974c0 {
    FadeV101974c0 **m_pMemory;
    int m_allocationCount;
    int m_growSize;
    int m_size;
    FadeV101974c0 **m_pElements;
    int Find(FadeV101974c0 *const &src)
    {
        for (int i = 0; i < m_size; i++)
            if (m_pMemory[i] == src)
                return i;
        return -1;
    }
    void Remove(int elem)
    {
        int n = m_size - elem - 1;
        if (n > 0)
            memmove(&m_pMemory[elem], &m_pMemory[elem + 1], n * 4);
        m_size--;
    }
    void FindAndRemove(FadeV101974c0 *const &src)
    {
        int elem = Find(src);
        if (elem != -1)
            Remove(elem);
    }
    FadeV101974c0 *&operator[](int i) { return m_pElements[i]; }
};
struct ViewV101974c0 { int pad0; VecV101974c0 m_Fades; };

void CViewEffects::vfunc5()
{
    ScopeTrace scope("CViewEffects::ClearPermanentFades", g_102de300);
    ViewV101974c0 *v = (ViewV101974c0 *)this;
    for (int i = v->m_Fades.m_size - 1; i >= 0; i--)
    {
        FadeV101974c0 *pFade = v->m_Fades.m_pMemory[i];
        if (pFade->flags & 8)
        {
            v->m_Fades.FindAndRemove(pFade);
            delete pFade;
        }
    }
}
// END FUNCTION

// FUNCTION: 0x10197580 size=0xa5
#include "CViewEffects.h"
#include "ScopeTrace.h"

struct CUtlVectorPtrView
{
	void **m_pMemory;
	int m_nAllocationCount;
	int m_nGrowSize;
	int m_size;
	void **m_pElements;
};
extern void (__cdecl *g_101e30fc)(void *);

// TARGET: CViewEffects::vfunc17
void CViewEffects::vfunc17()
{
	ScopeTrace trace("CViewEffects::ClearAllFades", g_102de300);
	CUtlVectorPtrView *v = (CUtlVectorPtrView *)((char *)this + 4);
	for (int i = v->m_size - 1; i >= 0; i--)
		::operator delete(v->m_pMemory[i]);
	v->m_size = 0;
	if (v->m_nGrowSize != -1)
	{
		if (v->m_pMemory)
		{
			g_101e30fc(v->m_pMemory);
			v->m_pMemory = 0;
		}
		v->m_nAllocationCount = 0;
	}
	v->m_pElements = v->m_pMemory;
	vfunc11();
}
// END FUNCTION

// FUNCTION: 0x10197630 size=0x9f
#include "CViewEffects.h"
#include "ScopeTrace.h"
// TARGET: CViewEffects::vfunc2
void CViewEffects::vfunc2(int unused, unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *a, unsigned char *speed)
{
	ScopeTrace trace("CViewEffects::GetFadeParams", g_102de300);
	vfunc16();
	*r = *(unsigned char *)&m_unk88;
	*g = *(unsigned char *)&m_unk8c;
	*b = *(unsigned char *)&m_unk90;
	*a = *(unsigned char *)&m_unk94;
	*speed = *(unsigned char *)&m_unk98;
}
// END FUNCTION

// FUNCTION: 0x101976d0 size=0x5f
#include "CViewEffects.h"
#include "ScopeTrace.h"

// TARGET: CViewEffects::vfunc10
void CViewEffects::vfunc10()
{
	ScopeTrace trace("CViewEffects::StartHolyLight", g_102de300);
	*(char *)((char *)this + 0x99) = 1;
}
// END FUNCTION

// FUNCTION: 0x10197730 size=0x64
#include "CViewEffects.h"
#include "ScopeTrace.h"

// TARGET: CViewEffects::vfunc11
void CViewEffects::vfunc11()
{
    ScopeTrace trace("CViewEffects::EndHolyLight", g_102de300);
    *((char *)this + 0x99) = 0;
    vfunc15();
}
// END FUNCTION

// FUNCTION: 0x101977a0 size=0x5f
#include "CViewEffects.h"
#include "ScopeTrace.h"

// TARGET: CViewEffects::sub_101977a0
bool CViewEffects::sub_101977a0()
{
	ScopeTrace trace("CViewEffects::IsHolyLightActive", g_102de300);
	return *(bool *)((char *)this + 0x99);
}
// END FUNCTION

// FUNCTION: 0x10197800 size=0xb9
#include "engineclient.h"
#include "CViewEffects.h"
#include "CGodLight.h"
#include "ScopeTrace.h"
void CViewEffects::vfunc13()
{
	ScopeTrace t("CViewEffects::RenderHolyLightBox", g_102de300);
	render->vfunc47("holylight", 1.0f, 1.0f, 1.0f);
	static CGodLight s_light;
	s_light.vfunc1();
	s_light.vfunc3();
}
// END FUNCTION

// FUNCTION: 0x101978d0 size=0x72
#include "CViewEffects.h"
#include "ScopeTrace.h"

void CViewEffects::vfunc14(float flStrength)
{
    ScopeTrace trace("CViewEffects::PullTowardsHolyLight", "", "");
    if (m_flHolyLightStrength < flStrength)
        m_flHolyLightStrength = flStrength;
}
// END FUNCTION

// FUNCTION: 0x10197950 size=0x85
#include "CViewEffects.h"
#include "ScopeTrace.h"
extern Vector g_104d5190;
void CViewEffects::vfunc15()
{
	ScopeTrace trace("CViewEffects::ClearHolyLightPull", g_102de300);
	m_flHolyLightStrength = 0;
	m_vecHolyLight = g_104d5190;
}
// END FUNCTION
