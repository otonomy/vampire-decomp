// CHandle<T>: the SDK's typed entity handle (ehandle.h): a CBaseHandle that converts to T * through Get().
// (the body of CBaseHandle::Get() lives in ehandle.h: include it in the source that uses Get)
#pragma once
#include "CBaseHandle.h"

template <class T>
class CHandle : public CBaseHandle
{
public:
	CHandle() {}
	CHandle(const CHandle<T> &other) { m_Index = other.m_Index; }
	T *Get() const { return (T *)CBaseHandle::Get(); }
	operator T *() const { return Get(); }
	bool operator==(T *val) const { return Get() == val; }
};
