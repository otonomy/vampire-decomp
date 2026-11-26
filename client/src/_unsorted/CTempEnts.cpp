// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1003b530 size=0x36
#include "CTempEnts.h"

CTempEnts::CTempEnts()
{
	sub_1003cd80();
}
// END FUNCTION

// FUNCTION: 0x1003b570 size=0x1e
#include "CTempEnts.h"

// VC6 writes CTempEnts's scalar deleting destructor where it emits the class's vtable; `new` in a function
// nothing calls makes it emit both here
CTempEnts *pcd_emit_1003b570(const CTempEnts &other) { return new CTempEnts(other); }

// TARGET: ??_GCTempEnts@@UAEPAXI@Z
// END FUNCTION

// FUNCTION: 0x1003b590 size=0x37
#include "CTempEnts.h"
CTempEnts::~CTempEnts()
{
}
// END FUNCTION

// FUNCTION: 0x1003b5d0 size=0x27e
#include "Vector.h"
#include "QAngle.h"
#include "CTempEnts.h"

struct FizzModelInfo
{
	virtual void v0(); virtual void v1();
	virtual void *GetModel(int modelIndex);
	virtual void GetModelBounds(const void *model, Vector &mins, Vector &maxs);
	virtual void v4();
	virtual int GetModelFrameCount(const void *model);
};
extern FizzModelInfo *g_104a57f8;
struct FizzRandom
{
	virtual void v0();
	virtual float RandomFloat(float lo, float hi);
	virtual int RandomInt(int lo, int hi);
};
extern FizzRandom *g_104a5738;
struct FizzEngine
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
	virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
	virtual void v36(); virtual void v37(); virtual void v38();
	virtual float GetTime(int n);	// 39
};
extern FizzEngine *g_104a57d4;

struct FizzEnt
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual const QAngle &GetLocalAngles();	// 10
	char pad4[0x40 - 4];
	void *m_pModel;	// 0x40
	char pad44[0x50 - 0x44];
	unsigned char m_r, m_g, m_b, m_a;	// 0x50
};

struct TempEntView
{
	char pad0[0x48];
	int m_nRenderMode;	// 0x48
	char pad4c[0x53 - 0x4c];
	unsigned char m_alpha;	// 0x53
	char pad54[0x7ac - 0x54];
	int flags;	// 0x7ac
	float die;	// 0x7b0
	int m_7b4;
	float x;	// 0x7b8
	float y;	// 0x7bc
	char pad7c0[0x7f0 - 0x7c0];
	float m_flSpriteScale;	// 0x7f0
	int m_7f4, m_7f8;
	float m_flFrame;	// 0x7fc
};
struct CUnknown1003a840 { int sub_1003a840(int x, int y, int z); };

static inline void SinCos( float radians, float *sine, float *cosine )
{
	_asm
	{
		fld		DWORD PTR [radians]
		fsincos

		mov edx, DWORD PTR [cosine]
		mov eax, DWORD PTR [sine]

		fstp DWORD PTR [edx]
		fstp DWORD PTR [eax]
	}
}

void CTempEnts::vfunc11(C_BaseEntity *pEnt, int modelIndex, int density)
{
	FizzEnt *pent = (FizzEnt *)pEnt;
	TempEntView *pTemp;
	void *model;
	int i, width, depth, count, frameCount;
	float maxHeight, speed, xspeed, yspeed;
	Vector origin;
	Vector mins, maxs;

	if (!pent->m_pModel || !modelIndex)
		return;

	model = g_104a57f8->GetModel(modelIndex);
	if (!model)
		return;

	count = density + 1;

	g_104a57f8->GetModelBounds(model, mins, maxs);

	maxHeight = maxs.z - mins.z;
	width = maxs.x - mins.x;
	depth = maxs.y - mins.y;
	speed = pent->m_r * 256.0 + pent->m_g;
	if (pent->m_b)
		speed = -speed;

	float yaw = pent->GetLocalAngles().y * (3.14159265358979323846 / 180);
	SinCos(yaw, &yspeed, &xspeed);
	xspeed *= speed;
	yspeed *= speed;
	frameCount = g_104a57f8->GetModelFrameCount(model);

	for (i = 0; i < count; i++)
	{
		origin.x = mins.x + g_104a5738->RandomInt(0, width - 1);
		origin.y = mins.y + g_104a5738->RandomInt(0, depth - 1);
		origin.z = mins.z;
		pTemp = sub_1003cdd0(&origin, model);
		if (!pTemp)
			return;

		pTemp->flags |= 1;
		pTemp->x = origin.x;
		pTemp->y = origin.y;

		float zspeed = g_104a5738->RandomInt(80, 140);
		((CUnknown1003a840 *)pTemp)->sub_1003a840(*(int *)&xspeed, *(int *)&yspeed, *(int *)&zspeed);
		pTemp->die = g_104a57d4->GetTime(0) + (maxHeight / zspeed) - 0.1;
		pTemp->m_flFrame = g_104a5738->RandomInt(0, frameCount - 1);
		pTemp->m_flSpriteScale = 1.0 / g_104a5738->RandomFloat(2, 5);
		pTemp->m_nRenderMode = 4;
		pTemp->m_alpha = 255;
	}
}
// END FUNCTION

