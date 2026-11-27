// C_Beam: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
#pragma once
#include "C_BaseEntity.h"
#include "CBaseHandle.h"

struct Vector3;
struct EntV;
struct CUnknown100a2de0 { void sub_100a2de0(int); };
class C_Beam : public C_BaseEntity
{
public:
	C_Beam();
	void sub_10080450(EntV *pEnt);
	void sub_10081060(Vector *a, Vector *b);
	void sub_10080490(void *pEntity);
	void sub_100804f0(char *arg);
	void sub_100805a0(char *arg);
	Vector3 *sub_100806f0();
	void sub_10080890(int, int);
	void sub_10080c70();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_Beam's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual void vfunc19();
	virtual void vfunc21();
	virtual void vfunc37();
	virtual const Vector &vfunc56();
	virtual bool vfunc113(bool isbeingremoved, C_BaseEntity *predicted);
	// the slots C_Beam adds to its base's vtable: 120-121, vfuncK at slot K
	virtual void vfunc120(const char *szModelName);
	virtual int vfunc121();
	int m_unk0014[(0x41c - 0x14) / 4];
	int m_nNumBeamEnts;	// 0x41c
	int m_unk0420;
	int m_nBeamType;	// 0x424: the type in the low 4 bits
	CBaseHandle m_hStart;	// 0x428: m_hAttachEntity[0] of the SDK's CBaseHandle m_hAttachEntity[10]
	int m_unk042c[(0x450 - 0x42c) / 4];	// m_hAttachEntity[1..9]
	int m_nAttach;	// 0x450: m_nAttachIndex[0] of int m_nAttachIndex[10]
	int m_unk0454[(0x4b8 - 0x454) / 4];
	const Vector &sub_10080650();
};
