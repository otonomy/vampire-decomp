// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1016a760 size=0x5
#include "CTextMessagePanel.h"
int CTextMessagePanel::vfunc7(int a0, int a1, int a2)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1016a770 size=0x1e
#include "CTextMessagePanel.h"

// VC6 writes CTextMessagePanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CTextMessagePanel *pcd_emit_1016a770(const CTextMessagePanel &other) { return new CTextMessagePanel(other); }

// TARGET: ??_GCTextMessagePanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1016a7a0 size=0x88
#include "CTextMessagePanel.h"
struct ABC { int a, b, c, sum; };
struct ISurfV {
	virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
	virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
	virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
	virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31();
	virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39();
	virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(); virtual void f44(); virtual void f45(); virtual void f46(); virtual void f47();
	virtual void f48(); virtual void f49(); virtual void f50(); virtual void f51(); virtual void f52(); virtual void f53(); virtual void f54(); virtual void f55();
	virtual void f56(); virtual void f57(); virtual void f58(); virtual void f59(); virtual void f60(); virtual void f61(); virtual void f62();
	virtual int SetFont(int font);
	virtual void GetCharABCwide(int font, int ch, int *a, int *b, int *c);
};
extern ISurfV *sub_101ac8d0();
int CTextMessagePanel::vfunc113(ABC *table, int font)
{
	if (!font) {
		font = *(int *)((char *)this + 0x58);
		if (!font)
			return 0;
	}
	if (table) {
		for (int i = 0; i < 256; i++) {
			int a, b, c;
			sub_101ac8d0()->GetCharABCwide(font, (char)i, &a, &b, &c);
			table[i].a = a;
			table[i].b = b;
			table[i].c = c;
			table[i].sum = a + b + c;
		}
	}
	return sub_101ac8d0()->SetFont(font);
}
// END FUNCTION

// FUNCTION: 0x1016a8c0 size=0x20
#include "CTextMessagePanel.h"
namespace lifted {
int sub_1016a870();
}
int CTextMessagePanel::vfunc107(int a0, int a1)
{
    int t0 = lifted::sub_1016a870();
    if (t0 != 0) {
        *(int *)((char *)t0) = 1;
        *(int *)((char *)t0 + 8) = a0;
        *(int *)((char *)t0 + 0xc) = a1;
    }
    return t0;
}
// END FUNCTION

// FUNCTION: 0x1016a8e0 size=0x35
#include "CTextMessagePanel.h"
namespace lifted {
int sub_1016a870();
}
int CTextMessagePanel::vfunc108(int a0, int a1, int a2, int a3, char a4)
{
    int t0 = lifted::sub_1016a870();
    if (t0 != 0) {
        *(int *)((char *)t0 + 0x10) = a0;
        *(int *)((char *)t0 + 0x14) = a1;
        *(int *)((char *)t0 + 0x18) = a2;
        *(int *)((char *)t0) = 2;
        *(int *)((char *)t0 + 0x1c) = a3;
        *(char *)((char *)t0 + 0x20) = a4;
    }
    return t0;
}
// END FUNCTION

// FUNCTION: 0x1016a920 size=0x3d
#include "CTextMessagePanel.h"
struct GObj;
struct GTab { void *f[15]; int (__cdecl *f15)(GObj *, int, int); };
struct GObj { GTab *tab; };
struct IObjB { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual int f63(int); };
extern GObj *g_104a5820;
IObjB *sub_101ac8d0();
void CTextMessagePanel::vfunc109(int *a1, int *a2, int a3)
{
	*a1 = g_104a5820->tab->f15(g_104a5820, *(int *)((char *)this + 0x58), a3);
	*a2 = sub_101ac8d0()->f63(*(int *)((char *)this + 0x58));
}
// END FUNCTION

// FUNCTION: 0x1016a960 size=0x23
#include "CTextMessagePanel.h"
namespace lifted {
int sub_1016a870();
}
int CTextMessagePanel::vfunc110(int a0)
{
    *(int *)((char *)this + 0x58) = a0;
    int t0 = lifted::sub_1016a870();
    if (t0 != 0) {
        *(int *)((char *)t0) = 3;
        *(int *)((char *)t0 + 0x24) = *(int *)((char *)this + 0x58);
    }
    return t0;
}
// END FUNCTION

// FUNCTION: 0x1016a990 size=0xd
#include "CTextMessagePanel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual int f110(int); };
}
int CTextMessagePanel::vfunc111()
{
    return ((lifted::V *)this)->f110(*(int *)((char *)this + 0x5c));
}
// END FUNCTION

// FUNCTION: 0x1016a9a0 size=0x15
#include "CTextMessagePanel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual int f112(); };
}
void CTextMessagePanel::vfunc2()
{
    ((lifted::V *)this)->f21(((lifted::V *)this)->f112());
}
// END FUNCTION

// FUNCTION: 0x1016a9c0 size=0xc
struct V_1016a9c0 { int m_unk[0x14060 / 4]; int m_n14060; };
// TARGET: sub_1016a9c0
bool __fastcall sub_1016a9c0(V_1016a9c0 *self)
{
	return self->m_n14060 ? true : false;
}
// END FUNCTION

// FUNCTION: 0x1016a9d0 size=0x13b
#include "CTextMessagePanel.h"
typedef unsigned short wchar_t_;
struct IVSurface_1016a9d0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(int font); virtual void v18(); virtual void v19(int r, int g, int b, int a); virtual void v20(int x, int y); virtual void v21(const wchar_t_ *p, int n); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(int font, int ch, int *a, int *b, int *c); };
struct ILocalize_1016a9d0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(const char *src, wchar_t_ *dst, int n); };
IVSurface_1016a9d0 *sub_101ac8d0();
ILocalize_1016a9d0 *sub_101ac920();
struct TMItem
{
	int m_type;
	TMItem *m_pNext;
	int m_x;
	int m_y;
	int m_r;
	int m_g;
	int m_b;
	int m_a;
	char m_text[4];
	int m_font;
};
struct TMView
{
	char pad[0x58];
	int m_font;
	char pad2[0x14060 - 0x5c];
	TMItem *m_pItems;
	void sub_1016a830();
};
void CTextMessagePanel::vfunc98()
{
	TMView *v = (TMView *)this;
	TMItem *head = 0;
	TMItem *p = v->m_pItems;
	while (p) {
		TMItem *next = p->m_pNext;
		p->m_pNext = head;
		head = p;
		p = next;
	}
	v->m_pItems = head;
	int x = 0;
	int y = 0;
	sub_101ac8d0()->v17(v->m_font);
	for (TMItem *it = head; it; it = it->m_pNext) {
		switch (it->m_type) {
		case 1:
			x = it->m_x;
			y = it->m_y;
			break;
		case 2:
			if (v->m_font) {
				int b, a, c;
				wchar_t_ wch;
				sub_101ac8d0()->v64(v->m_font, it->m_text[0], &a, &b, &c);
				if (it->m_text[0] > 0x20) {
					sub_101ac8d0()->v19(it->m_r, it->m_g, it->m_b, it->m_a);
					sub_101ac8d0()->v20(x, y);
					sub_101ac920()->v7(it->m_text, &wch, 1);
					sub_101ac8d0()->v21(&wch, 1);
				}
				x += a + b + c;
			}
			break;
		case 3:
			v->m_font = it->m_font;
			sub_101ac8d0()->v17(v->m_font);
			break;
		}
	}
	v->sub_1016a830();
}
// END FUNCTION
