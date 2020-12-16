        section .text
        global  ft_strlen

ft_strlen:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        xor     rcx, rcx
        not     rcx
        cld
        repne scasb
        not     rcx
        dec     rcx
        mov     rax, rcx

        mov     rsp, rbp
        pop     rbp
        ret
