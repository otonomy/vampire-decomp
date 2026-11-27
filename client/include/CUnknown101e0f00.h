// CUnknown101e0f00: loader of the "DisciplineTgt_" data files (real name not yet known).
#pragma once

#include "CUnknown101dbc60.h"
#include "CUnknown101dd910.h"

class CBasePlayer;
struct S1033d380;
struct CVFeatKV;
class CUnknown101e0f00;

struct CUnknown101e0f00SrcA	// an element of the first list of a source description: one particle effect
{
	int m_bFirstPerson;	// 0x00
	char m_bMarkParticle;	// 0x04: the created particle gets its byte at +0x4c5 set
	char m_bDiscipline;	// 0x05
	char m_pad0006[2];
	const char *m_pszEntity;	// 0x08: the parameter block (CUnknown100eb420) starts here
	float m_flRateMin;	// 0x0c
	float m_flOpacityMin;	// 0x10
	float m_flSizeMin;	// 0x14
	const char *m_pszParticleName;	// 0x18
	int m_nAttachType;	// 0x1c
	const char *m_pszAttachName;	// 0x20
	int m_nBitFlags;	// 0x24
	int m_nMiscFlags;	// 0x28

	void sub_10147790();	// Debug_Display (stub 0x10003143)
};

struct CUnknown101e0f00SrcB	// an element of the second list of a source description
{
	void sub_10147290();	// Debug_Display (stub 0x10006ece)
};

struct CUnknown101e0f00SrcSub	// the object at +0xc of a source description
{
	char sub_10147730();	// whether it holds a value (stub 0x10011bc6)
		// runs the list of the sub object for the owner (stub 0x10015e38)
};

struct CUnknown101e0f00Src	// the 0x1c byte source descriptions at +0xa4 / +0xc0 of an entry
{
	int m_n0000;
	int m_nA;	// 0x04
	CUnknown101e0f00SrcA **m_ppA;	// 0x08
	CUnknown101e0f00SrcSub m_sub;	// 0x0c (its size is 8)
	char m_pad000d[0x14 - 0xd];
	int m_nB;	// 0x14
	CUnknown101e0f00SrcB **m_ppB;	// 0x18

	char sub_10147be0(class IKVNodeView *pKV, const char *pszName);	// loads a source description from the node
	void sub_10147da0(const char *pszLabel);	// Debug_Display with the label (stub 0x10015d66)
	void sub_10147990();	// the constructor body (stub 0x10002036)
		// notes the hit of discipline id on a (stub 0x10012157)
		// takes the effect of discipline id back from the character (stub 0x10001212)
};

struct CUnknown101e0f00Fx	// the object the tail's callback worker hands back
{
	int m_nDamage0;	// 0x00: handed to AddDiscFlag as the extra value by the hit worker 0x101dfc20
	const char *m_pszHitGroup;	// 0x04: the hit group name (DevMsg "Discipline<%s>: HitGroup: <%s> Hit Triggered on <%s> (%s)")
	char m_sub08[0x364 - 0x08];	// 0x08: an object whose sub_101de660(pSource, pTarget, id, value) (stub 0x1001554b) the hit worker runs
	char m_sub364[8];	// 0x364: a CUnknown101ddaf0 (sub_101ddaf0(value) scales the damage)
	int m_n36c;	// 0x36c: handed to sub_101f9a40 / sub_101f9a00
	char m_b370;	// 0x370: supernatural flag A (sub_102c51a0 on the target's AI object)
	char m_b371;	// 0x371: supernatural flag B (sub_102c5310)
		// finishes the callback of a discipline (stub 0x10009372)
		// finishes the callback (stub 0x100156ea)
		// finishes the callback of a character (stub 0x1000328d)
		// finishes the callback of a hit (stub 0x100086d9)
};

struct CUnknown101e0f00Tail	// the object at +0xdc of an entry
{
		// the constructor body (stub 0x1000e124)
	void sub_10149310();	// Debug_Display (stub 0x10006a23)
	void sub_101491f0();	// resets the tail (frees its list)
	CUnknown101e0f00Fx *sub_101492b0(int a, int b, int c, int d);	// callback worker taking four values (stub 0x10015da2)
};

