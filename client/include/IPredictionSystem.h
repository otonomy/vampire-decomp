// IPredictionSystem: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor; nothing else yet
// the virtual functions before the destructor are not declared yet
#pragma once

class IPredictionSystem
{
public:
	virtual ~IPredictionSystem();
	int m_pNextSystem;
	char m_bSuppressEvent;
	int m_pSuppressHost;
	int m_nStatusPushed;
	bool CanSend() const
	{
		if (m_nStatusPushed > 0)
			return false;
		return !m_bSuppressEvent;
	}
	void * vfunc0(char);	// as in C_TempEntsSystem (transplant)
};
