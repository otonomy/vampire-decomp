# VC6 code-generation notes

These notes were the working guide of the agents that first matched `vampire.dll` with pcdecomp, the owner's
matching tool. They record how VC6 (build 9044, `/O2 /GR`) turns source shapes into code: Source engine idioms,
register and stack-slot choices, inlining budget, ordering walls. The guide that applies now is `AGENTS.md`.

Read them with the code rules (`AGENTS.md`, "Code rules") in mind. Many notes describe **levers** that closed a byte
gap: local view structs with padding, a `// TARGET:` on another class, `volatile` reads, dead `if (0)` uses that spend
inline budget, `#pragma inline_depth`, calls through function-pointer casts. Each of those is a fakematch (R1, R4,
R17): it reproduces the bytes but not the source. Treat each as evidence of what the original did, such as an inline
call or a macro at that point, and look for that source; a function that still needs the lever is `MATCH-PENDING`.
The notes on Source idioms (DATADESC tables, recipient filters, containers, handles, traces, `gpGlobals`, `engine`)
describe real original code and remain the first thing to read.

The pcdecomp commands the notes mention (`claim_function`, `compile_and_diff`, `read_data`, ...) belong to the
owner's tool. Without it, use `vd gate` to check a function and read the retail bytes with any disassembler.

## Source engine DATADESC getters (82 bytes, one instruction sequence, many addresses)

Recognise it by this assembly (G = guard byte, T = 5 dwords inside a table, DM = a datamap global):

```
mov cl, byte ptr [G]; mov al, 1; test al, cl; jne L        ; guarded first-call init
or cl, al; mov eax, dword ptr [0x1055dc70]; mov byte ptr [G], cl
xor ecx, ecx; mov [T+4], ecx; mov [T], eax; mov [T+8], ecx; mov [T+12], ecx; mov [T+16], ecx
L: mov dword ptr [DM+4], n; mov dword ptr [DM], P; mov eax, DM; ret
```

It is NOT a guarded 5-dword struct (that reading stays at score 8-9 whatever you try; older notes on these
functions that say "5-dword static" or "same unsolved family" describe that dead end). It is the body of Source's
`BEGIN_DATADESC(Class) ... END_DATADESC()`: a function-local `static typedescription_t dataDesc[]` table in .data.
Its last entry is a `DEFINE_OUTPUT`, whose save/restore ops pointer is `g_1055dc70` (eventFuncs, a variable, not a
constant), so VC6 guards the table and fills the last 5 dwords of that entry (ops, inputFunc, td,
fieldSizeInBytes, unk) on the first call; T = that entry + 0x18. DM is the class's datamap
`{dataDesc, dataNumFields, dataClassName, baseMap}`; the function sets `DM = {&dataDesc[1], n}` and returns `&DM`.

Recover the whole table with read_data before writing anything:
1. P = &dataDesc[1]. Entries are 0x2c bytes, so the table starts at P - 0x2c and has n + 1 entries (entry 0 is all
   zeros): `read_data(P - 0x2c, "dwords", 11 * (n + 1))`.
2. Each entry is 11 dwords: fieldType, fieldName (string), fieldOffset[0], fieldOffset[1], fieldSize | flags << 16,
   externalName (string or 0), pSaveRestoreOps, inputFunc, td, fieldSizeInBytes, unk.
   `read_data(ptr, "string")` gives each name. `read_data(DM + 8, "dwords", 1)` then `"string"` gives the class name.
3. flags: 0x2 DEFINE_FIELD, 0x6 DEFINE_KEYFIELD (has an external name), 0x8 DEFINE_INPUTFUNC (fieldType 0, a function
   in inputFunc), 0xe DEFINE_INPUT, 0x16 DEFINE_OUTPUT, 0x20 DEFINE_THINKFUNC / DEFINE_FUNCTION (a function, no
   external name). fieldSize > 1 is an array.
4. Function pointers in the table point at jump stubs (skip functions): declare `void sub_XXXXXXXX();` with the
   address read_data shows and write `(void *)sub_XXXXXXXX` in the inputFunc slot.

Write it like this (matched: 0x103c50c0, CNPC_VVampireBoss; copy the struct exactly, it gives the 0x2c layout and the
store order). DM is an `extern int g_XXXXXXXX[2]` placeholder; put your own function's DM address, entries and
input-function addresses in place of these:

```cpp
class ISaveRestoreOps;	// a class, as the game's RTTI spells it (.?AV); `struct` gives .?AU
struct datamap_t;
struct typedescription_t {
    int fieldType;
    const char *fieldName;
    int fieldOffset[2];
    unsigned short fieldSize;
    short flags;
    const char *externalName;
    ISaveRestoreOps *pSaveRestoreOps;
    void *inputFunc;
    datamap_t *td;
    int fieldSizeInBytes;
    int unk;
};
extern ISaveRestoreOps *g_1055dc70;
extern int g_1065e418[2];
void sub_103c76b0();

int *sub_103c50c0()
{
    static typedescription_t dataDesc[] = {
        { 0, 0, {0, 0}, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 5, "m_bJumping", {0x6498, 0}, 1, 2 },
        { 2, "m_pMonsterModelName", {0x6680, 0}, 1, 2 },
        { 2, "m_pBodyEmitterNames", {0x6684, 0}, 4, 2 },
        { 3, "m_vJumpOrigin", {0x649c, 0}, 1, 2 },
        { 3, "m_vJumpTarget", {0x64a8, 0}, 1, 2 },
        { 1, "m_fJumpHeight", {0x64b4, 0}, 1, 2 },
        { 1, "m_HealthPercentRecord", {0x6698, 0}, 1, 2 },
        { 1, "m_fJumpGravity", {0x64b8, 0}, 1, 2 },
        { 15, "m_fTaskStartTime", {0x669c, 0}, 1, 2 },
        { 12, "m_hParticleEmitters", {0x66a0, 0}, 4, 2 },
        { 12, "m_hTransformPartner", {0x66b0, 0}, 1, 2 },
        { 16, "m_MorphModelName", {0x667c, 0}, 1, 6, "MorphModel" },
        { 0, "InputTransformModel", {0, 0}, 1, 8, "TransformModel", 0, (void *)sub_103c76b0 },
        { 10, "m_OnTransformComplete", {0x6664, 0}, 1, 0x16, "OnTransformComplete", g_1055dc70 },
    };
    g_1065e418[1] = sizeof(dataDesc) / sizeof(dataDesc[0]) - 1;
    g_1065e418[0] = (int)&dataDesc[1];
    return g_1065e418;
}
```

What the judge checks: it places `dataDesc` and its guard at the game's addresses and compares every number of the
table (types, offsets, sizes, flags) and whether each pointer slot is empty or not; the pointers themselves (strings,
functions) are not compared, but copy every string exactly from read_data. A wrong number gives "your initial value
differs from the game's at <table address>" (the bytes it shows are the table's first 16, not the differing ones:
compare your entries with read_data entry by entry). A wrong entry count gives "the game's code refers to different
addresses where yours uses it".

### Big DATADESC getters: the number of initializers per entry decides the stores (2026-11-10)

In a table that VC6 fills at run time (any entry after the first with a non-constant: `g_1055dc70`, an ops call, a
local static ops object), each entry is stored field by field, and VC6 writes the fields the source names in table
order but hoists the zero fill of the fields it leaves out. So write every entry with exactly the initializers
Source's macro has, no more and no fewer:

- DEFINE_FIELD / DEFINE_KEYFIELD: through inputFunc: `{ 1, "m_flInMin", {0x450, 0}, 1, 6, "inmin", 0, 0 }`
- DEFINE_CUSTOM_FIELD (ops, flags without 0x10): through inputFunc: `..., 0, sub_10045d90(8), 0 }`
- DEFINE_OUTPUT (flags 0x16): through the ops only: `..., "OutColor", g_1055dc70 }`
- DEFINE_INPUTFUNC / DEFINE_FUNCTION: through inputFunc; DEFINE_EMBEDDED: through td
- DEFINE_UTLVECTOR: ops is `Ops()` where `inline ISaveRestoreOps *Ops() { static CUtlVectorDataOps<CUtlVector<T,
  CUtlMemory<T> >, FIELDTYPE> ops; return (ISaveRestoreOps *)&ops; }` (CUtlVectorDataOps.h): the guard, the vtable
  store and the atexit at the top of the getter

All 16 open getters (177 B to 23 KB, 59 KB) matched this way with a table read from the game's data and stores;
every trailing zero written (`0, 0, 0, 0, 0`) or none at all gives scores of 65-270 that no reordering fixes.

## The matches together: what the link audit checks (rulings of 2026-10-20)

`pcdecomp link-audit` checks the matched functions as one program would see them; judging one function at a time
cannot see these. Keep to them in new work:

- **One name, one definition.** A class, struct or global is defined in exactly one header; a header that needs it
  `#include`s that one (never a second copy, not even a placeholder class with `vfuncN` slots: it clashes as soon as
  the real base is modelled). A placeholder global has one type in every header that declares it (`g_10566458` is
  `CGlobalEntityList *`; cast where another view is needed).
