%define WRITE 1

        section .text
        global  ft_write
        extern  __errno_location

ft_write:
        push    rbp             ; enter
        mov     rbp, rsp

        mov     rax, WRITE
        syscall
        cmp     rax, rdx        ; compare return is equal to count
        jne     error

return:
        mov     rsp, rbp        ; leave
        pop     rbp
        ret

error:
        call    __errno_location
        jmp     return
