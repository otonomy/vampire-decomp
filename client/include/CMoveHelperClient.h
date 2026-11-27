// CMoveHelperClient: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor; nothing else yet
// the destructor is slot 14 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "IMoveHelper.h"
#include "Vector.h"

class CMoveHelperClient : public IMoveHelper
{
public:
	int m_unk04; int m_unk08; int m_unk0c; int m_unk10; int m_unk14; int m_unk18;
	virtual void vfunc1();
	virtual bool vfunc2(const struct CGameTrace &tr, const Vector &impactvelocity);
	void sub_1010f5b0(const Vector &origin, int channel, const char *sample, float volume, int level, int flags, int pitch);
	virtual void vfunc3();
	virtual void vfunc4(int idx, const char *fmt, ...);
	virtual bool vfunc7();
	virtual void vfunc12();
	virtual void vfunc15(bool bDevMsg, const char *fmt, ...);
	int vfunc16(Vector *p);
	virtual ~CMoveHelperClient();
	void vfunc19();
	int vfunc22(const Vector &pt);
	virtual void *vfunc20(const char *name, int *pSize);
};
