// CUtlLinkedList12S: a CUtlLinkedList<T, unsigned short> whose nodes are 12 bytes (8 bytes of data, previous, next).
#pragma once

struct CUtlLinkedList12SNode
{
	char m_Data[8];
	unsigned short m_Previous;
	unsigned short m_Next;
};

class CUtlLinkedList12S
{
public:
	CUtlLinkedList12SNode *m_pMemory;	// 0x00
	int m_allocationCount;	// 0x04
	int m_growSize;	// 0x08
	unsigned short m_Head;	// 0x0c
	unsigned short m_Tail;	// 0x0e
	unsigned short m_FirstFree;	// 0x10
	unsigned short m_ElementCount;	// 0x12
	unsigned short m_NumAlloced;	// 0x14
	short m_pad16;
	CUtlLinkedList12SNode *m_pElements;	// 0x18 (debug pointer)

	unsigned short sub_100d3970(bool multilist);	// "CUtlLinkedList::AllocInternal"
};
