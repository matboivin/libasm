%include "src/macos/libasm.s"

        section .text
        global  _ft_read
        extern  ___error

_ft_read:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        mov     rax, MAC_SYSCALL_CONSTRUCT(READ)
        syscall
        jnc     _done

        push    rax
        call    ___error
        pop     WORD [rax]
        mov     rax, ERROR_VAL

_done:
        mov     rsp, rbp
        pop     rbp
        ret