// FUNCTION: 0x1003b850 size=0x264
#include "CTempEnts.h"
#include "Vector.h"

struct model_t;

struct IVModelInfo_1003b850
{
	virtual void v0();
	virtual void v1();
	virtual const model_t *GetModel(int modelIndex);
	virtual void v3();
	virtual void v4();
	virtual int GetModelFrameCount(const model_t *model);
};

struct IUniformRandomStream_1003b850
{
	virtual void SetSeed(int iSeed);
	virtual float RandomFloat(float flMinVal, float flMaxVal);
	virtual int RandomInt(int iMinVal, int iMaxVal);
};

struct IVEngineClient_1003b850
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
	virtual void v36(); virtual void v37(); virtual void v38();
	virtual float Time(int);
};

struct LocalTempEnt_1003b850
{
	char pad_0[0x48];
	int m_nRenderMode;      // 0x48
	int m_nRenderFX;        // 0x4c
	unsigned char m_r, m_g, m_b, m_a;    // 0x50
	char pad_54[0x758];
	int flags;              // 0x7ac
	float die;              // 0x7b0
	char pad_7b4[4];
	float x;                // 0x7b8
	float y;                // 0x7bc
	char pad_7c0[0x30];
	float m_flSpriteScale;  // 0x7f0
	char pad_7f4[0x08];
	float m_flFrame;        // 0x7fc
	float vel[3];           // 0x800

	void sub_1003a840(float x, float y, float z);
};

struct CTempEnts_Helper_1003b850
{
	LocalTempEnt_1003b850 *sub_1003cdd0(const Vector &org, const model_t *pModel);
};

extern IVModelInfo_1003b850 *g_104a57f8;
extern IUniformRandomStream_1003b850 *g_104a5738;
extern IVEngineClient_1003b850 *g_104a57d4;

inline void SinCos( float radians, float *sine, float *cosine )
{
	_asm
	{
		fld		DWORD PTR [radians]
		fsincos

		mov edx, DWORD PTR [cosine]
		mov eax, DWORD PTR [sine]

		fstp DWORD PTR [edx]
		fstp DWORD PTR [eax]
	}
}

// TARGET: CTempEnts::vfunc8
void CTempEnts::vfunc8(const Vector &mins, const Vector &maxs, float height, int modelIndex, int count, float speed)
{
	LocalTempEnt_1003b850 *pTemp;
	const model_t *model;
	int i, frameCount;
	float sine, cosine, zspeed;
	Vector origin;

	if (!modelIndex)
		return;

	model = g_104a57f8->GetModel(modelIndex);
	if (!model)
		return;

	frameCount = g_104a57f8->GetModelFrameCount(model);

	for (i = 0; i < count; i++)
	{
		origin[0] = g_104a5738->RandomInt(mins[0], maxs[0]);
		origin[1] = g_104a5738->RandomInt(mins[1], maxs[1]);
		origin[2] = g_104a5738->RandomInt(mins[2], maxs[2]);
		pTemp = ((CTempEnts_Helper_1003b850 *)this)->sub_1003cdd0(origin, model);
		if (!pTemp)
			return;

		pTemp->flags |= 1;

		pTemp->x = origin[0];
		pTemp->y = origin[1];
		SinCos(g_104a5738->RandomInt(-3, 3), &sine, &cosine);

		zspeed = g_104a5738->RandomInt(80, 140);
		pTemp->sub_1003a840(speed * cosine, speed * sine, zspeed);
		pTemp->die = g_104a57d4->Time(0) + ((height - (origin[2] - mins[2])) / zspeed) - 0.1;
		pTemp->m_flFrame = g_104a5738->RandomInt(0, frameCount - 1);

		pTemp->m_flSpriteScale = 1.0 / g_104a5738->RandomFloat(4, 16);
		pTemp->m_nRenderMode = 4;
		pTemp->m_b = 255;
		pTemp->m_g = 255;
		pTemp->m_r = 255;
		pTemp->m_a = 192;
	}
}
// END FUNCTION

// FUNCTION: 0x1003bca0 size=0x38b
#include "CTempEnts.h"
#include "engineclient.h"
#include "Vector.h"

