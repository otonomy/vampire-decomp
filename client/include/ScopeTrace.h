// ScopeTrace: the engine's scope-trace helper as the game's code inlines it. The constructor pushes a
// (function name, entity name, extra) record on tier0's trace stack g_ScopeTraceStack (depth
// g_ScopeTraceStackDepth; client.dll's import slots 0x101e3124 / 0x101e3128),
// the destructor pops it, so a function that returns a value pops after the value was computed.
// Use it with the entity name expression: this ? (m_name26c ? m_name26c : g_106b8540) : g_105387dc.
// The three argument form (function, entity name, file) is the one the game keeps out of line in a function that is
// over VC6's inline budget (0x10037300, stub 0x1000c4dc).
#pragma once

struct ScopeTraceEntry
{
	const char *name;	// the function
	const char *entity;	// the entity's name
	const char *extra;	// "" or the third argument
};

extern "C" __declspec(dllimport) ScopeTraceEntry g_ScopeTraceStack[];	// tier0 (import slot 0x101e3124)
extern "C" __declspec(dllimport) int g_ScopeTraceStackDepth;	// tier0 (import slot 0x101e3128)
extern char g_102de300[];	// empty string
	// "NULL_ENTITY"

struct ScopeTrace
{
	ScopeTrace(const char *func, const char *name)
	{
		g_ScopeTraceStack[g_ScopeTraceStackDepth].name = func;
		g_ScopeTraceStack[g_ScopeTraceStackDepth].entity = name;
		g_ScopeTraceStack[g_ScopeTraceStackDepth].extra = g_102de300;
		g_ScopeTraceStackDepth++;
	}
	ScopeTrace(const char *func, const char *name, const char *line)
	{
		g_ScopeTraceStack[g_ScopeTraceStackDepth].name = func;
		g_ScopeTraceStack[g_ScopeTraceStackDepth].entity = name;
		g_ScopeTraceStack[g_ScopeTraceStackDepth].extra = line;
		g_ScopeTraceStackDepth++;
	}
	~ScopeTrace() { g_ScopeTraceStackDepth--; }
};
