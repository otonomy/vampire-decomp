// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1012a170 size=0x8b
#include "CRestore.h"
extern void *(*g_101e3104)(void *, int);
extern void *(*g_101e3100)(int);

inline void CRestoreVec::EnsureCapacity(int num)
{
	if (m_allocationCount < num && m_growSize != -1) {
		m_allocationCount = num;
		if (m_pMemory)
			m_pMemory = (int *)g_101e3104(m_pMemory, num * 4);
		else
			m_pMemory = (int *)g_101e3100(num * 4);
	}
	m_pElements = m_pMemory;
}

// TARGET: CRestore::CRestore
CRestore::CRestore(void *pData) : m_pData(pData), m_pData2(pData ? (char *)pData + 0x18 : 0), m_field20(0), m_bField24(true)
{
	m_vec.EnsureCapacity(32);
}
// END FUNCTION

// FUNCTION: 0x1012a220 size=0x13
#include "CRestore.h"
namespace lifted {
int __stdcall sub_1012ab00(int, int, int);
}
int CRestore::vfunc2(CBaseEntity * a0, int a1)
{
    return lifted::sub_1012ab00(*(int *)&a0, a1, a1);
}
// END FUNCTION

// FUNCTION: 0x1012a240 size=0x16
#include "CRestore.h"
int CRestore::vfunc10()
{
	unsigned short v;
	vfunc9(&v);
	return v;
}
// END FUNCTION

// FUNCTION: 0x1012a260 size=0x4
#include "CRestore.h"
bool CRestore::vfunc32()
{
    return *(bool *)((char *)this + 0x24);
}
// END FUNCTION

// FUNCTION: 0x1012a270 size=0x4
#include "CRestore.h"
int CRestore::vfunc33()
{
    return *(int *)((char *)this + 0x1c);
}
// END FUNCTION

// FUNCTION: 0x1012a280 size=0x68
#include "CRestore.h"
#include "utlvector.h"

extern char vt_1023653c;

void *CRestore::vfunc34(unsigned char bFree)
{
	((CUtlVector<int> *)&m_vec)->~CUtlVector<int>();
	*(void **)this = &vt_1023653c;
	if (bFree & 1)
		::operator delete(this);
	return this;
}
// END FUNCTION

// FUNCTION: 0x1012a2f0 size=0x7
#include "CRestore.h"

// TARGET: CRestore::sub_1012a2f0
int CRestore::sub_1012a2f0()
{
	return *(int *)((char *)m_pData + 8);
}
// END FUNCTION

// FUNCTION: 0x1012a300 size=0x1d
#include "CRestore.h"

// TARGET: CRestore::vfunc1
void CRestore::vfunc1(int pos)
{
	int *piVar1 = (int *)m_pData;
	if (pos >= 0 && pos < piVar1[3]) {
		piVar1[2] = pos;
		piVar1[1] = piVar1[0] + pos;
	}
}
// END FUNCTION

// FUNCTION: 0x1012a320 size=0x2a
#include "CRestore.h"

extern char g_102de300[];
extern char g_102c3974[];

struct CTokenTbl {
	char pad[0x10]; int m_nCount; char **m_ppStr;
	const char *StringFromSymbol(int token)
	{
		if (token >= 0 && token < m_nCount)
			return m_ppStr[token];
		return g_102c3974;
	}
};

const char *CRestore::vfunc11(int token)
{
	CTokenTbl *t = *(CTokenTbl **)((char *)this + 0x18);
	const char *s = t->StringFromSymbol(token);
	if (s)
		return s;
	return g_102de300;
}
// END FUNCTION

// FUNCTION: 0x1012a610 size=0xbb
#include <string.h>
#include "CRestore.h"

struct SaveRestoreFieldInfo_t
{
	void *pField;
	void *pOwner;
	typedescription_t *pTypeDesc;
};

struct ISaveRestoreOpsLocal
{
	virtual void s0();
	virtual void s1();
	virtual void s2();
	virtual void Empty(SaveRestoreFieldInfo_t *pFieldInfo);
};

