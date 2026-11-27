// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101b2080 size=0x1e
#include "vgui2__Label.h"

// VC6 writes vgui2::Label's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::Label *pcd_emit_101b2080(const vgui2::Label &other) { return new vgui2::Label(other); }

// TARGET: ??_GLabel@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101b20a0 size=0xbd
#include "vgui2__Label.h"
extern "C" __declspec(dllimport) void Plat_Free(void *);
struct LabelObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual ~LabelObj(); };
struct LabelView {
	char pad0[0x5c];
	LabelObj *m5c;
	void *m60; int m64; int m68; int m6c; void *m70;
	void *m74; int m78; int m7c; int m80; void *m84;
	char pad88[0x20];
	void *ma8;
};
vgui2::Label::~Label()
{
	LabelView *v = (LabelView *)this;
	if (v->m5c)
		delete v->m5c;
	if (v->ma8)
		::operator delete(v->ma8);
	v->m80 = 0;
	if (v->m7c != -1) {
		if (v->m74) {
			Plat_Free(v->m74);
			v->m74 = 0;
		}
		v->m78 = 0;
	}
	v->m84 = v->m74;
	if (v->m7c != -1) {
		if (v->m74) {
			Plat_Free(v->m74);
			v->m74 = 0;
		}
		v->m78 = 0;
	}
	v->m6c = 0;
	if (v->m68 != -1) {
		if (v->m60) {
			Plat_Free(v->m60);
			v->m60 = 0;
		}
		v->m64 = 0;
	}
	v->m70 = v->m60;
	if (v->m68 != -1) {
		if (v->m60) {
			Plat_Free(v->m60);
			v->m60 = 0;
		}
		v->m64 = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x101b2230 size=0x23
#include "vgui2__Label.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
void vgui2::Label::vfunc117(int a0)
{
    if ((*(int *)((char *)this + 0xa0)) != a0) {
        *(int *)((char *)this + 0xa0) = a0;
        ((lifted::V *)this)->f57(0, 1);
    }
}
// END FUNCTION

// FUNCTION: 0x101b2260 size=0xbc
#include "vgui2__Label.h"
struct IObj101b2260 {
    virtual void v0();
    virtual void v1();
    virtual void GetSize(int *a, int *b);
    virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31();
    virtual void GetSize2(int *a, int *b);
};
struct LabelView101b2260 {
    char pad0[0x5c];
    IObj101b2260 *m5c;
    char pad1[0x74 - 0x60];
    short *m74;
    char pad2[0x80 - 0x78];
    int m80;
    char pad3[0x88 - 0x84];
    int m88;
    int m8c;
};

void vgui2::Label::vfunc110(int *wide, int *tall)
{
    LabelView101b2260 *v = (LabelView101b2260 *)this;
    int left, top, right, bottom;
    int a, b;
    vfunc131(&left, &right, &top, &bottom);
    *wide = v->m88 - left + top;
    v->m5c->GetSize(&a, &b);
    *wide -= a;
    v->m5c->GetSize2(&a, &b);
    *wide += a;
    for (int i = 0; i < v->m80; i++)
        *wide += v->m74[i];
    *tall = v->m8c - right + bottom;
}
// END FUNCTION

// FUNCTION: 0x101b2320 size=0x4a
extern "C" int isalnum(int);
extern "C" int tolower(int);
unsigned short __stdcall sub_101b2320(const char *text) {
 const char *p = text;
 const char *&r = p;
 if (*r) {
  do {
   if (*r == '&') {
    char c = *++r;
    if (c != '&') {
     if (!c) return 0;
     if (isalnum(c)) return tolower(*r);
    }
   }
  } while (*++r);
 }
 return 0;
}
// END FUNCTION

// FUNCTION: 0x101b2370 size=0x17
#include "vgui2__Label.h"
// TARGET: vgui2::Label::vfunc72
int vgui2::Label::vfunc72(int a)
{
	return (*(short *)((char *)this + 0xac) == (short)a) ? (int)this : 0;
}
// END FUNCTION

// FUNCTION: 0x101b2390 size=0xf
#include "vgui2__Label.h"
short vgui2::Label::vfunc120(short a0)
{
    *(short *)((char *)this + 0xac) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101b23a0 size=0x12
#include "vgui2__Label.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual int f15(int); };
}
void vgui2::Label::vfunc134()
{
    if ((*(int *)((char *)this + 0xa4)) != 0) {
        ((lifted::V *)(*(int *)((char *)this + 0xa4)))->f15(0);
    }
}
// END FUNCTION

// FUNCTION: 0x101b23c0 size=0x1a
#include "vgui2__Label.h"
struct Sub23c0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(int a); };
void vgui2::Label::vfunc87(int a) { Sub23c0 *p = *(Sub23c0 **)((char *)this + 0xa4); if (p) p->v15(0); }
// END FUNCTION

// FUNCTION: 0x101b23e0 size=0x8
#include "vgui2__Label.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual int f28(); };
}
int vgui2::Label::vfunc109()
{
    return ((lifted::V *)(*(int *)((char *)this + 0x5c)))->f28();
}
// END FUNCTION

