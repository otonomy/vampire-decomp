// vgui2::Button: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Label.h"

namespace vgui2
{
class KeyValues;
class Button : public vgui2::Label
{
public:
	Button(int, int, int);
	virtual ~Button();
	void sub_101b3580();
	void sub_101b4100(int);
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with Button's own function
	virtual void vfunc14();
	bool vfunc14(vgui2::KeyValues *data);
	virtual int vfunc74(int);
	virtual void vfunc75(int);
	virtual int vfunc76(int);
	virtual int vfunc77();
	virtual void vfunc80();
	virtual void vfunc81();
	virtual void vfunc85();
	virtual void vfunc86();
	virtual void vfunc87(int);
	virtual void vfunc88(int);
	virtual void vfunc89(int);
	virtual void vfunc91(int);
	virtual void vfunc94(int);
	virtual void vfunc98();
	virtual void vfunc101();
	virtual int vfunc102();
	virtual void vfunc129();
	void sub_101a98f0(int, int);
	// the slots Button adds to its base's vtable: 138-165, vfuncK at slot K
	virtual void vfunc138(char);
	virtual bool vfunc139();
	virtual bool vfunc140();
	virtual void vfunc141(char);
	virtual bool vfunc142();
	virtual void vfunc143(char);
	virtual bool vfunc144();
	virtual bool vfunc145(char);
	virtual bool vfunc146();
	virtual int vfunc147();
	virtual void vfunc148(int, bool);
	virtual bool vfunc149(int);
	virtual void vfunc150();
	virtual void vfunc151(int);
	virtual void vfunc152(char);
	virtual int vfunc153(unsigned int, unsigned int);
	virtual void vfunc154(unsigned int, unsigned int);
	virtual void vfunc155(unsigned int, unsigned int);
	virtual int vfunc156(int);
	virtual int vfunc157(int);
	virtual int vfunc158(int);
	virtual int vfunc159(int);
	virtual int vfunc160(int);
	virtual void vfunc161(int);
	virtual void vfunc162(int);
	virtual void vfunc163(int, int, int, int);
	virtual int vfunc164(int, int, int, int);
	virtual void vfunc165(int);
};
}
