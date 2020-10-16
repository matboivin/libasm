        section .text
        global  ft_strcpy

ft_strcpy:
        push    rbp                     ; enter
        mov     rbp, rsp

        xor     rax, rax                ; clears rax
        xor     rcx, rcx                ; clears rcx (count)
        cmp     BYTE [rsi], 0           ; checks src
        je      end

loop:
        mov     al, BYTE [rsi + rcx]    ; moves to al the byte from src + count
        mov     BYTE [rdi + rcx], al    ; moves to dst + count the byte from al
        inc     rcx                     ; increments count by 1
        test    al, al                  ; checks for trailing null char
        jnz     loop

end:
        mov     rax, rdi                ; returns pointer to dst
        mov     rsp, rbp                ; leave
        pop     rbp
        ret
