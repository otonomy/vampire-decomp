// CTextConsoleProxy: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills (vtable-slot layer, 2026-11-22)
// the destructor is slot 3 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "IMaterialProxy.h"

class C_BaseTerminal;
class IClientRenderable;

class CTextConsoleProxy : public IMaterialProxy
{
public:
	virtual ~CTextConsoleProxy();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with CTextConsoleProxy's own function
	virtual bool vfunc0(void*, void*);
	virtual void vfunc1(IClientRenderable*);
	virtual void vfunc2();
	void *m_pMaterial;
	C_BaseTerminal *m_pTerminal;
	void sub_100c8670(C_BaseTerminal *);
	void sub_100c8580(C_BaseTerminal *);
};
