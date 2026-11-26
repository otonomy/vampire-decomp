// vgui2::TextImage: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 5 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Image.h"

namespace vgui2
{
class TextImage : public vgui2::Image
{
public:
	TextImage(const char *text, unsigned long scheme);
	virtual ~TextImage();
	void sub_101ba270(unsigned short *buf, int n);
	char *m_pText;
	short m_unk20;
	short m_unk22;
	int m_font;
	int m_unk28;
	int m_unk2c;
	bool m_unk30;
	ImageColor m_unk31;
	bool m_unk35;
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with TextImage's own function
	virtual int vfunc0();
	virtual int vfunc9(int, int);
	// the slots TextImage adds to its base's vtable: 26-34, vfuncK at slot K
	virtual void vfunc26(const unsigned short *);
	virtual void vfunc27(const char *);
	virtual int vfunc28(int, int);
	virtual void vfunc29(char *buf, int size);
	virtual void vfunc30(int);
	virtual int vfunc31();
	virtual int vfunc32(int, int);
	virtual void vfunc33(int *, int *, int);
	virtual void vfunc34();
};
}
