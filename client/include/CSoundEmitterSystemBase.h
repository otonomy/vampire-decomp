// CSoundEmitterSystemBase: sound emitter system (3 virtual slots; only the layout the constructor sets up is declared).
// sub_101b31a0 is its own block; 0x101b4200 compiles a copy before itself in namespace block_101b4200 (one name,
// one definition: link audit B).
#pragma once
#include "CUnknown1024b2d0.h"
#include "utlrbtree.h"
#include "CSoundParameters.h"

class UtlMem2;

// One wave entry of a sound record: an 8 byte record (16 bit symbol of the wave name in the string table at +0xb0, value).
struct CSoundWaveEntry
{
	unsigned short m_symbol;
	char m_pad02[6];
};

// A sound record (0xe8 bytes each, table at CSoundEmitterSystemBase +0x54, record = table + 0x1c + index * 0xe8):
// only the wave list is declared.
struct CUnknown1012f700	// a random interval (start, range), see sub_1012f700
{
	float start;
	float range;
};

struct CSoundParametersInternal
{
	int m_channel;	// 0x00
	CUnknown1012f700 m_volume;	// 0x04
	CUnknown1012f700 m_pitch;	// 0x0c
	CUnknown1012f700 m_soundlevel;	// 0x14
	bool m_bPlayToOwnerOnly;	// 0x1c

	char m_bPrecache1d;	// 0x1d
	char m_pad001e[2];
	CSoundWaveEntry *m_pWaves;	// 0x20
	char m_pad0024[8];
	int m_nWaves;	// 0x2c
	char m_pad0030[0x48 - 0x30];
	char m_bMissingWave48;	// 0x48: set when one of the waves is not on disk

	CSoundWaveEntry &Wave(int i) { return m_pWaves[i]; }	// the i-th wave of the record (the CUtlVector element)
};

// The element of the sound record tree (CUtlRBTree<CSoundEmitterRecord, int>, 0xe8 byte nodes: 16 bytes of links and
// this 0xd8 byte element). Its sentinel static is at 0x1072c414.
struct CSoundEmitterRecordTail
{
	char m_pad[0xcc];
	CSoundEmitterRecordTail(const CSoundEmitterRecordTail &o);
};
struct CSoundEmitterRecord
{
	unsigned short m_w0;
	char m_pad02[2];
	char m_b4;
	char m_b5;
	char m_pad06[2];
	int m_i8;
	CSoundEmitterRecordTail m_tail;
	CSoundEmitterRecord();
	CSoundEmitterRecord(const CSoundEmitterRecord &o) : m_tail(o.m_tail), m_w0(o.m_w0), m_b4(o.m_b4), m_b5(o.m_b5), m_i8(o.m_i8) {}
};

// The element of the tree at CSoundEmitterSystemBase +4 (CUtlRBTree<CSoundEmitterFileEntry, int>, 0x18 byte nodes,
// sentinel 0x1072c428, out-of-line Links 0x101b7f00).
struct CSoundEmitterFileEntry
{
	int m_i00;
	int m_i04;
};

// A tree (0x20 bytes, int indices) followed by a 0x2c byte table object: 0x4c bytes.
struct CSoundEmitterDict
{
	CUtlRBTree<int, int> m_tree;
	CUnknown1024b2d0 m_table;

	CSoundEmitterDict(bool (*pfnLess)(int const &, int const &)) : m_tree(0, 0, pfnLess)
	{
		m_table.sub_1013d2b0(0, 0, 1);
	}
};

class CUnknown10248a50;
class CUnknown101b2570;
#include "UtlVec8.h"
#include "CUnknown101b61a0.h"
extern "C" int __cdecl _strcmpi(const char *, const char *);
extern "C" int __cdecl sub_101e28e0(const char *, const char *);
struct CSoundWord8 { unsigned short w; char pad[6]; };
struct CSoundParamsFull
{
	int m_channel;
	float m_f04, m_f08, m_f0c, m_f10, m_f14, m_f18;
	char m_b1c, m_b1d;
	char m_pad1e[2];
	UtlVec8 m_waves;
	CUnknown101b61a0 m_sub;
	char m_b48;
	char m_s49[0x20];
	char m_s69[0x20];
	char m_s89[0x20];
	char m_sa9[0x20];

	bool operator==(const CSoundParamsFull &other) const
	{
		if (this == &other)
			return true;
		if (m_channel != other.m_channel) return false;
		if (m_f04 != other.m_f04) return false;
		if (m_f08 != other.m_f08) return false;
		if (m_f0c != other.m_f0c) return false;
		if (m_f10 != other.m_f10) return false;
		if (m_f14 != other.m_f14) return false;
		if (m_f18 != other.m_f18) return false;
		if (_strcmpi(m_s69, other.m_s69)) return false;
		if (_strcmpi(m_s49, other.m_s49)) return false;
		if (_strcmpi(m_sa9, other.m_sa9)) return false;
		if (_strcmpi(m_s89, other.m_s89)) return false;
		if (m_b1c != other.m_b1c) return false;
		if (m_b1d != other.m_b1d) return false;
		int c = m_waves.m_Size;
		if (c != other.m_waves.m_Size) return false;
		for (int i = 0; i < c; i++)
		{
			if (((CSoundWord8 *)m_waves.m_pMemory)[i].w != ((CSoundWord8 *)other.m_waves.m_pMemory)[i].w)
				return false;
		}
		return true;
	}
};
struct CSoundRecordFull
{
	char m_pad00[4];
	int m_nScript;
	CSoundParamsFull m_params;
};

