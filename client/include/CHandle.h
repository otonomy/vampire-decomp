// CHandle<T>: the SDK's typed entity handle (ehandle.h): a CBaseHandle that converts to T * through Get().
#pragma once
#include "ehandle.h"

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
