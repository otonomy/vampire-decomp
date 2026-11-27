// CCollisionHandleList: an object (unnamed in the game, no vtable) holding a vector of entity handles at +4 (memory, allocation
// count, grow size, size); sub_10042dd0 walks it from the back, updating each entity's collision property partition, and empties it.
#pragma once
#include "CBaseHandle.h"

struct CHandleVec
{
	CBaseHandle *m_pMemory;
	int m_allocationCount;
	int m_growSize;
	int m_size;
	CBaseHandle *sub_100445d0(int i);	// &m_pMemory[i]
};

class CCollisionHandleList
{
public:
	int m_unk0;
	CHandleVec m_list;
	void sub_10042dd0();
};
