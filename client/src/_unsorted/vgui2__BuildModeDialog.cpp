// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101c32c0 size=0x777
#include "vgui2__BuildModeDialog.h"
#define D1(a) virtual void a();
#define D4(a) virtual void a##_0(); virtual void a##_1(); virtual void a##_2(); virtual void a##_3();
#define D16(a) D4(a##_a) D4(a##_b) D4(a##_c) D4(a##_d)
struct PV {
	D4(a1) D4(a2) D4(a3) D1(a4) D1(a5)
	virtual void SetString(const char *k, const char *v);
	D1(b1) D1(b2) D1(b3)
	virtual PV *MakeCopy();
	D1(c1) D1(c2)
	virtual void v21(int);
	D4(d1) D1(d2) D1(d3)
	virtual void v28(int);
	D4(e1) D4(e2) D4(e3)
	virtual void SetParent(PV *);
	D4(f1)
	virtual void v46(int);
	D16(g1) D16(g2) D16(g3) D4(g4) D4(g5) D4(g6) D1(g7) D1(g8) D1(g9)
	virtual void AddMenuItem(const char *, PV *, PV *);
	D16(h1) D1(h2) D1(h3)
	virtual void v129();
	D16(i1) D16(i2)
	virtual void SetText(const char *);
	D4(j1) D4(j2) D4(j3) D1(j4)
	virtual int AddItem(const char *, int);
	D4(k1)
	virtual void v181(int);
	void sub_101a9950(int, int, int, int);
	PV *sub_101b5670(const char *);
	PV *sub_101b1fc0(PV *, const char *, const char *);
	PV *sub_101b3630(PV *, const char *, const char *);
	PV *sub_101ba810(PV *, const char *, const char *);
	PV *sub_101c7820(PV *, const char *, int, int);
	PV *sub_101bf420(PV *, const char *);
	PV *sub_101ca6a0(PV *, const char *);
};
struct SV {
	D16(m1) D16(m2) D4(m3) D1(m4) D1(m5) D1(m6)
	virtual void GetScreenSize(int *, int *);
};
struct PanelList {
	int a, b, c, d, e;
	PV *m_pResourceData;
	PV *m_pControls;
	PanelList() { a = 0; b = 0; c = 0; d = 0; e = 0; }
};
SV *sub_101ac8d0();
void *__cdecl sub_101b6840(unsigned int);
void *__cdecl sub_101ac650(unsigned int);
#define FLD(t, o) (*(t *)((char *)this + (o)))

