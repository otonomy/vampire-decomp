// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101b46c0 size=0x1e
#include "vgui2__EditablePanel.h"

// VC6 writes vgui2::EditablePanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::EditablePanel *pcd_emit_101b46c0(const vgui2::EditablePanel &other) { return new vgui2::EditablePanel(other); }

// TARGET: ??_GEditablePanel@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101b4740 size=0x32
#include "vgui2__EditablePanel.h"
#include "vgui2__BuildGroup.h"
struct CUnknown101c2e30 { void sub_101c2e30(); };
using namespace vgui2;
// TARGET: vgui2::EditablePanel::~EditablePanel
EditablePanel::~EditablePanel()
{
	BuildGroup *p = (BuildGroup *)m_p58;
	if (p)
		delete p;
	((CUnknown101c2e30 *)((char *)this + 0x5c))->sub_101c2e30();
}
// END FUNCTION

// FUNCTION: 0x101b4780 size=0x42
#include "vgui2__EditablePanel.h"
int sub_101ac900();
struct VC {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(void *p);
	virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(void *p);
};
struct VB { virtual void v0(); virtual VC *v1(); };
struct VA { virtual void v0(); virtual VB *v1(int); };
// TARGET: vgui2::EditablePanel::vfunc10
void vgui2::EditablePanel::vfunc10(int a) {
	Panel::vfunc10(a);
	VC *c = ((VA *)sub_101ac900())->v1(a)->v1();
	c->v66(m_p58);
	c->v41(this);
}
// END FUNCTION

// FUNCTION: 0x101b47d0 size=0x151
#include "vgui2__EditablePanel.h"

// TARGET: vgui2::EditablePanel::vfunc11
void vgui2::EditablePanel::vfunc11(int newWide, int newTall)
{
	Panel::vfunc11(newWide, newTall);
	vfunc57(0, 0);
	int dx = newWide - m_i70;
	int dy = newTall - m_i74;
	for (int i = 0; i < vfunc36(); i++)
	{
		Panel *child = vfunc37(i);
		int x, y, wide, tall;
		child->sub_101a9980(&x, &y, &wide, &tall);
		if (child->sub_101ab460() == 1 || child->sub_101ab460() == 3)
			x += dx;
		if (child->sub_101ab460() == 2 || child->sub_101ab460() == 3)
			y += dy;
		if (child->sub_101ab480() == 1 || child->sub_101ab480() == 3)
			wide += dx;
		if (child->sub_101ab480() == 2 || child->sub_101ab480() == 3)
			tall += dy;
		child->sub_101a9950(x, y, wide, tall);
		child->vfunc57(0, 0);
	}
	vfunc5();
	m_i74 = newTall;
	m_i70 = newWide;
}
// END FUNCTION

// FUNCTION: 0x101b4930 size=0x61
#include "vgui2__KeyValues.h"

extern int sub_101b6840( int size );

class CUnknown101b5670
{
public:
	void *sub_101b5670( int name );
};

class CFocusNavGroup_101b4930
{
public:
	virtual void v0();
	virtual void SetDefaultButton( int panel );
};

class CEditablePanel_101b4930
{
public:
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22();
	virtual void PostMessage( int target, vgui2::KeyValues *msg, float delay = 0.0f );
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(); virtual void v29(); virtual void v30();
	virtual int GetVParent();

	char m_pad4[0x5c - 0x4];
	CFocusNavGroup_101b4930 m_NavGroup;

	void sub_101b4930( int panel );
};

void CEditablePanel_101b4930::sub_101b4930( int panel )
{
	m_NavGroup.SetDefaultButton( panel );
	if ( GetVParent() )
	{
		CUnknown101b5670 *raw = (CUnknown101b5670 *)sub_101b6840( 0x1c );
		vgui2::KeyValues *msg = raw ? (vgui2::KeyValues *)raw->sub_101b5670( (int)"DefaultButtonSet" ) : 0;
		msg->vfunc17( (int)"panel", panel );
		PostMessage( GetVParent(), msg, 0.0f );
	}
}
// END FUNCTION