- **VC6 has no covariant returns.** An override returns the base slot's type: `CBaseCombatWeapon *vfunc5(unsigned int
  flags)` in every weapon, not `CWeaponMelee *` (error C2555 once the base is modelled).
- **No view base class for a constructor's store order.** VC6 stores the vptr after the member initialisers (and
  sinks it past plain body stores, up to the first call), so stores the game makes before the vptr store come from
  the initialiser list or from members with constructors, not from an invented base: a base the game's RTTI does
  not have is a link-audit error (CSave, CAI_Pathfinder, CAI_PlaneSolver were rewritten this way on 2026-11-19).
- **A vtable slot that holds the class's own function is declared in that class** (with the base slot's signature),
  matched or not; otherwise the vtable the class's constructor emits holds the base's function there.
- **A callee the game compiled before its caller, in the same unit.** If a function only matches with its callee
  defined in its own block (VC6 then knows which registers the callee keeps; with a declaration you get
  `push esi; mov esi, ecx` around the call), match the callee in its own block first, then copy that source into the
  caller's block in a namespace of the block's own:
  `namespace block_102a1590 { int __fastcall sub_102a1420(N *p) { ... } } using namespace block_102a1590;`
  Never a second plain definition (two blocks defining one name: LNK2005), never `inline` (it gets inlined) or
  `static` (VC6 compiles it last and forgets its registers), never an anonymous namespace (VC6 writes the file's path
  into its names). A member callee: `struct CFooUnit : CFoo { void sub_X(); };` in that namespace, defined there, and
  called as `((CFooUnit *)this)->sub_X()` (0x1008d230, 0x10200ca0).
- **CUtlRBTree instances.** `CUtlRBTree12/16/24/36/232` each stand for every game instance of `CUtlRBTree<T, I>` with
  that node size, and each instance has its own sentinel (a guarded static in `Links()`). A function of an instance
  reads its links through `CUtlRBTree16At<sentinel address>` (the address its code fills with `0xffff`, `0xffff`,
  `0xffff`, `1` after testing the guard byte; e.g. `mov word ptr [0x106bdb44], si`):
  `const CUtlRBTree16At<0x106bdb44> *tree = (const CUtlRBTree16At<0x106bdb44> *)this; ... tree->Links(i)`.
  The tree classes have no `Links()` of their own any more; the other classes of one tree (`CUtlRBTreeFind16`,
  `CUtlRBTreeInsert24`, `CUtlRBTreeFind232`, `CUtlRBTreeNode36`) cast `this` the same way.
- **One static in the game, one function in include/.** When several functions' code use the same guarded static
  (same guard byte, same object), they all inline one function that holds it: that function goes in include/ and
  every one of them calls it, never a `static` of its own. This holds for a static with a destructor too (the judge
  places its destroy `?s_default@...@$AV2@A` since 2026-10-21). The stat list lookup (guard 0x109f0b2a, default list
  0x109f0b40) is `CVStatListSet::Of(pChar)->Find(type)` (CVStatList_t.h); the entry lookup (0x109f0938, 0x109f0960)
  is `FindEntry(key)` (CEntryX.h). Never a `static CVStatList_t s_default(-1)` or `static CEntryX` of your own.
  That function must not be a *static* member function: VC6 names the guard of its static `?$S<n>@...` with n
  counted per unit, so units do not share it (audit E static-shared). A non-static member or a free inline gets the
  communal guard `??_B...@51` (variant_t::NullHandle, 2026-11-20).

## Source mathlib Vector code (x87): write it with Vector.h's operators

Recognise it by `call dword ptr [pfSqrt]` (0x10579660, `__cdecl`, the caller pops the float), `call dword ptr
[pfVectorNormalize]` (0x1057966c, `__fastcall`, ecx = the vector), or the "z-spill" of an operator result copied into
a vector: x, y, z computed on the FPU, then

```
fstp dword ptr [esp+N]; mov edx, dword ptr [esp+N]; fxch st(1); fstp dword ptr [dst]; mov dword ptr [dst+8], edx; fstp dword ptr [dst+4]
```

`include/Vector.h` holds the game's inline layer (the 2004 SDK's mathlib/vector.h): `+ - * /` returning a temporary
(`Vector res; VectorSubtract(*this, v, res); return res;`), the inline `operator=`, `+= -= *= /=`, `==`, `!=`,
`Length()`, `LengthSqr()`, `Length2D()`, `DistTo()`, `Dot()`, `Cross()`, `Init()`, `operator[]`, and the free
functions `VectorAdd/Subtract/Multiply/Scale/Divide/MA/Lerp/Copy/Clear`, `DotProduct`, `CrossProduct`,
`VectorLength`, `VectorNormalize(v)` (calls pfVectorNormalize) and `FastSqrt(x)` (calls pfSqrt). Write the Source
code with them; never per-component arithmetic, never a local V3 struct with operators of your own, never
`g_10579660` / `g_1057966c` in new code (the names are pfSqrt / pfVectorNormalize).

How the source form shows in the code (each verified with the judge on 2026-10-21):

- **Assignment of an operator result = the z-spill.** `m_vecDir = GetAbsOrigin() - pOther->GetAbsOrigin();` or
  `vec = vec * flScale;`. For a new local the z-spill means it was declared first and assigned: `Vector dir; dir = a -
  b;`. `Vector dir = a - b;` (copy initialisation) stores x, y, z straight into the local instead (no spill).
- **x, y, z all stored to a temporary and then copied with three integer moves into a local** = a named local
  initialised from an operator and then used: `Vector vecVelocity = vecDelta / flTime; SetLocalVelocity(vecVelocity);`
  (the frame then has one more 12-byte slot than `SetLocalVelocity(vecDelta / flTime)` gives).
- **Lengths.** `(a - b).Length()`, `VectorLength(a - b)` and `a.DistTo(b)` give the same code in a small function. In a
  bigger one VC6 stops inlining `DistTo` (the judge says "cannot link" and shows `call 0`): use `(a - b).Length()`.
  Swapping the terms of `x*x + y*y + z*z` changes nothing (VC6 picks the order), but the grouping does: when
  `Length()` gives the right instructions with the squares in another order, write the length with a local inline
  helper grouped differently, e.g. `FastSqrt(v.x * v.x + (v.y * v.y + v.z * v.z))` (0x1030f7b0 matched that way;
  `Length()` gave 6). `sqrt()` from <math.h> is the inline `fsqrt`; `FastSqrt` / `Length()` is the `call [pfSqrt]`.
- **`a == b`** is `(b.x == a.x) && (b.y == a.y) && (b.z == a.z)`: the right operand is loaded first (`fld b.x; fcomp
  a.x`). `vecDest == GetLocalOrigin()` loads the origin first.
- **Float constants as literals.** Write `0.5f`, `-0.1f`, `5.0f` (a `fcomp qword ptr` constant is a `double`: `0.001`),
  not `extern float g_XXXXXXXX`: an extern global changes which operand VC6 loads first (0x10309f60: score 5 with
  externs, 0 with literals). read_data(addr, "dwords", 1) shows the bits (0x3f800000 = 1.0f, 0x3f000000 = 0.5f).
- **Real members, not casts.** `*(float *)((char *)this + 0x3fc)` changes the load order and turns a float copy
  (`mov edx, [a]; mov [b], edx`) into `fld; fstp`. Declare the members (or a local view struct with them).
- **A member read through an inline getter goes through the FPU** (found 2026-11-08 on 0x102c36d0, 222 -> 97):
  `fld dword ptr [m]; fld st(1); fcompp` (the clamp `f > Max() ? Max() : (f < Min() ? Min() : f)`, as matched
  CMathRemap::sub_101321f0) and a float argument pushed as `push ecx; fstp dword ptr [esp]` both mean
  `float Max() const { return m_flMax; }`-style getters; a plain member gives `fcom dword ptr [m]` and `mov; push`.
  A getter value loaded before a branch test (`fld [m]; ... je`) is VC6 hoisting the first instruction both branches
  share: make both branches start with the same getter use.
- **A Source inline wrapper evaluates all its arguments before the call inside it.** `inline void
  VectorTransform(const Vector &in1, const matrix3x4_t &in2, Vector &out) { VectorTransform(&in1.x, in2, &out.x); }`:
  the matrix getter runs before the pushes; calling the out-of-line function directly pushes `out` first.
- **Returning a Vector by value** (`Vector CBaseEntity::WorldSpaceCenter()`, hidden pointer, `ret 4`) can be declared
  in CBaseEntity_ext.h: CBaseEntity.h includes Vector.h.
- **AllocTempVector.** The ring of temporary vectors (`static Vector s_vecTemp[128]` at 0x109f0cc0, guard 0x109f0b80,
  index `g_106b856c`, `& 0x7f`) is Source's `AllocTempVector()`; its atexit destroy is an empty `ret` (Vector has a
  constructor, no destructor). Like any shared static it belongs in one function in include/ (the link audit rulings above).

Matched this way (bench copy, 2026-10-21): 0x101c2560 CSun (direction to the target, normalised), 0x10258320,
0x10309f60, 0x101c1520 CBaseToggle::LinearMove, 0x1013bb40 Catmull_Rom_Spline_Normalize, 0x10027160
CBaseEntity::WorldSpaceCenter (CCollisionProperty's OBBCenter / CollisionToWorldSpace inlined), 0x1004d9a0
CPhysicsSpring::Spawn; Sonnet workers with this header then also matched 0x101128d0 and 0x1030f7b0
(experiment 2026-10-21-x87-vector: marked x87 functions 6/18 -> 14/18). Not solved yet: a 2D normalise whose squares the game sums x first (0x102ed820: VC6 gives y
first for every form tried) and the VMatrix / VPlane layer (0x1024cdb0, 0x101382f0).

## VC6 order walls: a reload after a store means the source read through a pointer or a reference

VC6 moves a load above a store when it can see both use the same base with different offsets. When the game stores and
only then loads (or loads the same memory twice), the original source read that value through another pointer or a
reference, so VC6 had to assume the store might change it. Write it that way; reordering statements does not help.
Verified with the judge on 2026-11-06:

- **`x ? x : ""` through a reference (Source's STRING).** For `m_pszName ? m_pszName : g_106b8540` write a local
  `inline const char *STRINGR(const char *const &s) { return s ? s : g_106b8540; }` and call `STRINGR(pv->m_pszName)`.
  It gives the game's store-before-load order (0x1011c060 CServerGameClients::vfunc3: `mov [esi+0x2310], 0` before
  the name load, score 2 -> 0) and the game's second, unmerged null test (0x100aeda0's classname path; that function
  is still open for another reason). Eleven matched sources already
  use it under other names (STRING, S_STRING, SafeString...): define it in your source, there is no shared one.
- **A 64-bit add whose high half is loaded after the low half is stored** reads the addend through a pointer. The
  VPROF exit (CVProfile.h's ExitScopeInlined) written out by hand: `CUnknownCycle100335e0 *pc = &n->m_CurFrameTime;
  sub_100335e0(pc); n->m_TotalTime += pc->m_Int64;` (0x10037e90 PerformRotatePush, score 4 -> 0; the member form
  `n->m_CurFrameTime.m_Int64` loads both halves first).
- **Angles are QAngle, not Vector.** include/QAngle.h has the SDK's QAngle operators, which work per component;
  Vector's go through VectorAdd/VectorMultiply. In x87 code that changes which value stays on the FPU stack:
  `QAngle angles = *(QAngle *)((CEntityVSlots *)pRoot)->slot221(); angles += *(QAngle *)pRoot->m_angVel3c8 *
  flRotation;` (the SDK's `angles += GetLocalAngularVelocity() * movetime`) gives `fld angles.x; fadd st(2)`, Vector
  gives `fxch st(1); fadd` (0x10037c10 RotateRootEntity, score 8 -> 0). The Vector rule above holds here too: use
  QAngle.h, never a local angle struct with operators of your own.
- **Not a source question (stop after one try):** an independent `inc reg` that VC6 schedules into an x87
  `fld ... fstp` gap while the game has it just before the next call. Five positions of `text_offset++` (statement,
  `+= 1`, int/long, comma in an argument, comma in the callee) all gave the same code (0x1034ea80 CFogController).

## VC6 walls Opus closed (2026-11-09): score 1-2 near misses Sonnet had tried 12-25 times

Opus matched 12 of 20 such walls, most of them on its first compile, by writing the code the way a programmer would
have written it rather than adding temporaries that spell out the assembly:

- **Declare a local in the innermost block that uses it, and do not stage a call's result in a temporary.**
  0x101c5f40: `Vector dir, pos;` moved from the else branch into the `if` that uses them, the member-function pointer
  declared once before the `if`, and `(pOther->*pfn)(info.sub_101c2720(...))` called directly in each branch instead
  of `pInfo = ...; ... (pOther->*pfn)(pInfo);` after them (score 2 -> 0).
- **A chained assignment, not a pointer temporary:** `node.m_vPos = node.m_vPrevPos = v;` where Sonnet wrote
  `Vector *p = &node.m_vPrevPos; *p = v; node.m_vPos = *p;` (0x1012fe20, score 1 -> 0).
- **A plain local and a literal, not a helper:** `float f = pNode->vfunc11(...); m_n40 = f; if (f <= 0.0) DevMsg(...,
  f);` where Sonnet compared through an inline helper reading `g_1044fab0` (0x101ddfb0, score 2 -> 0). The judge maps
  the literal to the game's constant.
- **A `__fastcall sub_X(Self *self, int edx, ...)` is a member function:** write it as the real class's member (here
  `int CNPC_VTzimisceRunner::vfunc604(int)`), with the body in an `inline` member of the view struct it calls
  (0x103c4430, score 2 -> 0).
- **CUtlRBTree members are template members:** `#include "utlrbtree.h"`, an entry struct of the right size and the
  mangled `TARGET` (`?LinkToParent@?$CUtlRBTree@U...@@G@@QAEXGG_N@Z`), not a hand-written class with the same steps
  (0x100498c0, 0x10054c00; see the containers section).

