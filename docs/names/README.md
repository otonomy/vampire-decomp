# Names from debug information

Each file here records names applied from outside evidence, and why.

## `hldms-pdb.tsv`, `hldms-pdb-matches.csv`

Source: the Half-Life 2: Deathmatch debug build of 2006-06-02 (`server.dll` + `server.pdb`, `client.dll` +
`client.pdb`), matched against `vampire.dll` by a symbol-coverage search: a prototype function counts as a match when
its code, normalised for relocations, is identical to a function in `vampire.dll`. The Half-Life 2 for macOS builds
(2024) and the Linux Half-Life build (GoldSrc, 2023) gave no code matches: they come from another compiler and, for
GoldSrc, another engine.

`vd names` turned the 306 Source matches into renames only where all of these hold:
- the match is unique: no other prototype function with the same code has another name;
- the function is at least 48 bytes; shorter bodies (forwarders, accessors) share their shape with unrelated
  functions. One such match named the `UTIL_SetSize` wrapper (it forwards to the function that prints "backwards
  mins/maxs") `ParseFile`;
- the repository names it `sub_<address>`, so the rename is exact;
- the class agrees, or the repository's class is itself a placeholder;
- no other match gives the name to another address.

Five names passed, and each body agrees with its name: `ConsoleKillTarget` (prints `"killing %s\n"`),
`Motion_SetKeyAngles`, `CMathCounter::InputSetValue`, `SendPropTime`, `SetLocalBase`. `hldms-pdb-matches.csv` lists
every row with its verdict. The rejected rows are leads, not names: virtual-slot anchors (a slot name spans a class
hierarchy and needs a hierarchy-aware rename), class conflicts (some are Source namespaces such as `NAI_Hull`, others
mean one of the two class names is wrong), and short matches.

Applied with `vd rename docs/names/hldms-pdb.tsv`.
