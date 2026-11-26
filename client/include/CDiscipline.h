// CDiscipline: HUD discipline panel (from the game's RTTI)
#pragma once
#include "CManagedHudElement.h"

class CDisciplineChild { public: virtual ~CDisciplineChild(); };

struct CDisciplineEntry
{
	int m_nId;
	int m_unk4;
	bool m_b8;
	char m_pad9[3];
};

class CDiscipline : public CManagedHudElement
{
public:
	virtual ~CDiscipline();
	int sub_1004ec90(int id);
	int sub_1004ecb0(int id);
	void sub_1004ed00(int id);
	void sub_1004ed80(int id, int a, int b);
	virtual bool vfunc107();
	virtual void vfunc114(int id, int val);
	void sub_1004fa40();
	virtual void vfunc98();
	int m_unk174;
	int m_unk178;
	int m_unk17c;
	int m_n180;
	int m_n184;
	int m_n188;
	int m_n18c;
	int m_n190;
	int m_n194;
	int m_unk198;
	int m_unk19c;
	int m_n1a0;
	char m_c1a4;
	bool m_b1a5;
	bool m_b1a6;
	char m_c1a7;
	int m_nEntries;
	CDisciplineEntry m_Entries[6];
	CDisciplineChild *m_p1f4;
	CDisciplineChild *m_p1f8;
};
