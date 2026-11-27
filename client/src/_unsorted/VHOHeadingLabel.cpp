// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1017d430 size=0x1e
#include "VHOHeadingLabel.h"

// VC6 writes VHOHeadingLabel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
VHOHeadingLabel *pcd_emit_1017d430(const VHOHeadingLabel &other) { return new VHOHeadingLabel(other); }

// TARGET: ??_GVHOHeadingLabel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1017d460 size=0xa4
#include "VHOHeadingLabel.h"

struct HOScheme
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual int *vfunc6(int *pOut, const char *pszName);
};
struct HOLabelView { char m_pad[0xc0]; bool m_bC0; bool m_bC1; bool m_bC2; };

// TARGET: VHOHeadingLabel::vfunc74
int VHOHeadingLabel::vfunc74(int pScheme)
{
	HOScheme *s = (HOScheme *)pScheme;
	HOLabelView *v = (HOLabelView *)this;
	int clr;
	Label::vfunc74(pScheme);
	if (!v->m_bC2)
	{
		if (!v->m_bC1)
		{
			if (v->m_bC0)
				return vfunc51(*s->vfunc6(&clr, "VReferencedText"));
			return vfunc51(*s->vfunc6(&clr, "VDesHeaderText"));
		}
		return vfunc51(*s->vfunc6(&clr, "VSelectedText"));
	}
	if (!v->m_bC1)
	{
		if (v->m_bC0)
			return vfunc51(*s->vfunc6(&clr, "VDisabledRefText"));
		return vfunc51(*s->vfunc6(&clr, "VDisabledText"));
	}
	return vfunc51(*s->vfunc6(&clr, "VDisabledSelText"));
}
// END FUNCTION
