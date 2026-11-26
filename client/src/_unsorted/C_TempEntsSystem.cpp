// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100c50d0 size=0x57
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern int sub_10032250(int, int, int, int);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc5
void C_TempEntsSystem::vfunc5(int filter, int delay, int pos, int dir)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_10032250(filter, delay, pos, dir);
}
// END FUNCTION

// FUNCTION: 0x100c5130 size=0xaf
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

void sub_10032a60(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(void *);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

void C_TempEntsSystem::vfunc6(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(C_BasePlayer::GetLocalPlayer());
	}
	if (!pFilter->v2())
		return;

	sub_10032a60((int)pFilter, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19);
}
// END FUNCTION

// FUNCTION: 0x100c51e0 size=0xa5
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

void sub_10032e10(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(void *);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc7
void C_TempEntsSystem::vfunc7(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(C_BasePlayer::GetLocalPlayer());
	}
	if (!pFilter->v2())
		return;

	sub_10032e10((int)pFilter, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17);
}
// END FUNCTION

// FUNCTION: 0x100c5290 size=0xa5
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

void sub_100334f0(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(void *);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc8
void C_TempEntsSystem::vfunc8(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(C_BasePlayer::GetLocalPlayer());
	}
	if (!pFilter->v2())
		return;

	sub_100334f0((int)pFilter, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17);
}
// END FUNCTION

// FUNCTION: 0x100c5340 size=0xa5
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"
#include "C_RecipientFilter.h"

void sub_10033180(void *filter, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18);

// TARGET: C_TempEntsSystem::vfunc9
void C_TempEntsSystem::vfunc9(void *filter_, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18)
{
	if (CanPredict())
	{
		C_RecipientFilter *filter = (C_RecipientFilter *)filter_;
		if (!filter->sub_100be140())
			filter->sub_100bdf90(C_BasePlayer::GetLocalPlayer());
		if (filter->vfunc2())
			sub_10033180(filter, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18);
	}
}
// END FUNCTION

