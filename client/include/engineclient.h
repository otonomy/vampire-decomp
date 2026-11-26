// Client engine interfaces: the globals client.dll's CHLClient::Init fills from the engine's factory, named
// by the version string it asks for (2003 tree, cl_dll/cdll_client_int.cpp; physics: cl_dll/physics.cpp).
// Slots and types come from the views the matched functions used (votes of their signatures; a call the
// game makes through a slot proves it). Write `engine->Time()`, `materials->vfunc25(...)`; never a view of
// your own. Type a `void vfuncN()` slot here with edit_context when you need it. Change it through pcdecomp.
#pragma once
#include "Vector.h"
#include "QAngle.h"

struct CGameTrace;
class CSpriteHandle;
class CWaterEnum;
class C_BaseEntity;
class ConVar;
class IRecipientFilter;
struct Ray_t;
struct StudioHdr;
class VMatrix;

namespace EngineGlobals {

// engine = g_104a57d4, asked for as "VEngineClient006"
class IVEngineClient
{
public:
	virtual void vfunc0();
	virtual int vfunc1(char, int);	// slot 1; shapes differ
	virtual void vfunc2();
	virtual void vfunc3(const char *);	// slot 3
	virtual void vfunc4(const char *);	// slot 4
	virtual void vfunc5();
	virtual bool vfunc6();	// slot 6
	virtual void vfunc7();
	virtual void vfunc8();
	virtual void vfunc9();
	virtual bool vfunc10();	// slot 10
	virtual void vfunc11(int, void *);	// slot 11
	virtual void vfunc12(void *);	// slot 12; shapes differ
	virtual void vfunc13();
	virtual void vfunc14();
	virtual void vfunc15();
	virtual void vfunc16();
	virtual void vfunc17();
	virtual int vfunc18(int);	// slot 18
	virtual int vfunc19(int, const Vector &);	// slot 19; seen as GetPointContents 1
	virtual void vfunc20();
	virtual void vfunc21();
	virtual void vfunc22();
	virtual Vector *vfunc23(Vector *, void *, int);	// slot 23; shapes differ
	virtual void vfunc24();
	virtual void vfunc25();
	virtual void vfunc26();
	virtual void vfunc27(const char *, int);	// slot 27; seen as ClientCmd 7, ServerCmd 4; shapes differ
	virtual void ClientCmd(const char *);	// slot 28
	virtual void vfunc29();
	virtual void vfunc30(int, void *);	// slot 30
	virtual void vfunc31();
	virtual void vfunc32();
	virtual void vfunc33();
	virtual int vfunc34();	// slot 34
	virtual void vfunc35();
	virtual void *vfunc36(const char *);	// slot 36; seen as LoadModel 1
	virtual void vfunc37();
	virtual float vfunc38();	// slot 38; seen as Time 1
	virtual double Time(int);	// slot 39
	virtual void vfunc40();
	virtual float vfunc41(int);	// slot 41; seen as GetFrameTime 1, Time 1
	virtual float vfunc42();	// slot 42
	virtual void vfunc43();
	virtual int vfunc44();	// slot 44; seen as FrameCount 1
	virtual void vfunc45();
	virtual int vfunc46();	// slot 46; seen as GetX 1; shapes differ
	virtual int vfunc47();	// slot 47; seen as GetY 1
	virtual void vfunc48();
	virtual void GetViewAngles(QAngle &);	// slot 49
	virtual void SetViewAngles(QAngle &);	// slot 50
	virtual int GetMaxClients();	// slot 51
	virtual void vfunc52();
	virtual void vfunc53();
	virtual void vfunc54();
	virtual void vfunc55();
	virtual void vfunc56();
	virtual int IsInGame();	// slot 57
	virtual int vfunc58();	// slot 58
	virtual int vfunc59();	// slot 59
	virtual void vfunc60(int, const char *, ...);	// slot 60; seen as Con_NPrintf 1
	virtual void vfunc61();
	virtual void vfunc62();
	virtual int vfunc63();	// slot 63; seen as GetState 1, Cmd_Argc 1, Argc 1
	virtual char *Cmd_Argv(int);	// slot 64
	virtual void vfunc65();
	virtual int vfunc66(const Vector &, int, const Vector &, const QAngle &);	// slot 66
	virtual void vfunc67();
	virtual void vfunc68();
	virtual void vfunc69();
	virtual void vfunc70();
	virtual void vfunc71();
	virtual bool vfunc72(const Vector &, const Vector &);	// slot 72; seen as IsBoxVisible 1
	virtual void vfunc73();
	virtual void vfunc74();
	virtual void vfunc75();
	virtual void vfunc76();
	virtual void vfunc77();
	virtual void vfunc78();
	virtual void vfunc79();
	virtual void vfunc80();
	virtual void vfunc81();
	virtual void vfunc82();
	virtual void vfunc83();
	virtual void vfunc84();
	virtual void vfunc85();
	virtual void vfunc86();
	virtual void vfunc87();
	virtual void vfunc88();
	virtual void vfunc89();
	virtual void vfunc90();
	virtual void vfunc91(float *, float *);	// slot 91; seen as LinearToGamma 1
	virtual float vfunc92(int);	// slot 92; seen as LightStyleValue 1
	virtual void vfunc93();
	virtual void vfunc94(const Vector &, const Vector *, Vector &);	// slot 94; seen as ComputeDynamicLighting 1
	virtual void vfunc95();
	virtual int vfunc96();	// slot 96; seen as GetDXSupportLevel 1
	virtual void vfunc97();
	virtual void vfunc98();
	virtual void vfunc99();
	virtual void vfunc100();
	virtual void vfunc101();
	virtual void vfunc102();
	virtual int vfunc103(const char *);	// slot 103; seen as GetParticleIndex 1
	virtual void vfunc104();
	virtual void vfunc105();
	virtual const char *vfunc106();	// slot 106
	virtual void vfunc107();
	virtual void vfunc108();
	virtual void vfunc109();
	virtual void vfunc110();
	virtual void vfunc111();
	virtual void vfunc112();
	virtual void vfunc113();
	virtual void vfunc114();
	virtual void vfunc115();
	virtual void vfunc116();
	virtual void *vfunc117(int, int);	// slot 117
};
extern IVEngineClient *g_104a57d4;

// modelrender = g_104a57d8, asked for as "VEngineModel006"
class IVModelRender
{
public:
	virtual StudioHdr *GetStudiomodel(void *);	// slot 0; shapes differ
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3();
	virtual void vfunc4();
	virtual int vfunc5(int);	// slot 5; seen as GetModelFrameCount 1
	virtual void vfunc6();
	virtual void vfunc7();
	virtual void vfunc8(const Vector &);	// slot 8; seen as SetViewTarget 1
	virtual void vfunc9();
	virtual void vfunc10();
	virtual void vfunc11();
	virtual int vfunc12(const char *);	// slot 12; seen as GetModelIndex 1
	virtual int vfunc13(void *);	// slot 13; seen as GetModelMaterialCount 1
	virtual unsigned short vfunc14(void *, int, int);	// slot 14; seen as CreateHandle 1, GetModelMaterials 1; shapes differ
	virtual void vfunc15(unsigned short);	// slot 15; seen as RemoveRenderable 1
	virtual void vfunc16(unsigned short, const Ray_t &, const Vector &, int, int, bool, int);	// slot 16; seen as AddDecal 1
	virtual void vfunc17();
	virtual void vfunc18();
	virtual void vfunc19();
	virtual void vfunc20();
	virtual void vfunc21();
	virtual void vfunc22();
	virtual void vfunc23();
	virtual void vfunc24(unsigned short);	// slot 24
};
extern IVModelRender *g_104a57d8;

// effects = g_104a57dc, asked for as "VEngineEffects001"
class IVEfx
{
public:
	virtual int Draw_DecalIndex(int);	// slot 0
	virtual void vfunc1();
	virtual void DecalShoot(int, int, int, const Vector &, const QAngle &, const Vector &, const Vector *, int);	// slot 2
	virtual void vfunc3();
	virtual void *CL_AllocDlight(int);	// slot 4
};
extern IVEfx *g_104a57dc;

// cvar = g_104a57e0, asked for as "VEngineCvar001"
class ICvar
{
public:
	virtual void vfunc0();
	virtual bool vfunc1();	// slot 1
	virtual ConVar *FindVar(const char *);	// slot 2; shapes differ
};
extern ICvar *g_104a57e0;

// enginetrace = g_104a582c, asked for as "EngineTraceClient003"
class IEngineTrace
{
public:
	virtual int GetPointContents(const Vector &, void *);	// slot 0
	virtual void vfunc1();
	virtual void vfunc2(Ray_t *, unsigned int, const void *, CGameTrace *);	// slot 2
	virtual void vfunc3();
	virtual void vfunc4(int, int, const void *, int);	// slot 4; seen as Slot4 1; shapes differ
	virtual void vfunc5(void *, const float *, const float *, const float *, unsigned int, void *, CGameTrace *);	// slot 5
	virtual void vfunc6();
	virtual void vfunc7(Ray_t *, int, const void *);	// slot 7
	virtual void vfunc8();
	virtual void vfunc9();
	virtual void vfunc10();
	virtual void vfunc11();
	virtual void vfunc12();
	virtual void vfunc13();
	virtual void vfunc14();
	virtual void vfunc15();
	virtual void vfunc16();
	virtual void vfunc17();
	virtual void vfunc18();
	virtual void vfunc19();
	virtual void vfunc20();
	virtual void vfunc21();
	virtual void vfunc22();
	virtual void vfunc23();
	virtual void vfunc24();
	virtual void vfunc25();
	virtual void vfunc26();
	virtual void vfunc27();
	virtual void vfunc28();
	virtual void vfunc29();
	virtual void vfunc30();
	virtual void vfunc31();
	virtual void vfunc32();
	virtual void vfunc33();
	virtual void vfunc34();
	virtual void vfunc35();
	virtual void vfunc36();
	virtual void vfunc37();
	virtual void vfunc38();
	virtual void vfunc39();
	virtual void vfunc40();
	virtual void vfunc41();
	virtual void vfunc42();
	virtual void vfunc43();
	virtual void vfunc44();
	virtual void vfunc45();
	virtual void vfunc46();
	virtual void vfunc47();
	virtual void vfunc48();
	virtual void vfunc49();
};
extern IEngineTrace *g_104a582c;

// render = g_104a57e4, asked for as "VEngineRenderView008"
class IVRenderView
{
public:
	virtual void vfunc0(C_BaseEntity *, const void *, const Vector &, const QAngle &, int);	// slot 0; seen as DrawBrushModel 1; shapes differ
	virtual int vfunc1();	// slot 1
	virtual int vfunc2();	// slot 2
	virtual int vfunc3();	// slot 3
	virtual int vfunc4();	// slot 4
	virtual int vfunc5();	// slot 5
	virtual int vfunc6();	// slot 6
	virtual int vfunc7();	// slot 7
	virtual int vfunc8();	// slot 8
	virtual int vfunc9();	// slot 9
	virtual int vfunc10();	// slot 10
	virtual int vfunc11();	// slot 11
	virtual int vfunc12();	// slot 12
	virtual int vfunc13();	// slot 13
	virtual void vfunc14(const Vector &, float);	// slot 14; seen as GetSetup 1; shapes differ
	virtual int vfunc15();	// slot 15
	virtual int vfunc16();	// slot 16
	virtual int vfunc17();	// slot 17
	virtual int vfunc18();	// slot 18
	virtual int vfunc19();	// slot 19
	virtual int vfunc20();	// slot 20
	virtual int vfunc21();	// slot 21
	virtual int vfunc22();	// slot 22
	virtual int vfunc23();	// slot 23
	virtual int vfunc24();	// slot 24
	virtual int vfunc25();	// slot 25
	virtual int vfunc26();	// slot 26
	virtual int vfunc27();	// slot 27
	virtual void vfunc28(int, int, const Vector &);	// slot 28; seen as ViewSetupVis 1; shapes differ
	virtual int vfunc29();	// slot 29
	virtual int vfunc30();	// slot 30
	virtual int vfunc31();	// slot 31
	virtual void vfunc32(unsigned char *, void *);	// slot 32; shapes differ
	virtual int vfunc33();	// slot 33
	virtual int vfunc34();	// slot 34
	virtual bool vfunc35();	// slot 35; shapes differ
	virtual int vfunc36();	// slot 36
	virtual int vfunc37();	// slot 37
	virtual int vfunc38();	// slot 38
	virtual int vfunc39();	// slot 39
	virtual void vfunc40();
	virtual void vfunc41();
	virtual double vfunc42();	// slot 42
	virtual void vfunc43(int, int);	// slot 43; shapes differ
	virtual float vfunc44(int);	// slot 44
	virtual void vfunc45(const void *);	// slot 45
	virtual void vfunc46();
	virtual void vfunc47(const char *, float, float, float);	// slot 47
};
extern IVRenderView *g_104a57e4;

// debugoverlay = g_104a57e8, asked for as "VDebugOverlay002"
class IVDebugOverlay
{
public:
	virtual void __cdecl vfunc0(int, int, int, int, int, int, int, int);	// slot 0
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3();
	virtual void vfunc4();
	virtual void vfunc5(const Vector &, const Vector &, int, int, int, int, int);	// slot 5; seen as AddLineOverlay 1
	virtual int __cdecl vfunc6(int, int, int, int);	// slot 6
	virtual int __cdecl vfunc7(int, int, int);	// slot 7
	virtual void __cdecl vfunc8(int, int, int, int, int, int, int, int);	// slot 8
	virtual void vfunc9();
	virtual void vfunc10();
	virtual int vfunc11();	// slot 11
};
extern IVDebugOverlay *g_104a57e8;

// materials = g_104a57ec, asked for as "VMaterialSystem074"
class IMaterialSystem
{
public:
	virtual int vfunc0();	// slot 0
	virtual int vfunc1();	// slot 1
	virtual void *vfunc2(int);	// slot 2
	virtual void vfunc3();
	virtual void vfunc4();
	virtual void vfunc5();
	virtual void vfunc6();
	virtual void vfunc7();
	virtual void vfunc8();
	virtual void vfunc9();
	virtual void vfunc10();
	virtual void *vfunc11(const char *, bool *, bool);	// slot 11; seen as FindVar 1
	virtual void vfunc12();
	virtual void vfunc13();
	virtual void vfunc14();
	virtual void vfunc15();
	virtual void vfunc16();
	virtual void vfunc17();
	virtual void vfunc18();
	virtual void vfunc19();
	virtual void vfunc20();
	virtual void vfunc21();
	virtual void vfunc22();
	virtual void vfunc23();
	virtual void vfunc24();
	virtual void *FindMaterial(const char *, bool *, bool);	// slot 25; shapes differ
	virtual void vfunc26();
	virtual void vfunc27();
	virtual void *FindTexture(const char *, const char *, int);	// slot 28
	virtual void vfunc29();
	virtual void vfunc30();
	virtual void vfunc31();
	virtual void vfunc32();
	virtual void vfunc33();
	virtual void vfunc34();
	virtual void vfunc35();
	virtual void vfunc36(int *, int *);	// slot 36
	virtual void vfunc37();
	virtual void vfunc38();
	virtual void vfunc39();
	virtual void vfunc40(void *);	// slot 40
	virtual void vfunc41();
	virtual void vfunc42();
	virtual void vfunc43();
	virtual void vfunc44();
	virtual void vfunc45();
	virtual void vfunc46();
	virtual void vfunc47();
	virtual void vfunc48();
	virtual void vfunc49();
	virtual void vfunc50();
	virtual void vfunc51();
	virtual void vfunc52();
	virtual void Bind(const void *, void *);	// slot 53; shapes differ
	virtual void vfunc54();
	virtual void vfunc55();
	virtual void vfunc56();
	virtual void vfunc57();
	virtual void vfunc58();
	virtual void vfunc59();
	virtual void vfunc60();
	virtual void vfunc61(int);	// slot 61
	virtual void vfunc62(int, int);	// slot 62; shapes differ
	virtual void vfunc63();
	virtual int vfunc64(int);	// slot 64; shapes differ
	virtual void vfunc65(int);	// slot 65; shapes differ
	virtual void vfunc66();
	virtual void vfunc67();
	virtual void vfunc68();
	virtual void vfunc69();
	virtual void vfunc70();
	virtual void vfunc71();
	virtual void vfunc72();
	virtual void vfunc73();
	virtual void vfunc74();
	virtual void vfunc75();
	virtual void vfunc76();
	virtual void vfunc77();
	virtual void vfunc78();
	virtual void vfunc79();
	virtual void vfunc80();
	virtual void vfunc81();
	virtual void vfunc82();
	virtual void vfunc83();
	virtual void vfunc84();
	virtual void vfunc85();
	virtual void vfunc86();
	virtual void vfunc87();
	virtual void vfunc88();
	virtual void vfunc89();
	virtual void vfunc90();
	virtual void vfunc91();
	virtual void vfunc92();
	virtual void vfunc93();
	virtual void vfunc94(int);	// slot 94; seen as FogMode 1
	virtual void vfunc95(float);	// slot 95; seen as FogStart 1
	virtual void vfunc96(float);	// slot 96; seen as FogEnd 1
	virtual void vfunc97();
	virtual int vfunc98();	// slot 98
	virtual void vfunc99();
	virtual void vfunc100(const float *);	// slot 100; seen as FogColor3fv 1
	virtual void vfunc101();
	virtual void vfunc102();
	virtual void vfunc103();
	virtual void vfunc104();
	virtual void vfunc105();
	virtual void vfunc106();
	virtual void vfunc107();
	virtual void vfunc108();
	virtual void vfunc109();
	virtual void vfunc110();
	virtual void *GetDynamicMesh(bool, const void *, const void *, const void *);	// slot 111
	virtual void vfunc112();
	virtual void vfunc113();
	virtual void vfunc114();
	virtual void vfunc115();
	virtual void vfunc116();
	virtual void vfunc117();
	virtual void vfunc118();
	virtual void vfunc119();
	virtual void AddRestoreFunc(int);	// slot 120; shapes differ
	virtual void vfunc121();
	virtual void vfunc122();
	virtual void vfunc123();
	virtual void vfunc124();
	virtual void vfunc125();
	virtual void vfunc126();
	virtual void vfunc127();
	virtual void *vfunc128(int, int, int);	// slot 128; shapes differ
	virtual void vfunc129();
	virtual void vfunc130();
	virtual void vfunc131();
	virtual void vfunc132();
	virtual void vfunc133();
	virtual void vfunc134();
	virtual void vfunc135();
	virtual void vfunc136(void *);	// slot 136
};
extern IMaterialSystem *g_104a57ec;

// g_pMaterialSystemHardwareConfig = g_104a57f0, asked for as "MaterialSystemHardwareConfig010"
class IMaterialSystemHardwareConfig
{
public:
	virtual void vfunc0();
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3();
	virtual void vfunc4();
	virtual void vfunc5();
	virtual void vfunc6();
	virtual void vfunc7();
	virtual void vfunc8();
	virtual void vfunc9();
	virtual bool vfunc10();	// slot 10
};
extern IMaterialSystemHardwareConfig *g_104a57f0;

// engineCache = g_104a57f4, asked for as "VEngineCache001"
class IVEngineCache
{
public:
	virtual void vfunc0();
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3();
	virtual void vfunc4();	// seen as Enter 1
	virtual void vfunc5();	// seen as Exit 1
	virtual void vfunc6();
};
extern IVEngineCache *g_104a57f4;

// modelinfo = g_104a57f8, asked for as "VModelInfoClient001"
class IVModelInfoClient
{
public:
	virtual void vfunc0();
	virtual const char *GetModelName(const void *);	// slot 1; shapes differ
	virtual void *GetModel(int);	// slot 2
	virtual void vfunc3(int, float *, float *);	// slot 3; seen as GetBounds 1
	virtual void vfunc4(void *, int, Vector *, Vector *);	// slot 4
	virtual int GetModelFrameCount(const void *);	// slot 5
	virtual int GetModelType(const void *);	// slot 6; shapes differ
	virtual CSpriteHandle *vfunc7(const void *);	// slot 7; seen as GetSprite 1 (GetModelExtraData: a sprite model's CEngineSprite)
	virtual bool IsTranslucent(const void *);	// slot 8
	virtual bool vfunc9(int);	// slot 9; seen as IsTranslucent 1
	virtual bool vfunc10(const void *);	// slot 10; seen as IsModelTwoPass 1
	virtual void vfunc11(void *);	// slot 11; seen as RecomputeTranslucency 1
	virtual int GetModelIndex(const char *);	// slot 12
	virtual void vfunc13();
	virtual void vfunc14();
	virtual void vfunc15();
	virtual bool vfunc16(void *);	// slot 16; seen as IsModelVertexLit 1
	virtual void vfunc17();
	virtual void *vfunc18(int);	// slot 18; seen as GetVCollide 1
	virtual void vfunc19();
	virtual void *vfunc20(const void *);	// slot 20; seen as GetStudiomodel 1
};
extern IVModelInfoClient *g_104a57f8;

// enginevgui = g_104a57fc, asked for as "VEngineVGui001"
class IEngineVGui
{
public:
	virtual void vfunc0(int);	// slot 0
	virtual int vfunc1(int);	// slot 1
	virtual void vfunc2(int);	// slot 2
	virtual void vfunc3(int);	// slot 3
	virtual void vfunc4(int);	// slot 4
};
extern IEngineVGui *g_104a57fc;

// netgraph = g_104a5800, asked for as "VNETGRAPH001"
class INetGraph
{
public:
	virtual int vfunc0();	// slot 0; seen as GetOutgoingSequence 1
	virtual int vfunc1();	// slot 1; seen as GetIncomingSequence 1
	virtual int vfunc2();	// slot 2
	virtual int vfunc3();	// slot 3
	virtual int vfunc4();	// slot 4
	virtual int vfunc5();	// slot 5
	virtual int vfunc6();	// slot 6
	virtual int vfunc7();	// slot 7
	virtual void vfunc8(float *, float *);	// slot 8; seen as GetAverageDataFlow 1; shapes differ
	virtual float vfunc9(int);	// slot 9
	virtual char vfunc10(int);	// slot 10
	virtual int vfunc11(int);	// slot 11
};
extern INetGraph *g_104a5800;

// networkstringtable = g_104a5804, asked for as "VEngineClientStringTable001"
class INetworkStringTableClient
{
public:
	virtual void *vfunc0(const char *);	// slot 0
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3();
	virtual void vfunc4();
	virtual void vfunc5();
	virtual void vfunc6(int, void *, int, int, int, int);	// slot 6
};
extern INetworkStringTableClient *g_104a5804;

// partition = g_104a5808, asked for as "SpatialPartition001"
class ISpatialPartition
{
public:
	virtual void vfunc0();
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3(unsigned short);	// slot 3
	virtual void vfunc4();
	virtual void vfunc5();
	virtual void vfunc6();
	virtual void vfunc7();
	virtual void vfunc8();
	virtual void vfunc9();
	virtual void vfunc10();
	virtual void vfunc11(void *);	// slot 11
	virtual void vfunc12();
	virtual void vfunc13(int, Vector *, float, int, void *, int);	// slot 13
	virtual void vfunc14(int, const Ray_t &, bool, void *);	// slot 14; seen as EnumerateElementsAlongRay 1
	virtual void vfunc15(int, const Vector &, int, CWaterEnum *);	// slot 15; seen as Enum 1
	virtual void vfunc16(int, int);	// slot 16
};
extern ISpatialPartition *g_104a5808;

// filesystem = g_104a580c, asked for as "VFileSystem005"
class IFileSystem
{
public:
	virtual int Open(const char *, const char *, const char *);	// slot 0; shapes differ
	virtual void Close(int);	// slot 1; shapes differ
	virtual int vfunc2(void *, int, int);	// slot 2; seen as Read 1
	virtual int vfunc3();	// slot 3
	virtual void vfunc4(int, int, int);	// slot 4; seen as Seek 1
	virtual unsigned int vfunc5(int);	// slot 5; seen as Tell 1
	virtual int vfunc6(int);	// slot 6
	virtual void vfunc7();
	virtual void vfunc8();
	virtual bool FileExists(const char *, const char *);	// slot 9
	virtual void vfunc10();
	virtual void vfunc11();
	virtual void vfunc12();
	virtual void vfunc13();
	virtual void vfunc14();
	virtual void vfunc15();
	virtual void vfunc16();
	virtual void vfunc17();
	virtual void vfunc18();
	virtual void vfunc19();
	virtual char *vfunc20(char *, int, int);	// slot 20; seen as ReadLine 1
	virtual int vfunc21(void *, const char *, ...);	// slot 21; seen as FPrintf 1
	virtual int FindFirst(const char *, int *);	// slot 22; shapes differ
	virtual int FindNext(int);	// slot 23; shapes differ
	virtual void vfunc24();
	virtual void FindClose(int);	// slot 25
};
extern IFileSystem *g_104a580c;

// shadowmgr = g_104a5810, asked for as "VEngineShadowMgr001"
class IShadowMgr
{
public:
	virtual void vfunc0();
	virtual void vfunc1();
	virtual void vfunc2(unsigned short, const Vector &, const Vector &, const VMatrix &, void *, float, float);	// slot 2; seen as ProjectShadow 1
	virtual int vfunc3(unsigned short);	// slot 3
	virtual void vfunc4();
	virtual void vfunc5();
	virtual void vfunc6();
	virtual void vfunc7();
	virtual void vfunc8();
	virtual void vfunc9();
	virtual void vfunc10();
	virtual void vfunc11(unsigned short, const Vector &);	// slot 11; seen as SetShadowColor 1
};
extern IShadowMgr *g_104a5810;

// staticpropmgr = g_104a5814, asked for as "StaticPropMgrClient001"
class IStaticPropMgrClient
{
public:
	virtual void vfunc0(const void *, void *, int);	// slot 0
	virtual bool vfunc1();	// slot 1; seen as IsX 1
	virtual void vfunc2();
	virtual bool vfunc3(void *);	// slot 3
};
extern IStaticPropMgrClient *g_104a5814;

// enginesound = g_104a5818, asked for as "IEngineSoundClient003"
class IEngineSound
{
public:
	virtual void vfunc0(const char *, int);	// slot 0; seen as Precache 1; shapes differ
	virtual float vfunc1(const char *);	// slot 1; seen as GetSoundDuration 1; shapes differ
	virtual void vfunc2(IRecipientFilter &, int, int, const char *, float, int, int, int, const Vector *, int, int, int);	// slot 2; seen as EmitSound 1
	virtual void EmitSound(IRecipientFilter &, int, int, const char *, float, int, int, int, int, int, int, int);	// slot 3; shapes differ
	virtual void vfunc4();
	virtual void vfunc5();
	virtual void vfunc6();
	virtual void vfunc7(int, int, const char *);	// slot 7; seen as EmitAmbient 1
	virtual void vfunc8();
	virtual void vfunc9();
	virtual void vfunc10(int, int, int, int, int);	// slot 10; seen as EmitAmbientSound 1; shapes differ
	virtual void vfunc11();
	virtual void vfunc12();
	virtual void vfunc13();
	virtual void vfunc14();
	virtual void vfunc15();
	virtual void vfunc16();
	virtual void vfunc17();
	virtual void vfunc18();
	virtual void vfunc19();
	virtual void vfunc20();
	virtual void vfunc21();
	virtual void vfunc22();
	virtual void vfunc23();
	virtual bool vfunc24();	// slot 24
	virtual bool vfunc25();	// slot 25
	virtual bool vfunc26();	// slot 26
};
extern IEngineSound *g_104a5818;

// enginerandom = g_104a5738, asked for as "VEngineRandom001"
class IUniformRandomStream
{
public:
	virtual void SetSeed(int);	// slot 0
	virtual float RandomFloat(float, float);	// slot 1
	virtual int RandomInt(int, int);	// slot 2
};
extern IUniformRandomStream *g_104a5738;

// g_pMatSystemSurface = g_104a5820, asked for as "MatSystemSurface001"
class IMatSystemSurface
{
public:
	virtual void vfunc0();
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3();
	virtual void vfunc4();
	virtual void vfunc5();
	virtual void vfunc6();
	virtual void vfunc7();
	virtual void vfunc8();
	virtual void vfunc9();
	virtual void vfunc10();
	virtual void vfunc11();
	virtual void __cdecl vfunc12(int, int, int, ...);	// slot 12; seen as Draw 1; DrawColoredText(font, x, y, r, g, b, a, fmt, ...)
	virtual void vfunc13();
	virtual void vfunc14();
	virtual int vfunc15(int, const char *, ...);	// slot 15; seen as DrawTextLen 1
};
extern IMatSystemSurface *g_104a5820;

// physics = g_104e0c84, asked for as "VPhysics030"
class IPhysics
{
public:
	virtual void *vfunc0();	// slot 0
	virtual void vfunc1(void *);	// slot 1
	virtual void vfunc2();
	virtual int vfunc3();	// slot 3
	virtual void vfunc4(void *);	// slot 4
};
extern IPhysics *g_104e0c84;

// physcollision = g_104e0c8c, asked for as "VPhysicsCollision007"
class IPhysicsCollision
{
public:
	virtual void vfunc0();
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3();
	virtual void vfunc4();
	virtual void vfunc5();
	virtual void vfunc6();
	virtual void vfunc7();
	virtual void vfunc8();
	virtual void vfunc9();
	virtual void vfunc10();
	virtual void vfunc11();
	virtual void vfunc12();
	virtual void vfunc13();
	virtual void vfunc14();
	virtual void vfunc15();
	virtual void vfunc16();
	virtual void vfunc17();
	virtual void vfunc18(Vector &, Vector &, const void *, const Vector &, const QAngle &);	// slot 18; seen as CollideGetAABB 1
	virtual void vfunc19();
	virtual void vfunc20();
	virtual void vfunc21();
	virtual void vfunc22();
	virtual void vfunc23();
	virtual void vfunc24();
	virtual void vfunc25();
	virtual void *vfunc26(int);	// slot 26
	virtual void vfunc27(const void *);	// slot 27
};
extern IPhysicsCollision *g_104e0c8c;

// physprops = g_104e0c94, asked for as "VPhysicsSurfaceProps001"
class IPhysicsSurfaceProps
{
public:
	virtual void vfunc0();
	virtual void vfunc1();
	virtual void vfunc2();
	virtual int vfunc3(const char *);	// slot 3: GetSurfaceIndex
	virtual void vfunc4();
	virtual void *vfunc5(int);	// slot 5; seen as GetSurfaceData 1
	virtual const char *vfunc6(unsigned short);	// slot 6: GetString
};
extern IPhysicsSurfaceProps *g_104e0c94;

}  // namespace EngineGlobals

