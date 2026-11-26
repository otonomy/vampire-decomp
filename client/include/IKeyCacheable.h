// IKeyCacheable: abstract interface (RTTI .?AVIKeyCacheable@@, vtable 0x10483bb8, 3 slots).
// Only the virtual destructor (slot 2, whose scalar deleting destructor is the game's 0x101f2010) is
// modelled; the two pure virtuals before it are placeholders (their signatures are not recovered yet).
#pragma once

class IKeyCacheable
{
public:
	virtual void vfunc0() = 0;
	virtual void vfunc1() = 0;
	virtual ~IKeyCacheable() {}
	void * vfunc2(char);	// as in IParticleEffect (transplant)
};
