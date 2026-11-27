// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101b71e0 size=0x6f2
#include "vgui2__Frame.h"
#include "vgui2__FrameSystemButton.h"

using namespace vgui2;

#define F(T, off) (*(T *)((char *)this + (off)))
#define FP(T, p, off) (*(T *)((char *)(p) + (off)))

extern void *vt_10251594;	// GripPanel
extern void *vt_102513dc;	// CaptionGripPanel
extern void *vt_1025113c;	// FrameButton
extern void *vt_10250e84;	// FrameSystemButton
extern void *vt_1025174c;	// Frame
extern char g_1027a804[];
extern char g_1027a844[];
extern char g_1027d2bc[];
extern char g_102de300[];

struct Color_101b71e0
{
	unsigned char c[4];
	void SetColor(int r, int g, int b, int a) { c[0] = (unsigned char)r; c[1] = (unsigned char)g; c[2] = (unsigned char)b; c[3] = (unsigned char)a; }
};

struct Button_101b3630 { void sub_101b3630(Panel *parent, const char *name, const char *text); };
struct CUnknown10062280 { void sub_10062280(int r, int g, int b, int a); };
struct CUnknown101b5670 { void *sub_101b5670(const char *name); };
struct CUnknown101c9560 { void sub_101c9560(Panel *parent, const char *name, const char *text); };
struct Frame_101b92d0 { int sub_101b92d0(); };
struct FrameButton_101b8090 { Button *sub_101b8090(Panel *parent, const char *name, const char *text); };
struct FocusNavV { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void SetFocusTopLevel(bool); };
struct SurfaceV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
	virtual bool SupportsFeature59();
};
void *sub_101b6840(unsigned int size);
SurfaceV *sub_101ac8d0();

static __forceinline void InitGrip(Panel *p, Frame *frame, int xdir, int ydir)
{
	*(void **)p = &vt_10251594;
	FP(Frame *, p, 0x58) = frame;
	FP(bool, p, 0x64) = false;
	FP(int, p, 0x5c) = xdir;
	FP(int, p, 0x60) = ydir;
	p->Panel::vfunc64(0);
	p->Panel::vfunc63(0);
	p->Panel::vfunc62(0);
}

static __forceinline Panel *NewGrip(Frame *frame, const char *name, int xdir, int ydir)
{
	Panel *p = (Panel *)Panel::operator new(0x80);
	if (p)
	{
		new (p) Panel(frame, name);
		InitGrip(p, frame, xdir, ydir);
	}
	else
		p = 0;
	return p;
}

static __forceinline Panel *NewCaption(Frame *frame, const char *name)
{
	void *mem = Panel::operator new(0x80);
	Panel *cap;
	if (mem)
	{
		new (mem) Panel(frame, name);
		InitGrip((Panel *)mem, frame, 0, 0);
		*(void **)mem = &vt_102513dc;
		cap = (Panel *)mem;
	}
	else
		cap = 0;
	return cap;
}

static __forceinline void *NewKeyValues(const char *name)
{
	void *mem = sub_101b6840(0x1c);
	void *kv;
	if (mem)
		kv = ((CUnknown101b5670 *)mem)->sub_101b5670(name);
	else
		kv = 0;
	return kv;
}

static __forceinline Button *NewFrameButton(Frame *frame, const char *name, const char *text, bool inlineColor)
{
	void *mem = Panel::operator new(0x110);
	Button *b;
	if (mem)
	{
		((Button_101b3630 *)mem)->sub_101b3630(frame, name, text);
		((CUnknown10062280 *)((char *)mem + 0xfc))->sub_10062280(0, 0, 0, 0);
		((CUnknown10062280 *)((char *)mem + 0x100))->sub_10062280(0, 0, 0, 0);
		((CUnknown10062280 *)((char *)mem + 0x104))->sub_10062280(0, 0, 0, 0);
		if (inlineColor)
			((Color_101b71e0 *)((char *)mem + 0x108))->SetColor(0, 0, 0, 0);
		else
			((CUnknown10062280 *)((char *)mem + 0x108))->sub_10062280(0, 0, 0, 0);
		*(void **)mem = &vt_1025113c;
		((Button *)mem)->Button::sub_101a98f0(0x12, 0x12);
		FP(int, mem, 0xf0) = 0;
		FP(int, mem, 0xf4) = 0;
		FP(int, mem, 0xf8) = 0;
		FP(bool, mem, 0x10c) = true;
		((Button *)mem)->Label::vfunc111(0);
		((Button *)mem)->Label::vfunc112(2, 1);
		b = (Button *)mem;
	}
	else
		b = 0;
	return b;
}

