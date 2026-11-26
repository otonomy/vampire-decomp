// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1018da50 size=0x1e
#include "CVProfPanel.h"

// VC6 writes CVProfPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CVProfPanel *pcd_emit_1018da50(const CVProfPanel &other) { return new CVProfPanel(other); }

// TARGET: ??_GCVProfPanel@@UAEPAXI@Z
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