#ifdef PCD_INITIALIZERS	// the initializer unit: the global 0x1072be18 (CSoundEmitterSystem g_SoundEmitterSystem)
#include "CUtlSymbolTable.h"
#include "utlvector.h"
// The 2003 SDK's CUtlDict (utldict.h): a tree of (name, element) records over an int index, then the symbol table of
// the names. Its destructor is the members': the symbol table's, then the tree's memory.
template <class T, class I> class CUtlDict
{
public:
	struct DictElement_t
	{
		const char *m_Name;
		T m_Data;
	};
	CUtlRBTree<DictElement_t, I> m_Elements;	// 0x00 (0x20 bytes with an int index)
	CUtlSymbolTable m_SymbolTable;	// 0x20
};

// The SDK's layout (SoundEmitterSystemBase.h) with a second dict: built by the out-of-line constructor, destroyed by
// the inline destructor (stores the vtable, then the members last to first).
class CSoundEmitterSystemBase
{
public:
	struct CSoundScriptFile
	{
		bool dirty;
		bool precachealways;
		char filename[128];
	};

	CSoundEmitterSystemBase();	// function 0x101b26c0
	virtual ~CSoundEmitterSystemBase() {}
	virtual bool BaseInit();
	virtual void BaseShutdown();	// slot 2 (0x101b2e30): empties the sound tables; CSoundEmitterSystem's LogMessage is
								// its own slot 3

	CUtlDict<CSoundEmitterRecord, int> m_Sounds;	// 0x04
	CUtlDict<CSoundEmitterRecord, int> m_SavedOverrides;	// 0x50
	CUtlVector<CSoundScriptFile> m_SoundKeyValues;	// 0x9c
	CUtlSymbolTable m_Waves;	// 0xb0
};
#else
class CSoundEmitterSystemBase
{
public:
	bool sub_1012eca0(const char *pszSoundName, CUnknown10248a50 *pKeys, CUnknown101b2570 *pParams);	// 0x101b3bb0: applies one sound-script block (channel/volume/pitch/wave/rndwave/attenuation/soundlevel/play_to_owner_only/precache) to the parameter record
	void *m_vtbl;	// 0x00
	void *m_pfn04;
	int m_i08;
	int m_i0c;
	int m_i10;
	int m_i14;
	int m_i18;
	int m_i1c;
	int m_i20;
	CUnknown1024b2d0 m_list24;	// 0x24
	void *m_pfn50;
	int m_i54;
	int m_i58;
	int m_i5c;
	int m_i60;
	int m_i64;
	int m_i68;
	int m_i6c;
	CUnknown1024b2d0 m_list70;	// 0x70
	int m_i9c;
	int m_ia0;
	int m_ia4;
	int m_ia8;
	int m_iac;
	CUnknown1024b2d0 m_listb0;	// 0xb0

