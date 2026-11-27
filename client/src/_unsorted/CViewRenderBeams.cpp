// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101932d0 size=0x39
#include "CViewRenderBeams.h"
#include "Beam_t.h"
// TARGET: CViewRenderBeams::CViewRenderBeams
CViewRenderBeams::CViewRenderBeams() : m_pFirst(0)
{
}
// END FUNCTION

// FUNCTION: 0x10193320 size=0x1e
#include "CViewRenderBeams.h"

// VC6 writes CViewRenderBeams's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CViewRenderBeams *pcd_emit_10193320(const CViewRenderBeams &other) { return new CViewRenderBeams(other); }

// TARGET: ??_GCViewRenderBeams@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x101933b0 size=0x95
#include "CViewRenderBeams.h"
void CViewRenderBeams::vfunc2()
{
	m_unk1bc04 = 0;
	m_unk1bc08 = (int)&m_Beams[0];
	for (int i = 0; i < 128; i++) {
		m_Beams[i].sub_10192db0();
		*(Beam_t **)((char *)&m_Beams[i] + 0x24) = &m_Beams[i + 1];
	}
	*(int *)((char *)&m_Beams[127] + 0x24) = 0;
	m_unk1bc14 = (int)m_pFirst;
	m_unk1bc10 = 0;
	for (int j = 0; j < m_nNumBeamTrails; j++) {
		char *p = (char *)m_pFirst;
		*(char **)(p + j * 0x20) = p + j * 0x20 + 0x20;
	}
	*(int *)((char *)m_pFirst + m_nNumBeamTrails * 0x20 - 0x20) = 0;
}
// END FUNCTION

// FUNCTION: 0x10193450 size=0x12
#include "CViewRenderBeams.h"
namespace lifted {
int sub_101d1296(int);
}
void CViewRenderBeams::vfunc1()
{
    if ((*(int *)((char *)this + 0x1bc0c)) != 0) {
        lifted::sub_101d1296(*(int *)((char *)this + 0x1bc0c));
    }
}
// END FUNCTION

// FUNCTION: 0x10193520 size=0xbb
#include "CBaseEntityList.h"
#include "CViewRenderBeams.h"
#include "ehandle.h"
struct TrailV10193520 { TrailV10193520 *next; float die; };
struct BeamV10193520 {
    char pad0[0x24];
    BeamV10193520 *next;
    int type;
    int flags;
    char pad1[0xcc - 0x30];
    float die;
    char pad2[0x104 - 0xd0];
    CBaseHandle entity;
    char pad3[0x368 - 0x108];
    TrailV10193520 *trail;
};
struct GlobalsV10193520 { float a, b, c, curtime; };
extern GlobalsV10193520 *g_102b8494;
struct ActiveV10193520 { char pad[0x1bc04]; BeamV10193520 *m_pActive; };

// TARGET: CViewRenderBeams::vfunc6
void CViewRenderBeams::vfunc6(IHandleEntity *pDeadEntity)
{
    BeamV10193520 *pbeam, *pnext, *pnewlist = 0;
    pbeam = ((ActiveV10193520 *)this)->m_pActive;
    while (pbeam)
    {
        pnext = pbeam->next;
        IHandleEntity *pEnt;
        unsigned long h = pbeam->entity.m_Index;
        CBaseEntityListEntry *e;
        if (h != 0xffffffff && (e = &g_pEntityList->m_EntPtrArray[h & 0x1fff], e->m_SerialNumber == (int)(h >> 13)))
            pEnt = (IHandleEntity *)e->m_pEntity;
        else
            pEnt = 0;
        if (pEnt == pDeadEntity)
        {
            pbeam->flags &= ~3;
            if (pbeam->type != 0x16)
            {
                pbeam->die = g_102b8494->curtime - 0.1;
                for (TrailV10193520 *t = pbeam->trail; t; t = t->next)
                    t->die = g_102b8494->curtime - 0.1;
                sub_101934d0(pbeam);
                pbeam = pnext;
                continue;
            }
        }
        pbeam->next = pnewlist;
        pnewlist = pbeam;
        pbeam = pnext;
    }
    ((ActiveV10193520 *)this)->m_pActive = pnewlist;
}
// END FUNCTION

