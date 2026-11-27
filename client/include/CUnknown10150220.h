#pragma once
// Record of a client string/stat table (constructed with an id, +0x14 owns a heap block).
// 0x10150220 is its constructor, 0x10150240 its destructor.
class CUnknown10150220
{
public:
	CUnknown10150220(int nId);
	~CUnknown10150220();

	int m_nId;           // +0x00
	int m_unk04;         // +0x04
	const char *m_psz08; // +0x08
	int m_unk0c;         // +0x0c
	int m_unk10;         // +0x10
	void *m_p14;         // +0x14
};
