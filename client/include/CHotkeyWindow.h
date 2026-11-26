// CHotkeyWindow: the "hud/HotkeyWindow" popup (OKButton / CancelButton, ten "MenuFoo" rows); its constructor 0x10182750
// builds the item and record tables the refresh 0x10183e90 reads. Only the members that code names are modelled.
#pragma once

struct CHotkeyItem	// 0x60 bytes, at +0x1800
{
	int m_nRecord;	// 0x00: the record index a type 1 item matches (low word of the player's value)
	int m_nFirst;	// 0x04: the first record of the item
	int m_nCount;	// 0x08: how many records follow
	int m_nType;	// 0x0c: 0..6, matched against the player's type word
	char m_szText[0x50];	// 0x10
};

struct CHotkeyRow	// 0x14 bytes, at +0x1d4c
{
	int m_unk00;
	int m_unk04;
	int m_unk08;
	void *m_pLabel;	// 0x0c: the label panel (slot 108 sets its text, slot 109 reads it)
	void *m_pValue;	// 0x10: the value panel
};

struct CHotkeyRecord	// 0x90 bytes, at +0x180
{
	char m_szName[0x51];	// 0x00: shown in the value panel
	char m_szCommand[0x3f];	// 0x51: its CRC32 is the value of a type 2/3 row
};

class CHotkeyWindow
{
public:
	char m_pad0000[0x180];
	CHotkeyRecord m_Records[40];	// 0x180
	CHotkeyItem m_Items[12];	// 0x1800
	int m_nRecords;	// 0x1c80
	int m_nItems;	// 0x1c84
	char m_pad1c88[0x1d4c - 0x1c88];
	CHotkeyRow m_Rows[10];	// 0x1d4c

	void sub_10183e90();	// refresh the rows from the local player's two ten-entry tables (+0x1834 types, +0x185c values)
	void sub_10183690(int nRow, int nItem);
	void sub_10183b90();	// OKClicked: the rows back into (type, value) pairs, sent as "sethotkeys"
};
