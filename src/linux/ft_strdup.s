        section .text
        global  ft_strdup
        extern  ft_strlen
        extern  ft_strcpy
        extern  malloc
        extern  __errno_location

ft_strdup:
        push    rbp
        mov     rbp, rsp

        push    rdi
        call    ft_strlen
        inc     rax
        mov     rdi, rax

        call    malloc
        test    rax, rax
        jz      set_errno

        mov     rdi, rax
        pop     rsi
        call    ft_strcpy

done:
        mov     rsp, rbp
        pop     rbp
        ret

set_errno:
        neg     rax
        push    rax
        call    __errno_location
        pop     WORD [rax]
        xor     rax, rax
        jmp     done
