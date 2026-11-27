// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1015b150 size=0x11c
#include "CVStatInfo_t.h"
#include "ScopeTrace.h"
struct Blk14 { void sub_10161420(); };
struct ActList { void sub_1015ab90(); };
// TARGET: ??1CVStatInfo_t@@QAE@XZ
CVStatInfo_t::~CVStatInfo_t()
{
	{
		ScopeTrace st("CVStatInfo_t::~CVStatInfo_t", g_102de300);
		delete m_pLevels;
	}
	if (m_field0138)
	{
		for (int i = 0; i < m_field0134; i++)
		{
			void *p = m_field0138[i];
			if (p)
			{
				((Blk14 *)((char *)p + 0x18))->sub_10161420();
				delete p;
			}
			m_field0138[i] = 0;
		}
		delete m_field0138;
		m_field0138 = 0;
	}
	m_field0124 = 0;
	m_field0134 = 0;
	m_field0130 = 0;
	((ActList *)((char *)this + 0x10c))->sub_1015ab90();
	((Blk14 *)((char *)this + 0x9c))->sub_10161420();
	((Blk14 *)((char *)this + 0x88))->sub_10161420();
	((Blk14 *)((char *)this + 0x74))->sub_10161420();
	((Blk14 *)((char *)this + 0x60))->sub_10161420();
	((Blk14 *)((char *)this + 0x4c))->sub_10161420();
}
// END FUNCTION
