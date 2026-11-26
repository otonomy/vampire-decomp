// C_Sprite: skeleton from the game's RTTI (2026-11-24)
// declared: its base, slot 16
#pragma once
#include "C_BaseEntity.h"
#include "C_SpriteRenderer.h"

struct C_SpriteMembers14
{
	int m_unk14[(0x410 - 0x14) / 4];
};

class C_Sprite : public C_BaseEntity, public C_SpriteMembers14, public C_SpriteRenderer
{
public:
	__forceinline C_Sprite() {}
	void sub_10136310(const char *name, int a);
	virtual void GetRenderBounds(Vector &vecMins, Vector &vecMaxs);	// IClientRenderable slot 18
	virtual int vfunc16();
	virtual int vfunc17();
	float vfunc121();
	virtual int vfunc122();
};
