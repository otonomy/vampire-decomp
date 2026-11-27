// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1007fce0 size=0x6
#include "C_Beam.h"
namespace lifted {
extern char g_102acf94;
}
int C_Beam::vfunc16()
{
    return (int)&lifted::g_102acf94;
}
// END FUNCTION

// FUNCTION: 0x1007fcf0 size=0x3
#include "C_Beam.h"
int C_Beam::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10080220 size=0x46
#include "C_Beam.h"
C_Beam::C_Beam()
{
}
// END FUNCTION

// FUNCTION: 0x10080270 size=0x90
#include "C_Beam.h"
#include "Vector.h"

struct VD_10080270 : public Vector {
	~VD_10080270() {}
};

const Vector &C_Beam::vfunc56()
{
	static VD_10080270 s_Pos[128];
	static int nPos = 0;
	nPos = (nPos + 1) & 0x7f;
	Vector &out = s_Pos[nPos];
	VectorAdd(sub_10080650(), *(Vector *)sub_100806f0(), out);
	VectorScale(out, 0.5f, out);
	return out;
}
// END FUNCTION

// FUNCTION: 0x10080300 size=0x1e
#include "C_Beam.h"

// VC6 writes C_Beam's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_Beam *pcd_emit_10080300(const C_Beam &other) { return new C_Beam(other); }

// TARGET: ??_GC_Beam@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10080320 size=0x51
#include "engineclient.h"
#include "C_Beam.h"
__declspec(dllimport) void Msg(const char *, ...);
void C_Beam::vfunc120(const char *szModelName)
{
	int modelIndex = modelinfo->GetModelIndex( szModelName );
	void *model = modelinfo->GetModel( modelIndex );
	if ( model && modelinfo->GetModelType( model ) != 2 )
	{
		Msg( "Setting CBeam to non-sprite model %s\n", szModelName );
	}
	C_BaseEntity::sub_100a0710( szModelName );
}
// END FUNCTION

// FUNCTION: 0x10080380 size=0x32
#include "C_Beam.h"
namespace lifted {
struct C10043230 { int sub_10043230(int); };
int __stdcall sub_1009fc60(int, int);
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual int f21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual int f111(); };
}
void C_Beam::vfunc19()
{
    lifted::sub_1009fc60(0, 0);
    ((lifted::C10043230 *)((char *)this + 0x190))->sub_10043230(0);
    *(int *)((char *)this + 0x48) = 2;
    ((lifted::V *)this)->f111();
    ((lifted::V *)this)->f21();
}
// END FUNCTION

// FUNCTION: 0x100803c0 size=0x8f
#include "CBaseEntityList.h"
#include "C_Beam.h"
#include "CBaseHandle.h"

struct CEntInfo_100803c0
{
	IHandleEntity *m_pEntity;
	int m_SerialNumber;
	int m_pPrev;
};

struct CBaseEntityList_100803c0
{
	void *vtable;
	CEntInfo_100803c0 m_EntPtrArray[1];
};


struct C_Beam_Helper_100803c0
{
	char pad_0[0x4a4];
	CBaseHandle m_hEndEntity;

	void sub_10080450(int pEntity);
	void sub_10080490(C_BaseEntity *pEntity);
};

inline C_BaseEntity *GetEntity_100803c0(const CBaseHandle &h)
{
	if (!h.IsValid())
		return 0;
	const CEntInfo_100803c0 *pInfo = &((CBaseEntityList_100803c0 *)g_pEntityList)->m_EntPtrArray[h.GetEntryIndex()];
	if (pInfo->m_SerialNumber == h.GetSerialNumber())
		return (C_BaseEntity *)pInfo->m_pEntity;
	return 0;
}

void C_Beam::vfunc21()
{
	if (Collideable_vfunc13())
	{
		((C_Beam_Helper_100803c0 *)this)->sub_10080450(Collideable_vfunc13());
	}

	C_Beam_Helper_100803c0 *pSelf = (C_Beam_Helper_100803c0 *)this;
	if (GetEntity_100803c0(pSelf->m_hEndEntity))
	{
		pSelf->sub_10080490(GetEntity_100803c0(pSelf->m_hEndEntity));
	}
}
// END FUNCTION

// FUNCTION: 0x10080e40 size=0x3
#include "C_Beam.h"
int C_Beam::vfunc121()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10080e50 size=0x60
#include "C_Beam.h"
bool C_Beam::vfunc113(bool isbeingremoved, C_BaseEntity *predicted)
{
    C_BaseEntity::vfunc113(isbeingremoved, predicted);
    C_Beam *beam = dynamic_cast<C_Beam *>(predicted);
    if (!beam)
        return true;
    if (*(int *)((char *)beam + 0x184) & 1)
    {
        *(int *)((char *)this + 0x184) |= 1;
        return false;
    }
    return true;
}
// END FUNCTION

// FUNCTION: 0x10081000 size=0x5b
#include "C_Beam.h"
#include "CCollisionProperty.h"
void C_Beam::vfunc37()
{
	IClientRenderable *r = (IClientRenderable *)((char *)this + 4);
	if (r->ShouldDraw())
	{
		if (m_nAttach || m_unk0454[0])
		{
			Vector a, b;
			sub_10081060(&b, &a);
			((CCollisionProperty *)((char *)this + 0x190))->sub_100433c0(&b, (char *)&a);
		}
		sub_100a02e0(false);
	}
}
// END FUNCTION
