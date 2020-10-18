%define READ 0
%define ERROR_VAL -1

        section .text
        global  ft_read
        extern  __errno_location

ft_read:
        push    rbp                     ; enter
        mov     rbp, rsp

        mov     rax, READ               ; moves syscall number in rax
        syscall
        cmp     rax, rdx                ; compares return is equal to count
        jne     error

end:
        mov     rsp, rbp                ; leave
        pop     rbp
        ret

error:
        mov     rdi, rax                ; moves syscall return
        call    __errno_location
        mov     BYTE rax, ERROR_VAL
        jmp     end
