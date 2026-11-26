// CVProfile / CVProfNode: the engine's VPROF profiler as client.dll sees it (layout read off C_BaseAnimating::DrawModel's inlined scope code).
// EnterScope / ExitScope are imported (slots 0x101e3134 / 0x101e313c). The rdtsc Sample is written in the source of the function that needs it.
#pragma once

struct CCycleCountX
{
	unsigned __int64 v;
	void operator+=(const CCycleCountX &o) { v += o.v; }
};

class CVProfNode
{
public:
	int m_unk0;
	int m_unk4;
	CCycleCountX m_CurFrameTime;
	int m_nRecursions;
	int m_nCurFrameCalls;
	CCycleCountX m_TotalTime;
	int m_unk20[10];
	CVProfNode *m_pParent;
	__declspec(dllimport) bool ExitScope();
};

class CVProfile
{
public:
	char m_bEnabled;
	char m_pad1[3];
	int m_nCurBudget;
	int m_Stack[0x400];
	int m_nDepth;
	int m_nPause;
	char m_fAtRoot;
	char m_pad2[3];
	CVProfNode *m_pCurNode;
	CVProfNode *m_pRoot;
	__declspec(dllimport) void EnterScope(const char *pszName, int detailLevel, const char *pBudgetGroupName, bool bAssertAccounted);
};
