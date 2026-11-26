#pragma once
class CHudElement;
class IDel { public: virtual ~IDel() {} };
struct CHudSub { int m_u[33]; IDel *m_pObj; int m_t[4]; };
class CHud {
public:
	void *sub_100f11d0(const char *pName);
	void *GetIcon(const char *szIcon);	// 0x100f11d0 (SDK name)
	struct CHudSub *sub_100f1200(const char *pName, int *pWide, int *pTall);
	int sub_100f0980(const char *pName);
	int m_unk0; int m_unk4; int m_unk8; int m_unkc; int m_unk10; int m_unk14; int m_unk18; int m_unk1c;
	int m_unk20; int m_unk24; int m_unk28; int m_unk2c; int m_unk30; int m_unk34; int m_unk38; int m_unk3c;
	CHudElement **m_HudListMem;
	int m_HudListAlloc;
	int m_HudListGrow;
	int m_HudListSize;
	CHudElement *sub_100f0ed0(const char *pName);
	CHudElement *FindElement(const char *pName);	// 0x100f0ed0 (SDK name)
	void sub_100f0860();
	void sub_100f08d0();
	bool sub_100f10d0(int mask);
	void sub_100f2e80(int, int, int, int, int, int, int, int, int);
	void sub_100f07f0();
	void sub_100f06d0();
	void sub_100f07a0();
	void sub_100f28d0();
	void sub_100f12b0(bool b);
	int m_unk50; struct CHudSub *m_pSubs; int m_unk58; int m_unk5c; int m_unk60; int m_nSubs;
};

// the HUD (SDK cl_dll/hud.h): gHUD.FindElement("CHudX"), gHUD.GetIcon("name")
extern CHud gHUD;
