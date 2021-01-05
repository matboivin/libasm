        section .text
        global  _ft_strcmp

_ft_strcmp:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        xor     rcx, rcx
        xor     rdx, rdx

_while_str:
        mov     al, BYTE [rdi + rcx]
        mov     dl, BYTE [rsi + rcx]
        test    al, al
        jz      _done
        inc     rcx
        cmp     al, dl
        je      _while_str

_done:
        sub     rax, rdx

        mov     rsp, rbp
        pop     rbp
        ret
