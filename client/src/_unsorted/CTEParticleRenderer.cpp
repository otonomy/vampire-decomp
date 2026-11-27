// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1003df80 size=0x1e
#include "CTEParticleRenderer.h"

// VC6 writes CTEParticleRenderer's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CTEParticleRenderer *pcd_emit_1003df80() { return new CTEParticleRenderer; }

// TARGET: ??_GCTEParticleRenderer@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1003e060 size=0x710
#include "CTEParticleRenderer.h"
#include "ConVar.h"
#include "VMatrix.h"
#include "engineclient.h"

extern VMatrix g_104e08d4;
extern int g_10281068[][3];
extern int g_10280fa8[][3];
extern int g_10281008[][3];
extern int g_102810b0[][3];

struct TEMeshBuilder
{
	int m_unk00[0xa8 / 4];
	float *m_pCurrPosition;	// 0xa8
	float *m_pCurrNormal;	// 0xac
	float *m_pCurrTexCoord[4];	// 0xb0
	unsigned char *m_pCurrColor;	// 0xc0

	void sub_100319d0(float x, float y, float z);	// Position3f
	void sub_10031a20(int stage, float s, float t);	// TexCoord2f
	void sub_100052c0(const unsigned char *rgba);	// Color4ubv
	void sub_10005230();	// AdvanceVertex

	void Position3f(float x, float y, float z)
	{
		float *pDst = m_pCurrPosition;
		*pDst++ = x;
		*pDst++ = y;
		*pDst = z;
	}
};

struct ParticleDraw
{
	TEMeshBuilder *m_pMeshBuilder;
	int m_unk04;
	float m_flTimeDelta;
};

struct StandardParticle_t
{
	void *m_pPrev;
	void *m_pNext;
	void *m_pSubTexture;
	Vector m_Pos;
	Vector m_Velocity;
	float m_Lifetime;
	unsigned char m_EffectData;
	unsigned short m_EffectDataWord;
	unsigned char m_Color[4];

	void SetColor(float r, float g, float b)
	{
		m_Color[0] = (unsigned char)(r * 255.9f);
		m_Color[1] = (unsigned char)(g * 255.9f);
		m_Color[2] = (unsigned char)(b * 255.9f);
	}
};

inline int RoundFloatToInt(float f)
{
	int nResult;
	__asm
	{
		fld f
		fistp nResult
	}
	return nResult;
}

inline void RenderParticle_ColorSize(ParticleDraw *pDraw, const Vector &pos, const Vector &color, const float alpha, const float size)
{
	if (alpha < 0.001f)
		return;

	TEMeshBuilder *pBuilder = pDraw->m_pMeshBuilder;
	if (!pBuilder)
		return;

	unsigned char ubColor[4];
	ubColor[0] = (unsigned char)RoundFloatToInt(color.x * 254.9f);
	ubColor[1] = (unsigned char)RoundFloatToInt(color.y * 254.9f);
	ubColor[2] = (unsigned char)RoundFloatToInt(color.z * 254.9f);
	ubColor[3] = (unsigned char)RoundFloatToInt(alpha * 254.9f);

	pBuilder->Position3f(pos.x - size, pos.y - size, pos.z);
	*(int *)pBuilder->m_pCurrColor = (((((ubColor[3] << 8) | ubColor[0]) << 8) | ubColor[1]) << 8) | ubColor[2];
	float *pDst = pBuilder->m_pCurrTexCoord[0];
	*pDst++ = 0;
	*pDst = 1.0f;
	pBuilder->sub_10005230();

	pBuilder->Position3f(pos.x - size, pos.y + size, pos.z);
	pBuilder->sub_100052c0(ubColor);
	pBuilder->sub_10031a20(0, 0, 0);
	pBuilder->sub_10005230();

	pBuilder->sub_100319d0(pos.x + size, pos.y + size, pos.z);
	pBuilder->sub_100052c0(ubColor);
	pBuilder->sub_10031a20(0, 1.0f, 0);
	pBuilder->sub_10005230();

	pBuilder->sub_100319d0(pos.x + size, pos.y - size, pos.z);
	pBuilder->sub_100052c0(ubColor);
	pBuilder->sub_10031a20(0, 1.0f, 1.0f);
	pBuilder->sub_10005230();
}

