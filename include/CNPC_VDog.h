// CNPC_VDog: declared by pcdecomp transplant for 0x10373570 from CPhysForce (0x10027690);
// only what matched code needs, as plain members.
#pragma once

#include "CNPC_VAnimal.h"
#include "ConVar.h"
#include "CAI_BaseNPC.h"	// NPC_STATE, AI_CONDITION_TRACE

class CEntityVSlots;
class CUnknown103160c0;	// the squad (CAI_Squad: "SquadNewEnemy")

extern ConVar g_10924a68;	// the AI condition debug convar


struct CVAnimalArg;	// a tail-call override's parameter
class CNPC_VDog : public CNPC_VAnimal
{
public:
	virtual CBaseEntity *vfunc5(unsigned int flags);
	void sub_100123af();
	void vfunc433();	// slot 433 "RunTask"-like dog check (scope: none)
	void sub_102b27f0();	// CAI_BaseNPCTroika::vfunc433 (stub 0x10013f2f), called directly
	int vfunc546(int arg);	// as in CNPC_Crow (transplant)
	int sub_10374ad0(int act);	// slot 375: nothing for activity 3, else sub_10360120
	int sub_10360120(int act);	// CNPC_VAnimal::vfunc375 (stub 0x10009872), called directly
	CNPC_VDog *sub_103734f0();	// as in CKeepUpright (transplant)
	virtual void vfunc259(int *pEvent);	// slot 259: the dog's bite on event 0xbb9 (the dog's shot when a weapon is active, then "Gots a doggie bite!"), else CNPC_VAnimal::vfunc259
	virtual void vfunc432(int a);	// slot 432: for a few activities (+0xfec) asks slot 310 for state 1 or 3 (sometimes at random), then CNPC_VAnimal::vfunc432(a)
	void vfunc103();	// slot 103: a random 0..1 second delay + curtime at +0x6674, clears +0x6688, sets three flags through sub_1026dc00 (0x4000000, 0x200000, 0x8000), then CNPC_VAnimal::vfunc103
	void sub_1026dc00(unsigned int flags);	// CAI_BaseNPC member (stub 0x10012855), called directly
	void sub_10374e50();	// state change helper of vfunc460: passes the entity behind the handle at +0x628c to slot 596, records the source line (0x52a) and state 2, and tells the active thing at +0x5da4 about the slot 167 value
	void sub_10374f40();	// the dog's bite shot (called by vfunc259): with an enemy (slot 167) and an active weapon, traces from this one's origin to the enemy's origin at the same height (mask 0x202400b) and hands the trace result to the weapon's slot 270
	CEntityVSlots *sub_1032e7b0();	// CBaseCombatCharacter::GetActiveWeapon (stub 0x10007e19), called directly
	int vfunc461();	// slot 461 "SelectIdealState" (plain member): state 1 / 3 (+0x5cc0) pick the ideal state (+0x5cc4) from conditions (0x44, 0x54, 0x46, 0x78, 0x7c, 0x7d, 0x2b, ...) and stamp the source line; else CNPC_VAnimal::vfunc461
	void sub_100041b0(int condition);	// CAI_BaseNPC condition clear (stub for sub_10269a20), called directly
	char sub_103747c0(int arg);	// returns 0 (this unused)
	int vfunc460();	// slot 460 (declared as a plain member): conditions 0x78 / 0x7e run the state change helper and answer the state at +0x5cc4; 0x79 forces state 3, 0x7c leaves state 3 for state 1 (both stamp the source line), then the Troika base
	char sub_10014df8(int condition);	// "HasCondition" (the stub at 0x10014df8 for CAI_BaseNPC::sub_10269aa0), called directly
	char sub_1001482b(int condition);	// CAI_BaseNPC condition test (the stub for sub_10269d30), called directly
	void sub_10015839(int condition);	// CAI_BaseNPC "SetCondition"-like (stub 0x10015839), called directly
	int sub_1000cc34();	// CAI_BaseNPCTroika::vfunc460 (stub 0x1000cc34), tail called
	float vfunc516();	// slot 516 (declared as a plain member): the dog's movement speed: the moving state (flag 0x2000 at +0x5d8c) uses |slot 242| times a convar value (at least 1.0f); the flag 0x8000000 at +0x14b8 gives 45.0f; else by the activity (+0xfec) 30.0f, 40.0f, a convar value or 45.0f
	int vfunc438();	// slot 438 "SelectSchedule": +0x1b2c = 0xd; condition 0x7b (cleared again) gives schedule 0x166; the dog state (+0x5cc0): 1 uses the schedule of the object at +0x6590, else 0x164 without the byte +0x63d9; 1 / 3 give 0x167 while condition 0x7d holds; 2 clears the byte +0x5b80; else CNPC_VAnimal::vfunc438 (0x6b becomes 0x164)
	void vfunc442(int *pTask);	// slot 442 "StartTask": task 0x36 (move to the enemy's last known position): AutoMovement, resets the motor's look state, looks at the enemy's last known position (queued with weight -2.0f), starts activity 0x4b and completes the movement when slot 251 holds; task 0xbc first asks slot 310 for state 3; every other task goes to CNPC_VAnimal::vfunc442
	bool sub_10280a50();	// "CAI_BaseNPC::AutoMovement" (stub 0x1000cf6d), called directly
	void sub_10289ee0(int activity);	// CAI_BaseNPC activity setter (stub 0x10014524), called directly
	void sub_10273e80(char flag);	// CAI_BaseNPC::sub_10273e80 (stub 0x1000ac68), called directly
	virtual void vfunc444(int *pTask);	// slot 444 "RunTask": tasks 2 / 0x67 in state 3 queue a look at slot 217 of the local player (weight -2.0f), then CNPC_VAnimal::sub_1035f940
	int vfunc440(int activity);	// slot 440: 0x6b gives 0x164, 0x156 gives 0x161, 0x157 gives 0x162, else CNPC_VAnimal::vfunc440 (tail called)
public:
	virtual int vfunc580();
public:
	virtual int vfunc138();
	virtual int vfunc451();
	virtual bool vfunc452();
	char sub_10374aa0(CBaseEntity *pHint);	// slot 566 (plain member): whether the hint's type at +0x5dc is 12000 (0x2ee0)

