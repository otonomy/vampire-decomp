// C_BaseTerminal: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseAnimating.h"

class C_BaseTerminal : public C_BaseAnimating
{
public:
	C_BaseTerminal();
	virtual ~C_BaseTerminal();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_BaseTerminal's own function
	virtual int vfunc15();
	virtual int vfunc16();
	virtual bool vfunc25(int);
	virtual void vfunc29(char);
	char m_pad0014[0x790 - 0x14];
	void *m_pMem;
	int m_alloc;
	int m_grow;
	int m_size;
	void *m_pElements;
	void *m_pTexture;
	bool m_b7a8;
	char m_pad07a9[0x7ac - 0x7a9];
	int m_nStride;
	int m_nMax;
	unsigned char m_rgData[0x6c0];
	unsigned char m_bE74;
	char m_pad0e75[0x78 - 0x75];
	int m_nE78;
	int m_nE7c;
	int m_nE80;
	int m_nE84;
	bool m_bE88;
	char m_pad0e89[3];
	int m_nE8c;
	int m_aE90[0x12];
	union { bool m_bEd8; char m_szText[0x2c]; };	// 0xed8: the line being typed
	bool m_bF04;	// 0xf04: accepts typing
	char m_pad0f05[0xf0c - 0xf05];
	bool m_bF0c;	// 0xf0c: armed for the "hackcmd break" key ('c')
	bool m_bF0d;	// 0xf0d: cursor keys move the cursor
	char m_cF0e;
	char m_cF0f;
	unsigned int m_nF10;	// 0xf10: input flags (1 = command mode, 2 = digits only, 8 = key sound)
	int m_nF14;	// 0xf14: maximum text length (0 = none)
	int m_nF18;	// 0xf18: the key sound (engine slot 8 turns it into a name)
	int m_nF1c;
	void sub_100c6d50(int key);	// a typed character
	void sub_100c8060(int c);
	void sub_100c7fb0(const char *str);
	void sub_100c75b0();
	void sub_100c7ec0(int dx, int dy);
	void sub_100c7f50();
	void sub_100c7550();
	void sub_100c82e0();
	void *sub_100c7720();
	void sub_100c8210(int n);
	void sub_100c77f0(class ITexture *pTexture, class IVTFTexture *pVTFTexture, struct Rect_t *pRect);	// ITextureRegenerator::RegenerateTextureBits-like: draws the text grid (m_rgData) into a 512x512 texture with a CPixelWriter
};
