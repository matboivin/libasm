        section .text
        global  ft_strcmp

ft_strcmp:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; clears rax

loop:
        cmp     BYTE [rdi], 0
        je      end
        mov     BYTE al, [rdi]
        sub     BYTE al, [rsi]
        inc     rdi
        inc     rsi
        cmp     BYTE al, 0
        jz      loop

end:
        mov     rsp, rbp                ; leave
        pop     rbp
        ret
