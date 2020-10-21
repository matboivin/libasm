%include "src/linux/libasm.s"

        section .text
        global  ft_read
        extern  __errno_location

ft_read:
        push    rbp                     ; enter
        mov     rbp, rsp

        xor     rax, rax                ; clears rax
        mov     rax, READ               ; moves syscall number in rax
        syscall
        cmp     rax, rdx                ; checks if return is equal to count
        jne     error

done:
        mov     rsp, rbp                ; leave
        pop     rbp
        ret

error:
        neg     rax                     ; gets the positive error code
        push    rax                     ; saves error code
        call    __errno_location        ; gets the address of the errno variable
        pop     WORD [rax]              ; restores the error code as the value of errno
        mov     rax, ERROR_VAL          ; sets the return value to -1
        jmp     done
