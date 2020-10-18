        section .text
        global  ft_strcpy

ft_strcpy:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; clears rax
        mov     rax, rdi        ; returns pointer to dst

loop:
        cmp     BYTE [rsi], 0   ; checks src
        je      end
        mov     dl, [rsi]       ; moves to dl the byte from src
        mov     [rdi], dl       ; moves to dst the byte from dl
        inc     rdi             ; increments s1
        inc     rsi             ; increments s2
        jmp     loop

end:
        mov     BYTE [rdi], 0   ; adds trailing null char
        mov     rsp, rbp        ; leave
        pop     rbp
        ret
