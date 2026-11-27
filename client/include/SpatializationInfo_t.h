// SpatializationInfo_t: what IClientEntity::GetSoundSpatialization fills in. Only the output pointers at +0x140 are
// known (the engine fills the inputs before the +0x140 words).
#pragma once
#include "Vector.h"

struct SpatializationInfo_t
{
	int m_unk0[0x50];	// 0x0: inputs, not named yet
	Vector *pOrigin;	// 0x140
	QAngle *pAngles;	// 0x144
	float *pflRadius;	// 0x148
};
