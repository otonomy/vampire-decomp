# Vampire: The Masquerade – Bloodlines: `vampire.dll` decompilation

A matching decompilation of `vampire.dll`, the game-code DLL of *Vampire: The Masquerade – Bloodlines*
(Troika Games, 2004), patch 1.2. Each function in `src/` is C++ that Microsoft Visual C++ 6.0 (`/O2 /GR`, the
compiler and flags the game was built with) compiles to the same bytes as the original DLL.

The functions were first matched with **pcdecomp**, the owner's matching-decompilation tool for 32-bit Windows
games, by AI agents working through it, by hand, and by pcdecomp's automatic passes. The repository now carries its
own gate and rule checker in `tools/`, so anyone with the game and VC6 can check every function; see
[AGENTS.md](AGENTS.md).

## Status

Progress is counted two ways, and the first number is the headline:
- **Matched under the rules:** the bytes match *and* the source passes every [match] code rule: no layout views,
  offset casts, padding, `volatile` carriers, dead steering code, fake vtables or assembly bodies
  ([AGENTS.md](AGENTS.md), "Code rules"). This is source a reader can trust.
- **Bytes matched:** VC6 compiles the source to the original's bytes, and every reference (call, import, global,
  string, constant) names the same target as the original. Masking relocations is not enough.

Both come from the repository's own tools (`tools/`, C): `vd gate` compiles each unit with VC6 and compares every
annotated function with the retail DLL; `vd rules` checks the source against the code rules. The per-function
baseline is [`status/functions.csv`](status/functions.csv).

### `vampire.dll`

| | Functions | Code bytes |
|---|---:|---:|
| Annotated functions in `src/` | 18,977 | 2,946,356 |
| **Matched under the rules** | **10,878 (57.3%)** | **857,519 (29.1%)** |
| Bytes matched (the three rows below it: matched under the rules, `MATCH-PENDING`, `VERBATIM`) | 18,947 (99.8%) | 2,915,706 (99.0%) |
| Bytes matched, source still fake (`MATCH-PENDING`): open work | 7,945 | |
| Bytes matched with an inline-assembly body (`VERBATIM`, counted apart) | 124 | |
| Not matched: the bytes match only with relocations masked, a reference is wrong (`REF`) | 30 | |

Of the bytes-matched functions, 5,850 match as part of their unit compiled whole; the others match only when
compiled on their own, because 168 of the 1,171 units do not compile as one file (their function blocks declare
the same types and globals in conflicting ways). Making each unit one real translation unit is open work.

The earlier count of 23,934 functions came from pcdecomp's own database, which also counted copies of matched twin
functions; the repository's source holds 18,977 annotated functions.

The data is in the sources as well: initialized and constant data in `src/_data/`, zero-initialized globals in
`src/_bss/`, static initializers in `src/_init/`.

**Linking:**
- *Hybrid build*: the original DLL with the compiled functions linked in. It loads and plays in the game.
- *Standalone build*: all objects linked into a new DLL without the original file. `link.exe` finishes with 0
  unresolved names, 0 duplicates and 0 errors (14,634 alias names map the original symbol names).
  Still open before it can replace the original:
  - 50 vtable slots in 49 vtables are not yet the game's;
  - the exports and the entry point;
  - an in-game test of the standalone DLL.

### The rest of the game

| Part | State |
|---|---|
| `client.dll` (client game code) | In progress in [`client/`](client/): 7,550 of 16,003 functions (47.2%), 339,582 of 1,690,523 code bytes (20.1%) as of 2026-11-21 |
| `GameUI.dll`, `vampire_python21.dll` | Not started |
| Engine and its modules (`engine.dll`, `launcher.dll`, `materialsystem.dll`, `studiorender.dll`, `shaderapidx9.dll`, `stdshader_*.dll`, `vgui2.dll`, `vguimatsurface.dll`, `vphysics.dll`, `vstdlib.dll`, `tier0.dll`, `filesystem_stdio.dll`, `vaudio_miles.dll`, `voice_miles.dll`), `Vampire.exe` | Not started |
| Third-party libraries (Miles, Bink, zlib, Microsoft runtime) | Out of scope |

## What is in this repository

| Path | Contents |
|---|---|
| `src/` | The matched functions, grouped by the game's source files where the DLL names them (`src/dlls/...`), otherwise by class (`src/_unsorted/`); plus data, globals and static initializers |
| `include/` | The shared headers: the game's classes, recovered from its RTTI, vtables and code |
| `symbols.txt` | Every address with its symbol name |
| `project.toml` | The pcdecomp project settings (compiler flags, prelude, agent settings) |
| `tools/` | `vd`, the project's tools in C: the byte gate, the code-rule checker, the RTTI hierarchy check, the renamer |
| `status/` | The per-function baseline (`functions.csv`) and the rule-exception list |
| `docs/` | Research notes: VC6 code generation (`vc6-codegen-notes.md`), register allocation, the standalone-link work; `names/`: names applied from debug information, with their evidence |
| `AGENTS.md` | The project guide: tools, the byte gate, the code-rules profile, workflow (`CLAUDE.md` points to it) |
| `phase0/` | The first experiments that tested whether matching was possible |
| `client/` | `client.dll`, in progress: a pcdecomp project of its own with the same layout (`src/`, `include/`, `symbols.txt`, `project.toml`, `CLAUDE.md`) |
| `LICENSE` | CC0 1.0 Universal (see [License](#license-cc0-10)) |

**No game files are included.** To build or check anything you need your own legally obtained copy of the game:
`vampire.dll` from patch 1.2 (SHA-1 `3fe64bc0d9d7eca64976adc668617ca2814e5e4a`); for `client/`, `client.dll` from
the same patch (SHA-1 `39a2d2556f08090542f2d186320b9012a83ffb6b`). You also need Visual C++ 6.0
with the Processor Pack (the game was built with VC6 build 9044: `C2.DLL` 13.00.9044). Point the tools at both with
`VD_DLL` and `VD_CL` (or set `binary` and `cl` in `project.toml`), build them with `make -C tools`, and run
`build/vd.exe gate`. pcdecomp's database (`project.db`) and its cache are not part of the repository.

## Legal

This is an unofficial fan project for study and preservation. It is not affiliated with or endorsed by the owners of
the game. *Vampire: The Masquerade – Bloodlines* was developed by Troika Games and published by Activision.
*Vampire: The Masquerade* and *World of Darkness* are trademarks of Paradox Interactive. The game runs on Valve's
Source engine. No game assets or binaries are distributed here.

### License: CC0 1.0

The contributors dedicate their own work in this repository to the public domain under CC0 1.0 Universal (full
text in `LICENSE`). You may use, change and share that work for any purpose, without asking and without giving credit.
By opening a pull request you dedicate your contribution under the same terms.

The dedication is limited to the contributors' own work. It gives no rights in the game, its code, its data or its
assets, in the Source engine, or in any trademark; those remain with their owners. Building or checking anything here
needs your own legally obtained copy of the game. If a rights holder asks for material to be removed, open an issue and
it will be taken down.
