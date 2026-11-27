// VCharWizardUI: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, its operator delete; nothing else yet
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CHudElement.h"
#include "CBasePanel.h"
#include "vgui2__Label.h"
#include "vgui2__TextEntry.h"

class VCharWizardUI : public CHudElement, public CBasePanel
{
public:
	virtual ~VCharWizardUI();
	void sub_10174b20();
	void sub_101749c0();
	int sub_10174c60();
	static void operator delete(void *pMem) { CHudElement::operator delete(pMem); }
	struct PanelGroup
	{
		vgui2::Panel *m_p0;
		vgui2::Panel *m_p4;
		vgui2::Panel *m_p8;
		vgui2::Panel *m_pC;
		vgui2::Panel *m_p10;
	};
	int m_unk180[(0x360 - 0x180) / 4];
	PanelGroup m_groups[4];
	void sub_10175b30();
	void sub_10175b90(int idx);
};