	// The members below 0x6650 belong to the NPC bases (CBaseAnimating .. CAI_BaseNPCTroika). They are declared here
	// because CNPC_VAnimal is declared on CBaseEntity, while the RTTI chain is CNPC_VDog : CNPC_VAnimal :
	// CAI_BaseNPCTroika : CAI_BaseNPC : CBaseCombatCharacter; they move to those classes with the hierarchy.
	char m_pad03e0[0xfec - 0x3e0];
	int m_Activity;	// 0xfec: CAI_BaseNPC, the current activity
	char m_pad0ff0[0x1b38 - 0xff0];
	int m_n1b38;	// 0x1b38: CAI_BaseNPC, the NPC type id (sub_1027f290 names them) of the last ideal state pick; 0xd = the dog
	const char *m_pszFile1b3c;	// 0x1b3c: CAI_BaseNPC, __FILE__ of the last ideal state change
	int m_nLine1b40;	// 0x1b40: CAI_BaseNPC, its __LINE__
	char m_pad1b44[0x5b80 - 0x1b44];
	char m_b5b80;	// 0x5b80: CAI_BaseNPC, cleared when the NPC is hurt or loses its enemy
	char m_pad5b81[0x5bb0 - 0x5b81];
	int m_n5bb0;	// 0x5bb0: CAI_BaseNPC, the squad is ignored while this count is positive
	char m_pad5bb4[0x5cc0 - 0x5bb4];
	int m_NPCState;	// 0x5cc0: CAI_BaseNPC, the NPC state (1 idle, 2 alert, 3 combat, 4 scripted, 7 dead, 8 ...)
	int m_IdealState;	// 0x5cc4: CAI_BaseNPC, the state SelectIdealState picks
	char m_pad5cc8[0x5da4 - 0x5cc8];
	CUnknown103160c0 *m_pSquad;	// 0x5da4: CAI_BaseNPC, the squad (0 when none)
	char m_pad5da8[0x628c - 0x5da8];
	EHANDLE m_h628c;	// 0x628c: CAI_BaseNPCTroika, the entity handed to slot 596 when the dog turns alert
	char m_pad6290[0x665c - 0x6290];

	// the dog's own members
	int m_n665c;	// 0x665c: the follow state toward the player (0, 1, 2)
	char m_b6660;	// 0x6660: set by slot 390 when the player hurts the dog
	char m_pad6661[0x6664 - 0x6661];
	int m_n6664;	// 0x6664
	float m_fl6668;	// 0x6668: a distance to the player
	float m_fl666c;	// 0x666c: a distance to the player (activity 0x6e)
	char m_pad6670[0x6674 - 0x6670];
	float m_fl6674;	// 0x6674: a time (slot 103: curtime + a random 0..1 s)
	float m_fl6678;	// 0x6678: a time (curtime when the dog turns to combat)
	float m_fl667c;	// 0x667c: the last distance to the player (slot 433)
	float m_fl6680;	// 0x6680: m_fl667c when the dog turns to combat
	char m_pad6684[0x6688 - 0x6684];
	int m_n6688;	// 0x6688
	char m_pad668c[0x6694 - 0x668c];

	void SetCondition(int condition) { if (g_10924a68.GetBool()) AI_CONDITION_TRACE(condition); sub_100041b0(condition); }
	CUnknown103160c0 *GetSquad() { return m_n5bb0 <= 0 ? m_pSquad : 0; }
	void SetIdealState(int state, const char *pszFile, int nLine) { m_pszFile1b3c = pszFile; m_nLine1b40 = nLine; m_IdealState = state; }	// Troika stamps __FILE__ / __LINE__ with each ideal state
public:	// tail-call overrides (the game's 5-byte jmp bodies, link audit 2026-11-18)
	virtual bool vfunc366(int, int, int);	// slot 366 (0x10374900): a tail call of CNPC_VAnimal::vfunc366
public:	// tail-call overrides (the game's 5-byte jmp bodies, link audit 2026-11-18)
	virtual void vfunc104();	// slot 104 (0x10373fe0): a tail call of CNPC_VAnimal::vfunc104
	void vfunc434();	// slot 434 (0x103748c0): a tail call of sub_10360180::vfunc434 (no such slot in this view: plain)
public:	// tail-call overrides (the game's 5-byte jmp bodies, link audit 2026-11-18)
	void vfunc463(int, int);	// slot 463 (0x10374260): a tail call of CNPC_VAnimal::vfunc463 (a base declares it plain vfunc463: this one hides it)
	void vfunc390(CVAnimalArg *);	// slot 390 (0x103748e0): a tail call of CNPC_VAnimal::vfunc390 (a base declares it plain vfunc390: this one hides it)
public:	// tail-call overrides (the game's 5-byte jmp bodies, link audit 2026-11-18)
	void vfunc144(void *p0);	// slot 144 (0x10374920): a tail call of CNPC_VAnimal::vfunc144
};
