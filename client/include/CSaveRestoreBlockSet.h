// CSaveRestoreBlockSet (RTTI .?AVCSaveRestoreBlockSet@@): bases ISaveRestoreBlockSet and ISaveRestoreBlockHandler at +0x0.
// Only the members that decompiled code needs are declared.
#pragma once

extern "C" void *__cdecl memmove(void *, const void *, unsigned int);
extern "C" void *__cdecl sub_101d0f30(void *, const void *, unsigned int);
extern void *(__cdecl *g_101e3100)(unsigned int);
extern void *(__cdecl *g_101e3104)(void *, unsigned int);

#include "utlvector.h"

struct SaveRestoreBlockHeader_t	// one block's header record (0x28 bytes), as filled by vfunc1 and written by vfunc3
{
	char m_szName[0x20];	// 0x00: the handler's block name
	int m_nLocHeader;	// 0x20: the position of the block's data relative to the save's start (written by vfunc3 per handler, from the stream's slot 0)
	int m_nLocBody;	// 0x24: read back by vfunc7 (-1 = none; vfunc3 pre-fills the whole record with 0xff)
};

#ifdef PCD_INITIALIZERS	// the initializer unit: the global 0x1072bae8 (the SDK's g_SaveRestoreBlockSet("Game"))
extern "C" __declspec(dllimport) char *Q_strncpy(char *, const char *, int);
// The SDK form (2004 saverestore.cpp): ISaveRestoreBlockSet's 11 slots, the name, the handlers, two sizes and the
// headers; built inline by the constructor below, destroyed by the implicit destructor (the two vectors, last first).
class CSaveRestoreBlockSet
{
public:
	CSaveRestoreBlockSet(const char *pszName)
	{
		Q_strncpy(m_Name, pszName, sizeof(m_Name));
	}
	virtual const char *GetBlockName();
	virtual void PreSave(void *pData);
	virtual void Save(void *pSave);
	virtual void WriteSaveHeaders(void *pSave);
	virtual void PostSave();
	virtual void PreRestore();
	virtual void ReadRestoreHeaders(void *pRestore);
	virtual void Restore(void *pRestore, bool fCreatePlayers);
	virtual void PostRestore();
	virtual void AddBlockHandler(void *pHandler);
	virtual void RemoveBlockHandler(void *pHandler);

	char m_Name[0x20];	// 0x04
	CUtlVector<void *> m_Handlers;	// 0x24
	int m_SizeHeaders;	// 0x38
	int m_SizeBodies;	// 0x3c
	CUtlVector<SaveRestoreBlockHeader_t> m_BlockHeaders;	// 0x40
};
#else
class CSaveRestoreBlockSet
{
public:
	char pad0[0x4];
	char pad4[0x20];
	void **m_pHandlers;	// 0x24, CUtlVector memory
	int m_nAllocCount;	// 0x28
	int m_nGrowSize;	// 0x2c
	int m_nHandlers;	// 0x30
	void **m_pHandlerElements;	// 0x34
	char pad38[0x4];
	int m_nSize;	// 0x3c
	char *m_pEntries;	// 0x40, entries of 0x28 bytes
	int m_nEntriesAlloc;	// 0x44
	int m_nEntriesGrow;	// 0x48
	int m_nEntries;	// 0x4c, number of entries at m_pEntries
	char *m_pEntryElements;	// 0x50

	void vfunc1(void *pSave);	// slot 1: rebuilds the entry table from the handlers' block names, then calls slot 1 of every handler
	void vfunc2(void *pSave);
	void vfunc3(void *pSave);	// slot 3 (Save, 0x101a4970, ret 4): the stream (ISave-like, slots 0 tell / 1 seek / 10 WriteInt(const int *, int)); a local CUtlVector<SaveRestoreBlockHeader_t> sized like BlockHeaders() and memset 0xff; WriteInt(&sizeOfHeaderTable) then the local vector through a guarded static CUtlVectorDataOps<CUtlVector<SaveRestoreBlockHeader_t>, 9> (guard 0x109f0a02, object 0x109f0a0c, Save = vfunc0(&SaveRestoreFieldInfo_t{&vec, 0, 0}, pSave)); every handler's slot 3 (Save(pSave), vtable +0xc) stamping its header's m_nLocHeader (position - start); the position then goes to m_nSize (+0x38), the stream seeks back to the start, writes m_nSize (+0x38) and +0x3c, and the real BlockHeaders() vector through the same static ops
	CUtlVector<SaveRestoreBlockHeader_t> &BlockHeaders() { return *(CUtlVector<SaveRestoreBlockHeader_t> *)&m_pEntries; }	// 0x40: memory +0x40, allocation +0x44, grow +0x48, count +0x4c, elements +0x50 (the members above are views of the same vector)
	void vfunc4();	// slot 4: calls slot 4 of every handler, then empties the entry table (CUtlVector Purge)
	void vfunc5();	// slot 5: calls slot 5 of every handler in the list (CUtlVector<void *> at +0x24, count at +0x30)
	void vfunc6(void *pRestore);
	void vfunc7(void *pSave, int a, int b);	// for every handler whose block name is found in the entry table (name at +0, offset at +0x24 unless -1) seeks the save/restore stream to base + offset and forwards (pSave, a, b) to the handler's slot 7; finally seeks to base + m_nSize
	void vfunc8();	// slot 8: calls slot 8 of every handler, then empties the entry table (CUtlVector Purge)
	void vfunc9(void *pHandler);	// AddHandler: CUtlVector::AddToTail
	void vfunc10(void *pHandler);	// RemoveBlockHandler: CUtlVector::FindAndRemove
	CUtlVector<void *> &Handlers() { return *(CUtlVector<void *> *)&m_pHandlers; }

	// Inlined CUtlVector<void *> pieces.
	void GrowMemory(int num)
	{
		if (m_nGrowSize == -1)
			return;
		int requested = m_nAllocCount + num;
		if (m_nAllocCount < requested) {
			int count = m_nAllocCount;
			do {
				if (count) {
					if (m_nGrowSize)
						count += m_nGrowSize;
					else
						count += count;
				} else
					count = 8;
			} while (count < requested);
			m_nAllocCount = count;
		}
		if (m_pHandlers)
			m_pHandlers = (void **)g_101e3104(m_pHandlers, m_nAllocCount * 4);
		else
			m_pHandlers = (void **)g_101e3100(m_nAllocCount * 4);
	}
	void GrowVector()
	{
		if (m_nHandlers + 1 > m_nAllocCount)
			GrowMemory(m_nHandlers + 1 - m_nAllocCount);
		m_pHandlerElements = m_pHandlers;
		m_nHandlers++;
	}
	void ShiftElementsRight(int elem)
	{
		int toMove = m_nHandlers - elem - 1;
		if (toMove > 0)
			memmove(&m_pHandlers[elem + 1], &m_pHandlers[elem], toMove * 4);
	}
public:
	char * vfunc0();
};
#endif
