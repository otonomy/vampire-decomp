// CPanelMetaClassMgrImp: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor; nothing else yet
// the destructor is slot 4 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "IPanelMetaClassMgr.h"

class CPanelMetaClassMgrImp : public IPanelMetaClassMgr
{
public:
	virtual void vfunc0();
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3();
	virtual ~CPanelMetaClassMgrImp();
	void sub_101106a0(const char *pName, void *pElement);
	bool sub_101107c0(const char *pFileName, const char *pName, class CKeyValuesX *pKeyValues, int keyValueIdx);
	bool sub_10110ab0(const char *pFileName, class CKeyValuesX *pKeyValues, int keyValueIdx);
};
