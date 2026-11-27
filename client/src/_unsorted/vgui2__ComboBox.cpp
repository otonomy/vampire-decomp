// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101c78f0 size=0x1e
#include "vgui2__ComboBox.h"

// VC6 writes vgui2::ComboBox's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::ComboBox *pcd_emit_101c78f0(const vgui2::ComboBox &other) { return new vgui2::ComboBox(other); }

// TARGET: ??_GComboBox@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101c7910 size=0x33
#include "vgui2__ComboBox.h"
vgui2::ComboBox::~ComboBox()
{
	vgui2::Panel *a = *(vgui2::Panel **)((char *)this + 0x12c);
	if (a)
		delete a;
	vgui2::Panel *b = *(vgui2::Panel **)((char *)this + 0x130);
	if (b)
		delete b;
}
// END FUNCTION

// FUNCTION: 0x101c7950 size=0xe
#include "vgui2__ComboBox.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual int f127(); };
}
int vgui2::ComboBox::vfunc175()
{
    return ((lifted::V *)(*(int *)((char *)this + 0x12c)))->f127();
}
// END FUNCTION

// FUNCTION: 0x101c7960 size=0x7e
#include "vgui2__ComboBox.h"

#define V4(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d();
#define V16(n) V4(n##a) V4(n##b) V4(n##c) V4(n##d)
struct KVView {
    void *sub_101b5690(const char *name, const char *key, int value);
};
struct ItemListView {
    V16(a) V16(b) V16(c) V16(d) V16(e)
    V4(g) V4(h) V4(i) V4(j) V4(k) V4(l) V4(m)
    virtual void x108(); virtual void x109();
    virtual int AddItem(int text, void *kv, void *panel);
    virtual void x111(); virtual void x112(); virtual void x113(); virtual void x114(); virtual void x115();
    virtual void x116(); virtual void x117(); virtual void x118(); virtual void x119(); virtual void x120();
    virtual void x121(); virtual void x122();
    virtual int InsertItem(int index, int text, void *kv);
};
int sub_101b6840(int size);

// TARGET: vgui2::ComboBox::vfunc176
int vgui2::ComboBox::vfunc176(int text, int index)
{
    if (index == -1) {
        KVView *p = (KVView *)sub_101b6840(0x1c);
        void *kv = p ? p->sub_101b5690("SetText", "text", text) : 0;
        return (*(ItemListView **)((char *)this + 0x12c))->AddItem(text, kv, this);
    }
    KVView *p = (KVView *)sub_101b6840(0x1c);
    void *kv = p ? p->sub_101b5690("SetText", "text", text) : 0;
    return (*(ItemListView **)((char *)this + 0x12c))->InsertItem(index, text, kv);
}
// END FUNCTION

// FUNCTION: 0x101c79e0 size=0xe
#include "vgui2__ComboBox.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual int f125(); };
}
int vgui2::ComboBox::vfunc177()
{
    return ((lifted::V *)(*(int *)((char *)this + 0x12c)))->f125();
}
// END FUNCTION

// FUNCTION: 0x101c79f0 size=0xe
#include "vgui2__ComboBox.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual int f128(); };
}
int vgui2::ComboBox::vfunc181()
{
    return ((lifted::V *)(*(int *)((char *)this + 0x12c)))->f128();
}
// END FUNCTION

// FUNCTION: 0x101c7a00 size=0x11c
#include "vgui2__ComboBox.h"

struct ISurface_101c7a00
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
	virtual void GetScreenSize(int &wide, int &tall); // slot 39 (+0x9c)
};

ISurface_101c7a00 *sub_101ac8d0();

struct CMenuView_101c7a00
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(int); // +0x70
	virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
	virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
	virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
	virtual void v44(); virtual void v45();
	virtual void SetEnabled(bool); // slot 46 (+0xb8)
	virtual bool IsEnabled();      // slot 47 (+0xbc)
	virtual bool v48();            // slot 48 (+0xc0)

	void sub_101a9950(int x, int y, int w, int h);
};

struct CComboBoxView_101c7a00
{
	char pad0[0x12c];
	CMenuView_101c7a00 *m_pDropDown; // 0x12c
	CMenuView_101c7a00 *m_pButton;   // 0x130
};

