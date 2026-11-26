// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101b9bc0 size=0x70
#include "vgui2__TextImage.h"

int sub_101ac8c0();

struct ISchemeTmp
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual int GetFont(const char *fontName);
};

struct ISchemeManagerTmp
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual ISchemeTmp *GetIScheme(unsigned long scheme);
};

vgui2::TextImage::TextImage(const char *text, unsigned long scheme)
	: Image()
{
	m_pText = 0;
	m_unk20 = 0;
	m_font = ((ISchemeManagerTmp *)sub_101ac8c0())->GetIScheme(scheme)->GetFont("Default");
	m_unk2c = 0xffff;
	m_unk28 = 0;
	m_unk20 = 0;
	m_unk22 = 0;
	m_unk30 = false;
	m_unk35 = true;
	vfunc27(text);
}
// END FUNCTION

// FUNCTION: 0x101b9c30 size=0x1e
#include "vgui2__TextImage.h"

// VC6 writes vgui2::TextImage's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::TextImage *pcd_emit_101b9c30(const vgui2::TextImage &other) { return new vgui2::TextImage(other); }

// TARGET: ??_GTextImage@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101b9c50 size=0x1d
#include "vgui2__TextImage.h"
vgui2::TextImage::~TextImage()
{
	delete m_pText;
}
// END FUNCTION

// FUNCTION: 0x101b9d70 size=0x7c
#include "vgui2__TextImage.h"
extern "C" {
size_t wcslen(const unsigned short *);
unsigned short *wcscpy(unsigned short *, const unsigned short *);
}
void vgui2::TextImage::vfunc26(const unsigned short *text)
{
	short len = (short)wcslen(text);
	m_unk22 = len;
	if (len >= m_unk20) {
		delete m_pText;
		m_unk20 = m_unk22 + 1;
		m_pText = (char *)new char[m_unk20 * 2];
	}
	wcscpy((unsigned short *)m_pText, text);
	int w, h;
	vfunc33(&w, &h, (int)m_pText);
	vfunc9(w, h);
}
// END FUNCTION

// FUNCTION: 0x101b9df0 size=0x21
#include "vgui2__TextImage.h"
namespace lifted {
int sub_101ac920();
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual int f8(int, int, int); };
}
int vgui2::TextImage::vfunc28(int a0, int a1)
{
    return ((lifted::V *)(lifted::sub_101ac920()))->f8(*(int *)((char *)this + 0x1c), a0, a1);
}
// END FUNCTION

// FUNCTION: 0x101b9e20 size=0x59
#include "vgui2__TextImage.h"

struct CTextImageLayout
{
	char m_pad00[0x2c];
	int m_i2c;
};

class ILocalizeView
{
public:
	virtual void l0() = 0;
	virtual void l1() = 0;
	virtual void l2() = 0;
	virtual void l3() = 0;
	virtual void l4() = 0;
	virtual void l5() = 0;
	virtual void l6() = 0;
	virtual void l7() = 0;
	virtual void l8() = 0;
	virtual void l9() = 0;
	virtual void l10() = 0;
	virtual char *l11(unsigned short) = 0;
};

void *sub_101ac920();

extern "C" char *__cdecl strncpy(char *, const char *, unsigned int);

// TARGET: vgui2::TextImage::vfunc29
void vgui2::TextImage::vfunc29(char *buf, int size)
{
	CTextImageLayout *s = (CTextImageLayout *)this;
	if (s->m_i2c != 0xffff)
	{
		const char *txt = ((ILocalizeView *)sub_101ac920())->l11((unsigned short)s->m_i2c);
		buf[0] = '#';
		strncpy(buf + 1, txt, size - 1);
		buf[size - 1] = 0;
	}
	else
	{
		vfunc28((int)buf, size);
	}
}
// END FUNCTION

// FUNCTION: 0x101b9e80 size=0x39
#include "vgui2__TextImage.h"
struct TIView { char pad[0x1c]; int m1c; int m20; int m24; };
// TARGET: vgui2::TextImage::vfunc30
void vgui2::TextImage::vfunc30(int v)
{
    int local;
    ((TIView *)this)->m24 = v;
    vfunc33(&local, &v, ((TIView *)this)->m1c);
    vfunc9(local, v);
}
// END FUNCTION

// FUNCTION: 0x101b9ec0 size=0x4
#include "vgui2__TextImage.h"
int vgui2::TextImage::vfunc31()
{
    return *(int *)((char *)this + 0x24);
}
// END FUNCTION

// FUNCTION: 0x101b9ed0 size=0x1b
#include "vgui2__TextImage.h"
namespace lifted {
int __stdcall sub_101b6990(int, int);
}
int vgui2::TextImage::vfunc9(int a0, int a1)
{
    int t0 = lifted::sub_101b6990(a0, a1);
    *(int *)((char *)this + 0x28) = a0;
    return t0;
}
// END FUNCTION

// FUNCTION: 0x101b9ef0 size=0x371
#include "vgui2__TextImage.h"
#include <wchar.h>

struct ISurfaceTI
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void DrawSetTextPos(int x, int y);
	virtual void v21();
	virtual void DrawUnicodeChar(wchar_t wch);
	virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
	virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
	virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
	virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
	virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
	virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62();
	virtual int GetFontTall(int font);
	virtual void GetCharABCwide(int font, int ch, int &a, int &b, int &c);
};
ISurfaceTI *sub_101ac8d0();

