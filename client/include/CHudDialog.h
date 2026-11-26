// CHudDialog: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 20 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "CManagedHudElement.h"

class CHudDialog : public CManagedHudElement
{
public:
	virtual ~CHudDialog();
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
	char m_pad0008[0x122c - 0x174];	// starts at 0x174 (the bases end there)
	char m_szItems[4][0x800];	// 0x122c
	char m_pad322c[0x324c - 0x322c];
	char m_szText[0x800];	// 0x324c
	int m_nOptions;	// 0x3a4c
	char m_szOptions[4][0x800];	// 0x3a50
	int m_iOptionA[4];	// 0x5a50
	int m_iOptionB[4];	// 0x5a60
	char m_pad5a70[0x5bf0 - 0x5a70];
};
