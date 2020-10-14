%define READ 0

        section .text
        global  ft_read
        extern  __errno_location

ft_read:
        push    rbp             ; enter
        mov     rbp, rsp

        mov     rax, READ
        syscall
        cmp     rax, rdx        ; compare return is equal to count
        jne     error

end:
        mov     rsp, rbp        ; leave
        pop     rbp
        ret

error:
        call    __errno_location
        jmp     end
