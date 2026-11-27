// CViewRenderBeams: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 23 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "IViewRenderBeams.h"
#include "Beam_t.h"

struct BeamV;
struct BeamInfoV;

class CViewRenderBeams : public IViewRenderBeams
{
public:
	CViewRenderBeams();
	Beam_t m_Beams[128];
	int m_unk1bc04;
	int m_unk1bc08;
	Beam_t *sub_10193470(bool bInit);
	Beam_t *sub_101938a0(void *pInfo);
	Beam_t *sub_10194160(void *pInfo);
	void *m_pFirst;
	int m_unk1bc10;
	int m_unk1bc14;
	int m_nNumBeamTrails;
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CViewRenderBeams's own function
	virtual void vfunc0();
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3();
	virtual void vfunc4(Beam_t *pbeam);	// DrawBeam
	void sub_10194e20(const char *sprite, Beam_t *pbeam, int frame, int rendermode, float frametime, float *color);	// DrawBeamFollow
	void sub_10195770(Beam_t *pbeam, int frame, int rendermode, float *color, const char *sprite);	// DrawTesla
	virtual void vfunc5();
	virtual void vfunc6(IHandleEntity *);
	virtual void vfunc7();
	virtual void vfunc8();
	virtual void vfunc9();
	virtual void vfunc10();
	virtual void vfunc11(Vector &start, Vector &end, int modelIndex, int haloIndex, float haloScale, float life, float width, float endWidth, float fadeLength, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b);
	virtual Beam_t *vfunc12(BeamInfoV *);
	int sub_101937e0(Vector *, Vector *, int);
	virtual void vfunc13();
	virtual void vfunc14();
	virtual void vfunc15();
	virtual Beam_t *vfunc16(BeamInfoV *);
	virtual void vfunc17(int type, Vector &start, Vector &end, int modelIndex, int haloIndex, float haloScale, float life, float width, float endWidth, float fadeLength, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b);
	virtual void vfunc18(BeamInfo_t &beamInfo);
	virtual void vfunc19();
	virtual Beam_t *vfunc20(struct InfoView101942b0 *info);
	void sub_10194830(Beam_t *pBeam, float frametime);
	bool sub_10195d00(Beam_t *pBeam);
	virtual void vfunc21();
	void sub_10193790(BeamV *, BeamInfoV *);
	void sub_10194370(Vector *center, int startRadius, int endRadius, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18);
	void sub_10195520(Beam_t *pbeam, int frame, int rendermode, float *color, const char *spritemodel, int unused);	// DrawLaser
	void sub_101934d0(void *pBeam);
	void sub_10195070(Beam_t *pbeam, int frame, int rendermode, float *color, const char *sprite, const char *halosprite);	// DrawLaser with halo sprites
	void sub_101947b0(void **ppList);
	virtual void vfunc22(BeamV *, BeamInfoV *);
	// the slots CViewRenderBeams adds to its base's vtable: 23-23, vfuncK at slot K
	virtual ~CViewRenderBeams();
};
