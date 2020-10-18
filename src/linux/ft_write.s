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
        cmp     rax, rdx                ; compares return is equal to count
        jne     error

end:
        mov     rsp, rbp                ; leave
        pop     rbp
        ret

error:
        neg     rdi                     ; gets the positive error code
        mov     rdi, rax                ; moves syscall return
        call    __errno_location        ; gets the address of the errno variable
        mov     [rax], rdi              ; sets the value of errno with the error code
        mov     BYTE rax, ERROR_VAL     ; sets the return value to -1
        jmp     end
