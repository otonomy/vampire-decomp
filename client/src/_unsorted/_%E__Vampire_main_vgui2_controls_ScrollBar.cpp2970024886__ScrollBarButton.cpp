// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101bed70 size=0xf
struct S_101bed70 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual S_101bed70 *v31(); virtual void v32(); virtual void v33(); virtual void v34();
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
	virtual void v95(); virtual void v96();
};
// TARGET: sub_101bed70
void __fastcall sub_101bed70(S_101bed70 *self)
{
	self->v31()->v96();
}
// END FUNCTION

// FUNCTION: 0x101bed80 size=0xd6
#include "vgui2__Button.h"

struct SBScheme
{
	virtual void v0(); virtual void v1(); virtual void v2();
	virtual int vfunc3(const char *pszName);
	virtual int vfunc4(const char *pszName);
	virtual void v5();
	virtual int *vfunc6(int *pOut, const char *pszName);
};
struct SBColorSlots
{
	virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
	virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
	virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
	virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
	virtual void s50(); virtual void s51();
	virtual int *vfunc52(int *pOut);
	virtual int *vfunc53(int *pOut);
};
struct SBButton : public vgui2::Button
{
	void sub_101bed80(int pScheme);
};

// TARGET: SBButton::sub_101bed80
void SBButton::sub_101bed80(int pScheme)
{
	SBScheme *s = (SBScheme *)pScheme;
	SBColorSlots *c = (SBColorSlots *)this;
	int clrA;
	int clrB;
	Button::vfunc74(pScheme);
	vfunc118(s->vfunc4("Marlett"));
	vfunc158(s->vfunc3("ScrollBarButtonBorder"));
	vfunc154(*c->vfunc53(&clrB), *c->vfunc52(&clrA));
	vfunc155(*c->vfunc53(&clrB), *c->vfunc52(&clrA));
	vfunc153(*s->vfunc6(&clrB, "DimBaseText"), *c->vfunc52(&clrA));
}
// END FUNCTION
