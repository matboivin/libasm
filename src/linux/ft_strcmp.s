        section .text
        global  ft_strcmp

ft_strcmp:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        xor     rdx, rdx

loop_cmp:
        mov     al, BYTE [rdi]
        mov     dl, BYTE [rsi]
        test    al, al
        jz      done
        inc     rdi
        inc     rsi
        cmp     al, dl
        je      loop_cmp

done:
        sub     rax, rdx

        mov     rsp, rbp
        pop     rbp
        ret
