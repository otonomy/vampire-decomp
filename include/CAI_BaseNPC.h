// class CAI_BaseNPC (RTTI .?AVCAI_BaseNPC@@), primary vtable 0x104995c4.
// Only the slots the decompiled members need are given their real names; the
// others are placeholders that keep the slot indices of the primary vtable.
// The vtable has at least 569 slots; add the ones past 568 as they turn up.
#pragma once

#include "Vector.h"

class CBaseEntity;
class CBaseCombatCharacter;
class CAI_Motor;
struct animevent_t;
class CAI_Senses;
class CRestore;
class CUnknown102e0150;
class CAI_Pathfinder;
class CAI_BehaviorBase;
struct CAI_NavProvider;

// The NPC states (m_NPCState at +0x5cc0, m_IdealState at +0x5cc4). Troika's numbering: combat is 2 and alert 3
// ("***Combat state with no enemy!" in state 2 falls back to 3), 4 is the scripted sequence, 7 is dead (Event_Killed).
enum NPC_STATE
{
	NPC_STATE_NONE = 0,
	NPC_STATE_IDLE = 1,
	NPC_STATE_COMBAT = 2,
	NPC_STATE_ALERT = 3,
	NPC_STATE_SCRIPT = 4,
	NPC_STATE_DEAD = 7,
};

#define CAI_NPC_V(n) virtual void vfunc##n();
#define CAI_NPC_V10(p) CAI_NPC_V(p##0) CAI_NPC_V(p##1) CAI_NPC_V(p##2) CAI_NPC_V(p##3) CAI_NPC_V(p##4) CAI_NPC_V(p##5) CAI_NPC_V(p##6) CAI_NPC_V(p##7) CAI_NPC_V(p##8) CAI_NPC_V(p##9)

