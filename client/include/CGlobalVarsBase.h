// CGlobalVarsBase: the SDK's public/globalvars_base.h (2003 and 2004 alike), the globals the engine shares with
// client.dll. gpGlobals (0x102b8494) points at it: read gpGlobals->curtime, never a view of your own.
// The SDK's constructor and its debug-only m_bClient are left out: no initializer of the game constructs one.
#pragma once

class CSaveRestoreData;

class CGlobalVarsBase
{
public:
	float realtime;					// 0x00
	int framecount;					// 0x04
	float absoluteframetime;		// 0x08
	float curtime;					// 0x0c
	float frametime;				// 0x10
	int maxClients;					// 0x14
	int tickcount;					// 0x18
	float tick_interval;			// 0x1c
	float interpolation_amount;		// 0x20
	CSaveRestoreData *pSaveData;	// 0x24
};

extern CGlobalVarsBase *gpGlobals;
