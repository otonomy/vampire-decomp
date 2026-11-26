// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10002680 size=0x3
#include "C_BaseAnimating.h"

// TARGET: C_BaseAnimating::sub_10002680
void C_BaseAnimating::sub_10002680(int)
{
}
// END FUNCTION

// FUNCTION: 0x10002690 size=0x1
#include "C_BaseAnimating.h"
void C_BaseAnimating::vfunc141()
{
}
// END FUNCTION

// FUNCTION: 0x1008edc0 size=0x6
#include "C_BaseAnimating.h"
namespace lifted {
extern char g_102ad9f0;
}
int C_BaseAnimating::vfunc16()
{
    return (int)&lifted::g_102ad9f0;
}
// END FUNCTION

// FUNCTION: 0x1008edd0 size=0x3
#include "C_BaseAnimating.h"
int C_BaseAnimating::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1008f5a0 size=0x1e
#include "C_BaseAnimating.h"

// VC6 writes C_BaseAnimating's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_BaseAnimating *pcd_emit_1008f5a0(const C_BaseAnimating &other) { return new C_BaseAnimating(other); }

// TARGET: ??_GC_BaseAnimating@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1008f5c0 size=0x12a
#include "C_BaseAnimating.h"
#include "UtlMem.h"
struct VecView { UtlMem m; int m_Size; int *m_pElements; };
struct Dtorable { virtual ~Dtorable(); };
struct Elem14 { UtlMem m; int m_Size; int *m_pElements; void sub_10096d70(); };
extern "C" __declspec(dllimport) void __cdecl Plat_Free(void *);
#define PURGETAIL(v) \
	(v)->m_pElements = (v)->m.m_pMemory; \
	if ((v)->m.m_growSize != -1) { \
		if ((v)->m.m_pMemory) { Plat_Free((v)->m.m_pMemory); (v)->m.m_pMemory = 0; } \
		(v)->m.m_allocationCount = 0; \
	}
// TARGET: ??1C_BaseAnimating@@UAE@XZ
C_BaseAnimating::~C_BaseAnimating()
{
	char *self = (char *)this;
	sub_100966e0();
	delete *(void **)(self + 0x6d8);
	Dtorable *p = *(Dtorable **)(self + 0x6b0);
	if (p) delete p;
	VecView *v = (VecView *)(self + 0x770);
	v->m_Size = 0;
	v->m.sub_10096f90();
	PURGETAIL(v)
	v = (VecView *)(self + 0x728);
	v->m_Size = 0;
	v->m.sub_10096f60();
	PURGETAIL(v)
	v = (VecView *)(self + 0x6f4);
	v->m_Size = 0;
	v->m.sub_10096d10();
	v->m_pElements = v->m.m_pMemory;
	v->m.sub_10096d10();
	v = (VecView *)(self + 0x67c);
	v->m_Size = 0;
	v->m.sub_10096e70();
	PURGETAIL(v)
	Elem14 *e = (Elem14 *)(self + 0x4f8);
	int n = 2;
	do {
		e--;
		e->sub_10096d70();
		e->m.sub_10096d40();
		e->m_pElements = e->m.m_pMemory;
		e->m.sub_10096d40();
	} while (--n);
}
// END FUNCTION

// FUNCTION: 0x1008f720 size=0x61
#include "C_BaseAnimating.h"

int C_BaseAnimating::vfunc86()
{
	if (!vfunc71() || !*(void **)((char *)this + 0x6ac) || sub_1009f140(0x60))
		return 0;
	void *p = *(void **)((char *)this + 0x6ac);
	int n = *(int *)((char *)p + 0x108);
	if (n == 0)
		return 2;
	if (n == 1)
	{
		void *q = *(void **)((char *)p + 0x10c);
		if (*(int *)((char *)q + (int)p + 0xc) == 1)
			return 2;
	}
	return 3;
}
// END FUNCTION

// FUNCTION: 0x1008f8a0 size=0x52
#include "engineclient.h"
#include "C_BaseAnimating.h"
#include "StudioHdr.h"


// TARGET: C_BaseAnimating::vfunc71
bool C_BaseAnimating::vfunc71()
{
	*(void **)((char *)this + 0x6ac) = 0;
	void *pModel = *(void **)((char *)this + 0x40);
	if (!pModel)
		return false;
	StudioHdr *hdr = modelrender->GetStudiomodel(pModel);
	if (!hdr)
		return false;
	char *pName = hdr->m_name[0] ? hdr->m_name : 0;
	vfunc49((int)pName);
	*(void **)((char *)this + 0x6ac) = hdr;
	return true;
}
// END FUNCTION

