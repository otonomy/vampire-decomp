// C_VGuiScreen: skeleton from the game's RTTI (2026-11-24)
// declared: its base, slot 16
#pragma once
#include "C_BaseEntity.h"
#include "VMatrix.h"

struct CVGuiMemA { int m_unk0; void sub_100cd1e0(); ~CVGuiMemA() { sub_100cd1e0(); } };
struct CVGuiMemB { int m_unk0; void sub_10110440(); ~CVGuiMemB() { sub_10110440(); } };
class C_VGuiScreen : public C_BaseEntity
{
public:
	char m_pad0014[0x43c - 0x14];
	int m_n43c;
	char m_pad0440[0x450 - 0x440];
	CVGuiMemA m_a;
	CVGuiMemA m_b;
	VMatrix m_matrix;
	CVGuiMemB m_c;
	virtual int vfunc16();
	void sub_100c9270(int);
	void sub_100c9680(Vector &v1, Vector &v2, Vector &v3);
	void sub_100c9820();
	virtual int vfunc64(int, int, int);
	bool IsVisibleToTeam(int nTeam);	// 0x100c9320: always true here
	bool sub_100c9740(const struct Ray_t &ray, float *u, float *v, float *t);	// IntersectWithRay-like (ray, &u, &v, &t)
};
