// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100bbca0 size=0xb0
#include "CHudCounterElement.h"
#include "CHud.h"
struct ISurf6 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(int, int, int, int); };
extern ISurf6 *g_102bc800;
int sub_100cd0f0();
int sub_100cd100();
void CHudCounterElement::vfunc5(int a)
{
	int r = m_pDef->m_r;
	int g = m_pDef->m_g;
	int b = m_pDef->m_b;
	g_102bc800->v6(m_unk10, r, g, b);
	int y = (int)(sub_100cd100() * m_pDef->m_flY);
	int x = (int)(sub_100cd0f0() * (1.0f - m_pDef->m_flX));
	int flags = 5;
	if (m_pDef->m_bFlag)
		flags = 0xd;
	gHUD.sub_100f2e80(y, x, flags, m_pDef->m_unk418, r, g, b, -1, -1);
}
// END FUNCTION

// FUNCTION: 0x100bbe00 size=0x1e
#include "CHudCounterElement.h"

// VC6 writes CHudCounterElement's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CHudCounterElement *pcd_emit_100bbe00(const CHudCounterElement &other) { return new CHudCounterElement(other); }

// TARGET: ??_GCHudCounterElement@@UAEPAXI@Z
// END FUNCTION