// FUNCTION: 0x100c53f0 size=0xa0
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"
#include "C_RecipientFilter.h"
void sub_10033860(void *, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
void C_TempEntsSystem::vfunc10(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
	if (!CanPredict())
		return;
	C_RecipientFilter *f = (C_RecipientFilter *)filter;
	if (!f->sub_100be140())
		f->sub_100bdf90(C_BasePlayer::GetLocalPlayer());
	if (f->vfunc2())
		sub_10033860(f, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
}
// END FUNCTION

// FUNCTION: 0x100c5490 size=0xa5
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

void sub_10033bd0(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(void *);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc11
void C_TempEntsSystem::vfunc11(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(C_BasePlayer::GetLocalPlayer());
	}
	if (!pFilter->v2())
		return;

	sub_10033bd0((int)pFilter, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17);
}
// END FUNCTION

// FUNCTION: 0x100c5540 size=0x57
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern int sub_10033f70(int, int, int, int);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc12
void C_TempEntsSystem::vfunc12(int filter, int delay, int pos, int dir)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_10033f70(filter, delay, pos, dir);
}
// END FUNCTION

// FUNCTION: 0x100c55a0 size=0x70
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"
#include "C_RecipientFilter.h"

void __cdecl sub_100346b0(int, int, int, int, int, int, int, int, int);

void C_TempEntsSystem::vfunc13(int f1, int f2, int f3, int f4, int f5, int f6, int f7, int f8, int f9)
{
	if ( CanPredict() )
	{
		C_RecipientFilter *filter = (C_RecipientFilter *)f1;
		if ( !filter->sub_100be140() )
			filter->sub_100bdf90( C_BasePlayer::GetLocalPlayer() );
		if ( filter->vfunc2() )
			sub_100346b0( f1, f2, f3, f4, f5, f6, f7, f8, f9 );
	}
}
// END FUNCTION

// FUNCTION: 0x100c5610 size=0x70
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"
#include "C_RecipientFilter.h"
#include "Vector.h"

void sub_10034220(int, int, Vector *, Vector *, int, int, int, int, int);

void C_TempEntsSystem::vfunc14(int f1, int f2, Vector *f3, Vector *f4, int f5, int f6, int f7, int f8, int f9)
{
	if ( CanPredict() )
	{
		C_RecipientFilter *filter = (C_RecipientFilter *)f1;
		if ( !filter->sub_100be140() )
			filter->sub_100bdf90( C_BasePlayer::GetLocalPlayer() );
		if ( filter->vfunc2() )
			sub_10034220( f1, f2, f3, f4, f5, f6, f7, f8, f9 );
	}
}
// END FUNCTION

// FUNCTION: 0x100c5680 size=0x75
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"
#include "C_RecipientFilter.h"

void __cdecl sub_10034f20(int, int, int, int, int, int, int, int, int, int);

void C_TempEntsSystem::vfunc15(int filter, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    if (CanPredict())
    {
        C_RecipientFilter *pFilter = (C_RecipientFilter *)filter;
        if (!pFilter->sub_100be140())
            pFilter->sub_100bdf90(C_BasePlayer::GetLocalPlayer());
        if (pFilter->vfunc2())
            sub_10034f20(filter, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }
}
// END FUNCTION

// FUNCTION: 0x100c5700 size=0x5c
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern void sub_100352c0(int filter, int delay, int pos, int dir, int extra);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc16
void C_TempEntsSystem::vfunc16(int filter, int delay, int pos, int dir, int extra)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_100352c0(filter, delay, pos, dir, extra);
}
// END FUNCTION

// FUNCTION: 0x100c5760 size=0x6b
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"
#include "C_RecipientFilter.h"

extern void sub_10035690(int, int, int, int, int, int, int, int);

class FilterView
{
public:
	bool sub_100be140();
};

void C_TempEntsSystem::vfunc17(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	if ( !CanPredict() )
		return;

	C_RecipientFilter *pFilter = (C_RecipientFilter *)filter;

	if ( !((FilterView *)pFilter)->sub_100be140() )
		pFilter->sub_100bdf90( C_BasePlayer::GetLocalPlayer() );

	if ( pFilter->vfunc2() )
		sub_10035690(filter, a1, a2, a3, a4, a5, a6, a7);
}
// END FUNCTION

// FUNCTION: 0x100c57d0 size=0x6b
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"
#include "C_RecipientFilter.h"

extern void sub_100359d0(int, int, int, int, int, int, int, int);

class FilterView
{
public:
	bool sub_100be140();
};

void C_TempEntsSystem::vfunc18(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	if ( !CanPredict() )
		return;

	C_RecipientFilter *pFilter = (C_RecipientFilter *)filter;

	if ( !((FilterView *)pFilter)->sub_100be140() )
		pFilter->sub_100bdf90( C_BasePlayer::GetLocalPlayer() );

	if ( pFilter->vfunc2() )
		sub_100359d0(filter, a1, a2, a3, a4, a5, a6, a7);
}
// END FUNCTION

// FUNCTION: 0x100c58b0 size=0x75
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"
#include "C_RecipientFilter.h"

void __cdecl sub_10036140(int, int, int, int, int, int, int, int, int, int);

void C_TempEntsSystem::vfunc20(int filter, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    if (CanPredict())
    {
        C_RecipientFilter *pFilter = (C_RecipientFilter *)filter;
        if (!pFilter->sub_100be140())
            pFilter->sub_100bdf90(C_BasePlayer::GetLocalPlayer());
        if (pFilter->vfunc2())
            sub_10036140(filter, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }
}
// END FUNCTION

// FUNCTION: 0x100c5930 size=0x7a
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"
#include "C_RecipientFilter.h"


void sub_10036fa0(void *filter, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11);

void C_TempEntsSystem::vfunc21(void *arg0, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
	bool bOk = CanPredict();
	if (bOk == false)
		return;

	C_RecipientFilter *filter = (C_RecipientFilter *)arg0;
	if (!filter->sub_100be140())
		filter->sub_100bdf90(C_BasePlayer::GetLocalPlayer());
	if (filter->vfunc2())
		sub_10036fa0(filter, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}
// END FUNCTION

// FUNCTION: 0x100c59b0 size=0x57
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern int sub_100377e0(int, int, int, int);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc22
void C_TempEntsSystem::vfunc22(int filter, int delay, int pos, int dir)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_100377e0(filter, delay, pos, dir);
}
// END FUNCTION

// FUNCTION: 0x100c5a10 size=0x97
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern void sub_10038530(int, int, int, int, int, int, int, int, int, int, char, char, char, char, char, char);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc23
void C_TempEntsSystem::vfunc23(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_10038530(filter, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);
}
// END FUNCTION

// FUNCTION: 0x100c5ab0 size=0x66
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"
#include "C_RecipientFilter.h"

extern void sub_10038700(int, int, int, int, int, int, int);

class FilterView
{
public:
	bool sub_100be140();
};

void C_TempEntsSystem::vfunc24(int filter, int a1, int a2, int a3, int a4, int a5, int a6)
{
	if ( !CanPredict() )
		return;

	C_RecipientFilter *pFilter = (C_RecipientFilter *)filter;

	if ( !((FilterView *)pFilter)->sub_100be140() )
		pFilter->sub_100bdf90( C_BasePlayer::GetLocalPlayer() );

	if ( pFilter->vfunc2() )
		sub_10038700(filter, a1, a2, a3, a4, a5, a6);
}
// END FUNCTION

// FUNCTION: 0x100c5b20 size=0x66
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"
#include "C_RecipientFilter.h"

extern void sub_10037b90(int, int, int, int, int, int, int);

class FilterView
{
public:
	bool sub_100be140();
};

void C_TempEntsSystem::vfunc27(int filter, int a1, int a2, int a3, int a4, int a5, int a6)
{
	if ( !CanPredict() )
		return;

	C_RecipientFilter *pFilter = (C_RecipientFilter *)filter;

	if ( !((FilterView *)pFilter)->sub_100be140() )
		pFilter->sub_100bdf90( C_BasePlayer::GetLocalPlayer() );

	if ( pFilter->vfunc2() )
		sub_10037b90(filter, a1, a2, a3, a4, a5, a6);
}
// END FUNCTION

// FUNCTION: 0x100c5b90 size=0x5c
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern void sub_100370b0(int filter, int delay, int pos, int dir, int extra);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc28
void C_TempEntsSystem::vfunc28(int filter, int delay, int pos, int dir, int extra)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_100370b0(filter, delay, pos, dir, extra);
}
// END FUNCTION

// FUNCTION: 0x100c5bf0 size=0x52
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern void sub_1003a430(int filter, int delay, int pos);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc29
void C_TempEntsSystem::vfunc29(int filter, int delay, int pos)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_1003a430(filter, delay, pos);
}
// END FUNCTION

