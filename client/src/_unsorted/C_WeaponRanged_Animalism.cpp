// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10006190 size=0x6
#include "C_WeaponRanged_Animalism.h"

// TARGET: C_WeaponRanged_Animalism::vfunc16
int C_WeaponRanged_Animalism::vfunc16()
{
	return (int)"C_WeaponRanged_Animalism";
}
// END FUNCTION

// FUNCTION: 0x10006c70 size=0x62
#include "C_WeaponRanged_Animalism.h"

struct StatV_10006c70 { char *sub_1015ecd0(int); };
struct StatOwnerV_10006c70 { StatV_10006c70 *sub_1015f270(int); };
extern StatOwnerV_10006c70 g_105f93c0;
void sub_10064b60(const char *, int, int, char);

struct Weap_10006c70 {
	char m_pad[0x978];
	int m_978;
	int m_97c;
	int m_980;
	int m_984;
	int m_988;
	int m_98c;
	int m_990;
	int m_994;
	int m_998;
	int m_99c;
};

bool C_WeaponRanged_Animalism::vfunc188()
{
	Weap_10006c70 *w = (Weap_10006c70 *)this;
	bool b = (w->m_978 == 6 && w->m_97c <= 5);
	sub_10064b60(g_105f93c0.sub_1015f270(w->m_99c)->sub_1015ecd0(w->m_97c), w->m_97c, w->m_988, b);
	return C_BaseCombatWeapon::vfunc188();
}
// END FUNCTION

// FUNCTION: 0x10006ce0 size=0x18
#include "C_WeaponRanged_Animalism.h"
void sub_10064c60();
bool C_WeaponRanged_Animalism::vfunc189(int a)
{
	bool r = C_BaseCombatWeapon::vfunc189(a);
	sub_10064c60();
	return r;
}
// END FUNCTION

// FUNCTION: 0x10006d20 size=0x3c
#include "C_WeaponRanged_Animalism.h"
#include "CBaseHandle.h"
struct AnimView10006d20 {
    char m_unk[0x8fc];
    CBaseHandle m_h8fc;
    char m_unk900[0x978 - 0x900];
    int m_n978;
    int m_n97c;
};
void sub_10064dd0(CBaseHandle h, char flag);
// TARGET: C_WeaponRanged_Animalism::vfunc167
void C_WeaponRanged_Animalism::vfunc167()
{
    AnimView10006d20 *t = (AnimView10006d20 *)this;
    bool b = (t->m_n978 == 6 && t->m_n97c <= 5);
    sub_10064dd0(t->m_h8fc, b);
}
// END FUNCTION

// FUNCTION: 0x10006d70 size=0x47
#include "engineclient.h"
#include "C_WeaponRanged_Animalism.h"
#include "CHud.h"
struct HudElV { char pad[0x1c]; char m1c; };
// TARGET: ?vfunc246@C_WeaponRanged_Animalism@@UAEHHHH@Z
int C_WeaponRanged_Animalism::vfunc246(int a, int b, int c)
{
	if (a == 0 && b == 0x98967f) {
		HudElV *e = (HudElV *)gHUD.FindElement("CHudWeaponSelection");
		if (!e->m1c) {
			engine->vfunc27("lastinv", 1);
			return 0;
		}
	}
	return 1;
}
// END FUNCTION

// FUNCTION: 0x10006f90 size=0x1e
#include "C_WeaponRanged_Animalism.h"

// VC6 writes C_WeaponRanged_Animalism's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_WeaponRanged_Animalism *pcd_emit_10006f90(const C_WeaponRanged_Animalism &other) { return new C_WeaponRanged_Animalism(other); }

// TARGET: ??_GC_WeaponRanged_Animalism@@UAEPAXI@Z
// END FUNCTION