// FUNCTION: 0x101b23f0 size=0x35
#include "vgui2__Label.h"
struct TextView {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
 virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
 virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
 virtual void s24(); virtual void s25(); virtual void s26();
 virtual void Slot27(const char *text);
};
// TARGET: vgui2::Label::vfunc108
void vgui2::Label::vfunc108(const char *text)
{
    if (!text)
        text = "";
    ((TextView *)m_unk5c[0])->Slot27(text);
    vfunc120(vfunc130(text));
}
// END FUNCTION

// FUNCTION: 0x101b2430 size=0x1b
#include "vgui2__Label.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual int f26(int); };
}
int vgui2::Label::vfunc107(int a0)
{
    ((lifted::V *)(*(int *)((char *)this + 0x5c)))->f26(a0);
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101b2450 size=0x41
#include "vgui2__Label.h"
struct CUnknown101b9d50 { void sub_101b9d50(int); };
struct LabelView2 {
	char pad[0x5c];
	CUnknown101b9d50 *m5c;
	char pad2[0x88 - 0x60];
	int m88;
	int m8c;
};
// TARGET: ?vfunc112@Label@vgui2@@UAEXHH@Z
void vgui2::Label::vfunc112(int w, int h)
{
	LabelView2 *v = (LabelView2 *)this;
	v->m88 = w;
	v->m8c = h;
	sub_101a9920(&w, &h);
	v->m5c->sub_101b9d50(w - v->m88);
}
// END FUNCTION

// FUNCTION: 0x101b24b0 size=0x151
#include "vgui2__Label.h"

struct IImage131 { virtual void v0(); virtual void v1(); virtual void GetSize(int *, int *); };

struct LabelMem131
{
	void *vptr;
	char m_pad4[0x54];
	int m_align;	// 0x58
	int m_5c;
	IImage131 **m_images;	// 0x60
	int m_64;
	int m_68;
	int m_nImages;	// 0x6c
	int m_70;
	short *m_pSpacing;	// 0x74
};

// TARGET: vgui2::Label::vfunc131
void vgui2::Label::vfunc131(int *pX, int *pY, int *pW, int *pH)
{
	LabelMem131 *p = (LabelMem131 *)this;
	int wide, tall;
	vfunc65(wide, tall);
	*pX = 0;
	*pY = 0;
	int x = 0;
	int y = 0;
	int align = p->m_align;
	for (int i = 0; i < p->m_nImages; i++) {
		IImage131 *img = p->m_images[i];
		if (img) {
			int w, h;
			img->GetSize(&w, &h);
			if (y <= h)
				y = h;
			x += p->m_pSpacing[i] + w;
		}
	}
	switch (align) {
	case 0: case 3: case 6:
		*pX = 0;
		break;
	case 1: case 4: case 7:
		*pX = (wide - x) / 2;
		break;
	case 2: case 5: case 8:
		*pX = wide - x;
		break;
	}
	switch (p->m_align) {
	case 0: case 1: case 2:
		*pY = 0;
		break;
	case 3: case 4: case 5:
		*pY = (tall - y) / 2;
		break;
	case 6: case 7: case 8:
		*pY = tall - y;
		break;
	}
	*pW = *pX + x;
	*pH = *pY + y;
}
// END FUNCTION

// FUNCTION: 0x101b2610 size=0x26e
#include "vgui2__Label.h"

struct IImage_101b2610
{
	virtual void Paint();
	virtual void SetPos(int x, int y);
	virtual void GetSize(int &wide, int &tall);
	virtual void SetColor(int col);
};

struct TextImage_101b2610 : public IImage_101b2610
{
	char m_pad04[0x30 - 4];
	bool m_b30;
};

struct ISurface_101b2610
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22();
	virtual void DrawFlushText();
};
ISurface_101b2610 *sub_101ac8d0();

