// C_VGuiScreen: skeleton from the game's RTTI (2026-11-24)
// declared: its base, slot 16
#pragma once
#include "C_BaseEntity.h"
#include "VMatrix.h"

struct CVGuiMemA { int m_unk0; void sub_100cd1e0(); ~CVGuiMemA() { sub_100cd1e0(); } };
struct CVGuiMemB { int m_unk0; void sub_10110440(); void *sub_101104a0(); ~CVGuiMemB() { sub_10110440(); } };
class C_VGuiScreen : public C_BaseEntity
{
public:
	char m_pad0014[0x410 - 0x14];
	int m_nPixelWidth;	// 0x410
	int m_nPixelHeight;	// 0x414
	float m_flWidth;	// 0x418: the screen's world width
	float m_flHeight;	// 0x41c: its world height
	int m_unk420;
	int m_unk424;
	int m_nButtonPressed;	// 0x428
	int m_nButtonReleased;	// 0x42c
	int m_nOldPx;	// 0x430
	int m_nOldPy;	// 0x434
	int m_unk438;
	int m_n43c;
	char m_pad0440[0x450 - 0x440];
	CVGuiMemA m_a;
	CVGuiMemA m_b;
	VMatrix m_matrix;
	CVGuiMemB m_c;
	virtual int vfunc16();
	virtual void ClientThink();	// IClientThinkable slot 0
	void sub_100c9270(int);
	void sub_100c9680(Vector &v1, Vector &v2, Vector &v3);
	void sub_100c9820();
	void sub_100c9860();	// draws the screen's quad (m_flWidth x m_flHeight) with the panel material (m_b) at m_matrix
	virtual int vfunc64(int, int, int);
	bool IsVisibleToTeam(int nTeam);	// 0x100c9320: always true here
	bool sub_100c9740(const struct Ray_t &ray, float *u, float *v, float *t);	// IntersectWithRay-like (ray, &u, &v, &t)
};
