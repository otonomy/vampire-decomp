// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100606d0 size=0x57
#include "CSignLabel.h"

// TARGET: CSignLabel::CSignLabel
CSignLabel::CSignLabel(vgui2::Panel *parent, const char *name, const char *text)
	: vgui2::Label(parent, name, text), m_col()
{
}
// END FUNCTION

// FUNCTION: 0x10060730 size=0x1e
#include "CSignLabel.h"

// VC6 writes CSignLabel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CSignLabel *pcd_emit_10060730(const CSignLabel &other) { return new CSignLabel(other); }

// TARGET: ??_GCSignLabel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10060750 size=0x2c
#include "CSignLabel.h"
CSignLabel::~CSignLabel()
{
	::operator delete(*(void **)((char *)this + 0xb8));
	::operator delete(*(void **)((char *)this + 0xbc));
}
// END FUNCTION

// FUNCTION: 0x10060780 size=0x143
#include "CSignLabel.h"

extern int sub_100cd0f0();
extern int sub_100cd100();
extern const char *sub_1018c870(const char *name);

struct IScheme_10060780
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual int GetFont(const char *fontName);
};

struct PanelHelper_10060780
{
	char pad[0xb8];
	const char *m_pszText;   // 0xb8
	const char *m_pszFont;   // 0xbc
	int m_fgColor;           // 0xc0
	int m_bgColor;           // 0xc4
	int m_x;                 // 0xc8
	int m_y;                 // 0xcc
	int m_w;                 // 0xd0
	int m_h;                 // 0xd4
	int m_align;             // 0xd8

	void sub_101a9950(int x, int y, int w, int h);
	void sub_101b2e60(int pScheme);
};

// TARGET: ?vfunc74@CSignLabel@@UAEHH@Z
int CSignLabel::vfunc74(int pSchemeArg)
{
	IScheme_10060780 *pScheme = (IScheme_10060780 *)pSchemeArg;
	PanelHelper_10060780 *self = (PanelHelper_10060780 *)this;

	self->sub_101b2e60(pSchemeArg);
	vfunc108(self->m_pszText);
	int font = pScheme->GetFont(sub_1018c870(self->m_pszFont));
	vfunc118(font);
	vfunc51(self->m_fgColor);
	vfunc50(self->m_bgColor);
	self->sub_101a9950(
		(int)(self->m_x * ((float)sub_100cd100() / 1024.0)),
		(int)(self->m_y * ((float)sub_100cd0f0() / 768.0)),
		(int)(self->m_w * ((float)sub_100cd100() / 1024.0)),
		(int)(self->m_h * ((float)sub_100cd0f0() / 768.0))
	);
	vfunc63(1);
	vfunc62(0);
	vfunc64(1);
	vfunc46(1);
	vfunc21(1);
	vfunc39(0);
	return vfunc111(self->m_align);
}
// END FUNCTION
