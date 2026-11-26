// C_ServerRagdoll: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
#pragma once
#include "C_BaseAnimating.h"
#include "Vector.h"
#include "QAngle.h"
#include "matrix3x4_t.h"

struct CBoneAccessor	// Source's bone accessor: the entity, its bone matrices and the readable / writable bone masks
{
	void *m_pAnimating;	// 0x00
	matrix3x4_t *m_pBones;	// 0x04
	int m_ReadableBones;	// 0x08
	int m_WritableBones;	// 0x0c
};

class C_ServerRagdoll : public C_BaseAnimating
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	C_ServerRagdoll();
    // the base slots the game's vtable fills with C_ServerRagdoll's own function
    virtual int vfunc15();
    virtual int vfunc16();
    virtual void vfunc37();
    virtual int vfunc72();
    virtual void vfunc90();
    virtual void vfunc123(const Vector *pos, const Quaternion *q, const matrix3x4_t &cameraTransform, const struct StudioBoneMask *pBoneComputed);	// BuildTransformations
    virtual int vfunc125(int, int);
    virtual int vfunc126();
    virtual void vfunc131(int, int, int, int, int, int);
    char m_pad0014[0x6e4 - 0x14];
    CBoneAccessor m_BoneAccessor;	// 0x6e4
    char m_pad06f4[0x790 - 0x6f4];
    Vector m_ragPos[30];	// 0x790
    QAngle m_ragAngles[30];	// 0x8f8
    int m_elementCount;	// 0xa60
    int m_boneIndex[30];	// 0xa64
    // ends at 0xadc on purpose: the matched C_ServerRagdoll::vfunc37 views +0xae0 / +0xae4 past sizeof(C_ServerRagdoll); +0xae4 m_flBlendWeight, +0xae8 the blend sequence
};
