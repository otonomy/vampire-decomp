// CHUDSprite: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once

class CHUDSprite
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the slots CHUDSprite adds to its base's vtable: 0-0, vfuncK at slot K
	CHUDSprite(const char *pMaterial, int a1, int a2, int a3, int a4, int a5, int a6);
	virtual ~CHUDSprite();
	void getSize(int *wide, int *tall);
	void sub_10059620(int, int, int, int);
	int sub_100593e0(const struct wrect_100593e0 *, const struct wrect_100593e0 *, struct wrect_100593e0 *);
	void sub_1005aeb0(int, int, int, int, int, int, int, int);
	void sub_10059b70(int, int, int, int, int);
	void sub_1005a9e0(int x, int y, int w, int h, int, int r, int g, int b);
	void sub_1005c3b0(int, int, int, int, int);
	void sub_100594b0(float *s0, float *s1, float *t0, float *t1, int *w, int *h, void *rect);
	void sub_1005d280(int x, int y, int w, int h);
	void sub_1005a510(int x, int y, int w, int h, unsigned int tint);	// "CHUDSprite::drawAlphaColorTint": tint is 0x00RRGGBB
	void sub_1005c430(int, int, int, int, int, int);
	int m_unk04;
	int m_unk08;
	int m_unk0c;
	int m_unk10;
	int m_unk14;
	int m_unk18;
	int m_unk1c;
};