// FUNCTION: 0x1008f960 size=0x78
#include "C_BaseAnimating.h"

extern void *g_104a57d4;

struct EngV
{
	virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3(); virtual void e4();
	virtual void e5(); virtual void e6(); virtual void e7(); virtual void e8(); virtual void e9();
	virtual void e10(); virtual void e11(); virtual void e12(); virtual void e13(); virtual void e14();
	virtual void e15(); virtual void e16(); virtual void e17(); virtual void e18(); virtual void e19();
	virtual void e20(); virtual void e21(); virtual void e22(); virtual void e23(); virtual void e24();
	virtual void e25(); virtual void e26(); virtual void e27(); virtual void e28(); virtual void e29();
	virtual void e30(); virtual void e31(); virtual void e32(); virtual void e33(); virtual void e34();
	virtual void e35(); virtual void e36(); virtual void e37(); virtual void e38();
	virtual float vfunc39(int);
};

float C_BaseAnimating::vfunc122()
{
	float flBlend = *(float *)((char *)this + 0x70) - *(float *)((char *)this + 0x6c);
	float f = 1.0f;
	if (flBlend > 0.0f)
	{
		float x = ((EngV *)g_104a57d4)->vfunc39(0);
		f = 1.0 - (*(float *)((char *)this + 0x70) - x) / flBlend;
		if (f > 2.0f)
			return 2.0f;
		if (f < 0.0f)
			return 0.0f;
	}
	return f;
}
// END FUNCTION

// FUNCTION: 0x1008f9e0 size=0x8d
#include "C_BaseAnimating.h"
struct PoseDesc1008f9e0 { char pad[4]; unsigned char flags; char pad2[0x18 - 5]; };
struct Hdr1008f9e0
{
    char pad[0xf8]; int numPose; int poseIndex;
    PoseDesc1008f9e0 *GetPose(int i) { return (PoseDesc1008f9e0 *)((unsigned char *)this + poseIndex) + i; }
};
struct Anim1008f9e0
{
    char pad[0x65c]; float m_a[4]; float m_b[4]; char pad2[0x6ac - 0x67c]; Hdr1008f9e0 *m_pHdr;
    Hdr1008f9e0 *GetHdr() { return m_pHdr; }
};

void C_BaseAnimating::vfunc120(float *out, float t)
{
    Anim1008f9e0 *s = (Anim1008f9e0 *)this;
    int i;
    for (i = 0; i < s->GetHdr()->numPose; i++)
    {
        out[i] = sub_10091020(s->m_a[i], s->m_b[i], t, (s->GetHdr()->GetPose(i)->flags & 0x38) != 0);
    }
    for (i = s->GetHdr()->numPose; i < 4; i++)
        out[i] = 0;
}
// END FUNCTION

// FUNCTION: 0x1008fa70 size=0xbd
#include "C_BaseAnimating.h"
extern "C" double floor(double);
struct PoseDesc1008fa70 { int a, b; int flags; };
struct AnimView1008fa70 { char pad[0x5d4]; float m5d4; };

float C_BaseAnimating::sub_1008fa70(float a1, int idx, float a3, float a4, float a5)
{
    float r = sub_10095910(idx, &((AnimView1008fa70 *)this)->m5d4);
    if (r == 0.0f)
        return 0.0f;
    PoseDesc1008fa70 *p = sub_10096830(idx);
    if (!p)
        return 0.0f;
    float x = a5 / r * a4 + a1;
    if (p->flags & 1)
        return x - floor(x);
    if (x >= 0.999)
        x = 0.999f;
    if (x < 0.0)
        x = 0.0f;
    return x;
}
// END FUNCTION

// FUNCTION: 0x10090b60 size=0x3
#include "C_BaseAnimating.h"
void C_BaseAnimating::vfunc124(int a0, int a1)
{
}
// END FUNCTION

