// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100b63d0 size=0x6
#include "C_EntityFlame.h"
namespace lifted {
extern char g_102b39a0;
}
int C_EntityFlame::vfunc16()
{
    return (int)&lifted::g_102b39a0;
}
// END FUNCTION

// FUNCTION: 0x100b63e0 size=0x3
#include "C_EntityFlame.h"
int C_EntityFlame::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100b65a0 size=0x67
#include "C_EntityFlame.h"
C_EntityFlame::C_EntityFlame() : m_flA(-1.0f), m_nB(0)
{
	m_flSize = 4.0f;
	m_Effect = 0;
}
// END FUNCTION

// FUNCTION: 0x100b6610 size=0x1e
#include "C_EntityFlame.h"

// VC6 writes C_EntityFlame's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_EntityFlame *pcd_emit_100b6610(const C_EntityFlame &other) { return new C_EntityFlame(other); }

// TARGET: ??_GC_EntityFlame@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100b6630 size=0x3c
#include "C_EntityFlame.h"
// TARGET: ??1C_EntityFlame@@UAE@XZ
C_EntityFlame::~C_EntityFlame()
{
}
// END FUNCTION

// FUNCTION: 0x100b6740 size=0x273
#include "engineclient.h"
#include <stdlib.h>
#include "C_EntityFlame.h"
#include "Vector.h"



struct SimpleParticle_100b6740
{
	Vector m_Pos;
	void *m_pNext;
	void *m_pPrev;
	int m_nUnk14;
	Vector m_vecVelocity;
	float m_flRoll;
	float m_flDieTime;
	float m_flLifetime;
	unsigned char m_uchColor[3];
	unsigned char m_uchStartAlpha;
	unsigned char m_uchEndAlpha;
	unsigned char m_uchStartSize;
	unsigned char m_uchEndSize;
	unsigned char m_uchPad;
	float m_flRollDelta;
};

struct CEmitter_100b6740
{
	void sub_10118080(const Vector &origin);
	SimpleParticle_100b6740 *sub_101180c0(int particleSize, unsigned char hMaterial, const Vector &pos);
};

struct SmartEmitterPtr_100b6740
{
	CEmitter_100b6740 *m_p;
	inline CEmitter_100b6740 *operator->() { return m_p; }
};

struct TimedEvent_100b6740
{
	float m_flTimeBetweenEvents;
	float m_flNextEvent;

	inline bool NextEvent(float &curDelta)
	{
		if (curDelta >= m_flNextEvent)
		{
			curDelta -= m_flNextEvent;
			m_flNextEvent = m_flTimeBetweenEvents;
			return true;
		}
		else
		{
			m_flNextEvent -= curDelta;
			return false;
		}
	}
};


inline void VectorRandom_100b6740(Vector &v, float minVal, float maxVal)
{
	float scale = (maxVal - minVal) * (1.0f / (float)RAND_MAX);
	v.x = minVal + (float)rand() * scale;
	v.y = minVal + (float)rand() * scale;
	v.z = minVal + (float)rand() * scale;
}

void C_EntityFlame::vfunc37()
{
	SmartEmitterPtr_100b6740 &pEmitter = *(SmartEmitterPtr_100b6740 *)&m_Effect;
	pEmitter->sub_10118080(GetAbsOrigin());

	float tempDelta = engine->vfunc41(0);
	TimedEvent_100b6740 &event = *(TimedEvent_100b6740 *)((char *)this + 0x418);
	float &flSize = *(float *)((char *)this + 0x410);
	unsigned char *hMaterials = (unsigned char *)((char *)this + 0x420);

	while (event.NextEvent(tempDelta))
	{
		Vector offset;
		VectorRandom_100b6740(offset, -flSize, flSize);
		Vector pos = offset + GetAbsOrigin();

		SimpleParticle_100b6740 *pParticle = pEmitter->sub_101180c0(
			sizeof(SimpleParticle_100b6740),
			hMaterials[enginerandom->RandomInt(0, 4)],
			pos);

		if (pParticle)
		{
			pParticle->m_flDieTime = 0.4f;
			pParticle->m_flLifetime = 0.0f;
			pParticle->m_flRoll = (float)enginerandom->RandomInt(0, 360);
			pParticle->m_flRollDelta = enginerandom->RandomFloat(-2.0f, 2.0f);
			pParticle->m_uchStartSize = (unsigned char)enginerandom->RandomInt(4, 6);
			pParticle->m_uchEndSize = (unsigned char)enginerandom->RandomInt(12, 16);
			pParticle->m_uchStartAlpha = 255;
			pParticle->m_uchEndAlpha = 0;
			pParticle->m_uchColor[0] = 255;
			pParticle->m_uchColor[1] = 255;
			pParticle->m_uchColor[2] = 255;

			Vector dir;
			dir.x = enginerandom->RandomFloat(-1.0f, 1.0f);
			dir.y = enginerandom->RandomFloat(-1.0f, 1.0f);
			dir.z = enginerandom->RandomFloat(0.5f, 1.0f);

			pParticle->m_vecVelocity = dir * (float)enginerandom->RandomInt(4, 32);
			pParticle->m_vecVelocity.z = (float)enginerandom->RandomInt(32, 64);
		}
	}
}
// END FUNCTION