bool CTEParticleRenderer::vfunc3(StandardParticle_t *pParticle, ParticleDraw *pDraw, float &sortKey)
{
	pParticle->m_Lifetime -= pDraw->m_flTimeDelta;
	if (pParticle->m_Lifetime < 0)
		return false;

	float frametime = pDraw->m_flTimeDelta;
	float time3 = frametime * 15.0;
	float time2 = frametime * 10.0;
	float time1 = frametime * 5.0;
	float dvel = 4 * frametime;
	float grav = (g_104dfce4->vfunc1() ? 0.0f : g_104dfce4->m_fValue) * frametime * 0.05f;
	int i;
	const int *ramp;

	switch (pParticle->m_EffectData)
	{
	case 3:
		pParticle->m_EffectDataWord += (unsigned short)(time1 * 1024);
		i = pParticle->m_EffectDataWord >> 10;
		if (i >= 6)
			pParticle->m_Lifetime = -1;
		else
		{
			ramp = g_10281068[i];
			pParticle->SetColor(ramp[0] * (1.0f / 255.0f), ramp[1] * (1.0f / 255.0f), ramp[2] * (1.0f / 255.0f));
		}
		pParticle->m_Velocity[2] += grav;
		break;
	case 4:
		pParticle->m_EffectDataWord += (unsigned short)(time2 * 1024);
		i = pParticle->m_EffectDataWord >> 10;
		if (i >= 8)
			pParticle->m_Lifetime = -1;
		else
		{
			ramp = g_10280fa8[i];
			pParticle->SetColor(ramp[0] * (1.0f / 255.0f), ramp[1] * (1.0f / 255.0f), ramp[2] * (1.0f / 255.0f));
		}
		pParticle->m_Velocity = pParticle->m_Velocity + dvel * pParticle->m_Velocity;
		pParticle->m_Velocity.z -= grav;
		break;
	case 5:
		pParticle->m_EffectDataWord += (unsigned short)(time3 * 1024);
		i = pParticle->m_EffectDataWord >> 10;
		if (i >= 8)
			pParticle->m_Lifetime = -1;
		else
		{
			ramp = g_10281008[i];
			pParticle->SetColor(ramp[0] * (1.0f / 255.0f), ramp[1] * (1.0f / 255.0f), ramp[2] * (1.0f / 255.0f));
		}
		pParticle->m_Velocity = pParticle->m_Velocity - frametime * pParticle->m_Velocity;
		pParticle->m_Velocity.z -= grav;
		break;
	case 1:
		pParticle->m_Velocity.z -= grav * 20;
		break;
	case 9:
		pParticle->m_Velocity.z -= grav * 8;
		break;
	case 8:
		pParticle->m_Velocity.z -= grav * 4;
		break;
	case 2:
		pParticle->m_Velocity.z = grav;
		break;
	case 6:
	case 7:
		pParticle->m_EffectDataWord += (unsigned short)(time2 * 1024);
		i = pParticle->m_EffectDataWord >> 10;
		if (i >= 9)
			pParticle->m_EffectDataWord = i = 0;
		ramp = g_102810b0[i];
		pParticle->SetColor(ramp[0] * (1.0f / 255.0f), ramp[1] * (1.0f / 255.0f), ramp[2] * (1.0f / 255.0f));
		pParticle->m_Velocity[0] -= pParticle->m_Velocity[0] * (double)frametime * 0.5;
		pParticle->m_Velocity[1] -= pParticle->m_Velocity[1] * (double)frametime * 0.5;
		pParticle->m_Velocity.z -= grav * 5;
		if (enginerandom->RandomInt(0, 3))
		{
			pParticle->m_EffectData = 6;
			pParticle->m_Color[3] = 0;
		}
		else
		{
			pParticle->m_EffectData = 7;
			pParticle->m_Color[3] = 0xcc;
		}
		break;
	}

	Vector tPos;
	Vector &vOut = tPos;
	vOut.x = g_104e08d4.m[0][0] * pParticle->m_Pos.x + g_104e08d4.m[0][1] * pParticle->m_Pos.y + g_104e08d4.m[0][2] * pParticle->m_Pos.z + g_104e08d4.m[0][3];
	vOut.y = g_104e08d4.m[1][0] * pParticle->m_Pos.x + g_104e08d4.m[1][1] * pParticle->m_Pos.y + g_104e08d4.m[1][2] * pParticle->m_Pos.z + g_104e08d4.m[1][3];
	vOut.z = g_104e08d4.m[2][0] * pParticle->m_Pos.x + (g_104e08d4.m[2][1] * pParticle->m_Pos.y + g_104e08d4.m[2][2] * pParticle->m_Pos.z) + g_104e08d4.m[2][3];
	sortKey = tPos.z;

	Vector color(pParticle->m_Color[0] * (1.0f / 255.9f), pParticle->m_Color[1] * (1.0f / 255.9f), pParticle->m_Color[2] * (1.0f / 255.9f));
	RenderParticle_ColorSize(pDraw, tPos, color, pParticle->m_Color[3] * (1.0f / 255.9f), m_flParticleSize);

	pParticle->m_Pos = pParticle->m_Pos + frametime * pParticle->m_Velocity;
	return true;
}
// END FUNCTION
