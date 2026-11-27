// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1018b240 size=0x8
#include "CStudiomodelPanel.h"
struct V { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); };
void CStudiomodelPanel::vfunc88() { ((V *)this)->v87(); }
// END FUNCTION

// FUNCTION: 0x1018b250 size=0x1e
#include "CStudiomodelPanel.h"

// VC6 writes CStudiomodelPanel's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CStudiomodelPanel *pcd_emit_1018b250(const CStudiomodelPanel &other) { return new CStudiomodelPanel(other); }

// TARGET: ??_GCStudiomodelPanel@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1018b270 size=0x2a
#include "CStudiomodelPanel.h"
#include "CGUIClientRenderable.h"
// TARGET: ??1CStudiomodelPanel@@UAE@XZ
CStudiomodelPanel::~CStudiomodelPanel()
{
	CGUIClientRenderable *p = (CGUIClientRenderable *)m_p58;
	if (p)
		delete p;
}
// END FUNCTION

// FUNCTION: 0x1018bc10 size=0x16
#include "CStudiomodelPanel.h"
namespace lifted {
struct C1018b110 { int sub_1018b110(); };
}
void CStudiomodelPanel::vfunc3()
{
    if ((*(int *)((char *)this + 0x58)) != 0) {
        if ((*(char *)((char *)this + 0x74)) == 0) {
            ((lifted::C1018b110 *)(*(int *)((char *)this + 0x58)))->sub_1018b110(); return;
        }
    }
}
// END FUNCTION

// FUNCTION: 0x1018bdc0 size=0x73
#include "CStudiomodelPanel.h"

int sub_100cd100();

void CStudiomodelPanel::vfunc84(int iTime, int a2)
{
    if (!*(int *)((char *)this + 0x58))
        return; if (!*(char *)((char *)this + 0x75))
        return; else { float flDelta = (float)((int)iTime - *(int *)((char *)this + 0x70)) * 1440.0f;
    float flAngle; flAngle = flDelta / sub_100cd100() + *(float *)(*(int *)(0x58 + (char *)this) + 0x24);
    int iAngle = ((int)(flAngle * 182.04445f)) & 0xffff;
    *(float *)((char *)*(int *)(0x58 + (char *)this) + 0x24) = (float)iAngle * 0.005493164f;
    *(int *)((char *)this + 0x70) = iTime; }
}
// END FUNCTION

// FUNCTION: 0x1018be40 size=0x9
struct CUnknown1018be40 { char pad[0x74]; char a; char b; void sub_1018be40(); };
void CUnknown1018be40::sub_1018be40() { b = a = 0; }
// END FUNCTION

// FUNCTION: 0x1018be50 size=0x1c
#include "CStudiomodelPanel.h"
namespace lifted {
int sub_101ac8b0();
struct V { virtual void u0(); virtual int f1(int); };
}
void CStudiomodelPanel::vfunc89(int a0)
{
    *(char *)((char *)this + 0x74) = 0;
    *(char *)((char *)this + 0x75) = 0;
    a0 = 0;
    ((lifted::V *)(lifted::sub_101ac8b0()))->f1(a0);
}
// END FUNCTION
