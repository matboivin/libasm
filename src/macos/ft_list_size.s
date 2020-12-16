%include "src/linux/libasm.s"

        section .text
        global  _ft_list_size

_ft_list_size:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        xor     rcx, rcx

_while_node:
        cmp     rdi, 0
        je      _done
        inc     rcx
        mov     rdi, [rdi + NODE_SIZE]
        jmp     _while_node

_done:
        mov     rax, rcx

        mov     rsp, rbp
        pop     rbp
        ret
