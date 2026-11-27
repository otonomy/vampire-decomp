// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1004a3c0 size=0xd4
#include "CTextureTransformProxy.h"
#include "CKeyValuesX.h"
struct IMaterialV { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void *FindVar(const char *name, bool *found, bool complain); };
bool CTextureTransformProxy::vfunc0(void *pMaterial, void *pKeyValues)
{
	IMaterialV *mat = (IMaterialV *)pMaterial;
	CKeyValuesX *kv = (CKeyValuesX *)pKeyValues;
	m_pCenterVar = 0;
	m_pScaleVar = 0;
	m_pRotateVar = 0;
	m_pTranslateVar = 0;
	bool bFoundVar;
	const char *pVarName = kv->sub_10128590("centerVar", "");
	if (pVarName && pVarName[0])
		m_pCenterVar = mat->FindVar(pVarName, &bFoundVar, false);
	pVarName = kv->sub_10128590("scaleVar", "");
	if (pVarName && pVarName[0])
		m_pScaleVar = mat->FindVar(pVarName, &bFoundVar, false);
	pVarName = kv->sub_10128590("rotateVar", "");
	if (pVarName && pVarName[0])
		m_pRotateVar = mat->FindVar(pVarName, &bFoundVar, false);
	pVarName = kv->sub_10128590("translateVar", "");
	if (pVarName && pVarName[0])
		m_pTranslateVar = mat->FindVar(pVarName, &bFoundVar, false);
	return CResultProxy::vfunc0(pMaterial, pKeyValues);
}
// END FUNCTION

// FUNCTION: 0x1004a4a0 size=0x15e
#include "CTextureTransformProxy.h"
#include "Vector.h"
struct IVar_1004a4a0 {
	virtual void v0(); virtual void v1(); virtual void v2();
	virtual float GetFloatValue();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
	virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
	virtual void v14(); virtual void v15();
	virtual void GetVecValue(float *, int);
	virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
	virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
	virtual void SetMatrixValue(float *);
};
struct Mat_1004a4a0 { float m[16]; };
void sub_101a2b00(Mat_1004a4a0 *out, float x, float y, float z);
void sub_101a2e90(Mat_1004a4a0 *out, float x, float y, float z);
void sub_101a2e30(Mat_1004a4a0 *out, float angle);
void sub_101a2600(Mat_1004a4a0 *a, Mat_1004a4a0 *b, Mat_1004a4a0 *out);
void CTextureTransformProxy::vfunc1(int)
{
	Mat_1004a4a0 mat;
	Mat_1004a4a0 temp;
	float center[2];
	float translation[2];
	center[0] = 0.5f;
	center[1] = 0.5f;
	translation[0] = 0.0f;
	translation[1] = 0.0f;
	if (m_pCenterVar)
		((IVar_1004a4a0 *)m_pCenterVar)->GetVecValue(center, 2);
	sub_101a2b00(&mat, -center[0], -center[1], 0.0f);
	if (m_pScaleVar) {
		float scale[2];
		((IVar_1004a4a0 *)m_pScaleVar)->GetVecValue(scale, 2);
		sub_101a2e90(&temp, scale[0], scale[1], 1.0f);
		sub_101a2600(&temp, &mat, &mat);
	}
	if (m_pRotateVar) {
		float angle = ((IVar_1004a4a0 *)m_pRotateVar)->GetFloatValue();
		sub_101a2e30(&temp, angle);
		sub_101a2600(&temp, &mat, &mat);
	}
	sub_101a2b00(&temp, center[0], center[1], 0.0f);
	sub_101a2600(&temp, &mat, &mat);
	if (m_pTranslateVar) {
		((IVar_1004a4a0 *)m_pTranslateVar)->GetVecValue(translation, 2);
		sub_101a2b00(&temp, translation[0], translation[1], 0.0f);
		sub_101a2600(&temp, &mat, &mat);
	}
	(*(IVar_1004a4a0 **)((char *)this + 4))->SetMatrixValue(mat.m);
}
// END FUNCTION

// FUNCTION: 0x1004a670 size=0x1e
#include "CTextureTransformProxy.h"

// VC6 writes CTextureTransformProxy's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CTextureTransformProxy *pcd_emit_1004a670() { return new CTextureTransformProxy; }

// TARGET: ??_GCTextureTransformProxy@@UAEPAXI@Z
// END FUNCTION