#define SHARD_VOLUME 12.0

struct CBreakTempView
{
	char m_pad0000[0x48];
	int m_nRenderMode;	// 0x48
	char m_pad004c[0x53 - 0x4c];
	unsigned char m_nRenderAlpha;	// 0x53
	char m_pad0054[0x560 - 0x54];
	int m_nBody;	// 0x560
	char m_pad0564[0x7ac - 0x564];
	int flags;	// 0x7ac
	float die;	// 0x7b0
	char m_pad07b4[0x7c8 - 0x7b4];
	int hitSound;	// 0x7c8
	char m_pad07cc[0x7e0 - 0x7cc];
	float m_vecTempEntAngVelocity[3];	// 0x7e0
	int tempent_renderamt;	// 0x7ec
	char m_pad07f0[0x7fc - 0x7f0];
	float m_flFrame;	// 0x7fc

	void sub_1003a840(float x, float y, float z);	// SetVelocity: the vector's three floats by value
};

void CTempEnts::vfunc7(const Vector &pos, const Vector &size, const Vector &dir, float randRange, float life, int count, int modelIndex, char flags)
{
	if (!modelIndex)
		return;

	char type = flags & 0x4f;

	void *pModel = modelinfo->GetModel(modelIndex);
	if (!pModel)
		return;

	int frameCount = modelinfo->GetModelFrameCount(pModel);

	if (count == 0)
		count = (int)(((size[1] + size[0]) * size[2] + size[1] * size[0]) / (3 * SHARD_VOLUME * SHARD_VOLUME));

	if (count > 100)
		count = 100;

	for (int i = 0; i < count; i++) {
		Vector vecSpot;
		vecSpot[0] = pos[0] + enginerandom->RandomFloat(-0.5f, 0.5f) * size[0];
		vecSpot[1] = pos[1] + enginerandom->RandomFloat(-0.5f, 0.5f) * size[1];
		vecSpot[2] = pos[2] + enginerandom->RandomFloat(-0.5f, 0.5f) * size[2];

		CBreakTempView *pTemp = (CBreakTempView *)sub_1003cdd0(&vecSpot, pModel);
		if (!pTemp)
			return;

		pTemp->hitSound = type;

		if (modelinfo->GetModelType(pModel) == 2) {
			pTemp->m_flFrame = enginerandom->RandomInt(0, frameCount - 1);
		} else if (modelinfo->GetModelType(pModel) == 3) {
			if (i < 33)
				pTemp->m_nBody = 0;
			else if (i < 66)
				pTemp->m_nBody = 1;
			else
				pTemp->m_nBody = 2;
			if (pTemp->m_nBody > frameCount)
				pTemp->m_nBody = frameCount;
		}

		pTemp->flags |= 0xa8;

		if (enginerandom->RandomInt(0, 255) < 200) {
			pTemp->flags |= 4;
			pTemp->m_vecTempEntAngVelocity[0] = enginerandom->RandomFloat(-256, 255);
			pTemp->m_vecTempEntAngVelocity[1] = enginerandom->RandomFloat(-256, 255);
			pTemp->m_vecTempEntAngVelocity[2] = enginerandom->RandomFloat(-256, 255);
		}

		if (enginerandom->RandomInt(0, 255) < 100 && (flags & 0x10))
			pTemp->flags |= 0x10;

		if (type == 1 || (flags & 0x20)) {
			pTemp->m_nRenderMode = 2;
			pTemp->m_nRenderAlpha = 128;
			pTemp->tempent_renderamt = 128;
		} else {
			pTemp->m_nRenderMode = 0;
			pTemp->tempent_renderamt = 255;
		}

		pTemp->sub_1003a840(dir[0] + enginerandom->RandomFloat(-randRange, randRange),
			dir[1] + enginerandom->RandomFloat(-randRange, randRange),
			dir[2] + enginerandom->RandomFloat(0, randRange));

		pTemp->die = engine->Time(0) + enginerandom->RandomFloat(0, 2) + life;
	}
}
// END FUNCTION

