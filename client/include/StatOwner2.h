// StatOwner2: the list of VStringTable records (client.dll's g_105f93c0, vampire.dll's 0x1074e968; same layout as
// CUnknown10202d10); looked up by id or by name.
#pragma once

#include "CUnknown10202d10.h"

class StatOwner2 : public CUnknown10202d10
{
public:
	CUnknown102029c0 *sub_1015f270(int id);	// the record with that id, a shared default record when there is none
	int sub_1015f160(const char *pszName);	// the id of the record named pszName, -1 when there is none (stub 0x10012d50)
	CUnknown102029c0 *sub_1015f2f0(const char *pszName);	// the record named pszName (case-insensitive), a shared default record when there is none
	const char *sub_1015f1c0(int id, int index);	// text index of the record with that id, "" when there is none
	int sub_1015f060(void *pData, const char *pszName, int d);	// sub_1015f010(pData, pszName, "", d): creates a record, returns its id
	bool sub_1015f110(int id);	// jmp sub_1015f080: removes the record with that id
};

// the client's string tables: g_105f93c0.sub_1015f2f0("MiscStrs")->sub_1015ecd0(i), g_105f93c0.sub_1015f270(id)
extern StatOwner2 g_105f93c0;