Frame::Frame(Panel *parent, const char *name, bool bPrimary) : EditablePanel(parent, name)
{
	((Color_101b71e0 *)((char *)this + 0x78))->SetColor(0, 0, 0, 0);
	((Color_101b71e0 *)((char *)this + 0x7c))->SetColor(0, 0, 0, 0);
	((Color_101b71e0 *)((char *)this + 0x80))->SetColor(0, 0, 0, 0);
	((Color_101b71e0 *)((char *)this + 0x84))->SetColor(0, 0, 0, 0);
	*(void **)this = &vt_1025174c;
	F(bool, 0xd0) = true;
	F(bool, 0xd1) = false;
	F(int, 0xd4) = 5;
	F(int, 0xd8) = 0x1d;
	F(int, 0xdc) = 0;
	F(int, 0xe0) = 0;
	F(int, 0x88) = 0;
	F(bool, 0x8d) = true;
	F(bool, 0x8c) = true;
	F(bool, 0x8e) = false;
	F(bool, 0xc8) = false;
	vfunc118((int)"Untitled", 1);
	vfunc66(vfunc109());
	sub_101aaaf0(0x80, 0x42);
	F(int, 0xcc) = 0;
	((FocusNavV *)vfunc116())->SetFocusTopLevel(true);

	F(Panel *, 0x90) = NewGrip(this, "TopGrip", 0, -1);
	F(Panel *, 0x94) = NewGrip(this, "BottomGrip", 0, 1);
	F(Panel *, 0x98) = NewGrip(this, "LeftGrip", -1, 0);
	F(Panel *, 0x9c) = NewGrip(this, "RightGrip", 1, 0);
	F(Panel *, 0xa0) = NewGrip(this, "TopLeftGrip", -1, -1);
	F(Panel *, 0xa4) = NewGrip(this, "TopRightGrip", 1, -1);
	F(Panel *, 0xa8) = NewGrip(this, "BottomLeftGrip", -1, 1);
	F(Panel *, 0xac) = NewGrip(this, "BottomRightGrip", 1, 1);
	F(Panel *, 0xb0) = NewCaption(this, "Caption");
	F(Panel *, 0xb0)->vfunc54(2);

	F(Button *, 0xb4) = NewFrameButton(this, "Minimize", g_1027a804, true);
	F(Button *, 0xb4)->vfunc41((int)this);
	F(Button *, 0xb4)->vfunc161((int)NewKeyValues("Minimize"));

	F(Button *, 0xb8) = NewFrameButton(this, "Maximize", g_1027a844, false);
	vfunc127(0);

	void *mem = Panel::operator new(0x110);
	Button *close;
	if (mem)
		close = ((FrameButton_101b8090 *)mem)->sub_101b8090(this, "Close", g_1027d2bc);
	else
		close = 0;
	F(Button *, 0xbc) = close;
	F(Button *, 0xbc)->vfunc41((int)this);
	F(Button *, 0xbc)->vfunc161((int)NewKeyValues("Close"));

	FrameSystemButton *mb = (FrameSystemButton *)Panel::operator new(0x110);
	if (mb)
	{
		((CUnknown101c9560 *)mb)->sub_101c9560(this, 0, g_102de300);
		((CUnknown10062280 *)((char *)mb + 0x104))->sub_10062280(0, 0, 0, 0);
		((CUnknown10062280 *)((char *)mb + 0x108))->sub_10062280(0, 0, 0, 0);
		*(void **)mb = &vt_10250e84;
		FP(int, mb, 0xfc) = 0;
		FP(int, mb, 0x100) = 0;
		mb->FrameSystemButton::vfunc46(0);
		mb->Button::vfunc148(1, 1);
	}
	else
		mb = 0;
	F(FrameSystemButton *, 0xc0) = mb;
	F(FrameSystemButton *, 0xc0)->vfunc168(((Frame_101b92d0 *)this)->sub_101b92d0());

	if (!sub_101ac8d0()->SupportsFeature59())
	{
		vfunc126(0);
		vfunc127(0);
	}
	vfunc144();
	int wide, tall;
	sub_101a9920(&wide, &tall);
	vfunc21(0);
	vfunc28(bPrimary);
}
// END FUNCTION

// FUNCTION: 0x101b85b0 size=0x1e
#include "vgui2__Frame.h"

// VC6 writes vgui2::Frame's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::Frame *pcd_emit_101b85b0(const vgui2::Frame &other) { return new vgui2::Frame(other); }

// TARGET: ??_GFrame@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101b85d0 size=0xff
#include "vgui2__Frame.h"
struct IObj88 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(int); };
struct FrameView { char pad[0x88]; IObj88 *p88; char pad2[4]; vgui2::Panel *p[13]; };
#define FV ((FrameView *)this)
using namespace vgui2;
// TARGET: vgui2::Frame::~Frame
Frame::~Frame()
{
	if (FV->p[0]) delete FV->p[0];
	if (FV->p[1]) delete FV->p[1];
	if (FV->p[2]) delete FV->p[2];
	if (FV->p[3]) delete FV->p[3];
	if (FV->p[4]) delete FV->p[4];
	if (FV->p[5]) delete FV->p[5];
	if (FV->p[6]) delete FV->p[6];
	if (FV->p[7]) delete FV->p[7];
	if (FV->p[8]) delete FV->p[8];
	if (FV->p[9]) delete FV->p[9];
	if (FV->p[10]) delete FV->p[10];
	if (FV->p[11]) delete FV->p[11];
	if (FV->p[12]) delete FV->p[12];
	if (FV->p88) FV->p88->v5(1);
}
// END FUNCTION

// FUNCTION: 0x101b86d0 size=0x119
#include "vgui2__Frame.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual int f54(int); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual bool f122(); };
}
void vgui2::Frame::vfunc144()
{
    if ((*(char *)((char *)this + 0xd0)) != 0) {
        bool t0 = ((lifted::V *)this)->f122();
        if (t0 != 0) {
            ((lifted::V *)(*(int *)((char *)this + 0x90)))->f54(0xa);
            ((lifted::V *)(*(int *)((char *)this + 0x94)))->f54(0xa);
            ((lifted::V *)(*(int *)((char *)this + 0x98)))->f54(9);
            ((lifted::V *)(*(int *)((char *)this + 0x9c)))->f54(9);
            ((lifted::V *)(*(int *)((char *)this + 0xa0)))->f54(7);
            ((lifted::V *)(*(int *)((char *)this + 0xa4)))->f54(8);
            ((lifted::V *)(*(int *)((char *)this + 0xa8)))->f54(8);
            ((lifted::V *)(*(int *)((char *)this + 0xac)))->f54(7); return;
        }
        ((lifted::V *)(*(int *)((char *)this + 0x90)))->f54(2);
        ((lifted::V *)(*(int *)((char *)this + 0x94)))->f54(2);
        ((lifted::V *)(*(int *)((char *)this + 0x98)))->f54(2);
        ((lifted::V *)(*(int *)((char *)this + 0x9c)))->f54(2);
        ((lifted::V *)(*(int *)((char *)this + 0xa0)))->f54(2);
        ((lifted::V *)(*(int *)((char *)this + 0xa4)))->f54(2);
        ((lifted::V *)(*(int *)((char *)this + 0xa8)))->f54(2);
        ((lifted::V *)(*(int *)((char *)this + 0xac)))->f54(2);
    }
}
// END FUNCTION

