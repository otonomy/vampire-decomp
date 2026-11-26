// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101c11b0 size=0x45
#include "vgui2__BuildGroup.h"
namespace lifted {
int sub_101c2180();
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual int f15(int); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); };
}
void vgui2::BuildGroup::vfunc0(char a0)
{
    if ((*(char *)((char *)this + 4)) != a0) {
        *(int *)((char *)this + 0x3c) = 0;
        if (a0 != 0) {
            int t0 = lifted::sub_101c2180();
            *(char *)((char *)this + 4) = a0;
            return;
        }
        if ((*(int *)((char *)this + 0x58)) != 0) {
            ((lifted::V *)(*(int *)((char *)this + 0x58)))->f21(0);
        }
        ((lifted::V *)(*(int *)((char *)this + 0x60)))->f15(0);
    }
    *(char *)((char *)this + 4) = a0;
}
// END FUNCTION

// FUNCTION: 0x101c1200 size=0x4
#include "vgui2__BuildGroup.h"
bool vgui2::BuildGroup::vfunc1()
{
    return *(bool *)((char *)this + 4);
}
// END FUNCTION

// FUNCTION: 0x101c1210 size=0x4
#include "vgui2__BuildGroup.h"
char * vgui2::BuildGroup::vfunc14()
{
    return (char *)this + 0x64;
}
// END FUNCTION

// FUNCTION: 0x101c1220 size=0x7
#include "vgui2__BuildGroup.h"
bool vgui2::BuildGroup::vfunc17()
{
    return *(bool *)((char *)this + 0xb0);
}
// END FUNCTION

// FUNCTION: 0x101c1330 size=0x3d
#include "vgui2__BuildGroup.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); };
}
int vgui2::BuildGroup::vfunc16(int a0)
{
    ((lifted::V *)(*(int *)((char *)this + 0xa0)))->f21(a0);
    ((lifted::V *)(*(int *)((char *)this + 0xa4)))->f21(a0);
    ((lifted::V *)(*(int *)((char *)this + 0xa8)))->f21(a0);
    return ((lifted::V *)(*(int *)((char *)this + 0xac)))->f21(a0);
}
// END FUNCTION

// FUNCTION: 0x101c1370 size=0x435
#include "vgui2__BuildGroup.h"
#include "vgui2__Label.h"
#include <stdio.h>

struct Surface_101c1370
{
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void PushMakeCurrent(int panel, bool useInsets);
    virtual void PopMakeCurrent(int panel);
    virtual void v10();
    virtual void DrawSetColor(int r, int g, int b, int a);
    virtual void DrawFilledRect(int x0, int y0, int x1, int y1);
};

Surface_101c1370 *sub_101ac8d0();

struct Bounds_101a9980
{
    void sub_101a9980(int &x, int &y, int &wide, int &tall);
};

#define BG_BUILDCONTEXT ((vgui2::Panel *)m_unk5c)
#define BG_CURRENT ((vgui2::Panel *)m_unk3c)
#define BG_RULER(i) (((vgui2::Label **)((char *)this + 0xa0))[i])

void vgui2::BuildGroup::vfunc18()
{
    if (!*((char *)this + 0xb0))
        return;

    if (BG_BUILDCONTEXT == BG_CURRENT)
    {
        vfunc16(0);
        return;
    }
    else
        vfunc16(1);

    int x, y, wide, tall;
    ((Bounds_101a9980 *)BG_BUILDCONTEXT)->sub_101a9980(x, y, wide, tall);
    BG_BUILDCONTEXT->vfunc27(&x, &y);

    int cx, cy, cwide, ctall;
    ((Bounds_101a9980 *)BG_CURRENT)->sub_101a9980(cx, cy, cwide, ctall);

    sub_101ac8d0()->PushMakeCurrent(BG_BUILDCONTEXT->vfunc0(), false);

    sub_101ac8d0()->DrawSetColor(255, 255, 255, 255);

    sub_101ac8d0()->DrawFilledRect(0, cy, cx, cy + 1);
    sub_101ac8d0()->DrawFilledRect(cx + cwide, cy, wide, cy + 1);

    sub_101ac8d0()->DrawFilledRect(0, cy + ctall - 1, cx, cy + ctall);
    sub_101ac8d0()->DrawFilledRect(cx + cwide, cy + ctall - 1, wide, cy + ctall);

    sub_101ac8d0()->DrawFilledRect(cx, 0, cx + 1, cy);
    sub_101ac8d0()->DrawFilledRect(cx + cwide - 1, 0, cx + cwide, cy);

    sub_101ac8d0()->DrawFilledRect(cx, cy + ctall, cx + 1, tall);
    sub_101ac8d0()->DrawFilledRect(cx + cwide - 1, cy + ctall, cx + cwide, tall);

    sub_101ac8d0()->PopMakeCurrent(BG_BUILDCONTEXT->vfunc0());

    char textstring[20];
    sprintf(textstring, "%d", cx);
    BG_RULER(0)->vfunc108(textstring);
    int twide, ttall;
    BG_RULER(0)->vfunc110(&twide, &ttall);
    BG_RULER(0)->sub_101a98f0(twide, ttall);
    BG_RULER(0)->sub_101a9890(cx / 2 - twide / 2, cy - ttall + 3);

    sprintf(textstring, "%d", cy);
    BG_RULER(1)->vfunc108(textstring);
    BG_RULER(1)->vfunc110(&twide, &ttall);
    BG_RULER(1)->sub_101a98f0(twide, ttall);
    BG_RULER(1)->sub_101a9920(&twide, &ttall);
    BG_RULER(1)->sub_101a9890(cx - twide + 3, cy / 2 - ttall / 2);

    sprintf(textstring, "%d", cy);
    BG_RULER(2)->vfunc108(textstring);
    BG_RULER(2)->vfunc110(&twide, &ttall);
    BG_RULER(2)->sub_101a98f0(twide, ttall);
    BG_RULER(2)->sub_101a9890(cx + cwide + (wide - cx - cwide) / 2 - twide / 2, cy + ctall - 3);

    sprintf(textstring, "%d", cy);
    BG_RULER(3)->vfunc108(textstring);
    BG_RULER(3)->vfunc110(&twide, &ttall);
    BG_RULER(3)->sub_101a98f0(twide, ttall);
    BG_RULER(3)->sub_101a9890(cx + cwide, cy + ctall + (tall - cy - ctall) / 2 - ttall / 2);
}
// END FUNCTION

