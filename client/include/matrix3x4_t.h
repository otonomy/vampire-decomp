// matrix3x4_t: Source's 3x4 transform matrix (three rows of x / y / z axis and translation), as a plain float table.
#pragma once

#include "Vector.h"

class QAngle;

struct matrix3x4_t
{
	float m_flMatVal[3][4];

	float *operator[](int i) { return m_flMatVal[i]; }
	const float *operator[](int i) const { return m_flMatVal[i]; }

		// the 12 value constructor (stub 0x10003049)
		// VectorITransform: pOut = (pIn - translation) projected on the three axes (columns), through a local copy of the input
		// whether the three rows are orthonormal: every row's length within 0.01f of 1, every pair's dot product within 0.01f of 0
};

void sub_101094e0(const QAngle &angles, matrix3x4_t &matrix);	// AngleMatrix: the rotation matrix of pitch / yaw / roll (each converted with 0.017453292f)
