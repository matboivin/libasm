# CPU

<p align="center">
  <img src="assets/ABasicComputer.gif" alt="CPU diagram" />
</p>

> Block diagram of a basic uniprocessor-CPU computer. Black lines indicate data flow, whereas red lines indicate control flow; arrows indicate flow directions.  [(Source)](https://en.wikipedia.org/wiki/Central_processing_unit#Structure_and_implementation)

A computer (ie CPU) essentially implements this process:

1. reads the [instruction pointer](http://www.simplecpu.com/InstructionPointer.html):  
   The instruction pointer register is a control register that holds the location of the next instruction in a pipeline, and increments itself after every instruction.
2. fetches the next instruction from a [storage device](https://datacadamia.com/computer/storage):  
   A machine instruction is a unique bit string that a device can identify and execute.
3. decode the instruction: A [decoder](https://datacadamia.com/computer/cpu/decode) retrieves the current instruction and selects the device to execute it.
4. execute it,
5. increments the instruction pointer
6. and then goes back to step one.

Source: [CPU - Pipeline (Cycle)](https://datacadamia.com/computer/cpu/pipeline)

## Storage

A storage device (or data-storage component or media) can be anything that can store and retrieve `0` and `1`. It stores byte:
- machine instructions byte,
- data byte.

They basically serve I/O request.

A data storage component is a computer components where data are recording (storing) such as:

- cpu registers and cache,
- ram,
- floppy disks,
- hard disks,
- CD-ROMs (optical discs).

Source: [Computer - Storage Device (Media)](https://datacadamia.com/computer/storage)

# Memory Layout

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

Source: [Memory Layout of C program](https://aticleworld.com/memory-layout-of-c-program/)

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

> The code segment in memory is typically read-only and has a fixed size, so on embedded systems it can usually be placed in read-only memory (ROM), without the need for loading. If the code segment is not read-only, then the particular architecture allows self-modifying code. Fixed-position or position independent code may be shared in memory by several processes in segmented or paged memory systems. As a memory region, the code segment may be placed below the heap or stack in order to prevent heap and stack overflows from overwriting it.  [(Source)](https://en.wikipedia.org/wiki/Code_segment)

# Stack frame

> A stack frame is a frame of data that gets pushed onto the stack. In the case of a call stack, a stack frame would represent a function call and its argument data.  
If I remember correctly, the function return address is pushed onto the stack first, then the arguments and space for local variables. Together, they make the "frame," although this is likely architecture-dependent. The processor knows how many bytes are in each frame and moves the stack pointer accordingly as frames are pushed and popped off the stack.

[Explain the concept of a stack frame in a nutshell](https://stackoverflow.com/questions/10057443/explain-the-concept-of-a-stack-frame-in-a-nutshell)