// TARGET: ?vfunc101@ComboBox@vgui2@@UAEXXZ
void vgui2::ComboBox::vfunc101()
{
	int wide, tall;
	vfunc65(wide, tall);

	TextEntry::vfunc101();

	int screenW, screenH;
	sub_101ac8d0()->GetScreenSize(screenW, screenH);

	CComboBoxView_101c7a00 *v = (CComboBoxView_101c7a00 *)this;
	v->m_pButton->sub_101a9950(
		(int)((wide - tall) + 4.0 * (screenW / 1024.0)),
		(int)(2.0 * (screenH / 768.0)),
		(int)(tall - 2.0 * (screenW / 1024.0)),
		(int)(tall - 2.0 * (screenH / 768.0)));

	if (!v->m_pDropDown->v48())
	{
		v->m_pDropDown->v28(0);
	}

	if (vfunc135())
	{
		vfunc54(3);
	}
	else
	{
		vfunc54(2);
	}

	v->m_pButton->SetEnabled(vfunc47());
}
// END FUNCTION

// FUNCTION: 0x101c7b20 size=0x1
#include "vgui2__ComboBox.h"
void vgui2::ComboBox::vfunc178()
{
}
// END FUNCTION

// FUNCTION: 0x101c7b30 size=0xb
#include "vgui2__ComboBox.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual int f22(); };
}
int vgui2::ComboBox::vfunc180()
{
    return ((lifted::V *)(*(int *)((char *)this + 0x12c)))->f22();
}
// END FUNCTION

// FUNCTION: 0x101c7b40 size=0x2c
#include "vgui2__ComboBox.h"
namespace lifted {
extern char g_102dac58;
int __stdcall sub_101ace00(int);
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual int f3(int); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual int f60(int); };
}
int vgui2::ComboBox::vfunc74(int a0)
{
    lifted::sub_101ace00(a0);
    return ((lifted::V *)this)->f60(((lifted::V *)a0)->f3((int)&lifted::g_102dac58));
}
// END FUNCTION

// FUNCTION: 0x101c7b70 size=0x13
#include "vgui2__ComboBox.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(float); };
}
int vgui2::ComboBox::vfunc179(float a0)
{
    return ((lifted::V *)(*(int *)((char *)this + 0x130)))->f21(a0);
}
// END FUNCTION

// FUNCTION: 0x101c7b90 size=0x70
#include "vgui2__ComboBox.h"
namespace lifted {
struct C101af210 { int sub_101af210(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual int f15(int); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual bool f47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual bool f70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual bool f135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual void u168(); virtual void u169(); virtual void u170(); virtual void u171(); virtual void u172(); virtual void u173(); virtual void u174(); virtual void u175(); virtual void u176(); virtual void u177(); virtual void u178(); virtual void u179(); virtual void u180(); virtual void u181(); virtual int f182(); virtual void u183(); virtual int f184(); };
}
void vgui2::ComboBox::vfunc87(int a0)
{
    if ((*(int *)((char *)this + 0x12c)) != 0) {
        bool t0 = ((lifted::V *)this)->f47();
        if (t0 != 0) {
            bool t1 = ((lifted::V *)this)->f70();
            if (t1 == 0) {
                ((lifted::V *)this)->f182(); return;
            }
            bool t2 = ((lifted::V *)this)->f135();
            if (t2 != 0) {
                ((lifted::C101af210 *)this)->sub_101af210(a0);
                ((lifted::V *)this)->f182(); return;
            }
            ((lifted::V *)this)->f15(0);
            ((lifted::V *)this)->f184();
        }
    }
}
// END FUNCTION

// FUNCTION: 0x101c7c00 size=0x8
#include "vgui2__ComboBox.h"
void vgui2::ComboBox::vfunc88(int a) { vfunc87(a); }
// END FUNCTION

// FUNCTION: 0x101c7c10 size=0x31
#include "vgui2__ComboBox.h"
namespace lifted {
extern char g_102dac48;
struct C101ab3d0 { int sub_101ab3d0(int); };
int sub_101e28e0(int, int);
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual void u168(); virtual void u169(); virtual void u170(); virtual void u171(); virtual void u172(); virtual void u173(); virtual void u174(); virtual void u175(); virtual void u176(); virtual void u177(); virtual void u178(); virtual void u179(); virtual void u180(); virtual void u181(); virtual void u182(); virtual void u183(); virtual int f184(); };
}
void vgui2::ComboBox::vfunc78(int a0)
{
    int t0 = lifted::sub_101e28e0(a0, (int)&lifted::g_102dac48);
    if (t0 == 0) {
        ((lifted::V *)this)->f184();
    }
    ((lifted::C101ab3d0 *)this)->sub_101ab3d0(a0);
}
// END FUNCTION

