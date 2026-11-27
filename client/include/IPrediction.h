// IPrediction: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the virtual functions before the destructor are not declared yet
#pragma once

class IPrediction
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the slots IPrediction adds to its base's vtable: 0-15, vfuncK at slot K
	virtual ~IPrediction();
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3();
	virtual void vfunc4();
	virtual void vfunc5();
	virtual void vfunc6(bool error_check, int commands_acknowledged);
	virtual int vfunc7();
	virtual void vfunc8(class Vector *);
	virtual void vfunc9(int);
	virtual void vfunc10(class Vector *);
	virtual void vfunc11(const class Vector *v);
	virtual bool vfunc12();
	virtual int vfunc13();
	virtual bool vfunc14();
	virtual int vfunc15();
	void * vfunc0(char);	// as in IParticleEffect (transplant)
};
