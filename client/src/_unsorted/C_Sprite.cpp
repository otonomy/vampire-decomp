// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100b54b0 size=0x33
#include "C_Sprite.h"
C_Sprite *pcd_emit_100b54b0() { return new C_Sprite; }
// TARGET: ??_GC_Sprite@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10135d70 size=0x6
extern int g_102c5b5c;

#include "C_Sprite.h"

// TARGET: C_Sprite::vfunc17
int C_Sprite::vfunc17()
{
	return (int)&g_102c5b5c;
}
// END FUNCTION

// FUNCTION: 0x10135d80 size=0x6
#include "C_Sprite.h"

// TARGET: C_Sprite::vfunc16
int C_Sprite::vfunc16()
{
	return (int)"C_Sprite";
}
// END FUNCTION

// FUNCTION: 0x10136660 size=0x86
#include "engineclient.h"
#include "C_Sprite.h"
// TARGET: C_Sprite::vfunc121
float C_Sprite::vfunc121()
{
	float *f = (float *)this;
	if (f[0x448 / 4] != 0.0f)
	{
		double end = f[0x45c / 4] + f[0x448 / 4];
		if (!(engine->Time(0) > end))
			return (engine->Time(0) - f[0x45c / 4]) / f[0x448 / 4] * (f[0x458 / 4] - f[0x454 / 4]) + f[0x454 / 4];
	}
	return f[0x444 / 4];
}
// END FUNCTION

// FUNCTION: 0x101366f0 size=0x99
#include "C_Sprite.h"
#define D8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
struct IEng136 {
	D8(a) D8(b) D8(c) D8(d)
	virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3(); virtual void e4(); virtual void e5(); virtual void e6();
	virtual double Time(int unused);
};
extern IEng136 *g_104a57d4;
struct SprV136 { char pad[0x43c]; int m43c; float m440; char pad2[0x460 - 0x444]; int m460; int m464; float m468; };
int C_Sprite::vfunc122()
{
	SprV136 *s = (SprV136 *)this;
	if (s->m440 != 0.0f) {
		double end = s->m468 + s->m440;
		if (!(g_104a57d4->Time(0) > end)) {
			double frac = (g_104a57d4->Time(0) - s->m468) / s->m440;
			return (int)((s->m464 - s->m460) * frac + s->m460);
		}
	}
	return s->m43c;
}
// END FUNCTION

// FUNCTION: 0x10136970 size=0x2d5
#include "C_Sprite.h"
#include "CSpriteHandle.h"
#include "engineclient.h"
#include <math.h>
#include <float.h>

void sub_101090a0(const QAngle &angles, Vector *forward, Vector *right, Vector *up);

#define SV1(n) virtual void v##n();
#define SV10(p) SV1(p##0) SV1(p##1) SV1(p##2) SV1(p##3) SV1(p##4) SV1(p##5) SV1(p##6) SV1(p##7) SV1(p##8) SV1(p##9)
struct C_SpriteScaleView	// C_Sprite's primary vtable: slot 121 is the render scale
{
	SV10(0) SV10(1) SV10(2) SV10(3) SV10(4) SV10(5) SV10(6) SV10(7) SV10(8) SV10(9)
	SV10(10) SV10(11) SV1(120)
	virtual float GetRenderScale();
};

#define max_L(a, b) (((a) > (b)) ? (a) : (b))

void C_Sprite::GetRenderBounds(Vector &vecMins, Vector &vecMaxs)
{
	CSpriteHandle *pSprite = modelinfo->vfunc7(GetModel());
	if (!pSprite)
	{
		vecMins.Init();
		vecMaxs.Init();
		return;
	}

	float flScale = ((C_SpriteScaleView *)this)->GetRenderScale();
	int nOrientation = pSprite->sub_10136fc0();
	float flRight = pSprite->GetRight() * flScale;
	float flLeft = pSprite->GetLeft() * flScale;
	float flUp = pSprite->GetUp() * flScale;
	flScale = pSprite->GetDown() * flScale;

	switch (nOrientation)
	{
	case 3:
		{
			Vector forward, right, up;
			sub_101090a0(GetRenderAngles(), &forward, &right, &up);
			vecMins.Init(FLT_MAX, FLT_MAX, FLT_MAX);
			vecMaxs.Init(-FLT_MAX, -FLT_MAX, -FLT_MAX);
			for (int i = 0; i < 4; ++i)
			{
				Vector vecPos = right * ((i & 1) ? flLeft : flRight);
				vecPos += up * ((i & 2) ? flScale : flUp);
				VectorMin(vecMins, vecPos, vecMins);
				VectorMax(vecMaxs, vecPos, vecMaxs);
			}
		}
		break;

	case 0:
	case 1:
		{
			float flMaxWidth = max_L(-flLeft, flRight);
			vecMins.x = vecMins.y = -flMaxWidth;
			vecMaxs.x = vecMaxs.y = flMaxWidth;
			vecMins.z = flScale;
			vecMaxs.z = flUp;
		}
		break;

	default:
		{
			flLeft = -flLeft;
			flScale = -flScale;
			float flWidth = max_L(flLeft, flRight);
			float flHeight = max_L(flUp, flScale);
			float flMaxDim = sqrt(flHeight * flHeight + flWidth * flWidth);
			vecMins.x = vecMins.y = vecMins.z = -flMaxDim;
			vecMaxs.x = vecMaxs.y = vecMaxs.z = flMaxDim;
		}
		break;
	}
}
// END FUNCTION
