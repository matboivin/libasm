%include "src/linux/libasm.s"

        section .text
        global  _ft_list_size

_ft_list_size:
        push    rbp                     ; enter
        mov     rbp, rsp

        xor     rax, rax                ; clears rax
        xor     rcx, rcx                ; clears rcx (count)

_while_node:
        cmp     rdi, 0                  ; checks if node is null
        je      _done
        inc     rcx                     ; increments count by 1
        mov     rdi, [rdi + NODE_SIZE]  ; moves to next node
        jmp     _while_node

_done:
        mov     rax, rcx                ; moves count in return

        mov     rsp, rbp                ; leave
        pop     rbp
        ret
