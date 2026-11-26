// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100015a0 size=0x3
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc24()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100015b0 size=0x7
#include "C_BaseEntity.h"
ICollideable * C_BaseEntity::GetClientCollideable()
{
    return (ICollideable *)((char *)this + 0x190);
}
// END FUNCTION

// FUNCTION: 0x100015c0 size=0xb
#include "C_BaseEntity.h"
IClientNetworkable * C_BaseEntity::GetClientNetworkable()
{
    if (((int)this) != 0) {
        return (IClientNetworkable *)((char *)this + 8);
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100015d0 size=0xb
#include "C_BaseEntity.h"
IClientRenderable * C_BaseEntity::GetClientRenderable()
{
    if (((int)this) != 0) {
        return (IClientRenderable *)((char *)this + 4);
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100015e0 size=0x3
#include "C_BaseEntity.h"
IClientEntity * C_BaseEntity::GetIClientEntity()
{
    return this;
}
// END FUNCTION

// FUNCTION: 0x100015f0 size=0x3
#include "C_BaseEntity.h"
C_BaseEntity * C_BaseEntity::GetBaseEntity()
{
    return this;
}
// END FUNCTION

// FUNCTION: 0x10001600 size=0xb
#include "C_BaseEntity.h"
IClientThinkable * C_BaseEntity::GetClientThinkable()
{
    if (((int)this) != 0) {
        return (IClientThinkable *)((char *)this + 0x10);
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10001610 size=0x5
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc25(int a0)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10001620 size=0x3
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc26()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10001660 size=0x7
#include "C_BaseEntity.h"
char * C_BaseEntity::vfunc54()
{
    return (char *)this + 0x1f4;
}
// END FUNCTION

// FUNCTION: 0x10001670 size=0x21
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc55(int a0)
{
    int t0 = *(int *)((char *)a0);
    *(int *)((char *)this + 0x1f4) = t0;
    int t1 = *(int *)((char *)a0 + 4);
    *(int *)((char *)this + 0x1f8) = t1;
    int t2 = *(int *)((char *)a0 + 8);
    *(int *)((char *)this + 0x1fc) = t2;
    return t2;
}
// END FUNCTION

// FUNCTION: 0x100016a0 size=0x3
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc58()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100016b0 size=0x6
#include "C_BaseEntity.h"
namespace lifted {
extern char g_102de300;
}
int C_BaseEntity::vfunc59()
{
    return (int)&lifted::g_102de300;
}
// END FUNCTION

// FUNCTION: 0x100016c0 size=0x3
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc63()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100016d0 size=0x3
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc84()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100016e0 size=0x6
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc85()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100016f0 size=0x3
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc94()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10001700 size=0x11
struct B1 { int a; };
struct B2 { int b; };
struct T_10001700 : B1, B2 { void f(); };
struct V_10001700 : T_10001700 {
	int m_unk[(0x20 - 12) / 4];
	void (T_10001700::*m_pfn)();
};
// TARGET: sub_10001700
void __fastcall sub_10001700(V_10001700 *self)
{
	if (self->m_pfn)
		(self->*self->m_pfn)();
}
// END FUNCTION

// FUNCTION: 0x10001720 size=0x3
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc106()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10001890 size=0x1
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc112()
{
}
// END FUNCTION

// FUNCTION: 0x100018a0 size=0x5
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc117(int a0)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100018d0 size=0xf
struct I_100018d0 { virtual void v0(); virtual void v1(); };
struct V_100018d0 { int m_unk[0x190 / 4]; I_100018d0 m_obj; };
// TARGET: sub_100018d0
void __fastcall sub_100018d0(V_100018d0 *self)
{
	self->m_obj.v1();
}
// END FUNCTION

// FUNCTION: 0x1007dbb0 size=0x52
// TARGET: CBaseEntView::sub_1007dbb0
#include "C_BaseEntity.h"
#include "Vector.h"

struct CBaseEntView
{
	Vector sub_1007dbb0();
};

Vector CBaseEntView::sub_1007dbb0()
{
	return ((C_BaseEntity *)(void *)this)->GetAbsOrigin() + *(Vector *)((char *)this + 0x148);
}
// END FUNCTION

// FUNCTION: 0x1007dc10 size=0x5
#include "C_BaseEntity.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual int f10(); };
}
int C_BaseEntity::vfunc108()
{
    return ((lifted::V *)this)->f10();
}
// END FUNCTION

// FUNCTION: 0x1007dc20 size=0x8
#include "C_BaseEntity.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual int f41(); };
}
char * C_BaseEntity::vfunc109()
{
    return (char *)(((lifted::V *)this)->f41());
}
// END FUNCTION

// FUNCTION: 0x1007dc30 size=0x14
#include "C_BaseEntity.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual int f107(int); };
}
int C_BaseEntity::vfunc110(int a0)
{
    ((lifted::V *)this)->f107(a0);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x1007dd90 size=0xe
struct V_1007dd90 { int m_unk[0x88 / 4]; int m_n88; };
// TARGET: sub_1007dd90
int __fastcall sub_1007dd90(V_1007dd90 *self)
{
	return self->m_n88 == 0;
}
// END FUNCTION

// FUNCTION: 0x1007dda0 size=0x1e
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc65(int a, int flags)
{
	bool r = true;
	if (*(int *)((char *)this + 0x2d0) == 1 && !(flags & 0x4000000))
		r = false;
	return r;
}
// END FUNCTION

// FUNCTION: 0x1007de10 size=0x3
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc92(int a0, int a1)
{
}
// END FUNCTION

// FUNCTION: 0x1007de20 size=0x3
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc93(int a0, int a1, int a2)
{
}
// END FUNCTION

// FUNCTION: 0x1007de30 size=0x3c
#include "engineclient.h"
#include "C_BaseEntity.h"
// TARGET: C_BaseEntity::vfunc91
int C_BaseEntity::vfunc91(int a, int b)
{
	int v = *(int *)((char *)this + 0x48);
	if (v == 4)
		return -1;
	if (v && b == 0x47)
		return 0x34;
	return enginerandom->RandomInt(0, 4);
}
// END FUNCTION

// FUNCTION: 0x1007de70 size=0x7
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc30()
{
    return *(int *)((char *)this + 0x184);
}
// END FUNCTION

// FUNCTION: 0x1007de80 size=0xd
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc31(int a0)
{
    *(int *)((char *)this + 0x184) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x1007de90 size=0xab
#include "Vector.h"
#include "QAngle.h"
#include "C_BaseEntity.h"
#include "IPhysicsObject.h"
#include "Tier1.h"

static inline bool IsFiniteF(float f)
{
	return (*(unsigned int *)&f & 0x7f800000) != 0x7f800000;
}

void C_BaseEntity::vfunc89(IPhysicsObject *pPhysics)
{
	if (GetSolid() != 7)
		return;
	Vector origin;
	QAngle angles;
	pPhysics->vfunc37(&origin, (int)&angles);
	if (!IsFiniteF(angles.x) || !IsFiniteF(angles.y) || !IsFiniteF(angles.x))
		g_101e3108("Infinite values from vphysics!\n");
	sub_100a2030(&origin);
	sub_100a2100(angles);
	vfunc111();
}
// END FUNCTION

// FUNCTION: 0x1007df40 size=0x23
#include "C_BaseEntity.h"
namespace lifted {
int sub_10120190(int, int);
}
void C_BaseEntity::vfunc88()
{
    if ((*(int *)((char *)this + 0xec)) != 0) {
        int t0 = lifted::sub_10120190(*(int *)((char *)this + 0xec), (int)this);
        *(int *)((char *)this + 0xec) = 0;
    }
}
// END FUNCTION

// FUNCTION: 0x1007df70 size=0x3
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc87()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1007e030 size=0x7
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc115()
{
    return *(bool *)((char *)this + 0x40d);
}
// END FUNCTION

// FUNCTION: 0x1009d3e0 size=0x6
#include "C_BaseEntity.h"
namespace lifted {
extern char g_102afc00;
}
int C_BaseEntity::vfunc16()
{
    return (int)&lifted::g_102afc00;
}
// END FUNCTION

// FUNCTION: 0x1009d3f0 size=0x3
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1009dda0 size=0x1e
#include "C_BaseEntity.h"

// VC6 writes C_BaseEntity's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_BaseEntity *pcd_emit_1009dda0(const C_BaseEntity &other) { return new C_BaseEntity(other); }

// TARGET: ??_GC_BaseEntity@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1009e040 size=0x1
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc19()
{
}
// END FUNCTION

// FUNCTION: 0x1009e050 size=0x1
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc20()
{
}
// END FUNCTION

// FUNCTION: 0x1009e060 size=0x1
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc21()
{
}
// END FUNCTION

// FUNCTION: 0x1009e070 size=0x3c
#include "CClientEntityList.h"
#include "C_BaseEntity.h"
struct CUnknown100e2340 { int sub_100e2340(int a, int b, int c, int d); };
struct CUnknown10044400 { short sub_10044400(); };
struct EntHandleView { virtual int v0(); };
// TARGET: ?Init@C_BaseEntity@@UAE_NHH@Z
bool C_BaseEntity::Init(int entnum, int iSerialNum)
{
	((CUnknown100e2340 *)cl_entitylist)->sub_100e2340((int)&iSerialNum, ((EntHandleView *)((char *)this + 4))->v0(), entnum, iSerialNum);
	((CUnknown10044400 *)((char *)this + 0x190))->sub_10044400();
	*(int *)((char *)this + 0x44) = entnum;
	return true;
}
// END FUNCTION

// FUNCTION: 0x1009e0b0 size=0x3c
#include "engineclient.h"
#include "C_BaseEntity.h"


// TARGET: C_BaseEntity::vfunc60
void C_BaseEntity::vfunc60(int a, int b)
{
	sub_1009e0f0(a ? modelinfo->GetModelIndex((const char *)a) : -1, b);
}
// END FUNCTION

// FUNCTION: 0x1009f050 size=0xf
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc0(int a0)
{
    *(int *)((char *)this + 0xe4) = *(int *)((char *)a0);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x1009f060 size=0x7
#include "C_BaseEntity.h"
unsigned int * C_BaseEntity::vfunc1()
{
    return (unsigned int *)((char *)this + 0xe4);
}
// END FUNCTION

// FUNCTION: 0x1009f070 size=0x25
#include "C_BaseEntity.h"

struct V_100a2ed0;
bool __fastcall sub_100a2ed0(V_100a2ed0 *);

void C_BaseEntity::Release()
{
	C_BaseEntity *pEntity = (C_BaseEntity *)this;
	if (sub_100a2ed0((V_100a2ed0 *)pEntity))
		pEntity->sub_100a2f50();
	delete pEntity;
}
// END FUNCTION

// FUNCTION: 0x1009f210 size=0x48
#include "C_BaseEntity.h"
struct IClientMode11 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10();
    virtual bool ShouldDrawEntity(C_BaseEntity *);
};
extern IClientMode11 *g_105f99d8;
// TARGET: ?ShouldDraw@C_BaseEntity@@UAE_NXZ
bool C_BaseEntity::ShouldDraw()
{
    if (g_105f99d8 && !g_105f99d8->ShouldDrawEntity(this))
        return false;
    return !IsDormant() && ((int *)this)[0x40 / 4] && !(((char *)this)[0x74] & 0x40) && ((int *)this)[0x44 / 4];
}
// END FUNCTION

// FUNCTION: 0x1009f2c0 size=0x5
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc27(int a0, int a1, int a2)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1009f2d0 size=0x3
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc38(int a0, int a1)
{
}
// END FUNCTION

// FUNCTION: 0x1009f300 size=0x26
#include "C_BaseEntity.h"
struct ModelInfoView { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int GetModelType(int idx); };
extern ModelInfoView *g_104a57f8;
int C_BaseEntity::vfunc86()
{
	if (*(int *)((char *)this + 0x74) & 0x60)
		return 0;
	return g_104a57f8->GetModelType(*(int *)((char *)this + 0x40)) == 3 ? 2 : 0;
}
// END FUNCTION

// FUNCTION: 0x1009f4d0 size=0xe9
#include "engineclient.h"
#include "C_BaseEntity.h"
#include "QAngle.h"
#include "matrix3x4_t.h"


struct IRV
{
	virtual void u0();
	virtual Vector &GetRenderOrigin();
	virtual QAngle &GetRenderAngles();
	virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7();
	virtual void *GetModel();
};

struct CollV
{
	virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9();
	virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14();
	virtual void f15(void *, void *);
};

extern void sub_101094b0(QAngle &, Vector &, matrix3x4_t &);
extern void sub_1010b210(matrix3x4_t &, Vector &, Vector &, Vector &, Vector &);

void C_BaseEntity::GetRenderBoundsWorldspace(Vector &absMins, Vector &absMaxs)
{
	char *r = (char *)this + 4;
	int t = modelinfo->GetModelType(*(void **)(r + 0x3c));
	if (t == 3 || t == 1)
	{
		modelinfo->vfunc4(((IRV *)r)->GetModel(), 0, &absMins, &absMaxs);
		QAngle &angles = ((IRV *)r)->GetRenderAngles();
		Vector &origin = ((IRV *)r)->GetRenderOrigin();
		if ((*(int *)&angles.x | *(int *)&angles.y | *(int *)&angles.z) != 0)
		{
			matrix3x4_t matrix;
			sub_101094b0(angles, origin, matrix);
			sub_1010b210(matrix, absMins, absMaxs, absMins, absMaxs);
		}
		else
		{
			VectorAdd(origin, absMins, absMins);
			VectorAdd(origin, absMaxs, absMaxs);
		}
		return;
	}
	((CollV *)(r + 0x18c))->f15(&absMins, &absMaxs);
}
// END FUNCTION

// FUNCTION: 0x1009f640 size=0x5
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc116(int a0, int a1)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1009f650 size=0x3
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc118(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1009f660 size=0x3
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc119(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1009fb50 size=0x45
#include "Vector.h"
#include "C_BaseEntity.h"
void C_BaseEntity::Collideable_vfunc1(int a0, int a1)
{
	*(Vector *)a0 = vfunc52();
	*(Vector *)a1 = vfunc53();
}
// END FUNCTION

// FUNCTION: 0x1009fba0 size=0x7
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc51()
{
    return *(int *)((char *)this + 0x80);
}
// END FUNCTION

// FUNCTION: 0x1009fca0 size=0x28
#include "engineclient.h"
#include "C_BaseEntity.h"
bool C_BaseEntity::IsTransparent()
{
	return modelinfo->vfunc9(*(int *)((char *)this + 0x40)) || *(int *)((char *)this + 0x48);
}
// END FUNCTION

// FUNCTION: 0x1009fce0 size=0x7
#include "C_BaseEntity.h"
CMouthInfo * C_BaseEntity::GetMouth()
{
    return (CMouthInfo *)((char *)this + 0xfc);
}
// END FUNCTION

// FUNCTION: 0x1009fcf0 size=0x3d
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc57(int a1, int a2, int a3)
{
	float *pos = (float *)a2;
	float *ang = (float *)a3;
	const float *o = (const float *)&GetAbsOrigin();
	pos[0] = o[0]; pos[1] = o[1]; pos[2] = o[2];
	const float *a = (const float *)&GetAbsAngles();
	ang[0] = a[0]; ang[1] = a[1]; ang[2] = a[2];
	return true;
}
// END FUNCTION

// FUNCTION: 0x1009fd30 size=0xf7
#include "engineclient.h"
#include <math.h>
#include "C_BaseEntity.h"
#include "Vector.h"
#include "QAngle.h"



struct CBaseEntityModelView
{
	char pad[0x40];
	const model_t *m_model;
};

bool C_BaseEntity::vfunc79()
{
	if (modelinfo->GetModelType(((CBaseEntityModelView *)this)->m_model) != 1)
		return false;

	if (IsTransparent())
		return false;

	if (GetAbsOrigin().x != 0.0f || GetAbsOrigin().y != 0.0f || GetAbsOrigin().z != 0.0f)
		return false;

	if (fmod(GetAbsAngles().x, 360.0) != 0.0 ||
		fmod(GetAbsAngles().y, 360.0) != 0.0 ||
		fmod(GetAbsAngles().z, 360.0) != 0.0)
		return false;

	if (modelinfo->IsTranslucent(((CBaseEntityModelView *)this)->m_model))
		return false;

	return true;
}
// END FUNCTION

// FUNCTION: 0x1009fe30 size=0x7a
#include "engineclient.h"
#include "C_BaseEntity.h"

class CClientStatsTime_1009fe30
{
public:
	virtual double GetTime() = 0;
};

struct CClientStats_1009fe30
{
	char pad0[0x148];
	double m_flTotalTime;
	char pad1[0x220 - 0x150];
	double m_flStartTime;
	char pad2[0x308 - 0x228];
	CClientStatsTime_1009fe30 *m_pTime;

	void BeginTimedStat()
	{
		if (m_pTime)
		{
			m_flStartTime = m_pTime->GetTime();
		}
	}

	void EndTimedStat()
	{
		if (m_pTime)
		{
			m_flTotalTime += m_pTime->GetTime() - m_flStartTime;
		}
	}
};


int sub_100ad7a0();

int C_BaseEntity::vfunc80(int flags)
{
	((CClientStats_1009fe30 *)sub_100ad7a0())->BeginTimedStat();
	render->vfunc0(this, *(const model_t **)((char *)this + 0x40), GetAbsOrigin(), GetAbsAngles(), flags);
	((CClientStats_1009fe30 *)sub_100ad7a0())->EndTimedStat();
	return 1;
}
// END FUNCTION

// FUNCTION: 0x1009feb0 size=0xb8
#include "C_BaseEntity.h"
#include "Tier1.h"

#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();
struct EntBrushView {
    V4(a) V4(b) V4(c) V4(d) V4(e) V4(f) V4(g) V4(h) V4(i) V4(j)
    V4(k) V4(l) V4(m) V4(n) V4(o) V4(p) V4(q) V4(r) V4(s) V4(t)
    virtual int DrawBrushModel(bool bTransparent);
};
struct ModelInfoView {
    virtual void v0();
    virtual const char *GetModelName(int model);
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual int GetModelType(int model);
};
extern ModelInfoView *g_104a57f8;
extern void (*g_101e3114)(const char *, ...);
struct ClientClassView { void *a; void *b; const char *m_pNetworkName; };

// TARGET: C_BaseEntity::DrawModel
int C_BaseEntity::DrawModel(int flags, int a1)
{
    if (!*((char *)this + 0xe0))
        return 0;

    int drawn = 0;
    if (!*(int *)((char *)this + 0x40))
        return drawn;

    int modelType = g_104a57f8->GetModelType(*(int *)((char *)this + 0x40));
    switch (modelType) {
    case 1:
        drawn = ((EntBrushView *)this)->DrawBrushModel(flags & 0x80000000 ? true : false);
        break;
    case 3:
        g_101e3114("ERROR:  Can't draw studio model %s because %s is not derived from C_BaseAnimating\n",
            g_104a57f8->GetModelName(*(int *)((char *)this + 0x40)),
            ((ClientClassView *)GetClientClass())->m_pNetworkName ? ((ClientClassView *)GetClientClass())->m_pNetworkName : "unknown");
        break;
    case 2:
        g_101e3114("ERROR:  Sprite model's not supported any more except in legacy temp ents\n");
        break;
    default:
        break;
    }
    return drawn;
}
// END FUNCTION

// FUNCTION: 0x100a06e0 size=0x3
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc67()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100a08a0 size=0x3d
#include "C_BaseEntity.h"
#include "Vector.h"
struct EntView {
	char pad[0x54];
	Vector v0, v1;
	int a6;
	int c70;
	char pad3[0x29c - 0x74];
	Vector w0, w1;
};
// TARGET: C_BaseEntity::vfunc70
int C_BaseEntity::vfunc70()
{
	EntView *p = (EntView *)this;
	p->v0 = p->w0;
	p->v1 = p->w1;
	return p->a6 = p->c70;
}
// END FUNCTION

// FUNCTION: 0x100a08e0 size=0x3
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc71()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100a0bb0 size=0xb
#include "C_BaseEntity.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual int f112(); };
}
int C_BaseEntity::vfunc72()
{
    ((lifted::V *)this)->f112();
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100a0bc0 size=0x3
#include "C_BaseEntity.h"
bool C_BaseEntity::vfunc74()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100a0bd0 size=0x37
#include "C_BaseEntity.h"
namespace lifted {
extern int g_104a57f8;
struct V { virtual void u0(); virtual int f1(int); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(int); };
}
bool C_BaseEntity::vfunc75()
{
    if ((*(int *)((char *)this + 0x40)) != 0) {
        int t0 = ((lifted::V *)lifted::g_104a57f8)->f6(*(int *)((char *)this + 0x40));
        if (t0 == 1) {
            int t1 = ((lifted::V *)lifted::g_104a57f8)->f1(*(int *)((char *)this + 0x40));
            if ((*(char *)((char *)t1)) == 0x2a) {
                return 1;
            }
        }
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100a0de0 size=0x10
#include "C_BaseEntity.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual int f76(); };
}
void C_BaseEntity::vfunc37()
{
    if ((*(int *)((char *)this + 0x44)) != 0) {
        ((lifted::V *)this)->f76(); return;
    }
}
// END FUNCTION

// FUNCTION: 0x100a0df0 size=0x3f
#include "C_BaseEntity.h"
void __stdcall sub_100a0df0(C_BaseEntity *ent, float *pos, float *ang)
{
	const float *o = (const float *)&ent->GetAbsOrigin();
	pos[0] = o[0]; pos[1] = o[1]; pos[2] = o[2];
	const float *a = (const float *)&ent->GetAbsAngles();
	ang[0] = a[0]; ang[1] = a[1]; ang[2] = a[2];
}
// END FUNCTION

// FUNCTION: 0x100a0e30 size=0x272
#include "CBaseEntityList.h"
#include "Vector.h"
#include "C_BaseEntity.h"
#include "ehandle.h"
#include "CUnknown100290c0.h"
#include "QAngle.h"
#include <math.h>

struct C_BaseEntity_LocalView
{
	char m_pad[0x2b4];
	Vector m_vecOrigin2b4;
	QAngle m_angRotation2c0;
};

void C_BaseEntity::vfunc77()
{
	CBaseHandle &hParent = *(CBaseHandle *)((char *)this + 0x188);
	if (!((CUnknown100290c0 *)g_pEntityList)->sub_1007aca0((unsigned int *)&hParent))
		return;
	if (GetSolid() == 11) {
		int pParent = ((CUnknown100290c0 *)g_pEntityList)->sub_1007aca0((unsigned int *)&hParent);
		if (!pParent)
			return;
		Vector unused;
		QAngle angles;
		Vector origin;
		vfunc64(pParent, (int)&origin, (int)&angles);
		sub_100a2030(&origin);
		sub_100a2100(angles);
		((C_BaseEntity_LocalView *)this)->m_vecOrigin2b4 = origin;
		((C_BaseEntity_LocalView *)this)->m_angRotation2c0 = angles;
	} else if (GetSolid() == 12) {
		C_BaseEntity *pEnt = (C_BaseEntity *)hParent.Get();
		if (!pEnt)
			return;
		Vector vOffset = pEnt->vfunc53();
		QAngle angles;
		float flYaw = pEnt->GetAbsAngles()[1] * 0.017453292f;
		vOffset.x = sin(flYaw) * (vOffset.y * 0.6f);
		vOffset.y = cos(flYaw) * (vOffset.y * -0.6f);
		vOffset.z = vOffset.z * 0.9f;
		{
			Vector a = vOffset + pEnt->GetRenderOrigin();
			sub_100a2030(&a);
		}
		{
			Vector b = vOffset + pEnt->GetAbsOrigin();
			vfunc44((int)&b);
		}
		angles = pEnt->GetAbsAngles();
		angles.x += 90.0f;
		vfunc46((int)&angles);
		angles = pEnt->GetRenderAngles();
		angles.x += 90.0f;
		sub_100a2100(angles);
	}
}
// END FUNCTION

// FUNCTION: 0x100a11e0 size=0x7
#include "C_BaseEntity.h"
namespace lifted {
extern float g_101e34f0;
}
float C_BaseEntity::vfunc81()
{
    return lifted::g_101e34f0;
}
// END FUNCTION

// FUNCTION: 0x100a11f0 size=0x1
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc82()
{
}
// END FUNCTION

// FUNCTION: 0x100a1210 size=0x1
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc61()
{
}
// END FUNCTION

// FUNCTION: 0x100a1220 size=0x8
#include "C_BaseEntity.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual int f37(); };
}
int C_BaseEntity::vfunc62()
{
    return ((lifted::V *)this)->f37();
}
// END FUNCTION

// FUNCTION: 0x100a1aa0 size=0x73
#include "C_BaseEntity.h"

struct ModelInfoView
{
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual int GetModelType(int modelindex);
};
extern ModelInfoView *g_104a57f8;

int C_BaseEntity::vfunc66()
{
    if (*(int *)((char *)this + 0x80) &&
        *(int *)((char *)this + 0x40) &&
        *(int *)((char *)this + 0x1d0) &&
        !(*(int *)((char *)this + 0x1d4) & 4))
    {
        if (g_104a57f8->GetModelType(*(int *)((char *)this + 0x40)) == 1 ||
            g_104a57f8->GetModelType(*(int *)((char *)this + 0x40)) == 3)
        {
            if (*(int *)((char *)this + 0x80) == 1 ||
                *(float *)((char *)this + 0x1d8) != 0.0f)
                return 1;
        }
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100a2000 size=0x16
#include "C_BaseEntity.h"
namespace lifted {
int sub_1009e240();
}
void C_BaseEntity::vfunc29(char a0)
{
    *(char *)((char *)this + 0x12d) = a0;
    if (a0 != 0) {
        lifted::sub_1009e240();
    }
}
// END FUNCTION

// FUNCTION: 0x100a2350 size=0x7
#include "C_BaseEntity.h"
char * C_BaseEntity::vfunc43()
{
    return (char *)this + 0x254;
}
// END FUNCTION

// FUNCTION: 0x100a2360 size=0x21
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc44(int a0)
{
    int t0 = *(int *)((char *)a0);
    *(int *)((char *)this + 0x254) = t0;
    int t1 = *(int *)((char *)a0 + 4);
    *(int *)((char *)this + 0x258) = t1;
    int t2 = *(int *)((char *)a0 + 8);
    *(int *)((char *)this + 0x25c) = t2;
    return t2;
}
// END FUNCTION

// FUNCTION: 0x100a2390 size=0x7
#include "C_BaseEntity.h"
char * C_BaseEntity::vfunc45()
{
    return (char *)this + 0x260;
}
// END FUNCTION

// FUNCTION: 0x100a23a0 size=0x21
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc46(int a0)
{
    int t0 = *(int *)((char *)a0);
    *(int *)((char *)this + 0x260) = t0;
    int t1 = *(int *)((char *)a0 + 4);
    *(int *)((char *)this + 0x264) = t1;
    int t2 = *(int *)((char *)a0 + 8);
    *(int *)((char *)this + 0x268) = t2;
    return t2;
}
// END FUNCTION

// FUNCTION: 0x100a23d0 size=0xd
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc47(int a0)
{
    *(int *)((char *)this + 0x264) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x100a23e0 size=0xd
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc48(int a0)
{
    *(int *)((char *)this + 0x24c) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x100a2470 size=0x7
#include "C_BaseEntity.h"
char * C_BaseEntity::vfunc39()
{
    return (char *)this + 0x254;
}
// END FUNCTION

// FUNCTION: 0x100a2480 size=0x6b
#include "C_BaseEntity.h"
#include "vector.h"
struct EntView2480 { char pad[0x254]; Vector m_vecOrigin; };
void C_BaseEntity::sub_100a2480(const Vector &origin)
{
	EntView2480 *v = (EntView2480 *)this;
	if (v->m_vecOrigin != origin)
	{
		sub_1007e180(0x800, 0);
		sub_1007e100();
		v->m_vecOrigin = origin;
	}
}
// END FUNCTION

// FUNCTION: 0x100a24f0 size=0x7
#include "C_BaseEntity.h"
char * C_BaseEntity::vfunc41()
{
    return (char *)this + 0x260;
}
// END FUNCTION

// FUNCTION: 0x100a2500 size=0x75
#include "C_BaseEntity.h"
// TARGET: ?vfunc42@C_BaseEntity@@UAEXPAD@Z
void C_BaseEntity::vfunc42(char *p)
{
	float *v = (float *)p;
	float *cur = (float *)((char *)this + 0x260);
	if (v[0] != cur[0] || v[1] != cur[1] || v[2] != cur[2])
	{
		sub_1007e180(0x800, 0x3000);
		sub_1007e040();
		sub_1007e100();
		cur[0] = v[0];
		cur[1] = v[1];
		cur[2] = v[2];
	}
}
// END FUNCTION

// FUNCTION: 0x100a2840 size=0x6
#include "C_BaseEntity.h"
namespace lifted {
extern char g_102afb7c;
}
int C_BaseEntity::vfunc17()
{
    return (int)&lifted::g_102afb7c;
}
// END FUNCTION

// FUNCTION: 0x100a28b0 size=0x4c
#include "C_BaseEntity.h"
#include "CClassMap.h"
CClassMap *sub_100cde00();
struct IClassMapView1 { virtual void v0(); virtual const char *Lookup(int id); };
extern "C" __declspec(dllimport) int Q_snprintf(char *pDest, int nSize, const char *pFmt, ...);
struct SClientClass { int m_unk0; int m_unk4; int m_ClassID; };
char *C_BaseEntity::vfunc114()
{
	static char outstring[256];
	outstring[0] = 0;
	SClientClass *pClass = (SClientClass *)vfunc17();
	if (pClass) {
		const char *p = ((IClassMapView1 *)sub_100cde00())->Lookup(pClass->m_ClassID);
		if (p && p[0])
			Q_snprintf(outstring, sizeof(outstring), "%s", p);
	}
	return outstring;
}
// END FUNCTION

// FUNCTION: 0x100a2d40 size=0x2a
#include "C_BaseEntity.h"
namespace lifted {
struct V { virtual void u0(); virtual int f1(); };
}
void C_BaseEntity::vfunc103(int a0)
{
    if (a0 != 0) {
        *(int *)((char *)this + 0x98) = *(int *)((char *)(((lifted::V *)a0)->f1()));
        return;
    }
    *(int *)((char *)this + 0x98) = -1;
}
// END FUNCTION

// FUNCTION: 0x100a2d70 size=0x2d
#include "CBaseEntityList.h"
#include "C_BaseEntity.h"
#include "CBaseEntityList.h"
void *C_BaseEntity::sub_100a2d70()
{
	unsigned int h = *(unsigned int *)((char *)this + 0x98);
	if (h != 0xffffffff) {
		CBaseEntityListEntry *e = &g_pEntityList->m_EntPtrArray[h & 0x1fff];
		if (e->m_SerialNumber == (int)(h >> 13))
			return e->m_pEntity;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x100a2e10 size=0xd
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc49(int a0)
{
    *(int *)((char *)this + 0x18c) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x100a2e20 size=0xf
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc50(int a0)
{
    *(int *)((char *)a0) = *(int *)((char *)this + 0x18c);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x100a2e30 size=0x1
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc90()
{
}
// END FUNCTION

// FUNCTION: 0x100a2e70 size=0x7
#include "C_BaseEntity.h"
namespace lifted {
extern float g_101e34ec;
}
float C_BaseEntity::vfunc28()
{
    return lifted::g_101e34ec;
}
// END FUNCTION

// FUNCTION: 0x100a32d0 size=0x6
#include "C_BaseEntity.h"
namespace lifted {
extern char g_102afbe8;
}
int C_BaseEntity::vfunc14()
{
    return (int)&lifted::g_102afbe8;
}
// END FUNCTION

// FUNCTION: 0x100a3320 size=0x10
#include "C_BaseEntity.h"
namespace lifted {
struct C1009f8a0 { int sub_1009f8a0(); };
struct C1009fa70 { int sub_1009fa70(); };
}
int C_BaseEntity::vfunc32()
{
    ((lifted::C1009f8a0 *)this)->sub_1009f8a0();
    return ((lifted::C1009fa70 *)this)->sub_1009fa70();
}
// END FUNCTION

// FUNCTION: 0x100a3330 size=0x1
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc33()
{
}
// END FUNCTION

// FUNCTION: 0x100a3340 size=0x19
#include "C_BaseEntity.h"
namespace lifted {
struct C100a3360 { int sub_100a3360(int, int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual int f14(); };
}
int C_BaseEntity::vfunc35(int a0)
{
    return ((lifted::C100a3360 *)this)->sub_100a3360(a0, ((lifted::V *)this)->f14());
}
// END FUNCTION

// FUNCTION: 0x100a3380 size=0x19
#include "C_BaseEntity.h"
namespace lifted {
struct C100a33a0 { int sub_100a33a0(int, int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual int f14(); };
}
int C_BaseEntity::vfunc36(int a0)
{
    return ((lifted::C100a33a0 *)this)->sub_100a33a0(a0, ((lifted::V *)this)->f14());
}
// END FUNCTION

// FUNCTION: 0x100a33c0 size=0x3
#include "C_BaseEntity.h"
int C_BaseEntity::vfunc34()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1011a430 size=0x1b4
#include "C_BaseEntity.h"

__declspec(dllimport) void vtune( bool resume );

class CCycleCount
{
public:
	__int64 m_Int64;
	void Sample()
	{
		unsigned long *pSample = (unsigned long *)&m_Int64;
		__asm
		{
			mov ecx, pSample
			rdtsc
			mov [ecx], eax
			mov [ecx+4], edx
		}
	}
	void operator+=( const CCycleCount &other )
	{
		m_Int64 += other.m_Int64;
	}
};

class CFastTimer
{
public:
	CCycleCount m_Duration;
	void Start()
	{
		m_Duration.Sample();
	}
	void End()
	{
		CCycleCount cnt;
		cnt.m_Int64 = 0;
		cnt.Sample();
		m_Duration.m_Int64 = cnt.m_Int64 - m_Duration.m_Int64;
	}
	const CCycleCount &GetDuration() const
	{
		return m_Duration;
	}
};

class CVProfNode;

class CVProfile
{
public:
	bool m_bVTuneGroupEnabled;	// 0x0
	int m_nVTuneGroupID;	// 0x4
	int m_BudgetGroupStack[1024];	// 0x8
	int m_nBudgetGroupStackPtr;	// 0x1008
	int m_enabled;	// 0x100c
	bool m_fAtRoot;	// 0x1010
	CVProfNode *m_pCurNode;	// 0x1014
	CVProfNode *m_pRoot;	// 0x1018

	inline void EnterScope( const char *pszName, int detailLevel, const char *pBudgetGroupName );
	inline void ExitScope();
	inline void PushBudgetGroup( int id )
	{
		m_BudgetGroupStack[m_nBudgetGroupStackPtr] = id;
		m_nBudgetGroupStackPtr++;
		if ( m_BudgetGroupStack[m_nBudgetGroupStackPtr - 2] != id && m_bVTuneGroupEnabled && id == m_nVTuneGroupID )
			vtune( true );
	}
	inline void PopBudgetGroup()
	{
		m_nBudgetGroupStackPtr--;
		int id = m_BudgetGroupStack[m_nBudgetGroupStackPtr + 1];
		if ( m_BudgetGroupStack[m_nBudgetGroupStackPtr] != id && m_bVTuneGroupEnabled && id == m_nVTuneGroupID )
			vtune( false );
	}
};

extern "C" __declspec(dllimport) CVProfile g_VProfCurrentProfile;

class CVProfNode
{
public:
	const char *m_pszName;	// 0x00
	int m_unk04;
	CFastTimer m_Timer;	// 0x08
	int m_nRecursions;	// 0x10
	int m_nCalls;	// 0x14
	CCycleCount m_CurFrameTime;	// 0x18
	char m_pad[0x48 - 0x20];
	CVProfNode *m_pParent;	// 0x48
	char m_pad2[0x54 - 0x4c];
	int m_BudgetGroupID;	// 0x54

	__declspec(dllimport) CVProfNode *GetSubNode( const char *pszName, int detailLevel, const char *pBudgetGroupName );

	inline void EnterScope()
	{
		m_nCalls++;
		if ( m_nRecursions++ == 0 )
		{
			m_Timer.Start();
			g_VProfCurrentProfile.PushBudgetGroup( m_BudgetGroupID );
		}
	}
	inline bool ExitScope()
	{
		if ( --m_nRecursions == 0 && m_nCalls != 0 )
		{
			m_Timer.End();
			m_CurFrameTime += m_Timer.GetDuration();
			g_VProfCurrentProfile.PopBudgetGroup();
		}
		return m_nRecursions == 0;
	}
};

inline void CVProfile::EnterScope( const char *pszName, int detailLevel, const char *pBudgetGroupName )
{
	if ( m_enabled || !m_fAtRoot )
	{
		if ( m_pCurNode->m_pszName != pszName )
			m_pCurNode = m_pCurNode->GetSubNode( pszName, detailLevel, pBudgetGroupName );
		m_pCurNode->EnterScope();
		m_fAtRoot = false;
	}
}

inline void CVProfile::ExitScope()
{
	if ( !m_fAtRoot || m_enabled )
	{
		if ( m_pCurNode->ExitScope() )
			m_pCurNode = m_pCurNode->m_pParent;
		m_fAtRoot = ( m_pCurNode == m_pRoot );
	}
}

void C_BaseEntity::vfunc111()
{
	g_VProfCurrentProfile.EnterScope( "C_BaseEntity::Relink", 0, "Unaccounted" );
	sub_1009e2d0( 0 );
	g_VProfCurrentProfile.ExitScope();
}
// END FUNCTION

// FUNCTION: 0x1011a940 size=0x3
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc96(int a0, int a1, int a2, int a3)
{
}
// END FUNCTION

// FUNCTION: 0x1011ac20 size=0x3
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc99(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1011ac30 size=0x13
struct B1 { int a; };
struct B2 { int b; };
struct T_1011ac30 : B1, B2 { void f(int); };
struct V_1011ac30 : T_1011ac30 {
	int m_unk[(0x30 - 12) / 4];
	void (T_1011ac30::*m_pfn)(int);
};
void __fastcall sub_1011ac30(V_1011ac30 *self, int edx, int a)
{
	if (self->m_pfn)
		(self->*self->m_pfn)(a);
}
// END FUNCTION

// FUNCTION: 0x1011ac50 size=0x3
#include "C_BaseEntity.h"
void C_BaseEntity::vfunc101(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1011ac60 size=0x17
struct S_1011ac60 { char pad[0xd4]; int cnt; bool f; };
void __fastcall sub_1011ac60(S_1011ac60 *self, int edx, bool b)
{
	self->f = b;
	if (b)
		self->cnt++;
}
// END FUNCTION

// FUNCTION: 0x1011b920 size=0x79
#include "C_BaseEntity.h"
#include "ScopeTrace.h"
// TARGET: C_BaseEntity::vfunc98
bool C_BaseEntity::vfunc98()
{
	ScopeTrace t("CBaseEntity::IsCurrentlyTouching", this ? "clientside entity" : "NULL CLIENT ENTITY");
	if (sub_1011b290(1))
		return true;
	return false;
}
// END FUNCTION

// FUNCTION: 0x1011c520 size=0x9d
#include "C_BaseEntity.h"
#include "ScopeTrace.h"
// TARGET: C_BaseEntity::vfunc102
int C_BaseEntity::vfunc102()
{
	ScopeTrace trace("CBaseEntity::PhysicsSolidMaskForEntity", this ? "clientside entity" : "NULL CLIENT ENTITY");
	if (sub_100a2450() & 0x2000)
		return 0x202400b;
	if (*(int *)((char *)this + 0x3f8))
		return 0x201400b;
	return 0x200400b;
}
// END FUNCTION
