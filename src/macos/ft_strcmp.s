        section .text
        global  _ft_strcmp

_ft_strcmp:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; clears rax
        xor     rdx, rdx        ; clears rdx

_loop_cmp:
        cmp     BYTE [rdi], 0   ; checks for trailing null char in s1
        jz      _done
        cmp     BYTE [rsi], 0   ; checks for trailing null char in s2
        jz      _done
        mov     al, [rdi]       ; moves character from s1 in al
        mov     dl, [rsi]       ; moves character from s2 in al
        inc     rdi             ; increments s1
        inc     rsi             ; increments s2
        test    al, dl          ; checks if characters are equal
        je      _loop_cmp

_done:
        sub     rax, rdx        ; gets the difference between the two characters

        mov     rsp, rbp        ; leave
        pop     rbp
        ret
