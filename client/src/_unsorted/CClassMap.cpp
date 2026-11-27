// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100cded0 size=0x288
#include "CClassMap.h"

extern "C" __declspec(dllimport) void DevMsg(int level, const char *pMsg, ...);
extern "C" __declspec(dllimport) int Q_strcasecmp(const char *s1, const char *s2);
extern "C" __declspec(dllimport) char *Q_strncpy(char *pDest, const char *pSrc, int maxLen);

typedef void *(*DISPATCHFUNCTION)(void);

struct classentry_t
{
	classentry_t()
	{
		mapname[0] = 0;
		factory = 0;
		size = -1;
	}
	char mapname[128];
	DISPATCHFUNCTION factory;
	int size;
};

struct ClassDictNode
{
	ClassDictNode() : key(0xffff) {}
	CUnknown1024b370Symbol key;
	classentry_t elem;
};

struct ClassDictTreeNode
{
	unsigned short m_Left;
	unsigned short m_Right;
	unsigned short m_Parent;
	unsigned short m_Tag;
	ClassDictNode m_Data;
};

void sub_100ce8f0(ClassDictNode *pMemory, const ClassDictNode &src);	// CopyConstruct

// the dictionary at CClassMap +4 (CUtlDict<classentry_t, unsigned short>): a CUtlRBTree of ClassDictNode, then the
// symbol table of the class names
struct CClassDictTree
{
	bool (*m_LessFunc)(const ClassDictNode &, const ClassDictNode &);
	ClassDictTreeNode *m_pMemory;
	int m_nAllocationCount;
	int m_nGrowSize;
	unsigned short m_Root;
	unsigned short m_NumElements;
	unsigned short m_FirstFree;
	unsigned short m_TotalElements;
	CUnknown1024b370 m_Symbols;

	unsigned short sub_100ce3f0(unsigned short parent, bool leftchild);	// InsertAt
	void sub_100ce560(unsigned short i);	// RemoveNode

	ClassMapEntry *Links(unsigned short i) { return ((CClassMap *)this)->sub_100ce920(i); }

	unsigned short Find(const char *pName)
	{
		ClassDictNode node;
		node.key = m_Symbols.sub_1013d520(pName);
		unsigned short current = m_Root;
		while (current != 0xffff) {
			if (m_LessFunc(node, m_pMemory[current].m_Data))
				current = Links(current)->m_iLeft;
			else if (m_LessFunc(m_pMemory[current].m_Data, node))
				current = Links(current)->m_iRight;
			else
				break;
		}
		return current;
	}

	void RemoveAt(unsigned short i)
	{
		if (i != 0xffff) {
			sub_100ce560(i);
			m_pMemory[i].m_Left = i;
			m_pMemory[i].m_Right = m_FirstFree;
			m_FirstFree = i;
			--m_NumElements;
		}
	}

	unsigned short Insert(const char *pName, const classentry_t &insert)
	{
		ClassDictNode node;
		node.key = m_Symbols.sub_1013d520(pName);
		unsigned short current = m_Root;
		unsigned short parent = 0xffff;
		bool leftchild = false;
		while (current != 0xffff) {
			parent = current;
			if (m_LessFunc(node, m_pMemory[current].m_Data)) {
				leftchild = true;
				current = Links(current)->m_iLeft;
			} else {
				leftchild = false;
				current = Links(current)->m_iRight;
			}
		}
		unsigned short i = sub_100ce3f0(parent, leftchild);
		sub_100ce8f0(&m_pMemory[i].m_Data, node);
		m_pMemory[i].m_Data.elem = insert;
		return i;
	}
};

#define m_ClassDict (*(CClassDictTree *)&m_pfnLess)

