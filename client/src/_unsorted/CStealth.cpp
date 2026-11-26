// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100622c0 size=0x200
#include "CStealth.h"
int sub_100cd100();
int sub_100cd0f0();
char *sub_1018c870(const char *);
// TARGET: ??0CStealth@@QAE@H@Z
CStealth::CStealth(int a)
    : CManagedHudElement(a, (int)"VStealth")
{
    sub_10062610();
    vfunc63(0);
    m_n198 = (int)(100 * (sub_100cd100() * 0.0015625));
    m_n19c = (int)(50 * (sub_100cd0f0() * 0.0020833333333333333));
    m_n1a0 = (int)(50 * (sub_100cd100() * 0.0015625));
    m_n1a4 = (int)(50 * (sub_100cd0f0() * 0.0020833333333333333));
    m_n1a8 = (int)(15 * (sub_100cd0f0() * 0.0020833333333333333));
    sub_101a9890(m_n178, m_n17c);
    m_b186 = false;
    m_b184 = true;
    m_b185 = true;
    m_n180 = 0;
    m_b190 = false;
    m_b192 = false;
    m_b191 = false;
    m_n188 = 0;
    m_b195 = false;
    m_b194 = false;
    m_b193 = false;
    m_n18c = 0;
    m_p1b0 = 0;
    int i;
    for (i = 0; i < 5; i++)
        m_arr1b4[i] = 0;
    m_p1c8 = 0;
    m_unk1cc = 0;
    m_p1d0 = 0;
    m_p1d4 = 0;
    m_p1d8 = 0;
    m_p1dc = 0;
    m_p1e0 = 0;
    m_p1e4 = 0;
    m_p1fc = 0;
    m_p200 = 0;
    m_p204 = 0;
    for (i = 0; i < 4; i++)
        m_arr1e8[i] = 0;
    IFontLike *p = sub_101ac830();
    m_unk1f8 = p->GetFont(sub_1018c870("Copperplate"));
    m_n1ac = -1;
}
// END FUNCTION

// FUNCTION: 0x100624e0 size=0x1e
#include "CStealth.h"

// VC6 writes CStealth's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CStealth *pcd_emit_100624e0(const CStealth &other) { return new CStealth(other); }

// TARGET: ??_GCStealth@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10062500 size=0x110
#include "CStealth.h"
// TARGET: ??1CStealth@@UAE@XZ
CStealth::~CStealth()
{
	CBasePanel::sub_101a9ff0(0);
	if (m_p1b0) {
		delete m_p1b0;
		for (int i = 0; i < 5; i++)
			if (m_arr1b4[i]) delete m_arr1b4[i];
		if (m_p1c8) delete m_p1c8;
	}
	if (m_p1d0) delete m_p1d0;
	if (m_p1d4) delete m_p1d4;
	if (m_p1d8) delete m_p1d8;
	if (m_p1dc) delete m_p1dc;
	if (m_p1e0) delete m_p1e0;
	if (m_p1e4) delete m_p1e4;
	for (int j = 0; j < 4; j++)
		if (m_arr1e8[j]) delete m_arr1e8[j];
	if (m_p1fc) delete m_p1fc;
	if (m_p200) delete m_p200;
	if (m_p204) delete m_p204;
}
// END FUNCTION

// FUNCTION: 0x10062660 size=0x23
#include "CStealth.h"
bool sub_10163bf0();
struct IUnkG286860 { virtual void v0(); virtual void v1(); virtual bool Check(int); };
extern IUnkG286860 *g_10286860;
bool CStealth::vfunc107()
{
	return sub_10163bf0() && !g_10286860->Check(0);
}
// END FUNCTION

// FUNCTION: 0x10063580 size=0x1
#include "CStealth.h"
void CStealth::vfunc97()
{
}
// END FUNCTION
