%include "src/macos/libasm.s"

        section .text
        global  _ft_write
        extern  ___error

_ft_write:
        push    rbp
        mov     rbp, rsp

        xor     rax, rax
        mov     rax, MAC_SYSCALL_CONSTRUCT(WRITE)
        syscall
        cmp     rax, rdx
        jnc     _done

        push    rax
        call    ___error
        pop     WORD [rax]
        mov     rax, ERROR_VAL

_done:
        mov     rsp, rbp
        pop     rbp
        ret
