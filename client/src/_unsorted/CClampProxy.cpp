// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1010cdb0 size=0x58
#include "CClampProxy.h"
// TARGET: CClampProxy::vfunc0
bool CClampProxy::vfunc0(void *pMaterial, void *pKeyValues)
{
	if (!CFunctionProxy::sub_100e34b0(pMaterial, pKeyValues))
		return false;
	if (!m_flMin.sub_100e3140(pMaterial, pKeyValues, "min", 0.0f))
		return false;
	return m_flMax.sub_100e3140(pMaterial, pKeyValues, "max", 1.0f) ? true : false;
}
// END FUNCTION

// FUNCTION: 0x1010ce10 size=0x178
#include "CClampProxy.h"

struct MatVarView
{
	virtual void s0();
	virtual void s1();
	virtual void s2();
	virtual float GetFloat();
	virtual void SetInt(int);
	virtual int GetInt();
	virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
	virtual void SetVec(const float *, int);
	virtual void s14(); virtual void s15();
	virtual void GetVec(float *, int);
};

// TARGET: CClampProxy::vfunc1
void CClampProxy::vfunc1(int)
{
	int type, vecsize;
	sub_100e3560(&type, &vecsize);
	float fMin = m_flMin.sub_100e3270();
	float fMax = m_flMax.sub_100e3270();
	if (fMin > fMax)
	{
		float t = fMin;
		fMin = fMax;
		fMax = t;
	}
	switch (type)
	{
	case 0:
	{
		float f = ((MatVarView *)m_unk0c)->GetFloat();
		if (f < fMin)
			f = fMin;
		else if (f > fMax)
			f = fMax;
		sub_100e33c0(f);
		break;
	}
	case 2:
	{
		float vec[3];
		((MatVarView *)m_unk0c)->GetVec(vec, vecsize);
		for (int i = 0; i < vecsize; i++)
		{
			if (vec[i] < fMin)
				vec[i] = fMin;
			else if (vec[i] > fMax)
				vec[i] = fMax;
		}
		((MatVarView *)m_unk04)->SetVec(vec, vecsize);
		break;
	}
	case 4:
	{
		int v = ((MatVarView *)m_unk0c)->GetInt();
		if ((float)v < fMin)
			v = (int)fMin;
		else if ((float)v > fMax)
			v = (int)fMax;
		((MatVarView *)m_unk04)->SetInt(v);
		break;
	}
	}
}
// END FUNCTION

// FUNCTION: 0x1010cff0 size=0x1e
#include "CClampProxy.h"

// VC6 writes CClampProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CClampProxy *pcd_emit_1010cff0() { return new CClampProxy; }

// TARGET: ??_GCClampProxy@@UAEPAXI@Z
// END FUNCTION
