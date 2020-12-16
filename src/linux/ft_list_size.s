%include "src/linux/libasm.s"

        section .text
        global  ft_list_size

ft_list_size:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        xor     rcx, rcx

while_node:
        cmp     rdi, 0
        je      done
        inc     rcx
        mov     rdi, [rdi + NODE_SIZE]
        jmp     while_node

done:
        mov     rax, rcx

        mov     rsp, rbp
        pop     rbp
        ret
