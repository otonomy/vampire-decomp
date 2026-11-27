// CUnknown10142e50: the 0x14-byte trait-combo object the chargen ordering code uses (VObj-like:
// the At method is VObj::sub_10143120). Constructor 0x10142e50 stores its int arg at +0 and clears +4..+0x10;
// destructor 0x10142e70. It is the shared lazy function-local static default at 0x10680c60.
#pragma once

class CUnknown10142e50
{
public:
	int m_unk0;	// +0x0 (the entity index)
	int m_unk4;	// +0x4
	int m_unk8;	// +0x8 (count)
	int m_unkc;	// +0xc (data)
	int m_unk10;	// +0x10 (sorted)
	CUnknown10142e50(int);
	~CUnknown10142e50();
	int sub_10143120(int);
	void sub_10142f10(void *);
};
