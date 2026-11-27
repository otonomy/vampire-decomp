// C_Hairball: client hairball entity (members from the constructor 0x1002c740)
#pragma once
#include "C_BaseEntity.h"
#include "CUtlMemory12.h"
#include "Vector.h"

extern "C" __declspec(dllimport) void __cdecl Plat_Free(void *);
struct HairVec36 { char *m_pMemory; int m_alloc; int m_grow; int m_Size; char *m_pElements;
	int sub_1002d4a0(int where, int num, const void *p);
	void Purge() { if (m_grow != -1) { if (m_pMemory) { Plat_Free(m_pMemory); m_pMemory = 0; } m_alloc = 0; } }
	~HairVec36() { m_Size = 0; Purge(); m_pElements = m_pMemory; Purge(); } };
struct HairVec12 { CUtlMemory12 m_Memory; int m_Size; char *m_pElements;
	int sub_1002d570(int where, int num, const void *p); };

struct HairVec12P { CUtlMemory12 m_Memory; int m_Size; char *m_pElements;
	~HairVec12P() { m_Size = 0; m_Memory.sub_1002d470(); m_pElements = m_Memory.m_pMemory; m_Memory.Purge(); } };
struct HairVec12D { CUtlMemory12 m_Memory; int m_Size; char *m_pElements;
	~HairVec12D() { m_Size = 0; m_Memory.Purge(); m_pElements = m_Memory.m_pMemory; m_Memory.Purge(); } };
class C_Hairball : public C_BaseEntity
{
public:
	C_Hairball();
	void sub_1002ca30();
	char m_pad14[0x410 - 0x14];
	float m_flRadius;	// 0x410
	int m_nCount;	// 0x414
	int m_unk418;
	float m_unk41c;
	HairVec36 m_Vec420;
	HairVec12D m_Vec434;
	HairVec12P m_Vec448;
	int m_unk45c;	// 0x45c: the physics helper the simulation calls back
	int m_unk460;
	int m_unk464;
	struct HairPhysics { int m_a[7]; void sub_1012c770(void *pNodes, int nNodes, void *pHelper, float dt, float damping); } m_Physics;	// 0x468: CSimplePhysics-like (Simulate)
	float m_flNextBurst;	// 0x484
	Vector m_vecBurstVel;	// 0x488
	float m_flSwayPeriod;	// 0x494
	float m_flSwayTime;	// 0x498
	float m_flSwayX;	// 0x49c
	float m_flSwayY;	// 0x4a0
	bool m_bResetNodes;	// 0x4a4

	virtual void ClientThink();	// IClientThinkable slot 0
};
