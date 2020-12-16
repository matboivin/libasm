        section .text
        global  _ft_strdup
        extern  _ft_strlen
        extern  _ft_strcpy
        extern  _malloc
        extern  ___error

_ft_strdup:
        push    rbp
        mov     rbp, rsp

        push    rdi
        call    _ft_strlen
        inc     rax
        mov     rdi, rax

        call    _malloc
        test    rax, rax
        jz      _set_errno

        mov     rdi, rax
        pop     rsi
        call    _ft_strcpy

_done:
        mov     rsp, rbp
        pop     rbp
        ret

_set_errno:
        push    rax
        call    ___error
        pop     WORD [rax]
        xor     rax, rax
        jmp     _done
