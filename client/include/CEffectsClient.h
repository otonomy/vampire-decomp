// CEffectsClient: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases; nothing else yet
#pragma once
#include "IEffects.h"

class CEffectsClient : public IEffects
{
public:
	virtual void vfunc4(const class Vector &origin, int a, int b, int c);
	virtual void vfunc3(const class Vector &origin, int a, int b, int c);
	virtual void vfunc5(const class Vector &origin, int a, int b, int c);
	virtual void vfunc6(const class Vector &origin, int a);
	virtual void vfunc7(const class Vector &origin, int a, int b);
	virtual void vfunc2(const class Vector &origin, int a, float b, int c);
	virtual void vfunc8(const class Vector &origin, int a);
};
