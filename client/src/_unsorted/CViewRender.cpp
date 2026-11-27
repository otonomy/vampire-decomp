// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1018e860 size=0xe
struct CView { char pad[0x390]; int m390[1]; int sub_1018e860(int); };
// TARGET: ?sub_1018e860@CView@@QAEHH@Z
int CView::sub_1018e860(int i) { return m390[i]; }
// END FUNCTION

// FUNCTION: 0x1018e870 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc20()
{
    return *(int *)((char *)this + 0x3b0);
}
// END FUNCTION

// FUNCTION: 0x1018e880 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc21()
{
    return *(int *)((char *)this + 0x3b4);
}
// END FUNCTION

// FUNCTION: 0x1018e890 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc22()
{
    return *(int *)((char *)this + 0x3b8);
}
// END FUNCTION

// FUNCTION: 0x1018e8a0 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc23()
{
    return *(int *)((char *)this + 0x3bc);
}
// END FUNCTION

// FUNCTION: 0x1018e8b0 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc24()
{
    return *(int *)((char *)this + 0x3c0);
}
// END FUNCTION

// FUNCTION: 0x1018e8c0 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc25()
{
    return *(int *)((char *)this + 0x3c4);
}
// END FUNCTION

// FUNCTION: 0x1018e8d0 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc26()
{
    return *(int *)((char *)this + 0x3c8);
}
// END FUNCTION

// FUNCTION: 0x1018e8e0 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc27()
{
    return *(int *)((char *)this + 0x3cc);
}
// END FUNCTION

// FUNCTION: 0x1018e8f0 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc28()
{
    return *(int *)((char *)this + 0x3d0);
}
// END FUNCTION

// FUNCTION: 0x1018e900 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc29()
{
    return *(int *)((char *)this + 0x3d4);
}
// END FUNCTION

// FUNCTION: 0x1018e910 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc30()
{
    return *(int *)((char *)this + 0x3d8);
}
// END FUNCTION

// FUNCTION: 0x1018e920 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc31()
{
    return *(int *)((char *)this + 0x3d8);
}
// END FUNCTION

// FUNCTION: 0x1018e930 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc32()
{
    return *(int *)((char *)this + 0x3e0);
}
// END FUNCTION

// FUNCTION: 0x1018e940 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc33()
{
    return *(int *)((char *)this + 0x3e4);
}
// END FUNCTION

// FUNCTION: 0x1018e950 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc34()
{
    return *(int *)((char *)this + 0x3e8);
}
// END FUNCTION

// FUNCTION: 0x1018e960 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc35()
{
    return *(int *)((char *)this + 0x3ec);
}
// END FUNCTION

// FUNCTION: 0x1018e970 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc36()
{
    return *(int *)((char *)this + 0x438);
}
// END FUNCTION

// FUNCTION: 0x1018e980 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc37()
{
    return *(int *)((char *)this + 0x43c);
}
// END FUNCTION

// FUNCTION: 0x1018e990 size=0x7
#include "CViewRender.h"
int CViewRender::vfunc38()
{
    return *(int *)((char *)this + 0x444);
}
// END FUNCTION

// FUNCTION: 0x1018e9a0 size=0x7
#include "CViewRender.h"
bool CViewRender::vfunc43()
{
    return *(bool *)((char *)this + 0x49c);
}
// END FUNCTION

// FUNCTION: 0x1018e9b0 size=0x204
#include "CViewRender.h"
extern int vt_1024f984[];
struct MR { int d; void sub_100cd1e0(); };
struct UV { int *m_pMemory; int m_nAlloc; int m_nGrow; int m_pad; int m_pElements; void sub_10192cb0(); void sub_100aad50(); };
extern void (*g_101e30fc)(void *);
#define M(off) ((MR *)((char *)this + (off)))
#define D(off) M(off)->sub_100cd1e0();
CViewRender *CViewRender::sub_1018e9b0(unsigned flags)
{
	*(int **)this = vt_1024f984;
	UV *v = (UV *)((char *)this + 0x464);
	v->sub_10192cb0();
	v->sub_100aad50();
	v->m_pElements = (int)v->m_pMemory;
	if (v->m_nGrow != -1) {
		if (v->m_pMemory) {
			g_101e30fc(v->m_pMemory);
			v->m_pMemory = 0;
		}
		v->m_nAlloc = 0;
	}
	D(0x444) D(0x440) D(0x43c) D(0x438) D(0x434) D(0x430) D(0x42c) D(0x428) D(0x424)
	D(0x410) D(0x40c) D(0x408) D(0x404) D(0x400) D(0x3fc) D(0x3f8) D(0x3f4) D(0x3f0)
	D(0x3ec) D(0x3e8) D(0x3e4) D(0x3e0) D(0x3dc) D(0x3d8) D(0x3d4) D(0x3d0) D(0x3cc)
	D(0x3c8) D(0x3c4) D(0x3c0) D(0x3bc) D(0x3b8) D(0x3b4)
	{
		MR *arr = M(0x390);
		M(0x3b0)->sub_100cd1e0();
		int i = 8;
		do {
			i--;
			arr[i].sub_100cd1e0();
		} while (i);
	}
	D(0x38c) D(0x388)
	if (flags & 1)
		::operator delete(this);
	return this;
}
// END FUNCTION

