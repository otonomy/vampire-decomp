// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100011c0 size=0x6
#include "C_BaseCineCamera.h"
namespace lifted {
extern char g_10270a8c;
}
int C_BaseCineCamera::vfunc16()
{
    return (int)&lifted::g_10270a8c;
}
// END FUNCTION

// FUNCTION: 0x100011d0 size=0x3
#include "C_BaseCineCamera.h"
int C_BaseCineCamera::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10001450 size=0x121
#include "C_BaseCineCamera.h"
#include "CCameraShotTable.h"
extern Vector g_104d4970;
extern Vector g_104d5190;
extern CCameraShotTable g_102ea298;
C_BaseCineCamera::C_BaseCineCamera()
{
	m_v410 = g_104d4970;
	m_v41c = g_104d4970;
	m_v428 = g_104d5190;
	m_f458 = 75.0f;
	m_n45c = 0;
	m_b465 = 0;
	m_v468.Init(0, 0, 0);
	m_v474.Init(0, 0, 0);
	g_102ea298.sub_10029200("vdata/CameraShots/*.txt");
	m_n490 = 0;
	m_f480 = 75.0f;
	m_n460 = 0;
	m_n498 = 0;
	m_b4a0 = 0;
}
// END FUNCTION

// FUNCTION: 0x10001900 size=0x1e
#include "C_BaseCineCamera.h"

// VC6 writes C_BaseCineCamera's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_BaseCineCamera *pcd_emit_10001900(const C_BaseCineCamera &other) { return new C_BaseCineCamera(other); }

// TARGET: ??_GC_BaseCineCamera@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10001920 size=0x4e
#include "C_BaseCineCamera.h"

struct CShotV
{
	char m_pad0[0x20];
	int m_nFlags;
};

struct CUnknown10001f20
{
	int sub_10001f20();
};

struct IFace103eec98
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void v9();
	virtual void v10();
	virtual void v11();
	virtual void v12();
	virtual void v13();
	virtual void v14();
	virtual void v15();
	virtual void v16();
	virtual void v17();
	virtual void v18();
	virtual void v19();
	virtual void v20();
	virtual void v21();
	virtual void v22();
	virtual void v23();
	virtual void v24();
	virtual void v25();
	virtual void v26();
	virtual void v27();
	virtual void v28();
	virtual void v29();
	virtual void v30();
	virtual void v31();
	virtual void v32();
	virtual void v33();
	virtual void v34();
	virtual void v35();
	virtual void v36();
	virtual void v37();
	virtual void v38();
	virtual void v39();
	virtual void v40();
	virtual void v41();
	virtual void v42();
	virtual void v43();
	virtual void v44();
	virtual void v45();
	virtual void v46();
	virtual void v47();
	virtual void v48();
	virtual void v49();
	virtual void v50();
	virtual void v51();
	virtual void v52();
	virtual void v53();
	virtual void v54();
	virtual void v55();
	virtual void v56();
	virtual void v57();
	virtual void v58();
	virtual void v59();
	virtual void v60();
	virtual void v61();
	virtual void v62();
	virtual void v63();
	virtual void v64();
	virtual void v65();
	virtual void v66();
	virtual void v67();
	virtual void v68();
	virtual void v69();
	virtual void v70();
	virtual void v71();
	virtual void v72();
	virtual void v73();
	virtual void v74();
	virtual void v75();
	virtual void v76();
	virtual void v77();
	virtual void v78();
	virtual void v79();
	virtual void v80();
	virtual void v81();
	virtual void v82();
	virtual void v83();
	virtual void v84();
	virtual void v85();
	virtual void v86();
	virtual void v87();
	virtual void v88();
	virtual void v89();
	virtual void v90();
	virtual void v91();
	virtual void v92();
	virtual void v93();
	virtual void v94();
	virtual void v95();
	virtual void v96();
	virtual void v97();
	virtual void v98();
	virtual void v99();
	virtual void v100();
	virtual void v101();
	virtual void v102();
	virtual void v103();
	virtual void v104();
	virtual void v105();
	virtual void v106();
	virtual void v107();
	virtual void v108();
	virtual void v109();
	virtual void v110();
	virtual void v111();
	virtual void v112();
	virtual void v113();
	virtual void v114(int);
};

int sub_10058080();

C_BaseCineCamera::~C_BaseCineCamera()
{
	CShotV *pShot = (CShotV *)((CUnknown10001f20 *)this)->sub_10001f20();
	if (!(pShot->m_nFlags & 0x200))
	{
		IFace103eec98 *pObj = (IFace103eec98 *)sub_10058080();
		pObj->v114(0xa06d);
	}
}
// END FUNCTION