// FUNCTION: 0x10193f90 size=0xa9
#include "engineclient.h"
#include "CViewRenderBeams.h"
#include "Vector.h"
struct BeamInfoV
{
	int m_nType;
	void *m_pStartEnt;
	int m_nStartAttachment;
	void *m_pEndEnt;
	int m_nEndAttachment;
	Vector m_vecStart;
	Vector m_vecEnd;
	int m_nModelIndex;
	const char *m_pszModelName;
	int m_nHaloIndex;
	const char *m_pszHaloName;
	float m_flHaloScale;
	float m_flLife;
};
// TARGET: ?vfunc12@CViewRenderBeams@@UAEPAUBeam_t@@PAUBeamInfoV@@@Z
Beam_t *CViewRenderBeams::vfunc12(BeamInfoV *info)
{
	if (info->m_flLife != 0)
	{
		if (!sub_101937e0(&info->m_vecStart, &info->m_vecEnd, 1))
			return 0;
	}
	if (info->m_pszModelName && info->m_nModelIndex == -1)
		info->m_nModelIndex = modelinfo->GetModelIndex(info->m_pszModelName);
	if (info->m_pszHaloName && info->m_nHaloIndex == -1)
		info->m_nHaloIndex = modelinfo->GetModelIndex(info->m_pszHaloName);
	Beam_t *pBeam = sub_101938a0(info);
	if (!pBeam)
		return 0;
	sub_10193790((BeamV *)pBeam, info);
	if (info->m_flLife == 0)
		*(unsigned int *)((char *)pBeam + 0x2c) |= 0x80000000;
	return pBeam;
}
// END FUNCTION

// FUNCTION: 0x10194040 size=0x11a
#include "CViewRenderBeams.h"
#include "Vector.h"

struct BeamInfo_t
{
	int m_nType;
	void *m_pStartEnt;
	int m_nStartAttachment;
	void *m_pEndEnt;
	int m_nEndAttachment;
	Vector m_vecStart;
	Vector m_vecEnd;
	int m_nModelIndex;
	const char *m_pszModelName;
	int m_nHaloIndex;
	const char *m_pszHaloName;
	float m_flHaloScale;
	float m_flLife;
	float m_flWidth;
	float m_flEndWidth;
	float m_flFadeLength;
	float m_flAmplitude;
	float m_flBrightness;
	float m_flSpeed;
	int m_nStartFrame;
	float m_flFrameRate;
	float m_flRed;
	float m_flGreen;
	float m_flBlue;
	bool m_bRenderable;
	int m_nSegments;
	int m_nFlags;
	Vector m_vecCenter;
	float m_flStartRadius;
	float m_flEndRadius;

	BeamInfo_t()
	{
		m_nType = 0;
		m_nSegments = -1;
		m_pszModelName = 0;
		m_pszHaloName = 0;
		m_nModelIndex = -1;
		m_nHaloIndex = -1;
		m_bRenderable = true;
		m_nFlags = 0;
	}
};

// TARGET: CViewRenderBeams::vfunc17
void CViewRenderBeams::vfunc17(int type, Vector &start, Vector &end,
	int modelIndex, int haloIndex, float haloScale, float life, float width,
	float endWidth, float fadeLength, float amplitude, float brightness,
	float speed, int startFrame, float framerate, float r, float g, float b)
{
	BeamInfo_t beamInfo;

	beamInfo.m_nType = type;
	beamInfo.m_vecStart = start;
	beamInfo.m_vecEnd = end;
	beamInfo.m_nModelIndex = modelIndex;
	beamInfo.m_nHaloIndex = haloIndex;
	beamInfo.m_flHaloScale = haloScale;
	beamInfo.m_flLife = life;
	beamInfo.m_flWidth = width;
	beamInfo.m_flEndWidth = endWidth;
	beamInfo.m_flFadeLength = fadeLength;
	beamInfo.m_flAmplitude = amplitude;
	beamInfo.m_flBrightness = brightness;
	beamInfo.m_flSpeed = speed;
	beamInfo.m_nStartFrame = startFrame;
	beamInfo.m_flFrameRate = framerate;
	beamInfo.m_flRed = r;
	beamInfo.m_flGreen = g;
	beamInfo.m_flBlue = b;

	vfunc18(beamInfo);
}
// END FUNCTION

