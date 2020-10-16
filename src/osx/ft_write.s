%define MAC_SYSCALL_CLASS_UNIX 0x2000000
%define MAC_SYSCALL_CONSTRUCT(n) (MAC_SYSCALL_CLASS_UNIX | n)
%define WRITE 4

        section .text
        global  _ft_write
        extern  ___error

_ft_write:
        push    rbp             ; enter
        mov     rbp, rsp

        mov     rax, WRITE      ; moves syscall number in rax
        syscall
        cmp     rax, rdx        ; compares return is equal to count
        jne     _error

_end:
        mov     rsp, rbp        ; leave
        pop     rbp
        ret

_error:
        call    __errno_location
        jmp     _end
