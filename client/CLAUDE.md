# pcdecomp project

This folder is a pcdecomp matching-decompilation workspace. Change source only through the pcdecomp MCP tools
(`claim_function`, `compile_and_diff`, `edit_context`, `patch_context`, `rename_symbol`, `release_function`): they compile with the
game's original compiler and keep every matched function matching. Do not edit `src/` or `include/` by hand; hand
edits in `src/` are re-checked and broken functions go back to the queue.

Start with `guide("workflow")`, then `project_info()` and `claim_function()`.
Never commit the game's own files (client.dll or anything else from the game folder): they belong to its owner.

## Where this project comes from

client.dll of the same game, built by the same compiler (Visual C++ 6.0, `/O2 /GR`) from the same Source engine
tree as vampire.dll. Project `vtmb` (the repository root, one folder up) has matched all of vampire.dll; its CLAUDE.md is the
long record of how. Read it there when a wall below is not enough; never copy text or code from that folder into
this one.

`pcdecomp carry <vtmb project> <client project>` copies vtmb's matched functions onto
client.dll functions whose bytes are the same (relocations and call targets masked), renames them for this binary
and judges each one here. It reads vtmb only. It can be run again: matched functions are no longer open, a score
already noted is not noted twice. Run it before agents edit headers here: a header carry made that someone changed
since is this project's own for carry, and every block that includes it is skipped (`header conflict`).

