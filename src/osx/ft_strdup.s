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
        call    _ft_strlen      ; gets the string length
        inc     rax             ; increments for terminating character
        mov     rdi, rax        ; moves length in rdi to malloc the result

        call    _malloc
        test    rax, rax        ; checks if null
        jz      _error

        mov     rdi, rax        ; moves address to be used as dst for copy
        pop     rsi             ; restores the string as src
        call    _ft_strcpy

_end:
        mov     rsp, rbp        ; leave
        pop     rbp
        ret

_error:
        neg     rax             ; gets the positive error code
        push    rax             ; saves error code
        call    ___error        ; gets the address of the errno variable
        pop     WORD [rax]      ; restores the error code as the value of errno
        xor     rax, rax        ; sets the return value to 0
        jmp     _end