// FUNCTION: 0x101c7c50 size=0x124
#include "vgui2__ComboBox.h"
#include <string.h>
extern void *sub_101b6840(unsigned int size);
extern "C" int _strcmpi(const char *, const char *);
struct KV_101c7c50 {
	KV_101c7c50 *sub_101b5690(const char *name, const char *key, const char *value);
};
struct Loc_101c7c50 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7();
	virtual void ConvertUnicodeToANSI(const wchar_t *unicode, char *ansi, int ansiBufferSize);
	virtual unsigned short FindIndex(const char *name);
	virtual void v10(); virtual void v11();
	virtual const wchar_t *GetValueByIndex(unsigned short index);
};
extern Loc_101c7c50 *sub_101ac920();
struct View_101c7c50 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5();
	virtual void Slot6();
	virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
	virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
	virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
	virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
	virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
	virtual void v42();
	virtual void PostActionSignal(KV_101c7c50 *msg);
	virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
	virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
	virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
	virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
	virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68();
	virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73();
	virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78();
	virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
	virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88();
	virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93();
	virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98();
	virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
	virtual void v104(); virtual void v105(); virtual void v106();
	virtual void SetText(const char *text);
	virtual void GetText(int idx, char *buf, int bufLen);
	virtual void v109(); virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113();
	virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118();
	virtual void v119(); virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123();
	virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127(); virtual void v128();
	virtual void v129(); virtual void v130(); virtual void v131(); virtual void v132(); virtual void v133();
	virtual void v134(); virtual void v135(); virtual void v136(); virtual void v137(); virtual void v138();
	virtual void v139(); virtual void v140(); virtual void v141(); virtual void v142(); virtual void v143();
	virtual void v144(); virtual void v145(); virtual void v146(); virtual void v147(); virtual void v148();
	virtual void v149(); virtual void v150(); virtual void v151(); virtual void v152(); virtual void v153();
	virtual void v154(); virtual void v155(); virtual void v156(); virtual void v157(); virtual void v158();
	virtual void v159(); virtual void v160(); virtual void v161(); virtual void v162(); virtual void v163();
	virtual void v164(); virtual void v165(); virtual void v166(); virtual void v167(); virtual void v168();
	virtual void v169(); virtual void v170(); virtual void v171(); virtual void v172(); virtual void v173();
	virtual void v174(); virtual void v175(); virtual void v176(); virtual void v177(); virtual void v178();
	virtual void v179(); virtual void v180(); virtual void v181();
	virtual void Slot182();
};
void vgui2::ComboBox::vfunc167(const char *newtext)
{
	char current[256];
	char buf[256];
	const char *text = newtext;
	View_101c7c50 *v = (View_101c7c50 *)this;
	if (newtext[0] == '#')
	{
		int idx = sub_101ac920()->FindIndex(newtext + 1);
		if (idx != 0xffff)
		{
			const wchar_t *w = sub_101ac920()->GetValueByIndex(idx);
			sub_101ac920()->ConvertUnicodeToANSI(w, buf, 255);
			text = buf;
		}
	}
	v->GetText(0, current, 254);
	if (strcmp(current, text) != 0)
	{
		if (!_strcmpi("<All>", newtext))
			text = "";
		v->SetText(text);
		KV_101c7c50 *kv = (KV_101c7c50 *)sub_101b6840(0x1c);
		if (kv)
			kv = kv->sub_101b5690("TextChanged", "text", text);
		else
			kv = 0;
		v->PostActionSignal(kv);
		v->Slot6();
	}
	v->Slot182();
}
// END FUNCTION

