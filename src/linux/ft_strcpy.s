        section .text
        global  ft_strcpy

ft_strcpy:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        xor     rcx, rcx

while_str:
        cmp     BYTE [rsi + rcx], 0
        je      done
        mov     dl, [rsi + rcx]
        mov     [rdi + rcx], dl
        inc     rcx
        jmp     while_str

done:
        mov     BYTE [rdi + rcx], 0
        mov     rax, rdi

        mov     rsp, rbp
        pop     rbp
        ret
