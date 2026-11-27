// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10167960 size=0x30
#include "CLoadingDisc.h"
void *sub_101ac650(unsigned int);
struct LDPanel { LDPanel *sub_101670d0(int a); };
int CLoadingDisc::vfunc0(int a)
{
	LDPanel *p = (LDPanel *)sub_101ac650(0xa0);
	LDPanel *r;
	if (p)
		r = p->sub_101670d0(a);
	else
		r = 0;
	return (int)(*(LDPanel **)((char *)this + 4) = r);
}
// END FUNCTION

// FUNCTION: 0x10167990 size=0x24
#include "CLoadingDisc.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual int f20(int); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual int f33(int); };
}
void CLoadingDisc::vfunc1()
{
    if ((*(int *)((char *)this + 4)) != 0) {
        int t0 = ((lifted::V *)(*(int *)((char *)this + 4)))->f33(0);
        if ((*(int *)((char *)this + 4)) != 0) {
            ((lifted::V *)(*(int *)((char *)this + 4)))->f20(1);
        }
    }
}
// END FUNCTION

// FUNCTION: 0x101679c0 size=0x10f
#include "engineclient.h"
#include "CGlobalVarsBase.h"
#include "CLoadingDisc.h"

#define LV1(a) virtual void a();
#define LV10(p) LV1(p##0) LV1(p##1) LV1(p##2) LV1(p##3) LV1(p##4) LV1(p##5) LV1(p##6) LV1(p##7) LV1(p##8) LV1(p##9)

struct LoadingDiscPanel
{
	LV10(a) LV10(b)
	LV1(c0)
	virtual void vfunc21(bool bOn);
	LV10(d)
	LV1(e0) LV1(e1) LV1(e2) LV1(e3) LV1(e4) LV1(e5) LV1(e6)
	LV10(f)
	virtual void vfunc49();
	char m_pad[0x88 - 4];
	int m_nAlpha;
	bool m_bVisible;
};

extern bool g_105fad08;
extern float g_105fad0c;
extern "C" void sub_1018ccf0(int);

void CLoadingDisc::vfunc2(bool bOn)
{
	if (g_105fad08 != bOn)
	{
		if (g_105fad08)
		{
			g_105fad0c = gpGlobals->curtime + 3.0;
			engine->ClientCmd("clear_io_states");
		}
		else
			sub_1018ccf0(4);
		m_pPanel->m_nAlpha = 255;
		g_105fad08 = bOn;
	}
	if (!bOn)
	{
		if (g_105fad0c > gpGlobals->curtime)
		{
			bOn = true;
			double flT = 3.0 - (g_105fad0c - gpGlobals->curtime);
			int nAlpha;
			if (flT < 1.0)
				nAlpha = 255;
			else
			{
				double flFrac = (flT - 1.0) * 255.0;
				nAlpha = (int)(255.0 - flFrac * 0.5);
				if (nAlpha > 255)
					nAlpha = 255;
				else if (nAlpha < 0)
					nAlpha = 0;
			}
			m_pPanel->m_nAlpha = nAlpha;
			m_pPanel->vfunc49();
			m_pPanel->m_bVisible = bOn;
		}
		else
			m_pPanel->m_bVisible = false;
	}
	m_pPanel->vfunc21(bOn);
}
// END FUNCTION
