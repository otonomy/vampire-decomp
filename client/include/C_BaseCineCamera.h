// C_BaseCineCamera: skeleton from the game's RTTI (pcdecomp gdtors)
// declared: its bases, its destructor, the game's vtable slots it adds or fills on the entity chain (vtable-slot layer, 2026-11-22)
// the destructor is slot 8 of its vtable; the virtual functions before it are not declared yet
#pragma once
#include "C_BaseEntity.h"
#include "Vector.h"
#include "CBaseHandle.h"

class C_BaseCineCamera : public C_BaseEntity
{
public:
	C_BaseCineCamera();
	virtual ~C_BaseCineCamera();
public:	// vtable-slot layer (2026-11-22), from the game's vtables
	// the base slots the game's vtable fills with C_BaseCineCamera's own function
	virtual int vfunc15();
	virtual int vfunc16();
	bool sub_100019a0();
	bool sub_10001970();
	void sub_100019d0(QAngle *pAngles, Vector *pOrigin);	// the camera's angles (+0x474) and origin (+0x468)
	char m_pad0014[0x410 - 0x14];
	Vector m_v410;	// the target position
	Vector m_v41c;
	Vector m_v428;
	CBaseHandle m_h434[4];
	char m_pad0444[0x458 - 0x444];
	float m_f458;
	int m_n45c;
	int m_n460;
	char m_b464;
	char m_b465;
	char m_pad0466[2];
	Vector m_v468;	// the camera position
	Vector m_v474;
	float m_f480;
	char m_pad0484[0x490 - 0x484];
	int m_n490;
	char m_pad0494[4];
	int m_n498;
	char m_pad049c[4];
	char m_b4a0;
	char m_pad04a1[3];
	float m_f4a4;
	float m_af4a8[6];
	char m_b4c0;
	char m_ab4c1[3];
	float m_f4c4;
	float sub_10001c80(int idx, float f, float d);
	Vector sub_10001fe0(float dt);	// moves m_v468 toward m_v410, returns the new position
};
