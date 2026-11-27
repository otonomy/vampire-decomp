// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10114de0 size=0x1c0
#include "CParticleCollision.h"
#include "QAngle.h"
void sub_10109340(const Vector &, QAngle &);
void sub_101090a0(const QAngle &, Vector *, Vector *, Vector *);
// TARGET: CParticleCollision::vfunc4
void CParticleCollision::vfunc4(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	const Vector &origin = *(const Vector *)a1;
	const Vector *direction = (const Vector *)a2;
	float flGravity = *(float *)&a6;
	m_flGravity = flGravity;
	m_flCollisionDampen = *(float *)&a7;
	m_nActivePlanes = 0;
	float flSpeed = (*(float *)&a5 + *(float *)&a4) * 0.5f;
	if (!direction)
	{
		Vector v;
		v.Init(1.0f, 0.0f, 0.0f);
		vfunc2(origin, v, flSpeed, flGravity);
		v.Init(-1.0f, 0.0f, 0.0f);
		vfunc2(origin, v, flSpeed, flGravity);
		v.Init(0.0f, 1.0f, 0.0f);
		vfunc2(origin, v, flSpeed, flGravity);
		v.Init(0.0f, -1.0f, 0.0f);
		vfunc2(origin, v, flSpeed, flGravity);
		v.Init(0.0f, 0.0f, 1.0f);
		vfunc2(origin, v, flSpeed, flGravity);
		v.Init(0.0f, 0.0f, -1.0f);
		vfunc2(origin, v, flSpeed, flGravity);
	}
	else
	{
		QAngle angles;
		Vector right;
		sub_10109340(*direction, angles);
		sub_101090a0(angles, 0, &right, 0);
		vfunc2(origin, *direction, flSpeed, flGravity);
		Vector v = right;
		vfunc2(origin, v, flSpeed, flGravity);
		v *= -1.0f;
		vfunc2(origin, v, flSpeed, flGravity);
	}
}
// END FUNCTION