// FUNCTION: 0x101b4d60 size=0xa
#include "vgui2__EditablePanel.h"
namespace lifted {
struct V { virtual int f0(int); };
}
int vgui2::EditablePanel::vfunc108()
{
    return ((lifted::V *)(*(int *)((char *)this + 0x58)))->f0(1);
}
// END FUNCTION

// FUNCTION: 0x101b4d70 size=0x8
#include "vgui2__EditablePanel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual int f3(); };
}
void vgui2::EditablePanel::vfunc107()
{
    ((lifted::V *)(*(int *)((char *)this + 0x58)))->f3();
}
// END FUNCTION

// FUNCTION: 0x101b4e70 size=0x4
#include "vgui2__EditablePanel.h"
int vgui2::EditablePanel::vfunc109()
{
    return *(int *)((char *)this + 0x58);
}
// END FUNCTION

// FUNCTION: 0x101b4e80 size=0x4
#include "vgui2__EditablePanel.h"
char * vgui2::EditablePanel::vfunc116()
{
    return (char *)this + 0x5c;
}
// END FUNCTION

// FUNCTION: 0x101b4e90 size=0x9
#include "vgui2__EditablePanel.h"
struct SubObj59 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(int); };
// TARGET: vgui2::EditablePanel::vfunc59
void vgui2::EditablePanel::vfunc59(int a)
{
	((SubObj59 *)((char *)this + 0x5c))->v5(a);
}
// END FUNCTION

// FUNCTION: 0x101b4ea0 size=0x9
#include "vgui2__EditablePanel.h"
struct EPView { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(int); };
void vgui2::EditablePanel::vfunc58(int a) { ((EPView *)((char *)this + 0x5c))->f4(a); }
// END FUNCTION

// FUNCTION: 0x101b4eb0 size=0x2b
#include "vgui2__EditablePanel.h"
struct V_101b4eb0 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57();
	virtual int v58(int); virtual int v59(int);
};
int vgui2::EditablePanel::vfunc15(int a)
{
	if (a == 1)
		return ((V_101b4eb0 *)this)->v59(0);
	if (a == -1)
		return ((V_101b4eb0 *)this)->v58(0);
	return Panel::vfunc15(0);
}
// END FUNCTION

// FUNCTION: 0x101b4ee0 size=0x51
#include "vgui2__EditablePanel.h"

struct Sub5c {
	virtual vgui2::Panel *v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual vgui2::Panel *v6();
};

typedef vgui2::Panel BasePanel;

// TARGET: vgui2::EditablePanel::vfunc80
void vgui2::EditablePanel::vfunc80()
{
	vgui2::Panel *p = ((Sub5c *)((char *)this + 0x5c))->v6();
	if (p && p != this) {
		p->vfunc15(0);
		((BasePanel *)this)->BasePanel::vfunc80();
		return;
	}
	vgui2::Panel *q = ((Sub5c *)((char *)this + 0x5c))->v0();
	if (q) {
		q->vfunc15(0);
		q->vfunc80();
	}
	((BasePanel *)this)->BasePanel::vfunc80();
}
// END FUNCTION

// FUNCTION: 0x101b4f40 size=0x2b
#include "vgui2__EditablePanel.h"
struct XObj5 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(int); };
// TARGET: vgui2::EditablePanel::vfunc75
void vgui2::EditablePanel::vfunc75(int a)
{
	sub_101ab4e0(a);
	((XObj5 *)m_p58)->v5(a);
	sub_101a9920(&m_i70, &m_i74);
}
// END FUNCTION

// FUNCTION: 0x101b4f70 size=0x2d
#include "vgui2__EditablePanel.h"
struct Sub_101b4f70 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(vgui2::Panel *); };
struct Obj_101b4f70 { char pad[0x5c]; Sub_101b4f70 m_sub; };
struct P48_101b4f70 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual bool v48(); };
void vgui2::EditablePanel::vfunc105(vgui2::Panel *p)
{
	if (!((P48_101b4f70 *)p)->v48())
		((Obj_101b4f70 *)this)->m_sub.v7(p);
	Panel::vfunc105(this);
}
// END FUNCTION

