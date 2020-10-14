%define MAC_SYSCALL_CLASS_UNIX 0x2000000
%define MAC_SYSCALL_CONSTRUCT(n) (MAC_SYSCALL_CLASS_UNIX | n)
%define WRITE 4

        section .text
        global  _ft_write
        extern  ___error

_ft_write:
        push    rbp             ; enter
        mov     rbp, rsp

        mov     rax, MAC_SYSCALL_CONSTRUCT(WRITE)
        syscall
        cmp     rax, rdx        ; compare return is equal to count
        jne     _error

_return:
        mov     rsp, rbp        ; leave
        pop     rbp
        ret

_error:
        call    ___error
        jmp     _return
