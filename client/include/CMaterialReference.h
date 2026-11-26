// CMaterialReference: the SDK's materialsystem/imaterialsystem.h helper (holds one IMaterial *, IncrementReferenceCount on Init)
#pragma once

class CMaterialReference
{
public:
	CMaterialReference(const char *pMaterialName = 0);	// 0x100cd1c0
	~CMaterialReference() { sub_100cd1e0(); }
	void Init(const char *pMaterialName);	// 0x100cd1f0
	void Init(CMaterialReference &ref);	// 0x100cd240
	void sub_100cd1e0();	// jmp 0x100cd260 (Shutdown)
	void *m_pMaterial;
};
