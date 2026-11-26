// CVGuiScreenEnumerator: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "IPartitionEnumerator.h"

extern "C" __declspec(dllimport) void Plat_Free(void *);

class CVGuiScreenEnumerator : public IPartitionEnumerator
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots CVGuiScreenEnumerator adds to its base's vtable: 0-0, vfuncK at slot K
    virtual void vfunc0();

	struct ScreenList	// CUtlVector< CHandle< C_VGuiScreen > > m_VguiScreens (memory, allocation count, grow size, size, element pointer)
	{
		int *m_pMemory;
		int m_allocationCount;
		int m_growSize;
		int m_size;
		int *m_pElements;
		ScreenList() : m_pMemory(0), m_allocationCount(0), m_growSize(0), m_size(0), m_pElements(0) {}
		~ScreenList()
		{
			m_size = 0;
			if (m_growSize != -1)
			{
				if (m_pMemory)
				{
					Plat_Free(m_pMemory);
					m_pMemory = 0;
				}
				m_allocationCount = 0;
			}
			m_pElements = m_pMemory;
			if (m_growSize != -1 && m_pMemory)
				Plat_Free(m_pMemory);
		}
	};
	ScreenList m_VguiScreens;	// 0x4
};