Carry so far (2026-11-21, seven runs): 1,081 functions matched, 130,654 bytes. 26 of them use inline assembly, so
the progress counts 1,055 of 11,424 functions / 126,299 of 1,636,178 bytes (7.72% of the code that is not skip).
Run 6 paired address placeholders through the operands of the equal bodies (+193). Before run 7, `pcdecomp split`
gave the functions the import had merged into one row their own rows (3,035 rows -> 10,070 functions; the note
`split at 0x...` on each host) and `skip-initializers` marked 6,489 initializer pieces skip; run 7 then matched 502
(319 of them split pieces) and 4 function-local static destroys as companions of their blocks. Why the rest of the
equal-bytes pairs stayed open in run 7: 705 need server classes (their headers define classes client.dll's RTTI
does not have, or reach vtmb's server interfaces; most are one 30-byte scalar deleting destructor shape), 141 a
score above 0, 111 a name this project cannot save (mostly scalar deleting destructors), 59 an unpaired placeholder
(a vampire.dll name that is no operand of the pair, in the block or in a header's inline code), 41 a compile
failure, 21 an RTTI class conflict, 6 the full prelude. 144 notes `carried: from 0x..., score N` mark the same bytes
judged a near miss, a good start for a hand pass. Backups of the database before each step are in cache/
(`project.db.pre-split-20261121`, `.pre-skipinit-`, `.pre-carry7-`).

Then (2026-11-21): five initializer entries that follow a switch's tables were still inside the rows before them;
`pcdecomp split --hosts` cut them (split now takes every initializer table address as a certain cut) and
`skip-initializers` marked those five chains' 18 pieces skip. `pcdecomp lift` (model-free C++ from tiny
straight-line functions, at most 32 bytes) then matched 1,494 functions, 12,754 bytes; it leaves out any function an
initializer chain names. Totals now: 2,575 matched; the progress counts 2,549 of 11,411 functions / 139,053 of
1,635,862 bytes (8.50%). Lift saved them under placeholder names (`CUnknown<address>::sub_<address>`, this binary's
addresses). Backups: cache/`project.db.pre-chaincuts-20261121`, `.pre-skipinit2-`, `.pre-lift-`.

Globals: `pcdecomp globals` writes only initializers already skip, and at first its generators fit 33 of the 2,067:
945 constructs called a constructor with no linker name (client.dll's functions are unnamed; a `??0Class@@` name
gives the class), 47 call InterfaceReg's constructor under a provisional name, about 1,000 are shapes no generator
has yet. A hand naming pass then gave 9 constructors and destructors vtmb's names with `rename_symbol` (four ConVar
constructors and ~ConVar, ConCommand's constructor and destructor, CGameMovement's), each reason citing the
byte-equal vtmb twin, the RTTI vftable it stores and the pushes of the initializers that call it. `pcdecomp globals`
then saved 557 definitions (522 through a named constructor), all in `src/_init/unit_000_100011f0.cpp`: client.dll's
initializer table is one run (vtmb's incremental link gave 251), so that file says nothing about units. Their 2,174
initializer pieces went from skip to matched. Totals now: 4,749 matched; the progress counts 4,723 of 13,585
functions / 171,313 of 1,668,122 bytes (10.27%; the pieces count now, so the total grew). Backups:
cache/`project.db.pre-ctornames-20261121`, `.pre-globals-`.

RecvTable: 0x100e1590 (bytes equal to vtmb's SendTable constructor) is `RecvTable::RecvTable()`, which calls
Construct(NULL, 0, NULL); with 0x100e15b0 (the three-argument constructor), 0x100e15d0 (the empty destructor, where
all 331 globals' destroys jump) and 0x100e15e0 (Construct) it is the SDK's dt_recv.cpp in order. `include/RecvTable.h`
(the SDK's layout, read off Construct's stores) and these names let `pcdecomp globals` save the 331
BEGIN_RECV_TABLE tables (`RecvTable g_X;`) and InterfaceReg's 47 (0x10106be0 now also has its real constructor
name): 378 more, 1,418 pieces, 15,124 bytes. Totals now: 6,144 matched of 15,003 functions / 186,520 of 1,683,246
bytes (11.08%). Next behind them: 333 open functions that fill those tables (each builds its RecvProp list and calls
Construct), 61,755 bytes. Still blocked: classes only RTTI names, with no header here. Backups:
cache/`project.db.pre-recvtable-20261121`, `.pre-recvglobals-`.

Recv table builders (2026-11-21, `pcdecomp recvtables`, pcdecomp main 9f015cc). A hand pass first named, from the
code and the SDK's dt_recv.cpp / cl_dll/recvproxy.cpp:
- RecvProp::RecvProp (0x100e1560; its stores give RecvProp's 13 fields);
- the six prop helpers, each setting m_RecvType to its DPT_ value: RecvPropFloat 0x100e1610, Vector 0x100e1660,
  Int 0x100e16b0, String 0x100e1730, DataTable 0x100e1790, InternalRecvPropArray 0x100e17f0;
- cl_dll's RecvPropTime 0x101277b0, RecvPropPredictableId 0x101277e0 and RecvPropEHandle 0x10127770 (VtMB's has 3
  parameters, the proxy fixed in its body; all 23 callers pass m_h* names);
- 9 proxies: FloatToFloat 0x100e1840, VectorToVector 0x100e1850, Int32ToInt8/16/32 0x100e1870/1880/1890,
  StringToString 0x100e18a0, the Static/Pointer data table proxies 0x100e18e0/18f0, IntToEHandle 0x10127720.

`include/RecvTable.h` gained SendPropType, DVariant, CRecvProxyData, the proxy typedefs (data table proxy:
`void (void **, void *, int)`), RecvProp and the declarations; 12 of those functions matched from the SDK's code.
`pcdecomp split` cut 12 rows at a local static's destroy (11 builders and 0x100ce160) and `skip-initializers`
marked the 12 skip. Then `pcdecomp recvtables` named all 331 builders `?ClientClassInit@@YAHPAUignored@DT_X@@@Z`
and matched them (61,690 bytes), each with its array's 1-byte destroy as a local destroy companion; a `verify` of
20 still matched. `globals --kind recvinit` saved the 331 `g_RecvTableInit` (662 pieces). Totals now: 7,506
matched rows; the panel counts 7,480 of 15,996 functions / 256,261 of 1,690,516 bytes (15.16%). Left unnamed:
0x10127810 (the SDK's static RecvProxy_IntToPredictableId, matched as sub_), 0x10127680 (VtMB's queued handle
lookup) and the game's own proxies (0x10043090, 0x1009d4e0, ...). Backups: cache/`project.db.pre-handpass-20261121`,
`.pre-split-`, `.pre-recvtables-`, `.pre-recvinit-`.

Carry run 8 (2026-11-21, pcdecomp main 6351212). Carry's byte mask used to blank the four bytes after every 0xE8/0xE9
byte, also when that byte was part of an address or of another call's displacement; those bytes differ between the
two DLLs, so long functions with many addresses never looked equal (and a few unequal ones did: `c1 e8 02` against
`c1 e8 03`). It now decodes each body and masks only real call/jmp displacements: 1,252 open functions in 611 groups
instead of 1,080. The run planned 332 and matched 64 (+7 initializer rows matched with them), 83,636 bytes, 68 of them
from groups the old mask missed; the biggest is 0x10068330 (68,194 bytes, the activity list: 4,460 `ACT_` names
registered with their numbers, vampire.dll's 0x104126e0) with its helper 0x10068230. 185 missed by score (most by 1
or 3: a `carried: from 0x..., score N` note marks them, a good hand pass), 47 failed to compile. A `verify` of 19
still matched. Totals now: 7,577 matched rows; the panel counts 7,550 of 16,003 functions / 339,582 of 1,690,523
bytes (20.09%). Backup: cache/`project.db.pre-carry8-20261121`.

Naming pass and carry run 9 (2026-11-21). Run 8's misses were mostly missing names, not different code: carry keeps
a name only where this project knows it at the same address, and this project had no symbol at any import slot, so
a carried `Msg(...)` became `g_101e3108` and the link failed ("not in the game's import table"); names used from
headers (`pfSqrt`, constructors) gave "unknown symbol". A naming pass with `rename_symbol` (agent `carry-names`, 49
commits) added 27 import-slot names copied from vtmb by import name (only names whose own identifier is the
import's: vtmb's slot aliases `Q_strstr` at the Q_stristr slot and `ExitScopeCall` at the ExitScope slot were left
out) and 22 names proven by run 8's byte-equal pairs (`pfSqrt` 0x102be4dc, `pfVectorNormalize` 0x102be4e8,
ConCommandBase's constructor 0x100df1c0, 18 constructors and destructors). Run 9 then planned 275 and matched 132
(+4 initializer rows), 27,206 bytes; all 125 of run 8's misses that a judge-only preview said would match did. 60
missed by score (the `carried:` notes), 47 failed to compile, and 44 wait on one spelling conflict: `_strcmpi`
(0x101e28e0, a skipped CRT row whose linker name is `__strcmpi`) would be spelled both `sub_101e28e0` and
`_strcmpi`. A `verify` of 20 still matched. Totals now: 7,713 matched rows; the panel counts 7,686 of 16,007
functions / 366,788 of 1,690,545 bytes (21.70%). Backups: cache/`project.db.pre-names2-20261121`,
cache/`project.db.pre-carry9-20261121`.

Carry run 10 (2026-11-21, pcdecomp main d212c95). The `_strcmpi` conflict came from vtmb's two linker names for
one CRT function: the C name `__strcmpi` (which this project knows at 0x101e28e0) and a C++ declaration
`?_strcmpi@@YAHPBD0@Z` this project does not know at all. Carry now lets a name this project knows at the paired
address win over an alias it does not know; an alias this project places at another address is still a conflict.
Run 10 planned 187 and matched 39 (+2 initializer rows), 10,235 bytes; all 39 are `_strcmpi` callers. Of the other
5: 0x1008cfa0 (score 3) and 0x10128360 (score 1) missed, and 0x1014f200, 0x1014f700, 0x101a3eb0 now wait on an
unpaired placeholder (a header still spelled `sub_X`). Name conflicts 108 -> 62: 19 are `??_GIRecipientFilter`
deleting destructors and 33 constructors, destructors and vfuncs whose own name this project's row cannot take (no
linker name), and 10 are the `s_default` / `s_Sentinel` statics spelled at two addresses. A `verify` of 20 still matched. Totals now:
7,754 matched rows; the panel counts 7,727 of 16,009 functions / 377,023 of 1,690,556 bytes (22.30%). Backup:
cache/`project.db.pre-carry10-20261121`.

Naming pass 3 and carry run 11 (2026-11-21, pcdecomp main bbf0381). Own names: `rename_symbol` (agent
`carry-names`) gave 17 constructors, destructors and operators the name of vtmb's matched twin, each proven by a
one-to-one carry group (equal bodies, no other function in either DLL has the body), eight of them also by the same
class's vtable store on both sides (CSave, CRestore, CBaseEntityList, CMeasureSection, CMeasureSectionInstance,
VKeyValues). Five more were refused because their class is not declared in include/ (CVFeat_t x2, CEntryX,
StatDefault2, CVStatAction_t); a 1:2 group (??0CUnknown10248a50), a 2:1 group (??4CBaseHandle: vtmb has the body
twice under two names) and six names with a vampire.dll address in a class this project does not use were left
out. Statics: carry used to attach a data operand to the nearest vtmb data symbol below it however far away (vtmb's
symbol map has no `g_` placeholders), so a field of `g_1089d7c8` read as `s_Sentinel + 0x1d522a` and statics got two
spellings; carry now also counts the block's `g_` placeholders as object starts and trusts an exact pair, or inner
pairs that agree. Run 11 planned 174 and matched 23 (+2 initializer rows), 6,896 bytes: 14 of the 17 named
(`CValRecord::operator=` 2,703 B, CBaseEntityList's constructor 383 B; VKeyValues' constructor score 6, destructor
score 2, StatDefault's constructor an unpaired placeholder) and 5 of the 7 the statics fix freed (two `bf_write`
functions reached only through fields of a `g_` placeholder). Name conflicts 62 -> 35 (19 of them the one-body
`??_G` interface destructors). A `verify` of 19 still matched (the 20th sample was an initializer row). Totals now:
7,779 matched rows; the panel counts 7,750 of 16,011 functions / 383,669 of 1,690,576 bytes (22.69%). Backups:
cache/`project.db.pre-names3-20261121`, cache/`project.db.pre-carry11-20261121`.

