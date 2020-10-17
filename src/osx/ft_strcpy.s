        section .text
        global  _ft_strcpy

_ft_strcpy:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; clears rax
        xor     rcx, rcx        ; clears rcx (count)

_loop:
        cmp     BYTE [rsi], 0   ; checks src
        je      end
        mov     al, [rsi + rcx] ; moves to al the byte from src + count
        mov     [rdi + rcx], al ; moves to dst + count the byte from al
        inc     rcx             ; increments count by 1
        jnz     _loop

_end:
        mov     BYTE [rdi], 0   ; adds trailing null char
        mov     rax, rdi        ; returns pointer to dst
        mov     rsp, rbp        ; leave
        pop     rbp
        ret
