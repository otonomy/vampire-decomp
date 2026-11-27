// vgui2::ComboBox: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__TextEntry.h"

namespace vgui2
{
class ComboBox : public vgui2::TextEntry
{
public:
	virtual ~ComboBox();
	ComboBox(Panel *parent, const char *name, int numLines, bool editable);
	void sub_101c7950(int);
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with ComboBox's own function
	virtual void vfunc11(int, int);
	virtual int vfunc74(int);
	virtual void vfunc78(int);
	virtual void vfunc81();
	virtual void vfunc85();
	virtual void vfunc86();
	virtual void vfunc87(int);
	virtual void vfunc88(int);
	virtual void vfunc101();
	virtual int vfunc102();
	virtual void vfunc167(const char *);
	// the slots ComboBox adds to its base's vtable: 173-184, vfuncK at slot K
	virtual void vfunc173(int);
	virtual void vfunc174(int);
	virtual int vfunc175();
	virtual int vfunc176(int, int);
	virtual int vfunc177();
	virtual void vfunc178();
	virtual int vfunc179(float);
	virtual int vfunc180();
	virtual int vfunc181();
	virtual void vfunc182();
	virtual int vfunc183();
	virtual void vfunc184();
};
}
