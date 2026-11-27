// CExperienceTable: table of 12-byte award records (CUtlVector layout: memory pointer at +0, size at +0xc).
#pragma once

struct CExperienceAward
{
	int m_a;	// the award's name (a heap string pointer)
	int m_b;
	int m_c;
};

class CExperienceTable
{
public:
#ifdef PCD_INITIALIZERS	// the initializer units: the global 0x10750930 is built and destroyed by these
	CExperienceTable();	// function 0x102221d0
	~CExperienceTable();	// function 0x10222210
#endif
	CExperienceAward *m_pMemory;	// 0x00
	int m_allocationCount;	// 0x04
	int m_growSize;	// 0x08
	int m_Size;	// 0x0c
	CExperienceAward *m_pElements;	// 0x10
	char m_flag14;	// 0x14

	CExperienceAward *sub_10163600(int index);
	void sub_101636a0(int file);	// "ExperienceTable::GetAward": scope trace, record `index` or a warning and the static dummy record
	void sub_10163410();	// "ExperienceTable::PurgeExperience": scope trace, frees the two strings of every record and purges the memory
	void sub_10163290();	// "ExperienceTable::~ExperienceTable": scope trace, PurgeExperience, then the inlined CUtlVector destructor (RemoveAll + Purge, then the CUtlMemory Purge)
		// "ExperienceTable::FindIndex": scope trace, index of the record whose name equals pszName (case-insensitive, compared over the longer length), else a warning and -1
	bool sub_101637f0(char *line, CExperienceAward *out);	// "ExperienceTable::ParseLine": scope trace, splits "name|desc|number" in place at the two '|' and fills out with heap copies of name and desc and atoi(number); false when a part is missing or empty
		// "ExperienceTable::LoadFile": scope trace, reads lines of the file through slot 20 of the global at 0x1070b238 into a 0x1000 byte buffer; skips lines starting with '>' and lines shorter than 3 characters, parses the others and appends them (inlined CUtlVector::AddToTail); stops at the end of the file or on a parse failure
		// "ExperienceTable::PreCache": scope trace, unless already loaded opens "vdata\system\Experience_Table.txt" through the file system (global 0x1070b238, slot 0), LoadFile, closes it (slot 1) and sets the flag at +0x14; DevWarning and the flag cleared when the file cannot be opened
};
