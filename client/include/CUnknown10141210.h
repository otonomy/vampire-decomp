// CUnknown10141210: the element/default type of the reference table used by sub_10142620 and its siblings.
// Constructor 0x10141210, destructor 0x10141240 (registered with atexit by the function-local static's thunk
// 0x10144c70), refcount at +0x10 (sub_10141370 increments it).
#pragma once

class CUnknown10141210
{
public:
	CUnknown10141210(int n);
	~CUnknown10141210();
	void sub_10141370();
	bool sub_10141300(const char **ppHelp);
	const char *sub_10141340();
};
