// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1004a690 size=0x6a
#include "CMatrixRotateProxy.h"
#include "CKeyValuesX.h"
struct IMatVarFinder { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void *FindVar(const char *pName, bool *pFound, bool bComplain); };
extern char g_102de300[];
// TARGET: CMatrixRotateProxy::vfunc0
bool CMatrixRotateProxy::vfunc0(void *pMaterial, void *pKeyValues)
{
	m_pAxisVar = 0;
	const char *pAxisVarName = ((CKeyValuesX *)pKeyValues)->sub_10128590("axisVar", g_102de300);
	if (pAxisVarName && pAxisVarName[0])
	{
		bool found;
		m_pAxisVar = ((IMatVarFinder *)pMaterial)->FindVar(pAxisVarName, &found, false);
	}
	if (!m_Angle.sub_100e3140(pMaterial, pKeyValues, "angle", 0))
		return false;
	return CResultProxy::vfunc0(pMaterial, pKeyValues);
}
// END FUNCTION

// FUNCTION: 0x1004a700 size=0x92
#include "CMatrixRotateProxy.h"
#include "CClampProxy.h"
#include "Vector.h"
#include "VMatrix.h"
void sub_101a2b60(VMatrix &, const Vector &, float);
struct IVarX {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void GetVecValue(float *, int);
	virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
	virtual void SetMatrixValue(VMatrix &);
};
void CMatrixRotateProxy::vfunc1(int)
{
	IVarX *pAxis = *(IVarX **)((char *)this + 0x18);
	Vector axis(0, 0, 1);
	if (pAxis) {
		pAxis->GetVecValue(axis.Base(), 3);
		if (VectorNormalize(axis) < 0.001)
			axis.Init(0, 0, 1);
	}
	VMatrix mat;
	sub_101a2b60(mat, axis, ((CClampProxy::CInput *)((char *)this + 0xc))->sub_100e3270());
	(*(IVarX **)((char *)this + 4))->SetMatrixValue(mat);
}
// END FUNCTION

// FUNCTION: 0x1004a800 size=0x1e
#include "CMatrixRotateProxy.h"

// VC6 writes CMatrixRotateProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CMatrixRotateProxy *pcd_emit_1004a800() { return new CMatrixRotateProxy; }

// TARGET: ??_GCMatrixRotateProxy@@UAEPAXI@Z
// END FUNCTION
