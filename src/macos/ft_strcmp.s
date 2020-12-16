        section .text
        global  _ft_strcmp

_ft_strcmp:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        xor     rdx, rdx

_loop_cmp:
        mov     al, BYTE [rdi]
        mov     dl, BYTE [rsi]
        test    al, al
        jz      _done
        inc     rdi
        inc     rsi
        cmp     al, dl
        je      _loop_cmp

_done:
        sub     rax, rdx

        mov     rsp, rbp
        pop     rbp
        ret