struct datamap_t
{
	typedescription_t *dataDesc;
	int dataNumFields;
};

struct typedescription_t
{
	int fieldType;
	const char *fieldName;
	int fieldOffset[2];
	unsigned short fieldSize;
	short flags;
	const char *externalName;
	ISaveRestoreOpsLocal *pSaveRestoreOps;
	void *inputFunc;
	datamap_t *td;
	int fieldSizeInBytes;
	int unk;
};

extern int g_102c34b8[];

// TARGET: CRestore::vfunc4
void CRestore::vfunc4(void *pBaseData, typedescription_t *pFields, int fieldCount)
{
	for (int i = 0; i < fieldCount; i++)
	{
		typedescription_t *pField = &pFields[i];
		if (!sub_1012a5e0(pField))
			continue;
		void *pData = (char *)pBaseData + pField->fieldOffset[0];
		if (pField->fieldType == 10)
		{
			SaveRestoreFieldInfo_t fieldInfo;
			fieldInfo.pField = pData;
			fieldInfo.pOwner = pBaseData;
			fieldInfo.pTypeDesc = pField;
			pField->pSaveRestoreOps->Empty(&fieldInfo);
		}
		else if (pField->fieldType == 9)
		{
			if (pField->flags & 0x40)
				pData = *(void **)pData;
			vfunc4(pData, pField->td->dataDesc, pField->td->dataNumFields);
		}
		else
		{
			memset(pData, 0, g_102c34b8[pField->fieldType] * (short)pField->fieldSize);
		}
	}
}
// END FUNCTION

// FUNCTION: 0x1012a6d0 size=0xbe
#include "CRestore.h"

extern "C" void *__cdecl memmove(void *, const void *, unsigned int);
extern void *(*g_101e3100)(unsigned int);	// Plat_Alloc
extern void *(*g_101e3104)(void *, unsigned int);	// Plat_Realloc

struct RestoreSlots
{
	virtual int s0();
	virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
	virtual void s9(unsigned short *p);
};

void CRestore::sub_1012a6d0(unsigned short *pValue)
{
	((RestoreSlots *)this)->s9(pValue);
	int value = ((RestoreSlots *)this)->s0() + *pValue;
	int elem = m_vec.m_size;
	if (m_vec.m_size + 1 > m_vec.m_allocationCount) {
		if (m_vec.m_growSize != -1) {
			int num = m_vec.m_size + 1 - m_vec.m_allocationCount;
			int nAllocationRequested = m_vec.m_allocationCount + num;
			while (m_vec.m_allocationCount < nAllocationRequested) {
				if (m_vec.m_allocationCount != 0) {
					if (m_vec.m_growSize != 0)
						m_vec.m_allocationCount += m_vec.m_growSize;
					else
						m_vec.m_allocationCount += m_vec.m_allocationCount;
				} else {
					m_vec.m_allocationCount = 8;
				}
			}
			if (m_vec.m_pMemory)
				m_vec.m_pMemory = (int *)g_101e3104(m_vec.m_pMemory, m_vec.m_allocationCount * 4);
			else
				m_vec.m_pMemory = (int *)g_101e3100(m_vec.m_allocationCount * 4);
		}
	}
	m_vec.m_pElements = m_vec.m_pMemory;
	m_vec.m_size++;
	int toMove = m_vec.m_size - elem - 1;
	if (toMove > 0)
		memmove(&m_vec.m_pMemory[elem + 1], &m_vec.m_pMemory[elem], toMove * 4);
	int *p = &m_vec.m_pMemory[elem];
	if (p)
		*p = value;
}
// END FUNCTION

// FUNCTION: 0x1012a790 size=0x3b
#include "CRestore.h"

__declspec(dllimport) char *Q_strncpy(char *pDest, const char *pSrc, int nMaxLen);

// TARGET: CRestore::vfunc6
void CRestore::vfunc6(void *pData)
{
	unsigned short value[2];
	vfunc7(value);
	Q_strncpy((char *)pData, vfunc11(value[1]), 0x20);
}
// END FUNCTION

