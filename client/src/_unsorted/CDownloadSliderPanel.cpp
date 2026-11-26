// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10165b00 size=0x1e
#include "CDownloadSliderPanel.h"

// VC6 writes CDownloadSliderPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CDownloadSliderPanel *pcd_emit_10165b00(const CDownloadSliderPanel &other) { return new CDownloadSliderPanel(other); }

// TARGET: ??_GCDownloadSliderPanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10165b30 size=0x15
#include "CDownloadSliderPanel.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(int); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual int f107(); };
}
void CDownloadSliderPanel::vfunc2()
{
    ((lifted::V *)this)->f21(((lifted::V *)this)->f107());
}
// END FUNCTION

// FUNCTION: 0x10165b50 size=0x59
#include "engineclient.h"
#include "CDownloadSliderPanel.h"




class CDownloadChild
{
public:
	virtual void c0() = 0;
	virtual bool c1() = 0;
	char m_pad4[0x2c - 4];
	int m_i2c;
};

class CDownloadPanel
{
public:
	virtual void p0() = 0;
	virtual void p1() = 0;
	virtual void p2() = 0;
	virtual void p3() = 0;
	virtual void p4(int) = 0;
	CDownloadChild *m_pChild;
};

struct CDownloadSliderLayout
{
	char m_pad00[0x58];
	CDownloadPanel *m_pPanel;
};

// TARGET: CDownloadSliderPanel::vfunc107
bool CDownloadSliderPanel::vfunc107()
{
	CDownloadSliderLayout *s = (CDownloadSliderLayout *)this;
	CDownloadPanel *p = s->m_pPanel;
	if (!p)
		return false;
	if (!p->m_pChild->c1() && p->m_pChild->m_i2c < 0)
		return false;
	if (render->vfunc35() || engine->vfunc58() == 0)
	{
		s->m_pPanel->p4(-1);
		return false;
	}
	return true;
}
// END FUNCTION

// FUNCTION: 0x10165bb0 size=0x1
#include "CDownloadSliderPanel.h"
void CDownloadSliderPanel::vfunc108()
{
}
// END FUNCTION
