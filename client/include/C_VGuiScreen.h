// C_VGuiScreen: skeleton from the game's RTTI (2026-11-24)
// declared: its base, slot 16
#pragma once
#include "C_BaseEntity.h"
#include "VMatrix.h"

#include "CMaterialReference.h"
#include "CPanelWrapper.h"
class C_VGuiScreen : public C_BaseEntity
{
public:
	char m_pad0014[0x410 - 0x14];
	int m_nPixelWidth;	// 0x410
	int m_nPixelHeight;	// 0x414
	float m_flWidth;	// 0x418: the screen's world width
	float m_flHeight;	// 0x41c: its world height
	int m_nPanelName;	// 0x420
	int m_unk424;
	int m_nButtonPressed;	// 0x428
	int m_nButtonReleased;	// 0x42c
	int m_nOldPx;	// 0x430
	int m_nOldPy;	// 0x434
	int m_unk438;
	int m_n43c;
	int m_nOverlayMaterial;	// 0x440
	int m_unk444;
	int m_nOldPanelName;	// 0x448
	int m_nOldOverlayMaterial;	// 0x44c
	CMaterialReference m_a;	// 0x450: m_WriteZMaterial
	CMaterialReference m_b;	// 0x454: m_OverlayMaterial
	VMatrix m_matrix;
	CPanelWrapper m_c;	// 0x498: m_PanelWrapper
	// the game's constructor is out of line in c_vguiscreen.cpp; it is written here so the ??_G emitter still emits the vtable
	C_VGuiScreen()
	{
		m_nOldPanelName = m_nPanelName = -1;
		m_nOldOverlayMaterial = m_nOverlayMaterial = -1;
		m_nOldPx = m_nOldPy = -1;
		m_unk424 = 0;

		m_a.Init("engine/writez");
		m_b.Init(m_a);
	}
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
