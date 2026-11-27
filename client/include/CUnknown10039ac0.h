// CUnknown10039ac0: a temp entity shaped like C_TEDecal (origin at +0xc, start at +0x18, entity, hitbox, decal index,
// flag byte); the game keeps one static instance at 0x102ee4c4 (written by 0x10039de0) and calls sub_10039ac0 on it.
#pragma once
#include "Vector.h"

class CUnknown10039ac0
{
public:
	void *m_vtable;	// 0x00
	int m_unk04;
	int m_unk08;
	Vector m_vecOrigin;	// 0x0c
	Vector m_vecStart;	// 0x18
	int m_nEntity;	// 0x24
	int m_nHitbox;	// 0x28
	int m_nIndex;	// 0x2c
	int m_n30;	// 0x30
	bool m_b34;	// 0x34
	void sub_10039ac0(int a);
};