extern int (*g_102d8860[])[2];
extern int g_10250470[];

#pragma pack(push, 1)
struct LabelView_101b2610
{
	char m_pad00[0x5c];
	TextImage_101b2610 *_textImage;	// 0x5c
	IImage_101b2610 **_images;	// 0x60
	int m_i64;
	int m_i68;
	int _imageCount;	// 0x6c
	int m_i70;
	short *_offsets;	// 0x74
	char m_pad78[0x88 - 0x78];
	int _textInset[2];	// 0x88
	int _disabledFgColor1;	// 0x90
	int _disabledFgColor2;	// 0x94
	int _associateColor;	// 0x98
	char m_pad9c[0xa4 - 0x9c];
	vgui2::Panel *_associate;	// 0xa4
	char *_associateName;	// 0xa8
	char m_padac[2];
	int m_shadowColor;	// 0xae
	char m_padb2[2];
	int m_nShadow;	// 0xb4
};
#pragma pack(pop)

void vgui2::Label::vfunc98()
{
	LabelView_101b2610 *v = (LabelView_101b2610 *)this;
	int tx0, ty0, tx1, ty1;
	vfunc131(&tx0, &ty0, &tx1, &ty1);

	if (v->_associateName)
	{
		vfunc121((int)((vgui2::Panel *)vfunc31())->vfunc38((int)v->_associateName, 0));
		delete v->_associateName;
		v->_associateName = 0;
	}

	int labelWide, labelTall;
	sub_101a9920(&labelWide, &labelTall);
	int x = v->_textInset[0] + tx0;
	int y = v->_textInset[1] + ty0;

	for (int i = 0; i < v->_imageCount; i++)
	{
		IImage_101b2610 *image = v->_images[i];
		if (!image)
			continue;
		x += v->_offsets[i];
		image->SetPos(x, y);
		if (image == v->_textImage)
		{
			if (vfunc47())
			{
				if (v->m_nShadow > 0)
				{
					int n = v->m_nShadow;
					if (n > 3)
						n = 3;
					int (*offs)[2] = g_102d8860[n];
					int count = g_10250470[n];
					v->_textImage->SetColor(v->m_shadowColor);
					bool bSave = v->_textImage->m_b30;
					v->_textImage->m_b30 = false;
					for (int j = 0; j < count; j++)
					{
						v->_textImage->SetPos(offs[j][0] + x, offs[j][1] + y);
						v->_textImage->Paint();
					}
					v->_textImage->m_b30 = bSave;
				}
				if (v->_associate && v->_associate->vfunc56())
				{
					v->_textImage->SetColor(v->_associateColor);
				}
				else
				{
					int col;
					v->_textImage->SetColor(*(int *)vfunc53((int)&col));
				}
				v->_textImage->SetPos(x, y);
				v->_textImage->Paint();
			}
			else
			{
				v->_textImage->SetPos(x + 1, y + 1);
				v->_textImage->SetColor(v->_disabledFgColor1);
				v->_textImage->Paint();
				sub_101ac8d0()->DrawFlushText();
				v->_textImage->SetPos(x, y);
				v->_textImage->SetColor(v->_disabledFgColor2);
				v->_textImage->Paint();
			}
		}
		else
		{
			image->Paint();
		}
		int wide, tall;
		image->GetSize(wide, tall);
		x += wide;
	}
}
// END FUNCTION

