// CStatDefault3List: array of StatDefault3 pointers (name provisional).
#pragma once
#include "StatDefault3.h"

class CBaseCombatCharacter;

class CStatDefault3List
{
public:
	int m_allocCount;
	int m_count;
	StatDefault3 **m_pItems;

	StatDefault3 *sub_10140000(int index);
	StatDefault3 *sub_10140060(void *pChar);	// "operator[]": the item at index, or a lazily created default item when out of range
	StatDefault3 *sub_10140d50(int index);
	StatDefault3 *sub_101492b0(int index);
	StatDefault3 *sub_10149ce0(int index);
	StatDefault3 *sub_1013f8c0();	// grows by one slot and returns the (lazily created) item
		// the item of the character (stub 0x100040b1): operator[] of the index sub_10337860 finds, default item when out of range
	void sub_1013fcb0(const char *pszName, int arg);	// loads every "vdata\system\<pszName>*.txt" file (counted first with the file system's find functions): each one through sub_101d57c0, with a message for the ones that fail
	char sub_1013fac0(const char *pszFile, int arg);	// loads one template file (stub 0x10009d2c): the "ClanData" nodes fill the items from the index (*arg) on
	char sub_1013fa20(const char *pszFile);
	int sub_10157b30(const char *pszName);	// index of the clan whose name equals pszName (case-insensitive), -1 when none (stub 0x1000297d)
	int sub_10157b80(const char *pszName);
	int sub_1013fdf0(const char *pszName);
	const char *sub_1013ffa0(int index);	// the name of the clan at index (stub 0x1000ce46)
	void sub_1013fdc0();	// loads the ClanDoc and NPCTemplate template sets
};
