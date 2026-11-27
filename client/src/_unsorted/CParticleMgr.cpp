// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10117340 size=0x1e
#include "CParticleMgr.h"

// VC6 writes CParticleMgr's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CParticleMgr *pcd_emit_10117340() { return new CParticleMgr; }

// TARGET: ??_GCParticleMgr@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10117360 size=0xa0
#include "CParticleMgr.h"
extern "C" __declspec(dllimport) void Plat_Free(void *);
extern unsigned char g_104e09c0;
// TARGET: ??1CParticleMgr@@UAE@XZ
CParticleMgr::~CParticleMgr()
{
	sub_10117460();
	g_104e09c0 = 0;
	if (m_list.m_NumAlloced != 0)
	{
		unsigned short next = 0xffff;
		for (int i = m_list.m_NumAlloced - 1; i >= 0; --i)
		{
			m_list.InternalElement(i).m_Next = next;
			m_list.InternalElement(i).m_Previous = (unsigned short)i;
			next = i;
		}
		m_list.m_FirstFree = 0;
		m_list.m_Head = 0xffff;
		m_list.m_Tail = 0xffff;
		m_list.m_ElementCount = 0;
	}
	if (m_list.m_growSize != -1)
	{
		if (m_list.m_pMemory)
		{
			Plat_Free(m_list.m_pMemory);
			m_list.m_pMemory = 0;
		}
		m_list.m_allocationCount = 0;
	}
}
// END FUNCTION