Scalar deleting destructors (2026-11-22, `pcdecomp gdtors`, applied from pcdecomp branch gdtor-skeletons d790455,
in main since 4ad9d8e). The command reads the class tree from the game's RTTI (each base's contained count) and judges, from every
30-byte `??_G`, which destructor and which operator delete it calls: R1 the destructor stores the class's own vtable,
R2 a base's (no class between has a destructor of its own), R3 the delete belongs to the lowest class whose `??_G`
calls it, R4 names already known must agree. It then writes one skeleton header per class, names the destructors
and deletes with `rename_symbol` (the names are read from the compiled object, never made up), and saves each `??_G`
as an emitter block: `X *pcd_emit_<addr>() { return new X; }` plus `// TARGET: ??_GX@@UAEPAXI@Z` (VC6 writes the
`??_G` where `new` makes it emit the vtable). A skeleton (`include/<Class>.h`, `vgui2__<Class>.h` for vgui2; first
line ends "skeleton from the game's RTTI (pcdecomp gdtors)") declares the bases, the destructor and the operator
delete, nothing else yet, and is written once, never rewritten. IHandleEntity (include/CBaseHandle.h) leaves
`vfunc0` / `vfunc1` pure, so the overrides are declared in the class whose game vtable has a real function at that
slot: C_BaseEntity, C_BaseTempEntity, C_BaseNetworkable and CDetailModel. IClientEntity and CBaseStaticModel have
`__purecall` there and declare none. Result: 531 headers (one commit, e14ec164), 204 names (R1 195, R2 7, R3 2:
`??3C_BaseEntity@@SAXPAX@Z` 0x100a1ec0 for 260 `??_G`, `??3Panel@vgui2@@SAXPAX@Z` 0x101ac660 for 102), and 504
`??_G` matched, 15,120 bytes. Open: CBaseStaticModel's own `??_G` 0x100dfe30, which is abstract in the game, so
`new` cannot make it (it needs a hand emitter); 8 proxies whose `??_G` calls another of the 9 copies of
IMaterialProxy's inline destructor (only 0x100e3300 has the name `IMaterialProxy::~IMaterialProxy`, and one name
names one address); and 34 out of scope (10 under a vtmb header name, 10 declared in include/ already, 3 in an
anonymous namespace, 1 nested). 89 of the named destructors were matched before under a placeholder: the real name
sits beside it as a second symbol, but the block still defines `CUnknown<addr>::sub_<addr>`, so a standalone link
needs those blocks to define the real names. Emitter blocks are temporary. A later header edit that ends an emitter
(the class's real pure virtuals declared, a constructor of its own) releases that `??_G` instead of refusing the
edit (note "emitter-made ??_G released by a header edit"), and `pcdecomp gdtors --retry-released` tries it again.
A score above 0 still refuses the edit. Run the command again after new classes are declared: rows already matched
are evidence, and headers already written are left alone. Totals now: 8,283 matched rows; the panel counts 8,254 of
16,011 functions / 398,789 of 1,690,576 bytes (23.59%). Backup: cache/`project.db.pre-gdtors-20261121`.

Units: `pcdecomp units --apply` saved 4,066 unit guesses in 194 units (functions.unit_guess: the "probably unit"
line and the panel's per-unit progress; it never moves a file), from the reference trees' class homes and the
functions between two of one unit; client.dll's code names no source path. A unit under `_init/` is not read as the
game's (pcdecomp a4c86c9). Doubtful: the 658 guesses of `cl_dll/vgui_scorepanel.cpp` come from one 113 KB gap
between two CLabelHeader vtable slots (0x10171330, 0x1018ce30) with no hint between them. Backup
cache/`project.db.pre-units-20261121`.

Names: client.dll has almost no linker names, so carried functions are saved under this binary's placeholders
(`Class::sub_<address here>`, `g_`, `vt_`), even where the vtmb twin has a real name; a naming pass with
`rename_symbol`, citing the byte-equal vtmb function, can give them vtmb's names. Imported slots are paired by
import name (vampire.dll's `Plat_Free` slot becomes this binary's `Plat_Free` slot). Type names
that embed a vampire.dll address (`CUnknown1004ddc0`, `CUnk101f75f0`, `block_10256200`, `CRBTree12Entry_10194f30`)
came across as they were: the address in them is vampire.dll's, not this binary's. Rename them with
`rename_symbol` when you know the real class.

## VC6 rules that hold here too (measured on vampire.dll; summaries, details in vtmb's CLAUDE.md)

- **Vector code (x87): write Source's operators.** A `call [pfSqrt]` / `call [pfVectorNormalize]` or the "z-spill"
  (x, y, z on the FPU, one through an integer register) is mathlib's inline layer: `a - b`, `.Length()`,
  `VectorNormalize`, `DotProduct`. Assignment of an operator result to a declared local gives the z-spill;
  `Vector d = a - b;` does not. Write float constants as literals (`0.5f`; a `qword` constant is a `double`), declare
  real members instead of casts at offsets, and read angles as QAngle (per component), not Vector. vtmb section:
  "Source mathlib Vector code (x87)".
- **A reload after a store means a read through a pointer or reference.** VC6 hoists a load above a store when it
  can see they differ; when the game stores first, the source read through a reference (`x ? x : ""` through a
  `const char *const &`, a 64-bit addend through a pointer). Reordering statements does not help. vtmb section:
  "VC6 order walls".
- **Write it the way a programmer would.** Declare a local in the innermost block that uses it; call directly
  instead of staging a result in a temporary; a chained assignment instead of a pointer temporary; a plain local
  and a literal instead of a helper. A `__fastcall sub_X(Self *self, int edx, ...)` is a member function. vtmb
  section: "VC6 walls Opus closed".
- **Stack slots.** Declaration order and store order never move a slot; locals in sibling blocks share one; a dead
  argument's home slot is reused. When only slots differ, note the layout and move on. vtmb section: "VC6 stack
  slots".
- **Containers: the Source call, never the inlined steps.** CUtlVector / CUtlMemory / CUtlRBTree code is tier1's
  inline templates: `AddToTail`, `InsertBefore`, `Remove`, `Find`, `Purge`; RB-tree members are template members
  with a mangled `// TARGET:`. vtmb section: "Source containers".
- **Smaller levers that held often:** the SDK's spelling of a constant, not the folded value; `float`, not `double`,
  for a float local; initialise a local only one path sets; template instantiations with identical code are one
  function under one name. vtmb section: "VC6 walls closed by hand".
- **Reference source.** `get_function(addr, part="reference")` shows Valve's code of the same function (2004 SDK,
  project.toml `[reference]`; the client side lives in `cl_dll/`). Read it for control flow
  and names, then write the game's version under this project's names.

## Engine interfaces (engine, materials, modelinfo, ...): use engineclient.h, never a view of your own

`include/engineclient.h` declares the interfaces client.dll's `CHLClient::Init` asks the engine for, under the names
of the SDK's cl_dll/cdll_client_int.cpp. `#include "engineclient.h"` and call through the name; slot N sits at
+N*4 of the vtable, so `mov ecx, [0x104a57d4]; mov eax, [ecx]; call [eax+0x9c]` is `engine->Time(...)` (slot 39).

| name | global | asked for as |
|---|---|---|
| `engine` | g_104a57d4 | VEngineClient006 |
| `modelrender` | g_104a57d8 | VEngineModel006 |
| `effects` | g_104a57dc | VEngineEffects001 |
| `cvar` | g_104a57e0 | VEngineCvar001 |
| `render` | g_104a57e4 | VEngineRenderView008 |
| `debugoverlay` | g_104a57e8 | VDebugOverlay002 |
| `materials` | g_104a57ec | VMaterialSystem074 |
| `g_pMaterialSystemHardwareConfig` | g_104a57f0 | MaterialSystemHardwareConfig010 |
| `engineCache` | g_104a57f4 | VEngineCache001 |
| `modelinfo` | g_104a57f8 | VModelInfoClient001 |
| `enginevgui` | g_104a57fc | VEngineVGui001 |
| `netgraph` | g_104a5800 | VNETGRAPH001 |
| `networkstringtable` | g_104a5804 | VEngineClientStringTable001 |
| `partition` | g_104a5808 | SpatialPartition001 |
| `filesystem` | g_104a580c | VFileSystem005 |
| `shadowmgr` | g_104a5810 | VEngineShadowMgr001 |
| `staticpropmgr` | g_104a5814 | StaticPropMgrClient001 |
| `enginesound` | g_104a5818 | IEngineSoundClient003 |
| `enginetrace` | g_104a582c | EngineTraceClient003 |
| `enginerandom` | g_104a5738 | VEngineRandom001 (the SDK's `random`; the word is a local's name in matched code) |
| `g_pMatSystemSurface` | g_104a5820 | MatSystemSurface001 |
| `physics`, `physcollision`, `physprops` | g_104e0c84, g_104e0c8c, g_104e0c94 | VPhysics030, VPhysicsCollision007, VPhysicsSurfaceProps001 |

- **Troika changed the interfaces.** The version strings are the SDK's, but the slots are not: VEngineClient006's
  GetWindowCenterX/Y are slots 46/47 in the game, 18/19 in the SDK. Never number a slot from the SDK's header; the
  header's slots come from what the matched functions call.
- **A typed slot is proven by matched code**: its signature is the one most matched views used (a view whose function
  calls the slot counting more). Slot 39 `double Time(int)` was measured: `float` broke 8 matched callers. A slot
  still `virtual void vfuncN();` has no evidence yet: give it its type with edit_context when your function calls it
  (the edit is judged against every function that includes the header).
- **Pointers the header does not know** are `const void *` parameters and `void *` returns: cast at the call
  (`(const model_t *)engine->vfunc36(name)`), do not add a view. A class include/ defines keeps its own type
  (`ConVar *cvar->FindVar(name)`).
- **The names are macros** (`#define engine EngineGlobals::g_104a57d4`): a source that includes the header cannot use
  them as its own identifiers (a parameter named `filesystem`, a local `render`).

## client.dll idioms (from the agents' matches and give-ups, 2026-11-26)

- **A header slot written `virtual void vfuncN();` is a placeholder, not a fact.** Most give-ups with a working body
  failed only because the function calls or overrides a slot the header still declares `void()` (ITempEnts.h,
  C_BaseEntity, vgui2 panels). Give the slot its real signature with edit_context in the same submit as the
  function: the edit is judged against every function that includes the header, and a header patch passed only in a
  note is lost.
- **vgui2 classes** live in `include/vgui2__<Class>.h` (namespace `vgui2`); a source that names `vgui2::X` includes
  that header. Panels are allocated with `vgui2::Panel::operator new` (`new X(parent, name)`, never a raw
  allocation call) and built on `Panel(Panel *parent, const char *name)`; the game's panel constructors store their
  own vtable after the base constructor: write a real constructor.
- **HUD elements** derive from CManagedHudElement (`CManagedHudElement.h`): the constructors pass the element's
  name string and store two vtables (the class and its IManagedHudElement part).
- **VtMB scope traces.** A push of a function-name string and a counter increment at the top is `ScopeTrace st("Class::
  Method", name)` (`ScopeTrace.h`, 2- and 3-argument forms); the counter decrement at every exit is its destructor.
- **Particles** hold their emitters in `CSmartPtr<T>` (`CSmartPtr.h`; AddRef/Release are sub_10117fd0/sub_10117fe0):
  a null check before AddRef and a Release on every exit is the smart pointer, not hand code.
- **Engine interfaces**: see "Engine interfaces" (engineclient.h); never a view of your own.
- **The local player** (0x104a0d50, read directly by 267 functions) is the 2004 SDK's `g_pLocalPlayer`:
  `#include "C_BasePlayer.h"` and write `C_BasePlayer::GetLocalPlayer()` (inline, the same load); never declare
  `g_104a0d50` yourself. Cast for a member the header does not declare yet, or give C_BasePlayer.h the member.
- **gpGlobals** (0x102b8494) is the SDK's `CGlobalVarsBase *gpGlobals`: `#include "CGlobalVarsBase.h"` and read
  `gpGlobals->curtime` (+0xc), `->frametime` (+0x10), `->framecount`, `->maxClients`, ...; never a view of your own.
- **The entity list** is the SDK's `g_pEntityList` (0x102b8e98, `CBaseEntityList *`, CBaseEntityList.h) and
  `cl_entitylist` (0x102b8e9c, `CClientEntityList *`, CClientEntityList.h, with `ClientEntityList()`); both point at
  one object. A handle lookup is `CBaseHandle::Get()` (ehandle.h). Never declare `g_102b8e98` / `g_102b8e9c`: a
  second name for the same global keeps VC6 from merging the loads, and the function stops matching.
- **The HUD** (0x104cfe38) is the SDK's `CHud gHUD;` object (CHud.h): `gHUD.FindElement("CHudX")` (0x100f0ed0),
  `gHUD.GetIcon("name")` (0x100f11d0); never declare `g_104cfe38` yourself.
- **The string tables** (0x105f93c0) are one `StatOwner2` object, the list of VStringTable records (StatOwner2.h,
  no real name known): `g_105f93c0.sub_1015f2f0("MiscStrs")->sub_1015ecd0(i)` by name, `.sub_1015f270(id)` by id;
  include StatOwner2.h instead of declaring it with a view type of your own.
- **The input object** (0x1027ba58) is the SDK's `input` (`static CHLInput g_Input; IInput *input = &g_Input;`),
  declared `extern CInput *input;` in CInput.h because the slots are declared on CInput: call `input->vfuncN()`,
  never `g_1027ba58` through a view. Some CInput slot signatures are still guesses (vfunc3 is the SDK's CreateMove,
  declared with the six dwords its matched caller passes); when yours disagrees with the game's call, note it rather
  than adding a second view. A wrapper that only calls a `void` slot returns `void` (the lift's `int` was a guess).
- **CHLClient** (vtable 0x10233f44) follows the SDK's IBaseClientDLL order: slots 13-21 carry the SDK names and
  types (IN_ActivateMouse .. IN_KeyEvent, CreateMove, WriteUsercmdDeltaToBuffer), each forwarding to the input slot of
  the same SDK name. VC6 compiles such a forward to a sibling `jmp [eax+N]`, and a forwarded `bool` shows as
  `mov edx,[esp+N]; mov [esp+N],edx`: read that as a bool parameter, not an int.
- **Two functions in one row.** When the game's bytes end with `ret` / padding and go on with a second function
  (another `ret N`, its own callers), the import merged two rows; note "merged row: second function at 0x..." and
  move on (`pcdecomp split` cuts it), do not write both into one source.
- **strcmp inline** (`repe cmpsb` with a length in ecx): `#pragma intrinsic(strcmp)` with the CRT declaration.
