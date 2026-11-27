// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10176420 size=0x1e
#include "VLabelComboBox.h"

// VC6 writes VLabelComboBox's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
VLabelComboBox *pcd_emit_10176420(const VLabelComboBox &other) { return new VLabelComboBox(other); }

// TARGET: ??_GVLabelComboBox@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10176450 size=0x7e
#include "VLabelComboBox.h"

struct VSchemeView {
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void *v3(const char *name);
	virtual void v4();
	virtual void v5();
	virtual int *v6(int *out, const char *name);
};

int VLabelComboBox::vfunc74(int a)
{
	VSchemeView *s = (VSchemeView *)a;
	LabelComboBox::vfunc74(a);
	void *b = s->v3("DropDownHighlightBorder");
	vfunc60(b);
	vfunc158((int)b);
	vfunc159((int)b);
	vfunc160((int)b);
	int c;
	if (*(char *)((char *)this + 0x100))
		return vfunc51(*s->v6(&c, "BorderBright"));
	else
		return vfunc51(*s->v6(&c, "BorderDark"));
}
// END FUNCTION