// TARGET: vgui2::BuildModeDialog::BuildModeDialog
vgui2::BuildModeDialog::BuildModeDialog(void *pBuildGroup) : Frame(0, "BuildModeDialg", true)
{
	int tall;
	int wide;
	void *p;
	sub_101ac8d0()->GetScreenSize(&wide, &tall);
	((PV *)this)->sub_101a9950(0, 0, (int)(285.0 * (wide * 0.0009765625)), (int)(200.0 * (tall * 0.0013020833333333333)));
	FLD(int, 0xe4) = 0;
	FLD(void *, 0x120) = pBuildGroup;
	FLD(PanelList *, 0xe8) = new PanelList;
	p = sub_101b6840(0x1c);
	FLD(PanelList *, 0xe8)->m_pResourceData = p ? ((PV *)p)->sub_101b5670("BuildDialog") : 0;
	p = sub_101ac650(0x78);
	FLD(PanelList *, 0xe8)->m_pControls = p ? ((PV *)p)->sub_101ca6a0((PV *)this, "BuildModeControls") : 0;
	p = sub_101ac650(0xb8);
	FLD(PV *, 0x118) = p ? ((PV *)p)->sub_101b1fc0((PV *)this, 0, "New Panel") : 0;
	p = sub_101ac650(0x138);
	FLD(PV *, 0x11c) = p ? ((PV *)p)->sub_101c7820((PV *)this, 0, 0xf, 0) : 0;
	FLD(PV *, 0x11c)->sub_101a9950(0x3c, 0x1e, 0x8c, 0x18);
	FLD(PV *, 0x11c)->SetParent((PV *)this);
	FLD(PV *, 0x11c)->AddItem("None", -1);
	FLD(PV *, 0x11c)->AddItem("Label", -1);
	FLD(PV *, 0x11c)->AddItem("Button", -1);
	FLD(PV *, 0x11c)->AddItem("CheckButton", -1);
	FLD(PV *, 0x11c)->AddItem("ComboBox", -1);
	FLD(PV *, 0x11c)->AddItem("ProgressBar", -1);
	FLD(PV *, 0x11c)->AddItem("RadioButton", -1);
	FLD(PV *, 0x11c)->AddItem("TextEntry", -1);
	FLD(PV *, 0x11c)->AddItem("ToggleButton", -1);
	FLD(PV *, 0x11c)->v181(0);
	p = sub_101ac650(0xf0);
	FLD(PV *, 0xec) = p ? ((PV *)p)->sub_101b3630((PV *)this, "SizeToTextButton", "S&ize to Text") : 0;
	FLD(PV *, 0xec)->sub_101a9950(0x3c, 0x3c, 0x55, 0x19);
	FLD(PV *, 0xec)->SetParent((PV *)this);
	FLD(PV *, 0xec)->SetText("SizeToText");
	p = sub_101ac650(0xfc);
	FLD(PV *, 0x10c) = p ? ((PV *)p)->sub_101ba810((PV *)this, "AutoUpdatePanelCheck", "Auto Update") : 0;
	FLD(PV *, 0x10c)->sub_101a9950(0x3c, 0x5a, 0x64, 0xd);
	FLD(PV *, 0x10c)->v129();
	FLD(PV *, 0x10c)->SetParent((PV *)this);
	FLD(char, 0x110) = 0;
	p = sub_101ac650(0xfc);
	FLD(PV *, 0x114) = p ? ((PV *)p)->sub_101ba810((PV *)this, "RulerDisplayCheck", "Display Rulers") : 0;
	FLD(PV *, 0x114)->sub_101a9950(0x3c, 0x5a, 0x64, 0xd);
	FLD(PV *, 0x114)->v129();
	FLD(PV *, 0x114)->SetParent((PV *)this);
	p = sub_101ac650(0xf0);
	FLD(PV *, 0xf8) = p ? ((PV *)p)->sub_101b3630((PV *)this, "ExitButton", "&Exit") : 0;
	FLD(PV *, 0xf8)->sub_101a9950(0x3c, 0x78, 0x37, 0x19);
	p = sub_101ac650(0xf0);
	FLD(PV *, 0xf0) = p ? ((PV *)p)->sub_101b3630((PV *)this, "SaveButton", "&Save") : 0;
	FLD(PV *, 0xf0)->sub_101a9950(0x78, 0x78, 0x37, 0x19);
	FLD(PV *, 0xf0)->v46(0);
	p = sub_101ac650(0xf0);
	FLD(PV *, 0xf4) = p ? ((PV *)p)->sub_101b3630((PV *)this, "ApplyButton", "&Apply") : 0;
	FLD(PV *, 0xf4)->sub_101a9950(0x3c, 0x78, 0x37, 0x19);
	FLD(PV *, 0xf8)->SetText("Exit");
	FLD(PV *, 0xf0)->SetText("Save");
	FLD(PV *, 0xf4)->SetText("Apply");
	FLD(PV *, 0xf0)->SetParent((PV *)this);
	FLD(PV *, 0xf8)->SetParent((PV *)this);
	FLD(PV *, 0xf4)->SetParent((PV *)this);
	p = sub_101ac650(0xf0);
	FLD(PV *, 0xfc) = p ? ((PV *)p)->sub_101b3630((PV *)this, "DeletePanelButton", "&Delete Panel") : 0;
	FLD(PV *, 0xfc)->sub_101a9950(0x3c, 0x78, 0x64, 0x19);
	FLD(PV *, 0xfc)->SetParent((PV *)this);
	FLD(PV *, 0xfc)->SetText("DeletePanel");
	p = sub_101ac650(0xf0);
	FLD(PV *, 0x100) = p ? ((PV *)p)->sub_101b3630((PV *)this, "RevertToSavedButton", "&Revert To Saved") : 0;
	FLD(PV *, 0x100)->sub_101a9950(0x3c, 0x82, 0x6e, 0x19);
	FLD(PV *, 0x100)->SetParent((PV *)this);
	FLD(PV *, 0x100)->SetText("RevertToSaved");
	p = sub_101ac650(0xf0);
	FLD(PV *, 0x104) = p ? ((PV *)p)->sub_101b3630((PV *)this, "ShowHelpButton", "S&how Help") : 0;
	FLD(PV *, 0x104)->sub_101a9950(0x3c, 0x37, 0x64, 0x19);
	FLD(PV *, 0x104)->SetParent((PV *)this);
	FLD(PV *, 0x104)->SetText("ShowHelp");
	Frame::vfunc121(0);
	p = sub_101ac650(0x90);
	FLD(PV *, 0x128) = p ? ((PV *)p)->sub_101bf420((PV *)this, "NewControlMenu") : 0;
	FLD(PV *, 0x128)->v28(0);
	p = sub_101b6840(0x1c);
	PV *kv = p ? ((PV *)p)->sub_101b5670("NewControlFromDropDown") : 0;
	kv->SetString("ControlName", "Label");
	FLD(PV *, 0x128)->AddMenuItem("Label", kv->MakeCopy(), (PV *)this);
	kv->SetString("ControlName", "Button");
	FLD(PV *, 0x128)->AddMenuItem("Button", kv->MakeCopy(), (PV *)this);
	kv->SetString("ControlName", "CheckButton");
	FLD(PV *, 0x128)->AddMenuItem("CheckButton", kv->MakeCopy(), (PV *)this);
	kv->SetString("ControlName", "ComboBox");
	FLD(PV *, 0x128)->AddMenuItem("ComboBox", kv->MakeCopy(), (PV *)this);
	kv->SetString("ControlName", "RadioButton");
	FLD(PV *, 0x128)->AddMenuItem("RadioButton", kv->MakeCopy(), (PV *)this);
	kv->SetString("ControlName", "TextEntry");
	FLD(PV *, 0x128)->AddMenuItem("TextEntry", kv->MakeCopy(), (PV *)this);
	kv->SetString("ControlName", "ToggleButton");
	FLD(PV *, 0x128)->AddMenuItem("ToggleButton", kv->MakeCopy(), (PV *)this);
	FLD(PV *, 0x128)->v21(0);
	sub_101a9810("BuildDialog");
	FLD(int, 0x12c) = 0;
	FLD(int, 0x130) = 0;
}
// END FUNCTION

