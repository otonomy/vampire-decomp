// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101ca820 size=0x1e
#include "vgui2__PanelListPanel.h"

// VC6 writes vgui2::PanelListPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::PanelListPanel *pcd_emit_101ca820(const vgui2::PanelListPanel &other) { return new vgui2::PanelListPanel(other); }

// TARGET: ??_GPanelListPanel@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101ca910 size=0x21
#include "vgui2__PanelListPanel.h"
int vgui2::PanelListPanel::vfunc113(int a0)
{
	if (a0 >= 0 && a0 < *(int *)((char *)this + 0x58)) {
		int *p = (*(int ***)((char *)this + 0x60))[a0];
		if (p)
			return *p;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x101cab10 size=0x4
#include "vgui2__PanelListPanel.h"
int vgui2::PanelListPanel::vfunc109()
{
    return *(int *)((char *)this + 0x58);
}
// END FUNCTION

// FUNCTION: 0x101cab80 size=0x6e
#include "vgui2__PanelListPanel.h"

namespace vgui2
{
struct PanelListPanelItem
{
	Panel *m_pPanel;
};

struct PanelListPanelView
{
	char m_pad[0x58];
	int m_nItems;		// 0x58
	int m_unk5c;		// 0x5c
	PanelListPanelItem **m_ppItems;	// 0x60
};

void PanelListPanel::sub_101cab80(int itemID)
{
	PanelListPanelView *v = (PanelListPanelView *)this;

	PanelListPanelItem *data = ( itemID >= 0 && itemID < v->m_nItems ) ? v->m_ppItems[itemID] : 0;

	delete data->m_pPanel;
	delete data;

	if ( itemID >= 0 && itemID < v->m_nItems )
	{
		for ( int i = itemID; i < v->m_nItems - 1; i++ )
			v->m_ppItems[i] = v->m_ppItems[i + 1];
		v->m_nItems--;
	}

	vfunc57(0, 0);
}
}
// END FUNCTION

// FUNCTION: 0x101cabf0 size=0x77
#include "vgui2__PanelListPanel.h"

struct PItem
{
	vgui2::Panel *panel;
};

struct PVec
{
	char pad[0x58];
	volatile int m_Size;
	char pad5c[4];
	PItem ** volatile m_pMem;
};

static inline PItem *GetItem(PVec *v, int i)
{
	if (i < 0 || i >= v->m_Size)
		return 0;
	return v->m_pMem[i];
}

void vgui2::PanelListPanel::vfunc112()
{
	int i;
	for (i = 0; i < ((PVec *)this)->m_Size; i++)
	{
		if (GetItem((PVec *)this, i))
			delete GetItem((PVec *)this, i)->panel;
		delete GetItem((PVec *)this, i);
	}
	((PVec *)this)->m_Size = 0;
	vfunc57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101cac80 size=0x26
#include "vgui2__PanelListPanel.h"
namespace lifted {
struct C101a98f0 { int sub_101a98f0(int, int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int vgui2::PanelListPanel::vfunc114(int a0, int a1)
{
    ((lifted::C101a98f0 *)this)->sub_101a98f0(a0, a1);
    return ((lifted::V *)this)->f57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101cacb0 size=0x27d
#include "vgui2__PanelListPanel.h"

struct ScrollBarView_101cacb0
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20();
	virtual void vfunc21(int);
	virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
	virtual void v45();
	virtual void vfunc46(int);
	virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
	virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
	virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
	virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
	virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70();
	virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
	virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80();
	virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85();
	virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90();
	virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
	virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100();
	virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105();
	virtual void v106();
	virtual int vfunc107();
	virtual int vfunc108();
	virtual void vfunc109(int, int);
	virtual void vfunc110(int);
	virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115();
	virtual void v116(); virtual void v117();
	virtual void vfunc118(int);
};

struct SurfaceView_101cacb0
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38();
	virtual void vfunc39(int &wide, int &tall);
};
SurfaceView_101cacb0 *sub_101ac8d0();

struct ListItem_101cacb0 { vgui2::Panel *panel; };
struct ItemVec_101cacb0
{
	int m_Size;
	int m_unk;
	ListItem_101cacb0 **m_pData;
	int Count() const { return m_Size; }
	ListItem_101cacb0 *Get(int i) const { return (i >= 0 && i < m_Size) ? m_pData[i] : 0; }
};

#define LP_ITEMS (*(ItemVec_101cacb0 *)((char *)this + 0x58))
#define LP_VBAR (*(ScrollBarView_101cacb0 **)((char *)this + 0x64))
#define LP_EMBEDDED (*(vgui2::Panel **)((char *)this + 0x68))
#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif

namespace vgui2
{
void PanelListPanel::vfunc101()
{
	int wide, tall;
	sub_101a9920(&wide, &tall);

	int vpixels = ((ScrollBarView_101cacb0 *)this)->vfunc107();

	LP_VBAR->vfunc21(1);
	LP_VBAR->vfunc46(0);
	LP_VBAR->vfunc109(0, vpixels);
	LP_VBAR->vfunc110(tall - 2);
	LP_VBAR->vfunc118(0x18);
	((Panel *)LP_VBAR)->sub_101a9890(wide - 0x12, 1);
	((Panel *)LP_VBAR)->sub_101a98f0(0x12, tall - 2);

	int top = LP_VBAR->vfunc108();

	LP_EMBEDDED->sub_101a9890(1, -top);
	LP_EMBEDDED->sub_101a98f0(wide - 0x14, vpixels);

	top = LP_VBAR->vfunc108();

	int y = 0;
	int h = 0;
	int totalh = 0;
	int sw, sh;
	sub_101ac8d0()->vfunc39(sw, sh);
	for (int i = 0; i < LP_ITEMS.Count(); i += 2, y += h)
	{
		y += 5;
		ListItem_101cacb0 *label = LP_ITEMS.Get(i);
		ListItem_101cacb0 *item = LP_ITEMS.Get(i + 1);
		if (!label)
			continue;
		Panel *pLabel = label->panel;
		if (!pLabel || !item)
			continue;
		Panel *pItem = item->panel;
		if (!pItem)
			continue;

		h = max(pLabel->sub_101ab1a0(), pItem->sub_101ab1a0());
		if ((totalh += h) < top)
			continue;

		label->panel->sub_101a9950((int)(8.0 * (sw / 1024.0)), y, m_i74, pLabel->sub_101ab1a0());

		item = LP_ITEMS.Get(i + 1);
		int labelWide = m_i74;
		item->panel->sub_101a9950((int)(labelWide + (8.0 * (sw / 1024.0)) + 5.0), y, (int)((wide - labelWide) - 36.0 * (sw / 1024.0)), pItem->sub_101ab1a0());
	}
}
}
// END FUNCTION

// FUNCTION: 0x101caf40 size=0x75
#include "vgui2__PanelListPanel.h"

struct ISchemeV
{
	virtual void vf0();
	virtual void vf1();
	virtual void vf2();
	virtual void *GetBorder(const char *name);
	virtual void vf4();
	virtual int *GetColor(int *out, const char *name);
	virtual int *GetColor(int *out, const char *name, int def);
};

#pragma warning(disable:4716)
int vgui2::PanelListPanel::vfunc74(int hScheme)
{
	ISchemeV *pScheme = (ISchemeV *)hScheme;
	Panel::vfunc74(hScheme);
	vfunc60(pScheme->GetBorder("ButtonDepressedBorder"));
	int c1, c2;
	vfunc50(*pScheme->GetColor(&c2, "ListBgColor",
		*pScheme->GetColor(&c1, "WindowDisabledBgColor")));
	vfunc60(pScheme->GetBorder("DepressedButtonBorder"));
}
// END FUNCTION

// FUNCTION: 0x101cafc0 size=0x1a
#include "vgui2__PanelListPanel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual int f6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int vgui2::PanelListPanel::vfunc115(int a0)
{
    ((lifted::V *)this)->f57(0, 0);
    return ((lifted::V *)this)->f6();
}
// END FUNCTION

// FUNCTION: 0x101cafe0 size=0xe
#include "vgui2__PanelListPanel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual int f107(int); };
}
int vgui2::PanelListPanel::vfunc116()
{
    return ((lifted::V *)(*(int *)((char *)this + 0x64)))->f107(0);
}
// END FUNCTION

// FUNCTION: 0x101cb090 size=0x6
#include "vgui2__PanelListPanel.h"
namespace lifted {
extern char g_102daed0;
}
int vgui2::PanelListPanel::vfunc102()
{
    return (int)&lifted::g_102daed0;
}
// END FUNCTION
