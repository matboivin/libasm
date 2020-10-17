%define WRITE 1
%define ERROR_VAL -1

        section .text
        global  ft_write
        extern  __errno_location

ft_write:
        push    rbp             ; enter
        mov     rbp, rsp

        mov     rax, WRITE      ; moves syscall number in rax
        syscall
        cmp     rax, rdx        ; compares return is equal to count
        jne     error

end:
        mov     rsp, rbp        ; leave
        pop     rbp
        ret

error:
        ;call    __errno_location
        mov     BYTE rax, ERROR_VAL
        jmp     end
