#pragma once
#include "IRecipientFilter.h"
#include "utlvector.h"
#include "vector.h"

class C_RecipientFilter : public IRecipientFilter
{
public:
	C_RecipientFilter();
	virtual bool vfunc1();
	virtual int vfunc2();
	virtual int vfunc3(int);
	virtual bool vfunc4();
	virtual int vfunc5();
	virtual bool vfunc6();
	void sub_100bdeb0();
	void sub_100be040(const Vector &origin);
	void sub_100bdf90(void *pPlayer);
	bool sub_100be140();
	void sub_100bded0(int iPlayer);
	void sub_100be0d0();
	bool m_bReliable;
	bool m_bInitMessage;
	CUtlVector<int> m_Recipients;
	int m_nBufSize;
	int m_unk20;
	int m_unk24;
	bool m_bUsingPredictionRules;
	bool m_bIgnorePredictionCull;
};

class CBroadcastRecipientFilter : public C_RecipientFilter
{
public:
	CBroadcastRecipientFilter()
	{
		sub_100bdeb0();
	}
};

class CSingleUserRecipientFilter : public C_RecipientFilter
{
public:
	CSingleUserRecipientFilter() {}
	CSingleUserRecipientFilter(int iPlayer) { sub_100bded0(iPlayer); }
};

class CPASFilter : public C_RecipientFilter
{
public:
	CPASFilter() {}
	CPASFilter(const Vector &origin) { sub_100be040(origin); }
};

class CPASAttenuationFilter : public CPASFilter
{
public:
	CPASAttenuationFilter() {}
	CPASAttenuationFilter(const Vector &origin) : CPASFilter(origin) {}
	void *vfunc0(int flags);
};

class CLocalPlayerFilter : public C_RecipientFilter
{
#ifdef PCD_LPF_CTOR
public:
	CLocalPlayerFilter();	// 0x100be160, out of line; only sources that call it define PCD_LPF_CTOR (the ??_G emitter needs it inline)
#endif
};