// FUNCTION: 0x101b8810 size=0x49
#include "vgui2__Frame.h"
namespace lifted {
int sub_101ac8d0();
struct V { virtual int f0(int); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual int f15(int); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual int f44(int); virtual void u45(); virtual int f46(int); virtual void u47(); virtual void u48(); virtual int f49(); };
}
int vgui2::Frame::vfunc124()
{
    ((lifted::V *)this)->f49();
    ((lifted::V *)this)->f15(0);
    ((lifted::V *)this)->f21(1);
    ((lifted::V *)this)->f46(1);
    return ((lifted::V *)(lifted::sub_101ac8d0()))->f44(((lifted::V *)this)->f0(0));
}
// END FUNCTION

// FUNCTION: 0x101b8860 size=0x5f
#include "vgui2__Frame.h"
#include "vgui2__Panel.h"

// TARGET: vgui2::Frame::vfunc125
int sub_101ac8d0();

class ISurf83
{
public:
#define D(n) virtual void d##n();
	D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9)
	D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
	D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28) D(29)
	D(30) D(31) D(32) D(33) D(34) D(35) D(36) D(37) D(38) D(39)
	D(40) D(41) D(42) D(43) D(44) D(45) D(46) D(47) D(48) D(49)
	D(50) D(51) D(52) D(53) D(54) D(55) D(56) D(57) D(58) D(59)
	D(60) D(61) D(62) D(63) D(64) D(65) D(66) D(67) D(68) D(69)
	D(70) D(71) D(72) D(73) D(74) D(75) D(76) D(77) D(78) D(79)
	D(80) D(81) D(82)
#undef D
	virtual void vfunc83(int *, int *, int *, int *);
};

struct PVX
{
	int sub_101ab1a0();
	int sub_101ab130();
	void sub_101a9890(int, int);
};

void vgui2::Frame::vfunc125()
{
	int a, b, c, d;
	((ISurf83 *)sub_101ac8d0())->vfunc83(&d, &c, &b, &a);
	((PVX *)this)->sub_101a9890((b - ((PVX *)this)->sub_101ab130()) / 2, (a - ((PVX *)this)->sub_101ab1a0()) / 2);
}
// END FUNCTION

// FUNCTION: 0x101b8db0 size=0x7a
#include "vgui2__Frame.h"
#include "vgui2__TextImage.h"

struct FrameView {
    char m_pad[0x88];
    void *m_pTitle;
};

struct SurfaceView {
    virtual void s0();  virtual void s1();  virtual void s2();  virtual void s3();
    virtual void s4();  virtual void s5();  virtual void s6();  virtual void s7();
    virtual void s8();  virtual void s9();  virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
    virtual void s44(); virtual void s45();
    virtual void vfunc46(int, const char *);
};

int sub_101ac8d0();

// TARGET: vgui2::Frame::vfunc118
int vgui2::Frame::vfunc118(int title_, char surfaceTitle)
{
    const char *title = (const char *)title_;
    FrameView *fv = (FrameView *)this;
    if (!fv->m_pTitle)
        fv->m_pTitle = new vgui2::TextImage((const char *)0, sub_101aa220());
    ((vgui2::TextImage *)fv->m_pTitle)->vfunc27(title);
    if (surfaceTitle)
        ((SurfaceView *)sub_101ac8d0())->vfunc46(vfunc0(), title);
    return vfunc6();
}
// END FUNCTION

// FUNCTION: 0x101b8e30 size=0x12
#include "vgui2__Frame.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual int f118(int, int); };
}
int vgui2::Frame::vfunc142(int a0)
{
    return ((lifted::V *)this)->f118(a0, 1);
}
// END FUNCTION

// FUNCTION: 0x101b8e50 size=0xd
#include "vgui2__Frame.h"
bool vgui2::Frame::vfunc119(char a0)
{
    *(char *)((char *)this + 0x8d) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101b8e60 size=0x15
#include "vgui2__Frame.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual int f144(); };
}
int vgui2::Frame::vfunc121(char a0)
{
    *(char *)((char *)this + 0x8c) = a0;
    return ((lifted::V *)this)->f144();
}
// END FUNCTION

// FUNCTION: 0x101b8e80 size=0x7
#include "vgui2__Frame.h"
bool vgui2::Frame::vfunc120()
{
    return *(bool *)((char *)this + 0x8d);
}
// END FUNCTION

// FUNCTION: 0x101b8e90 size=0x7
#include "vgui2__Frame.h"
bool vgui2::Frame::vfunc122()
{
    return *(bool *)((char *)this + 0x8c);
}
// END FUNCTION

// FUNCTION: 0x101b8ea0 size=0x33
#include "vgui2__Frame.h"
int vgui2::Frame::vfunc141(int a0, int a1, int a2, int a3)
{
    int t0 = *(int *)((char *)this + 0xd4);
    *(int *)((char *)a0) = t0;
    int t1 = *(int *)((char *)this + 0xd8);
    *(int *)((char *)a1) = t1;
    int t2 = *(int *)((char *)this + 0xdc);
    *(int *)((char *)a2) = t2;
    int t3 = *(int *)((char *)this + 0xe0);
    *(int *)((char *)a3) = t3;
    return t3;
}
// END FUNCTION

