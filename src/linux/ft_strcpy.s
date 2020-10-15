        section .text
        global  ft_strcpy

ft_strcpy:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; clears rax
        xor     rcx, rcx        ; clears rcx (count)

loop:
        cmp     BYTE [rsi], 0   ; checks for trailing null char
        je      end
        mov     al, [rsi + rcx] ; moves to al the byte at address src + count
        mov     [rdi + rcx], al ; moves to dst + count the byte from al
        inc     rcx             ; increments count by 1
        jmp     loop

end:
        mov     rax, rdi        ; returns pointer to dst
        mov     rsp, rbp        ; leave
        pop     rbp
        ret
