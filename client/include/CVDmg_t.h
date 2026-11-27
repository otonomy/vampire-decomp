// CVDmg_t: damage record (no vtable known). Only what decompiled code needs.
#pragma once

struct CVDmgBlock20_t
{
	int m_a, m_b, m_c, m_d, m_e;
};

struct CVDmgBlock16_t
{
	int m_a, m_b, m_c, m_d;

#ifdef PCD_INITIALIZERS	// the initializer units: the out-of-line empty destructor 0x10310b70 (stub 0x100072d9) their globals'
				// atexit destroys jump to, and the constructor from the text form 0x10310b40
	~CVDmgBlock16_t();
	CVDmgBlock16_t(const char *pszText);
#endif
	CVDmgBlock16_t();	// calls sub_10204270 (stub 0x10004b7e, body at 0x10205380)
	CVDmgBlock16_t(int a, int b);	// calls sub_102042a0(a, b) (0x102053a0, stub 0x10004561)
		// the constructor's body (stub 0x10004b7e), called directly on a block that is a part of an int array
	void sub_10160670();	// reset: m_a = m_b = -1, m_d = 1 (stub 0x10010573)
	void sub_10160690(int a, int b);	// stores a / b in the first two fields and sets m_d to 1 (stub 0x10014290)
	bool sub_101613e0(const CVDmgBlock16_t *pOther);	// whether kind, number and multiplier (not m_c) equal pOther's
	bool sub_10160710(const CVDmgBlock16_t *pOther);
		// a copy of sub_10204360 in another unit
	char sub_10160660();	// whether the block is empty (stub 0x100051f0)
	int sub_10160b40(void *pCharacter);	// the value this block names for the character (a stat, a feat, ...; stub 0x10013cc8), 0 for an empty block or no character
		// the part of sub_10204900 for a feat block (kind 4), without the null character test: the feat record of the id (m_b) answers for the character; 0 for other kinds or an empty block
	const char *sub_10160740();	// the block's name text (stub 0x10001af0)
	int sub_10160db0(int value);	// scales value by the multiplier m_d (stub 0x1000c45f): 1 keeps it, a negative multiplier divides (negated), else multiplies
	int sub_10161510();	// the value of a block without a character (type m_a: 0 the plain number m_b, 1 the default value of the stat info record the number m_b names, 2 the value of the stat owner entry m_b, 3 zero, else -1)
	void sub_101613c0(int *pNumber);	// stub 0x10005786: sets the block from a stat info number
		// the text form (sub_10204570) then returns this (0x102053d0)
		// the text form (sub_10310b90) then returns this (0x10310b40)
		// the text copy into the block (stub 0x1000ae8e, body at 0x10310b90)
	void sub_101608a0(const char *pszText);	// stub 0x100045e3: sets the block from its text form: "<name>[ ]/<n>": the name is looked up in the stat lists (kinds 0..3), the feats (4), the reactions (5), the trait strings (8), "ObfuscateCanInc" (9, a function pointer), else a hook (global 0x1074eec4) or the empty block; a "/n" suffix makes the multiplier -n
		// stub 0x10009bba: stores the kind and a value (here a function pointer) and sets the multiplier to 1
		// stub 0x1001067c: constructs the block (the constructor, then the reset), returns this; the construction the stat owner code of the 0x10230xxx unit uses
		// stub 0x10014790: copies the first two dwords (kind and number) of pOther, returns this
		// stub 0x10009fcf: the value this block names for the character, like sub_10204900 (a copy of it in the 0x10230xxx unit)
};

// The entity handed to CVDmg_t::SetSrc (class not known): its character at +0x9c and its edict at +0x2e0.
struct CVDmgSource_t
{
	char m_pad0000[0x9c];
	void *m_pCharacter;	// 0x9c
	char m_pad00a0[0x2e0 - 0xa0];
	int m_pEdict;	// 0x2e0
};

class CVDmg_t
{
public:
	int m_pad0000;
	int m_field04;
	int m_field08;
	int m_field0c;
	int m_field10;
	CVDmgBlock16_t m_block14;	// 0x14
	CVDmgBlock16_t m_block24;	// 0x24
	int m_field34;
	int m_field38;
	float m_field3c;
	int m_field40;

	CVDmg_t();	// "CVDmg_t::CVDmg_t": constructs the two blocks, scope trace, then sets the fields to their defaults
#ifdef PCD_INITIALIZERS	// the initializer units: the array 0x108c1288 destroys its elements with it (body 0x101fa680)
	~CVDmg_t();
#endif
	int sub_10158a80();	// "CVDmg_t::GetDmg"
	int sub_10159080(int a, int b);	// "CVDmg_t::Apply": forwards to the global apply callback
	bool sub_10159170(int target);	// "CVDmg_t::EvadeCheck": forwards to the global evade callback
	void sub_101591f0(unsigned int flags);	// "CVDmg_t::AddFlags": ORs the flags into the dword at +0x40
	void sub_101587f0(CVDmg_t *pOther);	// "CVDmg_t::Copy": scope trace, copies the fields 0x00..0x34 and 0x40 of pOther (blocks of 20, 16 and 16 bytes, then two dwords)
	void sub_101588c0();	// "CVDmg_t::Null": scope trace, resets the fields (the two 16 byte blocks at +0x14 / +0x24 through sub_10204270)
		// "CVDmg_t::SetSrc": scope trace; removes the first block's value for the old source from the field at +0x4, stores the new source's edict index (IndexOfEdict) at +0x34 (0 for no source) and adds the block's value for the new source
		// "CVDmg_t::ToStr": scope trace; into the global buffer at 0x1074e5c8: "(" then the first block's name, " <field +4> <name of the damage type record>", the second block's name and " )"
		// "CVDmg_t::ToShortStr": scope trace; into the global buffer at 0x1074e2ec: "" for field +0 == -1, else " %s %d" (block name, field +4) or " %d" (field +4) when the block at +0x14 is empty
	char *sub_10159400();
	char *sub_10159260();
	static char *sub_10158c80(int flags);	// "CVDmg_t::DMGFlagsToStr": scope trace; the names of the set DMG_ flags in a static 128 byte buffer
	void sub_101589c0(struct CVDmgNewSrcX *pSrc);
	void sub_10158790();	// the destructor body (stub 0x10010956), called directly
	void sub_10158950(int a, int b, int c);	// "CVDmg_t::Set": scope trace, stores a / c / b in the fields +0 / +4 / +0x10 (the free-function form of the same address is matched as sub_101fa8d0)
	void sub_10158ef0(const char *pszText);	// "CVDmg_t::Parse": scope trace; reads "<block> <number> <damage type value> ..." from the text (space separated): the first block (a name, or the empty block when it starts with a digit), the number at +4, the damage type value at +0 and the field at +0x10, then an optional second block at +0x24; a text that is cut short nulls the record
};
