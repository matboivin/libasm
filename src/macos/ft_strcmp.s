%define IS_LESS -1
%define IS_GREATER 1

        section .text
        global  _ft_strcmp

_ft_strcmp:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rdx, rdx        ; clears rdx

_loop_cmp:
        xor     rax, rax        ; clears rax
        cmp     BYTE [rdi], 0   ; checks for trailing null char in s1
        je      _done
        cmp     BYTE [rsi], 0   ; checks for trailing null char in s1
        je      _done
        mov     al, BYTE [rdi]  ; moves s1 char in al
        mov     dl, BYTE [rsi]  ; moves s2 char in dl
        inc     rdi             ; increments s1
        inc     rsi             ; increments s2
        cmp     al, dl          ; checks if characters are equal
        je      _loop_cmp
        jl      _s1_lesser
        jg      _s1_greater

_s1_lesser:
        mov     rax, IS_LESS    ; s1 is less than s2
        jmp     _done

_s1_greater:
        mov     rax, IS_GREATER ; s1 is greater than s2
        jmp     _done

_done:
        mov     rsp, rbp        ; leave
        pop     rbp
        ret
