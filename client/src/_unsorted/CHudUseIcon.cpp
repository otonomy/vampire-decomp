// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1005e020 size=0xd1
#include "engineclient.h"
#include "CHudUseIcon.h"
extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
extern CHudUseIcon *g_103eede0;
// TARGET: ??0CHudUseIcon@@QAE@H@Z
CHudUseIcon::CHudUseIcon(int parent) : CManagedHudElement(parent, (int)"CHudUseIcon")
{
	sub_1005e1a0();
	vfunc63(0);
	sub_101a9890(m_unk194, m_unk198);
	sub_101a98f0(m_unk19c, m_unk1a0);
	vfunc64(1);
	m_pChild1 = 0;
	m_pChild2 = 0;
	m_pChild3 = 0;
	m_unk1c0 = 0;
	m_b1ac = 1;
	m_unk1c4 = 0;
	m_unk1a4 = 0;
	m_f1a8 = engine->Time(0);
	memset(m_arr1c9, 0, sizeof(m_arr1c9));
	m_pChild4 = 0;
	m_pChild5 = 0;
	g_103eede0 = this;
}
// END FUNCTION

// FUNCTION: 0x1005e100 size=0x1e
#include "CHudUseIcon.h"

// VC6 writes CHudUseIcon's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CHudUseIcon *pcd_emit_1005e100(const CHudUseIcon &other) { return new CHudUseIcon(other); }

// TARGET: ??_GCHudUseIcon@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1005e120 size=0x7c
#include "CHudUseIcon.h"
extern int g_103eede0;
// TARGET: ??1CHudUseIcon@@UAE@XZ
CHudUseIcon::~CHudUseIcon()
{
	g_103eede0 = 0;
	sub_101a9ff0(0);
	delete m_pChild1;
	delete m_pChild2;
	delete m_pChild3;
	delete m_pChild4;
	delete m_pChild5;
}
// END FUNCTION

// FUNCTION: 0x1005e3d0 size=0x30
#include "CHudUseIcon.h"
bool sub_1018c770();
bool sub_10170bf0();
extern int g_104a0d50;
bool CHudUseIcon::vfunc107()
{
	if (!m_b1ac)
		return false;
	if (sub_1018c770())
		return false;
	if (sub_10170bf0())
		return false;
	bool b = g_104a0d50 != 0;
	return b;
}
// END FUNCTION
