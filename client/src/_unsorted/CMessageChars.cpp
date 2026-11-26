// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101685e0 size=0x43
#include "engineclient.h"
#include "CMessageChars.h"
#include "CMessageCharsPanel.h"


void *sub_101ac650(unsigned int size);

struct MsgPanel
{
	MsgPanel *sub_10168150(vgui2::Panel *parent);
};

int CMessageChars::vfunc0(int parent)
{
	*(int *)((char *)this + 8) = ((int)cvar->FindVar("con_color"));

	MsgPanel *p = (MsgPanel *)sub_101ac650(0x107064);
	MsgPanel *r;
	if ( p )
		r = p->sub_10168150((vgui2::Panel *)(void *)parent);
	else
		r = 0;

	return (int)(*(MsgPanel **)((char *)this + 4) = r);
}
// END FUNCTION

// FUNCTION: 0x10168630 size=0x24
#include "CMessageChars.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual int f20(int); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual int f33(int); };
}
void CMessageChars::vfunc1()
{
    if ((*(int *)((char *)this + 4)) != 0) {
        int t0 = ((lifted::V *)(*(int *)((char *)this + 4)))->f33(0);
        if ((*(int *)((char *)this + 4)) != 0) {
            ((lifted::V *)(*(int *)((char *)this + 4)))->f20(1);
        }
    }
}
// END FUNCTION

// FUNCTION: 0x10168660 size=0xac
#include <stdarg.h>
#include <stdio.h>
#include "CMessageChars.h"

struct Target_10168660
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
	virtual int vfunc107(float time, int a1, int a2, int a3, int a4, int a5, int a6, int a7, const char *text, int messageID, ...);
};

int CMessageChars::vfunc5(float time, int a1, int a2, int a3, int a4, int a5, int a6, int a7, const char *fmt, int messageID, ...)
{
	char buf[1024];
	va_list args;
	va_start(args, fmt);
	_vsnprintf(buf, sizeof(buf), fmt, args);
	buf[sizeof(buf) - 1] = 0;
	Target_10168660 *p = *(Target_10168660 **)((char *)this + 4);
	if (!p)
		return a2;
	return p->vfunc107(time, a1, a2, a3, a4, a5, a6, a7, buf, messageID);
}
// END FUNCTION

// FUNCTION: 0x101687c0 size=0x8
#include "CMessageChars.h"
namespace lifted {
struct C10168570 { int sub_10168570(); };
}
int CMessageChars::vfunc6()
{
    return ((lifted::C10168570 *)(*(int *)((char *)this + 4)))->sub_10168570();
}
// END FUNCTION

// FUNCTION: 0x101687d0 size=0x42
#include <stdarg.h>
#include "CMessageChars.h"

int CMessageChars::vfunc3(int a1, int a2, int a3, int a4, int a5, int a6, int a7, const char *fmt, int messageID, ...)
{
	va_list argptr;
	va_start(argptr, fmt);
	int ret = vfunc5(0.0f, a1, a2, a3, a4, a5, a6, a7, fmt, messageID, argptr);
	va_end(argptr);
	return ret;
}
// END FUNCTION

// FUNCTION: 0x10168820 size=0x2e
struct IMsg_10168820 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void __cdecl v4(int, int, int, int, int, int, int *); };
void sub_10168820(IMsg_10168820 *p, int a1, int a2, int a3, int a4, int a5)
{
	p->v4(0, a1, a2, a3, a4, a5, &a5);
}
// END FUNCTION

// FUNCTION: 0x10168850 size=0x6f
#include "CMessageChars.h"
#include <stdarg.h>

extern "C" int _vsnprintf(char *, unsigned int, const char *, va_list);

struct V
{
	virtual void u0();  virtual void u1();  virtual void u2();  virtual void u3();
	virtual void u4();  virtual void u5();  virtual void u6();  virtual void u7();
	virtual void u8();  virtual void u9();  virtual void u10(); virtual void u11();
	virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15();
	virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
	virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23();
	virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27();
	virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31();
	virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35();
	virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39();
	virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43();
	virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47();
	virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51();
	virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55();
	virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59();
	virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63();
	virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67();
	virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71();
	virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75();
	virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79();
	virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83();
	virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87();
	virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91();
	virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95();
	virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99();
	virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103();
	virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107();
	virtual void u108(int, int, int, char *);
};

struct MCharsView
{
	char pad0[4];
	V *m_pView;
};

void CMessageChars::vfunc7(int a1, int a2, int a3, const char *fmt, ...)
{
	MCharsView *self = (MCharsView *)this;
	if ( self->m_pView )
	{
		char buf[0x400];
		va_list ap;
		va_start(ap, fmt);
		_vsnprintf(buf, 0x400, fmt, ap);
		buf[0x3ff] = 0;
		self->m_pView->u108(a1, a2, a3, buf);
	}
}
// END FUNCTION

// FUNCTION: 0x101688c0 size=0xd
#include "CMessageChars.h"
namespace lifted {
struct C10168260 { int sub_10168260(); };
}
void CMessageChars::vfunc8()
{
    if ((*(int *)((char *)this + 4)) != 0) {
        ((lifted::C10168260 *)(*(int *)((char *)this + 4)))->sub_10168260(); return;
    }
}
// END FUNCTION
