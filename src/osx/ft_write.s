%define MAC_SYSCALL_CLASS_UNIX 0x2000000
%define MAC_SYSCALL_CONSTRUCT(n) (MAC_SYSCALL_CLASS_UNIX | n)
%define WRITE 4
%define ERROR_VAL -1

        section .text
        global  _ft_write
        extern  ___error

_ft_write:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        mov     rax, MAC_SYSCALL_CONSTRUCT(WRITE)
        syscall
        cmp     rax, rdx
        jne     _error

_end:
        mov     rsp, rbp
        pop     rbp
        ret

_error:
        neg     rax
        push    rax
        call    ___error
        pop     WORD [rax]
        mov     rax, ERROR_VAL
        jmp     _end
