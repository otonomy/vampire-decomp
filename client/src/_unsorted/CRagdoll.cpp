// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10125200 size=0xe
struct SE { int a; int b[5]; };
struct CView { SE e[1]; int sub_10125200(int); };
// TARGET: ?sub_10125200@CView@@QAEHH@Z
int CView::sub_10125200(int i) { return e[i + 1].a; }
// END FUNCTION

// FUNCTION: 0x10125420 size=0x1d
#include "CRagdoll.h"
void sub_101271e0(int *p);

// TARGET: ??1CRagdoll@@UAE@XZ
CRagdoll::~CRagdoll()
{
	sub_101271e0((int *)((char *)this + 4));
}
// END FUNCTION

// FUNCTION: 0x10125460 size=0x42
#include "CRagdoll.h"
struct CRagdollLayout { int m_n; };
struct CRagdollStudio;
bool __cdecl sub_10127320(CRagdollLayout *l, CRagdollStudio *s, int i);
// TARGET: CRagdoll::vfunc1
void CRagdoll::vfunc1(int a, int b, int c, char *flags, CRagdollStudio *studio) {
	CRagdollLayout *l = (CRagdollLayout *)((char *)this + 4);
	for (int i = 0; i < l->m_n; i++) {
		if (sub_10127320(l, studio, i))
			flags[(&m_off[0])[i]] = 1;
	}
}
// END FUNCTION

// FUNCTION: 0x101254b0 size=0x1b
#include "CRagdoll.h"
struct Ent54b0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
 virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(void *, int); };
struct Rag54b0 { int pad0; int pad4; int pad8; int padc; int pad10; int pad14; Ent54b0 *m18; char pad2[0x36c - 0x1c]; char m36c; void *sub_101254b0(); };
void *Rag54b0::sub_101254b0() { m18->v37(&m36c, 0); return &m36c; }
// END FUNCTION

// FUNCTION: 0x101254d0 size=0x3f
#include "CRagdoll.h"
void CRagdoll::vfunc3(Vector &mins, Vector &maxs)
{
	mins = m_vecMins;
	maxs = m_vecMaxs;
}
// END FUNCTION

// FUNCTION: 0x10125510 size=0x107
#include "CGlobalVarsBase.h"
#include "Vector.h"


extern bool sub_101274d0(void *pRagdoll);
extern void sub_101273b0(void *pRagdoll, const Vector &origin, Vector &mins, Vector &maxs);

struct Ragdoll_10125510
{
	virtual ~Ragdoll_10125510() {}
	virtual void v1();
	virtual const Vector &GetRagdollOrigin();

	char m_ragdoll[0x350]; // 0x04..0x353
	Vector m_mins;         // 0x354
	Vector m_maxs;         // 0x360
	char pad_36c[0x0c];
	float m_radius;        // 0x378
	float m_lastUpdate;    // 0x37c
	bool m_allAsleep;      // 0x380

	void sub_10125510(int pEnt);
};

// TARGET: Ragdoll_10125510::sub_10125510
void Ragdoll_10125510::sub_10125510(int pEnt)
{
	if (m_lastUpdate == gpGlobals->curtime)
		return;

	m_lastUpdate = gpGlobals->curtime;
	m_allAsleep = sub_101274d0(&m_ragdoll);

	if (m_allAsleep)
	{
		Vector origin = GetRagdollOrigin();
		sub_101273b0(&m_ragdoll, origin, m_mins, m_maxs);
		m_mins -= origin;
		m_maxs -= origin;
	}
	else
	{
		m_mins.Init(-m_radius, -m_radius, -m_radius);
		m_maxs.Init(m_radius, m_radius, m_radius);
	}
}
// END FUNCTION

// FUNCTION: 0x10125620 size=0x66
#include "engineclient.h"
#include "CRagdoll.h"

struct CPhysObjectV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37();
	virtual void v38(void *pMatrix);
	virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
	virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
	virtual int v49();
};


struct RagdollBodyV
{
	CPhysObjectV *m_pObject;
	char m_pad[0x14];
};


void sub_101267c0(int a, void *pMaterial, void *pMatrix);

// TARGET: CRagdoll::vfunc5
void CRagdoll::vfunc5()
{
	void *pMaterial = materials->FindMaterial("shadertest/wireframevertexcolor", 0, 1);
	char mat[0x30];
	for (int i = 0; i < m_n0004; i++)
	{
		RagdollBodyV *p = (RagdollBodyV *)((char *)this + 0x18) + i;
		p->m_pObject->v38(mat);
		int x = p->m_pObject->v49();
		sub_101267c0(x, pMaterial, mat);
	}
}
// END FUNCTION
