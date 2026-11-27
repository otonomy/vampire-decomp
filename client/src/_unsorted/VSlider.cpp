// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1017b330 size=0x1e
#include "VSlider.h"

// VC6 writes VSlider's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
VSlider *pcd_emit_1017b330(const VSlider &other) { return new VSlider(other); }

// TARGET: ??_GVSlider@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1017b350 size=0x33
#include "VSlider.h"
VSlider::~VSlider()
{
	vgui2::Panel *a = *(vgui2::Panel **)((char *)this + 0xa0);
	if (a)
		delete a;
	vgui2::Panel *b = *(vgui2::Panel **)((char *)this + 0xa4);
	if (b)
		delete b;
}
// END FUNCTION

// FUNCTION: 0x1017b390 size=0xb0
#include "VSlider.h"
struct SliderDtorView { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual ~SliderDtorView(); };
struct SliderImageView { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void SetVisible(int); };
struct SliderSchemeView { virtual void v0(); virtual SliderImageView *GetImage(const char *name); };
struct Obj_101ac830 { SliderSchemeView *sub_101ac830(); };
struct SliderBoundsView { void sub_101a9980(int *, int *, int *, int *); };
int sub_100cd100();
// TARGET: VSlider::vfunc101
void VSlider::vfunc101()
{
	SliderDtorView *p0 = *(SliderDtorView **)((char *)this + 0xa0);
	if (p0)
		delete p0;
	int x, y, w, h;
	((SliderBoundsView *)this)->sub_101a9980(&x, &y, &w, &h);
	SliderDtorView *p1 = *(SliderDtorView **)((char *)this + 0xa4);
	if (p1)
		delete p1;
	SliderSchemeView *scheme = ((Obj_101ac830 *)this)->sub_101ac830();
	*(SliderImageView **)((char *)this + 0xa8) = scheme->GetImage("interface/charactermaintenance/cm_slider");
	SliderImageView *img = scheme->GetImage("interface/charactermaintenance/cm_slide");
	*(SliderImageView **)((char *)this + 0xac) = img;
	img->SetVisible(0);
	vfunc116((int)((sub_100cd100() * 0.0009765625) * 32.0));
	Slider::vfunc101();
}
// END FUNCTION

// FUNCTION: 0x1017b440 size=0xae
#include "VSlider.h"
void VSlider::vfunc98()
{
    if (m_pA4) {
        int x, y, p, q;
        vfunc112((int)&x, (int)&y);
        sub_101a98c0(&p, &q);
        m_pA4->sub_101a9890(p + x, q);
    }
    if (m_pA8)
        m_pA8->v0();
    if (m_pAC) {
        int x, y, p, q;
        vfunc112((int)&p, (int)&y);
        sub_101a98c0(&q, &x);
        m_pAC->v1(p, 0);
        m_pAC->v0();
    }
}
// END FUNCTION
