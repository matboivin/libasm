%define IS_LESS -1
%define IS_GREATER 1

        section .text
        global  _ft_strcmp

_ft_strcmp:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; clears rax
        xor     rdx, rdx        ; clears rdx

_loop_cmp:
        mov     al, BYTE [rdi]  ; moves s1 char in al
        mov     dl, BYTE [rsi]  ; moves s2 char in dl
        cmp     BYTE [rdi], 0   ; checks for trailing null char in s1
        je      _endif
        cmp     BYTE [rsi], 0   ; checks for trailing null char in s1
        je      _endif
        inc     rdi             ; increments s1
        inc     rsi             ; increments s2
        cmp     al, dl          ; checks if characters are equal
        je      _loop_cmp

_endif:
        cmp     al, dl          ; checks if characters are equal
        jne     _if_lesser
        sub     rax, rdx        ; returns 0
        jmp     _done

_if_lesser:
        cmp     al, dl          ; checks if s1 char is lesser than s2 char
        jnbe    _if_greater
        mov     rax, IS_LESS    ; s1 is lesser than s2
        jmp     _done

_if_greater:
        mov     rax, IS_GREATER ; s1 is greater than s2

_done:
        mov     rsp, rbp        ; leave
        pop     rbp
        ret
