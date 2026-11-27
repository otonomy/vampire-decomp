// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x10115d40 size=0x83
#include "CParticleEffectBinding.h"
// TARGET: ??0CParticleEffectBinding@@QAE@XZ
CParticleEffectBinding::CParticleEffectBinding()
{
	m_unk30 = 0;
	m_unk2c = 0;
	m_unk34 = 0x9c;
	m_Min.Init(-50.0f, -50.0f, -50.0f);
	m_Max.Init(50.0f, 50.0f, 50.0f);
	m_unk08 = 0xffff;
	m_unk28 = 0xffff;
	m_unk24 = 0;
	m_unk26 = 0;
}
// END FUNCTION

// FUNCTION: 0x10115e10 size=0x8f
#include "CParticleEffectBinding.h"
extern "C" __declspec(dllimport) void Plat_Free(void *);
struct PEBElem { unsigned short pad0, pad2, m_Prev, m_Next; };
CParticleEffectBinding::~CParticleEffectBinding()
{
	if (m_unk30)
		m_unk30->sub_101176b0(this);
	sub_10116e10();
	if (m_List.m_s14 != 0)
	{
		unsigned short prev = 0xffff;
		for (int i = m_List.m_s14 - 1; i >= 0; --i)
		{
			((PEBElem *)m_List.m_a)[(unsigned short)i].m_Next = prev;
			((PEBElem *)m_List.m_a)[(unsigned short)i].m_Prev = i;
			prev = i;
		}
		m_List.m_s10 = 0;
		m_List.m_s0c = -1;
		m_List.m_s0e = -1;
		m_List.m_s12 = 0;
	}
	if (m_List.m_c != -1)
	{
		if (m_List.m_a)
		{
			Plat_Free((void *)m_List.m_a);
			m_List.m_a = 0;
		}
		m_List.m_b = 0;
	}
}
// END FUNCTION

// FUNCTION: 0x10116070 size=0x322
#include "CParticleEffectBinding.h"
#include "IClientMode.h"
#include "ConVar.h"
#include "engineclient.h"

// tier0/fasttimer.h
class CCycleCount
{
public:
	CCycleCount() { m_Int64 = 0; }
	void Sample()
	{
		unsigned long *pSample = (unsigned long *)&m_Int64;
		__asm
		{
			mov ecx, pSample
			rdtsc
			mov [ecx], eax
			mov [ecx+4], edx
		}
	}
	__int64 m_Int64;
};

class CFastTimer
{
public:
	void Start() { m_Duration.Sample(); }
	void sub_100befd0();	// CFastTimer::End, out of line
	CCycleCount m_Duration;
};

class CTimeAdder
{
public:
	CTimeAdder(CCycleCount *pTotal) { m_pTotal = pTotal; m_Timer.Start(); }
	CCycleCount *m_pTotal;
	CFastTimer m_Timer;
};

struct IMaterialV
{
	virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
	virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
	virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25();
	virtual bool vfunc26();	// NeedsFrameBufferTexture
};

struct VMatrixV { float m[4][4]; };

struct MaterialNodeV	// CUtlLinkedList<CEffectMaterial *, unsigned short> node
{
	void *m_Element;
	unsigned short m_Previous;
	unsigned short m_Next;
};

struct MaterialListV	// CUtlLinkedList<CEffectMaterial *, unsigned short> at +0x38
{
	MaterialNodeV *m_pMemory;
	int m_nAllocationCount;
	int m_nGrowSize;
	unsigned short m_Head;

	unsigned short Head() const { return m_Head; }
	unsigned short Next(unsigned short i) const { return m_pMemory[i].m_Next; }
	void *Element(unsigned short i) const { return m_pMemory[i].m_Element; }
};

extern ConVar g_104e0920;	// r_drawparticles
extern ConVar g_106192f0;	// particle wireframe
extern IClientMode *g_105f99d8;
extern CCycleCount g_104e09b8;
float sub_10117b40();
int sub_10198260();

int CParticleEffectBinding::DrawModel(int flags, int a1)
{
	if (!g_104e0920.GetInt())
		return 0;

	bool bNoRender = (flags == 0);
	if (!g_105f99d8->vfunc13() && !bNoRender)
		return 0;

	CTimeAdder adder(&g_104e09b8);

	SetDrawn(true);

	if (!m_unk24) {
		if (adder.m_pTotal) {
			adder.m_Timer.sub_100befd0();
			adder.m_pTotal->m_Int64 += adder.m_Timer.m_Duration.m_Int64;
		}
		return 1;
	}

	VMatrixV mTempModel, mTempView;
	if (!bNoRender)
		sub_10116bb0((VMatrix *)&mTempModel, (VMatrix *)&mTempView);

	bool bBucketSort = enginerandom->RandomInt(0, 8) == 0;

	Vector vMins(0, 0, 0);
	Vector vMaxs(0, 0, 0);
	sub_10115fb0(bBucketSort, &vMins, &vMaxs);

	float flFrameTime = 0;
	if (m_unk26 != *(unsigned short *)((char *)m_unk30 + 4)) {
		m_unk26 = *(unsigned short *)((char *)m_unk30 + 4);
		flFrameTime = sub_10117b40();
	}

	MaterialListV &list = *(MaterialListV *)&m_List;
	bool bWireframe = false;
	for (int i = list.Head(); i != 0xffff; i = list.Next(i)) {
		void *pMaterial = list.Element(i);
		if (!bNoRender) {
			IMaterialV *pPage = (IMaterialV *)sub_101165c0(i);
			if (pPage && pPage->vfunc26()) {
				materials->vfunc65(0);
				int pTexture = sub_10198260();
				materials->vfunc61(pTexture);
				materials->vfunc62(pTexture, 0);
			}
		}
		sub_10116720(bBucketSort, bNoRender, pMaterial, flFrameTime, &vMins, &vMaxs, &bWireframe, false);
	}

	if (g_106192f0.GetInt()) {
		for (int j = list.Head(); j != 0xffff; j = list.Next(j)) {
			sub_10116720(bBucketSort, bNoRender, list.Element(j), flFrameTime, &vMins, &vMaxs, &bWireframe, true);
		}
	}

	sub_10116010(bBucketSort, bWireframe, &vMins, &vMaxs);

	if (!bNoRender)
		sub_10116ca0((VMatrix *)&mTempModel, (VMatrix *)&mTempView);

	if (adder.m_pTotal) {
		CCycleCount cnt;
		cnt.Sample();
		adder.m_Timer.m_Duration.m_Int64 = cnt.m_Int64 - adder.m_Timer.m_Duration.m_Int64;
		adder.m_pTotal->m_Int64 += adder.m_Timer.m_Duration.m_Int64;
	}
	return 1;
}
// END FUNCTION
