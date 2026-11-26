// CHudDialog: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CHUDSprite;
struct DlgColor { unsigned char c[4]; DlgColor() { c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0; } };	// vgui Color-like: four bytes the constructor zeroes one by one

class CHudDialog : public CManagedHudElement
{
public:
	CHudDialog(int a);	// 0x10052980
	virtual ~CHudDialog();
	void sub_100545d0();	// vfunc112's body, called directly by the constructor
	void sub_101a9890(int, int);
	void sub_101a98f0(int, int);
	void *sub_101ac830();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CHudDialog's own function
	virtual void vfunc97();
	virtual void vfunc98();
	virtual bool vfunc107();
	virtual void vfunc112();
	// the slots CHudDialog adds to its base's vtable: 114-116, vfuncK at slot K
	virtual void vfunc114();
	virtual void vfunc115(int, int, int);
	virtual bool vfunc116();
	void sub_10054450(bool);
	int sub_10055650();
	int sub_10053f10(int flags, int n);
	int sub_10061450(int, int, int);
	void SetDrawLastPickEnabled(bool bEnabled);
	void ScrollDn();
	void ScrollUp();
	void sub_100544d0(bool bEnabled);
	void sub_10054bd0(bool bEnabled);
	void sub_10055360(bool b);
	void sub_10054670(int n);
	void sub_10054f70(int type, const char *text);
	void sub_10054860();
	void sub_10053ff0(bool bDraw, const char *pszText, int nFlags, int nType, int *pY);	// "CHudDialog::PaintResponseLine"
	void sub_100549f0(int a, int b);
	void sub_10053c70(bool bDraw, int nIndex, const char *pszText, int nFlags, int nType, int *pY);	// "CHudDialog::PaintResponse"
	int sub_100556d0(int nFont, const char *pszText);
	int m_unk174;
	int m_n178; int m_n17c; int m_n180; int m_n184; int m_n188; int m_n18c;
	bool m_b190; char m_c191; char m_c192; char m_c193;
	int m_n194; int m_n198; int m_n19c; int m_n1a0;	// 0x194 wide (XRES 832), 0x198 tall (YRES 163), 0x19c bottom gap (YRES 22), 0x1a0 x
	float m_flAlpha;	// 0x1a4: the dialog alpha ComputeAlpha clamps to 0..g_10285ad0
	float m_flAlpha1a8;	// 0x1a8
	float m_flAlpha1ac;	// 0x1ac
	bool m_b1b0;
	bool m_b1b1;
	bool m_b1b2;
	bool m_b1b3;
	bool m_b1b4;
	bool m_b1b5;
	bool m_b1b6;
	bool m_b1b7;
	float m_flLastTime;	// 0x1b8: engine time of the last ComputeAlpha
	char m_pad01bc[0x9c8 - 0x1bc];
	int m_nFonts[8];	// 0x9c8: scheme fonts Dlg_Base x3, Persuasion, Seduction, Dominate, Dementation, Intimidate
	DlgColor m_aColors[6];	// 0x9e8: scheme colors of the same names
	DlgColor m_colError;	// 0xa00
	DlgColor m_colFillBkg;	// 0xa04
	CHUDSprite *m_pCorners[2][2];	// 0xa08: hud/DialogFrmCrnrs
	CHUDSprite *m_pEdges[2][2];	// 0xa18: hud/DialogFrmEdgs
	char m_pad0a28[0x122c - 0xa28];
	void sub_10053200();	// "CHudDialog::ComputeAlpha"
	void sub_10053b50(bool);
	void sub_10053770(bool);
	void sub_100530f0();
	char m_szItems[4][0x800];	// 0x122c
	char m_pad322c[0x324c - 0x322c];
	char m_szText[0x800];	// 0x324c
	int m_nOptions;	// 0x3a4c
	char m_szOptions[4][0x800];	// 0x3a50
	int m_iOptionA[4];	// 0x5a50
	int m_iOptionB[4];	// 0x5a60
	DlgColor m_col5a70; DlgColor m_col5a74; DlgColor m_col5a78; DlgColor m_col5a7c;
	char m_pad5a80[0x5bf0 - 0x5a80];
};
