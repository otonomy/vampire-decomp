// CUtlLinkedList8: a CUtlLinkedList<T, unsigned short> whose nodes are 8 bytes (4 bytes of data, previous, next).
#pragma once

struct CUtlLinkedList8Node
{
	int m_Data;
	unsigned short m_Previous;
	unsigned short m_Next;
};

class CUtlLinkedList8
{
public:
	CUtlLinkedList8Node *m_pMemory;	// 0x00
	int m_allocationCount;	// 0x04
	int m_growSize;	// 0x08
	unsigned short m_Head;	// 0x0c
	unsigned short m_Tail;	// 0x0e
	unsigned short m_FirstFree;	// 0x10
	unsigned short m_ElementCount;	// 0x12
	unsigned short m_NumAlloced;	// 0x14
	short m_pad16;
	void *m_pElements;	// 0x18

	bool IsInList(unsigned short i) const { return i < m_NumAlloced && m_pMemory[i].m_Previous != i; }
	CUtlLinkedList8Node &InternalElement(unsigned short i) { return m_pMemory[i]; }

	void sub_100d3500();
	unsigned short sub_100d3b10(bool multilist);

	void sub_1002c080(unsigned short elem);	// "CUtlLinkedList::Unlink"
	void sub_100d1190(unsigned short elem);
	void sub_100d3a80(unsigned short elem);
	void sub_100efee0(unsigned short elem);
	void sub_10117ba0(unsigned short elem);
	void sub_10117c70(unsigned short elem);
};
