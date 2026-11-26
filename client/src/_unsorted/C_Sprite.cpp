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
