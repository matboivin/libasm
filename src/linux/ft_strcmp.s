        section .text
        global  ft_strcmp

ft_strcmp:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        xor     rcx, rcx
        xor     rdx, rdx

while_str:
        mov     al, BYTE [rdi + rcx]
        mov     dl, BYTE [rsi + rcx]
        test    al, al
        jz      done
        inc     rcx
        cmp     al, dl
        je      while_str

done:
        sub     rax, rdx

        mov     rsp, rbp
        pop     rbp
        ret
