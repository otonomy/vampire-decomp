// Ray_t: the engine's trace ray (0x38 bytes): start, delta, extents, start offset, then the ray / swept flags.
#pragma once

#include "Vector.h"

extern float g_101e34f0;	// the float 0.0f the game shares in its constant pool

struct Ray_t
{
	float m_Start[3];
	float m_Delta[3];
	float m_Extents[3];
	float m_StartOffset[3];
	bool m_IsRay;	// 0x30
	bool m_IsSwept;	// 0x31
	char m_b32;
	char m_b33;
	float m_n34;

	void Init(const Vector &start, const Vector &end)	// Ray_t::Init(start, end) as the game inlines it
	{
		m_Delta[0] = end.x - start.x;
		m_Delta[1] = end.y - start.y;
		m_Delta[2] = end.z - start.z;
		m_IsSwept = (m_Delta[0] * m_Delta[0] + m_Delta[1] * m_Delta[1] + m_Delta[2] * m_Delta[2]) != g_101e34f0;
		m_StartOffset[0] = m_StartOffset[1] = m_StartOffset[2] = 0.0f;
		m_IsRay = true;
		m_Extents[0] = m_Extents[1] = m_Extents[2] = 0.0f;
		m_Start[0] = start.x;
		m_Start[1] = start.y;
		m_Start[2] = start.z;
		m_b32 = 0;
		m_n34 = 0;
		m_b33 = 0;
	}

	// InitInline: Init(start, end) forced inline. VC6 decides per call site whether to expand Init; in a big caller it may
	// call the out-of-line copy (0x1004f7a0) where the game expanded it. UTIL_Trace.h's inline forms use this.
	__forceinline void InitInline(const Vector &start, const Vector &end)
	{
		m_Delta[0] = end.x - start.x;
		m_Delta[1] = end.y - start.y;
		m_Delta[2] = end.z - start.z;
		m_IsSwept = (m_Delta[0] * m_Delta[0] + m_Delta[1] * m_Delta[1] + m_Delta[2] * m_Delta[2]) != g_101e34f0;
		m_StartOffset[0] = m_StartOffset[1] = m_StartOffset[2] = 0.0f;
		m_IsRay = true;
		m_Extents[0] = m_Extents[1] = m_Extents[2] = 0.0f;
		m_Start[0] = start.x;
		m_Start[1] = start.y;
		m_Start[2] = start.z;
		m_b32 = 0;
		m_n34 = 0;
		m_b33 = 0;
	}

	// InitInlineSumYXZ: InitInline with the swept test's squares grouped y*y + (x*x + z*z); VC6 then sums x, z, y as
	// some callers do (0x102d1af0). Same source meaning: only the grouping VC6 follows differs.
	__forceinline void InitInlineSumYXZ(const Vector &start, const Vector &end)
	{
		m_Delta[0] = end.x - start.x;
		m_Delta[1] = end.y - start.y;
		m_Delta[2] = end.z - start.z;
		m_IsSwept = (m_Delta[1] * m_Delta[1] + (m_Delta[0] * m_Delta[0] + m_Delta[2] * m_Delta[2])) != g_101e34f0;
		m_StartOffset[0] = m_StartOffset[1] = m_StartOffset[2] = 0.0f;
		m_IsRay = true;
		m_Extents[0] = m_Extents[1] = m_Extents[2] = 0.0f;
		m_Start[0] = start.x;
		m_Start[1] = start.y;
		m_Start[2] = start.z;
		m_b32 = 0;
		m_n34 = 0;
		m_b33 = 0;
	}

	void Init(const Vector &start, const Vector &end, const Vector &mins, const Vector &maxs)	// Ray_t::Init(start, end, mins, maxs) as CGameRules::vfunc76 inlines it
	{
		m_Delta[0] = end.x - start.x;
		m_Delta[1] = end.y - start.y;
		m_Delta[2] = end.z - start.z;
		m_IsSwept = (m_Delta[0] * m_Delta[0] + m_Delta[1] * m_Delta[1] + m_Delta[2] * m_Delta[2]) != g_101e34f0;
		Vector &extents = *(Vector *)m_StartOffset;
		Vector &offset = *(Vector *)m_Extents;
		VectorSubtract(maxs, mins, extents);
		VectorScale(extents, 0.5f, extents);
		m_IsRay = (extents.LengthSqr() < 1e-6);
		VectorAdd(mins, maxs, offset);
		VectorScale(offset, 0.5f, offset);
		VectorAdd(start, offset, *(Vector *)m_Start);
		VectorScale(offset, -1.0f, offset);
		m_b32 = 0;
		m_b33 = 0;
		m_n34 = 0;
	}

	void sub_10042370();
	void sub_100e91e0(const Vector &start, const Vector &end, const float *pMins, const float *pMaxs, char a, char b);
	void sub_10005e00(const float *pStart, const float *pEnd);	// Ray_t::Init(start, end): delta = end - start, swept when the delta is not zero, the extents zeroed, IsRay set
	void sub_100e91e0(const Vector &start, const float *pEnd, const float *pMins, const float *pMaxs, char a, char b);	// Ray_t::Init(start, end, mins, maxs) (stub 0x1000c725), thiscall with six stack arguments (the last two are bytes)
};
