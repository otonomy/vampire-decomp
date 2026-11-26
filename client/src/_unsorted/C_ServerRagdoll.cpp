// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10125770 size=0x1e
#include "C_ServerRagdoll.h"

// VC6 writes C_ServerRagdoll's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_ServerRagdoll *pcd_emit_10125770(const C_ServerRagdoll &other) { return new C_ServerRagdoll(other); }

// TARGET: ??_GC_ServerRagdoll@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101257a0 size=0xc9
#include "engineclient.h"
#include "C_ServerRagdoll.h"
#include "ConVar.h"
#include "matrix3x4_t.h"
#include "QAngle.h"

extern ConVar g_1049c448;

struct vcollide_t_101257a0
{
	int solidCount;
	void **solids;
};




void sub_101094b0(const QAngle &angles, const Vector &position, matrix3x4_t &matrix);
void sub_101267c0(void *pCollide, void *pMaterial, const matrix3x4_t &matrix);

// TARGET: C_ServerRagdoll::vfunc125
int C_ServerRagdoll::vfunc125(int flags, int a1)
{
	if (g_1049c448.GetBool())
	{
		vcollide_t_101257a0 *pCollide = ((vcollide_t_101257a0 *)modelinfo->vfunc18(vfunc51()));
		void *pMaterial = materials->FindMaterial("shadertest/wireframevertexcolor", 0, true);
		matrix3x4_t matrix;
		for (int i = 0; i < *(int *)((char *)this + 0xa60); i++)
		{
			sub_101094b0(
				((QAngle *)((char *)this + 0x8f8))[i],
				((Vector *)((char *)this + 0x790))[i],
				matrix);
			sub_101267c0(pCollide->solids[i], pMaterial, matrix);
		}
	}
	return C_BaseAnimating::vfunc125(flags, a1);
}
// END FUNCTION

// FUNCTION: 0x10125920 size=0xae
#include "engineclient.h"
#include "C_ServerRagdoll.h"
#include "CCollisionProperty.h"
// TARGET: C_ServerRagdoll::vfunc126
int C_ServerRagdoll::vfunc126()
{
	Vector mins, maxs;
	CCollisionProperty *c = (CCollisionProperty *)((char *)this + 0x190);
	c->sub_10043860(c->m_vecMins, *(Vector *)((char *)c + 0x10), &mins, &maxs);
	const Vector &org = GetAbsOrigin();
	const Vector &src = *(Vector *)((char *)this + 0x790);
	Vector d;
	d.x = src.x - org.x;
	d.y = src.y - org.y;
	d.z = src.z - org.z;
	VectorAdd(mins, d, mins);
	VectorAdd(maxs, d, maxs);
	return !engine->vfunc72(mins, maxs);
}
// END FUNCTION

// FUNCTION: 0x10125a70 size=0x38
#include "CGlobalVarsBase.h"
#include "C_ServerRagdoll.h"
float sub_1010c2e0(float target, float value, float speed);
struct RagView : public C_ServerRagdoll { char pad[0xae0 - sizeof(C_ServerRagdoll)]; float m_fae0; float m_fae4; };
// TARGET: C_ServerRagdoll::vfunc37
void C_ServerRagdoll::vfunc37()
{
    C_BaseAnimating::vfunc37();
    RagView *r = (RagView *)this;
    r->m_fae4 = sub_1010c2e0(r->m_fae0, r->m_fae4, gpGlobals->frametime * 5.0f);
}
// END FUNCTION

// FUNCTION: 0x10125ab0 size=0x88
#include "C_ServerRagdoll.h"

struct StudioHdr_10125ab0
{
	char pad_0[0x110];
	int numseq;
};

struct BoneList_10125ab0
{
	int data[12];
	void sub_1008e230(StudioHdr_10125ab0 *hdr, int mask);
};

struct ServerRagdoll_Helper_10125ab0
{
	char pad_0[0x648];
	int m_nField648;
	char pad_64c[0x498];
	float m_flFieldAE4;
	int m_nFieldAE8;
};

extern void sub_1008a110(StudioHdr_10125ab0 *hdr, int a2, int a3, int a4, int a5, int a6, BoneList_10125ab0 *pBones, float a8, int a9);

