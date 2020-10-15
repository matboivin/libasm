        section .text
        global  ft_strlen

ft_strlen:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; clears rax
        xor     rcx, rcx        ; clears rcx (count)
        not     rcx             ; performs a bit-wise inversion, rcx = -1
        cld                     ; clears DF to scan in the forward direction
        repne scasb             ; scans string until trailing null char is found
        not     rcx             ; performs a bit-wise inversion
        dec     rcx             ; decrements rcx by 1 to remove trailing zero
        mov     rax, rcx        ; moves count in return

        mov     rsp, rbp        ; leave
        pop     rbp
        ret
