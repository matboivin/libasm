        section .text
        global  ft_strcmp

ft_strcmp:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; clears rax

loop_cmp:
        cmp     BYTE [rdi], 0   ; checks for trailing null char in s1
        je      done
        mov     al, [rdi]       ; moves s1 char in al
        sub     al, [rsi]       ; subtracts s2 char from al
        inc     rdi             ; increments s1
        inc     rsi             ; increments s2
        test    al, al          ; checks if zero (means characters are equal)
        jz      loop_cmp

done:
        mov     rsp, rbp        ; leave
        pop     rbp
        ret
