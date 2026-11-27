// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101bb0f0 size=0x1e
#include "vgui2__LabelComboBox.h"

// VC6 writes vgui2::LabelComboBox's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::LabelComboBox *pcd_emit_101bb0f0(const vgui2::LabelComboBox &other) { return new vgui2::LabelComboBox(other); }

// TARGET: ??_GLabelComboBox@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101bb110 size=0x33
#include "vgui2__LabelComboBox.h"
vgui2::LabelComboBox::~LabelComboBox()
{
	vgui2::Panel *a = *(vgui2::Panel **)((char *)this + 0xf8);
	if (a)
		delete a;
	vgui2::Panel *b = *(vgui2::Panel **)((char *)this + 0xfc);
	if (b)
		delete b;
}
// END FUNCTION

// FUNCTION: 0x101bb180 size=0xe
#include "vgui2__LabelComboBox.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual int f110(); };
}
int vgui2::LabelComboBox::vfunc166()
{
    return ((lifted::V *)(*(int *)((char *)this + 0xf8)))->f110();
}
// END FUNCTION

// FUNCTION: 0x101bb1a0 size=0xd2
#include "vgui2__LabelComboBox.h"
#include "vgui2__Button.h"

int sub_101ac8d0();

struct TEntV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(int);
	virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
	virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
	virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
	virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
	virtual void v45();
	virtual void v46(bool);
	virtual void v47();
	virtual bool v48();
	virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52();
	virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56();
	virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60();
	virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
	virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68();
	virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72();
	virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76();
	virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80();
	virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
	virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88();
	virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92();
	virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96();
	virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100();
	virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104();
	virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108();
	virtual void v109(); virtual void v110(); virtual void v111(); virtual void v112();
	virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116();
	virtual void v117(); virtual void v118(); virtual void v119(); virtual void v120();
	virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124();
	virtual void v125();
	virtual void v126(int);
	int sub_101ab130();
	void sub_101a9950(int, int, int, int);
};

struct ISchemeV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
	virtual void v36(); virtual void v37(); virtual void v38();
	virtual void v39(int &a, int &b);
};

void vgui2::LabelComboBox::vfunc101()
{
	((TEntV *)*(void **)((char *)this + 0xf8))->v126(((TEntV *)this)->sub_101ab130());

	int wide, tall;
	this->vfunc65(wide, tall);

	int a, b;
	((ISchemeV *)sub_101ac8d0())->v39(a, b);

	int x = (int)((wide - tall) + (a / 1024.0) * 4.0);

	((TEntV *)*(void **)((char *)this + 0xfc))->sub_101a9950(x, 0, tall, tall);

	if ( !((TEntV *)*(void **)((char *)this + 0xf8))->v48() )
		((TEntV *)*(void **)((char *)this + 0xf8))->v28(0);

	((TEntV *)*(void **)((char *)this + 0xfc))->v46(this->vfunc47());

	this->Button::vfunc101();
}
// END FUNCTION

// FUNCTION: 0x101bb280 size=0x11
#include "vgui2__LabelComboBox.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual int f147(); };
}
void vgui2::LabelComboBox::vfunc87(int a0)
{
    ((lifted::V *)(*(int *)((char *)this + 0xfc)))->f147();
}
// END FUNCTION

// FUNCTION: 0x101bb2a0 size=0xe
#include "vgui2__LabelComboBox.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual void u168(); virtual int f169(); };
}
int vgui2::LabelComboBox::vfunc167()
{
    return ((lifted::V *)(*(int *)((char *)this + 0xfc)))->f169();
}
// END FUNCTION

// FUNCTION: 0x101bb2b0 size=0x33
#include "vgui2__LabelComboBox.h"
struct LCBView {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
	virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
	virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
	virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
	virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
	virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
	virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
	virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
	virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104();
	virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
	virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114();
	virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(int);
	virtual void v119(); virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123();
	virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127(); virtual void v128();
	virtual void v129(); virtual void v130(int);
};
// TARGET: vgui2::LabelComboBox::vfunc118
void vgui2::LabelComboBox::vfunc118(int a)
{
	((LCBView *)*(int *)((char *)this + 0xf8))->v130(a);
	((LCBView *)*(int *)((char *)this + 0xfc))->v118(a);
	Label::vfunc118(a);
}
// END FUNCTION
