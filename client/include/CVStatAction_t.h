// CVStatAction_t: a stat action record of the V-stat UI (placeholder layout from its destructor 0x1015a1b0)
#pragma once

class CVStatActionPart
{
public:
	void sub_10161420();	// empty (a one-byte ret) in the game
};

class CVStatAction_t
{
public:
	int m_unk0;
	int m_nType;	// +0x04: 4 owns the buffer at +0x3c
	int m_unk08; int m_unk0c; int m_unk10; int m_unk14; int m_unk18; int m_unk1c;
	int m_unk20; int m_unk24;
	CVStatActionPart m_Part;	// +0x28
	int m_unk2c; int m_unk30; int m_unk34; int m_unk38;
	void *m_pBuffer;	// +0x3c

	bool sub_1015a750();
	char *sub_1015a9a0();	// "CVStatAction_t::ToDetailedStr"
	void sub_1015a1b0();	// the destructor body (scope trace "CVStatAction_t::~CVStatAction_t")
};
