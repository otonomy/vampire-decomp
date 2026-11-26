// Pixel formats of the SDK's public/bitmap/imageformat.h (the ones client.dll's DXT decoders use).
#pragma once

struct BGRA8888_t
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

struct BGR888_t
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
};

struct RGB888_t
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	// out of line at 0x100f86a0 where the inline budget ran out (DXT decoders)
	inline RGB888_t &operator=(const BGRA8888_t &in)
	{
		r = in.r;
		g = in.g;
		b = in.b;
		return *this;
	}
};
