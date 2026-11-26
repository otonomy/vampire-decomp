// StudioHdr: the fields of the studio model header (the object CBaseAnimating::GetModelPtr returns) that
// decompiled code reads. Only what the sequence / hitbox lookups need.
#pragma once

#include "Vector.h"
#include "Quaternion.h"

struct StudioHdr;

struct StudioVirtualModel	// the object behind an include model: slot 1 gives the included model's header
{
	virtual void vfunc0();
	virtual StudioHdr *vfunc1(StudioHdr *pOwner, int index);
};

struct StudioIncludeModel	// 0x74 bytes: a model whose sequences are included
{
	char m_pad00[4];
	StudioVirtualModel *m_pVirtual;	// 0x04
	int m_nBase;	// 0x08: first sequence index
	int m_nCount;	// 0x0c: sequence count
	int m_nBoneInfoIndex;	// 0x10: offset of the per-owner-bone records (0x38 bytes each)
	short m_aBoneRemap14[24];	// 0x14: for an index of the accumulated attachment list, the included model's attachment index
	short m_aPoseParamRemap[24];	// 0x44: the pose parameter of the owner each of the included model's parameters follows (-1: none)
};

struct StudioSeqDesc	// 0x2fc bytes each (the sequence lookups at 0x10427df0 read these)
{
	char m_pad00[8];
	unsigned int m_flags;	// 0x08: bit 0x100 / 0x200 are the two exclusion flags the activity lookup's char arguments test
	int m_nActivity;	// 0x0c: the activity the sequence plays
	int m_nActivityWeight;	// 0x10: its weight (the lookup stores it next to the sequence index)
	char m_pad14[0x29c - 0x14];
	int m_weightlistindex;	// 0x29c: offset of the per-bone weights (floats)
	char m_pad2a0[0x2b8 - 0x2a0];
	int m_nMaxWeight;	// 0x2b8: compared with the lookup's last argument (the lookup keeps the sequence when either is negative or the argument <= it... i.e. rejects when 0 <= arg < this)
	char m_pad2bc[0x2fc - 0x2bc];

	float weight(int i) const { return *((float *)((char *)this + m_weightlistindex) + i); }
};

struct StudioBone	// 0xa0 bytes each (Studio_BuildMatrices 0x100c3600 reads these)
{
	char m_pad00[4];
	int m_iParent;	// 0x04: parent bone index, -1 for a root
	char m_pad08[0x20 - 8];
	Vector m_pos;	// 0x20
	Quaternion m_quat;	// 0x2c
	char m_pad3c[0x88 - 0x3c];
	unsigned char m_bFlags88;	// 0x88: bit 1 (value 2) = the bone's rotation is not inherited from the parent (only the translation is: rotation = the root matrix * bone rotation)
	char m_pad89[0x90 - 0x89];
	int m_nProcIndex90;	// 0x90: offset of the procedural bone record from this bone (0 = none)
	void *pProcedure() { if (m_nProcIndex90 == 0) return 0; return (char *)this + m_nProcIndex90; }
	short m_nPhysicsBone94;	// 0x94
	char m_pad96[0x9c - 0x96];
	unsigned int m_nFlags9c;	// 0x9c: contents

	char *Name() { return (char *)this + *(int *)this; }
};

struct StudioBoneMask	// the bit list of bones to build (0x100c3600's last argument): bit i is tested at m_bits[i >> 5] & (1 << (i & 31))
{
	int m_nSize;	// 0x00
	unsigned int m_bits[1];	// 0x04
};

struct StudioHitbox	// 0x20 bytes each: a hitbox of a hitbox set
{
	int m_iBone;	// 0x00: the bone the box is attached to (index into the bone array)
	int m_iGroup;	// 0x04
	Vector m_vecMins;	// 0x08: the box in bone space
	Vector m_vecMaxs;	// 0x14
};

struct StudioHitboxSet	// 0xc bytes each (the table at header + m_nHitboxSetIndex)
{
	int m_iName;	// 0x00: offset of the set's name string
	int m_nHitboxes;	// 0x04: number of StudioHitbox records
	int m_iHitboxIndex;	// 0x08: offset of the records from the start of the set
	StudioHitbox *Hitbox(int i) { return (StudioHitbox *)((char *)this + m_iHitboxIndex) + i; }
};

struct StudioHdr
{
	char m_pad0000[0x0c];
	char m_name[64];	// 0x0c: the model's path ("error/missing.mdl" when the model failed to load)
	char m_pad004c[0xf0 - 0x4c];
	int m_nBones;	// 0xf0: number of bones
	int m_nBoneIndex;	// 0xf4: offset of the bone records (StudioBone, 0xa0 bytes each)
	char m_pad00f8[0x100 - 0xf8];
	int m_nHitboxSets;	// 0x100: number of hitbox sets
	int m_nHitboxSetIndex;	// 0x104: offset of the hitbox set records (StudioHitboxSet, 0xc bytes each)
	char m_pad0108[0x110 - 0x108];
	int m_nLocalSeq;	// 0x110: number of local sequences
	int m_nLocalSeqIndex;	// 0x114: offset of the local sequence descriptors (StudioSeqDesc, 0x2fc bytes each)
	void *m_pSeqCache118;	// 0x118: zero until sub_10427a70 (0x1000.. stub 0x100115f4) has built the sequence data (sub_10427dc0 calls it)
	char m_pad011c[0x180 - 0x11c];
	int m_nAttachments;	// 0x180: number of attachment records (0x14 bytes each, name offset first)
	int m_nAttachmentIndex;	// 0x184: offset of the attachment records
	char m_pad0188[0x194 - 0x188];
	int m_nIncludeModels;	// 0x194
	int m_nIncludeIndex;	// 0x198: offset of the include model records

	StudioBone *Bone(int i) { return (StudioBone *)((char *)this + m_nBoneIndex) + i; }
	StudioIncludeModel *IncludeModel(int i) { return (StudioIncludeModel *)((char *)this + m_nIncludeIndex) + i; }
	StudioSeqDesc *LocalSeq(int i) { return (StudioSeqDesc *)((char *)this + m_nLocalSeqIndex) + i; }
	StudioSeqDesc *pSeqdesc(int i) { if (i < 0) i = 0; return (StudioSeqDesc *)((char *)this + m_nLocalSeqIndex) + i; }	// the game's inline: a negative index reads sequence 0
	StudioHitboxSet *HitboxSet(int i) { return (StudioHitboxSet *)((char *)this + m_nHitboxSetIndex) + i; }
};

	// CStudioHdr::LookupBone thunk (jmp sub_100c6280): index of the bone / attachment named pName, -1 when missing