class CAI_BaseNPC
{
public:
	void sub_10266780(struct CTakeDamageInfo *pInfo, const Vector *pVecDir, struct CGameTrace *pTrace);	// slot 141 body "TraceAttack"
	void sub_10265a90(CBaseEntity *pEnt);	// 0x10265a90: fires the "killed" output event at +0x5e24 with pEnt once (guard byte +0x5bd4), called by Event_Killed and CBaseCombatCharacter::CreateCorpse
	// slots 0..9
	virtual void vfunc0(); virtual void vfunc1(); virtual void vfunc2(); virtual void vfunc3(); virtual void vfunc4();
	virtual CAI_BaseNPC *vfunc5(unsigned int flags); virtual void vfunc6(); virtual void vfunc7(); virtual void vfunc8(); virtual const char **vfunc9(int *pOut);
	// slots 10..289
	CAI_NPC_V10(1) CAI_NPC_V(20) virtual void vfunc21(int a); CAI_NPC_V(22) CAI_NPC_V(23) CAI_NPC_V(24) CAI_NPC_V(25) CAI_NPC_V(26) virtual void vfunc27(int a); CAI_NPC_V(28) CAI_NPC_V(29) CAI_NPC_V10(3) CAI_NPC_V10(4) CAI_NPC_V10(5) CAI_NPC_V10(6) CAI_NPC_V10(7) CAI_NPC_V(80) virtual int vfunc81();	/* slot 81 "CBaseCombatCharacter::vfunc81"-like: an int getter (the Troika override returns 0) */ CAI_NPC_V(82) CAI_NPC_V(83) CAI_NPC_V(84) CAI_NPC_V(85) CAI_NPC_V(86) CAI_NPC_V(87) CAI_NPC_V(88) CAI_NPC_V(89) CAI_NPC_V(90) CAI_NPC_V(91) CAI_NPC_V(92) CAI_NPC_V(93) virtual int vfunc94();	// move type (5 / 6 asked by the scripted-sequence goal moves)
	CAI_NPC_V(95) CAI_NPC_V(96) CAI_NPC_V(97) CAI_NPC_V(98) CAI_NPC_V(99)
	CAI_NPC_V(100) CAI_NPC_V(101) CAI_NPC_V(102) CAI_NPC_V(103) CAI_NPC_V(104) CAI_NPC_V(105) virtual void vfunc106(const char *pszName);	/* slot 106 (+0x1a8): sets the entity name */ CAI_NPC_V(107) CAI_NPC_V(108) CAI_NPC_V(109)
	CAI_NPC_V10(11)
	CAI_NPC_V(120) CAI_NPC_V(121) CAI_NPC_V(122) CAI_NPC_V(123) CAI_NPC_V(124) CAI_NPC_V(125)
	virtual int vfunc126(class CSave *pSave);	// "CAI_BaseNPC::Save" (0x1027bc60, ret 4): pre-save: sub_101cf250(this+0x5b8c, 4) / (this+0x5db4, 3), the object at +0x5d44 (when set) sub_102e0b60, the member at +0x5cf4 sub_102e8aa0, then a stack record {short 1 (+0), flags (+4: 1 = slot 167 answers, 2 = the handle at +0x5ce4 is live, 4 = the navigator +0x5d34 answers sub_102ee6a0), name[0x80] (+8) copied from [+0x5c38]+0x40 with Q_strncpy and a CRC of [+0x5c38]+0x20 / +0x24 * 8 bits (sub_1023f040 / sub_1023f0c0 / sub_1023f060) at +0x88, both zero without a schedule} written with pSave->vfunc2(&record, 0x105cabd0), then CBaseCombatCharacter::vfunc126(pSave) (sub_10348980) and the undo calls (sub_101cf2f0 stubs 0x10015311 / sub_102e0b80 / sub_102e8ac0) as in vfunc127; returns the base result
	int sub_10348980(class CSave *pSave);	// CBaseCombatCharacter::vfunc126 (stub 0x1000e534), called directly
	virtual int vfunc127(CRestore *pRestore);	// "CAI_BaseNPC::Restore": reads the data description block at +0x19b4, CBaseCombatCharacter::vfunc127, fixes up the arrays at +0x5b8c (4) and +0x5db4 (3), the object at +0x5d44 (when set) and the member at +0x5cf4; returns the base result
	virtual char vfunc128(); CAI_NPC_V(129)
	virtual void vfunc130(int a);	// post-restore (0x1027bf50, ret 4): re-finds the saved schedule by name/CRC (see CAI_BaseNPCSavedSched.h), then CBaseCombatCharacter::vfunc130(a)
	CAI_NPC_V(131) CAI_NPC_V(132) CAI_NPC_V(133) CAI_NPC_V(134) CAI_NPC_V(135) virtual char vfunc136(); CAI_NPC_V(137) virtual int vfunc138(); CAI_NPC_V(139)
	CAI_NPC_V(140) CAI_NPC_V(141)
	virtual int vfunc142(int a);	// slot 142 (ret 4: one argument, answers in eax)
	CAI_NPC_V(143)
	virtual void vfunc144(int a);
	virtual int vfunc145();	// slot 145 "BloodColor" (the blood color at +0x1570)
	virtual void vfunc146(class CVDmg_t *pDmg, const Vector *pVecDir, struct CGameTrace *pTrace);	// slot 146 "TraceBleed"
	CAI_NPC_V(147) CAI_NPC_V(148) CAI_NPC_V(149)
	CAI_NPC_V(150) CAI_NPC_V(151) CAI_NPC_V(152) virtual int vfunc153(); CAI_NPC_V(154) CAI_NPC_V(155) CAI_NPC_V(156) CAI_NPC_V(157)
	virtual bool vfunc158();	// asked by the Troika schedule code ("slot 158 holds")
	CAI_NPC_V(159)
	CAI_NPC_V(160) CAI_NPC_V(161) CAI_NPC_V(162) CAI_NPC_V(163) CAI_NPC_V(164) CAI_NPC_V(165) CAI_NPC_V(166)
	virtual int vfunc167();	// the NPC's squad/classification id (compared between a squad member and its leader)
	virtual CBaseEntity *vfunc168();	// the entity the NPC is after (its enemy); 0 when none
	CAI_NPC_V(169)
	CAI_NPC_V10(17) CAI_NPC_V10(18)
	CAI_NPC_V(190) CAI_NPC_V(191)
	virtual Vector vfunc192();	// returns a vector by value (hidden result pointer)
	virtual Vector vfunc193(); CAI_NPC_V(194) CAI_NPC_V(195) CAI_NPC_V(196) virtual Vector vfunc197(const Vector &posSrc, int bNoisy, int bUseEye);	// slot 197: a point along the eye direction, scaled / jittered; returns by value (hidden result pointer, ret 0x10)
	CAI_NPC_V(198) CAI_NPC_V(199)
	CAI_NPC_V(200)
	virtual bool vfunc201(CBaseEntity *pEnt, int a, int *pOut, int d);	// check whether the NPC may act on pEnt (CBaseEntity::vfunc201 = sub_100a6fa0 at the end of the Troika override)
	CAI_NPC_V(202) CAI_NPC_V(203) CAI_NPC_V(204) CAI_NPC_V(205) CAI_NPC_V(206) CAI_NPC_V(207)
	virtual void vfunc208(int a);	// takes one argument (0 from AI_BaseNPC_Schedule's failure path)
	virtual CBaseEntity *vfunc209();
	void vfunc581();	// slot 581: debug text dump (DevMsg)
	void vfunc582(float flThinkTime);	// slot 582 (0x10277d90): the slow-think report (DevWarning "%.02fms", profiler clock deltas); plain member so it can be defined
	CAI_NPC_V(210) CAI_NPC_V(211) CAI_NPC_V(212) CAI_NPC_V(213) virtual float *vfunc214(); CAI_NPC_V(215) CAI_NPC_V(216)
	virtual float *vfunc217();	// "CBaseEntity::GetAbsOrigin"
	CAI_NPC_V(218) virtual float *vfunc219();
	virtual float *vfunc220();	// "CBaseEntity::GetOrigin": the pointer to the three origin floats at +0x41c
	virtual float *vfunc221();	// "CBaseEntity::GetAngles": the pointer to the three angle floats at +0x428
	CAI_NPC_V(222) CAI_NPC_V(223) CAI_NPC_V(224) CAI_NPC_V(225) CAI_NPC_V(226) CAI_NPC_V(227) CAI_NPC_V(228) CAI_NPC_V(229)
	CAI_NPC_V10(23) CAI_NPC_V10(24)
	virtual float vfunc250(int a); virtual bool vfunc251();	// slot 251 (+0x3ec): a boolean answer in al, asked by the animal task handlers (CNPC_VAnimal::vfunc444)
	CAI_NPC_V(252) CAI_NPC_V(253) CAI_NPC_V(254) CAI_NPC_V(255) CAI_NPC_V(256) CAI_NPC_V(257) virtual void vfunc258(float flInterval, CAI_BaseNPC *pNPC);	/* slot 258 (+0x408, ret 8): called by PostRun with the advance sub_1026c540 returned and this */ virtual void vfunc259(animevent_t *pEvent);	/* slot 259 "HandleAnimEvent": the animation event record at +0 of the argument is the event id */
	CAI_NPC_V(260) CAI_NPC_V(261) CAI_NPC_V(262) virtual Vector *vfunc263(Vector *pOut); CAI_NPC_V(264) CAI_NPC_V(265) CAI_NPC_V(266) CAI_NPC_V(267) CAI_NPC_V(268) CAI_NPC_V(269) virtual bool vfunc270(int a); CAI_NPC_V(271) CAI_NPC_V(272) CAI_NPC_V(273) CAI_NPC_V(274) CAI_NPC_V(275) CAI_NPC_V(276) CAI_NPC_V(277) CAI_NPC_V(278) CAI_NPC_V(279) CAI_NPC_V10(28)
	// slots 290..409
	CAI_NPC_V(290) CAI_NPC_V(291) virtual void vfunc292(struct CTakeDamageInfo *pInfo, const Vector *pVecDir, struct CGameTrace *pTrace);	// slot 292 "DamageFlinch"
	virtual int vfunc293();
	CAI_NPC_V(294) virtual bool vfunc295(CBaseCombatCharacter *pOther); CAI_NPC_V(296) CAI_NPC_V(297) CAI_NPC_V(298) CAI_NPC_V(299)
	CAI_NPC_V(300) CAI_NPC_V(301) CAI_NPC_V(302) CAI_NPC_V(303) CAI_NPC_V(304) CAI_NPC_V(305) CAI_NPC_V(306) virtual bool vfunc307();
	virtual bool vfunc308();	// asked by the Troika schedule selection (true when the NPC can take the offered action)
	CAI_NPC_V(309)
	CAI_NPC_V(310)
	virtual void vfunc311(int a, int b, int c);	// when c >= 0: stores the activity-like triple a (+0xfec/+0xff0, slot 465(a) first when it changes), b (+0x5cd0/+0x5cd4/+0xff4) and c (+0x5ccc, sub_10260a50(c)), then clears +0x6f8 and +0x170
	CAI_NPC_V(312) CAI_NPC_V(313) virtual void vfunc314(float flDeltaTime); CAI_NPC_V(315) virtual void vfunc316(void *pEnt, char bFlagA, char bFlagB); virtual bool vfunc317(int unused); CAI_NPC_V(318) virtual bool vfunc319(int a, CBaseEntity *pOther, int c);	// slot 319 (ret 0xc: three arguments, true): the Troika override re-arms the timer at +0x1564
	CAI_NPC_V(320) CAI_NPC_V(321) CAI_NPC_V(322) CAI_NPC_V(323) virtual char vfunc324(); virtual char vfunc325(); CAI_NPC_V(326) CAI_NPC_V(327) CAI_NPC_V(328) CAI_NPC_V(329)	// slots 324 / 325 (+0x510 / +0x514): boolean answers in al, asked by the Troika slot 316
	CAI_NPC_V(330) CAI_NPC_V(331) CAI_NPC_V(332) virtual void vfunc333(float flInterval); CAI_NPC_V(334) CAI_NPC_V(335) CAI_NPC_V(336) virtual char vfunc337(); CAI_NPC_V(338) CAI_NPC_V(339)
	CAI_NPC_V(340) CAI_NPC_V(341) CAI_NPC_V(342) CAI_NPC_V(343) CAI_NPC_V(344)
	virtual float vfunc345(const char *pszName, float flValue, int a);	// slot 345 (+0x564, ret 0xc): sets a pose parameter by name, returns a float
	CAI_NPC_V(346) CAI_NPC_V(347) CAI_NPC_V(348) CAI_NPC_V(349)
	CAI_NPC_V(350) CAI_NPC_V(351) CAI_NPC_V(352) CAI_NPC_V(353) CAI_NPC_V(354) virtual bool vfunc355(); CAI_NPC_V(356) CAI_NPC_V(357) CAI_NPC_V(358)
	virtual int vfunc359(CBaseEntity *pEnt);	// "GetCombatState"-like (see the Troika override)
	CAI_NPC_V(360) CAI_NPC_V(361) CAI_NPC_V(362)
	virtual char vfunc363(CBaseEntity *pEnt);	// slot 363: asked about an entity (a boolean answer in al; the alarmed check of sub_102bf5d0 passes the entity)
	virtual bool vfunc364(const float *pPosition);	// asked about a look position (true accepts it; the "FInViewCone"-like test)
	CAI_NPC_V(365) virtual bool vfunc366(int a, int b, int c);	// slot 366 "HandleInteraction" (CBaseCombatCharacter::vfunc366, 0x10326d40)
	 CAI_NPC_V(367) virtual Vector vfunc368(); CAI_NPC_V(369)
	virtual void vfunc370(int a); CAI_NPC_V(371) virtual int vfunc372(int a); CAI_NPC_V(373) CAI_NPC_V(374)
	virtual int vfunc375(int act);	// TranslateActivity step 1: the activity the NPC wants for act
	virtual int vfunc376(int act);	// the next activity of the fallback chain
	CAI_NPC_V(377) CAI_NPC_V(378)
	virtual bool vfunc379(CBaseEntity *pEnt, int b, int c, int d, int e, int f, int g);	// slot 379 (ret 0x1c: seven stack arguments): the Troika override damages pEnt with its damage records first
	virtual void vfunc380();	// slot 380: hands the entity of the handle at +0x1538 (when the dword at +0x153c is set) to the container at +0x5bf0, then CBaseCombatCharacter::vfunc380, slot 416(0) and sub_10007ea0
	virtual int vfunc381(int act);	// resolves an activity to the sequence/activity the model really has
	virtual char vfunc382(void *pWeapon);
	virtual void vfunc383(void *pWeapon, int a);	// "Weapon_Equip"-like: equips the given weapon (the Spawn of the NPCs equips the weapon named by the field at +0x5dec)
	CAI_NPC_V(384) virtual void vfunc385(void *a, int b, int c); CAI_NPC_V(386) CAI_NPC_V(387) CAI_NPC_V(388) virtual void vfunc389(Vector *pOut, const Vector *pIn);
	virtual int vfunc390(struct CTakeDamageInfo *pInfo);	// slot 390 (ret 4, answers in eax; 0x10265ed0 = CAI_BaseNPC, 0x103302e0 = CBaseCombatCharacter): the take-damage reaction, true when the character takes the hit; the Troika override (0x102beda0) first stores a copy of the record at +0x660c
	virtual int vfunc391(int a);	// slot 391 "OnTakeDamage_Dying" (CBaseCombatCharacter::vfunc391, 0x103315e0)
	 virtual int vfunc392(struct CTakeDamageInfo *pInfo); CAI_NPC_V(393) virtual char vfunc394(); CAI_NPC_V(395) CAI_NPC_V(396) CAI_NPC_V(397) virtual char vfunc398(); CAI_NPC_V(399)
	CAI_NPC_V(400) CAI_NPC_V(401) virtual char vfunc402();	// slot 402: asks slot 394; when it holds either removes the NPC (slot 398 false: sub_101cd940) or, with slot 398 true, hands the field at +0xfd0 to sub_100544f0, runs slot 77 and slot 395; without it only slot 395; returns the answer of slot 394
	CAI_NPC_V(403)
	virtual int vfunc404(CBaseEntity *pEnt);	// classification of pEnt (vfunc468 treats 1 and 2 as true)
	virtual int vfunc405(CBaseEntity *pEnt);	// relation priority of pEnt (vfunc469 compares < 0 / > 10; 0x10089fc0 prints it)
	virtual const char *vfunc406(int state);	// slot 406 (+0x658): the name of an NPC state (debug text "State: %s, ", asked with the state at +0x5cc0)
	virtual const char *vfunc407(int moveType);	// slot 407 (+0x65c): the name of a move type ("Move: %s, ", asked with the result of sub_1027d990)
	virtual const char *vfunc408(int state);	// slot 408: like slot 406 (the state name of the argument)
	virtual int vfunc409();	// slot 409 (+0x664): the number of states
	int sub_1027d990();	// stub 0x100023a1: the move type
	float sub_10272ab0(const Vector *A, const Vector *B, float flGrav, float flD, const Vector *mins, const Vector *maxs, int pIgnore, Vector *out, int *pHit);
	bool sub_10279420();
	// slots 410..482
	virtual int vfunc410(int a);	// slot 410 (ret 4): returns its argument
	CAI_NPC_V(411) CAI_NPC_V(412) CAI_NPC_V(413) CAI_NPC_V(414) CAI_NPC_V(415)
	virtual void vfunc416(char value);
	virtual char vfunc417();	// slot 417 (plain member): returns 0
	virtual float vfunc418(float a);	// float lookup keyed by magic values (-1000005..-1000008 in the Troika override), else the base value
	CAI_NPC_V(419) CAI_NPC_V(420) CAI_NPC_V(421) CAI_NPC_V(422)
	virtual unsigned int vfunc423();
	virtual bool vfunc424();	// "CAI_BaseNPC::CreateComponents": asks slots 425 (senses, +0x5cdc), 427 (motor, +0x5d44), 428 (local navigator, +0x5d38), 426 (move probe, +0x5d40), 429 (navigator, +0x5d34) and 430 (pathfinder, +0x5d3c) for a component each and gives up (false) at the first that is missing; then points the components at each other (motor <- local navigator <- navigator, the navigator's slot 3 gets the global at 0x1093407c)
	virtual CAI_Senses *vfunc425();	// "CAI_BaseNPC::CreateSenses": a new CAI_Senses (constructor inlined) whose owner is this NPC
	CAI_NPC_V(426)
	virtual CAI_Motor *vfunc427();	// creates the NPC's motor (operator new, then CAI_Motor::sub_102e0900(this))
	virtual class CAI_LocalNavigator *vfunc428();	// "CreateLocalNavigator": operator new(0x20), then the CAI_LocalNavigator constructor at 0x102ddab0 with this as outer
	virtual class CAI_Navigator *vfunc429();	// "CreateNavigator": operator new(0x68), then the CAI_Navigator constructor at 0x102eca50 with this as outer
	
