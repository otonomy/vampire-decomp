// ehandle.h: CBaseHandle::Get (the entity-list lookup the game inlines), as CBaseHandle.h promises.
#pragma once

#include "CBaseHandle.h"
#include "CBaseEntityList.h"

extern CBaseEntityList *g_102b8e98;

inline IHandleEntity *CBaseHandle::Get() const
{
	if ( m_Index != 0xffffffff )
	{
		CBaseEntityListEntry &e = g_pEntityList->m_EntPtrArray[m_Index & 0x1fff];
		if ( e.m_SerialNumber != (int)(m_Index >> 13) )
			return 0;
		return (IHandleEntity *)e.m_pEntity;
	}
	return 0;
}
