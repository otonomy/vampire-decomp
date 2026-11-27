// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101b57a0 size=0x3b
#include "vgui2__KeyValues.h"
#include <stdlib.h>
int sub_101b6860(int);
vgui2::KeyValues::~KeyValues()
{
	vgui2::KeyValues *p = m_pSub;
	if (p) {
		do {
			vgui2::KeyValues *next = p->m_pPeer;
			p->~KeyValues();
			sub_101b6860((int)p);
			p = next;
		} while (p);
	}
	free(m_pName);
}
// END FUNCTION

// FUNCTION: 0x101b57e0 size=0x15
#include "vgui2__KeyValues.h"
namespace lifted {
int sub_101ac930();
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(int); };
}
int vgui2::KeyValues::vfunc0()
{
    return ((lifted::V *)(lifted::sub_101ac930()))->f4(*(int *)((char *)this + 4));
}
// END FUNCTION

// FUNCTION: 0x101b5800 size=0x4
#include "vgui2__KeyValues.h"
int vgui2::KeyValues::vfunc1()
{
    return *(int *)((char *)this + 4);
}
// END FUNCTION

// FUNCTION: 0x101b5810 size=0xda
#include "vgui2__KeyValues.h"
#include "engineclient.h"
struct KVSymTab { virtual void s0(); virtual void s1(); virtual void s2(); virtual int Find(const char *); };
KVSymTab *sub_101ac930();
char *sub_101b58f0(char **, int *);
// TARGET: vgui2::KeyValues::vfunc2
bool vgui2::KeyValues::vfunc2(void *pfs, const char *filename, const char *pathID)
{
    EngineGlobals::IFileSystem *fs = (EngineGlobals::IFileSystem *)pfs;
    int f = fs->Open(filename, "rb", pathID);
    if (!f)
        return false;
    int size = fs->vfunc6(f);
    char *buf = new char[size];
    char *p = buf;
    fs->vfunc2(buf, size, f);
    char *tok = sub_101b58f0(&p, &size);
    if (tok)
        m_unk4 = sub_101ac930()->Find(tok);
    tok = sub_101b58f0(&p, &size);
    if (m_unk4 > -1 && tok && *tok == '{')
        sub_101b5ac0((char *)&p, (int)&size);
    fs->Close(f);
    delete[] buf;
    return true;
}
// END FUNCTION

// FUNCTION: 0x101b6280 size=0xf5
#include <string.h>
#include "vgui2__KeyValues.h"

struct KVSystemView
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(const char *);
};

KVSystemView *sub_101ac930();

vgui2::KeyValues *vgui2::KeyValues::vfunc4(const char *keyName, bool bCreate)
{
    if ( !keyName || !keyName[0] )
        return this;

    char szBuf[256];
    const char *pName = keyName;
    char *pSlash = (char *)strchr(keyName, '/');
    if ( pSlash )
    {
        int len = pSlash - keyName;
        memcpy(szBuf, keyName, len);
        szBuf[len] = 0;
        pName = szBuf;
    }

    int keySymbol = sub_101ac930()->v3(pName);

    KeyValues *p = m_pSub;
    KeyValues *pPrev = NULL;
    while ( p )
    {
        pPrev = p;
        if ( p->m_unk4 == keySymbol )
            break;
        p = p->m_pPeer;
    }

    if ( !p )
    {
        if ( bCreate )
        {
            p = new KeyValues(pName);
            if ( pPrev )
                pPrev->m_pPeer = p;
            else
                m_pSub = p;
            p->m_pPeer = NULL;
            m_unk10 = 0;
        }
        else
        {
            return NULL;
        }
    }

    if ( pSlash )
        return p->vfunc4(pSlash + 1, bCreate);

    return p;
}
// END FUNCTION

// FUNCTION: 0x101b6380 size=0x56
#include "vgui2__KeyValues.h"

extern "C" int atoi(const char *s);
extern "C" char *_itoa(int value, char *string, int radix);

