// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1017b510 size=0x16
#define V8(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7();
struct O_1017b510 {
V8(a) V8(b) V8(c) V8(d) V8(e) V8(f) V8(g) V8(h) V8(i) V8(j)
virtual void k0(); virtual void k1(); virtual void k2(); virtual void k3(); virtual void k4(); virtual void k5(); virtual void k6();
virtual void v87(int); };
O_1017b510 *sub_10170f70();
struct CUnknown1017b510 { void sub_1017b510(int a); };
void CUnknown1017b510::sub_1017b510(int a)
{
	O_1017b510 *p = sub_10170f70();
	if (p)
		p->v87(a);
}
// END FUNCTION

// FUNCTION: 0x1017b530 size=0x1e
#include "CharEditInfoPanel.h"

// VC6 writes CharEditInfoPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CharEditInfoPanel *pcd_emit_1017b530(const CharEditInfoPanel &other) { return new CharEditInfoPanel(other); }

// TARGET: ??_GCharEditInfoPanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1017c260 size=0x131
template <class T> __forceinline T pcd_stage(T x) { return x; }
#include "CharEditInfoPanel.h"
#include "CharEditPanel.h"
#include "CHud.h"
#include <string.h>

struct VTarget_1017c260
{
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
	virtual void v107(int);
};

struct View_1017c260
{
	char pad[0xb0];
	VTarget_1017c260 *m_pTarget;
	char pad2[0xc4 - 0xb4];
	int m_nColor;
};

// TARGET: CharEditInfoPanel::vfunc78
void CharEditInfoPanel::vfunc78(int command)
{
	const char *pszCommand = (const char *)command;
	View_1017c260 *v = (View_1017c260 *)this;
	if (!_strcmpi(pszCommand, "refresh"))
	{
		sub_1017c580();
		return;
	}
	if (!_strcmpi(pszCommand, "accept"))
	{
		(pcd_stage((CharEditPanel *)gHUD.FindElement("CharEditPanel")))->sub_101733d0(false);
		return;
	}
	if (!_strcmpi(pszCommand, "color0"))
	{
		v->m_nColor = 0;
		v->m_pTarget->v107(0xff);
		return;
	} else { if (!_strcmpi(pszCommand, "color1"))
	{
		v->m_nColor = 1;
		v->m_pTarget->v107(0xbf);
		return;
	}
	if (!_strcmpi(pszCommand, "color2"))
	{
		v->m_nColor = 2;
		v->m_pTarget->v107(0x3f);
		return;
	} else { if (!_strcmpi(pszCommand, "color3"))
	{
		v->m_nColor = 3;
		v->m_pTarget->v107(0x7f);
		return;
	} typedef vgui2::Panel BaseClass;
	BaseClass::vfunc78(command); } }
}
// END FUNCTION

// FUNCTION: 0x1017c3a0 size=0x3
#include "CharEditInfoPanel.h"
void CharEditInfoPanel::vfunc124(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1017c530 size=0x6
#include "CharEditInfoPanel.h"
namespace lifted {
extern char g_102d1340;
}
int CharEditInfoPanel::vfunc102()
{
    return (int)&lifted::g_102d1340;
}
// END FUNCTION

// FUNCTION: 0x1017c560 size=0x1
#include "CharEditInfoPanel.h"
void CharEditInfoPanel::vfunc119()
{
}
// END FUNCTION

// FUNCTION: 0x1017c5d0 size=0x21
#include "CharEditInfoPanel.h"
int sub_1016a6b0();
void CharEditInfoPanel::vfunc123()
{
	int n = sub_1016a6b0();
	vfunc33(n);
	sub_101aa0a0(1000);
}
// END FUNCTION

// FUNCTION: 0x1017c600 size=0x28
#include "CharEditInfoPanel.h"
namespace lifted {
struct C1017c650 { int sub_1017c650(); };
struct C1017c660 { int sub_1017c660(); };
struct C101a99f0 { int sub_101a99f0(int); };
}
int CharEditInfoPanel::vfunc21(int a0)
{
    int t0 = ((lifted::C101a99f0 *)this)->sub_101a99f0(a0);
    if (((char)a0) != 0) {
        return ((lifted::C1017c660 *)this)->sub_1017c660();
    }
    return ((lifted::C1017c650 *)this)->sub_1017c650();
}
// END FUNCTION

// FUNCTION: 0x1017c640 size=0xe
#include "CharEditInfoPanel.h"
namespace lifted {
extern int g_104a57d4;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual int f57(); };
}
void CharEditInfoPanel::vfunc3()
{
    ((lifted::V *)lifted::g_104a57d4)->f57();
}
// END FUNCTION