// FUNCTION: 0x10090f80 size=0x98
#include "C_BaseAnimating.h"
struct SPoseHdr { char pad[0x10]; float m10; };
SPoseHdr *sub_1008d930(void *hdr, int idx);
struct GlobalV { virtual void v0(); virtual bool IsPaused(); char pad[0x28 - 4]; float m28; };
extern GlobalV *g_1049c494;
struct AnimV { char pad[0x3fc]; int m3fc; char pad2[0x6ac - 0x400]; void *m6ac; };
float C_BaseAnimating::vfunc129(int idx, float a, float b, float c)
{
	AnimV *self = (AnimV *)this;
	SPoseHdr *p = sub_1008d930(self->m6ac, idx);
	if (!p)
		return 0.0f;
	if (!g_1049c494->IsPaused()) {
		if (g_1049c494->m28 != 0.0f && self->m3fc && !idx)
			c = 1.0f;
	}
	return sub_10091020(a, b, c, p->m10 != 0.0f);
}
// END FUNCTION

// FUNCTION: 0x100910f0 size=0x1b
#include "C_BaseAnimating.h"
namespace lifted {
struct C10094020 { bool sub_10094020(); };
struct C100a1aa0 { int sub_100a1aa0(); };
}
int C_BaseAnimating::vfunc66()
{
    bool t0 = ((lifted::C10094020 *)this)->sub_10094020();
    if (t0 != 0) {
        return 2;
    }
    return ((lifted::C100a1aa0 *)this)->sub_100a1aa0();
}
// END FUNCTION

// FUNCTION: 0x10091640 size=0x3
#include "C_BaseAnimating.h"
void C_BaseAnimating::vfunc131(int a0, int a1, int a2, int a3, int a4, int a5)
{
}
// END FUNCTION

// FUNCTION: 0x10091960 size=0x3
#include "C_BaseAnimating.h"
bool C_BaseAnimating::vfunc142()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10092810 size=0xbb
#include "C_BaseAnimating.h"
#include "Vector.h"
struct CollView92810 {
    virtual void v0();
    virtual void v1();
    virtual Vector *GetOrigin();
    virtual void GetBounds(Vector &mins, Vector &maxs);
};
struct AnimView92810 {
    char pad[0x6b0];
    CollView92810 *m_pColl;
};
struct IEngBase92810 {
#define V8(n) virtual void a##n##0(); virtual void a##n##1(); virtual void a##n##2(); virtual void a##n##3(); virtual void a##n##4(); virtual void a##n##5(); virtual void a##n##6(); virtual void a##n##7();
    V8(0) V8(1) V8(2) V8(3) V8(4) V8(5) V8(6) V8(7) V8(8)
    virtual bool IsBox(Vector &a, Vector &b);
};
extern IEngBase92810 *g_104a57d4;

// TARGET: C_BaseAnimating::sub_10092810
int C_BaseAnimating::sub_10092810()
{
    if (sub_10094020())
    {
        Vector org = *((AnimView92810 *)this)->m_pColl->GetOrigin();
        Vector mins, maxs;
        ((AnimView92810 *)this)->m_pColl->GetBounds(mins, maxs);
        mins += org;
        maxs += org;
        return !g_104a57d4->IsBox(mins, maxs);
    }
    return 2;
}
// END FUNCTION

// FUNCTION: 0x10093f00 size=0x34
#include "C_BaseAnimating.h"
#include "IClientCollideable.h"
// TARGET: C_BaseAnimating::vfunc67
bool C_BaseAnimating::vfunc67()
{
  if (*((bool *)this + 0x6a8))
    return true;
  int solid = ((IClientCollideable *)((char *)this + 0xc))->GetSolid();
  if (solid == 4 || solid == 0 || solid == 3 || solid == 5 || solid == 6)
    return false;
  return true;
}
// END FUNCTION

// FUNCTION: 0x10093f40 size=0x90
#include "C_BaseAnimating.h"
struct S96 { int d[24]; };
struct S16 { int d[4]; };
struct V3 { int x, y, z; V3 &operator=(const V3 &o) { x = o.x; y = o.y; z = o.z; return *this; } };
void C_BaseAnimating::vfunc132(bool b)
{
	char *p = (char *)this;
	if (b) {
		*(S96 *)(p + 0x574) = *(S96 *)(p + 0x5d4);
		*(int *)(p + 0x644) = *(int *)(p + 0x648);
		*(S16 *)(p + 0x65c) = *(S16 *)(p + 0x66c);
	}
	*(float *)(p + 0x6c) = *(float *)(p + 0x70) = *(float *)(p + 0x144);
	*(V3 *)(p + 0x54) = *(const V3 *)&GetAbsOrigin();
	*(V3 *)(p + 0x60) = *(const V3 *)&GetAbsAngles();
}
// END FUNCTION

// FUNCTION: 0x10093fd0 size=0x4e
#include "C_BaseAnimating.h"