// FUNCTION: 0x101c1db0 size=0x15
#include "vgui2__BuildGroup.h"
namespace lifted {
int sub_101ac8b0();
struct V { virtual void u0(); virtual int f1(int); };
}
int vgui2::BuildGroup::vfunc13(int a0, int a1)
{
    *(char *)((char *)this + 0x24) = 0;
    return ((lifted::V *)(lifted::sub_101ac8b0()))->f1(0);
}
// END FUNCTION

// FUNCTION: 0x101c1dd0 size=0x3
#include "vgui2__BuildGroup.h"
void vgui2::BuildGroup::vfunc20(int a0, int a1)
{
}
// END FUNCTION

// FUNCTION: 0x101c1de0 size=0x2eb
struct KV {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
	virtual void SetPtr(const char *name, void *p);
	KV *sub_101b5670(const char *name);
};
struct IInputV {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11();
	virtual bool IsKeyDown(int code);
};
struct IVGuiV {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void PostMessage(int to, KV *msg, int from, float delay);
};
struct PH { virtual int GetVPanel(); };
struct PanelV {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void Repaint();
	virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30();
	virtual PanelV *GetParent();
	void sub_101a9980(int *x, int *y, int *w, int *h);
	void sub_101a98f0(int w, int h);
	void sub_101a9890(int x, int y);
};
IInputV *sub_101ac8b0();
IVGuiV *sub_101ac8f0();
void *sub_101b6840(int size);
struct BG {
	virtual void v0(); virtual void v1();
	virtual PanelV *GetPanel();
	int m_unk4;
	int m_stepX;
	int m_stepY;
	char pad[0x58 - 0x10];
	PH *m_pOwner;
	void sub_101c2310(PanelV *p);
	void sub_101c1de0(int code, PanelV *panel);
};
// TARGET: BG::sub_101c1de0
void BG::sub_101c1de0(int code, PanelV *panel)
{
	int dx = 0, dy = 0;
	if (!sub_101ac8b0()->IsKeyDown(0x51))
		sub_101ac8b0()->IsKeyDown(0x52);
	bool b1 = sub_101ac8b0()->IsKeyDown(0x4f) || sub_101ac8b0()->IsKeyDown(0x50);
	bool b2 = sub_101ac8b0()->IsKeyDown(0x53) || sub_101ac8b0()->IsKeyDown(0x54);
	switch (code)
	{
	case 89: dx = -m_stepX; break;
	case 91: dx = m_stepX; break;
	case 88: dy = -m_stepY; break;
	case 90: dy = m_stepY; break;
	case 73:
		{
			KV *kv = 0;
			KV *t = (KV *)sub_101b6840(0x1c);
			if (t)
				kv = t->sub_101b5670("DeletePanel");
			sub_101ac8f0()->PostMessage(m_pOwner->GetVPanel(), kv, 0, 0);
		}
		break;
	}
	if (b2)
	{
		KV *kv;
		switch (code)
		{
		case 0xd:
			kv = (KV *)sub_101b6840(0x1c);
			if (kv)
				kv = kv->sub_101b5670("Copy");
			else
				kv = 0;
			sub_101ac8f0()->PostMessage(m_pOwner->GetVPanel(), kv, 0, 0);
			break;
		case 0x20:
			kv = (KV *)sub_101b6840(0x1c);
			if (kv)
				kv = kv->sub_101b5670("Paste");
			else
				kv = 0;
			sub_101ac8f0()->PostMessage(m_pOwner->GetVPanel(), kv, 0, 0);
			break;
		case 0x24:
			kv = (KV *)sub_101b6840(0x1c);
			if (kv)
				kv = kv->sub_101b5670("Undo");
			else
				kv = 0;
			sub_101ac8f0()->PostMessage(m_pOwner->GetVPanel(), kv, 0, 0);
			break;
		}
	}
	if (dx || dy)
	{
		int x, y, w, h;
		panel->sub_101a9980(&x, &y, &w, &h);
		if (b1)
			panel->sub_101a98f0(w + dx, h + dy);
		else
			panel->sub_101a9890(x + dx, y + dy);
		sub_101c2310(panel);
		panel->Repaint();
		if (panel->GetParent())
			panel->GetParent()->Repaint();
		if (m_pOwner)
		{
			KV *kv = (KV *)sub_101b6840(0x1c);
			if (kv)
				kv = kv->sub_101b5670("SetActiveControl");
			else
				kv = 0;
			kv->SetPtr("PanelPtr", GetPanel());
			sub_101ac8f0()->PostMessage(m_pOwner->GetVPanel(), kv, 0, 0);
		}
	}
}
// END FUNCTION

