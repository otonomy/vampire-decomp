// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10170eb0 size=0x1e
#include "VAnarchyLabel.h"

// VC6 writes VAnarchyLabel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
VAnarchyLabel *pcd_emit_10170eb0(const VAnarchyLabel &other) { return new VAnarchyLabel(other); }

// TARGET: ??_GVAnarchyLabel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10170ed0 size=0x2b
#include "VAnarchyLabel.h"
struct IObjC0 { virtual ~IObjC0(); };
VAnarchyLabel::~VAnarchyLabel()
{
	IObjC0 *p = *(IObjC0 **)((char *)this + 0xc0);
	if (p)
		delete p;
	*(int *)((char *)this + 0xc0) = 0;
}
// END FUNCTION

// FUNCTION: 0x10170f10 size=0x43
#include "VAnarchyLabel.h"
void VAnarchyLabel::vfunc98()
{
	int w, h;
	sub_101a98c0(&w, &h);
	if (m_pSprite)
		m_pSprite->sub_10059620(w, h, m_n0b8, m_n0bc);
}
// END FUNCTION