// FUNCTION: 0x101c3a40 size=0x1e
#include "vgui2__BuildModeDialog.h"

// VC6 writes vgui2::BuildModeDialog's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
vgui2::BuildModeDialog *pcd_emit_101c3a40(const vgui2::BuildModeDialog &other) { return new vgui2::BuildModeDialog(other); }

// TARGET: ??_GBuildModeDialog@vgui2@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101c3a60 size=0x142
#include "vgui2__BuildModeDialog.h"
#include "utlvector.h"
#define G(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4(); virtual void a##5(); virtual void a##6(); virtual void a##7(); virtual void a##8(); virtual void a##9();
#define H(a) G(a##0) G(a##1) G(a##2) G(a##3) G(a##4) G(a##5) G(a##6) G(a##7) G(a##8) G(a##9)
struct IV21_101c3a60 {
	G(a0) G(a1) virtual void v20(); virtual void v21();
};
struct IP112_101c3a60 {
	H(a) virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5(); virtual void b6(); virtual void b7(); virtual void b8(); virtual void b9(); virtual void b10(); virtual void b11(); virtual void b12();
};
struct S_101c3a60 {
	CUtlVector<int> m_vec;
	IV21_101c3a60 *m_p14;
	vgui2::Panel *m_p18;
};
#define m_pList (*(S_101c3a60 **)((char *)this + 0xe8))
#define m_pF0 (*(vgui2::Panel **)((char *)this + 0xf0))
#define m_pF4 (*(vgui2::Panel **)((char *)this + 0xf4))
#define m_pF8 (*(vgui2::Panel **)((char *)this + 0xf8))
#define m_pFC (*(vgui2::Panel **)((char *)this + 0xfc))
#define m_p10C (*(vgui2::Panel **)((char *)this + 0x10c))
#define m_p118 (*(vgui2::Panel **)((char *)this + 0x118))
#define m_p128 (*(vgui2::Panel **)((char *)this + 0x128))
#define m_p12C (*(IV21_101c3a60 **)((char *)this + 0x12c))
#define m_p130 (*(IV21_101c3a60 **)((char *)this + 0x130))
// TARGET: vgui2::BuildModeDialog::~BuildModeDialog
vgui2::BuildModeDialog::~BuildModeDialog()
{
	m_pList->m_p14->v21();
	((IP112_101c3a60 *)m_pList->m_p18)->b12();
	if (m_p12C)
		m_p12C->v21();
	if (m_p130)
		m_p130->v21();
	delete m_p128;
	delete m_pFC;
	delete m_p118;
	delete m_p10C;
	delete m_pList->m_p18;
	delete m_pList;
	delete m_pF8;
	delete m_pF0;
	delete m_pF4;
}
// END FUNCTION

