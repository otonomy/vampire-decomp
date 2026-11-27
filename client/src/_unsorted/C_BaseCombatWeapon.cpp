// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10003000 size=0x1
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc143()
{
}
// END FUNCTION

// FUNCTION: 0x10003010 size=0x1
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc144()
{
}
// END FUNCTION

// FUNCTION: 0x10003020 size=0x7
#include "C_BaseCombatWeapon.h"
namespace lifted {
extern float g_101e4408;
}
float C_BaseCombatWeapon::vfunc151()
{
    return lifted::g_101e4408;
}
// END FUNCTION

// FUNCTION: 0x10003030 size=0x3
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc154()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10003040 size=0x3
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc155()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x10003050 size=0x5
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc156(int a0)
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10003060 size=0x2d
#include "CBaseEntityList.h"
#include "C_BaseCombatWeapon.h"
#include "CBaseEntityList.h"
void *C_BaseCombatWeapon::sub_10003060()
{
	unsigned int h = *(unsigned int *)((char *)this + 0x8f8);
	if (h != 0xffffffff) {
		CBaseEntityListEntry *e = &g_pEntityList->m_EntPtrArray[h & 0x1fff];
		if (e->m_SerialNumber == (int)(h >> 13))
			return e->m_pEntity;
	}
	return 0;
}
// END FUNCTION

// FUNCTION: 0x10003090 size=0x3
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc158()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100030a0 size=0x3
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc159()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100030b0 size=0x4
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc161()
{
    return -1;
}
// END FUNCTION

