// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101bf4d0 size=0x1e
#include "vgui2__Menu.h"

// VC6 writes vgui2::Menu's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::Menu *pcd_emit_101bf4d0(const vgui2::Menu &other) { return new vgui2::Menu(other); }

// TARGET: ??_GMenu@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101bf4f0 size=0x2b
#include "vgui2__Menu.h"
namespace vgui2 {
Menu::~Menu()
{
	Panel *p = *(Panel **)((char *)this + 0x70);
	if (p)
		delete p;
	::operator delete(*(void **)((char *)this + 0x6c));
}
}
// END FUNCTION

// FUNCTION: 0x101bf660 size=0x5f
#include "vgui2__Menu.h"
#include "vgui2__MenuItem.h"

void *sub_101ac650(unsigned int size);
inline void *operator new(unsigned int, void *p) { return p; }

struct MenuItemV_101bf660 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40();
	virtual void v41(int);
	virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
	virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
	virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56();
	virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61();
	virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66();
	virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
	virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76();
	virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81();
	virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86();
	virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
	virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96();
	virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101();
	virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106();
	virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
	virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116();
	virtual void v117(); virtual void v118(); virtual void v119(); virtual void v120(); virtual void v121();
	virtual void v122(); virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126();
	virtual void v127(); virtual void v128(); virtual void v129(); virtual void v130(); virtual void v131();
	virtual void v132(); virtual void v133(); virtual void v134(); virtual void v135(); virtual void v136();
	virtual void v137(); virtual void v138(); virtual void v139(); virtual void v140(); virtual void v141();
	virtual void v142(); virtual void v143(); virtual void v144(); virtual void v145(); virtual void v146();
	virtual void v147(); virtual void v148(); virtual void v149(); virtual void v150(); virtual void v151();
	virtual void v152(); virtual void v153(); virtual void v154(); virtual void v155(); virtual void v156();
	virtual void v157(); virtual void v158(); virtual void v159(); virtual void v160(); virtual void v161();
	virtual void v162(int);
};

struct MenuV_101bf660 {
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
	virtual void v105(); virtual void v106();
	virtual int v107(void *p);
};

int vgui2::Menu::vfunc111(int a1, int a2, int a3, int a4)
{
	vgui2::MenuItem *item = (vgui2::MenuItem *)sub_101ac650(0x104);
	if (item)
		item = ::new (item) vgui2::MenuItem((int)this, a1, a2, 0, 0);
	else
		item = 0;

	((MenuItemV_101bf660 *)item)->v162(a3);
	((MenuItemV_101bf660 *)item)->v41(a4);
	return ((MenuV_101bf660 *)this)->v107(item);
}
// END FUNCTION

// FUNCTION: 0x101bf6c0 size=0x1b
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual int f111(int, int, int, int); };
}
int vgui2::Menu::vfunc112(int a0, int a1, int a2)
{
    return ((lifted::V *)this)->f111(a0, a0, a1, a2);
}
// END FUNCTION

// FUNCTION: 0x101bf6e0 size=0x5f
#include "vgui2__Menu.h"
#include "vgui2__MenuItem.h"

inline void *operator new(unsigned int, void *p) { return p; }

extern void *sub_101ac650(int);

int vgui2::Menu::vfunc109(int a, int b, int c, int d)
{
	void *mem = sub_101ac650(0x104);
	vgui2::MenuItem *item = mem ? ::new(mem) vgui2::MenuItem((int)this, a, b, 0, 0) : 0;
	item->vfunc161(c);
	item->vfunc41(d);
	return this->vfunc107(item);
}
// END FUNCTION

// FUNCTION: 0x101bf740 size=0x1b
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual int f109(int, int, int, int); };
}
int vgui2::Menu::vfunc110(int a0, int a1, int a2)
{
    return ((lifted::V *)this)->f109(a0, a0, a1, a2);
}
// END FUNCTION

// FUNCTION: 0x101bf760 size=0x16
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual int f112(int, int, int); };
}
int vgui2::Menu::vfunc108(int a0, int a1)
{
    return ((lifted::V *)this)->f112(a0, a0, a1);
}
// END FUNCTION

// FUNCTION: 0x101bf780 size=0x5f
#include "vgui2__Menu.h"
#include "vgui2__MenuItem.h"

void *sub_101ac650(unsigned int size);
inline void *operator new(unsigned int, void *p) { return p; }

