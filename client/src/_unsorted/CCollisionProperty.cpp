// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100431d0 size=0x4
#include "CCollisionProperty.h"

// TARGET: CCollisionProperty::vfunc0
void *CCollisionProperty::vfunc0()
{
	return m_unk3c;
}
// END FUNCTION

// FUNCTION: 0x100431e0 size=0xb
#include "CCollisionProperty.h"
struct V { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); };
void __fastcall sub_100431e0(CCollisionProperty *self, int edx) { ((V *)((char *)self->m_unk3c + 0xc))->v12(); }
// END FUNCTION

// FUNCTION: 0x10043210 size=0xa
#include "CCollisionProperty.h"
namespace lifted {
struct V { virtual int f0(); };
}
void CCollisionProperty::vfunc13()
{
    ((lifted::V *)((*(int *)((char *)this + 0x3c)) + 4))->f0();
}
// END FUNCTION

// FUNCTION: 0x10043290 size=0x4
#include "CCollisionProperty.h"
// TARGET: CCollisionProperty::vfunc11
int CCollisionProperty::vfunc11()
{
	return m_unk40;
}
// END FUNCTION

// FUNCTION: 0x100432e0 size=0x8
#include "CCollisionProperty.h"
#include "C_BaseEntity.h"

// TARGET: CCollisionProperty::vfunc8
const Vector &CCollisionProperty::vfunc8()
{
	return ((C_BaseEntity *)m_unk3c)->GetAbsOrigin();
}
// END FUNCTION

// FUNCTION: 0x100432f0 size=0x2e
#include "CCollisionProperty.h"
struct IEntV { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual int *v10(); };
extern int g_104d5190;
int *CCollisionProperty::sub_100432f0(char a)
{
	if (!a) {
		if ((m_unk44 & 0x80) || m_unk40 == 2 || m_unk40 == 0)
			return &g_104d5190;
	}
	return ((IEntV *)m_unk3c)->v10();
}
// END FUNCTION

// FUNCTION: 0x10043320 size=0x88
#include "CCollisionProperty.h"
#include "matrix3x4_t.h"
#include "C_BaseEntity.h"
void sub_10109420(matrix3x4_t *);
void sub_10108540(const Vector &, int, matrix3x4_t *);
struct CMatRing { matrix3x4_t m[4]; ~CMatRing() {} };
// TARGET: CCollisionProperty::vfunc10
const matrix3x4_t &CCollisionProperty::vfunc10()
{
	static CMatRing s_Matrix;
	static int s_nIndex = 0;
	matrix3x4_t &matResult = s_Matrix.m[s_nIndex];
	s_nIndex = (s_nIndex + 1) & 3;
	if (m_unk44 & 0x80 || m_unk40 == 2 || m_unk40 == 0)
	{
		sub_10109420(&matResult);
		sub_10108540(vfunc8(), 3, &matResult);
		return matResult;
	}
	C_BaseEntity *pEnt = (C_BaseEntity *)m_unk3c;
	pEnt->sub_1009f8a0();
	return *(matrix3x4_t *)((char *)pEnt + 0x26c);
}
// END FUNCTION

// FUNCTION: 0x10043440 size=0x4
#include "CCollisionProperty.h"

// TARGET: CCollisionProperty::vfunc1
Vector &CCollisionProperty::vfunc1()
{
	return m_vecMins;
}
// END FUNCTION

// FUNCTION: 0x10043450 size=0x4
#include "CCollisionProperty.h"

// TARGET: CCollisionProperty::vfunc2
void *CCollisionProperty::vfunc2()
{
	return &m_unk10;
}
// END FUNCTION

// FUNCTION: 0x10043460 size=0x5f
#include "CCollisionProperty.h"
// TARGET: CCollisionProperty::vfunc3
void CCollisionProperty::vfunc3(Vector *pWorldMins, Vector *pWorldMaxs)
{
	sub_10043860(m_vecMins, *(Vector *)&m_unk10, pWorldMins, pWorldMaxs);
	if (vfunc12x() & 0x100) {
		pWorldMins->x -= m_flBloat;
		pWorldMins->y -= m_flBloat;
		pWorldMaxs->x = m_flBloat + pWorldMaxs->x;
		pWorldMaxs->y += m_flBloat;
		pWorldMaxs->z += m_flBloat * 0.5f;
	}
}
// END FUNCTION

// FUNCTION: 0x10043500 size=0xb
#include "CCollisionProperty.h"
struct V { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
virtual void v50(); virtual void v51(); };
void __fastcall sub_10043500(CCollisionProperty *self, int edx) { ((V *)self->m_unk3c)->v51(); }
// END FUNCTION

// FUNCTION: 0x10043510 size=0xb
#include "CCollisionProperty.h"
struct V { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); };
void __fastcall sub_10043510(CCollisionProperty *self, int edx) { ((V *)((char *)self->m_unk3c + 4))->v8(); }
// END FUNCTION

// FUNCTION: 0x10043520 size=0xa
#include "CCollisionProperty.h"
struct V { virtual void v0(); };
void CCollisionProperty::vfunc4() { ((V *)((char *)m_unk3c + 0xc))->v0(); }
// END FUNCTION

// FUNCTION: 0x10043530 size=0x8
#include "CCollisionProperty.h"
struct CColView { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); };
void CCollisionProperty::vfunc5() { ((CColView *)m_unk3c)->v27(); }
// END FUNCTION

// FUNCTION: 0x10044630 size=0x1
#include "CCollisionProperty.h"

// TARGET: CCollisionProperty::vfunc17
void CCollisionProperty::vfunc17()
{
}
// END FUNCTION

// FUNCTION: 0x10044640 size=0x7
#include "CCollisionProperty.h"

// TARGET: CCollisionProperty::vfunc12
int CCollisionProperty::vfunc12()
{
	return m_unk44;
}
// END FUNCTION