void CClassMap::vfunc0(const char *mapname, const char *classname, int size, DISPATCHFUNCTION factory)
{
	DevMsg(1, "CClassMap::Add( %s, %s, %d )\n", mapname, classname, size);

	const char *map = vfunc1(classname);
	if (map && !Q_strcasecmp(mapname, map))
		return;

	if (map) {
		int index = m_ClassDict.Find(classname);
		m_ClassDict.RemoveAt(index);
	}

	classentry_t element;
	Q_strncpy(element.mapname, mapname, sizeof(element.mapname));
	element.factory = factory;
	element.size = size;
	m_ClassDict.Insert(classname, element);
}
// END FUNCTION

// FUNCTION: 0x100ce160 size=0x140
#include "CClassMap.h"

struct ClassRec_100ce160
{
	char m_name[0x80];
	int m_a;
	int m_b;
	ClassRec_100ce160() { m_name[0] = 0; m_a = 0; m_b = -1; }
	~ClassRec_100ce160() {}
};

struct ClassKey_100ce160
{
	CUnknown1024b370Symbol m_sym;
	ClassRec_100ce160 m_rec;
	ClassKey_100ce160() : m_sym(0xffff) {}
};

struct ClassTree_100ce160
{
	bool (*m_pfnLess)(const void *, const void *);
	ClassMapEntry *m_pElements;
	int m_nAlloc;
	int m_nGrow;
	unsigned short m_Root;
	unsigned short m_pad12, m_pad14, m_pad16;
	CUnknown1024b370 m_Symbols;
	ClassMapEntry *sub_100ce920(unsigned short i);
};

// TARGET: CClassMap::vfunc1
const char *CClassMap::vfunc1(const char *classname)
{
	static ClassRec_100ce160 s_rec;
	ClassTree_100ce160 *t = (ClassTree_100ce160 *)((char *)this + 4);
	ClassKey_100ce160 key;
	key.m_sym = ((CUnknown1024b370 *)((char *)t + 0x18))->sub_1013d520(classname);
	unsigned short i = t->m_Root;
	while (i != 0xffff)
	{
		if (t->m_pfnLess(&key, (char *)t->m_pElements + i * 0x94 + 8))
			i = t->sub_100ce920(i)->m_iLeft;
		else if (t->m_pfnLess((char *)t->m_pElements + i * 0x94 + 8, &key))
			i = t->sub_100ce920(i)->m_iRight;
		else
			break;
	}
	if (i == 0xffff)
		return 0;
	s_rec = *(ClassRec_100ce160 *)((char *)m_Memory.m_pMemory + i * 0x94 + 0xc);
	return (const char *)&s_rec;
}
// END FUNCTION

// FUNCTION: 0x100ce2b0 size=0x8b
#include "CClassMap.h"
#include <string.h>
void *CClassMap::vfunc2(const char *classname)
{
	for (int i = 0; i < m_NumElements; i++)
	{
		const char *pszName = (const char *)&m_Memory[(unsigned short)i] + 0xc;
		if (pszName && !strcmp(pszName, classname))
		{
			if (*(void *(**)())(pszName + 0x80))
				return (*(void *(**)())(pszName + 0x80))();
		}
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x100ce340 size=0x82
#include <string.h>
#include "CClassMap.h"
#include "utlrbtree.h"

struct classentry_100ce340
{
	char mapname[128];
	void *factory;
	int size;
};

struct DictElem_100ce340
{
	const char *pszName;
	classentry_100ce340 elem;
};

struct ClassMapFields_100ce340
{
	void *vtable;
	CUtlRBTree<DictElem_100ce340, unsigned short> m_Elements;
};

// TARGET: CClassMap::vfunc3
int CClassMap::vfunc3(const char *classname)
{
	ClassMapFields_100ce340 *self = (ClassMapFields_100ce340 *)this;
	int c = self->m_Elements.Count();
	for (int i = 0; i < c; i++)
	{
		classentry_100ce340 *lookup = &self->m_Elements[i].elem;
		if (!lookup)
			continue;

		if (!strcmp(lookup->mapname, classname))
			return lookup->size;
	}
	return -1;
}
// END FUNCTION