struct MenuItemV_101bf780 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40();
	virtual void v41(int);
	virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
	virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
	virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56();
	virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61();
	virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66();
	virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
	virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76();
	virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81();
	virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86();
	virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
	virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96();
	virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101();
	virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106();
	virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
	virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116();
	virtual void v117(); virtual void v118(); virtual void v119(); virtual void v120(); virtual void v121();
	virtual void v122(); virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126();
	virtual void v127(); virtual void v128(); virtual void v129(); virtual void v130(); virtual void v131();
	virtual void v132(); virtual void v133(); virtual void v134(); virtual void v135(); virtual void v136();
	virtual void v137(); virtual void v138(); virtual void v139(); virtual void v140(); virtual void v141();
	virtual void v142(); virtual void v143(); virtual void v144(); virtual void v145(); virtual void v146();
	virtual void v147(); virtual void v148(); virtual void v149(); virtual void v150(); virtual void v151();
	virtual void v152(); virtual void v153(); virtual void v154(); virtual void v155(); virtual void v156();
	virtual void v157(); virtual void v158(); virtual void v159(); virtual void v160(); virtual void v161();
	virtual void v162(int);
};

struct MenuV_101bf780 {
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
	virtual void v105(); virtual void v106();
	virtual int v107(void *p);
};

int vgui2::Menu::vfunc116(int a1, int a2, int a3, int a4)
{
	vgui2::MenuItem *item = (vgui2::MenuItem *)sub_101ac650(0x104);
	if (item)
		item = ::new (item) vgui2::MenuItem((int)this, a1, a2, 0, 1);
	else
		item = 0;

	((MenuItemV_101bf780 *)item)->v162(a3);
	((MenuItemV_101bf780 *)item)->v41(a4);
	return ((MenuV_101bf780 *)this)->v107(item);
}
// END FUNCTION

// FUNCTION: 0x101bf7e0 size=0x1b
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual int f116(int, int, int, int); };
}
int vgui2::Menu::vfunc117(int a0, int a1, int a2)
{
    return ((lifted::V *)this)->f116(a0, a0, a1, a2);
}
// END FUNCTION

// FUNCTION: 0x101bf800 size=0x5f
#include "vgui2__Menu.h"
#include "vgui2__MenuItem.h"

void *sub_101ac650(unsigned int size);
inline void *operator new(unsigned int, void *p) { return p; }

struct MenuItemV_101bf800 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40();
	virtual void v41(int);
	virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46();
	virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
	virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56();
	virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61();
	virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66();
	virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
	virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76();
	virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81();
	virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86();
	virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
	virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96();
	virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101();
	virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106();
	virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
	virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115(); virtual void v116();
	virtual void v117(); virtual void v118(); virtual void v119(); virtual void v120(); virtual void v121();
	virtual void v122(); virtual void v123(); virtual void v124(); virtual void v125(); virtual void v126();
	virtual void v127(); virtual void v128(); virtual void v129(); virtual void v130(); virtual void v131();
	virtual void v132(); virtual void v133(); virtual void v134(); virtual void v135(); virtual void v136();
	virtual void v137(); virtual void v138(); virtual void v139(); virtual void v140(); virtual void v141();
	virtual void v142(); virtual void v143(); virtual void v144(); virtual void v145(); virtual void v146();
	virtual void v147(); virtual void v148(); virtual void v149(); virtual void v150(); virtual void v151();
	virtual void v152(); virtual void v153(); virtual void v154(); virtual void v155(); virtual void v156();
	virtual void v157(); virtual void v158(); virtual void v159(); virtual void v160();
	virtual void v161(int);
	virtual void v162();
};

struct MenuV_101bf800 {
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
	virtual void v105(); virtual void v106();
	virtual int v107(void *p);
};

int vgui2::Menu::vfunc114(int a1, int a2, int a3, int a4)
{
	vgui2::MenuItem *item = (vgui2::MenuItem *)sub_101ac650(0x104);
	if (item)
		item = ::new (item) vgui2::MenuItem((int)this, a1, a2, 0, 1);
	else
		item = 0;

	((MenuItemV_101bf800 *)item)->v161(a3);
	((MenuItemV_101bf800 *)item)->v41(a4);
	return ((MenuV_101bf800 *)this)->v107(item);
}
// END FUNCTION