// FUNCTION: 0x101b8ee0 size=0x240
#include "vgui2__Frame.h"
#define S(n) virtual void s##n();
#define S10(p) S(p##0) S(p##1) S(p##2) S(p##3) S(p##4) S(p##5) S(p##6) S(p##7) S(p##8) S(p##9)
struct Color_101b8ee0 { unsigned char r, g, b, a; };
struct XBtn_101b8ee0 { S10(0) S10(1) S10(2) S10(3) S(40) S(41) S(42) S(43) S(44) S(45) virtual void v46(bool);
	S(47) S(48) S(49) S(50) S(51) S(52) S(53) S(54) S(55) S(56) virtual void v57(int, int);
	S(58) S(59) S10(6) S10(7) S10(8) S10(9) S10(10) S10(11) S10(12) S10(13) S10(14) S10(15) S(160) S(161) S(162) S(163) S(164) S(165) virtual void v166(bool); };
struct XInput_101b8ee0 { S(0) S(1) S(2) virtual int GetFocus(); };
struct XIvgui_101b8ee0 { S10(0) S10(1) virtual bool HasParent(int, int); };
struct XScheme_101b8ee0 { S(0) S(1) virtual void v2(int); virtual void *GetBorder(const char *); virtual void *GetFont(const char *); };
struct XSurf_101b8ee0 { S10(0) virtual void DrawSetColor(Color_101b8ee0); S(11) virtual void DrawFilledRect(int, int, int, int); S(13) S(14) S(15) S(16) virtual void DrawSetTextFont(void *); };
struct XLabel_101b8ee0 { virtual void Paint(); virtual void SetPos(int, int); virtual void v2(); virtual void SetFgColor(Color_101b8ee0); };
struct XBorder_101b8ee0 { S(0) S(1) virtual void Paint(int); };
struct XSchemeMgr_101b8ee0 { S(0) S(1) S(2) S(3) virtual XScheme_101b8ee0 *GetIScheme(int); };
struct XThis_101b8ee0 {
	virtual int GetVPanel(); S(1) S(2) S(3) S(4) S(5) S(6) S(7) S(8) S(9)
	S10(1) S10(2) S10(3) S10(4) S10(5) S10(6) S10(7) S10(8) S10(9) S10(10) S10(11) S10(12) S(130) S(131) S(132) virtual void g133();
	int sub_101ab130(); void sub_101ab1a0(); int sub_101aa220(); void sub_101b4d50();
};
struct XFrame_101b8ee0 { char p[0x78]; Color_101b8ee0 m78; Color_101b8ee0 m7c; Color_101b8ee0 m80; Color_101b8ee0 m84; XLabel_101b8ee0 *m88; char pad8c[2]; bool m8e; char pad8f[0xb4 - 0x8f]; XBtn_101b8ee0 *mb4; XBtn_101b8ee0 *mb8; XBtn_101b8ee0 *mbc; XBtn_101b8ee0 *mc0; char pc4[4]; bool mc8; char pc9[0xd1 - 0xc9]; bool md1; };
XInput_101b8ee0 *sub_101ac8b0();
XIvgui_101b8ee0 *sub_101ac900();
XSchemeMgr_101b8ee0 *sub_101ac8c0();
XSurf_101b8ee0 *sub_101ac8d0();
struct XText_101b8ee0 { void sub_101b9d60(int *); };

#define T ((XThis_101b8ee0 *)this)
#define F ((XFrame_101b8ee0 *)this)

void vgui2::Frame::vfunc97()
{
	int wide = T->sub_101ab130();
	T->sub_101ab1a0();
	Color_101b8ee0 titleColor = F->m7c;
	bool hasFocus = false;
	T->sub_101b4d50();

	int focus = sub_101ac8b0()->GetFocus();
	if (focus && sub_101ac900()->HasParent(focus, T->GetVPanel()))
	{
		hasFocus = true;
		titleColor = F->m78;
	}

	if (F->m8e != hasFocus)
	{
		F->m8e = hasFocus;
		F->mb4->v166(!hasFocus);
		F->mb8->v166(!hasFocus);
		F->mbc->v166(!hasFocus);
		F->mc0->v46(hasFocus);
		F->mb4->v57(0, 0);
		F->mb8->v57(0, 0);
		F->mbc->v57(0, 0);
		F->mc0->v57(0, 0);
	}

	if (F->m8e && F->mc8)
		T->g133();

	XScheme_101b8ee0 *pScheme = sub_101ac8c0()->GetIScheme(T->sub_101aa220());
	XBorder_101b8ee0 *border = (XBorder_101b8ee0 *)pScheme->GetBorder("ButtonBorder");
	if (border)
		border->Paint(T->GetVPanel());

	sub_101ac8d0()->DrawSetColor(titleColor);
	sub_101ac8d0()->DrawFilledRect(5, 5, wide - 5, 0x1c);

	if (F->m88)
	{
		if (hasFocus)
			F->m88->SetFgColor(F->m80);
		else
			F->m88->SetFgColor(F->m84);
		sub_101ac8d0()->DrawSetTextFont(pScheme->GetFont("Default"));
		if (F->md1)
		{
			int w;
			((XText_101b8ee0 *)F->m88)->sub_101b9d60(&w);
			F->m88->SetPos((wide - w) / 2, 3);
		}
		else
		{
			F->m88->SetPos(0x1c, 9);
		}
		F->m88->Paint();
	}
}
// END FUNCTION

// FUNCTION: 0x101b9120 size=0x7
#include "vgui2__Frame.h"
int vgui2::Frame::vfunc138()
{
    return *(int *)((char *)this + 0x88);
}
// END FUNCTION

// FUNCTION: 0x101b9130 size=0x7
#include "vgui2__Frame.h"
bool vgui2::Frame::vfunc139()
{
    return *(bool *)((char *)this + 0xd1);
}
// END FUNCTION

// FUNCTION: 0x101b9140 size=0xd
#include "vgui2__Frame.h"
bool vgui2::Frame::vfunc140(char a0)
{
    *(char *)((char *)this + 0xd1) = a0;
    return *(bool *)&a0;
}
// END FUNCTION

