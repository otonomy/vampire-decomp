// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10163b10 size=0x1e
#include "CBasePanel.h"

// VC6 writes CBasePanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CBasePanel *pcd_emit_10163b10(const CBasePanel &other) { return new CBasePanel(other); }

// TARGET: ??_GCBasePanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10163bf0 size=0x40
#include "CInput.h"
struct IUnkGlob {
	virtual void v0();
	virtual bool IsX();
};
struct CUnkMgr : IUnkGlob { int m_n4[10]; int m_n2c; };
extern CUnkMgr *g_105faa34;
int sub_10163bf0()
{
	if (!g_105faa34->IsX() && g_105faa34->m_n2c && input->vfunc52() == 0.0f)
		return 1;
	return 0;
}
// END FUNCTION

// FUNCTION: 0x10163c30 size=0x157
#include "CBasePanel.h"

class ISurface_10163c30
{
public:
	virtual void v0() = 0;
	virtual void v1() = 0;
	virtual void v2() = 0;
	virtual void v3() = 0;
	virtual void v4() = 0;
	virtual void v5() = 0;
	virtual void v6() = 0;
	virtual void v7() = 0;
	virtual void v8() = 0;
	virtual void v9() = 0;
	virtual void DrawSetColor(int col) = 0; // slot 10 (+0x28)
	virtual void v11() = 0;
	virtual void v12() = 0;
	virtual void v13() = 0;
	virtual void v14() = 0;
	virtual void v15() = 0;
	virtual void v16() = 0;
	virtual void v17() = 0;
	virtual void v18() = 0;
	virtual void v19() = 0;
	virtual void v20() = 0;
	virtual void v21() = 0;
	virtual void v22() = 0;
	virtual void v23() = 0;
	virtual void v24() = 0;
	virtual void v25() = 0;
	virtual void v26() = 0;
	virtual void DrawSetTextureFile(int id, const char *filename, int hardwareFilter) = 0; // slot 27 (+0x6c)
	virtual void v28() = 0;
	virtual void v29() = 0;
	virtual void v30() = 0;
	virtual void DrawSetTexture(int id) = 0; // slot 31 (+0x7c)
	virtual void DrawGetTextureSize(int id, int &wide, int &tall) = 0; // slot 32 (+0x80)
	virtual void DrawTexturedRect(int x0, int y0, int x1, int y1) = 0; // slot 33 (+0x84)
	virtual void v34() = 0;
	virtual void v35() = 0;
	virtual void v36() = 0;
	virtual void v37() = 0;
	virtual int CreateNewTextureID(bool procedural) = 0; // slot 38 (+0x98)
};

ISurface_10163c30 *sub_101ac8d0();

struct PanelHelper_10163c30
{
	void sub_101a9920(int &wide, int &tall);
	void sub_101a9ea0();
};

struct CBasePanelFields_10163c30
{
	char pad0[0x58];
	bool m_bHasBg;
	char pad59[3];
	int m_iTextureID;
	char m_szTexture[0x100];
	bool m_bTile;
	char pad161[3];
	int m_iTileWide;
	int m_iTileTall;
};

// TARGET: CBasePanel::vfunc97
void CBasePanel::vfunc97()
{
	CBasePanelFields_10163c30 *f = (CBasePanelFields_10163c30 *)this;
	if (!f->m_bHasBg)
	{
		((PanelHelper_10163c30 *)this)->sub_101a9ea0();
		return;
	}

	if (f->m_iTextureID == -1)
	{
		f->m_iTextureID = sub_101ac8d0()->CreateNewTextureID(false);
		sub_101ac8d0()->DrawSetTextureFile(f->m_iTextureID, f->m_szTexture, 0);
	}

	int col;
	sub_101ac8d0()->DrawSetColor(*(int *)vfunc53((int)&col));
	sub_101ac8d0()->DrawSetTexture(f->m_iTextureID);

	if (f->m_bTile && !f->m_iTileWide)
	{
		sub_101ac8d0()->DrawGetTextureSize(f->m_iTextureID, f->m_iTileWide, f->m_iTileTall);
	}

	int w, h;
	((PanelHelper_10163c30 *)this)->sub_101a9920(w, h);

	if (f->m_bTile && f->m_iTileWide && f->m_iTileTall)
	{
		int x = 0;
		int y = 0;
		while (y < h)
		{
			sub_101ac8d0()->DrawTexturedRect(0, 0, f->m_iTileWide, f->m_iTileTall);
			x += f->m_iTileWide;
			if (x >= w)
			{
				x = 0;
				y += f->m_iTileTall;
			}
		}
	}
	else
	{
		sub_101ac8d0()->DrawTexturedRect(0, 0, w, h);
	}
}
// END FUNCTION