// FUNCTION: 0x101bf860 size=0x1b
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual int f114(int, int, int, int); };
}
int vgui2::Menu::vfunc115(int a0, int a1, int a2)
{
    return ((lifted::V *)this)->f114(a0, a0, a1, a2);
}
// END FUNCTION

// FUNCTION: 0x101bf880 size=0x16
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual int f117(int, int, int); };
}
int vgui2::Menu::vfunc113(int a0, int a1)
{
    return ((lifted::V *)this)->f117(a0, a0, a1);
}
// END FUNCTION

// FUNCTION: 0x101bf8a0 size=0x62
#include "vgui2__Menu.h"
#include "vgui2__MenuItem.h"

void *sub_101ac650(unsigned int);
inline void *operator new(unsigned int, void *p) { return p; }

// TARGET: vgui2::Menu::vfunc121
int vgui2::Menu::vfunc121(int a1, int a2, int a3, int a4, int a5)
{
    void *mem = sub_101ac650(0x104);
    vgui2::MenuItem *item;
    if (mem)
        item = new (mem) vgui2::MenuItem((int)this, a1, a2, a5, 0);
    else
        item = 0;
    item->vfunc162(a3);
    item->vfunc41(a4);
    return vfunc107(item);
}
// END FUNCTION

// FUNCTION: 0x101bf910 size=0x20
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual int f121(int, int, int, int, int); };
}
int vgui2::Menu::vfunc122(int a0, int a1, int a2, int a3)
{
    return ((lifted::V *)this)->f121(a0, a0, a1, a2, a3);
}
// END FUNCTION

// FUNCTION: 0x101bf930 size=0x62
#include "vgui2__Menu.h"
#include "vgui2__MenuItem.h"

void *sub_101ac650(unsigned int);
inline void *operator new(unsigned int, void *p) { return p; }

// TARGET: vgui2::Menu::vfunc119
int vgui2::Menu::vfunc119(int a1, int a2, int a3, int a4, int a5)
{
    void *mem = sub_101ac650(0x104);
    vgui2::MenuItem *item;
    if (mem)
        item = new (mem) vgui2::MenuItem((int)this, a1, a2, a5, 0);
    else
        item = 0;
    item->vfunc161(a3);
    item->vfunc41(a4);
    return vfunc107(item);
}
// END FUNCTION

// FUNCTION: 0x101bf9a0 size=0x20
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual int f119(int, int, int, int, int); };
}
int vgui2::Menu::vfunc120(int a0, int a1, int a2, int a3)
{
    return ((lifted::V *)this)->f119(a0, a0, a1, a2, a3);
}
// END FUNCTION

// FUNCTION: 0x101bf9c0 size=0x1b
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual int f122(int, int, int, int); };
}
int vgui2::Menu::vfunc118(int a0, int a1, int a2)
{
    return ((lifted::V *)this)->f122(a0, a0, a1, a2);
}
// END FUNCTION