// FUNCTION: 0x101b9150 size=0xd6
#include "vgui2__Frame.h"
#include "vgui2__Label.h"
#pragma warning(disable: 4716)

class FrameColor_101b9150
{
public:
	unsigned int m_rgba;
	FrameColor_101b9150() {}
	FrameColor_101b9150(const FrameColor_101b9150 &c) { m_rgba = c.m_rgba; }
};

class SchemeV_101b9150
{
public:
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual int GetFont(const char *pName);	// slot 4
	virtual void v5();
	virtual FrameColor_101b9150 GetSchemeColor(const char *pName);	// slot 6
};

struct FrameView_101b9150
{
	char m_pad0[0x78];
	FrameColor_101b9150 m_bgColor;			// 0x78
	FrameColor_101b9150 m_disabledBgColor;	// 0x7c
	FrameColor_101b9150 m_fgColor;			// 0x80
	FrameColor_101b9150 m_disabledFgColor;	// 0x84
	char m_pad2[0xb4 - 0x88];
	vgui2::Label *m_pMinimizeButton;	// 0xb4
	vgui2::Label *m_pMaximizeButton;	// 0xb8
	vgui2::Label *m_pSysTrayButton;		// 0xbc
};

// TARGET: vgui2::Frame::vfunc74
int vgui2::Frame::vfunc74(int pSchemeArg)
{
	SchemeV_101b9150 *pScheme = (SchemeV_101b9150 *)pSchemeArg;
	Panel::vfunc74(pSchemeArg);

	FrameView_101b9150 *v = (FrameView_101b9150 *)this;
	v->m_pMinimizeButton->vfunc118(pScheme->GetFont("Marlett"));
	v->m_pMaximizeButton->vfunc118(pScheme->GetFont("Marlett"));
	v->m_pSysTrayButton->vfunc118(pScheme->GetFont("Marlett"));

	v->m_fgColor = pScheme->GetSchemeColor("TitleBarFgColor");
	v->m_bgColor = pScheme->GetSchemeColor("TitleBarBgColor");
	v->m_disabledFgColor = pScheme->GetSchemeColor("TitleBarDisabledFgColor");
	v->m_disabledBgColor = pScheme->GetSchemeColor("TitleBarDisabledBgColor");
}
// END FUNCTION

// FUNCTION: 0x101b9230 size=0x23
#include "vgui2__Frame.h"
namespace lifted {
extern char g_102d4cdc;
struct C101b4f40 { int sub_101b4f40(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual int f15(int, int); };
}
void vgui2::Frame::vfunc75(int a0)
{
    ((lifted::V *)a0)->f15((int)&lifted::g_102d4cdc, -1);
    ((lifted::C101b4f40 *)this)->sub_101b4f40(a0);
}
// END FUNCTION

// FUNCTION: 0x101b9260 size=0x8
#include "vgui2__Frame.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); };
}
int vgui2::Frame::vfunc130()
{
    return ((lifted::V *)this)->f21(0);
}
// END FUNCTION

// FUNCTION: 0x101b9270 size=0x59
#include "vgui2__Frame.h"
#include <string.h>

int sub_101e28e0(const char *s1, const char *s2);

typedef void (__fastcall *VFn)(void *);

class Panel78View
{
public:
	void sub_101ab3d0(const char *pName);
};

void vgui2::Frame::vfunc78(int nName)
{
	const char *pName = (const char *)nName;

	if ( !sub_101e28e0( pName, "Close" ) )
	{
		(*(VFn **)this)[129]( this );
	}
	else if ( !strcmp( pName, "Minimize" ) )
	{
		(*(VFn **)this)[131]( this );
	}
	else
	{
		((Panel78View *)this)->sub_101ab3d0( pName );
	}
}
// END FUNCTION

// FUNCTION: 0x101b92d0 size=0x154
extern void *sub_101ac650(unsigned int size);

class Panel_101b92d0
{
public:
	virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
	virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
	virtual void v8() = 0; virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
	virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0; virtual void v15() = 0;
	virtual void v16() = 0; virtual void v17() = 0; virtual void v18() = 0; virtual void v19() = 0;
	virtual void v20() = 0;
	virtual void SetVisible(bool state) = 0;
	virtual bool IsVisible() = 0;
	virtual void v23() = 0; virtual void v24() = 0; virtual void v25() = 0; virtual void v26() = 0;
	virtual void v27() = 0; virtual void v28() = 0; virtual void v29() = 0; virtual void v30() = 0;
	virtual void v31() = 0; virtual void v32() = 0; virtual void v33() = 0; virtual void v34() = 0;
	virtual void v35() = 0; virtual void v36() = 0; virtual void v37() = 0;
	virtual Panel_101b92d0 *FindChildByName(const char *childName, bool recurseDown) = 0;
	virtual void v39() = 0; virtual void v40() = 0;
	virtual void AddActionSignalTarget(Panel_101b92d0 *messageTarget) = 0;
	virtual void v42() = 0; virtual void v43() = 0; virtual void v44() = 0; virtual void v45() = 0;
	virtual void SetEnabled(bool state) = 0;
};