// FUNCTION: 0x10163d90 size=0x22
#include "CBasePanel.h"
namespace lifted {
int sub_101ac8d0();
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual int f30(int); };
}
void CBasePanel::vfunc110()
{
    if ((*(int *)((char *)this + 0x5c)) != -1) {
        int t0 = ((lifted::V *)(lifted::sub_101ac8d0()))->f30(*(int *)((char *)this + 0x5c));
        *(int *)((char *)this + 0x5c) = -1;
    }
}
// END FUNCTION

// FUNCTION: 0x10163dc0 size=0x5d
#include "CBasePanel.h"

struct VGuiView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
	virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26();
	virtual void v27(int, const char *, int);
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
	virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
	virtual int v38(int);
};

extern "C" char *(*g_101e3188)(char *, const char *, int);
VGuiView *sub_101ac8d0();

// TARGET: CBasePanel::vfunc108
void CBasePanel::vfunc108(const char *name, char b)
{
	vfunc110();
	*(char *)((char *)this + 0x58) = 1;
	*(char *)((char *)this + 0x160) = b;
	g_101e3188((char *)this + 0x60, name, 0x100);
	*(int *)((char *)this + 0x5c) = sub_101ac8d0()->v38(0);
	VGuiView *v = sub_101ac8d0();
	v->v27(*(int *)((char *)this + 0x5c), (char *)this + 0x60, 0);
}
// END FUNCTION

// FUNCTION: 0x10163e20 size=0x7c
#include "CBasePanel.h"
struct ISurf { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void Set(int h, float f); };
ISurf *sub_101ac8d0();
void CBasePanel::vfunc109(float f)
{
	if (*(char *)((char *)this + 0x58)) {
		double d;
		if (f > 1.0) d = 1.0;
		else if (f < 0.0) d = 0.0;
		else d = f;
		sub_101ac8d0()->Set(*(int *)((char *)this + 0x5c), (float)d);
	}
}
// END FUNCTION

// FUNCTION: 0x10163ea0 size=0xa
#include "CBasePanel.h"
void CBasePanel::vfunc111(int a0)
{
    *(char *)((char *)this + 0x16c) = 1;
}
// END FUNCTION

// FUNCTION: 0x10163eb0 size=0x9b
#include "CBasePanel.h"
#define V10(p) virtual int p##0(); virtual int p##1(); virtual int p##2(); virtual int p##3(); virtual int p##4(); virtual int p##5(); virtual int p##6(); virtual int p##7(); virtual int p##8(); virtual int p##9();
struct KVX { KVX *sub_101b5730(const char *, const char *, int, const char *, int); };
struct IVGuiX { V10(a) V10(b) virtual int vfunc20(int, KVX *, int, int); };
struct PanelX {
    virtual int vfunc0();
    V10(b) V10(c) virtual int c10(); virtual int c11(); virtual int c12(); virtual int c13(); virtual int c14();
    virtual void vfunc26(int *, int *);
    virtual int c27(); virtual int c28(); virtual int c29(); virtual int c30();
    virtual PanelX *vfunc31();
};
void *sub_101b6840(int);
IVGuiX *sub_101ac8f0();
// TARGET: CBasePanel::vfunc84
void CBasePanel::vfunc84(int x, int y)
{
    if (*((char *)this + 0x16c)) {
        PanelX *target = ((PanelX *)this)->vfunc31();
        if (target) {
            ((PanelX *)this)->vfunc26(&x, &y);
            KVX *p = (KVX *)sub_101b6840(0x1c);
            KVX *kv = p ? p->sub_101b5730("CursorMoved", "xpos", x, "ypos", y) : 0;
            PanelX *t2 = ((PanelX *)this)->vfunc31();
            IVGuiX *vgui = sub_101ac8f0();
            vgui->vfunc20(t2->vfunc0(), kv, ((PanelX *)this)->vfunc0(), 0);
        }
    }
}
// END FUNCTION

// FUNCTION: 0x10163f50 size=0x7a
#include "CBasePanel.h"

extern void *sub_101b6840(int);
extern void *sub_101ac8f0();

class CUnknown101b56c0
{
public:
	void *sub_101b56c0(const char *, const char *, int);
};

struct IVGuiView
{
	virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3();
	virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7();
	virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11();
	virtual void g12(); virtual void g13(); virtual void g14(); virtual void g15();
	virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19();
	virtual void g20(int, void *, int, int);
};