// FUNCTION: 0x101bfa40 size=0x16
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int vgui2::Menu::vfunc126(int a0)
{
    *(int *)((char *)this + 0x58) = a0;
    return ((lifted::V *)this)->f57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101bfea0 size=0xab
#include "vgui2__Menu.h"
#include "vgui2__Slider.h"

struct ItemVec101bfea0
{
	char pad[0xc];
	int m_Size;
	int m_unk10;
	vgui2::Panel **m_pElements;
	vgui2::Panel *Get(int i)
	{
		if (i >= 0 && i < m_Size)
			return m_pElements[i];
		return 0;
	}
};

void vgui2::Menu::vfunc137()
{
	ItemVec101bfea0 *items = (ItemVec101bfea0 *)((char *)this + 0x58);
	int nShown = 0;
	int first = (*(vgui2::Slider **)((char *)this + 0x70))->vfunc108();
	do
	{
		int i;
		for (i = 0; i < first; i++)
		{
			vgui2::Panel *p = items->Get(i);
			if (p)
				p->vfunc21(0);
		}
		i = first;
		while (nShown < *(int *)((char *)this + 0x60))
		{
			if (i >= *(int *)((char *)this + 0x64))
				goto done;
			vgui2::Panel *p = items->Get(i);
			if (p)
			{
				p->vfunc21(1);
				nShown++;
			}
			i++;
		}
		for (; i < *(int *)((char *)this + 0x64); i++)
		{
			vgui2::Panel *p = items->Get(i);
			if (p)
				p->vfunc21(0);
		}
done:
		if (nShown < *(int *)((char *)this + 0x60))
		{
			first--;
			nShown = 0;
		}
	} while (nShown < *(int *)((char *)this + 0x60) - 1);
}
// END FUNCTION

// FUNCTION: 0x101bff50 size=0x3a
#include "vgui2__Menu.h"
namespace lifted {
extern char g_102d9a1c;
struct C101aa220 { int sub_101aa220(); };
struct C101ac8c0 { int sub_101ac8c0(); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual int f3(int); virtual int f4(int); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual int f60(int); };
}
void vgui2::Menu::vfunc136()
{
    int t0 = ((lifted::C101ac8c0 *)this)->sub_101ac8c0();
    int t1 = ((lifted::V *)(((lifted::V *)t0)->f4(((lifted::C101aa220 *)this)->sub_101aa220())))->f3((int)&lifted::g_102d9a1c);
    if (t1 != 0) {
        ((lifted::V *)this)->f60(t1);
    }
}
// END FUNCTION

// FUNCTION: 0x101bff90 size=0x9f
#include "vgui2__Menu.h"
struct ColX { unsigned char r, g, b, a; ColX() {} ColX(int R, int G, int B, int A) { r = R; g = G; b = B; a = A; } };
struct ISchemeX { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual ColX GetColor(const char *, ColX); };
struct ISchemeMgrX { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual ISchemeX *GetIScheme(int); };
struct ISurfY {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void SetColor(ColX);
	virtual void v11();
	virtual void FillRect(int, int, int, int);
};
struct IMenuItemsX { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual bool v22(); };
ISchemeMgrX *sub_101ac8c0();
ISurfY *sub_101ac8d0();
// TARGET: vgui2::Menu::vfunc98
void vgui2::Menu::vfunc98()
{
	if ((*(IMenuItemsX **)&m_i70)->v22()) {
		int w, t;
		sub_101a9920(&w, &t);
		ISchemeX *scheme = sub_101ac8c0()->GetIScheme(sub_101aa220());
		ColX def(255, 255, 255, 0);
		ColX c = scheme->GetColor("BorderDark", def);
		sub_101ac8d0()->SetColor(c);
		sub_101ac8d0()->FillRect(w - 18, -1, w - 17, t);
	}
}
// END FUNCTION

// FUNCTION: 0x101c0030 size=0x16
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int vgui2::Menu::vfunc127(int a0)
{
    *(int *)((char *)this + 0x60) = a0;
    return ((lifted::V *)this)->f57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101c00d0 size=0x44
#include "vgui2__Menu.h"
int sub_101b6840(int size);
struct CUnknown101b5690 { void *sub_101b5690(int, int, int); };
// TARGET: vgui2::Menu::vfunc78
void vgui2::Menu::vfunc78(int cmd) {
	CUnknown101b5690 *kv = (CUnknown101b5690 *)sub_101b6840(0x1c);
	vfunc43(kv ? kv->sub_101b5690((int)"Command", (int)"command", cmd) : 0);
	Panel::vfunc78(cmd);
}
// END FUNCTION

// FUNCTION: 0x101c03e0 size=0x3e
#include "vgui2__Menu.h"
struct SbV {
	virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8(); virtual void p9();
	virtual void p10(); virtual void p11(); virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15(); virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
	virtual void p20(); virtual void p21(); virtual bool IsVisible();
	virtual void p23(); virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27(); virtual void p28(); virtual void p29();
	virtual void p30(); virtual void p31(); virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35(); virtual void p36(); virtual void p37(); virtual void p38(); virtual void p39();
	virtual void p40(); virtual void p41(); virtual void p42(); virtual void p43(); virtual void p44(); virtual void p45(); virtual void p46(); virtual void p47(); virtual void p48(); virtual void p49();
	virtual void p50(); virtual void p51(); virtual void p52(); virtual void p53(); virtual void p54(); virtual void p55(); virtual void p56(); virtual void p57(); virtual void p58(); virtual void p59();
	virtual void p60(); virtual void p61(); virtual void p62(); virtual void p63(); virtual void p64(); virtual void p65(); virtual void p66(); virtual void p67(); virtual void p68(); virtual void p69();
	virtual void p70(); virtual void p71(); virtual void p72(); virtual void p73(); virtual void p74(); virtual void p75(); virtual void p76(); virtual void p77(); virtual void p78(); virtual void p79();
	virtual void p80(); virtual void p81(); virtual void p82(); virtual void p83(); virtual void p84(); virtual void p85(); virtual void p86(); virtual void p87(); virtual void p88(); virtual void p89();
	virtual void p90(); virtual void p91(); virtual void p92(); virtual void p93(); virtual void p94(); virtual void p95(); virtual void p96(); virtual void p97(); virtual void p98(); virtual void p99();
	virtual void p100(); virtual void p101(); virtual void p102(); virtual void p103(); virtual void p104(); virtual void p105(); virtual void p106();
	virtual void SetValue(int v);
	virtual int GetValue();
};
struct MenuV {
	virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8(); virtual void p9();
	virtual void p10(); virtual void p11(); virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15(); virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
	virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23(); virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27(); virtual void p28(); virtual void p29();
	virtual void p30(); virtual void p31(); virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35(); virtual void p36(); virtual void p37(); virtual void p38(); virtual void p39();
	virtual void p40(); virtual void p41(); virtual void p42(); virtual void p43(); virtual void p44(); virtual void p45(); virtual void p46(); virtual void p47(); virtual void p48(); virtual void p49();
	virtual void p50(); virtual void p51(); virtual void p52(); virtual void p53(); virtual void p54(); virtual void p55(); virtual void p56(); virtual void f57(int, int);
};
void vgui2::Menu::vfunc90(int a)
{
	SbV *sb = *(SbV **)((char *)this + 0x70);
	if (sb->IsVisible()) {
		int v = (*(SbV **)((char *)this + 0x70))->GetValue() - a;
		(*(SbV **)((char *)this + 0x70))->SetValue(v);
		((MenuV *)this)->f57(0, 0);
	}
}
// END FUNCTION

// FUNCTION: 0x101c0420 size=0xd7
#include "vgui2__Menu.h"
#include "vgui2__MenuItem.h"
#include "vgui2__KeyValues.h"

int sub_101ac8b0();
int sub_101ac900();

class InputV_101c0420
{
public:
	virtual void v0(); virtual void v1(); virtual void v2();
	virtual int v3();	// slot 3
};

class PanelGlobalV_101c0420
{
public:
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual bool v20(int a, int b);	// slot 20
};

// TARGET: vgui2::Menu::vfunc81
void vgui2::Menu::vfunc81()
{
	if ( ((InputV_101c0420 *)sub_101ac8b0())->v3() )
	{
		if ( ((PanelGlobalV_101c0420 *)sub_101ac900())->v20(
				((InputV_101c0420 *)sub_101ac8b0())->v3(), vfunc0() ) )
			return;
	}

	vgui2::MenuItem *pMenu = dynamic_cast<vgui2::MenuItem *>(
		(vgui2::Panel *)vfunc31() );
	if ( pMenu )
	{
		InputV_101c0420 *pInput = (InputV_101c0420 *)sub_101ac8b0();
		vgui2::Panel *pFocus = (vgui2::Panel *)(int)pMenu->vfunc31();
		int nFocus = pInput->v3();
		if ( nFocus == pFocus->vfunc0()
				&& *(int *)((char *)this + 0x84) == 0 )
		{
			vfunc49();
			return;
		}
	}

	vfunc43(new vgui2::KeyValues("MenuClose"));
	vfunc21(0);
}
// END FUNCTION

// FUNCTION: 0x101c0590 size=0x4f
#include "vgui2__Menu.h"

struct ISchemeView {
	virtual void d0(); virtual void d1(); virtual void d2();
	virtual void d3(); virtual void d4(); virtual void d5();
	virtual int *v6(int *pOut, const char *name);
};

int vgui2::Menu::vfunc74(int pScheme)
{
	Panel::vfunc74(pScheme);
	int color;
	int *p1 = ((ISchemeView *)pScheme)->v6(&color, "Menu/FgColor");
	vfunc51(*p1);
	int *p2 = ((ISchemeView *)pScheme)->v6(&color, "Menu/BgColor");
	int nRet = vfunc50(*p2);
	return nRet;
}
// END FUNCTION

// FUNCTION: 0x101c0750 size=0x4
#include "vgui2__Menu.h"
int vgui2::Menu::vfunc129()
{
    return *(int *)((char *)this + 0x64);
}
// END FUNCTION

// FUNCTION: 0x101c0770 size=0xaa
#include <string.h>
#include "vgui2__Menu.h"
#include "vgui2__MenuItem.h"

#pragma intrinsic(strcmp)

struct ItemVec_101c0770
{
	int m_n0;
	int m_nCount;
	int m_n8;
	vgui2::MenuItem **m_pItems;
};

static inline vgui2::MenuItem *GetItem(vgui2::Menu *menu, int i)
{
	ItemVec_101c0770 *v = (ItemVec_101c0770 *)((char *)menu + 0x60);
	if (i >= 0 && i < v->m_nCount)
		return v->m_pItems[i];
	return 0;
}

void vgui2::Menu::vfunc124(const char *name, int arg)
{
	for (int i = 0; i < ((ItemVec_101c0770 *)((char *)this + 0x60))->m_nCount; i++)
	{
		vgui2::MenuItem *item = GetItem(this, i);
		if (strcmp(name, (const char *)item->vfunc18()) == 0)
		{
			vgui2::MenuItem *mi = dynamic_cast<vgui2::MenuItem *>(GetItem(this, i));
			mi->vfunc46(arg);
		}
	}
}
// END FUNCTION

// FUNCTION: 0x101c0820 size=0x13
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); };
}
int vgui2::Menu::vfunc133()
{
    int t0 = ((lifted::V *)(*(int *)((char *)this + 0x70)))->f21(1);
    *(char *)((char *)this + 0x74) = 1;
    return t0;
}
// END FUNCTION

