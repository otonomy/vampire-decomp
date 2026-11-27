// VBarterUI: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, its operator delete; nothing else yet
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CHudElement.h"
#include "CBasePanel.h"

struct VBarterSlot { vgui2::Panel *a; vgui2::Panel *b; vgui2::Panel *c; };
struct IVBarterObj { virtual void vfunc0(int); };

class VBarterUI : public CHudElement, public CBasePanel
{
public:
	int m_unk180; int m_unk184;
	VBarterSlot m_Slots1[0x18];
	VBarterSlot m_Slots2[0x20];
	vgui2::Panel *m_p428; vgui2::Panel *m_p42c; vgui2::Panel *m_p430; vgui2::Panel *m_p434;
	vgui2::Panel *m_p438; vgui2::Panel *m_p43c; vgui2::Panel *m_p440; vgui2::Panel *m_p444;
	vgui2::Panel *m_p448;
	int m_unk44c[(0x4dc - 0x44c) / 4];
	IVBarterObj *m_p4dc;
	virtual ~VBarterUI();
	void sub_1016cdc0();
	void sub_1016b790();
	void sub_1016edf0();
	bool sub_10170aa0(void *pItem, bool bSell);
	void sub_1016f4a0();
	void sub_1016d150();
	void sub_1016ef40();
	void sub_1016f1b0(int a);
	void sub_1016f2c0();
	void sub_1016f3a0(const char *pszIcon);
	void sub_101703e0(int nArg);
	void sub_10170580();
	static void operator delete(void *pMem) { CHudElement::operator delete(pMem); }
};
