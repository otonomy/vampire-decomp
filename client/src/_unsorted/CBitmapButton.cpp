// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10164270 size=0x1
#include "CBitmapButton.h"
void CBitmapButton::vfunc97()
{
}
// END FUNCTION

// FUNCTION: 0x10164280 size=0x1e
#include "CBitmapButton.h"

// VC6 writes CBitmapButton's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CBitmapButton *pcd_emit_10164280(const CBitmapButton &other) { return new CBitmapButton(other); }

// TARGET: ??_GCBitmapButton@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101642a0 size=0x2d
#include "CBitmapButton.h"
struct CUnknown101b6900 { char m_pad[0x4c]; void sub_101b6900(); };
CBitmapButton::~CBitmapButton()
{
	CUnknown101b6900 *img = (CUnknown101b6900 *)((char *)this + 0x220);
	for (int i = 4; i != 0; i--) {
		img--;
		img->sub_101b6900();
	}
}
// END FUNCTION

// FUNCTION: 0x101642e0 size=0x67
#include "CBitmapButton.h"
#include "BitmapImage.h"
struct IKV11;
bool sub_10164a50(IKV11 *, const char *, int, BitmapImage *);
struct BitmapImage4c { char pad[0x4c]; };
// TARGET: CBitmapButton::vfunc75
void CBitmapButton::vfunc75(int pInitData)
{
    Button::vfunc75(pInitData);
    const char *pSectionName[4] =
    {
        "enabledImage",
        "mouseOverImage",
        "pressedImage",
        "disabledImage"
    };
    for (int i = 0; i < 4; ++i)
    {
        ((char *)this)[0x220 + i] = sub_10164a50((IKV11 *)pInitData, pSectionName[i], (int)this, (BitmapImage *)((BitmapImage4c *)((char *)this + 0xf0) + i));
    }
}
// END FUNCTION

// FUNCTION: 0x101643c0 size=0x66
#include "CBitmapButton.h"

struct BImgV
{
	void sub_10164900(void *pPanel, int a, float b);
};

struct BBView
{
	char pad0[0x220];
	char m_bImage[4];
};

void __fastcall sub_101b3900(void *self);

void CBitmapButton::vfunc98()
{
	int idx = 0;
	if (vfunc139())
		idx = vfunc140() ? 2 : 1;
	else if (!vfunc47())
		idx = 3;
	BBView *v = (BBView *)this;
	if (v->m_bImage[idx])
	{
		((BImgV *)((char *)this + 0xf0 + 0x4c * idx))->sub_10164900(this, 0, 1.0f);
	}
	sub_101b3900(this);
}
// END FUNCTION