// FUNCTION: 0x101c0840 size=0x13
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); };
}
int vgui2::Menu::vfunc134()
{
    int t0 = ((lifted::V *)(*(int *)((char *)this + 0x70)))->f21(0);
    *(char *)((char *)this + 0x74) = 0;
    return t0;
}
// END FUNCTION

// FUNCTION: 0x101c0860 size=0x1a
#include "vgui2__Menu.h"
namespace lifted {
int __stdcall sub_101c0080(int);
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); };
}
int vgui2::Menu::vfunc135()
{
    lifted::sub_101c0080(0);
    return ((lifted::V *)this)->f57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101c0880 size=0x41
#include "vgui2__Menu.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual int f15(int); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual int f31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(int, int); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual int f84(int, int); };
}
void vgui2::Menu::vfunc84(int a0, int a1)
{
    *(int *)((char *)this + 0x84) = 0;
    ((lifted::V *)(((lifted::V *)this)->f31()))->f84(a0, a1);
    ((lifted::V *)this)->f15(0);
    ((lifted::V *)this)->f57(0, 0);
}
// END FUNCTION

// FUNCTION: 0x101c08d0 size=0x69
#include "vgui2__Menu.h"

extern void *sub_101b6840(unsigned int size);

struct KV_101c08d0 {
	KV_101c08d0 *sub_101b5670(const char *name);
};

