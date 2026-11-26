// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101260b0 size=0x6
#include "C_ServerRagdollAttached.h"
namespace lifted {
extern char g_102c2f34;
}
int C_ServerRagdollAttached::vfunc16()
{
    return (int)&lifted::g_102c2f34;
}
// END FUNCTION

// FUNCTION: 0x101260c0 size=0x3
#include "C_ServerRagdollAttached.h"
int C_ServerRagdollAttached::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10126260 size=0x38f
#include "C_ServerRagdollAttached.h"
#include "StudioHdr.h"
#include "matrix3x4_t.h"
#include "CVProfile.h"

struct CGlobalVarsView
{
	float realtime;
	int framecount;
	float absoluteframetime;
	float curtime;
};
extern CGlobalVarsView *g_102b8494;
extern CVProfile *g_101e3138;
__declspec(dllimport) void vtune(bool);

struct CCycleCount
{
	CCycleCount() { m_Int64 = 0; }
	void Sample()
	{
		unsigned long *pSample = (unsigned long *)&m_Int64;
		__asm
		{
			mov ecx, pSample
			rdtsc
			mov [ecx], eax
			mov [ecx+4], edx
		}
	}
	unsigned __int64 m_Int64;
};

// CVProfNode::ExitScope as vprof.h inlines it (the timer's End, the frame time, the budget group pop)
inline bool VProfNodeExitScope(CVProfNode *pNode)
{
	if (--pNode->m_nRecursions == 0 && pNode->m_nCurFrameCalls != 0)
	{
		CCycleCount cnt;
		cnt.Sample();
		pNode->m_CurFrameTime.v = cnt.m_Int64 - pNode->m_CurFrameTime.v;
		pNode->m_TotalTime += pNode->m_CurFrameTime;

		CVProfile *g = g_101e3138;
		g->m_nDepth--;
		if (g->m_Stack[g->m_nDepth] != g->m_Stack[g->m_nDepth + 1])
		{
			if (g->m_bEnabled && g->m_Stack[g->m_nDepth + 1] == g->m_nCurBudget)
				vtune(false);
		}
	}
	return pNode->m_nRecursions == 0;
}

// CVProfile::ExitScope as vprof.h inlines it
inline void VProfExitScope()
{
	CVProfile *pProf = g_101e3138;
	if (!pProf->m_fAtRoot || pProf->m_nPause != 0)
	{
		if (VProfNodeExitScope(pProf->m_pCurNode))
			pProf->m_pCurNode = pProf->m_pCurNode->m_pParent;
		pProf->m_fAtRoot = (pProf->m_pCurNode == pProf->m_pRoot);
	}
}

inline float RemapVal(float val, float A, float B, float C, float D)
{
	return C + (D - C) * (val - A) / (B - A);
}

#define clamp(val, min, max) (((val) > (max)) ? (max) : (((val) < (min)) ? (min) : (val)))

struct Ent_100921d0 { C_BaseAnimating *sub_100921d0(); };
struct Anim_1008fcd0 { void sub_1008fcd0(int iBone, matrix3x4_t &matrix); };

void sub_10107f80(const Vector &in, const matrix3x4_t &matrix, Vector &out);
void sub_10108510(const matrix3x4_t &matrix, int column, Vector &out);
void sub_10108540(const Vector &in, int column, matrix3x4_t &matrix);

void C_ServerRagdollAttached::vfunc123(const Vector *pos, const Quaternion *q, const matrix3x4_t &cameraTransform, const StudioBoneMask *pBoneComputed)
{
	g_101e3138->EnterScope("C_ServerRagdollAttached::SetupBones", 0, "Client Animation", false);

	StudioHdr *hdr = (StudioHdr *)sub_1008f900(-1);
	if (!hdr)
	{
		g_101e3138->ExitScope();
		return;
	}

	float frac = RemapVal(g_102b8494->curtime, m_parentTime, m_parentTime + 0.2, 0, 1);
	frac = clamp(frac, 0, 1);
	Vector offset = m_vecOffset * (1 - frac);

	C_BaseAnimating *parent = 0;
	Vector worldOrigin;
	worldOrigin.Init();

	if (sub_100a1140())
	{
		parent = ((Ent_100921d0 *)this)->sub_100921d0();
		if (parent)
		{
			parent->SetupBones(0, -1, 0xfffc, g_102b8494->curtime, 0);
			matrix3x4_t boneToWorld;
			((Anim_1008fcd0 *)parent)->sub_1008fcd0(m_boneIndexAttached, boneToWorld);
			sub_10107f80(m_attachmentPointBoneSpace, boneToWorld, worldOrigin);
		}
	}

	C_ServerRagdoll::vfunc123(pos, q, cameraTransform, pBoneComputed);

	if (parent)
	{
		int index = m_boneIndex[m_ragdollAttachedObjectIndex];
		const matrix3x4_t &matrix = m_BoneAccessor.m_pBones[index];
		Vector ragOrigin;
		sub_10107f80(m_attachmentPointRagdollSpace, matrix, ragOrigin);
		offset = worldOrigin - ragOrigin;
		sub_100a2030(&worldOrigin);
		m_vecOffset = offset;
	}

	for (int i = 0; i < hdr->m_nBones; i++)
	{
		if (!(pBoneComputed->m_bits[i >> 5] & (1 << (i & 31))))
			continue;

		Vector bonePos;
		matrix3x4_t &matrix = m_BoneAccessor.m_pBones[i];
		sub_10108510(matrix, 3, bonePos);
		bonePos += offset;
		sub_10108540(bonePos, 3, matrix);
	}

	VProfExitScope();
}
// END FUNCTION

// FUNCTION: 0x101265f0 size=0x1e
#include "C_ServerRagdollAttached.h"

// VC6 writes C_ServerRagdollAttached's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_ServerRagdollAttached *pcd_emit_101265f0() { return new C_ServerRagdollAttached; }

// TARGET: ??_GC_ServerRagdollAttached@@UAEPAXI@Z
// END FUNCTION
