        section .text
        global  ft_strcpy

ft_strcpy:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; clears rax

loop:
        cld
        lodsb                   ; loads byte from src to al and inc src
        stosb                   ; stores byte from al to dst and inc dst
        test    al, al
        jnz     loop

        mov     rax, rdi        ; returns pointer to dst
        mov     rsp, rbp        ; leave
        pop     rbp
        ret
