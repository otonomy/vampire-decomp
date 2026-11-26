// BigV_10142340: a 0x174-byte chargen record (the element/default type of the clan-pair table at 0x105e77d0).
// Constructor 0x10142340 stores its int at +0, -1 at +0x14, clears +4..+0x10 and builds the members at +0x18,
// +0x34, +0x44 and four 0x48-byte entries from +0x54; destructor 0x101423a0 tears them down in reverse.
// 0x10143f80 keeps a function-local static default of it (0x10680ae0, guard 0x10680ac4, atexit thunk 0x10144cb0).
#pragma once

class BigV_10142340
{
public:
	BigV_10142340(int n);
	~BigV_10142340();
	int m_unk00;
	const char *m_pszHelp;	// 0x04: the help popup name 0x10143f80 hands back
};
