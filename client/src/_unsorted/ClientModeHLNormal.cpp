// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100295e0 size=0x4
#include "ClientModeHLNormal.h"
char * ClientModeHLNormal::vfunc7()
{
    return (char *)this + 8;
}
// END FUNCTION

// FUNCTION: 0x10029630 size=0x5e
#include "ClientModeHLNormal.h"
#include "vgui2__Panel.h"

// TARGET: ClientModeHLNormal::vfunc3
int sub_1016a6b0();
int sub_101ac8d0();

class IG1027ba58
{
public:
#define D(n) virtual void d##n();
	D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9)
	D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17)
#undef D
	virtual bool vfunc18();
};

extern IG1027ba58 *g_1027ba58;

class ISurfaceX
{
public:
#define D(n) virtual void d##n();
	D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9)
	D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
	D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28) D(29)
	D(30) D(31) D(32) D(33) D(34) D(35) D(36) D(37) D(38) D(39)
	D(40) D(41) D(42) D(43) D(44) D(45) D(46) D(47) D(48) D(49)
	D(50) D(51)
#undef D
	virtual void vfunc52(int);
};

void ClientModeHLNormal::vfunc3()
{
	int x = sub_1016a6b0();
	if (x)
		((vgui2::Panel *)&m_sub)->vfunc33(x);
	if (g_1027ba58->vfunc18())
	{
		((vgui2::Panel *)&m_sub)->vfunc54(m_unk04);
		((ISurfaceX *)sub_101ac8d0())->vfunc52(m_unk04);
	}
	((vgui2::Panel *)&m_sub)->vfunc21(1);
	vfunc5();
}
// END FUNCTION

// FUNCTION: 0x10029690 size=0x27
#include "ClientModeHLNormal.h"
int sub_1016a6b0();
void ClientModeHLNormal::vfunc4()
{
	if (sub_1016a6b0())
		m_sub.v33(0);
	m_sub.v21(0);
}
// END FUNCTION

// FUNCTION: 0x100296c0 size=0x3b
#include "ClientModeHLNormal.h"
struct PanelView { void sub_101a9920(int *, int *); };
struct SubView { void sub_101a9950(int, int, int, int); };
int sub_1016a6b0();
// TARGET: ClientModeHLNormal::vfunc5
void ClientModeHLNormal::vfunc5()
{
	PanelView *p = (PanelView *)sub_1016a6b0();
	if (p)
	{
		int wide, tall;
		p->sub_101a9920(&wide, &tall);
		((SubView *)&m_sub)->sub_101a9950(0, 0, wide, tall);
	}
}
// END FUNCTION

// FUNCTION: 0x10029700 size=0x41
#include "ClientModeHLNormal.h"
struct CUnkInputObj { int sub_100f29d0(float a, int b); };
struct IUnkG4cfdf4 { virtual void v0(); virtual bool IsX(); char m_pad[0x28]; int m_n2c; };
extern IUnkG4cfdf4 *g_104cfdf4;
extern CUnkInputObj g_104cfe38;
int ClientModeHLNormal::vfunc6(float a, int b)
{
	int v;
	if (g_104cfdf4->IsX())
		v = 0;
	else
		v = g_104cfdf4->m_n2c;
	m_sub.v21(v != 0);
	return g_104cfe38.sub_100f29d0(a, b);
}
// END FUNCTION

// FUNCTION: 0x10029770 size=0x3
#include "ClientModeHLNormal.h"
void ClientModeHLNormal::vfunc22(int a0, int a1)
{
}
// END FUNCTION

// FUNCTION: 0x10029780 size=0x1d
#include "ClientModeHLNormal.h"
struct Sub8_10029780
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
	virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
	virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
	virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
	virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
	virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
	virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
	virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
};
struct HLView_10029780 { int m_vptr; Sub8_10029780 m_sub; };
// TARGET: ClientModeHLNormal::vfunc24
void ClientModeHLNormal::vfunc24(int a)
{
	ClientModeShared::vfunc24(a);
	((Sub8_10029780 *)((char *)this + 8))->v107();
}
// END FUNCTION

// FUNCTION: 0x100297b0 size=0x3
#include "ClientModeHLNormal.h"
bool ClientModeHLNormal::vfunc27()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x10029980 size=0x28
#include "C_BasePlayer.h"
#include "ClientModeHLNormal.h"
namespace lifted {
struct C100d4040 { int sub_100d4040(int); };
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual void u168(); virtual void u169(); virtual void u170(); virtual void u171(); virtual void u172(); virtual void u173(); virtual void u174(); virtual void u175(); virtual void u176(); virtual void u177(); virtual void u178(); virtual void u179(); virtual void u180(); virtual void u181(); virtual void u182(); virtual void u183(); virtual void u184(); virtual void u185(); virtual void u186(); virtual int f187(int); };
}
void ClientModeHLNormal::vfunc15(int a0)
{
    if (C_BasePlayer::GetLocalPlayer() != 0) {
        ((lifted::V *)((int)C_BasePlayer::GetLocalPlayer()))->f187(a0);
        ((lifted::C100d4040 *)this)->sub_100d4040(a0);
    }
}
// END FUNCTION