// FUNCTION: 0x100030c0 size=0x6
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc162()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100030d0 size=0x3
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc164(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x100030e0 size=0x3
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc168()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100030f0 size=0x7
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc169()
{
    return *(int *)((char *)this + 0x950);
}
// END FUNCTION

// FUNCTION: 0x10003100 size=0xd
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc170(int a0)
{
    *(int *)((char *)this + 0x950) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x10003110 size=0x3
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc186()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x10003120 size=0x3
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc187()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x10003130 size=0x3
#include "C_BaseCombatWeapon.h"
void * C_BaseCombatWeapon::vfunc190()
{
    return this;
}
// END FUNCTION

// FUNCTION: 0x10003140 size=0x3
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc208()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10003150 size=0x3
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc209()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10003160 size=0x9
#include "C_BaseCombatWeapon.h"
namespace lifted {
extern float g_101e34f0;
}
float C_BaseCombatWeapon::vfunc210(int a0, int a1)
{
    return lifted::g_101e34f0;
}
// END FUNCTION

// FUNCTION: 0x10003170 size=0x1
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc243()
{
}
// END FUNCTION

// FUNCTION: 0x10003180 size=0x3
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc244(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x10003190 size=0x3
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc245(int a0, int a1)
{
}
// END FUNCTION

// FUNCTION: 0x100031a0 size=0x3
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc247()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x100031b0 size=0x3
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc248(int a0, int a1, int a2)
{
}
// END FUNCTION

// FUNCTION: 0x100031c0 size=0x3
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc249(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
}
// END FUNCTION

// FUNCTION: 0x10003c80 size=0x8
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc246(int a0, int a1, int a2)
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x1007ab20 size=0x1e
#include "C_BaseCombatWeapon.h"

// VC6 writes C_BaseCombatWeapon's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_BaseCombatWeapon *pcd_emit_1007ab20(const C_BaseCombatWeapon &other) { return new C_BaseCombatWeapon(other); }

// TARGET: ??_GC_BaseCombatWeapon@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1007ab40 size=0x159
#include "C_BaseCombatWeapon.h"
#include "CUtlVector4.h"
#include "CVDmg_t.h"
struct HV_1007ab40 {
	int *m_pMemory;
	int m_allocationCount;
	int m_growSize;
	int m_size;
	int *m_pElements;
	void sub_1007db30(int elem, int num);
	int Find(unsigned int *h)
	{
		for (int i = 0; i < m_size; i++) {
			CBaseHandle *pe = (CBaseHandle *)&m_pMemory[i];
			void *pSrc = g_pEntityList->sub_1007aca0(h);
			if (pe->Get() == pSrc)
				return i;
		}
		return -1;
	}
	void Remove(int elem)
	{
		sub_1007db30(elem, 1);
		m_size--;
	}
};
extern HV_1007ab40 g_1049d8f8;
extern HV_1007ab40 g_1049d978;
C_BaseCombatWeapon::~C_BaseCombatWeapon()
{
	unsigned int h = -1;
	h = *((IHandleEntity *)this)->vfunc1();
	int i = g_1049d8f8.Find(&h);
	if (i != -1)
		g_1049d8f8.Remove(i);
	i = g_1049d978.Find(&h);
	if (i != -1)
		g_1049d978.Remove(i);
	CVDmg_t *p = (CVDmg_t *)((char *)this + 0x8a8);
	for (int n = 3; n; n--) {
		p--;
		p->sub_10158790();
	}
}
// END FUNCTION

// FUNCTION: 0x1007acd0 size=0xb7
#include "C_BaseCombatWeapon.h"

class CCollisionUnk_10043230
{
public:
	void sub_10043230(int solid);
};

class CEntityUnk_100a0710
{
public:
	void sub_100a0710(int modelName);
};

void C_BaseCombatWeapon::vfunc19()
{
	vfunc21();

	((CCollisionUnk_10043230 *)((char *)this + 0x190))->sub_10043230(2);

	*(int *)((char *)this + 0x928) = 0;
	*(int *)((char *)this + 0x934) = 0;
	*(int *)((char *)this + 0x914) = 0;

	int *pClip = (int *)((char *)this + 0x7ac);
	for (int i = 0; i < 2; i++, pClip++)
	{
		if (vfunc150(i))
		{
			if (sub_1007b160())
			{
				if (*pClip < *(int *)((char *)sub_1007b160() + 0x2668))
				{
					*pClip = *(int *)((char *)sub_1007b160() + 0x2668);
				}
			}
			else
			{
				*pClip = 0;
			}
		}
		else
		{
			*pClip = -1;
		}
	}

	((CEntityUnk_100a0710 *)this)->sub_100a0710(vfunc216());

	*(int *)((char *)this + 0x8b4) = -1;
	*(int *)((char *)this + 0x184) &= ~0x40000;
}
// END FUNCTION

// FUNCTION: 0x1007ad90 size=0x3b5
#include "C_BaseCombatWeapon.h"
#include "StatOwner2.h"
#include "CUnknown102029c0.h"

char __cdecl sub_101a48b0(void *fs, const char *name, void *p);
extern "C" int __cdecl _strcmpi(const char *, const char *);
extern void (__cdecl *g_101e3108)(const char *fmt, ...);
extern char g_102de300[];
extern void *g_104a580c;

struct EngineSoundV
{
	virtual void vfunc0(const char *, int);
};
extern EngineSoundV *g_104a5818;

struct AmmoV
{
	int sub_10078f40(const char *);
};
struct AmmoGet
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual AmmoV *v6();
};
extern AmmoGet *g_104a56fc;

struct XRes
{
	void sub_101a8d30(void *p);
};
extern XRes g_10678dd4;

struct NLV
{
	int sub_10157b30(void *);
};
extern NLV g_105f8b98;


struct DmgV
{
	void sub_10158ef0(void *);
};

struct WeapHelper
{
	void sub_1007cc30(void *);
	void sub_100a2910(const char *);
};

struct WeaponSoundSet
{
	char m_Sounds[25][16][0x94];
	int m_nCounts[25];
};
struct WeaponAmmoRec
{
	char m_pad0[0x14];
	char m_szAmmo[0x100];
	int m_iAmmoType;
	char m_pad118[0x2198 - 0x118];
	WeaponSoundSet m_Sounds;
};
struct WeaponAttackRec
{
	int m_n0;
	char m_szName[0x80];
	char m_szTag[0x80];
	int m_nTag104;
	int m_nKey108;
	int m_n10c[3];
	char m_Dmg118[0x1dc - 0x118];
	char m_szBotch[0x80];
	int m_nBotch25c;
	char m_pad260[0x490 - 0x260];
	WeaponSoundSet m_Sounds;
	char m_padec34[0xec84 - 0xec34];
};
struct WeaponInfoView
{
	char m_pad0[0x242c];
	int m_nFlags242c;
	char m_pad2430[0x2450 - 0x2430];
	char m_Keys2450[0x2560 - 0x2450];
	char m_sz2560[0x80];
	int m_n25e0;
	char m_pad25e4[0x2668 - 0x25e4];
	WeaponAmmoRec m_Ammo[2];
	WeaponAttackRec m_Attacks[3];
	char m_pad4fe6c[0x50378 - 0x4fe6c];
	WeaponSoundSet m_Sounds;
};

struct WeaponNamedRec
{
	int m_nId;
	const char *m_pszName;
};
extern int g_105e8630;
extern WeaponNamedRec **g_105e8634;
extern int g_105e85a4;
extern WeaponNamedRec **g_105e85a8;

inline const char *STRINGR(const char *const &s)
{
	return s ? s : g_102de300;
}

inline int LookupKeyA(const char *name)
{
	for (int i = 0; i < g_105e8630; i++)
		if (!_strcmpi(STRINGR(g_105e8634[i]->m_pszName), name))
			return g_105e8634[i]->m_nId;
	return -1;
}

inline int LookupKeyB(const char *name)
{
	for (int i = 0; i < g_105e85a4; i++)
		if (!_strcmpi(STRINGR(g_105e85a8[i]->m_pszName), name))
			return g_105e85a8[i]->m_nId;
	return -1;
}

struct WeapFields
{
	char m_pad0[0x7a4];
	int m_iAmmoType[2];
};

#define INFO() ((WeaponInfoView *)sub_1007b160())
#define F ((WeapFields *)this)

// TARGET: C_BaseCombatWeapon::vfunc21
void C_BaseCombatWeapon::vfunc21()
{
	if (sub_101a48b0(g_104a580c, vfunc114(), (char *)this + 0x95e)) {
		int i, j, k;
		{
			WeaponSoundSet &set = INFO()->m_Sounds;
			for (k = 0; k < 25; k++)
				for (j = 0; j < set.m_nCounts[k]; j++)
					g_104a5818->vfunc0(set.m_Sounds[k][j], 0);
		}
		for (i = 0; i < 2; i++) {
			WeaponAmmoRec *r = &INFO()->m_Ammo[i];
			if (r->m_szAmmo[0]) {
				r->m_iAmmoType = F->m_iAmmoType[i] = g_104a56fc->v6()->sub_10078f40(r->m_szAmmo);
				F->m_iAmmoType[i] = g_104a56fc->v6()->sub_10078f40(r->m_szAmmo);
			} else
				F->m_iAmmoType[i] = -1;
			*(int *)((char *)&F->m_iAmmoType[i] + 0x118) = r->m_iAmmoType;
			{
				WeaponSoundSet &set = r->m_Sounds;
				for (k = 0; k < 25; k++)
					for (j = 0; j < set.m_nCounts[k]; j++)
						g_104a5818->vfunc0(set.m_Sounds[k][j], 0);
			}
		}
		g_10678dd4.sub_101a8d30(this);
		((WeapHelper *)this)->sub_1007cc30(INFO()->m_Keys2450);
		INFO()->m_n25e0 = g_105f8b98.sub_10157b30(INFO()->m_sz2560);
		int tmp = g_105f93c0.sub_1015f160("TagStrings");
		if (tmp == -1)
			g_101e3108("Unable to find String List!\n");
		for (i = 0; i < 3; i++) {
			WeaponAttackRec *r = &INFO()->m_Attacks[i];
			if (r->m_szName[0]) {
				r->m_nTag104 = 0;
				if (tmp != -1)
					r->m_nTag104 = g_105f93c0.sub_1015f270(tmp)->sub_1015ed00(r->m_szName);
				r->m_nKey108 = LookupKeyA(r->m_szTag);
				((DmgV *)((char *)this + 0x7dc + i * 0x44))->sub_10158ef0(r->m_Dmg118);
				r->m_nBotch25c = LookupKeyB(r->m_szBotch);
				{
					WeaponSoundSet &set = r->m_Sounds;
					for (k = 0; k < 25; k++)
						for (j = 0; j < set.m_nCounts[k]; j++)
							((WeapHelper *)this)->sub_100a2910(set.m_Sounds[k][j]);
				}
			}
		}
		{
			const char *s = (const char *)vfunc215(0);
			if (s && *s)
				sub_100a0710(s);
		}
	}
	*((char *)this + 0x94c) = (INFO()->m_nFlags242c & 8) == 8;
}
// END FUNCTION

// FUNCTION: 0x1007b5f0 size=0xd
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc215(int a0)
{
    return (lifted::sub_1007b160()) + 0x2188;
}
// END FUNCTION

// FUNCTION: 0x1007b600 size=0xb
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc216()
{
    return (lifted::sub_1007b160()) + 0x2208;
}
// END FUNCTION

// FUNCTION: 0x1007b610 size=0xb
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc145()
{
    return (lifted::sub_1007b160()) + 0x2288;
}
// END FUNCTION

// FUNCTION: 0x1007b620 size=0xb
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc146()
{
    return (lifted::sub_1007b160()) + 0x2308;
}
// END FUNCTION

// FUNCTION: 0x1007b630 size=0xb
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc147()
{
    return (lifted::sub_1007b160()) + 0x2388;
}
// END FUNCTION

// FUNCTION: 0x1007b640 size=0xb
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc217()
{
    return (lifted::sub_1007b160()) + 0x2408;
}
// END FUNCTION

// FUNCTION: 0x1007b650 size=0x27
#include "CWeaponOwner.h"
struct CWeaponOwner;
CWeaponOwner *sub_1007b160();

int __stdcall sub_1007b650(int nIndex)
{
	return *(int *)((char *)sub_1007b160() + 0x2668 + nIndex * 0x1093c);
}
// END FUNCTION

// FUNCTION: 0x1007b6b0 size=0x1a
#include "C_BaseCombatWeapon.h"
// TARGET: C_BaseCombatWeapon::vfunc150
bool C_BaseCombatWeapon::vfunc150(int a)
{
	return vfunc148(a) != -1;
}
// END FUNCTION

// FUNCTION: 0x1007b6d0 size=0xc
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc218()
{
    return *(int *)((char *)(lifted::sub_1007b160()) + 0x2424);
}
// END FUNCTION

// FUNCTION: 0x1007b6e0 size=0xc
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc219()
{
    return *(int *)((char *)(lifted::sub_1007b160()) + 0x2428);
}
// END FUNCTION

// FUNCTION: 0x1007b6f0 size=0x9
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc223()
{
    return (lifted::sub_1007b160()) + 8;
}
// END FUNCTION

// FUNCTION: 0x1007b920 size=0xc
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc226()
{
    return *(int *)((char *)(lifted::sub_1007b160()) + 0x5ebd0);
}
// END FUNCTION

// FUNCTION: 0x1007b930 size=0xc
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc227()
{
    return *(int *)((char *)(lifted::sub_1007b160()) + 0x5ebd4);
}
// END FUNCTION

// FUNCTION: 0x1007b940 size=0xc
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc228()
{
    return *(int *)((char *)(lifted::sub_1007b160()) + 0x5ebd8);
}
// END FUNCTION

// FUNCTION: 0x1007b950 size=0xc
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc229()
{
    return *(int *)((char *)(lifted::sub_1007b160()) + 0x5ebdc);
}
// END FUNCTION

// FUNCTION: 0x1007b960 size=0xc
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc230()
{
    return *(int *)((char *)(lifted::sub_1007b160()) + 0x5ebe0);
}
// END FUNCTION

// FUNCTION: 0x1007b970 size=0xc
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc231()
{
    return *(int *)((char *)(lifted::sub_1007b160()) + 0x5ebe4);
}
// END FUNCTION

// FUNCTION: 0x1007b980 size=0xc
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc232()
{
    return *(int *)((char *)(lifted::sub_1007b160()) + 0x5ebe8);
}
// END FUNCTION

// FUNCTION: 0x1007b990 size=0xc
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b160();
}
int C_BaseCombatWeapon::vfunc233()
{
    return *(int *)((char *)(lifted::sub_1007b160()) + 0x5ebec);
}
// END FUNCTION

// FUNCTION: 0x1007b9a0 size=0x67
#include "C_BaseCombatWeapon.h"
// TARGET: C_BaseCombatWeapon::vfunc222
int C_BaseCombatWeapon::vfunc222(int n)
{
	switch (n) {
	case 21: case 22: case 23: case 24:
		return *(int *)((char *)sub_1007b160() + n * 4 + 0x5eab8);
	case 10: case 11:
		return *(int *)((char *)sub_1007b5b0() + n * 4 + 0x108d8);
	default:
		return *(int *)(sub_1007b180() + n * 4 + 0xebd0);
	}
}
// END FUNCTION

// FUNCTION: 0x1007bbe0 size=0x3
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc175()
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x1007bbf0 size=0x7a
#include "C_BasePlayer.h"
#include "C_BaseCombatWeapon.h"


bool C_BaseCombatWeapon::vfunc152()
{
	if (*(int *)((char *)this + 0x7a4) == -1 && *(int *)((char *)this + 0x7a8) == -1)
		return true;

	if (vfunc219() & 1)
		return true;

	void *p = C_BasePlayer::GetLocalPlayer();
	if (!p)
		return false;

	return *(int *)((char *)this + 0x7ac) > 0
		|| *(int *)((char *)p + 0xfdc + *(int *)((char *)this + 0x7a4) * 4)
		|| *(int *)((char *)this + 0x7b0) > 0
		|| *(int *)((char *)p + 0xfdc + *(int *)((char *)this + 0x7a8) * 4);
}
// END FUNCTION

// FUNCTION: 0x1007bdd0 size=0x1d
#include "C_BaseCombatWeapon.h"
struct CGlobals_102b8494 { float realtime, framecount, absoluteframetime, curtime; };
extern CGlobals_102b8494 *g_102b8494;
// TARGET: C_BaseCombatWeapon::vfunc182
bool C_BaseCombatWeapon::vfunc182()
{
	if (g_102b8494->curtime > *(float *)((char *)this + 0x918))
		return true;
	return false;
}
// END FUNCTION

// FUNCTION: 0x1007bdf0 size=0xd
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc183(int a0)
{
    *(int *)((char *)this + 0x918) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x1007be00 size=0x7
#include "C_BaseCombatWeapon.h"
float C_BaseCombatWeapon::vfunc184()
{
    return *(float *)((char *)this + 0x918);
}
// END FUNCTION

// FUNCTION: 0x1007bee0 size=0x1
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc173()
{
}
// END FUNCTION

// FUNCTION: 0x1007bef0 size=0x3
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc172(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1007bf00 size=0x3
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc214(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1007bf20 size=0x1
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc178()
{
}
// END FUNCTION

// FUNCTION: 0x1007bf30 size=0x3
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc171(int a0, int a1)
{
}
// END FUNCTION

// FUNCTION: 0x1007bf50 size=0xa9
#include "C_BaseCombatWeapon.h"

void C_BaseCombatWeapon::vfunc211(int seqType, float rate)
{
	int seq = sub_10095b90(seqType, -1, -1);
	if (seq == -1)
	{
		seq = sub_10095b90(0xb6, -1, -1);
		if (seq == -1)
			return;
	}
	*(int *)((char *)this + 0x63c) = seq;
	*(int *)((char *)this + 0x92c) = seqType;
	*(int *)((char *)this + 0x648) = 0;
	sub_10095880();
	if (rate > 0.0f)
	{
		float v = sub_10095910(seq, (char *)this + 0x5d4) / rate;
		*(float *)((char *)this + 0x640) = v;
		*(float *)((char *)this + 0x640) = (v < 12.0) ? v : 12.0;
	}
	else
		*(float *)((char *)this + 0x640) = 1.0f;
}
// END FUNCTION

// FUNCTION: 0x1007c000 size=0x8
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc174(int a0)
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x1007c010 size=0xd
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc179(int a0)
{
    *(int *)((char *)this + 0x914) = a0;
    return a0;
}
// END FUNCTION

// FUNCTION: 0x1007c020 size=0xcb
#include "C_BaseCombatWeapon.h"
#include "C_BasePlayer.h"

struct HV
{
	int sub_1007bab0();
};

struct WpnView
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
	virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
	virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
	virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
	virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
	virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
	virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
	virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
	virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
	virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
	virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
	virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
	virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
	virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
	virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
	virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
	virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
	virtual void v112(); virtual void v113(); virtual void v114(); virtual void v115();
	virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
	virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123();
	virtual void v124(); virtual void v125(); virtual void v126(); virtual void v127();
	virtual void v128(); virtual void v129(); virtual void v130(); virtual void v131();
	virtual void v132(); virtual void v133(); virtual void v134(); virtual void v135();
	virtual void v136(); virtual void v137(); virtual void v138(); virtual void v139();
	virtual void v140(); virtual void v141(); virtual void v142();
	virtual void v143(int);
	virtual void v144(int);
};

void C_BaseCombatWeapon::vfunc181(int a, int b)
{
	if (!vfunc168())
		return;
	if (!((HV *)this)->sub_1007bab0())
		return;
	C_BasePlayer *pPlayer = (C_BasePlayer *)((HV *)this)->sub_1007bab0();
	if (!pPlayer)
		return;
	C_BasePlayer *pOwner = *(C_BasePlayer **)((char *)pPlayer + 0x3f8);
	if (!pOwner)
		return;

	C_BaseCombatWeapon *pWeapon = (C_BaseCombatWeapon *)pOwner->sub_100a9af0(*(int *)((char *)this + 0x914));
	if (pWeapon)
	{
		((WpnView *)pWeapon)->v144(vfunc215(*(int *)((char *)this + 0x914)));
		((WpnView *)pWeapon)->v143(a);
		*(float *)((char *)pWeapon + 0x640) = *(float *)((char *)pOwner + 0x1078);
	}

	pWeapon = (C_BaseCombatWeapon *)pOwner->sub_100a9af0(1);
	if (pWeapon && pWeapon->sub_1008f900(-1))
	{
		((WpnView *)pWeapon)->v143(b);
		*(float *)((char *)pWeapon + 0x640) = *(float *)((char *)pOwner + 0x1078);
	}
}
// END FUNCTION

// FUNCTION: 0x1007c0f0 size=0x3
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc180(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1007c100 size=0x23
#include "C_BaseCombatWeapon.h"
// TARGET: ?vfunc185@C_BaseCombatWeapon@@UAE_NXZ
bool C_BaseCombatWeapon::vfunc185() { for (int i = 0; i < 2; i++) { if (vfunc153(i)) return true; } return false; }
// END FUNCTION

// FUNCTION: 0x1007c130 size=0x6d
#include "C_BaseCombatWeapon.h"

class CWeaponAmmoView
{
public:
	char sub_1007c1a0(int idx);
};

class CHost_10097f80
{
public:
	int sub_10097f80(int idx);
};

struct WeaponAmmoFields
{
	char m_pad0000[0x7a4];
	int m_iClip[2];		// 0x7a4
	int m_iAmmo[2];		// 0x7ac
};

bool C_BaseCombatWeapon::vfunc153(int i)
{
	WeaponAmmoFields *w = (WeaponAmmoFields *)this;

	if ( !((CWeaponAmmoView *)this)->sub_1007c1a0(i) )
		return true;

	if ( vfunc150(i) && w->m_iAmmo[i] > 0 )
		return true;

	if ( sub_1007bab0() && ((CHost_10097f80 *)sub_1007bab0())->sub_10097f80( w->m_iClip[i] ) > 0 )
		return true;

	return false;
}
// END FUNCTION

// FUNCTION: 0x1007c1d0 size=0xd
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1005fa40(int);
}
bool C_BaseCombatWeapon::vfunc188()
{
    lifted::sub_1005fa40(0);
    return 1;
}
// END FUNCTION

// FUNCTION: 0x1007c1e0 size=0x5
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc189(int a0)
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x1007c1f0 size=0x1
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc191()
{
}
// END FUNCTION

// FUNCTION: 0x1007c200 size=0x1
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc192()
{
}
// END FUNCTION

// FUNCTION: 0x1007c210 size=0x1
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc193()
{
}
// END FUNCTION

// FUNCTION: 0x1007c220 size=0x3
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc203()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1007c230 size=0x47
#include "C_BaseCombatWeapon.h"
struct VecD { float x, y, z; VecD(float a, float b, float c) { x = a; y = b; z = c; } ~VecD() {} };
// TARGET: C_BaseCombatWeapon::vfunc204
int C_BaseCombatWeapon::vfunc204()
{
    static VecD v(0.02618f, 0.02618f, 0.02618f);
    return (int)&v;
}
// END FUNCTION

// FUNCTION: 0x1007c290 size=0xc
#include "C_BaseCombatWeapon.h"
namespace lifted {
int sub_1007b180();
}
float C_BaseCombatWeapon::vfunc205()
{
    return *(float *)((char *)(lifted::sub_1007b180()) + 0x260);
}
// END FUNCTION

// FUNCTION: 0x1007c2a0 size=0x3a2
#include "C_BaseCombatWeapon.h"
#include "C_RecipientFilter.h"
#include "engineclient.h"

struct WeaponSoundData
{
    char m_szName[0x80];
    int m_nPitch;          // 0x80
    int m_nPitchMin;       // 0x84
    int m_nPitchMax;       // 0x88
    float m_flVolume;      // 0x8c
    bool m_bLocal;         // 0x90
};

struct WeaponOwnerView
{
    char pad[0x3f8];
    int m_n3f8;
};

void C_BaseCombatWeapon::vfunc206(int sound_type, int channel, float flVolume, int iPitch, float flAttenuation, int iFlagsOverride)
{
    if (vfunc222(sound_type) <= 0)
        return;

    float attn;
    int iFlags;
    int idx = enginerandom->RandomInt(0, vfunc222(sound_type) - 1);
    attn = 0.27f;
    iFlags = 0;
    WeaponSoundData *snd = (WeaponSoundData *)sub_1007ba10(sound_type, idx);

    float volume;
    if (flVolume == 0.0f)
    {
        volume = 1.0f;
        if (snd->m_flVolume != 0.0f)
            volume = snd->m_flVolume;
    }
    else
        volume = flVolume;
    if (iPitch == 0)
    {
        iPitch = 100;
        if (snd->m_nPitch)
            iPitch = snd->m_nPitch;
        if (snd->m_nPitchMin && snd->m_nPitchMax)
            iPitch = enginerandom->RandomInt(snd->m_nPitchMin, snd->m_nPitchMax);
    }
    if (flAttenuation != 0.0f)
        attn = flAttenuation;
    if (iFlagsOverride)
        iFlags = iFlagsOverride;

    if (snd->m_bLocal)
    {
        if (!sub_1007bab0())
            return;
        if (!((WeaponOwnerView *)sub_1007bab0())->m_n3f8)
            return;
        enginesound->vfunc0(snd->m_szName, 0);
        WeaponOwnerView *owner = (WeaponOwnerView *)sub_1007bab0();
        CSingleUserRecipientFilter filter(owner ? owner->m_n3f8 : 0);
        if (vfunc168())
            filter.sub_100be0d0();
        enginesound->EmitSound(filter, ((C_BaseEntity *)sub_1007bab0())->entindex(), 6, snd->m_szName, volume, *(int *)&attn, 0, iPitch, 0, 0, 1, 0);
    }
    else if (sub_1007bab0())
    {
        CPASAttenuationFilter filter(((C_BaseEntity *)sub_1007bab0())->GetAbsOrigin());
        if (vfunc168())
            filter.sub_100be0d0();
        enginesound->EmitSound(filter, ((C_BaseEntity *)sub_1007bab0())->entindex(), channel, snd->m_szName, volume, *(int *)&attn, iFlags, iPitch, 0, 0, 1, 0);
    }
    else
    {
        CPASAttenuationFilter filter(GetAbsOrigin());
        if (vfunc168())
            filter.sub_100be0d0();
        enginesound->EmitSound(filter, entindex(), channel, snd->m_szName, volume, *(int *)&attn, iFlags, iPitch, 0, 0, 1, 0);
    }
}
// END FUNCTION

// FUNCTION: 0x1007c8f0 size=0xb
#include "C_BaseCombatWeapon.h"
namespace lifted {
int __stdcall sub_1007c8d0(int);
}
int C_BaseCombatWeapon::vfunc198()
{
    return lifted::sub_1007c8d0(0xc2);
}
// END FUNCTION

// FUNCTION: 0x1007c900 size=0x1
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc194()
{
}
// END FUNCTION

// FUNCTION: 0x1007c910 size=0x6
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc201()
{
    return 0xbc;
}
// END FUNCTION

// FUNCTION: 0x1007c920 size=0x6
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc202()
{
    return 0xc0;
}
// END FUNCTION

// FUNCTION: 0x1007c930 size=0x1
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc212()
{
}
// END FUNCTION

// FUNCTION: 0x1007c940 size=0x6
#include "C_BaseCombatWeapon.h"
namespace lifted {
extern char g_102ac0bc;
}
int C_BaseCombatWeapon::vfunc213()
{
    return (int)&lifted::g_102ac0bc;
}
// END FUNCTION

// FUNCTION: 0x1007c950 size=0x1
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc195()
{
}
// END FUNCTION

// FUNCTION: 0x1007c960 size=0x10c
#include "C_BaseCombatWeapon.h"

struct AmmoOwnerView
{
	int sub_10097f80(int);
	void sub_10097f10(int, int);
	char m_pad[0x3f8];
	int m_n3f8;
};
struct GameRulesView
{
	virtual void v0();
	virtual bool vfunc1();
	char m_pad[0x2c - 4];
	int m_n2c;
};
extern GameRulesView *g_104772ac;
struct WpnAmmoView
{
	char m_pad[0x7a4];
	int m_nA[2];
	int m_nB[2];
};

// TARGET: C_BaseCombatWeapon::vfunc196
void C_BaseCombatWeapon::vfunc196()
{
	AmmoOwnerView *pOwner = (AmmoOwnerView *)sub_1007bab0();
	if (pOwner)
	{
		if (!*((char *)this + 0x94c))
		{
			WpnAmmoView *w = (WpnAmmoView *)this;
			for (int i = 0; i < 2; i++)
			{
				if (vfunc150(i))
				{
					int n = (vfunc148(i) - w->m_nB[i] < pOwner->sub_10097f80(w->m_nA[i])) ? vfunc148(i) - w->m_nB[i] : pOwner->sub_10097f80(w->m_nA[i]);
					w->m_nB[i] += n;
					if (pOwner->m_n3f8)
					{
						if (g_104772ac->vfunc1() || g_104772ac->m_n2c < 1)
							pOwner->sub_10097f10(n, w->m_nA[i]);
					}
				}
			}
		}
		*((char *)this + 0x91c) = 0;
		*((char *)this + 0x91e) = 0;
		*((char *)this + 0x91d) = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x1007ca70 size=0x14
#include "C_BaseCombatWeapon.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual void u168(); virtual void u169(); virtual void u170(); virtual void u171(); virtual void u172(); virtual void u173(); virtual void u174(); virtual void u175(); virtual void u176(); virtual void u177(); virtual void u178(); virtual void u179(); virtual void u180(); virtual void u181(); virtual void u182(); virtual void u183(); virtual void u184(); virtual void u185(); virtual void u186(); virtual void u187(); virtual void u188(); virtual void u189(); virtual void u190(); virtual void u191(); virtual void u192(); virtual void u193(); virtual void u194(); virtual void u195(); virtual void u196(); virtual void u197(); virtual void u198(); virtual void u199(); virtual void u200(); virtual void u201(); virtual void u202(); virtual void u203(); virtual void u204(); virtual void u205(); virtual void u206(); virtual int f207(int, int); };
}
int C_BaseCombatWeapon::vfunc197()
{
    *(char *)((char *)this + 0x91c) = 0;
    return ((lifted::V *)this)->f207(0xa, 3);
}
// END FUNCTION

// FUNCTION: 0x1007ca90 size=0x1
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc200()
{
}
// END FUNCTION

// FUNCTION: 0x1007caa0 size=0x152
#include "C_BaseCombatWeapon.h"
#include "CGlobalVarsBase.h"
#include "Vector.h"
#define V4(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3();
#define V16(p) V4(p##a) V4(p##b) V4(p##c) V4(p##d)
struct CWpnOwner {
    V16(a) V16(b) V4(c) V4(d) virtual void s0(); virtual void s1(); virtual void s2();
    virtual int vfunc43();
    V16(e) V16(f) V16(g) V16(h) V16(i) V16(j) V4(k) V4(l) virtual void t0(); virtual void t1();
    virtual void vfunc150(Vector *, int);
    V16(m) V16(n) V4(o) virtual void u0(); virtual void u1();
    virtual void vfunc189(int);
    char pad[0x70];
    int m_flags74;
    void sub_100a9b50(Vector *, float);
    int sub_10097f80(int);
    void sub_100a9be0(const char *, int, int);
};
// TARGET: C_BaseCombatWeapon::vfunc199
void C_BaseCombatWeapon::vfunc199()
{
    if (vfunc150(0) && !*(int *)((char *)this + 0x7ac)) {
        vfunc198();
        return;
    }
    CWpnOwner *o = sub_1007bb30();
    if (o) {
        vfunc206(1, 1, 0.0f, 0, 0.0f, 0);
        o->m_flags74 |= 2;
        vfunc180(vfunc201());
        o->vfunc189(5);
        Vector v;
        o->vfunc150(&v, o->vfunc43());
        Vector w;
        o->sub_100a9b50(&w, 0.087155745f);
        int n = 0;
        float f = vfunc205();
        float &t = *(float *)((char *)this + 0x790);
        if (t <= gpGlobals->curtime) {
            do {
                t += f;
                n++;
            } while (f != 0.0f && t <= gpGlobals->curtime);
        }
        int &cnt = *(int *)((char *)this + 0x7ac);
        if (n > cnt)
            n = cnt;
        cnt -= n;
        if (cnt == 0 && o->sub_10097f80(*(int *)((char *)this + 0x7a4)) <= 0)
            o->sub_100a9be0("!HEV_AMO0", 0, 0);
        vfunc212();
    }
}
// END FUNCTION

// FUNCTION: 0x1007cc00 size=0x29
#include "C_BaseCombatWeapon.h"
struct CWeaponInfo_1007b160 { char pad[0x4fea0]; int m_n4fea0; };
bool C_BaseCombatWeapon::vfunc250()
{
	bool r = false;
	if (sub_1007b160())
		r = ((CWeaponInfo_1007b160 *)sub_1007b160())->m_n4fea0 != 0;
	return r;
}
// END FUNCTION

// FUNCTION: 0x1007cde0 size=0x6
#include "C_BaseCombatWeapon.h"
namespace lifted {
extern char g_102abc88;
}
int C_BaseCombatWeapon::vfunc17()
{
    return (int)&lifted::g_102abc88;
}
// END FUNCTION

// FUNCTION: 0x1007cdf0 size=0x6
#include "C_BaseCombatWeapon.h"
namespace lifted {
extern char g_102abd10;
}
int C_BaseCombatWeapon::vfunc16()
{
    return (int)&lifted::g_102abd10;
}
// END FUNCTION

// FUNCTION: 0x1007ce00 size=0x3
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1007d450 size=0xe
struct V_1007d450 {
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
	virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
	virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
	virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
	virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
	virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
	virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
	virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
	virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
	virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
	virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
	virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104();
	virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
	virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114();
	virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
	virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124();
	virtual void v125(); virtual void v126(); virtual void v127(); virtual void v128(); virtual void v129();
	virtual void v130(); virtual void v131(); virtual void v132(); virtual void v133(); virtual void v134();
	virtual void v135(); virtual void v136(); virtual void v137(); virtual void v138(); virtual void v139();
	virtual void v140(); virtual void v141(); virtual void v142(); virtual void v143(); virtual void v144();
	virtual void v145(); virtual void v146(); virtual void v147(); virtual void v148(); virtual void v149();
	virtual void v150(); virtual void v151(); virtual void v152(); virtual void v153(); virtual void v154();
	virtual void v155(); virtual void v156(); virtual void v157(); virtual void v158(); virtual void v159();
	virtual void v160(); virtual void v161(); virtual void v162(); virtual void v163(); virtual void v164();
	virtual void v165(); virtual void v166(); virtual void v167(); virtual void v168(); virtual void v169();
	virtual void v170(); virtual void v171(); virtual void v172(); virtual void v173(); virtual void v174();
	virtual void v175(); virtual void v176(); virtual char v177();
};
// TARGET: sub_1007d450
bool __fastcall sub_1007d450(V_1007d450 *self)
{
	return self->v177() ? true : false;
}
// END FUNCTION

// FUNCTION: 0x1007d460 size=0x11
#include "C_BaseCombatWeapon.h"
// TARGET: C_BaseCombatWeapon::vfunc177
bool C_BaseCombatWeapon::vfunc177() { void *p = *(void **)((char *)sub_1007b160() + 0x2444); if (p) return true; return false; }
// END FUNCTION

// FUNCTION: 0x1007d480 size=0x4f
#include "C_BasePlayer.h"
#include "C_BaseCombatWeapon.h"

struct Player { int sub_100a8ba0(int i); };


struct WeaponView { char pad[0x79c]; int m_79c; };

int C_BaseCombatWeapon::vfunc220()
{
	Player *pPlayer = (Player *)(void *)((int)C_BasePlayer::GetLocalPlayer());
	if ( !pPlayer )
		return -1;
	WeaponView *pThis = (WeaponView *)this;
	int total = 0;
	for ( int i = 0; i < 7; i++ )
	{
		if ( pThis->m_79c >= total )
		{
			if ( pThis->m_79c < total + pPlayer->sub_100a8ba0(i) )
				return i;
		}
		total += pPlayer->sub_100a8ba0(i);
	}
	return -1;
}
// END FUNCTION

// FUNCTION: 0x1007d4d0 size=0x4c
#include "C_BasePlayer.h"
#include "C_BaseCombatWeapon.h"

class Player_1007d4d0
{
public:
	int sub_100a8ba0(int);
};


// TARGET: C_BaseCombatWeapon::vfunc221
int C_BaseCombatWeapon::vfunc221()
{
	Player_1007d4d0 *player = ((Player_1007d4d0 *)C_BasePlayer::GetLocalPlayer());
	if (!player)
		return -1;

	int slot = vfunc220();
	int sum = 0;
	for (int i = 0; i < slot; i++)
	{
		sum += player->sub_100a8ba0(i);
	}
	return *(int *)((char *)this + 0x79c) - sum;
}
// END FUNCTION

// FUNCTION: 0x1007d800 size=0x8
#include "C_BaseCombatWeapon.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual void u168(); virtual void u169(); virtual void u170(); virtual void u171(); virtual void u172(); virtual void u173(); virtual void u174(); virtual void u175(); virtual void u176(); virtual void u177(); virtual void u178(); virtual void u179(); virtual void u180(); virtual void u181(); virtual void u182(); virtual void u183(); virtual void u184(); virtual void u185(); virtual void u186(); virtual void u187(); virtual void u188(); virtual void u189(); virtual void u190(); virtual void u191(); virtual void u192(); virtual void u193(); virtual void u194(); virtual void u195(); virtual void u196(); virtual void u197(); virtual void u198(); virtual void u199(); virtual void u200(); virtual void u201(); virtual void u202(); virtual void u203(); virtual void u204(); virtual void u205(); virtual void u206(); virtual void u207(); virtual void u208(); virtual void u209(); virtual void u210(); virtual void u211(); virtual void u212(); virtual void u213(); virtual void u214(); virtual void u215(); virtual void u216(); virtual void u217(); virtual void u218(); virtual void u219(); virtual void u220(); virtual void u221(); virtual void u222(); virtual void u223(); virtual int f224(); };
}
int C_BaseCombatWeapon::vfunc160()
{
    return ((lifted::V *)this)->f224();
}
// END FUNCTION

// FUNCTION: 0x1007d860 size=0x8
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc35(int a0)
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x1007d870 size=0x8
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc36(int a0)
{
    return 1;
}
// END FUNCTION

// FUNCTION: 0x1007d880 size=0x3
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc165(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1007d8d0 size=0x3
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc166()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1007d8e0 size=0x1
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc167()
{
}
// END FUNCTION

// FUNCTION: 0x1007d8f0 size=0xe
#include "C_BaseCombatWeapon.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual void u168(); virtual void u169(); virtual void u170(); virtual void u171(); virtual void u172(); virtual void u173(); virtual void u174(); virtual void u175(); virtual void u176(); virtual void u177(); virtual void u178(); virtual void u179(); virtual int f180(int); };
}
int C_BaseCombatWeapon::vfunc163()
{
    return ((lifted::V *)this)->f180(0xc4);
}
// END FUNCTION

// FUNCTION: 0x1009b230 size=0x40
#include "C_BaseCombatWeapon.h"

void C_BaseCombatWeapon::vfunc29(char b)
{
	if (!IsDormant() && b)
	{
		if (!vfunc240())
			vfunc189(0);
	}
	C_BaseEntity::vfunc29(b);
}
// END FUNCTION

// FUNCTION: 0x1009b2c0 size=0x630
#include "C_BaseCombatWeapon.h"
#include "C_BasePlayer.h"
#include "CBaseHandle.h"
#include "ehandle.h"
#include "CHud.h"

void sub_1009c1a0();
void sub_10064bb0();
void sub_1009c6b0(C_BaseCombatWeapon *pWeapon);
extern "C" void *memmove(void *, const void *, unsigned int);

struct WpnEntListView { void *sub_1007aca0(const CBaseHandle *h); };
struct WpnHistoryView { void sub_100f01a0(int type, C_BaseCombatWeapon *pWeapon, int count); };

static inline void *WpnLookup(const CBaseHandle &h)
{
	return ((WpnEntListView *)g_pEntityList)->sub_1007aca0(&h);
}

struct WpnHandleVec
{
	CBaseHandle *m_pMemory;
	int m_nAllocationCount;
	int m_nGrowSize;
	int m_Size;
	CBaseHandle *m_pElements;

	void sub_1009ce10(int num);
	void sub_1009cea0(int elem, int num);
	void sub_1007db30(int elem, int num);
	void sub_1009cf00(int num);

	int Find(const CBaseHandle &src)
	{
		for (int i = 0; i < m_Size; i++) {
			const CBaseHandle &e = m_pMemory[i];
			void *pEnt = WpnLookup(src);
			if (e.Get() == pEnt)
				return i;
		}
		return -1;
	}
	int FindLookup(const CBaseHandle &src)
	{
		for (int i = 0; i < m_Size; i++) {
			if (WpnLookup(m_pMemory[i]) == WpnLookup(src))
				return i;
		}
		return -1;
	}
	void RemoveInline(int elem)
	{
		int numToMove = m_Size - elem - 1;
		if (numToMove > 0)
			memmove(&m_pMemory[elem], &m_pMemory[elem + 1], numToMove * sizeof(CBaseHandle));
		m_Size--;
	}
};
CBaseHandle *sub_1009cee0(CBaseHandle *pMem, const CBaseHandle &src);

extern WpnHandleVec g_1049d8f8;
extern WpnHandleVec g_1049d964;
extern WpnHandleVec g_1049d978;

struct WpnOwnerView
{
	char m_pad0000[0x3f0];
	struct WpnOwnerSub { char m_pad[0xfd0]; int m_nFD0; } *m_p3f0;
};

#define WF(T, off) (*(T *)((char *)this + (off)))

void C_BaseCombatWeapon::OnDataChanged(int updateType)
{
	sub_1009c1a0();
	C_BaseAnimating::OnDataChanged(updateType);
	bool bNew = (updateType == 0);
	CBaseHandle hThis;
	C_BaseCombatWeapon *pThis = this;
	hThis.m_Index = pThis ? *pThis->vfunc1() : 0xffffffff;

	if (bNew) {
		if (g_1049d964.Find(hThis) == -1) {
			int elem = g_1049d964.m_Size;
			g_1049d964.sub_1009ce10(1);
			g_1049d964.sub_1009cea0(elem, 1);
			CBaseHandle *p = &g_1049d964.m_pMemory[elem];
			if (p)
				*p = hThis;
		}
	}

	C_BasePlayer *pLocal = C_BasePlayer::GetLocalPlayer();
	if (!(pLocal && sub_1009b8f0() && sub_1007bab0() == pLocal)) {
		if (!bNew) {
			if (WF(int, 0x964) != 1 && WF(int, 0x964) != 2) {
				if (WF(int, 0x934) == 0 && sub_1007bab0() && sub_1007bab0() != pLocal)
					sub_1009c6b0(pThis);
			} else {
				int i = g_1049d8f8.FindLookup(hThis);
				if (i != -1) {
					g_1049d8f8.sub_1007db30(i, 1);
					g_1049d8f8.m_Size--;
				}
				pLocal->vfunc190(pThis);
			}
		}
		if (sub_1009b8f0()) {
			WpnOwnerView *pOwner = (WpnOwnerView *)sub_1007bab0();
			if (pOwner && pOwner->m_p3f0) {
				if (!pOwner->m_p3f0->m_nFD0)
					sub_100a06f0(WF(int, 0x7cc));
				else
					sub_100a06f0(WF(int, 0x7d0));
			} else {
				sub_100a06f0(WF(int, 0x924));
			}
		} else {
			sub_100a06f0(WF(int, 0x924));
		}
		if (WF(int, 0x934) != 0 || WF(int, 0x964) == 0)
			return;
	}

	if (!((WF(int, 0x934) == 1 || WF(int, 0x934) == 2) && (bNew || WF(int, 0x964) == 0))) {
		if (WF(int, 0x934) == 0 && WF(int, 0x964) != 0) {
			int i = g_1049d8f8.Find(hThis);
			if (i != -1)
				g_1049d8f8.RemoveInline(i);
		}
	} else {
		if (g_1049d8f8.Find(hThis) == -1) {
			int elem = g_1049d8f8.m_Size;
			if (g_1049d8f8.m_Size + 1 > g_1049d8f8.m_nAllocationCount)
				g_1049d8f8.sub_1009cf00(g_1049d8f8.m_Size + 1 - g_1049d8f8.m_nAllocationCount);
			g_1049d8f8.m_Size++;
			g_1049d8f8.m_pElements = g_1049d8f8.m_pMemory;
			g_1049d8f8.sub_1009cea0(elem, 1);
			sub_1009cee0(&g_1049d8f8.m_pMemory[elem], hThis);
		}
		CBaseHandle h2;
		h2.m_Index = pThis ? *pThis->vfunc1() : 0xffffffff;
		if (g_1049d978.Find(h2) != -1) {
			int i = g_1049d978.Find(h2);
			if (i != -1)
				g_1049d978.RemoveInline(i);
			pLocal->vfunc190(pThis);
		}
		if (vfunc242()) {
			WpnHistoryView *pHistory = (WpnHistoryView *)gHUD.FindElement("CHudHistoryResource");
			pHistory->sub_100f01a0(2, pThis, 0);
		}
	}

	if (WF(int, 0x934) >= 2 && WF(int, 0x964) < 2) {
		if (WF(int, 0x96c) != WF(int, 0x968)) {
			WF(int, 0x968) = WF(int, 0x96c);
			WF(float, 0x970) = 255.0f;
		}
		sub_1009c250();
	}
	if ((WF(int, 0x934) == 2 || WF(int, 0x934) == 0x40) && WF(int, 0x964) == 1) {
		sub_10064bb0();
		vfunc188();
		sub_1009c1a0();
		return;
	}
	if ((WF(int, 0x934) == 2 || WF(int, 0x934) == 0x40) && WF(int, 0x964) == 0) {
		sub_10064bb0();
		vfunc188();
		sub_1009c1a0();
		return;
	}
	if (WF(int, 0x934) == 1 && WF(int, 0x964) == 2)
		vfunc189(0);
	sub_1009c1a0();
}
// END FUNCTION

// FUNCTION: 0x1009b990 size=0x3
#include "C_BaseCombatWeapon.h"
int C_BaseCombatWeapon::vfunc86()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1009b9a0 size=0x32
#include "C_BaseCombatWeapon.h"
namespace lifted {
extern int g_105f99d8;
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual bool f27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual void u168(); virtual void u169(); virtual void u170(); virtual void u171(); virtual void u172(); virtual void u173(); virtual void u174(); virtual void u175(); virtual void u176(); virtual void u177(); virtual void u178(); virtual void u179(); virtual void u180(); virtual void u181(); virtual void u182(); virtual void u183(); virtual void u184(); virtual void u185(); virtual void u186(); virtual void u187(); virtual void u188(); virtual void u189(); virtual void u190(); virtual void u191(); virtual void u192(); virtual void u193(); virtual void u194(); virtual void u195(); virtual void u196(); virtual void u197(); virtual void u198(); virtual void u199(); virtual void u200(); virtual void u201(); virtual void u202(); virtual void u203(); virtual void u204(); virtual void u205(); virtual void u206(); virtual void u207(); virtual void u208(); virtual void u209(); virtual void u210(); virtual void u211(); virtual void u212(); virtual void u213(); virtual void u214(); virtual void u215(); virtual void u216(); virtual void u217(); virtual void u218(); virtual void u219(); virtual void u220(); virtual void u221(); virtual void u222(); virtual void u223(); virtual void u224(); virtual void u225(); virtual void u226(); virtual void u227(); virtual void u228(); virtual void u229(); virtual void u230(); virtual void u231(); virtual void u232(); virtual void u233(); virtual void u234(); virtual void u235(); virtual void u236(); virtual int f237(int); virtual int f238(int); };
}
int C_BaseCombatWeapon::vfunc235(int a0)
{
    bool t0 = ((lifted::V *)lifted::g_105f99d8)->f27();
    if (t0 != 0) {
        ((lifted::V *)this)->f237(a0);
    }
    return ((lifted::V *)this)->f238(a0);
}
// END FUNCTION

// FUNCTION: 0x1009b9e0 size=0x342
#include "C_BaseCombatWeapon.h"
#include "C_BasePlayer.h"
#include "CHud.h"
#include "CInput.h"

struct wrect_t
{
	int left, right, top, bottom;
};

struct CHudTextureView	// the icon gHUD.GetIcon returns
{
	char m_pad00[0x80];
	int textureId;	// 0x80
	int m_unk84;
	wrect_t rc;	// 0x88
};

struct CrosshairWpnInfo	// the weapon file info GetWpnData (sub_1007b160) returns
{
	char m_pad00000[0x50374];
	bool m_b50374;	// 0x50374
	char m_pad50375[0x5ebd8 - 0x50375];
	CHudTextureView *m_pCrosshair;	// 0x5ebd8
	CHudTextureView *m_pZoomedCrosshair;	// 0x5ebdc
	int m_n5ebe0;	// 0x5ebe0
};

struct ICrosshairDrawer	// g_102bc800
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
	virtual void DrawCrosshair(int textureId, wrect_t rc, int r, int g, int b);	// slot 18
};

struct G105V	// g_105f9994
{
	virtual void v0();
	virtual bool v1();
	int m_pad04[(0x2c - 4) / 4];
	int m_n2c;	// 0x2c
};

struct HV100a
{
	int sub_100a6b90();
};

extern ICrosshairDrawer *g_102bc800;
extern G105V *g_105f9994;
extern wrect_t g_1049d954;
extern bool g_103eeddc;
void sub_10064d50(CHudTextureView *pCrosshair, CHudTextureView *pZoomed, int n);
void sub_10064df0(C_BaseCombatWeapon *pWeapon);
void sub_10065050(int n);
bool sub_1004f830();

#define WPNDATA ((CrosshairWpnInfo *)sub_1007b160())

void C_BaseCombatWeapon::vfunc237(int)
{
	C_BasePlayer *player = C_BasePlayer::GetLocalPlayer();
	if (!player)
		return;

	if ((char)((HV100a *)player)->sub_100a6b90())
	{
		CHudTextureView *pArrow = (CHudTextureView *)gHUD.GetIcon("arrow");
		g_102bc800->DrawCrosshair(pArrow->textureId, pArrow->rc, 0xff, 0xd0, 0x50);
		return;
	}

	if (input->vfunc29())
	{
		sub_10064d50(0, 0, 0);
		g_102bc800->DrawCrosshair(0, g_1049d954, 0xff, 0xff, 0xff);
		return;
	}

	if (WPNDATA->m_pCrosshair && !WPNDATA->m_pCrosshair->textureId)
		sub_10064d50(WPNDATA->m_pCrosshair, WPNDATA->m_pZoomedCrosshair, WPNDATA->m_n5ebe0);
	else if (!WPNDATA->m_b50374)
		sub_10064d50(0, 0, 0);
	else
		sub_10064df0(this);

	if (sub_1004f830())
		return;

	if (*(int *)((char *)player + 0x1690) < (g_105f9994->v1() ? 0 : g_105f9994->m_n2c))
		return;

	if (*((bool *)player + 0x16a8))
	{
		if (g_103eeddc && WPNDATA->m_pZoomedCrosshair)
		{
			sub_10064d50(WPNDATA->m_pZoomedCrosshair, 0, 0);
			g_102bc800->DrawCrosshair(WPNDATA->m_pZoomedCrosshair->textureId, WPNDATA->m_pZoomedCrosshair->rc, 0xff, 0xd0, 0x50);
			sub_10065050(2);
			return;
		}
		if (WPNDATA->m_pCrosshair)
		{
			sub_10064d50(WPNDATA->m_pCrosshair, 0, 0);
			g_102bc800->DrawCrosshair(WPNDATA->m_pCrosshair->textureId, WPNDATA->m_pCrosshair->rc, 0xff, 0xd0, 0x50);
			return;
		}
		if (!WPNDATA->m_b50374)
			sub_10064d50(0, 0, 0);
	}
	else
	{
		sub_10064d50(0, 0, 0);
	}
	g_102bc800->DrawCrosshair(0, g_1049d954, 0xff, 0xff, 0xff);
}
// END FUNCTION

// FUNCTION: 0x1009bd30 size=0x4a
struct View { char pad[0x7ac]; int m7ac; char pad2[0x968-0x7b0]; int m968; int m96c; float m970; float m974; };
void __fastcall sub_1009bd30(View *self) {
 if (self->m968 != self->m7ac) {
  self->m970 = 255.0f;
  self->m974 = 127.5f;
  self->m96c = self->m968;
 }
 self->m968 = self->m7ac;
 if (self->m970 <= 0.0f) self->m96c = self->m7ac;
}
// END FUNCTION

// FUNCTION: 0x1009bd80 size=0x3
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc238(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1009bd90 size=0x3
#include "C_BaseCombatWeapon.h"
void C_BaseCombatWeapon::vfunc236(int a0)
{
}
// END FUNCTION

// FUNCTION: 0x1009bda0 size=0x2a
#include "C_BasePlayer.h"
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc240()
{
	if (!sub_1007bab0())
		return false;
	void *pPlayer = C_BasePlayer::GetLocalPlayer();
	return sub_1007bab0() == pPlayer;
}
// END FUNCTION

// FUNCTION: 0x1009bdd0 size=0x2b
#include "C_BaseCombatWeapon.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47(); virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51(); virtual void u52(); virtual void u53(); virtual void u54(); virtual void u55(); virtual void u56(); virtual void u57(); virtual void u58(); virtual void u59(); virtual void u60(); virtual void u61(); virtual void u62(); virtual void u63(); virtual void u64(); virtual void u65(); virtual void u66(); virtual void u67(); virtual void u68(); virtual void u69(); virtual void u70(); virtual void u71(); virtual void u72(); virtual void u73(); virtual void u74(); virtual void u75(); virtual void u76(); virtual void u77(); virtual void u78(); virtual void u79(); virtual void u80(); virtual void u81(); virtual void u82(); virtual void u83(); virtual void u84(); virtual void u85(); virtual void u86(); virtual void u87(); virtual void u88(); virtual void u89(); virtual void u90(); virtual void u91(); virtual void u92(); virtual void u93(); virtual void u94(); virtual void u95(); virtual void u96(); virtual void u97(); virtual void u98(); virtual void u99(); virtual void u100(); virtual void u101(); virtual void u102(); virtual void u103(); virtual void u104(); virtual void u105(); virtual void u106(); virtual void u107(); virtual void u108(); virtual void u109(); virtual void u110(); virtual void u111(); virtual void u112(); virtual void u113(); virtual void u114(); virtual void u115(); virtual void u116(); virtual void u117(); virtual void u118(); virtual void u119(); virtual void u120(); virtual void u121(); virtual void u122(); virtual void u123(); virtual void u124(); virtual void u125(); virtual void u126(); virtual void u127(); virtual void u128(); virtual void u129(); virtual void u130(); virtual void u131(); virtual void u132(); virtual void u133(); virtual void u134(); virtual void u135(); virtual void u136(); virtual void u137(); virtual void u138(); virtual void u139(); virtual void u140(); virtual void u141(); virtual void u142(); virtual void u143(); virtual void u144(); virtual void u145(); virtual void u146(); virtual void u147(); virtual void u148(); virtual void u149(); virtual void u150(); virtual void u151(); virtual void u152(); virtual void u153(); virtual void u154(); virtual void u155(); virtual void u156(); virtual void u157(); virtual void u158(); virtual void u159(); virtual void u160(); virtual void u161(); virtual void u162(); virtual void u163(); virtual void u164(); virtual void u165(); virtual void u166(); virtual void u167(); virtual void u168(); virtual void u169(); virtual void u170(); virtual void u171(); virtual void u172(); virtual void u173(); virtual void u174(); virtual void u175(); virtual void u176(); virtual void u177(); virtual void u178(); virtual void u179(); virtual void u180(); virtual void u181(); virtual void u182(); virtual void u183(); virtual void u184(); virtual void u185(); virtual void u186(); virtual void u187(); virtual void u188(); virtual void u189(); virtual void u190(); virtual void u191(); virtual void u192(); virtual void u193(); virtual void u194(); virtual void u195(); virtual void u196(); virtual void u197(); virtual void u198(); virtual void u199(); virtual void u200(); virtual void u201(); virtual void u202(); virtual void u203(); virtual void u204(); virtual void u205(); virtual void u206(); virtual void u207(); virtual void u208(); virtual void u209(); virtual void u210(); virtual void u211(); virtual void u212(); virtual void u213(); virtual void u214(); virtual void u215(); virtual void u216(); virtual void u217(); virtual void u218(); virtual void u219(); virtual void u220(); virtual void u221(); virtual void u222(); virtual void u223(); virtual void u224(); virtual void u225(); virtual void u226(); virtual void u227(); virtual void u228(); virtual void u229(); virtual void u230(); virtual void u231(); virtual void u232(); virtual void u233(); virtual void u234(); virtual void u235(); virtual void u236(); virtual void u237(); virtual void u238(); virtual void u239(); virtual bool f240(); };
}
bool C_BaseCombatWeapon::vfunc241()
{
    bool t0 = ((lifted::V *)this)->f240();
    if (t0 != 0) {
        if ((*(int *)((char *)this + 0x934)) == 2) {
            return 1;
        }
        if ((*(int *)((char *)this + 0x934)) == 0x40) {
            return 1;
        }
    }
    return 0;
}
// END FUNCTION

// FUNCTION: 0x1009bf10 size=0x81
#include "C_BaseCombatWeapon.h"
struct WpnVec { float x, y, z; };
struct WpnRend {
	virtual void v0(); virtual void v1();
	virtual WpnVec *GetRenderOrigin();
	virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
	virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
	virtual void GetRenderBounds(WpnVec &mins, WpnVec &maxs);
};
struct WpnEnt { int m_vptr; WpnRend m_Rend; };
#pragma warning(disable:4716)
// TARGET: ?vfunc64@C_BaseCombatWeapon@@UAEHHHH@Z
int C_BaseCombatWeapon::vfunc64(int a0, int a1, int a2)
{
	WpnEnt *ent = (WpnEnt *)a0;
	WpnVec *center = (WpnVec *)a1;
	WpnVec *origin = (WpnVec *)a2;
	WpnRend *r = &ent->m_Rend;
	WpnVec mins, maxs;
	r->GetRenderBounds(mins, maxs);
	center->x = (maxs.x - mins.x) * 0.5f + mins.x;
	center->y = (maxs.y - mins.y) * 0.5f + mins.y;
	center->z = (maxs.z - mins.z) * 0.5f + mins.z;
	*origin = *r->GetRenderOrigin();
}
// END FUNCTION

// FUNCTION: 0x1009c060 size=0x3
#include "C_BaseCombatWeapon.h"
bool C_BaseCombatWeapon::vfunc242()
{
    return 1;
}
// END FUNCTION
