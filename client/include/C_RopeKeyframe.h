// C_RopeKeyframe: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
#pragma once
#include "C_BaseEntity.h"

#include "CBaseRopePhysics.h"
#include "CBaseHandle.h"

class C_RopeKeyframe : public C_BaseEntity
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	class CPhysicsDelegate : public CSimplePhysics::IHelper
	{
	public:
		virtual void vfunc0(CRopeNode *pNodes, int iNode, Vector *pAccel);
		virtual void vfunc1(CRopeNode *pNodes, int nNodes);

		C_RopeKeyframe *m_pKeyframe;
	};

	C_RopeKeyframe();
    void sub_100c0850(float **pSubdivs, int *pSubdivCount);
    bool sub_100c0630(struct AttV *pEnt, int iAttachment, Vector &vPos, QAngle &angles);
    void sub_100c07b0(int iPoint, Vector &vPos, QAngle &angles);
    bool sub_100c0700(int iPt, Vector &vPos);
    bool sub_100bf790(bool &bApplyWind);	// DetectRestingState
    // the base slots the game's vtable fills with C_RopeKeyframe's own function
    virtual int vfunc15();
    virtual int vfunc16();
    char m_pad0014[0x410 - 0x14];
    bool m_b410;
    char m_b411;
    short m_n412;
    unsigned int m_LockedPoints[1];	// 0x414 (SDK m_LinksTouchingSomething, a CBitVec)
    int m_nLinksTouchingSomething;	// 0x418
    bool m_bApplyWind;
    char m_b41d;
    short m_n41e;
    int m_fPrevLockedPoints;
    int m_iForcePointMoveCounter;
    bool m_bPrevEndPointPos[2];
    short m_n42a;
    Vector m_vPrevEndPointPos[2];
    char m_pad0444[0x44c - 0x444];
    unsigned int m_RopeFlags;
    char m_pad0450[0x458 - 0x450];
    CRopePhysics<10> m_RopePhysics;	// 0x458
    char m_pad0640[0x6bc - 0x640];
    CBaseHandle m_hStartPoint;
    CBaseHandle m_hEndPoint;
    short m_iStartAttachment;
    short m_iEndAttachment;
    unsigned char m_nSubdivs;
    char m_pad06c9[0x6d8 - 0x6c9];
    int m_fLockedPoints;
    char m_pad06dc[0x6f0 - 0x6dc];
    Vector m_vForce;
    float m_flCurWindTime;
    float m_flWindDuration;
    int m_pad0704;
    Vector m_vWindDir;
    char m_pad0714[0x728 - 0x714];
};
