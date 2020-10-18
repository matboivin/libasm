        section .text
        global  ft_strdup
        extern  ft_strlen
        extern  ft_strcpy
        extern  malloc
        extern  __errno_location

ft_strdup:
        push    rbp             ; enter
        mov     rbp, rsp

        push    rdi             ; saves the string

        call    ft_strlen       ; gets the string length
        inc     rax             ; increments for terminating null character
        mov     rdi, rax        ; moves len in rdi to malloc the result

        call    malloc
        mov     rdi, rax        ; moves malloc result
        test    rax, rax        ; test malloc return
        jz      error

        pop     rsi             ; restores the string as src
        call    ft_strcpy

end:
        mov     rsp, rbp        ; leave
        pop     rbp
        ret

error:
        call    __errno_location
        xor     rax, rax
        jmp     end