// FUNCTION: 0x101b2880 size=0xc6
#include "vgui2__Label.h"
struct ISurfV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void DrawLine(int x0, int y0, int x1, int y1);
};
int sub_101ac8d0();
// TARGET: ?vfunc133@Label@vgui2@@UAEXHHHHHH@Z
void vgui2::Label::vfunc133(int x0, int y0, int x1, int y1, int dashLen, int gapLen)
{
	if ((x1 - x0) > (y1 - y0))
	{
		for (;;)
		{
			if (x0 + dashLen > x1)
				((ISurfV *)sub_101ac8d0())->DrawLine(x0, y0, x1, y1);
			else
				((ISurfV *)sub_101ac8d0())->DrawLine(x0, y0, x0 + dashLen, y1);
			x0 += dashLen;
			if (x0 + gapLen > x1)
				break;
			x0 += gapLen;
		}
	}
	else
	{
		for (;;)
		{
			if (y0 + dashLen > y1)
				((ISurfV *)sub_101ac8d0())->DrawLine(x0, y0, x1, y1);
			else
				((ISurfV *)sub_101ac8d0())->DrawLine(x0, y0, x1, y0 + dashLen);
			y0 += dashLen;
			if (y0 + gapLen > y1)
				break;
			y0 += gapLen;
		}
	}
}
// END FUNCTION

