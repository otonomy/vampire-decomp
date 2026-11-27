// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100bc1c0 size=0xfe
#include "CHudEntityElement.h"
#include "engineclient.h"
struct HudEntData {
	char pad0[0x50];
	unsigned char m_r, m_g, m_b;
	char pad53[0x410 - 0x53];
	int m_i410;
	char pad414[4];
	int m_i418;
	float m_f41c, m_f420, m_f424, m_f428;
	char pad42c[4];
	bool m_b430;
};
struct ISurf102bc800 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(int, int, int, int);
	virtual void v7(int, int, int, int, int, int);
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(int, int, int, int, int, int);
};
extern ISurf102bc800 *g_102bc800;
int sub_100ccbd0(const char *);
int sub_100cd100();
int sub_100cd0f0();
struct HudEntView { int pad[4]; int m_i10; HudEntData *m_pData; };
void CHudEntityElement::vfunc5(int)
{
	HudEntView *self = (HudEntView *)this;
	if (!self->m_i10)
		self->m_i10 = sub_100ccbd0(modelinfo->GetModelName(modelinfo->GetModel(self->m_pData->m_i410)));
	g_102bc800->v6(self->m_i10, self->m_pData->m_r, self->m_pData->m_g, self->m_pData->m_b);
	HudEntData *volatile *vp = &self->m_pData;
	int x0 = (int)(sub_100cd100() * (*vp)->m_f41c);
	HudEntData *p = *vp;
	int y0 = (int)(sub_100cd0f0() * (1.0f - p->m_f420));
	int x1 = (int)p->m_f424;
	int y1 = (int)-p->m_f428;
	if (x1 < 0) { x0 += x1; x1 = -x1; }
	if (y1 < 0) { y0 += y1; y1 = -y1; }
	if (p->m_b430)
		g_102bc800->v12(p->m_i418, x0, y0, x1, y1, 0);
	else
		g_102bc800->v7(p->m_i418, x0, y0, x1, y1, 0);
}
// END FUNCTION

// FUNCTION: 0x100bc2f0 size=0x1e
#include "CHudEntityElement.h"

// VC6 writes CHudEntityElement's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CHudEntityElement *pcd_emit_100bc2f0(const CHudEntityElement &other) { return new CHudEntityElement(other); }

// TARGET: ??_GCHudEntityElement@@UAEPAXI@Z
// END FUNCTION
