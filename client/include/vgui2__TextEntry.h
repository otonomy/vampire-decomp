// vgui2::TextEntry: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "vgui2__Panel.h"

namespace vgui2
{
class KeyValues;
class TextEntry : public vgui2::Panel
{
public:
	virtual ~TextEntry();
	TextEntry(Panel *parent, const char *name);
	// The game's TextEntry members at 0x58..0x104 (Dar<int> {count, capacity, data} at 0x58 / 0x64 / 0x78 / 0xe0 and
	// Color() at 0xb8 / 0xbc / 0xc0 / 0xc4 / 0xc8 / 0xd5 / 0xf0 / 0x101) are constructed before the vptr store. Panel's
	// header is 0x170 bytes (the game's Panel is 0x58), so this stand-in member constructs them through its own
	// address until Panel shrinks to the game's size and they can be declared here at their offsets.
	struct CMemberInit
	{
		static __forceinline void Dar(char *p) { *(int *)p = 0; *(int *)(p + 4) = 0; *(int *)(p + 8) = 0; }
		static __forceinline void Color(char *p) { p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0; }
		__forceinline CMemberInit()
		{
			char *p = (char *)this - sizeof(vgui2::Panel);
			Dar(p + 0x58); Dar(p + 0x64); Dar(p + 0x78);
			Color(p + 0xb8); Color(p + 0xbc); Color(p + 0xc0); Color(p + 0xc4); Color(p + 0xc8);
			Color(p + 0xd5);
			Dar(p + 0xe0);
			Color(p + 0xf0);
			Color(p + 0x101);
		}
	} m_memberInit;
	void sub_101af9e0(int a);
	bool sub_101aff70(int n);
	int sub_101afbf0();
	void sub_101ae490(int);
	char sub_101ae650(int a, int b);
	void sub_101b0650();
	void sub_101b1790();
	void sub_101afee0();
	void sub_101aff20();
	int sub_101b1c70();
	int sub_101b16e0();
	void sub_101af3d0(int code);	// OnKeyCodeTyped (vtable slot 92)
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with TextEntry's own function
	virtual void vfunc11(int, int);
	virtual void vfunc14();
	bool vfunc14(vgui2::KeyValues *data);
	virtual int vfunc46(int);
	virtual int vfunc74(int);
	virtual void vfunc75(int);
	virtual int vfunc76(int);
	virtual int vfunc77();
	virtual void vfunc79();
	virtual void vfunc80();
	virtual void vfunc81();
	virtual void vfunc84(int, int);
	virtual void vfunc85();
	virtual void vfunc86();
	virtual void vfunc87(int);
	virtual void vfunc88(int);
	virtual void vfunc89(int);
	virtual void vfunc90(int);
	virtual void vfunc92();
	virtual void vfunc93(int);
	virtual void vfunc95();
	virtual void vfunc96();
	virtual void vfunc97();
	virtual void vfunc101();
	virtual int vfunc102();
	// the slots TextEntry adds to its base's vtable: 107-172, vfuncK at slot K
	virtual void vfunc107(const char *);
	virtual void vfunc108(int offset, char *buf, int bufLen);	// GetText
	virtual int vfunc109();
	virtual int vfunc110();
	virtual int vfunc111();
	virtual void vfunc112();
	virtual void vfunc113();
	virtual void vfunc114();
	virtual void vfunc115();
	virtual int vfunc116();
	virtual int vfunc117();
	virtual int vfunc118();
	virtual int vfunc119();
	virtual void vfunc120(char);
	virtual void vfunc121(const char *);
	virtual void vfunc122();
	virtual void vfunc123();
	virtual int vfunc124();
	virtual void vfunc125();
	virtual void vfunc126();
	virtual void vfunc127();
	virtual void vfunc128();
	virtual void vfunc129();
	virtual void vfunc130();
	virtual void vfunc131();
	virtual int vfunc132(int);
	virtual int vfunc133(char);
	virtual bool vfunc134(char);
	virtual bool vfunc135();
	virtual void vfunc136(int line, int pixelsAcross);	// MoveCursor(line, pixelsAcross)
	virtual int vfunc137(int);
	virtual bool vfunc138(char);
	virtual bool vfunc139(char);
	virtual void vfunc140(char);
	virtual bool vfunc141(char);
	virtual bool vfunc142(char);
	virtual int vfunc143(int);
	virtual bool vfunc144(char);
	virtual void vfunc145();
	virtual bool vfunc146(int);
	virtual int vfunc147();
	virtual int vfunc148();
	virtual void vfunc149();
	virtual void vfunc150();
	virtual int vfunc151(int, int);
	virtual void vfunc152();
	virtual int vfunc153(char, int, int, int, int);
	virtual void vfunc154(int, int);
	virtual bool vfunc155(int, int);
	virtual void vfunc156(char, int);
	virtual int vfunc157();
	virtual bool vfunc158(int, int);
	virtual void vfunc159(int, int *, int *);
	virtual int vfunc160(int, int);
	virtual void vfunc161(int *, int *);
	virtual int vfunc162();
	virtual void vfunc163();
	virtual bool vfunc164(int, int, int, int);
	virtual void vfunc165();
	virtual void vfunc166(int);
	virtual void vfunc167();
	virtual int vfunc168();
	virtual int vfunc169();
	virtual void vfunc170(int);
	virtual int vfunc171(void *, int, int, int);
	virtual int vfunc172(int *);
	int sub_101ab130();
	void sub_101b18c0();
	void sub_101b1650(int);
	void sub_101a9920(int *, int *);
	void sub_101a98f0(int, int);
	void sub_101b16f0();
};
}
