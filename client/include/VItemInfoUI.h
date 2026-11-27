// VItemInfoUI: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, its operator delete; nothing else yet
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CHudElement.h"
#include "CBasePanel.h"
#include "vgui2__Label.h"
#include "vgui2__TextEntry.h"

struct VIILabel { char m_data[0xb8]; void sub_101b1fc0(CBasePanel *, const char *, void *); void sub_101aa230(void *); VIILabel(CBasePanel *p, const char *n, void *t) { sub_101b1fc0(p, n, t); } };
struct VIIEdit { char m_data[0x128]; void sub_101acaa0(CBasePanel *, const char *); void sub_101aa230(void *); VIIEdit(CBasePanel *p, const char *n) { sub_101acaa0(p, n); } };

class VItemInfoUI : public CHudElement, public CBasePanel
{
public:
	VItemInfoUI(int a);
	bool m_b180;
	int m_n184;
	VIILabel m_bkg;
	VIIEdit m_desc;
	VIILabel m_help;
	char m_b420;
	virtual ~VItemInfoUI();
	void sub_10184ba0();
	void sub_10184bc0(int a, char b, int c);
	void sub_10186860();
	void sub_10186890();
	void sub_10186450(int arg);
	void sub_10186620(int idx);
	void sub_10186530(const char *psz, int n);
	static void operator delete(void *pMem) { CHudElement::operator delete(pMem); }
	void sub_101838a0();	// provisional, like sub_10186860 (transplant)
};
