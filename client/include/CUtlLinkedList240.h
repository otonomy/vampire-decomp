// CUtlLinkedList240: a CUtlLinkedList<T, unsigned short> whose nodes are 0xf0 bytes (0xec of data, previous, next).
#pragma once

struct CUtlLinkedList240Node
{
	char m_Data[0xec];
	unsigned short m_Previous;
	unsigned short m_Next;
};

class CUtlLinkedList240
{
public:
	CUtlLinkedList240Node *m_pMemory;	// 0x00
	int m_allocationCount;	// 0x04
	int m_growSize;	// 0x08
	unsigned short m_Head;	// 0x0c
	unsigned short m_Tail;	// 0x0e
	unsigned short m_FirstFree;	// 0x10
	unsigned short m_ElementCount;	// 0x12
	unsigned short m_TotalElements;	// 0x14
	unsigned short m_pad16;
	CUtlLinkedList240Node *m_pElements;	// 0x18 (debug pointer)

	static unsigned short InvalidIndex() { return (unsigned short)~0; }
	CUtlLinkedList240Node &InternalElement(unsigned short i) { return m_pMemory[i]; }

	unsigned short sub_100d8c90(bool multilist);
	void sub_100d8b40(unsigned short before, unsigned short elem);	// "CUtlLinkedList::LinkBefore"
	bool IsInList(unsigned short i) const { return i < m_TotalElements && m_pMemory[i].m_Previous != i; }	// "CUtlLinkedList::AllocInternal"
};
