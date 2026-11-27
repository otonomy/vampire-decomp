// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1017d640 size=0x1e
#include "VRAcceptButton.h"

// VC6 writes VRAcceptButton's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
VRAcceptButton *pcd_emit_1017d640(const VRAcceptButton &other) { return new VRAcceptButton(other); }

// TARGET: ??_GVRAcceptButton@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1017d670 size=0x2a
#include "VRAcceptButton.h"
#pragma warning(disable: 4716)
struct IScheme_1017d670 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void *GetBorder(const char *name); };
int VRAcceptButton::vfunc74(int pSchemeArg)
{
	IScheme_1017d670 *pScheme = (IScheme_1017d670 *)pSchemeArg;
	VRButton::vfunc74(pSchemeArg);
	void *pBorder = pScheme->GetBorder("CharEditBorder");
	vfunc60(pBorder);
}
// END FUNCTION

// FUNCTION: 0x1017d6a0 size=0x39
#include "VRAcceptButton.h"
struct SItem { void sub_1017d310(int a); };
struct SEntry { SItem *m_p; int m_unk[8]; };
struct SPanel {
	char pad[0x18c];
	int m_n;
	int m_unk190;
	SEntry *m_pEntries;
};
extern SPanel *g_105fb6e4;
// TARGET: VRAcceptButton::vfunc86
void VRAcceptButton::vfunc86()
{
	for (int i = 0; i < g_105fb6e4->m_n; i++)
		g_105fb6e4->m_pEntries[i].m_p->sub_1017d310(0);
}
// END FUNCTION