// FUNCTION: 0x1012a7d0 size=0x11
#include "CRestore.h"
// TARGET: CRestore::vfunc5
void CRestore::vfunc5() { char buf[32]; vfunc6(buf); }
// END FUNCTION

// FUNCTION: 0x1012a7f0 size=0x42
#include "utlrbtree.h"
#include "CRestore.h"
#include "utlvector.h"

struct CRestoreSlot1 { virtual void a(); virtual void vfunc1(int v); };

// TARGET: CRestore::vfunc8
void CRestore::vfunc8()
{
	const CUtlVector<int> *pVec = (const CUtlVector<int> *)&m_vec;
	int v = pVec->Element(pVec->Count() - 1);
	((CUtlVector<int> *)&m_vec)->Remove(pVec->Count() - 1);
	((CRestoreSlot1 *)this)->vfunc1(v);
}
// END FUNCTION

// FUNCTION: 0x1012aa70 size=0x30
#include "CRestore.h"
void CRestore::vfunc9(unsigned short *pValue)
{
	if (pValue) {
		pValue[0] = vfunc13();
		pValue[1] = vfunc13();
		return;
	}
	sub_1012abd0(4);
}
// END FUNCTION

// FUNCTION: 0x1012aaa0 size=0x1c
#include "CRestore.h"

// TARGET: CRestore::vfunc13
short CRestore::vfunc13()
{
	int v = 0;
	sub_1012ab60(&v, 2);
	return v;
}
// END FUNCTION

// FUNCTION: 0x1012aac0 size=0x1b
// TARGET: CRestore::vfunc14
#include "CRestore.h"
int CRestore::vfunc14()
{
	int v = 0;
	sub_1012ab60(&v, 4);
	return v;
}
// END FUNCTION

// FUNCTION: 0x1012aae0 size=0x18
#include "CRestore.h"
char CRestore::vfunc16()
{
	char c = 0;
	sub_1012ab60(&c, 1);
	return c;
}
// END FUNCTION

// FUNCTION: 0x1012abe0 size=0x3f
#include "CRestore.h"

struct CRestoreCalleePlaceholder {
    void sub_1012ab60(int a, int n);
    void sub_1012abd0(int n);
};

// TARGET: CRestore::vfunc12
unsigned int CRestore::vfunc12(int a, int b, int c)
{
    int n = b * 2;
    if (c != 0 && n >= c) {
        n = c;
    }
    ((CRestoreCalleePlaceholder *)this)->sub_1012ab60(a, n);
    if (n < c) {
        ((CRestoreCalleePlaceholder *)this)->sub_1012abd0(c - n);
    }
    return (unsigned int)n >> 1;
}
// END FUNCTION

// FUNCTION: 0x1012ac70 size=0x3a
#include "CRestore.h"

// TARGET: CRestore::vfunc17
int CRestore::vfunc17(void *p, int count, int nBytesAvailable)
{
	int desired = count * sizeof(char);
	int actual = (nBytesAvailable == 0) ? desired : ((desired < nBytesAvailable) ? desired : nBytesAvailable);
	sub_1012ab60(p, actual);
	if (actual < nBytesAvailable)
		sub_1012abd0(nBytesAvailable - actual);
	return actual / sizeof(char);
}
// END FUNCTION

// FUNCTION: 0x1012acb0 size=0x44
#include "CRestore.h"

// TARGET: CRestore::vfunc18
int CRestore::vfunc18(float *pValues, int count, int nBytesAvailable)
{
	int n = count * sizeof(float);
	if (nBytesAvailable != 0 && n >= nBytesAvailable)
	{
		n = nBytesAvailable;
	}
	sub_1012ab60(pValues, n);
	if (n < nBytesAvailable)
	{
		sub_1012abd0(nBytesAvailable - n);
	}
	return (unsigned int)n / sizeof(float);
}
// END FUNCTION

