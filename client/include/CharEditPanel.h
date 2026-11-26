// CharEditPanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, its operator delete; nothing else yet
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CHudElement.h"
#include "vgui2__PropertyDialog.h"

class CharEditPanel : public CHudElement, public vgui2::PropertyDialog
{
public:
	virtual ~CharEditPanel();
	void sub_10173110();
	void sub_10173210(void *dst, void *src, void *flag, void *defs);
	void sub_101740e0(bool bApply);
	void sub_101733d0(bool bDisconnect);
	void sub_101735a0();
	bool sub_10172ac0();
	char m_padA[0x274 - sizeof(CHudElement) - sizeof(vgui2::PropertyDialog)];
	int m_unk274;
	int m_unk278;
	int m_unk27c;
	int m_unk280;
	vgui2::Panel *m_p284;
	int m_unk288;
	int m_unk28c;
	vgui2::Panel *m_p290;
	vgui2::Panel *m_p294;
	char m_padB[0x4c0 - 0x298];
	vgui2::Panel *m_p4c0[5];
	vgui2::Panel *m_p4d4[10];
	char m_padB2[0xcf9 - 0x4fc];
	bool m_bCf9;
	char m_szCfa[0xed0 - 0xcfa];
	int m_ied0;
	int m_unked4;
	bool m_bEd8;
	char m_padD[0xee0 - 0xed9];
	int m_iee0;
	int m_iee4;
	bool m_bEe8;
	void sub_10172ae0();
	static void operator delete(void *pMem) { CHudElement::operator delete(pMem); }
	void vfunc3();	// as in VHCheckButton (transplant)
	void vfunc7();	// as in VHCheckButton (transplant)
	void vfunc4();	// as in CharEditPanel (transplant)
};