struct Blob60 { int d[0x18]; };
struct Blob16 { int d[4]; };

struct AnimView
{
	char m_pad0[0x574];
	Blob60 m_574;
	Blob60 m_5d4;
	char m_pad634[0x644 - 0x634];
	int m_644;
	int m_648;
	char m_pad64c[0x65c - 0x64c];
	Blob16 m_65c;
	Blob16 m_66c;
};

int C_BaseAnimating::vfunc70()
{
	AnimView *v = (AnimView *)this;
	v->m_574 = v->m_5d4;
	v->m_65c = v->m_66c;
	v->m_644 = v->m_648;
	return C_BaseEntity::vfunc70();
}
// END FUNCTION

// FUNCTION: 0x10094150 size=0x73
#include "C_BaseAnimating.h"
#include "ScopeTrace.h"

int sub_1008cdc0(int, const char *);

int C_BaseAnimating::LookupBone(const char *pszName)
{
    ScopeTrace trace("C_BaseAnimating::LookupBone", "", "");
    return sub_1008cdc0(sub_1008f900(-1), pszName);
}
// END FUNCTION

// FUNCTION: 0x10094e90 size=0x22
#include "C_BaseAnimating.h"
namespace lifted {
struct C1009f140 { bool sub_1009f140(int); };
struct C100a0de0 { int sub_100a0de0(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual int f132(int); };
}
void C_BaseAnimating::vfunc37()
{
    bool t0 = ((lifted::C1009f140 *)this)->sub_1009f140(0x10);
    if (t0 != 0) {
        ((lifted::V *)this)->f132(0);
    }
    ((lifted::C100a0de0 *)this)->sub_100a0de0();
}
// END FUNCTION

// FUNCTION: 0x10095030 size=0x39
#include "engineclient.h"
#include "C_BaseAnimating.h"
// TARGET: C_BaseAnimating::vfunc61
void C_BaseAnimating::vfunc61()
{
  if (*((char *)this + 0x6a8)) {
    vfunc70();
    vfunc137(engine->vfunc41(0));
  }
}
// END FUNCTION

// FUNCTION: 0x10095070 size=0x14
#include "C_BaseAnimating.h"
int C_BaseAnimating::vfunc62()
{
	DoAnimationEvents();
	return C_BaseEntity::vfunc62();
}
// END FUNCTION

// FUNCTION: 0x10095090 size=0x21
#include "C_BaseAnimating.h"
struct CRagView { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int v4(int a); };
bool C_BaseAnimating::sub_10094020()
{
	return *(int *)((char *)this + 0x6b0) && *(int *)((char *)this + 0x4c) == 0x17;
}
// TARGET: C_BaseAnimating::vfunc133
int C_BaseAnimating::vfunc133()
{
	if (sub_10094020()) {
		CRagView *p = *(CRagView **)((char *)this + 0x6b0);
		return p->v4(*(int *)((char *)this + 0x6b4));
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x10095490 size=0x34
#include "C_BaseAnimating.h"
float C_BaseAnimating::vfunc138(int iSequence)
{
	float f = sub_10095910(iSequence, (void *)((char *)this + 0x5d4));
	if (f > 0.0f)
		return 1.0 / f;
	return 10.0f;
}
// END FUNCTION

// FUNCTION: 0x100954d0 size=0x117
#include "CGlobalVarsBase.h"
#include "C_BaseAnimating.h"


struct C_BaseAnimating_Fields
{
	char pad0[0x70];
	float m_flAnimTime;
	char pad74[0x508 - 0x74];
	float m_flGroundSpeed;
	char pad50c[0x510 - 0x50c];
	bool m_bSequenceFinished;
	bool m_bSequenceLoops;
	char pad512[0x63c - 0x512];
	int m_nSequence;
	float m_flPlaybackRate;
	float m_flUnk644;
	float m_flCycle;
	float sub_100955f0(int iSequence);
};

// TARGET: C_BaseAnimating::vfunc136
float C_BaseAnimating::vfunc136(float flInterval)
{
	C_BaseAnimating_Fields *f = (C_BaseAnimating_Fields *)this;
	if (flInterval == 0.0)
	{
		flInterval = 0.1f;
	}

	flInterval = (flInterval + gpGlobals->curtime) - f->m_flAnimTime;
	if (flInterval <= 0.001)
	{
		return 0.0f;
	}

	f->m_flCycle += vfunc138(f->m_nSequence) * f->m_flPlaybackRate * flInterval;
	f->m_flAnimTime += flInterval;

	if (f->m_flCycle < 0.0 || f->m_flCycle >= 1.0)
	{
		if (f->m_bSequenceLoops)
		{
			f->m_flCycle -= (int)(f->m_flCycle);
		}
		else
		{
			f->m_flCycle = (f->m_flCycle < 0.0f) ? 0.0f : 1.0f;
		}
		f->m_bSequenceFinished = true;
	}

	f->m_flGroundSpeed = f->sub_100955f0(f->m_nSequence);
	return flInterval;
}
// END FUNCTION

// FUNCTION: 0x10095870 size=0x6
#include "C_BaseAnimating.h"
namespace lifted {
extern char g_102ad9d8;
}
int C_BaseAnimating::vfunc17()
{
    return (int)&lifted::g_102ad9d8;
}
// END FUNCTION

// FUNCTION: 0x10095a60 size=0x57
#include "C_BaseAnimating.h"

void __cdecl sub_10107eb0(void *entry, int a);
void __cdecl sub_10108510(void *entry, int a, int b);

struct AnimAttView
{
    char m_pad00[0x770];
    char *m_pBase;              // +0x770
    char m_pad774[0x77c - 0x774];
    int m_nCount;               // +0x77c
};

bool C_BaseAnimating::vfunc57(int index, int arg2, int arg3)
{
    AnimAttView *v = (AnimAttView *)this;
    if (index < 1 || index > v->m_nCount)
        return false;
    if (!vfunc140())
        return false;
    char *entry = v->m_pBase + index * 72 - 0x48;
    sub_10107eb0(entry, arg3);
    sub_10108510(entry, 3, arg2);
    return true;
}
// END FUNCTION

// FUNCTION: 0x100965d0 size=0x72
#include "C_BaseAnimating.h"

struct EntryV
{
	int m_0;
	int m_4;
	int m_8;
	int m_c;
};

struct SeqV
{
	char pad0[0x140];
	int m_n140;	// 0x140
	int m_n144;	// 0x144
};

struct AnimView
{
	char pad0[0x560];
	int m_time;	// 0x560
	char pad1[0x6ac - 0x564];
	SeqV *m_pSeq;	// 0x6ac
};

int C_BaseAnimating::sub_100965d0(int arg1, int arg2)
{
	AnimView *v = (AnimView *)this;
	SeqV *seq = v->m_pSeq;
	if ( !seq )
		return 0;
	if ( arg1 > seq->m_n140 )
		return -1;
	int cur = v->m_time;
	EntryV *e = (EntryV *)((char *)seq + seq->m_n144 + arg1 * 16);
	int unit = e->m_8;
	int numFrames = e->m_4;
	int frame = (cur / unit) % numFrames;
	if ( arg2 >= numFrames )
		return frame;
	v->m_time = cur + (arg2 - frame) * unit;
	return arg2;
}
// END FUNCTION

// FUNCTION: 0x10096720 size=0xb9
#include "C_BaseAnimating.h"
extern void (*g_101e30fc)(void *);
struct DelView10096720 { virtual void Destroy(int bDelete); };
struct VecView10096720 { void *m_pMemory; int m_nAllocationCount; int m_nGrowSize; int m_Size; void *m_pElements; };
struct AnimViewA10096720 { char pad[0x6b0]; DelView10096720 *m_p6b0; };
void sub_1008df90(void *vec, int hdr, void *a, int b, void *c);
void C_BaseAnimating::vfunc112()
{
	DelView10096720 *&p = ((AnimViewA10096720 *)this)->m_p6b0;
	if (p)
		p->Destroy(1);
	p = 0;
	sub_100966e0();
	vfunc132(true);
	sub_10096650();
	VecView10096720 *v = (VecView10096720 *)((char *)this + 0x6f4);
	v->m_Size = 0;
	if (v->m_nGrowSize != -1)
	{
		if (v->m_pMemory)
		{
			g_101e30fc(v->m_pMemory);
			v->m_pMemory = 0;
		}
		v->m_nAllocationCount = 0;
	}
	v->m_pElements = v->m_pMemory;
	for (int i = 0; i < 2; i++)
		sub_1008df90((char *)this + 0x4d0 + i * 0x14, sub_1008f900(i), (char *)this + 0x428, sub_1008f900(-1), (char *)this + 0x450);
	sub_10096c30();
}
// END FUNCTION
