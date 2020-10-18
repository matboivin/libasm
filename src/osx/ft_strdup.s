        section .text
        global  _ft_strdup
        extern  _ft_strlen
        extern  _ft_strcpy
        extern  _malloc
        extern  ___error

_ft_strdup:
        push    rbp             ; enter
        mov     rbp, rsp

        push    rdi             ; saves the string

        call    _ft_strlen       ; gets the string length
        inc     rax             ; increments for terminating null character
        mov     rdi, rax        ; moves len in rdi to malloc the result

        call    _malloc
        mov     rdi, rax        ; moves malloc result
        test    rax, rax        ; test malloc return
        jz      _error

        pop     rsi             ; restores the string as src
        call    _ft_strcpy

_end:
        mov     rsp, rbp        ; leave
        pop     rbp
        ret

_error:
        call    ___error
        mov     [rax], rdi
        xor     rax, rax
        jmp     _end