// FUNCTION: 0x10194160 size=0x48
#include "CViewRenderBeams.h"

struct BeamInfoView2
{
	int m_n0;
	char m_pad4[0x40 - 0x4];
	float m_fl40;
};

class BeamHelpers
{
public:
	void sub_10193790(Beam_t *pBeam, void *pInfo);
};

Beam_t *CViewRenderBeams::sub_10194160(void *pInfo)
{
	BeamInfoView2 *info = (BeamInfoView2 *)pInfo;
	Beam_t *pBeam = sub_101938a0(pInfo);
	if ( !pBeam )
		return pBeam;

	*(int *)((char *)pBeam + 0x28) = info->m_n0;
	((BeamHelpers *)this)->sub_10193790(pBeam, pInfo);

	if ( info->m_fl40 == 0.0f )
		*(int *)((char *)pBeam + 0x2c) |= (int)0x80000000;

	return pBeam;
}
// END FUNCTION

// FUNCTION: 0x101942b0 size=0xb8
#include "CViewRenderBeams.h"
#include "vector.h"
extern Vector g_104d4970;
struct EntView101942b0 { virtual void v0(); virtual unsigned int *v1(); };
struct InfoView101942b0
{
	int m_nType;
	EntView101942b0 *m_pStartEnt;
	int m_nStartAttachment;
	int m_unkc[2];
	Vector m_vecStart;
	Vector m_vecEnd;
	int m_unk2c[(0x58 - 0x2c) / 4];
	float m_f58;
	float m_f5c;
	float m_f60;
};
struct BeamView101942b0
{
	char pad[0x28];
	int type;
	int flags;
	char pad2[0x104 - 0x30];
	unsigned int entity0;
	char pad3[0x12c - 0x108];
	int attach0;
};
Beam_t *CViewRenderBeams::vfunc20(InfoView101942b0 *info)
{
	info->m_vecStart = g_104d4970;
	info->m_vecEnd = g_104d4970;
	info->m_f58 = 1.0f;
	BeamView101942b0 *pBeam = (BeamView101942b0 *)sub_101938a0(info);
	if (!pBeam)
		return 0;
	pBeam->type = 0x16;
	pBeam->flags = 1;
	if (info->m_pStartEnt)
		pBeam->entity0 = *info->m_pStartEnt->v1();
	else
		pBeam->entity0 = 0xffffffff;
	pBeam->attach0 = info->m_nStartAttachment;
	info->m_f60 = 1.0f;
	info->m_f5c = 0;
	sub_10193790((BeamV *)pBeam, (BeamInfoV *)info);
	sub_10194830((Beam_t *)pBeam, 0);
	return (Beam_t *)pBeam;
}
// END FUNCTION

// FUNCTION: 0x10194490 size=0xac
#include "CViewRenderBeams.h"
struct BeamInfoV { char p0[0x14]; int m14, m18, m1c, m20, m24, m28; char p2c[0x40 - 0x2c]; float m40; char p44[0x7c - 0x44]; int m7c, m80, m84; int m88, m8c; };
struct BmView { char p0[0x28]; int m28; unsigned int m2c; char p30[0x4c - 0x30]; int m4c, m50, m54; char p58[0x36c - 0x58]; int m36c, m370; };
Beam_t *CViewRenderBeams::vfunc16(BeamInfoV *info)
{
	const int &x = info->m7c;
	const int &y = info->m80;
	const int &z = info->m84;
	info->m14 = x;
	info->m18 = y;
	info->m1c = z;
	info->m20 = x;
	info->m24 = y;
	info->m28 = z;
	Beam_t *b = sub_101938a0(info);
	if (!b)
		return 0;
	BmView *v = (BmView *)b;
	v->m28 = 0x1a;
	v->m36c = info->m88;
	v->m370 = info->m8c;
	v->m4c = x;
	v->m50 = y;
	v->m54 = z;
	sub_10193790((BeamV *)b, info);
	if (info->m40 == 0.0f)
		v->m2c |= 0x80000000;
	return b;
}
// END FUNCTION