// FUNCTION: 0x101c2270 size=0x8d
#include "vgui2__BuildGroup.h"
#include "vgui2__Panel.h"
struct ISurf_101c2270 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
	virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
	virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
	virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71();
	virtual void GetCursorPos(int &x, int &y);
};
extern ISurf_101c2270 *sub_101ac8d0();
struct PV_101c2270 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26();
	virtual void ScreenToLocal(int *x, int *y);
};

int vgui2::BuildGroup::vfunc22(vgui2::Panel *panel)
{
	int x, y, wide, tall;
	sub_101ac8d0()->GetCursorPos(x, y);
	((PV_101c2270 *)panel)->ScreenToLocal(&x, &y);
	panel->sub_101a9920(&wide, &tall);
	if (x < 2) {
		if (y < 4)
			return m_n10;
		if (y < tall - 4)
			return m_n18;
		return m_n14;
	}
	return m_n20;
}
// END FUNCTION

// FUNCTION: 0x101c2300 size=0x4
#include "vgui2__BuildGroup.h"
int vgui2::BuildGroup::vfunc10()
{
    return *(int *)((char *)this + 0x54);
}
// END FUNCTION

// FUNCTION: 0x101c23b0 size=0x4
#include "vgui2__BuildGroup.h"
int vgui2::BuildGroup::vfunc2()
{
    return *(int *)((char *)this + 0x3c);
}
// END FUNCTION

// FUNCTION: 0x101c23c0 size=0xbf
#include "vgui2__BuildGroup.h"
struct PHandle101c23c0
{
    int m_h;
    PHandle101c23c0() : m_h(-1) {}
    vgui2::Panel *sub_101ac6b0(vgui2::Panel *);
};

void vgui2::BuildGroup::vfunc11(vgui2::Panel *pPanel)
{
    PHandle101c23c0 h;
    h.sub_101ac6b0(pPanel);
    ((CUtlVector<int> &)m_Panels).AddToTail(h.m_h);
}
// END FUNCTION

// FUNCTION: 0x101c2480 size=0x79
#include "vgui2__BuildGroup.h"
#include <string.h>

extern void *sub_101b6840(unsigned int size);
extern void *sub_101ac910();

struct KV_101c2480 {
	virtual void v0();
	virtual void v1();
	virtual bool LoadFromFile(void *filesystem, const char *resourceName, const char *pathID);
	virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
	virtual void deleteThis();
	KV_101c2480 *sub_101b5670(const char *name);
};

// TARGET: vgui2::BuildGroup::vfunc3
void vgui2::BuildGroup::vfunc3(const char *resourceName)
{
	KV_101c2480 *kv = (KV_101c2480 *)sub_101b6840(0x1c);
	if (kv)
		kv = kv->sub_101b5670(resourceName);
	else
		kv = 0;

	kv->LoadFromFile(sub_101ac910(), resourceName, 0);

	char *&pResourceName = *(char **)((char *)this + 0x54);
	if (!pResourceName)
	{
		pResourceName = new char[strlen(resourceName) + 1];
		strcpy(pResourceName, resourceName);
	}

	vfunc5(kv);
	kv->deleteThis();
}
// END FUNCTION

// FUNCTION: 0x101c25e0 size=0x52
#include "vgui2__BuildGroup.h"

extern void *sub_101b6840(unsigned int size);
extern void *sub_101ac910();

