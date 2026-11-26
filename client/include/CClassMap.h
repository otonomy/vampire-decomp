// CClassMap: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "IClassMap.h"
#include "utlmemory.h"
#include "CUnknown1024b2d0.h"
#include "CUnknown1024b370.h"

struct ClassMapEntry
{
    unsigned short m_iLeft;
    unsigned short m_iRight;
    unsigned short m_iParent;
    unsigned short m_iHeight;
    char m_pad08[0x94 - 8];
};

int sub_100ce3d0(const void *a, const void *b);

class CClassMap : public IClassMap
{
public:
    CClassMap()
        : m_pfnLess((void *)sub_100ce3d0), m_Memory(0, 0), m_Root(0xffff), m_NumElements(0), m_FirstFree(0xffff), m_TotalElements(0), m_Symbols(0, 0, 1)
    {
    }
    ~CClassMap() { m_Symbols.sub_1013d330(); }
    union {
        void *m_pfnLess;
        ClassMapEntry *m_pElements;
    };
    CUtlMemory<ClassMapEntry> m_Memory;
    unsigned short m_Root;
    unsigned short m_NumElements;
    unsigned short m_FirstFree;
    unsigned short m_TotalElements;
    CUnknown1024b370 m_Symbols;
    ClassMapEntry *sub_100ce920(unsigned short i);
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with CClassMap's own function
    virtual void vfunc0(const char *mapname, const char *classname, int size, void *(*factory)(void));	// Add: DevMsg, replaces an entry of another map name, inserts the class entry
    virtual const char *vfunc1(const char *classname);	// Lookup
    virtual void *vfunc2(const char *classname);
    virtual int vfunc3(const char *classname);
};
