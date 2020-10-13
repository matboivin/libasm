%define WRITE 1

        section .text
        global  ft_write
        extern  __errno_location

ft_write:
        push    rbp             ; enter
        mov     rbp, rsp
        mov     rdi, 1
        mov     rsi, "lol"
        mov     rdx, 3
        mov     rax, WRITE
        syscall
        cmp     rax, 0
        jnz     error

        mov     rsp, rbp        ; leave
        pop     rbp

        ret

error:
        call    __errno_location
        ret