// FUNCTION: 0x1003c3e0 size=0x1e3
#include "CClientEntityList.h"
#include "CTempEnts.h"
#define D1(n) virtual void n(){}
#define D4(p) virtual void p##a(){} virtual void p##b(){} virtual void p##c(){} virtual void p##d(){}
#define D16(p) D4(p##1) D4(p##2) D4(p##3) D4(p##4)
__declspec(dllimport) void Warning(const char *, ...);
struct V3 { float x, y, z; V3() {} V3(const V3 &o) { x = o.x; y = o.y; z = o.z; } };
struct IEngC { D16(a) D16(b) D4(c) D1(c1) D1(c2) D1(c3) virtual float Time(int); D4(d) D4(e) D1(e1) D1(e2) D1(e3) virtual int GetMaxClients(); };
extern IEngC *g_104a57d4;
struct IMdl { D1(a) D1(b) virtual const void *GetModel(int); D1(c) D1(d) virtual int GetModelFrameCount(const void *); virtual int GetModelType(const void *); };
extern IMdl *g_104a57f8;
struct EntList { D1(a) D1(b) D1(c) virtual char *GetEntry(int); };
struct IUnk { D4(a) D1(b) virtual void *GetIClientEntity(); };
struct INet { virtual IUnk *GetUnk(); };
struct IEnt { D4(a) D4(b) D1(c) virtual const V3 &GetAbsOrigin(); };
struct TEv {
	char pad0[0x40]; const void *model; char pad44[4]; int renderMode; int renderFx; char pad50[3]; unsigned char colorA;
	char pad54[0x568 - 0x54]; float modelScale;
	char pad56c[0x7ac - 0x56c]; int flags; float die; float frameMax; char pad7b8[0x7d0 - 0x7b8];
	unsigned short clientIndex; char pad7d2[2]; float tentOffset[3]; char pad7e0[0x7ec - 0x7e0]; int renderamt;
	char pad7f0[0x7f8 - 0x7f0]; float frameRate; float frame;
};
// TARGET: CTempEnts::vfunc15
void CTempEnts::vfunc15(int client, int modelIndex, float zoffset, float life)
{
	if (client < 0 || client > g_104a57d4->GetMaxClients())
	{
		Warning("Bad client in AttachTentToPlayer()!\n");
		return;
	}
	char *pEntry = ((EntList *)(((char *)cl_entitylist) + 0x1803c))->GetEntry(client);
	INet *pNet = pEntry ? (INet *)(pEntry + 8) : 0;
	IEnt *clientClass = 0;
	if (pEntry && pNet)
		clientClass = (IEnt *)pNet->GetUnk()->GetIClientEntity();
	if (!clientClass)
	{
		Warning("Couldn't get IClientEntity for %i\n", client);
		return;
	}
	const void *pModel = g_104a57f8->GetModel(modelIndex);
	if (!pModel)
	{
		Warning("No model %d!\n", modelIndex);
		return;
	}
	V3 position(clientClass->GetAbsOrigin());
	position.z += zoffset;
	TEv *pTemp = (TEv *)sub_1003cf20(&position, pModel);
	if (!pTemp)
	{
		Warning("No temp ent.\n");
		return;
	}
	pTemp->renderMode = 0;
	pTemp->colorA = 255;
	pTemp->renderamt = 255;
	pTemp->renderFx = 0xe;
	pTemp->modelScale = 1;
	pTemp->clientIndex = client;
	pTemp->tentOffset[0] = 0;
	pTemp->tentOffset[1] = 0;
	pTemp->tentOffset[2] = zoffset;
	pTemp->die = g_104a57d4->Time(0) + life;
	pTemp->flags |= 0xa000;
	if (g_104a57f8->GetModelType(pTemp->model) == 2)
	{
		int frameCount = g_104a57f8->GetModelFrameCount(pModel);
		pTemp->frameMax = frameCount;
		pTemp->flags |= 0x10100;
		pTemp->frameRate = 10;
	}
	else
	{
		pTemp->frameMax = 0;
	}
	pTemp->frame = 0;
}
// END FUNCTION

// FUNCTION: 0x1003c5d0 size=0x75
#include "engineclient.h"
#include "CTempEnts.h"
extern "C" __declspec(dllimport) void Warning(const char *fmt, ...);
struct Tent_1003c5d0 {
	char pad[0x7a8];
	Tent_1003c5d0 *next;
	int flags;
	float die;
	char pad2[0x1c];
	short clientIndex;
};
void CTempEnts::vfunc16(int client)
{
	if (client < 0 || client > engine->GetMaxClients())
	{
		Warning("Bad client in KillAttachedTents()!\n");
		return;
	}
	Tent_1003c5d0 *pTemp = (Tent_1003c5d0 *)m_pHead;
	while (pTemp)
	{
		if (pTemp->flags & 0x8000)
		{
			if (pTemp->clientIndex == client)
				pTemp->die = (float)engine->Time(0);
		}
		pTemp = pTemp->next;
	}
}
// END FUNCTION

// FUNCTION: 0x1003c710 size=0x162
#include "CTempEnts.h"

struct color32
{
    unsigned char r, g, b, a;
};

struct model_t;

struct IVModelInfo_1003c710
{
    virtual void v0();
    virtual void v1();
    virtual const model_t *GetModel(int modelIndex);
    virtual void v3();
    virtual void v4();
    virtual int GetModelFrameCount(const model_t *model);
};

