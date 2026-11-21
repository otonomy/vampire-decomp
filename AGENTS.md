# vampire-decomp: agent and contributor guide

Reconstruct the source of `vampire.dll` (Vampire: The Masquerade – Bloodlines, patch 1.2) so that Visual C++ 6.0,
with the game's flags, emits object code identical to the retail DLL, function by function. Correct structure
outranks any score: classes, types, ownership, storage, control flow, calling conventions and referents.

The point of the project is source a reader can understand. Matching bytes prove the source is faithful; they don't
make it readable. Every function must pass the reader test of the code rules (below): would a programmer at Troika,
working in Valve's Source codebase, have typed this? Source that matches through tricks (a fakematch) is not a match.

This file takes precedence over every other guide in the repository. `docs/vc6-codegen-notes.md` holds the VC6
code-generation research gathered while the functions were first matched; read its "levers" as clues to the original
source, never as source to keep (see "Code rules").

## Project adapter

Build the tools once, with MinGW-w64 gcc or MSVC:

```
make -C tools                                                    # -> build/vd.exe
gcc -std=c99 -O2 -o build/vd.exe tools/*.c                       # the same, without make
cl /O2 /Fe:build\vd.exe tools\*.c                                # MSVC
```

Point them at your own copies of the game and the compiler (the checked-in `project.toml` holds the owner's paths):

```
set VD_DLL=X:\path\to\vampire.dll          (patch 1.2, SHA-1 3fe64bc0d9d7eca64976adc668617ca2814e5e4a)
set VD_CL=X:\path\to\VC98\BIN\CL.EXE       (VC6 with the Processor Pack: C2.DLL 13.00.9044)
```

| verb | meaning | this project's command |
|---|---|---|
| `build` | compile every unit, compare every annotated function | `build/vd.exe gate` (about 5 minutes with 22 jobs; `--jobs N`) |
| `match <unit>` | compile and compare one unit (the inner loop) | `build/vd.exe gate -v src/path/Unit.cpp` |
| `diff <function>` | compiled against retail assembly | `dumpbin /disasm build/obj/<unit>.obj` against the retail DLL (no `vd diff` yet) |
| `report` | refresh the status files | `build/vd.exe gate`, then `build/vd.exe rules --r2 advisory --out status/functions.csv` |
| `gate` | what stays green before a merge | the byte gate (below), then `rules` compared with `status/functions.csv` |
| `class` | vtable and hierarchy evidence | `build/vd.exe rtti` (RTTI bases against the headers' declared bases) |
| `rules [<unit>]` | the rule checker | `build/vd.exe rules --r2 advisory [src/path/Unit.cpp ...]` |
| `names` / `rename` | evidence names | `build/vd.exe names --matches <symcov matches.csv> --map M.tsv --log M.csv`, then `build/vd.exe rename M.tsv` |
| `permute <function>` | permuter | none |

`gate` writes `build/check.csv`: one row per annotated function with its status, how it was compiled (`unit`: as
part of its whole unit; `alone`: only on its own) and the first difference. `rules` joins it with the rule findings
and writes one row per function with `MATCHED`, `MATCH-PENDING`, `VERBATIM` or `UNMATCHED`.

**Toolchain:** VC6 `CL.EXE` 12.00.8804, `C1XX.DLL` 12.00.8964, `C2.DLL` 13.00.9044 (the Processor Pack back end the
game was built with), flags `/O2 /GR`, prelude `vampire.h`. `LINK.EXE` 6.00.8447 for the standalone link work
(`docs/standalone-link-gap.md`).

**Annotations:**
- `// FUNCTION: 0xADDR size=0xSIZE` opens a function block, `// END FUNCTION` closes it. ADDR is the function body,
  not its incremental-link stub; `symbols.txt` names the stubs.
- `// TARGET: Name` inside a block names the symbol the block compiles to, when `symbols.txt` does not spell it
  (templates, unqualified placeholders). A `TARGET` whose class differs from the binary's is a layout view: an R1
  finding.
- `// PARKED: <reason>` inside a block whose body sits in `#ifdef NON_MATCHING` marks unfinished work. The gate skips
  it and counts it apart. This is the project's parking mechanism, exempt from R37.
- `// RULE-EXCEPTION: <rule>, <reason the bytes give>` at the code; list each one in `status/exceptions.md`.

**Policies:** `build/` is generated and ignored. `status/` holds the committed baseline (`functions.csv`, the gate's
and the rule checker's per-function result) and the exception list. Commit messages name the change (`match:`,
`names:`, `rules:`, `tools:`, `status:`). Tooling is written in C (C99, no dependencies); avoid Python for project
tools. Never commit game files.

**Reference sources, in order of trust:**
1. the retail DLL itself: strings (`"E:\Vampire\main\dlls\..."` `__FILE__` paths name the units; error and debug
   strings name functions), RTTI (class names and real base classes: `vd rtti`), DATADESC and SendTable data
   (field and class names), exports;
2. Valve's Source code of the same era (Source SDK) and the Half-Life 2: Deathmatch 2006 debug build
   (`server.pdb`, `client.pdb`): names for functions whose code matches it (`docs/names/`);
3. later Source builds with symbols (Half-Life 2 for macOS, 2024): names only, never code shape (another compiler).

## The byte gate

A function is matched only when the gate prints it as `OK` or `OK-UNVERIFIED`:
- **`OK`**: every code byte outside relocations is identical, and every relocation names the same target as the
  retail reference (a `symbols.txt` name, the address a placeholder name carries, an import name, or identical
  referenced bytes).
- **`OK-UNVERIFIED`**: the bytes match and no reference is wrong, but some references (guard variables of
  function-local statics, uninitialized data) cannot be resolved either way.
- **`REF`**: the bytes match only because relocations are masked; a reference names a different function, import or
  datum. Not a match.
- **`DIFF`**, **`SIZE`**, **`NOSYM`**, **`NOOBJ`**: code differs, length differs, the function is missing from the
  object, the unit does not compile.

"Banked" and "matched" come only from the gate's printed summary, never from memory or a ledger. Gate from a clean
`build/` before a merge. A function that matches only `alone` (its unit does not compile whole, or neighbouring
blocks change its code) still counts as bytes matched; the gate prints both counts, and making units compile whole is
open structural work (R15).

## Code rules

The full catalogue is the `decomp-code-rules` skill (`references/rules.md`). Two laws:

1. **The bytes win.** A change made for style must not change what the compiler emits. When a rule and the bytes
   disagree, keep the bytes and write `// RULE-EXCEPTION: <rule>, <reason the bytes give>` at the code.
2. **Identical bytes alone are not a match.** A function counts as matched only when its bytes match *and* it passes
   every [match] rule (R1, R2, R4, R13, R17, R18) as `vd rules` checks them. A byte-exact function that fails is
   `MATCH-PENDING`: its source is kept as the best-known state and listed as open work; it is never thrown away. A
   function with an inline-assembly body is `VERBATIM` (R18), counted apart. Naming (R7) is not required for a match.

Progress always reports two numbers: **matched under the rules** (the headline) and **bytes matched**.

### Project profile

| item | this project |
|---|---|
| compiler dialect (R22) | VC6 C++ (pre-standard): a `for` variable stays in scope after the loop; no partial template specialization, limited member templates, no `typename` outside templates; `__int64`, `__fastcall`, `__declspec`; no `nullptr`, `auto`, `enum class`, `<stdint.h>` |
| naming style (R8) | Valve Source SDK (ruling 2026-11-21): classes `CName`, interfaces `IName`; members `m_` with Hungarian prefixes (`m_fl`, `m_i`, `m_n`, `m_b`, `m_h` for handles, `m_p`, `m_vec`, `m_ang`, `m_isz` for `string_t`, `m_sz`); globals `g_`, statics `s_`; methods and free functions in PascalCase, `UTIL_` for shared utilities; console variables named by their console string; enums and macros in upper case. Troika's own classes follow the same conventions (`CNPC_V...`, `CVampire...`). |
| layout style (R23, R32, R33) | Allman braces, tabs, Valve's banner over each function: `//-----------------------------------------------------------------------------` / `// Purpose: ...` / `//-----------------------------------------------------------------------------`. The name-only form (`// Purpose:` left out) is fine for trivial accessors. |
| placeholder patterns (R7) | `sub_XXXXXXXX`, `vfuncN`, `slotN`, `g_XXXXXXXX`, `CUnknownXXXXXXXX`, `CUnkXXXXXXXX`, other address-named types, `a0`/`a1` parameters. Offset-named members (`m_n5bb0`) are the R27 form for unknown members: open naming work, not a violation. |
| evidence for names (R7) | the reference sources above; record each applied name's provenance in `docs/names/` |
| line information (R23) | the retail DLL has no line information, but code stamps `__FILE__`/`__LINE__` values into objects (`m_pszFile`/`m_nLine` debug stamps). Those constants are the original line numbers: keep them exactly; they are evidence of the original file's layout. |
| parking (R37) | `#ifdef NON_MATCHING` around the body, with `// PARKED: <reason>` in the block |
| rule changes | **R2 relaxed** (ruling 2026-11-21): Valve's code writes file-scope `extern` declarations in `.cpp` files, so a file-scope extern in a unit is advisory (R25). Still [match]: an extern inside a function body, and one global declared with two different types anywhere. **Gate tightened:** a byte match with a wrong reference (`REF`) is not a match. |
| pending rulings | whether a class whose declared base differs from its RTTI base (`vd rtti`) makes its methods [match] R13 findings |

### Fakematches this codebase uses (the first places to look)

Each is a clue to the original source, not the source:
- **Layout views** (R1, R17): a local `struct` with `char pad[0x5bb0]` and a few fields, and a `// TARGET:` that
  compiles the function as its method. The original was a method of the real class (`CAI_BaseNPC`), reading real
  members.
- **Offset casts and offset macros** (R4): `*(int *)((char *)this + 0x5cc4)`, `#define X_INT(off) ...`. Declare
  the member in the class's header.
- **`volatile` carriers and `*(T *volatile *)&p` reads** (R17): usually a missing inline accessor, or a member read
  through the wrong type.
- **Dead `if (0)` code spending inline budget** (R17): the original called an inline function or a macro (an
  assert, a debug stamp) that left that trace.
- **Fake hierarchies** (R13): a class declared on `CBaseEntity` with `virtual void vfuncN();` stand-ins for the slots
  its real base supplies. `vd rtti` gives the real bases.
- **Function-pointer-cast calls in static initializers** (`int g = ((int (*)(int))sub_X)(0);`): the original
  constructed a global object.

## Workflow

1. **Pick work** from `status/functions.csv`: `MATCH-PENDING` functions (bytes exact, source fake), `REF`
   functions (wrong referents), units that do not compile whole, then naming.
2. **Classify the gap** (`wall-identifier`), **reconstruct** (`matcher`), **recover helpers** (`helper-recovery`).
3. **Iterate** with `vd gate -v <unit>`; run the full gate when a shared header changes.
4. **Gate and check** before a merge: the full gate from a clean `build/`, then `vd rules`, compared with
   `status/functions.csv`. Only a function you edited whose status got worse blocks a merge.
5. **Update the baseline**: commit the regenerated `status/functions.csv` with the change.

## Repository hygiene

- Tool inputs live in `project.toml` and `docs/names/`, generated output in the ignored `build/`, the baseline in
  `status/`, history in git. Docs describe current usage and contracts; no diaries or score snapshots outside
  `status/`.
- Source comments explain the code: markers, ABI constraints, `RULE-EXCEPTION`s, Valve-style banners, the original's
  quirks (`// BUG:` only with proof that simpler source does not match, otherwise `// guess:`). No history, scores or
  dates.
- Stage only your own work; never commit `build/`.