void CBasePanel::vfunc87(int code)
{
	if (!((char *)this)[0x16c])
		return;

	vgui2::Panel *p = (vgui2::Panel *)vfunc31();
	if (!p)
		return;

	void *kv;
	void *k = sub_101b6840(0x1c);
	if (k)
		kv = ((CUnknown101b56c0 *)k)->sub_101b56c0("MousePressed", "code", code);
	else
		kv = 0;

	vgui2::Panel *p2 = (vgui2::Panel *)vfunc31();
	void *vgui = sub_101ac8f0();
	((IVGuiView *)vgui)->g20(p2->vfunc0(), kv, vfunc0(), 0);
}
// END FUNCTION

// FUNCTION: 0x10163fd0 size=0x7a
#include "CBasePanel.h"

extern void *sub_101b6840(int);
extern void *sub_101ac8f0();

class CUnknown101b56c0
{
public:
	void *sub_101b56c0(const char *, const char *, int);
};

struct IVGuiView
{
	virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3();
	virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7();
	virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11();
	virtual void g12(); virtual void g13(); virtual void g14(); virtual void g15();
	virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19();
	virtual void g20(int, void *, int, int);
};

void CBasePanel::vfunc88(int code)
{
	if (!((char *)this)[0x16c])
		return;

	vgui2::Panel *p = (vgui2::Panel *)vfunc31();
	if (!p)
		return;

	void *kv;
	void *k = sub_101b6840(0x1c);
	if (k)
		kv = ((CUnknown101b56c0 *)k)->sub_101b56c0("MouseDoublePressed", "code", code);
	else
		kv = 0;

	vgui2::Panel *p2 = (vgui2::Panel *)vfunc31();
	void *vgui = sub_101ac8f0();
	((IVGuiView *)vgui)->g20(p2->vfunc0(), kv, vfunc0(), 0);
}
// END FUNCTION

// FUNCTION: 0x10164050 size=0x7a
#include "CBasePanel.h"

extern void *sub_101b6840(int);
extern void *sub_101ac8f0();

class CUnknown101b56c0
{
public:
	void *sub_101b56c0(const char *, const char *, int);
};

struct IVGuiView
{
	virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3();
	virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7();
	virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11();
	virtual void g12(); virtual void g13(); virtual void g14(); virtual void g15();
	virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19();
	virtual void g20(int, void *, int, int);
};

void CBasePanel::vfunc89(int code)
{
	if (!((char *)this)[0x16c])
		return;

	vgui2::Panel *p = (vgui2::Panel *)vfunc31();
	if (!p)
		return;

	void *kv;
	void *k = sub_101b6840(0x1c);
	if (k)
		kv = ((CUnknown101b56c0 *)k)->sub_101b56c0("MouseReleased", "code", code);
	else
		kv = 0;

	vgui2::Panel *p2 = (vgui2::Panel *)vfunc31();
	void *vgui = sub_101ac8f0();
	((IVGuiView *)vgui)->g20(p2->vfunc0(), kv, vfunc0(), 0);
}
// END FUNCTION

// FUNCTION: 0x101640d0 size=0x7a
#include "CBasePanel.h"

extern void *sub_101b6840(int);
extern void *sub_101ac8f0();

class CUnknown101b56c0
{
public:
	void *sub_101b56c0(const char *, const char *, int);
};

struct IVGuiView
{
	virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3();
	virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7();
	virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11();
	virtual void g12(); virtual void g13(); virtual void g14(); virtual void g15();
	virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19();
	virtual void g20(int, void *, int, int);
};

void CBasePanel::vfunc90(int code)
{
	if (!((char *)this)[0x16c])
		return;

	vgui2::Panel *p = (vgui2::Panel *)vfunc31();
	if (!p)
		return;

	void *kv;
	void *k = sub_101b6840(0x1c);
	if (k)
		kv = ((CUnknown101b56c0 *)k)->sub_101b56c0("MouseWheeled", "delta", code);
	else
		kv = 0;

	vgui2::Panel *p2 = (vgui2::Panel *)vfunc31();
	void *vgui = sub_101ac8f0();
	((IVGuiView *)vgui)->g20(p2->vfunc0(), kv, vfunc0(), 0);
}
// END FUNCTION

// FUNCTION: 0x10164150 size=0x1
#include "CBasePanel.h"
void CBasePanel::vfunc2()
{
}
// END FUNCTION
