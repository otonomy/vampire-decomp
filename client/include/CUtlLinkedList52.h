// CUtlLinkedList52: a CUtlLinkedList<T, unsigned short> whose nodes are 0x34 bytes (0x30 of data, previous, next).
#pragma once

struct CUtlLinkedList52Node
{
	char m_Data[0x30];
	unsigned short m_Previous;
	unsigned short m_Next;
};

class CUtlLinkedList52
{
public:
	typedef CUtlLinkedList52Node Node;
	Node *m_pMemory;	// 0x00
	int m_allocationCount;	// 0x04
	int m_growSize;	// 0x08
	unsigned short m_Head;	// 0x0c
	unsigned short m_Tail;	// 0x0e
	unsigned short m_FirstFree;	// 0x10
	unsigned short m_ElementCount;	// 0x12
	unsigned short m_NumAlloced;	// 0x14
	unsigned short m_pad16;
	Node *m_pElements;	// 0x18 (debug pointer)

	void sub_100d3600(unsigned short before, unsigned short node);	// LinkBefore
};