struct IVGui_101c08d0 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void PostMessage(int target, void *params, int from, float delaySeconds);
};
extern IVGui_101c08d0 *sub_101ac8f0();

struct PanelLike_101c08d0 {
	virtual int GetVPanel();
};

void vgui2::Menu::vfunc91(int)
{
	*(int *)((char *)this + 0x84) = 1;
	KV_101c08d0 *msg = (KV_101c08d0 *)sub_101b6840(0x1c);
	if (msg)
		msg = msg->sub_101b5670("KeyModeSet");
	else
		msg = 0;

	PanelLike_101c08d0 *parent = (PanelLike_101c08d0 *)vfunc31();
	sub_101ac8f0()->PostMessage(parent->GetVPanel(), msg, vfunc0(), 0.0f);
}
// END FUNCTION

// FUNCTION: 0x101c0e60 size=0x6
#include "vgui2__Menu.h"
namespace lifted {
extern char g_102d99b0;
}
int vgui2::Menu::vfunc102()
{
    return (int)&lifted::g_102d99b0;
}
// END FUNCTION

// FUNCTION: 0x101c0e70 size=0xd
#include "vgui2__Menu.h"
int vgui2::Menu::vfunc130(int a0)
{
    *(int *)((char *)this + 0x8c) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x101c0e80 size=0x7
#include "vgui2__Menu.h"
int vgui2::Menu::vfunc131()
{
    return *(int *)((char *)this + 0x8c);
}
// END FUNCTION
