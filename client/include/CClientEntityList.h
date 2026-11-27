// CClientEntityList: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases; nothing else yet (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "CBaseEntityList.h"
#include "IClientEntityList.h"
#include "CBaseHandle.h"

class CClientEntityList : public CBaseEntityList, public IClientEntityList
{
public:
	CClientEntityList();
	void sub_100d0b40();
	~CClientEntityList();
	class C_BaseEntity *sub_100d0dc0(CBaseHandle h);	// GetBaseEntityFromHandle

	// the SDK's CBaseEntityList::FirstHandle / NextHandle (inline): the live list's handles in order
	CBaseHandle FirstHandle() const
	{
		if (m_Live.m_Head == 0xffff)
			return CBaseHandle();
		int index = m_Live.m_pMemory[m_Live.m_Head].m_Element;
		return CBaseHandle(index, m_EntPtrArray[index].m_SerialNumber);
	}
	CBaseHandle NextHandle(CBaseHandle hEnt) const
	{
		int next = m_Live.m_pMemory[m_EntPtrArray[hEnt.m_Index & 0x1fff].m_ListIndex].m_Next;
		if (next == CBaseEntityListLL::InvalidIndex())
			return CBaseHandle();
		int index = m_Live.m_pMemory[(unsigned short)next].m_Element;
		return CBaseHandle(index, m_EntPtrArray[index].m_SerialNumber);
	}
	int sub_100d0d90(CBaseHandle h);
	class C_BaseEntity *sub_100d0cf0(int entnum);
	int m_i18040; int m_i18044; int m_i18048;
	char m_pad1804c[0x2804c - 0x1804c];
	struct Tail {
		int a; int b; int c; unsigned short d; unsigned short e; unsigned short f; unsigned short g; unsigned short h; int i;
		Tail() { a = 0; b = 0; c = 0; d = 0xffff; e = 0xffff; f = 0xffff; h = 0; g = 0; i = 0; }
	} m_tail;
};

// the client's entity list (SDK cl_dll/cliententitylist.h): cl_entitylist, ClientEntityList()
extern CClientEntityList *cl_entitylist;

inline CClientEntityList &ClientEntityList()
{
	return *cl_entitylist;
}
