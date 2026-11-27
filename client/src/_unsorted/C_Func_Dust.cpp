// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x100ba0c0 size=0x6
#include "C_Func_Dust.h"
namespace lifted {
extern char g_102b44ec;
}
int C_Func_Dust::vfunc16()
{
    return (int)&lifted::g_102b44ec;
}
// END FUNCTION

// FUNCTION: 0x100ba0d0 size=0x3
#include "C_Func_Dust.h"
int C_Func_Dust::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x100ba960 size=0x1e
#include "C_Func_Dust.h"

// VC6 writes C_Func_Dust's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_Func_Dust *pcd_emit_100ba960(const C_Func_Dust &other) { return new C_Func_Dust(other); }

// TARGET: ??_GC_Func_Dust@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x100ba980 size=0x38
#include "C_Func_Dust.h"
// TARGET: ??1C_Func_Dust@@UAE@XZ
C_Func_Dust::~C_Func_Dust()
{
}
// END FUNCTION

// FUNCTION: 0x100ba9c0 size=0x13c
#include "C_Func_Dust.h"
#include "Vector.h"
extern "C" int __cdecl _strnicmp(const char *, const char *, unsigned int);
extern "C" char *strstr(const char *, const char *);
// TARGET: ?PostDataUpdate@C_Func_Dust@@UAEXH@Z
void C_Func_Dust::PostDataUpdate(int updateType)
{
	C_BaseEntity::PostDataUpdate(updateType);
	const char *pName = m_pszMaterial;
	if (!pName)
		pName = "";
	if (_strnicmp(pName, "materials/", 10) == 0)
		pName += 10;
	char *pExt = strstr(pName, ".vmt");
	if (pExt)
		*pExt = 0;
	if (updateType == 0) {
		m_hMaterial = (unsigned char)(int)m_ParticleEffect.sub_101180b0(pName);
		const Vector &mins = vfunc52();
		const Vector &maxs = vfunc53();
		Vector sum = maxs + mins;
		Vector center = sum * 0.5f;
		m_ParticleEffect.sub_10118080(&center);
		vfunc83(-1293.0f);
		if (m_DustFlags & 4) {
			for (int i = 0; i < m_unk414; i++)
				sub_100babb0();
		}
	}
	m_unk4b4 = 0;
	m_flFactor = 1.0f / m_unk414;
}
// END FUNCTION