void vgui2::KeyValues::vfunc5()
{
	int max = 1;
	for (KeyValues *sub = m_pSub; sub; sub = sub->m_pPeer)
	{
		int n = atoi((const char *)sub->vfunc0());
		if (max <= n)
			max = n + 1;
	}
	char buf[12];
	_itoa(max, buf, 10);
	vfunc4(buf, 1);
}
// END FUNCTION

// FUNCTION: 0x101b63e0 size=0x4b
#include "vgui2__KeyValues.h"
void vgui2::KeyValues::vfunc6(KeyValues *sub)
{
	if (!sub)
		return;
	if (m_pSub == sub) {
		m_pSub = sub->m_pPeer;
		sub->m_pPeer = 0;
		return;
	}
	KeyValues *p = m_pSub;
	while (p->m_pPeer) {
		if (p->m_pPeer == sub) {
			p->m_pPeer = sub->m_pPeer;
			break;
		}
		p = p->m_pPeer;
	}
	sub->m_pPeer = 0;
}
// END FUNCTION

// FUNCTION: 0x101b6430 size=0x4
#include "vgui2__KeyValues.h"
int vgui2::KeyValues::vfunc7()
{
    return *(int *)((char *)this + 0x18);
}
// END FUNCTION

// FUNCTION: 0x101b6440 size=0x4
#include "vgui2__KeyValues.h"
int vgui2::KeyValues::vfunc8()
{
    return *(int *)((char *)this + 0x14);
}
// END FUNCTION

// FUNCTION: 0x101b6450 size=0x42
#include "vgui2__KeyValues.h"
extern "C" int __cdecl atoi(const char *);
int vgui2::KeyValues::vfunc9(const char *keyName, int defaultValue)
{
	KeyValues *dat = vfunc4(keyName, 0);
	if (dat)
	{
		switch (dat->m_unk10)
		{
		case 1:
			return atoi((const char *)dat->m_pName);
		case 3:
			return (int)dat->m_flValue;
		default:
			return dat->m_unkc;
		}
	}
	return defaultValue;
}
// END FUNCTION

// FUNCTION: 0x101b64a0 size=0x28
#include "vgui2__KeyValues.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(int, int); };
}
int vgui2::KeyValues::vfunc12(int a0, int a1)
{
    int t0 = ((lifted::V *)this)->f4(a0, 0);
    if (t0 != 0) {
        if ((*(int *)((char *)t0 + 0x10)) != 4) {
            return 0;
        }
        return *(int *)((char *)t0 + 0xc);
    }
    return a1;
}
// END FUNCTION

// FUNCTION: 0x101b64d0 size=0x47
#include "vgui2__KeyValues.h"
extern "C" double atof(const char *);
// TARGET: vgui2::KeyValues::vfunc10
float vgui2::KeyValues::vfunc10(const char *keyName, float defaultValue)
{
    KeyValues *dat = vfunc4(keyName, 0);
    if (dat) {
        switch (dat->m_unk10) {
        case 1:
            return (float)atof((const char *)dat->m_pName);
        case 2:
            return (float)dat->m_unkc;
        case 3:
            return dat->m_flValue;
        default:
            return 0.0f;
        }
    }
    return defaultValue;
}
// END FUNCTION

// FUNCTION: 0x101b6520 size=0xac
#include <stdio.h>
#include "vgui2__KeyValues.h"
using namespace vgui2;
const char *KeyValues::vfunc11(const char *keyName, const char *defaultValue)
{
    KeyValues *dat = vfunc4(keyName, 0);
    if (dat) {
        char buf[64];
        switch (dat->m_unk10) {
        case 3:
            sprintf(buf, "%f", dat->m_flValue);
            vfunc14(keyName, buf);
            break;
        case 2:
        case 4:
            sprintf(buf, "%d", dat->m_unkc);
            vfunc14(keyName, buf);
            break;
        case 1:
            break;
        default:
            return defaultValue;
        }
        return (const char *)dat->m_pName;
    }
    return defaultValue;
}
// END FUNCTION

// FUNCTION: 0x101b6640 size=0x21
#include "vgui2__KeyValues.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(int, int); };
}
int vgui2::KeyValues::vfunc15(int a0, int a1)
{
    int t0 = ((lifted::V *)this)->f4(a0, 1);
    if (t0 != 0) {
        *(int *)((char *)t0 + 0x10) = 2;
        *(int *)((char *)t0 + 0xc) = a1;
    }
    return t0;
}
// END FUNCTION

