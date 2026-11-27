// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101105e0 size=0x1e
#include "CPanelMetaClassMgrImp.h"

// VC6 writes CPanelMetaClassMgrImp's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CPanelMetaClassMgrImp *pcd_emit_101105e0() { return new CPanelMetaClassMgrImp; }

// TARGET: ??_GCPanelMetaClassMgrImp@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10110600 size=0x91
#include "CPanelMetaClassMgrImp.h"
#include "CUnknown1024b370.h"

extern "C" __declspec(dllimport) void Plat_Free(void *p);

struct Mem_10110600 {
	void *m_pMemory;
	int m_allocationCount;
	int m_growSize;
};

#define MEM_PURGE_(m) \
	if ((m).m_growSize != -1) { \
		if ((m).m_pMemory) { \
			Plat_Free((m).m_pMemory); \
			(m).m_pMemory = 0; \
		} \
		(m).m_allocationCount = 0; \
	}

CPanelMetaClassMgrImp::~CPanelMetaClassMgrImp()
{
	((CUnknown1024b370 *)((char *)this + 0xa4))->sub_1013d330();
	MEM_PURGE_(*(Mem_10110600 *)((char *)this + 0x90));
	((CUnknown1024b370 *)((char *)this + 0x60))->sub_1013d330();
	MEM_PURGE_(*(Mem_10110600 *)((char *)this + 0x4c));
	((CUnknown1024b370 *)((char *)this + 0x1c))->sub_1013d330();
	MEM_PURGE_(*(Mem_10110600 *)((char *)this + 0x8));
}
// END FUNCTION

// FUNCTION: 0x101106a0 size=0x120
#include "CPanelMetaClassMgrImp.h"
#include "CUtlRBTree16.h"
#include "CUnknown1024b370.h"
#include "Tier1.h"
#include <string.h>
#include <malloc.h>
#pragma intrinsic(strlen)
struct DictElem
{
	CUnknown1024b370Symbol sym;
	int value;
	static void *operator new(unsigned int, void *p) { return p; }
};
struct CMetaDict : public CUtlRBTree16
{
	CUnknown1024b370 m_Symbols;
};
void CPanelMetaClassMgrImp::sub_101106a0(const char *pName, void *pElement)
{
	int len = strlen(pName) + 1;
	char *tmp = (char *)alloca(len);
	g_101e3188(tmp, pName, len);
	g_101e31e0(tmp, len);
	CMetaDict *d = (CMetaDict *)((char *)this + 4);
	DictElem key;
	key.sym = CUnknown1024b370Symbol(0xffff);
	key.sym = d->m_Symbols.sub_1013d520(tmp);
	unsigned short current = d->m_Root;
	unsigned short parent = 0xffff;
	bool leftchild = false;
	while (current != 0xffff)
	{
		parent = current;
		if (d->m_LessFunc(&key, &d->m_pElements[current].m_Data))
		{
			leftchild = true;
			current = d->sub_10112720(current).m_Left;
		}
		else
		{
			leftchild = false;
			current = d->sub_10112720(current).m_Right;
		}
	}
	unsigned short i = d->sub_10112270();
	d->sub_10112390(i, parent, leftchild);
	d->m_NumElements++;
	new (&d->m_pElements[i].m_Data) DictElem(key);
	((DictElem *)&d->m_pElements[i].m_Data)->value = (int)pElement;
}
// END FUNCTION
