%include "src/linux/libasm.s"

        section .text
        global  ft_list_size

ft_list_size:
        push    rbp                     ; enter
        mov     rbp, rsp

        xor     rax, rax                ; clears rax
        xor     rcx, rcx                ; clears rcx (count)

while_node:
        cmp     rdi, 0                  ; checks if list is null
        je      done
        inc     rcx                     ; increments count by 1
        mov     rdi, [rdi + NODE_SIZE]  ; moves to next node
        jmp     while_node

done:
        mov     rax, rcx                ; moves count in return

        mov     rsp, rbp                ; leave
        pop     rbp
        ret
