// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1018d770 size=0x2dd
#include "CVProfPanel.h"
#include "vgui2__Button.h"

int sub_100cd100();	// ScreenWidth
int sub_100cd0f0();	// ScreenHeight
extern char g_10281e04[];

struct VColor { unsigned char r, g, b, a; };
struct CUnknown1018dd40 { int sub_1018dd40(int); };	// a Panel slot override of CVProfPanel's (this = the Panel part)

using vgui2::Label;
using vgui2::Button;

#define XRES(x) (int)((x) * (sub_100cd100() / 640.0))
#define YRES(y) (int)((y) * (sub_100cd0f0() / 480.0))
#define m_Title (*(Label *)((char *)this + 0x6c))
#define m_pClose (*(Button **)((char *)this + 0x1c8))

CVProfPanel::CVProfPanel(const char *pElementName) : CHudElement((int)pElementName), vgui2::Panel(0, pElementName), m_members(this)
{
	*(int *)((char *)this + 0x68) = 0;

	((CUnknown1018dd40 *)(vgui2::Panel *)this)->sub_1018dd40(0);
	Panel::vfunc39(0);
	int x = XRES(20);
	int y = YRES(10);
	int w = sub_100cd100() - 2 * x;
	int h = sub_100cd0f0() - 2 * y;
	sub_101a9950(x, y, w, h);
	VColor bg = { 0, 0, 0, 175 };
	Panel::vfunc50(*(int *)&bg);
	Panel::vfunc54(2);
	sub_101aa0a0(1000);
	m_Title.vfunc108("VProf");
	m_Title.vfunc63(0);
	m_Title.vfunc111(3);
	double dw = w;
	m_Title.sub_101a9950(XRES(10), 4, (int)(dw - 20 * (sub_100cd100() / 640.0)), YRES(22));
	Panel::vfunc62(1);

	m_pClose = new (vgui2::Panel::operator new(0xf0)) Button((int)(vgui2::Panel *)this, (int)"Close", (int)g_10281e04);
	m_pClose->vfunc63(0);
	VColor fg = { 255, 255, 255, 255 };
	m_pClose->vfunc51(*(int *)&fg);
	m_pClose->vfunc41((int)(vgui2::Panel *)this);
	m_pClose->sub_101a9950((int)(dw - 18 * (sub_100cd100() / 640.0)), YRES(2), XRES(12), YRES(12));
	m_pClose->vfunc162((int)"close");
}
// END FUNCTION

// FUNCTION: 0x1018da50 size=0x1e
#include "CVProfPanel.h"

// VC6 writes CVProfPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CVProfPanel *pcd_emit_1018da50(const CVProfPanel &other) { return new CVProfPanel(other); }

// TARGET: ??_GCVProfPanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1018da70 size=0x40
#include "CVProfPanel.h"
#include "vgui2__Label.h"
#include "vgui2__TreeView.h"
extern int g_105fbd28;
typedef vgui2::Label VLabel;
typedef vgui2::TreeView VTreeView;
CVProfPanel::~CVProfPanel()
{
	g_105fbd28 = 0;
	((VTreeView *)((char *)this + 0x124))->VTreeView::~VTreeView();
	((VLabel *)((char *)this + 0x6c))->VLabel::~VLabel();
}
// END FUNCTION

// FUNCTION: 0x1018dab0 size=0xaa
#include "CVProfPanel.h"
#include "vgui2__Label.h"
#include "vgui2__TreeView.h"

struct SchemeColor
{
	unsigned char r, g, b, a;
	SchemeColor() {}
	SchemeColor(int r_, int g_, int b_, int a_) { r = r_; g = g_; b = b_; a = a_; }
};

struct ISchemeView
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void *GetBorder(const char *name);
	virtual int GetFont(const char *name);
	virtual void v5();
	virtual SchemeColor GetColor(const char *name);
};

typedef vgui2::Panel VProfBase;

#pragma warning(disable : 4716)
int CVProfPanel::vfunc74(int scheme)
{
	VProfBase::vfunc74(scheme);
	ISchemeView *pScheme = (ISchemeView *)scheme;
	((vgui2::Label *)((char *)this + 0x6c))->vfunc118(pScheme->GetFont("Trebuchet18"));
	((vgui2::Label *)((char *)this + 0x6c))->vfunc51(*(int *)&pScheme->GetColor("TitleText"));
	void *border = pScheme->GetBorder("ToolTipBorder");
	vfunc60(border);
	SchemeColor col(0, 0, 0, 0xaf);
	vfunc50(*(int *)&col);
	((vgui2::TreeView *)((char *)this + 0x124))->vfunc114(pScheme->GetFont("DefaultVerySmall"));
}
// END FUNCTION

// FUNCTION: 0x1018dd70 size=0x1e
#include "CVProfPanel.h"
// TARGET: CVProfPanel::CHudElement_vfunc9
bool CVProfPanel::CHudElement_vfunc9()
{
	return CHudElement::sub_100f05b0() && *(int *)((char *)this + 0x68) != 0;
}
// END FUNCTION