// FUNCTION: 0x101b6670 size=0x21
#include "vgui2__KeyValues.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(int, int); };
}
int vgui2::KeyValues::vfunc16(int a0, int a1)
{
    int t0 = ((lifted::V *)this)->f4(a0, 1);
    if (t0 != 0) {
        *(int *)((char *)t0 + 0x10) = 3;
        *(int *)((char *)t0 + 0xc) = a1;
    }
    return t0;
}
// END FUNCTION

// FUNCTION: 0x101b66a0 size=0x21
#include "vgui2__KeyValues.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(int, int); };
}
int vgui2::KeyValues::vfunc17(int a0, int a1)
{
    int t0 = ((lifted::V *)this)->f4(a0, 1);
    if (t0 != 0) {
        *(int *)((char *)t0 + 0x10) = 4;
        *(int *)((char *)t0 + 0xc) = a1;
    }
    return t0;
}
// END FUNCTION

// FUNCTION: 0x101b66d0 size=0xd0
#include "vgui2__KeyValues.h"
#include <string.h>
#include <stdlib.h>

namespace vgui2
{

KeyValues *KeyValues::vfunc18()
{
	KeyValues *dat = new KeyValues((const char *)vfunc0());
	dat->m_unk10 = m_unk10;
	switch (m_unk10)
	{
	case 1:
		if (m_pName)
		{
			int len = strlen((char *)m_pName);
			dat->m_pName = malloc(len + 1);
			memcpy(dat->m_pName, m_pName, len + 1);
		}
		break;
	case 2:
		dat->m_unkc = m_unkc;
		break;
	case 3:
		dat->m_flValue = m_flValue;
		break;
	case 4:
		dat->m_unkc = m_unkc;
		break;
	}
	KeyValues *prev = 0;
	for (KeyValues *p = m_pSub; p != 0; p = p->m_pPeer)
	{
		KeyValues *c = p->vfunc18();
		if (prev)
			prev->m_pPeer = c;
		else
			dat->m_pSub = c;
		c->m_pPeer = 0;
		prev = c;
	}
	return dat;
}

}
// END FUNCTION

// FUNCTION: 0x101b67a0 size=0x2d
#include "vgui2__KeyValues.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(int, int); };
}
bool vgui2::KeyValues::vfunc13(int a0)
{
    int t0 = ((lifted::V *)this)->f4(a0, 0);
    if (t0 == 0) {
        return 1;
    }
    if ((*(int *)((char *)t0 + 0x10)) == 0) {
        if ((*(int *)((char *)t0 + 0x18)) == 0) {
            return 1;
        }
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x101b67d0 size=0x28
#include "vgui2__KeyValues.h"
namespace lifted {
struct C101b57a0 { int sub_101b57a0(); };
int sub_101b6860(int);
}
void vgui2::KeyValues::vfunc19()
{
    int t0 = *(int *)((char *)this + 0x18);
    if (t0 != 0) {
        ((lifted::C101b57a0 *)t0)->sub_101b57a0();
        lifted::sub_101b6860(t0);
    }
    *(int *)((char *)this + 0x18) = 0;
    *(int *)((char *)this + 0x10) = 0;
}
// END FUNCTION

// FUNCTION: 0x101b6800 size=0x1b
#include "vgui2__KeyValues.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual int f4(int, int); };
}
int vgui2::KeyValues::vfunc20(int a0)
{
    int t0 = ((lifted::V *)this)->f4(a0, 0);
    if (t0 != 0) {
        return *(int *)((char *)t0 + 0x10);
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x101b6820 size=0x17
#include "vgui2__KeyValues.h"
namespace lifted {
int sub_101b57a0();
int sub_101b6860(int);
}
void vgui2::KeyValues::vfunc21()
{
    if (((int)this) != 0) {
        lifted::sub_101b57a0();
        lifted::sub_101b6860((int)this);
    }
}
// END FUNCTION