struct IUniformRandomStream_1003c710
{
    virtual void SetSeed(int iSeed);
    virtual float RandomFloat(float flMinVal, float flMaxVal);
    virtual int RandomInt(int iMinVal, int iMaxVal);
};

struct IVEngineClient_1003c710
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
    virtual void v36(); virtual void v37(); virtual void v38();
    virtual float Time(int);
};

struct LocalTempEnt_1003c710
{
    char pad_0[0x48];
    int m_nRenderMode;      // 0x48
    int m_nRenderFX;        // 0x4c
    color32 m_clrRender;    // 0x50
    char pad_54[0x758];
    int flags;              // 0x7ac
    float die;              // 0x7b0
    float m_flFrameMax;     // 0x7b4
    char pad_7b8[0x0c];
    int m_nField7c4;        // 0x7c4
    char pad_7c8[0x24];
    int m_nRenderAmt;       // 0x7ec
    float m_flSpriteScale;  // 0x7f0
    char pad_7f4[0x04];
    float m_flFrameRate;    // 0x7f8
    float m_flFrame;        // 0x7fc

    void sub_1003a840(float x, float y, float z);
    void sub_1009f6c0(int axis, float val);
};

struct CTempEnts_Helper
{
    LocalTempEnt_1003c710 *sub_1003cf20(const void *pos, const model_t *pModel);
};

extern IVModelInfo_1003c710 *g_104a57f8;
extern IUniformRandomStream_1003c710 *g_104a5738;
extern IVEngineClient_1003c710 *g_104a57d4;

void CTempEnts::vfunc4(const void *pos, int r, int g, int b, int a, int modelIndex, float flUnused, float flSize)
{
    if (!modelIndex)
        return;

    const model_t *pModel = g_104a57f8->GetModel(modelIndex);
    if (!pModel)
        return;

    int frameCount = g_104a57f8->GetModelFrameCount(pModel);

    color32 color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;

    LocalTempEnt_1003c710 *pTemp = ((CTempEnts_Helper *)this)->sub_1003cf20(pos, pModel);
    if (!pTemp)
        return;

    pTemp->m_nRenderMode = 2;
    pTemp->m_nRenderFX = 19;
    pTemp->m_flSpriteScale = g_104a5738->RandomFloat(flSize / 25.0f, flSize / 35.0f);
    pTemp->m_clrRender = color;
    pTemp->flags = 0x100;
    pTemp->m_nRenderAmt = pTemp->m_clrRender.a;
    pTemp->sub_1003a840(0.0f, 0.0f, 0.0f);

    pTemp->m_flFrameRate = (float)(frameCount * 4);
    float fFrameCount = (float)frameCount;
    pTemp->die = g_104a57d4->Time(0) + (fFrameCount / pTemp->m_flFrameRate);
    pTemp->m_flFrame = 0.0f;
    pTemp->m_flFrameMax = fFrameCount;
    pTemp->m_nField7c4 = 0;

    pTemp->sub_1009f6c0(2, (float)g_104a5738->RandomInt(0, 360));
}
// END FUNCTION

// FUNCTION: 0x1003c9b0 size=0x77
#include "engineclient.h"
#include "CTempEnts.h"

class CUnknown1003a840
{
public:
	void sub_1003a840(int, int, int);
};

struct CV1009f670
{
	float sub_1009f670(int);
};



void CTempEnts::vfunc13(C_LocalTempEntity *pEnt, int n)
{
	if (!pEnt)
		return;

	*(int *)((char *)pEnt + 0x48) = 4;
	*(int *)((char *)pEnt + 0x4c) = 0;
	((CUnknown1003a840 *)pEnt)->sub_1003a840(0, 0, 0x41f00000);

	int r = enginerandom->RandomInt(20, 35);
	((char *)pEnt)[0x50] = (char)r;
	((char *)pEnt)[0x51] = (char)r;
	((char *)pEnt)[0x52] = (char)r;
	((char *)pEnt)[0x53] = (char)0xff;

	float f = ((CV1009f670 *)pEnt)->sub_1009f670(2);
	pEnt->sub_1009f680(2, f + 20.0f);

	((int *)pEnt)[0x7ac / 4] = 0x200000;
	pEnt->m_unk7f0 = n;
}
// END FUNCTION

// FUNCTION: 0x1003ca30 size=0x260
#include "engineclient.h"
#include "CTempEnts.h"
#include "ConVar.h"
#include "Vector.h"
#include "QAngle.h"

struct model_t;