// FUNCTION: 0x101b4ff0 size=0x48
#include "vgui2__EditablePanel.h"
// TARGET: ?vfunc72@EditablePanel@vgui2@@UAEHH@Z
int vgui2::EditablePanel::vfunc72(int a)
{
	for (int i = 0; i < vfunc36(); i++) {
		int r = vfunc37(i)->vfunc72(a);
		if (r)
			return r;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x101b5040 size=0x60
#include "vgui2__EditablePanel.h"
#include "vgui2__KeyValues.h"

void vgui2::EditablePanel::vfunc111(int a, int b)
{
	vgui2::Panel *p = vfunc38(a, 0);
	if (!p)
		return;
	vfunc23(p, new vgui2::KeyValues("SetText", "text", (const char *)b), 0);
}
// END FUNCTION

// FUNCTION: 0x101b50a0 size=0x60
#include "vgui2__EditablePanel.h"
#include "vgui2__KeyValues.h"

void vgui2::EditablePanel::vfunc112(int a, int b)
{
	vgui2::Panel *p = vfunc38(a, 0);
	if (!p)
		return;
	vfunc23(p, new vgui2::KeyValues("SetState", "state", b), 0);
}
// END FUNCTION

// FUNCTION: 0x101b5100 size=0x62
#include "vgui2__EditablePanel.h"
#include "vgui2__KeyValues.h"

struct PCDSlot14 {
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void s6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9() = 0;
    virtual void s10() = 0;
    virtual void s11() = 0;
    virtual void s12() = 0;
    virtual void s13() = 0;
    virtual bool s14(vgui2::KeyValues *data) = 0;
};

// TARGET: vgui2::EditablePanel::vfunc113
int vgui2::EditablePanel::vfunc113(int name, int defaultState)
{
    vgui2::Panel *control = vfunc38(name, 0);
    if (control)
    {
        vgui2::KeyValues *data = new vgui2::KeyValues("GetState");
        if (((PCDSlot14 *)control)->s14(data))
            return data->vfunc9("state", defaultState);
    }
    return defaultState;
}
// END FUNCTION

// FUNCTION: 0x101b5170 size=0x24
#include "vgui2__EditablePanel.h"
namespace lifted {
extern char g_10679a00;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual int f114(int, int, int, int); };
}
int vgui2::EditablePanel::vfunc115(int a0, int a1)
{
    ((lifted::V *)this)->f114(a0, (int)&lifted::g_10679a00, 0x1ff, a1);
    return (int)&lifted::g_10679a00;
}
// END FUNCTION

// FUNCTION: 0x101b51a0 size=0x8c
#include "vgui2__EditablePanel.h"
#include "vgui2__KeyValues.h"
#include <string.h>
struct KVView {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10();
	virtual const char *GetString(const char *, const char *);
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
	virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
	virtual void Release();
};
struct PView {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
	virtual bool Req(KVView *);
};
void vgui2::EditablePanel::vfunc114(const char *name, char *dest, int len, const char *def)
{
	PView *p = (PView *)vfunc38((int)name, 0);
	KVView *kv = (KVView *)new vgui2::KeyValues("GetText");
	if (p && p->Req(kv))
		strncpy(dest, kv->GetString("text", def), len - 1);
	else
		strncpy(dest, def, len - 1);
	dest[len - 1] = 0;
	kv->Release();
}
// END FUNCTION

// FUNCTION: 0x101b5230 size=0x3ae
#include "vgui2__EditablePanel.h"
extern "C" int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
void *__cdecl sub_101ac650(unsigned int);

struct VP {
	void *sub_101b1fc0(vgui2::Panel *, const char *, const char *);
	void *sub_101b3630(vgui2::Panel *, const char *, const char *);
	void *sub_101ba810(vgui2::Panel *, const char *, const char *);
	void *sub_101c7820(vgui2::Panel *, const char *, int, int);
	void *sub_101bf420(vgui2::Panel *, const char *);
	void *sub_101c6c10(vgui2::Panel *, const char *, const char *, int, int);
	void *sub_101c6780(const char *, const char *, int);
	void *sub_101c6500(vgui2::Panel *, const char *);
	void *sub_101c5b80(vgui2::Panel *, const char *, const char *);
	void *sub_101beb90(vgui2::Panel *, const char *, int);
	void *sub_101acaa0(vgui2::Panel *, const char *);
	void *sub_101bc310(vgui2::Panel *, const char *, const char *);
	void *sub_101c5920(vgui2::Panel *, const char *);
	void *sub_101c5500(vgui2::Panel *, const char *);
	void *sub_101a9530(vgui2::Panel *, const char *);
	void *sub_101b4660(vgui2::Panel *, const char *);
};

// TARGET: vgui2::EditablePanel::sub_101b5230
vgui2::Panel *vgui2::EditablePanel::sub_101b5230(vgui2::Panel *parent, const char *controlName)
{
	void *p;
	if (!strcmp(controlName, "Label")) {
		p = sub_101ac650(0xb8);
		return p ? (Panel *)((VP *)p)->sub_101b1fc0(parent, 0, "Label") : 0;
	} else if (!strcmp(controlName, "Button")) {
		p = sub_101ac650(0xf0);
		return p ? (Panel *)((VP *)p)->sub_101b3630(parent, 0, "Button") : 0;
	} else if (!strcmp(controlName, "CheckButton")) {
		p = sub_101ac650(0xfc);
		return p ? (Panel *)((VP *)p)->sub_101ba810(parent, 0, "CheckButton") : 0;
	} else if (!strcmp(controlName, "ComboBox")) {
		p = sub_101ac650(0x138);
		return p ? (Panel *)((VP *)p)->sub_101c7820(parent, 0, 5, 1) : 0;
	} else if (!strcmp(controlName, "Menu")) {
		p = sub_101ac650(0x90);
		return p ? (Panel *)((VP *)p)->sub_101bf420(parent, "Menu") : 0;
	} else if (!strcmp(controlName, "MenuItem")) {
		p = sub_101ac650(0x104);
		return p ? (Panel *)((VP *)p)->sub_101c6c10(parent, 0, "MenuItem", 0, 0) : 0;
	} else if (!strcmp(controlName, "MessageBox")) {
		p = sub_101ac650(0xf0);
		return p ? (Panel *)((VP *)p)->sub_101c6780("MessageBox", "MessageBoxText", 0) : 0;
	} else if (!strcmp(controlName, "ProgressBar")) {
		p = sub_101ac650(0x60);
		return p ? (Panel *)((VP *)p)->sub_101c6500(parent, 0) : 0;
	} else if (!strcmp(controlName, "RadioButton")) {
		p = sub_101ac650(0x104);
		return p ? (Panel *)((VP *)p)->sub_101c5b80(parent, 0, "RadioButton") : 0;
	} else if (!strcmp(controlName, "ScrollBar")) {
		p = sub_101ac650(0x70);
		return p ? (Panel *)((VP *)p)->sub_101beb90(parent, 0, 0) : 0;
	} else if (!strcmp(controlName, "TextEntry")) {
		p = sub_101ac650(0x128);
		return p ? (Panel *)((VP *)p)->sub_101acaa0(parent, 0) : 0;
	} else if (!strcmp(controlName, "ToggleButton")) {
		p = sub_101ac650(0xf4);
		return p ? (Panel *)((VP *)p)->sub_101bc310(parent, 0, "ToggleButton") : 0;
	} else if (!strcmp(controlName, "ImagePanel")) {
		p = sub_101ac650(0x60);
		return p ? (Panel *)((VP *)p)->sub_101c5920(parent, "ResourceImagePanel") : 0;
	} else if (!strcmp(controlName, "AnimatingImagePanel")) {
		p = sub_101ac650(0x7c);
		return p ? (Panel *)((VP *)p)->sub_101c5500(parent, 0) : 0;
	} else if (!strcmp(controlName, "Panel")) {
		p = sub_101ac650(0x58);
		return p ? (Panel *)((VP *)p)->sub_101a9530(parent, 0) : 0;
	} else if (!strcmp(controlName, "EditablePanel")) {
		p = sub_101ac650(0x78);
		return p ? (Panel *)((VP *)p)->sub_101b4660(parent, 0) : 0;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x101b5650 size=0x6
#include "vgui2__EditablePanel.h"
namespace lifted {
extern char g_102d8c88;
}
int vgui2::EditablePanel::vfunc102()
{
    return (int)&lifted::g_102d8c88;
}
// END FUNCTION
