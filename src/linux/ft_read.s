%include "src/linux/libasm.s"

        section .text
        global  ft_read
        extern  __errno_location

ft_read:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        mov     rax, READ
        syscall
        cmp     rax, 0
        jge     done

        neg     rax
        push    rax
        call    __errno_location
        pop     WORD [rax]
        mov     rax, ERROR_VAL

done:
        mov     rsp, rbp
        pop     rbp
        ret
