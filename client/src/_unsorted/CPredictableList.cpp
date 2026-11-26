// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1009d2c0 size=0x22
#include "CClientEntityList.h"
#include "CPredictableList.h"
#include "CClientEntityList.h"
#include "CBaseHandle.h"
struct CIdxView100445d0 { CBaseHandle *sub_100445d0(int i); };
void CPredictableList::vfunc0(int i)
{
	cl_entitylist->sub_100d0dc0(*((CIdxView100445d0 *)((char *)this + 4))->sub_100445d0(i));
}
// END FUNCTION

// FUNCTION: 0x1009d2f0 size=0x4
#include "CPredictableList.h"

// TARGET: CPredictableList::vfunc1
void *CPredictableList::vfunc1()
{
	return m_unk10;
}
// END FUNCTION
