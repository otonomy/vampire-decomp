// CUtlMemory12: the memory part of a CUtlVector whose elements are 12 bytes (pointer, allocation count, grow size).
#pragma once

extern "C" __declspec(dllimport) void __cdecl Plat_Free(void *);
struct CUtlMemory12
{
	char *m_pMemory;
	int m_allocationCount;
	int m_growSize;

	void sub_1002d470();
	void Purge() { if (m_growSize != -1) { if (m_pMemory) { Plat_Free(m_pMemory); m_pMemory = 0; } m_allocationCount = 0; } }
	void sub_10119fe0(int num);
	void sub_1002d690(int num);
	CUtlMemory12 *sub_1002d430(int growSize, int allocationCount);	// constructor: allocates allocationCount * 12 bytes
};
