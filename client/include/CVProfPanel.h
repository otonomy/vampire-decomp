// CVProfPanel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, its operator delete; nothing else yet
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CHudElement.h"
#include "vgui2__Panel.h"

class CVProfPanel : public CHudElement, public vgui2::Panel
{
public:
	virtual ~CVProfPanel();
	static void operator delete(void *pMem) { CHudElement::operator delete(pMem); }
	bool CHudElement_vfunc9();	// as in CHudHistoryResource (transplant)
	void sub_1018dda0(void *kv, void *node, int parent);
};