// FUNCTION: 0x1012ad00 size=0x3a
#include "CRestore.h"

// TARGET: CRestore::vfunc19
int CRestore::vfunc19(void *p, int count, int nBytesAvailable)
{
	int desired = count * sizeof(char);
	int actual = (nBytesAvailable == 0) ? desired : ((desired < nBytesAvailable) ? desired : nBytesAvailable);
	sub_1012ab60(p, actual);
	if (actual < nBytesAvailable)
		sub_1012abd0(nBytesAvailable - actual);
	return actual / sizeof(char);
}
// END FUNCTION

// FUNCTION: 0x1012ad40 size=0x2a
#include "CRestore.h"

extern void (*g_101e3188)(char *, const char *, int);
void __stdcall sub_1012abd0(int n);

// TARGET: CRestore::vfunc21
void CRestore::vfunc21(char *pDest, int n, int a)
{
    const char *src = (const char *)sub_1012ab50();
    ::sub_1012abd0(a);
    g_101e3188(pDest, src, n);
}
// END FUNCTION

// FUNCTION: 0x1012ad70 size=0x7b
#include "CRestore.h"
#include "CUnknown101a1f70.h"

struct PooledString1042
{
	PooledString1042() {}
	PooledString1042(const PooledString1042 &o) : m_v(o.m_v) {}
	PooledString1042 &operator=(const PooledString1042 &o) { m_v = o.m_v; return *this; }
	int m_v;
};
PooledString1042 sub_100ee890(const char *psz);

struct CRestoreUnit : CRestore
{
	void sub_1012abd0(int nBytes);
};

// TARGET: CRestore::vfunc20
int CRestore::vfunc20(int *pValues, int count, int nBytesAvailable)
{
	const char *pString = (const char *)((CUnknown101a1f70 *)this)->sub_1012ab50();
	const char *pLimit = pString + nBytesAvailable;
	int nRead = 0;
	PooledString1042 *pDest = (PooledString1042 *)pValues;
	while (nRead < count && pString < pLimit)
	{
		if (*pString == 0)
			pDest[nRead].m_v = 0;
		else
			pDest[nRead] = sub_100ee890(pString);
		while (*pString)
			pString++;
		pString++;
		nRead++;
	}
	((CRestoreUnit *)this)->sub_1012abd0(nBytesAvailable);
	return nRead;
}
// END FUNCTION

// FUNCTION: 0x1012adf0 size=0x14
#include "CRestore.h"
namespace lifted {
int __stdcall sub_1012ab60(int, int);
}
int CRestore::vfunc23(int a0)
{
    lifted::sub_1012ab60(a0, 0xc);
    return 1;
}
// END FUNCTION

// FUNCTION: 0x1012ae10 size=0x4c
#include "CRestore.h"

int CRestore::vfunc22(Vector *pValues, int count, int nBytesAvailable)
{
	int desired = count * 12;
	int actual;

	if (nBytesAvailable == 0)
		actual = desired;
	else
	{
		actual = ((desired < nBytesAvailable) ? desired : nBytesAvailable);
	}

	sub_1012ab60(pValues, actual);

	if (actual < nBytesAvailable)
		sub_1012abd0(nBytesAvailable - actual);

	return (actual / 12u);
}
// END FUNCTION

// FUNCTION: 0x1012af00 size=0x96
#include "CRestore.h"
#include <string.h>
// TARGET: CRestore::vfunc28
int CRestore::vfunc28(CBaseEntity **pValues, int count, int nBytesAvailable)
{
	int entityIndex[256];
	int nRead = vfunc15(entityIndex, count, nBytesAvailable);
	for (int i = 0; i < nRead; i++)
		pValues[i] = sub_1012ae60(entityIndex[i]);
	if (nRead < count)
		memset(&pValues[nRead], 0, (count - nRead) * sizeof(pValues[0]));
	return nRead;
}
// END FUNCTION

// FUNCTION: 0x1012afa0 size=0x5
#include "CRestore.h"
int CRestore::vfunc29(int * a0, int a1, int a2)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1012afb0 size=0xaa
#include "CRestore.h"
extern "C" void *__cdecl memset(void *, int, unsigned int);

