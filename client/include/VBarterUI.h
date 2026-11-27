// VBarterUI: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, its operator delete; nothing else yet
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CHudElement.h"
#include "CBasePanel.h"

class VBarterUI : public CHudElement, public CBasePanel
{
public:
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
