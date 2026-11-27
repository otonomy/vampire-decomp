// CVMainMenu: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CBasePanel.h"
#include "utlvector.h"

class CVMainMenu : public CBasePanel
{
public:
	virtual ~CVMainMenu();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CVMainMenu's own function
	virtual void vfunc97();
	virtual void vfunc98();
	void sub_10066250();
	void sub_10067540(bool);
	void sub_10067450();
	int sub_10067850();
	void sub_10065f40();
	char *sub_10065eb0(int);
	int *sub_100678a0(int *);
	void sub_100660e0();
	void sub_10066440();
	bool sub_10067750(int action);
	bool sub_10065d30();
	bool sub_10065c90();
	void sub_10067610(int action);
	int sub_10065db0(int, int, int);
	void sub_10065950();
	void sub_10065a00();
	void sub_10066af0();
	CUtlVector<int> m_vec170;
	int m_n184;
	int m_n188;
	int m_unk18c;
	int m_n190;
	char m_unk194[0x2d8 - 0x194];
	float m_f2d8;
	float m_f2dc;
	float m_f2e0;
	int m_unk2e4;
	int m_unk2e8;
	CUtlVector<int> m_vec2ec;
	struct CVMenuSub *m_p300;
	int m_n304;
	int m_n308;
	int m_n30c;
	int m_n310;
	int m_n314;
	char m_pad318[0x5b4 - 0x318];
};