struct HandleSrc {
	virtual void pad0();
	virtual unsigned int *GetRefEHandle();
};

int CRestore::vfunc30(unsigned int *pValues, int count, int nBytesAvailable)
{
	int buf[256];
	int n = vfunc15(buf, count, nBytesAvailable);
	for (int i = 0; i < n; i++) {
		HandleSrc *e = (HandleSrc *)sub_1012ae60(buf[i]);
		if (e)
			pValues[i] = *e->GetRefEHandle();
		else
			pValues[i] = 0xffffffff;
	}
	if (n < count)
		memset(&pValues[n], 0, (count - n) * sizeof(unsigned int));
	return n;
}
// END FUNCTION

// FUNCTION: 0x1012b060 size=0xec
#include "CBaseEntityList.h"
#include "CRestore.h"
#include "ehandle.h"

extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)

int CRestore::vfunc31(int *pValues, int nCount, int nBytesAvailable)
{
    int buf[256];
    int nRead = vfunc15(buf, nCount, nBytesAvailable);
    for (int i = 0; i < nRead; i++)
    {
        CRestoreSaveEnt *pRec = sub_1012aec0(buf[i]);
        pValues[i] = -1;
        if (!pRec)
            continue;
        unsigned int &h = pRec->m_hEntity;
        if (h != 0xffffffff)
        {
            CBaseEntityListEntry &e = g_pEntityList->m_EntPtrArray[h & 0x1fff];
            if (e.m_SerialNumber == (int)(h >> 13) && e.m_pEntity)
            {
                pValues[i] = pRec->m_hEntity;
                continue;
            }
        }
        int idx = pRec->m_nIndex;
        if (idx > 0 && idx < 0xffff)
            pValues[i] = -idx;
    }
    if (nRead < nCount)
        memset(&pValues[nRead], 0, (nCount - nRead) * sizeof(int));
    return nRead;
}
// END FUNCTION

// FUNCTION: 0x1012b280 size=0x3d
#include "CRestore.h"

// TARGET: CRestore::vfunc24
int CRestore::vfunc24(float *pValues, int count, int nBytesAvailable)
{
	float flAdd = *(float *)(m_pData2 + 0x12e8);
	int n = vfunc18(pValues, count, nBytesAvailable);
	for (int i = n - 1; i >= 0; i--)
		pValues[i] = flAdd + pValues[i];
	return n;
}
// END FUNCTION

// FUNCTION: 0x1012b2e0 size=0x7f
#include "CRestore.h"

extern Vector g_104d4970;

// TARGET: CRestore::vfunc25
int CRestore::vfunc25(Vector *pValues, int count, int nBytesAvailable)
{
	const Vector *pOffset;
	if (*(int *)(m_pData2 + 0x12c4))
		pOffset = (const Vector *)(m_pData2 + 0x12dc);
	else
		pOffset = &g_104d4970;
	Vector vecOffset = *pOffset;
	int nRead = vfunc22(pValues, count, nBytesAvailable);
	for (int i = nRead - 1; i >= 0; i--)
		VectorAdd(vecOffset, pValues[i], pValues[i]);
	return nRead;
}
// END FUNCTION

// FUNCTION: 0x1012b360 size=0x41
#include "CRestore.h"
namespace lifted {
int sub_10128dd0(int, int);
int sub_1012ab50();
int __stdcall sub_1012abd0(int);
}
int CRestore::vfunc27(void * a0, int * a1, int a2, int a3)
{
    int t0 = lifted::sub_1012ab50();
    int t1 = lifted::sub_1012abd0(a3);
    if ((*(char *)((char *)t0)) == 0) {
        *(int *)((char *)*(int *)&a1) = 0;
        return 0;
    }
    *(int *)((char *)*(int *)&a1) = lifted::sub_10128dd0(*(int *)&a0, t0);
    return 0;
}
// END FUNCTION
