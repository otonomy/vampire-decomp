// CPredictableList: skeleton from the game's RTTI (2026-11-24)
// declared: its base, slot 1; the vtable has no deleting destructor
#pragma once
#include "IPredictableList.h"
#include "CBaseHandle.h"
#include "CUtlVector4.h"

class CPredictableList : public IPredictableList
{
public:
	union { struct { int m_unk04; int m_unk08; int m_unk0c; void *m_unk10; }; CUtlVector4 m_Predictables; };
	virtual void vfunc0(int);
	void sub_1009d0e0(CBaseHandle add);
	virtual void *vfunc1();
};
