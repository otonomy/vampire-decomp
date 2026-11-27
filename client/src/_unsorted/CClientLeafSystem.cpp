// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100d1510 size=0x1
#include "CClientLeafSystem.h"
void CClientLeafSystem::vfunc22()
{
}
// END FUNCTION

// FUNCTION: 0x100d1520 size=0x1
#include "CClientLeafSystem.h"
void CClientLeafSystem::vfunc23()
{
}
// END FUNCTION

// FUNCTION: 0x100d1770 size=0xd
#include "CClientLeafSystem.h"
bool CClientLeafSystem::vfunc15(char a0)
{
    *(char *)((char *)this + 0xd8) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x100d1780 size=0xd
#include "CClientLeafSystem.h"
bool CClientLeafSystem::vfunc16(char a0)
{
    *(char *)((char *)this + 0xd9) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x100d1c10 size=0x5d
#include "engineclient.h"
#include "CClientLeafSystem.h"
#include "IClientRenderable.h"



void CClientLeafSystem::vfunc0(IClientRenderable *pRenderable, bool bRenderWithViewModels)
{
	int group = pRenderable->IsTransparent() ? 2 : 1;

	bool bTwoPass = false;
	if (group == 2)
	{
		bTwoPass = modelinfo->vfunc10(pRenderable->GetModel());
	}

	int flags = bRenderWithViewModels ? 2 : 0;
	if (bTwoPass)
		flags |= 1;

	sub_100d1b60(pRenderable, group, flags);
}
// END FUNCTION

// FUNCTION: 0x100d1c70 size=0x1d
struct El1c70 { char pad[0x15]; char f; char pad2[0x34 - 0x16]; };
struct V1c70 { char pad[0x20]; El1c70 *arr; void sub_100d1c70(unsigned int h, char v); };
void V1c70::sub_100d1c70(unsigned int h, char v) { arr[h & 0xffff].f = v; }
// END FUNCTION

// FUNCTION: 0x100d1c90 size=0x60
#include "CClientLeafSystem.h"
struct RendView { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void GetBounds(float *mins, float *maxs); };
unsigned short CClientLeafSystem::vfunc4(IClientRenderable *pRenderable, int group)
{
    bool b = false;
    if (group == 3) { b = true; group = 2; }
    float mins[3], maxs[3];
    unsigned short h = sub_100d1b60(pRenderable, group, b ? 1 : 0);
    ((RendView *)pRenderable)->GetBounds(mins, maxs);
    sub_100d2800(h, mins, maxs);
    return h;
}
// END FUNCTION

// FUNCTION: 0x100d1de0 size=0x23
#include "CClientLeafSystem.h"
struct LeafRec { int a0, a4, a8, ac; unsigned short w10; short w12; int a14, a18, a1c, a20, a24, a28, a2c, a30; };
// TARGET: ?vfunc5@CClientLeafSystem@@UAE_NG@Z
bool CClientLeafSystem::vfunc5(unsigned short h) { return ((LeafRec *)m_pData)[h].w10 != 0xffff; }
// END FUNCTION

// FUNCTION: 0x100d1eb0 size=0x29
#include "CClientLeafSystem.h"
struct CLeafEnt_12 { int m_n0; unsigned short m_s4; unsigned short m_s6; int m_n8; };
void CClientLeafSystem::vfunc6(int idx, unsigned short a, unsigned short b)
{
	CLeafEnt_12 *e = &((CLeafEnt_12 *)m_unkc)[idx];
	e->m_s4 = a;
	e = &((CLeafEnt_12 *)m_unkc)[idx];
	e->m_s6 = b;
}
// END FUNCTION

// FUNCTION: 0x100d1ee0 size=0x2f
#include "CClientLeafSystem.h"
struct Ent_100d1ee0 { int m_u0; unsigned short m_w4; unsigned short m_w6; int m_u8; };
struct View_100d1ee0 { char pad[0xc]; Ent_100d1ee0 *m_pEnts; };
void CClientLeafSystem::vfunc7(int idx, unsigned int *a, unsigned int *b)
{
	Ent_100d1ee0 *p = ((View_100d1ee0 *)this)->m_pEnts;
	*a = p[idx].m_w4;
	*b = ((View_100d1ee0 *)this)->m_pEnts[idx].m_w6;
}
// END FUNCTION

// FUNCTION: 0x100d1f60 size=0xaa
#include "CClientLeafSystem.h"
#include "CUtlLinkedList12S.h"

// TARGET: CClientLeafSystem::vfunc18
void CClientLeafSystem::vfunc18(unsigned short elem)
{
	sub_100d2220(elem);
	CUtlLinkedList12S &list = *(CUtlLinkedList12S *)((char *)this + 0x3c);
	if (elem < list.m_NumAlloced && list.m_pMemory[elem].m_Previous != elem)
	{
		CUtlLinkedList12SNode *p = list.m_pMemory;
		unsigned short prev = p[elem].m_Previous;
		if (prev != 0xffff)
			p[prev].m_Next = p[elem].m_Next;
		else
			list.m_Head = p[elem].m_Next;
		unsigned short next = p[elem].m_Next;
		if (next != 0xffff)
			p[next].m_Previous = p[elem].m_Previous;
		else
			list.m_Tail = p[elem].m_Previous;
		p[elem].m_Next = elem;
		p[elem].m_Previous = elem;
		list.m_ElementCount--;
	}
	list.m_pMemory[elem].m_Next = list.m_FirstFree;
	list.m_FirstFree = elem;
}
// END FUNCTION

// FUNCTION: 0x100d2770 size=0x68
#include "CClientLeafSystem.h"
struct IVf { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(void *, void *); };
struct LSView { unsigned short sub_100d1e10(unsigned short); };
// TARGET: CClientLeafSystem::vfunc2
void CClientLeafSystem::vfunc2(unsigned short arg, int count, unsigned short *list)
{
    for (int i = 0; i < count; i++)
        sub_100d2560(list[i], arg);
    char *base = (char *)m_pData + (arg & 0xffff) * 0x34;
    *(unsigned short *)(base + 0x16) = ((LSView *)this)->sub_100d1e10(arg);
    char *item = (char *)m_pData + (arg & 0xffff) * 0x34;
    (*(IVf **)item)->v19(item + 0x18, item + 0x24);
}
// END FUNCTION

// FUNCTION: 0x100d2a10 size=0x25
#include "CClientLeafSystem.h"
namespace lifted {
struct C100d2800 { int sub_100d2800(int, int, int); };
struct C100d28a0 { int sub_100d28a0(int); };
}
int CClientLeafSystem::vfunc10(int a0, int a1, int a2)
{
    ((lifted::C100d28a0 *)this)->sub_100d28a0(a0);
    return ((lifted::C100d2800 *)this)->sub_100d2800(a0, a1, a2);
}
// END FUNCTION

// FUNCTION: 0x100d2a40 size=0xbf
#include "CClientLeafSystem.h"
struct RendV {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18();
    virtual void GetRenderBounds(float *mins, float *maxs);
};
struct LeafV {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void Changed(int handle, float *mins, float *maxs);
};
// TARGET: CClientLeafSystem::sub_100d2a40
void CClientLeafSystem::sub_100d2a40(int handle, int group)
{
    CClientLeafSystem::Item_t *p = &((CClientLeafSystem::Item_t *)m_pData)[handle & 0xffff];
    unsigned char flags = *(unsigned char *)&p->m_a14;
    if (group == 3) {
        group = 2;
        flags |= 1;
    } else {
        flags &= 0xfe;
    }
    *(unsigned char *)&p->m_a14 = flags;
    float maxs[3], mins[3];
    ((RendV *)p->m_a0)->GetRenderBounds(mins, maxs);
    float *pf = (float *)&p->m_a18;
    if (pf[0] != mins[0] || pf[1] != mins[1] || pf[2] != mins[2] || pf[3] != maxs[0] || pf[4] != maxs[1] || pf[5] != maxs[2])
        ((LeafV *)this)->Changed(handle, mins, maxs);
    ((unsigned char *)&p->m_a14)[1] = (unsigned char)group;
}
// END FUNCTION

// FUNCTION: 0x100d2b00 size=0x2f
#include "CClientLeafSystem.h"
struct Ent_100d2b00 { int m_u0; unsigned short m_w4; unsigned short m_w6; int m_u8; };
struct View_100d2b00 { char pad[0xc]; Ent_100d2b00 *m_pEnts; };
void CClientLeafSystem::vfunc8(int idx, int v, unsigned int *a, unsigned int *b)
{
	Ent_100d2b00 *p = &((View_100d2b00 *)this)->m_pEnts[idx];
	p->m_u8 = v;
	*a = p->m_w4;
	*b = p->m_w6;
}
// END FUNCTION

// FUNCTION: 0x100d2b30 size=0x1e
#include "CClientLeafSystem.h"
struct LeafE_100d2b30 { int a, b, c; };
struct LeafView_100d2b30 { char pad[0xc]; LeafE_100d2b30 *m_p; };
// TARGET: CClientLeafSystem::vfunc9
bool CClientLeafSystem::vfunc9(int i, int v)
{
	return ((LeafView_100d2b30 *)this)->m_p[i].c == v;
}
// END FUNCTION

// FUNCTION: 0x100d2b50 size=0x1f4
template <class T> __forceinline T pcd_stage(T x) { return x; }
#include "CClientLeafSystem.h"
struct CCycleCount_ {
	unsigned long m_lo, m_hi;
	void Sample() { __asm { mov ecx, this
		rdtsc
		mov [ecx], eax
		mov [ecx+4], edx } }
};
struct Cyc {
	unsigned __int64 m;
	void SubFrom(Cyc &o) { m = o.m - m; }
	void Accum(Cyc &o) { m += o.m; }
};
struct VNode {
	const char *m_pszName;
	int m_u4;
	Cyc m_CurTime;
	int m_nRecursions;
	int m_nCurFrameCalls;
	Cyc m_TotalTime;
	char m_pad[0x28];
	VNode *m_pParent;
	VNode *GetSubNode(const char *, int, const char *);
	void EnterScope();
};
struct VProfG {
	bool m_bVTune; int m_TargetGroup;
	int m_Stack[1024];
	int m_nStack; int m_enabled; bool m_fAtRoot; VNode *m_pCurNode; VNode *m_pRoot;
};
extern "C" __declspec(dllimport) void vtune(bool);
extern VProfG *g_101e3138;
extern VNode *(VNode::*g_101e314c)(const char *, int, const char *);
extern void (VNode::*g_101e3148)();
struct Info { int a0; int m_RenderFrame; int a8; int ac; short a10; short m_RenderLeaf; unsigned char m_Flags; unsigned char m_RenderGroup; short a16; int a18; int a1c; int a20; int a24; int a28; int a2c; int a30; };
struct Node8 { unsigned short elem; unsigned short a2; unsigned short a4; unsigned short next; };
struct LeafView {
	char pad0[0x20]; Info *m_Renderables;
	char pad1[0x34]; Node8 *m_InLeaf;
	char pad2[0x38]; unsigned short *(*pfn94)(int);
};
void CClientLeafSystem::vfunc12(int count, int *pLeafList, int *pLeafFogVolumeList, int frameNumber)
{
	LeafView *v = (LeafView *)this;
	VProfG *g = g_101e3138;
	if (g->m_enabled || !g->m_fAtRoot) {
		if (g->m_pCurNode->m_pszName != "CDetailObjectSystem::BuildDetailObjectRenderLists")
			g->m_pCurNode = (g->m_pCurNode->*g_101e314c)("CDetailObjectSystem::BuildDetailObjectRenderLists", 0, "Unaccounted");
		(g->m_pCurNode->*g_101e3148)();
		g->m_fAtRoot = false;
	}
	for (int i = 0; i < count; ++i) {
		int leaf = pLeafList[i];
		unsigned short idx = *v->pfn94(leaf);
		while (idx != 0xffff) {
			Node8 &n8 = v->m_InLeaf[idx];
			Info &info = v->m_Renderables[n8.elem];
			if (info.m_RenderFrame != frameNumber) {
				if (info.m_RenderGroup == 2)
					info.m_RenderLeaf = (short)leaf;
				info.m_RenderFrame = frameNumber;
				info.m_Flags &= ~0x18;
			}
			if (pLeafFogVolumeList[i] == -1)
				info.m_Flags |= 0x10;
			else
				info.m_Flags |= 8;
			idx = v->m_InLeaf[idx].next;
		}
	}
	g = g_101e3138;
	if (!g->m_fAtRoot || g->m_enabled) {
		VNode *n = g->m_pCurNode;
		if (--pcd_stage(n)->m_nRecursions == 0 && n->m_nCurFrameCalls != 0) {
			CCycleCount_ t;
			t.m_lo = 0; t.m_hi = 0;
			t.Sample();
			n->m_CurTime.SubFrom(*(Cyc *)&t);
			n->m_TotalTime.Accum(n->m_CurTime);
			VProfG *g2 = g_101e3138;
			int cur = --g2->m_nStack;
			int to = g2->m_Stack[cur + 1];
			int from = g2->m_Stack[cur];
			if (from != to && g2->m_bVTune && to == g2->m_TargetGroup)
				vtune(false);
		}
		if (n->m_nRecursions == 0)
			g->m_pCurNode = g->m_pCurNode->m_pParent;
		g->m_fAtRoot = (g->m_pCurNode == g->m_pRoot);
	}
}
// END FUNCTION

// FUNCTION: 0x100d2d50 size=0xae
#include "CClientLeafSystem.h"
#include "CUtlVector4.h"
struct LeafItem { int m_a0; int m_a4; int m_a8; int m_ac; int m_a10; unsigned char m_a14; unsigned char m_type; unsigned char m_a16; unsigned char m_a17; int m_a18; int m_a1c; int m_a20; int m_a24; int m_a28; int m_a2c; unsigned short m_a30; unsigned short m_next; };
// TARGET: CClientLeafSystem::vfunc14
void CClientLeafSystem::vfunc14(CUtlVector4 *out)
{
	unsigned short i = *(unsigned short *)((char *)this + 0x2c);
	while (i != 0xffff) {
		LeafItem *it = &((LeafItem *)*(void **)((char *)this + 0x20))[i];
		if (it->m_type == 4)
			out->AddToTailNew(it->m_a0);
		i = ((LeafItem *)*(void **)((char *)this + 0x20))[i].m_next;
	}
}
// END FUNCTION

// FUNCTION: 0x100d2e00 size=0x506
#include "CClientLeafSystem.h"
class __declspec(dllimport) CVProfNode
{
public:
	const char *m_pszName;
	char m_pad[0x44];
	CVProfNode *m_pParent;
	CVProfNode *GetSubNode(const char *pszName, int detailLevel, const char *pBudgetGroupName);
	void EnterScope();
	bool ExitScope();
};
struct VProf_Cur {
	char pad[0x100c];
	int m_Enabled;
	bool m_bAtRoot;
	char pad1011[3];
	CVProfNode *m_pCurNode;
	CVProfNode *m_pRootNode;
};
extern VProf_Cur *g_101e3138;
struct CV_13 {
	virtual void v0();
	virtual bool IsOff();
	char m_pad[0x28];
	int m_n2c;
};
extern CV_13 *g_104cef4c;
struct IRend_13 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual bool vf4();
	virtual void v5();
	virtual bool vf6();
	virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual int vf12();
	virtual void v13();
	virtual bool vf14();
};
struct RInfo_13 {
	IRend_13 *m_pRenderable;
	int m_u4;
	int m_nFrame;
	int m_uc;
	short m_w10;
	unsigned short m_w12;
	unsigned char m_Flags;
	unsigned char m_Group;
	short m_w16;
	float m_Mins[3];
	float m_Maxs[3];
	int m_u30;
};
struct RLEntry_13 { void *m_pRenderable; short m_iLeaf; short m_Handle; void *m_pBounds; };
struct RList_13 { RLEntry_13 m_Groups[6][0x1000]; int m_Counts[6]; };
struct SetupInfo_13 { RList_13 *m_pList; int m_n4; bool m_b8; bool m_b9; };
struct A1_13 { char pad[0xc]; int *m_p; };
struct Leaf_13 { int m_u0; unsigned short m_First; unsigned short m_Count; int m_u8; };
struct EngT_13 { char pad[0xf0]; void (__cdecl *Con_NPrintf)(void *self, int i, const char *fmt, ...); };
struct EngV_13 {
	EngT_13 *t;
};
struct EngI_13 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9();
	virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5(); virtual void b6(); virtual void b7(); virtual void b8(); virtual void b9();
	virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7(); virtual void c8(); virtual void c9();
	virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
	virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3(); virtual void e4(); virtual void e5(); virtual void e6(); virtual void e7(); virtual void e8(); virtual void e9();
	virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
	virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7(); virtual void g8(); virtual void g9();
	virtual void h0(); virtual void h1(); virtual void h2(); virtual void h3(); virtual void h4(); virtual void h5(); virtual void h6(); virtual void h7(); virtual void h8(); virtual void h9();
	virtual void i0(); virtual void i1(); virtual void i2(); virtual void i3(); virtual void i4(); virtual void i5(); virtual void i6(); virtual void i7();
	virtual bool vf98(const float *mins, const float *maxs, int leaf);
};
extern EngV_13 *g_104a57d4;
struct Detail_13 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
	virtual IRend_13 *vf9(unsigned int idx);
	virtual void v10();
	virtual void *vf11(unsigned int idx);
};
Detail_13 *sub_100dfdf0();
struct CLS_13 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
	virtual bool vf9(int leaf, int frame);
	int m_u4; int m_u8;
	Leaf_13 *m_pLeafs;
	char m_pad10[0x20 - 0x10];
	char *m_pRends;
	char m_pad24[0x58 - 0x24];
	char *m_pNodes;
	char m_pad5c[0x94 - 0x5c];
	unsigned short *(__cdecl *m_pfnLeafList)(int leaf);
	char m_pad98[0xd8 - 0x98];
	bool m_bD8;
	bool m_bD9;
};
static inline void AddToList_13(RList_13 &list, void *rend, int iLeaf, int group, int handle, void *bounds)
{
	int &curCount = list.m_Counts[group];
	if (curCount < 0x1000)
	{
		RLEntry_13 *pEntry = &list.m_Groups[group][curCount];
		pEntry->m_pRenderable = rend;
		pEntry->m_iLeaf = iLeaf;
		pEntry->m_Handle = handle;
		pEntry->m_pBounds = bounds;
		curCount++;
	}
	else
	{
		g_104a57d4->t->Con_NPrintf(g_104a57d4, 10, "Warning: overflowed CRenderList group %d", group);
	}
}
static inline void ProfExit_13()
{
	VProf_Cur *g = g_101e3138;
	if (!g->m_bAtRoot || g->m_Enabled)
	{
		if (g->m_pCurNode->ExitScope())
			g->m_pCurNode = g->m_pCurNode->m_pParent;
		g->m_bAtRoot = (g->m_pCurNode == g->m_pRootNode);
	}
}
// TARGET: CClientLeafSystem::vfunc13
void CClientLeafSystem::vfunc13(void *a1, int leaf, int a3, void *infoV)
{
	CLS_13 *self = (CLS_13 *)this;
	SetupInfo_13 *info = (SetupInfo_13 *)infoV;
	unsigned short idx = *self->m_pfnLeafList(leaf);
	while (idx != 0xffff)
	{
		RInfo_13 *r = (RInfo_13 *)(self->m_pRends + *(unsigned short *)((int)idx * 8 + (int)self->m_pNodes) * 52);
		if (!self->m_bD8 && (r->m_Flags & 2))
			goto next;
		if (!self->m_bD9 && (r->m_Maxs[0] - r->m_Mins[0] < 50.0f) && (r->m_Maxs[1] - r->m_Mins[1] < 50.0f))
			goto next;
		if (r->m_Group != 2)
		{
			if (r->m_nFrame == info->m_n4)
				goto next;
			r->m_nFrame = info->m_n4;
		}
		if (!g_104cef4c->IsOff() && g_104cef4c->m_n2c)
		{
			VProf_Cur *g = g_101e3138;
			if (g->m_Enabled || !g->m_bAtRoot)
			{
				if (g->m_pCurNode->m_pszName != "r_PortalTestEnts")
					g->m_pCurNode = g->m_pCurNode->GetSubNode("r_PortalTestEnts", 0, "Unaccounted");
				g->m_pCurNode->EnterScope();
				g->m_bAtRoot = false;
			}
			if (r->m_w16 != -1)
			{
				if (!((EngI_13 *)g_104a57d4)->vf98(r->m_Mins, r->m_Maxs, r->m_w16))
				{
					ProfExit_13();
					goto next;
				}
			}
			ProfExit_13();
		}
		if (info->m_b9)
		{
			if (!r->m_pRenderable->vf6())
				goto next;
		}
		if (r->m_Group == 2)
		{
			if (r->m_w12 != leaf)
				goto next;
			if (r->m_pRenderable->vf14())
			{
				AddToList_13(*info->m_pList, r->m_pRenderable, a3, r->m_Group, r->m_Flags, r->m_Mins);
				if (r->m_Flags & 1)
					AddToList_13(*info->m_pList, r->m_pRenderable, a3, 1, r->m_Flags, r->m_Mins);
			}
		}
		else
		{
			if (r->m_pRenderable->vf14())
				AddToList_13(*info->m_pList, r->m_pRenderable, a3, r->m_Group, r->m_Flags, r->m_Mins);
		}
next:
		idx = *(unsigned short *)((int)idx * 8 + (int)self->m_pNodes + 6);
	}
	if (info->m_b8 && self->vf9(leaf, info->m_n4))
	{
		Leaf_13 *pLeaf = &self->m_pLeafs[leaf];
		unsigned short first = pLeaf->m_First;
		bool bSecond = ((A1_13 *)a1)->m_p[a3] == -1;
		int handle = bSecond ? 16 : 8;
		for (int i = pLeaf->m_Count - 1; i >= 0; i--)
		{
			IRend_13 *d = sub_100dfdf0()->vf9(first);
			if (d)
			{
				if (d->vf4())
				{
					if (d->vf12() > 0)
					{
						void *b = sub_100dfdf0()->vf11(first);
						AddToList_13(*info->m_pList, d, a3, 2, handle, b);
					}
				}
				else
				{
					void *b = sub_100dfdf0()->vf11(first);
					AddToList_13(*info->m_pList, d, a3, 1, handle, b);
				}
			}
			first++;
		}
	}
}
// END FUNCTION

// FUNCTION: 0x100d3310 size=0x19
#include "CClientLeafSystem.h"
// TARGET: CClientLeafSystem::vfunc21
void *CClientLeafSystem::vfunc21(unsigned short h) { return &m_pData->m_Items[h]; }
// END FUNCTION
