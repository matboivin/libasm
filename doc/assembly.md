# Assembly - NASM

## Registers

Register is a hardware device component that is used for two purposes:

- storage of value (at high speed),
- passing argument and retrieving return value (to communicate between hardware devices).

Source: [Device - Register](https://datacadamia.com/computer/device/register)

Processor registers are located inside the processor. They are the quickest memory and are then located at the top of the memory hierarchy.  
One standard function of a register is to **define the input and output operand of an instruction**.

Source: [Processor - (Execution) Register](https://datacadamia.com/computer/cpu/register/register)

| Size   |       |         |
| ------ | ----- | ------- |
| 64-bit | qword | 8 bytes |
| 32-bit | long  | 4 bytes |
| 16-bit | word  | 2 bytes |
| 8-bit  | byte  | 1 byte  |

<p align="center">
  <img src="assets/x86-register-set.png" alt="x86 register set" />
</p>

Image source: [Program and Data Representation: Textbook](https://uva-cs.github.io/pdr/book/)

<p align="center">
  <img src="assets/register-ids.png" alt="identifiers to access registers" />
</p>

The **8 General-Purpose Registers** are (16-bit naming conventions):

1. Accumulator register (AX). Used in arithmetic operations
2. Counter register (CX). Used in shift/rotate instructions and loops.
3. Data register (DX). Used in arithmetic operations and I/O operations.
4. Base register (BX). Used as a pointer to data (located in segment register DS, when in segmented mode).
5. Stack Pointer register (SP). Pointer to the top of the stack.
6. Stack Base Pointer register (BP). Used to point to the base of the stack.
7. Source Index register (SI). Used as a pointer to a source in stream operations.
8. Destination Index register (DI). Used as a pointer to a destination in stream operations.

The order in which they are listed here is for a reason: it is the same order that is used in a push-to-stack operation.

Source: [X86 Assembly/X86 Architecture](https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture)

[What does the 'R' in x64 register names stand for?](https://softwareengineering.stackexchange.com/questions/127668/what-does-the-r-in-x64-register-names-stand-for)

64-bit naming conventions:

|     | Name                        | Purpose                                                                       | Use                                       |
| --- | :-------------------------- | :---------------------------------------------------------------------------- | :---------------------------------------- |
| RAX | Accumulator register        | Accumulator for operands and results data                                     | Arithmetic operations                     |
| RCX | Counter register            | Counter for string and loop operations                                        | Shift/rotate instructions and loops       |
| RDX | Data register               | I/O pointer                                                                   | Arithmetic and I/O operations             |
| RBX | Base register               | Pointer to data in the DS segment. Preserved register: don't use it without saving it! | Pointer to data                           |
| RSP | Stack Pointer register      | Stack pointer in the SS segment                                               | Pointer to the top of the stack           |
| RBP | Stack Base Pointer register | Stack pointer to data in the SS segment                                       | Pointer to the base of the stack          |
| RSI | Source Index register       | Pointer to data in the segment pointed to by the DS register                  | Source pointer for string operations      |
| RDI | Destination Index register  | Pointer to data (or destination) in the segment pointed to by the ES register | Destination pointer for string operations |

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

## Syntax

### Leading underscore or not? (Linux)

- [Format of a C decorated name](https://docs.microsoft.com/en-us/cpp/build/reference/decorated-names?view=vs-2019#FormatC): Note that in a 64-bit environment, functions are not decorated (Windows)
- [Writing 32-bit Code (Unix, Win32, DJGPP)](https://www.csee.umbc.edu/~chang/cs313.f04/nasmdoc/html/nasmdoc8.html)
- [The leading underscore not recommended nowadays for labels?](https://stackoverflow.com/questions/41529300/the-leading-underscore-not-recommended-nowadays-for-labels): "No underscores if you're writing for Linux or BSD. Except for the entry point label, which is expected to be `_start`."

In short: not so important. In C, used to indicate if more or less low level (e.g. hook).

To prefix all global and extern variables: `--prefix _`
> The --prefix and --postfix options prepend or append (respectively) the given argument to all global or extern variables. E.g. --prefix _ will prepend the underscore to all global and external variables, as C requires it in some, but not all, system calling conventions.  [(Source)](https://www.nasm.us/xdoc/2.14rc0/html/nasmdoc2.html#section-2.1.27)

### Order of parameters

Intel:
```
OPERATION DESTINATION, SOURCE
```

AT&T:
```
OPERATION SOURCE, DESTINATION
```

## Exporting Symbols to Other Modules

`global` makes the symbol visible to ld.

`global` refers to symbols which are defined in the same module as the `global` directive.

```
        global _main 
_main: 
        ; some code
```

The entrypoint of the program depends on the linker used to transform the compiled code into executable file. A global symbol is exported so other files can used it. If a function (or variable) is both identified by a label and declared as global in the file where it's defined, this function can be called in another file if its label is declared as `extern` in the latter.

## Operand size specifiers

| Size   |       |         |
| ------ | ----- | ------- |
| 64-bit | qword | 8 bytes |
| 32-bit | long  | 4 bytes |
| 16-bit | word  | 2 bytes |
| 8-bit  | byte  | 1 byte  |

```
mov BYTE  [dst], 0      ; Move 0 into the single byte at memory location dst
mov WORD  [dst], 0      ; Move the 16-bit integer repr of 0 into the 2 bytes starting at memory location dst
mov DWORD [dst], 0      ; Move the 32-bit integer repr of 0 into the 4 bytes starting at memory location dst
mov QWORD [dst], 0      ; Move the 64-bit integer repr of 0 into the 8 bytes starting at memory location dst
```

## Prologue / Epilogue

> The base pointer is conventionally used to mark the start of a function's stack frame, or the area of the stack managed by that function. Local variables are stored below the base pointer and above the stack pointer. The start of each function has a preamble saves the old base pointer and initializes a new one and the end of each function has epilogue that restores the old base pointer.  [(Source)](https://codearcana.com/posts/2013/05/21/a-brief-introduction-to-x86-calling-conventions.html)

Source: [ENTER and LEAVE in Assembly?](https://stackoverflow.com/questions/5858996/enter-and-leave-in-assembly)

- `enter` creates a stack frame
- `leave` destroys a stack frame

Better not used these 2 instructions.

Use instead:

```
; enter / prologue
push    rbp             ; push base pointer to the stack to save it
mov     rbp, rsp        ; base pointer <- stack pointer

; leave /epilogue
mov     rsp, rbp        ; stack pointer <- base pointer
pop     rbp             ; restore the top of the stack into base pointer
```

## MacOs differences

- The object file format is `macho64`, not `elf64`.
- The system call numbers are totally different.
- Symbols shared between modules will be prefixed by underscores.

Source: [NASM Tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)

> By different I do not mean that numbering of syscalls do not match, since I would be surprised if it did. Rather that there are some nuances that made my work more troublesome. [On syscall table available on Apple’s website](https://opensource.apple.com/source/xnu/xnu-2782.20.48/bsd/kern/syscalls.master) you can see that write has code 4 (instead of 1) and exit has number 1 (instead of 60). The arguments are the same due to POSIX standard and go to same registers (because this depends on the architecture of the processor). But in order to get a syscall right you have to add class identifier to the syscall number. For BSD syscalls this is 0x200000 to the syscall.  [(Source)](https://blacksheephacks.pl/simple-assembly-program-on-macos/)
