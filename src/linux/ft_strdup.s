; malloc(size_t size);
; strdup(const char *s);
; ft_strcpy(char *dst, const char *src)

        section .text
        global  ft_strdup
        extern  ft_strlen
        extern  ft_strcpy
        extern  malloc
        extern  __errno_location

ft_strdup:
        push    rbp             ; enter
        mov     rbp, rsp

        push    rdi

        call    ft_strlen
        inc     rax             ; increments for terminating null character
        mov     rdi, rax

        call    malloc
        test    al, al
        jz      error

        pop     rsi
        mov     rdi, rax

        call    ft_strcpy

end:
        mov     rsp, rbp        ; leave
        pop     rbp
        ret

error:
        ;call    __errno_location
        mov     BYTE rax, 0
        jmp     end
