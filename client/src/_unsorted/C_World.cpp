// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100ca210 size=0x6
#include "C_World.h"
namespace lifted {
extern char g_102b8030;
}
int C_World::vfunc16()
{
    return (int)&lifted::g_102b8030;
}
// END FUNCTION

// FUNCTION: 0x100ca220 size=0x3
#include "C_World.h"
int C_World::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100ca4c0 size=0x152
#include "C_World.h"
#include "CUtlLinkedList12.h"
struct CUtlMemory12 { void sub_100caa80(int); };
extern CUtlLinkedList12 g_104a56cc;
extern void (__cdecl *g_101e310c)(const char *, ...);
void sub_100ca9e0(void *p, void *src);
void sub_10067f60();
C_World::C_World()
{
	m_fCur = 0;
	m_fUp = 5.0f;
	m_fDown = 5.0f;
	m_fTarget = 0;
	C_World *src = this;
	int elem;
	if (g_104a56cc.m_FirstFree == -1)
	{
		if (g_104a56cc.m_NumAlloced == g_104a56cc.m_allocationCount)
			((CUtlMemory12 *)&g_104a56cc)->sub_100caa80(1);
		elem = g_104a56cc.m_NumAlloced++;
		if (elem == -1)
			g_101e310c("CUtlLinkedList overflow!\n");
	}
	else
	{
		elem = g_104a56cc.m_FirstFree;
		g_104a56cc.m_FirstFree = g_104a56cc.m_pMemory[elem].m_Next;
	}
	g_104a56cc.m_pMemory[elem].m_Previous = elem;
	g_104a56cc.m_pMemory[elem].m_Next = elem;
	g_104a56cc.m_pElements = g_104a56cc.m_pMemory;
	g_104a56cc.sub_100caa00(elem);
	CUtlLinkedList12Node &n = g_104a56cc.m_pMemory[elem];
	n.m_Next = -1;
	n.m_Previous = g_104a56cc.m_Tail;
	g_104a56cc.m_Tail = elem;
	if (n.m_Previous == -1)
		g_104a56cc.m_Head = elem;
	else
		g_104a56cc.m_pMemory[n.m_Previous].m_Next = elem;
	g_104a56cc.m_ElementCount++;
	sub_100ca9e0(&g_104a56cc.m_pMemory[elem], &src);
	m_n410 = 0;
	sub_10067f60();
}
// END FUNCTION

// FUNCTION: 0x100ca620 size=0x3
#include "C_World.h"
int C_World::vfunc66()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100ca630 size=0x1e
#include "C_World.h"

// VC6 writes C_World's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_World *pcd_emit_100ca630(const C_World &other) { return new C_World(other); }

// TARGET: ??_GC_World@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100ca650 size=0xf7
#include "C_World.h"
#include "CUtlLinkedList12.h"
extern CUtlLinkedList12 g_104a56cc;
void sub_10067f70();
// TARGET: ??1C_World@@UAE@XZ
C_World::~C_World()
{
	int i = g_104a56cc.m_Head;
	while (i != -1) {
		if (g_104a56cc.m_pMemory[i].m_pData == this)
			break;
		i = g_104a56cc.m_pMemory[i].m_Next;
	}
	if (i != -1) {
		if (g_104a56cc.IsInList(i)) {
			CUtlLinkedList12Node *pBase = g_104a56cc.m_pMemory;
			CUtlLinkedList12Node *pOldElem = &pBase[i];
			if (pOldElem->m_Previous != -1)
				pBase[pOldElem->m_Previous].m_Next = pOldElem->m_Next;
			else
				g_104a56cc.m_Head = pOldElem->m_Next;
			if (pOldElem->m_Next != -1)
				pBase[pOldElem->m_Next].m_Previous = pOldElem->m_Previous;
			else
				g_104a56cc.m_Tail = pOldElem->m_Previous;
			pOldElem->m_Previous = pOldElem->m_Next = i;
			--g_104a56cc.m_ElementCount;
		}
		g_104a56cc.m_pMemory[i].m_Next = g_104a56cc.m_FirstFree;
		g_104a56cc.m_FirstFree = i;
	}
	sub_10067f70();
}
// END FUNCTION

// FUNCTION: 0x100ca990 size=0x1f
#include "C_World.h"
namespace lifted {
extern int g_104a56fc;
int sub_100c87d0();
int sub_101206b0();
struct V { virtual int f0(int); };
}
void C_World::vfunc21()
{
    if (lifted::g_104a56fc != 0) {
        ((lifted::V *)lifted::g_104a56fc)->f0(1);
    }
    lifted::g_104a56fc = lifted::sub_100c87d0();
    lifted::sub_101206b0();
}
// END FUNCTION

// FUNCTION: 0x100ca9b0 size=0x5
#include "C_World.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(); };
}
void C_World::vfunc19()
{
    ((lifted::V *)this)->f21();
}
// END FUNCTION
