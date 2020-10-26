        section .text
        global  ft_strcmp

ft_strcmp:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; clears rax
        xor     rdx, rdx        ; clears rdx

loop_cmp:
        mov     al, BYTE [rdi]  ; gets s1 char
        mov     dl, BYTE [rsi]  ; gets s1 char
        test    al, al          ; check s1
        jz      done
        inc     rdi             ; increments s1
        inc     rsi             ; increments s2
        cmp     al, dl          ; checks if characters are equals
        je      loop_cmp

done:
        sub     rax, rdx        ; gets the difference

        mov     rsp, rbp        ; leave
        pop     rbp
        ret
