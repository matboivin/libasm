# Functions

## strlen

- [repne: REPeat while Not Equal](https://www.aldeid.com/wiki/X86-assembly/Instructions/repne)
- [scasb: SCan A String](https://www.aldeid.com/wiki/X86-assembly/Instructions/scasb)
- [cld: CLear Direction flag](https://www.aldeid.com/wiki/X86-assembly/Instructions/cld)

DF = 0 -> the instructions work by incrementing the pointer to the data after every iteration until ECX = 0

For example, `repne scasb` will scan bytes of a string until the trailing null character is found (end of string).