class Menu_101b92d0 : public Panel_101b92d0
{
public:
	virtual void v47() = 0; virtual void v48() = 0; virtual void v49() = 0; virtual void v50() = 0;
	virtual void v51() = 0; virtual void v52() = 0; virtual void v53() = 0; virtual void v54() = 0;
	virtual void v55() = 0; virtual void v56() = 0; virtual void v57() = 0; virtual void v58() = 0;
	virtual void v59() = 0; virtual void v60() = 0; virtual void v61() = 0; virtual void v62() = 0;
	virtual void v63() = 0; virtual void v64() = 0; virtual void v65() = 0; virtual void v66() = 0;
	virtual void v67() = 0; virtual void v68() = 0; virtual void v69() = 0; virtual void v70() = 0;
	virtual void v71() = 0; virtual void v72() = 0; virtual void v73() = 0; virtual void v74() = 0;
	virtual void v75() = 0; virtual void v76() = 0; virtual void v77() = 0; virtual void v78() = 0;
	virtual void v79() = 0; virtual void v80() = 0; virtual void v81() = 0; virtual void v82() = 0;
	virtual void v83() = 0; virtual void v84() = 0; virtual void v85() = 0; virtual void v86() = 0;
	virtual void v87() = 0; virtual void v88() = 0; virtual void v89() = 0; virtual void v90() = 0;
	virtual void v91() = 0; virtual void v92() = 0; virtual void v93() = 0; virtual void v94() = 0;
	virtual void v95() = 0; virtual void v96() = 0; virtual void v97() = 0; virtual void v98() = 0;
	virtual void v99() = 0; virtual void v100() = 0; virtual void v101() = 0; virtual void v102() = 0;
	virtual void v103() = 0; virtual void v104() = 0; virtual void v105() = 0; virtual void v106() = 0;
	virtual void v107() = 0; virtual void v108() = 0; virtual void v109() = 0; virtual void v110() = 0;
	virtual int AddMenuItem(const char *itemName, const char *itemText, const char *command, Panel_101b92d0 *target) = 0;

	Menu_101b92d0 *sub_101bf420(Panel_101b92d0 *parent, const char *panelName);
};

class Frame_101b92d0 : public Panel_101b92d0
{
public:
	virtual void v47() = 0; virtual void v48() = 0; virtual void v49() = 0; virtual void v50() = 0;
	virtual void v51() = 0; virtual void v52() = 0; virtual void v53() = 0; virtual void v54() = 0;
	virtual void v55() = 0; virtual void v56() = 0; virtual void v57() = 0; virtual void v58() = 0;
	virtual void v59() = 0; virtual void v60() = 0; virtual void v61() = 0; virtual void v62() = 0;
	virtual void v63() = 0; virtual void v64() = 0; virtual void v65() = 0; virtual void v66() = 0;
	virtual void v67() = 0; virtual void v68() = 0; virtual void v69() = 0; virtual void v70() = 0;
	virtual void v71() = 0; virtual void v72() = 0; virtual void v73() = 0; virtual void v74() = 0;
	virtual void v75() = 0; virtual void v76() = 0; virtual void v77() = 0; virtual void v78() = 0;
	virtual void v79() = 0; virtual void v80() = 0; virtual void v81() = 0; virtual void v82() = 0;
	virtual void v83() = 0; virtual void v84() = 0; virtual void v85() = 0; virtual void v86() = 0;
	virtual void v87() = 0; virtual void v88() = 0; virtual void v89() = 0; virtual void v90() = 0;
	virtual void v91() = 0; virtual void v92() = 0; virtual void v93() = 0; virtual void v94() = 0;
	virtual void v95() = 0; virtual void v96() = 0; virtual void v97() = 0; virtual void v98() = 0;
	virtual void v99() = 0; virtual void v100() = 0; virtual void v101() = 0; virtual void v102() = 0;
	virtual void v103() = 0; virtual void v104() = 0; virtual void v105() = 0; virtual void v106() = 0;
	virtual void v107() = 0; virtual void v108() = 0; virtual void v109() = 0; virtual void v110() = 0;
	virtual void v111() = 0; virtual void v112() = 0; virtual void v113() = 0; virtual void v114() = 0;
	virtual void v115() = 0; virtual void v116() = 0; virtual void v117() = 0; virtual void v118() = 0;
	virtual void v119() = 0; virtual void v120() = 0; virtual void v121() = 0; virtual void v122() = 0;
	virtual void v123() = 0; virtual void v124() = 0; virtual void v125() = 0; virtual void v126() = 0;
	virtual void v127() = 0; virtual void v128() = 0; virtual void v129() = 0; virtual void v130() = 0;
	virtual void v131() = 0; virtual void v132() = 0; virtual void v133() = 0;
	virtual Menu_101b92d0 *sub_101b92d0();

	char m_pad04[0xb0];
	Panel_101b92d0 *_minimizeButton;
	Panel_101b92d0 *_maximizeButton;
	Panel_101b92d0 *_closeButton;
	char m_padc0[0x0c];
	Menu_101b92d0 *_sysMenu;
};

// TARGET: Frame_101b92d0::sub_101b92d0
Menu_101b92d0 *Frame_101b92d0::sub_101b92d0()
{
	if (!_sysMenu)
	{
		Menu_101b92d0 *pMenu = (Menu_101b92d0 *)sub_101ac650(0x90);
		_sysMenu = pMenu ? pMenu->sub_101bf420(this, "SysMenu") : 0;
		_sysMenu->SetVisible(false);
		_sysMenu->AddActionSignalTarget(this);

		_sysMenu->AddMenuItem("Minimize", " Mi&nimize ", "Minimize", this);
		_sysMenu->AddMenuItem("Maximize", " Ma&ximize ", "Maximize", this);
		_sysMenu->AddMenuItem("Close", " &Close ", "Close", this);

		sub_101b92d0();

		Panel_101b92d0 *pPanel = _sysMenu->FindChildByName("Minimize", false);
		if (pPanel)
		{
			pPanel->SetEnabled(_minimizeButton->IsVisible());
		}

		pPanel = _sysMenu->FindChildByName("Maximize", false);
		if (pPanel)
		{
			pPanel->SetEnabled(_maximizeButton->IsVisible());
		}

		pPanel = _sysMenu->FindChildByName("Close", false);
		if (pPanel)
		{
			pPanel->SetEnabled(_closeButton->IsVisible());
		}
	}

	return _sysMenu;
}
// END FUNCTION

