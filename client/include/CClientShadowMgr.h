// CClientShadowMgr (RTTI .?AVCClientShadowMgr@@): cl_dll/clientshadowmgr.cpp. Only what matched code reads.
#pragma once
#include "CUtlLinkedList240.h"

struct ClientShadow_t
{
	int m_unk00;
	int m_unk04;
	unsigned short m_Flags;	// 0x08, bit 0 tested
	unsigned short m_unk0a;
	int m_unk0c;
};

class Vector;

class CClientShadowMgr
{
public:
	int m_unk00;	// vtable stand-in
	int m_unk04;	// IClientLeafShadowEnum vtable
	int m_unk08;
	int m_unk0c;
	int m_unk10;
	int m_unk14;
	int m_unk18;
	int m_unk1c;
	int m_unk20;
	int m_unk24;
	int m_unk28;
	CUtlLinkedList240 m_Shadows;	// 0x2c
	void sub_100d6540(int index, const Vector *v, float f);
	void sub_100d6390(class VMatrix &worldToShadow, const Vector &origin, const Vector &dir, const Vector &xvec, const Vector &yvec);
	float sub_100d6430(class IClientEntity *pEnt, const Vector &mins, const Vector &maxs, const Vector &localShadowDir, float backupFactor, Vector &origin);
	void sub_100d65a0(class IClientEntity *pEnt, unsigned short handle, const Vector *vec, const Vector &mins, const Vector &maxs, const Vector &localShadowDir);

	void sub_100d66d0(int a0, unsigned short h);	// BuildOrthoShadow-like: a blob box (-18,-18,0)..(18,18,+0xa4) around the shadow direction (+8)
	void sub_100d6320(class VMatrix &worldToShadow, const Vector &origin, const Vector &dir, const Vector &xvec, const Vector &yvec);	// BuildGeneralWorldToShadowMatrix
	void sub_100d5bd0(unsigned short h);
	void sub_100d5ca0(unsigned short h);
	void sub_100d6ca0(int a0, unsigned short h, int *a2, int *a3);
	void sub_100d7130(int a0, unsigned short h, int *a2);
	void sub_100d7180(int a0, unsigned short h, int *a2);	// provisional, like sub_100d7130 (transplant)
public:
	void vfunc1();
	void vfunc5();
	unsigned short vfunc9(class CBaseHandle entity, int flags);
	void vfunc3();
	void vfunc4();
	void vfunc6();
	void vfunc7(int);
	void *vfunc16(unsigned short);
	void vfunc14(const void *pDirection);
	void vfunc15(int, int, int);
	void vfunc13(int w, int h);	// "RenderShadowTexture": the shadow render target as a quad of w x h
};
