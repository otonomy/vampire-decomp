// C_BreakableSurface: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseEntity.h"
#include "IBrushRenderer.h"
#include "Vector.h"

class C_BreakableSurface : public C_BaseEntity, public IBrushRenderer
{
public:
	C_BreakableSurface();
	virtual ~C_BreakableSurface();
	int sub_100b7b40(int flags, int a1);
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_BreakableSurface's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual bool vfunc79();
	virtual bool IsTransparent();
	virtual void ReceiveMessage(int classID, bf_read &msg);
	char m_pad0018[0x414 - 0x18];
	int m_nWidth;
	int m_nHeight;
	char m_pad041c[0x424 - 0x41c];
	Vector m_vNormal;	// 0x424
	char m_pad0430[0x43c - 0x430];
	bool sub_100b7450(int x, int y);
	int sub_100b8460(int x, int y);
	void sub_100b7490(int x, int y, bool bSet);
	void sub_100b74f0();
	void sub_100b75c0(int i, int j, const char *pName);
	bool m_bUnk438;
	char m_pad043d[0x448 - 0x43d];
	void *m_pArray;
	int m_unk44c;
	int m_unk450;
	unsigned short m_n454;
	unsigned short m_n456;
	unsigned short m_n458;
	unsigned short m_n45a;
	unsigned short m_n45c;
	unsigned short m_n45e;
	int sub_100b83f0(int a0, int a1, int a2);
	int m_n460;
	int m_nPanelFlags[1];
	char m_pad0468[0x940 - 0x468];
	bool sub_100b80f0(int x, int y);
	void sub_100b8130(int nWidth, int nHeight);	// UpdateEdgeType: the eight neighbours' solidity picks each edge's style
	void sub_100b84c0(int nWidth, int nHeight, int nEdge, int nStyle);	// SetupEdge-like
	void sub_100b8a00(class IBrushSurface *pBrushSurface, struct IMesh *pMesh, class CMeshBuilder *pMeshBuilder, const Vector &vCurPos, const Vector &vWidthStep, const Vector &vHeightStep);	// DrawOneBlock
	void sub_100b8f30(class IBrushSurface *pBrushSurface, struct IMesh *pMesh, class CMeshBuilder *pMeshBuilder, const Vector &vCurPos, const Vector &vEdgeStep, const Vector &vEdgeExtStep, int nEdgeType);	// DrawOneEdge
};
