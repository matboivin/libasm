%define WRITE 1

        section .text
        global  ft_write
        extern  __errno_location

ft_write:
        push    rbp             ; enter
        mov     rbp, rsp

        mov     rax, WRITE
        syscall
        cmp     rax, rdx
        jne     error

        mov     rsp, rbp
        pop     rbp
        ret

error:
        call    __errno_location
        mov     rsp, rbp
        pop     rbp
        ret
