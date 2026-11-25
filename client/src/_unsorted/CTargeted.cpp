// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10063750 size=0x203
#include "CTargeted.h"
extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
char *sub_1018c870(const char *);
int sub_100cd0f0();
int sub_100cd100();
extern char g_103eef44, g_103eef04, g_103eef68, g_103eef9c, g_103eee68;
extern int g_103eef48, g_103eef38, g_103eef00, g_103eef98, g_103eee5c, g_103eee54;
extern int g_103eeedc, g_103eeeec;
extern float g_103eefec;
extern int g_103eef6c[10];
extern int g_103eeeb4[];
extern double g_10227ec8, g_1022b2a8, g_10227eb8, g_1022b2a0;
CTargeted::CTargeted(int a)
    : CManagedHudElement(a, (int)"Targeted")
{
	sub_10063a70();
	vfunc63(0);
	sub_101a9890(m_n178, m_n17c);
	sub_101a98f0(m_n180, m_n184);
	g_103eef44 = 0;
	g_103eef04 = 0;
	g_103eef68 = 0;
	g_103eef48 = 0xff;
	m_p1bc = 0;
	m_p1b8 = 0;
	m_p1b4 = 0;
	m_p1cc = 0;
	m_p1c8 = 0;
	m_p1c0 = 0;
	m_p1c4 = 0;
	g_103eef38 = 0;
	g_103eef00 = 0;
	g_103eef98 = 0;
	int *p = g_103eeeb4;
	memset(g_103eef6c, 0, sizeof(g_103eef6c));
	do {
		int a, b;
		if ((int)p < (int)&g_103eeedc)
			a = b = 0x100;
		else if ((int)p < (int)&g_103eeeec)
			a = b = 0x80;
		else
			a = b = 0x40;
		p[-1] = a;
		p[0] = b;
		p += 2;
	} while ((int)p < (int)&g_103eef04);
	g_103eee5c = 0;
	g_103eee68 = 0;
	g_103eee54 = -1;
	g_103eef9c = 0;
	IFontLike *f = sub_101ac830();
	m_nFont1a8 = f->GetFont(sub_1018c870("PercolatorMedium"));
	m_nFont1ac = f->GetFont(sub_1018c870("BenguiatBig"));
	m_nFont1b0 = f->GetFont(sub_1018c870("Copperplate"));
	sub_10063d40();
	m_n1d8 = (int)(sub_100cd100() * g_1022b2a8 * g_10227ec8);
	m_n1dc = (int)(sub_100cd0f0() - sub_100cd0f0() * g_1022b2a0 * g_10227eb8);
	m_n1d0 = 0;
	m_p220 = 0;
	g_103eefec = 0.0f;
}
// END FUNCTION

// FUNCTION: 0x10063980 size=0x1e
#include "CTargeted.h"

// VC6 writes CTargeted's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CTargeted *pcd_emit_10063980(const CTargeted &other) { return new CTargeted(other); }

// TARGET: ??_GCTargeted@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100639a0 size=0xd0
#include "CTargeted.h"
struct CTgtObj { virtual ~CTgtObj() {} };
extern CTgtObj *g_103eee5c;
extern CTgtObj *g_103eef6c[10];
// TARGET: ??1CTargeted@@UAE@XZ
CTargeted::~CTargeted()
{
	CBasePanel::sub_101a9ff0(0);
	delete m_p1b4;
	delete m_p1b8;
	delete m_p1bc;
	delete m_p1c0;
	delete m_p1c4;
	delete m_p1c8;
	delete m_p1cc;
	for (int i = 0; i < 10; i++)
		delete g_103eef6c[i];
	delete g_103eee5c;
	delete m_p220;
}
// END FUNCTION

// FUNCTION: 0x10064ab0 size=0x1
#include "CTargeted.h"
void CTargeted::vfunc97()
{
}
// END FUNCTION
