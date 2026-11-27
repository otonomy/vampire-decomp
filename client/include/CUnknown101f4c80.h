// CUnknown101f4c80: a record of the sound name table (id at +0, a name at +4, a folder name at +8); the shared
// default record (id -1) is the one function-local static of the table lookup, so every function that looks a record
// up inlines CUnknown101f4c80Table::Find instead of a static of its own (guard 0x109f08f8, object 0x109f0920).
#pragma once

extern char g_102de300[];	// empty string

class CUnknown101f5d60;

struct CUnknown101f4c80Str	// a string member whose accessor answers "" for null
{
	const char *m_psz;
	const char *Get() const { return m_psz ? m_psz : g_102de300; }
};

class CUnknown101f4c80
{
public:
	int m_nId;	// 0x00
	CUnknown101f4c80Str m_name;	// 0x04
	CUnknown101f4c80Str m_folder;	// 0x08
	int m_unk0c;
	int m_unk10;
	int m_nMaxRange;	// 0x14

	CUnknown101f4c80(int id);	// 0x101f4c80
	~CUnknown101f4c80();	// 0x101f4cb0
	void sub_10155ac0();	// prints the record and its activities with DevMsg
	bool sub_10155990(void *pKV, CUnknown101f5d60 *pOwner, int arg3);	// loads the record from its key: the name / folder from the key's name, then the "Activity" sub keys are counted (a failed activity lookup warns "Sound Table Activity Lookup Failed") and the "MaxRange" read (+0x14); with activities the id array (+0x10) is allocated and filled, every id also registered in the global table at 0x1073dd58 with (pOwner, id, arg3); false for no key
};

struct CUnknown101f4c80Table
{
	char m_pad0000[0x0c];
	CUnknown101f4c80Str m_directory;	// 0x0c
	char m_pad0010[4];
	int m_nRecords;	// 0x14
	CUnknown101f4c80 **m_pRecords;	// 0x18

	CUnknown101f4c80 *Find(int id)
	{
		for (int i = 0; i < m_nRecords; i++) {
			if (m_pRecords[i]->m_nId == id)
				return m_pRecords[i];
		}
		static CUnknown101f4c80 s_default(-1);
		return &s_default;
	}
};
