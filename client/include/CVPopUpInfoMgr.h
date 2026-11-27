// CVPopUpInfoMgr: the character generation wizard's list of pop-up infos ("[CharGenWiz]: CVPopUpInfoMgr::Lookup").
// A CUtlVector-like list: count at +8, pointer array at +0xc. Only what decompiled code needs.
#pragma once

class CVPopUpInfoMgr
{
public:
	int m_unk00;
	int m_unk04;
	int m_nCount;\t// 0x08
	int *m_pItems;\t// 0x0c: pointers to the CVPopUpInfo records

	int sub_10142b50(const char *name, int arg);\t// \"CVPopUpInfoMgr::Lookup\": the index of a random one of the pop-ups with that name that can be displayed, -1 when none
};
