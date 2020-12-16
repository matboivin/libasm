# Process

## Define

Was inspired by [MacOS Syscall header](https://opensource.apple.com/source/xnu/xnu-792.13.8/osfmk/mach/i386/syscall_sw.h):

```
#define SYSCALL_CLASS_SHIFT	24
#define SYSCALL_CLASS_MASK	(0xFF << SYSCALL_CLASS_SHIFT)
#define SYSCALL_NUMBER_MASK	(~SYSCALL_CLASS_MASK)

#define SYSCALL_CLASS_NONE	0	/* Invalid */
#define SYSCALL_CLASS_MACH	1	/* Mach */	
#define SYSCALL_CLASS_UNIX	2	/* Unix/BSD */
#define SYSCALL_CLASS_MDEP	3	/* Machine-dependent */
#define SYSCALL_CLASS_DIAG	4	/* Diagnostics */

/* Macros to simpllfy constructing syscall numbers. */
#define SYSCALL_CONSTRUCT_MACH(syscall_number) \
			((SYSCALL_CLASS_MACH << SYSCALL_CLASS_SHIFT) | \
			 (SYSCALL_NUMBER_MASK & (syscall_number)))
#define SYSCALL_CONSTRUCT_UNIX(syscall_number) \
			((SYSCALL_CLASS_UNIX << SYSCALL_CLASS_SHIFT) | \
			 (SYSCALL_NUMBER_MASK & (syscall_number)))
#define SYSCALL_CONSTRUCT_MDEP(syscall_number) \
			((SYSCALL_CLASS_MDEP << SYSCALL_CLASS_SHIFT) | \
			 (SYSCALL_NUMBER_MASK & (syscall_number)))
#define SYSCALL_CONSTRUCT_DIAG(syscall_number) \
			((SYSCALL_CLASS_DIAG << SYSCALL_CLASS_SHIFT) | \
			 (SYSCALL_NUMBER_MASK & (syscall_number)))
```

I find it cleaner to use define in separate files (here, `libasm.s`) like headers in C.

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
- cmpsb [1](https://www.aldeid.com/wiki/X86-assembly/Instructions/cmpsb) | [2](http://vitaly_filatov.tripod.com/ng/asm/asm_000.17.html): compares string bytes. After the comparison, SI and DI are incremented (if the direction flag is cleared) or decremented (if the direction flag is set).

## Misc.

- swap values using [push](https://www.aldeid.com/wiki/X86-assembly/Instructions/push) and [pop](https://www.aldeid.com/wiki/X86-assembly/Instructions/pop)

## strcmp

- [strcmp() return different values for same string comparisons](https://stackoverflow.com/questions/33091350/strcmp-return-different-values-for-same-string-comparisons)
