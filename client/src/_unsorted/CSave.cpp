// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10128e50 size=0x84
#include "CSave.h"

// TARGET: CSave::CSave
CSave::CSave(void *pData)
	: m_pSections(0), m_nAlloc(0), m_nGrow(0), m_nSections(0), m_pElements(0), m_pData(pData),
	  m_pEntityBlock(pData ? (char *)pData + 0x18 : 0)
{
	((CUtlVector<int> *)&m_pSections)->EnsureCapacity(0x20);
}
// END FUNCTION

// FUNCTION: 0x10128f00 size=0x13
#include "CSave.h"
namespace lifted {
int __stdcall sub_10129640(int, int, int);
}
void CSave::vfunc2(void * a0, const char * a1)
{
    lifted::sub_10129640(*(int *)&a0, *(int *)&a1, *(int *)&a1);
}
// END FUNCTION

// FUNCTION: 0x10128f20 size=0x4
#include "CSave.h"
int CSave::vfunc38()
{
    return *(int *)((char *)this + 0x1c);
}
// END FUNCTION

// FUNCTION: 0x10128f30 size=0x68
#include "CSave.h"

void *CSave::vfunc39(unsigned char bFree)
{
	((CUtlVector<int> *)((char *)this + 4))->~CUtlVector<int>();
	this->ISave::~ISave();
	if ( bFree & 1 )
		operator delete(this);
	return this;
}
// END FUNCTION

// FUNCTION: 0x10128fa0 size=0x7
#include "CSave.h"
int CSave::vfunc0()
{
    return *(int *)((char *)(*(int *)((char *)this + 0x18)) + 8);
}
// END FUNCTION

// FUNCTION: 0x10128fb0 size=0x1d
#include "CSave.h"

// TARGET: CSave::vfunc1
void CSave::vfunc1(int pos)
{
	int *piVar1 = (int *)m_pData;
	if (pos >= 0 && pos < piVar1[3]) {
		piVar1[2] = pos;
		piVar1[1] = piVar1[0] + pos;
	}
}
// END FUNCTION

// FUNCTION: 0x10128fd0 size=0x10
#include "CSave.h"
// TARGET: CSave::vfunc8
bool CSave::vfunc8(const void *pData, int nBytes) { return sub_101299c0(pData, nBytes * 2); }
// END FUNCTION

// FUNCTION: 0x10128fe0 size=0x14
#include "CSave.h"
bool CSave::vfunc10(const void *pData, int nBytes) { return sub_101299c0(pData, nBytes * 4); }
// END FUNCTION

// FUNCTION: 0x10129010 size=0x14
#include "CSave.h"
bool CSave::vfunc14(const void *pData, int nBytes) { return sub_101299c0(pData, nBytes * 4); }
// END FUNCTION

// FUNCTION: 0x10129040 size=0x21
#include "CSave.h"
#include <string.h>
void CSave::vfunc20(const char *pString) { sub_101299c0(pString, strlen(pString) + 1); }
// END FUNCTION

// FUNCTION: 0x10129070 size=0x40
#include "CSave.h"
#include <string.h>

extern char g_102de300[];

// TARGET: CSave::vfunc19
void CSave::vfunc19(const char **ppStrings, int count)
{
	for (int i = 0; i < count; i++) {
		const char *pString = ppStrings[i];
		if (!pString) {
			pString = g_102de300;
		}
		sub_101299c0(pString, strlen(pString) + 1);
	}
}
// END FUNCTION

// FUNCTION: 0x101290b0 size=0xf
#include "CSave.h"
// TARGET: CSave::vfunc24
void CSave::vfunc24(const Vector &value)
{
	sub_101299c0(&value, 12);
}
// END FUNCTION

// FUNCTION: 0x101290c0 size=0x13
#include "CSave.h"
void CSave::vfunc23(const void *pData, int count)
{
	sub_101299c0(pData, count * 12);
}
// END FUNCTION

// FUNCTION: 0x101290f0 size=0x1a
#include "CSave.h"

void CSave::vfunc7(int a, int b, int count)
{
    sub_10129830(a, count * 2, b);
}
// END FUNCTION

// FUNCTION: 0x10129110 size=0x1e
#include "CSave.h"

