// Beam_t: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases; nothing else yet (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "CDefaultClientRenderable.h"
#include "Vector.h"

class Beam_t : public CDefaultClientRenderable
{
public:
	Beam_t();
	void sub_10192db0();
	void sub_10192f20();	// ComputeBounds
	Vector m_Mins;		// 0x08
	Vector m_Maxs;		// 0x14
	int m_unk20;
	int m_unk24;
	int type;			// 0x28
	int flags;			// 0x2c
	int numAttachments;	// 0x30
	Vector attachment[10];	// 0x34
	Vector delta;		// 0xac
	int m_unkb8;
	int m_unkbc;
	int m_unkc0;
	float t;			// 0xc4
	float freq;			// 0xc8
	float die;			// 0xcc
	float width;		// 0xd0
	float endWidth;		// 0xd4
	float fadeLength;	// 0xd8
	float amplitude;	// 0xdc
	float life;			// 0xe0
	float r, g, b;		// 0xe4
	float brightness;	// 0xf0
	float speed;		// 0xf4
	float frameRate;	// 0xf8
	float frame;		// 0xfc
	int segments;		// 0x100
	struct BeamFill { int m_a[10]; BeamFill() { for (int i = 0; i < 10; i++) m_a[i] = -1; } } m_fill;
	int attachmentIndex[10];	// 0x12c
	int modelIndex;		// 0x154
	int haloIndex;		// 0x158
	float haloScale;	// 0x15c
	int frameCount;		// 0x160
	float rgNoise[129];	// 0x164
	void *trail;		// 0x368
	float start_radius;	// 0x36c
	float end_radius;	// 0x370
	bool m_bCalculatedNoise;	// 0x374
};
