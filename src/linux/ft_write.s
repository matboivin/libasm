%define WRITE 1
%define ERROR_VAL -1

        section .text
        global  ft_write
        extern  __errno_location

ft_write:
        push    rbp                     ; enter
        mov     rbp, rsp

        mov     rax, WRITE              ; moves syscall number in rax
        syscall
        cmp     rax, rdx                ; checks whether return is equal to count
        jne     error

end:
        mov     rsp, rbp                ; leave
        pop     rbp
        ret

error:
        neg     rax                     ; gets the positive error code
        push    rax                     ; saves error code
        call    __errno_location        ; gets the address of the errno variable
        pop     WORD [rax]              ; restores the error code as the value of errno
        mov     rax, ERROR_VAL          ; sets the return value to -1
        jmp     end