// FUNCTION: 0x1018f630 size=0x37e
#include "engineclient.h"
#include "CViewRender.h"
#include "ScopeTrace.h"
extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
struct BeamsV { virtual void v0(); };
struct TempV { virtual void v0(); };
struct MH { int m_p; void sub_100cd1f0(const char *); };
extern BeamsV *g_102d5050;
extern TempV *g_1028073c;
extern char *g_102d4290[8];

struct CVRView
{
	void *vptr;
	char m_pad04[0x288];
	int m_n28c; int m_n290; int m_n294; int m_n298; int m_n29c; int m_a2a0[6];
	char m_pad2b8[0xc4];
	void *m_pViewSize; void *m_pDrawEntities; void *m_pDrawBrushModels;
	MH m_mat388; MH m_mat38c; MH m_mats390[8]; int m_n3b0;
	MH m_m3b4; MH m_m3b8; MH m_m3bc; MH m_m3c0; MH m_m3c4; MH m_m3c8; MH m_m3cc; MH m_m3d0; MH m_m3d4; MH m_m3d8; MH m_m3dc; MH m_m3e0; MH m_m3e4; MH m_m3e8; MH m_m3ec; MH m_m3f0; MH m_m3f4; MH m_m3f8; MH m_m3fc; MH m_m400; MH m_m404; MH m_m408; MH m_m40c; MH m_m410;
	float m_f414; int m_n418; int m_n41c; int m_n420;
	MH m_m424; MH m_m428; MH m_m42c; MH m_m430; MH m_m434; MH m_m438; MH m_m43c; MH m_m440; MH m_m444;
	char m_b448; char m_b449; char m_b44a; float m_f44c; int m_n450; int m_n454; int m_a458[17]; char m_b49c;
};

