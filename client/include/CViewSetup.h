// CViewSetup: the view a CViewRender draws (0x94 bytes; VtMB's layout, read off CViewRender::Render 0x10191f10).
// CViewRender keeps one at +0x10 (m_View); CViewRender::Render builds a 2D one on the stack.
#pragma once
#include "Vector.h"
#include "QAngle.h"

struct CViewSetup
{
	CViewSetup() { m_b90 = false; }

	int m_unk00;	// 0x00
	int x;	// 0x04
	int y;	// 0x08
	int width;	// 0x0c
	int height;	// 0x10
	bool clearColor;	// 0x14
	bool clearDepth;	// 0x15
	bool m_bOrtho;	// 0x16
	char m_pad17;
	float m_OrthoLeft;	// 0x18
	float m_OrthoTop;	// 0x1c
	float m_OrthoRight;	// 0x20
	float m_OrthoBottom;	// 0x24
	float fov;	// 0x28
	float fovViewmodel;	// 0x2c
	float m_flTanHalfFov;	// 0x30: tan(fov / 2)
	float m_flTanHalfFovViewmodel;	// 0x34
	Vector origin;	// 0x38
	int m_unk44;	// 0x44
	int m_unk48;	// 0x48
	int m_unk4c;	// 0x4c
	QAngle angles;	// 0x50
	int m_unk5c;	// 0x5c
	int m_unk60;	// 0x60
	int m_unk64;	// 0x64
	int m_unk68;	// 0x68
	Vector m_vForward;	// 0x6c
	Vector m_vRight;	// 0x78
	Vector m_vUp;	// 0x84
	bool m_b90;	// 0x90
	char m_pad91[3];
};
