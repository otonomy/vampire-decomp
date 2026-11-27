// CVTraitDependencyValue_t (RTTI .?AVCVTraitDependencyValue_t@@): the value dependency of a trait. Base
// CVTraitSubDependency_t at +0x4 is not modelled; the member at +0x18 is built by sub_102056d0 (0x10003440).
#pragma once

struct CUnknown102056d0Sub { void sub_10161410(); };

class CVTraitDependencyValue_t
{
public:
	void *m_vptr;	// 0x0
	char m_pad0004[0x18 - 4];
	CUnknown102056d0Sub m_18;	// 0x18

	CVTraitDependencyValue_t *sub_10161800();
	CVTraitDependencyValue_t *sub_10161820(int a);	// the same constructor with one unused stack argument (ret 4)	// the constructor body: builds m_18, stores the vftable (0x10483d00), then vfunc0 (0x10002563), returns this
	void sub_10161840();	// CVTraitDependencyValue_t::vfunc0, called directly
	void vfunc0();
	void vfunc1(const char *psz);	// the constructor body: resets the block at +4 and stores -1 at +0x14
	char m_pad0019[0x2c - 0x19];
};