// TARGET: CViewRender::vfunc0
void CViewRender::vfunc0()
{
	CVRView *s = (CVRView *)this;
	ScopeTrace trace("CViewRender::Init", g_102de300);
	s->m_pViewSize = ((void *)cvar->FindVar("viewsize"));
	s->m_pDrawEntities = ((void *)cvar->FindVar("r_drawentities"));
	s->m_pDrawBrushModels = ((void *)cvar->FindVar("r_drawbrushmodels"));
	s->m_n28c = 0;
	s->m_n290 = 0;
	s->m_n294 = 0;
	s->m_n298 = 0;
	memset(s->m_a2a0, 0, sizeof(s->m_a2a0));
	g_102d5050->v0();
	g_1028073c->v0();
	s->m_mat388.sub_100cd1f0("debug/debugtranslucentsinglecolor");
	s->m_mat38c.sub_100cd1f0("engine/modulatesinglecolor");
	for (int i = 0; i < 8; i++)
		if (g_102d4290[i] && g_102d4290[i][0])
			s->m_mats390[i].sub_100cd1f0(g_102d4290[i]);
	s->m_m3b4.sub_100cd1f0("engine/depthonly");
	s->m_m3b8.sub_100cd1f0("engine/depthset");
	s->m_m3bc.sub_100cd1f0("highlights/Fortitude_character");
	s->m_m3c0.sub_100cd1f0("highlights/Fortitude_Hit_character");
	s->m_m3c4.sub_100cd1f0("highlights/Bloodshield_character");
	s->m_m3c8.sub_100cd1f0("highlights/Bloodshield_Hit_character");
	s->m_m3cc.sub_100cd1f0("models/character/fortitudeskin");
	s->m_m3d0.sub_100cd1f0("models/hands/FortMHandTop");
	s->m_m3d4.sub_100cd1f0("models/hands/FortMHandBottom");
	s->m_m3d8.sub_100cd1f0("models/hands/FortMHandTop");
	s->m_m3dc.sub_100cd1f0("models/hands/FortMHandBottom");
	s->m_m3e0.sub_100cd1f0("effects/burnpeel");
	s->m_m3e4.sub_100cd1f0("engine/vertexcoloradditive");
	s->m_m3e8.sub_100cd1f0("engine/vertexcolorblend");
	s->m_m3ec.sub_100cd1f0("engine/occlusionquery");
	s->m_m3f0.sub_100cd1f0("effects/desaturatespotlightmodel");
	s->m_m3f4.sub_100cd1f0("effects/desaturatespotlightmodelblend");
	s->m_m3f8.sub_100cd1f0("effects/desaturatespotlightmodeladditive");
	s->m_m3fc.sub_100cd1f0("effects/desaturatespotlightmodelalphatest");
	s->m_m400.sub_100cd1f0("effects/colorspotlightmodel");
	s->m_m404.sub_100cd1f0("effects/colorspotlightmodelblend");
	s->m_m408.sub_100cd1f0("effects/colorspotlightmodeladditive");
	s->m_m40c.sub_100cd1f0("effects/colorspotlightmodelalphatest");
	s->m_m410.sub_100cd1f0("effects/lightblur_plus_noise");
	s->m_f414 = -1000.0f;
	s->m_m428.sub_100cd1f0("effects/motion_blur");
	s->m_m42c.sub_100cd1f0("effects/insight_blur");
	s->m_m424.sub_100cd1f0("effects/crossfade");
	s->m_m430.sub_100cd1f0("effects/redvision");
	s->m_m434.sub_100cd1f0("effects/Obfuscate_overlay");
	s->m_m438.sub_100cd1f0("highlights/Obfuscate_character");
	s->m_m43c.sub_100cd1f0("highlights/bloodmelt");
	s->m_m440.sub_100cd1f0("effects/Bloodshield_overlay");
	s->m_m444.sub_100cd1f0("effects/meleetrail");
	s->m_b448 = 0;
	s->m_b449 = 0;
	s->m_b44a = 0;
	s->m_f44c = 1.0f;
	s->m_b49c = 0;
	engine->GetViewAngles(*(QAngle *)(s->m_a458));
}
// END FUNCTION

// FUNCTION: 0x1018f9b0 size=0x7e
#include "CViewRender.h"
#include "ScopeTrace.h"

struct IViewEffects_1018f9b0
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
};

struct IClientShadowMgr_1018f9b0
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
};

extern IViewEffects_1018f9b0 *g_102d5050;
extern IClientShadowMgr_1018f9b0 *g_1028073c;

// TARGET: CViewRender::vfunc1
void CViewRender::vfunc1()
{
	ScopeTrace trace("CViewRender::LevelInit", g_102de300);

	g_102d5050->v2();
	g_1028073c->v3();

	*(int *)((char *)this + 0x374) = 0;
	*(int *)((char *)this + 0x378) = 0;
}
// END FUNCTION

// FUNCTION: 0x1018fa30 size=0x78
#include "CViewRender.h"
#include "ScopeTrace.h"

extern void *g_102d5050;

class CUnknown100cd260
{
public:
	void sub_100cd260();
};

struct ViewEffectsView
{
	virtual void v0();
	virtual void v1();
};

void CViewRender::vfunc2()
{
	ScopeTrace trace("CViewRender::Shutdown", g_102de300);
	((CUnknown100cd260 *)((char *)this + 0x388))->sub_100cd260();
	((CUnknown100cd260 *)((char *)this + 0x38c))->sub_100cd260();
	((ViewEffectsView *)g_102d5050)->v1();
}
// END FUNCTION

// FUNCTION: 0x1018fab0 size=0x5f
#include "CViewRender.h"
#include "ScopeTrace.h"

// TARGET: CViewRender::sub_1018fab0
int CViewRender::sub_1018fab0()
{
	ScopeTrace trace("CViewRender::FrameNumber", g_102de300);
	return *(int *)((char *)this + 0x374);
}
// END FUNCTION

// FUNCTION: 0x1018fb10 size=0x5f
#include "CViewRender.h"
#include "ScopeTrace.h"

