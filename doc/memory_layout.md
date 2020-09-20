# Memory Layout

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
