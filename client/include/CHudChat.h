// CHudChat: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, its operator delete; nothing else yet
// the destructor is slot 0 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CHudElement.h"
#include "vgui2__Panel.h"

class CHudChatLine : public vgui2::Panel { public: CHudChatLine *sub_100f13a0(vgui2::Panel *parent, const char *name); };
class CHudChat : public CHudElement, public vgui2::Panel
{
public:
	CHudChat(int a);
	virtual ~CHudChat();
	virtual void vfunc13(int, int);
	void sub_100f24b0(int, int, int);
	void sub_100f2670(const char *name);
	static void operator delete(void *pMem) { CHudElement::operator delete(pMem); }
};
