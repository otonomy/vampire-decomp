// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1004dd20 size=0x1e
#include "CCredits.h"

// VC6 writes CCredits's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CCredits *pcd_emit_1004dd20(const CCredits &other) { return new CCredits(other); }

// TARGET: ??_GCCredits@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1004dd40 size=0x87
#include "CCredits.h"
extern "C" __declspec(dllimport) void Plat_Free(void *);
// TARGET: ??1CCredits@@UAE@XZ
CCredits::~CCredits()
{
	sub_101a9ff0(0);
	m_size = 0;
	if (m_growSize != -1) {
		if (m_pMem) {
			Plat_Free(m_pMem);
			m_pMem = 0;
		}
		m_allocCount = 0;
	}
	m_pElements = m_pMem;
	if (m_growSize != -1) {
		if (m_pMem) {
			Plat_Free(m_pMem);
			m_pMem = 0;
		}
		m_allocCount = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x1004ddf0 size=0x57
#include "engineclient.h"
#include "CCredits.h"



void CCredits::vfunc114(const char *a1)
{
	if (sub_1004e220(a1))
	{
		*(float *)((char *)this + 0x18c) = engine->Time(0);
		vfunc5_hud(true);
	}
	else
	{
		vfunc5_hud(false);
	}
}
// END FUNCTION

// FUNCTION: 0x1004de50 size=0x23
#include "CCredits.h"
bool sub_10163bf0();
struct IUnkG286860 { virtual void v0(); virtual void v1(); virtual bool Check(int); };
extern IUnkG286860 *g_10286860;
bool CCredits::vfunc107()
{
	return sub_10163bf0() && !g_10286860->Check(0);
}
// END FUNCTION

// FUNCTION: 0x1004de80 size=0x1e
#include "CCredits.h"
void CCredits::vfunc112()
{
	vfunc115();
	vfunc5_hud(false);
}
// END FUNCTION

// FUNCTION: 0x1004dea0 size=0x8
#include "CCredits.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual int f112(); };
}
void CCredits::vfunc113()
{
    ((lifted::V *)this)->f112();
}
// END FUNCTION

// FUNCTION: 0x1004df00 size=0x2e1
#include "CCredits.h"
#include "engineclient.h"

extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)

void sub_1004e420(const char *str, int *a, int *b, int *c, int *d);
int sub_100cd0f0();
char *sub_1018c870(const char *);

struct CreditsSpeed_103eddfc
{
    virtual void vfunc0();
    virtual bool vfunc1();
    char m_pad4[0x24];
    float m_flSpeed;
};
extern CreditsSpeed_103eddfc *g_103eddfc;

struct ScreenFade_t
{
    unsigned short duration;
    unsigned short holdTime;
    short fadeFlags;
    unsigned char r, g, b, a;
};

struct ViewEffects_102d5238
{
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4(int, int, ScreenFade_t *);
};
extern ViewEffects_102d5238 *g_102d5238;

struct SchemeView_Credits
{
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual int vfunc4(const char *);
};

struct HudElemView_Credits
{
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5(int);
};

static inline float CreditsScale()
{
    return sub_100cd0f0() * (1.0 / 768.0);
}

void CCredits::vfunc98()
{
    int y = 0;
    float speed = CreditsScale() * (g_103eddfc->vfunc1() ? 0 : g_103eddfc->m_flSpeed);
    float elapsed = engine->Time(0) - m_flStartTime;
    int start = (int)(elapsed * speed - m_unk180);
    int end = start + m_unk180;
    int tall = 0;
    if (m_size == 0)
        return;
    int i;
    for (i = 0; i < m_size; i++)
    {
        const char *str = ((const char **)m_pMem)[i];
        if (!str)
            continue;
        if (str[0] == '@')
        {
            m_unk184 = ((SchemeView_Credits *)m_unk178)->vfunc4(sub_1018c870(str + 1));
        }
        else if (str[0] == '$')
        {
            sub_1004e420(str + 1, &m_unk1a4, &m_unk1a8, &m_unk1ac, &m_unk1b0);
        }
        else if (str[0] == '%')
        {
            sub_1004e420(str + 1, &m_unk1b4, &m_unk1b8, &m_unk1bc, &m_unk1c0);
        }
        else
        {
            int wide = g_pMatSystemSurface->vfunc15(m_unk184, str);
            g_pMatSystemSurface->vfunc14(m_unk184, wide + 10, &tall, str);
            if (y + tall >= start)
            {
                if (m_unk1c0)
                    g_pMatSystemSurface->vfunc12(m_unk184, (m_unk17c - wide) / 2 + 2, y - start + 2,
                        m_unk1b4, m_unk1b8, m_unk1bc, m_unk1c0, str);
                g_pMatSystemSurface->vfunc12(m_unk184, (m_unk17c - wide) / 2, y - start,
                    m_unk1a4, m_unk1a8, m_unk1ac, m_unk1b0, str);
            }
            y += tall;
            if (y > end)
                break;
        }
    }
    if (y - start < -tall && i >= m_size)
    {
        ((HudElemView_Credits *)((char *)this + 0x170))->vfunc5(0);
        ScreenFade_t fade;
        memset(&fade, 0, sizeof(fade));
        fade.duration = 0xa00;
        fade.holdTime = 0x200;
        fade.r = 0;
        fade.g = 0;
        fade.b = 0;
        fade.a = 0xff;
        fade.fadeFlags = 0x52;
        g_102d5238->vfunc4(0, 0, &fade);
        vfunc115();
    }
}
// END FUNCTION

// FUNCTION: 0x1004e1f0 size=0x1
#include "CCredits.h"
void CCredits::vfunc97()
{
}
// END FUNCTION

// FUNCTION: 0x1004e340 size=0x82
#include "CCredits.h"
extern "C" __declspec(dllimport) void Plat_Free(void *);
void sub_1004e410(void *);
// TARGET: ?vfunc115@CCredits@@UAEXXZ
void CCredits::vfunc115()
{
	for (int i = 0; i < m_size; i++)
		sub_1004e410(((void **)m_pMem)[i]);
	m_size = 0;
	if (m_growSize != -1)
	{
		if (m_pMem)
		{
			Plat_Free(m_pMem);
			m_pMem = 0;
		}
		m_allocCount = 0;
	}
	m_pElements = m_pMem;
}
// END FUNCTION
