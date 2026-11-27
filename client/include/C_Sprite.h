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
	virtual void OnDataChanged(int updateType);
	virtual int DrawModel(int flags, int a1);
	float vfunc121();
	virtual void vfunc120(const char *);
	virtual float vfunc121_slot();
	virtual int vfunc122();
	virtual void vfunc19();
	void sub_10136580(int, int);
	void sub_101365a0(float, int);
	void sub_101365d0();
};