// FUNCTION: 0x10194d70 size=0xa2
#include "CGlobalVarsBase.h"
#include "CViewRenderBeams.h"


struct ILeafSystemV
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void v9();
	virtual void v10();
	virtual void vfunc11(unsigned short, int);
};
extern ILeafSystemV *g_102b9060;

struct BeamTrailV
{
	char pad0[0x20];
	unsigned short m_hRender;   // +0x20
	char pad22[0x24 - 0x22];
	BeamTrailV *m_pNext;        // +0x24
	char pad28[0x2c - 0x28];
	int m_nFlags;               // +0x2c
	char pad30[0xcc - 0x30];
	float m_flDie;              // +0xcc
	void sub_10192f20();
};

struct CViewRenderBeamsView
{
	char pad[0x1bc04];
	BeamTrailV *m_pFirst;
};

struct CBeamsHelper
{
	void sub_10194830(void *p, float f);
};

// TARGET: CViewRenderBeams::vfunc3
void CViewRenderBeams::vfunc3()
{
	CViewRenderBeamsView *v = (CViewRenderBeamsView *)this;
	if (!v->m_pFirst)
		return;
	float frametime = gpGlobals->frametime;
	BeamTrailV *prev = 0;
	BeamTrailV *p = v->m_pFirst;
	while (p)
	{
		BeamTrailV *next = p->m_pNext;
		if ((p->m_nFlags & 0x80000000) == 0 && p->m_flDie <= gpGlobals->curtime)
		{
			if (prev)
				prev->m_pNext = next;
			else
				v->m_pFirst = next;
			sub_101934d0(p);
		}
		else
		{
			((CBeamsHelper *)this)->sub_10194830(p, frametime);
			p->sub_10192f20();
			if (p->m_hRender != 0xffff)
				g_102b9060->vfunc11(p->m_hRender, 2);
			prev = p;
		}
		p = next;
	}
}
// END FUNCTION

// FUNCTION: 0x101957f0 size=0x49d
#include "CViewRenderBeams.h"
#include "CGlobalVarsBase.h"
#include "engineclient.h"

extern "C" __declspec(dllimport) void DevWarning(int level, const char *fmt, ...);

void sub_100845e0(int noise_divisions, float *prgNoise, const char *spritemodel, float frame, int rendermode, const Vector &source, const Vector &delta, float width, float scale, float freq, float speed, int segments, float *color);
void sub_10084ae0(int noise_divisions, float *prgNoise, const char *spritemodel, float frame, int rendermode, const Vector &source, const Vector &delta, float width, float scale, float freq, float speed, int segments, float *color);
void sub_10082fd0(int noise_divisions, float *prgNoise, const char *spritemodel, float frame, int rendermode, const Vector &source, const Vector &delta, float startWidth, float endWidth, float scale, float freq, float speed, int segments, int flags, float *color, float fadeLength, Vector *pOut);
void sub_10085000(int noise_divisions, float *prgNoise, void (*pfnNoise)(float *noise, int divs, float scale), const char *spritemodel, float frame, int rendermode, const Vector &source, const Vector &delta, float width, float amplitude, float freq, float speed, int segments, float *color);
void sub_10083d60(int noise_divisions, float *prgNoise, const char *spritemodel, const char *halosprite, float haloScale, float frame, int rendermode, int numAttachments, Vector *attachment, float startWidth, float endWidth, float amplitude, float freq, float speed, int segments, int flags, float *color, float fadeLength);
void sub_10194cb0(float *noise, int divs, float scale);

// mathlib.h's float-array forms
inline void VectorScale(const float *in, vec_t scale, float *out)
{
	out[0] = in[0] * scale;
	out[1] = in[1] * scale;
	out[2] = in[2] * scale;
}

inline void VectorCopy(const float *in, float *out)
{
	out[0] = in[0];
	out[1] = in[1];
	out[2] = in[2];
}

