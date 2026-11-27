// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1004b7a0 size=0x3a
#include "CTraceFilterSimpleList.h"
// TARGET: CTraceFilterSimpleList::vfunc0
bool CTraceFilterSimpleList::vfunc0(const void *pHandleEntity, int contentsMask)
{
	if (m_PassEntities.Find(pHandleEntity) != -1)
		return false;
	return CTraceFilterSimple::sub_1004b5f0(pHandleEntity, contentsMask);
}
// END FUNCTION