struct KV_101c25e0
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void vfunc3(void *filesystem, const char *resourceName, const char *pathID);
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
	virtual void deleteThis();
	KV_101c25e0 *sub_101b5670(const char *name);
};

// TARGET: vgui2::BuildGroup::vfunc4
void vgui2::BuildGroup::vfunc4()
{
	if ( !*(char **)((char *)this + 0x54) )
		return;

	KV_101c25e0 *kv = (KV_101c25e0 *)sub_101b6840(0x1c);
	if ( kv )
		kv = kv->sub_101b5670(*(char **)((char *)this + 0x54));
	else
		kv = 0;

	vfunc6(kv);
	kv->vfunc3(sub_101ac910(), *(char **)((char *)this + 0x54), 0);
	kv->deleteThis();
}
// END FUNCTION

// FUNCTION: 0x101c2640 size=0x88
#include "vgui2__BuildGroup.h"
#include "vgui2__Panel.h"

extern "C" int __cdecl _strcmpi(const char *, const char *);

struct KVV
{
	virtual const char *vfunc0();
	virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6();
	virtual void *vfunc7();
	virtual void *vfunc8();
	virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
	virtual int vfunc20(int);
};

struct XHView { int m_handle; vgui2::Panel *sub_101ac670(); };

void vgui2::BuildGroup::vfunc5(void *arg)
{
	KVV *p = (KVV *)((KVV *)arg)->vfunc7();
	if (!p)
		return;

	for (; p; p = (KVV *)p->vfunc8())
	{
		if (p->vfunc20(0))
			continue;
		for (int i = 0; i < m_Panels.Count(); i++)
		{
			vgui2::Panel *e = ((XHView *)&m_Panels[i])->sub_101ac670();
			if (_strcmpi(e->vfunc18(), p->vfunc0()) == 0)
			{
				e->vfunc75((int)p);
				goto next;
			}
		}
		sub_101c2770((vgui2::KeyValues *)p, 0, 0);
	next: ;
	}
}
// END FUNCTION

// FUNCTION: 0x101c2970 size=0xb0
#include "vgui2__BuildGroup.h"
#include "vgui2__Panel.h"
extern "C" int __cdecl strcmp(const char *, const char *);
struct BGHandleView { vgui2::Panel *sub_101ac670(); };
struct BGKeyValuesView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual int FindKey(const char *name, int create);
};
// TARGET: vgui2::BuildGroup::vfunc6
void vgui2::BuildGroup::vfunc6(void *resourceData)
{
	for (int i = 0; i < m_Panels.Count(); i++) {
		vgui2::Panel *panel = ((BGHandleView *)&m_Panels[i])->sub_101ac670();
		if (*(bool *)((char *)this + 0xb0)) {
			for (int j = 0; j < 4; j++) {
				if (panel == ((vgui2::Panel **)((char *)this + 0xa0))[j])
					goto next;
			}
		}
		if (!strcmp(panel->vfunc18(), "BuildDialog"))
			goto next;
		if (!panel->vfunc18())
			goto next;
		if (!*panel->vfunc18())
			goto next;
		{
			BGKeyValuesView *kv = (BGKeyValuesView *)resourceData;
			int dat = kv->FindKey(panel->vfunc18(), 1);
			panel->vfunc76(dat);
		}
next:;
	}
}
// END FUNCTION

// FUNCTION: 0x101c2a20 size=0xd2
#include "vgui2__BuildGroup.h"
#include "vgui2__Panel.h"

void *__fastcall sub_101ac670(void *pSlot);
bool __fastcall sub_101aab80(void *p);

void vgui2::BuildGroup::vfunc7()
{
	int i;
	for (i = 0; i < m_Controls.Count(); i++)
	{
		if (sub_101aab80(sub_101ac670(&m_Controls[i])))
		{
			vgui2::Panel *p = (vgui2::Panel *)sub_101ac670(&m_Controls[i]);
			if (p)
				delete p;
			m_Controls.Remove(i);
			i--;
		}
	}
	for (i = 0; i < m_Panels.Count(); i++)
	{
		if (sub_101ac670(&m_Panels[i]) != 0)
			continue;
		m_Panels.Remove(i);
		i--;
	}
	m_unk3c = m_unk5c;
	vfunc18();
	((vgui2::Panel *)m_unk5c)->vfunc6();
}
// END FUNCTION

// FUNCTION: 0x101c2b00 size=0xa
#include "vgui2__BuildGroup.h"
int vgui2::BuildGroup::vfunc8(int a0)
{
    *(int *)((char *)this + 0x5c) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101c2b10 size=0x4
#include "vgui2__BuildGroup.h"
int vgui2::BuildGroup::vfunc9()
{
    return *(int *)((char *)this + 0x5c);
}
// END FUNCTION
