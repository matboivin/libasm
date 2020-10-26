        section .text
        global  _ft_strcmp

_ft_strcmp:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; clears rax
        xor     rdx, rdx        ; clears rdx

_loop_cmp:
        mov     al, BYTE [rdi]  ; gets s1 char
        mov     dl, BYTE [rsi]  ; gets s1 char
        test    al, al          ; check s1
        jz      _done
        inc     rdi             ; increments s1
        inc     rsi             ; increments s2
        cmp     al, dl          ; checks if characters are equals
        je      _loop_cmp

_done:
        sub     rax, rdx        ; gets the difference

        mov     rsp, rbp        ; leave
        pop     rbp
        ret
