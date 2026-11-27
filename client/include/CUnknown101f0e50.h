// CUnknown101f0e50: the reaction table (the global g_1073a9a0), 0x4c bytes: seven dwords of which five are cleared
// by its constructor-like initialiser (fields +0x0, +0x4, +0x8, +0x14, +0x18), then the modifier names and their
// lengths; real name not yet known.
#pragma once

#include "CUnknown101f1c70.h"

class CVTraitEffectGroup_t;

// The object whose list of applied trait ids lives at +0x1460; real name not yet known.
class CTraitOwnerX
{
public:
	char m_pad0000[0x1460];
	CUnknown101f1c70 m_Applied;	// 0x1460
};

class CUnknown101f0e50
{
public:
#ifdef PCD_INITIALIZERS	// the initializer units: the global 0x1073a9a0 is built and destroyed by these
	CUnknown101f0e50();	// function 0x101f0e50
	~CUnknown101f0e50();	// function 0x101f0e80
#endif
	int m_f00;
	int m_f04;	// element count
	int m_f08;
	int m_f0c;
	int m_f10;
	int m_f14;
	int m_f18;
	const char *m_pszMods[6];	// 0x1c: the modifier names the Reaction.txt loader (sub_101f14a0) stores; matched code
								// reads them as the globals g_1073a9bc / g_1073a9c0
	int m_nModLens[6];	// 0x34: their lengths (the global g_1073a9d4 in matched code); 0x4c bytes in all

		// zeroes the fields above and returns this
		// the index of the entry named pszName, -1 when there is none (stub 0x10010861)
	bool sub_10153230(const char *pszFile);
	bool sub_10153640(int index);	// "IsValidIndex": index is not -1 and below the count at +0x4
	bool sub_10157af0(int index);
	char sub_10157b10(int index);	// stub 0x1000a78b: whether index is a valid entry id (checked by sub_101f9b70)
		// provisional, like sub_101f18f0 (transplant)
	bool sub_101530c0(void *pData);	// parses one reaction category of the data file: its InternalName picks the entry of the pointer array (+0x8, count +0x4) and every ReactionGroup key is handed to that entry (sub_101f0bc0); false (with a Msg) for no data or a missing entry
	CVTraitEffectGroup_t *sub_10153770(int index);
	CVTraitEffectGroup_t *sub_1014e6d0(int index);	// the entry of the pointer array (+0x8) for a valid index, else the function-local static default entry (0x101ea0b0)
	CVTraitEffectGroup_t *sub_10157c20(int index);
		// the entry of the pointer array (+0x8) for a valid index, else the function-local static default entry (stub 0x1000c5d1)
		// stub 0x1000181b: applies a named trait of the entry to the owner
		// walks the effects of the entry for index: kind 5 effects are removed from the owner's applied list (+0x1460, sub_101f1c70), kind 6 effects are handed to sub_101f9af0 with their name ("" when none)
		// the same walk written with ascending loops over each effect's count (+0x14)
		// stub 0x100112b1: the counterpart of sub_101f8e20 for the effects of the other kinds
	bool sub_1014e590(int index);	// provisional, like sub_10153640 (transplant)
};