struct CUnknown101e0f00Entry	// one targeted discipline
{
	CUnknown101e0f00Entry(int id);
	~CUnknown101e0f00Entry();
	int m_id;	// 0x00
	const char *m_pszName;	// 0x04
	const char *m_pszInternalName;	// 0x08
	unsigned int m_nMask;	// 0x0c: 1 << id
	int m_n10;	// 0x10
	int m_n14;	// 0x14
	const char *m_pszViewModel;	// 0x18
	const char *m_pszTgtHighlightParticle;	// 0x1c
	int m_nBaseCost;	// 0x20
	char m_bOvert;	// 0x24
	char m_pad0025[0x28 - 0x25];
	int m_n28;	// 0x28: the level handed to the player's sub_1017df50
	float m_flRecoveryTime;	// 0x2c
	char m_b30;
	char m_b31;
	char m_b32;
	char m_b33;
	char m_b34;
	char m_b35;
	char m_pad0036[0x38 - 0x36];
	CUnknown101dbc60 m_range;	// 0x38
	char m_pad0060[0x68 - 0x60];
	CUnknown101dd910 m_projectile;	// 0x68
	char m_pad0078[0xa4 - 0x78];
	char m_srcInstant[0x1c];	// 0xa4: a CUnknown101e0f00Src
	char m_srcHit[0x1c];	// 0xc0: a CUnknown101e0f00Src
	char m_tail[4];	// 0xdc: a CUnknown101e0f00Tail

		// loads the entry from its "DisciplineTgt" key (the loader hands itself as the second argument)
	void sub_101496e0();	// Debug_Display of the entry (stub 0x100100fa)
	bool sub_10149450(class IKVNodeView *pKV, class CUnknown101e0f00 *pLoader);
	CUnknown101e0f00Entry *sub_10149370(int id);	// the constructor body (stub of 0x101e0520): constructs the sub objects, stores the id and its bit mask (a DevMsg "Overflowed targeted discipline" and mask 0 from id 30 up)
		// stub 0x1000da7b: the cost of the entry for the character (the character's stat 8 / 2 for the dword at +0x10, plus the dword at +0x20)
};

class CUnknown101e0f00
{
public:
	int m_n0000;
	int m_nEntries;	// 0x04
	void **m_ppEntries;	// 0x08: the entries the data files fill, one per file
	// (members not declared: +0x14 is a dword sub_101e22b0 tests for 1, +0x20 a dword sub_101e3560 clears; adding them broke 0x101e2f50)

		// stub 0x1000dba2, ret 8: "prepare the effect of discipline id on the character": the entry m_ppEntries[sub_101e12a0(id)] (nothing for -1) becomes the current entry (global 0x10739a74); unless pChar->sub_1033d2f0(id) (it already has the discipline) it AddDiscFlag(id, 0.1f, pChar, -1) (sub_1033cfb0), the entry's instant source (+0xa4) notes the hit (sub_101dd090(pChar, id)), this+0x20 = 0, pChar->AddMiscFlag(0x200000) (sub_1033c6b0); with the entry's byte +0x35 it inserts a combat sound (sub_101bac90, cdecl: type 1, pChar->vfunc220(), the int global 0x1072bc40, 0.2f, the byte global 0x1072bcb0, pChar); and for a character with the object at +0xa8, when the user message type global 0x10726054 is non-zero, sends it reliably to that player (CSingleUserRecipientFilter filter(pPlayer); filter.MakeReliable(); engine->vfunc65(&filter, g_10726054); engine->vfunc67(index of the entry); engine->vfunc66())

