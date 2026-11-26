// C_TEDecal: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 10 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseTempEntity.h"
#include "Vector.h"

class C_TEDecal : public C_BaseTempEntity
{
public:
	virtual ~C_TEDecal();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_TEDecal's own function
	virtual int vfunc8();
	virtual int vfunc9();
	virtual void vfunc13();
	C_TEDecal();
	virtual void PostDataUpdate(int updateType);	// IClientNetworkable slot 7: TE_Decal with a broadcast filter
	Vector m_vecOrigin;
	Vector m_vecStart;
	int m_unk28;
	int m_unk2c;
	int m_unk30;
	bool m_b34;	// TE_Decal's last argument
	char m_c35; char m_c36; char m_c37;
	int m_unk38;
};
