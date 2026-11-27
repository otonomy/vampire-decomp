// IViewRenderBeams: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
#pragma once

class Vector;
struct BeamInfo_t;

class IViewRenderBeams
{
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the slots IViewRenderBeams adds to its base's vtable: 0-22, vfuncK at slot K
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4(class Beam_t *pbeam);	// DrawBeam
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual void vfunc11(Vector &start, Vector &end, int modelIndex, int haloIndex, float haloScale, float life, float width, float endWidth, float fadeLength, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b);
    virtual struct Beam_t *vfunc12(struct BeamInfoV *);
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual struct Beam_t *vfunc16(struct BeamInfoV *);
    virtual void vfunc17(int type, Vector &start, Vector &end, int modelIndex, int haloIndex, float haloScale, float life, float width, float endWidth, float fadeLength, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b);
    virtual void vfunc18(BeamInfo_t &beamInfo);
    virtual void vfunc19();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
};