void CViewRenderBeams::vfunc4(Beam_t *pbeam)
{
	if (pbeam->delta.Length() < 0.1)
		return;

	const char *sprite;
	const char *halosprite;

	if (pbeam->modelIndex < 0) {
		pbeam->die = gpGlobals->curtime;
		return;
	}

	sprite = (const char *)modelinfo->GetModel(pbeam->modelIndex);
	if (!sprite)
		return;

	halosprite = (const char *)modelinfo->GetModel(pbeam->haloIndex);

	int frame = ((int)(pbeam->frame + gpGlobals->curtime * pbeam->frameRate) % pbeam->frameCount);
	int rendermode = (pbeam->flags & 0x20) ? 0 : 5;

	float srcColor[3];
	float color[3];

	srcColor[0] = pbeam->r;
	srcColor[1] = pbeam->g;
	srcColor[2] = pbeam->b;
	if (pbeam->flags & 4) {
		VectorScale(srcColor, pbeam->t, color);
	} else if (pbeam->flags & 8) {
		VectorScale(srcColor, (1.0f - pbeam->t), color);
	} else {
		VectorCopy(srcColor, color);
	}

	VectorScale(color, ((float)pbeam->brightness / 255.0), color);
	VectorScale(color, (1 / 255.0), color);

	switch (pbeam->type) {
	case 20:
		sub_100845e0(128, pbeam->rgNoise, sprite, frame, rendermode,
			pbeam->attachment[0], pbeam->delta, pbeam->width, pbeam->amplitude,
			pbeam->freq, pbeam->speed, pbeam->segments, color);
		break;

	case 21:
		sub_10084ae0(128, pbeam->rgNoise, sprite, frame, rendermode,
			pbeam->attachment[0], pbeam->delta, pbeam->width, pbeam->amplitude,
			pbeam->freq, pbeam->speed, pbeam->segments, color);
		break;

	case 0:
		if (halosprite) {
			sub_10195070(pbeam, frame, rendermode, color, sprite, halosprite);
		} else {
			sub_10082fd0(128, pbeam->rgNoise, sprite, frame, rendermode,
				pbeam->attachment[0], pbeam->delta, pbeam->width, pbeam->endWidth,
				pbeam->amplitude, pbeam->freq, pbeam->speed, pbeam->segments,
				pbeam->flags, color, pbeam->fadeLength, (Vector *)&pbeam->m_unkb8);
		}
		break;

	case 22:
		sub_10194e20(sprite, pbeam, frame, rendermode, gpGlobals->frametime, color);
		break;

	case 24:
	case 26:
		sub_10085000(128, pbeam->rgNoise, sub_10194cb0, sprite, frame, rendermode,
			pbeam->attachment[0], pbeam->delta, pbeam->width, pbeam->amplitude,
			pbeam->freq, pbeam->speed, pbeam->segments, color);
		break;

	case 25:
		sub_10083d60(128, pbeam->rgNoise, sprite, halosprite,
			pbeam->haloScale, frame, rendermode, pbeam->numAttachments,
			pbeam->attachment, pbeam->width, pbeam->endWidth, pbeam->amplitude,
			pbeam->freq, pbeam->speed, pbeam->segments, pbeam->flags, color, pbeam->fadeLength);
		break;

	case 27:
		sub_10195520(pbeam, frame, rendermode, color, sprite, (int)halosprite);
		break;

	case 28:
		sub_10195770(pbeam, frame, rendermode, color, sprite);
		break;

	default:
		DevWarning(1, "CViewRenderBeams::DrawBeam:  Unknown beam type %i\n", pbeam->type);
		break;
	}
}
// END FUNCTION

// FUNCTION: 0x10195c90 size=0x6f
#include "CViewRenderBeams.h"
#include "Vector.h"

struct BeamInfoV
{
	char pad0[0x14];
	Vector m_vecStart;	// 0x14
	Vector m_vecEnd;	// 0x20
};

struct BeamV
{
	char pad0[0x34];
	Vector m_vecStart;	// 0x34
	Vector m_vecEnd;	// 0x40
	char pad1[0xac - 0x4c];
	Vector m_vecDelta;	// 0xac
};

void CViewRenderBeams::vfunc22(BeamV *pBeam, BeamInfoV *pInfo)
{
	pBeam->m_vecStart = pInfo->m_vecStart;
	pBeam->m_vecEnd = pInfo->m_vecEnd;
	pBeam->m_vecDelta = pInfo->m_vecEnd - pInfo->m_vecStart;
	sub_10193790(pBeam, pInfo);
}
// END FUNCTION
