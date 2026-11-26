// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100dfe00 size=0x28
#include "CBaseStaticModel.h"
CBaseStaticModel::CBaseStaticModel() : m_unk38(0), m_unk3e(0xff)
{
	m_unk3c = 0xffff;
}
// END FUNCTION

// FUNCTION: 0x100dfe50 size=0x24
#include "engineclient.h"
#include "CBaseStaticModel.h"
CBaseStaticModel::~CBaseStaticModel()
{
	if (m_unk3c != 0xFFFF)
		modelrender->vfunc15(m_unk3c);
}
// END FUNCTION

// FUNCTION: 0x100dff30 size=0x23
#include "engineclient.h"
#include "CBaseStaticModel.h"
bool CBaseStaticModel::IsTransparent()
{
	return m_unk3e < 255 || modelinfo->vfunc9(m_unk38);
}
// END FUNCTION

// FUNCTION: 0x100dff60 size=0xb
#include "CBaseStaticModel.h"
namespace lifted {
extern int g_105f99d8;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual bool f10(); };
}
bool CBaseStaticModel::ShouldDraw()
{
    return ((lifted::V *)lifted::g_105f99d8)->f10();
}
// END FUNCTION

// FUNCTION: 0x100dff70 size=0x43
#include "CBaseStaticModel.h"
void CBaseStaticModel::GetRenderBounds(Vector &mins, Vector &maxs)
{
	mins = m_vecMins - m_vecOrigin;
	maxs = m_vecMaxs - m_vecOrigin;
}
// END FUNCTION

// FUNCTION: 0x100dffc0 size=0x2d
#include "CBaseStaticModel.h"
// TARGET: ?GetRenderBoundsWorldspace@CBaseStaticModel@@UAEXAAVVector@@0@Z
void CBaseStaticModel::GetRenderBoundsWorldspace(Vector &mins, Vector &maxs)
{
	mins = m_vecMins;
	maxs = m_vecMaxs;
}
// END FUNCTION

// FUNCTION: 0x100e0030 size=0xb8
#include "CBaseStaticModel.h"
struct CModelInfoView { virtual void *vfunc0(int handle); };
struct StudioView { char m_pad[0xa8]; char m_a8[0x48]; int m_nBones; };
extern CModelInfoView *g_104a57d8;
void sub_101094e0(const QAngle *ang, void *matrix);
void sub_10108430(void *a, void *b);
void sub_10107f80(void *a, void *b, void *c);
struct MatView { float m[12]; };
bool CBaseStaticModel::SetupBones(matrix3x4_t *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime, int a4)
{
	if (m_unk38) {
		const QAngle &ang = GetRenderAngles();
		const Vector &org = GetRenderOrigin();
		MatView mat;
		sub_101094e0(&ang, &mat);
		mat.m[3] = org.x;
		mat.m[7] = org.y;
		mat.m[11] = org.z;
		StudioView *hdr = (StudioView *)g_104a57d8->vfunc0(m_unk38);
		if (hdr) {
			for (int i = 0; i < hdr->m_nBones; i++)
				sub_10108430(&mat, (char *)pBoneToWorldOut + i * 0x30);
			if (a4)
				sub_10107f80(hdr->m_a8, &mat, (void *)a4);
			return true;
		}
	}
	return false;
}
// END FUNCTION

// FUNCTION: 0x100e0120 size=0xe3
#include "C_BasePlayer.h"
#include "CBaseStaticModel.h"

extern void *g_102d43d8;
extern void *g_104a57ec;
extern void *g_104a57d8;

struct ILeaf39 {
	virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
	virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
	virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
	virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
	virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
	virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
	virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
	virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
	virtual void s36(); virtual void s37(); virtual void s38();
	virtual bool s39(int, void *);
};

struct IMatSys30 {
	virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
	virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
	virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
	virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
	virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
	virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
	virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
	virtual void s28();
	virtual void s29(int);
};

struct IModelRender9 {
	virtual void s0();
	virtual void s1();
	virtual int s2(int, void *, unsigned short, void *, void *, void *, int, int, int);
	virtual void s3(int);
};

struct IColl16 {
	virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
	virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
	virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
	virtual void s12(); virtual void s13(); virtual void s14();
	virtual void s15(Vector *, Vector *);
};

// TARGET: CBaseStaticModel::DrawModel
int CBaseStaticModel::DrawModel(int flags, int a1)
{
	if (!m_unk3e || !m_unk38)
		return 0;

	int result = 0;
	bool bSkip;
	bool bCheck = ((ILeaf39 *)g_102d43d8)->s39(0, &bSkip);
	if (bCheck) {
		if (C_BasePlayer::GetLocalPlayer()) {
			Vector vA, vB;
			((IColl16 *)((char *)C_BasePlayer::GetLocalPlayer() + 0x190))->s15(&vB, &vA);
			if (vA.z + 10.0f < m_vecMaxs.z)
				bSkip = true;
		}
	}
	if (!bSkip) {
		((IMatSys30 *)g_104a57ec)->s29(0);
		void *pRend = this ? (void *)((char *)this + 4) : 0;
		result = ((IModelRender9 *)g_104a57d8)->s2(flags, pRend, m_unk3c,
			(void *)m_unk38, &m_vecOrigin, (void *)((char *)this + 0x14), 0, 0, a1);
	}
	if (bCheck) {
		((IModelRender9 *)g_104a57d8)->s3(0);
	}
	return result;
}
// END FUNCTION

// FUNCTION: 0x100e13b0 size=0x3
#include "CBaseStaticModel.h"
ICollideable * CBaseStaticModel::GetClientCollideable()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100e13c0 size=0x3
#include "CBaseStaticModel.h"
IClientNetworkable * CBaseStaticModel::GetClientNetworkable()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100e13d0 size=0xb
#include "CBaseStaticModel.h"
IClientRenderable * CBaseStaticModel::GetClientRenderable()
{
    if (((int)this) != 0) {
        return (IClientRenderable *)((char *)this + 4);
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100e13e0 size=0x3
#include "CBaseStaticModel.h"
IClientEntity * CBaseStaticModel::GetIClientEntity()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100e13f0 size=0x3
#include "CBaseStaticModel.h"
C_BaseEntity * CBaseStaticModel::GetBaseEntity()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100e1400 size=0x3
#include "CBaseStaticModel.h"
IClientThinkable * CBaseStaticModel::GetClientThinkable()
{
    return 0;
}
// END FUNCTION
