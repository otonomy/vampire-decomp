// BitmapImage: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
#pragma once
#include "vgui2__Image.h"

class BitmapImage : public vgui2::Image
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with BitmapImage's own function
    virtual int vfunc0();
    virtual int vfunc1(int, int);
    virtual int vfunc2(int, int);
    virtual int vfunc8(int);

	BitmapImage();
	BitmapImage(const char *pSzFilename, int nArg);
	int m_hTexture;	// +0x1c
	vgui2::Image::ImageColor m_clr;	// +0x20
	int m_unk24;
	int m_unk28;
	int m_unk2c;
	int m_unk30;
	int m_unk34;
	bool m_b38;
	int m_unk3c;
	int m_unk40;
	int m_unk44;
	int m_unk48;
	void sub_101646d0(int x, int y, int wide, int tall, float yaw, float flAlphaModulate);

	bool sub_10164520(int arg0, int arg1);
	bool sub_10164600(int, struct IKV11 *);
	void sub_10164980(Color4b *);
	bool sub_10164570(int arg0, class CKeyValuesX *pKV);
};
