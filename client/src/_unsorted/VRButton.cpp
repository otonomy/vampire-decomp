// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1017b160 size=0x1e
#include "VRButton.h"

// VC6 writes VRButton's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
VRButton *pcd_emit_1017b160(const VRButton &other) { return new VRButton(other); }

// TARGET: ??_GVRButton@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1017b190 size=0xdf
#include "VRButton.h"
struct SchemeView {
	virtual void v0(); virtual void v1(); virtual void v2();
	virtual void *GetBorder(const char *name);
};
struct V60 {
#define D8(n) virtual void n##a(); virtual void n##b(); virtual void n##c(); virtual void n##d(); virtual void n##e(); virtual void n##f(); virtual void n##g(); virtual void n##h();
	D8(a) D8(b) D8(c) D8(d) D8(e) D8(f) D8(g)
	virtual void x0(); virtual void x1(); virtual void x2(); virtual void x3();
	virtual int f60(void *);
};
int VRButton::vfunc74(int a)
{
	Button::vfunc74(a);
	SchemeView *s = (SchemeView *)a;
	struct { unsigned char r, g, b, a; } c;
	int t;
	c.a = 0xff;
	c.r = 0x52;
	c.g = 0x52;
	c.b = 0x52;
	vfunc51(*(int *)&c);
	vfunc153(*(unsigned int *)vfunc53((int)&t), *(unsigned int *)vfunc52((int)&c));
	vfunc154(*(unsigned int *)vfunc53((int)&t), *(unsigned int *)vfunc52((int)&c));
	vfunc155(*(unsigned int *)vfunc53((int)&t), *(unsigned int *)vfunc52((int)&c));
	void *b = s->GetBorder("CharEditBorder");
	return ((V60 *)this)->f60(b);
}
// END FUNCTION

// FUNCTION: 0x1017b280 size=0x4e
#include "VRButton.h"

extern void sub_1017c680(const char *);

void VRButton::vfunc143(char state)
{
	bool bWasArmed = vfunc144();
	Button::vfunc143(state);
	if (vfunc144() != bWasArmed)
	{
		sub_1017c680(vfunc144() ? "interface/bubble_click_on.wav" : "interface/bubble_click_off.wav");
	}
}
// END FUNCTION

// FUNCTION: 0x1017b2d0 size=0x25
#include "VRButton.h"
namespace lifted {
extern int g_105fb6e4;
struct C10181ad0 { int sub_10181ad0(int); };
struct C101b4210 { int sub_101b4210(); };
}
void VRButton::vfunc85()
{
    int t0 = ((lifted::C101b4210 *)this)->sub_101b4210();
    if ((*(int *)((char *)this + 0xf0)) != -1) {
        if (lifted::g_105fb6e4 != 0) {
            ((lifted::C10181ad0 *)lifted::g_105fb6e4)->sub_10181ad0(*(int *)((char *)this + 0xf0));
        }
    }
}
// END FUNCTION
