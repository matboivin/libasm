%include "src/linux/libasm.s"

        section .text
        global  ft_list_push_front

ft_list_push_front:
        push    rbp                     ; enter
        mov     rbp, rsp

        xor     rax, rax                ; clears rax

        cmp     BYTE [rdi], 0           ; checks if null list
        je      done
        cmp     BYTE [rsi], 0           ; checks if null new node
        je      done

        mov     rax, [rdi]              ; store *lst in rax
        mov     [rsi + NODE_SIZE], rax  ; new node next is now *lst
        mov     [rax], rsi              ; head of list is now the new node

done:
        mov     rsp, rbp                ; leave
        pop     rbp
        ret