	void sub_10149ac0();
	bool sub_10149c30(const char *name, int *pIndex);	// opens the data file `name` (stub 0x1000bb9a) and walks its "DisciplineTgt" nodes: each node is parsed into the entry m_ppEntries[(*pIndex)++] (sub_101e08d0); false (after a Msg) when the file cannot be opened or an entry is missing
		// counts the "vdata\system\DisciplineTgt_*.txt" files, then loads each DisciplineTgt_%03d.txt (Msg when one cannot be opened)
		// the index of the entry whose internal name equals pszName (case-insensitive), -1 when none (stub 0x10004570)
		// "Targeted Discipline Manager" Debug_Display: without a name lists every entry (index, name, base cost), with the name of an entry (or "ALL") displays that entry (every entry)
	int sub_10149d80(int id);	// the index of the entry of the discipline id, -1 when none (stub 0x10007df1)
		// the entry with that index (stub 0x100123d7)
		// "CallbackHit": looks the entry of discipline c up, logs "Discipline<%s> CallbackHit", runs the entry's tail callback worker with (d, a, b, c | 0x80000000) while the global current entry (0x10739a74) points at the entry
		// the mask (+0xc) of the entry with that internal name (case-insensitive), 0 when none (stub 0x1000418d)
		// runs the "Hit" style callback for the named discipline when the character has it active
		// runs the "InterruptSchedule" callback for every active discipline (bit of the mask at +0xeb4) whose entry has the byte at +0x34 set
		// "InterruptSchedule" callback: looks the entry of discipline id up, logs "Discipline<%s> InterruptSchedule", runs the entry's tail callback worker with the character's two lookups while the global current entry (0x10739a74) points at the entry
		// "Hit" callback: looks the entry of discipline id up, logs "Discipline<%s> Hit", notes the hit on the entry's hit source (a, id), runs the entry's tail callback worker with (d, a, b, id | 0x80000000) while the global current entry (0x10739a74) points at the entry
		// id | 0x80000000, called with this in ecx (the game's member form of the free function)
	void *sub_1014a9e0(int a, int b, int c);	// the target of the source for the discipline reference (pSource, c): sub_101e28e0 of the source when the entry applies to the pair (sub_101e1a60 with 1), else 0
	void *sub_1014a9c0(void *pSource);	// the target object of the source (stub 0x10004d6d)
	int sub_10149d40(int a, int b);
	CUnknown101e0f00Entry *sub_10149ce0(int index);	// the index of the entry for a discipline reference (stub 0x100142a4), -1 when none
	char sub_1014a270(CUnknown101e0f00Entry *pEntry, void *pSource, void *pSource2, void *pTarget, char flag);	// whether the entry applies to the source / target pair (stub 0x1000b956)
		// applies the entry's effect (stub 0x1000ae07)
		// applies the effect of a mask to the pair with one more value (stub 0x1000fb4b)
		// "ActivateEffect" by reference: finds the entry, applies it to the target when sub_101e1a60 accepts the pair or the target is a CNPC_VPlayerController (dynamic cast of a CBaseCombatCharacter)
	void sub_1014aa40(int a, char *pFlag, int *pRef, unsigned int *pMask, float *pTime, int *pOut);	// "ERROR: Wpn_UpdateMode Failed!" when the reference has no entry; else hands back the entry's mask and a time of 10.0f
		// "CVTgt_DisciplineFXMgr_t::UpdateSupernaturalLevel": when the player's default stat list has a positive stat 0x19, hands the level of the "Thaumaturgy_Bloodshield" entry to the player's sub_1017df50 (time -1.0f)
		// "ActivateEffect" by discipline id (stub 0x10005c0e): prepares the pair (sub_101e3560) and applies the entry (sub_101e3730 with flag -1)
		// like sub_101e3400 but without the dynamic cast: when the entry does not apply and sub_101e22b0 holds, runs sub_101e3be0(pTarget, entry mask)
		// whether the dword at +0x14 is 1 (stub 0x100087e2)
		// stub 0x10013494
		// stub 0x1000948a: applies the entry to the character after paying nCost of stat 0xc (a user message on failure)
		// "GetTargetEntities" (stub of 0x101e2990, ret 12): pRange is an entry's m_range (+0x38): m_iSource (+4) 0 = source is the target of pCaller (sub_101e28e0 + sub_101e1a60), 1 = pCaller itself, else DevMsg "SrcType Error"; m_iAffects (+8): 0 = the single target, 1 = pCaller, 2 = every entity within m_nMaxRadius (+0x10) of the source (CGlobalEntityList::sub_100f79b0 sphere walk, entity +0x9c = its owner) accepted by sub_101e1a60(.., 0), 3 = like 2 plus CBaseCombatCharacter::sub_103268e0(origin, -0.7f); else DevMsg "AffectsType Error"; appends each entity's handle (slot 1) to the CUtlVector<CEntHandle> pOutHandles (cases 0-2 use the out-of-line AddToTail steps, case 3 the inline grow + memmove). NOTE sub_101e1a60's first parameter is then this m_range, not the entry
		// finds the entry of the discipline reference (a, b), and applies it (sub_101e2f50) when the character's stat 0xc covers its cost and the stat list 2 value of a does too; else tells the player (message 0x38)
};