// FUNCTION: 0x101b9430 size=0x34
#include "vgui2__Frame.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual int f71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual int f168(int); };
}
void vgui2::Frame::vfunc135(int a0)
{
    if (a0 != (*(int *)((char *)this + 0xcc))) {
        int t0 = ((lifted::V *)(*(int *)((char *)this + 0xcc)))->f71();
        *(int *)((char *)this + 0xcc) = a0;
        ((lifted::V *)(*(int *)((char *)this + 0xc0)))->f168(a0);
    }
}
// END FUNCTION

// FUNCTION: 0x101b9470 size=0x8
#include "vgui2__Frame.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual int f130(); };
}
int vgui2::Frame::vfunc129()
{
    return ((lifted::V *)this)->f130();
}
// END FUNCTION

// FUNCTION: 0x101b9480 size=0x23
#include "vgui2__Frame.h"
namespace lifted {
int sub_101ac8d0();
struct V { virtual int f0(int); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual int f44(int); };
}
int vgui2::Frame::vfunc131()
{
    return ((lifted::V *)(lifted::sub_101ac8d0()))->f44(((lifted::V *)this)->f0(1));
}
// END FUNCTION

// FUNCTION: 0x101b94b0 size=0x5a
#include "vgui2__Frame.h"

struct VGuiSystemView
{
	virtual void s0();
	virtual void s1();
	virtual void s2();
	virtual void *s3();
};

struct VGuiSurfaceView
{
	virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
	virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
	virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
	virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
	virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual bool s20(void *, int);
};

int sub_101ac8b0();
int sub_101ac900();

namespace vgui2
{
void Frame::vfunc87(int a)
{
	if (!vfunc67())
	{
		void *p = ((VGuiSystemView *)sub_101ac8b0())->s3();
		if (!p || !((VGuiSurfaceView *)sub_101ac900())->s20(p, vfunc0()))
			vfunc15(0);
	}
	Panel::vfunc87(a);
}
}
// END FUNCTION

// FUNCTION: 0x101b9510 size=0x2a
#include "vgui2__Frame.h"
struct IV { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int v6(); };
struct FView {
	virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9();
	virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
	virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24(); virtual void a25(); virtual void a26(); virtual void a27(); virtual void a28(); virtual void a29(); virtual void a30();
	virtual IV *v31();
};
int vgui2::Frame::vfunc21(int a)
{
	sub_101a99f0(a);
	int r = (int)((FView *)this)->v31();
	if (r)
		r = ((FView *)this)->v31()->v6();
	return r;
}
// END FUNCTION

// FUNCTION: 0x101b9540 size=0x13
#include "vgui2__Frame.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(float); };
}
int vgui2::Frame::vfunc123(float a0)
{
    return ((lifted::V *)(*(int *)((char *)this + 0xc0)))->f21(a0);
}
// END FUNCTION

// FUNCTION: 0x101b9580 size=0x13
#include "vgui2__Frame.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(float); };
}
int vgui2::Frame::vfunc126(float a0)
{
    return ((lifted::V *)(*(int *)((char *)this + 0xb4)))->f21(a0);
}
// END FUNCTION

// FUNCTION: 0x101b95a0 size=0x13
#include "vgui2__Frame.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(float); };
}
int vgui2::Frame::vfunc127(float a0)
{
    return ((lifted::V *)(*(int *)((char *)this + 0xb8)))->f21(a0);
}
// END FUNCTION

// FUNCTION: 0x101b95c0 size=0x13
#include "vgui2__Frame.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(float); };
}
int vgui2::Frame::vfunc128(float a0)
{
    return ((lifted::V *)(*(int *)((char *)this + 0xbc)))->f21(a0);
}
// END FUNCTION

