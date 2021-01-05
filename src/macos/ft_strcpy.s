        section .text
        global  _ft_strcpy

_ft_strcpy:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        xor     rcx, rcx

_while_str:
        cmp     BYTE [rsi + rcx], 0
        je      _done
        mov     dl, [rsi + rcx]
        mov     [rdi + rcx], dl
        inc     rcx
        jmp     _while_str

_done:
        mov     BYTE [rdi + rcx], 0
        mov     rax, rdi

        mov     rsp, rbp
        pop     rbp
        ret
