// CUnknown10141e80: the 0x10-byte element of the list at +0x18 of the object copied by 0x101423d0 (its constructor
// 0x10141e80 takes the index; a function-local static default of it, built with -1, is used by 0x10142050).
#pragma once

class CUnknown10141e80
{
public:
	int m_unk0;	// +0x0: the index
	int m_unk4;	// +0x4: -1
	int m_unk8;	// +0x8: 0
	int m_unkc;	// +0xc: 99999
	CUnknown10141e80(int a);	// 0x10141e80
	~CUnknown10141e80() {}
	CUnknown10141e80 *sub_10141eb0(const CUnknown10141e80 *src);	// copies +4, +8, +0xc
};
