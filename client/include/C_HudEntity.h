#pragma once
#include "C_BaseEntity.h"

class C_HudEntity : public C_BaseEntity
{
public:
	int m_unk0014[(0x42c - 0x14) / 4];
	struct Zero { int v; Zero() { v = 0; } };
	Zero m_z;
	int m_unk0430[2];
	C_HudEntity() {}
	virtual ~C_HudEntity() { sub_100bc660(); }
	void sub_100bc660();
};