struct TIColor
{
	Color4b c;
	TIColor() {}
};

struct TextImageView
{
	virtual void v0(); virtual void v1();
	virtual void GetSize(int &wide, int &tall);
	virtual void v3(); virtual void v4(); virtual void v5();
	virtual void GetPos(int &x, int &y);
	virtual void v7();
	virtual TIColor GetColor();
	virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void DrawSetTextFont(int font);
	virtual void v17();
	virtual void DrawSetTextColor(Color4b col);
	virtual void v19(); virtual void v20(); virtual void v21();
	virtual void DrawPrintChar(int x, int y, wchar_t ch);
	virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
	virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30();
	virtual int GetFont();
};

static __forceinline void TextImagePaint(vgui2::TextImage *self)
{
	TextImageView *v = (TextImageView *)self;
	int wide, tall;
	v->GetSize(wide, tall);
	if (!self->m_pText)
		return;

	v->DrawSetTextColor(v->GetColor().c);
	int font = v->GetFont();
	v->DrawSetTextFont(font);
	int lineTall = sub_101ac8d0()->GetFontTall(font);
	int x = 0;
	int y = 0;
	int px, py;
	v->GetPos(px, py);

	wchar_t buffer[1024];
	wcsncpy(buffer, (wchar_t *)self->m_pText, 1023);
	self->sub_101ba270(buffer, self->m_unk22);

	int i = 0;
	wchar_t ch = buffer[0];
	int a, b, c;
	sub_101ac8d0()->GetCharABCwide(font, ch, a, b, c);
	while (ch)
	{
		if (ch == '\r')
		{
		}
		else if (ch == '\n')
		{
			x = 0;
			y += lineTall;
		}
		else if (ch == ' ')
		{
			wchar_t next = buffer[i + 1];
			sub_101ac8d0()->GetCharABCwide(font, ' ', a, b, c);
			if (next != 0 && next != '\n' && next != '\r')
			{
				x += a + b + c;
				if (x > wide)
				{
					x = 0;
					y += lineTall;
				}
			}
		}
		else
		{
			int wordLen = 1;
			wchar_t wc;
			while ((wc = buffer[i + wordLen]) != 0)
			{
				if (wc == '\n' || wc == '\r' || wc == ' ')
					break;
				int a2, b2, c2;
				sub_101ac8d0()->GetCharABCwide(font, wc, a2, b2, c2);
				wordLen++;
			}
			for (int j = 0; j < wordLen; j++)
			{
				wchar_t wc = buffer[i + j];
				bool bHotkey = false;
				if (wc == '&')
				{
					j++;
					wc = buffer[i + j];
					if (j >= wordLen)
						continue;
					if (wc != '&')
					{
						if (self->m_unk35)
							v->DrawPrintChar(x, y, '_');
						if (self->m_unk30)
							bHotkey = true;
					}
				}
				sub_101ac8d0()->GetCharABCwide(font, wc, a, b, c);
				sub_101ac8d0()->DrawSetTextPos(px + x, py + y);
				if (bHotkey)
				{
					v->DrawSetTextColor(*(Color4b *)&self->m_unk31);
					sub_101ac8d0()->DrawUnicodeChar(wc);
					v->DrawSetTextColor(v->GetColor().c);
				}
				else
				{
					sub_101ac8d0()->DrawUnicodeChar(wc);
				}
				x += a + b + c;
			}
			i += wordLen - 1;
		}
		i++;
		ch = buffer[i];
		sub_101ac8d0()->GetCharABCwide(font, ch, a, b, c);
	}
}

#pragma warning(disable: 4716)
int vgui2::TextImage::vfunc0()
{
	TextImagePaint(this);
}
// END FUNCTION

// FUNCTION: 0x101ba700 size=0xe9
#include "vgui2__TextImage.h"
#include <wchar.h>

class ISurfaceView
{
public:
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
	virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
	virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
	virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
	virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
	virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62();
	virtual int v63(int font);					// 63
	virtual void v64(int font, int ch, int *a, int *b, int *c);	// 64
};

void *sub_101ac8d0();

// TARGET: vgui2::TextImage::vfunc33
void vgui2::TextImage::vfunc33(int *wide, int *tall, int textArg)
{
	const unsigned short *text = (const unsigned short *)textArg;
	*wide = 0;
	int maxWidth = 0;
	*tall = 0;
	int font = vfunc31();
	if ( font == 0 )
		return;
	ISurfaceView *surface = (ISurfaceView *)sub_101ac8d0();
	*tall = surface->v63(font);
	int len = wcslen(text);
	for ( int i = 0; i < len; i++ )
	{
		int a, b, c;
		surface = (ISurfaceView *)sub_101ac8d0();
		surface->v64(font, text[i], &a, &b, &c);
		*wide += a + b + c;
		if ( text[i] == 0xa )
		{
			surface = (ISurfaceView *)sub_101ac8d0();
			*tall += surface->v63(font);
			if ( *wide > maxWidth )
				maxWidth = *wide;
			*wide = 0;
		}
	}
	if ( *wide < maxWidth )
		*wide = maxWidth;
}
// END FUNCTION

// FUNCTION: 0x101ba7f0 size=0x19
#include "vgui2__TextImage.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual int f33(int, int, int); };
}
int vgui2::TextImage::vfunc32(int a0, int a1)
{
    return ((lifted::V *)this)->f33(a0, a1, *(int *)((char *)this + 0x1c));
}
// END FUNCTION
