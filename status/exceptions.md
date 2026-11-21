# Rule exceptions and pending matches

`functions.csv` beside this file is the per-function baseline: the byte gate's result (`bytes`), the rule checker's
verdict (`rules`, `status`) and the first [match] finding for each annotated function. Regenerate it with
`vd gate` and `vd rules --r2 advisory --out status/functions.csv`; never edit it by hand.

Statuses:
- `MATCHED`: bytes match and every [match] rule passes.
- `MATCH-PENDING`: bytes match, a [match] rule fails. The source is the best-known state; the function is open work.
- `VERBATIM`: the body is inline assembly (R18), counted apart.
- `UNMATCHED`: the gate does not accept the bytes (including `REF`: a wrong referent hidden by relocation masking).
- `PARKED`: unfinished work under `#ifdef NON_MATCHING`.

## RULE-EXCEPTION list

Each `// RULE-EXCEPTION: <rule>, <reason>` in the source is listed here with its function and the reason the bytes
give.

| function | rule | reason |
|---|---|---|
| (none yet) | | |
