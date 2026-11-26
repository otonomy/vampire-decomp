// Matched functions only. Written by pcdecomp; change it through pcdecomp.
#include "client.h"

// FUNCTION: 0x101586f0 size=0x97
#include "ScopeTrace.h"
#include "CVDmg_t.h"
extern char g_102de300[];

// TARGET: CVDmg_t::CVDmg_t
CVDmg_t::CVDmg_t()
{
    g_ScopeTraceStack[g_ScopeTraceStackDepth].name = "CVDmg_t::CVDmg_t";
    g_ScopeTraceStack[g_ScopeTraceStackDepth].entity = g_102de300;
    g_ScopeTraceStack[g_ScopeTraceStackDepth].extra = g_102de300;
    ++g_ScopeTraceStackDepth;
    m_pad0000 = -1;
    m_field10 = 0;
    m_field04 = 0;
    m_field08 = 0;
    m_field0c = 0;
    m_field34 = 0;
    m_field40 = 0;
    m_field38 = -1;
    m_field3c = 1.0f;
    --g_ScopeTraceStackDepth;
}
// END FUNCTION
