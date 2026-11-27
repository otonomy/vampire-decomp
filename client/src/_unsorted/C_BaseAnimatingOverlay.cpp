// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10097210 size=0x1e
#include "C_BaseAnimatingOverlay.h"

// VC6 writes C_BaseAnimatingOverlay's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
C_BaseAnimatingOverlay *pcd_emit_10097210(const C_BaseAnimatingOverlay &other) { return new C_BaseAnimatingOverlay(other); }

// TARGET: ??_GC_BaseAnimatingOverlay@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x10097360 size=0x6
#include "C_BaseAnimatingOverlay.h"
namespace lifted {
extern char g_102ae334;
}
int C_BaseAnimatingOverlay::vfunc16()
{
    return (int)&lifted::g_102ae334;
}
// END FUNCTION

// FUNCTION: 0x10097370 size=0x3
#include "C_BaseAnimatingOverlay.h"
int C_BaseAnimatingOverlay::vfunc15()
{
    return 0;
}
// END FUNCTION

// FUNCTION: 0x10097950 size=0x6
#include "C_BaseAnimatingOverlay.h"
namespace lifted {
extern char g_102ae31c;
}
int C_BaseAnimatingOverlay::vfunc17()
{
    return (int)&lifted::g_102ae31c;
}
// END FUNCTION

// FUNCTION: 0x10097960 size=0x41
#include "C_BaseAnimatingOverlay.h"

struct Blob4C { int d[0x13]; };
struct Elem { Blob4C a; Blob4C b; Blob4C c; };

struct OverlayView
{
	char m_pad[0x790];
	Elem m_elems[4];
};

int C_BaseAnimatingOverlay::vfunc70()
{
	OverlayView *v = (OverlayView *)this;
	Elem *e = v->m_elems;
	for ( int i = 4; i--; )
	{
		Blob4C *p = &e->b;
		p[-1] = p[0];
		p[0] = p[1];
		e++;
	}
	return C_BaseAnimating::vfunc70();
}
// END FUNCTION

// FUNCTION: 0x100979b0 size=0x431
#include "C_BaseAnimatingOverlay.h"
#include "Quaternion.h"
#include "engineclient.h"

struct SPoseHdr;
SPoseHdr *sub_1008d930(SPoseHdr *, int);
void sub_1008a690(char *, void *, void *, int, int);
void sub_1008a1e0(void *, void *, void *, void *, const CBitVecWords *);

struct OverlayBlend_t
{
	int m_n00;
	int m_unk04;
	int m_unk08;
	float m_fl0c;
	int m_unk10[(0x4c - 0x10) / 4];
	int m_nSequence;
	int m_n50;
	float m_flCycle;
	float m_fl58;
	int m_unk5c[(0xe4 - 0x5c) / 4];
};

struct OverlayGesture_t
{
	int m_nSequence;
	int m_unk04;
	float m_flFadeIn;
	float m_flFadeOut;
	int m_iPoseParam;
	float m_flPoseValue;
	float m_flStartTime;
	int m_unk1c;
};

union OverlayView
{
	struct {
		char m_pad0000[0x574];
		float m_flPoseA[24];
		float m_flPoseB[24];
		int m_unk634;
		int m_unk638;
		int m_nSequence;
		float m_flCycle;
		int m_unk644;
		int m_n648;
		int m_unk64c;
		int m_unk650;
		float m_fl654;
		char m_pad0658[0x6ac - 0x658];
		char *m_p6ac;
		char m_pad06b0[0x7dc - 0x6b0];
		OverlayBlend_t m_Blend[4];
	};
	struct {
		char m_pad0000b[0xb20];
		OverlayGesture_t m_Gesture[3];
	};
};

void C_BaseAnimatingOverlay::vfunc130(const CBitVecWords *boneMask, Vector *pos, Quaternion *q)
{
	OverlayView *v = (OverlayView *)this;
	float poseparam[24];
	float f = vfunc122();
	SPoseHdr *hdr = (SPoseHdr *)sub_1008f900(-1);
	int i;
	for (i = 0; i < 24; i++) {
		if (!sub_1008d930(hdr, i))
			break;
		poseparam[i] = vfunc129(i, v->m_flPoseA[i], v->m_flPoseB[i], f);
	}
	float t = f * 0.1;
	float cycle = vfunc121(v->m_n648, v->m_nSequence, poseparam, v->m_flCycle, t);
	float savedCycle = cycle;
	sub_100968a0(pos, q, v->m_nSequence, cycle, poseparam, boneMask);
	sub_10091110(boneMask, cycle, poseparam, pos, q);
	OverlayBlend_t *pb = v->m_Blend;
	for (i = 0; i < 4; i++, pb++) {
		if (pb->m_nSequence != pb->m_n00) {
			if (pb->m_fl58 > 0.5)
				pb->m_fl0c = 1.0f;
			else
				pb->m_fl0c = 0.0f;
		}
	}
	Vector pos2[350];
	Quaternion q2[350];
	float inv = 1.0f - f;
	for (i = 0; i < 4; i++) {
		OverlayBlend_t &b = v->m_Blend[i];
		float w = inv * b.m_fl0c + f * b.m_fl58;
		if (w > 0.0f && sub_10096830(b.m_nSequence)) {
			cycle = vfunc121(b.m_n50, b.m_nSequence, poseparam, b.m_flCycle, t);
			sub_100968a0(pos2, q2, b.m_nSequence, cycle, poseparam, boneMask);
			if (w > 1.0f)
				w = 1.0f;
			sub_10096b30(q, pos, b.m_nSequence, q2, pos2, w, boneMask);
		}
	}
	sub_1008a690(v->m_p6ac, pos, q, (int)poseparam, (int)boneMask);
	int layer[3];
	layer[0] = 0;
	for (i = 1; i < 3; i++) {
		int j;
		for (j = i; j > 0 && v->m_Gesture[layer[j - 1]].m_flStartTime > v->m_Gesture[i].m_flStartTime; j--)
			layer[j] = layer[j - 1];
		layer[j] = i;
	}
	float now = engine->Time(0);
	for (i = 0; i < 3; i++) {
		OverlayGesture_t &g = v->m_Gesture[layer[i]];
		if (!(g.m_flStartTime < 0.0f) && !(g.m_flStartTime > now)
			&& !(g.m_flFadeOut + g.m_flFadeIn + g.m_flStartTime <= now)
			&& sub_10096830(g.m_nSequence)) {
			float saved = 0.0f;
			if (g.m_iPoseParam >= 0 && g.m_iPoseParam < 24) {
				saved = poseparam[g.m_iPoseParam];
				poseparam[g.m_iPoseParam] = g.m_flPoseValue;
			}
			sub_100968a0(pos2, q2, g.m_nSequence, 0.0f, poseparam, boneMask);
			if (g.m_iPoseParam >= 0 && g.m_iPoseParam < 24)
				poseparam[g.m_iPoseParam] = saved;
			float w;
			if (g.m_flFadeIn + g.m_flStartTime > now)
				w = (now - g.m_flStartTime) / g.m_flFadeIn;
			else
				w = (g.m_flFadeOut + g.m_flFadeIn + g.m_flStartTime - now) / g.m_flFadeOut;
			sub_10096b30(q, pos, g.m_nSequence, q2, pos2, w, boneMask);
		}
	}
	float extra[4];
	vfunc120(extra, f);
	sub_1008a1e0(v->m_p6ac, pos, q, extra, boneMask);
	v->m_fl654 = savedCycle;
}
// END FUNCTION
