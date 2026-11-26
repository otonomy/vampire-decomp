// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100c6890 size=0x6
#include "C_BaseTerminal.h"
namespace lifted {
extern char g_102b7144;
}
int C_BaseTerminal::vfunc16()
{
    return (int)&lifted::g_102b7144;
}
// END FUNCTION

// FUNCTION: 0x100c68a0 size=0x3
#include "C_BaseTerminal.h"
int C_BaseTerminal::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100c6bf0 size=0x1e
#include "C_BaseTerminal.h"

// VC6 writes C_BaseTerminal's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_BaseTerminal *pcd_emit_100c6bf0(const C_BaseTerminal &other) { return new C_BaseTerminal(other); }

// TARGET: ??_GC_BaseTerminal@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100c6c10 size=0xa6
#include "engineclient.h"
#include "C_BaseTerminal.h"
extern "C" __declspec(dllimport) void __cdecl Plat_Free(void *);
// TARGET: ??1C_BaseTerminal@@UAE@XZ
C_BaseTerminal::~C_BaseTerminal()
{
	engine->vfunc12(this);
	sub_100c7550();
	m_size = 0;
	if (m_grow != -1) {
		if (m_pMem) {
			Plat_Free(m_pMem);
			m_pMem = 0;
		}
		m_alloc = 0;
	}
	m_pElements = m_pMem;
	if (m_grow != -1) {
		if (m_pMem) {
			Plat_Free(m_pMem);
			m_pMem = 0;
		}
		m_alloc = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x100c7620 size=0x5e
#include "engineclient.h"
#include "C_BaseTerminal.h"
#include "C_BaseEntity.h"
#include "IClientNetworkable.h"



void C_BaseTerminal::vfunc29(char b)
{
	C_BaseEntity::vfunc29(b);

	if (IsDormant())
	{
		sub_100c7550();
		vfunc83(-1.0f);
	}
	else
	{
		vfunc83(engine->Time(0) + 0.25);
	}
}
// END FUNCTION
