// CSoundControllerImp: hand-made header (not the RTTI skeleton). The game's class is CSoundEnvelopeController at +0 and
// CAutoGameSystem at +4 (RTTI); only the primary vtable's slots are declared here, vfuncK at slot K.
#pragma once

struct envelopePoint_t
{
	float amplitudeMin;
	float amplitudeMax;
	float durationMin;
	float durationMax;
};

class CSoundControllerImp
{
public:
	virtual void vfunc0();
	virtual void vfunc1();
	virtual void vfunc2();
	virtual void vfunc3(void *pSound, float executeDeltaTime, int command, float commandTime, float value);	// CommandAdd
	virtual void vfunc4(void *pSound);	// CommandClear
	virtual void vfunc5(void *pSound);
	virtual struct CSoundPatch *vfunc6(void *filter, int nEntIndex, int channel, const char *pSoundName, int soundlevel);
	virtual struct CSoundPatch *vfunc7(void *filter, int nEntIndex, int channel, const char *pSoundName, float flAttenuation);
	virtual void vfunc8();
	virtual void vfunc9(void *pSound);
	virtual void vfunc10();
	virtual void vfunc11();
	virtual void vfunc12();
	virtual void vfunc13();
	virtual void vfunc14();
	virtual void vfunc15();
	virtual float vfunc16(void *pSound, int soundCommand, envelopePoint_t *points, int numPoints);	// SoundPlayEnvelope
	virtual void vfunc17();
	virtual void vfunc18();

	int m_unk04;
	int m_unk08;
	void **m_ppSounds;	// 0x0c
	int m_unk10;
	int m_unk14;
	int m_nSoundCount;	// 0x18
};
