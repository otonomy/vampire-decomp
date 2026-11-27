#pragma once
#include "CTraceFilterSimple.h"

class CTraceFilterSimpleList : public CTraceFilterSimple
{
public:
	struct PassList {
		const void **m_pMemory;
		int m_nAllocationCount;
		int m_nGrowSize;
		int m_Size;
		int Count() const { return m_Size; }
		int Find(const void *src) const {
			for (int i = 0; i < Count(); i++) {
				if (m_pMemory[i] == src) return i;
			}
			return -1;
		}
	};
	PassList m_PassEntities;
	bool vfunc0(const void *pHandleEntity, int contentsMask);
};
