// CPanelWrapper: the SDK's cl_dll/c_vguiscreen.h panel holder (Activate/Deactivate/GetPanel)
#pragma once

class CPanelWrapper
{
public:
	CPanelWrapper();	// 0x10110430
	~CPanelWrapper() { sub_10110440(); }
	void sub_10110440();	// jmp 0x10110480 (Deactivate)
	void *sub_101104a0();	// GetPanel
	void *m_pPanel;
};