// FUNCTION: 0x100c5c50 size=0x57
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern int sub_10032230(int, int, int, int);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc30
void C_TempEntsSystem::vfunc30(int filter, int delay, int pos, int dir)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_10032230(filter, delay, pos, dir);
}
// END FUNCTION

// FUNCTION: 0x100c5cb0 size=0x5c
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern void sub_100365b0(int filter, int delay, int pos, int dir, int extra);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc31
void C_TempEntsSystem::vfunc31(int filter, int delay, int pos, int dir, int extra)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_100365b0(filter, delay, pos, dir, extra);
}
// END FUNCTION

// FUNCTION: 0x100c5d10 size=0x61
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern void sub_1003e820();

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

void C_TempEntsSystem::vfunc32(int filter, int a, int b, int c, int d, int e)
{
	if (!CanRunTempEnt(this))
		return;
	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	if (!pFilter->v2())
		return;
	((void (*)(int, int, int, int, int, int))sub_1003e820)(filter, a, b, c, d, e);
}
// END FUNCTION

// FUNCTION: 0x100c5d80 size=0x57
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern int sub_1003edc0(int, int, int, int);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc33
void C_TempEntsSystem::vfunc33(int filter, int delay, int pos, int dir)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_1003edc0(filter, delay, pos, dir);
}
// END FUNCTION

// FUNCTION: 0x100c5de0 size=0x61
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern void sub_1003eeb0(int, int, int, int, int, int);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc34
void C_TempEntsSystem::vfunc34(int filter, int a2, int a3, int a4, int a5, int a6)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_1003eeb0(filter, a2, a3, a4, a5, a6);
}
// END FUNCTION

// FUNCTION: 0x100c5e50 size=0x61
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern void sub_1003f1a0();

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

void C_TempEntsSystem::vfunc35(int filter, int a, int b, int c, int d, int e)
{
	if (!CanRunTempEnt(this))
		return;
	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	if (!pFilter->v2())
		return;
	((void (*)(int, int, int, int, int, int))sub_1003f1a0)(filter, a, b, c, d, e);
}
// END FUNCTION

// FUNCTION: 0x100c5ec0 size=0x7f
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern void sub_1003f4e0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, const char *a8, char a9, int a10, int a11, int a12);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

void C_TempEntsSystem::vfunc36(int filter, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_1003f4e0(filter, a2, a3, a4, a5, a6, a7, (const char *)a8, (char)a9, 0xff, 0xff, 0xff);
}
// END FUNCTION

// FUNCTION: 0x100c5f40 size=0x6b
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"
#include "C_RecipientFilter.h"

extern void sub_1003f8c0(int, int, int, int, int, int, int, int);

class FilterView
{
public:
	bool sub_100be140();
};