	virtual CAI_Pathfinder *vfunc430(); virtual void vfunc431();	// slot 431 "CAI_BaseNPC::NPCThink" (0x1026ca80, no stack arguments): scope trace (entity name or "NULL ENTITY" for a null this); byte +0x5b55 set -> cleared and sub_1027efb0(); sub_1026a0f0() (CAI_BaseNPCUnit, stub 0x100056fa); next think +0x17c = (float)(curtime + 0.1) (double constant 0x104493d0); only when the global 0x10934088 is set and its byte +0x658: VPROF scope "CAI_BaseNPC_NPCThink" (group "Unaccounted") on g_109f3648, entered with the imported CVProfNode::EnterScope (call [0x109f3664], not inlined); if !sub_1026c3d0() (stub 0x100155d7, char) the scope is left with the imported ExitScope (call [0x109f3654]) and the function returns; else unless the handle at +0x1538 resolves to a non-null entity with +0x153c == 1 slot 432(0) runs, then sub_1026c120(sub_1026c7c0() (PostRun, float in st0), 0) (PerformMovement) and the profile scope is left with the inlined rdtsc ExitScope tail (same idiom as the matched sub_1026c120)
	virtual void vfunc432(char bSkip);	// CAI_BaseNPC::RunAI: profiled and scope-traced
	CAI_NPC_V(433) CAI_NPC_V(434)
	virtual void vfunc435(void *pSchedule);	// called with the new schedule by sub_10280e50
	CAI_NPC_V(436)
	virtual int vfunc437();	// "SelectFailSchedule"-like (AI_BaseNPC_Schedule.cpp): returns a schedule id picked from the failure conditions
	virtual int vfunc438();	// "SelectSchedule": returns the schedule id
	CAI_NPC_V(439)
	CAI_NPC_V(440) CAI_NPC_V(441) int vfunc441(int a); CAI_NPC_V(442) CAI_NPC_V(443) virtual void vfunc444(void *pTask); CAI_NPC_V(445)
	virtual int vfunc446(int condition);	// "SetCondition" with translation: ids below 1000000000 (and -1) go through the condition table of slot 580 first; a missing schedule warns "ERROR: %s missing schedule" and sets condition 1
	virtual int vfunc447(int a);	// classification of a (the dword at +0x1c of the object at +0x5c38); 0x12f is the special case of vfunc509
	virtual void vfunc448(int a);	// "CAI_BaseNPC::TaskFail": remembers the failure code (+0x5c50), name text (+0x5f30) and failing task (+0x5c38 -> +0x5f38) unless the AI system is paused, clears +0x1a40, then sub_10269a20(0x5c)
	virtual int vfunc449(int a);	// returns a task/schedule id for the argument (used by PrintTask)
	CAI_NPC_V(450)
	virtual const char *vfunc451();	// the NPC's name text (used in warnings)
	virtual bool vfunc452(); CAI_NPC_V(453) virtual int vfunc454(); CAI_NPC_V(455)
	virtual CAI_BehaviorBase **vfunc456();	// the list of the NPC's behaviours (CAI_StandoffGoal walks it with slot 457)
	virtual int vfunc457();	// the number of behaviours in that list
	CAI_NPC_V(458) CAI_NPC_V(459)
	virtual int vfunc460();	// SelectIdealState helper: the NPC's current state, 0 when unset
	virtual int vfunc461();	// SelectIdealState
	virtual char vfunc462();
	virtual void vfunc463(int a, int type);	// "CAI_BaseNPC::SetIdealActivityForType": stores a value picked by `type` (0..14) at +0x5b64
	virtual int vfunc464();	// GetState: the NPC state (7 is dead; used by CAI_GoalEntity::PruneActors)
	virtual void vfunc465(int a);	// called by vfunc311 when the value at +0xfec changes
	virtual bool vfunc466();	// asked by MaintainActivity: whether the NPC may update its activity
	CAI_NPC_V(467)
	virtual bool vfunc468(CBaseEntity *pEnt);	// Troika override: false when pEnt is the NPC's own target or is ignored, true when it has the field at +0xa8 or vfunc404 gives 1 or 2
	virtual void vfunc469(int unused);	// slot 469 "CAI_BaseNPC::Look" (0x1026a2c0, ret 4, the argument is unused): ClearConditions-like sub_10269bd0(0x105c979c table, 6); the leader entity is found from the object at +0x98 (slot 586(&tmp) handle through LookupEntity sub_100290c0, else, with bit 22 of its flags +0x14b8, its handle at +0x608c); then for each entity the senses object at +0x5cdc yields (S1030fc90::sub_1030fc90 begin via sub_102707d0, sub_1030fd20 next) except the leader: type = slot 404(ent); an entity with the field +0xa8 sets condition 0x5a through the dev flag object (global 0x10924a6c slot 1) and, with +0x9c set and the byte +0x1480, calls CUnknown1017fd60::sub_1017ff40(obj98, type); type 4 stops; the slot 167 entity sets condition 0x46; type 1 (unless class flags +0x14bc bit 16): slot 405(ent) < 0 -> handle to +0x5b70, condition 0x45; > 10 -> +0x5b74, 0x5b; else +0x5b68, 0x43; then slot 544(ent, ent slot 217 of ent+0x3d4); type 2 (unless the same flag): +0x5b6c = handle, slot 544 likewise, condition 0x44; types 3, 4 nothing; other types DevWarning(2, "%s can't assess %s\n", debug names of ent and this) (jump table over type - 1, cases 1 and 2 share code)
	CAI_NPC_V(470)
	virtual float vfunc471();	// a random float between 0.2 and 0.9 (the engine random stream's RandomFloat)
	virtual void vfunc472(CBaseEntity *pEnt);
	virtual int vfunc473(); virtual void *vfunc474(); CAI_NPC_V(475) CAI_NPC_V(476) CAI_NPC_V(477) virtual CBaseEntity *vfunc478(); virtual bool vfunc479(CBaseEntity *pEnt);
	virtual bool vfunc480();	// "CAI_BaseNPC::...": false while bit 16 of the flags at +0x14bc is set; true without a slot 167 object, when it is not usable (slot 158), or when the memory list (slot 541) flags it; else whether one of the conditions 0x43, 0x45, 0x5b, 0x58 holds
	virtual void vfunc481(int a); virtual int vfunc482(int a);	// slot 482: asked of another NPC with the value slot 585 returns, nonzero accepts
	virtual void vfunc483(int unused);
	// slots 484..567
	virtual int vfunc484(const char *pszSample, int unused, float flVolume, int iSoundLevel, int unused2);	// "CAI_BaseNPC::EmitSound"-like: -1 for a null name or while slot 158 is false; a '!' name is a sentence (looked up by sub_101af070, emitted to a CPASAttenuationFilter through the engine sound object's slot 4, returns the sentence index), else the entity's edict (+0x2e0) emits the sample (sub_101aeb60); pitch 100
	virtual void vfunc485(const char *pszSample, int a, float flVolume, int b, int c, int d);	// slot 485 (ret 0x18, six arguments): forwards the first four to slot 484 with a zero fifth argument (the last two are unused)
	virtual bool vfunc486(); CAI_NPC_V(487) CAI_NPC_V(488) CAI_NPC_V(489)
	CAI_NPC_V10(49)
	CAI_NPC_V(500) CAI_NPC_V(501) CAI_NPC_V(502) CAI_NPC_V(503) CAI_NPC_V(504) CAI_NPC_V(505) CAI_NPC_V(506) CAI_NPC_V(507) virtual void vfunc508(int a);
	virtual bool vfunc509();	// true when the NPC may start the idle/engine request (state 1 or 3, flag bits clear, no live dialog partner, not busy)
	virtual bool vfunc510();
	CAI_NPC_V(511) virtual int vfunc512();
	virtual unsigned int vfunc513();	// the NPC's class flags (bit 26 marks the NPCs that must be in a squad)
	CAI_NPC_V(514) bool vfunc514(int a, int b, int c, int d);	// slot 514: always false (ret 0x10)
	CAI_NPC_V(515)
	virtual float vfunc516();
	CAI_NPC_V(517) CAI_NPC_V(518)
	virtual void vfunc519(int a, float b, float c, float d);	// when the debug convar is set, forwards to slot 14 of the object at +0x5d44
	virtual float vfunc520(int a);	// forwards a to slot 15 of the object pointed to at +0x5d44 and returns its float result
	CAI_NPC_V(521) void vfunc521(int a, int b, int c); void sub_1001484e(int a, int b, int c, float d, float e, float f); virtual float vfunc522(); CAI_NPC_V(523) CAI_NPC_V(524) CAI_NPC_V(525) virtual bool vfunc526(void *pGoal, float flInterval);
	virtual bool vfunc527(CAI_NavProvider *pNode);	// slot 527 (+0x83c): asked about a node of the network (CAI_NavProvider, see CAI_Navigator.h); true when this NPC may not use it. Troika override: sub_102d1540. Called by sub_1027db30 and by the nearest-node search 0x102f3c10
	CAI_NPC_V(528)
	virtual bool vfunc529();	// slot 529 (offset 0x844): a boolean answer in al, asked by the navigator after it finishes a move
	virtual bool vfunc530(CBaseEntity *pEnt);	// slot 530: walks the 20 byte records of the list at +0x5d48 (count +0x5d54; handle, expiry time, position) from the back: stale handles are dropped (the last record moved over them), the record of pEnt is kept (true) while its expiry is not passed and pEnt is within 120 units of the stored position, else dropped (false); false when pEnt has no record
	CAI_NPC_V(531) CAI_NPC_V(532)
	virtual Vector vfunc533(int a, int b);	// slot 533 (ret 0xc: hidden result pointer, two arguments): a position vector for an activity (the Troika override moves it to the hint node's position while the NPC works at a hint)
	virtual CBaseEntity *vfunc534();	// slot 534: the nearest visible entity within 1024 units that has an AI or is flagged as a character, found again at most every 1..5 seconds (time at +0x5d6c) and remembered by handle (+0xe64); returns the remembered entity
	CAI_NPC_V(535) virtual void vfunc536(int a, int b, int c, int d); CAI_NPC_V(537) CAI_NPC_V(538)
	virtual void vfunc539(const Vector *pDir);	// sets the aim_pitch / aim_yaw pose parameters from the angles of a direction (sub_10139970)
	CAI_NPC_V(540) void vfunc540(const char *pszScene);	// slot 540 (plain overload): sub_10084b40(this, pszScene, 0)
	virtual CUnknown102e0150 *vfunc541();	// the NPC's memory list (the same object type as CUnknown102dfc10: nodes at +0xc linked through +0x38)
	virtual void vfunc542();
	CAI_NPC_V(543)
	virtual char vfunc544(CBaseEntity *pEnt, int a, int b);	// slot 544 (ret 0xc): 1 without a memory list (slot 541); false when pEnt's squad owner is this NPC's squad owner (both counts <= 0); otherwise lets the memory list note pEnt (sub_102e0210, then slot 494 on a hit) and returns the memory list's sub_102df700(object at +0x5d34's +0x2c, pEnt, a, b)
	virtual bool vfunc545();	// finds the squad (+0x5da4) from the name at +0x5da8 when the class flags ask for one; true when it has one
	CAI_NPC_V(546) CAI_NPC_V(547) CAI_NPC_V(548) CAI_NPC_V(549)
	virtual float vfunc550(); virtual void vfunc551(int a, int b);
	virtual unsigned int vfunc552();
	virtual int vfunc553(float a, float b);	// slot 553: an activity picked by the float b (< 100: 8, < 200: 0x5f, > 1024: 0x60) else 0x4f / 0x61 by the float a against 0.5
	virtual int vfunc554(float a, float b);	// slot 554: an activity picked by the float b (< 64: 8, > 512: 0x60) else 0x61 / 0x50 by the float a against 0.5
	virtual int vfunc555(float a, float b);	// slot 555: an activity picked by the float b (> 256: 9, > 64: 0x60) else 0 / 0x51 by the float a against 0.7, the slot 167 object and its object at +0x9c (slot 327)
	virtual int vfunc556(float a, float b);	// slot 556: an activity picked by the float b (> 180: 9, > 64: 0x60) else 0 / 0x52 by the float a against 0.7 and the focus entity's object (slot 327)
	virtual char vfunc557(); CAI_NPC_V(558)
	virtual CBaseEntity *vfunc559(const char *pszName);	// slot 559: the entity of that name (asked by the follow-target setter)
	virtual void vfunc560();	// slot 560: sets the conditions 0x4f..0x52, 0x2e, 0x2f and 0x62..0x66 (sub_10269b50 each)
	virtual void vfunc561(CAI_BaseNPC *pOther, float flDist);	// slot 561 "GatherAttackConditions"
	virtual char vfunc562(int a, int b, char bFlag);	// slot 562 (ret 0xc): lets the active weapon (slot 364) answer, else, for NPCs with class flag 0x20000, slot 573; without either a TaskFail(0x42) when bFlag; with class flag 0x10000000 and sub_10266b10(a, b, 0.92f) true a TaskFail(0x64) when bFlag and false; else the answer
	virtual void vfunc563(CBaseEntity *pEnt, const void *pGoal, const void *pParams, const void *pExtra);	// slot 563: takes the entity, a vector (the goal's destination), a movement parameter block (8 dwords) and the address of a stack value
	virtual bool vfunc564();	// slot 564: false in states 3 and 1 and while condition 0x46 is clear or 0x55 set
	CAI_NPC_V(565)
	virtual bool vfunc566(CBaseEntity *pHint);	// "FValidateHintType": whether the hint (its groups at +0x470 against the NPC's usable groups, its type at +0x5dc) is one this NPC can use
	virtual int vfunc567(int unused);
	virtual float vfunc568(int a);
	int vfunc570(CBaseEntity *pHint);	// slot 570: the activity for a hint entity (plain member so the slot numbers do not shift)
	void sub_1028e480(CBaseEntity *pEnt);	// 0x1028e480 (ret 4): the navigator move check run by GatherConditions
	void sub_1026b580(int nDir, Vector *pOut);
	int vfunc571(float f);	// slot 571 (plain member so the derived slots keep their numbers): 9 when f < 190.0f, else 0x13
	bool vfunc575();	// slot 575: bit 6 of the class flags (plain member so the declared base slots do not shift)
	int vfunc576(float a, int unused);	// slot 576: true when the float is above 0.0f
	void vfunc518(int a, float b, float c, float d);	// slot 518 (plain overload of the placeholder): forwards to slot 13 of the motor at +0x5d44 when the global at 0x10924f74 allows
	int vfunc450(int a);	// slot 450 (plain overload of the placeholder slot): translates a schedule id through slot 580 + 0x18
	void vfunc517(int a, int b, float c, float d, float e);	// slot 517 (plain overload): forwards the five arguments to slot 12 of the motor at +0x5d44 when the convar-like global 0x10924f74 allows it

