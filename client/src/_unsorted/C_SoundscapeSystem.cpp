// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100c0a30 size=0x1
#include "C_SoundscapeSystem.h"
void C_SoundscapeSystem::vfunc9()
{
}
// END FUNCTION

// FUNCTION: 0x100c0a40 size=0x1
#include "C_SoundscapeSystem.h"
void C_SoundscapeSystem::vfunc2()
{
}
// END FUNCTION

// FUNCTION: 0x100c0a50 size=0x1
#include "C_SoundscapeSystem.h"
void C_SoundscapeSystem::vfunc3()
{
}
// END FUNCTION

// FUNCTION: 0x100c0a60 size=0x1
#include "C_SoundscapeSystem.h"
void C_SoundscapeSystem::vfunc4()
{
}
// END FUNCTION

// FUNCTION: 0x100c0a70 size=0x1
#include "C_SoundscapeSystem.h"
void C_SoundscapeSystem::vfunc5()
{
}
// END FUNCTION

// FUNCTION: 0x100c0a80 size=0x1
#include "C_SoundscapeSystem.h"
void C_SoundscapeSystem::vfunc6()
{
}
// END FUNCTION

// FUNCTION: 0x100c0a90 size=0xd5
#include "C_SoundscapeSystem.h"
#include "UtlMem.h"

extern void (*g_101e30fc)(void *);
extern void *vt_10232478[];

// TARGET: C_SoundscapeSystem::sub_100c0a90
void *C_SoundscapeSystem::sub_100c0a90(unsigned int flags)
{
	*(void ***)this = vt_10232478;

	int *v = (int *)((char *)this + 0x6c);
	v[3] = 0;
	((UtlMem *)v)->sub_100c1eb0();
	int g1 = v[2];
	int p1 = v[0];
	void (*pFree)(void *) = g_101e30fc;
	v[4] = p1;
	if (g1 != -1)
	{
		if (p1)
		{
			pFree((void *)p1);
			v[0] = 0;
		}
		v[1] = 0;
	}

	int g2 = *(int *)((char *)this + 0x60);
	*(int *)((char *)this + 0x64) = 0;
	if (g2 != -1)
	{
		int p2 = *(int *)((char *)this + 0x58);
		if (p2)
		{
			pFree((void *)p2);
			*(int *)((char *)this + 0x58) = 0;
		}
		*(int *)((char *)this + 0x5c) = 0;
	}
	int g3 = *(int *)((char *)this + 0x60);
	int p3 = *(int *)((char *)this + 0x58);
	*(int *)((char *)this + 0x68) = p3;
	if (g3 != -1)
	{
		if (p3)
		{
			pFree((void *)p3);
			*(int *)((char *)this + 0x58) = 0;
		}
		*(int *)((char *)this + 0x5c) = 0;
	}

	int g4 = *(int *)((char *)this + 0x10);
	*(int *)((char *)this + 0x14) = 0;
	if (g4 != -1)
	{
		int p4 = *(int *)((char *)this + 8);
		if (p4)
		{
			pFree((void *)p4);
			*(int *)((char *)this + 8) = 0;
		}
		*(int *)((char *)this + 0xc) = 0;
	}
	int g5 = *(int *)((char *)this + 0x10);
	int p5 = *(int *)((char *)this + 8);
	*(int *)((char *)this + 0x18) = p5;
	if (g5 != -1)
	{
		if (p5)
		{
			pFree((void *)p5);
			*(int *)((char *)this + 8) = 0;
		}
		*(int *)((char *)this + 0xc) = 0;
	}

	IGameSystem::~IGameSystem();
	if (flags & 1)
		operator delete(this);
	return this;
}
// END FUNCTION

// FUNCTION: 0x100c1030 size=0x2c
#include "engineclient.h"
#include "C_SoundscapeSystem.h"
void C_SoundscapeSystem::vfunc7(int a)
{
    sub_100c0f30(a);
    sub_100c1dd0((float)engine->Time(0));
}
// END FUNCTION
