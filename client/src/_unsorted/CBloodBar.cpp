// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1004c550 size=0x13b
#include "CBloodBar.h"

extern "C" int sub_100cd100();

// TARGET: ??0CBloodBar@@QAE@H@Z
CBloodBar::CBloodBar(int parent) : CManagedHudElement(parent, (int)"BloodBar")
{
    sub_1004c780();
    vfunc63(0);
    sub_101a9890((sub_100cd100() - (m_n178 * 15 + (m_n17c * 7 + m_n188 + m_n180) * 2)) / 2, m_n184);
    sub_101a98f0(m_n178 * 15 + (m_n17c * 7 + m_n188 + m_n180) * 2, m_n178);
    m_b1a0 = 1;
    m_b1a1 = 1;
    m_b1a2 = 0;
    m_n19c = 0;
    vfunc114(0);
    m_n198 = 0;
    m_p1a4 = 0;
    m_p1ac = 0;
    m_p1b0 = 0;
    m_p1b4 = 0;
    m_p1b8 = 0;
    m_p1bc = 0;
    m_p1c0 = 0;
    m_p1c4 = 0;
    m_p1c8 = 0;
    m_n1cc = 0;
    m_n1d0 = 0;
    m_flTime1d4 = 0;
    m_n1d8 = -1;
}
// END FUNCTION

// FUNCTION: 0x1004c690 size=0x1e
#include "CBloodBar.h"

// VC6 writes CBloodBar's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CBloodBar *pcd_emit_1004c690(const CBloodBar &other) { return new CBloodBar(other); }

// TARGET: ??_GCBloodBar@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1004c6b0 size=0xb2
#include "CBloodBar.h"
// TARGET: ??1CBloodBar@@UAE@XZ
CBloodBar::~CBloodBar()
{
	sub_101a9ff0(0);
	delete m_p1a4;
	delete m_p1ac;
	delete m_p1b0;
	delete m_p1b4;
	delete m_p1b8;
	delete m_p1bc;
	delete m_p1c0;
	delete m_p1c4;
	delete m_p1c8;
}
// END FUNCTION

// FUNCTION: 0x1004c770 size=0xb
#include "CBloodBar.h"
void CBloodBar::vfunc112()
{
    *(int *)((char *)this + 0x1d4) = 0;
}
// END FUNCTION

// FUNCTION: 0x1004c9c0 size=0x23
#include "CBloodBar.h"
struct CUnkIface10286860 { virtual void v0(); virtual void v1(); virtual bool v2(int); };
extern CUnkIface10286860 *g_10286860;
bool sub_10163bf0();
// TARGET: CBloodBar::vfunc107
bool CBloodBar::vfunc107()
{
	return sub_10163bf0() && !g_10286860->v2(0);
}
// END FUNCTION

// FUNCTION: 0x1004d2f0 size=0x1
#include "CBloodBar.h"
void CBloodBar::vfunc97()
{
}
// END FUNCTION

// FUNCTION: 0x1004d390 size=0x27
#include "CBloodBar.h"
namespace lifted {
struct C1004d300 { int sub_1004d300(); };
struct C1004d460 { int sub_1004d460(); };
}
int CBloodBar::vfunc114(int a0)
{
    if ((*(int *)((char *)this + 0x190)) > a0) {
        ((lifted::C1004d460 *)this)->sub_1004d460();
    }
    *(int *)((char *)this + 0x190) = a0;
    return ((lifted::C1004d300 *)this)->sub_1004d300();
}
// END FUNCTION

// FUNCTION: 0x1004d3c0 size=0x27
#include "CBloodBar.h"
namespace lifted {
struct C1004d300 { int sub_1004d300(); };
struct C1004d460 { int sub_1004d460(); };
}
int CBloodBar::vfunc115(int a0)
{
    if ((*(int *)((char *)this + 0x194)) > a0) {
        ((lifted::C1004d460 *)this)->sub_1004d460();
    }
    *(int *)((char *)this + 0x194) = a0;
    return ((lifted::C1004d300 *)this)->sub_1004d300();
}
// END FUNCTION