struct LocalTempEnt_1003ca30
{
	char pad_0[0x48];
	int m_nRenderMode;      // 0x48
	char pad_4c[0x514];
	int m_nBody;            // 0x560
	char pad_564[0x248];
	int flags;              // 0x7ac
	float die;              // 0x7b0
	char pad_7b4[0x14];
	int hitSound;           // 0x7c8
	char pad_7cc[0x14];
	float tempent_angles[3];// 0x7e0
	int m_nRenderAmt;       // 0x7ec

	void sub_100a2100(const QAngle &angles);
	void sub_1003a840(float x, float y, float z);
};

struct CTempEnts_Helper_1003ca30
{
	char pad_0[0xfbf78];
	const model_t *m_pShells[6];

	LocalTempEnt_1003ca30 *sub_1003cdd0(const Vector &org, model_t *model);
};

extern void sub_101090a0(const QAngle &angles, Vector *forward, Vector *right, Vector *up);

extern ConVar *g_102eec5c;
extern ConVar *g_105fb29c;

void CTempEnts::vfunc19(const Vector &pos1, const QAngle &angles, const QAngle &gunAngles, int type, const Vector &vel)
{
	if (g_102eec5c->vfunc1() || !g_102eec5c->m_nValue)
		return;

	if (g_105fb29c->vfunc1() || !g_105fb29c->m_nValue)
		return;

	if (type < 0 || type > 5)
		return;

	if (type == -1)
		return;

	const model_t *pModel = ((CTempEnts_Helper_1003ca30 *)this)->m_pShells[type];
	if (pModel == 0)
		return;

	LocalTempEnt_1003ca30 *pTemp = ((CTempEnts_Helper_1003ca30 *)this)->sub_1003cdd0(pos1, (model_t *)pModel);
	if (pTemp == 0)
		return;

	if (type == 2)
	{
		pTemp->hitSound = 0x80;
	}
	else if (type >= 3)
	{
		pTemp->hitSound = 0x1000;
	}
	else
	{
		pTemp->hitSound = 0x20;
	}

	pTemp->m_nBody = 0;
	pTemp->flags |= 0xa6;

	pTemp->tempent_angles[0] = enginerandom->RandomFloat(-256.0f, 255.0f);
	pTemp->tempent_angles[1] = enginerandom->RandomFloat(-256.0f, 255.0f);
	pTemp->tempent_angles[2] = enginerandom->RandomFloat(-256.0f, 255.0f);

	if (type >= 3)
	{
		pTemp->sub_100a2100(angles);
	}
	else
	{
		pTemp->sub_100a2100(gunAngles);
	}

	pTemp->m_nRenderMode = 0;
	pTemp->m_nRenderAmt = 255;

	Vector dir;
	sub_101090a0(angles, &dir, 0, 0);

	dir *= enginerandom->RandomFloat(150.0f, 200.0f);
	dir += vel;

	if (type >= 3)
	{
		pTemp->sub_1003a840(vel.x, vel.y, vel.z);
	}
	else
	{
		pTemp->sub_1003a840(
			dir[0] + enginerandom->RandomFloat(-64.0f, 64.0f),
			dir[1] + enginerandom->RandomFloat(-64.0f, 64.0f),
			dir[2] + enginerandom->RandomFloat(0.0f, 64.0f));
	}

	pTemp->die = enginerandom->RandomFloat(0.0f, 1.0f) + engine->Time(0) + 5.0;
}
// END FUNCTION

// FUNCTION: 0x1003cc90 size=0x39
#include "CTempEnts.h"
namespace lifted {
struct V { virtual void u0(); virtual void u1(); virtual void u2(); virtual void u3(); virtual void u4(); virtual void u5(); virtual void u6(); virtual void u7(); virtual void u8(); virtual void u9(); virtual void u10(); virtual void u11(); virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15(); virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19(); virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23(); virtual void u24(); virtual int f25(int, int, int, int, int, int, int); virtual int f26(int, int, int, int, int, int, int); };
}
int CTempEnts::vfunc6(int a0, int a1, int a2, int a3, char a4, int a5, int a6, int a7, int a8)
{
    if (a4 != 0) {
        return ((lifted::V *)this)->f25(a0, a1, a3, a5, a6, a7, a8);
    }
    return ((lifted::V *)this)->f26(a0, a1, a3, a5, a6, a7, a8);
}
// END FUNCTION

