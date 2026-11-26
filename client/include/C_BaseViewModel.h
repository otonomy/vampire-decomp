// C_BaseViewModel: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseAnimating.h"
class C_BasePlayer;

class C_BaseViewModel : public C_BaseAnimating
{
public:
	C_BaseViewModel();
	virtual ~C_BaseViewModel();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_BaseViewModel's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual int vfunc17();
	virtual void vfunc19();
	virtual void vfunc21();
	virtual void vfunc29(char);
	virtual void vfunc37();
	virtual int vfunc86();
	virtual void vfunc118(int);
	virtual void vfunc120(int, int);
	virtual float vfunc122();
	virtual void vfunc127(const Vector &origin, const QAngle &angles, int event, const char *options);
	C_BasePlayer *sub_100ac070();
	virtual int vfunc139(int);
	virtual void vfunc141();
	virtual bool vfunc142();
	// the slots C_BaseViewModel adds to its base's vtable: 143-145, vfuncK at slot K
	virtual void vfunc143(int);
	virtual int vfunc51();
	virtual void vfunc144();
	virtual void *vfunc145();
	char m_pad0014[0xa8 - 0x14];
	int m_unka8;
	char m_pad00ac[0x650 - 0xac];
	float m_fl650;
	float m_fl654;
	char m_pad0658[0x7bc - 0x658];
	void *m_pMem; int m_allocCount; int m_growSize; int m_size; void *m_pElements;
	void sub_100ab890(void *p);
	char m_pad07d0[0x7f8 - 0x7d0];
};
