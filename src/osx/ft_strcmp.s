        section .text
        global  ft_strcmp

_ft_strcmp:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; clears rax

_loop:
        cmp     BYTE [rdi], 0   ; checks for trailing null char in s1
        jz      _end
        mov     al, [rdi]       ; moves s1 char in al
        sub     al, [rsi]       ; subtracts s2 char from al
        inc     rdi             ; increments s1
        inc     rsi             ; increments s2
        test    al, al          ; checks if zero (means characters are equal)
        jz      _loop

_end:
        mov     rsp, rbp        ; leave
        pop     rbp
        ret