// TARGET: CViewRender::sub_1018fb10
int CViewRender::sub_1018fb10()
{
	ScopeTrace trace("CViewRender::BuildWorldListsNumber", g_102de300);
	return *(int *)((char *)this + 0x378);
}
// END FUNCTION

// FUNCTION: 0x101902e0 size=0x75
#include "engineclient.h"
#include "CViewRender.h"

struct XView
{
	virtual void v0();
	virtual bool vfunc1();
	char m_pad04[0x28 - 0x4];
	float m_fl28;
};
extern XView *g_105fc764;

struct ViewRenderV
{
	char m_pad00[0x2a0];
	float m_fl2a0;		// 0x2a0
	bool m_b2a4;		// 0x2a4
	char m_pad2a5[0x2a8 - 0x2a5];
	int m_n2a8;			// 0x2a8
	char m_pad2ac[0x2b0 - 0x2ac];
	double m_d2b0;		// 0x2b0
};

// TARGET: CViewRender::vfunc8
void CViewRender::vfunc8()
{
	ViewRenderV *v = (ViewRenderV *)this;
	float fov = engine->Time(0);
	if (fov == v->m_d2b0)
		return;
	if (!v->m_b2a4 && v->m_fl2a0 != 0.0f)
		return;
	float f;
	if (g_105fc764->vfunc1())
		f = 0.0f;
	else
		f = g_105fc764->m_fl28;
	v->m_fl2a0 = f;
	v->m_b2a4 = false;
	v->m_n2a8 = 0;
}
// END FUNCTION

// FUNCTION: 0x10190360 size=0x2c
#include "engineclient.h"
#include "CViewRender.h"
struct XVR { char u0[0x2a0]; int m_i2a0; char m_b2a4; char u1[0xb]; double m_d2b0; };
// TARGET: CViewRender::vfunc9
void CViewRender::vfunc9()
{
	XVR *p = (XVR *)this;
	p->m_d2b0 = engine->Time(0);
	p->m_b2a4 = 1;
	p->m_i2a0 = 0;
}
// END FUNCTION

// FUNCTION: 0x101911a0 size=0x5a
#include "CViewRender.h"
#include "ScopeTrace.h"
#include "CUnknown101d7520.h"

// TARGET: CViewRender::vfunc3
void CViewRender::vfunc3()
{
	ScopeTrace trace("CViewRender::OnRenderStart", g_102de300);
	sub_10191710();
}
// END FUNCTION

// FUNCTION: 0x10191610 size=0x5e
#include "CViewRender.h"
#include "ScopeTrace.h"

void *CViewRender::vfunc14()
{
	ScopeTrace trace("CViewRender::GetViewSetup", g_102de300);
	return (void *)((char *)this + 0x10);
}
// END FUNCTION

// FUNCTION: 0x10191670 size=0x8c
#include "CViewRender.h"
#include "ScopeTrace.h"
#include "Vector.h"
struct CViewRenderView {
	char pad[0xa5];
	bool m_bA5;
	char pad2[2];
	int m_nVisOrigins;
	Vector m_vecVisOrigins[1];
};
void CViewRender::vfunc15(const Vector &vecOrigin)
{
	ScopeTrace trace("CViewRender::AddVisOrigin", g_102de300);
	CViewRenderView *v = (CViewRenderView *)this;
	v->m_bA5 = true;
	v->m_vecVisOrigins[v->m_nVisOrigins++] = vecOrigin;
}
// END FUNCTION

// FUNCTION: 0x10191700 size=0x8
#include "CViewRender.h"
void CViewRender::vfunc16()
{
    *(char *)((char *)this + 0xa4) = 1;
}
// END FUNCTION

// FUNCTION: 0x10191940 size=0x9f
#include "CViewRender.h"
#include "C_BaseEntity.h"
#include "ScopeTrace.h"
#include "CUnknown1007f870.h"

struct ViewModelInfo
{
	char m_pad[8];
	Vector m_vecOrigin;
	QAngle m_angles;
};

extern CUnknown1007f870 *sub_100ab1e0(int);