// FUNCTION: 0x101c7d80 size=0x2e
#include "vgui2__ComboBox.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual int f5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual void u168(); virtual void u169(); virtual void u170(); virtual void u171(); virtual void u172(); virtual void u173(); virtual int f174(int); };
}
void vgui2::ComboBox::vfunc182()
{
    if ((*(int *)((char *)this + 0x12c)) != 0) {
        ((lifted::V *)(*(int *)((char *)this + 0x12c)))->f21(0);
        ((lifted::V *)this)->f5();
        ((lifted::V *)this)->f174(*(int *)((char *)this + 0x12c));
    }
}
// END FUNCTION

// FUNCTION: 0x101c7dc0 size=0x73
#include "vgui2__ComboBox.h"
namespace lifted {
struct C101b1760 { int sub_101b1760(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual int f15(int); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual bool f56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual bool f70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual int f85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual int f138(int); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual void u168(); virtual void u169(); virtual void u170(); virtual void u171(); virtual void u172(); virtual void u173(); virtual void u174(); virtual void u175(); virtual void u176(); virtual void u177(); virtual void u178(); virtual void u179(); virtual void u180(); virtual void u181(); virtual int f182(); };
}
int vgui2::ComboBox::vfunc183()
{
    ((lifted::V *)this)->f182();
    bool t0 = ((lifted::V *)this)->f56();
    if (t0 != 0) {
        return ((lifted::C101b1760 *)this)->sub_101b1760();
    }
    if ((*(char *)((char *)this + 0x134)) != 0) {
        int t1 = ((lifted::C101b1760 *)this)->sub_101b1760();
        *(char *)((char *)this + 0x134) = 0;
        return t1;
    }
    bool t2 = ((lifted::V *)this)->f70();
    if (t2 != 0) {
        ((lifted::C101b1760 *)this)->sub_101b1760();
        ((lifted::V *)this)->f85();
        return ((lifted::V *)this)->f15(0);
    }
    return ((lifted::V *)(*(int *)((char *)this + 0x130)))->f138(0);
}
// END FUNCTION

// FUNCTION: 0x101c8010 size=0x19
#include "vgui2__ComboBox.h"
namespace lifted {
struct C101af140 { int sub_101af140(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual int f85(); };
}
void vgui2::ComboBox::vfunc85()
{
    ((lifted::V *)(*(int *)((char *)this + 0x130)))->f85();
    ((lifted::C101af140 *)this)->sub_101af140();
}
// END FUNCTION

// FUNCTION: 0x101c8030 size=0x2c
#include "vgui2__ComboBox.h"
struct VA {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual bool v22();
};
struct VB {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
	virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
	virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
	virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
	virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127(); virtual void v128(); virtual void v129();
	virtual void v130(); virtual void v131(); virtual void v132(); virtual void v133(); virtual void v134(); virtual void v135(); virtual void v136(); virtual void v137(); virtual void v138(int a);
};
void vgui2::ComboBox::vfunc86()
{
	if (!(*(VA **)((char *)this + 0x12c))->v22()) {
		(*(VB **)((char *)this + 0x130))->v138(0);
		TextEntry::vfunc86();
	}
}
// END FUNCTION

// FUNCTION: 0x101c8070 size=0x45
#include "vgui2__ComboBox.h"

class CUnknown101b1870
{
public:
	int sub_101b1870(int);
};

struct CTextEntryView
{
	void sub_101ad050(int, int);
};

// TARGET: vgui2::ComboBox::vfunc11
void vgui2::ComboBox::vfunc11(int wide, int tall)
{
	int w = wide;
	((CTextEntryView *)this)->sub_101ad050(wide, tall);
	vfunc101();
	((vgui2::Panel *)*(int *)((char *)this + 0x130))->sub_101a9920(&tall, &wide);
	((CUnknown101b1870 *)this)->sub_101b1870(w - tall);
}
// END FUNCTION

// FUNCTION: 0x101c81b0 size=0x6
#include "vgui2__ComboBox.h"
namespace lifted {
extern char g_102dabf0;
}
int vgui2::ComboBox::vfunc102()
{
    return (int)&lifted::g_102dabf0;
}
// END FUNCTION

// FUNCTION: 0x101c81d0 size=0x3
#include "vgui2__ComboBox.h"
void vgui2::ComboBox::vfunc173(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101c81e0 size=0x3
#include "vgui2__ComboBox.h"
void vgui2::ComboBox::vfunc174(int a0)
{
}
// END FUNCTION
