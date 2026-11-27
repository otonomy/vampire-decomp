#pragma once

class CTraceFilterSimple
{
public:
	void *m_vftable;
	const void *m_pPassEnt;
	int m_collisionGroup;

	void sub_1004b5c0(const void *passentity, int collisionGroup);
	bool sub_1004b5f0(const void *pHandleEntity, int contentsMask);
};
