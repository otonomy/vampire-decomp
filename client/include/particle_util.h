// particle_util.h: the 2003 SDK's cl_dll/particle_util.h inlines as the game compiles them.
#pragma once
#include "VMatrix.h"
#include "Vector.h"

// TransformParticle(g_ParticleMgr.GetModelView(), pos, tPos): the model view matrix is the VMatrix at 0x104e08d4
// (declare `extern VMatrix g_104e08d4;`). Grouped as y + z first, then x: VC6 then emits the z, y, x products in the
// game's order (matched in CFleckParticles::vfunc3, 0x100e58b0; the plain x + y + z sum gives x, z, y).
inline void TransformParticle(const VMatrix &vMat, const Vector &vIn, Vector &vOut)
{
	vOut.x = vMat.m[0][0] * vIn.x + (vMat.m[0][1] * vIn.y + vMat.m[0][2] * vIn.z) + vMat.m[0][3];
	vOut.y = vMat.m[1][0] * vIn.x + (vMat.m[1][1] * vIn.y + vMat.m[1][2] * vIn.z) + vMat.m[1][3];
	vOut.z = vMat.m[2][0] * vIn.x + (vMat.m[2][1] * vIn.y + vMat.m[2][2] * vIn.z) + vMat.m[2][3];
}
