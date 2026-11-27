// CVStatActionList_t: the list of actions of a stat record (placeholder layout from Debug_Display 0x1015afa0)
#pragma once

class CVStatAction_t;
class CVStatActionList_t
{
public:
	int m_unk0;
	int m_nActions;	// +4
	CVStatAction_t **m_pActions;	// +8

	void sub_1015afa0();	// "CVStatActionList_t::Debug_Display"
};