#define engine EngineGlobals::g_104a57d4
#define modelrender EngineGlobals::g_104a57d8
#define effects EngineGlobals::g_104a57dc
#define cvar EngineGlobals::g_104a57e0
#define enginetrace EngineGlobals::g_104a582c
#define render EngineGlobals::g_104a57e4
#define debugoverlay EngineGlobals::g_104a57e8
#define materials EngineGlobals::g_104a57ec
#define g_pMaterialSystemHardwareConfig EngineGlobals::g_104a57f0
#define engineCache EngineGlobals::g_104a57f4
#define modelinfo EngineGlobals::g_104a57f8
#define enginevgui EngineGlobals::g_104a57fc
#define netgraph EngineGlobals::g_104a5800
#define networkstringtable EngineGlobals::g_104a5804
#define partition EngineGlobals::g_104a5808
#define filesystem EngineGlobals::g_104a580c
#define shadowmgr EngineGlobals::g_104a5810
#define staticpropmgr EngineGlobals::g_104a5814
#define enginesound EngineGlobals::g_104a5818
#define enginerandom EngineGlobals::g_104a5738
#define g_pMatSystemSurface EngineGlobals::g_104a5820
#define physics EngineGlobals::g_104e0c84
#define physcollision EngineGlobals::g_104e0c8c
#define physprops EngineGlobals::g_104e0c94