// FUNCTION: 0x1003ccd0 size=0xb0
#include "engineclient.h"
#include "CTempEnts.h"
struct CVAll
{
	void sub_1003a840(int, int, int);
	void sub_1009f6c0(int, float);
	void sub_1009f680(int, float);
};
float __stdcall sub_1009f670(int);
// TARGET: CTempEnts::vfunc10
void CTempEnts::vfunc10(C_LocalTempEntity *pEnt, int n, int flags)
{
	if (!pEnt)
		return;
	CVAll *e = (CVAll *)pEnt;
	if (flags & 1) {
		*(int *)((char *)pEnt + 0x48) = 0;
		((unsigned char *)pEnt)[0x53] = 0xff;
	} else {
		((unsigned char *)pEnt)[0x53] = 0xb4;
		if (flags & 0x10)
			*(int *)((char *)pEnt + 0x48) = 4;
		else
			*(int *)((char *)pEnt + 0x48) = 5;
	}
	if (flags & 0x20)
		e->sub_1009f6c0(2, (float)enginerandom->RandomInt(0, 360));
	*(int *)((char *)pEnt + 0x4c) = 0;
	e->sub_1003a840(0, 0, 0x41000000);
	((unsigned char *)pEnt)[0x50] = 0xff;
	((unsigned char *)pEnt)[0x51] = 0xff;
	((unsigned char *)pEnt)[0x52] = 0xff;
	e->sub_1009f680(2, sub_1009f670(2) + 10.0f);
	pEnt->m_unk7f0 = n;
}
// END FUNCTION

// FUNCTION: 0x1003d5e0 size=0x23
#include "CTempEnts.h"
// TARGET: ?vfunc1@CTempEnts@@UAEXXZ
void CTempEnts::vfunc1() { while (m_pHead) sub_1003ce90(m_pHead, 0); }
// END FUNCTION

// FUNCTION: 0x1003d610 size=0x21
#include "CTempEnts.h"
namespace lifted {
int sub_10044870(int, int, int, int, int);
}
int CTempEnts::vfunc22(int a0, int a1, int a2)
{
    return lifted::sub_10044870(a0, a1, 0x3f400000, a2, 0);
}
// END FUNCTION

// FUNCTION: 0x1003d740 size=0x21
#include "CTempEnts.h"
namespace lifted {
int sub_10044870(int, int, int, int, int);
}
int CTempEnts::vfunc24(int a0, int a1, int a2)
{
    return lifted::sub_10044870(a0, a1, 0x3f800000, a2, 0);
}
// END FUNCTION

// FUNCTION: 0x1003d770 size=0x1d1
#include "engineclient.h"
#include "CTempEnts.h"
#include "Vector.h"
#include "QAngle.h"

struct model_t;

struct color32
{
	unsigned char r, g, b, a;
};



struct IViewRender_1003d770
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
	virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
	virtual void v8(); virtual void v9();
	virtual void AddVisibleEntity(void *pEnt);
};

struct LocalTempEnt_1003d770
{
	char pad_0[0x48];
	int m_nRenderMode;      // 0x48
	int m_nRenderFX;        // 0x4c
	color32 m_clrRender;    // 0x50
	char pad_54[0x758];
	int flags;              // 0x7ac
	float die;              // 0x7b0
	float m_flFrameMax;     // 0x7b4
	char pad_7b8[0x30];
	float m_flRoll;         // 0x7e8
	char pad_7ec[0x04];
	float m_flSpriteScale;  // 0x7f0
	char pad_7f4[0x08];
	float m_flFrame;        // 0x7fc

	void sub_100a2030(const Vector &origin);
	void sub_100a2100(const QAngle &angles);
	void sub_1009f6c0(int axis, float val);
};

struct CTempEnts_Helper_1003d770
{
	char pad_0[0xfbf54];
	const model_t *m_pSpriteMuzzleFlash[2];

	LocalTempEnt_1003d770 *sub_1003cdd0(const Vector &org, model_t *model);
};

struct SimpleParticle_1003d770
{
	char pad_0[0x18];
	Vector m_vecVelocity;      // 0x18
	float m_flRoll;            // 0x24
	float m_flDieTime;         // 0x28
	float m_flLifetime;        // 0x2c
	unsigned char m_uchColor[3]; // 0x30
	unsigned char m_uchStartAlpha; // 0x33
	unsigned char m_uchEndAlpha;   // 0x34
	unsigned char m_uchStartSize;  // 0x35
	unsigned char m_uchEndSize;    // 0x36
	unsigned char pad_37;          // 0x37
	float m_flRollDelta;           // 0x38
};

struct CSimpleEmitter_1003d770
{
	void sub_10117fe0();
	void sub_10118080(const Vector &origin);
	int sub_101180b0(const char *pMaterialName);
	SimpleParticle_1003d770 *sub_101180c0(int particleSize, int hMaterial, const Vector &pos);
};

template <class T>
class CSmartPtr_1003d770
{
public:
	~CSmartPtr_1003d770()
	{
		if (m_pObj)
			m_pObj->sub_10117fe0();
	}

	T *operator->() { return m_pObj; }

	T *m_pObj;
};

extern CSmartPtr_1003d770<CSimpleEmitter_1003d770> sub_10118160(const char *pDebugName);