// FUNCTION: 0x101b2950 size=0xf
#include "vgui2__Label.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); };
}
int vgui2::Label::vfunc111(int a0)
{
    *(int *)((char *)this + 0x58) = a0;
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101b2960 size=0x30
#include "vgui2__Label.h"
// TARGET: vgui2::Label::vfunc129
void vgui2::Label::vfunc129()
{
	int w, h;
	vfunc110(&w, &h);
	((Panel *)this)->sub_101a98f0(w, h);
}
// END FUNCTION

// FUNCTION: 0x101b2990 size=0x1b
#include "vgui2__Label.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual int f30(int); };
}
void vgui2::Label::vfunc118(int a0)
{
    ((lifted::V *)(*(int *)((char *)this + 0x5c)))->f30(a0);
    ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101b29b0 size=0x24
#include "vgui2__Label.h"
namespace lifted {
struct C101aa090 { int sub_101aa090(int, int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
void vgui2::Label::vfunc11(int a0, int a1)
{
    ((lifted::V *)this)->f57(0, 0);
    ((lifted::C101aa090 *)this)->sub_101aa090(a0, a1);
}
// END FUNCTION

// FUNCTION: 0x101b29e0 size=0x8
#include "vgui2__Label.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual int f31(); };
}
int vgui2::Label::vfunc119()
{
    return ((lifted::V *)(*(int *)((char *)this + 0x5c)))->f31();
}
// END FUNCTION

// FUNCTION: 0x101b29f0 size=0x52
#include "vgui2__Label.h"
#include "vgui2__Panel.h"

typedef vgui2::Panel BasePanel;

struct C4 {
	unsigned char r, g, b, a;
	bool operator!=(const C4 &o) const
	{
		return r != o.r || g != o.g || b != o.b || a != o.a;
	}
};

struct Sub5c {
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3(int);
};

// TARGET: vgui2::Label::vfunc51
int vgui2::Label::vfunc51(int color)
{
	C4 cur;
	C4 *p = (C4 *)vfunc53((int)&cur);
	if (*p != *(C4 *)&color) {
		((BasePanel *)this)->BasePanel::vfunc51(color);
		(*(Sub5c **)((char *)this + 0x5c))->v3(color);
		return vfunc6();
	}
	return (int)p;
}
// END FUNCTION

// FUNCTION: 0x101b2a50 size=0x19
#include "vgui2__Label.h"
int vgui2::Label::vfunc53(int p) { int t; Panel::vfunc53((int)&t); *(int *)p = t; return p; }
// END FUNCTION

// FUNCTION: 0x101b2a70 size=0xd
#include "vgui2__Label.h"
int vgui2::Label::vfunc113(int a0)
{
    *(int *)((char *)this + 0x90) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101b2a80 size=0xd
#include "vgui2__Label.h"
int vgui2::Label::vfunc114(int a0)
{
    *(int *)((char *)this + 0x94) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101b2a90 size=0xf
#include "vgui2__Label.h"
int vgui2::Label::vfunc115(int a0)
{
    *(int *)((char *)a0) = *(int *)((char *)this + 0x90);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101b2aa0 size=0xf
#include "vgui2__Label.h"
int vgui2::Label::vfunc116(int a0)
{
    *(int *)((char *)a0) = *(int *)((char *)this + 0x94);
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101b2ab0 size=0x4
#include "vgui2__Label.h"
int vgui2::Label::vfunc127()
{
    return *(int *)((char *)this + 0x5c);
}
// END FUNCTION

// FUNCTION: 0x101b2ac0 size=0x72
#include "vgui2__Label.h"
#include <string.h>

struct KVView
{
    virtual const char *GetName();
    virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
    virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
    virtual void s13();
    virtual void SetString(const char *, const char *);
};

struct TextViewV
{
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(char *buf, int len);
};

struct PanelImpl
{
    bool sub_101ac540(vgui2::KeyValues *data);
};

bool vgui2::Label::vfunc14(vgui2::KeyValues *data)
{
    KVView *kv = (KVView *)data;
    if (!strcmp(kv->GetName(), "GetText"))
    {
        char buf[256];
        TextViewV *tv = (TextViewV *)(*(int *)((char *)this + 0x5c));
        tv->s28(buf, 255);
        kv->SetString("text", buf);
        return true;
    }
    return ((PanelImpl *)this)->sub_101ac540(data);
}
// END FUNCTION

// FUNCTION: 0x101b2b40 size=0x8
#include "vgui2__Label.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual int f108(); };
}
int vgui2::Label::vfunc132()
{
    return ((lifted::V *)this)->f108();
}
// END FUNCTION

// FUNCTION: 0x101b2b50 size=0xcf
#include "utlvector.h"
#include "vgui2__Label.h"

struct CUtlMemoryInt
{
	int *m_pMemory;
	int m_nAllocationCount;
	int m_nGrowSize;
	void sub_101b3480(int num);
	void Grow(int num) { sub_101b3480(num); }
	int NumAllocated() const { return m_nAllocationCount; }
	int *Base() { return m_pMemory; }
	int &operator[](int i) { return m_pMemory[i]; }
};

struct CUtlMemoryShort
{
	short *m_pMemory;
	int m_nAllocationCount;
	int m_nGrowSize;
	void sub_101b34f0(int num);
	void Grow(int num) { sub_101b34f0(num); }
	int NumAllocated() const { return m_nAllocationCount; }
	short *Base() { return m_pMemory; }
	short &operator[](int i) { return m_pMemory[i]; }
};

struct LabelVecView
{
	char m_pad00[0x60];
	CUtlVector<int, CUtlMemoryInt> m_vecA;		// 0x60
	CUtlVector<short, CUtlMemoryShort> m_vecB;	// 0x74
};

int vgui2::Label::vfunc122(void *a, int b)
{
	LabelVecView *v = (LabelVecView *)this;
	v->m_vecB.AddToTail((short)b);
	vfunc57(0, 0);
	return v->m_vecA.AddToTail((int)a);
}
// END FUNCTION

// FUNCTION: 0x101b2c20 size=0x4f
#include "vgui2__Label.h"

struct LabelView_123 {
	char pad00[0x60];
	int *m60;
	char pad64[0x74 - 0x64];
	short *m74;
};

void vgui2::Label::vfunc123(int index, int value, int value2)
{
	LabelView_123 *v = (LabelView_123 *)this;
	vfunc135(index);
	if (v->m60[index] != value || v->m74[index] != value2)
	{
		v->m60[index] = value;
		v->m74[index] = value2;
		vfunc57(0, 0);
	}
}
// END FUNCTION

// FUNCTION: 0x101b2c70 size=0xd
struct CView { char pad[0x60]; int *m60; int sub_101b2c70(int); };
// TARGET: ?sub_101b2c70@CView@@QAEHH@Z
int CView::sub_101b2c70(int i) { return m60[i]; }
// END FUNCTION

// FUNCTION: 0x101b2c80 size=0x4
#include "vgui2__Label.h"
int vgui2::Label::vfunc126()
{
    return *(int *)((char *)this + 0x6c);
}
// END FUNCTION

// FUNCTION: 0x101b2cd0 size=0xe4
#include "vgui2__Label.h"
#include "UtlMem.h"

extern "C" void *__cdecl memmove(void *, const void *, unsigned int);

class Mem2 {
public:
	void sub_101b34f0(int num);
};

struct VecInt5 {
	int *m_pMemory;
	int m_alloc;
	int m_grow;
	int m_size;
	int *m_pElems;
};

struct VecShort5 {
	short *m_pMemory;
	int m_alloc;
	int m_grow;
	int m_size;
	short *m_pElems;
};

// TARGET: vgui2::Label::vfunc135
void vgui2::Label::vfunc135(int index)
{
	while (*(int *)((char *)this + 0x6c) <= index) {
		VecInt5 *v = (VecInt5 *)((char *)this + 0x60);
		int elem = v->m_size;
		if (v->m_size + 1 > v->m_alloc)
			((UtlMem *)v)->sub_101b3480(v->m_size + 1 - v->m_alloc);
		v->m_size += 1;
		v->m_pElems = v->m_pMemory;
		int numToMove = v->m_size - elem - 1;
		if (numToMove > 0)
			memmove(&v->m_pMemory[elem + 1], &v->m_pMemory[elem], numToMove * 4);
		int *p = v->m_pMemory + elem;
		if (p)
			*p = 0;
	}

	while (*(int *)((char *)this + 0x80) <= index) {
		VecShort5 *w = (VecShort5 *)((char *)this + 0x74);
		int elem = w->m_size;
		if (w->m_size + 1 > w->m_alloc)
			((Mem2 *)w)->sub_101b34f0(w->m_size + 1 - w->m_alloc);
		w->m_size += 1;
		w->m_pElems = w->m_pMemory;
		int numToMove = w->m_size - elem - 1;
		if (numToMove > 0)
			memmove(&w->m_pMemory[elem + 1], &w->m_pMemory[elem], numToMove * 2);
		short *p = w->m_pMemory + elem;
		if (p)
			*p = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x101b2dc0 size=0x42
#include "vgui2__Label.h"
// TARGET: vgui2::Label::vfunc124
void vgui2::Label::vfunc124(int idx, int val) {
	if (idx >= 0 && idx < m_h80) {
		short *p = &((short *)m_i74)[idx];
		if (*p != val) {
			*p = val;
			vfunc57(0, 0);
		}
	}
}
// END FUNCTION

// FUNCTION: 0x101b2e10 size=0x1e
#include "vgui2__Label.h"
int vgui2::Label::vfunc121(int a0)
{
    if (a0 != ((int)this)) {
        *(int *)((char *)this + 0xa4) = a0;
        return a0;
    }
    *(int *)((char *)this + 0xa4) = 0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101b2e30 size=0x2a
#include "vgui2__Label.h"
struct V_101b2e30 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(void *); };
void vgui2::Label::vfunc105(vgui2::Panel *p)
{
	V_101b2e30 *w = *(V_101b2e30 **)((char *)this + 0xa4);
	if (w && p == this)
		w->v15(0);
	else
		Panel::vfunc105(p);
}
// END FUNCTION

// FUNCTION: 0x101b2e60 size=0x10b
#include "vgui2__Label.h"
#pragma warning(disable: 4716)
struct Color { unsigned int rgba; Color() {} };
struct IScheme_101b2e60 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual Color GetColor(const char *name); };
struct LabelView
{
	char pad0[0x60];
	void **m_pImages;
	int pad64; int pad68;
	int m_nImages;
	char pad70[0x98 - 0x70];
	unsigned int m_AssociateColor;
	int m_nTextImageIndex;
	int m_nTextColorState;
};
#define LV ((LabelView *)this)
// TARGET: vgui2::Label::vfunc74
int vgui2::Label::vfunc74(int pSchemeArg)
{
	IScheme_101b2e60 *pScheme = (IScheme_101b2e60 *)pSchemeArg;
	Panel::vfunc74(pSchemeArg);
	for (int i = 0; i < LV->m_nImages; i++)
	{
		if (!LV->m_pImages[i])
			continue;
		if (i == LV->m_nTextImageIndex)
			continue;
		LV->m_pImages[i] = 0;
	}
	vfunc113(pScheme->GetColor("DisabledFgColor1").rgba);
	vfunc114(pScheme->GetColor("DisabledFgColor2").rgba);
	vfunc50(pScheme->GetColor("LabelBgColor").rgba);
	switch (LV->m_nTextColorState)
	{
	case 1:
		vfunc51(pScheme->GetColor("LabelDimText").rgba);
		break;
	case 2:
		vfunc51(pScheme->GetColor("BrightControlText").rgba);
	default:
		vfunc51(pScheme->GetColor("BrightBaseText").rgba);
		break;
	}
	LV->m_AssociateColor = pScheme->GetColor("BrightControlText").rgba;
}
// END FUNCTION

// FUNCTION: 0x101b2f70 size=0x118
#include "vgui2__Label.h"
#include "vgui2__KeyValues.h"
#define V10(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); \
	virtual void p##5(); virtual void p##6(); virtual void p##7(); virtual void p##8(); virtual void p##9();
struct TextImageView { V10(a) V10(b) virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7(); virtual void c8(); virtual void GetText(char *buf, int n); };
void vgui2::Label::sub_101b2f70(int a)
{
	vgui2::KeyValues *kv = (vgui2::KeyValues *)a;
	Panel::sub_101ab750(a);
	char buf[256];
	(*(TextImageView **)((char *)this + 0x5c))->GetText(buf, 255);
	kv->vfunc14("labelText", buf);
	const char *s;
	switch (*(int *)((char *)this + 0x58))
	{
	case 0: s = "north-west"; break;
	case 1: s = "north"; break;
	case 2: s = "north-east"; break;
	case 4: s = "center"; break;
	case 5: s = "east"; break;
	case 6: s = "south-west"; break;
	case 7: s = "south"; break;
	case 8: s = "south-east"; break;
	case 3:
	default: s = "west"; break;
	}
	kv->vfunc14("textAlignment", s);
	if (m_pA4)
		kv->vfunc14("associate", m_pA4->vfunc18());
	kv->vfunc15((int)"dulltext", *(int *)((char *)this + 0xa0) == 1);
	kv->vfunc15((int)"brighttext", *(int *)((char *)this + 0xa0) == 2);
}
// END FUNCTION

// FUNCTION: 0x101b3090 size=0x1f9
#include "vgui2__Label.h"
extern "C" int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
extern "C" unsigned int strlen(const char *);
#pragma intrinsic(strlen)

struct KVV {
	virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4();
	virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8();
	virtual int GetInt(const char *, int);
	virtual void p10();
	virtual const char *GetString(const char *, const char *);
};

// TARGET: vgui2::Label::vfunc75
void vgui2::Label::vfunc75(int data)
{
	KVV *kv = (KVV *)data;
	Panel::vfunc75(data);
	const char *labelText = kv->GetString("labelText", 0);
	if (labelText)
		vfunc108(labelText);
	const char *alignmentString = kv->GetString("textAlignment", "");
	int align = -1;
	if (!strcmp(alignmentString, "north-west")) {
		align = 0;
	} else if (!strcmp(alignmentString, "north")) {
		align = 1;
	} else if (!strcmp(alignmentString, "north-east")) {
		align = 2;
	} else if (!strcmp(alignmentString, "west")) {
		align = 3;
	} else if (!strcmp(alignmentString, "center")) {
		align = 4;
	} else if (!strcmp(alignmentString, "east")) {
		align = 5;
	} else if (!strcmp(alignmentString, "south-west")) {
		align = 6;
	} else if (!strcmp(alignmentString, "south")) {
		align = 7;
	} else if (!strcmp(alignmentString, "south-east")) {
		align = 8;
	}
	if (align != -1)
		vfunc111(align);
	const char *associateName = kv->GetString("associate", "");
	if (associateName[0] != 0) {
		char *p = new char[strlen(associateName) + 1];
		*(char **)((char *)this + 0xa8) = p;
		const char *s = associateName;
		char *d = p;
		char c;
		do {
			c = *s;
			s++;
			*d = c;
			d++;
		} while (c);
	}
	if (kv->GetInt("dulltext", 0) == 1) {
		vfunc117(1);
	} else if (kv->GetInt("brighttext", 0) == 1) {
		vfunc117(2);
	} else {
		vfunc117(0);
	}
	vfunc57(1, 0);
}
// END FUNCTION

// FUNCTION: 0x101b3290 size=0x23
#include "vgui2__Label.h"
namespace lifted {
extern char g_102d89c8;
extern char g_10679200;
int sub_101ab860();
int sub_101d3192(int, int, int, int);
}
int vgui2::Label::vfunc77()
{
    lifted::sub_101d3192((int)&lifted::g_10679200, 0x400, (int)&lifted::g_102d89c8, lifted::sub_101ab860());
    return (int)&lifted::g_10679200;
}
// END FUNCTION

// FUNCTION: 0x101b32c0 size=0xda
#include "vgui2__Label.h"

class TIV_101b32c0
{
public:
	virtual void v0();
	virtual void v1();
	virtual int v2(int *a, int *b);	// slot 2
	virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
	virtual void v7(); virtual void v8();
	virtual int v9(int a, int b);	// slot 9
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
	virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
	virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
	virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
	virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31();
	virtual int v32(int *a, int *b);	// slot 32
};

struct LabelView_101b32c0
{
	char m_pad0[0x5c];
	TIV_101b32c0 *m_pImage;		// 0x5c
	TIV_101b32c0 **m_pLines;	// 0x60
	char m_pad64[0x6c - 0x64];
	int m_nLines;				// 0x6c
	char m_pad70[0x88 - 0x70];
	int m_nInset;				// 0x88
	char m_pad8c[0x9c - 0x8c];
	int m_nSkip;				// 0x9c
};

// TARGET: vgui2::Label::vfunc101
void vgui2::Label::vfunc101()
{
	LabelView_101b32c0 *v = (LabelView_101b32c0 *)this;
	int wide, tall;
	sub_101a9920(&wide, &tall);
	wide = wide - v->m_nInset;

	if ( v->m_nLines == 1 )
	{
		int imgW, imgH;
		v->m_pImage->v32(&imgW, &imgH);
		if ( wide < imgW )
			v->m_pImage->v9(wide, imgH);
		else
			v->m_pImage->v9(imgW, imgH);
		return;
	}

	int sum = 0;
	for ( int i = 0; i < v->m_nLines; i++ )
	{
		TIV_101b32c0 *img = v->m_pLines[i];
		if ( !img )
			continue;
		if ( i == v->m_nSkip )
			continue;
		int a, b;
		img->v2(&a, &b);
		sum += a;
	}

	int rem = wide - sum;
	if ( rem < 0 )
		return;

	int a, b;
	v->m_pImage->v2(&a, &b);
	v->m_pImage->v9(rem, b);
}
// END FUNCTION

// FUNCTION: 0x101b33a0 size=0xd
#include "vgui2__Label.h"
int vgui2::Label::vfunc136(int a0)
{
    *(int *)((char *)this + 0xb4) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101b33b0 size=0x7
#include "vgui2__Label.h"
int vgui2::Label::vfunc137()
{
    return *(int *)((char *)this + 0xb4);
}
// END FUNCTION

// FUNCTION: 0x101b3470 size=0x6
#include "vgui2__Label.h"
namespace lifted {
extern char g_102d88f0;
}
int vgui2::Label::vfunc102()
{
    return (int)&lifted::g_102d88f0;
}
// END FUNCTION