## VC6 walls closed by hand (2026-11-12): score 1-2 near misses Opus had given up

17 near misses matched in one afternoon (7.7 KB) after their header patches were saved; 67 by the evening. The levers, each one measured:

- **Write the SDK's spelling of a constant, not the folded value.** `#define DEG2RAD(x) ((float)(x) * (float)(M_PI_F /
  180.f))` with `M_PI_F ((float)(M_PI))` (0x101d2f40), `#define lbs2kg(x) ((x)*(1.0f/(2.2f)))` (0x1002bdc0): the
  unfolded expression moves an `fstp`/`fmul` to the game's place. Double literals passed to float parameters
  (`vfunc1(0.95, 1.05)`) and a plain `0` instead of `0.0f` did the same in 0x100f49e0 (both needed).
- **Initialise a local that only one path sets.** `bool bWentThrough = false;` let VC6 thread the jump of the other
  path straight past two tests, as the game does (0x102579f0, 1,672 B).
- **float, not double, for a local that holds a float expression.** `float flZ = ... ? g_x : cv.m_fValue;` moved one
  load after an `fcos` (0x103e9e00).
- **A constant local the SDK keeps:** Studio_AnimVelocity's `float prevframe = 0;` used in both expressions
  (0x100c5a30).
- **A by-value return of a small struct:** `color32 Color32() const { return rgbaVal; }` then
  `pWorld->m_FogColor2 = in.value.Color32();` (0x1034e9a0, 0x1034e8c0).
- **x87 sum order:** a term holding a const `operator[]` (returns by value) is computed first and its operand loaded
  first; use it on the one term the game computes first (0x102961a0, not matched yet: it also reorders a Length).
- **A bit test the game keeps as `test [mem],imm; setne al; and eax,0xff`:** an inline bool helper that takes the mask
  as a parameter, `inline bool IsSet(int x, int m) { return (x & m) != 0; }` called as `IsSet(x, 0x80000000)`;
  spelled out, VC6 folds it to `shr eax,31` (0x101e18c0, 0x101e1890). Likewise `if (c) return true; return false;` in
  an inline keeps a `setge; ...; sete` pair that a one-expression body folds into one `setl` (0x10224100).
- **A ternary arm the game does not thread** (`je L; mov esi,[eax+N]; jmp T; L: xor esi,esi; T: test esi,esi`): read
  the field through an inline accessor, `p ? p->MyNPCPointer() : NULL` (0x102efde0).
- **Constructors: build members with their own constructors**, not hand-ordered stores: view structs whose members
  have real constructors (handles set to -1, a base whose initialiser runs before the vptr store, a sub-object
  calling the out-of-line ctor; `#pragma pack(1)` for odd offsets), constructed with `((V *)p)->V::V();`
  (0x10389cc0, 4 -> 0; 0x10029610).
- **A record's `operator=` stores members in its own order:** look for a matched copy of the same record (search its
  hash constant) and use that member order (0x1028ea60).
- **The SDK helper chain, not its steps:** `SetCount()` = RemoveAll + AddMultipleToTail moved the argument register
  (0x101a4970); a 2-element member array filled with `for (i = 0; i < 2; i++) a[i] = x;` (0x10254cd0).
- **A load VC6 copy-propagates into a temporary** (game `mov esi,[local]; test esi,esi; mov ecx,esi`, ours `mov
  ecx,[local]; test ecx,ecx; mov esi,ecx`): `*(T *volatile *)&local` keeps it (0x10193fb0; a last resort, it is not
  what the original said).
- **Unit-dependent matches:** some functions match or not with the number of struct declarations in the unit
  (0x10073c20: 0,0,2,2,0,... for 0..11 extra `struct S{int x;};`; 0x1016fa90 matched with 12 extra typedefs). A header
  edit can release them ("unstable match"): re-submit the old score-0 source, then sweep the count (0x102f9cd0: 6
  extra structs). The sweep costs ~1 s per count: try it first on any eax/edx-swap or slot-only near miss.
- **Find what a function is from its stub:** the 0x1000xxxx jump stub's references (a DATADESC input or think entry
  next to it) give the Source name ("InputSpawnDust" -> 0x101145d0), and the SDK body then matches; a call in the
  middle of an argument list is a getter returning a reference. A function calling itself calls its own stub by name.
- **Use the SDK's inline helper at every call site** (ENTINDEX / EdictIndex on every index lookup, NumEntities /
  GetEntityInfo inside the loop condition): one place written out moves registers elsewhere (0x10141c80, 0x1009fe40,
  0x101a08f0). Declaration order of locals CAN move registers (unlike stack slots).
- **Source's string_t:** a dead `mov eax,[eax]` before a repeated call is `!G || !STRING(G) || !*STRING(G)`;
  MAKE_STRING as a by-value struct with a constructor (0x103689c0).
- **A stored value before a constant flag store:** write the value through a reference (`bool &r = p->m_b; r = v;`,
  0x1023e0b0). A float copy the game does with fld/fstp: `(float)(x * 1.0)` (0x103ea7e0, workaround).
- **A `||` chain returning bool:** move it into an inline helper and write `if (H(x)) return false; return true;` to
  keep the separate epilogues (0x102b62e0). The same tail in each branch: write it once after an if/else (0x1021deb0).
- **POD handle by value** to an inline helper (no user copy constructor) puts the copy store before lea/push
  (0x1013f280); CBaseHandle with its copy constructor does not.
- **Round 4 (score 3-13, 23 of 48 matched):** look for Valve's function first, even for slot-only diffs: both slot
  walls 0x102f99d0 (GetFloorZ) and 0x102f05d0 (ShouldAttemptSimplifyTo) fell on the first compile of the SDK form,
  found by searching the 2004 SDK for a constant (0.766) or a line (`return tr.endpos.z`). Write the reference body
  verbatim, macros included.
- **`push esi` after the early exits** (shrink-wrapped): the rest of the body is an inline function with its own locals
  (0x100af840), or the function returns the value (0x102457f0). **eax holds the same value at every `ret`**: the
  function returns it; declaring the return type changes register use throughout.
- **`lea [esp+N]` of a dead temp passed to a virtual** is the hidden pointer of a by-value return (`virtual Vector
  BodyDirection2D()`), not a `const Vector &` argument (0x102f05d0).
