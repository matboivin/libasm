        section .text
        global  _ft_strcpy

_ft_strcpy:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; clears rax
        mov     rax, rdi        ; returns pointer to dst

_loop_cpy:
        cmp     BYTE [rsi], 0   ; checks src
        je      _done
        mov     dl, [rsi]       ; moves to dl the byte from src
        mov     [rdi], dl       ; moves to dst the byte from dl
        inc     rdi             ; increments dst
        inc     rsi             ; increments src
        jmp     _loop_cpy

_done:
        mov     BYTE [rdi], 0   ; adds trailing null char
        mov     rsp, rbp        ; leave
        pop     rbp
        ret