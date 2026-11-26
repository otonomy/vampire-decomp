// CharEditStatsPanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, its operator delete, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include <stdlib.h>
#include "vgui2__PropertyPage.h"
#include "vgui2__Label.h"

struct CStatsSub1017f860 { void sub_1017f860(); };
class CharEditStatsPanel : public vgui2::PropertyPage
{
public:
	void sub_1017f640();
	void sub_10181cc0();
	void sub_1017dc20();
	void sub_10181f80();
	void sub_1017f610();
	void sub_10182460();
	int sub_10182450();
	int sub_1017f290();
	char m_pad0[0x20c - sizeof(vgui2::PropertyPage)];
	class vgui2::Label *m_pFeatLabels[16];
	char m_pad24c[0x2bc - 0x24c];
	vgui2::Panel *m_p2bc;
	vgui2::Panel *m_p2c0;
	vgui2::Panel *m_p2c4;
	vgui2::Panel *m_p2c8;
	int m_unk2cc; int m_unk2d0; int m_unk2d4;
	vgui2::Panel *m_p2d8;
	char m_pad2dc[0x434 - 0x2dc];
	bool m_bAutoLevel;
	void sub_10181ba0();
	void sub_10181bf0();
	void *sub_101808d0(const char *, int *);
	virtual ~CharEditStatsPanel();
	static void operator delete(void *pMem) { free(pMem); }
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CharEditStatsPanel's own function
	virtual void vfunc3();
	virtual int vfunc21(int);
	virtual void vfunc78(int);
	virtual void vfunc98();
	virtual int vfunc102();
	// the slots CharEditStatsPanel adds to its base's vtable: 123-123, vfuncK at slot K
	virtual void vfunc123();
};
