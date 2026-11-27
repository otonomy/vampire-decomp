// C_BaseEntity: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its overrides of IHandleEntity::vfunc0 and IHandleEntity::vfunc1, its destructor, its operator delete, the client entity interfaces' slots it fills (client entity layer, 2026-11-22), the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; its overrides are declared, the other virtual functions before it are not yet
#pragma once
#include "IClientEntity.h"
class IPhysicsObject;
struct CGameTrace;

class C_BaseEntity : public IClientEntity
{
public:
	C_BaseEntity();
	bool sub_1011c5c0();
	void sub_1009e150();
	void sub_1011b9a0();
	struct TouchLink *sub_1011b440(int type);
	void sub_100a26e0();
	void sub_100af040();
	void sub_100a2580();
	void sub_100a2610(bool flag, int a);
	void sub_1011d190(float frametime);
	bool sub_100a0d10();
	bool sub_100a1b20();
	void sub_100a2850(Vector *mins, Vector *maxs);
	void sub_100a2480(const Vector &origin);
	void sub_1007e180(int a, int b);
	void sub_100a2260(const Vector &origin);
	void sub_1007e100();
	void sub_100a2970(C_BaseEntity *p);
	void sub_1007eb60();
	void sub_100a2220(Vector v);
	void sub_1009f6c0(int, float);
	void sub_1007e040();
	void sub_100a2850(const Vector *mins, const Vector *maxs);
	void sub_100a10b0(int a);
	void sub_100a2930();
	bool sub_100a2600();
	void sub_1009fc60(int a, int b);
	void sub_100a1110();
	int sub_100a2450();
	void sub_1011bd60(C_BaseEntity *other);
	void sub_1011c480(C_BaseEntity *other, CGameTrace &trace);
	void sub_1011c1b0(C_BaseEntity *other, CGameTrace &trace);
	int *sub_1011be90(C_BaseEntity *other);
	void sub_1011c310(C_BaseEntity *other, CGameTrace &trace);
	void sub_1011bdf0(C_BaseEntity *other);
	bool sub_1011b290(int type);
	void sub_1011b320(int type);
	void sub_1011b3b0(int type);
	void sub_1011b890();
	void sub_1011b730(int type);
	void sub_100a2ee0();
	void sub_100a25b0();
	void sub_100a2e90(int);
	void sub_100a0650(const char *context);
	bool sub_100a29a0();
	void sub_100a2e40(int);
	void sub_100a25f0(int);
	void sub_100a2760(int, int);
	void sub_100a2f50();
	int sub_100a31e0(void *pDataMap);
	void sub_100a0450();
	void sub_1009e2d0(int bForce);	// UpdateShadows
	void sub_100a02e0(bool force);
	char *sub_1009f760();
	char *sub_1009f770();
	void *sub_100a2d70();
	void sub_100a1a70(int a);
	bool sub_1009e0f0(int a, int b);
	void sub_1009f8a0();
	void sub_1009fa70();
	void sub_1009f780();
	float sub_1009f190();
	void *sub_1009f7f0(void *);
	void sub_1011c7f0();
	bool sub_1009f140(int mask);
	bool sub_100a1140();
	C_BaseEntity *sub_100a11a0();
	void sub_1011ac90(void (C_BaseEntity::*thinkFunc)(), int a, int b);	// PhysicsDispatchThink: the two trailing ints are the rest of the 16-byte member pointer
	void sub_100a2030(const void *);
	bool sub_100a29b0(int);
	void sub_100a36e0();
	void sub_100a2100(const QAngle &absAngles);
	bool sub_100a0710(const char *name);
	void sub_1009f680(int i, float v);	// stores v in the float array at +0x23c (the absolute origin)
	void sub_1009f2e0(int a, int b);
	void sub_1011a950();
	void sub_1011a5f0(const Vector &start, const Vector &move, CGameTrace &trace);
	void sub_1011cf40();
	void sub_1011cbd0(CGameTrace &trace, Vector &move);
	void sub_1011d250();
	void sub_1011c9a0(Vector &move);
	int sub_1011cac0(Vector &in, const Vector &normal, Vector &out, float overbounce);
	void sub_100a23f0(int flag);
	void sub_100a1ce0(struct Ray_t &ray, const Vector &center, int decal, bool doTrace, CGameTrace &tr, int lod);
	void sub_100a1b40(struct Ray_t &ray, int hitbox, int decal, bool doTrace, CGameTrace &tr, int lod);
	void sub_100a1d60(const Vector &start, const Vector &pos, const Vector &dir, int hitbox, int decal, bool, CGameTrace &tr, int);	// AddDecal (TE_Decal)
	virtual ICollideable *GetClientCollideable();	// IClientUnknown slot 2
	virtual IClientNetworkable *GetClientNetworkable();	// IClientUnknown slot 3
	virtual IClientRenderable *GetClientRenderable();	// IClientUnknown slot 4
	virtual IClientEntity *GetIClientEntity();	// IClientUnknown slot 5
	virtual C_BaseEntity *GetBaseEntity();	// IClientUnknown slot 6
	virtual IClientThinkable *GetClientThinkable();	// IClientUnknown slot 7
	virtual const Vector &GetAbsOrigin() const;	// IClientEntity slot 9
	virtual const QAngle &GetAbsAngles() const;	// IClientEntity slot 10
	virtual const Vector &vfunc11();	// IClientEntity slot 11
	virtual CMouthInfo *GetMouth();	// IClientEntity slot 12
	virtual bool GetSoundSpatialization(SpatializationInfo_t &info);	// IClientEntity slot 13
	virtual IClientUnknown *GetIClientUnknown();	// IClientRenderable slot 0, IClientNetworkable slot 0
	virtual const Vector &GetRenderOrigin();	// IClientRenderable slot 1
	virtual const QAngle &GetRenderAngles();	// IClientRenderable slot 2
	virtual bool ShouldDraw();	// IClientRenderable slot 3
	virtual bool IsTransparent();	// IClientRenderable slot 4
	virtual bool UsesFrameBufferTexture();	// IClientRenderable slot 5
	virtual bool Renderable_vfunc6();	// IClientRenderable slot 6
	virtual const model_t *GetModel();	// IClientRenderable slot 8
	virtual int DrawModel(int flags, int a1);	// IClientRenderable slot 9
	virtual int Renderable_vfunc10(int a0, int a1);	// IClientRenderable slot 10
	virtual int ComputeFxBlend();	// IClientRenderable slot 11
	virtual int GetFxBlend();	// IClientRenderable slot 12
	virtual void GetColorModulation(float *color);	// IClientRenderable slot 13
	virtual bool LODTest();	// IClientRenderable slot 14
	virtual bool SetupBones(matrix3x4_t *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime, int a4);	// IClientRenderable slot 15
	virtual void SetupWeights();	// IClientRenderable slot 16
	virtual void DoAnimationEvents();	// IClientRenderable slot 17
	virtual void GetRenderBounds(Vector &mins, Vector &maxs);	// IClientRenderable slot 18
	virtual void GetRenderBoundsWorldspace(Vector &mins, Vector &maxs);	// IClientRenderable slot 19
	virtual bool Renderable_vfunc20();	// IClientRenderable slot 20
	virtual void Release();	// IClientNetworkable slot 1, IClientThinkable slot 3
	virtual ClientClass *GetClientClass();	// IClientNetworkable slot 2
	virtual void NotifyShouldTransmit(int state);	// IClientNetworkable slot 3
	virtual void OnPreDataChanged(int updateType);	// IClientNetworkable slot 4
	virtual void OnDataChanged(int updateType);	// IClientNetworkable slot 5
	virtual void PreDataUpdate(int updateType);	// IClientNetworkable slot 6
	virtual void PostDataUpdate(int updateType);	// IClientNetworkable slot 7
	virtual bool IsDormant();	// IClientNetworkable slot 8
	virtual int entindex();	// IClientNetworkable slot 9
	virtual void ReceiveMessage(int classID, bf_read &msg);	// IClientNetworkable slot 10
	virtual void *GetDataTableBasePtr();	// IClientNetworkable slot 11
	virtual bool Collideable_vfunc0(int a0, int a1, int a2);	// IClientCollideable slot 0
	virtual void Collideable_vfunc1(int a0, int a1);	// IClientCollideable slot 1
	virtual int GetCollisionModelIndex();	// IClientCollideable slot 2
	virtual const model_t *GetCollisionModel();	// IClientCollideable slot 3
	virtual const Vector &GetCollisionOrigin();	// IClientCollideable slot 4
	virtual const QAngle &GetCollisionAngles();	// IClientCollideable slot 5
	virtual int Collideable_vfunc6();	// IClientCollideable slot 6
	virtual int Collideable_vfunc7();	// IClientCollideable slot 7
	virtual int GetSolid();	// IClientCollideable slot 8
	virtual int GetSolidFlags();	// IClientCollideable slot 9
	virtual bool Collideable_vfunc10();	// IClientCollideable slot 10
	virtual bool Collideable_vfunc11();	// IClientCollideable slot 11
	virtual int GetCollisionGroup();	// IClientCollideable slot 12
	virtual int Collideable_vfunc13();	// IClientCollideable slot 13
	virtual void ClientThink();	// IClientThinkable slot 0
	virtual void *GetThinkHandle();	// IClientThinkable slot 1
	virtual void SetThinkHandle(void *hThink);	// IClientThinkable slot 2
	virtual int vfunc0(int a0);	// overrides IHandleEntity::vfunc0, pure there; C_BaseEntity has a vtable of its own in the game
	virtual unsigned int *vfunc1();	// overrides IHandleEntity::vfunc1, pure there; C_BaseEntity has a vtable of its own in the game
	virtual ~C_BaseEntity();
	static void operator delete(void *pMem);
	static void *operator new(size_t stAllocateBlock);
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the slots C_BaseEntity adds to its base's vtable: 14-119, vfuncK at slot K
	virtual int vfunc14();
	virtual int vfunc15();
	virtual int vfunc16();
	virtual int vfunc17();
	virtual bool vfunc18();
	virtual void vfunc19();
	virtual void vfunc20();
	virtual void vfunc21();
	virtual bool Init(int entnum, int iSerialNum);
	virtual Vector vfunc23();
	virtual int vfunc24();
	virtual bool vfunc25(int);
	virtual int vfunc26();
	virtual bool vfunc27(int, int, int);
	virtual float vfunc28();
	virtual void vfunc29(char);
	virtual int vfunc30();
	virtual int vfunc31(int);
	virtual int vfunc32();
	virtual void vfunc33();
	virtual int vfunc34();
	virtual int vfunc35(int);
	virtual int vfunc36(int);
	virtual void vfunc37();
	virtual void vfunc38(int, int);
	virtual char * vfunc39();
	virtual void vfunc40(char *);
	virtual char * vfunc41();
	virtual void vfunc42(char *);
	virtual char * vfunc43();
	virtual int vfunc44(int);
	virtual char * vfunc45();
	virtual int vfunc46(int);
	virtual int vfunc47(int);
	virtual int vfunc48(int);
	virtual int vfunc49(int);
	virtual int vfunc50(int);
	virtual int vfunc51();
	virtual const Vector &vfunc52();
	virtual const Vector &vfunc53();
	virtual char * vfunc54();
	virtual int vfunc55(int);
	virtual const Vector &vfunc56();
	virtual bool vfunc57(int, int, int);
	virtual bool vfunc58();
	virtual int vfunc59();
	virtual void vfunc60(int, int);
	virtual void vfunc61();
	virtual int vfunc62();
	virtual int vfunc63();
	virtual int vfunc64(int, int, int);
	virtual bool vfunc65(int, int);
	virtual int vfunc66();
	virtual bool vfunc67();
	virtual void vfunc68(bool);
	virtual void vfunc69();
	virtual int vfunc70();
	virtual bool vfunc71();
	virtual int vfunc72();
	virtual bool vfunc73();
	virtual bool vfunc74();
	virtual bool vfunc75();
	virtual void vfunc76();
	virtual void vfunc77();
	virtual void vfunc78();
	virtual bool vfunc79();
	virtual int vfunc80(int flags);
	virtual float vfunc81();
	virtual void vfunc82();
	virtual void vfunc83(float);
	virtual int vfunc84();
	virtual int vfunc85();
	virtual int vfunc86();
	virtual bool vfunc87();
	virtual void vfunc88();
	virtual void vfunc89(IPhysicsObject *pPhysics);
	virtual void vfunc90();
	virtual int vfunc91(int, int);
	virtual void vfunc92(int, int);
	virtual void vfunc93(int, int, int);
	virtual bool vfunc94();
	virtual void vfunc95();
	virtual void vfunc96(int, int, int, int);
	virtual void vfunc97(int);
	virtual bool vfunc98();
	virtual void vfunc99(int);
	virtual void vfunc100(int a);
	virtual void vfunc101(int);
	virtual int vfunc102();
	virtual void vfunc103(int);
	virtual C_BaseEntity *vfunc104();
	virtual CGameTrace vfunc105(const Vector &move);
	virtual bool vfunc106();
	virtual int vfunc107(int);
	virtual int vfunc108();
	virtual char * vfunc109();
	virtual int vfunc110(int);
	virtual void vfunc111();
	virtual void vfunc112();
	virtual bool vfunc113(bool isbeingremoved, C_BaseEntity *predicted);	// OnPredictedEntityRemove
	virtual char*vfunc114();
	virtual bool vfunc115();
	virtual bool vfunc116(int, int);
	virtual bool vfunc117(int);
	virtual void vfunc118(int);
	virtual void vfunc119(int);
};
