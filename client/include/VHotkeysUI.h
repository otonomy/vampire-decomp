// VHotkeysUI: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, its operator delete; nothing else yet
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CBasePanel.h"
#include "CHudElement.h"
#include "vgui2__Label.h"

struct VHotkeysTail { int m_n1d40; int m_n1d44; int m_n1d48; struct HkEntry { int f0, f1, f2, f3, f4; } m_arr[10]; char m_b1e14; };
struct HotkeyRow_10183280;
class VHotkeysUI : public CBasePanel, public CHudElement
{
public:
	virtual ~VHotkeysUI();
	void sub_10183280(HotkeyRow_10183280 *row, int y, const char *title, int unused, int index, bool bLeft);
	void sub_10183aa0();
	void sub_10183a20();
	char m_pad0000[0x1c88 - 0x170 - sizeof(CHudElement)];
	vgui2::Label m_Label;
	VHotkeysUI(int a);
	virtual int vfunc21(int);
	virtual bool vfunc107();
	virtual void vfunc78(int);
	VHotkeysTail *Tail() { return (VHotkeysTail *)((char *)this + 0x1d40); }
	static void operator delete(void *pMem) { CHudElement::operator delete(pMem); }
};
