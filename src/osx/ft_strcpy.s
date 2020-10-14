        section .text
        global  _ft_strcpy

_ft_strcpy:
        push    rbp             ; enter
        mov     rbp, rsp

        xor     rax, rax        ; set rax to 0
        xor     rcx, rcx        ; set rcx (count) to 0

_loop:
        mov     al, [rsi + rcx] ; moves to al the byte at address src + count
        mov     [rdi + rcx], al ; moves to dst + count the byte from al
        inc     rcx             ; increments count by 1
        cmp     BYTE [rsi], 0   ; checks for terminating character
        je      end
        jmp     loop

_end:
        mov     rax, rdi        ; returns pointer to dst
        mov     rsp, rbp        ; leave
        pop     rbp
        ret
