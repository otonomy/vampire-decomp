// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101766a0 size=0x1e
#include "CharEditCharPanel.h"

// VC6 writes CharEditCharPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CharEditCharPanel *pcd_emit_101766a0(const CharEditCharPanel &other) { return new CharEditCharPanel(other); }

// TARGET: ??_GCharEditCharPanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10177370 size=0xb7
#include "engineclient.h"
#include "CharEditCharPanel.h"
#include <string.h>

extern void sub_10179840();


struct CCharEditPanel_10177370
{
	char m_pad0[0x274];
	int m_unk274;
	void sub_101733d0(int a);
	void sub_101744c0(int a);
};

struct CHud_10177370
{
	CCharEditPanel_10177370 *sub_100f0ed0(const char *name);
};

struct CCharEditCharPanel_10177370
{
	void sub_10177a20();
};

extern CHud_10177370 g_104cfe38;

// TARGET: ?vfunc78@CharEditCharPanel@@UAEXH@Z
void CharEditCharPanel::vfunc78(int command)
{
	const char *pszCommand = (const char *)command;
	if (!_strcmpi(pszCommand, "refresh"))
	{
		((CCharEditCharPanel_10177370 *)this)->sub_10177a20();
	}
	else if (!_strcmpi(pszCommand, "play"))
	{
		sub_10179840();
		CCharEditPanel_10177370 *pPanel = g_104cfe38.sub_100f0ed0("CharEditPanel");
		pPanel->sub_101733d0(0);
		pPanel->m_unk274 = 0;
		engine->vfunc27("vclan teamchoose done", 1);
	}
	else if (!_strcmpi(pszCommand, "next"))
	{
		CCharEditPanel_10177370 *pPanel = g_104cfe38.sub_100f0ed0("CharEditPanel");
		pPanel->sub_101744c0(1);
	}
	else
	{
		typedef vgui2::Panel BaseClass;
		BaseClass::vfunc78(command);
	}
}
// END FUNCTION

// FUNCTION: 0x10177990 size=0x6
#include "CharEditCharPanel.h"
namespace lifted {
extern char g_102d0928;
}
int CharEditCharPanel::vfunc102()
{
    return (int)&lifted::g_102d0928;
}
// END FUNCTION

// FUNCTION: 0x10177a00 size=0x1
#include "CharEditCharPanel.h"
void CharEditCharPanel::vfunc119()
{
}
// END FUNCTION

// FUNCTION: 0x10177aa0 size=0x21
#include "CharEditCharPanel.h"
int sub_1016a6b0();
void CharEditCharPanel::vfunc123()
{
	int n = sub_1016a6b0();
	vfunc33(n);
	sub_101aa0a0(1000);
}
// END FUNCTION

// FUNCTION: 0x10177ad0 size=0x28
#include "CharEditCharPanel.h"
namespace lifted {
struct C10177ea0 { int sub_10177ea0(); };
struct C10177eb0 { int sub_10177eb0(); };
struct C101a99f0 { int sub_101a99f0(int); };
}
int CharEditCharPanel::vfunc21(int a0)
{
    int t0 = ((lifted::C101a99f0 *)this)->sub_101a99f0(a0);
    if (((char)a0) != 0) {
        return ((lifted::C10177eb0 *)this)->sub_10177eb0();
    }
    return ((lifted::C10177ea0 *)this)->sub_10177ea0();
}
// END FUNCTION

// FUNCTION: 0x10177b00 size=0x10
#include "CharEditCharPanel.h"
namespace lifted {
struct C10176f80 { int sub_10176f80(); };
struct C101ab2f0 { int sub_101ab2f0(); };
}
void CharEditCharPanel::vfunc101()
{
    ((lifted::C101ab2f0 *)this)->sub_101ab2f0();
    ((lifted::C10176f80 *)this)->sub_10176f80();
}
// END FUNCTION

// FUNCTION: 0x10177ef0 size=0x16
#define V8(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7();
struct O_10177ef0 {
V8(a) V8(b) V8(c) V8(d) V8(e) V8(f) V8(g) V8(h) V8(i) V8(j)
virtual void E0(); virtual void E1(); virtual void E2(); virtual void E3(); virtual void E4(); virtual void E5(); virtual void E6();
virtual void v87(int); };
O_10177ef0 *sub_10170f70();
struct S_10177ef0 { void sub_10177ef0(int a); };
void S_10177ef0::sub_10177ef0(int a)
{
	O_10177ef0 *p = sub_10170f70();
	if (p)
		p->v87(a);
}
// END FUNCTION
