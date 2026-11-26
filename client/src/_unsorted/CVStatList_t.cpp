// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x1015d1e0 size=0x73
#include "ScopeTrace.h"
#include "CVStatList_t.h"
extern char g_102cc214[];
extern char g_102de300[];
CVStatList_t::CVStatList_t(int a)
{
    g_ScopeTraceStack[g_ScopeTraceStackDepth].name = g_102cc214;
    g_ScopeTraceStack[g_ScopeTraceStackDepth].entity = g_102de300;
    g_ScopeTraceStack[g_ScopeTraceStackDepth].extra = g_102de300;
    ++g_ScopeTraceStackDepth;
    m_field10 = a;
    m_field0c = 0;
    m_field04 = 0;
    m_field08 = 0;
    --g_ScopeTraceStackDepth;
}
// END FUNCTION

// FUNCTION: 0x1015d260 size=0x5f
#include "CVStatList_t.h"
#include "ScopeTrace.h"

CVStatList_t::~CVStatList_t()
{
	ScopeTrace trace("CVStatList_t::~CVStatList_t", g_102de300);
	m_field04 = 0;
}
// END FUNCTION
