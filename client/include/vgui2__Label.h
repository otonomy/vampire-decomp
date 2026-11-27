// vgui2::Label: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Panel.h"

namespace vgui2
{
class KeyValues;
class Label : public vgui2::Panel
{
public:
	Label(vgui2::Panel *, const char *, const char *);
	void sub_101aa230(void *);
	void sub_101b2610();
	void sub_101b2f70(int);
	void sub_101b2160(const char *);
	void sub_101a9920(int *, int *);
	virtual ~Label();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with Label's own function
	virtual void vfunc11(int, int);
	virtual void vfunc14();
	bool vfunc14(vgui2::KeyValues *data);
	virtual int vfunc46(int);
	virtual int vfunc51(int);
	virtual int vfunc53(int);
	virtual int vfunc72(int);
	virtual int vfunc74(int);
	virtual void vfunc75(int);
	virtual int vfunc76(int);
	virtual int vfunc77();
	virtual void vfunc87(int);
	virtual void vfunc98();
	virtual void vfunc101();
	virtual int vfunc102();
	virtual void vfunc105(Panel *);
	// the slots Label adds to its base's vtable: 107-137, vfuncK at slot K
	virtual int vfunc107(int);
	virtual void vfunc108(const char *);
	virtual int vfunc109();
	virtual void vfunc110(int *, int *);
	virtual int vfunc111(int);
	virtual void vfunc112(int, int);
	virtual int vfunc113(int);
	virtual int vfunc114(int);
	virtual int vfunc115(int);
	virtual int vfunc116(int);
	virtual void vfunc117(int);
	virtual void vfunc118(int);
	virtual int vfunc119();
	virtual short vfunc120(short);
	virtual int vfunc121(int);
	virtual int vfunc122(void *, int);
	virtual void vfunc123(int, int, int);
	virtual void vfunc124(int, int);
	virtual void vfunc125();
	virtual int vfunc126();
	virtual int vfunc127();
	virtual void vfunc128();
	virtual void vfunc129();
	virtual int vfunc130(const char *);
	virtual void vfunc131(int *, int *, int *, int *);
	virtual int vfunc132();
	virtual void vfunc133(int, int, int, int, int, int);
	virtual void vfunc134();
	virtual void vfunc135(int);
	virtual int vfunc136(int);
	virtual int vfunc137();
};
}