// TARGET: CViewRender::CopyViewModelInfoToEntities
void CViewRender::CopyViewModelInfoToEntities()
{
	ScopeTrace st("CViewRender::CopyViewModelInfoToEntities", g_102de300);
	for ( int i = 0; i < 2; i++ )
	{
		ViewModelInfo *pInfo = (ViewModelInfo *)vfunc6(i);
		if ( !pInfo )
			continue;
		C_BaseEntity *pEntity = (C_BaseEntity *)(void *)sub_100ab1e0(i);
		if ( !pEntity )
			continue;
		pEntity->sub_100a2030(&pInfo->m_vecOrigin);
		pEntity->sub_100a2100(pInfo->m_angles);
	}
}
// END FUNCTION

// FUNCTION: 0x10192780 size=0xcc
#include "CViewRender.h"
#include "ScopeTrace.h"

struct ViewRenderV
{
	char pad0[0x478];
	bool m_b478;	// 0x478
	char pad479[3];
	Vector m_vec47c;	// 0x47c
	Vector m_vec488;	// 0x488
	float m_fl494;		// 0x494
};

bool CViewRender::vfunc40(Vector *pOut1, Vector *pOut2, float *pOut3)
{
	ScopeTrace trace("CViewRender::IsDrawingCrossfade", g_102de300);
	ViewRenderV *pView = (ViewRenderV *)this;
	if (!pView->m_b478)
		return false;
	if (pOut1)
		*pOut1 = pView->m_vec47c;
	if (pOut2)
		*pOut2 = pView->m_vec488;
	if (pOut3)
		*pOut3 = pView->m_fl494;
	return true;
}
// END FUNCTION

// FUNCTION: 0x10192850 size=0x1e
struct V2850 { char pad[0x450]; float m; int sub_10192850(); };
int V2850::sub_10192850() { return m > 0.0f; }
// END FUNCTION

// FUNCTION: 0x10192870 size=0x7
#include "CViewRender.h"
float CViewRender::vfunc45()
{
    return *(float *)((char *)this + 0x450);
}
// END FUNCTION

// FUNCTION: 0x10192aa0 size=0x14c
#include "CViewRender.h"
#include "engineclient.h"
#include "C_BasePlayer.h"
#include "ehandle.h"

void sub_10192990();
void sub_10192880();

struct CColl1 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void vfunc15(Vector *, Vector *); };

// TARGET: vfunc39
bool CViewRender::vfunc39(C_BaseEntity *pEnt, bool *pbOut)
{
	*pbOut = false;
	if (!*((bool *)this + 0x448))
		return false;
	if (!*((bool *)this + 0x44a)) {
		float blend = render->vfunc7();
		render->vfunc6(blend * *(float *)((char *)this + 0x44c));
	}
	if (pEnt) {
		C_BasePlayer *pLocal = C_BasePlayer::GetLocalPlayer();
		if (pLocal) {
			for (;;) {
				CBaseHandle &h = *(CBaseHandle *)((char *)pEnt + 0x188);
				C_BaseEntity *pParent = (C_BaseEntity *)h.Get();
				if (!pParent)
					break;
				pEnt = pParent;
			}
			int idx = *(int *)((char *)pEnt + 0x44);
			if (idx != *(int *)((char *)pLocal + 0x44) && idx != *(int *)((char *)pLocal + 0x16cc)) {
				Vector a, b;
				Vector c, d;
				((CColl1 *)((char *)pEnt + 0x190))->vfunc15(&a, &b);
				((CColl1 *)((char *)pLocal + 0x190))->vfunc15(&c, &d);
				if (d.z + 10.0f < b.z) {
					*pbOut = true;
					return false;
				}
			} else {
				if (*((bool *)this + 0x449))
					modelrender->vfunc4((void *)sub_10192990);
				return true;
			}
		}
	}
	if (*((bool *)this + 0x449))
		modelrender->vfunc4((void *)sub_10192880);
	return true;
}
// END FUNCTION

// FUNCTION: 0x101994c0 size=0xc9
#include "engineclient.h"
#include "CViewRender.h"
#include "C_BaseEntity.h"


struct IClientLeafSystemView
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void v9();
	virtual void v10();
	virtual void v11(unsigned short handle, int flags);
};

struct CBaseEntV
{
	char pad40[0x40];
	void *m_pModel;		// 0x40
	int m_unk44;
	int m_n48;		// 0x48
	char pad4c[0xe8 - 0x4c];
	unsigned short m_hE8;	// 0xe8
};

extern IClientLeafSystemView *g_102b9060;

