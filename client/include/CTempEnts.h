// CTempEnts: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#define CTEMPENTS_HEADER
#include "ITempEnts.h"
#include "C_LocalTempEntity.h"

class CTempEnts : public ITempEnts
{
public:
	CTempEnts();
	void sub_1003cd80();
	void sub_1003ce90(void *, int);
	void sub_1003cee0();
	void *sub_1003cf20(const void *, const void *);
	struct TempEntView *sub_1003cdd0(const void *org, void *model);
	int m_unk4;
	C_LocalTempEntity m_TempEnts[500];
	void *m_pFreeTempEnts;
	void *m_pHead;
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CTempEnts's own function
	virtual void vfunc0();
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3();
	virtual void vfunc4(const void *, int, int, int, int, int, float, float);
	virtual void vfunc5();
	virtual int vfunc6(int, int, int, int, char, int, int, int, int);
	virtual void vfunc7(const Vector &pos, const Vector &size, const Vector &dir, float randRange, float life, int count, int modelIndex, char flags);	// BreakModel
	virtual void vfunc8(const Vector &mins, const Vector &maxs, float height, int modelIndex, int count, float speed);	// Bubbles
	virtual void vfunc9(const Vector &start, const Vector &end, float flHeight, int modelIndex, int count, float speed);
	virtual void vfunc10(C_LocalTempEntity *, int, int);
	virtual void vfunc11(class C_BaseEntity *pent, int modelIndex, int density);	// FizzEffect
	virtual void vfunc12();
	virtual void vfunc13(C_LocalTempEntity *, int);
	virtual C_LocalTempEntity *vfunc14(const Vector &pos, const Vector &dir, float scale, int modelIndex, int rendermode, int renderfx, float a, float life, int flags, int r, int g, int b);
	virtual void vfunc15(int, int, float, float);
	virtual void vfunc16(int);
	virtual void vfunc17(int, int, int, int, int, int);
	virtual void vfunc18(C_LocalTempEntity *pTemp, float damp);	// PlaySound: shell / shotgun shell / clip drop sounds (pitch 90..124 now and then), louder with the fall speed
	virtual void vfunc19(const Vector &, const QAngle &, const QAngle &, int, const Vector &);
	// the slots CTempEnts adds to its base's vtable: 20-26, vfuncK at slot K
	virtual ~CTempEnts();
	virtual void vfunc21(const Vector &, const QAngle &, int);
	virtual int vfunc22(int, int, int);
	virtual void vfunc23(const Vector &org, int ang, int unused);
	virtual int vfunc24(int, int, int);
	virtual void vfunc25(int, int, int, const char *, const char *, int, int);
	virtual void vfunc26(int, int, int, const char *, const char *, int, int);
};
