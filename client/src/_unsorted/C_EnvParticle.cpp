// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100ae5b0 size=0x6
#include "C_EnvParticle.h"
namespace lifted {
extern char g_102b2c20;
}
int C_EnvParticle::vfunc16()
{
    return (int)&lifted::g_102b2c20;
}
// END FUNCTION

// FUNCTION: 0x100ae5c0 size=0x3
#include "C_EnvParticle.h"
int C_EnvParticle::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100aeac0 size=0x1e
#include "C_EnvParticle.h"

// VC6 writes C_EnvParticle's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_EnvParticle *pcd_emit_100aeac0(const C_EnvParticle &other) { return new C_EnvParticle(other); }

// TARGET: ??_GC_EnvParticle@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100aeae0 size=0x183
#include "C_EnvParticle.h"
#include "UtlMem.h"
#include "ehandle.h"
extern "C" __declspec(dllimport) void __cdecl Plat_Free(void *);
struct V104a581c { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void vfunc14(void *); };
extern V104a581c *g_104a581c;
struct EPThing { virtual void v0(); };
struct EPCurrent { EPThing *sub_100af130(); };
#define F(type, off) (*(type *)((char *)this + (off)))
struct UVec { void *m_p; int m_alloc; int m_grow; int m_size; void *m_pElems; };
static inline void PurgeMem(UVec *v)
{
    if (v->m_grow != -1) {
        if (v->m_p) {
            Plat_Free(v->m_p);
            v->m_p = 0;
        }
        v->m_alloc = 0;
    }
}
// TARGET: C_EnvParticle::~C_EnvParticle
C_EnvParticle::~C_EnvParticle()
{
    C_BaseEntity *pOwner = (C_BaseEntity *)F(CBaseHandle, 0x188).Get();
    if (pOwner)
        pOwner->vfunc118((int)this);
    EPThing *p = ((EPCurrent *)this)->sub_100af130();
    if (p)
        ((C_BaseEntity *)p)->vfunc119((int)this);
    if (F(int, 0x46c)) {
        g_104a581c->vfunc14((void *)F(int, 0x46c));
        F(int, 0x46c) = 0;
    }
    UVec *c = (UVec *)((char *)this + 0x4a0);
    c->m_size = 0;
    ((UtlMem *)c)->sub_100b4e00();
    c->m_pElems = c->m_p;
    PurgeMem(c);
    UVec *b = (UVec *)((char *)this + 0x48c);
    b->m_size = 0;
    PurgeMem(b);
    b->m_pElems = b->m_p;
    PurgeMem(b);
    UVec *a = (UVec *)((char *)this + 0x470);
    a->m_size = 0;
    PurgeMem(a);
    a->m_pElems = a->m_p;
    PurgeMem(a);
}
// END FUNCTION

// FUNCTION: 0x100aec70 size=0x69
#include "C_EnvParticle.h"
#include "Vector.h"

void C_EnvParticle::vfunc122(int p)
{
	Vector *v = (Vector *)p;
	Vector &a = *(Vector *)((char *)this + 0x2b4);
	Vector &b = *(Vector *)((char *)this + 0x23c);
	Vector &c = *(Vector *)((char *)this + 0x254);
	c = b = a = *v;
}
// END FUNCTION

// FUNCTION: 0x100aece0 size=0x69
#include "C_EnvParticle.h"
#include "Vector.h"

void C_EnvParticle::vfunc123(int p)
{
	Vector *v = (Vector *)p;
	Vector &a = *(Vector *)((char *)this + 0x2c0);
	Vector &b = *(Vector *)((char *)this + 0x248);
	Vector &c = *(Vector *)((char *)this + 0x260);
	c = b = a = *v;
}
// END FUNCTION