int CViewRender::vfunc10(C_BaseEntity *pEntity)
{
	CBaseEntV *pView = (CBaseEntV *)pEntity;

	if (modelinfo->IsTranslucent(pEntity->GetModel()))
	{
		modelinfo->vfunc11((void *)(pEntity->GetModel()));
	}

	int nRenderMode = 5;
	IClientLeafSystemView *pLeaf = g_102b9060;
	if (pView->m_n48 == 0 && !pEntity->IsTransparent())
	{
		nRenderMode = !pEntity->vfunc79();
	}
	else if (pView->m_n48 != 6)
	{
		nRenderMode = 2;
	}

	if (pView->m_hE8 == 0xffff)
	{
		if (nRenderMode == 2 && modelinfo->vfunc10(pView->m_pModel))
			nRenderMode = 3;
		pEntity->sub_100a1a70(nRenderMode);
	}
	else
	{
		pLeaf->v11(pView->m_hE8, nRenderMode);
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x10199590 size=0x7
#include "CViewRender.h"
char * CViewRender::vfunc11()
{
    return (char *)this + 0x22c;
}
// END FUNCTION

// FUNCTION: 0x101995a0 size=0x7
#include "CViewRender.h"
char * CViewRender::vfunc12()
{
    return (char *)this + 0x310;
}
// END FUNCTION

// FUNCTION: 0x101995b0 size=0x29
struct CInner_q { virtual int v0(); virtual char v1(); char pad[0x2c - 4]; int m_n2c; };
struct COuter_p { int m_n0; CInner_q *m_pq; };
struct VView384 {
	char pad[0x384];
	COuter_p *m_p384;
	char sub_101995b0();
};
char VView384::sub_101995b0()
{
	COuter_p *p = m_p384;
	if (p && (p->m_pq->v1() || !p->m_pq->m_n2c))
		return 0;
	return 1;
}
// END FUNCTION

// FUNCTION: 0x1019a3f0 size=0x16b
#include "CViewRender.h"
#include "engineclient.h"
#include "ScopeTrace.h"
#include "CBaseHandle.h"
#include "ehandle.h"
#include "CUnknown100290c0.h"

extern "C" void *__cdecl memmove(void *, const void *, unsigned int);

struct RenderableView_1019a3f0
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual const void *GetModel();
};

struct EntView_1019a3f0
{
	virtual void v0();
	virtual const CBaseHandle &GetRefEHandle();
	char m_pad[0x400 - 4];
	int m_n400;
};

struct VecEH_1019a3f0
{
	int *m_pMemory;
	int m_allocationCount;
	int m_growSize;
	int m_size;
	int *m_pElements;

	void sub_100aad80(int num);
};

void CViewRender::vfunc42(EntView_1019a3f0 *pEnt)
{
	ScopeTrace st("CViewRender::AddObfuscatedEntityToRenderList", g_102de300);
	RenderableView_1019a3f0 *pRend = (RenderableView_1019a3f0 *)((char *)pEnt + 4);
	if (modelinfo->GetModelType(pRend->GetModel()) != 3 || pEnt->m_n400 != 0)
		return;
	CBaseHandle h;
	h = pEnt->GetRefEHandle();
	VecEH_1019a3f0 *v = (VecEH_1019a3f0 *)((char *)this + 0x464);
	int idx = -1;
	{ int i = 0; while (i < v->m_size) { int *base = v->m_pMemory;
		IHandleEntity *pSrc = (IHandleEntity *)((CUnknown100290c0 *)g_pEntityList)->sub_1007aca0((unsigned int *)&h);
		if (((CBaseHandle *)&base[i])->Get() == pSrc)
		{
			idx = i;
			break;
		} i++; } }
	if (!(idx != -1)) { int elem = v->m_size;
	if (1 + v->m_size > v->m_allocationCount)
		v->sub_100aad80(v->m_size + 1 - v->m_allocationCount);
	v->m_size += 1;
	v->m_pElements = v->m_pMemory;
	int n = v->m_size - elem - 1;
	if (0 < n)
		memmove(&v->m_pMemory[elem + 1], &v->m_pMemory[elem], n * 4);
	int *p = &v->m_pMemory[elem];
	if (p)
		*p = *(const int *)&h; }
}
// END FUNCTION

// FUNCTION: 0x1019dbd0 size=0x61d
#include "CViewRender.h"
#include "ScopeTrace.h"
#include "engineclient.h"
#include "C_BasePlayer.h"
#include "C_BaseEntity.h"
#include "CClientEntityList.h"
#include "ConVar.h"
extern "C" double pow(double, double);
#pragma intrinsic(pow)
extern "C" __declspec(dllimport) void Msg(const char *pMsg, ...);

struct CViewSetupRV
{
    int context;	// 0x00
    int m_n4; int m_n8; int m_nC; int m_n10;
    bool clearColor;	// 0x14
    bool clearDepth;	// 0x15
    bool m_b16; bool m_b17;
    int m_n18; int m_n1c; int m_n20; int m_n24; int m_n28; int m_n2c; int m_n30; int m_n34;
    Vector origin;	// 0x38
    Vector m_vUnreflectedOrigin;	// 0x44
    Vector angles;	// 0x50
    float zNear;	// 0x5c
    float zFar;	// 0x60
    int m_n64; int m_n68; int m_n6c; int m_n70; int m_n74; int m_n78; int m_n7c;
    int m_n80; int m_n84; int m_n88; int m_n8c; int m_n90;
};

#define VS6(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5();
struct Obj6View { VS6(a) virtual bool vfunc6(); };
extern Obj6View *g_10288318;
struct Panel22View { VS6(a) VS6(b) VS6(c) virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual bool vfunc22(); };
struct HudThing { int m_n0; int m_n4; int m_n8; int m_nC; Panel22View m_panel; };
HudThing *sub_10170f60();
struct ViewEffectsRV {
    virtual void v0(); virtual void v1();
    virtual void vfunc2(int context, unsigned char *r, unsigned char *g, unsigned char *b, unsigned char *a, bool *blend);
    virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual bool vfunc12();
    virtual void vfunc13();
};
extern ViewEffectsRV *g_102d5238;
struct ClientModeRV { VS6(a) VS6(b) VS6(c) VS6(d) VS6(e) virtual void vfunc30(); };
extern ClientModeRV *g_105f99d8;
struct OverdrawRV { VS6(a) virtual void v6(); virtual void vfunc7(float t, int b); };
extern OverdrawRV *g_102b849c;
struct PlayerRV { float sub_10099ac0(int); };

extern ConVar g_10618e18;
extern ConVar g_10618bd8;
extern ConVar g_10619140;
extern ConVar g_10618cb0;
extern ConVar g_10618c20;
extern ConVar g_106198a8;
extern bool g_106198f4;
extern bool g_106198ec;
void sub_10198720();
void sub_1002bfb0();

class CViewRenderRV : public CViewRender
{
public:
    void sub_1019d990(CViewSetupRV *view);
    bool sub_1019d600(const CViewSetupRV &view);
    void sub_1019d8f0(CViewSetupRV *view);
    void sub_1019b370(bool drawSky, CViewSetupRV *view, int a, bool drawViewModel);
    void sub_1019d590();
    void sub_10198fa0(const CViewSetupRV &view, bool drawViewModel);
    void sub_1019f940(const CViewSetupRV &view);
    bool sub_101a03a0(const CViewSetupRV &view);
    bool sub_1019ef20(const CViewSetupRV &view);
    bool sub_1019fea0(const CViewSetupRV &view);
    bool sub_101a00a0(const CViewSetupRV &view);
    bool sub_1019fa30(const CViewSetupRV &view);
    bool sub_1019f140(const CViewSetupRV &view);
    void sub_1019f480(const CViewSetupRV &view);
    void sub_1019fb50(const CViewSetupRV &view);
    void sub_1019dbd0(const CViewSetupRV &view, bool drawViewModel, bool bDraw2D);
};

// TARGET: CViewRenderRV::sub_1019dbd0
void CViewRenderRV::sub_1019dbd0(const CViewSetupRV &view, bool drawViewModel, bool bDraw2D)
{
    ScopeTrace st("CViewRender::RenderView", g_102de300);
    if (g_10288318 && g_10288318->vfunc6())
        return;
    if (sub_10170f60() && sub_10170f60()->m_panel.vfunc22())
        return;

    CViewSetupRV tmpView = view;
    g_106198f4 = true;
    sub_1019d990(&tmpView);

    C_BasePlayer *pPlayer = C_BasePlayer::GetLocalPlayer();
    if (pPlayer)
    {
        if (((PlayerRV *)pPlayer)->sub_10099ac0(0) > 0.01)
        {
            float scale = ((PlayerRV *)pPlayer)->sub_10099ac0(0);
            float fa = g_10618e18.GetFloat();
            float fb = g_10618bd8.GetFloat();
            fa = (*(int *)((char *)pPlayer + 0x1738) + fa) * scale;
            render->vfunc10((int)((pow(*(int *)((char *)pPlayer + 0x1734), 1.5) * 5.0 + fb) * scale));
            render->vfunc12((int)fa);
        }
        else
        {
            render->vfunc10((int)(pow(*(int *)((char *)pPlayer + 0x1734), 1.5) * 5.0));
            render->vfunc12(*(int *)((char *)pPlayer + 0x1738));
        }
    }
    else
    {
        render->vfunc10(0);
        render->vfunc12(0);
    }

    render->vfunc15();
    bool drawSky = true;
    if (!g_102d5238->vfunc12())
    {
        if (render->vfunc48(view.origin))
        {
            if (g_10619140.GetInt())
                Msg("Skybox is visible\n");
            if (sub_1019d600(view))
            {
                tmpView.clearColor = false;
                tmpView.clearDepth = false;
                drawSky = false;
            }
        }
        else
        {
            drawSky = false;
            if (g_10619140.GetInt())
                Msg("Skybox is NOT visible\n");
        }

        if (!tmpView.clearColor)
        {
            if (engine->vfunc19(engine->vfunc18(cl_entitylist->sub_100d0cf0(0)->vfunc51()), tmpView.origin) == 1)
            {
                tmpView.clearColor = true;
                tmpView.clearDepth = true;
            }
        }

        sub_1019d8f0(&tmpView);
        sub_1019b370(drawSky, &tmpView, 1, drawViewModel);
        g_106198ec = true;
        engine->vfunc93();
        sub_1019d590();
    }
    else
    {
        render->vfunc29(&tmpView, (char *)this + 0x22c);
        g_102d5238->vfunc13();
    }

    render->vfunc16();
    render->vfunc22();
    if (!g_102d5238->vfunc12())
        sub_10198fa0(tmpView, drawViewModel);
    g_105f99d8->vfunc30();
    if (!bDraw2D)
        return;

    unsigned char color[4];
    bool blend;
    g_102d5238->vfunc2(tmpView.context, &color[0], &color[1], &color[2], &color[3], &blend);
    void *pMaterial = *(blend ? (void **)((char *)this + 0x38c) : (void **)((char *)this + 0x388));
    render->vfunc32(color, pMaterial);
    engine->vfunc76();
    float flTime = engine->Time(0);
    tmpView.clearColor = false;
    tmpView.clearDepth = false;
    render->vfunc30(&tmpView);

    sub_1019f940(view);
    bool b = sub_101a03a0(view);
    if (!b)
        b = sub_1019ef20(view);
    if (!b)
        b = sub_1019fea0(view);
    if (!b)
        b = sub_101a00a0(view);
    if (!b)
        b = sub_1019fa30(view);
    if (!b)
        b = sub_1019f140(view);
    sub_10198720();
    sub_1019f480(view);
    if (b)
        sub_1019fb50(view);
    render->vfunc27();
    bool c = false;
    if (render->vfunc37())
        c = true;
    if (g_10618cb0.GetInt())
        g_102b849c->vfunc7(flTime, c);

    Vector *hist = (Vector *)((char *)this + 0x310);
    int &counter = *(int *)((char *)this + 0x370);
    hist[counter] = tmpView.angles;
    counter = (counter + 1) & 7;

    float angleMovementDelta = 0;
    for (int i = 0; i < 8; i++)
        angleMovementDelta += (hist[(i + 1) & 7] - hist[i]).Length();
    angleMovementDelta /= 8;
    if (angleMovementDelta > g_10618c20.GetFloat())
        g_106198a8.sub_100dfa90(1);
    else
        g_106198a8.sub_100dfa90(0);

    g_106198f4 = false;
    g_106198ec = false;
    ++*(int *)((char *)this + 0x374);
    sub_1002bfb0();
}
// END FUNCTION

// FUNCTION: 0x1019e1f0 size=0x22
#include "CViewRender.h"
struct E1019e1f0 { int d[11]; };
void *CViewRender::vfunc6(int i)
{
	if (i >= 0 && i < 2)
		return &((E1019e1f0 *)((char *)this + 0x2b8))[i];
	return 0;
}
// END FUNCTION
