// CSmartPtr<T>: Source's reference-counting smart pointer (particles: AddRef = sub_10117fd0, Release = sub_10117fe0 on T).
// Hand-made from the inline code in C_FireSmoke::C_FireSmoke (0x100b52c0) and 0x10118820.
#pragma once

template <class T>
class CSmartPtr
{
public:
	CSmartPtr() { m_pObj = 0; }
	CSmartPtr(T *pObj) { m_pObj = 0; *this = pObj; }
	~CSmartPtr() { if (m_pObj) m_pObj->sub_10117fe0(); }

	void operator=(T *pObj)
	{
		if (pObj)
			pObj->sub_10117fd0();
		if (m_pObj)
			m_pObj->sub_10117fe0();
		m_pObj = pObj;
	}
	operator T *() const { return m_pObj; }
	T *operator->() const { return m_pObj; }

	T *m_pObj;
};
