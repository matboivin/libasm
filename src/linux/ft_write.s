%include "src/linux/libasm.s"

        section .text
        global  ft_write
        extern  __errno_location

ft_write:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        mov     rax, WRITE
        syscall
        cmp     rax, rdx
        je      done

        neg     rax
        push    rax
        call    __errno_location
        pop     WORD [rax]
        mov     rax, ERROR_VAL

done:
        mov     rsp, rbp
        pop     rbp
        ret
