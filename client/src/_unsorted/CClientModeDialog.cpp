// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10042a50 size=0x28
#include "vgui2__Panel.h"
typedef vgui2::Panel PanelT;
struct VDlg { int m0, m4; void sub_100d3f70(); void *sub_10042a50(unsigned flags); };
// TARGET: ?sub_10042a50@VDlg@@QAEPAXI@Z
void *VDlg::sub_10042a50(unsigned flags) { PanelT *p = (PanelT *)((char *)this + 8); p->PanelT::~PanelT(); sub_100d3f70(); if (flags & 1) ::operator delete(this); return this; }
// END FUNCTION

// FUNCTION: 0x10042a80 size=0xd0
#include "CClientModeDialog.h"
#include "engineclient.h"
extern "C" int strncmp(const char *, const char *, unsigned int);
extern "C" unsigned int strlen(const char *);
#pragma intrinsic(strlen)
// TARGET: CClientModeDialog::vfunc16
int CClientModeDialog::vfunc16(int down, int key, const char *binding)
{
	const char *keys[11] = { "+attack", "+move", "+back", "+forward", "+right", "+left", "+duck", "+look", "centerview", "inv", "+attack" };
	if (down == 1 && !engine->vfunc33() && binding) {
		for (unsigned int i = 0; i < 11; i++) {
			if (strncmp(binding, keys[i], strlen(keys[i])) == 0)
				return 0;
		}
	}
	return ClientModeShared::vfunc16(down, key, binding);
}
// END FUNCTION

// FUNCTION: 0x10042b50 size=0x3
#include "CClientModeDialog.h"
void CClientModeDialog::vfunc22(int a0, int a1)
{
}
// END FUNCTION
