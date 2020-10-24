%include "src/linux/libasm.s"

        section .text
        global  ft_list_push_front

ft_list_push_front:
        push    rbp                     ; enter
        mov     rbp, rsp

        xor     rax, rax                ; clears rax

        cmp     rdi, 0                  ; checks if list is null
        je      done
        cmp     BYTE [rsi], 0           ; checks if new node is null
        je      done

        mov     rax, [rdi]              ; store *lst in rax
        mov     [rsi + NODE_SIZE], rax  ; new_node->next is now head of list
        mov     [rax], rsi              ; head of list is now the new node

done:
        mov     rsp, rbp                ; leave
        pop     rbp
        ret
