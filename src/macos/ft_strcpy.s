        section .text
        global  _ft_strcpy

_ft_strcpy:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        mov     rax, rdi

_loop_cpy:
        cmp     BYTE [rsi], 0
        je      _done
        mov     dl, [rsi]
        mov     [rdi], dl
        inc     rdi
        inc     rsi
        jmp     _loop_cpy

_done:
        mov     BYTE [rdi], 0

        mov     rsp, rbp
        pop     rbp
        ret
