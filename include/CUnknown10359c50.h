// CUnknown10359c50: 0x18-byte global registry object used by the NPC schedule loader (static instances
// 0x1093a1a8, 0x1093a1c0, ...): an id space that maps the symbols of one kind (schedules, tasks, conditions) to
// global ids; real name not yet known.
#pragma once

struct CUnknown10359c50Symbols
{
	void sub_102e9fe0(const char *pszSymbol, int nGlobalId);	// stub 0x10001014: stores the symbol with its global id
};

class CUnknown10359c50;

// The four registry objects of one NPC class's schedule file (schedule / task / condition / squadslot kinds).
extern CUnknown10359c50 g_1093a740;
extern CUnknown10359c50 g_1093a758;
extern CUnknown10359c50 g_1093a770;
extern CUnknown10359c50 g_1093a788;

class CUnknown10359c50
{
public:
	bool sub_1001153b(const char *a, const char *b);	// returns false on failure
	void sub_1000a948(const char *name, int id, const char *type, const char *className);
	bool sub_102ea130(const char *pszSymbol, int nLocalId, const char *pszIdType, const char *pszClassName);	// adds a symbol (stub 0x1000a948): errors (Msg, false) for a table that is not set up, a first local id that is not valid (SetLocalBase) or one below the base; keeps the highest local id and its global id, then stores the symbol with the global id of the local id (sub_102ea2d0)
	bool SetLocalBase(int nLocalId);	// stub 0x10009142: whether the id is a valid first local id
	int sub_102ea2d0(int nLocalId);	// stub 0x10012300: the global id of a local id

	int m_nGlobalBase;	// 0x00
	int m_nLocalBase;	// 0x04: 9999 until the first symbol is added
	int m_nHighestLocal;	// 0x08: -1 until the first symbol is added
	int m_nHighestGlobal;	// 0x0c
	int m_n10;
	CUnknown10359c50Symbols *m_pSymbols;	// 0x14
};