void CSave::vfunc9(const char *pszName, void *pData, int count)
{
    sub_10129830((int)pszName, count * 4, (int)pData);
}
// END FUNCTION

// FUNCTION: 0x10129130 size=0x17
#include "CSave.h"
namespace lifted {
struct C10129830 { int sub_10129830(int, int, int); };
}
int CSave::vfunc11(int a0, int a1, int a2)
{
    return ((lifted::C10129830 *)this)->sub_10129830(a0, a2, a1);
}
// END FUNCTION

// FUNCTION: 0x10129150 size=0x1e
#include "CSave.h"

void CSave::vfunc13(const char *pszName, void *pData, int count)
{
    sub_10129830((int)pszName, count * 4, (int)pData);
}
// END FUNCTION

// FUNCTION: 0x10129170 size=0x22
#include "CSave.h"
#include <string.h>
#pragma intrinsic(strlen)

void CSave::vfunc18(int a, const char *psz)
{
	sub_10129830(a, strlen(psz) + 1, (int)psz);
}
// END FUNCTION

// FUNCTION: 0x101291a0 size=0x59
#include "CSave.h"
#include <string.h>
void CSave::vfunc17(const char *pszName, void *pData, int count)
{
	const char **ppStrings = (const char **)pData;
	int total = 0;
	for (int i = 0; i < count; i++)
		total += strlen(ppStrings[i] ? ppStrings[i] : "") + 1;
	sub_10129860(pszName, total);
	vfunc19(ppStrings, count);
}
// END FUNCTION

// FUNCTION: 0x10129220 size=0x2b
#include "CSave.h"

// TARGET: CSave::vfunc21
void CSave::vfunc21(const char *pszName, const void *pData, int count)
{
	sub_10129860(pszName, count * sizeof(Vector));
	sub_101299c0(pData, count * sizeof(Vector));
}
// END FUNCTION

// FUNCTION: 0x101295b0 size=0x8a
#include "datamap.h"
#include "CSave.h"

struct CFieldView	// the 0x2c byte typedescription_t, only the offset
{
	char m_pad0000[8];
	int m_nOffset;
	char m_pad000c[0x2c - 0xc];
};

int CSave::vfunc3(int a, int b, int c, int d, int e)
{
	int nFieldsToSave = sub_10129560((const void *)b, (typedescription_t *)d, e);
	vfunc9((const char *)a, &nFieldsToSave, 1);
	for (int i = 0; i < e; i++, d += 0x2c) {
		CFieldView *pField = (CFieldView *)d;
		void *pData = (char *)b + pField->m_nOffset;
		if (!sub_10129250(pData, (typedescription_t *)pField))
			continue;
		if (!sub_10129540((const char *)a, pData, (void *)c, (typedescription_t *)pField))
			break;
	}
	return 1;
}
// END FUNCTION

// FUNCTION: 0x10129690 size=0xb9
#include "CSave.h"
#include "CUtlVector4.h"

extern "C" __declspec(dllimport) void *Plat_Alloc(unsigned int);
extern "C" __declspec(dllimport) void *Plat_Realloc(void *, unsigned int);

void CSave::vfunc5(const void *p)
{
	sub_10129860(p, 0);
	int pos = vfunc0();
	CUtlVector4 *v = (CUtlVector4 *)((char *)this + 4);
	int elem = v->m_size;
	if (1 + v->m_size > v->m_allocationCount && v->m_growSize != -1) {
		int newSize = v->m_allocationCount + (1 + v->m_size - v->m_allocationCount);
		while (v->m_allocationCount < newSize) {
			if (v->m_allocationCount != 0) {
				if (v->m_growSize != 0)
					v->m_allocationCount += v->m_growSize;
				else
					v->m_allocationCount += v->m_allocationCount;
			} else {
				v->m_allocationCount = 8;
			}
		}
		if (v->m_pMemory)
			v->m_pMemory = (int *)Plat_Realloc(v->m_pMemory, v->m_allocationCount * 4);
		else
			v->m_pMemory = (int *)Plat_Alloc(v->m_allocationCount * 4);
	}
	v->m_size += 1;
	v->m_pElements = v->m_pMemory;
	int numToMove = v->m_size - elem - 1;
	if (numToMove > 0)
		memmove(v->m_pMemory + elem + 1, v->m_pMemory + elem, numToMove * 4);
	int *dst = v->m_pMemory + elem;
	if (dst)
		*dst = pos;
}
// END FUNCTION