// FUNCTION: 0x101b95e0 size=0x3
#include "vgui2__Frame.h"
void vgui2::Frame::vfunc91(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101b95f0 size=0x3
#include "vgui2__Frame.h"
void vgui2::Frame::vfunc94(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101b9600 size=0x1
#include "vgui2__Frame.h"
void vgui2::Frame::vfunc95()
{
}
// END FUNCTION

// FUNCTION: 0x101b9610 size=0x84
#include "vgui2__Frame.h"
#include "vgui2__KeyValues.h"
struct ISurfV {
	virtual int s0(); virtual int s1(); virtual int s2(); virtual int s3(); virtual int s4(); virtual int s5(); virtual int s6(); virtual int s7(); virtual int s8(); virtual int s9();
	virtual int s10(); virtual int s11(); virtual int s12(); virtual int s13(); virtual int s14(); virtual int s15(); virtual int s16(); virtual int s17(); virtual int s18(); virtual int s19();
	virtual int s20(); virtual int s21(); virtual int s22(); virtual int s23(); virtual int s24(); virtual int s25(); virtual int s26(); virtual int s27(); virtual int s28(); virtual int s29();
	virtual int s30(); virtual int s31(); virtual int s32(); virtual int s33(); virtual int s34(); virtual int s35(); virtual int s36(); virtual int s37(); virtual int s38(); virtual int s39();
	virtual int s40(); virtual int s41(); virtual int s42(); virtual int s43(); virtual int s44();
	virtual void FlashWindow(int panel, bool flash);
};
ISurfV *sub_101ac8d0();
// TARGET: vgui2::Frame::vfunc143
void vgui2::Frame::vfunc143()
{
	if (*(bool *)((char *)this + 0xc8)) {
		*(bool *)((char *)this + 0xc9) = true;
		sub_101ac8d0()->FlashWindow(vfunc0(), *(bool *)((char *)this + 0xc9));
		*(bool *)((char *)this + 0xc9) = !*(bool *)((char *)this + 0xc9);
		vgui2::KeyValues *kv = new vgui2::KeyValues("FlashWindow");
		vfunc23(this, kv, (void *)0x3fe66666);
	}
}
// END FUNCTION

// FUNCTION: 0x101b96b0 size=0x16
#include "vgui2__Frame.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual int f143(); };
}
int vgui2::Frame::vfunc132()
{
    *(char *)((char *)this + 0xc8) = 1;
    *(char *)((char *)this + 0xc9) = 1;
    return ((lifted::V *)this)->f143();
}
// END FUNCTION

// FUNCTION: 0x101b96d0 size=0x2a
#include "vgui2__Frame.h"
struct XSurf { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(int); };
struct XPanel { virtual int g0(int); };
XSurf *sub_101ac8d0();
// TARGET: vgui2::Frame::vfunc133
void vgui2::Frame::vfunc133()
{
	XSurf *s = sub_101ac8d0();
	s->v45(((XPanel *)this)->g0(0));
	*((char *)this + 0xc8) = 0;
}
// END FUNCTION

// FUNCTION: 0x101b9700 size=0x34
#include "vgui2__Frame.h"
struct ChildView {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void SetVisibleLike(int a);
};
struct HolderView {
	virtual ChildView *Get();
};
// TARGET: vgui2::Frame::vfunc107
void vgui2::Frame::vfunc107(int a)
{
	sub_101b4d70(a);
	ChildView *p = ((HolderView *)vfunc116())->Get();
	if (p)
		p->SetVisibleLike(0);
}
// END FUNCTION

// FUNCTION: 0x101b9740 size=0x226
#include "vgui2__Frame.h"
#include "vgui2__KeyValues.h"
struct Q11_Input
{
	virtual void v0(); virtual void v1();
	virtual int vfunc2(int, char *, int);
	virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual bool vfunc12(int);
};
struct Q11_Surf { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int vfunc6(); };
struct Q11_Obj { virtual void v0(); virtual vgui2::Panel *vfunc1(); };
struct Q11_IPanel { virtual void v0(); virtual Q11_Obj *vfunc1(int); };
struct Q11_Scheme { virtual void v0(); virtual void v1(); virtual void vfunc2(); };
struct Q11_Hot { virtual void v0(); virtual void v1(); virtual vgui2::Panel *vfunc2(); virtual vgui2::Panel *vfunc3(int); };
Q11_Input *sub_101ac8b0();
Q11_Scheme *sub_101ac8c0();
Q11_Surf *sub_101ac8d0();
Q11_IPanel *sub_101ac900();

// TARGET: vgui2::Frame::vfunc92
void vgui2::Frame::vfunc92(int code)
{
	bool shift = sub_101ac8b0()->vfunc12(0x4f) || sub_101ac8b0()->vfunc12(0x50);
	bool ctrl = sub_101ac8b0()->vfunc12(0x53) || sub_101ac8b0()->vfunc12(0x54);
	bool alt = sub_101ac8b0()->vfunc12(0x51) || sub_101ac8b0()->vfunc12(0x52);
	if (ctrl && shift && alt && code == 0xc)
	{
		vfunc108();
	}
	else if (ctrl && shift && alt && code == 0x1c)
	{
		int top = sub_101ac8d0()->vfunc6();
		if (top)
		{
			vgui2::Panel *pPanel = sub_101ac900()->vfunc1(top)->vfunc1();
			if (pPanel)
			{
				sub_101ac8c0()->vfunc2();
				pPanel->vfunc57(0, 1);
			}
		}
	}
	else if (alt && code == 0x5f)
	{
		vfunc23(this, new vgui2::KeyValues("Close"), 0);
	}
	else if (code == 0x40)
	{
		vgui2::Panel *pPanel = ((Q11_Hot *)vfunc116())->vfunc2();
		if (pPanel)
			vfunc23(pPanel, new vgui2::KeyValues("Hotkey"), 0);
	}
	else if (code != 0x43 && alt)
	{
		char buf[2];
		sub_101ac8b0()->vfunc2(code, buf, 2);
		if (buf[0])
		{
			vgui2::Panel *pPanel = ((Q11_Hot *)vfunc116())->vfunc3(code);
			if (pPanel)
				vfunc23(pPanel, new vgui2::KeyValues("Hotkey"), 0);
		}
	}
}
// END FUNCTION

// FUNCTION: 0x101b9970 size=0x3
#include "vgui2__Frame.h"
void vgui2::Frame::vfunc93(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x101b9ac0 size=0x6
#include "vgui2__Frame.h"
namespace lifted {
extern char g_102d8ee8;
}
int vgui2::Frame::vfunc102()
{
    return (int)&lifted::g_102d8ee8;
}
// END FUNCTION

// FUNCTION: 0x101b9ad0 size=0x7f
#include "vgui2__Frame.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); };
}
int vgui2::Frame::vfunc136(int a0)
{
    *(char *)((char *)this + 0xd0) = a0;
    ((lifted::V *)(*(int *)((char *)this + 0x90)))->f21(a0);
    ((lifted::V *)(*(int *)((char *)this + 0x94)))->f21(a0);
    ((lifted::V *)(*(int *)((char *)this + 0x98)))->f21(a0);
    ((lifted::V *)(*(int *)((char *)this + 0x9c)))->f21(a0);
    ((lifted::V *)(*(int *)((char *)this + 0xa0)))->f21(a0);
    ((lifted::V *)(*(int *)((char *)this + 0xa4)))->f21(a0);
    ((lifted::V *)(*(int *)((char *)this + 0xa8)))->f21(a0);
    ((lifted::V *)(*(int *)((char *)this + 0xac)))->f21(a0);
    return ((lifted::V *)(*(int *)((char *)this + 0xb0)))->f21(a0);
}
// END FUNCTION

// FUNCTION: 0x101b9b50 size=0x2b
#include "vgui2__Frame.h"
int vgui2::Frame::vfunc137(int a0, int a1, int a2, int a3)
{
    *(int *)((char *)this + 0xd4) = a0;
    *(int *)((char *)this + 0xd8) = a1;
    *(int *)((char *)this + 0xdc) = a2;
    *(int *)((char *)this + 0xe0) = a3;
    return a2;
}
// END FUNCTION