	void vfunc310(int act);	// slot 310 (plain overload of the placeholder slot, ret 4): switches the ideal activity (+0xff0) unless it is the current one (+0xfec) or the NPC is in activity 2 and act is not 0, then sub_10272130 / sub_10272490
	int vfunc440(int schedule);	// slot 440 "TranslateSchedule" base implementation (declared as a plain member like the subclasses' overrides): schedule 0x2e (a failed scripted sequence) becomes 0x2f..0x33 by the move type at +0x5f60 of the scripted sequence entity (handle at +0x5d74), after a DevWarning when that entity is gone; unchanged otherwise
	float sub_1026c7c0();	// "CAI_BaseNPC::PostRun" (VPROF "CAI_BaseNPC_PostRun"/"Unaccounted", cycle counter global 0x1090ff00; same scaffolding as sub_1026c120): f = sub_1026c540(); slot 258(f, this); sub_1032aa40(); returns f
	int sub_1032aa40();	// CBaseCombatCharacter member (stub 0x1000acf4), called by PostRun
	void vfunc481(CBaseEntity *pEnemy);	// slot 481 "CAI_BaseNPC_GatherEnemyConditions" (0x10270b20, ret 4; plain member, fields in CAI_BaseNPC_vfunc481.h)
	CAI_BaseNPC *sub_1027c300();	// constructor body 0x1027c300 (returns this; called by the NPC constructors 0x101a62d0, 0x10260b30, 0x1028d230, aitesthull, monster_generic, scripted_target, CNPC_Bullseye, npc_crow ...): base ctor CBaseCombatCharacter 0x10326de0; IAI_MovementSink at +0x19b0 (vptr CAI_DefMovementSink 0x1049a0cc then CAI_BaseNPC 0x10499594; word +0x19b4 = 1, dword +0x19b8 = 0); 0x101c2690 object +0x1a48; -1 at +0x1a94; 0x102cc670 objects +0x1a9c, +0x1ae0; -1 at +0x5b68..+0x5b7c, +0x5ba8; COutputEvent x4 at +0x5bd8 (step 0x18); 0x1027f610 objects (condition bit vectors) +0x5c5c, +0x5c74, +0x5c8c, +0x5ca8; -1 at +0x5ce0, +0x5ce4, +0x5d00, +0x5d24..+0x5d2c, +0x5d74, +0x5d90, +0x5dac; +0x5cf4 CAI_MoveAndShootOverlay vptr 0x1049a0b8; record vector at +0x5d48 (ptr, grow 4, count; Plat_Alloc(0x50) = 4 records of 20 bytes, +0x5d58 copy, +0x5d5c = -1.0f); COutputEvent x12 at +0x5e0c..+0x5f14 (step 0x18); flags |= 0x20 at +0x4c; vptr 0x104995c4 at +0; 0x1000 dwords cleared at +0x1b4e; navigator-ish pointers +0x5d34, +0x5d38, +0x5d3c, +0x5d40, +0x5d44 = 0; operator new(0x14) + 0x102e06f0 at +0x5d88; 0.95f at +0xe3c; sub_10279cc0(0); bytes 1 at +0x5f2c / +0x5f2d; 0.3f / 0.5f at +0x5bbc / +0x5bc0; global 0x105c9798 = 0; g_1090fe10.AddToTail(this) (CUtlVector4::sub_10265310); sub_100aaa40(7) (SetCollisionGroup); +0x94 = this; +0x158c = 2; byte +0x5bd4 = 0
	void sub_1027c820();	// destructor body (called by the vfunc5 deleting destructors and CCineNPC / CGenericNPC ...): vptr 0x104995c4, second vptr 0x10499594 at +0x19b0, sub_102653f0(this), sub_10273e40; deletes (slot 0 with 1) the owned objects at +0x5d3c, +0x5d34, +0x5d44, +0x5d38, +0x5d40, +0x5cdc in that order when set; ~COutputEvent (sub_100cd2d0) of the 12 outputs +0x5f14 down to +0x5e0c step 0x18 (descending); CUtlVector at +0x5d48 (size +0x5d54 zeroed, sub_1027faa0, Plat_Free chain); CAI_Component vptr 0x1049a0f8 at +0x5cf4; outputs +0x5c20, +0x5c08, +0x5bf0, +0x5bd8; sub_102cc6a0 on the members at +0x1ae0 and +0x1a9c; tail jmp 0x100078c4 -> CBaseCombatCharacter body 0x103274d0
	void *&Owned5d3c() { return *(void **)((char *)this + 0x5d3c); }	// pathfinder (created by slot 430)
	void *&Owned5d34() { return *(void **)((char *)this + 0x5d34); }	// navigator
	void *&Owned5d44() { return *(void **)((char *)this + 0x5d44); }	// motor
	void *&Owned5d38() { return *(void **)((char *)this + 0x5d38); }	// local navigator
	void *&Owned5d40() { return *(void **)((char *)this + 0x5d40); }	// move probe
	void *&Owned5cdc() { return *(void **)((char *)this + 0x5cdc); }	// senses
	void sub_1027d170();	// stub 0x100119b9: run by vfunc440 when the scripted sequence entity is gone, before schedule 1 is asked for
	void sub_1027f270(int nState);	// stub 0x10005cc2, ret 4: called by CCineNPC::sub_101a8640 with 2 right before the movement state at +0x5d70 is set to 2
	void sub_10270aa0(CBaseEntity *pEnt);	// stores pEnt's entity handle at +0x5d90 (-1 for null)
	void sub_10269a20(int a);	// stub 0x100041b0, run by TaskFail with 0x5c
	bool sub_10269c70(int condition);
	bool sub_10280360();
	void sub_1026af70(const float *pTargetPos, float flInterval);	// slot 537 body (0x1026af70, ret 8): smooths the look yaw (+0xe5c) and pitch (+0xe60) bone controllers toward pTargetPos; declared as a plain member because retyping the placeholder virtual vfunc537() breaks matched vtable users
	void sub_1026d460(int nSide);	// footstep: picks volume / sound level from the surface data or convars by nSide, emits the sound the sound table gives for the record at +0x5b90 to a CPASAttenuationFilter (called by vfunc259)
	bool sub_10273180(char bForce);
	void sub_1026ab50();
	void sub_10273070(char bForce);	// sets the hull size from the hull (+0x1568) when the byte +0x5f2d is clear or bForce, sets the byte, then runs sub_10272f40 with a navigator at +0x36c; always true
	void sub_10272f40();	// the navigator hand-over after the hull is set (stub 0x100081c0)
	void sub_10269b50(int condition);	// "CAI_BaseNPC::SetCondition"-like (called through the stub at 0x10015839)
	bool sub_10269aa0(int condition);	// "CAI_BaseNPC::HasCondition" (stub 0x10014df8): translates ids below 1000000000 first, then tests the condition bit in the array at +0x5c5c
	bool sub_10269d30(int condition);	// "CAI_BaseNPC::HasConditionAndNotIgnored" (0x10269d30): false without a schedule (+0x5c38), else the condition (ids below 1000000000 translated through slot 580) must have its bit set in both +0x5c5c and +0x5c74
	void sub_1026e5e0();	// "CAI_BaseNPC::CheckOnGround" (0x1026e5e0): ground trace / condition 0x73 update run by GatherConditions
	void sub_10273390();	// 0x10273390: the body behind vtable slot 420 (a Spawn/Initialize router, line 0x1af1)
	bool sub_10279dd0();	// "CAI_BaseNPC::ChooseEnemy" (0x10279dd0): the enemy selection worker (memory list / conditions 0x54 / 0x47 / 0x58)
	int vfunc458(int condition);	// slot 458 (plain member): ids below 1000000000 (and -1) are translated through slot 580 first, then the (translated) id goes to the global 0x109203dc's sub_102ea020 (a name / id lookup)
	void sub_10269bd0(int *pConditions, int nConditions);	// "CAI_BaseNPC::ClearConditions": clears the condition bits (array at +0x5c5c) of each id, translating ids below 1000000000 first through slot 580
	void sub_1026e340(int newState);	// "CAI_BaseNPC::SetState": stores the state at +0x5cc0/+0x5cc4 (curtime at +0x5cc8 on a change), strips the weapon of an NPC in state 1 that slot 167 flags, then calls slot 463(old, new)
	void sub_1028e090(void *pModel);  // stub 0x1000944e: called by sub_1028e060 with the model pointer of the object (GetModelPtr of the entity at its +0x0)
	void sub_1028e060();  // the model-dependent setup: when the object of sub_10007e19 exists, hands its model pointer (GetModelPtr(-1)) to sub_1028e090
	void sub_10279c90();  // the caller of CUnknown102e0150::sub_102e0210: asks slot 167 for an id and slot 541 for the memory list, then tests the id on the list
	void sub_10279a50(int a);	// called through the stub at 0x1000b974 by SetState with 0
	void sub_10260a50(int c);	// called through the stub at 0x1000d0b2 by vfunc311 with its third argument
	void sub_10273e80(char flag);	// sets the state at +0x5c44 to 4 unless flag is clear and a check (0x5c) passes (called with 0 by animation event handlers)
	void sub_10274080(CBaseEntity *pEnt);	// enemy memory update: finds pEnt's record in the 20-byte record vector at +0x5d48 (handle, time, position) and refreshes its time, or appends a new one; then stores pEnt's absolute origin in it
	int sub_10274aa0(void *pOther);	// slot 569: picks an activity-like index (1, 6, 7 or 8) from SelectWeightedSequence results and pOther's state at +0x5dc
	int sub_1026f4d0();	// clears the path/schedule fields, then (for NPCs flagged 0x20000) selects the fail schedule by the state of vfunc460
	void sub_1028ae60();	// releases the occupied slot (bit +0x5dac in the bitmask of the owner at +0x5da4) and resets the slot index to -1
	bool sub_1028ad20(int slotIDStart, int slotIDEnd);	// "CAI_BaseNPC::OccupyStrategySlotRange": true when the NPC has no owner (squad) or another class than the leader; else keeps/gets a free slot of the range in the owner's bitmask (at +0x6c), false when none is free
	int sub_10271ff0(int act, int *pOut);	// "CAI_BaseNPC::TranslateActivity": walks the activity fallback chain (slots 375/376/381, at most 5 steps) and returns the first activity the model has a sequence for
	bool sub_102d1350(CBaseEntity *pEnt);	// stores pEnt's handle at +0x5e0 unless a different live entity is already stored (then false)
	void sub_10280e50(void *pSchedule);	// "CAI_BaseNPC::SetSchedule": calls slot 435(pSchedule), resets the schedule bookkeeping at +0x5bb8/+0x5c38.., stamps curtime, may start the idle state; prints "Schedule: %s" when flag 0x8000000 is set at +0x224
	void sub_10182c40(const char *text, const char *sound);	// copies text into a global buffer (+0x1ca4 = the buffer, or null when empty), stamps curtime - 0.5 at +0x1ca8, then moves that time forward by the sound's duration (when the dialog partner at +0xfe8 has the object at +0x98) or by 0.6, and sets bit 0 of +0x1cac
	void sub_101828b0(CBaseEntity *pEnt, float flScore);	// keeps the best candidate (handle +0x1cc0, score +0x1cc4, stamp +0x1cc8; reset to -1 / 99999.9 / 0 when the stored entity is gone or no longer alive): pEnt replaces it when its score is lower and it is alive, not flagged 0x40 at +0x19c, has a sequence, answers slot 404 with 1, is not slot 293's value and fails sub_100b5190; the same entity just refreshes score and stamp
	int sub_10182a90();	// stub 0x10007a95: the stamp stored at +0x1cc8
	void sub_1026e4f0();	// "CAI_BaseNPC::PerformSensing": scope trace (entity name), when the count at +0x5bb4 is not positive calls sub_10310710 on the object at +0x5cdc, then slot 459
	bool sub_1027d0a0();	// SelectIdealState helper: with the take-damage mode (+0x200) at 1 stamps the source file/line (+0x1b3c / +0x1b40) and sets the state (+0x5cc4) to 7 and returns false; else cancels the scripted sequence entity of the handle at +0x5d74 (CCineNPC::sub_101a8c30) and returns true
	int sub_10265970();	// picks a hurt/idle activity (0x49 default, 0x66 / 0x68..0x6c by the value at +0x1594) that the model has a sequence for (CBaseAnimating::SelectWeightedSequence), else 0x49; first computes AngleVectors of GetAngles() (unused)
	int sub_1008dc40(int a, int b);	// CBaseAnimating::SelectWeightedSequence, called directly
	int *sub_1008d990(int seq);
	const char *sub_1008ff50(int act);
	const char *sub_100ab4f0();	// CBaseEntity::GetDebugName (stub 0x1000b5cd)
	void sub_10280c80();	// the AI report hand-off run at the end of the slow-think report
	int sub_1008dd30(int a, int b);	// CBaseAnimating member (stub 0x10004ec1), called directly by sub_1026c540 when the byte at +0x65d is clear
	void sub_1026c120(int a, int b);	// "CAI_BaseNPC::PerformMovement": scope trace (entity name), profiled as CAI_BaseNPC_PerformMovement; times slot 5 of the object at +0x5d34 called with (a, b) in the global cycle counter at 0x1090ff58
	float sub_1026c540();	// "CAI_BaseNPC::RunAnimation": profiled as CAI_BaseNPC_RunAnimation; slot 250(0) gives the advance (zeroed while the debug flag bit 1 is set and the navigator at +0x5d34 does not answer sub_102ee6a0), slot 538 when the class flags (slot 513) have bit 29, then for an NPC in a state other than 4 / 7 with the activity at +0xfec equal to 1 and slot 251 true selects a sequence for +0xff4 and sets it (sub_10260a50); returns the advance
	void sub_1000c9cd();	// as in CPhysForce (transplant)
	void sub_10156580(CBaseEntity *pEnt);	// provisional, like sub_10270aa0 (transplant)
	void sub_10175360(CBaseEntity *pEnt);	// provisional, like sub_10270aa0 (transplant)
	void sub_10209ac0(CBaseEntity *pEnt);	// provisional, like sub_10270aa0 (transplant)
	void sub_10252470(CBaseEntity *pEnt);	// provisional, like sub_10270aa0 (transplant)
	void sub_10279b70(CBaseEntity *pEnt);	// provisional, like sub_10270aa0 (transplant)
	void sub_10279cc0(CBaseEntity *pEnt);	// provisional, like sub_10270aa0 (transplant)
	void sub_10279c20();
	float sub_10279bf0();
	Vector *sub_10279bb0(Vector *pOut);	// the memory list's node of the slot 167 object's id is marked (sub_102dfd90 of the list at slot 541)
	void sub_10280d30();	// clears the schedule bookkeeping (+0x5c38..+0x5c4c); the object at +0x98 loses bit 3 of its flags (+0x14b8) and is told slot 435 with the cleared schedule
	void sub_1026d130();	// stub 0x100050d3, run first by vfunc379
	void sub_1026d050();	// stub 0x1000c153, called by sub_1026d130 after sub_10279a50(0)
	bool sub_10329760(CBaseEntity *pEnt, int b, int c, int d, int e, int f, int g);	// CBaseCombatCharacter::vfunc379 (stub 0x100152da), called directly
	void sub_10323b60(int a);	// CBaseCombatCharacter::vfunc130 (stub 0x1000bfcd), called directly by vfunc130 with its argument
	void sub_10005d94();	// CBaseCombatCharacter::vfunc380 (stub 0x10005d94), called directly
	void sub_10007ea0();	// tail-called by vfunc380 (0x10007ea0)
	void sub_10357110(CBaseEntity *pEnt);	// provisional, like sub_10270aa0 (transplant)
	void sub_103f6ab0(CBaseEntity *pEnt);	// provisional, like sub_10270aa0 (transplant)
	void sub_1042b9c0(CBaseEntity *pEnt);	// provisional, like sub_10270aa0 (transplant)
	void sub_10271900();	// keeps the navigator's goal (the memory list's last known position for the slot 167 entity) up to date while the navigator is in mode 2 (called by vfunc481)
	CBaseEntity *sub_102729d0();	// the entity the NPC is focusing on, chosen by the kind (object at +0x5d34, 2: handle at +0x5ce0, 1: handle at +0x5ce4, 7: the handle slot 586 of the object at +0x98 gives); null for other kinds or a stale handle
	int sub_10278090(char bFlag, int n);	// slot 482 "CAI_BaseNPC::vfunc482" override as seen at 0x10278090 (ret 8: two arguments): 1, or 2 when the scripted sequence entity of the handle at +0x5d74 is live and accepts (CCineNPC::sub_101a8ac0); 0 when slot 158 is false or, with bFlag clear and the state at +0x5cc0 not 0 / 1 (and +0x5cc4 not 1, and for state 3 n < 1), the NPC may not take part
	int sub_10289fe0();	// the activity for the action animation named by the scripted entity (handle at +0x5d74, name at +0x5f50): 9 by default, the model's activity of that name, or 9 / 0x18 depending on whether the model has a sequence of that name
	void sub_10272940(const char *label);	// "CAI_BaseNPC::ResetSequence"-like: LookupSequence(label); a found sequence is set (sub_10260a50), the ground-speed-like float at +0x6f8 cleared unless the sequence is unchanged and the byte at +0x65d is set, then the object at +0x5d44 updated (sub_102e1cf0); else DevWarning "%s has no sequence named:%f" and the sequence at +0x6f0 cleared
	int sub_10348890(CRestore *pRestore);	// CBaseCombatCharacter::vfunc127 (stub 0x10010d48), called directly
	bool sub_1026fb40();	// throttled check: when the class flags (slot 513) have bit 21 and the time at +0x5da0 has passed, pushes it ahead and, unless sub_10007e19() holds, asks sub_10005dd5 about a (300, 300, 100) box
	int sub_10007e19();	// CBaseCombatCharacter member (the stub at 0x10007e19 for 0x1032e7b0), called directly
	int sub_10005dd5(float *pBox);	// CBaseCombatCharacter member (the stub at 0x10005dd5 for 0x10333ad0), called directly
	void sub_102695d0();	// scope trace (entity name), makes the entity fully visible when its field at +0x16c is 0 (alpha byte +0x1a3 = 0xff, field = 2), AddSolidFlags(4) on the collision property at +0x270 (inlined scope trace), sub_100b2f50(zero vector), sub_100b3b00(), next think = curtime + 10.0, ThinkSet(think stub 0x100152b2, 0, 0)
	void sub_1027dd10(CBaseEntity *pEnt);	// run when the NPC stops caring about pEnt: only while slot 158 holds and pEnt is set; when it is the entity of the handle at +0x5d24 slot 532(1); lets the object at +0x5d34 finish (sub_102ee2c0 when sub_102ee2e0 holds), sets the byte at +0x1a40, runs slot 528, and clears the state at +0x644c (1 or 2) of the object at +0x98
	float sub_1027db80(const Vector *pDir);	// the yaw for a direction: the NPC's own yaw (angles, slot 221, y) for a zero direction, else sub_101d2c70(pDir)
	void sub_1027be60();	// level transition cleanup (called by OnRestore): lets the navigator at +0x5d34 finish (sub_102ee270), sub_10280d30, clears +0xfec, clears the six condition dwords at +0x5c5c unless slot 167 holds, and strips a scripted sequence entity that is gone from a state 4 NPC (SetState(1), DevMsg "Scripted Sequence stripped on level transition for %s")
	char sub_102800c0(int a, CBaseEntity *pEnt, int c);	// starts a move to pEnt's origin: sub_10280de0(a), remembers pEnt at +0x5de8, then slot 563(pEnt, goal.dest, params, &a) with a type 4 goal at pEnt's slot 217 origin and a 128 unit tolerance block, and hands the goal to the navigator at +0x5d34 (sub_102ecd20, stub 0x1000ce64); takes three stack arguments
	void sub_102801e0(int a, CBaseEntity *pEnt, int c);	// like sub_102800c0 with a type 3 goal at pEnt's slot 220 origin and the default tolerance block (-1.0f, 1, ...)
	void sub_10280de0(int a);	// stub 0x1000c27a, called directly
	void sub_102727d0();	// "CAI_BaseNPC::MaintainActivity": scope trace (entity name); when slot 466 allows it and the ideal activity (+0xff0) differs from the current one (+0xfec) or the sequence (+0x6f0) from +0x5ccc: for activity 2 only sub_102726a0 when the byte at +0x65c is set, else sub_10272130(ideal, +0x5ccc, +0x5cd0, +0x5cd4) then sub_102726a0
	void sub_102726a0();	// stub 0x10008efe, called directly
	void sub_10272130(int act, int *pSeq, int *pA, int *pB);	// stub 0x1000faa6, called directly
	bool sub_10280a50();	// "CAI_BaseNPC::AutoMovement": scope trace (entity name), slot 250(0), the studio worker sub_10094b70 (stub 0x10008d64) fills a movement delta from the frame times at +0x170 / +0x174; true when slot 94 (move type) is 4, the entity flags lack 0x400 and the motor (+0x5d44) accepts the move toward the focus entity (sub_102729d0)
	int sub_100b3700();	// CBaseEntity::GetFlags (stub 0x10008b84), called directly
	float sub_10094b70(float flInterval, char *pbOut, void *pvecOut, int *pnOut);	// stub 0x10008d64, called directly
	void sub_10323a90();	// CBaseCombatCharacter::vfunc103 (stub 0x1001374b), called directly
	void *sub_1032e120(const char *pszName);	// CBaseCombatCharacter::Weapon_Create (stub 0x1000b0b4), called directly
	void sub_10272490(int act, int seq, int c, int d);	// "CAI_BaseNPC::ResetActivity"-like (ret 0x10: four arguments): stores c at +0xff4, sets the sequence (sub_10260a50, with the sequence duration handed to sub_1032a910(d, duration)) or clears it when seq < 0, asks slot 533 for the activity vector, switches the activity at +0xfec to act (slot 465, the sound table when the byte at +0x5cd8 is clear) and updates the motor object at +0x5d44
	void sub_1028e700(int condition, float *pTime);	// per-condition timer: when the condition is not set clears *pTime; else starts it (+0x62c8 ahead of curtime) when it is 0 and, once curtime is below it, runs sub_10269b50(condition)
	void sub_1028e790();	// notes the position of the focus entities: with a slot 167 object hands the position at +0x62cc to sub_1028e700(0x48, ...) and, while the condition 0x48 is not set, sub_10270180(slot 167 object, 0); with a live entity in the handle at +0x5ce4 hands +0x62d0 to sub_1028e700(0x49, ...)
	void sub_1028e700(int kind, int *pPosition);	// stub 0x1001596f, called directly
	void sub_10270180(void *pObject, char bTrack);	// stub 0x10006217, called directly: remembers where the entity pObject is (position at +0x5bc8, tracking flag +0x5bc5)
	void sub_1027d8d0(CBaseEntity *pEnt);	// run for an entity that moves faster than 50 units (|vx| + |vy| of its velocity at +0x3bc / +0x3c0): asks the dev flag object (slot 1), sets condition 0x74, resets the motor's (+0x5d44) look state (sub_102e0b40) and hands it pEnt's slot 220 position (sub_102e2020)
	CBaseEntity *sub_1027a310(const char *pszItemName, Vector vecPos, Vector vecAng);	// "CAI_BaseNPC::DropItem": DevMsg "DropItem() - No item name!" for no name; creates the item entity at vecPos / vecAng (sub_100a99d0), clears its parent when it has one (bit 12 of the flags at +0x268), gives it this NPC's velocity (+0x3bc), then a random 0..100 impulse; null with a DevMsg when the item cannot be created
	void sub_10269fb0(int condition);	// sets the condition bit in the array at +0x5c8c (ids below 1000000000 and -1 are translated through slot 580 first)
	void sub_1026a030(int condition);	// clears the condition bit in the array at +0x5c8c (ids below 1000000000 and -1 are translated through slot 580 first)
	void sub_10269eb0(int condition);	// sets the condition bit in the array at +0x5c74 (ids below 1000000000 and -1 are translated through slot 580 first)
	void sub_10266690(void *pInfo, void *pOther);
	char sub_10266b10(int a, int b, float f);	// stub 0x10013c32, called by slot 562 with (a, b, 0.92f)
	void sub_102792b0();	// NPC death setup: CBaseAnimating::InitBoneControllers, RemoveSolidFlags(4) (inlined scope trace), move type 6 (slot 93), ResetSequenceInfo with the playback rate +0x6f4 cleared, +0x6f8 cleared, health +0x208 = +0x210, take-damage mode +0x200 = 2, sub_101cf390(this, zero, zero), sub_100b3b00(), sub_10265a40(), ThinkSet(stub 0x1000b1d6, 0, 0), next think = curtime + a constant
	void sub_10265a40();	// stub 0x10011644: halves the health (+0x208 / 2 into +0x210), take-damage mode +0x1fc = 2, +0x208 = 5, then slot 93(6, 0)
	void sub_10274ca0();	// eye offset setup: the model's eye position (via sub_100952d0(-1)) into the vector at +0x5d60; when it is still zero warns "has no eye offset in .qc" and uses (collision maxs + mins) * 0.75; then stores it as the view offset (sub_1009f380)
	void *sub_100952d0(int a);	// CBaseAnimating::GetModelPtr (stub 0x10013d8b), called directly
	const char *sub_1009f200();	// CBaseEntity::GetDebugName (stub 0x1000ea11), called directly
	int sub_102814d0();	// \"CAI_BaseNPC::SelectSchedule\" worker: refreshes the cached interrupt conditions when their time has passed, runs slot 433 unless the byte at +0x5ca4 is set, then (profiled as CAI_BaseNPC_SelectSchedule) picks the schedule (sub_1028a260), stores its local id (the global id through slot 580 when it is below 1000000000 or -1) at +0x5c3c and answers sub_102cc1f0 of it
	bool sub_10090180(void *pObj, int a, int b);
	int sub_1028a260();	// stub 0x10008f80: the schedule pick of the NPC, called directly by sub_102814d0
	void sub_100b3640(int a);	// CBaseEntity member (stub 0x1001457e), called directly by vfunc422 with 1
	int sub_100ac4e0(int a, int b, const char *pszContext);	// CBaseEntity::sub_100ac4e0 (ThinkSet, stub 0x10007fe5), called directly
	void sub_1009f380(const Vector *pVec);	// CBaseEntity view offset setter (+0x184 vector), called directly
	int *sub_1028a150();	// stub 0x10005f1a: the 8 byte record of the current task (index +0x5c40 in the list at +0x5c38), 0 when there is none
	void sub_1027c1f0();	// ends a scripted/forced movement phase: while the schedule at +0x5c38 is the one of type 0x3a (sub_102cc1f0): asks the dev flag object (global 0x10924a6c slot 1), sub_10269a20(0x76), clears the activity at +0xfec, move type 4 (slot 93), +0x3ec = 1.0f; otherwise sub_10269a20(0x75), move type 0, +0x3ec = 0, origin and velocity reset to zero vectors
	int sub_102cc1f0(int type);	// stub 0x10014f6a: the schedule of the given type
	void sub_10273ec0();	// "CAI_BaseNPC::TaskMovementComplete": clears the byte at +0x1a40, by the movement state at +0x5c44 (0 / 1: becomes 3, 2: sub_10273e80(0), 3: Warning "Movement completed twice!") and, unless the state at +0x5d70 is 4, 5 or 6, sub_10272650(sub_1027a6c0()); then, when the navigator at +0x5d34 answers sub_102ee6a0, sub_102f0400, and finally the navigator's sub_102ee270
	int sub_1027a6c0();	// stub 0x1000b285, run by TaskMovementComplete
	void sub_10272650(int a);
	void sub_10289ee0(int activity);	// CAI_BaseNPC activity setter (stub 0x10014524): clears +0xfec when it holds activity, then sub_10272650(activity)	// stub 0x100097d2, run by TaskMovementComplete with the result of sub_1027a6c0
	bool sub_10278220(const Vector *pStart, const Vector *pEnd, int mask);	// stub 0x100116b7: a trace-based visibility test of pEnd (offset by the eye offset at +0x184) from pStart; true when it is clear or the navigator accepts a move there
	bool sub_102784a0(const Vector *pStart, int mask);	// tests pStart against the NPC's origin and then against five pairs of points that step 48 units either side of the origin along its right vector (sub_10278220 each); true at the first one that is clear
	char vfunc573(const Vector *pOffset, const float *pEnd, char bSetCondition);	// slot 573 (plain member): traces from the view position (+0x184 plus pOffset) to pEnd; true when the way is clear or the hit entity is slot 167's, else (with bSetCondition) sets condition 0x63 / 0x66 and reports the blocker
	Vector vfunc574(const Vector &vecPos, int a, int b);	// slot 574 (plain member): the unit direction from vecPos to the point sub_10278650 finds for (vecPos, a, b): (point - vecPos) normalised, returned by value
	Vector sub_10278650(const Vector &vecPos, int a, int b);	// stub 0x1001592e, called directly by vfunc574, returns a Vector by value
	void sub_100544f0(int a);	// CBaseCombatCharacter member (stub 0x10006f73), called directly by vfunc402 with the field at +0xfd0
	float vfunc515(const Vector *pTarget);	// slot 515 "CAI_BaseNPC::GetYawTo"-like (declared as a plain overload of the placeholder slot): the yaw (sub_101d2c70, stub 0x1000612c) of the vector from the NPC's origin (slot 220) to pTarget; while the navigator (+0x5d34) reports task 0x37 / 0x38 the target's x / y are swapped (0x37 also negates the new x) and its z is left unset
	CBaseEntity *sub_1026a930();	// the first grenade (CBaseGrenade, not exploded) of the memory list (slot 541) that this NPC sees (slot 201): within 200 units, or flying (velocity direction) toward the NPC (dot above 0.85); null when there is none
	CBaseEntity *sub_102b6650();	// the closest entity (2D distance) in a (512, 512, 64) box around the NPC that has the flag byte at +0x788 and passes sub_102b62e0; null without a slot 167 object or a hit
	bool sub_102b62e0(CBaseEntity *pEnt);	// stub 0x10005065, the per-candidate test of sub_102b6650
	const char *sub_1027f290(int unused);	// the class name of the NPC type id at +0x1b2c (a switch over 0..0x2b returning "NONE", "AI_BASENPC", ... "NPC_VZOMBIE"; "**UNKNOWN**" otherwise); takes one unused stack argument
	int sub_1008f7b0(const char *label);	// CBaseAnimating::LookupSequence (stub 0x1000e057), called directly
	void sub_10273790(const char *pszRelationship, CBaseEntity *pActivator);	// "CAI_BaseNPC::AddRelationship" (stub 0x1000421e): parses "[entityname|entityclass|player] [D_HT|D_FR|D_LI|D_NU] [priority]" groups with strtok and adds entity / class relationships; the activator is unused
	void sub_10332ca0(CBaseEntity *pEnt, int disposition, int priority);	// CBaseCombatCharacter::AddEntityRelationship (stub 0x10005849), called directly
	void sub_10332aa0(int classId, int disposition, int priority);	// CBaseCombatCharacter::AddClassRelationship (stub 0x10013cf5), called directly
	void sub_10271d10(CBaseEntity *pTarget);	// profiled as CAI_Memory_CheckTarget: clears conditions 0x4b / 0x49, then sets one by slot 201 (can see pTarget), then sub_10271b10
	void sub_10271b10();
	void sub_1028e980(CBaseEntity *pEnt);	// called by vfunc433: while the navigator (+0x5d34) is neither in mode 1 nor 3 and has a navigation type, hands pEnt's slot 220 position to the navigator (sub_102ee220, stub 0x1000481d) once the point the route heads for is farther than the threshold at 0x104454c8 from it
	int vfunc546(int a);	// slot 546 (plain overload of the placeholder): the global at 0x10936c74's sub_1000aed4(a), tail called
	char vfunc532(int unused);	// slot 532 (plain overload of the placeholder): clears the handle at +0x5d24 and the byte at +0x5d30, returns 1
	int vfunc373(int a);	// slot 373 (plain overload of the placeholder): tells slot 371 and returns a
	int sub_102767d0();	// slot 124 body "CAI_BaseNPC::DrawDebugTextOverlays" (0x102767d0)
	int sub_1033e4a0();	// CBaseCombatCharacter::vfunc124 (DrawDebugTextOverlays, stub 0x1000eeda), called directly
	int sub_103346c0(int ammoType);	// CBaseCombatCharacter member (stub 0x1000ff97): the ammo count of a type
	void sub_100b1d10();	// CBaseEntity::CalcAbsoluteVelocity (stub 0x1000d486), called directly
	static bool TestBitDbg(unsigned int bits, int bit) { return ((bits >> bit) & 1) != 0; }
	const Vector &GetAbsVelocityDbg() { if (TestBitDbg(*(unsigned int *)((char *)this + 0x268), 12)) sub_100b1d10(); return *(Vector *)((char *)this + 0x3bc); }
	static int ENTINDEXDbg(int pEdict) { return engine->vfunc35(pEdict); }
	int entindexDbg() { return ENTINDEXDbg(*(int *)((char *)this + 0x2e0)); }
};
