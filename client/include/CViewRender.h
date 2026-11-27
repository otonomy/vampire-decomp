// CViewRender: skeleton from the game's RTTI (vtable-slot skeletons, 2026-11-22)
// declared: its bases, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22) (its vtable has no deleting destructor: no virtual destructor)
#pragma once
#include "IViewRender.h"
#include "QAngle.h"
#include "Vector.h"
#include "CViewSetup.h"

class CViewRender : public IViewRender
{
public:
    void sub_1019ac50(bool, int, int);
    char sub_10198e70();
    void sub_101997e0(struct VWInfo *, struct VRList *, bool);
    bool sub_1019f140(int arg);
    bool sub_1019fa30(int arg);
    void sub_1019e530(int, int, float, float, int, int, int, int);
    void sub_1019af80(bool, int);
    void sub_10190850();
    float sub_101907a0(const QAngle &, const Vector &, float, float);
    void sub_1019c970();
    void sub_1019d8f0(const char *view);
    void sub_1019a950(int, void *, void *, int, int);
	void sub_1019add0(int, int, int);
	void sub_1019add0(bool, int, int);	// ViewDrawScene's call: the game passes the bool drawSkybox unwidened, as to sub_1019ac50
	void sub_1019ab90(bool, int, int, int);
    void sub_10191710();
    void sub_10190390();
    void sub_1019a560(int unused);	// "CViewRender::DrawObfuscatedEntities": draws the obfuscated model (+0x404) of each entity in the handle list at +0x464 with the local player's blend, then purges the list
    void CopyViewModelInfoToEntities();
    int sub_1018fab0();
    void sub_1019fb50(const struct CViewSetup &view);
    int sub_1018fb10();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
    // the base slots the game's vtable fills with CViewRender's own function
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4(struct vrect_t *rect);	// "CViewRender::Render"
    virtual void vfunc5(const CViewSetup &view, bool drawViewModel, bool bFlag);	// RenderView-like
    virtual void *vfunc6(int);
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual int vfunc10(class C_BaseEntity *pEntity);
    virtual char * vfunc11();
    virtual char * vfunc12();
    virtual bool vfunc13();
    virtual void *vfunc14();
    virtual void vfunc15(const class Vector &);
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual int vfunc20();
    virtual int vfunc21();
    virtual int vfunc22();
    virtual int vfunc23();
    virtual int vfunc24();
    virtual int vfunc25();
    virtual int vfunc26();
    virtual int vfunc27();
    virtual int vfunc28();
    virtual int vfunc29();
    virtual int vfunc30();
    virtual int vfunc31();
    virtual int vfunc32();
    virtual int vfunc33();
    virtual int vfunc34();
    virtual int vfunc35();
    virtual int vfunc36();
    virtual int vfunc37();
    virtual int vfunc38();
    virtual void vfunc39();
    virtual bool vfunc40(Vector *pOut1, Vector *pOut2, float *pOut3);
    virtual void vfunc41();
    virtual void vfunc42();
    virtual bool vfunc43();
    // the slots CViewRender adds to its base's vtable: 44-45, vfuncK at slot K
    virtual void vfunc44();
    virtual float vfunc45();
    void *sub_10190ba0(int nIndex, int nModel, const Vector &eyeOrigin, const QAngle &eyeAngles, const Vector &offset, float flZ, int unused);	// "CViewRender::CalcViewModelView": the view model record of slot 6, placed at the cine camera or the eye (+offset), nudged by the convar at +0x37c and by the offset vector at +0x4
    void sub_1018fcb0(int nIndex);
    void sub_1018fb70(int nIndex);
    CViewRender *sub_1018e9b0(unsigned flags);
    CViewRender *sub_10198a90();	// the constructor ("CViewRender::CViewRender" scope trace), written as a plain member
    void sub_1019aed0(bool, int);	// provisional, like sub_1019af80 (transplant)
    void sub_1019b370(bool drawSkybox, const struct CViewSetup &view, bool bSetupViewModel, bool bDrawViewModel);	// "CViewRender::ViewDrawScene" (keeps materials slot 34's answer at +0x454 and gives it back through slot 33)
    void sub_1019b030(float flFeed, const struct CViewSetup &view);
    void sub_101919e0(struct CViewSetup cameraView);	// "CViewRender::DrawHighEndMonitors": every active C_PointCamera drawn into engine/camerarendertarget
    void sub_1019d590();
    void sub_10199910(void *pInfo, void *pRenderList, bool, bool);
    void sub_10199cc0(void *pInfo, void *pRenderList, bool, bool, bool);
    void sub_10199ed0(const struct CViewSetup &view, void *pInfo, void *pRenderList, bool, bool, bool);
    void sub_10190a70();
    void sub_10191200();
    float sub_10190900();
    void sub_10190640();
    float sub_1018ffd0();
    // m_View (the CViewSetup at +0x10) through an accessor: classes of matched code derive from CViewRender with
    // members placed after sizeof(CViewRender), so CViewRender declares no data members yet
    CViewSetup &View() { return *(CViewSetup *)((char *)this + 0x10); }
};
