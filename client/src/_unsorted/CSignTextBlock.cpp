// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10060400 size=0x1e
#include "CSignTextBlock.h"

// VC6 writes CSignTextBlock's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CSignTextBlock *pcd_emit_10060400(const CSignTextBlock &other) { return new CSignTextBlock(other); }

// TARGET: ??_GCSignTextBlock@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10060530 size=0x2c
#include "CSignTextBlock.h"
CSignTextBlock::~CSignTextBlock()
{
	::operator delete(*(void **)((char *)this + 0x128));
	::operator delete(*(void **)((char *)this + 0x12c));
}
// END FUNCTION

// FUNCTION: 0x10060560 size=0x16e
#include "CSignTextBlock.h"

extern int sub_100cd0f0();
extern int sub_100cd100();
extern const char *sub_1018c870(const char *name);

struct IScheme_10060560
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual int GetFont(const char *fontName);
};

#define N10(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4(); virtual void a##5(); virtual void a##6(); virtual void a##7(); virtual void a##8(); virtual void a##9();
struct SlotView
{
	N10(a) N10(b) N10(c) N10(d) N10(e) N10(f) N10(g) N10(h) N10(i) N10(j) N10(k) N10(l) N10(m) N10(n)
	virtual void o0(); virtual void o1(); virtual void o2(); virtual void o3();
	virtual int v144(char);
};

struct SignTextHelper
{
	char pad[0x128];
	const char *m_pszText;	// 0x128
	const char *m_pszFont;	// 0x12c
	int m_fgColor;	// 0x130
	int m_bgColor;	// 0x134
	int m_x;	// 0x138
	int m_y;	// 0x13c
	int m_w;	// 0x140
	int m_h;	// 0x144
	void sub_101ace00(int pScheme);
	void sub_101a9950(int x, int y, int w, int h);
};

// TARGET: CSignTextBlock::vfunc74
int CSignTextBlock::vfunc74(int pSchemeArg)
{
	IScheme_10060560 *pScheme = (IScheme_10060560 *)pSchemeArg;
	SignTextHelper *self = (SignTextHelper *)this;

	self->sub_101ace00(pSchemeArg);
	vfunc107(self->m_pszText);
	int font = pScheme->GetFont(sub_1018c870(self->m_pszFont));
	vfunc132(font);
	vfunc51(self->m_fgColor);
	vfunc50(self->m_bgColor);
	self->sub_101a9950(
		(int)(self->m_x * (sub_100cd100() * 0.0009765625)),
		(int)(self->m_y * (sub_100cd0f0() * 0.0013020833333333333)),
		(int)(self->m_w * (sub_100cd100() * 0.0009765625)),
		(int)(self->m_h * (sub_100cd0f0() * 0.0013020833333333333))
	);
	vfunc138(1);
	vfunc140(0);
	vfunc134(0);
	vfunc63(1);
	vfunc62(0);
	vfunc64(1);
	vfunc46(1);
	vfunc21(1);
	vfunc39(0);
	vfunc133(0);
	return ((SlotView *)this)->v144(1);
}
// END FUNCTION
