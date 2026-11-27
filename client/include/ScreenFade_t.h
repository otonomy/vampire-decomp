// ScreenFade_t: one running screen fade of CViewEffects (the fade list at CViewEffects + 4 holds pointers to these).
// 0x14 bytes: Speed (alpha per second), End, Reset (both in seconds), the colour and the fade flags.
#pragma once

struct ScreenFade_t
{
	float Speed;
	float End;
	float Reset;
	unsigned char r, g, b, a;
	int Flags;
};

// the screenfade user message as CViewEffects::vfunc4 reads it: 12 bit fixed point seconds
struct ScreenFadeMsg_t
{
	unsigned short duration;
	unsigned short holdTime;
	short fadeFlags;
	unsigned char r, g, b, a;
};
