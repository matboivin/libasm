# NASM

## Layout of a NASM Source Line

Traditionally, assembly code was written in a four column layout. The columns were:

1. Labels
2. [Mnemonic](https://datacadamia.com/lang/assembly/mnemonic) / Instructions
3. Operands
4. Comments

<p align="center">
  <img src="assets/nasmstructure.png" alt="NASM Structure" />
</p>

> NASM is line-based. Most programs consist of directives followed by one or more sections. Lines can have an optional label. Most lines have an instruction followed by zero or more operands.  [(Source)](https://cs.lmu.edu/~ray/notes/nasmtutorial/)

> Traditional assemblers dating back to punched cards recognised the meaning of each word by what column it appeared on. Modern assemblers use more sophisticated parsers, allowing for assembler programs to have a free form layout. Nevertheless, it is a good idea to stick with the traditional layout for readability.  
As you can see, the second column says “mnemonic.” This indicates both assembler directives and instructions.  [(Source)](https://stackoverflow.com/questions/55212617/indenting-for-nasm-directives-and-macros)

```
;                     dst, src
label:    instruction operands        ; comment
```

Source : [NASM - The Netwide Assembler](https://www.nasm.us/doc/nasmdoc3.html#section-3.1)

Example formatter: [nasmfmt](https://github.com/yamnikov-oleg/nasmfmt)

## MacOs

- The object file format is `macho64`, not `elf64`.
- The system call numbers are totally different.
- Symbols shared between modules will be prefixed by underscores.

Source: [NASM Tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)

> By different I do not mean that numbering of syscalls do not match, since I would be surprised if it did. Rather that there are some nuances that made my work more troublesome. [On syscall table available on Apple’s website](https://opensource.apple.com/source/xnu/xnu-2782.20.48/bsd/kern/syscalls.master) you can see that write has code 4 (instead of 1) and exit has number 1 (instead of 60). The arguments are the same due to POSIX standard and go to same registers (because this depends on the architecture of the processor). But in order to get a syscall right you have to add class identifier to the syscall number. For BSD syscalls this is 0x200000 to the syscall.  [(Source)](https://blacksheephacks.pl/simple-assembly-program-on-macos/)

## Leading underscore or not? (Linux)

- [Format of a C decorated name](https://docs.microsoft.com/en-us/cpp/build/reference/decorated-names?view=vs-2019#FormatC): Note that in a 64-bit environment, functions are not decorated (Windows)
- [Writing 32-bit Code (Unix, Win32, DJGPP)](https://www.csee.umbc.edu/~chang/cs313.f04/nasmdoc/html/nasmdoc8.html)
- [The leading underscore not recommended nowadays for labels?](https://stackoverflow.com/questions/41529300/the-leading-underscore-not-recommended-nowadays-for-labels): "No underscores if you're writing for Linux or BSD. Except for the entry point label, which is expected to be `_start`."

In short: not so important. In C, used to indicate if more or less low level (e.g. hook).

To prefix all global and extern variables: `--prefix _`
> The --prefix and --postfix options prepend or append (respectively) the given argument to all global or extern variables. E.g. --prefix _ will prepend the underscore to all global and external variables, as C requires it in some, but not all, system calling conventions.  [(Source)](https://www.nasm.us/xdoc/2.14rc0/html/nasmdoc2.html#section-2.1.27)

## Syntax

### Order of parameters

Intel:
```
OPERATION DESTINATION, SOURCE
```

AT&T:
```
OPERATION SOURCE, DESTINATION
```