- **Offsets during pushed arguments:** `fst [esp+N]` between the pushes and `add esp` is [esp+N-4] in the normal frame;
  a store that looks dead there can be a real variable read later (0x10122190: the SDK's `spd`).
- **A constructor without a header ctor:** the source can define its own `class X : public Base { X(); ... }` with the
  SDK members and target `X::X`; it links to the game's vtable, no header patch needed (0x1019dc80).
- **Smaller levers measured in round 4:** a thiscall member that ignores `this` -> call it through a view of `this`; a
  ternary that pushes per arm -> if/else with the same call in each; a bool member read as `m_b ? b : false`;
  `lea [esp+param]` of a dead parameter slot -> a separate local; `return false` at each exit instead of a shared
  label; `dz += X; r = dz;`; a hash decoded into an int local; const `operator[]` per Vector component; a base ctor
  written as a call in a hand ctor; `(float)(x * 1.0)` for float arguments (0x1017ed00, workaround). Changing an
  operand's width (short -> int counter) moves later registers (0x10122cd0).
- **Round 5 (score 2-19):** SDK inlines in a local view struct close walls nothing else does:
  `CGameTrace::DidHit()` then `if (tr.DidHit()) return false; return true;` (0x102a0fb0); SDK inlines on a global
  object via a view struct declared `extern` at the object's base address (field address minus offset, 0x1019d040);
  `HasSpawnFlags(p, 32)` with the mask as a parameter gives `mov dl,0x20; test [mem],dl` (0x100c93b0); a free inline
  that takes values as parameters (`::IsSolid(solid, flags)` under CCollisionProperty::IsSolid) keeps a second null
  test (0x100342c0); an SDK inline called with a constant false keeps its dead arm (`fTranslate && ...`) or the
  vtable temps change registers (IsCurSchedule: 0x1027a420 and twin 0x103e0fa0).
- **Unnamed Troika-looking functions can be plain SDK ones** (0x100c93b0 ButtonResponseToTouch).
- **Pushes that do not add up:** count each callee's arguments from its `ret N` (and its stub target); pushes before a
  virtual can belong to an enclosing call, a lone `push 1` can be a trailing `true` (0x102ed390).
- **A callee whose registers the caller relies on** (ecx kept across calls, a loop counter in edx across a call): copy
  the matched callee bodies (and their callees) into one `block_` namespace before the caller under `#pragma
  auto_inline(off)`, as real thiscall members, not fastcall copies (0x100789b0, 0x101dc750).
- **A bool return whose tails read `mov al,1` / `xor al,al` before a ScopeTrace `dec [ecx]`** is `return a && b == c;`
  (operand order of `==` matters, 0x10051c10). A container scan that reloads the element pointer each pass is the
  real `CUtlVector<T>` with its inline `operator[]` (0x101b4cc0).
- **Two names for one global break CSE:** `::g_10566458` and `EHandleDetail::g_10566458` are separate symbols to VC6;
  mixing them forces a reload. Use one spelling (ehandle.h) at every use in a function.
- **Valve's naked asm:** mathlib's VectorMA (0x101387e0, 0x10139500) is `__declspec(naked)` x87 asm in the game.
  Since 2026-11-14 pcdecomp accepts an `__asm` block that is a word-for-word copy of a whole block in the [reference]
  trees (naked too when that file is naked): paste Valve's block verbatim (comments and `#if` lines may stay), never
  an edited one. Listed apart like other inline assembly. _SSE_VectorMA 0x10138830 had its size cut 49 -> 38 (no ret:
  the extent ran over the padding).
- **Round 6 (score 2-25 + transplant twins, 26 matched):** a free `__stdcall` function whose callers set ecx is a
  thiscall member ignoring `this` (a view `struct V { int sub_X(...); };`): ecx is then taken and every later
  register and spill moves. A sweep of all 14 open stdcall bests matched 3 at once and 0x10227da0, a 1,055-variant
  permuter wall (scratchpad tcsweep.py, 2026-11-12). The tell: the caller loads ecx, the callee never reads it.
- **Hand-written cvar views are ConVar:** `g_X->vfunc1() ? 0 : g_X->m_f28` is `ConVar::GetFloat()` on `extern ConVar
  g_<X-4>` (ConVar.h); `.GetFloat()` / `.GetBool()` took 0x10351e10 from 48 to 0.
- **A view method named sub_<addr> links to the game's address**, so a callee can get another signature (argument
  count, return type, bool instead of the header's int) without a header patch: `struct V : CClass { bool sub_X(); };`
  (0x10336a50, 0x102395c0). Only for functions without a known mangled name.
- **Template instantiations with identical code** (CUtlVector<int> vs CUtlVector<CHandle<T>>) are separate copies:
  the caller's SDK container type names each (0x100fdd00, rename_symbol). A twin whose transplant scores ~9 may
  have a literal where the sibling has a parameter (0x101456e0: 2048.0f).
- **Smaller round 6 levers:** read the real `CUtlVector<T>` `operator[]` through a cast of the member (this's register
  reused, 0x10036270), then retry the SDK control flow rejected earlier; identical case bodies written twice so VC6
  merges table entries and cross-jumps one tail (0x10204dd0); `idx = -1; for (...) if (..) { idx = i; break; } return
  idx;` (0x10316760); a struct with constructors but no copy constructor for a hidden-pointer return read back as a
  dword (CUtlSymbol, 0x1024b5e0); one vtable load shared by several virtual calls = a local view of pointer-to-member
  slots (0x102395c0, workaround); a late `push ebx` with the body moved to an inline taking the modified parameter by
  reference (0x100e9290); store a float to a member then test the member, not the local (0x10218320); Troika studio
  loops are `if (n > 0) { off = 0; do { ...; j++; off += size; } while (j < n); }` (0x100c7be0); `p = e ? e->m : 0;
  if (!p) { X; return; }` keeps X its own copy (0x10384ab0); CRestore Read* = Valve's ReadSimple verbatim
  (0x101a2320); Valve's SSE
  helpers match with their `__asm` pasted into a plain function (0x1013d2e0, `_SSE_RSqrtAccurate`).
- **Round 7 (second pass on score 1-2 + untried 20-35, 22 matched):** the thiscall lever has two more forms: a
  stdcall callee whose caller never loads ecx (`mov esi,ecx; call X`: ecx still holds the caller's `this`) is a member
  of the caller's view (0x101e12a0, 0x10219400, 0x102dd470); and a function that calls a member of class C without
  loading ecx is itself a member of C (view `struct V : C { void sub_self(...); }`, 0x102e3a60, 0x10193c30).
- **Parameter width moves dead-slot reuse:** a bool/char/short parameter instead of int changes which dead argument
  slot gets a float spill; the target's own signature can be changed in a view method (0x102ed540).
- **Jump tables:** an entry 0 that goes to the default block = `case 0:` with its own copy of the default body
  (`case 0: default:` gives a compare chain, 0x102b8980); a later block jumping back into an earlier case's tail =
  identical bodies spread so one copy sits before and one after (0x103e01d0).
- **Header inlines as out-of-line copies:** `#pragma inline_depth(0)` plus a wrapper that calls the inline, TARGET the
  mangled member name: the compiler's own copy is judged (bf_read::ReadUBitLong 0x1011d340). bf_read one-liners
  (ReadByte, ReadWord) are `return ReadUBitLong(N);` in a `struct bf_readX : bf_read` view.
- **Virtual-inheritance constructors** judge as `X::X(...) : m(1) { body(); }` once the vbtables are named
  (`??_8X@@7B0@@`, `??_8X@@7BBase@@@`, read the offsets with read_data) (VKeyValues 0x101f1f50).
- **Smaller round 7 levers:** `if (!x) return false; return true;` instead of `return x ? true : false;` changes
  which `xor al,al; ret` earlier returns cross-jump to (0x103ddaf0); an else-if chain with one shared `return true`
  (0x1021b9c0); nested SDK inlines (`entindex()` calling a static ENTINDEX) move registers far away (0x100a0130);
  Python bindings: `p = !ent ? 0 : ent->m; if (!p) {...}` and None as `++*g_109f3748; return g_109f3748;`
  (0x10198070); a container element pointer declared inside `if (arr[i].m_p)` (0x102daf80); an inline called from a
  `__forceinline` view member stays an unlinkable call: use `__forceinline` free helpers (0x101265d0).
- **Round 8 (34 matched; SDK identification was most of it):** unnamed math/utility functions are often Valve's
  code under an SDK name: name it first, then write it verbatim (vmatrix.cpp Transpose/Transpose3x3/Scale/
  MatrixMultiply/Vector3DMultiply, mathlib BoxOnPlaneSide, Catmull_Rom_Spline_Tangent, _SSE2_SinCos/_SSE2_cos,
  VectorTransformSSE, dispcoll_common AxisTestEdgeCrossZ1, wcedit UndoDestroyAINode, ai_basenpc WalkMove,
  ai_pathfinder RouteToNode). Hand rebuilds of the same math had stalled at 100-300.
- **"Loads all 16 floats before any store" = an inline 16-argument call:** a VMatrix returned by value through the
  16-float constructor or `Init(16 args)` (ret-4 thiscall with a hidden return pointer). An empty user-declared
  `VMatrix() {}` changes x87 operand order of `tmp1, tmp2` users (MatrixMultiply 0x1024e260; include/VMatrix.h has
  no constructors yet, a local view class with them is used).
- **SDK `__asm` (SSE/SSE2/3DNow) pasted into a plain function** matches; `_ps_*` constants are `extern int g_X`
  operands; a game ebp frame on a no-locals asm function = `#pragma optimize("y", off)` (0x10137b20). Hand-scheduled
  plain-x87 asm (TransformAndRotate 0x101382f0, naked VectorMA) is accepted only as a verbatim copy of the
  [reference] block (2026-11-14).
- **Struct members as Vector, not float[3]** (`cplane_t::normal`): `operator[]` decides the load order (0x10139200).
- **x87 in double:** `fld [m]; faddp st(N)` where ours is `fxch; fadd [m]` = the add done in double, `(double)a + b`
  (0x102808c0); `fild a; fidiv b` kept together = `(a + 0.0f) / b` (0x101d8b40); `fxch st(1); fxch st(1)` after
  fpatan = `(double)a - (float)atan2(y, x) * g` (0x103229d0).
- **Smaller round 8 levers:** a Vector temporary copied with integer moves = implicit POD struct copy (`*(V3 *)&dst =
  *(V3 *)&tmp`, workaround, 0x103cb920); VC6's per-function inline budget: drop trivial wrapper inlines so every copy
  of a heavier inline expands (0x10198cc0); a hoisted `mov edi,[DevMsg]; call edi` = C++ `__declspec(dllimport) void
  DevMsg(const char *, ...)`; a search loop returning from inside = an inline helper returning id or -1; two
  identical `call; epilogue` copies = ONE return after if/else (0x101989b0); a wrong order at a function's END can
  come from its START (write the SDK front, 0x10130800); `p->f(a, b, p->g())` shares one vtable load: stage `p->g()`
  when the game reloads (0x1022d5a0); `return T(*(T *)p);` for a hidden-pointer return copied from a callee's
  pointer (0x101e8330).
- **Round 9 (16 of 46; third passes on score-2 walls gave 0):** collisionutils.cpp (2004) holds the big unnamed
  collision functions: ComputeSeparatingPlane (0x102437d0, needs `#define FloatMakePositive(f) ((float)fabs(f))` as
  a macro, not an inline), IsBoxIntersectingTriangle (0x10244910: the SDK's function-scope locals in sibling `{}`
  blocks give the game's frame), IsRayIntersectingOBB (0x102441b0, 45, slots). Troika's AI condition sets are
  `CFixedBitString<192>` with the SDK bodies through pointer locals (`a.And(b, &out)` loads b first, 0x10280ff0);
  `CBitString` locals with inline ctor/dtor (0x102ff3e0 FindShortRandomPath); bitbuf.h ReadOneBitNoCheck
  (0x100be060); `string_t` by value to inline setters and SetName/SetHintGroup (0x1034c2d0); CUtlVector FastRemove
  from utlvector.h with `Destruct` and memmove (0x103e32b0); an unmerged second null test = re-read through a
  separate cast of `this` (0x10260540); a small buffer at a dead parameter's home = `char sz[4]`; check format
  strings against the DLL bytes; score 1 "absolute-address slots differ" = declare the literal-address object
  `extern T g_X;`; scrambled records read through an `operator unsigned()` on the record view (0x102ae920).
- **Still open after three passes (scheduling walls, do not reassign without a new idea):** 0x103e0540 / 0x1037b1f0 /
  0x100e05f0 (`mov ecx,obj` before `push reg`: the source defined that register there), 0x101bef50, 0x1036dd20,
  0x102f6d80 (FindAINodeNearestFacing), 0x10410bf0 (LaunchObject), 0x101cf7c0, 0x102478f0, 0x102b7cf0, 0x102a0490,
  0x102961a0, 0x102ef1a0 (OnFailedSteer), 0x1011fb50 (CheckWaterJump), 0x1024b880, 0x1026cec0.
- **Round 10 (15 of 48, never-tried functions):** more unnamed SDK code: bitbuf.h WriteUBitLong (0x100bc860,
  0x100bd450, overflow path sets m_bOverflow before m_iCurBit), choreoscene.cpp EventThink (0x1007d300),
  soundenvelope.cpp CommandClear with utlpriorityqueue.h RemoveAt (0x101bcae0), ai_networkmanager.cpp
  CAI_NetworkBuilder::Rebuild's first loop (0x102f4be0: node accessors as view inlines, called through
  `m_ppNodes[i]` each time), GenerateBlockingEntityList with the real CUtlVector (0x10036fb0). Known names still
  open: 0x1014cbf0 physgun CreatePelletAttraction, 0x102fe150 ai_pathfinder FindBestPath (inlined in HasPathInner,
  18: two CBitString slots swapped), 0x102eaaf0 ai_nav_property NavPropertyAdd (55, registers). Idioms:
  - a dead conditional stack store of an entity-slot pointer = a `T *volatile p` local assigned in an `if`
    (0x10169660; it also moves the hoisted entity-list load);
  - a mid-function Vector local sharing the slot of earlier statement temporaries (our frame one Vector larger) =
    put that local and the rest of the function in a `{}` block (0x1012c150);
  - an offset counter compared with a small constant beside a separate pointer IV = a loop inside an inline member
    of a global table object; a search loop returning its index = inline `bool Find(..., int &idx)` (0x101f6a30);
  - a pointer parameter both kept in a register and passed by address had a local copy (`const char *p = param;`);
  - a full Vector op with a dead component changes which component VC6 keeps on the x87 stack later
    (`d = a - b` vs x/y stores, 0x103acba0); the SDK accessor (`GetNavigator()`) changes entry register choice;
  - `fld [const]; fadd [var]` with the constant first = the constant is a global float `extern float g_X;`; a
    float argument `fld; fstp [esp]` from an angle = `((const QAngle &)ang)[1]`; two dwords copied from a Vector =
    a Vector local of which only x/y are used (0x10329a70);
  - CBitString bit ops with `shl eax,2; [eax+base]` = `int *p = m_pData + (bit >> 5); *p |= mask;`;
  - VC6 spends the inline budget from the END of a function backward: the earliest sites stay calls; a trailing
    dead `(void)inlineFn(x);` takes budget (workaround, 0x102daac0);
  - if/else bodies that differ in one init call are tail-merged into the game's single copy (0x102a99e0);
  - two calls through one global in a loop: keep both in one comparison, or VC6 hoists the global (0x1017c300);
  - Python bindings: `if (!p) {...} else return X;` plus one final `return 0;` gives the cross-jumped error tails.
  Unsolved, seen twice: x87 `fmul/fadd st(1)` ... `fstp st(0)` (value kept on the stack, 0x101200c0, 0x101c2d20).
- **Round 11 (17 of 59, 2026-11-13, functions Opus had tried but no hand agent):** SDK verbatim again: bitbuf
  WriteBitCoord (0x100bd1d0) and WriteSBitLong (0x100bc600) through a `struct bf_write03 : bf_write` view with
  that file's inlines; physconstraint CreateConstraint (0x1002bb90, keep the DEAD `params.torqueLimit = ...` line:
  dead SDK statements still move x87 scheduling); AddTriOverlayLines; rope CalcRopeStartingConditions;
  player_lagcompensation FrameUpdatePostEntityThink; InitGroundNodePosition. Idioms:
  - CUtlRBTree members the game keeps partly out of line: an explicit `template<>` specialisation of the member
    whose view calls the out-of-line callees by their jump-stub names (0x102ce150);
  - a member vector read through a reference local lets VC6 cache its pointers across a loop; a cast at every
    use gives the game's per-pass reloads (0x102dc8f0);
  - look for a matched function with the same byte sequence and copy its helper spelling first (ENTINDEX(void *)
    for StopSound, 0x1020c9a0); SDK `edict()` / `entindex()` accessor pair fixes eax/edx swaps around vfunc35;
  - two matched Ray hull inits to copy as header-free local views: 0x10218320 (CHullRay + float HullSqrt) and
    0x1026e940 (UTIL_TraceHull with bTraceOffset); pick by the radius x87 shape;
  - header-patch near misses move into the source: a local field view (`#define F ((View *)this)`), view methods
    named sub_<addr>, local base+derived classes declaring the right `virtual int vfuncN(...)`; an extra dtor via
    `struct L : T { ~L() { sub_X(); } };`;
  - the save refuses local classes named after game classes; a non-game view with its vptr set by hand in a
    `__forceinline` ctor (`*(void **)this = g_<vtable>`) saves (0x1042db40, WORKAROUND);
  - `~CBaseEntity` (0x1009df20) matched with a unit-only macro on a neighbouring declaration (WORKAROUND); the
    slim prelude adds includes BEFORE the source, so declare the triggering name `extern` yourself;
  - unfolded SDK DEG2RAD `(float)(x) * (float)(M_PI_F / 180.f)` for a score-2 store wall (0x102a1650);
  - switch: `sub eax,N` = inside one switch's compare tree, `add eax,-N` = a separate switch (0x10297ce0, 1);
  - `(x >> bit) & 1` through an inline `IsBitSet(unsigned, int)` gives shr (signed: sar);
  - 0x10430520 was a size error (658 B swallowed padding + import thunks): size set to 46 by hand, matched with
    `#pragma optimize("", off)`. A far miss on a tiny SafeDisc-area helper: check the span first.
  0x101b2e30 was saved under the view name CSoundEmitterSystemBaseV::sub_101b2e30 (was provisional vfunc2): watch
  the link audit for its vtable slot.
- **Round 12 (12 of 40 BIG 1-3 KB functions, 20.5 KB, 2026-11-13):** the inline budget is the main wall of big
  functions. Idioms:
  - VPROF: `CVProfile::EnterScope` is an inline member of a dllimport class;
    VC6 decides per site whether to expand it. Defining its inline body in the source (allowed over the header's
    dllimport declaration), or the whole tier0 profiler as local `class __declspec(dllimport)` classes
    (scratchpad work/vprof_local.h, session 30d205cb; offsets m_enabled 0x100c, m_pCurNode 0x1014, CVProfNode
    m_pParent 0x48), gives uncached `call [imp]` and frees the register (0x10270b20 116 -> 0, 0x10040390 102 -> 13);
  - spend or free budget on purpose: SDK accessor inlines (GetAbsVelocity, IsWorld -> entindex -> edict, nested)
    use it; a dead `(void)Inl(x);` near the end uses it (WORKAROUND: 0x10270b20, 0x103645a0, 0x10365a90); writing
    an inline out by hand frees it. It decides how deep ~CUtlVector -> Purge -> RemoveAll expands at each filter
    teardown and which vector gets which stack slot. Search it by judging sets of code-neutral wrappers in
    parallel (scratchpad h49/pm.py: 0x102c0520 31 -> 4 in ~30 s);
  - nested SDK accessor inlines fix registers far away (IsWorld chain fixed a lea rotation 150 B earlier);
  - x87 knobs: mixed indexing `d[0]*d.x` / `v[2]*p[2]` (by-value const operator[] on some terms) sets the sum
    order (0x10306700, 0x10034590); `double t = v.Length() * 0.2; if (a < t)` keeps the fcomp before the cdecl pop;
    staging `float t = a.y; s.y = t + y;` flips the operand order in loops; `*(const float *)&m_nX` for a union
    float; the count of dead int locals flips one fadd with period 8 (a VC6 hash: sweep it);
  - a same-unit callee defined earlier (auto_inline off) tells VC6 its clobbers: a read-only body that clobbers
    ecx gives "global cached in edi, ecx reloaded per call" (WORKAROUND, 0x1027d170);
  - header patches move into the source: `#define name() name(); bool newdecl(args)` before the include and
    `#undef` after (macro injection of a declaration); existing `virtual slotN` as the target name
    (`// TARGET: CGameMovement::slot17`); member-function-pointer views for vcalls instead of a __fastcall dummy
    (that emits `xor edx,edx`): 0x1016d260 104 -> 67;
  - 20-byte zero block with its own zero register in ascending stores = `memset(p, 0, 20)` (32+ B is rep stosd);
  - strong string_t in saverestore: POD `{ const char *pszValue; }` passed BY VALUE (0x101a2e40).
  Saved under view names (watch the link audit): 0x10365a90 CNPC_VBachCamp::sub_10365a90, 0x1027d170
  CAI_CineCleanupNPC::sub_1027d170. Near misses: 0x10333ad0 (4), 0x101226b0 (7), 0x103d2a10 (11), 0x10254450 (12),
  0x100cc430 (12), 0x102da0d0 (12), 0x10040390 (13).
- **Near-miss pass (13 of 63 functions scored 1-15, 8.4 KB, 2026-11-13):** the round-10..12 idioms closed most:
  - x87 kept-alive reciprocal (`fmul st(1)` ... `fstp st(0)` at the end): `const Vector &cd = d;
    Vector n(cd[0] * r, cd[1] * r, 0);` (by-value const operator[] on the reference; 0x10295ed0). Untested yet on
    the x87 near misses 0x101200c0, 0x101c2d20, 0x101cb340, 0x103264d0, 0x103efa30 (3);
  - a one-level `__forceinline Vector VMulG(const Vector &v, float fl)` instead of the SDK two-level operator chain
    frees inline budget (0x101b06a0); `#define inline __forceinline` around `#include "Vector.h"` replaces a
    Vector.h patch (0x102bf820 5 -> 2);
  - `if (0) Purge();` spends inline budget with no code (inlining runs before dead-code removal): WORKAROUND,
    0x1023a7d0; five dummy struct declarations revived 0x102f9cd0 (declaration-count hash, unstable: WORKAROUND);
  - a scope-trace string ("CDialog::~CDialog") is evidence for rename_symbol: the stub got `??1CDialog@@QAE@XZ`
    and the rejudge matched 0x100df590 without a new source;
  - lead: a byte-copy loop pair may be the compiler-generated implicit `operator=` (target
    `??4S@@QAEAAU0@ABU0@@Z`; 0x1025b930 needs the record's real member list).
  Saved under view names (watch the link audit): 0x103f03e0 CFrag914::sub_103f03e0, 0x10295ed0
  CAI_BaseNPCTroikaV::sub_10295ed0. Unsolved patterns: the game hoists pointer loads above stack stores
  (0x102e7e80, 0x101001e0, 0x10176930); include-loop address reassociation (0x10429080, 0x10427df0, 0x101810f0).
- **Round 16 + family / near-miss / holder passes (2026-11-13, vtmb 15,955 -> 16,005):** register rules measured on
  small functions are in docs/vc6-register-rules.md (R1 weight = refs, esi>edi>ebx>ebp; R2 ties go to the value
  DEFINED first; R7 int -1 and 0 are register candidates by count; R9 one eax->ecx->edx cursor runs through the whole
  function). Search before guessing: `pcdecomp holders` / the compile_and_diff `holders:` block list matched functions
  whose game code has the game's instructions where yours differ; read that spot of their source. New idioms:
  - big switches: InitCustomSchedules bodies generated from a matched twin's PushBack list; case bodies in the game's
    code order; `default:` first + separate `case 0:` last (or `case 0: case 1: ; default:`) keeps the table from 0;
    `case 0: goto other; ... default: other:` keeps one push per arm; teardown copies inside each failing `if` with
    their own `return`; `bool b = A(); if (!b) b = B(); if (b) {...}` = local zero register + success-first.
  - inline budget: N inlined sites then out-of-line = `__forceinline` wrapper for the first N + explicit
    `sub_<outofline>` calls; POD `*(Vec3 *)&v = *p` frees budget, Vector operator= spends it; dead `if (0)` uses spend it.
  - zero register: whole-function threshold; an int 0 counts, a float 0.0f store does not; a dead SDK range clamp
    (`if (i < 0 || i >= n) i = 0;`) in an inline accessor adds zero uses.
  - copy order (call-returned pointer into an address-taken local): named int locals, loads in order, stores in the
    game's order (`a,b,c; c,b,a` / `a,b; b,a; c direct` / interleaved `La Lb Sa Lc Sb Sc`); fails when the game keeps
    a dead store, and when the destination escapes to a non-inline call (escape wall: 0x101001e0, 0x10177c10).
  - slots: a literal float compare counts as a reference to the variable, `extern float g_<const addr>` does not;
    a named float local's slot follows first mention (`if (0) x = 0;`); one unnamed temporary passed straight as an
    argument can shift every high temporary.
  - x87: CHullRay member `__forceinline Init` (`float fl = sqrt(..); m_f34 = fl; if (m_f34 > 1e-6)`) = `fxch; fadd
    st(1); fsqrt; fstp st(1)`; `mins[0] + maxs.x` sets the commuted fadd order; float member template view without
    outer parens changes operand order; unresolved `fcomp [0]` needs `extern` g_104454c4 / g_104492dc.
  - calls: a `lea` pushed before an inner virtual call can be the outer call's last argument (check `ret N`); VC6
    alternates eax/edx between consecutive virtual calls and code-free inline helpers advance it (open-code them);
    callers' declarations in src/ tell parameter types (char); macro injection `#define sub_X() sub_X(); virtual
    int vfuncN()` adds a missing override (slim narrow form only).
  - a big all-member copy can be the compiler-generated `operator=`: force it out of line with `&S::operator=`.
- **Round 15 (28 of 63 never-hand-tried functions, 31.2 KB, 2026-11-13; 1-3 KB ones 17/41, mostly SDK code):** new idioms:
  - inline budget: `__forceinline` forward declarations of header free inlines (VectorSubtract before Vector.h,
    StatDefault2 helpers) keep them inline when the budget runs out (0x1040f940, 0x1017aa40); dead
    `if (0) { Vector q = -right; }` spends budget so a depth-2 ctor goes out of line; calling
    Clear/Set/HasCondition directly instead of wrappers frees budget for EHANDLE::Get (0x1028efc0).
  - factories/ctors: a `__declspec(novtable)` view with a manual vptr store; a this-returning method and a ctor
    compile alike, take the name the factory calls (rename_symbol, 0x10407b30, 0x102258a0); hand-written ??_E.
  - frame/slots: `{}` blocks around mid-function temporaries shrink the frame (0x10292de0, 0x10241620); a goto into
    a shared exit tail stops slot packing, write the tail out again (VC6 tail-merges it); a function-scope result
    local shared by tail-merged switch cases; a goto-target assignment block `if (0) { L: x = t; }` after a switch.
  - order: copy through a temporary `Vector pos = Vector(*p->slot217());` closes an interleaved-store copy wall;
    a float z temp then x/y/z member stores gives integer x/y copies; member-assign Vector copies ints, the
    Vector(x,y,z) ctor copies fld/fstp; store-then-read-back member `m = expr; int n = m;`.
  - x87: `0.5 * q * q + 0.5` (VC6 rewrites `q*q*0.5 + 0.5` as `(q*q+1)*0.5`); dot association
    `a.x*b.x + (a.y*b.y + a.z*b.z)`; Length() operand order follows the count of Vector temporaries (dead
    `if (0) (void)(a - b);` per site, 0x102fd240); `(a-b).Length()` + `fabs(dz)` from one delta = fst reuse;
    SDK DEG2RAD spelling; `clamp(x, 0, 50)` with a literal 0 folds as the game.
  - calls: dllimport callees are kept in esi (`call esi`), a function-pointer global is reloaded (0x100e37d0;
    Q_strcat needs extern "C"); a thiscall view member instead of a free __fastcall fixes push/mov ecx order; a
    callee that keeps edx alive goes in the same-unit block (sub_100df010); a non-POD 4-byte struct return is a
    hidden-pointer temp; an inline getter as a call argument picks the argument register.
  - switches/loops: a jump table from 0 needs real labels with dead stores (`case 0: n = 0; break;`);
    `if (n) do { } while (n);` places the loop-exit block as the game (0x10301720).
  - templates: InitCustomSchedules bodies (AI_BEGIN_CUSTOM_NPC, callers of stubs 0x1001528a/0x1000ce8c/0x10006398)
    are generated from the game's PushBack list (scratchpad h89/ext.py) on a matched twin; FindLosNode 0x10302e50
    is the template of FindCover 0x10301720; opcode twin search finds byte twins (0x103835f0 from 0x101839a0).
  - workaround searches: random search over dead `int` locals for commutative operand order (0x10241620) and
    dead-statement anchors for [a+b] index order (0x102630b0); not real source, kept only at 0.
- **Round 14 (20 of 75 never-hand-tried functions scored 14-60, 11.3 KB, 2026-11-13):** new idioms:
  - same-unit block callee beyond x87: a read-only callee in the block lets VC6 keep a global (g_10566458) in a
    register across the call (0x10182550); a LookupEntity (sub_100290c0) block copy must clobber ecx (variable shift
    `h >> g_s` with `static int g_s = 13;`) or VC6 keeps the list in ecx (0x10271900, 0x1017c300);
  - block copy return type = the callee's parameter type from its mangled name (E = unsigned char; bool adds a
    conversion, 0x100e58e0 52 -> 0); a callee called with no ecx setup right after entry is a same-class thiscall
    member using `this` still in ecx (0x101f6530); a recursive call needs a view symbol on another struct (its own
    symbol links to the body, the game calls its stub, 0x101f39d0);
  - the game reloads a register parameter from its stack home: read it once through `*(T *volatile *)&p`
    (0x10333340); `default: if (1) return 1; run: ...; break;` with `goto run` keeps a return block where the game
    has it (0x101655b0, 0x10165f20);
  - zero register: VC6 counts zero uses BEFORE tail merging, so an extra identical `x = 0; return;` tail brings
    `xor ebx,ebx` back (0x1003f4d0); `memset(p, 0, 8)` stores are expanded late and do not count (0x103c5ac0);
  - a dllimport called twice where the game does `call [imp]` both times: call one site through
    `extern R (C::*g_<IAT slot>)(args); (obj->*g_<slot>)(...)` (0x1026f110);
  - `#define inline __forceinline` around `#include "Vector.h"` lifts the Vector inline budget for SDK-verbatim
    bodies (0x101265d0 CanUnduck, 0x1025eaf0 SetHeadDirection); writing `VectorSubtract(a, b, d); d.LengthSqr()`
    for `(a-b).LengthSqr()` frees budget for a later RemoveAll (0x102d1760); splitting a VPROF scope over two block
    inlines lets a sibling-block local's slot be reused (0x10123f40);
  - one inline called in both if/else arms with different constants gives the game's cross-jumped
    "then, join, else jumps back" shape (0x100ee560); a local copy of a global right before the call
    (`T *fs = g_X; f(.., fs, ..)`) or an `int c = n->m;` argument local in an inline fixes push-register rotation
    (0x10228020, 0x101053a0 28 -> 4); STRING applied inside an inline wrapper moves the other arguments' loads
    above its branch (0x100502b0 60 -> 8); `const char *p = STRINGR(x); strcpy(d, p);` gives the one-induction copy
    loop (0x1034b7b0 24 -> 9);
  - an unexplained 4-byte frame difference can be a view struct declared too small that shares a sibling slot:
    use the SDK struct at full size (CBoneAccessor 16 B, 0x10155fb0); a statement-order hill-climb script over
    per-component Init stores beats hand tries for x87 scheduling (0x1016b750 20 -> 12, S/h78/hc750*.py);
  - copying a matched sibling line for line closed 0x1021f920, 0x103c4160 (separate `int edict` local before
    engine->vfunc35), 0x10165f20.
  Hybrid rules now in the briefs: a header-inline target is written `// TARGET:` + `static ... (T::*s_X) = &T::X;`
  (never a non-inline template<> specialisation: LNK2005 with every inline copy); a helper global a source invents
  is defined in its block (`static int g = value;`).
- **Near-miss pass 2 (11 of 40 never-hand-tried near misses scored 1-13, 5.5 KB, 2026-11-13):** new idioms:
  - one inline expansion too many (game calls the 4th AddDataAccessor out of line): dead `if (0) m[i] = 0;` stores
    inside the CALLEE's body raise its cost; sweep the count (0x1003c660: 1 = 13, 2 = 0, 3+ = 25). The same dead
    code in the caller only pushes other inlines out;
  - a record passed by address (AI_NavGoal_t): build it as a temporary in the argument list through an inline
    `SetGoal(const T &g, unsigned f = 0)` view wrapper, with the SDK ctor's default args (`float tol = g_<per-unit
    const>`, `pTarget = g_<null>`) in the init list; a named local keeps a different copy schedule (0x103ac740,
    0x1035f650: twins, 17 -> 0 with the same form);
  - fadd/fmul operand order per component: a temp-returning `AddV(a, b)` with by-value `a[1]`/`a[2]` on just the
    components the game flips (0x1011fb50 y,z; 0x1032a490 x,z); the same mix in a `Vector(...)` ctor never closes;
    SDK VectorLerp through operator[] fixes a lerp's schedule against a nearby struct copy (0x10121ce0);
  - two byte-identical tails VC6 cross-jumps but the game keeps: call the callee through a view method named
    `sub_<addr>` on ANOTHER class in one tail; different symbols, same stub (0x103954e0);
  - a clamp as a ternary initializer `int n = (c < 20) ? c : 20;`, not `if (n >= 20) n = 20;` (registers rotate,
    0x103451d0); a named local for a constant used twice moves a later loop's temp registers (0x1024b880, SDK
    `I prev = InvalidIndex()`); `switch (p != 0) { case 0: return; }` keeps an unthreaded ternary-join test
    (0x10254250); a cheaper `template <> CUtlVector<int>::RemoveAll() { m_Size = 0; }` lets the inliner take the
    teardown the game inlines (0x100a6c50);
  - copy the same-class sibling's loop line for line (early-return form) to get the game's tail merge (0x1008eb70
    after CalcPose 0x1008e770).
  Judges 0 but unsaved: 0x1002dc50 needs `static T *g_106b89bc;` (SDK file-static g_pShadowEntities); a defined
  static gets its own storage in the linked hybrid (hybrid/binding.py DATA), so it waits for a tool rule binding
  g_<addr> statics. Twin walls: 0x103e0540/0x1037b1f0 `mov ecx,imm` before `push esi` (only these two in the DLL);
  reload-order walls 0x102f6d80/0x101e56e0 (game reloads in the reverse order).
- **Round 13 (14 of 40 never-hand-tried >1 KB functions, 19.9 KB, 2026-11-13):** SDK identification again won the
  biggest ones (0x1018b7e0 ClientData_Update 320 -> 0, 0x100f4b90 CGibShooter::ShootThink 288, 0x1011d980
  DrawDispCollPlane 242, 0x1017b8a0 VPhysicsShadowUpdate 301, 0x101213b0 WalkMove 209 via local dllimport VPROF).
  New idioms:
  - x87 value kept across a call (`fld c; call f; ... fstp st(0)`): the callee is in the same unit; define it before
    the caller in a `block_<caller>` namespace under `#pragma auto_inline(off)` (0x1017b8a0: callee 0x1016b980).
    VC6 then knows the callee's x87 depth. scratchpad r13/mkblock.py builds such a block from matched callees;
  - identical stores/calls written in both if/else branches give VC6's tail-merged single copy (0x1018b7e0,
    0x10206da0); `if ((bool)((m_iEFlags >> 12) & 1))` gives `shr eax,0xc; test al,1` where `& 0x1000` caches the
    mask in a register and shifts the whole function (0x1017b8a0 92 -> 5);
  - an int local mask `int m = 0xb10; f = (f & ~m) | (t & m);` changes the register choice of a flag merge;
  - a CUtlVector whose ctor/AddMultipleToTail are out of line under another symbol: explicit `template <>`
    specialisations before use that call the view member (0x102e8b80, 0x103cfc50); re-index `list[i].f` in every
    statement instead of an element pointer; declare-then-assign `Vector v; v = f();` keeps separate return temps;
  - the bf_read ReadOneBit with CheckForOverflow as an inline view method named after its out-of-line address
    (0x1011ccc0); `extern "C" __declspec(dllimport) float RandomFloat(float, float)` for the vstdlib import;
    `extern char g_X[]; vt = (void *)g_X;` fixes a score-1 vftable reloc; `extern T g_X; g_X.f()` instead of a
    cast address fixes a relocation-only mismatch;
  - sibling blocks `{ Vector a; ... } { Vector b; ... }` share stack slots (0x102441b0); splitting an inline address
    expression into a local inside the inline changes VC6's sum association (0x100c67b0);
  - forward-declaring `__forceinline void VectorSubtract(...)` before `#include "Vector.h"` forces that inline.
  Near misses left: 0x103302e0 (9), 0x10326de0 (14), 0x101257b0 (14), 0x103ed9b0 (17), 0x10301010 (18),
  0x102fe150 (18), 0x1014a4f0 (25), 0x1014d7c0 (25), 0x102fa630 (27), 0x10188de0 (29).
- **x87 retry (6 of 24 open x87 near misses, 4.1 KB, 2026-11-13):** the game keeps a scale on the x87 stack
  (`fld s; fld x; fmul st(1); fstp x; ... fstp st(0)`); ours reloads it (`fmul [mem]`). Forms that give the game's
  shape (try each; which one depends on the function):
  - by-value const operator[] on the LAST component only: `const Vector &cv = v; v.x = cv.x*s; v.y = cv.y*s;
    v.z = cv[2]*s;` (0x103efa30, 0x103f0d10); `v *= s`, `v.x *= s`, by-ref VectorScale, `v = v*s` all reload;
  - same for adds: `v.x = v.x + a.x; v.y = ((const Vector &)v)[1] + a.y; ...` where the game does `fadd st(1)`;
  - a temp-returning helper `inline Vector MulV(const Vector &a, float b) { Vector r; r.x = a[0]*b; r.y = a[1]*b;
    r.z = a[2]*b; return r; }` behind `MulF(float, const Vector &)` in place of the SDK `fl * v` (0x101cb340);
  - a plain `Vector n(d.x * r, d.y * r, 0.0f)` ctor (0x102961a0: here the const-ref form went to 41);
  - a `double` scale: `double s = a / b; v.x *= s; ...` (0x101200c0) or `double f = cvar; p - (e - f * dir)` gives
    `fld st(0)` reuse (0x103264d0).
  Also: one nested ternary instead of a count local + if/else fixed both loops' registers (0x10350620); `x < 0.0f`
  and `0.0f > x` compile differently (fcom [const] vs fld const; fcomp st(1)).
  Recurring wall NOT moved by any source form (5 functions: 0x102a0490, 0x10176930, 0x10410bf0, 0x102bf820,
  0x101001e0): a copy from a pointer a call returned into a local whose address then goes to an out-of-line call
  (Ray Init): the game loads all components before storing any; ours interleaves. Likely needs a header/tool look.
  Studied 2026-11-13 with standalone VC6 probes (session 30d205cb scratchpad cw/p, run.bat = cl /O2 /FAs): this
  VC6 serializes every copy into an address-taken local (ld x, st x, ld y, st y, ...), whatever the source form
  (implicit/user copy ctor, operator=, POD struct, const local, by-value return, inline or out-of-line Init,
  Base()/&v.x/reference) or flag (/Oa, /Ow, /G3-/G6, /GX, pragma a/w). Free order only when the destination does
  not escape or a copy-propagated temp sits in between (the frame grows). Among Ray-init callers: matched 23
  serialized / 0 free; the free ones are all open (0x10410bf0, 0x102a0490, 0x10176930, 0x101001e0, 0x10177c10,
  0x10086910, 0x102c3b50). Do not spend more source variants on the copy itself.
- **Same-name plain member + later virtual = shifted vtable (found 2026-11-12):** MSVC puts all functions of one
  name together in the vtable, at the first declaration's position. A plain `void vfunc442(int *)` near the top of
  a class plus the `virtual void vfunc442();` placeholder further down moved slot 442 before slot 134, so every
  new slot of CNPC_VScurrying was one too high (vfunc217_slot called +0x368). Fixed in CNPC_VScurrying.h and
  CFuncMoveLinear.h (one `virtual` declaration with the real signature). Still shifted: CNPC_VHengeyokai.h
  (vfunc292/375; its matched vfunc444 0x10380cb0 depends on the shifted numbering, fix both together);
  CNPC_VCop.h is one slot LOW from vfunc473 (other cause). Never declare a slot name as a plain member when the
  class also has its virtual placeholder; scan with scratchpad samename.py (session 30d205cb).

## VC6 stack slots: what moves them and what does not (measured 2026-11-08, partial)

Measured by compiling small bodies (cache/hand102c3b50/exp2.py prints each tagged local's frame offset):

- **Declaration order and store order never move a slot.** Do not spend attempts reordering declarations.
- **Locals in sibling blocks share a slot** (`{ Vector x; ... } { Vector y; ... }` gives x and y one offset). A local
  of the enclosing scope never shares with them, even when it is only used after the blocks.
- **Dead parameters are reused**: a local (or a float spill) can live in an argument's home slot (`[esp+frame+4+N]`)
  once that argument is no longer read. An offset above the frame is not always an argument read.
- **Order in simple cases**: small objects (4-byte ints, a vtable-only filter) below a Vector, Vector below 72-92
  byte arrays and traces; within a size class the most-referenced local is lowest; ties: the one whose last use comes
  first is lowest. Loop references did not count more in the tests.
- **Not explained yet**: big functions break the size-class order (0x102c3b50: sum (Vector) sits between two 4-byte
  spills; the game's 4-byte trace filter sits above three Vectors). Compiler temporaries (z-spill temps) can land high,
  right below the trace. When only slots differ, record the decoded layout in a note and move on.

## Source recipient filters (CRecipientFilter and friends): write the Source code, never the teardown

Recognise it by `call 0x100035d5` (the CRecipientFilter constructor, 0x1019ce00) on a 0x2c-byte stack object, then
one or two vtable stores and a call, and at the end of the scope the recipient vector's teardown: `mov reg, dword
ptr [_imp__Plat_Free]`, the size (+0x14) zeroed, two `cmp ..., -1` / `call reg` purges, sometimes a loop calling
stub 0x10013e12 (CUtlMemory<int>::Base) per element first, or `call 0x100047aa` (CUtlVector<int>::RemoveAll) and
`call 0x10007275` (CUtlMemory<int>::Purge) instead of the first purge.

The headers hold Source's classes (recipientfilter.h, 2004 public SDK form) on a real CUtlVector<int>
(include/utlvector.h): declare the filter and let it go out of scope. Which of the teardown forms you get is VC6's
inlining choice (deeper classes and bigger functions inline less), and it comes out right by itself when the class
and the rest of the function are right. Never write the teardown, a vtable store, a `char buf[0x2c]` or a copy of
the vector by hand (the old CRecipientVec / Purger views are only for matched code).

| the game's code after `call 0x100035d5` | write |
|---|---|
| vptr 0x1044ba34, AddAllPlayers (0x1000d9f9) | `CBroadcastRecipientFilter filter;` |
| ... then vptr 0x10462828, MakeReliable (0x1001186f) | `CReliableBroadcastFilter filter;` (= CRelieableBroadcastRecipientFilter) |
| vptr 0x104540e8, AddRecipient (0x1001531b) | `CSingleUserRecipientFilter filter(pPlayer);` |
| ... then vptr 0x10454688, MakeReliable | `CReliableSingleUserRecipientFilter filter(pPlayer);` |
| vptr 0x10455e54, AddRecipientsByPVS (0x100043db) | `CPVSFilter filter(vecOrigin);` |
| vptr 0x104470dc, AddRecipientsByPAS (0x10004caa) | `CPASFilter filter(vecOrigin);` |
| ... then vptr 0x104470b0, Filter (0x1000dfa3) | `CPASAttenuationFilter filter(this);` / `(this, ATTN_NONE)` / `(this, soundlevel)` / `(vecOrigin, 0.8f)` |
| vptr 0x1045ffec, AddAllPlayers | `CEntityMessageFilter filter;` |
| no vtable store, AddAllPlayers | `CRecipientFilter filter; filter.AddAllPlayers();` |

- **CPASAttenuationFilter(entity, ...)** calls GetSoundEmissionOrigin (slot 222, +0x378, a Vector by value: a hidden
  result pointer) twice: once before the CRecipientFilter constructor (the CPASFilter base) and once for Filter. The
  entity may be any class that declares `virtual Vector GetSoundEmissionOrigin();` in slot 222: cast `this` to
  `CEntitySoundOriginView *` when the class's own header does not. The float pushed for Filter tells the form: 0.8f
  (or nothing) = `filter(this)`, 0 = `filter(this, ATTN_NONE)`, an `idiv` of 20 by (soundlevel - 50) else the double 4.0
  = `filter(this, soundlevel)` with a `soundlevel_t` argument (SNDLVL_TO_ATTN, CPASAttenuationFilter.h).
- **Calls after the constructor**: Source's names are declared and known to the symbol map: `filter.MakeReliable()`,
  `filter.UsePredictionRules()` (0x10005ce0), `filter.AddRecipient(pPlayer)`, `filter.AddAllPlayers()`, `Reset()`,
  `Filter(origin, attenuation)`. The old sub_ names (sub_1019cf50, sub_1019d3d0, ...) are the same functions.
- **Pass the filter** to the engine (g_1070b22c slot 65 UserMessageBegin, g_1070b248 sound slots) as `&filter`. An
  argument that the game loads before the filter's construction is a local declared before it, e.g.
  `int edict = m_pEdict2e0;` then the call (0x103e7680: score 11 without the local, 0 with it).

Matched this way on the bench copy (2026-10-22): 0x10143630, 0x101c75a0 (CReliableBroadcastFilter: the Base()
loop came by itself), 0x103e7680 (CPASAttenuationFilter(this, ATTN_NONE)), and three matched functions rewritten from
hand-made views into this form (0x101f5b60, 0x1020c890, 0x103e2d10).

## Source containers (CUtlVector, CUtlMemory, CUtlRBTree): write the Source call, never the inlined steps

`include/utlvector.h`, `utlmemory.h` and `utlrbtree.h` hold Source's container templates (tier1, 2004 public SDK
form) with every member inline, as the game compiled them. Recognise them by:

- **CUtlVector** (0x14 bytes: memory +0, allocation count +4, grow size +8, size +0xc, element pointer +0x10):
  `cmp size+1, alloc; jle` then Grow (inline: `cmp grow, -1`, a doubling loop, `call [0x109f3638]` Plat_Realloc /
  `call [0x109f3634]` Plat_Alloc; or a call to the out-of-line copy), `+0x10 = memory`, a `memmove` of the tail and a
  null-checked store (`lea eax, [mem + i*N]; test eax, eax; je`) = `v.AddToTail(x)` / `v.InsertBefore(i, x)`;
  `size = 0`, `cmp grow, -1`, `call [Plat_Free]` twice = `v.Purge()` or the vector's destructor (a member going out
  of scope: a class with CUtlVector members and an empty destructor body gives the whole teardown);
  memmove down and `--size` = `v.Remove(i)`; a compare loop returning the index or -1 = `v.Find(x)`.
- **CUtlRBTree** (less function +0, node memory +4/+8/+0xc, root, count, first free, total at +0x10.. as words for
  `unsigned short` indices or dwords for `int`): a guarded static filled with 0xffff, 0xffff, 0xffff, 1 (the
  sentinel of `Links()`), nodes of 4 * sizeof(I) + sizeof(T) bytes = `CUtlRBTree<T, I>`. Its own functions are the
  template's members: NewNode, Insert / InsertAt / LinkToParent / InsertRebalance, RotateLeft / RotateRight, Find,
  FindInsertionPosition, RemoveAt / RemoveRebalance / FreeNode, RemoveAll, Purge.

How to write it:

1. Declare the container with its element type: `CUtlVector<int> m_Recipients;`, `CUtlVector<CBaseHandle>`,
   `CUtlVector<CFoo *>`, `CUtlRBTree<CFooEntry, unsigned short>`. Use the real Source type when the game shows it
   (RTTI names such as `CUtlVectorDataOps<CUtlVector<thinkfunc_t, ...>>`, strings, a matched twin). Otherwise define
   the element in the owning class's header as a struct of the element's size named after its owner
   (`struct CBreakModelsPrecached_Entry`), with a constructor / copy only if the game's code runs one.
2. Write the Source call (`m_List.AddToTail(h)`, `m_Tree.Insert(entry)`, `m_Tree.Find(key)`, `m_Tree.Element(i)`,
   a member destroyed by its class's destructor). Never the grow, memmove, Plat_Free, sentinel or rebalancing steps by
   hand, and never `CUtlVector4` / `CUtlVector20` / `CUtlRBTree12` / `UtlMem*` style views in new code (they are kept
   for matched code only).
3. The out-of-line copies are per element type (one CUtlMemory<T>::Grow, one CUtlRBTree<T,I>::Links ... per T). When
   the judge says "cannot link ?Grow@?$CUtlMemory@VCBaseHandle@@@@QAEXH@Z: the game's copy is not known yet", the
   game's `call` there goes to that copy: `rename_symbol` the address the game calls (its body, not the stub) to the
   name the judge prints, then compile again. If the name already belongs to another address, the game's container
   holds a different type: pick another T (another struct of the same size).
4. For a function that IS one of the template's members (an out-of-line `NewNode`, `RotateLeft`, `GrowVector`,
   `Grow`, `Links`, ...), the source is just the instantiation; rename_symbol its own address to the member's name
   first (the judge prints it), then instantiate THAT member only, through a member pointer:

   ```cpp
   // TARGET: ?NewNode@?$CUtlRBTree@UCFooEntry@@G@@QAEGXZ
   #include "utlrbtree.h"
   #include "CFoo.h"	// where CFooEntry is defined
   static unsigned short (CUtlRBTree<CFooEntry, unsigned short>::*s_NewNode)() = &CUtlRBTree<CFooEntry, unsigned short>::NewNode;
   ```

   Never `template class CUtlRBTree<...>;`: it emits every member (Links' sentinel, LinkToParent, RemoveAt ...) into
   the object, and the whole-DLL link audit then finds copies the game does not have (2026-10-25: 14 errors). VC6
   ignores `template unsigned short CUtlRBTree<...>::NewNode();`. One game instance (one sentinel address) is one T:
   before you invent an element struct, look for the instance's existing T (`grep -r "CUtlRBTree<" src include`) and
   for an old `CUtlRBTreeNNAt<0x...>` view of the same sentinel; an old view block reads the links through
   `((const CUtlRBTree<T, I> *)this)->Links(i)` of that T.

Which calls VC6 expands is its own choice, and it follows the whole function: an inline expansion that comes AFTER
the container call in the function (a later inline call, an inline call in another branch, a local whose inline
destructor runs at the end of the scope, such as the ScopeTrace) makes VC6 keep the deep, big members (Grow,
Links) as calls; without one it expands them. So write the whole function the Source way and the calls come out as
in the game; a `call` you do not get usually means a missing inline object or call later in the function. The
former exception CRecipientFilter::AddRecipient (0x1019d040) was exactly that: its missing inline was the prediction
system's `GetSuppressHost()` (a view struct of the global at 0x1072b3fc with the SDK inlines); with it a plain
`m_Recipients.AddToTail(index)` keeps Grow as a call (matched 2026-11-12).

Byte-identical this way on the bench copy (2026-10-23; a new name still needs its rename_symbol): 0x100ecb40 (three `v.Purge()`), 0x100eb490 (a class with three
CUtlVector<int> members and an empty destructor), 0x10323370 AddToPresenceList (`g_List.AddToTail(CEntHandle(this))`
inside a ScopeTrace; Grow stays a call), the RB-tree members 0x10194780 / 0x10055050 NewNode and 0x1004c5b0
RotateLeft (after naming its out-of-line Links), 0x100498c0 LinkToParent and 0x10055f50 RotateLeft (only their
out-of-line callees' names missing).

## Reference source (the view's "reference" part): Valve's code of the same function, not Troika's

When an open function's strings are also in a function of Valve's code (project.toml [reference]: the 2004 Source
SDK), its view ends with that function's source: `get_function(addr, part="reference")` pages
it. Read it for the control flow, the order of the calls and the names of members and locals; then write the game's
version, which Troika changed (other members, added code, other vtable slots). Keep the project's names: the
function is still defined under its own name (`CAI_BaseNPC::vfunc442`, not `StartTask`; slot numbers differ from the
SDK's), and members are the ones in include/ (add a missing one with edit_context, never a copy of the SDK's header).

## Source entity handles (EHANDLE, CHandle<T>): write the Source expression, never the slot lookup

`include/ehandle.h` (in the prelude) holds Source's entity handles in the 2004 public SDK form: `CBaseHandle`,
`CHandle<T>` and `EHANDLE` (= `CHandle<CBaseEntity>`), with Get / Set inline as the game compiled them. Recognise them by:

- **Get** (handle -> entity): `cmp h, -1; je`, `and h, 0x1fff`, `lea [x+x*2]` (12-byte slots) into
  `[0x10566458]+4`, `shr h, 0xd`, compare with the slot's serial, the slot's entity or 0.
  This is `m_hFoo.Get()`, `m_hFoo->vfuncN()`, `if (m_hFoo)`, `m_hFoo == pEnt`.
- **Set** (entity -> handle): `test p, p; je` then `call [vtable+4]` (GetRefEHandle) and `mov eax, [eax]`,
  else -1. This is `m_hFoo = pEnt;`.

How to write it:

1. Type the member as a handle: `EHANDLE m_hOwner364;` or `CHandle<CFoo> m_hFoo;` in place of `unsigned int`
   (same 4 bytes; `patch_context` the one line). Its default constructor stores -1, as the game's constructors do.
   `EHandle_Get(m_hFoo)` (CEHandleGet.h) still compiles for such a member, so matched code is not broken. If the
   header change is rejected, a matched function reads the member as a number (`m_hFoo != -1`,
   `m_hFoo & 0x1fff`): leave that member as it is and use `EHandle_Get(m_hFoo)`.
2. Write the Source code: `if (m_hOwner364.Get() != pOwner) { m_hOwner364 = pOwner; ... }` is the game's
   SetOwnerEntity byte for byte (0x100aab10); `pTarget == m_h628c.Get()` is 0x10372dd0's compare (the operand order
   matters: `m_h628c == pTarget` swaps the compare). Never open-code the slot lookup, never declare your own
   `g_10566458` slot struct, and never declare a private handle struct (`CFooHandle`) in new code.
3. A `CUtlVector<EHANDLE>` / `CUtlVector<CHandle<CFoo> >` is a list of handles (utlvector.h).

## Engine globals (gpGlobals): use globalvars.h, never a local view of g_1070b228

`include/globalvars.h` (in the prelude) declares the engine's global variables at g_1070b228 as `gpGlobals`:
`gpGlobals->curtime` (+0xc), `->frametime` (+0x10), `->realtime` (+0x0), `->framecount` (+0x4),
`->absoluteframetime` (+0x8), `->maxClients` (+0x14), `->mapname` (+0x24, const char *), `->mapversion` (+0x28),
`->m_nEdicts` (+0x38). Write `gpGlobals->curtime`, not `extern SomeView *g_1070b228;` with a struct of your own.
A member not named yet: add it to globalvars.h with edit_context (it lives in `namespace EngineGlobals`).

## Engine interface (engine): use engineserver.h, never a local view of g_1070b22c

`include/engineserver.h` (in the prelude) declares the engine's server interface at g_1070b22c as `engine`. Slot N
sits at +N*4 of its vtable, so `mov ecx,[0x1070b22c]; ... call [eax+0x150]` is `engine->vfunc84(1)`. Typed slots
include: vfunc13 PrecacheModel(name, preload), vfunc17 precache an emitter / resource by name, vfunc20 model index of
a name, vfunc35 IndexOfEdict, vfunc38 PEntityOfEntIndex, vfunc59 ServerCommand, vfunc61 ClientCommand (variadic),
vfunc65 UserMessageBegin(filter, type) / vfunc66 MessageEnd / vfunc67-72, 78 message writes, vfunc84 Cmd_Argv,
vfunc85 Cmd_Argc. Write `engine->vfunc84(1)`, not `extern SomeView *g_1070b22c;` with a struct of your own, and do
not include CUnknown1070b22c.h or IVEngineServer.h in new code. A slot still declared `void vfuncN()`: give it its
type in engineserver.h with edit_context (it lives in `namespace EngineGlobals`).

## Sound system and random stream (enginesound, enginerandom): use engineiface.h

`include/engineiface.h` (in the prelude) declares the engine's sound system at g_1070b248 as `enginesound` and its
random stream at g_1070b244 as `enginerandom`. Slot N sits at +N*4 of the vtable:
- `enginerandom->vfunc1(lo, hi)` is RandomFloat;
- `enginerandom->vfunc2(lo, hi)` is RandomInt;
- `enginesound->vfunc0(name, preload)` is PrecacheSound;
- `vfunc2` and `vfunc3` are the two EmitSound forms;
- `vfunc4` is EmitSentenceByIndex;
- `vfunc7` is StopSound.

Write `enginerandom->vfunc2(0, 3)`, not `extern SomeView *g_1070b244;` with a struct of your own, and do not include
CUnknown1070b244.h or CUnknown1070b248.h in new code. A slot still declared `void vfuncN()`: give it its type in
engineiface.h with edit_context (it lives in `namespace EngineGlobals`).

## Traces (UTIL_TraceLine, UTIL_TraceHull): use UTIL_Trace.h, never the Ray_t / filter / TraceRay steps by hand

`include/UTIL_Trace.h` holds the SDK's inline trace helpers (game_shared/util_shared.h) as this game inlines them.
In the game a trace looks like: a Ray_t built from two vectors (inline, or `call sub_1006dec0` for a box), a
CTraceFilterSimple ctor (`call 0x101d3190`) or the caller's own filter, `g_1070b254` slot 4 (TraceRay), then the
r_visualizetraces test (`g_10738964` slot 1 and +0x2c) around `call sub_10146570` (DebugDrawLine). Write the SDK call:
- `UTIL_TraceLine(vecStart, vecEnd, mask, pIgnore, collisionGroup, &tr);` (CTraceFilterSimple(pIgnore, group));
- `UTIL_TraceLine(vecStart, vecEnd, mask, &filter, &tr);` (the caller's filter, e.g. CTraceFilterFVisible);
- `UTIL_TraceHull(vecStart, vecEnd, vecMins, vecMaxs, mask, pIgnore, collisionGroup, &tr);` and the `&filter` form
  (the debug line is yellow: 0xff, 0xff, 0).
`CGameTrace tr;` is the trace_t. Evaluate a computed start into a local first when the game computes it before the
end (`Vector vecStart = EyePosition() + ofs; UTIL_TraceLine(vecStart, pEnemy->EyePosition(), ...)`): arguments are
evaluated right to left. Judged 2026-11-07 on three matched functions (0x10274820 line + simple filter, 0x1028ebc0
own filter, 0x1032ad30 hull): each scores 0 written this way. A trace without the visualize test is a direct
`g_1070b254->vfunc4(&ray, mask, &filter, &tr)` (UTIL_TraceRay / enginetrace->TraceRay in the SDK).

The game has two spellings of each inline part, and the helper's name picks them (read the target's asm):
| asm before / after TraceRay | helper |
|---|---|
| Ray_t built inline (fsub/fmul), test reads `g_10738964` | `UTIL_TraceLine` |
| `call 0x1004f7a0` (Ray_t::Init out of line), test reads `g_10738964` | `UTIL_TraceLine_RayCall` |
| Ray_t built inline, test is `mov ecx, 0x10738960; call 0x1005f190` | `UTIL_TraceLine_DebugCall` |
| `call 0x1004f7a0` and `call 0x1005f190` | `UTIL_TraceLine_Calls` |
| box (`call sub_1006dec0`), test reads `g_10738964` / calls 0x1005f190 | `UTIL_TraceHull` / `UTIL_TraceHull_DebugCall` |
Each has the (ignore, group) and the (&filter) overload. The hull forms take the Init's last two byte arguments at
the end (`..., &tr, 1, 0)` when the game pushes 1, 0; default 0, 0). A hull wrapped in a `push "UTIL_TraceHull"`
ScopeTrace: write `{ ScopeTrace scope("UTIL_TraceHull", g_106b8540); UTIL_TraceHull_DebugCall(...); }`.
The inline forms use `Ray_t::InitInline` (`__forceinline`): VC6 decides per call site whether to expand plain
`ray.Init`, and in a big function it may call 0x1004f7a0 where the game expanded it. Judged 2026-11-07: all forms
score 0 on matched functions (0x103e17b0 RayCall, 0x1006afd0 DebugCall, 0x1024f3d0 Calls, 0x103bf660 hull DebugCall
inside ScopeTrace with 1, 0).
