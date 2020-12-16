        section .text
        global  ft_strcpy

ft_strcpy:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        mov     rax, rdi

loop_cpy:
        cmp     BYTE [rsi], 0
        je      done
        mov     dl, [rsi]
        mov     [rdi], dl
        inc     rdi
        inc     rsi
        jmp     loop_cpy

done:
        mov     BYTE [rdi], 0

        mov     rsp, rbp
        pop     rbp
        ret