void C_TempEntsSystem::vfunc37(int filter, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	if ( !CanPredict() )
		return;

	C_RecipientFilter *pFilter = (C_RecipientFilter *)filter;

	if ( !((FilterView *)pFilter)->sub_100be140() )
		pFilter->sub_100bdf90( C_BasePlayer::GetLocalPlayer() );

	if ( pFilter->vfunc2() )
		sub_1003f8c0(filter, a1, a2, a3, a4, a5, a6, a7);
}
// END FUNCTION

// FUNCTION: 0x100c5fb0 size=0x57
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern int sub_10040050(int, int, int, int);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc38
void C_TempEntsSystem::vfunc38(int filter, int delay, int pos, int dir)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_10040050(filter, delay, pos, dir);
}
// END FUNCTION

// FUNCTION: 0x100c6010 size=0x5c
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern void sub_10040990(int filter, int delay, int pos, int dir, int extra);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc39
void C_TempEntsSystem::vfunc39(int filter, int delay, int pos, int dir, int extra)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_10040990(filter, delay, pos, dir, extra);
}
// END FUNCTION

// FUNCTION: 0x100c6070 size=0x66
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"
#include "C_RecipientFilter.h"

extern void sub_10040d80(int, int, int, int, int, int, int);

class FilterView
{
public:
	bool sub_100be140();
};

void C_TempEntsSystem::vfunc40(int filter, int a1, int a2, int a3, int a4, int a5, int a6)
{
	if ( !CanPredict() )
		return;

	C_RecipientFilter *pFilter = (C_RecipientFilter *)filter;

	if ( !((FilterView *)pFilter)->sub_100be140() )
		pFilter->sub_100bdf90( C_BasePlayer::GetLocalPlayer() );

	if ( pFilter->vfunc2() )
		sub_10040d80(filter, a1, a2, a3, a4, a5, a6);
}
// END FUNCTION

// FUNCTION: 0x100c60e0 size=0x57
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern int sub_100411c0(int, int, int, int);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc41
void C_TempEntsSystem::vfunc41(int filter, int delay, int pos, int dir)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	sub_100411c0(filter, delay, pos, dir);
}
// END FUNCTION

// FUNCTION: 0x100c6140 size=0x61
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern void sub_1003daf0();

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

void C_TempEntsSystem::vfunc42(int filter, int a, int b, int c, int d, int e)
{
	if (!CanRunTempEnt(this))
		return;
	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	if (!pFilter->v2())
		return;
	((void (*)(int, int, int, int, int, int))sub_1003daf0)(filter, a, b, c, d, e);
}
// END FUNCTION

// FUNCTION: 0x100c61b0 size=0x61
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern void sub_100bb3f0();

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

void C_TempEntsSystem::vfunc43(int filter, int a, int b, int c, int d, int e)
{
	if (!CanRunTempEnt(this))
		return;
	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	if (!pFilter->v2())
		return;
	((void (*)(int, int, int, int, int, int))sub_100bb3f0)(filter, a, b, c, d, e);
}
// END FUNCTION

// FUNCTION: 0x100c6270 size=0x4b
#include "C_BasePlayer.h"
#include "C_TempEntsSystem.h"

extern void (__cdecl *g_101e3114)(const char *, ...);

struct CTempEntRecipientFilter
{
	virtual void v0();
	virtual void v1();
	virtual int v2();
	bool sub_100be140();
	void sub_100bdf90(int);
};

static inline bool CanRunTempEnt(const C_TempEntsSystem *p)
{
	if (p->m_nSuppressCount > 0)
		return false;
	return !p->m_bSuppressEvent;
}

// TARGET: C_TempEntsSystem::vfunc2
void C_TempEntsSystem::vfunc2(int filter, int delay, int pos, int dir, int extra)
{
	if (!CanRunTempEnt(this))
		return;

	CTempEntRecipientFilter *pFilter = (CTempEntRecipientFilter *)filter;
	if (!pFilter->sub_100be140())
	{
		pFilter->sub_100bdf90(((int)C_BasePlayer::GetLocalPlayer()));
	}
	if (!pFilter->v2())
		return;

	g_101e3114("client temp ent TParticle not implemented\n");
}
// END FUNCTION

// FUNCTION: 0x100c6420 size=0x20
#include "C_TempEntsSystem.h"
namespace lifted {
extern char g_10232134;
int sub_101d1296(int);
}
void * C_TempEntsSystem::vfunc0(char a0)
{
    *(int *)this = (int)&lifted::g_10232134;
    if ((a0 & 1) != 0) {
        lifted::sub_101d1296((int)this);
    }
    return this;
}
// END FUNCTION
