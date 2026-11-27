// IClientMode: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the virtual functions before the destructor are not declared yet
#pragma once

class IClientMode
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the slots IClientMode adds to its base's vtable: 0-35, vfuncK at slot K
	virtual ~IClientMode();
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3();
	virtual void vfunc4();
	virtual void vfunc5();
	virtual void vfunc6();
	virtual char * vfunc7();
	virtual int vfunc8(int);
	virtual int vfunc9(int);
	virtual bool vfunc10();
	virtual bool vfunc11(int);
	virtual void vfunc12();
	virtual bool vfunc13();
	virtual bool vfunc14();
	virtual void vfunc15(int);
	virtual int vfunc16(int, int, const char *);
	virtual void vfunc17();
	virtual void vfunc18();
	virtual bool vfunc19();
	virtual int vfunc20();
	virtual void vfunc21();
	virtual void vfunc22(float flInputSampleTime, class CUserCmd *cmd);
	virtual void vfunc23(int);
	virtual void vfunc24(int);
	virtual void vfunc25();
	virtual bool vfunc26();
	virtual bool vfunc27();
	virtual void vfunc28(int, int, int, int);
	virtual void vfunc29(int);
	virtual void vfunc30();
	virtual void vfunc31();
	virtual void vfunc32();
	virtual int vfunc33(int);
	virtual int vfunc34();
	virtual void vfunc35();
	void * vfunc0(char);	// as in IParticleEffect (transplant)
};
