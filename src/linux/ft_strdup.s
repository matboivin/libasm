        section .text
        global  ft_strdup
        extern  ft_strlen
        extern  malloc

ft_strdup:
        push    rbp                     ; enter
        mov     rbp, rsp

        xor     rax, rax                ; clears rax

        mov     rax, rdi                ; returns pointer to dst
        mov     rsp, rbp                ; leave
        pop     rbp
        ret