// FUNCTION: 0x101c4600 size=0x1ad
#include "vgui2__BuildModeDialog.h"

extern "C" int __cdecl _strcmpi(const char *, const char *);
extern "C" int __cdecl strcmp(const char *, const char *);
#pragma intrinsic(strcmp)

#define V1(n) virtual void n();
#define V10(p) V1(p##0) V1(p##1) V1(p##2) V1(p##3) V1(p##4) V1(p##5) V1(p##6) V1(p##7) V1(p##8) V1(p##9)
struct ClassInfo_101c4600
{
	int m_unk0;
	int m_unk4;
	const char *m_pszName;
	ClassInfo_101c4600 *m_pNext;
};
struct Target_101c4600
{
	V10(a) V10(b) V10(c) V10(d) V10(e) V10(f) V10(g) V10(h) V10(i) V10(j)
	V1(k0) V1(k1)
	virtual ClassInfo_101c4600 *vfunc102();
	V10(l) V10(m)
	V1(n0) V1(n1) V1(n2) V1(n3) V1(n4) V1(n5)
	virtual void vfunc129();
};
struct Group_101c4600
{
	V1(a0) V1(a1)
	virtual Target_101c4600 *vfunc2();
	V1(a3)
	virtual void vfunc4();
};
struct Vis_101c4600
{
	V10(a) V10(b) V10(c) V10(d)
	V1(e0) V1(e1) V1(e2) V1(e3) V1(e4) V1(e5)
	virtual void vfunc46(int);
};
struct Self_101c4600
{
	V10(a) V10(b) V10(c) V10(d) V10(e) V10(f) V10(g) V10(h) V10(i) V10(j) V10(k) V10(l) V10(m) V10(n)
	V1(o0) V1(o1) V1(o2) V1(o3) V1(o4) V1(o5)
	virtual void vfunc146(Target_101c4600 *p);
};

#define FLD_GROUP (*(Group_101c4600 **)((char *)this + 0x120))
#define FLD_VIS (*(Vis_101c4600 **)((char *)this + 0xf0))

// TARGET: vgui2::BuildModeDialog::vfunc78
void vgui2::BuildModeDialog::vfunc78(const char *command)
{
	if (!_strcmpi(command, "Save"))
	{
		if (sub_101c4810())
			FLD_GROUP->vfunc4();
		FLD_VIS->vfunc46(0);
	}
	else if (!_strcmpi(command, "Exit"))
	{
		sub_101c4dd0();
	}
	else if (!_strcmpi(command, "Apply"))
	{
		sub_101c4810();
	}
	else if (!_strcmpi(command, "SizeToText"))
	{
		sub_101c4810();
		Target_101c4600 *pTarget = FLD_GROUP->vfunc2();
		ClassInfo_101c4600 *pInfo = pTarget->vfunc102();
		if (pInfo)
		{
			for (; pInfo; pInfo = pInfo->m_pNext)
			{
				if (!strcmp(pInfo->m_pszName, "CheckButton"))
				{
					pTarget->vfunc129();
					break;
				}
				if (!strcmp(pInfo->m_pszName, "RadioButton"))
				{
					pTarget->vfunc129();
					break;
				}
				if (!strcmp(pInfo->m_pszName, "Button"))
				{
					pTarget->vfunc129();
					break;
				}
				if (!strcmp(pInfo->m_pszName, "Label"))
				{
					pTarget->vfunc129();
					break;
				}
			}
		}
		((Self_101c4600 *)this)->vfunc146(pTarget);
		sub_101c4810();
	}
	else if (!_strcmpi(command, "DeletePanel"))
	{
		sub_101c47b0();
	}
	else if (!_strcmpi(command, "RevertToSaved"))
	{
		sub_101c4f50();
	}
	else if (!_strcmpi(command, "ShowHelp"))
	{
		sub_101c4f80();
	}
}
// END FUNCTION

// FUNCTION: 0x101c4a20 size=0x52
#include "vgui2__BuildModeDialog.h"

struct Obj { bool sub_101aab50(); };
struct P {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20();
	virtual void v21();
};

