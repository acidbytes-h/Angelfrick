# Angelfrick
| | |
|---|---|
| **name** | Angelfrick |
| **paradigms** | imperative |
| **author** | [Acidbytes.h](https://esolangs.org/wiki/User:Acidbytes.h) |
| **year** | 2026 |
| **typesys** | untyped |
| **memsys** | cell-based |
| **dimensions** | one-dimensional |
| **class** | Turing complete |
| **refimpl** | `angelfrick.cpp` (C++) |
| **influence** | [brainfuck](https://esolangs.org/wiki/Brainfuck) |
| **files** | `.angelfrick` |

**Angelfrick** is a [Trivial brainfuck substitution](https://esolangs.org/wiki/Trivial_brainfuck_substitution) created in 2026 by [acidbytes.h](https://esolangs.org/wiki/User:Acidbytes.h) in which each of the eight [brainfuck](https://esolangs.org/wiki/Brainfuck) commands is replaced by a long English word — mostly the standard trophy words of English lexicography, such as *pneumonoultramicroscopicsilicovolcanoconiosis* and *floccinaucinihilipilification* — subjected to three further layers of deliberate obstruction:

1. The letters of each word are **arbitrarily cased**, in a pattern with no rule behind it, which must be reproduced exactly.
2. Each word carries a case-scrambled copy of the nonsense string *cfguhyttrdes* and a **unique punctuation sigil**: `$ ! * % & @ {` and `£`.
3. Every keyword then ends with the literal text `><+-.,[]` — the entire brainfuck instruction set, appended to every instruction, meaning nothing.

The result is a language whose shortest command is 46 bytes and whose longest is 66, averaging just under 54. A program is roughly 56 times the size of the brainfuck it was translated from, which puts it among the bulkiest trivial brainfuck substitutions, alongside [Broccosprout](https://esolangs.org/wiki/Broccosprout). It is always spelled **Angelfrick**, never *AngelFrick*. A deliberately legible sibling, [Angelfrick--](angelfrick--.md), keeps the words in plain upper case and drops the sigils.

## Commands

| Brainfuck | Angelfrick | Bytes | Meaning |
|---|---|---|---|
| `>` | `ThyROparAtHyROIDectomIzEdCfGUhYTTrDeS$><+-.,[]` | 46 | Move the pointer right |
| `<` | `SUPErcaliFrAgilIStiCeXpiaLIDOcIOUsCFguhYtTRdeS!><+-.,[]` | 55 | Move the pointer left |
| `+` | `HIppoPOToMONStrOSeSQuIPPEdaLioPhOBiacFguHyTtrdes*><+-.,[]` | 57 | Increment the current cell |
| `-` | `PNEumoNoultRAMicroSCOPIcsiLiCoVolCanocONIOSISCFgUhyTtrDeS%><+-.,[]` | 66 | Decrement the current cell |
| `.` | `aNTiDiSesTaBLIsHmenTarIaniSmcFGUHYtTRDes&><+-.,[]` | 49 | Output the current cell as a character |
| `,` | `giBBERIsHghEjVIYOCNjnIRjVjjKwbXvqgvCFguHytTRdeS@><+-.,[]` | 56 | Read one character into the current cell |
| `[` | `pseUDopseUDOHYpopaRatHYROIDisMcfGUhYTTrDes{><+-.,[]` | 51 | Jump past the matching close if the current cell is zero |
| `]` | `fLoccInAUCiniHiLIpILIfiCaTionCFGUHyTtRDes£><+-.,[]` | 51 | Jump back to the matching open if the current cell is nonzero |

Six of the eight keywords are built on real English words. `giBBERIsHghEjVIYOCNjnIRjVjjKwbXvqgv` is not; the author ran out of long words before running out of commands, and the input instruction is therefore keyboard mash. That the language uses *hippopotomonstrosesquippedaliophobia* — the fear of long words — as its increment instruction is intentional.

## Syntax

### Matching rules

- Keywords are matched by **case-sensitive** prefix comparison, and any byte that does not begin a keyword is skipped. Whitespace between keywords is therefore optional, and so is its absence: a valid program may be written one keyword per line, or as a single unbroken six-kilobyte word.
- Because unrecognised text is discarded, **all non-keyword text is a comment**. Angelfrick source can be embedded in prose with no comment delimiter.
- No keyword occurs as a substring of another at a nonzero offset, so prefix matching is unambiguous.

### Case

The casing is the substance of the language rather than decoration. It is not alternating, not word-initial, and not derived from anything; it is simply a fixed arbitrary pattern per keyword that a programmer must reproduce byte for byte. Two consequences follow:

- The keywords are **no longer legible as the English words they are built from**. `PNEumoNoultRAMicroSCOPIcsiLiCoVolCanocONIOSIS` must be transcribed rather than read, which removes the one affordance a long-word substitution normally has.
- The trailing `cfguhyttrdes` is cased **differently in every keyword** — `CfGUhYTTrDeS`, `CFguhYtTRdeS`, `cFguHyTtrdes`, and so on. There is consequently no common suffix that a find-and-replace or a single regular expression can key on, which is the usual way trivial brainfuck substitutions are compiled.

### Encoding

The close-loop keyword ends with `£` (U+00A3), which is not ASCII. The reference implementation compares raw bytes, so **source files must be UTF-8**: under Latin-1 the pound sign is one byte rather than two, the close-loop keyword never matches, and every loop in the program silently fails. A Latin-1 copy of the Hello World program below emits thirteen bytes of noise instead of its greeting rather than reporting an error.

File encoding is therefore part of the language specification. Note the asymmetry — the open-loop keyword uses the ASCII `{`, so `[` is portable and `]` is not.

### File extension

Source files **must** carry the extension `.angelfrick`. The reference implementation refuses anything else, printing `ok, so where is it?` and exiting, which makes the extension part of the language rather than a convention.

### Memory model

The tape is 30000 cells of `char`, initialised to zero, with the pointer starting at cell 0. Cells wrap; the pointer is not bounds-checked.

## Examples

### Hello, world!

Translated from the standard 106-command brainfuck Hello World. The result is 5,983 bytes — an expansion of about 56× — to print twelve characters.

```bf
HIppoPOToMONStrOSeSQuIPPEdaLioPhOBiacFguHyTtrdes*><+-.,[]
HIppoPOToMONStrOSeSQuIPPEdaLioPhOBiacFguHyTtrdes*><+-.,[]
HIppoPOToMONStrOSeSQuIPPEdaLioPhOBiacFguHyTtrdes*><+-.,[]
HIppoPOToMONStrOSeSQuIPPEdaLioPhOBiacFguHyTtrdes*><+-.,[]
HIppoPOToMONStrOSeSQuIPPEdaLioPhOBiacFguHyTtrdes*><+-.,[]
HIppoPOToMONStrOSeSQuIPPEdaLioPhOBiacFguHyTtrdes*><+-.,[]
...
```

*5,979 bytes in total — see [`../examples/hello.angelfrick`](../examples/hello.angelfrick).*

### Cat

The direct translation of `,[.,]`:

```bf
giBBERIsHghEjVIYOCNjnIRjVjjKwbXvqgvCFguHytTRdeS@><+-.,[]
pseUDopseUDOHYpopaRatHYROIDisMcfGUhYTTrDes{><+-.,[]
aNTiDiSesTaBLIsHmenTarIaniSmcFGUHYtTRDes&><+-.,[]
giBBERIsHghEjVIYOCNjnIRjVjjKwbXvqgvCFguHytTRdeS@><+-.,[]
fLoccInAUCiniHiLIpILIfiCaTionCFGUHyTtRDes£><+-.,[]
```

Under the reference implementation this program does not terminate: `getchar` returns `EOF` (−1) at end of input, which is stored in the cell as a nonzero value, so the loop runs forever emitting `0xFF`. This follows from the implementation's silence on EOF semantics rather than being an intended feature.

### Self-compiler

A brainfuck-to-Angelfrick compiler **written in Angelfrick**: 12,641 brainfuck commands, 764,039 bytes. It reads a brainfuck program on standard input and emits the Angelfrick translation.

```
./angelfrick afc.angelfrick < hello.bf > hello.angelfrick
```

Fed its own brainfuck source it reproduces its own 764,039-byte source exactly. The language therefore bootstraps: no external translator is required to produce Angelfrick programs.

### Snake

A playable 8×8 Snake — growth, pseudo-random food, wall and self-collision, and a running score — at 481,307 brainfuck commands and 25,119,259 bytes. It is turn-based rather than real-time, because brainfuck's input instruction blocks and the language has no clock, so the snake cannot advance on its own while the player watches. This is a limit of the instruction set rather than of the implementation.

## Quines

No quine is known. A brainfuck quine stores its own code section as data, roughly three tape cells per command, which caps the code near 10,000 commands on a 30000-cell tape. An Angelfrick quine must additionally contain eight routines that each emit a keyword of 46 to 66 bytes, and at roughly 1,250 commands per keyword emitter those routines alone exceed the budget. Packing several commands per cell relieves the space at the cost of inflating the data section beyond practicality.

Whether Angelfrick admits a quine on a 30000-cell tape is therefore **open**. The obstruction is specific to the tape size: on an unbounded tape the construction is routine.

## Computational class

Angelfrick is a one-to-one substitution of brainfuck's instruction set with no additional state or commands, so it is Turing complete by the same argument as brainfuck, subject to the usual unbounded-tape idealisation.

## Implementation

The reference implementation is a single-file C++ interpreter, written in the common subset of C and C++ and using no C++-specific facilities beyond the explicit cast on `calloc`. It matches keywords with a `strncmp` prefix macro and, after a match, advances the cursor by one byte rather than by the token length; the remaining bytes of the keyword then fail to match anything and are skipped individually, so each keyword executes exactly once.

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IS(x) (!strncmp(c + i, x, sizeof(x) - 1))
#define OPEN  IS("pseUDopseUDOHYpopaRatHYROIDisMcfGUhYTTrDes{><+-.,[]")
#define CLOSE IS("fLoccInAUCiniHiLIpILIfiCaTionCFGUHyTtRDes£><+-.,[]")
int main(int ac , char** av)
{
  if (ac < 2 || !strstr(av[1], ".angelfrick")) return fprintf(stderr, "ok, so where is it?\n"), 1;
  FILE* f = fopen(av[1], "rb"); if (!f) return perror("Oopsies. You have accidentally typed rm -rf /."), 1;
  fseek(f, 0, SEEK_END); long s = ftell(f); rewind(f);
  char* c = (char*)calloc(s + 1, 1); fread(c, 1, s, f); fclose(f);
  char m[30000] = {0}; int p = 0, i = 0, l;
  while (i < s) {
    if (IS("ThyROparAtHyROIDectomIzEdCfGUhYTTrDeS$><+-.,[]")) p++;
    else if (IS("SUPErcaliFrAgilIStiCeXpiaLIDOcIOUsCFguhYtTRdeS!><+-.,[]")) p--;
    else if (IS("HIppoPOToMONStrOSeSQuIPPEdaLioPhOBiacFguHyTtrdes*><+-.,[]")) m[p]++;
    else if (IS("PNEumoNoultRAMicroSCOPIcsiLiCoVolCanocONIOSISCFgUhyTtrDeS%><+-.,[]")) m[p]--;
    else if (IS("aNTiDiSesTaBLIsHmenTarIaniSmcFGUHYtTRDes&><+-.,[]")) putchar(m[p]);
    else if (IS("giBBERIsHghEjVIYOCNjnIRjVjjKwbXvqgvCFguHytTRdeS@><+-.,[]")) m[p] = getchar();
    else if (OPEN && !m[p]) for (l = 1; l; ) { ++i; l += OPEN - CLOSE; }
    else if (CLOSE && m[p]) for (l = 1; l; ) { --i; l += CLOSE - OPEN; }
i++;
}
free(c);
}
```

Compile with `g++ -O2 -o angelfrick angelfrick.cpp` and run as `./angelfrick program.angelfrick`. It builds without modification under `-std=c++17`, `c++20` and `c++23`, emitting only the `fread` unused-result warning. The source must itself be saved as UTF-8 for the close-loop keyword to be encoded correctly.

### Known issues

- The tape pointer is not bounds-checked; a program that walks off either end of the 30000-cell array invokes undefined behaviour.
- Unmatched brackets cause the scanning loops to run past the ends of the buffer.
- EOF is stored as −1 rather than 0 or leaving the cell unchanged, breaking the usual `,[.,]` cat idiom (see above).
- The extension check uses `strstr` rather than testing the end of the filename, so `hello.angelfrick.txt` is also accepted.
- A mis-encoded close-loop keyword fails silently rather than raising an error.
- The return value of `fread` is ignored.

## Trivia

- Every Angelfrick keyword contains a complete copy of the brainfuck instruction set, and none of those eight characters ever does anything.
- Between them the sigils and the tail use `$ ! * % & @ { [ ] > <`, so no keyword can be typed into an interactive shell unquoted without triggering variable expansion, history expansion, globbing, brace expansion, or backgrounding. The decrement keyword additionally contains `%`, making it a format string.
- No keyword is a valid identifier in any mainstream programming language, which forecloses the traditional escape route of compiling programs with the C preprocessor.
- The 24 MB Snake program compresses to about 134 KB, a ratio near 190:1. Eight repeated keywords is close to the most compressible text a program can be made of.
- Because the reference implementation tests its argument with `strstr` rather than examining the end of the filename, the string `.angelfrick` is found inside `.angelfrick--`, so an [Angelfrick--](angelfrick--.md) program is accepted by the Angelfrick interpreter. None of its keywords match, every byte is skipped as a comment, and it exits successfully having done nothing. The reverse is not true.

## See also

- [Angelfrick--](angelfrick--.md)
- [brainfuck](https://esolangs.org/wiki/Brainfuck)
- [Trivial brainfuck substitution](https://esolangs.org/wiki/Trivial_brainfuck_substitution)
- [Ook!](https://esolangs.org/wiki/Ook!)
- [I use Arch btw](https://esolangs.org/wiki/I_use_Arch_btw)