// FUNCTION: 0x10129750 size=0xb
#include "CSave.h"
namespace lifted {
extern char g_102de300;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual int f5(int); };
}
void CSave::vfunc4()
{
    ((lifted::V *)this)->f5((int)&lifted::g_102de300);
}
// END FUNCTION

// FUNCTION: 0x10129760 size=0x6d
#include "utlrbtree.h"
#include "CSave.h"

void CSave::vfunc6()
{
    CUtlVector<int> &stack = *(CUtlVector<int> *)((char *)this + 4);
    int pos = vfunc0();
    int start = (*(int **)&m_pSections)[stack.Count() - 1];
    int size = pos - start;
    stack.Remove(stack.Count() - 1);
    vfunc1(start - 4);
    sub_101299c0(&size, 2);
    vfunc1(pos);
}
// END FUNCTION

// FUNCTION: 0x10129b00 size=0x53
#include "CSave.h"
struct SaveEB { char pad[0x12e8]; float flOffset; };
void CSave::vfunc26(const char *pszName, void *pData, int count)
{
    sub_10129860(pszName, count * 4);
    for (int i = 0; i < count; i++) {
        float off = ((SaveEB *)m_pEntityBlock)->flOffset;
        float f = ((float *)pData)[i] - off;
        vfunc16(&f, 4);
    }
}
// END FUNCTION

// FUNCTION: 0x10129b60 size=0x3f
#include "CSave.h"
struct CSaveBlk { char pad[0x12e8]; float m_flOffset; };
void CSave::vfunc25(const float *pValues, int count)
{
	for (int i = 0; i < count; i++) {
		float f = ((CSaveBlk *)m_pEntityBlock)->m_flOffset;
		f = pValues[i] - f;
		vfunc16(&f, 4);
	}
}
// END FUNCTION

// FUNCTION: 0x10129ba0 size=0x81
#include "CSave.h"

struct CSaveEntityBlockView {
    char pad[0x12c4];
    int m_nLandmark;
    char pad2[0x12dc - 0x12c8];
    Vector m_vecLandmark;
};
extern Vector g_104d4970;

void CSave::vfunc30(const char *pszName, const Vector &value)
{
    CSaveEntityBlockView *pBlock = (CSaveEntityBlockView *)m_pEntityBlock;
    const Vector *pOffset;
    if (pBlock->m_nLandmark)
        pOffset = &pBlock->m_vecLandmark;
    else
        pOffset = &g_104d4970;
    Vector vecOffset = *pOffset;
    Vector vecOut = value - vecOffset;
    vfunc22(pszName, vecOut);
}
// END FUNCTION

// FUNCTION: 0x10129c30 size=0x7c
#include "CSave.h"

struct CSaveBlockX
{
	char m_pad0000[0x12c4];
	int m_bLandmark;	// 0x12c4
	char m_pad12c8[0x12dc - 0x12c8];
	Vector m_vecLandmarkOffset;	// 0x12dc
};

extern Vector g_104d4970;

void CSave::vfunc28(const Vector &value)
{
	CSaveBlockX *pBlock = (CSaveBlockX *)m_pEntityBlock;
	Vector vecOffset = pBlock->m_bLandmark ? pBlock->m_vecLandmarkOffset : g_104d4970;
	Vector vecResult = value - vecOffset;
	vfunc24(vecResult);
}
// END FUNCTION

// FUNCTION: 0x10129cb0 size=0x2d
#include "CSave.h"

// TARGET: CSave::vfunc29
void CSave::vfunc29(const char *pszName, void *pData, int count)
{
	sub_10129860(pszName, count * 12);
	vfunc27((const Vector *)pData, count);
}
// END FUNCTION

// FUNCTION: 0x10129ce0 size=0x8d
#include "CSave.h"

struct CSaveBlockX
{
	char m_pad0000[0x12c4];
	int m_bLandmark;	// 0x12c4
	char m_pad12c8[0x12dc - 0x12c8];
	Vector m_vecLandmarkOffset;	// 0x12dc
};

extern Vector g_104d4970;

inline Vector GetLandmarkOffsetX(CSaveBlockX *pBlock)
{
	return pBlock->m_bLandmark ? pBlock->m_vecLandmarkOffset : g_104d4970;
}