struct V {
virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();
virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();
virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();
virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();virtual void v30();virtual void v31();
virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();
virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();
virtual void v48();virtual void v49();virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();
virtual void v56();virtual void v57();virtual void v58();virtual void v59();virtual void v60();virtual void v61();virtual void v62();virtual void v63();
virtual void v64();virtual void v65();virtual void v66();virtual void v67();virtual void v68();virtual void v69();virtual void v70();virtual void v71();
virtual void v72();virtual void v73();virtual void v74();virtual void v75();virtual void v76();virtual void v77();virtual void v78();virtual void v79();
virtual void v80();virtual void v81();virtual void v82();virtual void v83();virtual void v84();virtual void v85();virtual void v86();virtual void v87();
virtual void v88();virtual void v89();virtual void v90();virtual void v91();virtual void v92();virtual void v93();virtual void v94();virtual void v95();
virtual void v96();virtual void v97();virtual void v98();virtual void v99();virtual void v100();virtual void v101();virtual void v102();virtual void v103();
virtual void v104();virtual void v105();virtual void v106();virtual void v107();virtual void v108();virtual void v109();virtual void v110();virtual void v111();
virtual void v112();virtual void v113();virtual void v114();virtual void v115();virtual void v116();virtual void v117();virtual void v118();virtual void v119();
virtual void v120();virtual void v121();virtual void v122();virtual void v123();virtual void v124();virtual void v125();virtual void v126();virtual void v127();
virtual void v128();virtual void v129();virtual void v130();virtual void v131();virtual void v132();virtual void v133();virtual void v134();virtual void v135();
virtual void v136();virtual void v137();virtual void v138();virtual void v139();virtual void v140();virtual void v141();virtual void v142();virtual void v143();
virtual void v144();virtual void v145();virtual void v146();virtual void v147();
virtual void *v148();
};

// TARGET: vgui2::BuildModeDialog::sub_101c4a20
void vgui2::BuildModeDialog::sub_101c4a20()
{
	bool b = ((Obj *)*(void **)((char *)this + 0xe4))->sub_101aab50();
	P *p = *(P **)((char *)this + 0x12c);
	if (!b) {
		if (p)
			p->v21();
		*(P **)((char *)this + 0x12c) = 0;
	} else {
		if (p) {
			p->v21();
			*(P **)((char *)this + 0x12c) = 0;
		}
		*(void **)((char *)this + 0x12c) = ((V *)this)->v148();
	}
}
// END FUNCTION

// FUNCTION: 0x101c4be0 size=0xe8
#include "vgui2__BuildModeDialog.h"
#include "vgui2__Panel.h"
#include "vgui2__KeyValues.h"

extern "C" int __cdecl atoi(const char *);

#define V10(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4(); virtual void a##5(); virtual void a##6(); virtual void a##7(); virtual void a##8(); virtual void a##9();

struct IA
{
	V10(u0) V10(u1) V10(u2) V10(u3) V10(u4) V10(u5) V10(u6) V10(u7) V10(u8) V10(u9)
	virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107();
	virtual void vfunc108(int, char *, int);
};

struct ElemView { int m_unk0; IA *m_pObj; int m_unk8; char m_name[0x40]; int m_nType; };
struct SList { ElemView *m_pData; int m_unk4; int m_unk8; int m_nCount; int m_unk10; void *m_pA; };
#define LST (*(SList **)((char *)this + 0xe8))

vgui2::KeyValues *vgui2::BuildModeDialog::vfunc148()
{
	vgui2::KeyValues *kv = new vgui2::KeyValues((*(vgui2::Panel **)((char *)this + 0xe4))->vfunc18());
	char buf[0x100];
	for (int i = 0; i < LST->m_nCount; i++)
	{
		char *name = LST->m_pData[i].m_name;
		IA *obj = LST->m_pData[i].m_pObj;
		obj->vfunc108(0, buf, 0xff);
		int type = LST->m_pData[i].m_nType;
		if (type >= 4 && type <= 5)
			kv->vfunc15((int)name, atoi(buf));
		else
			kv->vfunc14(name, buf);
	}
	return kv;
}
// END FUNCTION

// FUNCTION: 0x101c4cd0 size=0x1a
#include "vgui2__BuildModeDialog.h"
struct BMD_101c4cd0 {
	void sub_101c4810();
};
void vgui2::BuildModeDialog::vfunc92(int code)
{
	if (code == 0x40)
		((BMD_101c4cd0 *)this)->sub_101c4810();
	else
		this->sub_101b9740(code);
}
// END FUNCTION

// FUNCTION: 0x101c54d0 size=0x6
#include "vgui2__BuildModeDialog.h"
namespace lifted {
extern char g_102d9fc8;
}
int vgui2::BuildModeDialog::vfunc102()
{
    return (int)&lifted::g_102d9fc8;
}
// END FUNCTION