	CSoundEmitterSystemBase *sub_1012dd70();
		// slot 1 (0x101b2c60, stub 0x10005597), "BaseInit"-like: when the count at +0xa8 is positive calls slot 2 (the class has no real virtuals yet: call (*(void (__fastcall **)(CSoundEmitterSystemBase *))((char *)m_vtbl + 8))(this)), sub_101b3b70(), loads "scripts/game_sounds_manifest.txt" into a new CUnknown10248a50 (g_1070b238, 0, true), for each sub key: name "precache_file" -> sub_101b4240(key->GetString(0, ""), true), "declare_file" -> sub_101b4240(key->GetString(0, ""), false), else DevWarning("CSoundEmitterSystemBase::BaseInit:  Manifest '%s' with bogus file type '%s', expecting 'declare_file' or 'precache_file'\n"); Error-like message when the file is missing; deletes the tree; DevMsg(1, "Registered %i sounds ( %i missing )") using sub_101b4740(false); returns true
	float sub_1012f720(const char *pszAttenuation);	// stub 0x10001c85: TranslateAttenuation, the attenuation of an ATTN_ name
		// empty (a plain ret), called by slot 1 before the manifest load
		// stub 0x1000924b, AddSoundsFromFile: grows the script file table (0x82 byte entries, memory +0x9c, count +0xa8), loads the script file into a CUnknown10248a50 and adds each sound record (tree at +0x50); DevMsg "No such file" (and removes the table entry again) / "Entry '%s' already exists" cases
	CSoundEmitterSystemBase *sub_1012d870(unsigned char flags);	// slot 0, scalar deleting destructor: purges the lists at +0xb0, +0x70, +0x24 and the memory blocks at +0x9c, +0x54, +0x8; deletes this when bit 0 of flags is set
	void sub_1012e970(void *pTable, const char *pszName, int value);	// interns pszName in the string table at +0xb0 and appends the 8 byte record (16 bit symbol, value) to the vector (memory at +0x20, size at +0x2c) of pTable
	int sub_1012e3f0(const char *pszName);	// index of the sound record (0xe8 bytes each, table at +0x54) named pszName, -1 when unknown
	char sub_1012e510(int index);	// true when index is within the sound record count at +0x64
	char sub_1012f1a0(int index);	// when index is valid, the byte at +0x15 of its sound record (0xe8 bytes, table at +0x54)
	void sub_1012fd30(const char *pszName);	// flags the sound record and its script file (record dword +0x18, flag table at +0x9c, 0x82 bytes each) as changed; DevWarning when there is no such sound
	int sub_1012dec0(int i);	// "CUtlRBTree::NextInorder" of the sound record tree at +0x50 (sentinel 0x1072c414)
	int sub_1012e570();	// "GetSoundCount" (stub 0x100070a9)
	const char *sub_1012e530(int index);	// "GetSoundName" (stub 0x1000e732): the name of the sound record, null when the index is invalid
	bool sub_1012fa30(const char *pszSound, const char *pszScript, const CSoundParamsFull &params);
	int sub_1012f9e0(const char *pszScript);	// the index of a script file in the manifest (stub 0x1000b113), -1 when it is not in it
		// "CSoundEmitterSystemBase::AddSound" (DevWarning format 0x10599780): 3 stack args, copies a sound record into the +0x54 table (0xe8 each at +0x14 + index*0xe8) and flags the script file in the 0x82-byte table at +0x9c; returns true
	void sub_1012e0e0(const char *pszScript, UtlMem2 *pOut);	// "GetSoundIndexesForScript"-like: clears the output vector, then appends the index of every sound record whose script file is pszScript; DevWarning "Can't PrecacheSoundScript( '%s' ), file not in manifest '%s'" when the script is unknown
	void sub_1012fda0(const char *pszSound, const char *pszScript);	// "CSoundEmitterSystemBase::MoveSound": moves the sound record to another script file of the manifest (both script flags are marked changed); DevWarning for an unknown sound or a script file that is not in the manifest
	CSoundParametersInternal *sub_1012e940(int index);	// the sound record of the index (stub 0x100130a7 is sub_101b2f60, this one is 0x10007469), null when the index is out of range
	int sub_1012e580(void *pWaves, int nStart);	// index of the first wave (from nStart) of the vector pWaves, -1 when none (stub 0x1000bfff)
	int sub_1012ec90(const char *pszName);	// stub returning 0 (ret 4)
	char sub_1012e6d0(const char *pszName, CSoundParameters &params);	// "GetParametersForSound": fills the parameters of the sound record named pszName; false (DevMsg) when it is unknown or has no wave
	int sub_1012f130(const char *pszName);	// "LookupSoundLevel"-like: the sound level of the named sound, 75 when it cannot be resolved
	const char *sub_1012f9c0(const CSoundWaveEntry *pWave);	// the wave name of an entry: looks its symbol up in the string table at +0xb0 (stub 0x10008981)
		// "CSoundEmitterSystemBase::RenameSound" (ret 8): _strcmpi equal -> nothing; sub_101b2f60(old) / sub_101b31a0 check -> DevMsg "Can't rename %s, no such sound\n"; new name known -> DevMsg "Can't rename %s to %s, new name already in list\n"; else copies the 0xe8 byte record (m_i54 table +0x14 + index * 0xe8: 8 bytes into a local, +8 into CUnknown101b6320Params::sub_101b5b70 (stub 0x10006e6f)), removes the old name from the RB tree at +0x50 (string table m_list70 = tree +0x20: sub_1024b5e0 -> CUtlRBTreeFind232::sub_101b68f0, 0x101b7970 / 0x101b7370 remove, --count at +0x64), inserts the new name (0x101b6d60, 0x101b6bd0, 0x101b6ea0, 0x101b6320), destroys two 0x14 byte CUtlVector temps (0x101b6120), sets the changed byte m_i9c[recordScript * 0x82] = 1, then two local CUtlVector purges (0x100076f8 + 0x101b6b90 + Plat_Free)
	int sub_1012f5c0(bool bVerbose);	// "CheckForMissingWavFiles": counts the sound records whose waves are not on disk ("sound/<name>" without the leading wave characters), flags them (+0x48) and DevMsg's each missing file when bVerbose
};

extern CSoundEmitterSystemBase g_105e5540;	// the sound emitter system object (at 0x1072be18, an object not a pointer; used by the "play" command 0x101b06a0 and 9 matched readers)
#endif
