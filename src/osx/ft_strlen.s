        section .text
        global  _ft_strlen

_ft_strlen:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; set rax to 0
        xor     rcx, rcx        ; set rcx (counter) to 0
        not     rcx             ; performs a bit-wise inversion, rcx = -1
        cld                     ; clears the direction flag: DF = 0
        repne scasb             ; scans a string until 0 is found
        not     rcx             ; performs a bit-wise inversion
        dec     rcx             ; decrements rcx by 1 to remove trailing zero
        mov     rax, rcx        ; moves count in return

        mov     rsp, rbp        ; leave
        pop     rbp

        ret