extern IViewRender_1003d770 *g_102d43d8;
extern QAngle g_104d5190;

// TARGET: ?vfunc21@CTempEnts@@UAEXABVVector@@ABVQAngle@@H@Z
void CTempEnts::vfunc21(const Vector &origin, const QAngle &angles, int entityIndex)
{
	LocalTempEnt_1003d770 *pTemp = ((CTempEnts_Helper_1003d770 *)this)->sub_1003cdd0(
		origin, (model_t *)((CTempEnts_Helper_1003d770 *)this)->m_pSpriteMuzzleFlash[1]);

	if (pTemp == 0)
		return;

	pTemp->m_nRenderMode = 5;
	pTemp->m_clrRender.r = 255;
	pTemp->m_clrRender.g = 255;
	pTemp->m_clrRender.b = 255;
	pTemp->m_clrRender.a = 255;
	pTemp->m_nRenderFX = 0;

	pTemp->die = engine->Time(0) + 0.01f;
	pTemp->m_flFrame = 0.0f;
	pTemp->m_flFrameMax = 1.0f;

	pTemp->sub_100a2030(origin);
	pTemp->sub_100a2100(g_104d5190);
	pTemp->sub_100a2100(angles);

	pTemp->m_flSpriteScale = enginerandom->RandomFloat(0.2f, 0.3f) * 0.3f;
	pTemp->sub_1009f6c0(2, (float)enginerandom->RandomInt(0, 360));
	pTemp->flags = 4;
	pTemp->m_flRoll = enginerandom->RandomFloat(0.0f, 360.0f);

	g_102d43d8->AddVisibleEntity(pTemp);

	CSmartPtr_1003d770<CSimpleEmitter_1003d770> pSimple = sub_10118160("MuzzleFlash_Pistol_Player");
	pSimple->sub_10118080(origin);

	SimpleParticle_1003d770 *pParticle = pSimple->sub_101180c0(
		sizeof(SimpleParticle_1003d770), pSimple->sub_101180b0("particle/particle_noisesphere"), origin);

	if (pParticle == 0)
		return;

	int alpha = enginerandom->RandomInt(64, 128);

	pParticle->m_flLifetime = 0.0f;
	pParticle->m_flDieTime = 0.25f;

	pParticle->m_vecVelocity.Init();

	pParticle->m_uchColor[0] = alpha;
	pParticle->m_uchColor[1] = alpha;
	pParticle->m_uchColor[2] = alpha;
	pParticle->m_uchStartAlpha = alpha;
	pParticle->m_uchEndAlpha = 0;
	pParticle->m_uchStartSize = enginerandom->RandomInt(4, 8);
	pParticle->m_uchEndSize = pParticle->m_uchStartSize * 2;
	pParticle->m_flRoll = (float)enginerandom->RandomInt(0, 360);
	pParticle->m_flRollDelta = enginerandom->RandomFloat(-4.0f, 4.0f);
	pParticle->m_vecVelocity.z = 16.0f;
}
// END FUNCTION

// FUNCTION: 0x1003d950 size=0x66
#include "CTempEnts.h"

extern int sub_100b47b0(const char *pszName, int a1, int a2, int a3, int a4, int a5, float f1, float f2, float f3, float f4);

void CTempEnts::vfunc25(int a0, int a1, int a2, const char *name1, const char *name2, int a5, int a6)
{
	sub_100b47b0(name1, a0, a1, a5, 6, a6, 1.0f, 1.0f, 1.0f, 1.0f);
	sub_100b47b0(name2, a0, a1, a5, 6, a6, 1.0f, 1.0f, 1.0f, 1.0f);
}
// END FUNCTION

// FUNCTION: 0x1003d9c0 size=0x89
#include "CTempEnts.h"
#include "Vector.h"

struct Part_1003d9c0
{
	void sub_100af150();
};

extern Vector g_104d5190;
extern Part_1003d9c0 *sub_100b47b0(const char *pszName, int a1, int a2, int a3, int a4, int a5, float f1, float f2, float f3, float f4);

void CTempEnts::vfunc26(int a0, int a1, int a2, const char *name1, const char *name2, int a5, int a6)
{
	if (name1)
	{
		Part_1003d9c0 *p = sub_100b47b0(name1, a0, (int)&g_104d5190, a5, 6, a6, 1.0f, 1.0f, 1.0f, 1.0f);
		if (p)
			p->sub_100af150();
	}
	if (name2)
	{
		Part_1003d9c0 *p = sub_100b47b0(name2, a0, (int)&g_104d5190, a5, 6, a6, 1.0f, 1.0f, 1.0f, 1.0f);
		if (p)
			p->sub_100af150();
	}
}
// END FUNCTION
