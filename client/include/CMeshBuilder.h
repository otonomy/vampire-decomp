#pragma once
#include "Vector.h"
class CMeshBuilder
{
public:
	void sub_10081820(const float *v);
	int m_i0; int m_unk4; int m_unk8; int m_ic; int m_i10; int m_unk14; int m_i18; int m_i1c; int m_i20; int m_i24; int m_unk28;
	void sub_10005230();	// AdvanceVertex (out of line)
	void sub_100052c0(const unsigned char *rgba);	// Color4ubv (out of line)
	void sub_100052f0(const unsigned char *rgb);	// Specular3ubv (out of line)
	void sub_10005330(int stage, float s, float t, float u);	// TexCoord3f (out of line)
	void sub_100421f0(int type, int numPrimitives);	// ComputeNumVertsAndIndices (out of line)
	void sub_100422e0();	// Reset (out of line)
	void sub_10042330(unsigned char r, unsigned char g, unsigned char b);	// Color3ub (out of line)
	void sub_10041b10(void *pMesh, int type, int numVertices);	// Begin
	void sub_10041c90(bool bSpewData, bool bDraw);	// End
	int m_i2c;
	int m_unk30[(0x3c - 0x30) / 4];
	unsigned short m_wIndexOffset;
	short m_unk3e;
	int m_unk40[(0x70 - 0x40) / 4];
	char *m_p70;
	int m_unk74[(0x7c - 0x74) / 4];
	unsigned short *m_pIndices;
	int m_unk80[(0x90 - 0x80) / 4];
	int m_n90;
	int m_nCurrentIndex;
	int m_i98;
	int m_nIndexCount;
	int m_unka0[(0xa8 - 0xa0) / 4];
	int m_a8; int m_ac; int m_b0; int m_b4; int m_b8; int m_bc;
	union { unsigned char *m_pCurrColor; int m_c0; };
	void sub_10049f90(unsigned short idx);
	void sub_10059af0(const float *rgb);
	void sub_100428d0(const float *rgba);
	void sub_1004afc0(float r, float g, float b, float a);	// Color4f
	void sub_100319d0(float x, float y, float z);	// Position3f
	void sub_10031a20(int stage, float s, float t);	// TexCoord2f
	void sub_10042960(int r, int g, int b, int a);	// Color4ub
	void sub_10115c00(float nx, float ny, float nz);	// Normal3f (out of line)
	void sub_100319f0(const float *n);	// Normal3fv (out of line)
	void sub_10041e00(const float *v);	// Position3fv (out of line)
};
