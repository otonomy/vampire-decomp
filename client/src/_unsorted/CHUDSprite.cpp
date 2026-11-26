// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10059250 size=0xd1
#include "engineclient.h"
#include "CHUDSprite.h"
#include "ScopeTrace.h"


struct MatV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(int);
};


CHUDSprite::CHUDSprite(const char *pMaterial, int a1, int a2, int a3, int a4, int a5, int a6)
{
	ScopeTrace trace("CHUDSprite::CHUDSprite", g_102de300);
	m_unk08 = a1;
	m_unk0c = a2;
	m_unk10 = a3;
	m_unk14 = a4;
	bool b;
	m_unk04 = (int)materials->FindMaterial(pMaterial, &b, 1);
	((MatV *)m_unk04)->v12(0);
	if (b)
	{
		m_unk18 = -1;
		m_unk1c = -1;
	}
	else
	{
		m_unk04 = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x10059330 size=0x1e
#include "CHUDSprite.h"

// VC6 writes CHUDSprite's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CHUDSprite *pcd_emit_10059330(const CHUDSprite &other) { return new CHUDSprite(other); }

// TARGET: ??_GCHUDSprite@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10059350 size=0x87
#include "engineclient.h"
#include "CHUDSprite.h"
#include "ScopeTrace.h"
struct HudObj59350
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12();
	virtual void v13(int a);
};
// TARGET: CHUDSprite::~CHUDSprite
CHUDSprite::~CHUDSprite()
{
	ScopeTrace trace("CHUDSprite::~CHUDSprite", g_102de300, g_102de300);
	if (m_unk04)
	{
		((HudObj59350 *)m_unk04)->v13(0);
		materials->vfunc40((void *)m_unk04);
		m_unk04 = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x1005d7d0 size=0x74
#include "CHUDSprite.h"
#include "ScopeTrace.h"

void CHUDSprite::getSize(int *wide, int *tall)
{
    ScopeTrace trace("CHUDSprite::getSize", "", "");
    if (wide)
        *wide = m_unk10;
    if (tall)
        *tall = m_unk14;
}
// END FUNCTION

// FUNCTION: 0x100f3690 size=0x18
#include "IHudSprite.h"
int CHudSprite::vfunc17(int a0)
{
    int t0 = *(int *)((char *)a0);
    *(int *)((char *)this + 0x24) = t0;
    int t1 = *(int *)((char *)a0 + 4);
    *(int *)((char *)this + 0x28) = t1;
    int t2 = *(int *)((char *)a0 + 8);
    *(int *)((char *)this + 0x2c) = t2;
    return t2;
}
// END FUNCTION

// FUNCTION: 0x100f3840 size=0xf0
#include "IHudSprite.h"

extern void *g_104a57d4;
extern void *g_104a57f8;
extern void (*g_101e3120)(int, const char *, const char *);

extern "C" unsigned int strlen(const char *);
#pragma intrinsic(strlen)
extern "C" char *strcpy(char *, const char *);
#pragma intrinsic(strcpy)
extern "C" int _strcmpi(const char *, const char *);

struct CEngineView
{
    virtual void v0() = 0;  virtual void v1() = 0;  virtual void v2() = 0;  virtual void v3() = 0;
    virtual void v4() = 0;  virtual void v5() = 0;  virtual void v6() = 0;  virtual void v7() = 0;
    virtual void v8() = 0;  virtual void v9() = 0;  virtual void v10() = 0; virtual void v11() = 0;
    virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0; virtual void v15() = 0;
    virtual void v16() = 0; virtual void v17() = 0; virtual void v18() = 0; virtual void v19() = 0;
    virtual void v20() = 0; virtual void v21() = 0; virtual void v22() = 0; virtual void v23() = 0;
    virtual void v24() = 0; virtual void v25() = 0; virtual void v26() = 0; virtual void v27() = 0;
    virtual void v28() = 0; virtual void v29() = 0; virtual void v30() = 0; virtual void v31() = 0;
    virtual void v32() = 0; virtual void v33() = 0; virtual void v34() = 0; virtual void v35() = 0;
    virtual int v36(const char *) = 0;
};

struct CModelInfoView
{
    virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
    virtual void v3() = 0; virtual void v4() = 0; virtual int v5(int) = 0;
};

struct HudSpriteEntry
{
    int m_hSprite;
    char *m_pszName;
    int m_pTexture;
};

// TARGET: CHudSprite::vfunc2
int CHudSprite::vfunc2(const char *pszName)
{
    if (!pszName)
        return 0;
    if (m_unk30 == 0)
        return 0;
    if (m_unk34 <= 0)
        return 0;

    for (int i = 0; i < m_unk34; i++)
    {
        if (((HudSpriteEntry *)m_unk30)[i].m_hSprite == 0)
        {
            ((HudSpriteEntry *)m_unk30)[i].m_pszName = new char[strlen(pszName) + 1];
            strcpy(((HudSpriteEntry *)m_unk30)[i].m_pszName, pszName);
        }
        if (_strcmpi(pszName, ((HudSpriteEntry *)m_unk30)[i].m_pszName) == 0)
        {
            ((HudSpriteEntry *)m_unk30)[i].m_hSprite = ((CEngineView *)g_104a57d4)->v36(pszName);
            if (((HudSpriteEntry *)m_unk30)[i].m_hSprite == 0)
            {
                g_101e3120(1, "Can't load sprite %s\n", pszName);
                return 0;
            }
            ((HudSpriteEntry *)m_unk30)[i].m_pTexture = ((CModelInfoView *)g_104a57f8)->v5(((HudSpriteEntry *)m_unk30)[i].m_hSprite);
            return i + 1;
        }
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100f3950 size=0x26
#include "IHudSprite.h"
struct V3d50 { El3d50 *sub_100f3d50(int); };
// TARGET: ?vfunc4@CHudSprite@@UAEHHH@Z
int CHudSprite::vfunc4(int a, int b)
{
	El3d50 *e = ((V3d50 *)this)->sub_100f3d50(a);
	if (e)
		return sub_100f3e20(e)[1];
	return 0;
}
// END FUNCTION

// FUNCTION: 0x100f3980 size=0x25
#include "IHudSprite.h"
struct El3d50;
struct V3d50 { El3d50 *sub_100f3d50(int); };
int CHudSprite::vfunc5(int a, int b)
{
	El3d50 *e = ((V3d50 *)this)->sub_100f3d50(a);
	if (e)
		return *sub_100f3e20(e);
	return 0;
}
// END FUNCTION

// FUNCTION: 0x100f39b0 size=0x57
#include "IHudSprite.h"

struct V3d50View100f39b0
{
	El3d50 *sub_100f3d50(int a);
};

// TARGET: CHudSprite::vfunc6
void CHudSprite::vfunc6(int a1, int r, int g, int b)
{
	El3d50 *v = ((V3d50View100f39b0 *)this)->sub_100f3d50(a1);
	if (!v)
		return;
	m_pSprite = (CHudSpriteInner *)sub_100f3e20(v);
	if (!m_pSprite)
		return;
	m_pSprite->sub_10136f20(r * 0.00392156862745098,
		g * 0.00392156862745098, b * 0.00392156862745098);
}
// END FUNCTION

// FUNCTION: 0x100f3a60 size=0x54
#include "IHudSprite.h"

extern int sub_100cd100();
extern int sub_100cd0f0();

// TARGET: CHudSprite::vfunc7
void CHudSprite::vfunc7(int a1, int x, int y, int a4, int a5, int a6)
{
	if (!m_pSprite)
		return;
	if (x >= sub_100cd100())
		return;
	if (y >= sub_100cd0f0())
		return;
	m_pSprite->sub_10136f60(false);
	m_pSprite->sub_10137020(a1, x, y, a4, a5, a6);
}
// END FUNCTION

// FUNCTION: 0x100f3ac0 size=0x54
#include "IHudSprite.h"

extern int sub_100cd100();
extern int sub_100cd0f0();

// TARGET: CHudSprite::vfunc9
void CHudSprite::vfunc9(int a1, int x, int y, int a4, int a5, int a6)
{
	if (!m_pSprite)
		return;
	if (x >= sub_100cd100())
		return;
	if (y >= sub_100cd0f0())
		return;
	m_pSprite->sub_10136f60(false);
	m_pSprite->sub_10137850(a1, x, y, a4, a5, a6);
}
// END FUNCTION

// FUNCTION: 0x100f3b70 size=0x54
#include "IHudSprite.h"

extern int sub_100cd100();
extern int sub_100cd0f0();

// TARGET: CHudSprite::vfunc10
void CHudSprite::vfunc10(int a1, int x, int y, int a4, int a5, int a6)
{
	if (!m_pSprite)
		return;
	if (x >= sub_100cd100())
		return;
	if (y >= sub_100cd0f0())
		return;
	m_pSprite->sub_10136f60(false);
	m_pSprite->sub_10137020(a1, x, y, a4, a5, a6);
}
// END FUNCTION

// FUNCTION: 0x100f3bd0 size=0x4a
#include "IHudSprite.h"

extern int sub_100cd100();
extern int sub_100cd0f0();

// TARGET: CHudSprite::vfunc13
void CHudSprite::vfunc13(int frame, int x, int y, int a3)
{
	if (!m_pSprite)
		return;
	if (x >= sub_100cd100())
		return;
	if (y >= sub_100cd0f0())
		return;
	m_pSprite->sub_10136f60(true);
	m_pSprite->sub_10136ff0(frame, x, y, a3);
}
// END FUNCTION

// FUNCTION: 0x100f3c20 size=0x54
#include "IHudSprite.h"

extern int sub_100cd100();
extern int sub_100cd0f0();

// TARGET: CHudSprite::vfunc12
void CHudSprite::vfunc12(int a1, int x, int y, int a4, int a5, int a6)
{
	if (!m_pSprite)
		return;
	if (x >= sub_100cd100())
		return;
	if (y >= sub_100cd0f0())
		return;
	m_pSprite->sub_10136f60(true);
	m_pSprite->sub_10137020(a1, x, y, a4, a5, a6);
}
// END FUNCTION

// FUNCTION: 0x100f3c80 size=0x54
#include "IHudSprite.h"

extern int sub_100cd100();
extern int sub_100cd0f0();

// TARGET: CHudSprite::vfunc14
void CHudSprite::vfunc14(int a1, int x, int y, int a4, int a5, int a6)
{
	if (!m_pSprite)
		return;
	if (x >= sub_100cd100())
		return;
	if (y >= sub_100cd0f0())
		return;
	m_pSprite->sub_10136f60(true);
	m_pSprite->sub_10137850(a1, x, y, a4, a5, a6);
}
// END FUNCTION

// FUNCTION: 0x100f3d10 size=0x3d
#include "IHudSprite.h"
struct SpriteRect4
{
	int l, t, r, b;
};
void CHudSprite::vfunc18(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
	m_unk04 = a1;
	*(SpriteRect4 *)&m_unk08 = *(SpriteRect4 *)&a2;
	m_unk18 = a6;
	m_unk1c = a7;
	m_unk20 = a8;
}
// END FUNCTION

// FUNCTION: 0x100f3d70 size=0x3a
#include "IHudSprite.h"
extern "C" void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
void *__cdecl operator new(unsigned int);
// TARGET: CHudSprite::vfunc0
void CHudSprite::vfunc0()
{
    if (!m_unk30) {
        m_unk04 = 0;
        m_unk34 = 0x80;
        m_unk30 = (int)operator new(0x4800);
        memset((void *)m_unk30, 0, 0x600);
        m_pSprite = 0;
    }
}
// END FUNCTION

// FUNCTION: 0x100f3db0 size=0x70
#include "IHudSprite.h"
#include "CBCCSlotViews.h"

struct SpriteElem { int m_iTexture; char *m_pData; int m_unk8; };

struct Eng37 {
	VIEW_SLOT10(0) VIEW_SLOT10(1) VIEW_SLOT10(2)
	VIEW_SLOT(30) VIEW_SLOT(31) VIEW_SLOT(32) VIEW_SLOT(33) VIEW_SLOT(34) VIEW_SLOT(35) VIEW_SLOT(36)
	virtual void vfunc37(int);
};
extern Eng37 *g_104a57d4;

// TARGET: vfunc1
void CHudSprite::vfunc1()
{
	if ( m_unk30 )
	{
		for ( int i = 0; i < m_unk34; i++ )
		{
			if ( ((SpriteElem *)m_unk30)[i].m_iTexture )
				g_104a57d4->vfunc37( ((SpriteElem *)m_unk30)[i].m_iTexture );
			delete ((SpriteElem *)m_unk30)[i].m_pData;
		}
		delete [] (SpriteElem *)m_unk30;
	}
	m_unk30 = 0;
	m_unk34 = 0;
	m_pSprite = 0;
}
// END FUNCTION
