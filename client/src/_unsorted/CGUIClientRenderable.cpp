// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10189c30 size=0x4
#include "CGUIClientRenderable.h"
char * CGUIClientRenderable::vfunc12()
{
    return (char *)this + 0x14;
}
// END FUNCTION

// FUNCTION: 0x10189c40 size=0x4
#include "CGUIClientRenderable.h"
char * CGUIClientRenderable::vfunc13()
{
    return (char *)this + 0x20;
}
// END FUNCTION

// FUNCTION: 0x10189c50 size=0x124
#include "CGUIClientRenderable.h"
#include "engineclient.h"
extern "C" __declspec(dllimport) void Plat_Free(void *);
struct PurgeVec
{
	void *m_pMemory; int m_allocationCount; int m_growSize; int m_Size; void *m_pElements;
	~PurgeVec()
	{
		m_Size = 0;
		if (m_growSize != -1)
		{
			if (m_pMemory)
			{
				Plat_Free(m_pMemory);
				m_pMemory = 0;
			}
			m_allocationCount = 0;
		}
		m_pElements = m_pMemory;
		if (m_growSize != -1)
		{
			if (m_pMemory)
			{
				Plat_Free(m_pMemory);
				m_pMemory = 0;
			}
			m_allocationCount = 0;
		}
	}
};
struct LHoldV { void sub_1018ae50(); };
struct GuiView { char pad[0x54]; PurgeVec c; char pad2[0x74 - 0x68]; PurgeVec b; char pad3[0x158 - 0x88]; PurgeVec a; };
// TARGET: ??1CGUIClientRenderable@@QAE@XZ
CGUIClientRenderable::~CGUIClientRenderable()
{
	delete (char *)m_unk08;
	((LHoldV *)this)->sub_1018ae50();
	unsigned short h = *(unsigned short *)((char *)this + 0x10);
	if (h != 0xffff)
	{
		modelrender->vfunc15(h);
		*(unsigned short *)((char *)this + 0x10) = 0xffff;
	}
	GuiView *v = (GuiView *)this;
	v->a.~PurgeVec();
	v->b.~PurgeVec();
	v->c.~PurgeVec();
}
// END FUNCTION

// FUNCTION: 0x1018a1f0 size=0x15b
#include "engineclient.h"
#include "CGUIClientRenderable.h"
#include "Vector.h"
#include "Quaternion.h"
#include "CUnknown100c7f30.h"

struct V3;
struct Q4;
struct SStudioHdr;
struct SPoseHdr;
struct StudioHdr;
struct SeqDesc;

struct SBoneMask
{
	CUnknown100c7f30 m_bits;
	unsigned int m_extra[10];
};



SeqDesc *sub_1008d9d0(StudioHdr *, int);
SPoseHdr *sub_1008d930(SPoseHdr *, int);
void sub_10089c40(char *, V3 *, Q4 *, int, int, float *, char *);
void sub_1008a690(char *, void *, void *, int, int);
void sub_1008a1e0(SStudioHdr *, Vector *, Quaternion *, const float *, SBoneMask *);

void CGUIClientRenderable::vfunc10(Vector *pos, Quaternion *q)
{
	if (!sub_1008d9d0((StudioHdr *)m_pStudioHdr, m_nSequence))
	{
		m_nSequence = 0;
	}

	float curTime = sub_1018a7d0();
	void *hdr = !m_pModel ? 0 : modelrender->GetStudiomodel(m_pModel);

	float poseParameter[24];
	for (int i = 0; i < 24; i++)
	{
		if (!sub_1008d930((SPoseHdr *)hdr, i))
			break;
		poseParameter[i] = sub_1018a860(i, m_flPoseParameter[i], m_flPrevPoseParameter[i], curTime);
	}

	SBoneMask boneComputed;
	boneComputed.m_bits.sub_1008e230((CUnknown100c7f30Hdr *)hdr, 0xfffc);

	float cycle = sub_1018a990(m_flCycle, m_nSequence, poseParameter, m_flPlaybackRate, (float)(curTime * 0.1));
	sub_10089c40((char *)m_pStudioHdr, (V3 *)pos, (Q4 *)q, m_nSequence, *(int *)&cycle, poseParameter, (char *)&boneComputed);
	sub_1018a350(cycle, poseParameter, pos, q);
	sub_1008a690((char *)m_pStudioHdr, pos, q, (int)poseParameter, (int)&boneComputed);

	float controllers[4];
	sub_1018a730(controllers, curTime);
	sub_1008a1e0((SStudioHdr *)m_pStudioHdr, pos, q, controllers, &boneComputed);
	m_flLastCycle = cycle;
}
// END FUNCTION
