%define MAC_SYSCALL_CLASS_UNIX 0x2000000
%define MAC_SYSCALL_CONSTRUCT(n) (MAC_SYSCALL_CLASS_UNIX | n)
%define READ 3
%define ERROR_VAL -1

        section .text
        global  _ft_read
        extern  ___error

_ft_read:
        push    rbp
        mov     rbp, rsp

        mov     rax, MAC_SYSCALL_CONSTRUCT(READ)
        syscall
        cmp     rax, rdx
        jne     _error

_end:
        mov     rsp, rbp
        pop     rbp
        ret

_error:
        ;call    ___error
        mov     BYTE rax, ERROR_VAL
        jmp     _end
