# Process

## NASM

### Layout of a NASM Source Line

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
label:    instruction operands        ; comment
```

Source : [NASM - The Netwide Assembler](https://www.nasm.us/doc/nasmdoc3.html#section-3.1)

Example formatter: [nasmfmt](https://github.com/yamnikov-oleg/nasmfmt)

### Leading underscore or not?

- [Format of a C decorated name](https://docs.microsoft.com/en-us/cpp/build/reference/decorated-names?view=vs-2019#FormatC): Note that in a 64-bit environment, functions are not decorated (Windows)
- [Writing 32-bit Code (Unix, Win32, DJGPP)](https://www.csee.umbc.edu/~chang/cs313.f04/nasmdoc/html/nasmdoc8.html)
- [The leading underscore not recommended nowadays for labels?](https://stackoverflow.com/questions/41529300/the-leading-underscore-not-recommended-nowadays-for-labels): "No underscores if you're writing for Linux or BSD. Except for the entry point label, which is expected to be `_start`."

In short: not so important. In C, used to indicate if more or less low level (e.g. hook).

To prefix all global and extern variables: `--prefix _`
> The --prefix and --postfix options prepend or append (respectively) the given argument to all global or extern variables. E.g. --prefix _ will prepend the underscore to all global and external variables, as C requires it in some, but not all, system calling conventions.  [(Source)](https://www.nasm.us/xdoc/2.14rc0/html/nasmdoc2.html#section-2.1.27)

## Memory Layout

Source: [Memory Layout of C program](https://aticleworld.com/memory-layout-of-c-program/)

```
High Addresses ---> .----------------------.
                    |      Environment     |
                    |----------------------|
                    |                      |   Functions and variable are declared
                    |         STACK        |   on the stack.
base pointer ->     | - - - - - - - - - - -|
                    |           |          |
                    |           v          |
                    :                      :
                    .                      .   The stack grows down into unused space
                    .         Empty        .   while the heap grows up. 
                    .                      .
                    .                      .   (other memory maps do occur here, such 
                    .                      .    as dynamic libraries, and different memory
                    :                      :    allocate)
                    |           ^          |
                    |           |          |
 brk point ->       | - - - - - - - - - - -|   Dynamic memory is declared on the heap
                    |          HEAP        |
                    |                      |
                    |----------------------|
                    |          BSS         |   Uninitialized data (BSS)
                    |----------------------|   
                    |          Data        |   Initialized data (DS)
                    |----------------------|
                    |          Text        |   Binary code
Low Addresses ----> '----------------------'
```

Stack:

- Stores local variables
- When a function is called, a stack frame is created
- When a function returns, a stack frame is destroyed
- One function = one stack frame
- Stack frames contain functions's local variables, arguments and return values

Heap:

- Dynamically allocated memory (malloc, calloc, realloc)
- Used to allocate memory at run time
- Shared by all shared libraries and dynamically loaded modules in a process

BSS (Block Started by Symbol) / Uninitialized data segment:

- All uninitialized global and static variables, or initialized to zero

Data (Initialized data segment):

- Global and static variable initialized with non-zero values 

Text / Code segment:

- Executable instructions of C programs
- Machine language representation of steps of the program
- Sharable and read-ony