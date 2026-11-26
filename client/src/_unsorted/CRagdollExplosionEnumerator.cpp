// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100367e0 size=0x20b
#include "CRagdollExplosionEnumerator.h"
#include "Ray_t.h"
#include "CGameTrace.h"
#include "CTraceFilterSimple.h"
#define V1(n) virtual void n();
#define V10(p) V1(p##0) V1(p##1) V1(p##2) V1(p##3) V1(p##4) V1(p##5) V1(p##6) V1(p##7) V1(p##8) V1(p##9)
struct Ent_36
{
	V10(a) V10(b) V10(c)
	virtual void vf30(const Vector *v);
	V1(d31) V1(d32) V1(d33) V1(d34) V1(d35) V1(d36)
	virtual void vf37(Vector *out, int a);
};
struct HE_36
{
	V10(a) V10(b) V10(c) V10(d) V10(e) V10(f) V10(g) V10(h) V10(i) V10(j) V10(k) V10(l) V10(m)
	V1(n0) V1(n1) V1(n2)
	virtual Ent_36 *vf133();
};
struct ET_36
{
	V1(a0) V1(a1) V1(a2) V1(a3)
	virtual void TraceRay(const Ray_t &ray, unsigned int mask, CTraceFilterSimple *filter, CGameTrace *tr);
};
struct CV_36 { int sub_10005de0(); };
extern CV_36 g_103edd98;
extern ET_36 *g_104a582c;
extern void sub_101659b0(const float *start, const float *end, int r, int g, int b, int noDepth, float duration);
// TARGET: CRagdollExplosionEnumerator::vfunc0
int CRagdollExplosionEnumerator::vfunc0(void *pHandleEntity)
{
	if (!pHandleEntity)
		return 0;
	Ent_36 *pEnt = ((HE_36 *)pHandleEntity)->vf133();
	if (!pEnt)
		return 0;
	CGameTrace tr;
	Ray_t ray;
	Vector vecPos;
	pEnt->vf37(&vecPos, 0);
	ray.Init(m_vecOrigin, vecPos);
	{
		CTraceFilterSimple filter;
		filter.sub_1004b5c0(0, 0);
		g_104a582c->TraceRay(ray, 0x46004003, &filter, &tr);
	}
	if (g_103edd98.sub_10005de0())
		sub_101659b0(tr.m_startpos, tr.m_endpos, 255, 0, 0, 1, -1.0f);
	if (tr.m_fraction < 1.0f)
		return 0;
	Vector vecDir = vecPos - m_vecOrigin;
	float flDist = VectorNormalize(vecDir);
	float flForce = m_flMagnitude - flDist * (m_flMagnitude / m_flRadius);
	if (flForce <= 0.0f)
		return 0;
	flForce *= 500.0f;
	vecDir *= flForce;
	pEnt->vf30(&vecDir);
	return 0;
}
// END FUNCTION
