# Functions

## strlen

- [repne: REPeat while Not Equal](https://www.aldeid.com/wiki/X86-assembly/Instructions/repne)
- [scasb: SCan A String](https://www.aldeid.com/wiki/X86-assembly/Instructions/scasb)
- [cld: CLear Direction flag](https://www.aldeid.com/wiki/X86-assembly/Instructions/cld)

DF = 0 -> the instructions work by incrementing the pointer to the data after every iteration until ECX = 0

For example, `repne scasb` will scan bytes of a string until the trailing null character is found (end of string).

## memcpy

- [lodsb: Load String Byte](https://www.aldeid.com/wiki/X86-assembly/Instructions/lodsb): Loads a byte (B), word (W), or doubleword (D) from the source operand into the AL, AX, or EAX register, respectively.
- [stos: Store String](https://www.aldeid.com/wiki/X86-assembly/Instructions/stos): copies the value in AL, AX or EAX into the location pointed to by ES:DI or ES:EDI.

## memcmp

- [rep](https://www.aldeid.com/wiki/X86-assembly/Instructions/rep): repeats until rcx != 0
- cmpsb [1]](https://www.aldeid.com/wiki/X86-assembly/Instructions/cmpsb)|[2](http://vitaly_filatov.tripod.com/ng/asm/asm_000.17.html): compares string bytes. After the comparison, SI and DI are incremented (if the direction flag is cleared) or decremented (if the direction flag is set).

## Misc.

- swap values using [push](https://www.aldeid.com/wiki/X86-assembly/Instructions/push) and [pop](https://www.aldeid.com/wiki/X86-assembly/Instructions/pop)