void CSave::vfunc27(const Vector *pValues, int count)
{
	for (int i = 0; i < count; i++) {
		Vector vecResult;
		vecResult = pValues[i] - GetLandmarkOffsetX((CSaveBlockX *)m_pEntityBlock);
		vfunc16(&vecResult, 12);
	}
}
// END FUNCTION

// FUNCTION: 0x10129d70 size=0x4c
#include "CSave.h"
#include <string.h>
const char *sub_10128d80(void *pMap, int pFunc);
__declspec(dllimport) void Warning(const char *fmt, ...);
void CSave::vfunc31(void *pBase, const char *pszName, void *pData, int count)
{
    const char *pName = sub_10128d80(pBase, *(int *)pData);
    if (pName) {
        sub_10129830((int)pszName, strlen(pName) + 1, (int)pName);
        return;
    }
    Warning("Invalid function pointer in entity!");
}
// END FUNCTION

// FUNCTION: 0x10129dc0 size=0x61
#include "CSave.h"
void CSave::vfunc33(const char *pszName, void *pData, int count)
{
	int tmp[256];
	for (int i = 0; i < count; i++)
		tmp[i] = sub_10129a30(((void **)pData)[i]);
	vfunc9(pszName, tmp, count);
}
// END FUNCTION

// FUNCTION: 0x10129e30 size=0x59
#include "CSave.h"
void CSave::vfunc32(const int *pHandles, int count)
{
	int indices[256];
	for (int i = 0; i < count; i++)
		indices[i] = sub_10129a30((void *)pHandles[i]);
	vfunc10(indices, count);
}
// END FUNCTION

// FUNCTION: 0x10129e90 size=0x56
#include "CSave.h"

int __stdcall sub_10129a20(int handle) { return -1; }

// TARGET: CSave::vfunc35
void CSave::vfunc35(const char *pszName, void *pData, int count)
{
    int buffer[256];
    for (int i = 0; i < count; i++)
        buffer[i] = sub_10129a20(((int *)pData)[i]);
    vfunc9(pszName, buffer, count);
}
// END FUNCTION

// FUNCTION: 0x10129ef0 size=0x4e
#include "CSave.h"

int __stdcall sub_10129a20(int)
{
	return -1;
}

// TARGET: CSave::vfunc34
void CSave::vfunc34(CSaveEdict *const *pEdicts, int count)
{
	int indices[256];
	int i = 0;
	if (count > 0)
	{
		do
		{
			indices[i] = sub_10129a20((int)pEdicts[i]);
		} while (++i < count);
	}
	vfunc10(indices, count);
}
// END FUNCTION

// FUNCTION: 0x10129f40 size=0x89
#include "CBaseEntityList.h"
#include "CSave.h"

struct EntInfo_t { void *m_pEntity; int m_SerialNumber; EntInfo_t *m_pPrev; };
struct EntList_t { int m_unk0; EntInfo_t m_EntPtrArray[8192]; };

struct EHandleT {
    unsigned long m_Index;
    void *Get() const
    {
        if (m_Index == 0xffffffff)
            return 0;
        EntInfo_t *pInfo = &((EntList_t *)g_pEntityList)->m_EntPtrArray[m_Index & 0x1fff];
        if (pInfo->m_SerialNumber == (int)(m_Index >> 13))
            return pInfo->m_pEntity;
        return 0;
    }
};

// TARGET: CSave::vfunc37
void CSave::vfunc37(const char *pszName, void *pData, int count)
{
    int entityArray[256];
    const EHandleT *pHandles = (const EHandleT *)pData;
    for (int i = 0; i < count; i++)
        entityArray[i] = sub_10129a30(pHandles[i].Get());
    vfunc9(pszName, entityArray, count);
}
// END FUNCTION

// FUNCTION: 0x10129fd0 size=0x81
#include "CSave.h"
#include "ehandle.h"

// TARGET: CSave::vfunc36
void CSave::vfunc36(const void *pData, int count)
{
	int buffer[256];
	const CBaseHandle *pHandles = (const CBaseHandle *)pData;

	for (int i = 0; i < count; i++)
		buffer[i] = sub_10129a30(pHandles[i].Get());

	vfunc10(buffer, count);
}
// END FUNCTION