void C_ServerRagdoll::vfunc131(int a1, int a2, int a3, int a4, int a5, int a6)
{
	C_BaseAnimating::vfunc131(a1, a2, a3, a4, a5, a6);

	ServerRagdoll_Helper_10125ab0 *pSelf = (ServerRagdoll_Helper_10125ab0 *)this;
	StudioHdr_10125ab0 *pHdr = (StudioHdr_10125ab0 *)a1;
	if (pSelf->m_nFieldAE8 >= 0 && pSelf->m_nFieldAE8 < pHdr->numseq)
	{
		BoneList_10125ab0 boneList;
		boneList.sub_1008e230(pHdr, a6);
		sub_1008a110(pHdr, a2, a3, pSelf->m_nFieldAE8, pSelf->m_nField648, a4, &boneList, pSelf->m_flFieldAE4, a5);
	}
}
// END FUNCTION

// FUNCTION: 0x10125b40 size=0x27d
#include "C_ServerRagdoll.h"
#include "StudioHdr.h"
#include "matrix3x4_t.h"

extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)

void sub_101094b0(const QAngle &angles, const Vector &position, matrix3x4_t &matrix);
bool sub_1008b180(StudioHdr *pHdr, int iBone, CBoneAccessor *pAccessor);
void sub_1010a570(const Quaternion &q, matrix3x4_t &matrix);
void sub_10108a50(const matrix3x4_t &in1, const matrix3x4_t &in2, matrix3x4_t &out);

// the blend members behind C_ServerRagdoll's declared ones (C_ServerRagdoll::vfunc37's matched source views +0xae0 / +0xae4 from sizeof(C_ServerRagdoll))
struct C_ServerRagdollBlendView : public C_ServerRagdoll
{
	int m_unkadc;
	float m_unkae0;
	float m_flBlendWeight;	// 0xae4
	int m_iBlendSequence;	// 0xae8
};

void C_ServerRagdoll::vfunc123(const Vector *pos, const Quaternion *q, const matrix3x4_t &cameraTransform, const StudioBoneMask *pBoneComputed)
{
	StudioHdr *hdr = (StudioHdr *)sub_1008f900(-1);
	if (!hdr)
		return;

	matrix3x4_t bonematrix;
	bool boneSimulated[350];
	memset(boneSimulated, 0, sizeof(boneSimulated));
	StudioBone *pbones = hdr->Bone(0);

	C_ServerRagdollBlendView *pThis = (C_ServerRagdollBlendView *)this;
	StudioSeqDesc *pSeqDesc = 0;
	if (pThis->m_iBlendSequence >= 0 && pThis->m_iBlendSequence < hdr->m_nLocalSeq)
		pSeqDesc = hdr->pSeqdesc(pThis->m_iBlendSequence);

	int i;
	for (i = 0; i < m_elementCount; i++)
	{
		int index = m_boneIndex[i];
		if (index >= 0 && (pBoneComputed->m_bits[index >> 5] & (1 << (index & 31))))
		{
			matrix3x4_t &matrix = m_BoneAccessor.m_pBones[index];
			boneSimulated[index] = true;
			if (pThis->m_flBlendWeight != 0.0f && pSeqDesc && pSeqDesc->weight(index) != 0.0f)
			{
				boneSimulated[index] = false;
				continue;
			}
			sub_101094b0(m_ragAngles[i], m_ragPos[i], matrix);
		}
	}

	for (i = 0; i < hdr->m_nBones; i++)
	{
		if (!(pBoneComputed->m_bits[i >> 5] & (1 << (i & 31))))
			continue;
		if (boneSimulated[i])
			continue;
		if (sub_1008b180(hdr, i, &m_BoneAccessor))
			continue;

		sub_1010a570(q[i], bonematrix);
		bonematrix[0][3] = pos[i].x;
		bonematrix[1][3] = pos[i].y;
		bonematrix[2][3] = pos[i].z;

		if (pbones[i].m_iParent == -1)
		{
			sub_10108a50(cameraTransform, bonematrix, m_BoneAccessor.m_pBones[i]);
		}
		else
		{
			sub_10108a50(m_BoneAccessor.m_pBones[pbones[i].m_iParent], bonematrix, m_BoneAccessor.m_pBones[i]);
		}
	}
}
// END FUNCTION

// FUNCTION: 0x10125e50 size=0x6
#include "C_ServerRagdoll.h"
namespace lifted {
extern char g_102c2ea0;
}
int C_ServerRagdoll::vfunc16()
{
    return (int)&lifted::g_102c2ea0;
}
// END FUNCTION

// FUNCTION: 0x10125e60 size=0x3
#include "C_ServerRagdoll.h"
int C_ServerRagdoll::vfunc15()
{
    return 0;
}
// END FUNCTION
